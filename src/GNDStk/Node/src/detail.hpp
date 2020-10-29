
namespace detail {

// node2Node: forward declaration
// This function is called by some of Node's assignment operators. We'd instead
// put this forward declaration into the file in which *those* are defined, but
// that file is #included inside class Node { ... }'s definition, where writing
// the forward declaration wouldn't make sense.
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
      // with the metadata key called "label"
      const std::string &label = n.meta("label",found);

      // If it's found, AND has the value we want,
      // then return true; otherwise return false
      return found && label == want;
   }
};


// -----------------------------------------------------------------------------
// noFilter
// -----------------------------------------------------------------------------

inline const auto noFilter = [](const auto &) { return true; };


// -----------------------------------------------------------------------------
// extract_found
// -----------------------------------------------------------------------------

inline bool &extract_found(bool &found)
{
   return found;
}

template<class T>
inline bool &extract_found(const T &)
{
   return detail::default_bool;
}

template<class T, class... ARGS>
inline bool &extract_found(const T &, ARGS &&...args)
{
   return extract_found(std::forward<ARGS>(args)...);
}

} // namespace detail
