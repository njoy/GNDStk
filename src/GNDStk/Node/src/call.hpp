
// -----------------------------------------------------------------------------
// Node::operator()
// -----------------------------------------------------------------------------

// These provide notationally consistent access to the meta() and child()
// functions, except that the std::string parameter versions of those functions
// are intentionally not supported here, as it would be indeterminate as to
// whether we'd want the meta or child (std::string) function. This also
// reflects the fact that calling our accessor functions with meta_t and
// child_t parameters - not with std::string parameters - should be preferred.
// Those encode (via their type) whether we're accessing metadata or children.

// ------------------------
// const
// ------------------------

// meta_t
// Forwards to meta(meta_t)
template<
   class RESULT
>
decltype(auto) operator()(
   const meta_t<RESULT> &kwd
) const {
   return meta(kwd);
}

// child_t
// Forwards to child(child_t)
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

// ------------------------
// non-const
// ------------------------

// meta_t
template<
   class RESULT
>
decltype(auto) operator()(
   const meta_t<RESULT> &kwd
) {
   return meta(kwd);
}

// child_t
template<
   class RESULT, bool MULTIPLE, class METADATA, class CHILDREN
>
decltype(auto) operator()(
   const child_t<RESULT,MULTIPLE,METADATA,CHILDREN> &kwd
) {
   return child(kwd);
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
   return (*this)(kwd)(std::forward<Ts>(ts)...);
}
