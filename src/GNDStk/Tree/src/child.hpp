
// -----------------------------------------------------------------------------
// Tree::child()
// -----------------------------------------------------------------------------

// child(string)
decltype(auto) child(const std::string &str) const
{
   assert(not empty());
   return root->child(str);
}

// child(child_t<RESULT>)
template<class RESULT, bool MULTIPLE, class METADATA, class CHILDREN>
decltype(auto) child(
   const child_t<RESULT,MULTIPLE,METADATA,CHILDREN> &kwd
) const {
   assert(not empty());
   return root->child(kwd);
}
