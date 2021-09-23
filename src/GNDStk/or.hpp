
// -----------------------------------------------------------------------------
// fixme
// Material here should be rearranged at some point, to be consistent with the
// general NJOY21 source structure. For now, we're making it available quickly.
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Helper classes:
//    IsMeta
//    IsChild
//    IsMetaOrChild
//    IsStringOrRegex
// for SFINAE.
// -----------------------------------------------------------------------------

namespace detail {

// ------------------------
// IsMeta
// ------------------------

// default
template<class T>
class IsMeta {
public:
   static constexpr bool value = false;
};

// Meta
template<class TYPE, class CONVERTER>
class IsMeta<Meta<TYPE,CONVERTER>> {
public:
   static constexpr bool value = true;
};


// ------------------------
// IsChild
// ------------------------

// default
template<class T>
class IsChild {
public:
   static constexpr bool value = false;
};

// Child
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
class IsChild<Child<TYPE,ALLOW,CONVERTER,FILTER>> {
public:
   static constexpr bool value = true;
};


// ------------------------
// IsMetaOrChild
// ------------------------

template<class T>
class IsMetaOrChild {
public:
   static constexpr bool value = IsMeta<T>::value || IsChild<T>::value;
};


// ------------------------
// IsStringOrRegex
// ------------------------

// default
template<class T>
class IsStringOrRegex {
public:
   static constexpr bool value = false;
};

// string
template<>
class IsStringOrRegex<std::string> {
public:
   static constexpr bool value = true;
   using type = std::string;
};

// char *
template<>
class IsStringOrRegex<char *> {
public:
   static constexpr bool value = true;
   using type = std::string;
};

// const char *
template<>
class IsStringOrRegex<const char *> {
public:
   static constexpr bool value = true;
   using type = std::string;
};

// char[N]
template<std::size_t N>
class IsStringOrRegex<char[N]> {
public:
   static constexpr bool value = true;
   using type = std::string;
};

// regex
template<>
class IsStringOrRegex<std::regex> {
public:
   static constexpr bool value = true;
   using type = std::regex;
};


// ------------------------
// IsPairChildStringOrRegex
// ------------------------

// default
template<class T>
class IsPairChildStringOrRegex {
public:
   static constexpr bool value = false;
};

// pair
template<class FIRST, class SECOND>
class IsPairChildStringOrRegex<std::pair<FIRST,SECOND>> {
public:
   static constexpr bool value =
      IsChild<FIRST>::value && IsStringOrRegex<SECOND>::value;
};

} // namespace detail



// -----------------------------------------------------------------------------
// Helper functionality for std::tuple
// -----------------------------------------------------------------------------

namespace detail {

// ------------------------
// tupleAllButLast
// ------------------------

// These are adapted from: https://stackoverflow.com/questions/51810702

template<class... Args, std::size_t... Is>
constexpr auto tupleAllButLastHelper(
   const std::tuple<Args...> &tup,
   std::index_sequence<Is...>
) {
   return std::tuple(std::get<Is>(tup)...);
}

template<
   class... Args,
   class = std::enable_if_t<(0 < sizeof...(Args))>
>
constexpr auto tupleAllButLast(const std::tuple<Args...> &tup)
{
   return tupleAllButLastHelper(
      tup,
      std::make_index_sequence<sizeof...(Args) - 1>{}
   );
}


// ------------------------
// tupleReplaceLast
// ------------------------

// Given a tuple with at least one element, make a new tuple that's mostly the
// same, except for a different last element, which can be of a different type.

template<
   class... Args, class RHS,
   class = std::enable_if_t<(0 < sizeof...(Args))>
>
constexpr auto tupleReplaceLast(const std::tuple<Args...> &tup, const RHS &rhs)
{
   return std::tuple_cat(tupleAllButLast(tup), std::tuple<RHS>(rhs));
}

} // namespace detail



// -----------------------------------------------------------------------------
// KeywordTup
// -----------------------------------------------------------------------------

// default
template<class... Ks>
class KeywordTup {
public:
   std::tuple<Ks...> tup;

