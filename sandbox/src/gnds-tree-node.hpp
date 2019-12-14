
// typed: forward declaration
template<class result, class wraps>
class typed;



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
   std::vector<std::shared_ptr<node>> children_;

   // accessors
   const auto &name    () const { return name_    ; }
   const auto &metadata() const { return metadata_; }
   const auto &children() const { return children_; }
   auto &name    () { return name_    ; }
   auto &metadata() { return metadata_; }
   auto &children() { return children_; }

   // push metadatum
   // fixme Consider making the return value be a reference to the new pair
   void push(const std::string &key, const std::string &value)
   {
      metadata().push_back(std::make_pair(key,value));
   }

   // push child
   // fixme Consider making the return value be a reference to the dereferenced
   // shared_ptr
   void push(node *const cptr)
   {
      children().push_back(std::shared_ptr<node>(cptr));
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

   // for string
   const std::string &meta(const std::string &str) const
   {
      for (auto &m : metadata())
         if (m.first == str)
            return m.second;
      // fixme: eventually, do something better than this...
      assert(false);
      static std::string empty = "";
      return empty;
   }

   // for meta_t<T>
   // Return by value isn't ideal, if T is something large like a vector.
   // Think about options.
   template<class T>
   T meta(const meta_t<T> &keyword) const
   {
      std::istringstream iss(meta(keyword.name));
      T value;
      gnds::read(iss,value);
      return value;
   }

   // for meta_t<variant>, caller must stipulate <T>.
   // We don't just fold this into meta(meta_t<T>) above and return the variant,
   // because the read() would have no idea what variant variation to read into!
   template<class T, class... Ts>
   T meta(const meta_t<std::variant<Ts...>> &keyword) const
   {
      // body is as above, but function signature is structurally different
      std::istringstream iss(meta(keyword.name));
      T value;
      gnds::read(iss,value);
      return value;
   }


   // ------------------------
   // child()
   // ------------------------

   // for string
   const node &child(const std::string &str) const
   {
      for (auto &c : children())
         if (c != nullptr && c->name() == str)
            return *c;
      // fixme: eventually, do something better than this...
      assert(false);
      static node empty;
      return empty;
   }

   // for child_t<T>
   template<class T>
   auto child(const child_t<T> &keyword) const
   {
      return typed<T,child_t<T>>(keyword,child(keyword.name));
   }

   // for child_t<variant>, caller must stipulate <T>.
   template<class T, class... Ts>
   auto child(const child_t<std::variant<Ts...>> &keyword) const
   {
      // fixme We may need another specialization of typed to handle this...
      // fixme or maybe not; its second temp arg isn't really used now!
      return typed<T,child_t<std::variant<Ts...>>>(keyword,child(keyword.name));
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
   typed<T,child_t<T>>
                  child ( const child_t<T>              &keyword ) const;
   typed<T,child_t<std::variant<Ts...>>>
                  child ( const child_t<variant<Ts...>> &keyword ) const

node::operator()()
   decltype(auto) operator() ( const meta_t <T> &keyword             ) const;
   decltype(auto) operator() ( const child_t<T> &keyword             ) const;
   decltype(auto) operator() ( const child_t<T> &keyword, Ts &&...ts ) const;
*/




