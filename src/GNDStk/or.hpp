
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
// keywords
// -----------------------------------------------------------------------------

// default
// Note: sizeof...(Ks) >= 1, because we'll specialize the <> case
template<class... Ks>
class keywords {
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
   keywords(const keywords<LHS...> &lhs, const RHS &rhs) :
      tup(std::tuple_cat(lhs.tup, std::tuple<RHS>(rhs)))
   { }
};


// <>
// intentionally non-constructible
template<>
class keywords<>
{
   keywords() = delete;
   keywords(const keywords &) = delete;
   keywords(keywords &&) = delete;
};


// just Meta
template<class TYPE, class CONVERTER>
class keywords<Meta<TYPE,CONVERTER>> {
   using M = Meta<TYPE,CONVERTER>;
public:
   std::tuple<M> tup;
   explicit keywords(const M &m) : tup(m) { }
};


// just Child
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
class keywords<Child<TYPE,ALLOW,CONVERTER,FILTER>> {
   using C = Child<TYPE,ALLOW,CONVERTER,FILTER>;
public:
   std::tuple<C> tup;
   explicit keywords(const C &c) : tup(c) { }
};



// -----------------------------------------------------------------------------
// operator|
// -----------------------------------------------------------------------------

/*
------------------------
CASES
------------------------

Below, keywords<...> doesn't include <>; at least one element must exist.

---------------------------------------+-------------------------------
   CASE                                |  RESULT
---------------------------------------+-------------------------------
1. Meta/Child | Meta/Child             |
   a. Meta  | Meta                     |  keywords<Meta,Meta>
   b. Meta  | Child                    |  keywords<Meta,Child>
   c. Child | Meta                     |  keywords<Child,Meta>
   d. Child | Child                    |  keywords<Child,Child>
---------------------------------------+-------------------------------
2. Child | string/regex                |
   a. Child | string                   |  keywords<Child,string>
   b. Child | char *                   |  keywords<Child,string>
   c. Child | regex                    |  keywords<Child,regex>
---------------------------------------+-------------------------------
3. keywords<...> | Meta/Child          |
   a. keywords<...> | Meta             |  keywords<...,Meta>
   b. keywords<...> | Child            |  keywords<...,Child>
---------------------------------------+-------------------------------
4. keywords<...,Child> | string/regex  |
   a. keywords<...,Child> | string     |  keywords<...,Child,string>
   b. keywords<...,Child> | char *     |  keywords<...,Child,string>
   c. keywords<...,Child> | regex      |  keywords<...,Child,regex>
---------------------------------------+-------------------------------
*/


// ------------------------
// Bootstrap keywords<...>
// ------------------------

// 1. Meta/Child | Meta/Child
// ==> keywords<Meta/Child, Meta/Child>
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
   return keywords<LHS,RHS>(keywords<LHS>(lhs),rhs);
}


// 2. Child | string/regex
// ==> keywords<Child, string/regex>
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
   return keywords<LHS,right>(keywords<LHS>(lhs),right(rhs));
}


// ------------------------
// Append to keywords<...>
// ------------------------

// 3. keywords<...> | Meta/Child
// ==> keywords<..., Meta/Child>
template<
   class... LHS, class RHS,
   class=typename std::enable_if<detail::IsMetaOrChild<RHS>::value>::type
>
auto operator|(
   const keywords<LHS...> &lhs,
   const RHS &rhs // via SFINAE: Meta or Child
) {
   log::debug("or: keywords<...> | Meta/Child");
   return keywords<LHS...,RHS>(lhs,rhs);
}


// 4. keywords<...,Child> | string/regex
// ==> keywords<..., Child, string/regex>
template<
   class... LHS, class RHS,
   class = typename std::enable_if<
      detail::IsChild<typename keywords<LHS...>::last_t>::value
   >::type,
   class right = typename detail::IsStringOrRegex<RHS>::type
>
auto operator|(
   const keywords<LHS...> &lhs,
   const RHS &rhs // via SFINAE: string (or char * etc.) or regex
) {
   log::debug("or: keywords<...,Child> | string/regex");
   return keywords<LHS...,right>(lhs,right(rhs));
}
