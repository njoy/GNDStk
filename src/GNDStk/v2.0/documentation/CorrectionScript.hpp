
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_DOCUMENTATION_CORRECTIONSCRIPT
#define NJOY_GNDSTK_V2_0_DOCUMENTATION_CORRECTIONSCRIPT

// core interface
#include "GNDStk.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// documentation::
// class CorrectionScript
// -----------------------------------------------------------------------------

namespace documentation {

class CorrectionScript : public Component<CorrectionScript> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "documentation"; }
   static auto className() { return "CorrectionScript"; }
   static auto GNDSName() { return "correctionScript"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return std::tuple<>{};
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
   } content;

   // ------------------------
   // Construction
   // ------------------------

   // default
   CorrectionScript() :
      Component{
         BodyText{}
      }
   {
      Component::finish();
   }

   // copy
   CorrectionScript(const CorrectionScript &other) :
      Component{
         other
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   CorrectionScript(CorrectionScript &&other) :
      Component{
         other
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   CorrectionScript(const Node &node) :
      Component{
         BodyText{}
      }
   {
      Component::finish(node);
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   CorrectionScript &operator=(const CorrectionScript &) = default;

   // move
   CorrectionScript &operator=(CorrectionScript &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/documentation/CorrectionScript/src/custom.hpp"

}; // class CorrectionScript

} // namespace documentation
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif