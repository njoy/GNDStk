
// -----------------------------------------------------------------------------
// Node::meta(string)
//
// Searches the Node's metadata for a metadatum of the given name. If found,
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
   static std::string empty = "";

   // If a "found" flag was not sent to this function, we'll produce an error.
   // Otherwise, we'll assume that the caller intends to deal with the issue
   // in its own way, and therefore that we shouldn't produce such an error.
   // Note that the question of whether a "found" flag was sent is determined
   // by looking at its address. This is entirely different from the question
   // of what found's value proves to be.
   if (&found == &detail::default_bool)
      error(
         "Node meta() called with key \"" + key + "\", "
         "but this key wasn't\nfound in the node's metadata."
      );

   // done
   return empty;
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
// Four cases of meta_t<*>:
//    RESULT    General case
//    string    For string, more efficient than general case
//    void      Like string case
//    variant   With caller-specified result type
// -----------------------------------------------------------------------------

// ------------------------
// meta(meta_t<RESULT>)
// ------------------------

// const
template<class RESULT>
RESULT meta(
   const meta_t<RESULT> &kwd,
   bool &found = detail::default_bool
) const {
   // call meta(string) above, with meta_t's key
   const std::string &value = meta(kwd.name,found);

   // convert value, if any, to the appropriate result type
   RESULT ret{};
   if (found)
      string2type(value,ret);
   return ret;
}

// non-const
// not needed


// ------------------------
// meta(meta_t<string>)
// meta(meta_t<void>)
// ------------------------

// Consistent with other meta_t<> cases (as opposed to the raw-string case),
// these return their result (which happens to be string) by value; we thus
// need only the const cases.

// Functionally equivalent to using meta(meta_t<RESULT>) with RESULT = string,
// but more direct and thus perhaps more efficient.
std::string meta(
   const meta_t<std::string> &kwd,
   bool &found = detail::default_bool
) const {
   return meta(kwd.name,found);
}

// Let's define the meta_t<void> case to be equivalent to the meta_t<string>
// case. This makes meta_t's behavior more consistent with that of child_t,
// which uses <void> to stipulate that the child node be returned in its
// original tree-node form.
std::string meta(
   const meta_t<void> &kwd,
   bool &found = detail::default_bool
) const {
   return meta(kwd.name,found);
}


// ------------------------
// meta(meta_t<variant>)
// With caller-specified
// result/return type
// ------------------------

// const
template<class RESULT, class... Ts>
RESULT meta(
   const meta_t<std::variant<Ts...>> &kwd,
   bool &found = detail::default_bool
) const {
   // body resembles that of general case, but function
   // signature is structurally different
   const std::string &value = meta(kwd.name,found);
   RESULT ret{}; // RESULT having been direct-specified as noted above
   if (found)
      string2type(value,ret);
   return ret;
}

// non-const
// not needed
