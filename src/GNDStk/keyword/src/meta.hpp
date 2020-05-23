
// -----------------------------------------------------------------------------
// keyword_t::meta()
// -----------------------------------------------------------------------------

// meta[<[void]>](name)
template<class RESULT = void>
static meta_t<
   typename detail::isVoid<RESULT>::type
> meta(
   const std::string &name
) {
   return meta_t<void>{name};
}


// meta<RESULT>(name[,converter])
template<class RESULT, class CONVERTER = detail::convert_t>
static meta_t<
   typename detail::isNotVoid<RESULT>::type,
   CONVERTER
> meta(
   const std::string &name,
   const CONVERTER &converter = CONVERTER{}
) {
   return meta_t<RESULT,CONVERTER>{name,converter};
}
