
// -----------------------------------------------------------------------------
// Node::meta(string)
//
// Searches the node's metadata for a metadatum of the given name. If found,
// returns the key's paired value. Else, returns an empty string.
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
      log::error("Node::meta(\"{}\"): key not found in metadata", key);
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
// Node::meta(meta_t<*>)
//
// Cases:
//
//    RESULT    General case
//    string    For string, more efficient than general case
//    void      Like string case
//    variant   With caller-specified result type
// -----------------------------------------------------------------------------

// ------------------------
// meta(meta_t<RESULT>)
// ------------------------

template<class RESULT>
typename detail::metaReturn<RESULT,RESULT>::general meta(
   const meta_t<RESULT> &kwd,
   bool &found = detail::default_bool
) const {
   try {
      // call meta(string), with the meta_t's key
      const std::string &value = meta(kwd.name,found);
      // convert value, if any, to the appropriate result type
      RESULT type{};
      if (found)
         convert(value,type);
      return type;
   } catch (const std::exception &) {
      log::context("Node::meta(meta_t(\"{}\"))", kwd.name);
      throw;
   }
}


// ------------------------
// meta(meta_t<void or string>)
// ------------------------

// const
template<class T>
typename detail::metaReturn<T,const std::string &>::special meta(
   const meta_t<T> &kwd,
   bool &found = detail::default_bool
) const {
   return meta(kwd.name,found);
}

// non-const
template<class T>
typename detail::metaReturn<T,std::string &>::special meta(
   const meta_t<T> &kwd,
   bool &found = detail::default_bool
) {
   return meta(kwd.name,found);
}


// ------------------------
// meta(meta_t<variant>)
// With caller-specified
// result type
// ------------------------

template<class RESULT, class... Ts>
typename detail::oneof<RESULT,Ts...>::type meta(
   const meta_t<std::variant<Ts...>> &kwd,
   bool &found = detail::default_bool
) const {
   return meta(meta_t<RESULT>(kwd.name),found);
}
