
// -----------------------------------------------------------------------------
// catenateChildren
// children<> += child_t types
// chuck meta_t types
// -----------------------------------------------------------------------------

namespace detail {

// default
template<class CHILDREN, class... Ks> class catenateChildren { };

// children
template<class... Cs>
class catenateChildren<children<Cs...>> {
public:
   // recursion terminal
   using type =
      children<Cs...>;
};

// +meta [+Ks]
template<class... Cs, class RESULT, class... Ks>
class catenateChildren<children<Cs...>, meta_t<RESULT>, Ks...> {
public:
   // chuck the meta_t; recurse
   using type =
      typename catenateChildren<children<Cs...>,Ks...>::type;
};

// +child [+Ks]
template<class... Cs, class... Ts, class... Ks>
class catenateChildren<children<Cs...>, child_t<Ts...>, Ks...> {
public:
   // fold the child_t into children; recurse
   using type =
      typename catenateChildren<children<Cs...,child_t<Ts...>>,Ks...>::type;
};

} // namespace detail
