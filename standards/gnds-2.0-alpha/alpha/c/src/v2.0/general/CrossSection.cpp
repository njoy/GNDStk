
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/CrossSection.hpp"
#include "CrossSection.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = CrossSectionClass;
using CPP = multigroup::CrossSection;

static const std::string CLASSNAME = "CrossSection";

namespace extract {
   static auto XYs1d = [](auto &obj) { return &obj.XYs1d; };
   static auto regions1d = [](auto &obj) { return &obj.regions1d; };
   static auto reference = [](auto &obj) { return &obj.reference; };
   static auto resonancesWithBackground = [](auto &obj) { return &obj.resonancesWithBackground; };
   static auto CoulombPlusNuclearElastic = [](auto &obj) { return &obj.CoulombPlusNuclearElastic; };
   static auto thermalNeutronScatteringLaw1d = [](auto &obj) { return &obj.thermalNeutronScatteringLaw1d; };
}

using CPPXYs1d = general::XYs1d;
using CPPRegions1d = general::Regions1d;
using CPPReference = general::Reference;
using CPPResonancesWithBackground = general::ResonancesWithBackground;
using CPPCoulombPlusNuclearElastic = general::CoulombPlusNuclearElastic;
using CPPThermalNeutronScatteringLaw1d = general::ThermalNeutronScatteringLaw1d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstCrossSection
CrossSectionDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2CrossSection
CrossSectionDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstCrossSection
CrossSectionCreateConst(
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstRegions1d regions1d,
   ConstHandle2ConstReference reference,
   ConstHandle2ConstResonancesWithBackground resonancesWithBackground,
   ConstHandle2ConstCoulombPlusNuclearElastic CoulombPlusNuclearElastic,
   ConstHandle2ConstThermalNeutronScatteringLaw1d thermalNeutronScatteringLaw1d
) {
   ConstHandle2CrossSection handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPXYs1d>(XYs1d),
      detail::tocpp<CPPRegions1d>(regions1d),
      detail::tocpp<CPPReference>(reference),
      detail::tocpp<CPPResonancesWithBackground>(resonancesWithBackground),
      detail::tocpp<CPPCoulombPlusNuclearElastic>(CoulombPlusNuclearElastic),
      detail::tocpp<CPPThermalNeutronScatteringLaw1d>(thermalNeutronScatteringLaw1d)
   );
   return handle;
}

