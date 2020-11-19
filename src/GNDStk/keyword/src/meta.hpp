
// -----------------------------------------------------------------------------
// keyword_t.meta()
// -----------------------------------------------------------------------------

// meta[<[void]>](name)
template<class TYPE = void>
static meta_t<
   typename detail::isVoid<TYPE>::type
> meta(
   const std::string &name
) {
   return meta_t<void>{name};
}


// meta<TYPE>(name[,converter])
template<class TYPE, class CONVERTER = detail::convert_t>
static meta_t<
   typename detail::isNotVoid<TYPE>::type,
   CONVERTER
> meta(
   const std::string &name,
   const CONVERTER &converter = CONVERTER{}
) {
   return meta_t<TYPE,CONVERTER>{name,converter};
}
