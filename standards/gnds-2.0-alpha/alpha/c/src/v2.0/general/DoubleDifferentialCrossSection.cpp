
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/DoubleDifferentialCrossSection.hpp"
#include "DoubleDifferentialCrossSection.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = DoubleDifferentialCrossSectionClass;
using CPP = multigroup::DoubleDifferentialCrossSection;

static const std::string CLASSNAME = "DoubleDifferentialCrossSection";

namespace extract {
   static auto CoulombPlusNuclearElastic = [](auto &obj) { return &obj.CoulombPlusNuclearElastic; };
   static auto coherentPhotonScattering = [](auto &obj) { return &obj.coherentPhotonScattering; };
   static auto incoherentPhotonScattering = [](auto &obj) { return &obj.incoherentPhotonScattering; };
   static auto thermalNeutronScatteringLaw_coherentElastic = [](auto &obj) { return &obj.thermalNeutronScatteringLaw_coherentElastic; };
   static auto thermalNeutronScatteringLaw_incoherentElastic = [](auto &obj) { return &obj.thermalNeutronScatteringLaw_incoherentElastic; };
   static auto thermalNeutronScatteringLaw_incoherentInelastic = [](auto &obj) { return &obj.thermalNeutronScatteringLaw_incoherentInelastic; };
}

using CPPCoulombPlusNuclearElastic = general::CoulombPlusNuclearElastic;
using CPPCoherentPhotonScattering = general::CoherentPhotonScattering;
using CPPIncoherentPhotonScattering = general::IncoherentPhotonScattering;
using CPPThermalNeutronScatteringLaw_coherentElastic = general::ThermalNeutronScatteringLaw_coherentElastic;
using CPPThermalNeutronScatteringLaw_incoherentElastic = general::ThermalNeutronScatteringLaw_incoherentElastic;
using CPPThermalNeutronScatteringLaw_incoherentInelastic = general::ThermalNeutronScatteringLaw_incoherentInelastic;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstDoubleDifferentialCrossSection
DoubleDifferentialCrossSectionDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2DoubleDifferentialCrossSection
DoubleDifferentialCrossSectionDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstDoubleDifferentialCrossSection
DoubleDifferentialCrossSectionCreateConst(
   ConstHandle2ConstCoulombPlusNuclearElastic CoulombPlusNuclearElastic,
   ConstHandle2ConstCoherentPhotonScattering coherentPhotonScattering,
   ConstHandle2ConstIncoherentPhotonScattering incoherentPhotonScattering,
   ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic thermalNeutronScatteringLaw_coherentElastic,
   ConstHandle2ConstThermalNeutronScatteringLaw_incoherentElastic thermalNeutronScatteringLaw_incoherentElastic,
   ConstHandle2ConstThermalNeutronScatteringLaw_incoherentInelastic thermalNeutronScatteringLaw_incoherentInelastic
) {
   ConstHandle2DoubleDifferentialCrossSection handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPCoulombPlusNuclearElastic>(CoulombPlusNuclearElastic),
      detail::tocpp<CPPCoherentPhotonScattering>(coherentPhotonScattering),
      detail::tocpp<CPPIncoherentPhotonScattering>(incoherentPhotonScattering),
      detail::tocpp<CPPThermalNeutronScatteringLaw_coherentElastic>(thermalNeutronScatteringLaw_coherentElastic),
      detail::tocpp<CPPThermalNeutronScatteringLaw_incoherentElastic>(thermalNeutronScatteringLaw_incoherentElastic),
      detail::tocpp<CPPThermalNeutronScatteringLaw_incoherentInelastic>(thermalNeutronScatteringLaw_incoherentInelastic)
   );
   return handle;
}

