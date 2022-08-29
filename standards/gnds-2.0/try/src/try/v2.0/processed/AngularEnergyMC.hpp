
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_PROCESSED_ANGULARENERGYMC
#define TRY_V2_0_PROCESSED_ANGULARENERGYMC

#include "try/v2.0/unknownNamespace/Angular.hpp"
#include "try/v2.0/transport/AngularEnergy.hpp"

namespace try {
namespace v2_0 {
namespace processed {

// -----------------------------------------------------------------------------
// processed::
// class AngularEnergyMC
// -----------------------------------------------------------------------------

class AngularEnergyMC : public Component<processed::AngularEnergyMC> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "processed"; }
   static auto CLASS() { return "AngularEnergyMC"; }
   static auto FIELD() { return "angularEnergyMC"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("label") |
         XMLName{}
            / Meta<>("productFrame") |
         // children
         unknownNamespace::Angular{}
            / --Child<>("angular") |
         transport::AngularEnergy{}
            / --Child<>("angularEnergy")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<XMLName> label{this};
   Field<XMLName> productFrame{this};

   // children
   Field<unknownNamespace::Angular> angular{this};
   Field<transport::AngularEnergy> angularEnergy{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->productFrame, \
      this->angular, \
      this->angularEnergy)

   // default, and from fields
   explicit AngularEnergyMC(
      const wrapper<XMLName> &label = {},
      const wrapper<XMLName> &productFrame = {},
      const wrapper<unknownNamespace::Angular> &angular = {},
      const wrapper<transport::AngularEnergy> &angularEnergy = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      productFrame(this,productFrame),
      angular(this,angular),
      angularEnergy(this,angularEnergy)
   {
      Component::finish();
   }

   // from node
   explicit AngularEnergyMC(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   AngularEnergyMC(const AngularEnergyMC &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   AngularEnergyMC(AngularEnergyMC &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   AngularEnergyMC &operator=(const AngularEnergyMC &) = default;
   AngularEnergyMC &operator=(AngularEnergyMC &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/processed/AngularEnergyMC/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class AngularEnergyMC

} // namespace processed
} // namespace v2_0
} // namespace try

#endif
