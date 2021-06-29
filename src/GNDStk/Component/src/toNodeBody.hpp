
// Starter node
Node node(DERIVED::GNDSName());

// DATA. This call might affect length, etc., so it's made prior to the
// writing of fields.
this->BodyText<hasBodyText>::toNode(node,derived.content);

// FIELDS
if constexpr (std::is_same_v<decltype(DERIVED::keys()),std::tuple<>>) {
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
        (node.add(
            key,
            *(detail::remove_cvref_t<decltype(Node{}(key))> *)links[n++]
         ),
         ...
        );
      },
      tup
   );
}

// Done
return node;
