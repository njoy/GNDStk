
// -----------------------------------------------------------------------------
// Component::getter()
// -----------------------------------------------------------------------------

// The getter() functions of class Component get some names from the derived
// class (which are used when printing diagnostics, if applicable), and then
// call getter() functions in the detail:: namespace to do most of the work.
//
// The motivation for having the following at all is to simplify the retrieval,
// in the derived-class getters, of certain information in the Content{} struct
// of the derived class object. For simple data, e.g. an int or a std::string
// in the derived class' Content struct, a derived-class getter will simply
// do a "return Content.something", because nothing more complicated is needed.
// So, the below functions involve circumstances where something more involved
// needs to be done.


// -----------------------------------------------------------------------------
// getter(vec, key, name)
// -----------------------------------------------------------------------------

// const
template<
   class VEC, class KEY,
   class = detail::isSearchKey<KEY>
>
decltype(auto) getter(
   const VEC &vec, // vector, or optional vector
   const KEY &key, // index, label, or Lookup
   const std::string &fieldName
) const {
   return detail::getter(
      vec, key, DERIVED::namespaceName(), DERIVED::className(), fieldName
   );
}

// non-const
template<
   class VEC, class KEY,
   class = detail::isSearchKey<KEY>
>
decltype(auto) getter(
   VEC &vec,
   const KEY &key,
   const std::string &fieldName
) {
   using RET = decltype(
      std::as_const(*this).template getter(vec, key, fieldName));

   if constexpr (std::is_reference_v<RET>)
      return const_cast<std::decay_t<RET> &>(
         std::as_const(*this).template getter(vec, key, fieldName));
   else
      return std::as_const(*this).template getter(vec, key, fieldName);
}


// -----------------------------------------------------------------------------
// getter<RETURN>(variant, name)
// These, in contrast to the getter()s above, don't involve a vector or an
// optional vector. We bother having these only because of the (admittedly
// small, in this case) extra complexity of checking that the variant holds
// the requested alternative, and of producing diagnostics if it doesn't.
// -----------------------------------------------------------------------------

// const
template<
   class RETURN, class... Ts,
   class = std::enable_if_t<detail::isAlternative<RETURN,std::variant<Ts...>>>
>
const RETURN *getter(
   const std::variant<Ts...> &var,
   const std::string &fieldName
) const {
   return detail::getter<RETURN>(
      var, DERIVED::namespaceName(), DERIVED::className(), fieldName
   );
}

// non-const
template<
   class RETURN, class... Ts,
   class = std::enable_if_t<detail::isAlternative<RETURN,std::variant<Ts...>>>
>
RETURN *getter(
   std::variant<Ts...> &var,
   const std::string &fieldName
) {
   return const_cast<RETURN *>(
      std::as_const(*this).template getter<RETURN>(var, fieldName)
   );
}


// -----------------------------------------------------------------------------
// getter<RETURN>(vector<variant>, key, name)
// The motivation for these essentially amounts to the combined motivations
// for the above two sets of getter() functions.
// -----------------------------------------------------------------------------

// const
template<
   class RETURN, class KEY, class... Ts,
   class = detail::isSearchKey<KEY>,
   class = std::enable_if_t<detail::isAlternative<RETURN,std::variant<Ts...>>>
>
const RETURN *getter(
   const std::vector<std::variant<Ts...>> &vecvar,
   const KEY &key,
   const std::string &fieldName
) const {
   return detail::getter<RETURN>(
      vecvar, key, DERIVED::namespaceName(), DERIVED::className(), fieldName
   );
}

// non-const
template<
   class RETURN, class KEY, class... Ts,
   class = detail::isSearchKey<KEY>,
   class = std::enable_if_t<detail::isAlternative<RETURN,std::variant<Ts...>>>
>
RETURN *getter(
   std::vector<std::variant<Ts...>> &vecvar,
   const KEY &key,
   const std::string &fieldName
) {
   return const_cast<RETURN *>(
      std::as_const(*this).template getter<RETURN>(vecvar, key, fieldName)
   );
}
