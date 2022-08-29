
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_POPS_DISCRETEENERGY
#define TRY_V2_0_POPS_DISCRETEENERGY

#include "try/v2.0/documentation/Documentation.hpp"
#include "try/v2.0/pops/Uncertainty.hpp"

namespace try {
namespace v2_0 {
namespace pops {

// -----------------------------------------------------------------------------
// pops::
// class DiscreteEnergy
// -----------------------------------------------------------------------------

class DiscreteEnergy : public Component<pops::DiscreteEnergy> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "DiscreteEnergy"; }
   static auto FIELD() { return "discreteEnergy"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::optional<XMLName>{}
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
   Field<std::optional<XMLName>> label{this};
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
   explicit DiscreteEnergy(
      const wrapper<std::optional<XMLName>> &label = {},
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
   explicit DiscreteEnergy(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   DiscreteEnergy(const DiscreteEnergy &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   DiscreteEnergy(DiscreteEnergy &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   DiscreteEnergy &operator=(const DiscreteEnergy &) = default;
   DiscreteEnergy &operator=(DiscreteEnergy &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/pops/DiscreteEnergy/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class DiscreteEnergy

} // namespace pops
} // namespace v2_0
} // namespace try

#endif
