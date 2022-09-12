
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_RESONANCES_RESONANCEREACTION
#define TEST_V2_0_RESONANCES_RESONANCEREACTION

#include "test/v2.0/common/Q.hpp"
#include "test/v2.0/resonances/ScatteringRadius.hpp"
#include "test/v2.0/resonances/HardSphereRadius.hpp"
#include "test/v2.0/containers/Link.hpp"

namespace test {
namespace v2_0 {
namespace resonances {

// -----------------------------------------------------------------------------
// resonances::
// class ResonanceReaction
// -----------------------------------------------------------------------------

class ResonanceReaction : public Component<resonances::ResonanceReaction> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "resonances"; }
   static auto CLASS() { return "ResonanceReaction"; }
   static auto FIELD() { return "resonanceReaction"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("label") |
         XMLName{}
            / Meta<>("ejectile") |
         std::optional<Float64>{}
            / Meta<>("boundaryConditionValue") |
         Defaulted<bool>{false}
            / Meta<>("eliminated") |
         // children
         std::optional<common::Q>{}
            / --Child<>("Q") |
         std::optional<resonances::ScatteringRadius>{}
            / --Child<>("scatteringRadius") |
         std::optional<resonances::HardSphereRadius>{}
            / --Child<>("hardSphereRadius") |
         containers::Link{}
            / --Child<>("link")
      ;
   }

public:
   using Component::construct;

   // defaults
   static inline const struct Defaults {
      static inline const bool eliminated = false;
   } defaults;

   // metadata
   Field<XMLName> label{this};
   Field<XMLName> ejectile{this};
   Field<std::optional<Float64>> boundaryConditionValue{this};
   Field<Defaulted<bool>> eliminated{this,defaults.eliminated};

   // children
   Field<std::optional<common::Q>> Q{this};
   Field<std::optional<resonances::ScatteringRadius>> scatteringRadius{this};
   Field<std::optional<resonances::HardSphereRadius>> hardSphereRadius{this};
   Field<containers::Link> link{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->ejectile, \
      this->boundaryConditionValue, \
      this->eliminated, \
      this->Q, \
      this->scatteringRadius, \
      this->hardSphereRadius, \
      this->link)

   // default, and from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit ResonanceReaction(
      const wrapper<XMLName> &label = {},
      const wrapper<XMLName> &ejectile = {},
      const wrapper<std::optional<Float64>> &boundaryConditionValue = {},
      const wrapper<std::optional<bool>> &eliminated = {},
      const wrapper<std::optional<common::Q>> &Q = {},
      const wrapper<std::optional<resonances::ScatteringRadius>> &scatteringRadius = {},
      const wrapper<std::optional<resonances::HardSphereRadius>> &hardSphereRadius = {},
      const wrapper<containers::Link> &link = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      ejectile(this,ejectile),
      boundaryConditionValue(this,boundaryConditionValue),
      eliminated(this,defaults.eliminated,eliminated),
      Q(this,Q),
      scatteringRadius(this,scatteringRadius),
      hardSphereRadius(this,hardSphereRadius),
      link(this,link)
   {
      Component::finish();
   }

   // from node
   explicit ResonanceReaction(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ResonanceReaction(const ResonanceReaction &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   ResonanceReaction(ResonanceReaction &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   ResonanceReaction &operator=(const ResonanceReaction &) = default;
   ResonanceReaction &operator=(ResonanceReaction &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/resonances/ResonanceReaction/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ResonanceReaction

} // namespace resonances
} // namespace v2_0
} // namespace test

#endif