
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/transport/DoubleDifferentialCrossSection.hpp"
#include "DoubleDifferentialCrossSection.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = DoubleDifferentialCrossSectionClass;
using CPP = multigroup::DoubleDifferentialCrossSection;

static const std::string CLASSNAME = "DoubleDifferentialCrossSection";

namespace extract {
   static auto regions3d = [](auto &obj) { return &obj.regions3d; };
   static auto XYs3d = [](auto &obj) { return &obj.XYs3d; };
   static auto CoulombPlusNuclearElastic = [](auto &obj) { return &obj.CoulombPlusNuclearElastic; };
   static auto reference = [](auto &obj) { return &obj.reference; };
   static auto coherentPhotonScattering = [](auto &obj) { return &obj.coherentPhotonScattering; };
   static auto incoherentPhotonScattering = [](auto &obj) { return &obj.incoherentPhotonScattering; };
   static auto thermalNeutronScatteringLaw_coherentElastic = [](auto &obj) { return &obj.thermalNeutronScatteringLaw_coherentElastic; };
   static auto thermalNeutronScatteringLaw_incoherentElastic = [](auto &obj) { return &obj.thermalNeutronScatteringLaw_incoherentElastic; };
   static auto thermalNeutronScatteringLaw_incoherentInelastic = [](auto &obj) { return &obj.thermalNeutronScatteringLaw_incoherentInelastic; };
}

