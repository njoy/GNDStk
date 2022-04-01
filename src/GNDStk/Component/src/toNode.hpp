
// -----------------------------------------------------------------------------
// Component
// Conversion to Node.
// -----------------------------------------------------------------------------

operator Node() const
{
   // Initialize a Node, with the necessary name
   Node node(DERIVED::FIELD());

   try {
      // Handle block data, if applicable
      if constexpr (hasBlockData) {
         // GNDStk uses a "#text" metadatum of a "#pcdata" child node for this
         std::string &text = node.add("#pcdata").add("#text","").second;
         BLOCKDATA::toNode(text);
      }

      // Write fields...

      // consistency check
      assert(std::tuple_size<decltype(Keys().tup)>::value == links.size());

      // apply links:
      // derived-class data ==> Node
      // Below, each apply'd "key" is one value from DERIVED::KEYS(), and
      // is a Meta, Child, or pair<Child,string/regex>. The cast gives the
      // underlying raw data type - int, say, or std::string - so that we
      // can correctly use our generic void* link to a derived-class field.
      std::apply(
         [this,&node](const auto &... key) {
            std::size_t n = 0;
           (node.add(key,*(std::decay_t<decltype(Node{}(key))>*)links[n++]),
            ...);
         },
         Keys().tup
      );
   } catch (...) {
      log::member("Component.operator Node() const");
      throw;
   }

   return node;
}


// -----------------------------------------------------------------------------
// Component
// Conversion to Tree.
// Like conversion to Node, but with a proper root Node.
// -----------------------------------------------------------------------------

operator Tree() const
{
   Tree tree;
   tree.add(Node(*this));
   return tree;
}
