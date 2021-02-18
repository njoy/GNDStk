
// ------------------------
// ()(Child)
// ------------------------

template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
decltype(auto) operator()(
   const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   bool &found = detail::default_bool
) GNDSTK_CONST {
   try {
      // Don't need or want:
      //    if (kwd.name == "")
      //       detail::apply_converter<TYPE>{}(kwd,*this);
      // because the effect will happen next...
      return child(kwd,found);
   } catch (...) {
      log::member("Node(" + detail::keyname(kwd) + ")");
      throw;
   }
}


// ------------------------
// ()(Child, string)
// ------------------------

template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
decltype(auto) operator()(
   const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const std::string label,
   bool &found = detail::default_bool
) GNDSTK_CONST {
   // as above, don't need or want (kwd.name == "") conditional
   try {
      // total filter
      auto filter = [kwd,label](const Node &n)
         { return kwd.filter(n) && detail::label_is(label)(n); };
      // --kwd: Child<...,Allow::one,...>
      return child(--kwd+filter, found);
   } catch (...) {
      log::member("Node(" + detail::keyname(kwd) + ",label=\"{}\")", label);
      throw;
   }
}


// ------------------------
// ()(Child, regex)
// ------------------------

template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
decltype(auto) operator()(
   const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const std::regex labelRegex,
   bool &found = detail::default_bool
) GNDSTK_CONST {
   try {
      // similar to std::string case
      auto filter = [kwd,labelRegex](const Node &n)
         { return kwd.filter(n) && detail::label_is_regex(labelRegex)(n); };
      return child(--kwd+filter, found);
   } catch (...) {
      log::member(
         "Node(" + detail::keyname(kwd) + ",label) with a std::regex label,\n"
         "not a std::string label"
      );
      throw;
   }
}


// ------------------------
// ()(pair<Child,string/regex>)
// ------------------------

template<
   class TYPE, Allow ALLOW, class CONVERTER, class FILTER,
   class SECOND,
   class = typename detail::IsStringOrRegex<SECOND>::type
>
decltype(auto) operator()(
   const std::pair<Child<TYPE,ALLOW,CONVERTER,FILTER>,SECOND> &pair,
   bool &found = detail::default_bool
) GNDSTK_CONST {
   try {
      return (*this)(pair.first, pair.second, found);
   } catch (...) {
      log::member("Node(" + detail::keyname(pair) + ")");
      throw;
   }
}


#undef GNDSTK_CONST
