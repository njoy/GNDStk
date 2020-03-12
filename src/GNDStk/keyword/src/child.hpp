
// fixme This file needs some review and probable cleanup.

// -----------------------------------------------------------------------------
// keyword_t::child()
// -----------------------------------------------------------------------------

/*
// child
inline const auto axes = keyword.child<            >("axes");
inline const auto axes = keyword.child<axes_t      >("axes");
inline const auto axes = keyword.child<axes_t,false>("axes");

inline const auto axis = keyword.child<void,  true >("axis");
inline const auto axis = keyword.child<axis_t,true >("axis");
*/



// Forms:
//
//    child<(void),(false) >(name    )   Node<>, singular, name, no
//    child<(void),(false) >(name,top)   Node<>, singular, name, top-level?
//    child<RESULT         >(name    )   RESULT, singular, name, no
//    child<RESULT         >(name,top)   RESULT, singular, name, top-level?
//    child<RESULT,MULTIPLE>(name    )   RESULT, multiple, name, no
//    child<RESULT,MULTIPLE>(name,top)   RESULT, multiple, name, top-level?
//
// Allowable metadata and children are unspecified; therefore we use:
//
//    metadata<>
//    children<>
//
// meaning that any are allowed.
//
template<class RESULT = void, bool MULTIPLE = false>
static auto child(const std::string &name, const bool top = false)
{
   return child_t<
      RESULT,
      MULTIPLE,
      metadata<>, // any
      children<>  // any
   >{name,top};
}



// Upcoming variations:
//
//    template<class RESULT,                class K, class... Ks>
//    template<class RESULT,                class K, class... Ks>
//    template<class RESULT, bool MULTIPLE, class K, class... Ks>
//    template<class RESULT, bool MULTIPLE, class K, class... Ks>
//
//    static auto child(const string &name,                 const K &, Ks...)
//    static auto child(const string &name, const bool top, const K &, Ks...)
//    static auto child(const string &name,                 const K &, Ks...)
//    static auto child(const string &name, const bool top, const K &, Ks...)
//
// As-written above, in order to see the structure.



// Form:
//    child<RESULT,(false) >(name,keywords)
template<class RESULT, class K, class... Ks>
static auto child(const std::string &name, const K &, Ks...)
{
   return child_t<
      RESULT,
      false, // not multiple
      typename detail::catenateMetadata<metadata<>,K,Ks...>::type,
      typename detail::catenateChildren<children<>,K,Ks...>::type
   >{name}; // not top-level
}



// Form:
//    child<RESULT,(false) >(name,top,keywords)
template<class RESULT, class K, class... Ks>
static auto child(const std::string &name, const bool top, const K &, Ks...)
{
   return child_t<
      RESULT,
      false, // not multiple
      typename detail::catenateMetadata<metadata<>,K,Ks...>::type,
      typename detail::catenateChildren<children<>,K,Ks...>::type
   >{name,top}; // top-level? (as given)
}



// Form:
//    child<RESULT,MULTIPLE>(name,keywords)
template<class RESULT, bool MULTIPLE, class K, class... Ks>
static auto child(const std::string &name, const K &, Ks...)
{
   return child_t<
      RESULT,
      MULTIPLE, // multiple? (as given)
      typename detail::catenateMetadata<metadata<>,K,Ks...>::type,
      typename detail::catenateChildren<children<>,K,Ks...>::type
   >{name}; // not top-level
}



// Form:
//    child<RESULT,MULTIPLE>(name,top,keywords)
template<class RESULT, bool MULTIPLE, class K, class... Ks>
static auto child(const std::string &name, const bool top, const K &, Ks...)
{
   return child_t<
      RESULT,
      MULTIPLE, // multiple? (as given)
      typename detail::catenateMetadata<metadata<>,K,Ks...>::type,
      typename detail::catenateChildren<children<>,K,Ks...>::type
   >{name,top}; // top-level? (as given)
}
