
// -----------------------------------------------------------------------------
// knoop
// Alternative to tree
// Not as fully equipped at the moment
// Because we may or may not keep it
// -----------------------------------------------------------------------------

// convert: forward
class knoop;
bool convert(const xml  &from, knoop &to);
bool convert(const json &from, knoop &to);


// knoop
class knoop {
public:

   // defined elsewhere
   class node;

   // data
   std::unique_ptr<node> root;

   // ctor: default
   knoop() { }

   // ctor: xml, json
   knoop(const xml  &x) { convert(x,*this); }
   knoop(const json &j) { convert(j,*this); }

   // clear
   void clear()
   {
      // smart pointer, so the rest of the tree is deleted too;
      // note that this in fact involves knoop::node::~node()
      root = nullptr;
   }

   // write
   std::ostream &write(std::ostream &) const;

}; // class knoop



// -----------------------------------------------------------------------------
// I/O
// -----------------------------------------------------------------------------

// write
inline std::ostream &knoop::write(std::ostream &os) const
{
   return root ? detail::write(*root,os,0) : os;
}

// ostream << knoop
inline std::ostream &operator<<(std::ostream &os, const knoop &obj)
{
   return obj.write(os);
}
