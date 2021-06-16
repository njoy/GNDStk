
// -----------------------------------------------------------------------------
// Component
// conversion to Node
// -----------------------------------------------------------------------------

operator Node() const
{
   try {
      // starter node
      Node node(DERIVED::GNDSName());

      // fields
      if constexpr (
         std::is_same<decltype(DERIVED::keys()),std::tuple<>>::value
      ) {
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
                *(typename detail::remove_cvref<decltype(Node{}(key))>::type *)
                  links[n++]
               ),
               ...
              );
            },
            tup
         );
      }

      // body text, a.k.a. XML "pcdata" (plain character data), if any
      this->BodyText<hasBodyText>::toNode(node);

      // done
      return node;

   } catch (...) {
      log::member("Component.operator Node()");
      throw;
   }
}
