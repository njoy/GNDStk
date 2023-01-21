
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_RESONANCES_BREITWIGNER
#define TEST_V2_0_RESONANCES_BREITWIGNER

#include "test/v2.0/pops/PoPs_database.hpp"
#include "test/v2.0/resonances/ScatteringRadius.hpp"
#include "test/v2.0/resonances/HardSphereRadius.hpp"
#include "test/v2.0/resonances/ResonanceParameters.hpp"

namespace test {
namespace v2_0 {
namespace resonances {

// -----------------------------------------------------------------------------
// resonances::
// class BreitWigner
// -----------------------------------------------------------------------------

class BreitWigner :
   public Component<resonances::BreitWigner>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "resonances"; }
   static auto CLASS() { return "BreitWigner"; }
   static auto FIELD() { return "BreitWigner"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         XMLName{}
            / Meta<>("label") |
         XMLName{}
            / Meta<>("approximation") |
         Defaulted<bool>{false}
            / Meta<>("calculateChannelRadius") |
         Defaulted<bool>{false}
            / Meta<>("useForSelfShieldingOnly") |

         // children
         --Child<std::optional<pops::PoPs_database>>("PoPs") |
         --Child<std::optional<resonances::ScatteringRadius>>("scatteringRadius") |
         --Child<std::optional<resonances::HardSphereRadius>>("hardSphereRadius") |
         --Child<std::optional<resonances::ResonanceParameters>>("resonanceParameters")
      ;
   }

public:
   using Component::construct;

   // defaults
   static inline const struct Defaults {
      static inline const bool calculateChannelRadius = false;
      static inline const bool useForSelfShieldingOnly = false;
   } defaults;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<XMLName> label{this};
   Field<XMLName> approximation{this};
   Field<Defaulted<bool>> calculateChannelRadius{this,defaults.calculateChannelRadius};
   Field<Defaulted<bool>> useForSelfShieldingOnly{this,defaults.useForSelfShieldingOnly};

   // children
   Field<std::optional<pops::PoPs_database>> PoPs_database{this};
   Field<std::optional<resonances::ScatteringRadius>> scatteringRadius{this};
   Field<std::optional<resonances::HardSphereRadius>> hardSphereRadius{this};
   Field<std::optional<resonances::ResonanceParameters>> resonanceParameters{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->label, \
      this->approximation, \
      this->calculateChannelRadius, \
      this->useForSelfShieldingOnly, \
      this->PoPs_database, \
      this->scatteringRadius, \
      this->hardSphereRadius, \
      this->resonanceParameters)

   // default
   BreitWigner() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   // optional replaces Defaulted; this class knows the default(s)
   explicit BreitWigner(
      const wrapper<XMLName> &label,
      const wrapper<XMLName> &approximation = {},
      const wrapper<std::optional<bool>> &calculateChannelRadius = {},
      const wrapper<std::optional<bool>> &useForSelfShieldingOnly = {},
      const wrapper<std::optional<pops::PoPs_database>> &PoPs_database = {},
      const wrapper<std::optional<resonances::ScatteringRadius>> &scatteringRadius = {},
      const wrapper<std::optional<resonances::HardSphereRadius>> &hardSphereRadius = {},
      const wrapper<std::optional<resonances::ResonanceParameters>> &resonanceParameters = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      approximation(this,approximation),
      calculateChannelRadius(this,defaults.calculateChannelRadius,calculateChannelRadius),
      useForSelfShieldingOnly(this,defaults.useForSelfShieldingOnly,useForSelfShieldingOnly),
      PoPs_database(this,PoPs_database),
      scatteringRadius(this,scatteringRadius),
      hardSphereRadius(this,hardSphereRadius),
      resonanceParameters(this,resonanceParameters)
   {
      Component::finish();
   }

   // from node
   explicit BreitWigner(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   BreitWigner(const BreitWigner &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      approximation(this,other.approximation),
      calculateChannelRadius(this,other.calculateChannelRadius),
      useForSelfShieldingOnly(this,other.useForSelfShieldingOnly),
      PoPs_database(this,other.PoPs_database),
      scatteringRadius(this,other.scatteringRadius),
      hardSphereRadius(this,other.hardSphereRadius),
      resonanceParameters(this,other.resonanceParameters)
   {
      Component::finish(other);
   }

   // move
   BreitWigner(BreitWigner &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      approximation(this,std::move(other.approximation)),
      calculateChannelRadius(this,std::move(other.calculateChannelRadius)),
      useForSelfShieldingOnly(this,std::move(other.useForSelfShieldingOnly)),
      PoPs_database(this,std::move(other.PoPs_database)),
      scatteringRadius(this,std::move(other.scatteringRadius)),
      hardSphereRadius(this,std::move(other.hardSphereRadius)),
      resonanceParameters(this,std::move(other.resonanceParameters))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   BreitWigner &operator=(const BreitWigner &) = default;
   BreitWigner &operator=(BreitWigner &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/resonances/BreitWigner/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class BreitWigner

} // namespace resonances
} // namespace v2_0
} // namespace test

#endif
