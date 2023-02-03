
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/Distribution.hpp"
#include "Distribution.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = DistributionClass;
using CPP = multigroup::Distribution;

static const std::string CLASSNAME = "Distribution";

namespace extract {
   static auto angularTwoBody = [](auto &obj) { return &obj.angularTwoBody; };
   static auto uncorrelated = [](auto &obj) { return &obj.uncorrelated; };
   static auto unspecified = [](auto &obj) { return &obj.unspecified; };
   static auto energyAngular = [](auto &obj) { return &obj.energyAngular; };
   static auto KalbachMann = [](auto &obj) { return &obj.KalbachMann; };
   static auto angularEnergy = [](auto &obj) { return &obj.angularEnergy; };
   static auto branching3d = [](auto &obj) { return &obj.branching3d; };
   static auto CoulombPlusNuclearElastic = [](auto &obj) { return &obj.CoulombPlusNuclearElastic; };
   static auto coherentPhotonScattering = [](auto &obj) { return &obj.coherentPhotonScattering; };
   static auto incoherentPhotonScattering = [](auto &obj) { return &obj.incoherentPhotonScattering; };
   static auto thermalNeutronScatteringLaw = [](auto &obj) { return &obj.thermalNeutronScatteringLaw; };
}

using CPPAngularTwoBody = general::AngularTwoBody;
using CPPUncorrelated = general::Uncorrelated;
using CPPUnspecified = general::Unspecified;
using CPPEnergyAngular = general::EnergyAngular;
using CPPKalbachMann = general::KalbachMann;
using CPPAngularEnergy = general::AngularEnergy;
using CPPBranching3d = general::Branching3d;
using CPPCoulombPlusNuclearElastic = general::CoulombPlusNuclearElastic;
using CPPCoherentPhotonScattering = general::CoherentPhotonScattering;
using CPPIncoherentPhotonScattering = general::IncoherentPhotonScattering;
using CPPThermalNeutronScatteringLaw = general::ThermalNeutronScatteringLaw;


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
   ConstHandle2ConstAngularTwoBody angularTwoBody,
   ConstHandle2ConstUncorrelated uncorrelated,
   ConstHandle2ConstUnspecified unspecified,
   ConstHandle2ConstEnergyAngular energyAngular,
   ConstHandle2ConstKalbachMann KalbachMann,
   ConstHandle2ConstAngularEnergy angularEnergy,
   ConstHandle2ConstBranching3d branching3d,
   ConstHandle2ConstCoulombPlusNuclearElastic CoulombPlusNuclearElastic,
   ConstHandle2ConstCoherentPhotonScattering coherentPhotonScattering,
   ConstHandle2ConstIncoherentPhotonScattering incoherentPhotonScattering,
   ConstHandle2ConstThermalNeutronScatteringLaw thermalNeutronScatteringLaw
) {
   ConstHandle2Distribution handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPAngularTwoBody>(angularTwoBody),
      detail::tocpp<CPPUncorrelated>(uncorrelated),
      detail::tocpp<CPPUnspecified>(unspecified),
      detail::tocpp<CPPEnergyAngular>(energyAngular),
      detail::tocpp<CPPKalbachMann>(KalbachMann),
      detail::tocpp<CPPAngularEnergy>(angularEnergy),
      detail::tocpp<CPPBranching3d>(branching3d),
      detail::tocpp<CPPCoulombPlusNuclearElastic>(CoulombPlusNuclearElastic),
      detail::tocpp<CPPCoherentPhotonScattering>(coherentPhotonScattering),
      detail::tocpp<CPPIncoherentPhotonScattering>(incoherentPhotonScattering),
      detail::tocpp<CPPThermalNeutronScatteringLaw>(thermalNeutronScatteringLaw)
   );
   return handle;
}

