
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/transport/CrossSection.hpp"
#include "CrossSection.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = CrossSectionClass;
using CPP = multigroup::CrossSection;

static const std::string CLASSNAME = "CrossSection";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
}

using CPPXYs1d = containers::XYs1d;
using CPPRegions1d = containers::Regions1d;
using CPPResonancesWithBackground = transport::ResonancesWithBackground;
using CPPCoulombPlusNuclearElastic = cpTransport::CoulombPlusNuclearElastic;
using CPPThermalNeutronScatteringLaw1d = tsl::ThermalNeutronScatteringLaw1d;
using CPPReference = transport::Reference;
using CPPGridded1d = containers::Gridded1d;
using CPPYs1d = containers::Ys1d;
using CPPURR_probabilityTables1d = transport::URR_probabilityTables1d;


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
   const XMLName label,
) {
   ConstHandle2CrossSection handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label
   );
   return handle;
}

// Create, general
Handle2CrossSection
CrossSectionCreate(
   const XMLName label,
) {
   ConstHandle2CrossSection handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label
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
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
CrossSectionLabelHas(ConstHandle2ConstCrossSection self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
XMLName
CrossSectionLabelGet(ConstHandle2ConstCrossSection self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
CrossSectionLabelSet(ConstHandle2CrossSection self, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/transport/CrossSection/src/custom.cpp"
