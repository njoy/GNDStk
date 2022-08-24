
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_FPY_INCIDENTENERGY
#define NJOY_GNDSTK_V2_0_FPY_INCIDENTENERGY

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/fpy/Energy.hpp"
#include "GNDStk/v2.0/fpy/Yields.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// fpy::
// class IncidentEnergy
// -----------------------------------------------------------------------------

namespace fpy {

class IncidentEnergy : public Component<IncidentEnergy> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "fpy"; }
   static auto className() { return "IncidentEnergy"; }
   static auto GNDSName() { return "incidentEnergy"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("label") |
         // children
         fpy::Energy{}
            / --Child<>("energy") |
         fpy::Yields{}
            / --Child<>("yields")
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
      XMLName label;
      // children
      fpy::Energy energy;
      fpy::Yields yields;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // label
   const XMLName &label() const
      { return content.label; }
   XMLName &label()
      { return content.label; }

   // energy
   const fpy::Energy &energy() const
      { return content.energy; }
   fpy::Energy &energy()
      { return content.energy; }

   // yields
   const fpy::Yields &yields() const
      { return content.yields; }
   fpy::Yields &yields()
      { return content.yields; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // label(value)
   IncidentEnergy &label(const XMLName &obj)
      { label() = obj; return *this; }

   // energy(value)
   IncidentEnergy &energy(const fpy::Energy &obj)
      { energy() = obj; return *this; }

   // yields(value)
   IncidentEnergy &yields(const fpy::Yields &obj)
      { yields() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   IncidentEnergy() :
      Component{
         BodyText{},
         content.label,
         content.energy,
         content.yields
      }
   {
      Component::finish();
   }

   // copy
   IncidentEnergy(const IncidentEnergy &other) :
      Component{
         other,
         content.label,
         content.energy,
         content.yields
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   IncidentEnergy(IncidentEnergy &&other) :
      Component{
         other,
         content.label,
         content.energy,
         content.yields
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   IncidentEnergy(const Node &node) :
      Component{
         BodyText{},
         content.label,
         content.energy,
         content.yields
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit IncidentEnergy(
      const XMLName &label,
      const fpy::Energy &energy,
      const fpy::Yields &yields
   ) :
      Component{
         BodyText{},
         content.label,
         content.energy,
         content.yields
      },
      content{
         label,
         energy,
         yields
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   IncidentEnergy &operator=(const IncidentEnergy &) = default;

   // move
   IncidentEnergy &operator=(IncidentEnergy &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/fpy/IncidentEnergy/src/custom.hpp"

}; // class IncidentEnergy

} // namespace fpy
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif