
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
               detail::sort(
                  *(
                     typename detail::queryResult<
                        std::decay_t<decltype(key)>
                     >::type
                  *)links[n++]
               ),
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
