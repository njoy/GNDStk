
// read(Node,Node)
// Overrides our default read(Node,...), defined elsewhere, because
// we know what to do in the following case.

template<
   template<class,class> class MCON,
   template<class,class> class CCON
>
inline void read(
   const gnds::Node<MCON,CCON> &from,
   gnds::Node<MCON,CCON> &to
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
   template<class,class> class MCON,
   template<class,class> class CCON,
   class T
>
class tnode : public Node<MCON,CCON> {
   using RETURN = typename detail::if_void<T,Node<MCON,CCON>>::type;

public:

   // ctor
   explicit tnode(const Node<MCON,CCON> &n) :
      Node<MCON,CCON>(n)
   { }

   // operator(): evaluate to RETURN (T if not void, else Node<MCON,CCON>)
   RETURN operator()() const
   {
      RETURN ret;
      read(*(Node<MCON,CCON>*)this,ret);
      return ret;
   }

   using Node<MCON,CCON>::leaf;
   using Node<MCON,CCON>::write;
   using Node<MCON,CCON>::meta;
   using Node<MCON,CCON>::child;
   using Node<MCON,CCON>::operator();
};
