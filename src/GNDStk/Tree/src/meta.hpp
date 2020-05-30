
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
// Tree::meta(meta_t<void>)
// -----------------------------------------------------------------------------

// const
const std::string &meta(
   const meta_t<void> &kwd,
   bool &found = detail::default_bool
) const {
   return meta(kwd.name,found);
}

// non-const
std::string &meta(
   const meta_t<void> &kwd,
   bool &found = detail::default_bool
) {
   return meta(kwd.name,found);
}



// -----------------------------------------------------------------------------
// Tree::meta(meta_t)
// -----------------------------------------------------------------------------

// RESULT
template<class RESULT, class CONVERTER>
RESULT meta(
   const meta_t<RESULT,CONVERTER> &kwd,
   bool &found = detail::default_bool
) const {
   // local "found"
   bool f;

   try {
      // look in the declaration node
      if (has_decl()) {
         auto d = decl().meta(kwd,f);
         if (f) { found = true; return d; }
      }

      // look in the top-level GNDS node
      if (has_top()) {
         auto t = top().meta(kwd,f);
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
   return decltype(top().meta(kwd,f)){};
}


// variant
// With caller-specified result type
template<class RESULT, class... Ts, class CONVERTER>
typename detail::oneof<RESULT,Ts...>::type meta(
   const meta_t<std::variant<Ts...>,CONVERTER> &kwd,
   bool &found = detail::default_bool
) const {
   return meta(meta_t<RESULT,CONVERTER>(kwd.name),found);
}