   using last_t =
      // Sans std::decay, const &ness can break detail::IsSomething<> traits.
      // Note: sizeof...(Ks) >= 1 here, because we'll specialize the <> case
      std::decay_t<decltype(std::get<sizeof...(Ks)-1>(tup))>;

   // KeywordTup(KeywordTup, RHS)
   template<
      class... LHS, class RHS,
      // ensure Ks... == LHS... RHS
      class = std::enable_if_t<
         std::is_same_v<
            std::tuple<Ks...>,
            std::tuple<LHS...,RHS>
         >
      >,
      // ensure RHS \in {Meta, Child, pair<Child,string|regex>, string, regex}
      class = std::enable_if_t<
          detail::IsMetaOrChild<RHS>::value ||
          detail::IsPairChildStringOrRegex<RHS>::value
      >
   >
   KeywordTup(const KeywordTup<LHS...> &lhs, const RHS &rhs) :
      tup(std::tuple_cat(lhs.tup, std::tuple<RHS>(rhs)))
   { }

   // KeywordTup(tuple)
   KeywordTup(const std::tuple<Ks...> &tup) :
      tup(tup)
   { }
};


// <>
// intentionally non-constructible
template<>
class KeywordTup<>
{
   KeywordTup() = delete;
   KeywordTup(const KeywordTup &) = delete;
   KeywordTup(KeywordTup &&) = delete;
};


// just Meta
template<class TYPE, class CONVERTER>
class KeywordTup<Meta<TYPE,CONVERTER>> {
   using M = Meta<TYPE,CONVERTER>;
public:
   std::tuple<M> tup;
   explicit KeywordTup(const M &m) : tup(m) { }
};


// just Child
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
class KeywordTup<Child<TYPE,ALLOW,CONVERTER,FILTER>> {
   using C = Child<TYPE,ALLOW,CONVERTER,FILTER>;
public:
   std::tuple<C> tup;
   explicit KeywordTup(const C &c) : tup(c) { }
};


// std::pair<Child,string>
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
class KeywordTup<std::pair<Child<TYPE,ALLOW,CONVERTER,FILTER>,std::string>> {
   using CPAIR = std::pair<Child<TYPE,ALLOW,CONVERTER,FILTER>,std::string>;
public:
   using last_t = CPAIR;
   std::tuple<CPAIR> tup;
   explicit KeywordTup(const CPAIR &cpair) : tup(cpair) { }
};


// std::pair<Child,regex>
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
class KeywordTup<std::pair<Child<TYPE,ALLOW,CONVERTER,FILTER>,std::regex>> {
   using CPAIR = std::pair<Child<TYPE,ALLOW,CONVERTER,FILTER>,std::regex>;
public:
   using last_t = CPAIR;
   std::tuple<CPAIR> tup;
   explicit KeywordTup(const CPAIR &cpair) : tup(cpair) { }
};



// -----------------------------------------------------------------------------
// toKeywordTup
// -----------------------------------------------------------------------------

// for std::tuple
template<class... Args>
constexpr auto toKeywordTup(const std::tuple<Args...> &tup)
{
   return KeywordTup<Args...>(tup);
}

// for KeywordTup
template<class... Args>
constexpr auto toKeywordTup(const KeywordTup<Args...> &kwds)
{
   return kwds;
}

// for Meta, Child, and pair<Child,string/regex>
// Returns a 1-element KeywordTup made from the object
template<
   class T,
   class = std::enable_if_t<
       detail::IsMetaOrChild<T>::value ||
       detail::IsPairChildStringOrRegex<T>::value
   >
>
constexpr auto toKeywordTup(const T &obj)
{
   return KeywordTup<T>(obj);
}



// -----------------------------------------------------------------------------
// operator|
// -----------------------------------------------------------------------------

