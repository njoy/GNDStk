
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_CPTRANSPORT_COULOMBPLUSNUCLEARELASTIC
#define TRY_V2_0_CPTRANSPORT_COULOMBPLUSNUCLEARELASTIC

#include "try/v2.0/cpTransport/RutherfordScattering.hpp"
#include "try/v2.0/cpTransport/NuclearAmplitudeExpansion.hpp"
#include "try/v2.0/cpTransport/NuclearPlusInterference.hpp"

namespace try {
namespace v2_0 {
namespace cpTransport {

// -----------------------------------------------------------------------------
// cpTransport::
// class CoulombPlusNuclearElastic
// -----------------------------------------------------------------------------

class CoulombPlusNuclearElastic : public Component<cpTransport::CoulombPlusNuclearElastic> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "cpTransport"; }
   static auto CLASS() { return "CoulombPlusNuclearElastic"; }
   static auto FIELD() { return "CoulombPlusNuclearElastic"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::optional<XMLName>{}
            / Meta<>("href") |
         Defaulted<bool>{false}
            / Meta<>("identicalParticles") |
         XMLName{}
            / Meta<>("label") |
         XMLName{}
            / Meta<>("pid") |
         enums::Frame{}
            / Meta<>("productFrame") |
         // children
         std::optional<cpTransport::RutherfordScattering>{}
            / --Child<>("RutherfordScattering") |
         std::optional<cpTransport::NuclearAmplitudeExpansion>{}
            / --Child<>("nuclearAmplitudeExpansion") |
         std::optional<cpTransport::NuclearPlusInterference>{}
            / --Child<>("nuclearPlusInterference")
      ;
   }

public:
   using Component::construct;

   // defaults
   static inline const struct Defaults {
      static inline const bool identicalParticles = false;
   } defaults;

   // metadata
   Field<std::optional<XMLName>> href{this};
   Field<Defaulted<bool>> identicalParticles{this,defaults.identicalParticles};
   Field<XMLName> label{this};
   Field<XMLName> pid{this};
   Field<enums::Frame> productFrame{this};

   // children
   Field<std::optional<cpTransport::RutherfordScattering>> RutherfordScattering{this};
   Field<std::optional<cpTransport::NuclearAmplitudeExpansion>> nuclearAmplitudeExpansion{this};
   Field<std::optional<cpTransport::NuclearPlusInterference>> nuclearPlusInterference{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->href, \
      this->identicalParticles, \
      this->label, \
      this->pid, \
      this->productFrame, \
      this->RutherfordScattering, \
      this->nuclearAmplitudeExpansion, \
      this->nuclearPlusInterference)

   // default, and from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit CoulombPlusNuclearElastic(
      const wrapper<std::optional<XMLName>> &href = {},
      const wrapper<std::optional<bool>> &identicalParticles = {},
      const wrapper<XMLName> &label = {},
      const wrapper<XMLName> &pid = {},
      const wrapper<enums::Frame> &productFrame = {},
      const wrapper<std::optional<cpTransport::RutherfordScattering>> &RutherfordScattering = {},
      const wrapper<std::optional<cpTransport::NuclearAmplitudeExpansion>> &nuclearAmplitudeExpansion = {},
      const wrapper<std::optional<cpTransport::NuclearPlusInterference>> &nuclearPlusInterference = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      href(this,href),
      identicalParticles(this,defaults.identicalParticles,identicalParticles),
      label(this,label),
      pid(this,pid),
      productFrame(this,productFrame),
      RutherfordScattering(this,RutherfordScattering),
      nuclearAmplitudeExpansion(this,nuclearAmplitudeExpansion),
      nuclearPlusInterference(this,nuclearPlusInterference)
   {
      Component::finish();
   }

   // from node
   explicit CoulombPlusNuclearElastic(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   CoulombPlusNuclearElastic(const CoulombPlusNuclearElastic &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   CoulombPlusNuclearElastic(CoulombPlusNuclearElastic &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   CoulombPlusNuclearElastic &operator=(const CoulombPlusNuclearElastic &) = default;
   CoulombPlusNuclearElastic &operator=(CoulombPlusNuclearElastic &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/cpTransport/CoulombPlusNuclearElastic/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class CoulombPlusNuclearElastic

} // namespace cpTransport
} // namespace v2_0
} // namespace try

#endif