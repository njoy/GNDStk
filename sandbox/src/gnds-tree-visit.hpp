
// -----------------------------------------------------------------------------
// Definitions:
//    tree::meta()
//    tree::child()
//    tree::operator()()
// These appear to be somewhat redundant, and they all just defer down to the
// document's top-level child node. Figure out a good way to fold them down.
// Possibly, even have the top-level document type be implicitly convertible
// to its top-level node; then we may not need these at all. Be sure that
// whatever we do, we don't allow screwy usages that cause pages and pages of
// incomprehensible compiler gibberish to spew out.
// -----------------------------------------------------------------------------

// ------------------------
// tree::meta()
// ------------------------

inline const std::string &tree::meta(const std::string &key) const
{
   assert(root != nullptr);
   return root->meta(key);
}

template<class T>
inline decltype(auto) tree::meta(const gnds::meta_t<T> &m) const
{
   assert(root != nullptr);
   return root->meta(m);
}

// ------------------------
// tree::child()
// ------------------------

inline const node &tree::child(const std::string &name) const
{
   assert(root != nullptr);
   return root->child(name);
}

inline const node &tree::child(const gnds::child_t &c) const
{
   assert(root != nullptr);
   return root->child(c);
}

// ------------------------
// tree::operator()()
// ------------------------

inline const node &tree::operator()(const gnds::child_t &c) const
{
   assert(root != nullptr);
   return root->child(c);
}

template<class T, class... Ts>
inline decltype(auto) tree::operator()(T &&t, Ts &&...ts) const
{
   assert(root != nullptr);
   return (*root)(t)(std::forward<Ts>(ts)...);
}
