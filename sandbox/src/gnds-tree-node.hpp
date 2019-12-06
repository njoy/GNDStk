
// -----------------------------------------------------------------------------
// node
// -----------------------------------------------------------------------------

class node {
public:

   // data
   // Simple but effective node for our tree structure
   //    - name
   //    - vector<pair> for metadata
   //    - vector<node pointer> for children
   // These could easily be changed (e.g. with a map for metadata)
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

   // push
   void push(const std::string &key, const std::string &value)
   {
      metadata().push_back(std::make_pair(key,value));
   }

   void push(node *const value)
   {
      children().push_back(std::unique_ptr<node>(value));
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
      // eventually do something better than this...
      assert(false);
      static std::string empty = "";
      return empty;
   }

   // 2. for meta_t<bool>
   bool meta(const gnds::meta_t<bool> &m) const
   {
      if (m.name == std::string("true" )) return true;
      if (m.name == std::string("false")) return false;
      assert(false);
      return false;
   }

   // 3. for meta_t<T>
   template<class T>
   T meta(const gnds::meta_t<T> &m) const
   {
      std::istringstream iss(meta(std::string(m.name)));
      T value;
      iss >> value;
      return value;
   }

   // 4. for meta_t<variant>
   // Caller must stipulate <T>
   template<class T, class... Vs>
   T meta(const gnds::meta_t<std::variant<Vs...>> &m) const
   {
      std::istringstream iss(meta(std::string(m.name)));
      T value;
      iss >> value;
      return value;
   }

   // 5. for meta_t<vector>
   // Return by value isn't ideal, performance-wise,
   // but we'll go with it for now
   template<class T>
   std::vector<T> meta(const gnds::meta_t<std::vector<T>> &m) const
   {
      std::istringstream iss(meta(std::string(m.name)));
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
      // eventually do something better than this...
      assert(false);
      static node empty{};
      return empty;
   }

   // 7. for child
   const node &child(const gnds::child_t &c) const
   {
      return child(std::string(c.name));
   }


   // ------------------------
   // operator()
   // ------------------------

   // These provide notationally consistent access to the above meta()
   // and child() functions, except that the (std::string) parameter
   // versions of those functions are intentionally not supported here,
   // as it would be indeterminate as to whether we'd want the meta or
   // child (std::string) function. This is not a deficiency here, but
   // instead reflects the fact that parameters of our meta and child
   // wrapper classes *should* be preferred.

   // forwards to (2), (3), (4), or (5) above
   template<class T>
   decltype(auto) operator()(const gnds::meta_t<T> &m) const
   {
      return meta(m);
   }

   // forwards to (7) above
   // return type will actually always be const node &, for now;
   // the decltype(auto) will work if and when child has <T>.
   decltype(auto) operator()(const gnds::child_t &c) const
   {
      return child(c);
   }

   // multi-argument
   // should have sfinae to ensure T is meta or child as for above operator()s
   template<class T, class... Ts>
   decltype(auto) operator()(T &&t, Ts &&...ts) const
   {
      return (*this)(t)(std::forward<Ts>(ts)...);
   }

}; // class node
