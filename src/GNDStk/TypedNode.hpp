
// -----------------------------------------------------------------------------
// TypedNode
// -----------------------------------------------------------------------------

template<class NODE, class T>
class TypedNode : public NODE
{
   // TYPE will be T if T != void; else NODE
   template<class A, class B> class if_void         { public: using type = A; };
   template<         class B> class if_void<void,B> { public: using type = B; };
   using TYPE = typename if_void<T,NODE>::type;

public:

   using NODE::clear;
   using NODE::empty;
   using NODE::leaf;
   using NODE::normalize;
   using NODE::add;
   using NODE::write;
   using NODE::meta;
   using NODE::child;
   using NODE::operator();

   TypedNode(const TypedNode &) = delete;
   TypedNode &operator=(const TypedNode &) = delete;

   // convert to TYPE
   // Note that this won't get called for the conversion if T was void,
   // so that TYPE ended up being NODE (the base class). In that case,
   // the base is just used.
   operator TYPE() const
   {
      TYPE ret;
      node2type(*(const NODE *)this,ret);
      return ret;
   }

   // operator()
   // Also convert to TYPE; just more explicit
   TYPE operator()() const
   {
      return TYPE(*this);
   }
};
