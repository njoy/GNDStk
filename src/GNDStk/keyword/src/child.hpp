
// -----------------------------------------------------------------------------
// keyword_t::child()
// -----------------------------------------------------------------------------

template<class RESULT = void, bool MULTIPLE = false>
static auto child(const std::string &name, const bool top = false)
{
   return child_t<
      RESULT,
      MULTIPLE,
      metadata<>,
      children<>
   >{name,top};
}

template<class RESULT = void, bool MULTIPLE = false, class K, class... Ks>
static auto child(const std::string &name, const K &, Ks...)
{
   return child_t<
      RESULT,
      MULTIPLE,
      typename detail::catenateMetadata<metadata<>,K,Ks...>::type,
      typename detail::catenateChildren<children<>,K,Ks...>::type
   >{name};
}

template<class RESULT = void, bool MULTIPLE = false, class K, class... Ks>
static auto child(const std::string &name, const bool top, const K &, Ks...)
{
   return child_t<
      RESULT,
      MULTIPLE,
      typename detail::catenateMetadata<metadata<>,K,Ks...>::type,
      typename detail::catenateChildren<children<>,K,Ks...>::type
   >{name,top};
}
