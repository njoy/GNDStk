
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_POPS_AVERAGEENERGY
#define TRY_V2_0_POPS_AVERAGEENERGY

#include "try/v2.0/documentation/Documentation.hpp"
#include "try/v2.0/pops/Uncertainty.hpp"

namespace try {
namespace v2_0 {
namespace pops {

// -----------------------------------------------------------------------------
// pops::
// class AverageEnergy
// -----------------------------------------------------------------------------

class AverageEnergy : public Component<pops::AverageEnergy> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "AverageEnergy"; }
   static auto FIELD() { return "averageEnergy"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("label") |
         Float64{}
            / Meta<>("value") |
         XMLName{}
            / Meta<>("unit") |
         // children
         std::optional<documentation::Documentation>{}
            / --Child<>("documentation") |
         std::optional<pops::Uncertainty>{}
            / --Child<>("uncertainty")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<XMLName> label{this};
   Field<Float64> value{this};
   Field<XMLName> unit{this};

   // children
   Field<std::optional<documentation::Documentation>> documentation{this};
   Field<std::optional<pops::Uncertainty>> uncertainty{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->value, \
      this->unit, \
      this->documentation, \
      this->uncertainty)

   // default, and from fields
   explicit AverageEnergy(
      const wrapper<XMLName> &label = {},
      const wrapper<Float64> &value = {},
      const wrapper<XMLName> &unit = {},
      const wrapper<std::optional<documentation::Documentation>> &documentation = {},
      const wrapper<std::optional<pops::Uncertainty>> &uncertainty = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      value(this,value),
      unit(this,unit),
      documentation(this,documentation),
      uncertainty(this,uncertainty)
   {
      Component::finish();
   }

   // from node
   explicit AverageEnergy(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   AverageEnergy(const AverageEnergy &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   AverageEnergy(AverageEnergy &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   AverageEnergy &operator=(const AverageEnergy &) = default;
   AverageEnergy &operator=(AverageEnergy &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/pops/AverageEnergy/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class AverageEnergy

} // namespace pops
} // namespace v2_0
} // namespace try

#endif
