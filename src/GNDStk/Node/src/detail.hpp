
// Forward declaration needed from Node.hpp
namespace detail {
   template<class NODEFROM, class NODETO>
   void node2Node(const NODEFROM &, NODETO &);
}

// -----------------------------------------------------------------------------
// apply_keyword
// -----------------------------------------------------------------------------

namespace detail {

// apply_keyword<TYPE>
template<class TYPE>
class apply_keyword {
public:
   template<class KEYWORD, class NODE>
   void operator()(const KEYWORD &kwd, const NODE &from) const
   {
      TYPE type{};
      kwd.converter(from,type);
   }
};

// apply_keyword<void>
template<>
class apply_keyword<void> {
public:
   template<class KEYWORD, class NODE>
   void operator()(const KEYWORD &, const NODE &) const
   {
      // no action
   }
};

} // namespace detail
