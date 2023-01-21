
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/cpTransport/NuclearPlusInterference.hpp"
#include "NuclearPlusInterference.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = NuclearPlusInterferenceClass;
using CPP = multigroup::NuclearPlusInterference;

static const std::string CLASSNAME = "NuclearPlusInterference";

namespace extract {
   static auto muCutoff = [](auto &obj) { return &obj.muCutoff; };
   static auto crossSection = [](auto &obj) { return &obj.crossSection; };
   static auto distribution = [](auto &obj) { return &obj.distribution; };
}

using CPPCrossSection = transport::CrossSection;
using CPPDistribution = transport::Distribution;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstNuclearPlusInterference
NuclearPlusInterferenceDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2NuclearPlusInterference
NuclearPlusInterferenceDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstNuclearPlusInterference
NuclearPlusInterferenceCreateConst(
   const Float64 muCutoff,
   ConstHandle2ConstCrossSection crossSection,
   ConstHandle2ConstDistribution distribution
) {
   ConstHandle2NuclearPlusInterference handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      muCutoff,
      detail::tocpp<CPPCrossSection>(crossSection),
      detail::tocpp<CPPDistribution>(distribution)
   );
   return handle;
}

// Create, general
Handle2NuclearPlusInterference
NuclearPlusInterferenceCreate(
   const Float64 muCutoff,
   ConstHandle2ConstCrossSection crossSection,
   ConstHandle2ConstDistribution distribution
) {
   ConstHandle2NuclearPlusInterference handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      muCutoff,
      detail::tocpp<CPPCrossSection>(crossSection),
      detail::tocpp<CPPDistribution>(distribution)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
NuclearPlusInterferenceAssign(ConstHandle2NuclearPlusInterference This, ConstHandle2ConstNuclearPlusInterference from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
NuclearPlusInterferenceDelete(ConstHandle2ConstNuclearPlusInterference This)
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
NuclearPlusInterferenceRead(ConstHandle2NuclearPlusInterference This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
NuclearPlusInterferenceWrite(ConstHandle2ConstNuclearPlusInterference This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
NuclearPlusInterferencePrint(ConstHandle2ConstNuclearPlusInterference This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
NuclearPlusInterferencePrintXML(ConstHandle2ConstNuclearPlusInterference This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
NuclearPlusInterferencePrintJSON(ConstHandle2ConstNuclearPlusInterference This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: muCutoff
// -----------------------------------------------------------------------------

// Has
int
NuclearPlusInterferenceMuCutoffHas(ConstHandle2ConstNuclearPlusInterference This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"MuCutoffHas", This, extract::muCutoff);
}

// Get
// Returns by value
Float64
NuclearPlusInterferenceMuCutoffGet(ConstHandle2ConstNuclearPlusInterference This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"MuCutoffGet", This, extract::muCutoff);
}

// Set
void
NuclearPlusInterferenceMuCutoffSet(ConstHandle2NuclearPlusInterference This, const Float64 muCutoff)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"MuCutoffSet", This, extract::muCutoff, muCutoff);
}


// -----------------------------------------------------------------------------
// Child: crossSection
// -----------------------------------------------------------------------------

// Has
int
NuclearPlusInterferenceCrossSectionHas(ConstHandle2ConstNuclearPlusInterference This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CrossSectionHas", This, extract::crossSection);
}

// Get, const
Handle2ConstCrossSection
NuclearPlusInterferenceCrossSectionGetConst(ConstHandle2ConstNuclearPlusInterference This)
{
   return detail::getField<CPP,Handle2ConstCrossSection>
      (CLASSNAME, CLASSNAME+"CrossSectionGetConst", This, extract::crossSection);
}

// Get, non-const
Handle2CrossSection
NuclearPlusInterferenceCrossSectionGet(ConstHandle2NuclearPlusInterference This)
{
   return detail::getField<CPP,Handle2CrossSection>
      (CLASSNAME, CLASSNAME+"CrossSectionGet", This, extract::crossSection);
}

// Set
void
NuclearPlusInterferenceCrossSectionSet(ConstHandle2NuclearPlusInterference This, ConstHandle2ConstCrossSection crossSection)
{
   detail::setField<CPP,CPPCrossSection>
      (CLASSNAME, CLASSNAME+"CrossSectionSet", This, extract::crossSection, crossSection);
}


// -----------------------------------------------------------------------------
// Child: distribution
// -----------------------------------------------------------------------------

// Has
int
NuclearPlusInterferenceDistributionHas(ConstHandle2ConstNuclearPlusInterference This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DistributionHas", This, extract::distribution);
}

// Get, const
Handle2ConstDistribution
NuclearPlusInterferenceDistributionGetConst(ConstHandle2ConstNuclearPlusInterference This)
{
   return detail::getField<CPP,Handle2ConstDistribution>
      (CLASSNAME, CLASSNAME+"DistributionGetConst", This, extract::distribution);
}

// Get, non-const
Handle2Distribution
NuclearPlusInterferenceDistributionGet(ConstHandle2NuclearPlusInterference This)
{
   return detail::getField<CPP,Handle2Distribution>
      (CLASSNAME, CLASSNAME+"DistributionGet", This, extract::distribution);
}

// Set
void
NuclearPlusInterferenceDistributionSet(ConstHandle2NuclearPlusInterference This, ConstHandle2ConstDistribution distribution)
{
   detail::setField<CPP,CPPDistribution>
      (CLASSNAME, CLASSNAME+"DistributionSet", This, extract::distribution, distribution);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/cpTransport/NuclearPlusInterference/src/custom.cpp"
