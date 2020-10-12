
// For now, in this file and in similar ones, I'm writing "context" try/catch
// blocks where the action is even slightly more substantial than a one-liner.
// For example, the apply_converter() calls below can catch exceptions thrown
// in user-provided conversion functions from nodes to user-defined types.
// Given that even the one-liner calls could result in an exception happening
// in (or past) the called function, a case could be made that context should
// be printed in those as well. Another approach would be to declutter GNDStk
// of any exception-context printing, and let that be handled by a supervisory
// code (e.g. a debugger). For now, we'll leave it at that.

// (child_t)
template<class TYPE, find FIND, class CONVERTER>
decltype(auto) operator()(
   const child_t<TYPE,FIND,CONVERTER> &kwd,
   bool &found = detail::default_bool
) GNDSTK_CONST {
   try {
      // Don't need or want:
      //    if (kwd.name == "")
      //       detail::apply_converter<TYPE>{}(kwd,*this);
      // because the effect will happen next...
      return child(kwd,found);
   } catch (const std::exception &) {
      log::context("Node(child_t(\"{}\"))", kwd.name);
      throw;
   }
}

// (child_t, string)
template<class TYPE, find FIND, class CONVERTER>
decltype(auto) operator()(
   const child_t<TYPE,FIND,CONVERTER> &kwd,
   std::string &&label,
   bool &found = detail::default_bool
) GNDSTK_CONST {
   try {
      // As above, don't need or want:
      //    if (kwd.name == "")
      //       detail::apply_converter<TYPE>{}(kwd,*this);
      return child(GNDStk::one(kwd), detail::label_is(label), found);
   } catch (const std::exception &) {
      log::context("Node(child_t(\"{}\"),label=\"{}\")", kwd.name, label);
      throw;
   }
}

// (child_t, ...)
template<class TYPE, find FIND, class CONVERTER, class... KEYWORDS>
decltype(auto) operator()(
   const child_t<TYPE,FIND,CONVERTER> &kwd,
   KEYWORDS &&...keywords
) GNDSTK_CONST {
   try {
      if (kwd.name == "")
         detail::apply_converter<TYPE>{}(kwd,*this);
      return child(-kwd)(std::forward<KEYWORDS>(keywords)...);
   } catch (const std::exception &) {
      log::context("Node(child_t(\"{}\"),...)", kwd.name);
      throw;
   }
}

// (child_t, string, ...)
template<class TYPE, find FIND, class CONVERTER, class... KEYWORDS>
decltype(auto) operator()(
   const child_t<TYPE,FIND,CONVERTER> &kwd,
   std::string &&label,
   KEYWORDS &&...keywords
) GNDSTK_CONST {
   try {
      if (kwd.name == "")
         detail::apply_converter<TYPE>{}(kwd,*this);
      return child(GNDStk::one(-kwd), detail::label_is(label))
                  (std::forward<KEYWORDS>(keywords)...);
   } catch (const std::exception &) {
      log::context("Node(child_t(\"{}\"),label=\"{}\",...)", kwd.name, label);
      throw;
   }
}

// (child_t, char *, ...)
// Otherwise, char * would match with class... KEYWORDS, not with std::string
template<class TYPE, find FIND, class CONVERTER, class... KEYWORDS>
decltype(auto) operator()(
   const child_t<TYPE,FIND,CONVERTER> &kwd,
   const char *const label,
   KEYWORDS &&...keywords
) GNDSTK_CONST {
   // Forward to the string overload above
   return (*this)(kwd, std::string(label), std::forward<KEYWORDS>(keywords)...);
}

#undef GNDSTK_CONST
