
// -----------------------------------------------------------------------------
// Helpers
// -----------------------------------------------------------------------------

// scalar2Value
template<class T>
void scalar2Value(
   const std::string &key, const std::string &value,
   orderedJSON &json
) {
   // Parameter "value" is a string, for example "1", "2.34", or "foo"; then,
   // the caller will have guessed T == int, T == double, or T == std::string.
   // We wish to write value AS-IS into the value of a JSON key/value pair, but
   // with quotes only when T == std::string. That way, for other T, we don't
   // convert value to a T, and then back to a string for the JSON file. That
   // would be inefficient, and would break our handling of significant digits.

   if constexpr (std::is_same_v<T,std::string>) {
      // Write JSON string.
      json[key] = value;
   } else {
      // Write JSON number (so unquoted, unlike in the string case above),
      // but write the "number" exactly as it appears in parameter value,
      // which the caller guessed contains a number: "1", "2.34", etc.
      //
      // fixme Unfortunately, the nlohmann/json library does not, at the
      // present time, allow us to write our string as a number - without
      // quotes. It'll format the number as it wants to. Given that GNDStk
      // allows fine control over the formatting of floating-point numbers,
      // we'll need to deal with this at some point, to have the formatting
      // respected in JSON output.
      T scalar;
      convert(value,scalar);
      json[key] = scalar;
   }
}

// vector2Value
template<class T>
void vector2Value(
   const std::string &key, const std::string &value,
   orderedJSON &json
) {
   // Like the scalar case, but value is for example be "1 2", "3.4 5.6 7.8",
   // or "foo bar baz" - a vector of T == int, T = double, or T == std::string.
   if constexpr (std::is_same_v<T,std::string>) {
      // Write JSON array of strings.
      std::vector<T> vector;
      convert(value,vector); // single string ==> vector<string>
      json[key] = vector;
   } else {
      // Write JSON array of numbers.
      // fixme Basically the same fixme as above.
      std::vector<T> vector;
      convert(value,vector);
      json[key] = vector;
   }
}

// pcdata2Value
inline void pcdata2Value(
   const std::string &key, const std::string &value,
   orderedJSON &json
) {
   if (JSON::typed) {
      const std::string type = guessType(value);
      if (type == "int"    || type == "ints"   )
         { vector2Value<int          >(key,value,json); return; }
      if (type == "uint"   || type == "uints"  )
         { vector2Value<unsigned     >(key,value,json); return; }
      if (type == "long"   || type == "longs"  )
         { vector2Value<long         >(key,value,json); return; }
      if (type == "ulong"  || type == "ulongs" )
         { vector2Value<unsigned long>(key,value,json); return; }
      if (type == "double" || type == "doubles")
         { vector2Value<double       >(key,value,json); return; }
   }
   vector2Value<std::string>(key,value,json);
}


// -----------------------------------------------------------------------------
// meta2json*
// -----------------------------------------------------------------------------

// ------------------------
// meta2json_typed
// ------------------------

// Use our "guess what's in the string" code to try to infer what each
// metadatum's string value actually contains (a single int, say, or
// a vector of doubles). Use the inferred types in the JSON file.
template<class NODE>
void meta2json_typed(const NODE &node, orderedJSON &json)
{
   // Current node is the parent of its metadata
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
         json[key] = value; // just a simple string value
         continue;
      }

      // *** #pcdata/#text
      // ACTION: Apply our type-guessing code, but write *vectors* only, never
      // scalars. So, <values>10</values> produces a vector with one element,
      // NOT a scalar; while <values>10 20 30</values> produces a vector with
      // three elements. What may look like scalars are made into vectors
      // because we think this reflects what these (#pcdata) nodes are intended
      // to represent. (If something was really just a scalar, then surely it
      // would be placed into standard metadata (in <...>), not #pcdata.
      if (parent == "#pcdata" && key == "#text") {
         const std::string type = guessType(value);
         if (type == "int" || type == "ints")
            vector2Value<int          >(key,value,json);
         else if (type == "uint" || type == "uints")
            vector2Value<unsigned     >(key,value,json);
         else if (type == "long" || type == "longs")
            vector2Value<long         >(key,value,json);
         else if (type == "ulong" || type == "ulongs")
            vector2Value<unsigned long>(key,value,json);
         else if (type == "double" || type == "doubles")
            vector2Value<double       >(key,value,json);
         else
            vector2Value<std::string  >(key,value,json);
         continue;
      }

      // *** key/#text not expected, except as already handled
      if (key == "#text") {
         log::warning("Metadatum \"#text\" not expected here; writing anyway");
         log::function("detail::meta2json(Node named \"{}\", ...)", parent);
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
      if (type == "int"    ) scalar2Value<int          >(key,value,json); else
      if (type == "ints"   ) vector2Value<int          >(key,value,json); else
      if (type == "uint"   ) scalar2Value<unsigned     >(key,value,json); else
      if (type == "uints"  ) vector2Value<unsigned     >(key,value,json); else
      if (type == "long"   ) scalar2Value<long         >(key,value,json); else
      if (type == "longs"  ) vector2Value<long         >(key,value,json); else
      if (type == "ulong"  ) scalar2Value<unsigned long>(key,value,json); else
      if (type == "ulongs" ) vector2Value<unsigned long>(key,value,json); else
      if (type == "double" ) scalar2Value<double       >(key,value,json); else
      if (type == "doubles") vector2Value<double       >(key,value,json); else
      /* string OR strings*/ scalar2Value<std::string  >(key,value,json);
   }
} // meta2json_typed


