
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_PROCESSED_ENERGYANGULARMC
#define TRY_V2_0_PROCESSED_ENERGYANGULARMC

#include "try/v2.0/common/Energy.hpp"
#include "try/v2.0/transport/EnergyAngular.hpp"

namespace try {
namespace v2_0 {
namespace processed {

// -----------------------------------------------------------------------------
// processed::
// class EnergyAngularMC
// -----------------------------------------------------------------------------

class EnergyAngularMC : public Component<processed::EnergyAngularMC> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "processed"; }
   static auto CLASS() { return "EnergyAngularMC"; }
   static auto FIELD() { return "energyAngularMC"; }

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
         common::Energy{}
            / --Child<>("energy") |
         transport::EnergyAngular{}
            / --Child<>("energyAngular")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<XMLName> label{this};
   Field<XMLName> productFrame{this};

   // children
   Field<common::Energy> energy{this};
   Field<transport::EnergyAngular> energyAngular{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->productFrame, \
      this->energy, \
      this->energyAngular)

   // default, and from fields
   explicit EnergyAngularMC(
      const wrapper<XMLName> &label = {},
      const wrapper<XMLName> &productFrame = {},
      const wrapper<common::Energy> &energy = {},
      const wrapper<transport::EnergyAngular> &energyAngular = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      productFrame(this,productFrame),
      energy(this,energy),
      energyAngular(this,energyAngular)
   {
      Component::finish();
   }

   // from node
   explicit EnergyAngularMC(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   EnergyAngularMC(const EnergyAngularMC &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   EnergyAngularMC(EnergyAngularMC &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   EnergyAngularMC &operator=(const EnergyAngularMC &) = default;
   EnergyAngularMC &operator=(EnergyAngularMC &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/processed/EnergyAngularMC/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class EnergyAngularMC

} // namespace processed
} // namespace v2_0
} // namespace try

#endif
