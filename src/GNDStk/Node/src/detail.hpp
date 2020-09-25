
namespace detail {

// Forward declaration needed from Node.hpp
template<class NODEFROM, class NODETO>
void node2Node(const NODEFROM &, NODETO &);


// -----------------------------------------------------------------------------
// apply_converter
// -----------------------------------------------------------------------------

// apply_converter<TYPE>
template<class TYPE>
class apply_converter {
public:
   template<class KEYWORD, class NODE>
   void operator()(const KEYWORD &kwd, const NODE &node) const
   {
      TYPE type{};
      kwd.converter(node,type);
   }
};

// apply_converter<void>
template<>
class apply_converter<void> {
public:
   template<class KEYWORD, class NODE>
   void operator()(const KEYWORD &, const NODE &) const
   {
      // no action
   }
};


// -----------------------------------------------------------------------------
// label_is
// -----------------------------------------------------------------------------

class label_is {
   std::string want;

public:
   explicit label_is(const std::string &str) : want(str)
   {
   }

   template<class NODE>
   bool operator()(const NODE &n) const
   {
      bool found;

      // In node n, look for the value associated
      // with the metadata key "label".
      const std::string &label = n.meta("label",found);

      // If it's found, AND has the value we want,
      // then return true. Otherwise return false.
      return found && label == want;
   }
};

} // namespace detail
