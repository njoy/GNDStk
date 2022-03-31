
// -----------------------------------------------------------------------------
// Component::sort()
// -----------------------------------------------------------------------------

void sort()
{
   try {
      if constexpr (!hasFields) {
         // Consistency check; then nothing further to do
         assert(0 == links.size());
      } else {
         // Make tuple (of individual keys) from DERIVED::KEYS()
         static const auto tup = makeKeyTuple(DERIVED::KEYS()).tup;

         // Consistency check
         assert(std::tuple_size<decltype(tup)>::value == links.size());

         // Apply links
         std::apply(
            [this](const auto &... key) {
               std::size_t n = 0;
               (
                  detail::sort(
                   *(std::decay_t<decltype(Node{}(key))> *)links[n++]
                  ),
                  ...
               );
            },
            tup
         );
      }
   } catch (...) {
      log::member("Component.sort()");
      throw;
   }
}
