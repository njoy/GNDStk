
// -----------------------------------------------------------------------------
// Node (templated)
// node (not)
// -----------------------------------------------------------------------------

template<
   template<class...> class MCON,
   template<class...> class CCON
>
class Node {
   using pair = std::pair<std::string,std::string>;
   using pointer = std::shared_ptr<Node>;

public:

   // Simple node for our tree structure:
   //    name
   //    metadata
   //    children
   std::string name;
   MCON<pair,   std::allocator<pair   >> metadata;
   CCON<pointer,std::allocator<pointer>> children;

   // push metadatum
   auto &push(const std::string &key, const std::string &value)
   {
      metadata.push_back(std::make_pair(key,value));
      return metadata.back();
   }

   // push child
   Node &push(Node *const cptr)
   {
      children.push_back(pointer(cptr));
      return *children.back();
   }

   // write
   bool write(const char * const file, const int level = 0) const;
   bool write(const std::string &file, const int level = 0) const
   {
      return write(file.c_str(),level);
   }
   std::ostream &write(std::ostream &, const int level = 0) const;

   // leaf?
   bool leaf() const
   {
      return children.size() == 0;
   }


   // ------------------------
   // meta()
   // ------------------------

   // for string
   const std::string &meta(const std::string &str) const
   {
      for (auto &m : metadata)
         if (m.first == str)
            return m.second;
      // fixme: eventually, do something better than this...
      assert(false);
      static std::string empty = "";
      return empty;
   }

   // for meta_t<T>
   // Return by value isn't ideal, if T is something large like a container.
   // Think about options.
   template<class T>
   T meta(const meta_t<T> &keyword) const
   {
      const std::string &str = meta(keyword.name);
      T value;
      gnds::read(str,value);
      return value;
   }

   // for meta_t<string>
   // The above is functionally equivalent, as we have a read(string,string)
   // that just copies the string (and we want that read() anyway, for possible
   // use by the variant case below). But let's do this directly, for clarity's
   // sake, even if after optimization the above probably wouldn't be worse...
   std::string meta(const meta_t<std::string> &keyword) const
   {
      return meta(keyword.name); // raw (not meta_t<>'d) string case, earlier
   }

   // for meta_t<void>
   // What the hey, let's define the meta_t<void> case to be equivalent to the
   // meta_t<string> case. This makes meta_t's behavior more consistent with
   // that of child_t, which uses <void> to stipulate that the child node be
   // returned in its original form in the tree.
   std::string meta(const meta_t<void> &keyword) const
   {
      return meta(keyword.name); // as above
   }

   // for meta_t<variant>, caller must stipulate <T>.
   // We don't just fold this into meta(meta_t<T>) above and return the variant,
   // because the read() would have no idea what variant variation to read into!
   template<class T, class... Ts>
   T meta(const meta_t<std::variant<Ts...>> &keyword) const
   {
      // body is as above, but function signature is structurally different
      const std::string &str = meta(keyword.name);
      T value;
      gnds::read(str,value);
      return value;
   }


   // ------------------------
   // child()
   // ------------------------

   // for string
   const Node &child(const std::string &str) const
   {
      for (auto &c : children)
         if (c != nullptr && c->name == str)
            return *c;
      // fixme: eventually, do something better than this...
      assert(false);
      static Node empty;
      return empty;
   }

   // for child_t<T>
   template<class T, class META, class CHILD>
   auto child(const child_t<T,META,CHILD> &keyword) const
   {
      return tnode<MCON,CCON,T>(child(keyword.name));
   }

   // for child_t<variant>, caller must stipulate <T>.
   template<class T, class META, class CHILD, class... Ts>
   auto child(const child_t<std::variant<Ts...>,META,CHILD> &keyword) const
   {
      return tnode<MCON,CCON,T>(child(keyword.name));
   }


   // ------------------------
   // operator()
   // ------------------------

   // These provide notationally consistent access to the above meta() and
   // child() functions, except that the std::string parameter versions of
   // those functions are intentionally not supported here, as it would be
   // indeterminate as to whether we'd want the meta or child (std::string)
   // function. This is not a deficiency, but instead reflects the fact that
   // calling these functions with meta_t and child_t parameters - not with
   // std::string parameters - should be preferred. Those encode (via their
   // type) whether we're accessing metadata or children.

   // meta_t
   // forwards to meta(meta_t) above
   template<class T>
   decltype(auto) operator()(const meta_t<T> &keyword) const
   {
      return meta(keyword);
   }

   // child_t
   // forwards to child(child_t) above
   template<class T, class META, class CHILD>
   decltype(auto) operator()(const child_t<T,META,CHILD> &keyword) const
   {
      return child(keyword);
   }

   // child_t, ...
   // multi-argument
   template<class T, class META, class CHILD, class... Ts>
   decltype(auto) operator()(
      const child_t<T,META,CHILD> &keyword,
      Ts &&...ts
   ) const {
      return (*this)(keyword)(std::forward<Ts>(ts)...);
   }

}; // class Node



// -----------------------------------------------------------------------------
// write
// -----------------------------------------------------------------------------

// write(char *)
template<
   template<class...> class MCON,
   template<class...> class CCON
>
inline bool Node<MCON,CCON>::write(
   const char * const file,
   const int level
) const {
   // calls write(ostream) below
   std::ofstream ofs(file);
   return !write(ofs,level).fail();
}


// write(ostream)
template<
   template<class...> class MCON,
   template<class...> class CCON
>
std::ostream &Node<MCON,CCON>::write(
   std::ostream &os,
   const int level
) const {
   // indentation
   const std::string icurr(indent* level   ,' ');
   const std::string inext(indent*(level+1),' ');

   // write name
   os << icurr << name << ":" << std::endl;

   // write metadata
   for (const auto &meta : metadata)
      os << inext << meta.first << ": " << meta.second << std::endl;

   // write children
   for (const auto &cptr : children)
      if (cptr)
         cptr->write(os,level+1);

   // done
   return os;
}


// operator<<
template<
   template<class...> class MCON,
   template<class...> class CCON
>
inline std::ostream &operator<<(std::ostream &os, const Node<MCON,CCON> &obj)
{
   // calls write(ostream) above
   return obj.write(os);
}



// -----------------------------------------------------------------------------
// Summary
// -----------------------------------------------------------------------------

/*
Node::meta()
   const string & meta  ( const string                  &str     ) const;
   T              meta  ( const meta_t<T>               &keyword ) const;
   string         meta  ( const meta_t<string>          &keyword ) const;
   string         meta  ( const meta_t<void>            &keyword ) const;
   T              meta  ( const meta_t<variant<Ts...>>  &keyword ) const;

Node::child()
   const Node & child ( const string                  &str     ) const;
   tnode<...,T> child ( const child_t<T>              &keyword ) const;
   tnode<...,T> child ( const child_t<variant<Ts...>> &keyword ) const

Node::operator()()
   decltype(auto) operator() ( const meta_t <T> &keyword             ) const;
   decltype(auto) operator() ( const child_t<T> &keyword             ) const;
   decltype(auto) operator() ( const child_t<T> &keyword, Ts &&...ts ) const;
*/
