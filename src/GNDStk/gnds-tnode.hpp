
// read(Node,Node)
// Overrides our default read(Node,...), defined elsewhere, because
// we know what to do in the following case.

template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
inline void read(
   const gnds::Node<METADATA_CONTAINER,CHILDREN_CONTAINER> &from,
   gnds::Node<METADATA_CONTAINER,CHILDREN_CONTAINER> &to
) {
   to = from;
}


// Helper: if_void
namespace detail {

// default
template<class A, class B>
class if_void {
public:
   using type = A;
};

// void
template<class B>
class if_void<void,B> {
public:
   using type = B;
};

}



// -----------------------------------------------------------------------------
// tnode
// -----------------------------------------------------------------------------

template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER,
   class T
>
class tnode : public Node<METADATA_CONTAINER,CHILDREN_CONTAINER> {
   using RETURN =
      typename detail::if_void<
         T,
         Node<METADATA_CONTAINER,CHILDREN_CONTAINER>
      >::type;

public:

   // ctor
   explicit tnode(const Node<METADATA_CONTAINER,CHILDREN_CONTAINER> &n) :
      Node<METADATA_CONTAINER,CHILDREN_CONTAINER>(n)
   { }

   // operator(): evaluate to RETURN (T if not void,
   // else Node<METADATA_CONTAINER,CHILDREN_CONTAINER>)
   RETURN operator()() const
   {
      RETURN ret;
      read(*(Node<METADATA_CONTAINER,CHILDREN_CONTAINER>*)this,ret);
      return ret;
   }

   using Node<METADATA_CONTAINER,CHILDREN_CONTAINER>::leaf;
   using Node<METADATA_CONTAINER,CHILDREN_CONTAINER>::write;
   using Node<METADATA_CONTAINER,CHILDREN_CONTAINER>::meta;
   using Node<METADATA_CONTAINER,CHILDREN_CONTAINER>::child;
   using Node<METADATA_CONTAINER,CHILDREN_CONTAINER>::operator();
};
