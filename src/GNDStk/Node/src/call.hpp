
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

// Note: for variant-based meta_t and child_t keywords, you'll still need to
// call meta<RESULT>() or child<RESULT> directly. Implementing the variant
// versions here would bulk up this file, and you'd need to write the operator
// call in functional form, e.g. mynode.operator()<some_t>(...), to use it.


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
   return meta(kwd,found);
}

// child_t
// Forwards to child(child_t)
template<
   class RESULT, find FIND, class METADATA, class CHILDREN
>
decltype(auto) operator()(
   const child_t<RESULT,FIND,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) const {
   return child(kwd,found);
}

// child_t, ...
// Multi-argument
template<
   class RESULT, find FIND, class METADATA, class CHILDREN,
   class... Keywords
>
decltype(auto) operator()(
   const child_t<RESULT,FIND,METADATA,CHILDREN> &kwd,
   Keywords &&...keywords
) const {
   if (kwd.name == "")
      detail::apply_keyword<RESULT>()(*this);
   const auto &peel = this->child(-kwd);
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
   return meta(kwd,found);
}

// child_t
template<
   class RESULT, find FIND, class METADATA, class CHILDREN
>
decltype(auto) operator()(
   const child_t<RESULT,FIND,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) {
   return child(kwd,found);
}

// child_t, ...
template<
   class RESULT, find FIND, class METADATA, class CHILDREN,
   class... Keywords
>
decltype(auto) operator()(
   const child_t<RESULT,FIND,METADATA,CHILDREN> &kwd,
   Keywords &&...keywords
) {
   if (kwd.name == "")
      detail::apply_keyword<RESULT>()(*this);
   return this->child(-kwd)(std::forward<Keywords>(keywords)...);
}
