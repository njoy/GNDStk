
// -----------------------------------------------------------------------------
// metadata
// children
// -----------------------------------------------------------------------------

// metadata
template<class... Ms>
class metadata {
};

// children
template<class... Cs>
class children {
};



// -----------------------------------------------------------------------------
// meta_t
// child_t
// Forward declarations
// -----------------------------------------------------------------------------

// meta_t
// fixme Should maybe have T = void, and have it mean retrieve as std::string
template<class T>
class meta_t;

// child_t
template<class T = void, class METADATA=metadata<>, class CHILDREN=children<>>
class child_t;



// -----------------------------------------------------------------------------
// mcat
// ccat
// -----------------------------------------------------------------------------

namespace detail {

// ------------------------
// mcat
// metadata<> += meta_ts
// chuck child_ts
// ------------------------

// default
template<class METADATA, class... Ks> class mcat { };

// metadata
template<class... Ms>
class mcat<metadata<Ms...>> {
public:
   // recursing terminal
   using type = metadata<Ms...>;
};

// +meta [+Ks]
template<class... Ms, class T, class... Ks>
class mcat<metadata<Ms...>, meta_t<T>, Ks...> {
public:
   // fold the meta_t into metadata; recurse
   using type = typename mcat<metadata<Ms...,meta_t<T>>,Ks...>::type;
};

// +child [+Ks]
template<class... Ms, class... Ts, class... Ks>
class mcat<metadata<Ms...>, child_t<Ts...>, Ks...> {
public:
   // chuck the child_t; recurse
   using type = typename mcat<metadata<Ms...>,Ks...>::type;
};


// ------------------------
// ccat
// children<> += child_ts
// chuck meta_ts
// ------------------------

// default
template<class CHILDREN, class... Ks> class ccat { };

// children
template<class... Cs>
class ccat<children<Cs...>> {
public:
   // recursing terminal
   using type = children<Cs...>;
};

// +meta [+Ks]
template<class... Cs, class T, class... Ks>
class ccat<children<Cs...>, meta_t<T>, Ks...> {
public:
   // chuck the meta_t; recurse
   using type = typename ccat<children<Cs...>,Ks...>::type;
};

// +child [+Ks]
template<class... Cs, class... Ts, class... Ks>
class ccat<children<Cs...>, child_t<Ts...>, Ks...> {
public:
   // fold the child_t into children; recurse
   using type = typename ccat<children<Cs...,child_t<Ts...>>,Ks...>::type;
};

} // namespace detail



// -----------------------------------------------------------------------------
// keyword_t
// keyword
// -----------------------------------------------------------------------------

// keyword_t
class keyword_t {
public:
   // ------------------------
   // meta
   // ------------------------

   // <[T]>
   template<class T = void>
   auto meta() const
   {
      return meta_t<T>{};
   }

   // ------------------------
   // child
   // ------------------------

   // <[T]>
   template<class T = void>
   auto child() const
   {
      return child_t<T,metadata<>,children<>>{};
   }

   // <T,K[,Ks...]>
   template<class T, class K, class... Ks>
   auto child(const K &, Ks...) const
   {
      using M = typename detail::mcat<metadata<>,K,Ks...>::type;
      using C = typename detail::ccat<children<>,K,Ks...>::type;
      return child_t<T,M,C>{};
   }
};

// keyword
inline const keyword_t keyword;



// -----------------------------------------------------------------------------
// Macros
// -----------------------------------------------------------------------------

// keyword_meta
#define keyword_meta(type,name) \
   inline const auto name = keyword.meta<type>{}

// keyword_child
#define keyword_child(type,name,...) \
   inline const auto name = keyword.child<type>{__VA_ARGS__}
