
// -----------------------------------------------------------------------------
// keyword_t::child()
// -----------------------------------------------------------------------------

// name [,top]
template<class RESULT = void, find FIND = find::one>
static auto child(const std::string &name, const bool top = false)
{
   return child_t<
      RESULT,
      FIND,
      metadata<>,
      children<>
   >{name,top};
}

// name, keyword[s]
template<class RESULT = void, find FIND = find::one, class K, class... Ks>
static auto child(const std::string &name, const K &, Ks...)
{
   return child_t<
      RESULT,
      FIND,
      typename detail::catenateMetadata<metadata<>,K,Ks...>::type,
      typename detail::catenateChildren<children<>,K,Ks...>::type
   >{name};
}

// name, top, keyword[s]
template<class RESULT = void, find FIND = find::one, class K, class... Ks>
static auto child(const std::string &name, const bool top, const K &, Ks...)
{
   return child_t<
      RESULT,
      FIND,
      typename detail::catenateMetadata<metadata<>,K,Ks...>::type,
      typename detail::catenateChildren<children<>,K,Ks...>::type
   >{name,top};
}
