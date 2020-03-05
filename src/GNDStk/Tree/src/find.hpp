
// -----------------------------------------------------------------------------
// Functions for FINDING THINGS in trees
// meta
// child
// operator()
// -----------------------------------------------------------------------------

/*
Summary:

Tree::meta()
   decltype(auto) meta  ( const string     &str ) const;
   decltype(auto) meta  ( const meta_t<T>  &kwd ) const;

Tree::child()
   decltype(auto) child ( const string     &str ) const;
   decltype(auto) child ( const child_t<T> &kwd ) const;

Tree::operator()()
   decltype(auto) operator() ( const meta_t <T> &kwd             ) const;
   decltype(auto) operator() ( const child_t<T> &kwd             ) const;
   decltype(auto) operator() ( const child_t<T> &kwd, Ts &&...ts ) const;
*/



// -----------------------------------------------------------------------------
// meta
// -----------------------------------------------------------------------------

decltype(auto) meta(const std::string &str) const
{
   assert(not empty());
   return root->meta(str);
}

template<class T>
decltype(auto) meta(const meta_t<T> &kwd) const
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

template<class T, class META, class CHILD>
decltype(auto) child(const child_t<T,META,CHILD> &kwd) const
{
   assert(not empty());
   return root->child(kwd);
}



// -----------------------------------------------------------------------------
// operator()
// -----------------------------------------------------------------------------

template<class T>
decltype(auto) operator()(const meta_t<T> &kwd) const
{
   return meta(kwd);
}

template<class T, class META, class CHILD>
decltype(auto) operator()(const child_t<T,META,CHILD> &kwd) const
{
   return child(kwd);
}

template<class T, class META, class CHILD, class... Ts>
decltype(auto) operator()(const child_t<T,META,CHILD> &kwd, Ts &&...ts) const
{
   return (*this)(kwd)(std::forward<Ts>(ts)...);
}
