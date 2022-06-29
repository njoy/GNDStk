
// 1. Initialize a Node, with the necessary name
Node node(DERIVED::GNDSName());

// 2. Body text, if applicable
if constexpr (hasBlockData) {
   // GNDStk uses a "text" metadatum of a "pcdata" child node for this
   std::string &text = node.add("pcdata").add("text","").second;
   // Note: the following call might compute length, start, and valueType;
   // so we need all of this before the upcoming writing of fields.
   body::toNode(text,derived().content);
}

// 3. Write fields
if constexpr (!hasFields) {
   // consistency check
   assert(0 == links.size());
} else {
   // make tuple (of individual keys) from DERIVED::keys()
   const auto tup = toKeywordTup(DERIVED::keys()).tup;

   // consistency check
   assert(std::tuple_size<decltype(tup)>::value == links.size());

   // apply links:
   // derived-class data ==> Node
   // Below, each apply'd "key" is one value from DERIVED::keys(), and
   // is a Meta, Child, or pair<Child,string/regex>. The cast gives the
   // underlying raw data type - int, say, or std::string - so that we
   // can correctly use our generic void* link to a derived-class field.
   std::apply(
      [this,&node](const auto &... key) {
         std::size_t n = 0;
        (node.add(key,*(std::decay_t<decltype(Node{}(key))>*)links[n++]), ...);
      },
      tup
   );
}

return node;
