
// -----------------------------------------------------------------------------
// Helpers
// -----------------------------------------------------------------------------

// ------------------------
// scalar2Attr
// vector2Attr
// ------------------------

// scalar2Attr
template<class T, class OBJECT>
void scalar2Attr(
   const std::string &key, const std::string &value,
   OBJECT &hdf5
) {
   T scalar;
   convert(value,scalar);
   hdf5.createAttribute(key,scalar);
}

// vector2Attr
template<class T, class OBJECT>
void vector2Attr(
   const std::string &key, const std::string &value,
   OBJECT &hdf5
) {
   std::vector<T> vector;
   convert(value,vector);
   hdf5.createAttribute(key,vector);
}


// ------------------------
// data2DataSet
// ------------------------

// <T> helper
template<class T, class OBJECT>
HighFive::DataSet data2DataSet(
   const std::string &key, const std::string &value,
   OBJECT &hdf5
) {
   // Similar to vector2Attr() above, but creates a DataSet, not an Attribute.
   // Note that in the JSON-format analogs of the various helper functions in
   // this section of code, an analog of *this* function doesn't exist. JSON
   // doesn't have HDF5's distinction between "attributes" and "data sets".
   // Therefore, writing a vector (as we do above, via createAttribute(), and
   // here, via createDataSet()) is done, in JSON, in just one way: by creating
   // a JSON key:value pair with the vector as the value. So, in the JSON code,
   // we have an analog of the above vector2Attr() function, and that function
   // is also used where this present function would otherwise have been used.
   std::vector<T> vector;
   convert(value,vector);
   return hdf5.createDataSet(key,vector);
}

// w/ type string
template<class OBJECT>
HighFive::DataSet data2DataSet(
   const std::string &key, const std::string &value,
   OBJECT &hdf5
) {
   if (HDF5::typed) {
      const std::string type = guessType(value);

      if (type == "int"    || type == "ints"   )
         return data2DataSet<int          >(key,value,hdf5);
      if (type == "uint"   || type == "uints"  )
         return data2DataSet<unsigned     >(key,value,hdf5);
      if (type == "long"   || type == "longs"  )
         return data2DataSet<long         >(key,value,hdf5);
      if (type == "ulong"  || type == "ulongs" )
         return data2DataSet<unsigned long>(key,value,hdf5);
      if (type == "double" || type == "doubles")
         return data2DataSet<double       >(key,value,hdf5);
   }
   return data2DataSet<std::string>(key,value,hdf5);
}


// -----------------------------------------------------------------------------
// meta2hdf5*
// See remarks in the JSON analogs of these functions.
// -----------------------------------------------------------------------------

// ------------------------
// meta2hdf5_typed
// ------------------------

template<class NODE, class OBJECT>
void meta2hdf5_typed(const NODE &node, OBJECT &hdf5)
{
   const std::string &parent = node.name;

   for (auto &meta : node.metadata) {
      const std::string &key = meta.first;
      const std::string &value = meta.second;

      // ------------------------
      // Special cases
      // ------------------------

      // *** #cdata/#text
      // *** #comment/#text
      if ((parent == special::cdata ||
           parent == special::comment) && key == special::text) {
         hdf5.createAttribute(key,value); // just a simple string attribute
         continue;
      }

      // *** #data/#text
      if (parent == special::data && key == special::text) {
         const std::string type = guessType(value);
         if (type == "int" || type == "ints")
            vector2Attr<int          >(key,value,hdf5);
         else if (type == "uint" || type == "uints")
            vector2Attr<unsigned     >(key,value,hdf5);
         else if (type == "long" || type == "longs")
            vector2Attr<long         >(key,value,hdf5);
         else if (type == "ulong" || type == "ulongs")
            vector2Attr<unsigned long>(key,value,hdf5);
         else if (type == "double" || type == "doubles")
            vector2Attr<double       >(key,value,hdf5);
         else
            vector2Attr<std::string  >(key,value,hdf5);
         continue;
      }

      // *** key/#text not expected, except as already handled
      if (key == special::text) {
         log::warning("Metadatum \"{}\" not expected here; writing anyway",
                      special::text);
         log::function("detail::meta2hdf5(Node named \"{}\", ...)", parent);
      }

      // ------------------------
      // General case
      // ------------------------

      // *** key/value
      const std::string type = guessType(value);
      if (type == "int"    ) scalar2Attr<int          >(key,value,hdf5); else
      if (type == "ints"   ) vector2Attr<int          >(key,value,hdf5); else
      if (type == "uint"   ) scalar2Attr<unsigned     >(key,value,hdf5); else
      if (type == "uints"  ) vector2Attr<unsigned     >(key,value,hdf5); else
      if (type == "long"   ) scalar2Attr<long         >(key,value,hdf5); else
      if (type == "longs"  ) vector2Attr<long         >(key,value,hdf5); else
      if (type == "ulong"  ) scalar2Attr<unsigned long>(key,value,hdf5); else
      if (type == "ulongs" ) vector2Attr<unsigned long>(key,value,hdf5); else
      if (type == "double" ) scalar2Attr<double       >(key,value,hdf5); else
      if (type == "doubles") vector2Attr<double       >(key,value,hdf5); else
      /* string OR strings*/ scalar2Attr<std::string  >(key,value,hdf5);
   }
} // meta2hdf5_typed


// ------------------------
// meta2hdf5_plain
// ------------------------

// Here, OBJECT hdf5 is either a HighFive::Group or a HighFive::DataSet
template<class NODE, class OBJECT>
void meta2hdf5_plain(const NODE &node, OBJECT &hdf5)
{
   for (auto &meta : node.metadata)
      hdf5.createAttribute(meta.first, meta.second);
}


// ------------------------
// meta2hdf5
// ------------------------

template<class NODE, class OBJECT>
void meta2hdf5(
   const NODE &node, OBJECT &hdf5,
   const std::string &base,
   const std::string &digits
) {
   // Create #nodename iff necessary. See remarks in the analogous JSON code.
   if (digits != "" &&
      !beginsin(base,std::string(1,special::prefix)))
      hdf5.createAttribute(special::nodename, node.name);

   // Existing metadata
   HDF5::typed
      ? meta2hdf5_typed(node,hdf5)
      : meta2hdf5_plain(node,hdf5);
}


// -----------------------------------------------------------------------------
// hdf5_reduce_*
// -----------------------------------------------------------------------------

// ------------------------
// hdf5_reduce_cdata_comment
// ------------------------

// Simplify certain #cdata and #comment cases.
template<class NODE, class OBJECT>
bool hdf5_reduce_cdata_comment(
   const NODE &node, OBJECT &hdf5, const std::string &suffix
) {
   const std::string nameOriginal = node.name;
   const std::string nameSuffixed = node.name + suffix;

   // #cdata or #comment
   //    #text the only metadatum
   //    no children
   // Reduce to: string attribute, w/name == (#cdata or #comment) + suffix
   // Sketch:
   //    +-----------------+     +-----------+
   //    | #cdata/#comment | ==> | Attribute | name: #cdata/#comment + suffix
   //    |    #text        |     |    value  |
   //    +-----------------+     +-----------+

   if (
      (nameOriginal == special::cdata || nameOriginal == special::comment) &&
       node.children.size() == 0 &&
       node.metadata.size() == 1 &&
       node.metadata[0].first == special::text
   ) {
      // string attribute
      hdf5.createAttribute(nameSuffixed,node.metadata[0].second);
      return true;
   }

   return false;
}


// ------------------------
// hdf5_reduce_data
// ------------------------

// Simplify #data case.
template<class NODE, class OBJECT>
bool hdf5_reduce_data(
   const NODE &node, OBJECT &hdf5, const std::string &suffix
) {
   const std::string nameOriginal = node.name;
   const std::string nameSuffixed = node.name + suffix;

   // #data
   //    #text the only metadatum
   //    no children
   // Reduce to: data set, w/name == #data + suffix
   // Sketch:
   //    +----------+     +---------+
   //    | #data    | ==> | DataSet | name: #data + suffix
   //    |    #text |     |    data |
   //    +----------+     +---------+

   if (nameOriginal == special::data &&
       node.children.size() == 0 &&
       node.metadata.size() == 1 &&
       node.metadata[0].first == special::text
   ) {
      // See the remark in the analogous JSON function regarding the difference
      // between this function and the one immediately below.

      // HDF5 data set
      data2DataSet(nameSuffixed, node.metadata[0].second, hdf5);
      return true;
   }

   return false;
}


// ------------------------
// hdf5_reduce_data_metadata
// ------------------------

// Simplify case of node with #data AND metadata
template<class NODE, class OBJECT>
bool hdf5_reduce_data_metadata(
   const NODE &node, OBJECT &hdf5, const std::string &suffix
) {
   // name (think e.g. "values", as in XML <values>)
   //    any number of metadata (possibly 0)
   //    #data the only child
   //       #text the only metadatum
   //       no children
   // Reduce to: data set, w/name == name + suffix
   // Sketch:
   //    +---------------+     +----------------+
   //    | name          | ==> | DataSet        | name: name + suffix
   //    |    [metadata] |     |   [Attributes] |
   //    |    #data      |     |    data        |
   //    |       #text   |     +----------------+
   //    |       -       |
   //    +---------------+

   if (node.children.size() == 1 &&
       node.children[0]->name == special::data &&
       node.children[0]->metadata.size() == 1 &&
       node.children[0]->metadata[0].first == special::text &&
       node.children[0]->children.size() == 0
   ) {
      // HDF5 data set
      const std::string text = node.children[0]->metadata[0].second;
      HighFive::DataSet dataset = data2DataSet(node.name+suffix, text, hdf5);

      // metadata
      meta2hdf5(node, dataset, node.name, suffix);
      return true;
   }

   return false;
}


// -----------------------------------------------------------------------------
// node2hdf5
// -----------------------------------------------------------------------------

// NODE is just GNDStk::Node. The latter isn't used directly, because
// it's an "incomplete type", to the compiler, at this point.
// OBJECT is either HighFive::File or HighFive::Group.
template<class NODE, class OBJECT>
bool node2hdf5(const NODE &node, OBJECT &h, const std::string &suffix = "")
{
   const std::string nameSuffixed = node.name + suffix;

   // ------------------------
   // Special cases
   // ------------------------

   if (HDF5::reduced && (
      hdf5_reduce_cdata_comment(node,h,suffix) ||
      hdf5_reduce_data         (node,h,suffix) ||
      hdf5_reduce_data_metadata(node,h,suffix)
   ))
      return true;

   // ------------------------
   // General case
   // ------------------------

   // Create a new Group, in parameter h, for metadata and children
   HighFive::Group group = h.createGroup(nameSuffixed);

   // metadata
   meta2hdf5(node, group, node.name, suffix);

   // children - preprocess
   // To understand this, see the remark in the JSON analog.
   std::map<std::string,std::size_t> childNames;
   for (auto &c : node.children) {
      auto iter = childNames.find(c->name);
      if (iter == childNames.end())
         childNames.insert({c->name,0});
      else
         iter->second = 1;
   }

   // children
   for (auto &c : node.children) {
      const std::size_t counter = childNames.find(c->name)->second++;
      if (!node2hdf5(*c, group, counter ? std::to_string(counter-1) : ""))
         return false;
   }

   // done
   return true;
}
