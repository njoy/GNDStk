
template<class DERIVED, bool hasBodyText = false>
class Component;

// general helper constructs
#include "GNDStk/Component/src/detail.hpp"

// Map from some term/subject to its documentation,
// for use by classes that derive from Component
using helpMap = std::map<std::string,std::string>;



// -----------------------------------------------------------------------------
// Component
// -----------------------------------------------------------------------------

template<class DERIVED, bool hasBodyText>
class Component : public BodyText<hasBodyText> {

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
      BodyText<hasBodyText>::operator=(other);
      return *this;
   }
   Component &operator=(Component &&other)
   {
      BodyText<hasBodyText>::operator=(std::move(other));
      return *this;
   }

   // Constructor; intentionally *private*
   #include "GNDStk/Component/src/ctor.hpp"

   // construct()
   // Hooks by which derived-class constructors, built by our auto-generation
   // process from JSON-format GNDS specs, can run arbitrary additional code.
   void construct()
   {
   }
   void construct(const DERIVED &)
   {
      static_cast<DERIVED &>(*this).construct();
   }
   void construct(const Node &)
   {
      static_cast<DERIVED &>(*this).construct();
   }

   // You can (but don't need to) override in DERIVED
   static std::string namespaceName() { return ""; }

   // Intermediaries between derived-class getters/setters and getter/setter
   // functions in detail::. These shorten the code in the derived classes.
   #include "GNDStk/Component/src/getter.hpp"
   #include "GNDStk/Component/src/setter.hpp"

   // Fallback for documentation() if DERIVED doesn't have help
   static inline helpMap help;

public:

   #include "GNDStk/Component/src/fromNode.hpp"
   #include "GNDStk/Component/src/toNode.hpp"
   #include "GNDStk/Component/src/write.hpp"

   // documentation
   static std::string documentation(const std::string &subject = "")
   {
      try {
         return DERIVED::help.at(subject);
      }
      catch ( ... ) {
         return "No help information is available";
      }
   }

   // Component << std::string
   // Meaning: read the string's content (currently XML or JSON) into an object
   // of the Component's DERIVED class. Uses the Node << std::string capability.
   void operator<<(const std::string &str)
   {
      try {
         Node node;
         node << str;
         static_cast<DERIVED &>(*this) = DERIVED(node);
      } catch (...) {
         log::function(std::string(DERIVED::className()) + " << string");
         throw;
      }
   }

}; // class Component


// -----------------------------------------------------------------------------
// ostream << Component
// -----------------------------------------------------------------------------

template<class DERIVED, bool hasBodyText>
std::ostream &operator<<(
   std::ostream &os,
   const Component<DERIVED,hasBodyText> &obj
) {
   return obj.write(os);
}
