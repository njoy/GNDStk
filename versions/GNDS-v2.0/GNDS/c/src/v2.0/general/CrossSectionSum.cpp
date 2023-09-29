
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/CrossSectionSum.hpp"
#include "CrossSectionSum.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = CrossSectionSumClass;
using CPP = multigroup::CrossSectionSum;

static const std::string CLASSNAME = "CrossSectionSum";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto ENDF_MT = [](auto &obj) { return &obj.ENDF_MT; };
   static auto summands = [](auto &obj) { return &obj.summands; };
   static auto Q = [](auto &obj) { return &obj.Q; };
   static auto crossSection = [](auto &obj) { return &obj.crossSection; };
}

using CPPSummands = general::Summands;
using CPPQ = general::Q;
using CPPCrossSection = general::CrossSection;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstCrossSectionSum
CrossSectionSumDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default, non-const
Handle2CrossSectionSum
CrossSectionSumDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstCrossSectionSum
CrossSectionSumCreateConst(
   const char *const label,
   const int ENDF_MT,
   ConstHandle2ConstSummands summands,
   ConstHandle2ConstQ Q,
   ConstHandle2ConstCrossSection crossSection
) {
   ConstHandle2CrossSectionSum handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      ENDF_MT,
      detail::tocpp<CPPSummands>(summands),
      detail::tocpp<CPPQ>(Q),
      detail::tocpp<CPPCrossSection>(crossSection)
   );
   return handle;
}

// Create, general, non-const
Handle2CrossSectionSum
CrossSectionSumCreate(
   const char *const label,
   const int ENDF_MT,
   ConstHandle2ConstSummands summands,
   ConstHandle2ConstQ Q,
   ConstHandle2ConstCrossSection crossSection
) {
   ConstHandle2CrossSectionSum handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      ENDF_MT,
      detail::tocpp<CPPSummands>(summands),
      detail::tocpp<CPPQ>(Q),
      detail::tocpp<CPPCrossSection>(crossSection)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
CrossSectionSumAssign(ConstHandle2CrossSectionSum self, ConstHandle2ConstCrossSectionSum from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
CrossSectionSumDelete(ConstHandle2ConstCrossSectionSum self)
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
CrossSectionSumRead(ConstHandle2CrossSectionSum self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
CrossSectionSumWrite(ConstHandle2ConstCrossSectionSum self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
CrossSectionSumPrint(ConstHandle2ConstCrossSectionSum self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
CrossSectionSumPrintXML(ConstHandle2ConstCrossSectionSum self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
CrossSectionSumPrintJSON(ConstHandle2ConstCrossSectionSum self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
CrossSectionSumLabelHas(ConstHandle2ConstCrossSectionSum self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
const char *
CrossSectionSumLabelGet(ConstHandle2ConstCrossSectionSum self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
CrossSectionSumLabelSet(ConstHandle2CrossSectionSum self, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: ENDF_MT
// -----------------------------------------------------------------------------

// Has
int
CrossSectionSumENDFMTHas(ConstHandle2ConstCrossSectionSum self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ENDFMTHas", self, extract::ENDF_MT);
}

// Get
// Returns by value
int
CrossSectionSumENDFMTGet(ConstHandle2ConstCrossSectionSum self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ENDFMTGet", self, extract::ENDF_MT);
}

// Set
void
CrossSectionSumENDFMTSet(ConstHandle2CrossSectionSum self, const int ENDF_MT)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ENDFMTSet", self, extract::ENDF_MT, ENDF_MT);
}


// -----------------------------------------------------------------------------
// Child: summands
// -----------------------------------------------------------------------------

// Has
int
CrossSectionSumSummandsHas(ConstHandle2ConstCrossSectionSum self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SummandsHas", self, extract::summands);
}

// Get, const
Handle2ConstSummands
CrossSectionSumSummandsGetConst(ConstHandle2ConstCrossSectionSum self)
{
   return detail::getField<CPP,Handle2ConstSummands>
      (CLASSNAME, CLASSNAME+"SummandsGetConst", self, extract::summands);
}

// Get, non-const
Handle2Summands
CrossSectionSumSummandsGet(ConstHandle2CrossSectionSum self)
{
   return detail::getField<CPP,Handle2Summands>
      (CLASSNAME, CLASSNAME+"SummandsGet", self, extract::summands);
}

// Set
void
CrossSectionSumSummandsSet(ConstHandle2CrossSectionSum self, ConstHandle2ConstSummands summands)
{
   detail::setField<CPP,CPPSummands>
      (CLASSNAME, CLASSNAME+"SummandsSet", self, extract::summands, summands);
}


// -----------------------------------------------------------------------------
// Child: Q
// -----------------------------------------------------------------------------

// Has
int
CrossSectionSumQHas(ConstHandle2ConstCrossSectionSum self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"QHas", self, extract::Q);
}

// Get, const
Handle2ConstQ
CrossSectionSumQGetConst(ConstHandle2ConstCrossSectionSum self)
{
   return detail::getField<CPP,Handle2ConstQ>
      (CLASSNAME, CLASSNAME+"QGetConst", self, extract::Q);
}

// Get, non-const
Handle2Q
CrossSectionSumQGet(ConstHandle2CrossSectionSum self)
{
   return detail::getField<CPP,Handle2Q>
      (CLASSNAME, CLASSNAME+"QGet", self, extract::Q);
}

// Set
void
CrossSectionSumQSet(ConstHandle2CrossSectionSum self, ConstHandle2ConstQ Q)
{
   detail::setField<CPP,CPPQ>
      (CLASSNAME, CLASSNAME+"QSet", self, extract::Q, Q);
}


// -----------------------------------------------------------------------------
// Child: crossSection
// -----------------------------------------------------------------------------

// Has
int
CrossSectionSumCrossSectionHas(ConstHandle2ConstCrossSectionSum self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CrossSectionHas", self, extract::crossSection);
}

// Get, const
Handle2ConstCrossSection
CrossSectionSumCrossSectionGetConst(ConstHandle2ConstCrossSectionSum self)
{
   return detail::getField<CPP,Handle2ConstCrossSection>
      (CLASSNAME, CLASSNAME+"CrossSectionGetConst", self, extract::crossSection);
}

// Get, non-const
Handle2CrossSection
CrossSectionSumCrossSectionGet(ConstHandle2CrossSectionSum self)
{
   return detail::getField<CPP,Handle2CrossSection>
      (CLASSNAME, CLASSNAME+"CrossSectionGet", self, extract::crossSection);
}

// Set
void
CrossSectionSumCrossSectionSet(ConstHandle2CrossSectionSum self, ConstHandle2ConstCrossSection crossSection)
{
   detail::setField<CPP,CPPCrossSection>
      (CLASSNAME, CLASSNAME+"CrossSectionSet", self, extract::crossSection, crossSection);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/CrossSectionSum/src/custom.cpp"
