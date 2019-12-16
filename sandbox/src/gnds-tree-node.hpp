
// -----------------------------------------------------------------------------
// node
// -----------------------------------------------------------------------------

class node {
public:

   // Simple node for our tree structure:
   //    name
   //    metadata
   //    children
   std::string name;
   std::vector<std::pair<std::string,std::string>> metadata;
   std::vector<std::shared_ptr<node>> children;

   // push metadatum
   auto &push(const std::string &key, const std::string &value)
   {
      metadata.push_back(std::make_pair(key,value));
      return metadata.back();
   }

   // push child
   node &push(node *const cptr)
   {
      children.push_back(std::shared_ptr<node>(cptr));
      return *children.back();
   }

   // write
   void write(std::ostream &, const int level = 0) const;

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
   const node &child(const std::string &str) const
   {
      for (auto &c : children)
         if (c != nullptr && c->name == str)
            return *c;
      // fixme: eventually, do something better than this...
      assert(false);
      static node empty;
      return empty;
   }

   // for child_t<T>
   template<class T>
   typednode<T> child(const child_t<T> &keyword) const
   {
      return typednode<T>(child(keyword.name));
   }

   // for child_t<variant>, caller must stipulate <T>.
   template<class T, class... Ts>
   typednode<T> child(const child_t<std::variant<Ts...>> &keyword) const
   {
      // fixme We may need another specialization of typednode to handle this...
      // fixme or maybe not; its second temp arg isn't really used now!
      return typednode<T>(child(keyword.name));
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
   // std::string parameters - should be preferred! Those encode (via their
   // type) whether we're accessing metadata or children.

   // forwards to meta(meta_t<>) above
   template<class T>
   decltype(auto) operator()(const meta_t<T> &keyword) const
   {
      return meta(keyword);
   }

   // forwards to child(child_t<>) above
   template<class T>
   decltype(auto) operator()(const child_t<T> &keyword) const
   {
      return child(keyword);
   }

   // multi-argument
   template<class T, class... Ts>
   decltype(auto) operator()(const child_t<T> &keyword, Ts &&...ts) const
   {
      return (*this)(keyword)(std::forward<Ts>(ts)...);
   }

}; // class node



// -----------------------------------------------------------------------------
// Summary
// -----------------------------------------------------------------------------

/*
node::meta()
   const string & meta  ( const string                  &str     ) const;
   T              meta  ( const meta_t<T>               &keyword ) const;
   T              meta  ( const meta_t<variant<Ts...>>  &keyword ) const;

node::child()
   const node   & child ( const string                  &str     ) const;
   typednode<T>   child ( const child_t<T>              &keyword ) const;
   typednode<T>   child ( const child_t<variant<Ts...>> &keyword ) const

node::operator()()
   decltype(auto) operator() ( const meta_t <T> &keyword             ) const;
   decltype(auto) operator() ( const child_t<T> &keyword             ) const;
   decltype(auto) operator() ( const child_t<T> &keyword, Ts &&...ts ) const;
*/
