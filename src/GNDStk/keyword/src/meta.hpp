
// -----------------------------------------------------------------------------
// keyword_t.meta()
// -----------------------------------------------------------------------------

// meta(name,converter)
// To make a Meta<TYPE,...>
template<
   class TYPE,
   class CONVERTER = typename detail::default_converter<TYPE>::type
>
static Meta<
   typename detail::isNotVoid<TYPE>::type, // ensure TYPE != void
   CONVERTER
> meta(
   const std::string &name,
   const TYPE &object = TYPE{},
   const CONVERTER &converter = CONVERTER{}
) {
   return Meta<TYPE,CONVERTER>{name,object,converter};
}


// meta(name)
// To make a Meta<void>
template<
   class TYPE = void
>
static Meta<
   typename detail::isVoid<TYPE>::type // ensure TYPE == void
> meta(
   const std::string &name
) {
   return Meta<void>(name);
}
