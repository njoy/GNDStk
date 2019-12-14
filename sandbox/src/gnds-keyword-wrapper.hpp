
// read(node,node)
// Overrides our default read(node,...), defined elsewhere, in the event
// that we produce a typednode<T> (see below) for T=node, as many child_t
// keywords currently do.
inline void read(const gnds::node &node, gnds::node &value)
{
   value = node;
}



// -----------------------------------------------------------------------------
// typednode
// -----------------------------------------------------------------------------

template<class T>
class typednode : public node {
public:

   // ctor
   explicit typednode(const node &n) : node(n) { }

   // operator(): evaluate to T
   T operator()() const
   {
      T ret;
      read(*(node*)this,ret);
      return ret;
   }

   using node::leaf;
   using node::write;

   using node::meta;
   using node::child;
   using node::operator();
};
