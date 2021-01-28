
// For now, in this file and in similar ones, I'm writing "context" try/catch
// blocks where the action is even slightly more substantial than a one-liner.
// For example, the apply_converter() calls below can catch exceptions thrown
// in user-provided conversion functions from nodes to user-defined types.
// Given that even the one-liner calls could result in an exception happening
// in (or past) the called function, a case could be made that context should
// be printed in those as well. Another approach would be to declutter GNDStk
// of any exception-context printing, and let that be handled by a supervisory
// code (e.g. a debugger). For now, we'll leave it at that.


// ------------------------
// (child_t, ...)
// ------------------------

template<
   class TYPE, Allow ALLOW, class CONVERTER, class FILTER,
   class... KEYWORDS
>
decltype(auto) operator()(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   KEYWORDS &&...keywords
) GNDSTK_CONST {
   bool &found = detail::extract_found(std::forward<KEYWORDS>(keywords)...);
   try {
      // ""?
      if (kwd.name == "")
         detail::apply_converter<TYPE>{}(kwd,*this);

      // This triggers a static assertion failure if, and only if, someone
      // sends operator() an Allow::many child_t that is not followed by a
      // string, char*, or regex, and is not at operator()'s end...
      (void)detail::call_operator_child_t<ALLOW>{};

      // Use -- to downgrade to Allow::one (so unchanged if already Allow::one,
      // and just one error (the static assertion failure as described above),
      // as opposed to two errors, if an Allow::many. Finally, use unary minus
      // to make the child_t's type <void>, so that we can continue to dig down
      // further into the tree structure.
      return child(---kwd,found)(std::forward<KEYWORDS>(keywords)...);
   } catch (...) {
      log::member("Node(" + detail::keyname(kwd) + ",...)");
      throw;
   }
}


// ------------------------
// (child_t, string, ...)
// (child_t, char *, ...)
// ------------------------

template<
   class TYPE, Allow ALLOW, class CONVERTER, class FILTER,
   class... KEYWORDS
>
decltype(auto) operator()(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const std::string label,
   KEYWORDS &&...keywords
) GNDSTK_CONST {
   bool &found = detail::extract_found(std::forward<KEYWORDS>(keywords)...);
   try {
      // ""?
      if (kwd.name == "")
         detail::apply_converter<TYPE>{}(kwd,*this);
      // total filter
      auto filter = [kwd,label](const Node &n)
         { return kwd.filter(n) && detail::label_is(label)(n); };
      // ---kwd: child_t<void,Allow::one,...>
      return child(---kwd+filter, found)(std::forward<KEYWORDS>(keywords)...);
   } catch (...) {
      log::member("Node(" + detail::keyname(kwd) + ",label=\"{}\",...)", label);
      throw;
   }
}

// Otherwise, char * would match with class... KEYWORDS, not with std::string
template<
   class TYPE, Allow ALLOW, class CONVERTER, class FILTER,
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


// ------------------------
// (child_t, regex, ...)
// ------------------------

template<
   class TYPE, Allow ALLOW, class CONVERTER, class FILTER,
   class... KEYWORDS
>
decltype(auto) operator()(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const std::regex labelRegex,
   KEYWORDS &&...keywords
) GNDSTK_CONST {
   bool &found = detail::extract_found(std::forward<KEYWORDS>(keywords)...);
   try {
      // ""?
      if (kwd.name == "")
         detail::apply_converter<TYPE>{}(kwd,*this);
      // total filter
      auto filter = [kwd,labelRegex](const Node &n)
         { return kwd.filter(n) && detail::label_is_regex(labelRegex)(n); };
      // ---kwd: child_t<void,Allow::one,...>
      return child(---kwd+filter, found)(std::forward<KEYWORDS>(keywords)...);
   } catch (...) {
      // C++ doesn't have stream output for regex, which one might think
      // would print the string from which the regex was created. In fact,
      // regex might not even use, or keep, its original string initializer;
      // thus it doesn't have, say, .str() or .c_str(). All of this is why
      // the following diagnostic doesn't print label's (regex) value.
      log::member(
         "Node(" + detail::keyname(kwd) + ",label,...) with "
         "a std::regex label,\nnot a std::string label"
      );
      throw;
   }
}

#undef GNDSTK_CONST
