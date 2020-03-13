
// -----------------------------------------------------------------------------
// TypedNode
// fixme Put in an explanation of what this is about
// -----------------------------------------------------------------------------

template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER,
   class T
>
class TypedNode : public Node<METADATA_CONTAINER,CHILDREN_CONTAINER>
{
   // base
   using base = Node<METADATA_CONTAINER,CHILDREN_CONTAINER>;

   // if_void: A != void ? A : B
   template<class A, class B> struct if_void         { using type = A; };
   template<         class B> struct if_void<void,B> { using type = B; };

   // RETURN
   using RETURN = typename if_void<T,base>::type;

public:

   using base::clear;
   using base::leaf;
   using base::normalize;
   using base::add;
   using base::write;
   using base::meta;
   using base::child;
   using base::operator();

   // ctor
   explicit TypedNode(const base &n) : base(n) { }

   // operator(): evaluate to RETURN (T if not void, else base)
   RETURN operator()() const
   {
      RETURN ret;
      read(*(base*)this,ret);
      return ret;
   }
};
