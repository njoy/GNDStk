
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
   const meta_t<RESULT> &kwd,
   bool &found = detail::default_bool
) const {
   debug(detail::np15);
   return meta(kwd,found);
}

// child_t
// Forwards to child(child_t)
template<
   class RESULT, bool MULTIPLE, class METADATA, class CHILDREN
>
decltype(auto) operator()(
   const child_t<RESULT,MULTIPLE,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) const {
   debug(detail::np16);
   return child(kwd,found);
}

// child_t, ...
// Multi-argument
template<
   class RESULT, bool MULTIPLE, class METADATA, class CHILDREN,
   class... Keywords
>
decltype(auto) operator()(
   const child_t<RESULT,MULTIPLE,METADATA,CHILDREN> &kwd,
   Keywords &&...keywords
) const {
   debug(detail::np17);
   if (kwd.name == "")
      detail::apply_keyword<RESULT>()(*this);
   const auto &peel = this->child(-kwd); // for const correctness
   return peel(std::forward<Keywords>(keywords)...);
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
   debug(detail::np18);
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
   debug(detail::np19);
   return child(kwd,found);
}

// child_t, ...
template<
   class RESULT, bool MULTIPLE, class METADATA, class CHILDREN,
   class... Keywords
>
decltype(auto) operator()(
   const child_t<RESULT,MULTIPLE,METADATA,CHILDREN> &kwd,
   Keywords &&...keywords
) {
   debug(detail::np20);
   if (kwd.name == "")
      detail::apply_keyword<RESULT>()(*this);
   return this->child(-kwd)(std::forward<Keywords>(keywords)...);
}
