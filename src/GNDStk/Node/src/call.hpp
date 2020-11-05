
// For now, in this file and in similar ones, I'm writing "context" try/catch
// blocks where the action is even slightly more substantial than a one-liner.
// For example, the apply_converter() calls below can catch exceptions thrown
// in user-provided conversion functions from nodes to user-defined types.
// Given that even the one-liner calls could result in an exception happening
// in (or past) the called function, a case could be made that context should
// be printed in those as well. Another approach would be to declutter GNDStk
// of any exception-context printing, and let that be handled by a supervisory
// code (e.g. a debugger). For now, we'll leave it at that.

// (child_t, ...)
template<
   class TYPE, allow ALLOW, class CONVERTER, class FILTER,
   class... KEYWORDS
>
decltype(auto) operator()(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   KEYWORDS &&...keywords
) GNDSTK_CONST {
   bool &found = detail::extract_found(std::forward<KEYWORDS>(keywords)...);
   try {
      if (kwd.name == "")
         detail::apply_converter<TYPE>{}(kwd,*this);
      return child(-kwd,found)(std::forward<KEYWORDS>(keywords)...);
   } catch (...) {
      log::function("Node(child_t(\"{}\"),...)", kwd.name);
      throw;
   }
}

// (child_t, string, ...)
template<
   class TYPE, allow ALLOW, class CONVERTER, class FILTER,
   class... KEYWORDS
>
decltype(auto) operator()(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   std::string &&label,
   KEYWORDS &&...keywords
) GNDSTK_CONST {
   bool &found = detail::extract_found(std::forward<KEYWORDS>(keywords)...);
   try {
      if (kwd.name == "")
         detail::apply_converter<TYPE>{}(kwd,*this);
      return child(-kwd.one(), detail::label_is(label), found)
                  (std::forward<KEYWORDS>(keywords)...);
   } catch (...) {
      log::function("Node(child_t(\"{}\"),label=\"{}\",...)", kwd.name, label);
      throw;
   }
}

// (child_t, char *, ...)
// Otherwise, char * would match with class... KEYWORDS, not with std::string
template<
   class TYPE, allow ALLOW, class CONVERTER, class FILTER,
   class... KEYWORDS
>
decltype(auto) operator()(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const char *const label,
   KEYWORDS &&...keywords
) GNDSTK_CONST {
   // Forward to the string overload
   return (*this)(kwd, std::string(label), std::forward<KEYWORDS>(keywords)...);
}

#undef GNDSTK_CONST
