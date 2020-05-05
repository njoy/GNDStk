
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

   try {
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
   } catch (const std::exception &) {
      log::context("Tree::meta(\"{}\")", key);
      throw;
   }

   // well, we didn't find it
   found = false;

   if (!detail::sent(found)) {
      log::error(
         "Tree::meta(\"{}\"): key not found in metadata of either\n"
         "the declaration node or the top-level GNDS node",
         key
      );
      throw std::exception{};
   }

   // done
   static std::string empty;
   return empty = "";
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
// Non-const versions are needed only for the std::string and void cases,
// because the const version otherwise returns by value.
// -----------------------------------------------------------------------------

// ------------------------
// RESULT
// ------------------------

template<class RESULT>
decltype(auto) // RESULT, except const string & if RESULT is void or string
meta(
   const meta_t<RESULT> &kwd,
   bool &found = detail::default_bool
) const {
   // local "found"
   bool f;

   try {
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
   } catch (const std::exception &) {
      log::context("Tree::meta(meta_t(\"{}\"))", kwd.name);
      throw;
   }

   // well, we didn't find it
   found = false;

   if (!detail::sent(found)) {
      log::error(
         "Tree::meta(meta_t(\"{}\")): key not found in metadata of either\n"
         "the declaration node or the top-level GNDS node",
         kwd.name
      );
      throw std::exception{};
   }

   // done
   // fixme Consider that we really only need static for void or string,
   // as otherwise the return is by value
   static decltype(decl().meta(kwd,f)) type{};
   return type;
}


// ------------------------
// void or string
// ------------------------

// const
// Handled appropriately by the decltype(auto) return case.
// So, we don't need to repeat, or factor out, its content.

// non-const
template<class T>
typename detail::metaReturn<T,std::string &>::special meta(
   const meta_t<T> &kwd,
   bool &found = detail::default_bool
) {
   return const_cast<std::string &>(std::as_const(*this).meta(kwd,found));
}


// ------------------------
// variant
// ------------------------

template<class RESULT, class... Ts>
typename detail::oneof<RESULT,Ts...>::type meta(
   const meta_t<std::variant<Ts...>> &kwd,
   bool &found = detail::default_bool
) const {
   return meta(meta_t<RESULT>(kwd.name),found);
}
