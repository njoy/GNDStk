
// -----------------------------------------------------------------------------
// gnds::knoop::tree
// Alternative to gnds::tree
// Not as fully equipped at the moment
// We may or may not keep it
// -----------------------------------------------------------------------------

// convert: forward
namespace knoop {
   class tree;
}
bool convert(const xml  &xdoc, knoop::tree &tree);
bool convert(const json &jdoc, knoop::tree &tree);

namespace knoop {

// tree
class tree {
public:

   // data
   std::unique_ptr<knoop::node> root;

   // ctor: default
   tree() { }

   // ctor: xml, json
   tree(const xml  &xdoc) { convert(xdoc,*this); }
   tree(const json &jdoc) { convert(jdoc,*this); }

   // clear
   void clear()
   {
      // smart pointer, so the rest of the tree is deleted as well
      root = nullptr;
   }

   // write
   std::ostream &write(std::ostream &) const;

   // normalize
   void normalize() { }

}; // class tree

} // namespace knoop



// -----------------------------------------------------------------------------
// I/O
// -----------------------------------------------------------------------------

namespace knoop {

// write
inline std::ostream &tree::write(std::ostream &os) const
{
   return root ? detail::write(*root,os,0) : os;
}

// ostream << knoop::tree
inline std::ostream &operator<<(std::ostream &os, const knoop::tree &obj)
{
   return obj.write(os);
}

} // namespace knoop
