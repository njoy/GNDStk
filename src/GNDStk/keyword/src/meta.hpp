
// -----------------------------------------------------------------------------
// keyword_t::meta()
// -----------------------------------------------------------------------------

// <>
// <RESULT>
// <RESULT,CONVERTER>
template<class RESULT = void, class CONVERTER = detail::convert_t>
static auto meta(const std::string &name)
{
   return meta_t<RESULT,CONVERTER>{name};
}
