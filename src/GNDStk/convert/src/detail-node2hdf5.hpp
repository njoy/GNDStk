
// -----------------------------------------------------------------------------
// Helpers
// -----------------------------------------------------------------------------

// scalarAttr
template<class T, class OBJECT>
HighFive::Attribute scalarAttr(
   const std::string &key, const std::string &value,
   OBJECT &hdf
) {
   T scalar;
   convert(value,scalar);
   return hdf.createAttribute(key,scalar);
}

// vectorAttr
template<class T, class OBJECT>
HighFive::Attribute vectorAttr(
   const std::string &key, const std::string &value,
   OBJECT &hdf
) {
   std::vector<T> vector;
   convert(value,vector);
   return hdf.createAttribute(key,vector);
}

// vecDataSet
template<class T, class OBJECT>
HighFive::DataSet vecDataSet(
   const std::string &key, const std::string &value,
   OBJECT &hdf
) {
   std::vector<T> vector;
   convert(value,vector);
   return hdf.createDataSet(key,vector);
}

// vecDataSet, w/ type string
template<class OBJECT>
HighFive::DataSet vecDataSet(
   const std::string &key, const std::string &value,
   OBJECT &hdf
) {
   const std::string type = guessType(value);
   return
      type == "int"    || type == "ints"    ?
         vecDataSet<int          >(key,value,hdf) :
      type == "uint"   || type == "uints"   ?
         vecDataSet<unsigned     >(key,value,hdf) :
      type == "long"   || type == "longs"   ?
         vecDataSet<long         >(key,value,hdf) :
      type == "ulong"  || type == "ulongs"  ?
         vecDataSet<unsigned long>(key,value,hdf) :
      type == "double" || type == "doubles" ?
         vecDataSet<double       >(key,value,hdf) :
      // "string", "strings", or ""
         vecDataSet<std::string  >(key,value,hdf) ;
}


// -----------------------------------------------------------------------------
// typedHDF5
// -----------------------------------------------------------------------------

template<class NODE, class OBJECT>
void typedHDF5(const NODE &node, OBJECT &hdf)
{
   const std::string &parent = node.name;

   for (auto &meta : node.metadata) {
      const std::string &key = meta.first;
      const std::string &value = meta.second;

      // *** #cdata/#text
      // *** #comment/#text
      // ACTION: Write these as-is. That is, do NOT apply our type-guessing code
      // to a comment, or to the contents of a <![CDATA[...]]> block like those
      // that we see in existing XML-format GNDS files. The type guesser would
      // see words, and think "vector of [whitespace-separated] strings," which
      // would be painfully wrong for what are clearly free-form strings.
      if (key == "#text" && (parent == "#cdata" || parent == "#comment")) {
         hdf.createAttribute(key,value); // just a simple string attribute
         continue;
      }

      // *** #pcdata/#text
      // ACTION: Apply our type-guessing code, but write *vectors* only, never
      // scalars. So, <values>10</values> would be interpreted as a vector with
      // one element, NOT as a scalar; while <values>10 20 30</values> would be
      // interpreted as a vector with three elements. What may look like scalars
      // are folded into vectors because we think that reflects what nodes like
      // this are intended to represent. (If something was really just a scalar,
      // then surely it would be placed in the metadata, not in a node such as
      // <values>scalar</values>.)
      if constexpr (std::is_same_v<OBJECT,HighFive::Group>) {
         if (key == "#text" && parent == "#pcdata") {
            vecDataSet(key,value,hdf); // DataSet will have name "#text"
            continue;
         }
      }

      // *** key/#text not expected except as already handled
      if (key == "#text") {
         log::warning("Metadatum name \"#text\" not expected here; "
                      "writing anyway");
         log::function("detail::typedHDF5(Node named \"{}\", ...)", parent);
      }

      // *** key/value
      // General case
      // ACTION: Apply our type-guessing code almost fully, except that for
      // a metadatum="that looks like this", interpret "..." as essentially
      // a single descriptive string. So, don't split it up into a vector.
      const std::string type = guessType(value);
      type == "int"     ? scalarAttr<int          >(key,value,hdf) :
      type == "ints"    ? vectorAttr<int          >(key,value,hdf) :
      type == "uint"    ? scalarAttr<unsigned     >(key,value,hdf) :
      type == "uints"   ? vectorAttr<unsigned     >(key,value,hdf) :
      type == "long"    ? scalarAttr<long         >(key,value,hdf) :
      type == "longs"   ? vectorAttr<long         >(key,value,hdf) :
      type == "ulong"   ? scalarAttr<unsigned long>(key,value,hdf) :
      type == "ulongs"  ? vectorAttr<unsigned long>(key,value,hdf) :
      type == "double"  ? scalarAttr<double       >(key,value,hdf) :
      type == "doubles" ? vectorAttr<double       >(key,value,hdf) :
      /* else........ */  scalarAttr<std::string  >(key,value,hdf) ;
   }
}


