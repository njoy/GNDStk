
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_COMMON_DISTRIBUTION
#define ALPHA_V2_0_COMMON_DISTRIBUTION

#include "alpha/v2.0/mean/AngularTwoBody.hpp"
#include "alpha/v2.0/mean/Uncorrelated.hpp"
#include "alpha/v2.0/mean/Unspecified.hpp"
#include "alpha/v2.0/mean/EnergyAngular.hpp"
#include "alpha/v2.0/mean/KalbachMann.hpp"
#include "alpha/v2.0/mean/AngularEnergy.hpp"
#include "alpha/v2.0/mean/Branching3d.hpp"
#include "alpha/v2.0/dfiles/CoulombPlusNuclearElastic.hpp"
#include "alpha/v2.0/mean/CoherentPhotonScattering.hpp"
#include "alpha/v2.0/mean/IncoherentPhotonScattering.hpp"
#include "alpha/v2.0/tsl/ThermalNeutronScatteringLaw.hpp"

namespace alpha {
namespace v2_0 {
namespace common {

// -----------------------------------------------------------------------------
// common::
// class Distribution
// -----------------------------------------------------------------------------

class Distribution :
   public Component<common::Distribution>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "common"; }
   static auto CLASS() { return "Distribution"; }
   static auto FIELD() { return "distribution"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<std::optional<mean::AngularTwoBody>>("angularTwoBody") |
         --Child<std::optional<mean::Uncorrelated>>("uncorrelated") |
         --Child<std::optional<mean::Unspecified>>("unspecified") |
         --Child<std::optional<mean::EnergyAngular>>("energyAngular") |
         --Child<std::optional<mean::KalbachMann>>("KalbachMann") |
         --Child<std::optional<mean::AngularEnergy>>("angularEnergy") |
         --Child<std::optional<mean::Branching3d>>("branching3d") |
         --Child<std::optional<dfiles::CoulombPlusNuclearElastic>>("CoulombPlusNuclearElastic") |
         --Child<std::optional<mean::CoherentPhotonScattering>>("coherentPhotonScattering") |
         --Child<std::optional<mean::IncoherentPhotonScattering>>("incoherentPhotonScattering") |
         --Child<std::optional<tsl::ThermalNeutronScatteringLaw>>("thermalNeutronScatteringLaw")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::optional<mean::AngularTwoBody>> angularTwoBody{this};
   Field<std::optional<mean::Uncorrelated>> uncorrelated{this};
   Field<std::optional<mean::Unspecified>> unspecified{this};
   Field<std::optional<mean::EnergyAngular>> energyAngular{this};
   Field<std::optional<mean::KalbachMann>> KalbachMann{this};
   Field<std::optional<mean::AngularEnergy>> angularEnergy{this};
   Field<std::optional<mean::Branching3d>> branching3d{this};
   Field<std::optional<dfiles::CoulombPlusNuclearElastic>> CoulombPlusNuclearElastic{this};
   Field<std::optional<mean::CoherentPhotonScattering>> coherentPhotonScattering{this};
   Field<std::optional<mean::IncoherentPhotonScattering>> incoherentPhotonScattering{this};
   Field<std::optional<tsl::ThermalNeutronScatteringLaw>> thermalNeutronScatteringLaw{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->angularTwoBody, \
      this->uncorrelated, \
      this->unspecified, \
      this->energyAngular, \
      this->KalbachMann, \
      this->angularEnergy, \
      this->branching3d, \
      this->CoulombPlusNuclearElastic, \
      this->coherentPhotonScattering, \
      this->incoherentPhotonScattering, \
      this->thermalNeutronScatteringLaw)

   // default
   Distribution() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Distribution(
      const wrapper<std::optional<mean::AngularTwoBody>> &angularTwoBody,
      const wrapper<std::optional<mean::Uncorrelated>> &uncorrelated = {},
      const wrapper<std::optional<mean::Unspecified>> &unspecified = {},
      const wrapper<std::optional<mean::EnergyAngular>> &energyAngular = {},
      const wrapper<std::optional<mean::KalbachMann>> &KalbachMann = {},
      const wrapper<std::optional<mean::AngularEnergy>> &angularEnergy = {},
      const wrapper<std::optional<mean::Branching3d>> &branching3d = {},
      const wrapper<std::optional<dfiles::CoulombPlusNuclearElastic>> &CoulombPlusNuclearElastic = {},
      const wrapper<std::optional<mean::CoherentPhotonScattering>> &coherentPhotonScattering = {},
      const wrapper<std::optional<mean::IncoherentPhotonScattering>> &incoherentPhotonScattering = {},
      const wrapper<std::optional<tsl::ThermalNeutronScatteringLaw>> &thermalNeutronScatteringLaw = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      angularTwoBody(this,angularTwoBody),
      uncorrelated(this,uncorrelated),
      unspecified(this,unspecified),
      energyAngular(this,energyAngular),
      KalbachMann(this,KalbachMann),
      angularEnergy(this,angularEnergy),
      branching3d(this,branching3d),
      CoulombPlusNuclearElastic(this,CoulombPlusNuclearElastic),
      coherentPhotonScattering(this,coherentPhotonScattering),
      incoherentPhotonScattering(this,incoherentPhotonScattering),
      thermalNeutronScatteringLaw(this,thermalNeutronScatteringLaw)
   {
      Component::finish();
   }

   // from node
   explicit Distribution(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Distribution(const Distribution &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      angularTwoBody(this,other.angularTwoBody),
      uncorrelated(this,other.uncorrelated),
      unspecified(this,other.unspecified),
      energyAngular(this,other.energyAngular),
      KalbachMann(this,other.KalbachMann),
      angularEnergy(this,other.angularEnergy),
      branching3d(this,other.branching3d),
      CoulombPlusNuclearElastic(this,other.CoulombPlusNuclearElastic),
      coherentPhotonScattering(this,other.coherentPhotonScattering),
      incoherentPhotonScattering(this,other.incoherentPhotonScattering),
      thermalNeutronScatteringLaw(this,other.thermalNeutronScatteringLaw)
   {
      Component::finish(other);
   }

   // move
   Distribution(Distribution &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      angularTwoBody(this,std::move(other.angularTwoBody)),
      uncorrelated(this,std::move(other.uncorrelated)),
      unspecified(this,std::move(other.unspecified)),
      energyAngular(this,std::move(other.energyAngular)),
      KalbachMann(this,std::move(other.KalbachMann)),
      angularEnergy(this,std::move(other.angularEnergy)),
      branching3d(this,std::move(other.branching3d)),
      CoulombPlusNuclearElastic(this,std::move(other.CoulombPlusNuclearElastic)),
      coherentPhotonScattering(this,std::move(other.coherentPhotonScattering)),
      incoherentPhotonScattering(this,std::move(other.incoherentPhotonScattering)),
      thermalNeutronScatteringLaw(this,std::move(other.thermalNeutronScatteringLaw))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Distribution &operator=(const Distribution &) = default;
   Distribution &operator=(Distribution &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/common/Distribution/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Distribution

} // namespace common
} // namespace v2_0
} // namespace alpha

#endif
