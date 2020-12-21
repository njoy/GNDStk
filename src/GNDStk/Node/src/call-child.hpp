
// ------------------------
// ()(child_t)
// ------------------------

template<class TYPE, allow ALLOW, class CONVERTER, class FILTER>
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
      log::member("Node(child_t(\"{}\"))", kwd.name);
      throw;
   }
}


// ------------------------
// ()(child_t, string)
// ------------------------

template<class TYPE, allow ALLOW, class CONVERTER, class FILTER>
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
      // --kwd: child_t<...,allow::one,...>
      return child(--kwd+filter, found);
   } catch (...) {
      log::member("Node(child_t(\"{}\"),label=\"{}\")", kwd.name, label);
      throw;
   }
}


// ------------------------
// ()(child_t, regex)
// ------------------------

template<class TYPE, allow ALLOW, class CONVERTER, class FILTER>
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
         "Node(child_t(\"{}\"),label) with a std::regex label,\n"
         "not a std::string label",
         kwd.name
      );
      throw;
   }
}

#undef GNDSTK_CONST
