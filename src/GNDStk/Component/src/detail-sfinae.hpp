
// -----------------------------------------------------------------------------
// Re: [optional] vector [of variant]
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

// isVector_v
template<class T>
inline constexpr bool isVector_v = isVector<T>::value;

// isVector_t
template<class T>
using isVector_t = std::enable_if_t<isVector_v<T>>;

// ------------------------
// isOptionalVector
// ------------------------

// general
template<class T>
struct isOptionalVector
   : public std::false_type
{ };

// for std::optional<std::vector>
template<class T, class Alloc>
struct isOptionalVector<std::optional<std::vector<T,Alloc>>>
   : public std::true_type
{ };

// for GNDStk::Optional<std::vector>
template<class T, class Alloc>
struct isOptionalVector<GNDStk::Optional<std::vector<T,Alloc>>>
   : public std::true_type
{ };

// isOptionalVector_v
template<class T>
inline constexpr bool isOptionalVector_v = isOptionalVector<T>::value;

// isOptionalVector_t
template<class T>
using isOptionalVector_t = std::enable_if_t<isOptionalVector_v<T>>;

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

// for GNDStk::Optional<std::vector>
template<class T, class Alloc>
struct isVectorOrOptionalVector<GNDStk::Optional<std::vector<T,Alloc>>>
   : public std::true_type
{
   using value_type = T;
};

// isVectorOrOptionalVector_v
template<class T>
inline constexpr bool isVectorOrOptionalVector_v =
   isVectorOrOptionalVector<T>::value;

// isVectorOrOptionalVector_t
template<class T>
using isVectorOrOptionalVector_t =
   std::enable_if_t<isVectorOrOptionalVector_v<T>>;

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

// isVectorVariant_t
template<class T>
using isVectorVariant_t = std::enable_if_t<isVectorVariant<T>::value>;


// -----------------------------------------------------------------------------
// Re: Defaulted
// -----------------------------------------------------------------------------

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

// isDefaulted_t
template<class T>
using isDefaulted_t = std::enable_if_t<isDefaulted<T>::value>;


// -----------------------------------------------------------------------------
// Re: Lookup
// -----------------------------------------------------------------------------

// ------------------------
// isLookup
// ------------------------

// general
template<class T>
struct isLookup
   : public std::false_type
{ };

// for Lookup
template<LookupMode MODE, class EXTRACTOR, class TYPE, class CONVERTER>
struct isLookup<Lookup<MODE,EXTRACTOR,TYPE,CONVERTER>>
   : public std::true_type
{ };

// isLookup_v
template<class T>
inline constexpr bool isLookup_v = isLookup<T>::value;

// isLookup_t
template<class T>
using isLookup_t = std::enable_if_t<isLookup_v<T>>;

// ------------------------
// isLookupRefReturn
// ------------------------

// general
template<class T>
struct isLookupRefReturn
   : public std::false_type
{ };

// for Lookup<get,EXTRACTOR,non-void,CONVERTER>
template<class EXTRACTOR, class TYPE, class CONVERTER>
struct isLookupRefReturn<Lookup<LookupMode::get,EXTRACTOR,TYPE,CONVERTER>>
{
   static inline constexpr bool value = !isVoid<TYPE>;
};

// isLookupRefReturn_t
template<class T>
using isLookupRefReturn_t = std::enable_if_t<isLookupRefReturn<T>::value>;

// ------------------------
// isLookupBoolReturn_v
// ------------------------

template<class T>
inline constexpr bool isLookupBoolReturn_v =
   detail::isLookup_v<T> &&
  !detail::isLookupRefReturn<T>::value;


// -----------------------------------------------------------------------------
// Re: Component's "forwards"
// -----------------------------------------------------------------------------

// ------------------------
// isMatchExact
// ------------------------

// general
template<class, class>
struct isMatchExact {
   static constexpr int count = 0;
};

// FROM, vector<FROM>
template<class FROM, class Alloc>
struct isMatchExact<FROM,std::vector<FROM,Alloc>> {
   static constexpr int count = 1;
};

// FROM, std::optional<vector<FROM>>
template<class FROM, class Alloc>
struct isMatchExact<FROM,std::optional<std::vector<FROM,Alloc>>>
 : public isMatchExact<FROM,std::vector<FROM,Alloc>>
{ };

// FROM, GNDStk::Optional<vector<FROM>>
template<class FROM, class Alloc>
struct isMatchExact<FROM,GNDStk::Optional<std::vector<FROM,Alloc>>>
 : public isMatchExact<FROM,std::vector<FROM,Alloc>>
{ };

// ------------------------
// MatchesExact
// ------------------------

// general
template<class, class>
struct MatchesExact {
   static constexpr size_t count = 0;
};

// FROM, tuple<...>
template<class FROM, class... TOs>
struct MatchesExact<FROM,std::tuple<TOs...>> {
   static constexpr size_t count = (
      isMatchExact<
         FROM,
         std::decay_t<decltype(Node{}(std::declval<TOs>()))>
      >::count +
      ...
   );
};

// ------------------------
// isMatchViable
// ------------------------

// general
template<class, class>
struct isMatchViable {
   static constexpr int count = 0;
};

// FROM, vector<TO>
template<class FROM, class TO, class Alloc>
struct isMatchViable<FROM,std::vector<TO,Alloc>> {
   static constexpr int count = std::is_convertible_v<FROM,TO>;
};

// FROM, std::optional<vector<TO>>
template<class FROM, class TO, class Alloc>
struct isMatchViable<FROM,std::optional<std::vector<TO,Alloc>>>
 : public isMatchViable<FROM,std::vector<TO,Alloc>>
{ };

// FROM, GNDStk::Optional<vector<TO>>
template<class FROM, class TO, class Alloc>
struct isMatchViable<FROM,GNDStk::Optional<std::vector<TO,Alloc>>>
 : public isMatchViable<FROM,std::vector<TO,Alloc>>
{ };

// ------------------------
// MatchesViable
// ------------------------

// general
template<class, class>
struct MatchesViable {
   static constexpr size_t count = 0;
};

// FROM, tuple<...>
template<class FROM, class... TOs>
struct MatchesViable<FROM,std::tuple<TOs...>> {
   static constexpr size_t count = (
      isMatchViable<
         FROM,
         std::decay_t<decltype(Node{}(std::declval<TOs>()))>
      >::count +
      ...
   );
};


// -----------------------------------------------------------------------------
// Miscellaneous
// -----------------------------------------------------------------------------

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
         std::conditional_t<isVariant_v<T>,void,T>{}
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
