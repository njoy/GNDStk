
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
// Forward declarations, which we'll need for other constructs in this file.
// -----------------------------------------------------------------------------

// meta_t
// The default template parameter, std::string, means to retrieve the metadatum
// in its original form in the tree: as a std::string.
template<class T = std::string>
class meta_t;

// child_t
// The default template parameter, void, means to retrieve the child node
// in its original form in the tree: as some variation of a Node<>. The precise
// type thus received depends on the template parameters of the tree's Tree<>
// type, as those parameters trickle down into the Tree<>'s Node<>s. The fact
// that there's no fixed "node" type is why we use void for this meaning.
template<class T = void, class METADATA=metadata<>, class CHILDREN=children<>>
class child_t;



// -----------------------------------------------------------------------------
// catenateMetadata
// catenateChildren
// fixme Eventually, I should put in a description, probably via an example,
// of what these template metaprogramming constructs are all about.
// -----------------------------------------------------------------------------

namespace detail {

// ------------------------
// catenateMetadata
// metadata<> += meta_ts
// chuck child_ts
// ------------------------

// default
template<class METADATA, class... Ks> class catenateMetadata { };

// metadata
template<class... Ms>
class catenateMetadata<metadata<Ms...>> {
public:
   // recursion terminal
   using type =
      metadata<Ms...>;
};

// +meta [+Ks]
template<class... Ms, class T, class... Ks>
class catenateMetadata<metadata<Ms...>, meta_t<T>, Ks...> {
public:
   // fold the meta_t into metadata; recurse
   using type =
      typename catenateMetadata<metadata<Ms...,meta_t<T>>,Ks...>::type;
};

// +child [+Ks]
template<class... Ms, class... Ts, class... Ks>
class catenateMetadata<metadata<Ms...>, child_t<Ts...>, Ks...> {
public:
   // chuck the child_t; recurse
   using type =
      typename catenateMetadata<metadata<Ms...>,Ks...>::type;
};


// ------------------------
// catenateChildren
// children<> += child_ts
// chuck meta_ts
// ------------------------

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
template<class... Cs, class T, class... Ks>
class catenateChildren<children<Cs...>, meta_t<T>, Ks...> {
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



// -----------------------------------------------------------------------------
// keyword_t
// keyword
// -----------------------------------------------------------------------------

namespace detail {

// keyword_t
class keyword_t {
public:
   // ------------------------
   // meta
   // ------------------------

   // <[T]>
   template<class T = void>
   static auto meta(const std::string &name)
   {
      return meta_t<T>{name};
   }

   // ------------------------
   // child
   // ------------------------

   // <[T]>
   template<class T = void>
   static auto child(const std::string &name)
   {
      return child_t<T,metadata<>,children<>>{name};
   }

   // <T,K[,Ks...]>
   template<class T, class K, class... Ks>
   static auto child(const std::string &name, const K &, Ks...)
   {
      // For all meta_t<> (resp. child_t<>) instances in {K,Ks}, pull
      // them out, and consolidate into metadata<> (resp. children<>).
      using METADATA = typename catenateMetadata<metadata<>,K,Ks...>::type;
      using CHILDREN = typename catenateChildren<children<>,K,Ks...>::type;
      return child_t<T,METADATA,CHILDREN>{name};
   }
};

} // namespace detail

// keyword
inline const detail::keyword_t keyword;



// -----------------------------------------------------------------------------
// Macros
// -----------------------------------------------------------------------------

// keyword_meta
#define keyword_meta(type,name) \
   inline const auto name = keyword.meta <type>{#name}

// keyword_child
#define keyword_child(type,name,...) \
   inline const auto name = keyword.child<type>{#name,##__VA_ARGS__}
