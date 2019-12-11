
// -----------------------------------------------------------------------------
// node
// -----------------------------------------------------------------------------

class node {
public:

   // data
   // Simple but effective node for our tree structure:
   //    - name
   //    - vector<pair<string,string>> for metadata
   //    - vector<node pointer> for children
   // These could easily be changed (e.g. with a map for metadata).
   std::string name_;
   std::vector<std::pair<std::string,std::string>> metadata_;
   std::vector<std::unique_ptr<node>> children_;

   // accessors
   const auto &name    () const { return name_    ; }
   const auto &metadata() const { return metadata_; }
   const auto &children() const { return children_; }
   auto &name    () { return name_    ; }
   auto &metadata() { return metadata_; }
   auto &children() { return children_; }

   // push metadatum
   void push(const std::string &key, const std::string &value)
   {
      metadata().push_back(std::make_pair(key,value));
   }

   // push child
   void push(node *const cptr)
   {
      children().push_back(std::unique_ptr<node>(cptr));
   }

   // leaf?
   bool leaf() const
   {
      return children().size() == 0;
   }

   // write
   void write(std::ostream &, const int level) const;


   // ------------------------
   // meta()
   // ------------------------

   // 1. for string
   const std::string &meta(const std::string &key) const
   {
      for (auto &m : metadata())
         if (m.first == key)
            return m.second;
      // fixme: eventually, do something better than this...
      assert(false);
      static std::string empty = "";
      return empty;
   }

   // 2. for meta_t<bool>
   bool meta(const gnds::meta_t<bool> &keyword) const
   {
      for (auto &m : metadata())
         if (m.first == keyword.name) {
            if (m.second == "true" ) return true;
            if (m.second == "false") return false;
            assert(false); // fixme as above
         }
      return false;
   }

   // 3. for meta_t<T>
   template<class T>
   T meta(const gnds::meta_t<T> &keyword) const
   {
      std::istringstream iss(meta(keyword.name));
      T value;
      iss >> value;
      return value;
   }

   // 4. for meta_t<variant>
   // Caller must stipulate <T>
   template<class T, class... Vs>
   T meta(const gnds::meta_t<std::variant<Vs...>> &keyword) const
   {
      std::istringstream iss(meta(keyword.name));
      T value;
      iss >> value;
      return value;
   }

   // 5. for meta_t<vector>
   // Return by value isn't ideal, performance-wise,
   // but we'll go with it for now
   template<class T>
   std::vector<T> meta(const gnds::meta_t<std::vector<T>> &keyword) const
   {
      std::istringstream iss(meta(keyword.name));
      std::vector<T> value;
      T val;
      while (iss >> val)
         value.push_back(val);
      return value;
   }


   // ------------------------
   // child()
   // ------------------------

   // 6. for string
   const node &child(const std::string &name) const
   {
      for (auto &c : children())
         if (c != nullptr && c->name() == name)
            return *c;
      // fixme: eventually, do something better than this...
      assert(false);
      static node empty;
      return empty;
   }

   // 7. for child_t
   template<class T>
   const node &child(const gnds::child_t<T> &c) const
   {
      return child(c.name);
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

   // forwards to (2), (3), (4), or (5) above
   template<class T>
   decltype(auto) operator()(const gnds::meta_t<T> &keyword) const
   {
      return meta(keyword);
   }

   // forwards to (7) above
   // The return type is always be const node &, for now; the decltype(auto)
   // will work if and when we actually use child_t's <T>, which we should.
   template<class T>
   decltype(auto) operator()(const gnds::child_t<T> &c) const
   {
      return child(c);
   }

   // multi-argument
   // fixme:
   // Have SFINAE to ensure T is meta_t or child_t (for above operator()s)
   template<class T, class... Ts>
   decltype(auto) operator()(T &&t, Ts &&...ts) const
   {
      return (*this)(t)(std::forward<Ts>(ts)...);
   }

}; // class node
