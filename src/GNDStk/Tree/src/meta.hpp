
// -----------------------------------------------------------------------------
// Tree::meta(string)
// -----------------------------------------------------------------------------

// const
const std::string &meta(
   const std::string &key,
   bool &found = detail::default_bool
) const {
   debug(detail::tm21);

   // if tree is empty, but a "found" flag wasn't sent
   if (empty() and &found == &detail::default_bool) {
      // fixme need a real error
      assert(false);
   }

   // first, look in the declaration node; then look in the top-level node
   bool f; // local "found"
   const std::string &d = decl().meta(key,f); if (f) { found = true; return d; }
   const std::string &t = top ().meta(key,f); if (f) { found = true; return t; }

   if (&found == &detail::default_bool)
      error(
         "Tree meta() called with key \"" + key + "\", "
         "but this key wasn't\nfound in the tree's declaration node "
         "or in its top-level GNDS node."
      );

   found = false;
   return t;
}


// non-const
std::string &meta(
   const std::string &key,
   bool &found = detail::default_bool
) {
   debug(detail::tm22);
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
   debug(detail::tm23);

   if (empty() and &found == &detail::default_bool) {
      // fixme need a real error
      assert(false);
   }

   /*
   bool found_in_decl;
   const auto ret = decl().meta(kwd,found_in_decl);
   return found_in_decl ? (found = true, ret) : top().meta(kwd,found);
   */

   bool f; // local "found"
   const auto d = decl().meta(kwd,f); if (f) { found = true; return d; }
   const auto t = top ().meta(kwd,f); if (f) { found = true; return t; }

   if (&found == &detail::default_bool)
      error(
         "Tree meta() called with meta_t key \"" + kwd.name + "\", "
         "but this key wasn't\nfound in the tree's declaration node "
         "or in its top-level GNDS node."
      );

   found = false;
   return t;
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
   debug(detail::tm24);
   return meta(meta_t<RESULT>(kwd.name),found);
}