using CPPRegions3d = containers::Regions3d;
using CPPXYs3d = containers::XYs3d;
using CPPCoulombPlusNuclearElastic = cpTransport::CoulombPlusNuclearElastic;
using CPPReference = transport::Reference;
using CPPCoherentPhotonScattering = atomic::CoherentPhotonScattering;
using CPPIncoherentPhotonScattering = atomic::IncoherentPhotonScattering;
using CPPThermalNeutronScatteringLaw_coherentElastic = tsl::ThermalNeutronScatteringLaw_coherentElastic;
using CPPThermalNeutronScatteringLaw_incoherentElastic = tsl::ThermalNeutronScatteringLaw_incoherentElastic;
using CPPThermalNeutronScatteringLaw_incoherentInelastic = tsl::ThermalNeutronScatteringLaw_incoherentInelastic;


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
   ConstHandle2ConstRegions3d regions3d,
   ConstHandle2ConstXYs3d XYs3d,
   ConstHandle2ConstCoulombPlusNuclearElastic CoulombPlusNuclearElastic,
   ConstHandle2ConstReference reference,
   ConstHandle2ConstCoherentPhotonScattering coherentPhotonScattering,
   ConstHandle2ConstIncoherentPhotonScattering incoherentPhotonScattering,
   ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic thermalNeutronScatteringLaw_coherentElastic,
   ConstHandle2ConstThermalNeutronScatteringLaw_incoherentElastic thermalNeutronScatteringLaw_incoherentElastic,
   ConstHandle2ConstThermalNeutronScatteringLaw_incoherentInelastic thermalNeutronScatteringLaw_incoherentInelastic
) {
   ConstHandle2DoubleDifferentialCrossSection handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPRegions3d>(regions3d),
      detail::tocpp<CPPXYs3d>(XYs3d),
      detail::tocpp<CPPCoulombPlusNuclearElastic>(CoulombPlusNuclearElastic),
      detail::tocpp<CPPReference>(reference),
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
   ConstHandle2ConstRegions3d regions3d,
   ConstHandle2ConstXYs3d XYs3d,
   ConstHandle2ConstCoulombPlusNuclearElastic CoulombPlusNuclearElastic,
   ConstHandle2ConstReference reference,
   ConstHandle2ConstCoherentPhotonScattering coherentPhotonScattering,
   ConstHandle2ConstIncoherentPhotonScattering incoherentPhotonScattering,
   ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic thermalNeutronScatteringLaw_coherentElastic,
   ConstHandle2ConstThermalNeutronScatteringLaw_incoherentElastic thermalNeutronScatteringLaw_incoherentElastic,
   ConstHandle2ConstThermalNeutronScatteringLaw_incoherentInelastic thermalNeutronScatteringLaw_incoherentInelastic
) {
   ConstHandle2DoubleDifferentialCrossSection handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPRegions3d>(regions3d),
      detail::tocpp<CPPXYs3d>(XYs3d),
      detail::tocpp<CPPCoulombPlusNuclearElastic>(CoulombPlusNuclearElastic),
      detail::tocpp<CPPReference>(reference),
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
DoubleDifferentialCrossSectionAssign(ConstHandle2DoubleDifferentialCrossSection This, ConstHandle2ConstDoubleDifferentialCrossSection from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
DoubleDifferentialCrossSectionDelete(ConstHandle2ConstDoubleDifferentialCrossSection This)
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
DoubleDifferentialCrossSectionRead(ConstHandle2DoubleDifferentialCrossSection This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
DoubleDifferentialCrossSectionWrite(ConstHandle2ConstDoubleDifferentialCrossSection This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
DoubleDifferentialCrossSectionPrint(ConstHandle2ConstDoubleDifferentialCrossSection This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
DoubleDifferentialCrossSectionPrintXML(ConstHandle2ConstDoubleDifferentialCrossSection This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
DoubleDifferentialCrossSectionPrintJSON(ConstHandle2ConstDoubleDifferentialCrossSection This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: regions3d
// -----------------------------------------------------------------------------

// Has
int
DoubleDifferentialCrossSectionRegions3dHas(ConstHandle2ConstDoubleDifferentialCrossSection This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Regions3dHas", This, extract::regions3d);
}

// Get, const
Handle2ConstRegions3d
DoubleDifferentialCrossSectionRegions3dGetConst(ConstHandle2ConstDoubleDifferentialCrossSection This)
{
   return detail::getField<CPP,Handle2ConstRegions3d>
      (CLASSNAME, CLASSNAME+"Regions3dGetConst", This, extract::regions3d);
}

// Get, non-const
Handle2Regions3d
DoubleDifferentialCrossSectionRegions3dGet(ConstHandle2DoubleDifferentialCrossSection This)
{
   return detail::getField<CPP,Handle2Regions3d>
      (CLASSNAME, CLASSNAME+"Regions3dGet", This, extract::regions3d);
}

// Set
void
DoubleDifferentialCrossSectionRegions3dSet(ConstHandle2DoubleDifferentialCrossSection This, ConstHandle2ConstRegions3d regions3d)
{
   detail::setField<CPP,CPPRegions3d>
      (CLASSNAME, CLASSNAME+"Regions3dSet", This, extract::regions3d, regions3d);
}


// -----------------------------------------------------------------------------
// Child: XYs3d
// -----------------------------------------------------------------------------

// Has
int
DoubleDifferentialCrossSectionXYs3dHas(ConstHandle2ConstDoubleDifferentialCrossSection This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"XYs3dHas", This, extract::XYs3d);
}

// Get, const
Handle2ConstXYs3d
DoubleDifferentialCrossSectionXYs3dGetConst(ConstHandle2ConstDoubleDifferentialCrossSection This)
{
   return detail::getField<CPP,Handle2ConstXYs3d>
      (CLASSNAME, CLASSNAME+"XYs3dGetConst", This, extract::XYs3d);
}

// Get, non-const
Handle2XYs3d
DoubleDifferentialCrossSectionXYs3dGet(ConstHandle2DoubleDifferentialCrossSection This)
{
   return detail::getField<CPP,Handle2XYs3d>
      (CLASSNAME, CLASSNAME+"XYs3dGet", This, extract::XYs3d);
}

// Set
void
DoubleDifferentialCrossSectionXYs3dSet(ConstHandle2DoubleDifferentialCrossSection This, ConstHandle2ConstXYs3d XYs3d)
{
   detail::setField<CPP,CPPXYs3d>
      (CLASSNAME, CLASSNAME+"XYs3dSet", This, extract::XYs3d, XYs3d);
}


// -----------------------------------------------------------------------------
// Child: CoulombPlusNuclearElastic
// -----------------------------------------------------------------------------

// Has
int
DoubleDifferentialCrossSectionCoulombPlusNuclearElasticHas(ConstHandle2ConstDoubleDifferentialCrossSection This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CoulombPlusNuclearElasticHas", This, extract::CoulombPlusNuclearElastic);
}

// Get, const
Handle2ConstCoulombPlusNuclearElastic
DoubleDifferentialCrossSectionCoulombPlusNuclearElasticGetConst(ConstHandle2ConstDoubleDifferentialCrossSection This)
{
   return detail::getField<CPP,Handle2ConstCoulombPlusNuclearElastic>
      (CLASSNAME, CLASSNAME+"CoulombPlusNuclearElasticGetConst", This, extract::CoulombPlusNuclearElastic);
}

// Get, non-const
Handle2CoulombPlusNuclearElastic
DoubleDifferentialCrossSectionCoulombPlusNuclearElasticGet(ConstHandle2DoubleDifferentialCrossSection This)
{
   return detail::getField<CPP,Handle2CoulombPlusNuclearElastic>
      (CLASSNAME, CLASSNAME+"CoulombPlusNuclearElasticGet", This, extract::CoulombPlusNuclearElastic);
}

// Set
void
DoubleDifferentialCrossSectionCoulombPlusNuclearElasticSet(ConstHandle2DoubleDifferentialCrossSection This, ConstHandle2ConstCoulombPlusNuclearElastic CoulombPlusNuclearElastic)
{
   detail::setField<CPP,CPPCoulombPlusNuclearElastic>
      (CLASSNAME, CLASSNAME+"CoulombPlusNuclearElasticSet", This, extract::CoulombPlusNuclearElastic, CoulombPlusNuclearElastic);
}


// -----------------------------------------------------------------------------
// Child: reference
// -----------------------------------------------------------------------------

// Has
int
DoubleDifferentialCrossSectionReferenceHas(ConstHandle2ConstDoubleDifferentialCrossSection This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ReferenceHas", This, extract::reference);
}

// Get, const
Handle2ConstReference
DoubleDifferentialCrossSectionReferenceGetConst(ConstHandle2ConstDoubleDifferentialCrossSection This)
{
   return detail::getField<CPP,Handle2ConstReference>
      (CLASSNAME, CLASSNAME+"ReferenceGetConst", This, extract::reference);
}

// Get, non-const
Handle2Reference
DoubleDifferentialCrossSectionReferenceGet(ConstHandle2DoubleDifferentialCrossSection This)
{
   return detail::getField<CPP,Handle2Reference>
      (CLASSNAME, CLASSNAME+"ReferenceGet", This, extract::reference);
}

// Set
void
DoubleDifferentialCrossSectionReferenceSet(ConstHandle2DoubleDifferentialCrossSection This, ConstHandle2ConstReference reference)
{
   detail::setField<CPP,CPPReference>
      (CLASSNAME, CLASSNAME+"ReferenceSet", This, extract::reference, reference);
}


// -----------------------------------------------------------------------------
// Child: coherentPhotonScattering
// -----------------------------------------------------------------------------

// Has
int
DoubleDifferentialCrossSectionCoherentPhotonScatteringHas(ConstHandle2ConstDoubleDifferentialCrossSection This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CoherentPhotonScatteringHas", This, extract::coherentPhotonScattering);
}

// Get, const
Handle2ConstCoherentPhotonScattering
DoubleDifferentialCrossSectionCoherentPhotonScatteringGetConst(ConstHandle2ConstDoubleDifferentialCrossSection This)
{
   return detail::getField<CPP,Handle2ConstCoherentPhotonScattering>
      (CLASSNAME, CLASSNAME+"CoherentPhotonScatteringGetConst", This, extract::coherentPhotonScattering);
}

// Get, non-const
Handle2CoherentPhotonScattering
DoubleDifferentialCrossSectionCoherentPhotonScatteringGet(ConstHandle2DoubleDifferentialCrossSection This)
{
   return detail::getField<CPP,Handle2CoherentPhotonScattering>
      (CLASSNAME, CLASSNAME+"CoherentPhotonScatteringGet", This, extract::coherentPhotonScattering);
}

// Set
void
DoubleDifferentialCrossSectionCoherentPhotonScatteringSet(ConstHandle2DoubleDifferentialCrossSection This, ConstHandle2ConstCoherentPhotonScattering coherentPhotonScattering)
{
   detail::setField<CPP,CPPCoherentPhotonScattering>
      (CLASSNAME, CLASSNAME+"CoherentPhotonScatteringSet", This, extract::coherentPhotonScattering, coherentPhotonScattering);
}


// -----------------------------------------------------------------------------
// Child: incoherentPhotonScattering
// -----------------------------------------------------------------------------

// Has
int
DoubleDifferentialCrossSectionIncoherentPhotonScatteringHas(ConstHandle2ConstDoubleDifferentialCrossSection This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"IncoherentPhotonScatteringHas", This, extract::incoherentPhotonScattering);
}

// Get, const
Handle2ConstIncoherentPhotonScattering
DoubleDifferentialCrossSectionIncoherentPhotonScatteringGetConst(ConstHandle2ConstDoubleDifferentialCrossSection This)
{
   return detail::getField<CPP,Handle2ConstIncoherentPhotonScattering>
      (CLASSNAME, CLASSNAME+"IncoherentPhotonScatteringGetConst", This, extract::incoherentPhotonScattering);
}

// Get, non-const
Handle2IncoherentPhotonScattering
DoubleDifferentialCrossSectionIncoherentPhotonScatteringGet(ConstHandle2DoubleDifferentialCrossSection This)
{
   return detail::getField<CPP,Handle2IncoherentPhotonScattering>
      (CLASSNAME, CLASSNAME+"IncoherentPhotonScatteringGet", This, extract::incoherentPhotonScattering);
}

// Set
void
DoubleDifferentialCrossSectionIncoherentPhotonScatteringSet(ConstHandle2DoubleDifferentialCrossSection This, ConstHandle2ConstIncoherentPhotonScattering incoherentPhotonScattering)
{
   detail::setField<CPP,CPPIncoherentPhotonScattering>
      (CLASSNAME, CLASSNAME+"IncoherentPhotonScatteringSet", This, extract::incoherentPhotonScattering, incoherentPhotonScattering);
}


// -----------------------------------------------------------------------------
// Child: thermalNeutronScatteringLaw_coherentElastic
// -----------------------------------------------------------------------------

// Has
int
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_coherentElasticHas(ConstHandle2ConstDoubleDifferentialCrossSection This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLaw_coherentElasticHas", This, extract::thermalNeutronScatteringLaw_coherentElastic);
}

// Get, const
Handle2ConstThermalNeutronScatteringLaw_coherentElastic
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_coherentElasticGetConst(ConstHandle2ConstDoubleDifferentialCrossSection This)
{
   return detail::getField<CPP,Handle2ConstThermalNeutronScatteringLaw_coherentElastic>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLaw_coherentElasticGetConst", This, extract::thermalNeutronScatteringLaw_coherentElastic);
}

// Get, non-const
Handle2ThermalNeutronScatteringLaw_coherentElastic
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_coherentElasticGet(ConstHandle2DoubleDifferentialCrossSection This)
{
   return detail::getField<CPP,Handle2ThermalNeutronScatteringLaw_coherentElastic>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLaw_coherentElasticGet", This, extract::thermalNeutronScatteringLaw_coherentElastic);
}

// Set
void
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_coherentElasticSet(ConstHandle2DoubleDifferentialCrossSection This, ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic thermalNeutronScatteringLaw_coherentElastic)
{
   detail::setField<CPP,CPPThermalNeutronScatteringLaw_coherentElastic>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLaw_coherentElasticSet", This, extract::thermalNeutronScatteringLaw_coherentElastic, thermalNeutronScatteringLaw_coherentElastic);
}


// -----------------------------------------------------------------------------
// Child: thermalNeutronScatteringLaw_incoherentElastic
// -----------------------------------------------------------------------------

// Has
int
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_incoherentElasticHas(ConstHandle2ConstDoubleDifferentialCrossSection This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLaw_incoherentElasticHas", This, extract::thermalNeutronScatteringLaw_incoherentElastic);
}

// Get, const
Handle2ConstThermalNeutronScatteringLaw_incoherentElastic
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_incoherentElasticGetConst(ConstHandle2ConstDoubleDifferentialCrossSection This)
{
   return detail::getField<CPP,Handle2ConstThermalNeutronScatteringLaw_incoherentElastic>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLaw_incoherentElasticGetConst", This, extract::thermalNeutronScatteringLaw_incoherentElastic);
}

// Get, non-const
Handle2ThermalNeutronScatteringLaw_incoherentElastic
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_incoherentElasticGet(ConstHandle2DoubleDifferentialCrossSection This)
{
   return detail::getField<CPP,Handle2ThermalNeutronScatteringLaw_incoherentElastic>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLaw_incoherentElasticGet", This, extract::thermalNeutronScatteringLaw_incoherentElastic);
}

// Set
void
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_incoherentElasticSet(ConstHandle2DoubleDifferentialCrossSection This, ConstHandle2ConstThermalNeutronScatteringLaw_incoherentElastic thermalNeutronScatteringLaw_incoherentElastic)
{
   detail::setField<CPP,CPPThermalNeutronScatteringLaw_incoherentElastic>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLaw_incoherentElasticSet", This, extract::thermalNeutronScatteringLaw_incoherentElastic, thermalNeutronScatteringLaw_incoherentElastic);
}


// -----------------------------------------------------------------------------
// Child: thermalNeutronScatteringLaw_incoherentInelastic
// -----------------------------------------------------------------------------

// Has
int
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_incoherentInelasticHas(ConstHandle2ConstDoubleDifferentialCrossSection This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLaw_incoherentInelasticHas", This, extract::thermalNeutronScatteringLaw_incoherentInelastic);
}

// Get, const
Handle2ConstThermalNeutronScatteringLaw_incoherentInelastic
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_incoherentInelasticGetConst(ConstHandle2ConstDoubleDifferentialCrossSection This)
{
   return detail::getField<CPP,Handle2ConstThermalNeutronScatteringLaw_incoherentInelastic>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLaw_incoherentInelasticGetConst", This, extract::thermalNeutronScatteringLaw_incoherentInelastic);
}

// Get, non-const
Handle2ThermalNeutronScatteringLaw_incoherentInelastic
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_incoherentInelasticGet(ConstHandle2DoubleDifferentialCrossSection This)
{
   return detail::getField<CPP,Handle2ThermalNeutronScatteringLaw_incoherentInelastic>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLaw_incoherentInelasticGet", This, extract::thermalNeutronScatteringLaw_incoherentInelastic);
}

// Set
void
DoubleDifferentialCrossSectionThermalNeutronScatteringLaw_incoherentInelasticSet(ConstHandle2DoubleDifferentialCrossSection This, ConstHandle2ConstThermalNeutronScatteringLaw_incoherentInelastic thermalNeutronScatteringLaw_incoherentInelastic)
{
   detail::setField<CPP,CPPThermalNeutronScatteringLaw_incoherentInelastic>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLaw_incoherentInelasticSet", This, extract::thermalNeutronScatteringLaw_incoherentInelastic, thermalNeutronScatteringLaw_incoherentInelastic);
}
