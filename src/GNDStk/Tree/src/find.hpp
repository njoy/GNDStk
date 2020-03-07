
// -----------------------------------------------------------------------------
// Functions for FINDING THINGS in trees
// meta
// child
// operator()
// -----------------------------------------------------------------------------

/*
Summary:

Tree::meta()
   decltype(auto) meta  ( const string          &str ) const;
   decltype(auto) meta  ( const meta_t <RESULT> &kwd ) const;

Tree::child()
   decltype(auto) child ( const string          &str ) const;
   decltype(auto) child ( const child_t<RESULT> &kwd ) const;

Tree::operator()()
   decltype(auto) operator() ( const meta_t <RESULT> &kwd             ) const;
   decltype(auto) operator() ( const child_t<RESULT> &kwd             ) const;
   decltype(auto) operator() ( const child_t<RESULT> &kwd, Ts &&...ts ) const;
*/

// fixme Probably have that bool &found stuff in these as well...



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



// -----------------------------------------------------------------------------
// child
// -----------------------------------------------------------------------------

decltype(auto) child(const std::string &str) const
{
   assert(not empty());
   return root->child(str);
}

template<class RESULT, bool MULTIPLE, class METADATA, class CHILDREN>
decltype(auto) child(
   const child_t<RESULT,MULTIPLE,METADATA,CHILDREN> &kwd
) const {
   assert(not empty());
   return root->child(kwd);
}



// -----------------------------------------------------------------------------
// operator()
// -----------------------------------------------------------------------------

template<class RESULT>
decltype(auto) operator()(const meta_t<RESULT> &kwd) const
{
   return meta(kwd);
}

template<
   class RESULT, bool MULTIPLE, class METADATA, class CHILDREN
>
decltype(auto) operator()(
   const child_t<RESULT,MULTIPLE,METADATA,CHILDREN> &kwd
) const {
   return child(kwd);
}

template<
   class RESULT, bool MULTIPLE, class METADATA, class CHILDREN,
   class... Ts
>
decltype(auto) operator()(
   const child_t<RESULT,MULTIPLE,METADATA,CHILDREN> &kwd,
   Ts &&...ts
) const {
   return (*this)(kwd)(std::forward<Ts>(ts)...);
}