// ------------------------
// meta2json_plain
// ------------------------

// Write simple JSON in which all metadata, as well as the contents
// of "cdata" and "pcdata" nodes) end up being strings. Not even vectors
// of strings, as from <values>H He Li ...</values>, but single strings.
template<class NODE>
void meta2json_plain(const NODE &node, orderedJSON &json)
{
   for (auto &meta : node.metadata)
      json[meta.first] = meta.second;
}


// ------------------------
// meta2json
// ------------------------

template<class NODE>
void meta2json(
   const NODE &node, orderedJSON &json, const std::string &suffix,
   const std::string &base = ""
) {
   // Create #nodename iff necessary (allows recovery of original node name)
   if (suffix != "")
      json[base+"#nodename"] = node.name;

   // Existing metadata
   if (node.metadata.size())
      JSON::typed
         ? meta2json_typed(node,json[base+"#metadata"])
         : meta2json_plain(node,json[base+"#metadata"]);
}


// -----------------------------------------------------------------------------
// json_reduce_*
// -----------------------------------------------------------------------------

// ------------------------
// json_reduce_cdata_comment
// ------------------------

// Simplify certain #cdata and #comment cases.
template<class NODE>
bool json_reduce_cdata_comment(
   const NODE &node, orderedJSON &json, const std::string &suffix
) {
   // Original node name, and suffixed name. The latter is for handling child
   // nodes of the same name under the same parent node, and includes a numeric
   // suffix (so, name0, name1, etc.) in that scenario. This is needed for JSON
   // because JSON doesn't support same-named child nodes. In cases where the
   // name was unique to begin with, nameOriginal == nameSuffixed.
   const std::string nameOriginal = node.name;
   const std::string nameSuffixed = node.name + suffix;

   // #cdata or #comment
   //    #text the only metadatum
   //    no children
   // Reduce to: string value, w/name == (#cdata or #comment) + suffix
   // Sketch:
   //    +-----------------+     +------------+
   //    | #cdata/#comment | ==> | "name" :   | name: #cdata/#comment + suffix
   //    |    #text        |     |    "value" |
   //    +-----------------+     +------------+

   if (
      (nameOriginal == "#cdata" || nameOriginal == "#comment") &&
       node.children.size() == 0 &&
       node.metadata.size() == 1 &&
       node.metadata[0].first == "#text"
   ) {
      // string value
      json[nameSuffixed] = node.metadata[0].second;
      return true;
   }

   return false;
}


// ------------------------
// json_reduce_pcdata
// ------------------------

