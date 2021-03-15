
// -----------------------------------------------------------------------------
// Component::query()
// -----------------------------------------------------------------------------

// Retrieve a Node's data, and, via the links, get it into the fields in the
// derived-class object. We'd have preferred to call this in the constructor,
// above, so that users wouldn't need to call it directly in the constructors
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

void query(const Node &node)
{
   // does the node have the name we expect?
   if (node.name != DERIVED::gnds()) {
      log::error(
        "Name \"{}\" in Node sent to Component::query() is not the "
        "expected GNDS name \"{}\"",
         node.name,
         DERIVED::gnds()
      );
      log::member("Component.query(Node(\"{}\"))", node.name);
      throw std::exception{};
   }

   try {
      // retrieve node's data by doing a multi-query
      const auto tup = node(toKeywordTup(DERIVED::keys()));

      // consistency check
      assert(std::tuple_size<decltype(tup)>::value == links.size());

      // apply links:
      // Node ==> derived-class data
      // Below, each apply'd "result" is one particular element - one
      // retrieved value - from the above multi-query on the node.

      std::apply(
         [this](const auto &... result) {
            std::size_t n = 0;
           ((*(typename detail::remove_cvref<decltype(result)>::type *)
               links[n++] = result),
            ...);
         },
         tup
      );

   } catch (...) {
      log::member("Component.query(Node(\"{}\"))", node.name);
      throw;
   }
}