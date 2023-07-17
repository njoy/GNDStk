
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2.0/general/Distribution.hpp"
#include "Distribution.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = DistributionClass;
using CPP = multigroup::Distribution;

static const std::string CLASSNAME = "Distribution";

namespace extract {
   static auto thermalNeutronScatteringLaw = [](auto &obj) { return &obj.thermalNeutronScatteringLaw; };
   static auto uncorrelated = [](auto &obj) { return &obj.uncorrelated; };
   static auto unspecified = [](auto &obj) { return &obj.unspecified; };
   static auto branching3d = [](auto &obj) { return &obj.branching3d; };
   static auto angularTwoBody = [](auto &obj) { return &obj.angularTwoBody; };
   static auto energyAngular = [](auto &obj) { return &obj.energyAngular; };
   static auto KalbachMann = [](auto &obj) { return &obj.KalbachMann; };
   static auto angularEnergy = [](auto &obj) { return &obj.angularEnergy; };
   static auto CoulombPlusNuclearElastic = [](auto &obj) { return &obj.CoulombPlusNuclearElastic; };
   static auto coherentPhotonScattering = [](auto &obj) { return &obj.coherentPhotonScattering; };
   static auto incoherentPhotonScattering = [](auto &obj) { return &obj.incoherentPhotonScattering; };
}

using CPPThermalNeutronScatteringLaw = general::ThermalNeutronScatteringLaw;
using CPPUncorrelated = general::Uncorrelated;
using CPPUnspecified = general::Unspecified;
using CPPBranching3d = general::Branching3d;
using CPPAngularTwoBody = general::AngularTwoBody;
using CPPEnergyAngular = general::EnergyAngular;
using CPPKalbachMann = general::KalbachMann;
using CPPAngularEnergy = general::AngularEnergy;
using CPPCoulombPlusNuclearElastic = general::CoulombPlusNuclearElastic;
using CPPCoherentPhotonScattering = general::CoherentPhotonScattering;
using CPPIncoherentPhotonScattering = general::IncoherentPhotonScattering;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstDistribution
DistributionDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Distribution
DistributionDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstDistribution
DistributionCreateConst(
   ConstHandle2ConstThermalNeutronScatteringLaw thermalNeutronScatteringLaw,
   ConstHandle2ConstUncorrelated uncorrelated,
   ConstHandle2ConstUnspecified unspecified,
   ConstHandle2ConstBranching3d branching3d,
   ConstHandle2ConstAngularTwoBody angularTwoBody,
   ConstHandle2ConstEnergyAngular energyAngular,
   ConstHandle2ConstKalbachMann KalbachMann,
   ConstHandle2ConstAngularEnergy angularEnergy,
   ConstHandle2ConstCoulombPlusNuclearElastic CoulombPlusNuclearElastic,
   ConstHandle2ConstCoherentPhotonScattering coherentPhotonScattering,
   ConstHandle2ConstIncoherentPhotonScattering incoherentPhotonScattering
) {
   ConstHandle2Distribution handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPThermalNeutronScatteringLaw>(thermalNeutronScatteringLaw),
      detail::tocpp<CPPUncorrelated>(uncorrelated),
      detail::tocpp<CPPUnspecified>(unspecified),
      detail::tocpp<CPPBranching3d>(branching3d),
      detail::tocpp<CPPAngularTwoBody>(angularTwoBody),
      detail::tocpp<CPPEnergyAngular>(energyAngular),
      detail::tocpp<CPPKalbachMann>(KalbachMann),
      detail::tocpp<CPPAngularEnergy>(angularEnergy),
      detail::tocpp<CPPCoulombPlusNuclearElastic>(CoulombPlusNuclearElastic),
      detail::tocpp<CPPCoherentPhotonScattering>(coherentPhotonScattering),
      detail::tocpp<CPPIncoherentPhotonScattering>(incoherentPhotonScattering)
   );
   return handle;
}

