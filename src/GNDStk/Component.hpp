
template<class DERIVED>
class Component;

// for printing
inline bool comments = true;

// for printing
#include "GNDStk/Component/src/colors.hpp"

// general helper constructs
#include "GNDStk/Component/src/detail.hpp"



// -----------------------------------------------------------------------------
// Component
// -----------------------------------------------------------------------------

template<class DERIVED>
class Component {

   // Links to fields in the object of the derived class. I can't find a way
   // to do this in a decltype(DERIVED::keys())-aware manner, because DERIVED
   // is generally an incomplete type *here* - outside of Component's member
   // functions. So, we'll do it the old-fashioned way.
   std::vector<void *> links;

   // This class cannot have copy or move construction. Its constructor MUST
   // know about the fields in the specific instance that's derived from it.
   Component(const Component &) = delete;
   Component(Component &&) = delete;

   // Do-nothing copy and move assignments have the right behavior, however.
   Component &operator=(const Component &) { return *this; }
   Component &operator=(Component &&) { return *this; }

   // Constructor; intentionally *private*
   #include "GNDStk/Component/src/ctor.hpp"

   // construct()
   // Hook by which a derived-class constructor, built by our auto-generation
   // process from a JSON-format GNDS spec, can run arbitrary additional code.
   void construct() const
   {
   }

public:

   #include "GNDStk/Component/src/query.hpp"
   #include "GNDStk/Component/src/toNode.hpp"
   #include "GNDStk/Component/src/write.hpp"

   // help
   // Override this function in a derived class in order to provide help,
   // e.g. for Python bindings, regarding a given subject.
   static std::string help(const std::string &/*subject*/ = "")
   {
      return "No description available";
      // Suggestion:
      // If subject == "", return help for the class
      // If subject == "constructor", return help for the constructor
      // If subject == "foo", return help for the "foo" parameter
      // Etc.
   }

}; // class Component



// -----------------------------------------------------------------------------
// operator<<
// -----------------------------------------------------------------------------

template<class DERIVED>
std::ostream &operator<<(std::ostream &os, const Component<DERIVED> &obj)
{
   return obj.write(os,0); // 0 == starting indentation level
}
