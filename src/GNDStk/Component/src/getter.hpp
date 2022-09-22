
// Component::getter()
// These retrieve names from the derived class (for use in printing diagnostics,
// if applicable), then call detail::getter() functions to do most of the work.


// -----------------------------------------------------------------------------
// getter(vector, key)
// getter(optional<vector>, key)
// Remark: while two getter() functions that appear later in this file work
// specifically on a vector<variant>, those require that the caller provide
// a template argument. The following two can, in fact, also be called with
// vector<variant>. Also, note that depending on which detail::getter() these
// forward to, the return type might be a reference to something, or might be
// a bool. Hence the decltype(auto) return type.
// -----------------------------------------------------------------------------

// const
template<
   class VEC, class KEY, class = detail::isSearchKey<KEY>,
   class = std::enable_if_t<
      detail::isVector<VEC>::value ||
      detail::isOptionalVector<VEC>::value>
>
decltype(auto) getter(
   const VEC &vec, // vector, or optional vector
   const KEY &key, // index, label, or Lookup
   const std::string &fieldName = ""
) const {
   return detail::getter(vec, key, Namespace(), Class(), fieldName);
}

// non-const
template<
   class VEC, class KEY, class = detail::isSearchKey<KEY>,
   class = std::enable_if_t<
      detail::isVector<VEC>::value ||
      detail::isOptionalVector<VEC>::value>
>
decltype(auto) getter(
   VEC &vec,
   const KEY &key,
   const std::string &fieldName = ""
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
// getter<RETURN>(variant)
// The caller must specify RETURN
// -----------------------------------------------------------------------------

// const
template<
   class RETURN, class... Ts,
   class = std::enable_if_t<detail::isAlternative<RETURN,std::variant<Ts...>>>
>
const RETURN *getter(
   const std::variant<Ts...> &var,
   const std::string &fieldName = ""
) const {
   return detail::getter<RETURN>(var, Namespace(), Class(), fieldName);
}

// non-const
template<
   class RETURN, class... Ts,
   class = std::enable_if_t<detail::isAlternative<RETURN,std::variant<Ts...>>>
>
RETURN *getter(
   std::variant<Ts...> &var,
   const std::string &fieldName = ""
) {
   return const_cast<RETURN *>(
      std::as_const(*this).template getter<RETURN>(var, fieldName)
   );
}


// -----------------------------------------------------------------------------
// getter<RETURN>(vector<variant>, key)
// The caller must specify RETURN
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
   const std::string &fieldName = ""
) const {
   return detail::getter<RETURN>(vecvar, key, Namespace(), Class(), fieldName);
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
   const std::string &fieldName = ""
) {
   return const_cast<RETURN *>(
      std::as_const(*this).template getter<RETURN>(vecvar, key, fieldName)
   );
}
