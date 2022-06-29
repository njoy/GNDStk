
// General helper constructs
#include "GNDStk/Component/src/detail.hpp"

// Map from some term/subject to its documentation,
// for use by classes that derive from Component,
// and in particular for use in the Python bindings.
using helpMap = std::map<std::string,std::string>;



// -----------------------------------------------------------------------------
// Component
// -----------------------------------------------------------------------------

template<class DERIVED, bool hasBlockData, class DATA>
class Component : public BlockData<hasBlockData,DATA>
{
   // For convenience
   using body = BlockData<hasBlockData,DATA>;
   using typename body::VariantOfVectors;
   using typename body::VariantOfScalars;
   static inline constexpr bool hasFields =
      !std::is_same_v<decltype(DERIVED::keys()),std::tuple<>>;

   // Links to fields in the object of the derived class. I can't find a way
   // to do this in a decltype(DERIVED::keys())-aware manner, because DERIVED
   // is generally an incomplete type *here* - outside of Component's member
   // functions. So, we'll do it the old-fashioned way.
   std::vector<void *> links;

   // This class cannot have copy or move construction. Its constructor MUST
   // know about the fields in the specific instance that's derived from it.
   Component(const Component &) = delete;
   Component(Component &&) = delete;

   // Copy and move *assignments* have the right behavior, however.
   Component &operator=(const Component &other)
   {
      body::operator=(other);
      return *this;
   }
   Component &operator=(Component &&other)
   {
      body::operator=(std::move(other));
      return *this;
   }

   // Constructor; intentionally *private*
   #include "GNDStk/Component/src/ctor.hpp"

   // finish
   // See comments in finish.hpp
   #include "GNDStk/Component/src/finish.hpp"

   // Helpers for derived-class getters/setters.
   // These shorten the code in the derived classes.
   #include "GNDStk/Component/src/getter.hpp"
   #include "GNDStk/Component/src/setter.hpp"

   // Fallback for documentation() if DERIVED doesn't have help
   static inline helpMap help;

public:

   #include "GNDStk/Component/src/read.hpp"
   #include "GNDStk/Component/src/write.hpp"
   #include "GNDStk/Component/src/fromNode.hpp"
   #include "GNDStk/Component/src/sort.hpp"
   #include "GNDStk/Component/src/toNode.hpp" // conversion to Node

   // You can (but need not) override the following in DERIVED
   static std::string namespaceName() { return ""; }

   // base
   // Convenient access to the BlockData base class
   body &baseBlockData() { return *this; }
   const body &baseBlockData() const { return *this; }

   // derived
   // Convenient access to the derived class
   DERIVED &derived()
      { return static_cast<DERIVED &>(*this); }
   const DERIVED &derived() const
      { return static_cast<const DERIVED &>(*this); }

   // documentation
   static std::string documentation(const std::string &subject = "")
   {
      try {
         return DERIVED::help.at(subject);
      } catch ( ... ) {
         return "No help information is available";
      }
   }

   // Component << string
   // Meaning: read the string's content (currently XML, JSON, or HDF5) into
   // an object of the Component's DERIVED class. Uses Node's << string, which
   // does most of the work.
   void operator<<(const std::string &str)
   {
      try {
         Node node;
         node << str;
         derived() = DERIVED(node);
      } catch (...) {
         log::function(std::string(DERIVED::className()) + " << string");
         throw;
      }
   }

}; // class Component


// -----------------------------------------------------------------------------
// ostream << Component
// -----------------------------------------------------------------------------

template<class DERIVED, bool hasBlockData, class DATA>
std::ostream &operator<<(
   std::ostream &os,
   const Component<DERIVED,hasBlockData,DATA> &obj
) {
   return obj.write(os,0);
}