// Create, general
Handle2DoubleDifferentialCrossSection
DoubleDifferentialCrossSectionCreate(
   ConstHandle2ConstCoulombPlusNuclearElastic CoulombPlusNuclearElastic,
   ConstHandle2ConstCoherentPhotonScattering coherentPhotonScattering,
   ConstHandle2ConstIncoherentPhotonScattering incoherentPhotonScattering,
   ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic thermalNeutronScatteringLaw_coherentElastic,
   ConstHandle2ConstThermalNeutronScatteringLaw_incoherentElastic thermalNeutronScatteringLaw_incoherentElastic,
   ConstHandle2ConstThermalNeutronScatteringLaw_incoherentInelastic thermalNeutronScatteringLaw_incoherentInelastic
) {
   ConstHandle2DoubleDifferentialCrossSection handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPCoulombPlusNuclearElastic>(CoulombPlusNuclearElastic),
      detail::tocpp<CPPCoherentPhotonScattering>(coherentPhotonScattering),
      detail::tocpp<CPPIncoherentPhotonScattering>(incoherentPhotonScattering),
      detail::tocpp<CPPThermalNeutronScatteringLaw_coherentElastic>(thermalNeutronScatteringLaw_coherentElastic),
      detail::tocpp<CPPThermalNeutronScatteringLaw_incoherentElastic>(thermalNeutronScatteringLaw_incoherentElastic),
      detail::tocpp<CPPThermalNeutronScatteringLaw_incoherentInelastic>(thermalNeutronScatteringLaw_incoherentInelastic)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
DoubleDifferentialCrossSectionAssign(ConstHandle2DoubleDifferentialCrossSection self, ConstHandle2ConstDoubleDifferentialCrossSection from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
DoubleDifferentialCrossSectionDelete(ConstHandle2ConstDoubleDifferentialCrossSection self)
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
DoubleDifferentialCrossSectionRead(ConstHandle2DoubleDifferentialCrossSection self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
DoubleDifferentialCrossSectionWrite(ConstHandle2ConstDoubleDifferentialCrossSection self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
DoubleDifferentialCrossSectionPrint(ConstHandle2ConstDoubleDifferentialCrossSection self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
DoubleDifferentialCrossSectionPrintXML(ConstHandle2ConstDoubleDifferentialCrossSection self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
DoubleDifferentialCrossSectionPrintJSON(ConstHandle2ConstDoubleDifferentialCrossSection self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: CoulombPlusNuclearElastic
// -----------------------------------------------------------------------------

// Has
int
DoubleDifferentialCrossSectionCoulombPlusNuclearElasticHas(ConstHandle2ConstDoubleDifferentialCrossSection self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CoulombPlusNuclearElasticHas", self, extract::CoulombPlusNuclearElastic);
}

// Get, const
Handle2ConstCoulombPlusNuclearElastic
DoubleDifferentialCrossSectionCoulombPlusNuclearElasticGetConst(ConstHandle2ConstDoubleDifferentialCrossSection self)
{
   return detail::getField<CPP,Handle2ConstCoulombPlusNuclearElastic>
      (CLASSNAME, CLASSNAME+"CoulombPlusNuclearElasticGetConst", self, extract::CoulombPlusNuclearElastic);
}

// Get, non-const
Handle2CoulombPlusNuclearElastic
DoubleDifferentialCrossSectionCoulombPlusNuclearElasticGet(ConstHandle2DoubleDifferentialCrossSection self)
{
   return detail::getField<CPP,Handle2CoulombPlusNuclearElastic>
      (CLASSNAME, CLASSNAME+"CoulombPlusNuclearElasticGet", self, extract::CoulombPlusNuclearElastic);
}

// Set
void
DoubleDifferentialCrossSectionCoulombPlusNuclearElasticSet(ConstHandle2DoubleDifferentialCrossSection self, ConstHandle2ConstCoulombPlusNuclearElastic CoulombPlusNuclearElastic)
{
   detail::setField<CPP,CPPCoulombPlusNuclearElastic>
      (CLASSNAME, CLASSNAME+"CoulombPlusNuclearElasticSet", self, extract::CoulombPlusNuclearElastic, CoulombPlusNuclearElastic);
}


// -----------------------------------------------------------------------------
// Child: coherentPhotonScattering
// -----------------------------------------------------------------------------

// Has
int
DoubleDifferentialCrossSectionCoherentPhotonScatteringHas(ConstHandle2ConstDoubleDifferentialCrossSection self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CoherentPhotonScatteringHas", self, extract::coherentPhotonScattering);
}

// Get, const
Handle2ConstCoherentPhotonScattering
DoubleDifferentialCrossSectionCoherentPhotonScatteringGetConst(ConstHandle2ConstDoubleDifferentialCrossSection self)
{
   return detail::getField<CPP,Handle2ConstCoherentPhotonScattering>
      (CLASSNAME, CLASSNAME+"CoherentPhotonScatteringGetConst", self, extract::coherentPhotonScattering);
}

// Get, non-const
Handle2CoherentPhotonScattering
DoubleDifferentialCrossSectionCoherentPhotonScatteringGet(ConstHandle2DoubleDifferentialCrossSection self)
{
   return detail::getField<CPP,Handle2CoherentPhotonScattering>
      (CLASSNAME, CLASSNAME+"CoherentPhotonScatteringGet", self, extract::coherentPhotonScattering);
}

// Set
void
DoubleDifferentialCrossSectionCoherentPhotonScatteringSet(ConstHandle2DoubleDifferentialCrossSection self, ConstHandle2ConstCoherentPhotonScattering coherentPhotonScattering)
{
   detail::setField<CPP,CPPCoherentPhotonScattering>
      (CLASSNAME, CLASSNAME+"CoherentPhotonScatteringSet", self, extract::coherentPhotonScattering, coherentPhotonScattering);
}


// -----------------------------------------------------------------------------
// Child: incoherentPhotonScattering
// -----------------------------------------------------------------------------

// Has
int
DoubleDifferentialCrossSectionIncoherentPhotonScatteringHas(ConstHandle2ConstDoubleDifferentialCrossSection self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"IncoherentPhotonScatteringHas", self, extract::incoherentPhotonScattering);
}

// Get, const
Handle2ConstIncoherentPhotonScattering
DoubleDifferentialCrossSectionIncoherentPhotonScatteringGetConst(ConstHandle2ConstDoubleDifferentialCrossSection self)
{
   return detail::getField<CPP,Handle2ConstIncoherentPhotonScattering>
      (CLASSNAME, CLASSNAME+"IncoherentPhotonScatteringGetConst", self, extract::incoherentPhotonScattering);
}

// Get, non-const
Handle2IncoherentPhotonScattering
DoubleDifferentialCrossSectionIncoherentPhotonScatteringGet(ConstHandle2DoubleDifferentialCrossSection self)
{
   return detail::getField<CPP,Handle2IncoherentPhotonScattering>
      (CLASSNAME, CLASSNAME+"IncoherentPhotonScatteringGet", self, extract::incoherentPhotonScattering);
}

// Set
void
DoubleDifferentialCrossSectionIncoherentPhotonScatteringSet(ConstHandle2DoubleDifferentialCrossSection self, ConstHandle2ConstIncoherentPhotonScattering incoherentPhotonScattering)
{
   detail::setField<CPP,CPPIncoherentPhotonScattering>
      (CLASSNAME, CLASSNAME+"IncoherentPhotonScatteringSet", self, extract::incoherentPhotonScattering, incoherentPhotonScattering);
}


// -----------------------------------------------------------------------------
// Child: thermalNeutronScatteringLaw_coherentElastic
// -----------------------------------------------------------------------------

// Has
int
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_coherentElasticHas(ConstHandle2ConstDoubleDifferentialCrossSection self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLaw_coherentElasticHas", self, extract::thermalNeutronScatteringLaw_coherentElastic);
}

// Get, const
Handle2ConstThermalNeutronScatteringLaw_coherentElastic
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_coherentElasticGetConst(ConstHandle2ConstDoubleDifferentialCrossSection self)
{
   return detail::getField<CPP,Handle2ConstThermalNeutronScatteringLaw_coherentElastic>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLaw_coherentElasticGetConst", self, extract::thermalNeutronScatteringLaw_coherentElastic);
}

// Get, non-const
Handle2ThermalNeutronScatteringLaw_coherentElastic
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_coherentElasticGet(ConstHandle2DoubleDifferentialCrossSection self)
{
   return detail::getField<CPP,Handle2ThermalNeutronScatteringLaw_coherentElastic>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLaw_coherentElasticGet", self, extract::thermalNeutronScatteringLaw_coherentElastic);
}

// Set
void
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_coherentElasticSet(ConstHandle2DoubleDifferentialCrossSection self, ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic thermalNeutronScatteringLaw_coherentElastic)
{
   detail::setField<CPP,CPPThermalNeutronScatteringLaw_coherentElastic>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLaw_coherentElasticSet", self, extract::thermalNeutronScatteringLaw_coherentElastic, thermalNeutronScatteringLaw_coherentElastic);
}


// -----------------------------------------------------------------------------
// Child: thermalNeutronScatteringLaw_incoherentElastic
// -----------------------------------------------------------------------------

// Has
int
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_incoherentElasticHas(ConstHandle2ConstDoubleDifferentialCrossSection self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLaw_incoherentElasticHas", self, extract::thermalNeutronScatteringLaw_incoherentElastic);
}

// Get, const
Handle2ConstThermalNeutronScatteringLaw_incoherentElastic
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_incoherentElasticGetConst(ConstHandle2ConstDoubleDifferentialCrossSection self)
{
   return detail::getField<CPP,Handle2ConstThermalNeutronScatteringLaw_incoherentElastic>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLaw_incoherentElasticGetConst", self, extract::thermalNeutronScatteringLaw_incoherentElastic);
}

// Get, non-const
Handle2ThermalNeutronScatteringLaw_incoherentElastic
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_incoherentElasticGet(ConstHandle2DoubleDifferentialCrossSection self)
{
   return detail::getField<CPP,Handle2ThermalNeutronScatteringLaw_incoherentElastic>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLaw_incoherentElasticGet", self, extract::thermalNeutronScatteringLaw_incoherentElastic);
}

// Set
void
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_incoherentElasticSet(ConstHandle2DoubleDifferentialCrossSection self, ConstHandle2ConstThermalNeutronScatteringLaw_incoherentElastic thermalNeutronScatteringLaw_incoherentElastic)
{
   detail::setField<CPP,CPPThermalNeutronScatteringLaw_incoherentElastic>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLaw_incoherentElasticSet", self, extract::thermalNeutronScatteringLaw_incoherentElastic, thermalNeutronScatteringLaw_incoherentElastic);
}


// -----------------------------------------------------------------------------
// Child: thermalNeutronScatteringLaw_incoherentInelastic
// -----------------------------------------------------------------------------

// Has
int
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_incoherentInelasticHas(ConstHandle2ConstDoubleDifferentialCrossSection self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLaw_incoherentInelasticHas", self, extract::thermalNeutronScatteringLaw_incoherentInelastic);
}

// Get, const
Handle2ConstThermalNeutronScatteringLaw_incoherentInelastic
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_incoherentInelasticGetConst(ConstHandle2ConstDoubleDifferentialCrossSection self)
{
   return detail::getField<CPP,Handle2ConstThermalNeutronScatteringLaw_incoherentInelastic>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLaw_incoherentInelasticGetConst", self, extract::thermalNeutronScatteringLaw_incoherentInelastic);
}

// Get, non-const
Handle2ThermalNeutronScatteringLaw_incoherentInelastic
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_incoherentInelasticGet(ConstHandle2DoubleDifferentialCrossSection self)
{
   return detail::getField<CPP,Handle2ThermalNeutronScatteringLaw_incoherentInelastic>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLaw_incoherentInelasticGet", self, extract::thermalNeutronScatteringLaw_incoherentInelastic);
}

// Set
void
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_incoherentInelasticSet(ConstHandle2DoubleDifferentialCrossSection self, ConstHandle2ConstThermalNeutronScatteringLaw_incoherentInelastic thermalNeutronScatteringLaw_incoherentInelastic)
{
   detail::setField<CPP,CPPThermalNeutronScatteringLaw_incoherentInelastic>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLaw_incoherentInelasticSet", self, extract::thermalNeutronScatteringLaw_incoherentInelastic, thermalNeutronScatteringLaw_incoherentInelastic);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/DoubleDifferentialCrossSection/src/custom.cpp"
