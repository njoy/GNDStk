
// -----------------------------------------------------------------------------
// Tree::meta(string)
// -----------------------------------------------------------------------------

// const
const std::string &meta(
   const std::string &key,
   bool &found = detail::default_bool
) const {
   // local "found"
   bool f;

   // look in the declaration node
   if (has_decl()) {
      const std::string &d = decl().meta(key,f);
      if (f) return found = true, d;
   }

   // look in the top-level GNDS node
   if (has_top()) {
      const std::string &t = top().meta(key,f);
      if (f) return found = true, t;
   }

   // well, we didn't find it
   if (detail::not_sent(found))
      error(
         "Tree meta() called with key \"" + key + "\", "
         "but this key wasn't\nfound in the tree's declaration node "
         "or in its top-level GNDS node."
      );

   static std::string empty;
   return found = false, empty = "";
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

   // local "found"
   bool f;

   // look in the declaration node
   if (has_decl()) {
      decltype(auto) d = decl().meta(kwd,f);
      if (f) { found = true; return d; }
   }

   // look in the top-level GNDS node
   if (has_top()) {
      decltype(auto) t = top().meta(kwd,f);
      if (f) { found = true; return t; }
   }

   // well, we didn't find it
   if (detail::not_sent(found))
      error(
         "Tree meta() called with key \"" + kwd.name + "\", "
         "but this key wasn't\nfound in the tree's declaration node "
         "or in its top-level GNDS node."
      );

   found = false;
   decltype(decl().meta(kwd,f)) type{};
   return type;
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