// -----------------------------------------------------------------------------
// Meta2HDF5
// -----------------------------------------------------------------------------

// Here, OBJECT hdf is either a HighFive::Group or a HighFive::DataSet
template<class NODE, class OBJECT>
void Meta2HDF5(const NODE &node, OBJECT &hdf, const std::string &suffix)
{
   // #nodeName if appropriate (as with JSON, allows recovery of original name)
   if (suffix != "")
      hdf.createAttribute(std::string("#nodeName"), node.name);

   // Existing attributes
   if (HDF5::typed) {
      // Use our "guess what's in the string" code to try to infer what certain
      // "string" values actually contain (a single int, say, or a vector of
      // doubles). Then, use the inferred types in the HDF5 file.
      typedHDF5(node,hdf);
   } else {
      // Write simple HDF5 where all data (metadata, and the content of "cdata"
      // and "pcdata" nodes) end up being strings. Not even vectors of strings
      // (as from <values>H He Li ...</values>), but single strings.
      for (auto &meta : node.metadata)
         hdf.createAttribute(meta.first, meta.second);
   }
}


// -----------------------------------------------------------------------------
// Node2HDF5
// -----------------------------------------------------------------------------

// Here, OBJECT hdf is either a HighFive::File or a HighFive::Group
template<class NODE, class OBJECT>
bool Node2HDF5(const NODE &node, OBJECT &hdf, const std::string &suffix = "")
{
   // As with JSON; see the remark in node2json()
   const std::string nameOriginal = node.name;
   const std::string nameSuffixed = node.name + suffix;

   // ------------------------
   // Specific cases
   // ------------------------

   if (HDF5::flat) {
      // #cdata or #comment
      //    #text the only metadatum
      //    no children
      // Reduce to: a string attribute, w/name == (#cdata or #comment) + suffix
      // Brief:
      //    +-----------------+     +-----------+
      //    | #cdata/#comment | ==> | Attribute |
      //    |    #text        |     |    value  |
      //    |    -            |     +-----------+
      //    +-----------------+
      //
      if (
         (nameOriginal == "#cdata" || nameOriginal == "#comment") &&
          node.children.size() == 0 &&
          node.metadata.size() == 1 &&
          node.metadata[0].first == "#text"
      ) {
         // attribute
         hdf.createAttribute(nameSuffixed,node.metadata[0].second);
         return true;
      }

      // #pcdata
      //    #text the only metadatum
      //    no children
      // Reduce to: a data set, w/name == #pcdata + suffix
      // Brief:
      //    +----------+     +---------+
      //    | #pcdata  | ==> | DataSet |
      //    |    #text |     |    data |
      //    +----------+     +---------+
      //
      if (nameOriginal == "#pcdata" &&
          node.children.size() == 0 &&
          node.metadata.size() == 1 &&
          node.metadata[0].first == "#text"
      ) {
         // dataset
         const std::string value = node.metadata[0].second;
         HighFive::DataSet dataset = vecDataSet(nameSuffixed,value,hdf);
         return true;
      }

      // someName (think e.g. values, as in XML <values>)
      //    any number of metadata
      //    #pcdata the only child
      //       #text the only metadatum
      //       no children
      // Reduce to: a data set, w/name == someName + suffix
      // Brief:
      //    +--------------+     +---------------+
      //    | someName     | ==> | DataSet       |
      //    |    metadata  |     |    Attributes |
      //    |    #pcdata   |     |    data       |
      //    |       #text  |     +---------------+
      //    |       -      |
      //    +--------------+
      //
      if (node.children.size() == 1 &&
          node.children[0]->name == "#pcdata" &&
          node.children[0]->metadata.size() == 1 &&
          node.children[0]->metadata[0].first == "#text" &&
          node.children[0]->children.size() == 0
      ) {
         // dataset
         const std::string value = node.children[0]->metadata[0].second;
         HighFive::DataSet dataset = vecDataSet(nameSuffixed,value,hdf);
         // metadata, then done; the #pcdata child was rolled into the data set
         Meta2HDF5(node,dataset,suffix);
         return true;
      }
   }

   // ------------------------
   // General case
   // ------------------------

   // subgroup
   HighFive::Group group = hdf.createGroup(nameSuffixed);

   // metadata
   Meta2HDF5(node,group,suffix);

   // children
   // Logic is as with JSON; see the remark in node2json().
   std::map<std::string,std::size_t> childNames;
   for (auto &c : node.children) {
      auto iter = childNames.find(c->name);
      if (iter == childNames.end())
         childNames.insert({c->name,0});
      else
         iter->second = 1;
   }
   for (auto &c : node.children) {
      const std::size_t counter = childNames.find(c->name)->second++;
      if (!Node2HDF5(*c, group, counter ? std::to_string(counter-1) : ""))
         return false;
   }

   // done
   return true;
}
