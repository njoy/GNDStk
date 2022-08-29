
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_RESONANCES_RESONANCES
#define TRY_V2_0_RESONANCES_RESONANCES

#include "try/v2.0/resonances/ScatteringRadius.hpp"
#include "try/v2.0/resonances/HardSphereRadius.hpp"
#include "try/v2.0/resonances/Resolved.hpp"
#include "try/v2.0/resonances/Unresolved.hpp"

namespace try {
namespace v2_0 {
namespace resonances {

// -----------------------------------------------------------------------------
// resonances::
// class Resonances
// -----------------------------------------------------------------------------

class Resonances : public Component<resonances::Resonances> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "resonances"; }
   static auto CLASS() { return "Resonances"; }
   static auto FIELD() { return "resonances"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::optional<XMLName>{}
            / Meta<>("href") |
         // children
         resonances::ScatteringRadius{}
            / --Child<>("scatteringRadius") |
         std::optional<resonances::HardSphereRadius>{}
            / --Child<>("hardSphereRadius") |
         std::optional<resonances::Resolved>{}
            / ++Child<>("resolved") |
         std::optional<resonances::Unresolved>{}
            / ++Child<>("unresolved")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::optional<XMLName>> href{this};

   // children
   Field<resonances::ScatteringRadius> scatteringRadius{this};
   Field<std::optional<resonances::HardSphereRadius>> hardSphereRadius{this};
   Field<std::optional<std::vector<resonances::Resolved>>> resolved{this};
   Field<std::optional<std::vector<resonances::Unresolved>>> unresolved{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->href, \
      this->scatteringRadius, \
      this->hardSphereRadius, \
      this->resolved, \
      this->unresolved)

   // default, and from fields
   explicit Resonances(
      const wrapper<std::optional<XMLName>> &href = {},
      const wrapper<resonances::ScatteringRadius> &scatteringRadius = {},
      const wrapper<std::optional<resonances::HardSphereRadius>> &hardSphereRadius = {},
      const wrapper<std::optional<std::vector<resonances::Resolved>>> &resolved = {},
      const wrapper<std::optional<std::vector<resonances::Unresolved>>> &unresolved = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      href(this,href),
      scatteringRadius(this,scatteringRadius),
      hardSphereRadius(this,hardSphereRadius),
      resolved(this,resolved),
      unresolved(this,unresolved)
   {
      Component::finish();
   }

   // from node
   explicit Resonances(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Resonances(const Resonances &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Resonances(Resonances &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Resonances &operator=(const Resonances &) = default;
   Resonances &operator=(Resonances &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/resonances/Resonances/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Resonances

} // namespace resonances
} // namespace v2_0
} // namespace try

#endif
