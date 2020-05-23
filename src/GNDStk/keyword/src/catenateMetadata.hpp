
// -----------------------------------------------------------------------------
// catenateMetadata
// metadata<> += meta_t types
// chuck child_t types
// -----------------------------------------------------------------------------

namespace detail {

// default
template<class... Ks>
class catenateMetadata {
};


// metadata
template<
   class... Ms
>
class catenateMetadata<metadata<Ms...>> {
public:
   // terminal
   using type = metadata<Ms...>;
};


// metadata + meta [+ Ks]
template<
   class... Ms,
   class RESULT, class CONVERTER,
   class... Ks
>
class catenateMetadata<
   metadata<Ms...>,
   meta_t<RESULT,CONVERTER>,
   Ks...
> {
public:
   // fold meta_t into metadata; continue
   using type = typename catenateMetadata<
      metadata<Ms...,meta_t<RESULT,CONVERTER>>,
      Ks...
   >::type;
};


// metadata + child [+ Ks]
template<
   class... Ms,
   class RESULT, find FIND, class CONVERTER, class METADATA, class CHILDREN,
   class... Ks
>
class catenateMetadata<
   metadata<Ms...>,
   child_t<RESULT,FIND,CONVERTER,METADATA,CHILDREN>,
   Ks...
> {
public:
   // chuck child_t; continue
   using type = typename catenateMetadata<
      metadata<Ms...>,
      Ks...
   >::type;
};

} // namespace detail
