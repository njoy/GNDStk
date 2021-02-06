
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
   static constexpr bool value =
       IsMeta <T>::value
    || IsChild<T>::value;
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

} // namespace detail



// -----------------------------------------------------------------------------
// KeywordTup
// -----------------------------------------------------------------------------

// default
// Note: sizeof...(Ks) >= 1, because we'll specialize the <> case
template<class... Ks>
class KeywordTup {
public:
   std::tuple<Ks...> tup;

   using last_t =
      // sans std::decay, const &ness can break is_something<> traits :-/
      typename std::decay<decltype(std::get<sizeof...(Ks)-1>(tup))>::type;

   template<
      class... LHS, class RHS,
      // ensure Ks... == LHS... RHS
      class = typename std::enable_if<
         std::is_same<
            std::tuple<Ks...>,
            std::tuple<LHS...,RHS>
         >::value
      >::type,
      // ensure RHS \in {Meta, Child, string, regex}
      class = typename std::enable_if<
          detail::IsMetaOrChild<RHS>::value
       || detail::IsStringOrRegex<RHS>::value
      >::type
   >
   KeywordTup(const KeywordTup<LHS...> &lhs, const RHS &rhs) :
      tup(std::tuple_cat(lhs.tup, std::tuple<RHS>(rhs)))
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



// -----------------------------------------------------------------------------
// operator|
// -----------------------------------------------------------------------------

/*
------------------------
CASES
------------------------

Below, KeywordTup<...> doesn't include <>; at least one element must exist.

-----------------------------------------+-------------------------------
   CASE                                  |  RESULT
-----------------------------------------+-------------------------------
1. Meta/Child | Meta/Child               |
   a. Meta  | Meta                       |  KeywordTup<Meta,Meta>
   b. Meta  | Child                      |  KeywordTup<Meta,Child>
   c. Child | Meta                       |  KeywordTup<Child,Meta>
   d. Child | Child                      |  KeywordTup<Child,Child>
-----------------------------------------+-------------------------------
2. Child | string/regex                  |
   a. Child | string                     |  KeywordTup<Child,string>
   b. Child | char *                     |  KeywordTup<Child,string>
   c. Child | regex                      |  KeywordTup<Child,regex>
-----------------------------------------+-------------------------------
3. KeywordTup<...> | Meta/Child          |
   a. KeywordTup<...> | Meta             |  KeywordTup<...,Meta>
   b. KeywordTup<...> | Child            |  KeywordTup<...,Child>
-----------------------------------------+-------------------------------
4. KeywordTup<...,Child> | string/regex  |
   a. KeywordTup<...,Child> | string     |  KeywordTup<...,Child,string>
   b. KeywordTup<...,Child> | char *     |  KeywordTup<...,Child,string>
   c. KeywordTup<...,Child> | regex      |  KeywordTup<...,Child,regex>
-----------------------------------------+-------------------------------
*/


// ------------------------
// Bootstrap KeywordTup<...>
// ------------------------

// 1. Meta/Child | Meta/Child
// ==> KeywordTup<Meta/Child, Meta/Child>
template<
   class LHS, class RHS,
   class=typename std::enable_if<detail::IsMetaOrChild<LHS>::value>::type,
   class=typename std::enable_if<detail::IsMetaOrChild<RHS>::value>::type
>
auto operator|(
   const LHS &lhs, // via SFINAE: Meta or Child
   const RHS &rhs  // via SFINAE: Meta or Child
) {
   log::debug("or: Meta/Child | Meta/Child");
   return KeywordTup<LHS,RHS>(KeywordTup<LHS>(lhs),rhs);
}


// 2. Child | string/regex
// ==> KeywordTup<Child, string/regex>
template<
   class TYPE, Allow ALLOW, class CONVERTER, class FILTER, class RHS,
   class right = typename detail::IsStringOrRegex<RHS>::type
>
auto operator|(
   const Child<TYPE,ALLOW,CONVERTER,FILTER> &lhs,
   const RHS &rhs // via SFINAE: string (or char * etc.) or regex
) {
   log::debug("or: Child | string/regex");
   using LHS = Child<TYPE,ALLOW,CONVERTER,FILTER>;
   return KeywordTup<LHS,right>(KeywordTup<LHS>(lhs),right(rhs));
}


// ------------------------
// Append to KeywordTup<...>
// ------------------------

// 3. KeywordTup<...> | Meta/Child
// ==> KeywordTup<..., Meta/Child>
template<
   class... LHS, class RHS,
   class=typename std::enable_if<detail::IsMetaOrChild<RHS>::value>::type
>
auto operator|(
   const KeywordTup<LHS...> &lhs,
   const RHS &rhs // via SFINAE: Meta or Child
) {
   log::debug("or: KeywordTup<...> | Meta/Child");
   return KeywordTup<LHS...,RHS>(lhs,rhs);
}


// 4. KeywordTup<...,Child> | string/regex
// ==> KeywordTup<..., Child, string/regex>
template<
   class... LHS, class RHS,
   class = typename std::enable_if<
      detail::IsChild<typename KeywordTup<LHS...>::last_t>::value
   >::type,
   class right = typename detail::IsStringOrRegex<RHS>::type
>
auto operator|(
   const KeywordTup<LHS...> &lhs,
   const RHS &rhs // via SFINAE: string (or char * etc.) or regex
) {
   log::debug("or: KeywordTup<...,Child> | string/regex");
   return KeywordTup<LHS...,right>(lhs,right(rhs));
}
