
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_TRANSPORT_DISTRIBUTION
#define TEST_V2_0_TRANSPORT_DISTRIBUTION

#include "test/v2.0/transport/AngularTwoBody.hpp"
#include "test/v2.0/transport/Uncorrelated.hpp"
#include "test/v2.0/transport/AngularEnergy.hpp"
#include "test/v2.0/transport/EnergyAngular.hpp"
#include "test/v2.0/transport/KalbachMann.hpp"
#include "test/v2.0/transport/Reference.hpp"
#include "test/v2.0/transport/Branching3d.hpp"
#include "test/v2.0/cpTransport/CoulombPlusNuclearElastic.hpp"
#include "test/v2.0/tsl/ThermalNeutronScatteringLaw.hpp"
#include "test/v2.0/atomic/CoherentPhotonScattering.hpp"
#include "test/v2.0/atomic/IncoherentPhotonScattering.hpp"
#include "test/v2.0/transport/Unspecified.hpp"
#include "test/v2.0/transport/MultiGroup3d.hpp"
#include "test/v2.0/processed/AngularEnergyMC.hpp"
#include "test/v2.0/processed/EnergyAngularMC.hpp"

namespace test {
namespace v2_0 {
namespace transport {

// -----------------------------------------------------------------------------
// transport::
// class Distribution
// -----------------------------------------------------------------------------

class Distribution : public Component<transport::Distribution> {
   friend class Component;

   using _t = std::variant<
      transport::AngularTwoBody,
      transport::Uncorrelated,
      transport::AngularEnergy,
      transport::EnergyAngular,
      transport::KalbachMann,
      transport::Reference,
      transport::Branching3d,
      cpTransport::CoulombPlusNuclearElastic,
      tsl::ThermalNeutronScatteringLaw,
      atomic::CoherentPhotonScattering,
      atomic::IncoherentPhotonScattering,
      transport::Unspecified,
      transport::MultiGroup3d,
      processed::AngularEnergyMC,
      processed::EnergyAngularMC
   >;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "transport"; }
   static auto CLASS() { return "Distribution"; }
   static auto FIELD() { return "distribution"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         _t{}
            / --(Child<>("angularTwoBody") || Child<>("uncorrelated") || Child<>("angularEnergy") || Child<>("energyAngular") || Child<>("KalbachMann") || Child<>("reference") || Child<>("branching3d") || Child<>("CoulombPlusNuclearElastic") || Child<>("thermalNeutronScatteringLaw") || Child<>("coherentPhotonScattering") || Child<>("incoherentPhotonScattering") || Child<>("unspecified") || Child<>("multiGroup3d") || Child<>("angularEnergyMC") || Child<>("energyAngularMC"))
      ;
   }

public:
   using Component::construct;

   // children - variant
   Field<_t> _angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC{this};
   FieldPart<decltype(_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC),transport::AngularTwoBody> angularTwoBody{_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC};
   FieldPart<decltype(_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC),transport::Uncorrelated> uncorrelated{_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC};
   FieldPart<decltype(_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC),transport::AngularEnergy> angularEnergy{_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC};
   FieldPart<decltype(_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC),transport::EnergyAngular> energyAngular{_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC};
   FieldPart<decltype(_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC),transport::KalbachMann> KalbachMann{_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC};
   FieldPart<decltype(_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC),transport::Reference> reference{_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC};
   FieldPart<decltype(_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC),transport::Branching3d> branching3d{_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC};
   FieldPart<decltype(_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC),cpTransport::CoulombPlusNuclearElastic> CoulombPlusNuclearElastic{_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC};
   FieldPart<decltype(_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC),tsl::ThermalNeutronScatteringLaw> thermalNeutronScatteringLaw{_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC};
   FieldPart<decltype(_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC),atomic::CoherentPhotonScattering> coherentPhotonScattering{_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC};
   FieldPart<decltype(_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC),atomic::IncoherentPhotonScattering> incoherentPhotonScattering{_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC};
   FieldPart<decltype(_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC),transport::Unspecified> unspecified{_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC};
   FieldPart<decltype(_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC),transport::MultiGroup3d> multiGroup3d{_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC};
   FieldPart<decltype(_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC),processed::AngularEnergyMC> angularEnergyMC{_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC};
   FieldPart<decltype(_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC),processed::EnergyAngularMC> energyAngularMC{_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC)

   // default, and from fields
   explicit Distribution(
      const wrapper<_t> &_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      _angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC(this,_angularTwoBodyuncorrelatedangularEnergyenergyAngularKalbachMannreferencebranching3dCoulombPlusNuclearElasticthermalNeutronScatteringLawcoherentPhotonScatteringincoherentPhotonScatteringunspecifiedmultiGroup3dangularEnergyMCenergyAngularMC)
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
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Distribution(Distribution &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
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

   #include "test/v2.0/transport/Distribution/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Distribution

} // namespace transport
} // namespace v2_0
} // namespace test

#endif