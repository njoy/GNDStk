
// -----------------------------------------------------------------------------
// Helpers
// -----------------------------------------------------------------------------

// scalarAttr
template<class T, class OBJECT>
HighFive::Attribute scalarAttr(
   const std::string &key, const std::string &value,
   OBJECT &hdf5
) {
   T scalar;
   convert(value,scalar);
   return hdf5.createAttribute(key,scalar);
}

// vectorAttr
template<class T, class OBJECT>
HighFive::Attribute vectorAttr(
   const std::string &key, const std::string &value,
   OBJECT &hdf5
) {
   std::vector<T> vector;
   convert(value,vector);
   return hdf5.createAttribute(key,vector);
}

// ------------------------
// vecDataSet
// ------------------------

// <T> helper
template<class T, class OBJECT>
HighFive::DataSet vecDataSet(
   const std::string &key, const std::string &value,
   OBJECT &hdf5
) {
   std::vector<T> vector;
   convert(value,vector);
   return hdf5.createDataSet(key,vector);
}

// w/ type string
template<class OBJECT>
HighFive::DataSet vecDataSet(
   const std::string &key, const std::string &value,
   OBJECT &hdf5
) {
   if (HDF5::typed) {
      const std::string type = guessType(value);
      if (type == "int"    || type == "ints"   )
         return vecDataSet<int          >(key,value,hdf5);
      if (type == "uint"   || type == "uints"  )
         return vecDataSet<unsigned     >(key,value,hdf5);
      if (type == "long"   || type == "longs"  )
         return vecDataSet<long         >(key,value,hdf5);
      if (type == "ulong"  || type == "ulongs" )
         return vecDataSet<unsigned long>(key,value,hdf5);
      if (type == "double" || type == "doubles")
         return vecDataSet<double       >(key,value,hdf5);
   }
   return vecDataSet<std::string>(key,value,hdf5);
}


// -----------------------------------------------------------------------------
// meta2hdf5_typed
// meta2hdf5_plain
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
      // NOT a scalar; while <values>10 20 30</values> would produces a vector
      // with three elements. What may look like scalars are made into vectors
      // because we think that reflects what these (#pcdata) nodes are intended
      // to represent. (If something was really just a scalar, then surely it
      // would be placed into standard metadata (in <...>), not #pcdata.
      if (parent == "#pcdata" && key == "#text") {
         std::string type = guessType(value);
         if (type == "int" || type == "ints")
            vectorAttr<int          >(key,value,hdf5);
         else if (type == "uint" || type == "uints")
            vectorAttr<unsigned     >(key,value,hdf5);
         else if (type == "long" || type == "longs")
            vectorAttr<long         >(key,value,hdf5);
         else if (type == "ulong" || type == "ulongs")
            vectorAttr<unsigned long>(key,value,hdf5);
         else if (type == "double" || type == "doubles")
            vectorAttr<double       >(key,value,hdf5);
         else
            vectorAttr<std::string  >(key,value,hdf5);
         continue;
      }

      // *** key/#text not expected, except as already handled
      if (key == "#text") {
         log::warning("Metadatum name \"#text\" not expected here; "
                      "writing anyway");
         log::function("detail::meta2hdf5_typed(Node named \"{}\", ...)",
                       parent);
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
      if (type == "int"    ) scalarAttr<int          >(key,value,hdf5); else
      if (type == "ints"   ) vectorAttr<int          >(key,value,hdf5); else
      if (type == "uint"   ) scalarAttr<unsigned     >(key,value,hdf5); else
      if (type == "uints"  ) vectorAttr<unsigned     >(key,value,hdf5); else
      if (type == "long"   ) scalarAttr<long         >(key,value,hdf5); else
      if (type == "longs"  ) vectorAttr<long         >(key,value,hdf5); else
      if (type == "ulong"  ) scalarAttr<unsigned long>(key,value,hdf5); else
      if (type == "ulongs" ) vectorAttr<unsigned long>(key,value,hdf5); else
      if (type == "double" ) scalarAttr<double       >(key,value,hdf5); else
      if (type == "doubles") vectorAttr<double       >(key,value,hdf5); else
      /* string or strings*/ scalarAttr<std::string  >(key,value,hdf5);
   }
} // meta2hdf5_typed


// ------------------------
// meta2hdf5_plain
// ------------------------

template<class NODE, class OBJECT>
void meta2hdf5_plain(const NODE &node, OBJECT &hdf5)
{
   for (auto &meta : node.metadata)
      hdf5.createAttribute(meta.first, meta.second);
}


// -----------------------------------------------------------------------------
// meta2hdf5
// -----------------------------------------------------------------------------

// Here, OBJECT hdf5 is either a HighFive::Group or a HighFive::DataSet
template<class NODE, class OBJECT>
void meta2hdf5(const NODE &node, OBJECT &hdf5, const std::string &suffix)
{
   // #nodename if appropriate (as with JSON, allows recovery of original name)
   if (suffix != "")
      hdf5.createAttribute(std::string("#nodename"), node.name);

   // Existing metadata
   if (HDF5::typed) {
      // Use our "guess what's in the string" code to try to infer what each
      // metadatum's string value actually contains (a single int, say, or
      // a vector of doubles). Use the inferred types in the HDF5 file.
      meta2hdf5_typed(node,hdf5);
   } else {
      // Write simple HDF5 in which all data (metadata, as well as the contents
      // of "cdata" and "pcdata" nodes) end up being strings. Not even vectors
      // of strings, as from <values>H He Li ...</values>, but single strings.
      meta2hdf5_plain(node,hdf5);
   }
}


// -----------------------------------------------------------------------------
// node2hdf5
// -----------------------------------------------------------------------------

// Here, OBJECT hdf5 is either a HighFive::File or a HighFive::Group
template<class NODE, class OBJECT>
bool node2hdf5(const NODE &node, OBJECT &hdf5, const std::string &suffix = "")
{
   // As with JSON; see the remark in node2json()
   const std::string nameOriginal = node.name;
   const std::string nameSuffixed = node.name + suffix;

   // ------------------------
   // Specific cases
   // ------------------------

   if (HDF5::reduced) {
      // #cdata or #comment
      //    #text the only metadatum
      //    no children
      // Reduce to: a string attribute, w/name == (#cdata or #comment) + suffix
      // Sketch:
      //    +-----------------+     +-----------+
      //    | #cdata/#comment | ==> | Attribute | name: #... + suffix
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
         hdf5.createAttribute(nameSuffixed,node.metadata[0].second);
         return true;
      }

      // #pcdata
      //    #text the only metadatum
      //    no children
      // Reduce to: a data set, w/name == #pcdata + suffix
      // Sketch:
      //    +----------+     +---------+
      //    | #pcdata  | ==> | DataSet | name: #pcdata + suffix
      //    |    #text |     |    data |
      //    +----------+     +---------+
      //
      if (nameOriginal == "#pcdata" &&
          node.children.size() == 0 &&
          node.metadata.size() == 1 &&
          node.metadata[0].first == "#text"
      ) {
         // Remark. This case (basically, #pcdata/#text) may look superficially
         // like it would have been handled, in the case immediately below here,
         // in the previous (next-up) recurse of the present function. Often
         // it would have, but not always. Below, someName/#pcdata/#text (three
         // levels, so to speak) reduces to one level (DataSet someName), but
         // only if someName has ONE child - the #pcdata. That's true when we
         // have (in XML) something like <values>1 2 3</values>, as the pcdata,
         // i.e. the 1 2 3 part, is <values>' only child node. However, it's
         // actually possible (though I don't see it in current GNDS files) to
         // have something like: <values><foo></foo>1 2 3</values>. There, the
         // outer someName node (<value>) has child foo and child #pcdata, and
         // thus can't be reduced in the manner that's done if only #pcdata is
         // there. In short, then, the present situation comes to pass if and
         // when #pcdata has sibling nodes.

         // dataset
         const std::string value = node.metadata[0].second;
         HighFive::DataSet dataset = vecDataSet(nameSuffixed,value,hdf5);
         return true;
      }

      // someName (think e.g. values, as in XML <values>)
      //    any number of metadata (possible 0)
      //    #pcdata the only child
      //       #text the only metadatum
      //       no children
      // Reduce to: a data set, w/name == someName + suffix
      // Sketch:
      //    +---------------+     +----------------+
      //    | someName      | ==> | DataSet        | name: someName + suffix
      //    |    [metadata] |     |   [Attributes] |
      //    |    #pcdata    |     |    data        |
      //    |       #text   |     +----------------+
      //    |       -       |
      //    +---------------+
      //
      if (node.children.size() == 1 &&
          node.children[0]->name == "#pcdata" &&
          node.children[0]->metadata.size() == 1 &&
          node.children[0]->metadata[0].first == "#text" &&
          node.children[0]->children.size() == 0
      ) {
         // dataset
         const std::string value = node.children[0]->metadata[0].second;
         HighFive::DataSet dataset = vecDataSet(nameSuffixed,value,hdf5);
         // metadata, then done; the #pcdata child was rolled into the data set
         meta2hdf5(node,dataset,suffix);
         return true;
      }
   } // if (HDF5::reduced)

   // ------------------------
   // General case
   // ------------------------

   // subgroup
   HighFive::Group group = hdf5.createGroup(nameSuffixed);

   // metadata
   meta2hdf5(node,group,suffix);

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
      if (!node2hdf5(*c, group, counter ? std::to_string(counter-1) : ""))
         return false;
   }

   // done
   return true;
}
