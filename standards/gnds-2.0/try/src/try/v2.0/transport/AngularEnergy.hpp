
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_TRANSPORT_ANGULARENERGY
#define TRY_V2_0_TRANSPORT_ANGULARENERGY

#include "try/v2.0/unknownNamespace/XYs3d.hpp"

namespace try {
namespace v2_0 {
namespace transport {

// -----------------------------------------------------------------------------
// transport::
// class AngularEnergy
// -----------------------------------------------------------------------------

class AngularEnergy : public Component<transport::AngularEnergy> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "transport"; }
   static auto CLASS() { return "AngularEnergy"; }
   static auto FIELD() { return "angularEnergy"; }

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
         unknownNamespace::XYs3d{}
            / --Child<>("XYs3d")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<XMLName> label{this};
   Field<XMLName> productFrame{this};

   // children
   Field<unknownNamespace::XYs3d> XYs3d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->productFrame, \
      this->XYs3d)

   // default, and from fields
   explicit AngularEnergy(
      const wrapper<XMLName> &label = {},
      const wrapper<XMLName> &productFrame = {},
      const wrapper<unknownNamespace::XYs3d> &XYs3d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      productFrame(this,productFrame),
      XYs3d(this,XYs3d)
   {
      Component::finish();
   }

   // from node
   explicit AngularEnergy(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   AngularEnergy(const AngularEnergy &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   AngularEnergy(AngularEnergy &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   AngularEnergy &operator=(const AngularEnergy &) = default;
   AngularEnergy &operator=(AngularEnergy &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/transport/AngularEnergy/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class AngularEnergy

} // namespace transport
} // namespace v2_0
} // namespace try

#endif
