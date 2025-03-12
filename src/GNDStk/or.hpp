
#include "GNDStk/or/src/detail.hpp"

/*
Discussion.

KeyTuple is based mostly on std::tuple, but is specifically designed to help
GNDStk's multi-query system work smoothly.

makeKeyTuple() can be understood in terms of the KEYS() function in a class
that derives from GNDStk::Component. Typically, a KEYS() function returns some
number of Meta and/or Child objects, |'d together with one of the operator|
overloads that we provide at the end of this file. However, a KEYS() function
can in fact return any of:

   - A KeyTuple (via operator| as described above).
   - A single Meta object.
   - A single Child object.
   - A std::tuple<>.

The first use is probably the most common, but all are allowed. The purpose of
makeKeyTuple() (which could be considered analogous to std::make_pair in C++)
is to take any of the above, and return an appropriately templated version of
KeyTuple, representing what KEYS() is asking for. Other functions can then be
defined uniformly in terms of KeyTuple only - not KeyTuple, Meta, etc.
*/


// -----------------------------------------------------------------------------
// KeyTuple
// -----------------------------------------------------------------------------

// default
template<class... Ks>
class KeyTuple {
public:
   std::tuple<Ks...> tup;

   // last_t
   using last_t =
      // Without std::decay, const &ness can break detail::IsSomething<> traits.
      // Note: sizeof...(Ks) >= 1 here; we've specialized the KeyTuple<> case.
      std::decay_t<decltype(std::get<sizeof...(Ks)-1>(tup))>;

   // KeyTuple(KeyTuple<LHS...>, RHS)
   template<
      class... LHS, class RHS,
      // require Ks... == LHS... RHS
      class = std::enable_if_t<
         std::is_same_v<std::tuple<Ks...>, std::tuple<LHS...,RHS>>
      >,
      // require RHS \in {Meta, Child, pair<Child,string|regex>}
      class = std::enable_if_t<
          detail::IsMetaOrChild_v<RHS> ||
          detail::IsPairChildStringOrRegex_v<RHS>
      >
   >
   KeyTuple(const KeyTuple<LHS...> &lhs, const RHS &rhs) :
      tup(std::tuple_cat(lhs.tup, std::tuple<RHS>(rhs)))
   { }

   // KeyTuple(tuple)
   KeyTuple(const std::tuple<Ks...> &tup) : tup(tup) { }
};

// <>
template<>
class KeyTuple<>
{
public:
   std::tuple<> tup;
   KeyTuple(const std::tuple<> &tup) : tup(tup) { }
};

// for Meta
template<class TYPE, class CONVERTER>
class KeyTuple<Meta<TYPE,CONVERTER>> {
   using M = Meta<TYPE,CONVERTER>;
public:
   std::tuple<M> tup;
   explicit KeyTuple(const M &m) : tup(m) { }
};

// for Child
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
class KeyTuple<Child<TYPE,ALLOW,CONVERTER,FILTER>> {
   using C = Child<TYPE,ALLOW,CONVERTER,FILTER>;
public:
   std::tuple<C> tup;
   explicit KeyTuple(const C &c) : tup(c) { }
};

// for std::pair<Child,string>
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
class KeyTuple<std::pair<Child<TYPE,ALLOW,CONVERTER,FILTER>,std::string>> {
   using CPAIR = std::pair<Child<TYPE,ALLOW,CONVERTER,FILTER>,std::string>;
public:
   using last_t = CPAIR;
   std::tuple<CPAIR> tup;
   explicit KeyTuple(const CPAIR &cpair) : tup(cpair) { }
};

// for std::pair<Child,regex>
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
class KeyTuple<std::pair<Child<TYPE,ALLOW,CONVERTER,FILTER>,std::regex>> {
   using CPAIR = std::pair<Child<TYPE,ALLOW,CONVERTER,FILTER>,std::regex>;
public:
   using last_t = CPAIR;
   std::tuple<CPAIR> tup;
   explicit KeyTuple(const CPAIR &cpair) : tup(cpair) { }
};


// -----------------------------------------------------------------------------
// makeKeyTuple
// -----------------------------------------------------------------------------

// for KeyTuple
template<class... Args>
constexpr auto makeKeyTuple(const KeyTuple<Args...> &keytup)
{
   return keytup;
}

// for Meta, Child, and pair<Child,string/regex>
// Returns a 1-element KeyTuple made from the object
template<
   class T,
   class = std::enable_if_t<
       detail::IsMetaOrChild_v<T> ||
       detail::IsPairChildStringOrRegex_v<T>
   >
