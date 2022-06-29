
#include "GNDStk/MultiQuery/src/detail.hpp"
#include "GNDStk/MultiQuery/src/KeywordTup.hpp"
#include "GNDStk/MultiQuery/src/toKeywordTup.hpp"

// -----------------------------------------------------------------------------
// operator|
// For making "multi-queries"
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
