
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_CPTRANSPORT_RUTHERFORDSCATTERING
#define NJOY_GNDSTK_V2_0_CPTRANSPORT_RUTHERFORDSCATTERING

// core interface
#include "GNDStk.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// cpTransport::
// class RutherfordScattering
// -----------------------------------------------------------------------------

namespace cpTransport {

class RutherfordScattering : public Component<RutherfordScattering> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "cpTransport"; }
   static auto className() { return "RutherfordScattering"; }
   static auto GNDSName() { return "RutherfordScattering"; }

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
   RutherfordScattering() :
      Component{
         BodyText{}
      }
   {
      Component::finish();
   }

   // copy
   RutherfordScattering(const RutherfordScattering &other) :
      Component{
         other
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   RutherfordScattering(RutherfordScattering &&other) :
      Component{
         other
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   RutherfordScattering(const Node &node) :
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
   RutherfordScattering &operator=(const RutherfordScattering &) = default;

   // move
   RutherfordScattering &operator=(RutherfordScattering &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/cpTransport/RutherfordScattering/src/custom.hpp"

}; // class RutherfordScattering

} // namespace cpTransport
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif