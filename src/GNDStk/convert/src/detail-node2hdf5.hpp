
// -----------------------------------------------------------------------------
// Helpers
// -----------------------------------------------------------------------------

// ------------------------
// scalar2Attr
// vector2Attr
// ------------------------

template<class T, class OBJECT>
void scalar2Attr(
   const std::string &key, const std::string &value,
   OBJECT &hdf5
) {
   T scalar;
   convert(value,scalar);
   hdf5.createAttribute(key,scalar);
}

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
// pcdata2DataSet
// ------------------------

// <T> helper
template<class T, class OBJECT>
HighFive::DataSet pcdata2DataSet(
   const std::string &key, const std::string &value,
   OBJECT &hdf5
) {
   // Similar to vector2Attr(), but creates a DataSet, not an Attribute
   std::vector<T> vector;
   convert(value,vector);
   return hdf5.createDataSet(key,vector);
}

// w/ type string
template<class OBJECT>
HighFive::DataSet pcdata2DataSet(
   const std::string &key, const std::string &value,
   OBJECT &hdf5
) {
   if (HDF5::typed) {
      const std::string type = guessType(value);
      if (type == "int"    || type == "ints"   )
         return pcdata2DataSet<int          >(key,value,hdf5);
      if (type == "uint"   || type == "uints"  )
         return pcdata2DataSet<unsigned     >(key,value,hdf5);
      if (type == "long"   || type == "longs"  )
         return pcdata2DataSet<long         >(key,value,hdf5);
      if (type == "ulong"  || type == "ulongs" )
         return pcdata2DataSet<unsigned long>(key,value,hdf5);
      if (type == "double" || type == "doubles")
         return pcdata2DataSet<double       >(key,value,hdf5);
   }
   return pcdata2DataSet<std::string>(key,value,hdf5);
}


// -----------------------------------------------------------------------------
// meta2hdf5*
// -----------------------------------------------------------------------------

// ------------------------
// meta2hdf5_typed
// ------------------------

// Use our "guess what's in the string" code to try to infer what each
// metadatum's string value actually contains (a single int, say, or
// a vector of doubles). Use the inferred types in the HDF5 file.
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
      // ACTION: Write these as-is. That is, do NOT apply our type-guessing code
      // to a comment, or to the contents of a <![CDATA[...]]> block like those
      // that we see in existing XML-format GNDS files. The type guesser would
      // see words, and think "vector of [whitespace-separated] strings," which
      // would be wrong for what are clearly intended to be free-form strings.
      if ((parent == "#cdata" || parent == "#comment") && key == "#text") {
         hdf5.createAttribute(key,value); // just a simple string attribute
         continue;
      }

      // *** #pcdata/#text
      // ACTION: Apply our type-guessing code, but write *vectors* only, never
      // scalars. So, <values>10</values> produces a vector with one element,
      // NOT a scalar; while <values>10 20 30</values> produces a vector with
      // with three elements. What may look like scalars are made into vectors
      // because we think this reflects what these (#pcdata) nodes are intended
      // to represent. (If something was really just a scalar, then surely it
      // would be placed into standard metadata (in <...>), not #pcdata.
      if (parent == "#pcdata" && key == "#text") {
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
      if (key == "#text") {
         log::warning("Metadatum \"#text\" not expected here; writing anyway");
         log::function("detail::meta2hdf5(Node named \"{}\", ...)", parent);
      }

      // ------------------------
      // General case
      // ------------------------

      // *** key/value
      // ACTION: Apply our type-guessing code.
      // Here we have normal metadata, as in <foo meta="free-form string">.
      // For numeric types we might produce vectors, if there appear to be
      // multiple values. But for string types, we'll assume that the value
      // is probably intended to be a free-form, human-readable descriptive
      // string, which shouldn't be split into tokens and made into a vector.
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

// Write simple HDF5 in which all metadata, as well as the contents
// of "cdata" and "pcdata" nodes, end up being strings. Not even vectors
// of strings, as from <values>H He Li ...</values>, but single strings.
template<class NODE, class OBJECT>
void meta2hdf5_plain(const NODE &node, OBJECT &hdf5)
{
   for (auto &meta : node.metadata)
      hdf5.createAttribute(meta.first, meta.second);
}


// ------------------------
// meta2hdf5
// ------------------------

// Here, OBJECT hdf5 is either a HighFive::Group or a HighFive::DataSet
template<class NODE, class OBJECT>
void meta2hdf5(const NODE &node, OBJECT &hdf5,  const std::string &suffix)
{
   // Create #nodename iff necessary (allows recovery of original node name)
   if (suffix != "")
      hdf5.createAttribute(std::string("#nodename"), node.name);

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
      (nameOriginal == "#cdata" || nameOriginal == "#comment") &&
       node.children.size() == 0 &&
       node.metadata.size() == 1 &&
       node.metadata[0].first == "#text"
   ) {
      // string attribute
      hdf5.createAttribute(nameSuffixed,node.metadata[0].second);
      return true;
   }

   return false;
}


// ------------------------
// hdf5_reduce_pcdata
// ------------------------

// Simplify #pcdata case.
template<class NODE, class OBJECT>
bool hdf5_reduce_pcdata(
   const NODE &node, OBJECT &hdf5, const std::string &suffix
) {
   const std::string nameOriginal = node.name;
   const std::string nameSuffixed = node.name + suffix;

   // #pcdata
   //    #text the only metadatum
   //    no children
   // Reduce to: data set, w/name == #pcdata + suffix
   // Sketch:
   //    +----------+     +---------+
   //    | #pcdata  | ==> | DataSet | name: #pcdata + suffix
   //    |    #text |     |    data |
   //    +----------+     +---------+

   if (nameOriginal == "#pcdata" &&
       node.children.size() == 0 &&
       node.metadata.size() == 1 &&
       node.metadata[0].first == "#text"
   ) {
      // Remark. This case (basically, #pcdata/#text) may look superficially
      // like it would have been handled, in the case immediately below here,
      // in the previous (next-up) recurse of the node2hdf5() function. Often
      // it would have, but not always. Below, name/#pcdata/#text (three
      // levels, so to speak) reduces to one level (DataSet name), but
      // only if name has ONE child - the #pcdata. That's true when we
      // have (in XML) something like <values>1 2 3</values>, as the pcdata,
      // i.e. the 1 2 3 part, is <values>' only child node. However, it's
      // actually possible (though I don't see it in current GNDS files) to
      // have something like: <values><foo></foo>1 2 3</values>. There, the
      // outer "name" node (<value>) has child foo and child #pcdata, and
      // thus can't be reduced in the manner that's done if only #pcdata is
      // there. In short, then, the present situation comes to pass if and
      // when #pcdata has sibling nodes.

      // HDF5 data set
      pcdata2DataSet(nameSuffixed, node.metadata[0].second, hdf5);
      return true;
   }

   return false;
}


// ------------------------
// hdf5_reduce_pcdata_metadata
// ------------------------

// Simplify case of node with #pcdata AND metadata
template<class NODE, class OBJECT>
bool hdf5_reduce_pcdata_metadata(
   const NODE &node, OBJECT &hdf5, const std::string &suffix
) {
   // name (think e.g. "values", as in XML <values>)
   //    any number of metadata (possibly 0)
   //    #pcdata the only child
   //       #text the only metadatum
   //       no children
   // Reduce to: data set, w/name == name + suffix
   // Sketch:
   //    +---------------+     +----------------+
   //    | name          | ==> | DataSet        | name: name + suffix
   //    |    [metadata] |     |   [Attributes] |
   //    |    #pcdata    |     |    data        |
   //    |       #text   |     +----------------+
   //    |       -       |
   //    +---------------+

   if (node.children.size() == 1 &&
       node.children[0]->name == "#pcdata" &&
       node.children[0]->metadata.size() == 1 &&
       node.children[0]->metadata[0].first == "#text" &&
       node.children[0]->children.size() == 0
   ) {
      // HDF5 data set
      const std::string text = node.children[0]->metadata[0].second;
      HighFive::DataSet dataset = pcdata2DataSet(node.name+suffix, text, hdf5);

      // metadata
      meta2hdf5(node, dataset, suffix);
      return true;
   }

   return false;
}


// -----------------------------------------------------------------------------
// node2hdf5
// -----------------------------------------------------------------------------

// NODE is just GNDStk::Node. The latter isn't used directly, because
// it's an incomplete type at this point.
// OBJECT is either HighFive::File or HighFive::Group.
template<class NODE, class OBJECT>
bool node2hdf5(const NODE &node, OBJECT &h, const std::string &suffix = "")
{
   const std::string nameSuffixed = node.name + suffix;

   // ------------------------
   // Special cases
   // ------------------------

   if (HDF5::reduced && (
      hdf5_reduce_cdata_comment  (node,h,suffix) ||
      hdf5_reduce_pcdata         (node,h,suffix) ||
      hdf5_reduce_pcdata_metadata(node,h,suffix)
   ))
      return true;

   // ------------------------
   // General case
   // ------------------------

   // Create a new Group, in parameter h, for metadata and children
   HighFive::Group group = h.createGroup(nameSuffixed);

   // metadata
   meta2hdf5(node, group, suffix);

   // children - preprocess
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
