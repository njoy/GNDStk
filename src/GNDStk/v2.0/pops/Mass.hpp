
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_POPS_MASS
#define NJOY_GNDSTK_V2_0_POPS_MASS

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/containers/Double.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// pops::
// class Mass
// -----------------------------------------------------------------------------

namespace pops {

class Mass : public Component<Mass> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "pops"; }
   static auto className() { return "Mass"; }
   static auto GNDSName() { return "mass"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // children
         std::optional<containers::Double>{}
            / --Child<>("Double")
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
      // children
      std::optional<containers::Double> Double;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // Double
   const std::optional<containers::Double> &Double() const
      { return content.Double; }
   std::optional<containers::Double> &Double()
      { return content.Double; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // Double(value)
   Mass &Double(const std::optional<containers::Double> &obj)
      { Double() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Mass() :
      Component{
         BodyText{},
         content.Double
      }
   {
      Component::finish();
   }

   // copy
   Mass(const Mass &other) :
      Component{
         other,
         content.Double
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Mass(Mass &&other) :
      Component{
         other,
         content.Double
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Mass(const Node &node) :
      Component{
         BodyText{},
         content.Double
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Mass(
      const std::optional<containers::Double> &Double
   ) :
      Component{
         BodyText{},
         content.Double
      },
      content{
         Double
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Mass &operator=(const Mass &) = default;

   // move
   Mass &operator=(Mass &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/pops/Mass/src/custom.hpp"

}; // class Mass

} // namespace pops
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif
