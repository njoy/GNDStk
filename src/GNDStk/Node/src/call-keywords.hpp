
// -----------------------------------------------------------------------------
// Multi-query
// -----------------------------------------------------------------------------

// ------------------------
// Private helpers
// ------------------------

private:

// ()(tuple<...>)
template<class... Ks>
auto operator()(
   const std::tuple<Ks...> &tup,
   bool &found
) GNDSTK_CONST {
   log::debug(
     "operator()(tuple<...>), size == {}",
      sizeof...(Ks)
   );

   bool head_found = false;
   bool tail_found = false;

   const auto ret = std::tuple_cat(
      // Process tup's <0>
      // We *don't* simply write:
      //    std::make_tuple(operator()(std::get<0>(tup),head_found)),
      // because doing so would decay references to non-references. That would
      // mean, ultimately, that meta_t<void> and child_t<void> instances inside
      // our keywords<...> objects, which are returned by our comma operators,
      // would no longer produce [possibly const] *references* to std::string
      // and Node, respectively, but would surreptitiously lose the references.
      // We don't want to lose the references, though, because our multi-query
      // system is far more awesome if we keep them.
      std::tuple<
         decltype(
            operator()(
               std::get<0>(tup),
               head_found
            )
         )
      >(
         operator()(
            std::get<0>(tup),
            head_found
         )
      ),

      // Continue to tup's <1...>
      operator()(
         std::apply(
            [](auto, auto... tail) { return std::make_tuple(tail...); },
            tup
         ),
         tail_found
      )
   ); // tuple_cat()

   found = head_found && tail_found;
   return ret;
}


// ()(tuple<child_t, string|regex, ...>)
template<
   class TYPE, allow ALLOW, class CONVERTER, class FILTER,
   class SECOND,
   class... TAIL,
   class = typename std::enable_if<
      detail::is_string_or_regex<SECOND>::value
   >::type
>
auto operator()(
   const std::tuple<
      child_t<TYPE,ALLOW,CONVERTER,FILTER>,
      SECOND,
      TAIL...
   > &tup,
   bool &found
) GNDSTK_CONST {
   log::debug(
     "operator()(child, string|regex, tuple<...>), size == 2+{}",
      sizeof...(TAIL)
   );

   bool head_found = false;
   bool tail_found = false;

   const auto ret = std::tuple_cat(
      // Process tup's <0> and <1>
      std::tuple<
         decltype(
            operator()(
               std::get<0>(tup),
               std::get<1>(tup),
               head_found
            )
         )
      >(
         operator()(
            std::get<0>(tup),
            std::get<1>(tup),
            head_found
         )
      ),

      // Continue to tup's <2...>
      operator()(
         std::apply(
            [](auto, auto, auto... tail) { return std::make_tuple(tail...); },
            tup
         ),
         tail_found
      )
   ); // tuple_cat()

   found = head_found && tail_found;
   return ret;
}


// ()(tuple<>)
auto operator()(
   const std::tuple<> &tup,
   bool &found
) GNDSTK_CONST {
   log::debug("operator()(tuple<>), size == 0");
   found = true;
   return tup;
}

// ------------------------
// ()(keywords<...>)
// ------------------------

public:

template<class... Ks>
auto operator()(
   const keywords<Ks...> &kwds,
   bool &found = detail::default_bool // means "found all" in this context
) GNDSTK_CONST {
   log::debug(
     "operator()(keywords<...>), size == {}",
      sizeof...(Ks)
   );

   try {
      return operator()(kwds.tup,found);
   } catch (...) {
      // fixme With some work, we could make this print the name sequence
      log::function("Node(keywords<...>)");
      throw;
   }
}

#undef GNDSTK_CONST
