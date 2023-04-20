
// -----------------------------------------------------------------------------
// Helpers
// -----------------------------------------------------------------------------

private:

template<class KEY>
void node_add(
   Node &node, const KEY &key,
   const size_t n
) const {
   using TYPE = typename detail::queryResult<KEY>::type;
   node.add(key, *(TYPE *)links[n]);
}

// todo See if Child|"string" can be formulated without this std::pair
// business; doing so may simplify some things here and there, and we'll
// no longer need this...
template<class KEY>
void node_add(
   Node &node, const std::pair<KEY,std::string> &pair,
   const size_t n
) const {
   node_add(node,pair.first,n);
}


// -----------------------------------------------------------------------------
// Component
// Conversion to Node.
// -----------------------------------------------------------------------------

public:

explicit operator Node() const
{
   // Initialize a Node, with the necessary name
   Node node(DERIVED::NODENAME());

   try {
      // Handle block data, if applicable
      if constexpr (hasBlockData) {
         // GNDStk uses a #text metadatum of a #data child node for this
         std::string &text =
            node.add(special::data).add(special::text,"").second;
         BLOCKDATA::toNode(text);
      }

      // Write fields...

      // consistency check
      assert(std::tuple_size_v<decltype(Keys().tup)> == links.size());

      // apply links:
      // derived-class data ==> Node
      // Below, each apply'd "key" is one value from DERIVED::KEYS(), and
      // is a Meta, Child, or pair<Child,string/regex>. The cast gives the
      // underlying raw data type - int, say, or std::string - so that we
      // can correctly use our generic void* link to a derived-class field.
      std::apply(
         [this,&node](const auto &... key) {
            size_t n = 0;
           (this->node_add(node,key,n++), ...);
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

explicit operator Tree() const
{
   Tree tree;
   tree.add(Node(*this));
   return tree;
}
