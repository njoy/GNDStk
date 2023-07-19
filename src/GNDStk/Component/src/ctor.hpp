
// Component can't have copy or move construction. Its constructor MUST
// know about the fields in the specific instance that derives from it.
Component(const Component &) = delete;
Component(Component &&) = delete;

// We give Component a *private* constructor + a friend declaration, so that
// a derived class can't accidentally derive from Component<something else>.
// But, please, don't let y'alls derived classes mess with Component's data
// member, "links". With friends like that, Component wouldn't need enemies.

friend DERIVED;

// ctor: BlockData<...>, fields
template<class... ARGS>
Component(const BLOCKDATA &other, ARGS &...args) : BLOCKDATA(other)
{
   // I'd have preferred to achieve the following check by using SFINAE
   // in the constructor's signature, but couldn't find a way to do that
   // without again running into the issue of DERIVED being incomplete.

   // Type that a multi-query with DERIVED::KEYS() will produce.
   using multi_t = typename detail::queryResult<decltype(Keys().tup)>::type;

   // The types in ARGS should exactly reflect what we'd get from
   // a DERIVED::KEYS() multi-query, except that an ARG of Field<T>
   // is accepted in place of a T.
   static_assert(
      std::is_same_v<std::tuple<typename stripField<ARGS>::type...>, multi_t>,
      "The number and/or types of the fields sent to Component's "
      "constructor is inconsistent with the query result implied "
      "by the KEYS() function in the derived class"
   );

   // Create links
   links.reserve(sizeof...(args));
   (links.push_back(fieldAddress(args)), ...);
}
