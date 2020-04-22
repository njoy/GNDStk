
// -----------------------------------------------------------------------------
// miscellaneous
// -----------------------------------------------------------------------------

namespace detail {

// is_oneof
// For some SFINAE
// Is Foo one of the types in Foos?
template<class Foo, class... Foos>
class is_oneof {
public:
   static constexpr bool value = (std::is_same_v<Foo,Foos> || ...);
};



// -----------------------------------------------------------------------------
// apply_keyword
// -----------------------------------------------------------------------------

// apply_keyword<RESULT>
template<class RESULT>
class apply_keyword {
public:
   template<class NODE>
   void operator()(const NODE &node) const
   {
      RESULT type{};
      node2type(node,type);
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
