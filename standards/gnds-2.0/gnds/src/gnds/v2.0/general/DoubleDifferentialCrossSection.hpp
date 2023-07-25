
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_DOUBLEDIFFERENTIALCROSSSECTION
#define GNDS_V2_0_GENERAL_DOUBLEDIFFERENTIALCROSSSECTION

#include "gnds/v2.0/general/CoulombPlusNuclearElastic.hpp"
#include "gnds/v2.0/general/CoherentPhotonScattering.hpp"
#include "gnds/v2.0/general/IncoherentPhotonScattering.hpp"
#include "gnds/v2.0/general/ThermalNeutronScatteringLaw_coherentElastic.hpp"
#include "gnds/v2.0/general/ThermalNeutronScatteringLaw_incoherentElastic.hpp"
#include "gnds/v2.0/general/ThermalNeutronScatteringLaw_incoherentInelastic.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class DoubleDifferentialCrossSection
// -----------------------------------------------------------------------------

class DoubleDifferentialCrossSection :
   public Component<general::DoubleDifferentialCrossSection>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "DoubleDifferentialCrossSection"; }
   static auto NODENAME() { return "doubleDifferentialCrossSection"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<std::optional<general::CoulombPlusNuclearElastic>>
            ("CoulombPlusNuclearElastic") |
         --Child<std::optional<general::CoherentPhotonScattering>>
            ("coherentPhotonScattering") |
         --Child<std::optional<general::IncoherentPhotonScattering>>
            ("incoherentPhotonScattering") |
         --Child<std::optional<general::ThermalNeutronScatteringLaw_coherentElastic>>
            ("thermalNeutronScatteringLaw_coherentElastic") |
         --Child<std::optional<general::ThermalNeutronScatteringLaw_incoherentElastic>>
            ("thermalNeutronScatteringLaw_incoherentElastic") |
         --Child<std::optional<general::ThermalNeutronScatteringLaw_incoherentInelastic>>
            ("thermalNeutronScatteringLaw_incoherentInelastic")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "CoulombPlusNuclearElastic",
         "coherentPhotonScattering",
         "incoherentPhotonScattering",
         "thermalNeutronScatteringLaw_coherentElastic",
         "thermalNeutronScatteringLaw_incoherentElastic",
         "thermalNeutronScatteringLaw_incoherentInelastic"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "coulomb_plus_nuclear_elastic",
         "coherent_photon_scattering",
         "incoherent_photon_scattering",
         "thermal_neutron_scattering_law_coherent_elastic",
         "thermal_neutron_scattering_law_incoherent_elastic",
         "thermal_neutron_scattering_law_incoherent_inelastic"
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
   Field<std::optional<general::CoulombPlusNuclearElastic>>
      CoulombPlusNuclearElastic{this};
   Field<std::optional<general::CoherentPhotonScattering>>
      coherentPhotonScattering{this};
   Field<std::optional<general::IncoherentPhotonScattering>>
      incoherentPhotonScattering{this};
   Field<std::optional<general::ThermalNeutronScatteringLaw_coherentElastic>>
      thermalNeutronScatteringLaw_coherentElastic{this};
   Field<std::optional<general::ThermalNeutronScatteringLaw_incoherentElastic>>
      thermalNeutronScatteringLaw_incoherentElastic{this};
   Field<std::optional<general::ThermalNeutronScatteringLaw_incoherentInelastic>>
      thermalNeutronScatteringLaw_incoherentInelastic{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->CoulombPlusNuclearElastic, \
      this->coherentPhotonScattering, \
      this->incoherentPhotonScattering, \
      this->thermalNeutronScatteringLaw_coherentElastic, \
      this->thermalNeutronScatteringLaw_incoherentElastic, \
      this->thermalNeutronScatteringLaw_incoherentInelastic \
   )

   // default
   DoubleDifferentialCrossSection() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit DoubleDifferentialCrossSection(
      const wrapper<std::optional<general::CoulombPlusNuclearElastic>>
         &CoulombPlusNuclearElastic,
      const wrapper<std::optional<general::CoherentPhotonScattering>>
         &coherentPhotonScattering = {},
      const wrapper<std::optional<general::IncoherentPhotonScattering>>
         &incoherentPhotonScattering = {},
      const wrapper<std::optional<general::ThermalNeutronScatteringLaw_coherentElastic>>
         &thermalNeutronScatteringLaw_coherentElastic = {},
      const wrapper<std::optional<general::ThermalNeutronScatteringLaw_incoherentElastic>>
         &thermalNeutronScatteringLaw_incoherentElastic = {},
      const wrapper<std::optional<general::ThermalNeutronScatteringLaw_incoherentInelastic>>
         &thermalNeutronScatteringLaw_incoherentInelastic = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      CoulombPlusNuclearElastic(this,CoulombPlusNuclearElastic),
      coherentPhotonScattering(this,coherentPhotonScattering),
      incoherentPhotonScattering(this,incoherentPhotonScattering),
      thermalNeutronScatteringLaw_coherentElastic(this,thermalNeutronScatteringLaw_coherentElastic),
      thermalNeutronScatteringLaw_incoherentElastic(this,thermalNeutronScatteringLaw_incoherentElastic),
      thermalNeutronScatteringLaw_incoherentInelastic(this,thermalNeutronScatteringLaw_incoherentInelastic)
   {
      Component::finish();
   }

   // from node
   explicit DoubleDifferentialCrossSection(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   DoubleDifferentialCrossSection(const DoubleDifferentialCrossSection &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      CoulombPlusNuclearElastic(this,other.CoulombPlusNuclearElastic),
      coherentPhotonScattering(this,other.coherentPhotonScattering),
      incoherentPhotonScattering(this,other.incoherentPhotonScattering),
      thermalNeutronScatteringLaw_coherentElastic(this,other.thermalNeutronScatteringLaw_coherentElastic),
      thermalNeutronScatteringLaw_incoherentElastic(this,other.thermalNeutronScatteringLaw_incoherentElastic),
      thermalNeutronScatteringLaw_incoherentInelastic(this,other.thermalNeutronScatteringLaw_incoherentInelastic)
   {
      Component::finish(other);
   }

   // move
   DoubleDifferentialCrossSection(DoubleDifferentialCrossSection &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      CoulombPlusNuclearElastic(this,std::move(other.CoulombPlusNuclearElastic)),
      coherentPhotonScattering(this,std::move(other.coherentPhotonScattering)),
      incoherentPhotonScattering(this,std::move(other.incoherentPhotonScattering)),
      thermalNeutronScatteringLaw_coherentElastic(this,std::move(other.thermalNeutronScatteringLaw_coherentElastic)),
      thermalNeutronScatteringLaw_incoherentElastic(this,std::move(other.thermalNeutronScatteringLaw_incoherentElastic)),
      thermalNeutronScatteringLaw_incoherentInelastic(this,std::move(other.thermalNeutronScatteringLaw_incoherentInelastic))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   DoubleDifferentialCrossSection &operator=(const DoubleDifferentialCrossSection &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         CoulombPlusNuclearElastic = other.CoulombPlusNuclearElastic;
         coherentPhotonScattering = other.coherentPhotonScattering;
         incoherentPhotonScattering = other.incoherentPhotonScattering;
         thermalNeutronScatteringLaw_coherentElastic = other.thermalNeutronScatteringLaw_coherentElastic;
         thermalNeutronScatteringLaw_incoherentElastic = other.thermalNeutronScatteringLaw_incoherentElastic;
         thermalNeutronScatteringLaw_incoherentInelastic = other.thermalNeutronScatteringLaw_incoherentInelastic;
      }
      return *this;
   }

   // move
   DoubleDifferentialCrossSection &operator=(DoubleDifferentialCrossSection &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         CoulombPlusNuclearElastic = std::move(other.CoulombPlusNuclearElastic);
         coherentPhotonScattering = std::move(other.coherentPhotonScattering);
         incoherentPhotonScattering = std::move(other.incoherentPhotonScattering);
         thermalNeutronScatteringLaw_coherentElastic = std::move(other.thermalNeutronScatteringLaw_coherentElastic);
         thermalNeutronScatteringLaw_incoherentElastic = std::move(other.thermalNeutronScatteringLaw_incoherentElastic);
         thermalNeutronScatteringLaw_incoherentInelastic = std::move(other.thermalNeutronScatteringLaw_incoherentInelastic);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "gnds/v2.0/general/DoubleDifferentialCrossSection/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class DoubleDifferentialCrossSection

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
