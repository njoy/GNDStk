
// ------------------------
// ()(child_t)
// ------------------------

template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
decltype(auto) operator()(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
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
// ()(child_t, string)
// ------------------------

template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
decltype(auto) operator()(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const std::string label,
   bool &found = detail::default_bool
) GNDSTK_CONST {
   // as above, don't need or want (kwd.name == "") conditional
   try {
      // total filter
      auto filter = [kwd,label](const Node &n)
         { return kwd.filter(n) && detail::label_is(label)(n); };
      // --kwd: child_t<...,Allow::one,...>
      return child(--kwd+filter, found);
   } catch (...) {
      log::member("Node(" + detail::keyname(kwd) + ",label=\"{}\")", label);
      throw;
   }
}


// ------------------------
// ()(child_t, regex)
// ------------------------

template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
decltype(auto) operator()(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
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

#undef GNDSTK_CONST
