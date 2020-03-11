
// -----------------------------------------------------------------------------
// Tree::operator()
// -----------------------------------------------------------------------------

// meta_t
template<class RESULT>
decltype(auto) operator()(const meta_t<RESULT> &kwd) const
{
   return meta(kwd);
}

// child_t
template<
   class RESULT, bool MULTIPLE, class METADATA, class CHILDREN
>
decltype(auto) operator()(
   const child_t<RESULT,MULTIPLE,METADATA,CHILDREN> &kwd
) const {
   return child(kwd);
}

// child_t, ...
// Multi-argument
template<
   class RESULT, bool MULTIPLE, class METADATA, class CHILDREN,
   class... Ts
>
decltype(auto) operator()(
   const child_t<RESULT,MULTIPLE,METADATA,CHILDREN> &kwd,
   Ts &&...ts
) const {
   return (*this)(kwd)(std::forward<Ts>(ts)...);
}
