
// We give Component a *private* constructor + a friend declaration, so that
// a derived class can't accidentally derive from Component<something else>.
// But, please, don't let y'alls derived classes mess with Component's data
// member, "links". With friends like that, Component wouldn't need enemies.

friend DERIVED;

// ctor: fields
template<class... ARGS>
Component(ARGS &...args)
{
   // static_assert needs string literal
   #define pairing_error \
     "The number and/or types of the fields sent to Component's " \
     "constructor is inconsistent with the query result implied " \
     "by the derived class' keys()"

   // I'd have preferred to achieve the following check by using SFINAE
   // in the constructor's signature, but couldn't find a way to do that
   // without again running into the issue of DERIVED being incomplete.

   // The parameters that are sent to this constructor must EXACTLY reflect
   // what we'd get from a DERIVED::keys() multi-query.
   if constexpr (std::is_same<decltype(DERIVED::keys()),std::tuple<>>::value) {
      static_assert(
         std::is_same<std::tuple<ARGS ...>, std::tuple<>>::value,
         pairing_error
      );
   } else {
      // The following is the *type* that a multi-query with DERIVED::keys()
      // will produce, except without cvrefs.
      using multi_t =
         typename detail::remove_cvrefs<
            decltype(Node{}(toKeywordTup(DERIVED::keys())))
         >::type;
      static_assert(
         std::is_same<std::tuple<ARGS ...>, multi_t>::value,
         pairing_error
      );
      // Create links
      (links.push_back(&args), ...);
   }

   #undef pairing_error
}
