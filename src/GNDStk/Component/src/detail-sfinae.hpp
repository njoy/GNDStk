
// -----------------------------------------------------------------------------
// Helper classes
// -----------------------------------------------------------------------------

// ------------------------
// isVector
// ------------------------

// general
template<class T>
struct isVector
   : public std::false_type
{ };

// for std::vector
template<class T, class Alloc>
struct isVector<std::vector<T,Alloc>>
   : public std::true_type
{ };

template<class T>
using isVector_t = std::enable_if_t<isVector<T>::value>;

// ------------------------
// isOptionalVector
// ------------------------

// general
template<class T>
struct isOptionalVector
   : public std::false_type
{ };

// for std::vector
template<class T, class Alloc>
struct isOptionalVector<std::optional<std::vector<T,Alloc>>>
   : public std::true_type
{ };

template<class T>
using isOptionalVector_t = std::enable_if_t<isOptionalVector<T>::value>;

// ------------------------
// isVectorOrOptionalVector
// ------------------------

// general
template<class T>
struct isVectorOrOptionalVector
   : public std::false_type
{ };

// for std::vector
template<class T, class Alloc>
struct isVectorOrOptionalVector<std::vector<T,Alloc>>
   : public std::true_type
{
   using value_type = T;
};

// for std::optional<std::vector>
template<class T, class Alloc>
struct isVectorOrOptionalVector<std::optional<std::vector<T,Alloc>>>
   : public std::true_type
{
   using value_type = T;
};

template<class T>
using isVectorOrOptionalVector_t =
   std::enable_if_t<isVectorOrOptionalVector<T>::value>;

// ------------------------
// isVectorVariant
// ------------------------

// general
template<class T>
struct isVectorVariant
   : public std::false_type
{ };

// for std::vector<std::variant<...>>
template<class... Ts, class Alloc>
struct isVectorVariant<std::vector<std::variant<Ts...>,Alloc>>
   : public std::true_type
{ };

template<class T>
using isVectorVariant_t = std::enable_if_t<isVectorVariant<T>::value>;

// ------------------------
// isDefaulted
// ------------------------

// general
template<class T>
struct isDefaulted
   : public std::false_type
{ };

// for Defaulted
template<class T>
struct isDefaulted<Defaulted<T>>
   : public std::true_type
{ };

template<class T>
using isDefaulted_t = std::enable_if_t<isDefaulted<T>::value>;

// ------------------------
// isLookup
// ------------------------

// general
template<class T>
struct isLookup
   : public std::false_type
{ };

// for Lookup
template<bool HAS, class EXTRACTOR, class TYPE, class CONVERTER>
struct isLookup<Lookup<HAS,EXTRACTOR,TYPE,CONVERTER>>
   : public std::true_type
{ };

// ------------------------
// isLookupRefReturn
// ------------------------

// general
template<class T>
struct isLookupRefReturn
   : public std::false_type
{ };

// for Lookup<false,EXTRACTOR,TYPE,CONVERTER>, with TYPE != void wanted
template<class EXTRACTOR, class TYPE, class CONVERTER>
struct isLookupRefReturn<Lookup<false,EXTRACTOR,TYPE,CONVERTER>>
{
   static inline constexpr bool value = !isVoid<TYPE>;
};

// ------------------------
// isLookupBoolReturn
// ------------------------

template<class KEY>
inline constexpr bool isLookupBoolReturn =
   detail::isLookup<KEY>::value &&
  !detail::isLookupRefReturn<KEY>::value;

// ------------------------
// isSearchKey
// isSearchKeyRefReturn
// ------------------------

// isSearchKey
// Type is one of:
//    - convertible to std::size_t, for use as an index
//    - convertible to std::string, for use as a label
//    - of type Lookup<...>
template<class T>
using isSearchKey = std::enable_if_t<
   std::is_convertible_v<T,std::size_t> ||
   std::is_convertible_v<T,std::string> ||
   isLookup<T>::value // any Lookup
>;

// isSearchKeyRefReturn
// Like the above, but allowing only a Lookup that triggers a reference return
template<class T>
using isSearchKeyRefReturn = std::enable_if_t<
   std::is_convertible_v<T,std::size_t> ||
   std::is_convertible_v<T,std::string> ||
   isLookupRefReturn<T>::value // not any Lookup; must give a reference return
>;

// ------------------------
// firstOrOnly
// ------------------------

// general
template<class T>
struct firstOrOnly {
   using type = T;
};

// for variant
template<class T, class... Ts>
struct firstOrOnly<std::variant<T,Ts...>> {
   using type = T;
};

// ------------------------
// has_field
// Compare with has_index,
// as defined elsewhere
// ------------------------

// default
template<class EXTRACTOR, class T, class = int>
struct has_field
   : std::false_type { };

// general
template<class EXTRACTOR, class T>
struct has_field<
   EXTRACTOR,
   T,
   decltype(
      (void)std::declval<EXTRACTOR>()(
         std::conditional_t<isVariant<T>::value,void,T>{}
      ),
      0
   )
>
   : std::true_type { };

// for variant
template<class EXTRACTOR, class... Ts>
struct has_field<
   EXTRACTOR,
   std::variant<Ts...>
> {
   // does any alternative have the field?
   static constexpr bool value = (has_field<EXTRACTOR,Ts>::value || ...);
};
