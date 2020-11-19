
// (child_t)
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
      log::function("Node(child_t(\"{}\"))", kwd.name);
      throw;
   }
}

// (child_t, string)
template<class TYPE, allow ALLOW, class CONVERTER, class FILTER>
decltype(auto) operator()(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   std::string &&label,
   bool &found = detail::default_bool
) GNDSTK_CONST {
   try {
      // As above, don't need or want:
      //    if (kwd.name == "")
      //       detail::apply_converter<TYPE>{}(kwd,*this);
      return child(kwd.one(), detail::label_is(label), found);
   } catch (...) {
      log::function("Node(child_t(\"{}\"),label=\"{}\")", kwd.name, label);
      throw;
   }
}

#undef GNDSTK_CONST
