
// -----------------------------------------------------------------------------
// Node.meta(string)
// Searches the node's metadata for a metadatum of the given name. If found,
// returns the value associated with the key. Else, returns an empty string.
// -----------------------------------------------------------------------------

// const
const std::string &meta(
   const std::string &key,
   bool &found = detail::default_bool
) const {
   // search
   for (auto &m : metadata)
      if (m.first == key)
         return found = true, m.second;

   // not found
   found = false;

   // If a "found" flag was not sent to this function, we'll produce an error.
   // Otherwise, we'll assume that the caller intends to deal with the issue
   // in its own way, and therefore that we shouldn't produce such an error.
   // Note that the question of whether a "found" flag was sent is determined
   // by looking at its address. This is entirely different from the question
   // of what found's value proves to be.
   if (!detail::sent(found)) {
      log::error("Key \"{}\" not found in metadata", key);
      log::member("Node.meta(\"{}\")", key);
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
// Node.meta(meta_t<void>)
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
// Node.meta(meta_t)
// -----------------------------------------------------------------------------

// TYPE
template<class TYPE, class CONVERTER>
TYPE meta(
   const meta_t<TYPE,CONVERTER> &kwd,
   bool &found = detail::default_bool
) const {
   try {
      // call meta(string), with the meta_t's key
      const std::string &value = meta(kwd.name,found);
      // convert value, if any, to the appropriate type
      TYPE type{};
      if (found)
         kwd.converter(value,type);
      return type;
   } catch (...) {
      log::member("Node.meta(meta_t(\"{}\"))", kwd.name);
      throw;
   }
}

// variant
// With caller-specified type
template<class TYPE, class... Ts, class CONVERTER>
typename detail::oneof<TYPE,Ts...>::type meta(
   const meta_t<std::variant<Ts...>,CONVERTER> &kwd,
   bool &found = detail::default_bool
) const {
   return meta(meta_t<TYPE,CONVERTER>(kwd.name),found);
}
