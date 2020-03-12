
// -----------------------------------------------------------------------------
// keyword_t::meta()
// -----------------------------------------------------------------------------

/*
// meta examples
inline const auto encoding = keyword.meta<>("encoding");
inline const auto encoding = keyword.meta<encoding_t>("encoding");
*/

// <>
// <RESULT>
template<class RESULT = void>
static auto meta(const std::string &name)
{
   return meta_t<RESULT>{name};
}