/*
------------------------
CASES
------------------------

Below, KeywordTup<...> doesn't include <>; at least one element must exist.

-----------------------------------------+------------------------------------
   CASE                                  |  RESULT
-----------------------------------------+------------------------------------
1. Meta/Child | Meta/Child               |
   a. Meta  | Meta                       |  KeywordTup<Meta,Meta>
   b. Meta  | Child                      |  KeywordTup<Meta,Child>
   c. Child | Meta                       |  KeywordTup<Child,Meta>
   d. Child | Child                      |  KeywordTup<Child,Child>
-----------------------------------------+------------------------------------
2. Child | string/regex                  |
   a. Child | string                     |  KeywordTup<pair<Child,string>>
   b. Child | char *                     |  KeywordTup<pair<Child,string>>
   c. Child | regex                      |  KeywordTup<pair<Child,regex>>
-----------------------------------------+------------------------------------
3. KeywordTup<...> | Meta/Child          |
   a. KeywordTup<...> | Meta             |  KeywordTup<...,Meta>
   b. KeywordTup<...> | Child            |  KeywordTup<...,Child>
-----------------------------------------+------------------------------------
4. KeywordTup<...,Child> | string/regex  |
   a. KeywordTup<...,Child> | string     |  KeywordTup<...,pair<Child,string>>
   b. KeywordTup<...,Child> | char *     |  KeywordTup<...,pair<Child,string>>
   c. KeywordTup<...,Child> | regex      |  KeywordTup<...,pair<Child,regex>>
-----------------------------------------+------------------------------------
*/


// ------------------------
// Bootstrap KeywordTup<...>
// ------------------------

// 1. Meta/Child | Meta/Child
// ==> KeywordTup<Meta/Child, Meta/Child>
template<
   class LHS, class RHS,
   class = std::enable_if_t<detail::IsMetaOrChild<LHS>::value>,
   class = std::enable_if_t<detail::IsMetaOrChild<RHS>::value>
>
auto operator|(
   const LHS &lhs, // via SFINAE: Meta or Child
   const RHS &rhs  // via SFINAE: Meta or Child
) {
   log::debug("or #1: Meta/Child | Meta/Child");
   return KeywordTup<LHS,RHS>(KeywordTup<LHS>(lhs),rhs);
}


// 2. Child | string/regex
// ==> KeywordTup<pair<Child,string/regex>>
template<
   class TYPE, Allow ALLOW, class CONVERTER, class FILTER, class RHS,
   class StringOrRegex = typename detail::IsStringOrRegex<RHS>::type
>
auto operator|(
   const Child<TYPE,ALLOW,CONVERTER,FILTER> &lhs,
   const RHS &rhs // via SFINAE: string (or char * etc.) or regex
) {
   log::debug("or #2: Child | string/regex");
   using LHS = Child<TYPE,ALLOW,CONVERTER,FILTER>;
   return KeywordTup<std::pair<LHS,StringOrRegex>>(
      std::pair<LHS,StringOrRegex>(lhs,StringOrRegex(rhs))
   );
}



// ------------------------
// Append to KeywordTup<...>
// ------------------------

// 3. KeywordTup<...> | Meta/Child
// ==> KeywordTup<..., Meta/Child>
template<
   class... LHS, class RHS,
   class = std::enable_if_t<detail::IsMetaOrChild<RHS>::value>
>
auto operator|(
   const KeywordTup<LHS...> &lhs,
   const RHS &rhs // via SFINAE: Meta or Child
) {
   log::debug("or #3: KeywordTup<...> | Meta/Child");
   return KeywordTup<LHS...,RHS>(lhs,rhs);
}


// 4. KeywordTup<...,Child> | string/regex
// ==> KeywordTup<..., pair<Child,string/regex>>
template<
   class... LHS, class RHS,
   class = std::enable_if_t<
      detail::IsChild<typename KeywordTup<LHS...>::last_t>::value
   >,
   class StringOrRegex = typename detail::IsStringOrRegex<RHS>::type
>
auto operator|(
   const KeywordTup<LHS...> &lhs,
   const RHS &rhs // via SFINAE: string (or char * etc.) or regex
) {
   log::debug("or #4: KeywordTup<...,Child> | string/regex");
   return toKeywordTup(
      detail::tupleReplaceLast(
         lhs.tup,
         std::make_pair(
            std::get<sizeof...(LHS)-1>(lhs.tup),
            StringOrRegex(rhs)
         )
      )
   );
}
