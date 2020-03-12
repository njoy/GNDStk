
// -----------------------------------------------------------------------------
// catenateMetadata
// metadata<> += meta_t types
// chuck child_t types
// -----------------------------------------------------------------------------

namespace detail {

// default
template<class METADATA, class... Ks>
class catenateMetadata {
};


// metadata
template<class... Ms>
class catenateMetadata<metadata<Ms...>> {
public:
   // recursion terminal
   using type =
      metadata<Ms...>;
};


// +meta [+Ks]
template<class... Ms, class RESULT, class... Ks>
class catenateMetadata<metadata<Ms...>, meta_t<RESULT>, Ks...> {
public:
   // fold the meta_t into metadata; recurse
   using type =
      typename catenateMetadata<metadata<Ms...,meta_t<RESULT>>,Ks...>::type;
};


// +child [+Ks]
template<class... Ms, class... Ts, class... Ks>
class catenateMetadata<metadata<Ms...>, child_t<Ts...>, Ks...> {
public:
   // chuck the child_t; recurse
   using type =
      typename catenateMetadata<metadata<Ms...>,Ks...>::type;
};

} // namespace detail
