
// -----------------------------------------------------------------------------
// Tree::meta()
// -----------------------------------------------------------------------------

// meta(string)
decltype(auto) meta(const std::string &key) const
{
   assert(not empty());
   return root->meta(key);
}

// meta(meta_t<RESULT>)
template<class RESULT>
decltype(auto) meta(const meta_t<RESULT> &kwd) const
{
   assert(not empty());
   return root->meta(kwd);
}
