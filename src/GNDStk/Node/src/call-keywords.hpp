
// -----------------------------------------------------------------------------
// Multi-query
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Private helpers
// -----------------------------------------------------------------------------

private:

// ------------------------
// ()(tuple<>)
// ------------------------

auto operator()(
   const std::tuple<> &tup,
   bool &found,
   std::vector<std::string> &
) GNDSTK_CONST {
   log::debug("Node(tuple<>), tuple size == 0");
   found = true;
   return tup;
}


// ------------------------
// ()(tuple<Child,
//    string/regex, ...>)
// ------------------------

template<
   class TYPE, Allow ALLOW, class CONVERTER, class FILTER,
   class SECOND,
   class... TAIL,
   class = typename detail::IsStringOrRegex<SECOND>::type
>
auto operator()(
   const std::tuple<
      Child<TYPE,ALLOW,CONVERTER,FILTER>,
      SECOND,
      TAIL...
   > &tup,
   bool &found,
   std::vector<std::string> &missing
) GNDSTK_CONST {

   log::debug(
     "Node(tuple<Child, string/regex, ...>), tuple size == {}",
      2 + sizeof...(TAIL)
   );

   // Process tup's <0> and <1>
   bool head_found = true;

   const auto head =
      std::tuple<decltype(
         operator()(std::get<0>(tup), std::get<1>(tup)))
      >(
         operator()(std::get<0>(tup), std::get<1>(tup), head_found)
      );

   if (!head_found) {
      missing.push_back(
         "\nElement: "
         + detail::keyname(std::get<0>(tup)) +  ", "
         + detail::keyname(std::get<1>(tup))
      );
   }

   // Process tup's <2...>
   bool tail_found = true;

   const auto tail = operator()( // <== already gives a tuple
      std::apply(
         [](auto, auto, auto... tail) { return std::make_tuple(tail...); },
         tup
      ),
      tail_found,
      missing
   );

   // Done
   found = head_found && tail_found;
   return std::tuple_cat(head,tail);
}


// ------------------------
// ()(tuple<...>)
// ------------------------

template<class... Ks>
auto operator()(
   const std::tuple<Ks...> &tup,
   bool &found,
   std::vector<std::string> &missing
) GNDSTK_CONST {

   log::debug(
     "Node(tuple<...>), tuple size == {}",
      sizeof...(Ks)
   );

   // Process tup's <0>
   // We *don't* simply write:
   //    std::make_tuple(operator()(std::get<0>(tup),head_found)),
   // because doing so would decay references to non-references. That would
   // mean, ultimately, that Meta<void> and Child<void> instances inside
   // our keywords<...> objects, which are returned by our | (or) operators,
   // would no longer produce [possibly const] *references* to std::string
   // and Node, respectively, but would surreptitiously lose the references.
   // We don't want to lose the references, though, because our multi-query
   // system is far more awesome if we keep them. For the same reason - not
   // losing the references - we also need the explicit <decltype(...)> on
   // std::tuple, even though this would be syntactically valid without it.
   bool head_found = true;

   const auto head = std::tuple<decltype(
      operator()(std::get<0>(tup)))
   >(
      operator()(std::get<0>(tup), head_found)
   );

   if (!head_found) {
      missing.push_back(
         "\nElement: "
         + detail::keyname(std::get<0>(tup))
      );
   }

   // Process tup's <1...>
   bool tail_found = true;

   const auto tail = operator()( // <== already gives a tuple
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
// ()(keywords<...>)
// -----------------------------------------------------------------------------

public:

template<class... Ks>
auto operator()(
   const keywords<Ks...> &kwds,
   bool &found = detail::default_bool // means "found all" in this context
) GNDSTK_CONST {

   log::debug(
     "Node(keywords<...>), keywords size == {}",
      sizeof...(Ks)
   );

   std::vector<std::string> missing;
   try {
      const auto ret = operator()(kwds.tup, found, missing);
      // As it does with other query functions, GNDStk returns with no error
      // if either the requested data were found, or if the "found" flag was
      // sent here explicitly. Either way, found == did we find the data?
      if (found || detail::sent(found))
         return ret;
      throw std::exception{};
   } catch (...) {
      // Construct and print error. The message is short and generic if an
      // error other than !found occurred in the try{} - which we suppose
      // could happen - and very informative if, as is likely, we came here
      // because nothing was found and the caller didn't send the found flag.
      std::string errorMessage = "Error during multi-query.";
      if (missing.size() > 0) {
         errorMessage +=
            " "
            + std::to_string(missing.size())
            + " element" + (missing.size() == 1 ? "" : "s")
            + " not found:";
         for (auto &m : missing)
            errorMessage += m;
      }
      log::error(errorMessage);

      // Construct and print context
      std::string names;
      std::apply(
         [&names](const Ks &... key) {
            using detail::keyname;
            std::size_t n = 0;
            ((names += keyname(key) + (++n < sizeof...(Ks) ? "," : "")), ...);
         },
         kwds.tup
      );
      log::member("Node(keywords({})", names);
      throw;
   }
}

#undef GNDSTK_CONST
