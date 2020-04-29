
// -----------------------------------------------------------------------------
// Tree::operator()
// -----------------------------------------------------------------------------

// ------------------------
// const
// ------------------------

// meta_t
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
template<
   class RESULT, find FIND, class METADATA, class CHILDREN,
   class... Keywords
>
decltype(auto) operator()(
   const child_t<RESULT,FIND,METADATA,CHILDREN> &kwd,
   Keywords &&...keywords
) const {
   try {
      if (kwd.name == "" && has_decl())
         detail::apply_keyword<RESULT>()(decl());
      return child(-kwd)(std::forward<Keywords>(keywords)...);
   } catch (const std::exception &) {
      log::context("Tree(child_t(\"{}\"),...) const", kwd.name);
      throw;
   }
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
   try {
      if (kwd.name == "" && has_decl())
         detail::apply_keyword<RESULT>()(decl());
      return this->child(-kwd)(std::forward<Keywords>(keywords)...);
   } catch (const std::exception &) {
      log::context("Tree(child_t(\"{}\"),...)", kwd.name);
      throw;
   }
}
