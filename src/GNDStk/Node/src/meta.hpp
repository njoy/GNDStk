
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
      if (std::regex_match(m.first, std::regex(key)))
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
// Node.meta(meta_t<non-void>)
// -----------------------------------------------------------------------------

// ------------------------
// TYPE
// ------------------------

template<class TYPE, class CONVERTER>
TYPE meta(
   const meta_t<TYPE,CONVERTER> &kwd,
   bool &found = detail::default_bool
) const {
   try {
      // call meta(string), with the meta_t's key
      const std::string &value = meta(kwd.name,found);
      // convert value, if any, to an object of the appropriate type
      TYPE obj = kwd.object;
      if (found)
         kwd.converter(value,obj);
      return obj;
   } catch (...) {
      log::member("Node.meta(" + detail::keyname(kwd) + ")");
      throw;
   }
}


// ------------------------
// optional<TYPE>
// ------------------------

template<class TYPE, class CONVERTER>
std::optional<TYPE> meta(
   const meta_t<std::optional<TYPE>,CONVERTER> &kwd,
   bool &found = detail::default_bool
) const {
   try {
      // Local "found", because found == default can lead to exceptions.
      // We still place in a try{}, in case an exception otherwise arises.
      bool f;
      const TYPE obj = meta((kwd.object ? *kwd.object : TYPE{})/kwd, f);
      // The "found" status affects our behavior here, but for optional we'll
      // always *return* with found == true. After all, being optional means
      // something can be (1) there or (2) not there. That condition is always
      // true. :-) And, this way, if an optional element isn't there, then its
      // absence won't break a multi-query.
      found = true;
      return f ? std::optional<TYPE>(obj) : std::nullopt;
   } catch (...) {
      log::member("Node.meta(" + detail::keyname(kwd) + ")");
      throw;
   }
}


// ------------------------
// variant
// ------------------------

// With caller-specified type
template<class TYPE, class... Ts, class CONVERTER>
typename detail::oneof<TYPE,std::variant<Ts...>>::type meta(
   const meta_t<std::variant<Ts...>,CONVERTER> &kwd,
   bool &found = detail::default_bool
) const {
   const auto ptr = std::get_if<TYPE>(&kwd.object);
   return meta((ptr ? *ptr : TYPE{})/kwd, found);
}
