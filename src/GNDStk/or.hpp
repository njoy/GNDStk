
// -----------------------------------------------------------------------------
// fixme
// Material here should be rearranged at some point, to be consistent with the
// general NJOY source structure. For now, we're making it available quickly.
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Helper classes:
//    is_meta_t
//    is_child_t
//    is_meta_or_child_t
//    is_string_or_regex
// for SFINAE.
// -----------------------------------------------------------------------------

namespace detail {

// ------------------------
// is_meta_t
// ------------------------

// default
template<class T>
class is_meta_t {
public:
   static constexpr bool value = false;
};

// meta_t
template<class TYPE, class CONVERTER>
class is_meta_t<meta_t<TYPE,CONVERTER>> {
public:
   static constexpr bool value = true;
};


// ------------------------
// is_child_t
// ------------------------

// default
template<class T>
class is_child_t {
public:
   static constexpr bool value = false;
};

// child_t
template<class TYPE, allow ALLOW, class CONVERTER, class FILTER>
class is_child_t<child_t<TYPE,ALLOW,CONVERTER,FILTER>> {
public:
   static constexpr bool value = true;
};


// ------------------------
// is_meta_or_child_t
// ------------------------

// default
template<class T>
class is_meta_or_child_t {
public:
   static constexpr bool value =
      is_meta_t <T>::value ||
      is_child_t<T>::value;
};


// ------------------------
// is_string_or_regex
// ------------------------

// default
template<class T>
class is_string_or_regex {
public:
   static constexpr bool value = false;
};

// string
template<>
class is_string_or_regex<std::string> {
public:
   static constexpr bool value = true;
   using type = std::string;
};

// char *
template<>
class is_string_or_regex<char *> {
public:
   static constexpr bool value = true;
   using type = std::string;
};

// const char *
template<>
class is_string_or_regex<const char *> {
public:
   static constexpr bool value = true;
   using type = std::string;
};

// char[N]
template<std::size_t N>
class is_string_or_regex<char[N]> {
public:
   static constexpr bool value = true;
   using type = std::string;
};

// regex
template<>
class is_string_or_regex<std::regex> {
public:
   static constexpr bool value = true;
   using type = std::regex;
};

} // namespace detail



// -----------------------------------------------------------------------------
// keywords
// -----------------------------------------------------------------------------

// default
// Note: sizeof...(Ks) >= 1, because we specialize the <> case
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
      // ensure RHS \in {meta_t, child_t, string, regex}
      class = typename std::enable_if<
         detail::is_meta_or_child_t<RHS>::value ||
         detail::is_string_or_regex<RHS>::value
      >::type
   >
   keywords(const keywords<LHS...> &lhs, const RHS &rhs) :
      tup(std::tuple_cat(lhs.tup, std::tuple<RHS>(rhs)))
   { }
};


// <>
// non-constructible
template<>
class keywords<>
{
   keywords() = delete;
   keywords(const keywords &) = delete;
   keywords(keywords &&) = delete;
};


// just meta_t
template<class TYPE, class CONVERTER>
class keywords<meta_t<TYPE,CONVERTER>> {
   using M = meta_t<TYPE,CONVERTER>;
public:
   std::tuple<M> tup;
   explicit keywords(const M &m) : tup(m) { }
};


// just child_t
template<class TYPE, allow ALLOW, class CONVERTER, class FILTER>
class keywords<child_t<TYPE,ALLOW,CONVERTER,FILTER>> {
   using C = child_t<TYPE,ALLOW,CONVERTER,FILTER>;
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

In the table:
   meta  means meta_t
   child means child_t
We omit the _t here for brevity.

---------------------------------------+-------------------------------
   CASE                                |  RESULT
---------------------------------------+-------------------------------
1. meta/child | meta/child             |
   a. meta  | meta                     |  keywords<meta,meta>
   b. meta  | child                    |  keywords<meta,child>
   c. child | meta                     |  keywords<child,meta>
   d. child | child                    |  keywords<child,child>
---------------------------------------+-------------------------------
2. child | string/regex                |
   a. child | string                   |  keywords<child,string>
   b. child | char *                   |  keywords<child,string>
   c. child | regex                    |  keywords<child,regex>
---------------------------------------+-------------------------------
3. keywords<...> | meta/child          |
   a. keywords<...> | meta             |  keywords<...,meta>
   b. keywords<...> | child            |  keywords<...,child>
---------------------------------------+-------------------------------
4. keywords<...,child> | string/regex  |
   a. keywords<...,child> | string     |  keywords<...,child,string>
   b. keywords<...,child> | char *     |  keywords<...,child,string>
   c. keywords<...,child> | regex      |  keywords<...,child,regex>
---------------------------------------+-------------------------------
*/


// 1. meta_t/child_t | meta_t/child_t
// ==> keywords<meta_t/child_t, meta_t/child_t>
template<
   class LHS, class RHS,
   class=typename std::enable_if<detail::is_meta_or_child_t<LHS>::value>::type,
   class=typename std::enable_if<detail::is_meta_or_child_t<RHS>::value>::type
>
auto operator|(
   const LHS &lhs,
   const RHS &rhs
) {
   log::debug("or: meta_t/child_t | meta_t/child_t");
   return keywords<LHS,RHS>(keywords<LHS>(lhs),rhs);
}


// 2. child_t | string/regex
// ==> keywords<child_t, string/regex>
template<
   class TYPE, allow ALLOW, class CONVERTER, class FILTER, class RHS,
   class=typename std::enable_if<detail::is_string_or_regex<RHS>::value>::type
>
auto operator|(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &lhs,
   const RHS &rhs
) {
   log::debug("or: child_t | string/regex");
   using LHS = child_t<TYPE,ALLOW,CONVERTER,FILTER>;
   using right = typename detail::is_string_or_regex<RHS>::type;
   return keywords<LHS,right>(keywords<LHS>(lhs),right(rhs));
}


// 3. keywords<...> | meta_t/child_t
// ==> keywords<..., meta_t/child_t>
template<
   class... LHS, class RHS,
   class=typename std::enable_if<detail::is_meta_or_child_t<RHS>::value>::type
>
auto operator|(
   const keywords<LHS...> &lhs,
   const RHS &rhs
) {
   log::debug("or: keywords<...> | meta_t/child_t");
   return keywords<LHS...,RHS>(lhs,rhs);
}


// 4. keywords<...,child_t> | string/regex
// ==> keywords<..., child_t, string/regex>
template<
   class... LHS, class RHS,
   class = typename std::enable_if<
      detail::is_child_t<typename keywords<LHS...>::last_t>::value
      >::type,
   class = typename std::enable_if<
      detail::is_string_or_regex<RHS>::value
   >::type
>
auto operator|(
   const keywords<LHS...> &lhs,
   const RHS &rhs
) {
   log::debug("or: keywords<...,child_t> | string/regex");
   using right = typename detail::is_string_or_regex<RHS>::type;
   return keywords<LHS...,right>(lhs,right(rhs));
}
