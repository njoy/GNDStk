
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_RESONANCES_TABULATEDWIDTHS
#define TRY_V2_0_RESONANCES_TABULATEDWIDTHS

#include "try/v2.0/unknownNamespace/PoPs.hpp"
#include "try/v2.0/resonances/ScatteringRadius.hpp"
#include "try/v2.0/resonances/HardSphereRadius.hpp"
#include "try/v2.0/resonances/ResonanceReactions.hpp"
#include "try/v2.0/resonances/Ls.hpp"

namespace try {
namespace v2_0 {
namespace resonances {

// -----------------------------------------------------------------------------
// resonances::
// class TabulatedWidths
// -----------------------------------------------------------------------------

class TabulatedWidths : public Component<resonances::TabulatedWidths> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "resonances"; }
   static auto CLASS() { return "TabulatedWidths"; }
   static auto FIELD() { return "tabulatedWidths"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("label") |
         XMLName{}
            / Meta<>("approximation") |
         Defaulted<bool>{false}
            / Meta<>("useForSelfShieldingOnly") |
         // children
         std::optional<unknownNamespace::PoPs>{}
            / --Child<>("PoPs") |
         std::optional<resonances::ScatteringRadius>{}
            / --Child<>("scatteringRadius") |
         std::optional<resonances::HardSphereRadius>{}
            / --Child<>("hardSphereRadius") |
         resonances::ResonanceReactions{}
            / --Child<>("resonanceReactions") |
         resonances::Ls{}
            / --Child<>("Ls")
      ;
   }

public:
   using Component::construct;

   // defaults
   static inline const struct Defaults {
      static inline const bool useForSelfShieldingOnly = false;
   } defaults;

   // metadata
   Field<XMLName> label{this};
   Field<XMLName> approximation{this};
   Field<Defaulted<bool>> useForSelfShieldingOnly{this,defaults.useForSelfShieldingOnly};

   // children
   Field<std::optional<unknownNamespace::PoPs>> PoPs{this};
   Field<std::optional<resonances::ScatteringRadius>> scatteringRadius{this};
   Field<std::optional<resonances::HardSphereRadius>> hardSphereRadius{this};
   Field<resonances::ResonanceReactions> resonanceReactions{this};
   Field<resonances::Ls> Ls{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->approximation, \
      this->useForSelfShieldingOnly, \
      this->PoPs, \
      this->scatteringRadius, \
      this->hardSphereRadius, \
      this->resonanceReactions, \
      this->Ls)

   // default, and from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit TabulatedWidths(
      const wrapper<XMLName> &label = {},
      const wrapper<XMLName> &approximation = {},
      const wrapper<std::optional<bool>> &useForSelfShieldingOnly = {},
      const wrapper<std::optional<unknownNamespace::PoPs>> &PoPs = {},
      const wrapper<std::optional<resonances::ScatteringRadius>> &scatteringRadius = {},
      const wrapper<std::optional<resonances::HardSphereRadius>> &hardSphereRadius = {},
      const wrapper<resonances::ResonanceReactions> &resonanceReactions = {},
      const wrapper<resonances::Ls> &Ls = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      approximation(this,approximation),
      useForSelfShieldingOnly(this,defaults.useForSelfShieldingOnly,useForSelfShieldingOnly),
      PoPs(this,PoPs),
      scatteringRadius(this,scatteringRadius),
      hardSphereRadius(this,hardSphereRadius),
      resonanceReactions(this,resonanceReactions),
      Ls(this,Ls)
   {
      Component::finish();
   }

   // from node
   explicit TabulatedWidths(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   TabulatedWidths(const TabulatedWidths &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   TabulatedWidths(TabulatedWidths &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   TabulatedWidths &operator=(const TabulatedWidths &) = default;
   TabulatedWidths &operator=(TabulatedWidths &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/resonances/TabulatedWidths/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class TabulatedWidths

} // namespace resonances
} // namespace v2_0
} // namespace try

#endif