// Create, general
Handle2Distribution
DistributionCreate(
   ConstHandle2ConstThermalNeutronScatteringLaw thermalNeutronScatteringLaw,
   ConstHandle2ConstUncorrelated uncorrelated,
   ConstHandle2ConstUnspecified unspecified,
   ConstHandle2ConstBranching3d branching3d,
   ConstHandle2ConstAngularTwoBody angularTwoBody,
   ConstHandle2ConstEnergyAngular energyAngular,
   ConstHandle2ConstKalbachMann KalbachMann,
   ConstHandle2ConstAngularEnergy angularEnergy,
   ConstHandle2ConstCoulombPlusNuclearElastic CoulombPlusNuclearElastic,
   ConstHandle2ConstCoherentPhotonScattering coherentPhotonScattering,
   ConstHandle2ConstIncoherentPhotonScattering incoherentPhotonScattering
) {
   ConstHandle2Distribution handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPThermalNeutronScatteringLaw>(thermalNeutronScatteringLaw),
      detail::tocpp<CPPUncorrelated>(uncorrelated),
      detail::tocpp<CPPUnspecified>(unspecified),
      detail::tocpp<CPPBranching3d>(branching3d),
      detail::tocpp<CPPAngularTwoBody>(angularTwoBody),
      detail::tocpp<CPPEnergyAngular>(energyAngular),
      detail::tocpp<CPPKalbachMann>(KalbachMann),
      detail::tocpp<CPPAngularEnergy>(angularEnergy),
      detail::tocpp<CPPCoulombPlusNuclearElastic>(CoulombPlusNuclearElastic),
      detail::tocpp<CPPCoherentPhotonScattering>(coherentPhotonScattering),
      detail::tocpp<CPPIncoherentPhotonScattering>(incoherentPhotonScattering)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
DistributionAssign(ConstHandle2Distribution self, ConstHandle2ConstDistribution from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
DistributionDelete(ConstHandle2ConstDistribution self)
{
   detail::deleteHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Delete", self);
}


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// Read from file
// File can be XML, JSON, or HDF5.
// We'll examine the file's contents to determine its type automatically.
int
DistributionRead(ConstHandle2Distribution self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
DistributionWrite(ConstHandle2ConstDistribution self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
DistributionPrint(ConstHandle2ConstDistribution self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
DistributionPrintXML(ConstHandle2ConstDistribution self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
DistributionPrintJSON(ConstHandle2ConstDistribution self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: thermalNeutronScatteringLaw
// -----------------------------------------------------------------------------

// Has
int
DistributionThermalNeutronScatteringLawHas(ConstHandle2ConstDistribution self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLawHas", self, extract::thermalNeutronScatteringLaw);
}

// Get, const
Handle2ConstThermalNeutronScatteringLaw
DistributionThermalNeutronScatteringLawGetConst(ConstHandle2ConstDistribution self)
{
   return detail::getField<CPP,Handle2ConstThermalNeutronScatteringLaw>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLawGetConst", self, extract::thermalNeutronScatteringLaw);
}

// Get, non-const
Handle2ThermalNeutronScatteringLaw
DistributionThermalNeutronScatteringLawGet(ConstHandle2Distribution self)
{
   return detail::getField<CPP,Handle2ThermalNeutronScatteringLaw>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLawGet", self, extract::thermalNeutronScatteringLaw);
}

// Set
void
DistributionThermalNeutronScatteringLawSet(ConstHandle2Distribution self, ConstHandle2ConstThermalNeutronScatteringLaw thermalNeutronScatteringLaw)
{
   detail::setField<CPP,CPPThermalNeutronScatteringLaw>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLawSet", self, extract::thermalNeutronScatteringLaw, thermalNeutronScatteringLaw);
}


// -----------------------------------------------------------------------------
// Child: uncorrelated
// -----------------------------------------------------------------------------

// Has
int
DistributionUncorrelatedHas(ConstHandle2ConstDistribution self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UncorrelatedHas", self, extract::uncorrelated);
}

// Get, const
Handle2ConstUncorrelated
DistributionUncorrelatedGetConst(ConstHandle2ConstDistribution self)
{
   return detail::getField<CPP,Handle2ConstUncorrelated>
      (CLASSNAME, CLASSNAME+"UncorrelatedGetConst", self, extract::uncorrelated);
}

// Get, non-const
Handle2Uncorrelated
DistributionUncorrelatedGet(ConstHandle2Distribution self)
{
   return detail::getField<CPP,Handle2Uncorrelated>
      (CLASSNAME, CLASSNAME+"UncorrelatedGet", self, extract::uncorrelated);
}

// Set
void
DistributionUncorrelatedSet(ConstHandle2Distribution self, ConstHandle2ConstUncorrelated uncorrelated)
{
   detail::setField<CPP,CPPUncorrelated>
      (CLASSNAME, CLASSNAME+"UncorrelatedSet", self, extract::uncorrelated, uncorrelated);
}


// -----------------------------------------------------------------------------
// Child: unspecified
// -----------------------------------------------------------------------------

// Has
int
DistributionUnspecifiedHas(ConstHandle2ConstDistribution self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UnspecifiedHas", self, extract::unspecified);
}

// Get, const
Handle2ConstUnspecified
DistributionUnspecifiedGetConst(ConstHandle2ConstDistribution self)
{
   return detail::getField<CPP,Handle2ConstUnspecified>
      (CLASSNAME, CLASSNAME+"UnspecifiedGetConst", self, extract::unspecified);
}

// Get, non-const
Handle2Unspecified
DistributionUnspecifiedGet(ConstHandle2Distribution self)
{
   return detail::getField<CPP,Handle2Unspecified>
      (CLASSNAME, CLASSNAME+"UnspecifiedGet", self, extract::unspecified);
}

// Set
void
DistributionUnspecifiedSet(ConstHandle2Distribution self, ConstHandle2ConstUnspecified unspecified)
{
   detail::setField<CPP,CPPUnspecified>
      (CLASSNAME, CLASSNAME+"UnspecifiedSet", self, extract::unspecified, unspecified);
}


// -----------------------------------------------------------------------------
// Child: branching3d
// -----------------------------------------------------------------------------

// Has
int
DistributionBranching3dHas(ConstHandle2ConstDistribution self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Branching3dHas", self, extract::branching3d);
}

// Get, const
Handle2ConstBranching3d
DistributionBranching3dGetConst(ConstHandle2ConstDistribution self)
{
   return detail::getField<CPP,Handle2ConstBranching3d>
      (CLASSNAME, CLASSNAME+"Branching3dGetConst", self, extract::branching3d);
}

// Get, non-const
Handle2Branching3d
DistributionBranching3dGet(ConstHandle2Distribution self)
{
   return detail::getField<CPP,Handle2Branching3d>
      (CLASSNAME, CLASSNAME+"Branching3dGet", self, extract::branching3d);
}

// Set
void
DistributionBranching3dSet(ConstHandle2Distribution self, ConstHandle2ConstBranching3d branching3d)
{
   detail::setField<CPP,CPPBranching3d>
      (CLASSNAME, CLASSNAME+"Branching3dSet", self, extract::branching3d, branching3d);
}


// -----------------------------------------------------------------------------
// Child: angularTwoBody
// -----------------------------------------------------------------------------

// Has
int
DistributionAngularTwoBodyHas(ConstHandle2ConstDistribution self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AngularTwoBodyHas", self, extract::angularTwoBody);
}

// Get, const
Handle2ConstAngularTwoBody
DistributionAngularTwoBodyGetConst(ConstHandle2ConstDistribution self)
{
   return detail::getField<CPP,Handle2ConstAngularTwoBody>
      (CLASSNAME, CLASSNAME+"AngularTwoBodyGetConst", self, extract::angularTwoBody);
}

// Get, non-const
Handle2AngularTwoBody
DistributionAngularTwoBodyGet(ConstHandle2Distribution self)
{
   return detail::getField<CPP,Handle2AngularTwoBody>
      (CLASSNAME, CLASSNAME+"AngularTwoBodyGet", self, extract::angularTwoBody);
}

// Set
void
DistributionAngularTwoBodySet(ConstHandle2Distribution self, ConstHandle2ConstAngularTwoBody angularTwoBody)
{
   detail::setField<CPP,CPPAngularTwoBody>
      (CLASSNAME, CLASSNAME+"AngularTwoBodySet", self, extract::angularTwoBody, angularTwoBody);
}


// -----------------------------------------------------------------------------
// Child: energyAngular
// -----------------------------------------------------------------------------

// Has
int
DistributionEnergyAngularHas(ConstHandle2ConstDistribution self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EnergyAngularHas", self, extract::energyAngular);
}

// Get, const
Handle2ConstEnergyAngular
DistributionEnergyAngularGetConst(ConstHandle2ConstDistribution self)
{
   return detail::getField<CPP,Handle2ConstEnergyAngular>
      (CLASSNAME, CLASSNAME+"EnergyAngularGetConst", self, extract::energyAngular);
}

// Get, non-const
Handle2EnergyAngular
DistributionEnergyAngularGet(ConstHandle2Distribution self)
{
   return detail::getField<CPP,Handle2EnergyAngular>
      (CLASSNAME, CLASSNAME+"EnergyAngularGet", self, extract::energyAngular);
}

// Set
void
DistributionEnergyAngularSet(ConstHandle2Distribution self, ConstHandle2ConstEnergyAngular energyAngular)
{
   detail::setField<CPP,CPPEnergyAngular>
      (CLASSNAME, CLASSNAME+"EnergyAngularSet", self, extract::energyAngular, energyAngular);
}


// -----------------------------------------------------------------------------
// Child: KalbachMann
// -----------------------------------------------------------------------------

// Has
int
DistributionKalbachMannHas(ConstHandle2ConstDistribution self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"KalbachMannHas", self, extract::KalbachMann);
}

// Get, const
Handle2ConstKalbachMann
DistributionKalbachMannGetConst(ConstHandle2ConstDistribution self)
{
   return detail::getField<CPP,Handle2ConstKalbachMann>
      (CLASSNAME, CLASSNAME+"KalbachMannGetConst", self, extract::KalbachMann);
}

// Get, non-const
Handle2KalbachMann
DistributionKalbachMannGet(ConstHandle2Distribution self)
{
   return detail::getField<CPP,Handle2KalbachMann>
      (CLASSNAME, CLASSNAME+"KalbachMannGet", self, extract::KalbachMann);
}

// Set
void
DistributionKalbachMannSet(ConstHandle2Distribution self, ConstHandle2ConstKalbachMann KalbachMann)
{
   detail::setField<CPP,CPPKalbachMann>
      (CLASSNAME, CLASSNAME+"KalbachMannSet", self, extract::KalbachMann, KalbachMann);
}


// -----------------------------------------------------------------------------
// Child: angularEnergy
// -----------------------------------------------------------------------------

// Has
int
DistributionAngularEnergyHas(ConstHandle2ConstDistribution self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AngularEnergyHas", self, extract::angularEnergy);
}

// Get, const
Handle2ConstAngularEnergy
DistributionAngularEnergyGetConst(ConstHandle2ConstDistribution self)
{
   return detail::getField<CPP,Handle2ConstAngularEnergy>
      (CLASSNAME, CLASSNAME+"AngularEnergyGetConst", self, extract::angularEnergy);
}

// Get, non-const
Handle2AngularEnergy
DistributionAngularEnergyGet(ConstHandle2Distribution self)
{
   return detail::getField<CPP,Handle2AngularEnergy>
      (CLASSNAME, CLASSNAME+"AngularEnergyGet", self, extract::angularEnergy);
}

// Set
void
DistributionAngularEnergySet(ConstHandle2Distribution self, ConstHandle2ConstAngularEnergy angularEnergy)
{
   detail::setField<CPP,CPPAngularEnergy>
      (CLASSNAME, CLASSNAME+"AngularEnergySet", self, extract::angularEnergy, angularEnergy);
}


// -----------------------------------------------------------------------------
// Child: CoulombPlusNuclearElastic
// -----------------------------------------------------------------------------

// Has
int
DistributionCoulombPlusNuclearElasticHas(ConstHandle2ConstDistribution self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CoulombPlusNuclearElasticHas", self, extract::CoulombPlusNuclearElastic);
}

// Get, const
Handle2ConstCoulombPlusNuclearElastic
DistributionCoulombPlusNuclearElasticGetConst(ConstHandle2ConstDistribution self)
{
   return detail::getField<CPP,Handle2ConstCoulombPlusNuclearElastic>
      (CLASSNAME, CLASSNAME+"CoulombPlusNuclearElasticGetConst", self, extract::CoulombPlusNuclearElastic);
}

// Get, non-const
Handle2CoulombPlusNuclearElastic
DistributionCoulombPlusNuclearElasticGet(ConstHandle2Distribution self)
{
   return detail::getField<CPP,Handle2CoulombPlusNuclearElastic>
      (CLASSNAME, CLASSNAME+"CoulombPlusNuclearElasticGet", self, extract::CoulombPlusNuclearElastic);
}

// Set
void
DistributionCoulombPlusNuclearElasticSet(ConstHandle2Distribution self, ConstHandle2ConstCoulombPlusNuclearElastic CoulombPlusNuclearElastic)
{
   detail::setField<CPP,CPPCoulombPlusNuclearElastic>
      (CLASSNAME, CLASSNAME+"CoulombPlusNuclearElasticSet", self, extract::CoulombPlusNuclearElastic, CoulombPlusNuclearElastic);
}


// -----------------------------------------------------------------------------
// Child: coherentPhotonScattering
// -----------------------------------------------------------------------------

// Has
int
DistributionCoherentPhotonScatteringHas(ConstHandle2ConstDistribution self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CoherentPhotonScatteringHas", self, extract::coherentPhotonScattering);
}

// Get, const
Handle2ConstCoherentPhotonScattering
DistributionCoherentPhotonScatteringGetConst(ConstHandle2ConstDistribution self)
{
   return detail::getField<CPP,Handle2ConstCoherentPhotonScattering>
      (CLASSNAME, CLASSNAME+"CoherentPhotonScatteringGetConst", self, extract::coherentPhotonScattering);
}

// Get, non-const
Handle2CoherentPhotonScattering
DistributionCoherentPhotonScatteringGet(ConstHandle2Distribution self)
{
   return detail::getField<CPP,Handle2CoherentPhotonScattering>
      (CLASSNAME, CLASSNAME+"CoherentPhotonScatteringGet", self, extract::coherentPhotonScattering);
}

// Set
void
DistributionCoherentPhotonScatteringSet(ConstHandle2Distribution self, ConstHandle2ConstCoherentPhotonScattering coherentPhotonScattering)
{
   detail::setField<CPP,CPPCoherentPhotonScattering>
      (CLASSNAME, CLASSNAME+"CoherentPhotonScatteringSet", self, extract::coherentPhotonScattering, coherentPhotonScattering);
}


// -----------------------------------------------------------------------------
// Child: incoherentPhotonScattering
// -----------------------------------------------------------------------------

// Has
int
DistributionIncoherentPhotonScatteringHas(ConstHandle2ConstDistribution self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"IncoherentPhotonScatteringHas", self, extract::incoherentPhotonScattering);
}

// Get, const
Handle2ConstIncoherentPhotonScattering
DistributionIncoherentPhotonScatteringGetConst(ConstHandle2ConstDistribution self)
{
   return detail::getField<CPP,Handle2ConstIncoherentPhotonScattering>
      (CLASSNAME, CLASSNAME+"IncoherentPhotonScatteringGetConst", self, extract::incoherentPhotonScattering);
}

// Get, non-const
Handle2IncoherentPhotonScattering
DistributionIncoherentPhotonScatteringGet(ConstHandle2Distribution self)
{
   return detail::getField<CPP,Handle2IncoherentPhotonScattering>
      (CLASSNAME, CLASSNAME+"IncoherentPhotonScatteringGet", self, extract::incoherentPhotonScattering);
}

// Set
void
DistributionIncoherentPhotonScatteringSet(ConstHandle2Distribution self, ConstHandle2ConstIncoherentPhotonScattering incoherentPhotonScattering)
{
   detail::setField<CPP,CPPIncoherentPhotonScattering>
      (CLASSNAME, CLASSNAME+"IncoherentPhotonScatteringSet", self, extract::incoherentPhotonScattering, incoherentPhotonScattering);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Distribution/src/custom.cpp"
