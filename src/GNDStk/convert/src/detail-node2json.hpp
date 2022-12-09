
// -----------------------------------------------------------------------------
// Helpers
// -----------------------------------------------------------------------------

// ------------------------
// scalar2Value
// vector2Value
// ------------------------

// scalar2Value
template<class T>
void scalar2Value(
   const std::string &key, const std::string &value,
   orderedJSON &json
) {
   // Parameter "value" is a string - for example "1", "2.34", or "foo". The
   // caller will have guessed T == int, T == double, or T == std::string in
   // those cases. In the present function, we wish to write std::string value
   // AS-IS into the value part of a JSON key/value pair. However, when T is
   // a number, like int or double, we wish to write it as a JSON number - so,
   // without quotes. In constrast, only when T == std::string will we write
   // it as a JSON string. Note that even when it's really a number, the value
   // parameter arrives here as a std::string, because our (very customizable)
   // handling of formatting and significant digits requires this. Here, right
   // now, we can assume that a "number" inside std::string reflects the exact
   // way that we want the number to be printed.

   if constexpr (std::is_same_v<T,std::string>) {
      // Write JSON string.
      json[key] = value;
   } else {
      // Write JSON number (so unquoted, unlike in the string case above),
      // but write the "number" exactly as it appears in parameter "value",
      // which the caller guessed contains a number: "1", "2.34", etc.
      //
      // fixme Unfortunately, the nlohmann/json library does not, at the
      // present time, allow us to write our string as a number - without
      // quotes. It'll format the number as it wants to. Given that GNDStk
      // allows fine control over the formatting of floating-point numbers,
      // we'll need to deal with this at some point, to have our formatting
      // be respected in JSON output.
      T scalar;
      convert(value,scalar);
      json[key] = scalar; // For now. Later, write the value literally
   }
}

// vector2Value
template<class T>
void vector2Value(
   const std::string &key, const std::string &value,
   orderedJSON &json
) {
   // Like the scalar case, but value is, for example, "1 2", "3.4 5.6 7.8",
   // or "foo bar baz" - a vector of T == int, T = double, or T == std::string.
   if constexpr (std::is_same_v<T,std::string>) {
      // Write JSON array of strings.
      std::vector<T> vector;
      convert(value,vector); // single string ==> vector<string>
      json[key] = vector;
   } else {
      // Write JSON array of numbers.
      // fixme Basically, the same fixme as above. For now, the "else" code
      // here is the same as the "if" code, but that'll change.
      std::vector<T> vector; // For now. Later, std::vector<std::string>...
      convert(value,vector);
      json[key] = vector; // For now. Later, write each string literally
   }
}


