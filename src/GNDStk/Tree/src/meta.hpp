
// -----------------------------------------------------------------------------
// meta
// -----------------------------------------------------------------------------

decltype(auto) meta(const std::string &str) const
{
   assert(not empty());
   return root->meta(str);
}

template<class RESULT>
decltype(auto) meta(const meta_t<RESULT> &kwd) const
{
   assert(not empty());
   return root->meta(kwd);
}