>
constexpr auto makeKeyTuple(const T &obj)
{
   return KeyTuple<T>(obj);
}

// for std::tuple
template<class... Args>
constexpr auto makeKeyTuple(const std::tuple<Args...> &tup)
{
   return KeyTuple<Args...>(tup);
}


// -----------------------------------------------------------------------------
// operator|
// -----------------------------------------------------------------------------

/*
------------------------
CASES
------------------------

Below, KeyTuple<...> doesn't include <>; at least one element must exist.

---------------------------------------+------------------------------------
   CASE                                |  RESULT
---------------------------------------+------------------------------------
1. Meta/Child | Meta/Child             |
   a. Meta  | Meta                     |  KeyTuple<Meta,Meta>
   b. Meta  | Child                    |  KeyTuple<Meta,Child>
   c. Child | Meta                     |  KeyTuple<Child,Meta>
   d. Child | Child                    |  KeyTuple<Child,Child>
---------------------------------------+------------------------------------
2. Child | string/regex                |
   a. Child | string                   |  KeyTuple<pair<Child,string>>
   b. Child | char *                   |  KeyTuple<pair<Child,string>>
   c. Child | regex                    |  KeyTuple<pair<Child,regex>>
---------------------------------------+------------------------------------
3. KeyTuple<...> | Meta/Child          |
   a. KeyTuple<...> | Meta             |  KeyTuple<...,Meta>
   b. KeyTuple<...> | Child            |  KeyTuple<...,Child>
---------------------------------------+------------------------------------
4. KeyTuple<...,Child> | string/regex  |
   a. KeyTuple<...,Child> | string     |  KeyTuple<...,pair<Child,string>>
   b. KeyTuple<...,Child> | char *     |  KeyTuple<...,pair<Child,string>>
   c. KeyTuple<...,Child> | regex      |  KeyTuple<...,pair<Child,regex>>
---------------------------------------+------------------------------------
*/


// ------------------------
// Bootstrap KeyTuple<...>
// ------------------------

// 1. Meta/Child | Meta/Child
// ==> KeyTuple<Meta/Child, Meta/Child>
template<
   class LHS, class RHS,
   class = std::enable_if_t<detail::IsMetaOrChild_v<LHS>>,
   class = std::enable_if_t<detail::IsMetaOrChild_v<RHS>>
>
auto operator|(
   const LHS &lhs, // via SFINAE: Meta or Child
   const RHS &rhs  // via SFINAE: Meta or Child
) {
   return KeyTuple<LHS,RHS>(KeyTuple<LHS>(lhs),rhs);
}


// 2. Child | string/regex
// ==> KeyTuple<pair<Child,string/regex>>
template<
   class TYPE, Allow ALLOW, class CONVERTER, class FILTER, class RHS,
   class StringOrRegex = typename detail::IsStringOrRegex<RHS>::type
>
auto operator|(
   const Child<TYPE,ALLOW,CONVERTER,FILTER> &lhs,
   const RHS &rhs // via SFINAE: string (or char * etc.) or regex
) {
   using LHS = Child<TYPE,ALLOW,CONVERTER,FILTER>;
   return KeyTuple<std::pair<LHS,StringOrRegex>>(
      std::pair<LHS,StringOrRegex>(lhs,StringOrRegex(rhs))
   );
}


// ------------------------
// Append to KeyTuple<...>
// ------------------------

// 3. KeyTuple<...> | Meta/Child
// ==> KeyTuple<..., Meta/Child>
template<
   class... LHS, class RHS,
   class = std::enable_if_t<detail::IsMetaOrChild_v<RHS>>
>
auto operator|(
   const KeyTuple<LHS...> &lhs,
   const RHS &rhs // via SFINAE: Meta or Child
) {
   return KeyTuple<LHS...,RHS>(lhs,rhs);
}


// 4. KeyTuple<...,Child> | string/regex
// ==> KeyTuple<..., pair<Child,string/regex>>
template<
   class... LHS, class RHS,
   class = std::enable_if_t<
      detail::IsChild<typename KeyTuple<LHS...>::last_t>::value
   >,
   class StringOrRegex = typename detail::IsStringOrRegex<RHS>::type
>
auto operator|(
   const KeyTuple<LHS...> &lhs,
   const RHS &rhs // via SFINAE: string or char array, or regex
) {
   return makeKeyTuple(
      detail::tupleReplaceLast(
         lhs.tup,
         std::make_pair(
            std::get<sizeof...(LHS)-1>(lhs.tup),
            StringOrRegex(rhs) // cast ensures char array ==> std::string
         )
      )
   );
}
