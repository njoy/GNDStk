
// -----------------------------------------------------------------------------
// Tree::meta()
// -----------------------------------------------------------------------------

// ------------------------
// meta(string)
// ------------------------

// const
decltype(auto) meta(
   const std::string &key,
   bool &found = detail::default_bool
) const {
   assert(not empty());
   return root->meta(key,found);
}

// non-const
decltype(auto) meta(
   const std::string &key,
   bool &found = detail::default_bool
) {
   assert(not empty());
   return root->meta(key,found);
}

// ------------------------
// meta(meta_t<RESULT>)
// ------------------------

// const
template<class RESULT>
decltype(auto) meta(
   const meta_t<RESULT> &kwd,
   bool &found = detail::default_bool
) const {
   assert(not empty());
   return root->meta(kwd,found);
}

// non-const
// not applicable
