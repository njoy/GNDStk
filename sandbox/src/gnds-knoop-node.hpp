
// -----------------------------------------------------------------------------
// gnds::knoop::node
// -----------------------------------------------------------------------------

namespace knoop {

class node : public njoy::knoop::Node<
   std::string, // name
   std::vector<std::pair<std::string,std::string>>, // metadata
   std::vector<node *> // children
> {
   using name_t     = std::string;
   using metadata_t = std::vector<std::pair<std::string,std::string>>;
   using children_t = std::vector<node *>;

   // begin(), for brevity later
   decltype(auto) begin()       { return list().begin(); }
   decltype(auto) begin() const { return list().begin(); }

   using base = njoy::knoop::Node<name_t, metadata_t, children_t>;

public:

   // ctor: default
   node() : base(name_t{}, metadata_t{}, children_t{}) { }

   // accessors
   const auto &name    () const { return (    begin())->get<name_t    >(); }
   const auto &metadata() const { return (  ++begin())->get<metadata_t>(); }
   const auto &children() const { return (++++begin())->get<children_t>(); }
   auto &name    () { return (    begin())->get<name_t    >(); }
   auto &metadata() { return (  ++begin())->get<metadata_t>(); }
   auto &children() { return (++++begin())->get<children_t>(); }

   // push
   void push(const std::string &key, const std::string &value)
   {
      metadata().push_back(std::make_pair(key,value));
   }

   void push(node *const value)
   {
      children().push_back(value);
   }

   // leaf?
   bool leaf() const
   {
      return children().size() == 0;
   }

   // write
   void write(std::ostream &, const int level) const;

   // dtor
  ~node()
   {
      for (auto &cptr : children()) {
         delete cptr;    // <== still have raw pointer in knoop-based class
         cptr = nullptr; // <== to ensure deleted raw pointer can't be used
         debug("delete node - knoop::tree");
      }
   }

}; // class node

} // namespace knoop
