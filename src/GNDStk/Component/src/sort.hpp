
// -----------------------------------------------------------------------------
// Component::sort()
// -----------------------------------------------------------------------------

void sort()
{
   if (!njoy::GNDStk::sort)
      return;

   try {
      // Consistency check
      assert(std::tuple_size_v<decltype(Keys().tup)> == links.size());

      // Apply links
      std::apply(
         [this](const auto &... key) {
            std::size_t n = 0;
            (
               detail::sort(*(std::decay_t<decltype(Node{}(key))> *)links[n++]),
               ...
            );
         },
         Keys().tup
      );

   } catch (...) {
      log::member("Component.sort()");
      throw;
   }
}
