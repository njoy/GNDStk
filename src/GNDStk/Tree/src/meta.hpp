
// -----------------------------------------------------------------------------
// Tree::meta(string)
// -----------------------------------------------------------------------------

// const
const std::string &meta(
   const std::string &key,
   bool &found = detail::default_bool
) const {
   // if tree is empty, but a "found" flag wasn't sent
   if (empty() and &found == &detail::default_bool) {
      // fixme need a real error
      assert(false);
   }

   // first, look in the declaration node; then look in the top-level node
   bool found_in_decl;
   const std::string &ret = decl().meta(key,found_in_decl);
   return found_in_decl ? (found = true, ret) : top().meta(key,found);
}


// non-const
std::string &meta(
   const std::string &key,
   bool &found = detail::default_bool
) {
   return const_cast<std::string &>(std::as_const(*this).meta(key,found));
}



// -----------------------------------------------------------------------------
// Tree::meta(meta_t<RESULT>)
// Tree::meta(meta_t<variant>)
//
// Non-const versions aren't needed for these, because the const versions
// return by value.
// -----------------------------------------------------------------------------

// RESULT
template<class RESULT>
decltype(auto) // usually RESULT, but std::string if RESULT == void
meta(
   const meta_t<RESULT> &kwd,
   bool &found = detail::default_bool
) const {
   if (empty() and &found == &detail::default_bool) {
      // fixme need a real error
      assert(false);
   }

   bool found_in_decl;
   const auto ret = decl().meta(kwd,found_in_decl);
   return found_in_decl ? (found = true, ret) : top().meta(kwd,found);
}


// variant
template<class RESULT, class... Ts>
typename std::enable_if<
   detail::is_oneof<RESULT,Ts...>::value,
   RESULT
>::type meta(
   const meta_t<std::variant<Ts...>> &kwd,
   bool &found = detail::default_bool
) const {
   return meta(meta_t<RESULT>(kwd.name),found);
}
