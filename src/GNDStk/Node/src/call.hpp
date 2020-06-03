
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
// call in functional form, e.g. mynode.operator()<RESULT>(...), to use it.

// For now, in this file and in similar ones, I'm writing "context" try/catch
// blocks where the action is even slightly more substantial than a one-liner.
// For example, the apply_keyword() calls below can catch exceptions thrown
// in user-provided conversion functions from nodes to user-defined types.
// Given that even the one-liner calls could result in an exception happening
// in (or past) the called function, a case could be made that context should
// be printed in those as well. Another school of thought would be to declutter
// GNDStk completely of exception context printing, and let that be handled
// by a supervisory code (e.g. a debugger). For now we'll leave that question
// unanswered.


// ------------------------
// const
// ------------------------

// meta_t
// Forwards to meta(meta_t)
template<class RESULT, class CONVERTER>
decltype(auto) operator()(
   const meta_t<RESULT,CONVERTER> &kwd,
   bool &found = detail::default_bool
) const {
   return meta(kwd,found);
}


// child_t
// Forwards to child(child_t)
template<class RESULT, find FIND, class CONVERTER>
decltype(auto) operator()(
   const child_t<RESULT,FIND,CONVERTER> &kwd,
   bool &found = detail::default_bool
) const {
   return child(kwd,found);
}


// child_t, ...
// Multi-argument
template<class RESULT, find FIND, class CONVERTER, class... Keywords>
decltype(auto) operator()(
   const child_t<RESULT,FIND,CONVERTER> &kwd,
   Keywords &&...keywords
) const {
   try {
      if (kwd.name == "")
         detail::apply_keyword<RESULT>()(kwd,*this);
      return child(-kwd)(std::forward<Keywords>(keywords)...);
   } catch (const std::exception &) {
      log::context("Node(child_t(\"{}\"),...) const", kwd.name);
      throw;
   }
}


// ------------------------
// non-const
// ------------------------

// meta_t
template<class RESULT, class CONVERTER>
decltype(auto) operator()(
   const meta_t<RESULT,CONVERTER> &kwd,
   bool &found = detail::default_bool
) {
   return meta(kwd,found);
}


// child_t
template<class RESULT, find FIND, class CONVERTER>
decltype(auto) operator()(
   const child_t<RESULT,FIND,CONVERTER> &kwd,
   bool &found = detail::default_bool
) {
   return child(kwd,found);
}


// child_t, ...
template<class RESULT, find FIND, class CONVERTER, class... Keywords>
decltype(auto) operator()(
   const child_t<RESULT,FIND,CONVERTER> &kwd,
   Keywords &&...keywords
) {
   try {
      if (kwd.name == "")
         detail::apply_keyword<RESULT>()(kwd,*this);
      return child(-kwd)(std::forward<Keywords>(keywords)...);
   } catch (const std::exception &) {
      log::context("Node(child_t(\"{}\"),...)", kwd.name);
      throw;
   }
}
