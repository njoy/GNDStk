
// -----------------------------------------------------------------------------
// keyword_t.child()
// -----------------------------------------------------------------------------

// child(name,converter,filter,top)
// To make a child_t<TYPE,...>
template<
   class TYPE,
   allow ALLOW = allow::one,
   class CONVERTER = typename detail::default_converter<TYPE>::type,
   class FILTER = detail::noFilter
>
static child_t<
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
   return child_t<TYPE,ALLOW,CONVERTER,FILTER>
      (name,object,converter,filter,top);
}


// child(name,filter,top)
// To make a child_t<void,...>
template<
   class TYPE = void,
   allow ALLOW = allow::one,
   class FILTER = detail::noFilter
>
static child_t<
   typename detail::isVoid<TYPE>::type, // ensure TYPE == void
   ALLOW,
   void,
   FILTER
> child(
   const std::string &name,
   const FILTER &filter = FILTER{},
   const bool top = false
) {
   return child_t<void,ALLOW,void,FILTER>
      (name,filter,top);
}