// Create, general
Handle2Distribution
DistributionCreate(
   ConstHandle2ConstAngularTwoBody angularTwoBody,
   ConstHandle2ConstUncorrelated uncorrelated,
   ConstHandle2ConstUnspecified unspecified,
   ConstHandle2ConstEnergyAngular energyAngular,
   ConstHandle2ConstKalbachMann KalbachMann,
   ConstHandle2ConstAngularEnergy angularEnergy,
   ConstHandle2ConstBranching3d branching3d,
   ConstHandle2ConstCoulombPlusNuclearElastic CoulombPlusNuclearElastic,
   ConstHandle2ConstCoherentPhotonScattering coherentPhotonScattering,
   ConstHandle2ConstIncoherentPhotonScattering incoherentPhotonScattering,
   ConstHandle2ConstThermalNeutronScatteringLaw thermalNeutronScatteringLaw
) {
   ConstHandle2Distribution handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPAngularTwoBody>(angularTwoBody),
      detail::tocpp<CPPUncorrelated>(uncorrelated),
      detail::tocpp<CPPUnspecified>(unspecified),
      detail::tocpp<CPPEnergyAngular>(energyAngular),
      detail::tocpp<CPPKalbachMann>(KalbachMann),
      detail::tocpp<CPPAngularEnergy>(angularEnergy),
      detail::tocpp<CPPBranching3d>(branching3d),
      detail::tocpp<CPPCoulombPlusNuclearElastic>(CoulombPlusNuclearElastic),
      detail::tocpp<CPPCoherentPhotonScattering>(coherentPhotonScattering),
      detail::tocpp<CPPIncoherentPhotonScattering>(incoherentPhotonScattering),
      detail::tocpp<CPPThermalNeutronScatteringLaw>(thermalNeutronScatteringLaw)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
DistributionAssign(ConstHandle2Distribution This, ConstHandle2ConstDistribution from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
DistributionDelete(ConstHandle2ConstDistribution This)
{
   detail::deleteHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Delete", This);
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
DistributionRead(ConstHandle2Distribution This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
DistributionWrite(ConstHandle2ConstDistribution This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
DistributionPrint(ConstHandle2ConstDistribution This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
DistributionPrintXML(ConstHandle2ConstDistribution This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
DistributionPrintJSON(ConstHandle2ConstDistribution This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: angularTwoBody
// -----------------------------------------------------------------------------

// Has
int
DistributionAngularTwoBodyHas(ConstHandle2ConstDistribution This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AngularTwoBodyHas", This, extract::angularTwoBody);
}

// Get, const
Handle2ConstAngularTwoBody
DistributionAngularTwoBodyGetConst(ConstHandle2ConstDistribution This)
{
   return detail::getField<CPP,Handle2ConstAngularTwoBody>
      (CLASSNAME, CLASSNAME+"AngularTwoBodyGetConst", This, extract::angularTwoBody);
}

// Get, non-const
Handle2AngularTwoBody
DistributionAngularTwoBodyGet(ConstHandle2Distribution This)
{
   return detail::getField<CPP,Handle2AngularTwoBody>
      (CLASSNAME, CLASSNAME+"AngularTwoBodyGet", This, extract::angularTwoBody);
}

// Set
void
DistributionAngularTwoBodySet(ConstHandle2Distribution This, ConstHandle2ConstAngularTwoBody angularTwoBody)
{
   detail::setField<CPP,CPPAngularTwoBody>
      (CLASSNAME, CLASSNAME+"AngularTwoBodySet", This, extract::angularTwoBody, angularTwoBody);
}


// -----------------------------------------------------------------------------
// Child: uncorrelated
// -----------------------------------------------------------------------------

// Has
int
DistributionUncorrelatedHas(ConstHandle2ConstDistribution This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UncorrelatedHas", This, extract::uncorrelated);
}

// Get, const
Handle2ConstUncorrelated
DistributionUncorrelatedGetConst(ConstHandle2ConstDistribution This)
{
   return detail::getField<CPP,Handle2ConstUncorrelated>
      (CLASSNAME, CLASSNAME+"UncorrelatedGetConst", This, extract::uncorrelated);
}

// Get, non-const
Handle2Uncorrelated
DistributionUncorrelatedGet(ConstHandle2Distribution This)
{
   return detail::getField<CPP,Handle2Uncorrelated>
      (CLASSNAME, CLASSNAME+"UncorrelatedGet", This, extract::uncorrelated);
}

// Set
void
DistributionUncorrelatedSet(ConstHandle2Distribution This, ConstHandle2ConstUncorrelated uncorrelated)
{
   detail::setField<CPP,CPPUncorrelated>
      (CLASSNAME, CLASSNAME+"UncorrelatedSet", This, extract::uncorrelated, uncorrelated);
}


// -----------------------------------------------------------------------------
// Child: unspecified
// -----------------------------------------------------------------------------

// Has
int
DistributionUnspecifiedHas(ConstHandle2ConstDistribution This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UnspecifiedHas", This, extract::unspecified);
}

// Get, const
Handle2ConstUnspecified
DistributionUnspecifiedGetConst(ConstHandle2ConstDistribution This)
{
   return detail::getField<CPP,Handle2ConstUnspecified>
      (CLASSNAME, CLASSNAME+"UnspecifiedGetConst", This, extract::unspecified);
}

// Get, non-const
Handle2Unspecified
DistributionUnspecifiedGet(ConstHandle2Distribution This)
{
   return detail::getField<CPP,Handle2Unspecified>
      (CLASSNAME, CLASSNAME+"UnspecifiedGet", This, extract::unspecified);
}

// Set
void
DistributionUnspecifiedSet(ConstHandle2Distribution This, ConstHandle2ConstUnspecified unspecified)
{
   detail::setField<CPP,CPPUnspecified>
      (CLASSNAME, CLASSNAME+"UnspecifiedSet", This, extract::unspecified, unspecified);
}


// -----------------------------------------------------------------------------
// Child: energyAngular
// -----------------------------------------------------------------------------

// Has
int
DistributionEnergyAngularHas(ConstHandle2ConstDistribution This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EnergyAngularHas", This, extract::energyAngular);
}

// Get, const
Handle2ConstEnergyAngular
DistributionEnergyAngularGetConst(ConstHandle2ConstDistribution This)
{
   return detail::getField<CPP,Handle2ConstEnergyAngular>
      (CLASSNAME, CLASSNAME+"EnergyAngularGetConst", This, extract::energyAngular);
}

// Get, non-const
Handle2EnergyAngular
DistributionEnergyAngularGet(ConstHandle2Distribution This)
{
   return detail::getField<CPP,Handle2EnergyAngular>
      (CLASSNAME, CLASSNAME+"EnergyAngularGet", This, extract::energyAngular);
}

// Set
void
DistributionEnergyAngularSet(ConstHandle2Distribution This, ConstHandle2ConstEnergyAngular energyAngular)
{
   detail::setField<CPP,CPPEnergyAngular>
      (CLASSNAME, CLASSNAME+"EnergyAngularSet", This, extract::energyAngular, energyAngular);
}


// -----------------------------------------------------------------------------
// Child: KalbachMann
// -----------------------------------------------------------------------------

// Has
int
DistributionKalbachMannHas(ConstHandle2ConstDistribution This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"KalbachMannHas", This, extract::KalbachMann);
}

// Get, const
Handle2ConstKalbachMann
DistributionKalbachMannGetConst(ConstHandle2ConstDistribution This)
{
   return detail::getField<CPP,Handle2ConstKalbachMann>
      (CLASSNAME, CLASSNAME+"KalbachMannGetConst", This, extract::KalbachMann);
}

// Get, non-const
Handle2KalbachMann
DistributionKalbachMannGet(ConstHandle2Distribution This)
{
   return detail::getField<CPP,Handle2KalbachMann>
      (CLASSNAME, CLASSNAME+"KalbachMannGet", This, extract::KalbachMann);
}

// Set
void
DistributionKalbachMannSet(ConstHandle2Distribution This, ConstHandle2ConstKalbachMann KalbachMann)
{
   detail::setField<CPP,CPPKalbachMann>
      (CLASSNAME, CLASSNAME+"KalbachMannSet", This, extract::KalbachMann, KalbachMann);
}


// -----------------------------------------------------------------------------
// Child: angularEnergy
// -----------------------------------------------------------------------------

// Has
int
DistributionAngularEnergyHas(ConstHandle2ConstDistribution This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AngularEnergyHas", This, extract::angularEnergy);
}

// Get, const
Handle2ConstAngularEnergy
DistributionAngularEnergyGetConst(ConstHandle2ConstDistribution This)
{
   return detail::getField<CPP,Handle2ConstAngularEnergy>
      (CLASSNAME, CLASSNAME+"AngularEnergyGetConst", This, extract::angularEnergy);
}

// Get, non-const
Handle2AngularEnergy
DistributionAngularEnergyGet(ConstHandle2Distribution This)
{
   return detail::getField<CPP,Handle2AngularEnergy>
      (CLASSNAME, CLASSNAME+"AngularEnergyGet", This, extract::angularEnergy);
}

// Set
void
DistributionAngularEnergySet(ConstHandle2Distribution This, ConstHandle2ConstAngularEnergy angularEnergy)
{
   detail::setField<CPP,CPPAngularEnergy>
      (CLASSNAME, CLASSNAME+"AngularEnergySet", This, extract::angularEnergy, angularEnergy);
}


// -----------------------------------------------------------------------------
// Child: branching3d
// -----------------------------------------------------------------------------

// Has
int
DistributionBranching3dHas(ConstHandle2ConstDistribution This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Branching3dHas", This, extract::branching3d);
}

// Get, const
Handle2ConstBranching3d
DistributionBranching3dGetConst(ConstHandle2ConstDistribution This)
{
   return detail::getField<CPP,Handle2ConstBranching3d>
      (CLASSNAME, CLASSNAME+"Branching3dGetConst", This, extract::branching3d);
}

// Get, non-const
Handle2Branching3d
DistributionBranching3dGet(ConstHandle2Distribution This)
{
   return detail::getField<CPP,Handle2Branching3d>
      (CLASSNAME, CLASSNAME+"Branching3dGet", This, extract::branching3d);
}

// Set
void
DistributionBranching3dSet(ConstHandle2Distribution This, ConstHandle2ConstBranching3d branching3d)
{
   detail::setField<CPP,CPPBranching3d>
      (CLASSNAME, CLASSNAME+"Branching3dSet", This, extract::branching3d, branching3d);
}


// -----------------------------------------------------------------------------
// Child: CoulombPlusNuclearElastic
// -----------------------------------------------------------------------------

// Has
int
DistributionCoulombPlusNuclearElasticHas(ConstHandle2ConstDistribution This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CoulombPlusNuclearElasticHas", This, extract::CoulombPlusNuclearElastic);
}

// Get, const
Handle2ConstCoulombPlusNuclearElastic
DistributionCoulombPlusNuclearElasticGetConst(ConstHandle2ConstDistribution This)
{
   return detail::getField<CPP,Handle2ConstCoulombPlusNuclearElastic>
      (CLASSNAME, CLASSNAME+"CoulombPlusNuclearElasticGetConst", This, extract::CoulombPlusNuclearElastic);
}

// Get, non-const
Handle2CoulombPlusNuclearElastic
DistributionCoulombPlusNuclearElasticGet(ConstHandle2Distribution This)
{
   return detail::getField<CPP,Handle2CoulombPlusNuclearElastic>
      (CLASSNAME, CLASSNAME+"CoulombPlusNuclearElasticGet", This, extract::CoulombPlusNuclearElastic);
}

// Set
void
DistributionCoulombPlusNuclearElasticSet(ConstHandle2Distribution This, ConstHandle2ConstCoulombPlusNuclearElastic CoulombPlusNuclearElastic)
{
   detail::setField<CPP,CPPCoulombPlusNuclearElastic>
      (CLASSNAME, CLASSNAME+"CoulombPlusNuclearElasticSet", This, extract::CoulombPlusNuclearElastic, CoulombPlusNuclearElastic);
}


// -----------------------------------------------------------------------------
// Child: coherentPhotonScattering
// -----------------------------------------------------------------------------

// Has
int
DistributionCoherentPhotonScatteringHas(ConstHandle2ConstDistribution This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CoherentPhotonScatteringHas", This, extract::coherentPhotonScattering);
}

// Get, const
Handle2ConstCoherentPhotonScattering
DistributionCoherentPhotonScatteringGetConst(ConstHandle2ConstDistribution This)
{
   return detail::getField<CPP,Handle2ConstCoherentPhotonScattering>
      (CLASSNAME, CLASSNAME+"CoherentPhotonScatteringGetConst", This, extract::coherentPhotonScattering);
}

// Get, non-const
Handle2CoherentPhotonScattering
DistributionCoherentPhotonScatteringGet(ConstHandle2Distribution This)
{
   return detail::getField<CPP,Handle2CoherentPhotonScattering>
      (CLASSNAME, CLASSNAME+"CoherentPhotonScatteringGet", This, extract::coherentPhotonScattering);
}

// Set
void
DistributionCoherentPhotonScatteringSet(ConstHandle2Distribution This, ConstHandle2ConstCoherentPhotonScattering coherentPhotonScattering)
{
   detail::setField<CPP,CPPCoherentPhotonScattering>
      (CLASSNAME, CLASSNAME+"CoherentPhotonScatteringSet", This, extract::coherentPhotonScattering, coherentPhotonScattering);
}


// -----------------------------------------------------------------------------
// Child: incoherentPhotonScattering
// -----------------------------------------------------------------------------

// Has
int
DistributionIncoherentPhotonScatteringHas(ConstHandle2ConstDistribution This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"IncoherentPhotonScatteringHas", This, extract::incoherentPhotonScattering);
}

// Get, const
Handle2ConstIncoherentPhotonScattering
DistributionIncoherentPhotonScatteringGetConst(ConstHandle2ConstDistribution This)
{
   return detail::getField<CPP,Handle2ConstIncoherentPhotonScattering>
      (CLASSNAME, CLASSNAME+"IncoherentPhotonScatteringGetConst", This, extract::incoherentPhotonScattering);
}

// Get, non-const
Handle2IncoherentPhotonScattering
DistributionIncoherentPhotonScatteringGet(ConstHandle2Distribution This)
{
   return detail::getField<CPP,Handle2IncoherentPhotonScattering>
      (CLASSNAME, CLASSNAME+"IncoherentPhotonScatteringGet", This, extract::incoherentPhotonScattering);
}

// Set
void
DistributionIncoherentPhotonScatteringSet(ConstHandle2Distribution This, ConstHandle2ConstIncoherentPhotonScattering incoherentPhotonScattering)
{
   detail::setField<CPP,CPPIncoherentPhotonScattering>
      (CLASSNAME, CLASSNAME+"IncoherentPhotonScatteringSet", This, extract::incoherentPhotonScattering, incoherentPhotonScattering);
}


// -----------------------------------------------------------------------------
// Child: thermalNeutronScatteringLaw
// -----------------------------------------------------------------------------

// Has
int
DistributionThermalNeutronScatteringLawHas(ConstHandle2ConstDistribution This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLawHas", This, extract::thermalNeutronScatteringLaw);
}

// Get, const
Handle2ConstThermalNeutronScatteringLaw
DistributionThermalNeutronScatteringLawGetConst(ConstHandle2ConstDistribution This)
{
   return detail::getField<CPP,Handle2ConstThermalNeutronScatteringLaw>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLawGetConst", This, extract::thermalNeutronScatteringLaw);
}

// Get, non-const
Handle2ThermalNeutronScatteringLaw
DistributionThermalNeutronScatteringLawGet(ConstHandle2Distribution This)
{
   return detail::getField<CPP,Handle2ThermalNeutronScatteringLaw>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLawGet", This, extract::thermalNeutronScatteringLaw);
}

// Set
void
DistributionThermalNeutronScatteringLawSet(ConstHandle2Distribution This, ConstHandle2ConstThermalNeutronScatteringLaw thermalNeutronScatteringLaw)
{
   detail::setField<CPP,CPPThermalNeutronScatteringLaw>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLawSet", This, extract::thermalNeutronScatteringLaw, thermalNeutronScatteringLaw);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Distribution/src/custom.cpp"
