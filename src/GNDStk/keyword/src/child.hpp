
// -----------------------------------------------------------------------------
// keyword_t.child()
// -----------------------------------------------------------------------------

// child(name,converter,filter,top)
// To make a Child<TYPE,...>
template<
   class TYPE,
   Allow ALLOW = Allow::one,
   class CONVERTER = typename detail::default_converter<TYPE>::type,
   class FILTER = detail::noFilter
>
static Child<
   typename detail::isNotVoid<TYPE>::type, // ensure TYPE != void
   ALLOW,
   CONVERTER,
   FILTER
> child(
   const std::string &name,
   const TYPE &object = TYPE{},
   const CONVERTER &converter = CONVERTER{},
   const FILTER &filter = FILTER{},
   const bool top = false
) {
   return Child<TYPE,ALLOW,CONVERTER,FILTER>(name,object,converter,filter,top);
}


// child(name,filter,top)
// To make a Child<void,...>
template<
   class TYPE = void,
   Allow ALLOW = Allow::one,
   class FILTER = detail::noFilter
>
static Child<
   typename detail::is_void<TYPE>::type, // ensure TYPE == void
   ALLOW,
   void,
   FILTER
> child(
   const std::string &name,
   const FILTER &filter = FILTER{},
   const bool top = false
) {
   return Child<void,ALLOW,void,FILTER>(name,filter,top);
}