// ------------------------
// pcdata2Value
// ------------------------

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

      // *** CDATA/TEXT
      // *** COMMENT/TEXT
      // ACTION: Write these as-is. That is, do NOT apply our type-guessing code
      // to a comment, or to the contents of a <![CDATA[...]]> block like those
      // that we see in existing XML-format GNDS files. The type guesser would
      // see words, and think "vector of [whitespace-separated] strings," which
      // would be wrong for what are clearly intended to be free-form strings.
      if ((parent == special::cdata ||
           parent == special::comment) && key == special::text) {
         json[key] = value; // just a simple string value
         continue;
      }

      // *** PCDATA/TEXT
      // ACTION: Apply our type-guessing code, but write *vectors* only, never
      // scalars. So, <values>10</values> produces a vector with one element,
      // NOT a scalar; while <values>10 20 30</values> produces a vector with
      // three elements. What may look like scalars are made into vectors
      // because we think this reflects what these (PCDATA) nodes are intended
      // to represent. (If something was really just a scalar, then surely it
      // would be placed into standard metadata (in <...>), not into PCDATA.
      if (parent == special::data && key == special::text) {
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

      // *** key/TEXT not expected, except as already handled
      if (key == special::text) {
         log::warning("Metadatum \"{}\" not expected here; writing anyway",
                      special::text);
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
   const NODE &node, orderedJSON &json,
   const std::string &base,
   const std::string &digits,
   const std::string &prefix
) {
   // Create NODENAME iff necessary, to allow recovery of the node's original
   // name. Note that NODENAME is not necessary for special nodes, in particular
   // CDATA, PCDATA, and COMMENT. For those, we can reliably reconstruct the
   // original name by removing trailing digits. A regular node, in contrast,
   // *might* have an actual name that has trailing digits (one user called a
   // node "sigma0", for example); or, trailing digits might have been added -
   // by us - solely for the purpose of disambiguating same-named child nodes
   // (for example, "sigma") that appeared multiple times under the same XML
   // parent (which is allowed), but which can't appear that way in JSON. (JSON
   // doesn't allow duplicate keys in the same object).
   if (digits != "" && // will have suffixed digits
      !beginsin(base,std::string(1,special::prefix))) // isn't special
      json[prefix + special::nodename] = node.name;

   // Existing metadata
   // Remark: we could do without the "if (node.metadata.size())" conditional,
   // except that the "json[...]" expressions have the side effect of creating
   // JSON values (nulls to start with, until/unless something is added later).
   // We don't want those to be created at all here if they won't end up having
   // anything, in this case metadata, added to them.
   if (node.metadata.size())
      JSON::typed
         ? meta2json_typed(node, json[prefix + special::metadata])
         : meta2json_plain(node, json[prefix + special::metadata]);
}


// -----------------------------------------------------------------------------
// json_reduce_*
// -----------------------------------------------------------------------------

// ------------------------
// json_reduce_cdata_comment
// ------------------------

// Simplify certain CDATA and COMMENT cases.
template<class NODE>
bool json_reduce_cdata_comment(
   const NODE &node, orderedJSON &json, const std::string &digits
) {
   // Original node name, and suffixed name. The latter is for handling child
   // nodes of the same name under the same parent node, and includes a numeric
   // suffix (so, name0, name1, etc.) in that scenario. This is needed for JSON
   // because JSON doesn't support same-named child nodes. In cases where the
   // name was unique to begin with, nameOriginal == nameSuffixed.
   const std::string nameOriginal = node.name;
   const std::string nameSuffixed = node.name + digits;

   // CDATA or COMMENT
   //    TEXT the only metadatum
   //    no children
   // Reduce to: string value, w/name == (CDATA or COMMENT) + digits
   // Sketch:
   //    +---------------+     +------------+
   //    | CDATA/COMMENT | ==> | "name" :   | name: CDATA/COMMENT + digits
   //    |    TEXT       |     |    "value" |
   //    +---------------+     +------------+

   if (
      (nameOriginal == special::cdata || nameOriginal == special::comment) &&
       node.children.size() == 0 &&
       node.metadata.size() == 1 &&
       node.metadata[0].first == special::text
   ) {
      // string value
      json[nameSuffixed] = node.metadata[0].second;
      return true;
   }

   return false;
}


// ------------------------
// json_reduce_data
// ------------------------

// Simplify PCDATA case.
template<class NODE>
bool json_reduce_data(
   const NODE &node, orderedJSON &json, const std::string &digits
) {
   const std::string nameOriginal = node.name;
   const std::string nameSuffixed = node.name + digits;

   // PCDATA
   //    TEXT the only metadatum
   //    no children
   // Reduce to: array, w/name == PCDATA + digits
   // Sketch:
   //    +---------+     +----------+
   //    | PCDATA  | ==> | "name" : | name: PCDATA + digits
   //    |    TEXT |     |    [...] |
   //    +---------+     +----------+

   if (nameOriginal == special::data &&
       node.children.size() == 0 &&
       node.metadata.size() == 1 &&
       node.metadata[0].first == special::text
   ) {
      // Remark. This case (basically, PCDATA/TEXT) may look superficially
      // like it would have been handled, in the case immediately below here,
      // in the previous (next-up) recurse of the node2json() function. Often
      // it would have, but not always. Later, name/PCDATA/TEXT (three
      // levels, so to speak) reduces to one level (name : [...]), but
      // only if name has ONE child - the PCDATA. That's true when we
      // have (in XML) something like <values>1 2 3</values>, as the pcdata,
      // i.e. the 1 2 3 part, is <values>' only child node. However, it's
      // actually possible (though I don't see it in current GNDS files) to
      // have something like: <values><foo></foo>1 2 3</values>. There, the
      // outer "name" node (<value>) has child foo and child PCDATA, and
      // thus can't be reduced in the manner that's done if only PCDATA is
      // there. In short, then, the present situation comes to pass if and
      // when PCDATA has sibling nodes.

      // JSON array
      pcdata2Value(nameSuffixed, node.metadata[0].second, json);
      return true;
   }

   return false;
}


// ------------------------
// json_reduce_data_metadata
// ------------------------

// Simplify case of node with PCDATA AND metadata
template<class NODE>
bool json_reduce_data_metadata(
   const NODE &node, orderedJSON &json, const std::string &digits
) {
   const std::string nameSuffixed = node.name + digits;

   // name (think e.g. "values", as in XML <values>)
   //    any number of metadata (possibly 0)
   //    PCDATA the only child
   //       TEXT the only metadatum
   //       no children
   // Reduce to: array, w/name == name + digits; separately encoded metadata
   // Sketch:
   //    +---------------+     +---------------------+
   //    | name          | ==> | "name" :            | name: name + digits
   //    |    [metadata] |     |    [...]            |
   //    |    PCDATA     |     | "nameMETADATA" : {  |
   //    |       TEXT    |     |    key/value pairs  |
   //    |       -       |     | }                   |
   //    +---------------+     +---------------------+
   // Remark. We're not super psyched about the "name#metadata" construction.
   // It effectively splits the original node into two siblings in the JSON
   // file; and, it differs from the present scenario's HDF5 handling, which
   // places those metadata into HDF5 "attributes" within an HDF5 "data set".
   // Here, the analog would be to place the metadata into the [...] part.
   // That's doable, because JSON arrays are polymorphic, but we believe it
   // would clutter the [...] with elements that would need to be interpreted,
   // by whatever tool someone might use to process the JSON file, separately
   // from how the rest of the [...] is interpreted. With HDF5 that probably
   // isn't an issue, because a data set's *attributes*, while residing in the
   // data set, would presumably be seen by HDF5 tools as logically distinct
   // from its *data* proper. With JSON, we don't see how that would happen.
   // Hence, our choice above. An important thing is that the above system
   // is reversible - a file, thus written, can be read back in, recovering
   // our original internal data structure unambiguously. Also, the two JSON
   // constructs, "name" and "nameMETADATA", will appear next to each other,
   // allowing someone who looks at the file to see what's going on.

   if (node.children.size() == 1 &&
       node.children[0]->name == special::data &&
       node.children[0]->metadata.size() == 1 &&
       node.children[0]->metadata[0].first == special::text &&
       node.children[0]->children.size() == 0
   ) {
      // JSON array
      const std::string text = node.children[0]->metadata[0].second;
      pcdata2Value(nameSuffixed, text, json);

      // metadata
      meta2json(node, json, node.name, digits, nameSuffixed);
      return true;
   }

   return false;
}


// -----------------------------------------------------------------------------
// node2json
// -----------------------------------------------------------------------------

// NODE is just GNDStk::Node. The latter isn't used directly, because
// it's an "incomplete type", to the compiler, at this point.
template<class NODE>
bool node2json(const NODE &node, orderedJSON &j, const std::string &digits = "")
{
   const std::string nameSuffixed = node.name + digits;

   // ------------------------
   // Special cases
   // ------------------------

   if (JSON::reduced && (
      json_reduce_cdata_comment(node,j,digits) ||
      json_reduce_data         (node,j,digits) ||
      json_reduce_data_metadata(node,j,digits)
   ))
      return true;

   // ------------------------
   // General case
   // ------------------------

   // Create a new orderedJSON, in parameter j, for metadata and children
   orderedJSON &json = j[nameSuffixed];

   // metadata
   meta2json(node, json, node.name, digits, "");

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
