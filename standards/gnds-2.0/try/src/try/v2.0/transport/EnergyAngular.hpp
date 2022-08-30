
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_TRANSPORT_ENERGYANGULAR
#define TRY_V2_0_TRANSPORT_ENERGYANGULAR

#include "try/v2.0/containers/XYs3d.hpp"

namespace try {
namespace v2_0 {
namespace transport {

// -----------------------------------------------------------------------------
// transport::
// class EnergyAngular
// -----------------------------------------------------------------------------

class EnergyAngular : public Component<transport::EnergyAngular> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "transport"; }
   static auto CLASS() { return "EnergyAngular"; }
   static auto FIELD() { return "energyAngular"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::optional<XMLName>{}
            / Meta<>("label") |
         XMLName{}
            / Meta<>("productFrame") |
         // children
         containers::XYs3d{}
            / --Child<>("XYs3d")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::optional<XMLName>> label{this};
   Field<XMLName> productFrame{this};

   // children
   Field<containers::XYs3d> XYs3d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->productFrame, \
      this->XYs3d)

   // default, and from fields
   explicit EnergyAngular(
      const wrapper<std::optional<XMLName>> &label = {},
      const wrapper<XMLName> &productFrame = {},
      const wrapper<containers::XYs3d> &XYs3d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      productFrame(this,productFrame),
      XYs3d(this,XYs3d)
   {
      Component::finish();
   }

   // from node
   explicit EnergyAngular(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   EnergyAngular(const EnergyAngular &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   EnergyAngular(EnergyAngular &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   EnergyAngular &operator=(const EnergyAngular &) = default;
   EnergyAngular &operator=(EnergyAngular &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/transport/EnergyAngular/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class EnergyAngular

} // namespace transport
} // namespace v2_0
} // namespace try

#endif