// Simplify #pcdata case.
template<class NODE>
bool json_reduce_pcdata(
   const NODE &node, orderedJSON &json, const std::string &suffix
) {
   const std::string nameOriginal = node.name;
   const std::string nameSuffixed = node.name + suffix;

   // #pcdata
   //    #text the only metadatum
   //    no children
   // Reduce to: array, w/name == #pcdata + suffix
   // Sketch:
   //    +----------+     +----------+
   //    | #pcdata  | ==> | "name" : | name: #pcdata + suffix
   //    |    #text |     |    [...] |
   //    +----------+     +----------+

   if (nameOriginal == "#pcdata" &&
       node.children.size() == 0 &&
       node.metadata.size() == 1 &&
       node.metadata[0].first == "#text"
   ) {
      // Remark. This case (basically, #pcdata/#text) may look superficially
      // like it would have been handled, in the case immediately below here,
      // in the previous (next-up) recurse of the node2json() function. Often
      // it would have, but not always. Later, name/#pcdata/#text (three
      // levels, so to speak) reduces to one level (name : [...]), but
      // only if name has ONE child - the #pcdata. That's true when we
      // have (in XML) something like <values>1 2 3</values>, as the pcdata,
      // i.e. the 1 2 3 part, is <values>' only child node. However, it's
      // actually possible (though I don't see it in current GNDS files) to
      // have something like: <values><foo></foo>1 2 3</values>. There, the
      // outer "name" node (<value>) has child foo and child #pcdata, and
      // thus can't be reduced in the manner that's done if only #pcdata is
      // there. In short, then, the present situation comes to pass if and
      // when #pcdata has sibling nodes.

      // JSON array
      pcdata2Value(nameSuffixed, node.metadata[0].second, json);
      return true;
   }

   return false;
}


// ------------------------
// json_reduce_pcdata_metadata
// ------------------------

// Simplify case of node with #pcdata AND metadata
template<class NODE>
bool json_reduce_pcdata_metadata(
   const NODE &node, orderedJSON &json, const std::string &suffix
) {
   const std::string nameSuffixed = node.name + suffix;

   // name (think e.g. "values", as in XML <values>)
   //    any number of metadata (possibly 0)
   //    #pcdata the only child
   //       #text the only metadatum
   //       no children
   // Reduce to: array, w/name == name + suffix; separately encoded metadata
   // Sketch:
   //    +---------------+     +----------------------+
   //    | name          | ==> | "name" :             | name: name + suffix
   //    |    [metadata] |     |    [...]             |
   //    |    #pcdata    |     | "name#metadata" : {  |
   //    |       #text   |     |    key/value pairs   |
   //    |       -       |     | }                    |
   //    +---------------+     +----------------------+

   if (node.children.size() == 1 &&
       node.children[0]->name == "#pcdata" &&
       node.children[0]->metadata.size() == 1 &&
       node.children[0]->metadata[0].first == "#text" &&
       node.children[0]->children.size() == 0
   ) {
      // JSON array
      const std::string text = node.children[0]->metadata[0].second;
      pcdata2Value(nameSuffixed, text, json);

      // metadata
      meta2json(node, json, suffix, nameSuffixed);
      return true;
   }

   return false;
}


// -----------------------------------------------------------------------------
// node2json
// -----------------------------------------------------------------------------

// NODE is just GNDStk::Node. The latter isn't used directly, because
// it's an incomplete type at this point.
template<class NODE>
bool node2json(
   const NODE &node, orderedJSON &j,
   const std::string &suffix = ""
) {
   const std::string nameSuffixed = node.name + suffix;

   // ------------------------
   // Special cases
   // ------------------------

   if (JSON::reduced && (
      json_reduce_cdata_comment  (node,j,suffix) ||
      json_reduce_pcdata         (node,j,suffix) ||
      json_reduce_pcdata_metadata(node,j,suffix)
   ))
      return true;

   // ------------------------
   // General case
   // ------------------------

   // Create a new ordered_json, in parameter j, for metadata and children
   orderedJSON &json = j[nameSuffixed];

   // metadata
   meta2json(node, json, suffix);

   // children - preprocess
   // First, account for what children appear in the current node. If any child
   // name appears multiple times, we must deal with that. For each represented
   // child name, the map gets 0 if the name appears once, 1 if it appears more
   // than once. Later, this 0/1 is used initially to make a boolean choice;
   // then it serves as a counter to generate a 0-indexed numeric suffix that
   // makes the child names unique: name0, name1, etc.
   std::map<std::string,std::size_t> childNames;
   for (auto &c : node.children) {
      auto iter = childNames.find(c->name);
      if (iter == childNames.end())
         childNames.insert({c->name,0}); // once (so far)
      else
         iter->second = 1; // more than once
   }

   // children
   for (auto &c : node.children) {
      const std::size_t counter = childNames.find(c->name)->second++;
      if (!node2json(*c, json, counter ? std::to_string(counter-1) : ""))
         return false;
   }

   // done
   return true;
}
