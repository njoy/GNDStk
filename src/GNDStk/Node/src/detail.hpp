
// -----------------------------------------------------------------------------
// miscellaneous
// -----------------------------------------------------------------------------

namespace detail {

// strip
// Strips leading digits and white-space from a string. Modifies
// the original string, and also returns a reference to it.
inline std::string &strip(std::string &name)
{
   int n = 0, ch; const int size = name.size();
   while (n < size and (isdigit(ch=name[n]) or isspace(ch)))
      n++;
   return n ? (name = std::string(&name[n])) : name;
}

// is_oneof
// For some SFINAE
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
      RESULT result;
      node2type(node,result);
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
