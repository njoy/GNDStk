
// -----------------------------------------------------------------------------
// keyword_t.meta()
// -----------------------------------------------------------------------------

// meta(name,converter)
// To make a meta_t<TYPE,...>
template<
   class TYPE,
   class CONVERTER = typename detail::default_converter<TYPE>::type
>
static meta_t<
   typename detail::isNotVoid<TYPE>::type, // ensure TYPE != void
   CONVERTER
> meta(
   const std::string &name,
   const TYPE &object = TYPE{},
   const CONVERTER &converter = CONVERTER{}
) {
   return meta_t<TYPE,CONVERTER>{name,object,converter};
}


// meta(name)
// To make a meta_t<void>
template<
   class TYPE = void
>
static meta_t<
   typename detail::isVoid<TYPE>::type // ensure TYPE == void
> meta(
   const std::string &name
) {
   return meta_t<void>(name);
}
