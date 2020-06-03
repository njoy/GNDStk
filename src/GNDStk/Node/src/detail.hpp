
// Forward declaration needed from Node.hpp
namespace detail {
   template<class NODEFROM, class NODETO>
   void node2Node(const NODEFROM &, NODETO &);
}

// -----------------------------------------------------------------------------
// apply_keyword
// -----------------------------------------------------------------------------

namespace detail {

// apply_keyword<RESULT>
template<class RESULT>
class apply_keyword {
public:
   template<class NODE>
   void operator()(const NODE &node) const
   {
      RESULT type{};
      convert(node,type);
   }
};

// apply_keyword<Node>
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
class apply_keyword<Node<METADATA_CONTAINER,CHILDREN_CONTAINER>> {
public:
   template<class NODE>
   void operator()(const NODE &) const
   {
      // no action
   }
};

// apply_keyword<void>
template<>
class apply_keyword<void> {
public:
   template<class NODE>
   void operator()(const NODE &) const
   {
      // no action
   }
};

} // namespace detail
