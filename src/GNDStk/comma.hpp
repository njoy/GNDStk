
// -----------------------------------------------------------------------------
// fixme Material in this file really should be rearranged at some point, to be
// more consistent with the general NJOY source code structure. For now, we want
// to make this available quickly.
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Helper classes:
//    is_child_t
//    is_meta_or_child_t
//    is_string_or_regex
// for SFINAE.
// -----------------------------------------------------------------------------

namespace detail {

// ------------------------
// is_child_t
// ------------------------

// default
template<class T>
class is_child_t {
public:
   static const bool value = false;
};

// child_t
template<class TYPE, allow ALLOW, class CONVERTER, class FILTER>
class is_child_t<child_t<TYPE,ALLOW,CONVERTER,FILTER>> {
public:
   static const bool value = true;
};

// ------------------------
// is_meta_or_child_t
// ------------------------

// default
template<class T>
class is_meta_or_child_t {
public:
   static const bool value = false;
};

// meta_t
template<class TYPE, class CONVERTER>
class is_meta_or_child_t<meta_t<TYPE,CONVERTER>> {
public:
   static const bool value = true;
};

// child_t
template<class TYPE, allow ALLOW, class CONVERTER, class FILTER>
class is_meta_or_child_t<child_t<TYPE,ALLOW,CONVERTER,FILTER>> {
public:
   static const bool value = true;
};

// ------------------------
// is_string_or_regex
// ------------------------

// default
template<class T>
class is_string_or_regex {
public:
   static const bool value = false;
};

// string
template<>
class is_string_or_regex<std::string> {
public:
   static const bool value = true;
};

// regex
template<>
class is_string_or_regex<std::regex> {
public:
   static const bool value = true;
};

} // namespace detail



// -----------------------------------------------------------------------------
// keywords
// -----------------------------------------------------------------------------

// default
template<class... Ks>
class keywords {
public:
   std::tuple<Ks...> tup;

   // note: (ctor is viable) == (sizeof...(Ks) >= 1), hence no 0-1
   using last_t =
      // sans std::decay, const &ness breaks is_child_t::value :-/
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
      // ensure RHS \in {meta_t,child_t,string,regex}
      class = typename std::enable_if<
         detail::is_meta_or_child_t<RHS>::value ||
         detail::is_string_or_regex<RHS>::value
      >::type
   >
   keywords(const keywords<LHS...> &lhs, const RHS &rhs) :
      tup(std::tuple_cat(lhs.tup, std::tuple<RHS>(rhs)))
   { }
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
// operator,
// -----------------------------------------------------------------------------

/*
------------------------
CASES
------------------------

Below, keywords<...> doesn't include <>; at least one element must exist.

-----------------------------------+-------------------------------
   CASE                            |  RESULT
-----------------------------------+-------------------------------
1. meta|child, meta|child          |
   a. meta,  meta                  |  keywords<meta,meta>
   b. meta,  child                 |  keywords<meta,child>
   c. child, meta                  |  keywords<child,meta>
   d. child, child                 |  keywords<child,child>
-----------------------------------+-------------------------------
2. child, string                   |
   a. child, string                |  keywords<child,string>
   b. child, char *                |  keywords<child,string>
-----------------------------------+-------------------------------
3. child, regex                    |
   a. child, regex                 |  keywords<child,regex>
-----------------------------------+-------------------------------
4. keywords<...>, meta|child       |
   a. keywords<...>, meta          |  keywords<...,meta>
   b. keywords<...>, child         |  keywords<...,child>
-----------------------------------+-------------------------------
5. keywords<...,child>, string     |
   a. keywords<...,child>, string  |  keywords<...,child,string>
   b. keywords<...,child>, char *  |  keywords<...,child,string>
-----------------------------------+-------------------------------
6. keywords<...,child>, regex      |
   a. keywords<...,child>, regex   |  keywords<...,child,regex>
-----------------------------------+-------------------------------

Note: we could use SFINAE with is_string_or_regex, to combine the string
and regex cases, but that would leave out char *. What we did is shorter.
*/


// 1. meta|child, meta|child
// ==> keywords<meta|child, meta|child>
template<
   class LHS, class RHS,
   class=typename std::enable_if<detail::is_meta_or_child_t<RHS>::value>::type,
   class=typename std::enable_if<detail::is_meta_or_child_t<LHS>::value>::type
>
auto operator,(const LHS &lhs, const RHS &rhs)
{
   log::debug("comma: meta|child, meta|child");
   return keywords<LHS,RHS>(keywords<LHS>(lhs),rhs);
}


// 2. child, string
// ==> keywords<child, string>
template<class TYPE, allow ALLOW, class CONVERTER, class FILTER>
auto operator,(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &lhs,
   const std::string &rhs
) {
   log::debug("comma: child, string");
   return (keywords<child_t<TYPE,ALLOW,CONVERTER,FILTER>>(lhs),rhs);
}


// 3. child, regex
// ==> keywords<child, regex>
template<class TYPE, allow ALLOW, class CONVERTER, class FILTER>
auto operator,(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &lhs,
   const std::regex &rhs
) {
   log::debug("comma: child, regex");
   return (keywords<child_t<TYPE,ALLOW,CONVERTER,FILTER>>(lhs),rhs);
}


// 4. keywords<...>, meta|child
// ==> keywords<..., meta|child>
template<
   class... LHS, class RHS,
   class=typename std::enable_if<detail::is_meta_or_child_t<RHS>::value>::type
>
auto operator,(
   const keywords<LHS...> &lhs,
   const RHS &rhs
) {
   log::debug(
     "comma: keywords<...>, meta|child, size == {}",
      sizeof...(LHS)
   );
   return keywords<LHS...,RHS>(lhs,rhs);
}


// 5. keywords<...,child>, string
// ==> keywords<..., child, string>
template<
   class HEAD, class... TAIL, // split, to guarantee >= 1
   class=typename std::enable_if<
      detail::is_child_t<typename keywords<HEAD,TAIL...>::last_t>::value
   >::type
>
auto operator,(
   const keywords<HEAD,TAIL...> &lhs,
   const std::string &rhs
) {
   log::debug(
     "comma: keywords<...,child>, string, size == {}+1",
      sizeof...(TAIL)
   );
   return keywords<HEAD,TAIL...,std::string>(lhs,rhs);
}


// 6. keywords<...,child>, regex
// ==> keywords<..., child, regex>
template<
   class HEAD, class... TAIL, // split, to guarantee >= 1
   class=typename std::enable_if<
      detail::is_child_t<typename keywords<HEAD,TAIL...>::last_t>::value
   >::type
>
auto operator,(
   const keywords<HEAD,TAIL...> &lhs,
   const std::regex &rhs
) {
   log::debug(
     "comma: keywords<...,child>, regex, size == {}+1",
      sizeof...(TAIL)
   );
   return keywords<HEAD,TAIL...,std::regex>(lhs,rhs);
}
