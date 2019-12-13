
// -----------------------------------------------------------------------------
// Definitions:
//    tree::meta()
//    tree::child()
//    tree::operator()()
//
// fixme
// These appear to be somewhat redundant, and they all just defer down to the
// document's top-level child node. Figure out a good way to fold them down.
// Possibly, even have the top-level document type be implicitly convertible
// to its top-level node; then we may not need these at all. Whatever we do,
// be sure to prevent meaningless usages.
// -----------------------------------------------------------------------------

// ------------------------
// tree.meta()
// ------------------------

inline decltype(auto) tree::meta(const std::string &str) const
{
   assert(root != nullptr);
   return root->meta(str);
}

template<class T>
inline decltype(auto) tree::meta(const meta_t<T> &keyword) const
{
   assert(root != nullptr);
   return root->meta(keyword);
}

// ------------------------
// tree.child()
// ------------------------

inline decltype(auto) tree::child(const std::string &str) const
{
   assert(root != nullptr);
   return root->child(str);
}

template<class T>
inline decltype(auto) tree::child(const child_t<T> &keyword) const
{
   assert(root != nullptr);
   return root->child(keyword);
}

// ------------------------
// tree.operator()()
// ------------------------

template<class T>
inline decltype(auto) tree::operator()(const meta_t<T> &keyword) const
{
   return meta(keyword);
}

template<class T>
inline decltype(auto) tree::operator()(const child_t<T> &keyword) const
{
   return child(keyword);
}

template<class T, class... Ts>
inline
decltype(auto) tree::operator()(const meta_t <T> &keyword, Ts &&...ts) const
{
   return (*this)(keyword)(std::forward<Ts>(ts)...);
}

template<class T, class... Ts>
inline
decltype(auto) tree::operator()(const child_t<T> &keyword, Ts &&...ts) const
{
   return (*this)(keyword)(std::forward<Ts>(ts)...);
}



// -----------------------------------------------------------------------------
// Summary
// -----------------------------------------------------------------------------

/*
tree::meta()

   decltype(auto) meta  ( const string     &str     ) const;
   decltype(auto) meta  ( const meta_t<T>  &keyword ) const;

tree::child()

   decltype(auto) child ( const string     &str     ) const;
   decltype(auto) child ( const child_t<T> &keyword ) const;

tree::operator()()

   decltype(auto) operator() ( const meta_t <T> &keyword             ) const
   decltype(auto) operator() ( const child_t<T> &keyword             ) const;
   decltype(auto) operator() ( const meta_t <T> &keyword, Ts &&...ts ) const;
   decltype(auto) operator() ( const child_t<T> &keyword, Ts &&...ts ) const;
*/
