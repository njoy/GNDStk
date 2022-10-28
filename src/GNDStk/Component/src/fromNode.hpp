
// -----------------------------------------------------------------------------
// Component::fromNode(Node)
// -----------------------------------------------------------------------------

// Retrieve a Node's data, and, via the links, get it into the fields in the
// derived-class object. We'd have preferred to call this in the constructor,
// so that users wouldn't need to call it directly in the constructors
// of their derived classes that accept Nodes. However, data initialization
// order in derived classes is such that their member data won't have been
// initialized (and thus would contain garbage data) when the Component base
// is constructed. Under such circumstances, the assignment in the below fold
// expression would, in general, break. (Imagine, say, assigning X = Y for
// std::strings X and Y - but when X isn't initialized, so that X contains
// garbage. The assignment would attempt to deallocate a junk pointer in X,
// and funny stuff would happen. Maybe not too funny.) We could use placement
// new(), below, but to no real effect: the result would be replaced, anyway,
// when the derived class' own members are initialized in its constructor.

private:

template<class KEY>
void transfer(const std::size_t n, const Node &node, const KEY &key)
{
   // todo working here on possibly optimizations
   if constexpr (detail::IsMeta<KEY>::value) {
      *(std::decay_t<decltype(node(key))> *)links[n] = node(key);
   } else if constexpr (detail::IsChild<KEY>::value) {
      *(std::decay_t<decltype(node(key))> *)links[n] = node(key);
   } else {
      assert(false);
   }
}

public:

void fromNode(const Node &node)
{
   try {
      // does the node have the name we expect?
      if (node.name != DERIVED::FIELD()) {
         log::error(
           "Node name \"{}\" is not the expected name \"{}\"",
            node.name, DERIVED::FIELD()
         );
         throw std::exception{};
      }

      // consistency check
      assert(std::tuple_size_v<decltype(Keys().tup)> == links.size());

      // apply links:
      // Node ==> derived-class data
      std::apply(
         [this,node](const auto &... key) {
            std::size_t n = 0;
            (
               (
                  this->transfer(n++, node, key)
                  ///*(std::decay_t<decltype(node(key))> *)links[n++] = node(key)
               ),
               ...
            );
         },
         Keys().tup
      );

      // block data, a.k.a. XML "pcdata" (plain character data), if any
      if constexpr (hasBlockData)
         BLOCKDATA::fromNode(node);

   } catch (...) {
      log::member("Component.fromNode(Node(\"{}\"))", node.name);
      throw;
   }
}
