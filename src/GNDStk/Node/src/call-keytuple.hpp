
// -----------------------------------------------------------------------------
// Multi-query
// -----------------------------------------------------------------------------

// ------------------------
// Private helpers
// ------------------------

private:

// (tuple<>)
auto operator()(
   const std::tuple<> &,
   bool &found,
   std::vector<std::string> &
) GNDSTK_CONST {
   found = true;
   return std::tuple<>{};
}


// (tuple<...>)
template<class... Ks>
auto operator()(
   const std::tuple<Ks...> &tup,
   bool &found,
   std::vector<std::string> &missing
) GNDSTK_CONST {

   // Process tup's <0>
   // We *don't* simply write:
   //    std::make_tuple(operator()(std::get<0>(tup),head_found)),
   // because doing so would decay references to non-references. That would
   // mean, ultimately, that Meta<void> and Child<void> instances inside
   // our KeyTuple<...> objects, which are returned by our | (or) operators,
   // would no longer produce [possibly const] *references* to std::string
   // and Node, respectively, but would surreptitiously lose the references.
   // We don't want to lose the references, though, because our multi-query
   // system is far more awesome if we keep them. For the same reason - not
   // losing the references - we also need the explicit <decltype(...)> on
   // std::tuple, even though this would be syntactically valid without it.
   bool head_found = true;

   const auto head = std::tuple<decltype(
      operator()(std::get<0>(tup)))
   >( operator()(std::get<0>(tup), head_found) );

   if (!head_found)
      missing.push_back("\nElement: " + detail::keyname(std::get<0>(tup)));

   // Process tup's <1...>
   bool tail_found = true;

   const auto tail = operator()( // <== gives a tuple
      std::apply(
         [](auto, auto... tail) { return std::make_tuple(tail...); },
         tup
      ),
      tail_found,
      missing
   );

   // Done
   found = head_found && tail_found;
   return std::tuple_cat(head,tail);
}


// -----------------------------------------------------------------------------
// Public
// (KeyTuple<...>)
// -----------------------------------------------------------------------------

public:

template<class... Ks>
auto operator()(
   const KeyTuple<Ks...> &keytup,
   bool &found = detail::default_bool // means "found all" in this context
) GNDSTK_CONST {

   std::vector<std::string> missing;
   try {
      const auto ret = operator()(keytup.tup, found, missing);
      // As it does with other query functions, GNDStk returns with no error
      // if either the requested data were found, or if the "found" flag was
      // sent here explicitly. Either way, found == did we find the data?
      if (found || detail::sent(found))
         return ret;
      throw std::exception{};
   } catch (...) {
      // Construct and print an error. The message is short and generic if
      // an error other than !found occurred in the try{} - which we suppose
      // could happen - and very informative if, as is likely, we came here
      // because nothing was found and the caller didn't send the found flag.
      std::string errorMessage = "Error during multi-query.";
      if (missing.size() > 0) {
         errorMessage +=
            " "
            + std::to_string(missing.size())
            + " element" + (missing.size() == 1 ? " was" : "s were")
            + " not found:";
         for (auto &m : missing)
            errorMessage += m;
      }
      log::error(errorMessage);

      // Construct and print the context. (Note: the if-constexpr seems
      // unnecessary, but a compiler gave a warning about "names" being
      // unused, in the lambda, in the empty tuple (std::tuple<>) case.)
      std::string names;
      if constexpr (!std::is_same_v<KeyTuple<Ks...>,KeyTuple<>>)
         std::apply(
            [&names](const Ks &... key) {
               using detail::keyname;
               std::size_t n = 0;
             ((names += keyname(key) + (++n < sizeof...(Ks) ? "," : "")), ...);
            },
            keytup.tup
         );
      log::member("Node(KeyTuple({})", names);
      throw;
   }
}

#undef GNDSTK_CONST
