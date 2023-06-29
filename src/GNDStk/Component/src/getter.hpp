
// Component::getter()
// These retrieve names from the derived class (for use in printing diagnostics,
// if applicable), then call detail::compGetter() to do most of the work.

// -----------------------------------------------------------------------------
// getter<T>(variant)
// The caller must specify T
// -----------------------------------------------------------------------------

// const
template<
   class T, class... Ts, class = std::enable_if_t<detail::is_in_v<T,Ts...>>
>
const T *getter(const std::variant<Ts...> &var) const
{
   return detail::compGetter<T>(var);
}

// non-const
template<
   class T, class... Ts, class = std::enable_if_t<detail::is_in_v<T,Ts...>>
>
T *getter(std::variant<Ts...> &var)
{
   return const_cast<T *>(std::as_const(*this).template getter<T>(var));
}


// -----------------------------------------------------------------------------
// getter(vector, key)
// getter(optional<vector>, key)
// Remark: while two getter() functions that appear later in this file work
// specifically on a vector<variant>, those require that the caller provide
// a template argument. The following two can, in fact, also be called with
// vector<variant>. Also, note that depending on which detail::compGetter()
// these forward to, the return type might be a reference to something, or
// might be a bool. Hence the decltype(auto) return type.
// -----------------------------------------------------------------------------

// const
template<
   class VEC, class = std::enable_if_t<detail::isVectorOrOptionalVector_v<VEC>>,
   LookupMode MODE, class EXTRACTOR, class TYPE, class CONVERTER
>
decltype(auto) getter(
   const VEC &vec, const Lookup<MODE,EXTRACTOR,TYPE,CONVERTER> &key,
   const std::string &fieldName = ""
) const {
   return detail::compGetter(vec, key, Namespace(), Class(), fieldName);
}

// non-const
template<
   class VEC, class = std::enable_if_t<detail::isVectorOrOptionalVector_v<VEC>>,
   LookupMode MODE, class EXTRACTOR, class TYPE, class CONVERTER
>
decltype(auto) getter(
   VEC &vec, const Lookup<MODE,EXTRACTOR,TYPE,CONVERTER> &key,
   const std::string &fieldName = ""
) {
   using RETURN = decltype(
      std::as_const(*this).template getter(vec, key, fieldName));

   if constexpr (std::is_reference_v<RETURN>)
      return const_cast<std::decay_t<RETURN> &>(
         std::as_const(*this).template getter(vec, key, fieldName));
   else
      return std::as_const(*this).template getter(vec, key, fieldName);
}


// -----------------------------------------------------------------------------
// getter<T>(vector<variant>, key)
// The caller must specify T
// -----------------------------------------------------------------------------

// const
template<
   class T, class... Ts, class = std::enable_if_t<detail::is_in_v<T,Ts...>>,
   LookupMode MODE, class EXTRACTOR, class TYPE, class CONVERTER
>
const T *getter(
   const std::vector<std::variant<Ts...>> &vecvar,
   const Lookup<MODE,EXTRACTOR,TYPE,CONVERTER> &key,
   const std::string &fieldName = ""
) const {
   return detail::compGetter<T>(vecvar, key, Namespace(), Class(), fieldName);
}

// non-const
template<
   class T, class... Ts, class = std::enable_if_t<detail::is_in_v<T,Ts...>>,
   LookupMode MODE, class EXTRACTOR, class TYPE, class CONVERTER
>
T *getter(
   std::vector<std::variant<Ts...>> &vecvar,
   const Lookup<MODE,EXTRACTOR,TYPE,CONVERTER> &key,
   const std::string &fieldName = ""
) {
   return const_cast<T *>(
      std::as_const(*this).template getter<T>(vecvar, key, fieldName)
   );
}
