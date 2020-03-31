
// -----------------------------------------------------------------------------
// Tree::operator()
// -----------------------------------------------------------------------------

// ------------------------
// const
// ------------------------

// meta_t
template<
   class RESULT
>
decltype(auto) operator()(
   const meta_t<RESULT> &kwd,
   bool &found = detail::default_bool
) const {
   return meta(kwd,found);
}

// child_t
template<
   class RESULT, bool MULTIPLE, class METADATA, class CHILDREN
>
decltype(auto) operator()(
   const child_t<RESULT,MULTIPLE,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) const {
   return child(kwd,found);
}

// child_t, ...
template<
   class RESULT, bool MULTIPLE, class METADATA, class CHILDREN,
   class... Ts
>
decltype(auto) operator()(
   const child_t<RESULT,MULTIPLE,METADATA,CHILDREN> &kwd,
   Ts &&...ts
) const {
   return (*this)(-kwd)(std::forward<Ts>(ts)...);
}


// ------------------------
// non-const
// ------------------------

// meta_t
template<
   class RESULT
>
decltype(auto) operator()(
   const meta_t<RESULT> &kwd,
   bool &found = detail::default_bool
) {
   return meta(kwd,found);
}

// child_t
template<
   class RESULT, bool MULTIPLE, class METADATA, class CHILDREN
>
decltype(auto) operator()(
   const child_t<RESULT,MULTIPLE,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) {
   return child(kwd,found);
}

// child_t, ...
template<
   class RESULT, bool MULTIPLE, class METADATA, class CHILDREN,
   class... Ts
>
decltype(auto) operator()(
   const child_t<RESULT,MULTIPLE,METADATA,CHILDREN> &kwd,
   Ts &&...ts
) {
   return (*this)(-kwd)(std::forward<Ts>(ts)...);
}
