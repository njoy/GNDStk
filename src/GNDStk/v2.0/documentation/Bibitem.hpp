
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_DOCUMENTATION_BIBITEM
#define NJOY_GNDSTK_V2_0_DOCUMENTATION_BIBITEM

// core interface
#include "GNDStk.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// documentation::
// class Bibitem
// -----------------------------------------------------------------------------

namespace documentation {

class Bibitem : public Component<Bibitem> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "documentation"; }
   static auto className() { return "Bibitem"; }
   static auto GNDSName() { return "bibitem"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("xref")
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static inline const struct Defaults {
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      XMLName xref;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // xref
   const XMLName &xref() const
      { return content.xref; }
   XMLName &xref()
      { return content.xref; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // xref(value)
   Bibitem &xref(const XMLName &obj)
      { xref() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Bibitem() :
      Component{
         BodyText{},
         content.xref
      }
   {
      Component::finish();
   }

   // copy
   Bibitem(const Bibitem &other) :
      Component{
         other,
         content.xref
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Bibitem(Bibitem &&other) :
      Component{
         other,
         content.xref
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Bibitem(const Node &node) :
      Component{
         BodyText{},
         content.xref
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Bibitem(
      const XMLName &xref
   ) :
      Component{
         BodyText{},
         content.xref
      },
      content{
         xref
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Bibitem &operator=(const Bibitem &) = default;

   // move
   Bibitem &operator=(Bibitem &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/documentation/Bibitem/src/custom.hpp"

}; // class Bibitem

} // namespace documentation
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif
