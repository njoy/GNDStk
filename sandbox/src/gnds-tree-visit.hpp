
// -----------------------------------------------------------------------------
// Definitions:
//    Tree::meta()
//    Tree::child()
//    Tree::operator()()
// -----------------------------------------------------------------------------

// ------------------------
// tree::meta()
// ------------------------

template<
   template<class...> class MCON,
   template<class...> class CCON
>
inline decltype(auto) Tree<MCON,CCON>::meta(const std::string &str) const
{
   assert(root != nullptr);
   return root->meta(str);
}

template<
   template<class...> class MCON,
   template<class...> class CCON
>
template<class T>
inline decltype(auto) Tree<MCON,CCON>::meta(const meta_t<T> &keyword) const
{
   assert(root != nullptr);
   return root->meta(keyword);
}


// ------------------------
// tree::child()
// ------------------------

template<
   template<class...> class MCON,
   template<class...> class CCON
>
inline decltype(auto) Tree<MCON,CCON>::child(const std::string &str) const
{
   assert(root != nullptr);
   return root->child(str);
}

template<
   template<class...> class MCON,
   template<class...> class CCON
>
template<class T, class META, class CHILD>
inline decltype(auto) Tree<MCON,CCON>::child(
   const child_t<T,META,CHILD> &keyword
) const {
   assert(root != nullptr);
   return root->child(keyword);
}


// ------------------------
// tree::operator()()
// ------------------------

template<
   template<class...> class MCON,
   template<class...> class CCON
>
template<class T>
inline decltype(auto) Tree<MCON,CCON>::operator()(
   const meta_t <T> &keyword
) const {
   return meta(keyword);
}

template<
   template<class...> class MCON,
   template<class...> class CCON
>
template<class T, class META, class CHILD>
inline decltype(auto) Tree<MCON,CCON>::operator()(
   const child_t<T,META,CHILD> &keyword
) const {
   return child(keyword);
}

template<
   template<class...> class MCON,
   template<class...> class CCON
>
template<class T, class META, class CHILD, class... Ts>
inline decltype(auto) Tree<MCON,CCON>::operator()(
   const child_t<T,META,CHILD> &keyword,
   Ts &&...ts
) const {
   return (*this)(keyword)(std::forward<Ts>(ts)...);
}



// -----------------------------------------------------------------------------
// Summary
// -----------------------------------------------------------------------------

/*
Tree::meta()
   decltype(auto) meta  ( const string     &str     ) const;
   decltype(auto) meta  ( const meta_t<T>  &keyword ) const;

Tree::child()
   decltype(auto) child ( const string     &str     ) const;
   decltype(auto) child ( const child_t<T> &keyword ) const;

Tree::operator()()
   decltype(auto) operator() ( const meta_t <T> &keyword             ) const;
   decltype(auto) operator() ( const child_t<T> &keyword             ) const;
   decltype(auto) operator() ( const child_t<T> &keyword, Ts &&...ts ) const;
*/