// Create, general
Handle2CrossSection
CrossSectionCreate(
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstRegions1d regions1d,
   ConstHandle2ConstReference reference,
   ConstHandle2ConstResonancesWithBackground resonancesWithBackground,
   ConstHandle2ConstCoulombPlusNuclearElastic CoulombPlusNuclearElastic,
   ConstHandle2ConstThermalNeutronScatteringLaw1d thermalNeutronScatteringLaw1d
) {
   ConstHandle2CrossSection handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPXYs1d>(XYs1d),
      detail::tocpp<CPPRegions1d>(regions1d),
      detail::tocpp<CPPReference>(reference),
      detail::tocpp<CPPResonancesWithBackground>(resonancesWithBackground),
      detail::tocpp<CPPCoulombPlusNuclearElastic>(CoulombPlusNuclearElastic),
      detail::tocpp<CPPThermalNeutronScatteringLaw1d>(thermalNeutronScatteringLaw1d)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
CrossSectionAssign(ConstHandle2CrossSection self, ConstHandle2ConstCrossSection from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
CrossSectionDelete(ConstHandle2ConstCrossSection self)
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
CrossSectionRead(ConstHandle2CrossSection self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
CrossSectionWrite(ConstHandle2ConstCrossSection self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
CrossSectionPrint(ConstHandle2ConstCrossSection self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
CrossSectionPrintXML(ConstHandle2ConstCrossSection self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
CrossSectionPrintJSON(ConstHandle2ConstCrossSection self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// Has
int
CrossSectionXYs1dHas(ConstHandle2ConstCrossSection self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"XYs1dHas", self, extract::XYs1d);
}

// Get, const
Handle2ConstXYs1d
CrossSectionXYs1dGetConst(ConstHandle2ConstCrossSection self)
{
   return detail::getField<CPP,Handle2ConstXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGetConst", self, extract::XYs1d);
}

// Get, non-const
Handle2XYs1d
CrossSectionXYs1dGet(ConstHandle2CrossSection self)
{
   return detail::getField<CPP,Handle2XYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGet", self, extract::XYs1d);
}

// Set
void
CrossSectionXYs1dSet(ConstHandle2CrossSection self, ConstHandle2ConstXYs1d XYs1d)
{
   detail::setField<CPP,CPPXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dSet", self, extract::XYs1d, XYs1d);
}


// -----------------------------------------------------------------------------
// Child: regions1d
// -----------------------------------------------------------------------------

// Has
int
CrossSectionRegions1dHas(ConstHandle2ConstCrossSection self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Regions1dHas", self, extract::regions1d);
}

// Get, const
Handle2ConstRegions1d
CrossSectionRegions1dGetConst(ConstHandle2ConstCrossSection self)
{
   return detail::getField<CPP,Handle2ConstRegions1d>
      (CLASSNAME, CLASSNAME+"Regions1dGetConst", self, extract::regions1d);
}

// Get, non-const
Handle2Regions1d
CrossSectionRegions1dGet(ConstHandle2CrossSection self)
{
   return detail::getField<CPP,Handle2Regions1d>
      (CLASSNAME, CLASSNAME+"Regions1dGet", self, extract::regions1d);
}

// Set
void
CrossSectionRegions1dSet(ConstHandle2CrossSection self, ConstHandle2ConstRegions1d regions1d)
{
   detail::setField<CPP,CPPRegions1d>
      (CLASSNAME, CLASSNAME+"Regions1dSet", self, extract::regions1d, regions1d);
}


// -----------------------------------------------------------------------------
// Child: reference
// -----------------------------------------------------------------------------

// Has
int
CrossSectionReferenceHas(ConstHandle2ConstCrossSection self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ReferenceHas", self, extract::reference);
}

// Get, const
Handle2ConstReference
CrossSectionReferenceGetConst(ConstHandle2ConstCrossSection self)
{
   return detail::getField<CPP,Handle2ConstReference>
      (CLASSNAME, CLASSNAME+"ReferenceGetConst", self, extract::reference);
}

// Get, non-const
Handle2Reference
CrossSectionReferenceGet(ConstHandle2CrossSection self)
{
   return detail::getField<CPP,Handle2Reference>
      (CLASSNAME, CLASSNAME+"ReferenceGet", self, extract::reference);
}

// Set
void
CrossSectionReferenceSet(ConstHandle2CrossSection self, ConstHandle2ConstReference reference)
{
   detail::setField<CPP,CPPReference>
      (CLASSNAME, CLASSNAME+"ReferenceSet", self, extract::reference, reference);
}


// -----------------------------------------------------------------------------
// Child: resonancesWithBackground
// -----------------------------------------------------------------------------

// Has
int
CrossSectionResonancesWithBackgroundHas(ConstHandle2ConstCrossSection self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ResonancesWithBackgroundHas", self, extract::resonancesWithBackground);
}

// Get, const
Handle2ConstResonancesWithBackground
CrossSectionResonancesWithBackgroundGetConst(ConstHandle2ConstCrossSection self)
{
   return detail::getField<CPP,Handle2ConstResonancesWithBackground>
      (CLASSNAME, CLASSNAME+"ResonancesWithBackgroundGetConst", self, extract::resonancesWithBackground);
}

// Get, non-const
Handle2ResonancesWithBackground
CrossSectionResonancesWithBackgroundGet(ConstHandle2CrossSection self)
{
   return detail::getField<CPP,Handle2ResonancesWithBackground>
      (CLASSNAME, CLASSNAME+"ResonancesWithBackgroundGet", self, extract::resonancesWithBackground);
}

// Set
void
CrossSectionResonancesWithBackgroundSet(ConstHandle2CrossSection self, ConstHandle2ConstResonancesWithBackground resonancesWithBackground)
{
   detail::setField<CPP,CPPResonancesWithBackground>
      (CLASSNAME, CLASSNAME+"ResonancesWithBackgroundSet", self, extract::resonancesWithBackground, resonancesWithBackground);
}


// -----------------------------------------------------------------------------
// Child: CoulombPlusNuclearElastic
// -----------------------------------------------------------------------------

// Has
int
CrossSectionCoulombPlusNuclearElasticHas(ConstHandle2ConstCrossSection self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CoulombPlusNuclearElasticHas", self, extract::CoulombPlusNuclearElastic);
}

// Get, const
Handle2ConstCoulombPlusNuclearElastic
CrossSectionCoulombPlusNuclearElasticGetConst(ConstHandle2ConstCrossSection self)
{
   return detail::getField<CPP,Handle2ConstCoulombPlusNuclearElastic>
      (CLASSNAME, CLASSNAME+"CoulombPlusNuclearElasticGetConst", self, extract::CoulombPlusNuclearElastic);
}

// Get, non-const
Handle2CoulombPlusNuclearElastic
CrossSectionCoulombPlusNuclearElasticGet(ConstHandle2CrossSection self)
{
   return detail::getField<CPP,Handle2CoulombPlusNuclearElastic>
      (CLASSNAME, CLASSNAME+"CoulombPlusNuclearElasticGet", self, extract::CoulombPlusNuclearElastic);
}

// Set
void
CrossSectionCoulombPlusNuclearElasticSet(ConstHandle2CrossSection self, ConstHandle2ConstCoulombPlusNuclearElastic CoulombPlusNuclearElastic)
{
   detail::setField<CPP,CPPCoulombPlusNuclearElastic>
      (CLASSNAME, CLASSNAME+"CoulombPlusNuclearElasticSet", self, extract::CoulombPlusNuclearElastic, CoulombPlusNuclearElastic);
}


// -----------------------------------------------------------------------------
// Child: thermalNeutronScatteringLaw1d
// -----------------------------------------------------------------------------

// Has
int
CrossSectionThermalNeutronScatteringLaw1dHas(ConstHandle2ConstCrossSection self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLaw1dHas", self, extract::thermalNeutronScatteringLaw1d);
}

// Get, const
Handle2ConstThermalNeutronScatteringLaw1d
CrossSectionThermalNeutronScatteringLaw1dGetConst(ConstHandle2ConstCrossSection self)
{
   return detail::getField<CPP,Handle2ConstThermalNeutronScatteringLaw1d>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLaw1dGetConst", self, extract::thermalNeutronScatteringLaw1d);
}

// Get, non-const
Handle2ThermalNeutronScatteringLaw1d
CrossSectionThermalNeutronScatteringLaw1dGet(ConstHandle2CrossSection self)
{
   return detail::getField<CPP,Handle2ThermalNeutronScatteringLaw1d>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLaw1dGet", self, extract::thermalNeutronScatteringLaw1d);
}

// Set
void
CrossSectionThermalNeutronScatteringLaw1dSet(ConstHandle2CrossSection self, ConstHandle2ConstThermalNeutronScatteringLaw1d thermalNeutronScatteringLaw1d)
{
   detail::setField<CPP,CPPThermalNeutronScatteringLaw1d>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLaw1dSet", self, extract::thermalNeutronScatteringLaw1d, thermalNeutronScatteringLaw1d);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/CrossSection/src/custom.cpp"