
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
// fixme See if I can make *forward* declarations unnecessary.
// -----------------------------------------------------------------------------

// meta_t
// The default template parameter, std::string, means to retrieve the metadatum
// in its original form in the tree: as a std::string.
template<
   class RESULT = std::string
>
class meta_t;

// child_t
// The default template parameter, void, means to retrieve the child node
// in its original form in the tree: as some variation of a Node<>. The precise
// type thus received depends on the template parameters of the tree's Tree<>
// type, because those parameters trickle down into the Tree<>'s Node<>s. The
// fact that there's no fixed Node<> type is why we use void for this meaning.
// See class child_t's definition, elsewhere, for an in-depth description.
template<
   class RESULT   = void,
   bool  MULTIPLE = false,      // multiple appearances allowed (e.g. <axis>)
   class METADATA = metadata<>, // allowed metadata for this child-node type
   class CHILDREN = children<>  // allowed children ...
>
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

   // <>
   // <RESULT>
   template<class RESULT = void>
   static auto meta(const std::string &name)
   {
      return meta_t<RESULT>{name};
   }

   // ------------------------
   // child
   // ------------------------

   /*
   // meta examples
   inline const auto encoding = keyword.meta<>("encoding");
   inline const auto encoding = keyword.meta<encoding_t>("encoding");

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
         typename catenateMetadata<metadata<>,K,Ks...>::type,
         typename catenateChildren<children<>,K,Ks...>::type
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
         typename catenateMetadata<metadata<>,K,Ks...>::type,
         typename catenateChildren<children<>,K,Ks...>::type
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
         typename catenateMetadata<metadata<>,K,Ks...>::type,
         typename catenateChildren<children<>,K,Ks...>::type
      >{name}; // not top-level
   }

   // Forms:
   //    child<RESULT,MULTIPLE>(name,top,keywords)
   template<class RESULT, bool MULTIPLE, class K, class... Ks>
   static auto child(const std::string &name, const bool top, const K &, Ks...)
   {
      return child_t<
         RESULT,
         MULTIPLE, // multiple? (as given)
         typename catenateMetadata<metadata<>,K,Ks...>::type,
         typename catenateChildren<children<>,K,Ks...>::type
      >{name,top}; // top-level? (as given)
   }

/*
fixme Get rid of this, if the new stuff works

   // <RESULT,K[,Ks...]>
   template<class RESULT, class K, class... Ks>
   static auto child(const std::string &name, const K &, Ks...)
   {
      // For all meta_t<> (resp. child_t<>) instances in {K,Ks}, pull
      // them out, and consolidate into metadata<> (resp. children<>).
      using METADATA = typename catenateMetadata<metadata<>,K,Ks...>::type;
      using CHILDREN = typename catenateChildren<children<>,K,Ks...>::type;
      return child_t<RESULT,METADATA,CHILDREN,false>{name};
   }

   // <RESULT,K[,Ks...]>
   template<class RESULT, class K, class... Ks>
   static auto child(const std::string &name,
                     const bool toplevel, const K &, Ks...)
   {
      using METADATA = typename catenateMetadata<metadata<>,K,Ks...>::type;
      using CHILDREN = typename catenateChildren<children<>,K,Ks...>::type;
      return child_t<RESULT,METADATA,CHILDREN,toplevel>{name};
   }
*/

};

} // namespace detail



// ------------------------
// keyword
// ------------------------

// Object of the above types, for use by us, or by users, in building
// smart keywords. (Or dumb keywords. There are lots of options.)
inline const detail::keyword_t keyword;



/*
I don't think these are really workable any longer.
They'd create more confusion that direct calls.
Besides, I don't think ##__VA_ARGS__ is entirely standard.

// -----------------------------------------------------------------------------
// Macros
// For users.
// These may change; I need to see how the keyword business pans out.
// -----------------------------------------------------------------------------

// GNDSTK_KEYWORD_META
#define GNDSTK_KEYWORD_META(type,name) \
   inline const auto name = keyword.meta <type>{#name}

// GNDSTK_KEYWORD_CHILD
#define GNDSTK_KEYWORD_CHILD(type,name,...) \
   inline const auto name = keyword.child<type>{#name,##__VA_ARGS__}
*/
