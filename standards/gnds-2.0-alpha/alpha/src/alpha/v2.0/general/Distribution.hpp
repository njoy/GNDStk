
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_DISTRIBUTION
#define ALPHA_V2_0_GENERAL_DISTRIBUTION

#include "alpha/v2.0/general/ThermalNeutronScatteringLaw.hpp"
#include "alpha/v2.0/general/Uncorrelated.hpp"
#include "alpha/v2.0/general/Unspecified.hpp"
#include "alpha/v2.0/general/Branching3d.hpp"
#include "alpha/v2.0/general/AngularTwoBody.hpp"
#include "alpha/v2.0/general/EnergyAngular.hpp"
#include "alpha/v2.0/general/KalbachMann.hpp"
#include "alpha/v2.0/general/AngularEnergy.hpp"
#include "alpha/v2.0/general/CoulombPlusNuclearElastic.hpp"
#include "alpha/v2.0/general/CoherentPhotonScattering.hpp"
#include "alpha/v2.0/general/IncoherentPhotonScattering.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Distribution
// -----------------------------------------------------------------------------

class Distribution :
   public Component<general::Distribution>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Distribution"; }
   static auto FIELD() { return "distribution"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<std::optional<general::ThermalNeutronScatteringLaw>>
            ("thermalNeutronScatteringLaw") |
         --Child<std::optional<general::Uncorrelated>>
            ("uncorrelated") |
         --Child<std::optional<general::Unspecified>>
            ("unspecified") |
         --Child<std::optional<general::Branching3d>>
            ("branching3d") |
         --Child<std::optional<general::AngularTwoBody>>
            ("angularTwoBody") |
         --Child<std::optional<general::EnergyAngular>>
            ("energyAngular") |
         --Child<std::optional<general::KalbachMann>>
            ("KalbachMann") |
         --Child<std::optional<general::AngularEnergy>>
            ("angularEnergy") |
         --Child<std::optional<general::CoulombPlusNuclearElastic>>
            ("CoulombPlusNuclearElastic") |
         --Child<std::optional<general::CoherentPhotonScattering>>
            ("coherentPhotonScattering") |
         --Child<std::optional<general::IncoherentPhotonScattering>>
            ("incoherentPhotonScattering")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "thermalNeutronScatteringLaw",
         "uncorrelated",
         "unspecified",
         "branching3d",
         "angularTwoBody",
         "energyAngular",
         "KalbachMann",
         "angularEnergy",
         "CoulombPlusNuclearElastic",
         "coherentPhotonScattering",
         "incoherentPhotonScattering"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "thermal_neutron_scattering_law",
         "uncorrelated",
         "unspecified",
         "branching3d",
         "angular_two_body",
         "energy_angular",
         "kalbach_mann",
         "angular_energy",
         "coulomb_plus_nuclear_elastic",
         "coherent_photon_scattering",
         "incoherent_photon_scattering"
      };
      return names;
   }

   // ------------------------
   // Public interface
   // ------------------------

