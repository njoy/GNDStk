
// -----------------------------------------------------------------------------
// Multi-query
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Private helpers
// -----------------------------------------------------------------------------

private:

// Note: In these, notice that we use decltype(auto), not auto. Where the input
// query tuple has Meta<void> and/or Child<void>, with the decltype(auto) we'll
// get *references* (not copies) in the output tuple - just as we would with a
// single-value query. (Of course, where we use a non-<void> Meta or Child, the
// output object is of some prescribed type and is created on-the-fly. So, there
// aren't references in those cases in any event.)

// tupleApplyHead
template<class T>
decltype(auto) tupleApplyHead(
   const T &head,
   bool &found, // overall "found"
   std::vector<std::string> &missing
) NJOY_GNDSTK_CONST {
   bool f = true; // head-specific "found"
   decltype(auto) ret = operator()(head, f);
   if (!f)
      missing.push_back("\n" + detail::keyname(head));
   found = found && f;
   return ret;
}

// tupleApply
template<class... Ks, size_t... Is>
decltype(auto) tupleApply(
   const std::tuple<Ks...> &tup,
   bool &found,
   std::vector<std::string> &missing,
   const std::index_sequence<Is...> &
) NJOY_GNDSTK_CONST {
   return typename detail::keys2outputs<Node,std::tuple<Ks...>>::type(
      tupleApplyHead(std::get<Is>(tup), found, missing)
      ...
   );
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
) NJOY_GNDSTK_CONST {

   std::vector<std::string> missing;

   try {
      found = true;
      const auto ret = tupleApply(
         keytup.tup, found, missing,
         std::make_index_sequence<sizeof...(Ks)>{}
      );

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
      std::string errorMessage = "Error during query into \"" + name + "\".";
      if (missing.size() > 0) {
         errorMessage +=
            "\nOne or more required metadata and/or children were not found:";
         for (const std::string &m : missing)
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
               size_t n = 0;
             ((names += keyname(key) + (++n < sizeof...(Ks) ? "," : "")), ...);
            },
            keytup.tup
         );
      log::member("Node(KeyTuple({})", names);
      throw;
   }
}

#undef NJOY_GNDSTK_CONST
