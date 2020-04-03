
// -----------------------------------------------------------------------------
// catenateChildren
// children<> += child_t types
// chuck meta_t types
// -----------------------------------------------------------------------------

namespace detail {

// default
template<class... Ks>
class catenateChildren {
};


// children
template<
   class... Cs
>
class catenateChildren<children<Cs...>> {
public:
   // terminal
   using type = children<Cs...>;
};


// children + child [+ Ks]
template<
   class... Cs,
   class RESULT, bool MULTIPLE, class METADATA, class CHILDREN,
   class... Ks
>
class catenateChildren<
   children<Cs...>,
   child_t<RESULT,MULTIPLE,METADATA,CHILDREN>,
   Ks...
> {
public:
   // fold child_t into children; continue
   using type = typename catenateChildren<
      children<Cs...,child_t<RESULT,MULTIPLE,METADATA,CHILDREN>>,
      Ks...
   >::type;
};


// children + meta [+ Ks]
template<
   class... Cs,
   class RESULT,
   class... Ks
>
class catenateChildren<
   children<Cs...>,
   meta_t<RESULT>,
   Ks...
> {
public:
   // chuck meta_t; continue
   using type = typename catenateChildren<
      children<Cs...>,
      Ks...
   >::type;
};

} // namespace detail