public:

   using component_t = Component;
   using Component::construct;

   // ------------------------
   // Data members
   // ------------------------

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::optional<general::ThermalNeutronScatteringLaw>>
      thermalNeutronScatteringLaw{this};
   Field<std::optional<general::Uncorrelated>>
      uncorrelated{this};
   Field<std::optional<general::Unspecified>>
      unspecified{this};
   Field<std::optional<general::Branching3d>>
      branching3d{this};
   Field<std::optional<general::AngularTwoBody>>
      angularTwoBody{this};
   Field<std::optional<general::EnergyAngular>>
      energyAngular{this};
   Field<std::optional<general::KalbachMann>>
      KalbachMann{this};
   Field<std::optional<general::AngularEnergy>>
      angularEnergy{this};
   Field<std::optional<general::CoulombPlusNuclearElastic>>
      CoulombPlusNuclearElastic{this};
   Field<std::optional<general::CoherentPhotonScattering>>
      coherentPhotonScattering{this};
   Field<std::optional<general::IncoherentPhotonScattering>>
      incoherentPhotonScattering{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->thermalNeutronScatteringLaw, \
      this->uncorrelated, \
      this->unspecified, \
      this->branching3d, \
      this->angularTwoBody, \
      this->energyAngular, \
      this->KalbachMann, \
      this->angularEnergy, \
      this->CoulombPlusNuclearElastic, \
      this->coherentPhotonScattering, \
      this->incoherentPhotonScattering \
   )

   // default
   Distribution() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Distribution(
      const wrapper<std::optional<general::ThermalNeutronScatteringLaw>>
         &thermalNeutronScatteringLaw,
      const wrapper<std::optional<general::Uncorrelated>>
         &uncorrelated = {},
      const wrapper<std::optional<general::Unspecified>>
         &unspecified = {},
      const wrapper<std::optional<general::Branching3d>>
         &branching3d = {},
      const wrapper<std::optional<general::AngularTwoBody>>
         &angularTwoBody = {},
      const wrapper<std::optional<general::EnergyAngular>>
         &energyAngular = {},
      const wrapper<std::optional<general::KalbachMann>>
         &KalbachMann = {},
      const wrapper<std::optional<general::AngularEnergy>>
         &angularEnergy = {},
      const wrapper<std::optional<general::CoulombPlusNuclearElastic>>
         &CoulombPlusNuclearElastic = {},
      const wrapper<std::optional<general::CoherentPhotonScattering>>
         &coherentPhotonScattering = {},
      const wrapper<std::optional<general::IncoherentPhotonScattering>>
         &incoherentPhotonScattering = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      thermalNeutronScatteringLaw(this,thermalNeutronScatteringLaw),
      uncorrelated(this,uncorrelated),
      unspecified(this,unspecified),
      branching3d(this,branching3d),
      angularTwoBody(this,angularTwoBody),
      energyAngular(this,energyAngular),
      KalbachMann(this,KalbachMann),
      angularEnergy(this,angularEnergy),
      CoulombPlusNuclearElastic(this,CoulombPlusNuclearElastic),
      coherentPhotonScattering(this,coherentPhotonScattering),
      incoherentPhotonScattering(this,incoherentPhotonScattering)
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
      thermalNeutronScatteringLaw(this,other.thermalNeutronScatteringLaw),
      uncorrelated(this,other.uncorrelated),
      unspecified(this,other.unspecified),
      branching3d(this,other.branching3d),
      angularTwoBody(this,other.angularTwoBody),
      energyAngular(this,other.energyAngular),
      KalbachMann(this,other.KalbachMann),
      angularEnergy(this,other.angularEnergy),
      CoulombPlusNuclearElastic(this,other.CoulombPlusNuclearElastic),
      coherentPhotonScattering(this,other.coherentPhotonScattering),
      incoherentPhotonScattering(this,other.incoherentPhotonScattering)
   {
      Component::finish(other);
   }

   // move
   Distribution(Distribution &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      thermalNeutronScatteringLaw(this,std::move(other.thermalNeutronScatteringLaw)),
      uncorrelated(this,std::move(other.uncorrelated)),
      unspecified(this,std::move(other.unspecified)),
      branching3d(this,std::move(other.branching3d)),
      angularTwoBody(this,std::move(other.angularTwoBody)),
      energyAngular(this,std::move(other.energyAngular)),
      KalbachMann(this,std::move(other.KalbachMann)),
      angularEnergy(this,std::move(other.angularEnergy)),
      CoulombPlusNuclearElastic(this,std::move(other.CoulombPlusNuclearElastic)),
      coherentPhotonScattering(this,std::move(other.coherentPhotonScattering)),
      incoherentPhotonScattering(this,std::move(other.incoherentPhotonScattering))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Distribution &operator=(const Distribution &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         thermalNeutronScatteringLaw = other.thermalNeutronScatteringLaw;
         uncorrelated = other.uncorrelated;
         unspecified = other.unspecified;
         branching3d = other.branching3d;
         angularTwoBody = other.angularTwoBody;
         energyAngular = other.energyAngular;
         KalbachMann = other.KalbachMann;
         angularEnergy = other.angularEnergy;
         CoulombPlusNuclearElastic = other.CoulombPlusNuclearElastic;
         coherentPhotonScattering = other.coherentPhotonScattering;
         incoherentPhotonScattering = other.incoherentPhotonScattering;
      }
      return *this;
   }

   // move
   Distribution &operator=(Distribution &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         thermalNeutronScatteringLaw = std::move(other.thermalNeutronScatteringLaw);
         uncorrelated = std::move(other.uncorrelated);
         unspecified = std::move(other.unspecified);
         branching3d = std::move(other.branching3d);
         angularTwoBody = std::move(other.angularTwoBody);
         energyAngular = std::move(other.energyAngular);
         KalbachMann = std::move(other.KalbachMann);
         angularEnergy = std::move(other.angularEnergy);
         CoulombPlusNuclearElastic = std::move(other.CoulombPlusNuclearElastic);
         coherentPhotonScattering = std::move(other.coherentPhotonScattering);
         incoherentPhotonScattering = std::move(other.incoherentPhotonScattering);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Distribution/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Distribution

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
