
// -----------------------------------------------------------------------------
// Definitions:
//    Tree::meta()
//    Tree::child()
//    Tree::operator()()
// -----------------------------------------------------------------------------

// ------------------------
// Tree::meta()
// ------------------------

// string
template<
   template<class...> class MCON,
   template<class...> class CCON
>
inline decltype(auto) Tree<MCON,CCON>::meta(const std::string &str) const
{
   assert(root != nullptr);
   return root->meta(str);
}

// meta_t
template<
   template<class...> class MCON,
   template<class...> class CCON
>
template<class T>
inline decltype(auto) Tree<MCON,CCON>::meta(const meta_t<T> &kwd) const
{
   assert(root != nullptr);
   return root->meta(kwd);
}


// ------------------------
// Tree::child()
// ------------------------

// string
template<
   template<class...> class MCON,
   template<class...> class CCON
>
inline decltype(auto) Tree<MCON,CCON>::child(const std::string &str) const
{
   assert(root != nullptr);
   return root->child(str);
}

// child_t
template<
   template<class...> class MCON,
   template<class...> class CCON
>
template<class T, class META, class CHILD>
inline decltype(auto) Tree<MCON,CCON>::child(
   const child_t<T,META,CHILD> &kwd
) const {
   assert(root != nullptr);
   return root->child(kwd);
}


// ------------------------
// Tree::operator()()
// ------------------------

// meta_t
template<
   template<class...> class MCON,
   template<class...> class CCON
>
template<class T>
inline decltype(auto) Tree<MCON,CCON>::operator()(
   const meta_t<T> &kwd
) const {
   return meta(kwd);
}

// child_t
template<
   template<class...> class MCON,
   template<class...> class CCON
>
template<class T, class META, class CHILD>
inline decltype(auto) Tree<MCON,CCON>::operator()(
   const child_t<T,META,CHILD> &kwd
) const {
   return child(kwd);
}

// child_t, ...
template<
   template<class...> class MCON,
   template<class...> class CCON
>
template<class T, class META, class CHILD, class... Ts>
inline decltype(auto) Tree<MCON,CCON>::operator()(
   const child_t<T,META,CHILD> &kwd,
   Ts &&...ts
) const {
   return (*this)(kwd)(std::forward<Ts>(ts)...);
}



// -----------------------------------------------------------------------------
// Summary
// -----------------------------------------------------------------------------

/*
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
