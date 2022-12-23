
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_RESONANCES_RMATRIX
#define TEST_V2_0_RESONANCES_RMATRIX

#include "test/v2.0/pops/PoPs_database.hpp"
#include "test/v2.0/resonances/ResonanceReactions.hpp"
#include "test/v2.0/resonances/SpinGroups.hpp"

namespace test {
namespace v2_0 {
namespace resonances {

// -----------------------------------------------------------------------------
// resonances::
// class RMatrix
// -----------------------------------------------------------------------------

class RMatrix : public Component<resonances::RMatrix> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "resonances"; }
   static auto CLASS() { return "RMatrix"; }
   static auto FIELD() { return "RMatrix"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("label") |
         XMLName{}
            / Meta<>("approximation") |
         Defaulted<enums::BoundaryCondition>{enums::BoundaryCondition::EliminateShiftFunction}
            / Meta<>("boundaryCondition") |
         std::optional<Float64>{}
            / Meta<>("boundaryConditionValue") |
         Defaulted<bool>{false}
            / Meta<>("calculateChannelRadius") |
         Defaulted<bool>{true}
            / Meta<>("calculatePenetrability") |
         Defaulted<bool>{false}
            / Meta<>("useForSelfShieldingOnly") |
         Defaulted<bool>{false}
            / Meta<>("supportsAngularReconstruction") |
         // children
         --Child<std::optional<pops::PoPs_database>>("PoPs") |
         --Child<resonances::ResonanceReactions>("resonanceReactions") |
         --Child<resonances::SpinGroups>("spinGroups")
      ;
   }

public:
   using Component::construct;

   // defaults
   static inline const struct Defaults {
      static inline const enums::BoundaryCondition boundaryCondition = enums::BoundaryCondition::EliminateShiftFunction;
      static inline const bool calculateChannelRadius = false;
      static inline const bool calculatePenetrability = true;
      static inline const bool useForSelfShieldingOnly = false;
      static inline const bool supportsAngularReconstruction = false;
   } defaults;

   // metadata
   Field<XMLName> label{this};
   Field<XMLName> approximation{this};
   Field<Defaulted<enums::BoundaryCondition>> boundaryCondition{this,defaults.boundaryCondition};
   Field<std::optional<Float64>> boundaryConditionValue{this};
   Field<Defaulted<bool>> calculateChannelRadius{this,defaults.calculateChannelRadius};
   Field<Defaulted<bool>> calculatePenetrability{this,defaults.calculatePenetrability};
   Field<Defaulted<bool>> useForSelfShieldingOnly{this,defaults.useForSelfShieldingOnly};
   Field<Defaulted<bool>> supportsAngularReconstruction{this,defaults.supportsAngularReconstruction};

   // children
   Field<std::optional<pops::PoPs_database>> PoPs{this};
   Field<resonances::ResonanceReactions> resonanceReactions{this};
   Field<resonances::SpinGroups> spinGroups{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->approximation, \
      this->boundaryCondition, \
      this->boundaryConditionValue, \
      this->calculateChannelRadius, \
      this->calculatePenetrability, \
      this->useForSelfShieldingOnly, \
      this->supportsAngularReconstruction, \
      this->PoPs, \
      this->resonanceReactions, \
      this->spinGroups)

   // default
   RMatrix() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit RMatrix(
      const wrapper<XMLName> &label,
      const wrapper<XMLName> &approximation = {},
      const wrapper<std::optional<enums::BoundaryCondition>> &boundaryCondition = {},
      const wrapper<std::optional<Float64>> &boundaryConditionValue = {},
      const wrapper<std::optional<bool>> &calculateChannelRadius = {},
      const wrapper<std::optional<bool>> &calculatePenetrability = {},
      const wrapper<std::optional<bool>> &useForSelfShieldingOnly = {},
      const wrapper<std::optional<bool>> &supportsAngularReconstruction = {},
      const wrapper<std::optional<pops::PoPs_database>> &PoPs = {},
      const wrapper<resonances::ResonanceReactions> &resonanceReactions = {},
      const wrapper<resonances::SpinGroups> &spinGroups = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      approximation(this,approximation),
      boundaryCondition(this,defaults.boundaryCondition,boundaryCondition),
      boundaryConditionValue(this,boundaryConditionValue),
      calculateChannelRadius(this,defaults.calculateChannelRadius,calculateChannelRadius),
      calculatePenetrability(this,defaults.calculatePenetrability,calculatePenetrability),
      useForSelfShieldingOnly(this,defaults.useForSelfShieldingOnly,useForSelfShieldingOnly),
      supportsAngularReconstruction(this,defaults.supportsAngularReconstruction,supportsAngularReconstruction),
      PoPs(this,PoPs),
      resonanceReactions(this,resonanceReactions),
      spinGroups(this,spinGroups)
   {
      Component::finish();
   }

   // from node
   explicit RMatrix(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   RMatrix(const RMatrix &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      label(this,other.label),
      approximation(this,other.approximation),
      boundaryCondition(this,other.boundaryCondition),
      boundaryConditionValue(this,other.boundaryConditionValue),
      calculateChannelRadius(this,other.calculateChannelRadius),
      calculatePenetrability(this,other.calculatePenetrability),
      useForSelfShieldingOnly(this,other.useForSelfShieldingOnly),
      supportsAngularReconstruction(this,other.supportsAngularReconstruction),
      PoPs(this,other.PoPs),
      resonanceReactions(this,other.resonanceReactions),
      spinGroups(this,other.spinGroups)
   {
      Component::finish(other);
   }

   // move
   RMatrix(RMatrix &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      label(this,std::move(other.label)),
      approximation(this,std::move(other.approximation)),
      boundaryCondition(this,std::move(other.boundaryCondition)),
      boundaryConditionValue(this,std::move(other.boundaryConditionValue)),
      calculateChannelRadius(this,std::move(other.calculateChannelRadius)),
      calculatePenetrability(this,std::move(other.calculatePenetrability)),
      useForSelfShieldingOnly(this,std::move(other.useForSelfShieldingOnly)),
      supportsAngularReconstruction(this,std::move(other.supportsAngularReconstruction)),
      PoPs(this,std::move(other.PoPs)),
      resonanceReactions(this,std::move(other.resonanceReactions)),
      spinGroups(this,std::move(other.spinGroups))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   RMatrix &operator=(const RMatrix &) = default;
   RMatrix &operator=(RMatrix &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/resonances/RMatrix/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class RMatrix

} // namespace resonances
} // namespace v2_0
} // namespace test

#endif
