
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/transport/CrossSectionSum.hpp"
#include "CrossSectionSum.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = CrossSectionSumClass;
using CPP = multigroup::CrossSectionSum;

static const std::string CLASSNAME = "CrossSectionSum";

namespace extract {
   static auto ENDF_MT = [](auto &obj) { return &obj.ENDF_MT; };
   static auto label = [](auto &obj) { return &obj.label; };
   static auto Q = [](auto &obj) { return &obj.Q; };
   static auto crossSection = [](auto &obj) { return &obj.crossSection; };
   static auto summands = [](auto &obj) { return &obj.summands; };
}

using CPPQ = common::Q;
using CPPCrossSection = transport::CrossSection;
using CPPSummands = transport::Summands;


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

// Create, default
Handle2CrossSectionSum
CrossSectionSumDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstCrossSectionSum
CrossSectionSumCreateConst(
   const Integer32 ENDF_MT,
   const XMLName label,
   ConstHandle2ConstQ Q,
   ConstHandle2ConstCrossSection crossSection,
   ConstHandle2ConstSummands summands
) {
   ConstHandle2CrossSectionSum handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      ENDF_MT,
      label,
      detail::tocpp<CPPQ>(Q),
      detail::tocpp<CPPCrossSection>(crossSection),
      detail::tocpp<CPPSummands>(summands)
   );
   return handle;
}

// Create, general
Handle2CrossSectionSum
CrossSectionSumCreate(
   const Integer32 ENDF_MT,
   const XMLName label,
   ConstHandle2ConstQ Q,
   ConstHandle2ConstCrossSection crossSection,
   ConstHandle2ConstSummands summands
) {
   ConstHandle2CrossSectionSum handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      ENDF_MT,
      label,
      detail::tocpp<CPPQ>(Q),
      detail::tocpp<CPPCrossSection>(crossSection),
      detail::tocpp<CPPSummands>(summands)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
CrossSectionSumAssign(ConstHandle2CrossSectionSum This, ConstHandle2ConstCrossSectionSum from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
CrossSectionSumDelete(ConstHandle2ConstCrossSectionSum This)
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
CrossSectionSumRead(ConstHandle2CrossSectionSum This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
CrossSectionSumWrite(ConstHandle2ConstCrossSectionSum This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
CrossSectionSumPrint(ConstHandle2ConstCrossSectionSum This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
CrossSectionSumPrintXML(ConstHandle2ConstCrossSectionSum This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
CrossSectionSumPrintJSON(ConstHandle2ConstCrossSectionSum This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: ENDF_MT
// -----------------------------------------------------------------------------

// Has
int
CrossSectionSumENDFMTHas(ConstHandle2ConstCrossSectionSum This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ENDFMTHas", This, extract::ENDF_MT);
}

// Get
// Returns by value
Integer32
CrossSectionSumENDFMTGet(ConstHandle2ConstCrossSectionSum This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ENDFMTGet", This, extract::ENDF_MT);
}

// Set
void
CrossSectionSumENDFMTSet(ConstHandle2CrossSectionSum This, const Integer32 ENDF_MT)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ENDFMTSet", This, extract::ENDF_MT, ENDF_MT);
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
CrossSectionSumLabelHas(ConstHandle2ConstCrossSectionSum This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
CrossSectionSumLabelGet(ConstHandle2ConstCrossSectionSum This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
CrossSectionSumLabelSet(ConstHandle2CrossSectionSum This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Child: Q
// -----------------------------------------------------------------------------

// Has
int
CrossSectionSumQHas(ConstHandle2ConstCrossSectionSum This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"QHas", This, extract::Q);
}

// Get, const
Handle2ConstQ
CrossSectionSumQGetConst(ConstHandle2ConstCrossSectionSum This)
{
   return detail::getField<CPP,Handle2ConstQ>
      (CLASSNAME, CLASSNAME+"QGetConst", This, extract::Q);
}

// Get, non-const
Handle2Q
CrossSectionSumQGet(ConstHandle2CrossSectionSum This)
{
   return detail::getField<CPP,Handle2Q>
      (CLASSNAME, CLASSNAME+"QGet", This, extract::Q);
}

// Set
void
CrossSectionSumQSet(ConstHandle2CrossSectionSum This, ConstHandle2ConstQ Q)
{
   detail::setField<CPP,CPPQ>
      (CLASSNAME, CLASSNAME+"QSet", This, extract::Q, Q);
}


// -----------------------------------------------------------------------------
// Child: crossSection
// -----------------------------------------------------------------------------

// Has
int
CrossSectionSumCrossSectionHas(ConstHandle2ConstCrossSectionSum This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CrossSectionHas", This, extract::crossSection);
}

// Get, const
Handle2ConstCrossSection
CrossSectionSumCrossSectionGetConst(ConstHandle2ConstCrossSectionSum This)
{
   return detail::getField<CPP,Handle2ConstCrossSection>
      (CLASSNAME, CLASSNAME+"CrossSectionGetConst", This, extract::crossSection);
}

// Get, non-const
Handle2CrossSection
CrossSectionSumCrossSectionGet(ConstHandle2CrossSectionSum This)
{
   return detail::getField<CPP,Handle2CrossSection>
      (CLASSNAME, CLASSNAME+"CrossSectionGet", This, extract::crossSection);
}

// Set
void
CrossSectionSumCrossSectionSet(ConstHandle2CrossSectionSum This, ConstHandle2ConstCrossSection crossSection)
{
   detail::setField<CPP,CPPCrossSection>
      (CLASSNAME, CLASSNAME+"CrossSectionSet", This, extract::crossSection, crossSection);
}


// -----------------------------------------------------------------------------
// Child: summands
// -----------------------------------------------------------------------------

// Has
int
CrossSectionSumSummandsHas(ConstHandle2ConstCrossSectionSum This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SummandsHas", This, extract::summands);
}

// Get, const
Handle2ConstSummands
CrossSectionSumSummandsGetConst(ConstHandle2ConstCrossSectionSum This)
{
   return detail::getField<CPP,Handle2ConstSummands>
      (CLASSNAME, CLASSNAME+"SummandsGetConst", This, extract::summands);
}

// Get, non-const
Handle2Summands
CrossSectionSumSummandsGet(ConstHandle2CrossSectionSum This)
{
   return detail::getField<CPP,Handle2Summands>
      (CLASSNAME, CLASSNAME+"SummandsGet", This, extract::summands);
}

// Set
void
CrossSectionSumSummandsSet(ConstHandle2CrossSectionSum This, ConstHandle2ConstSummands summands)
{
   detail::setField<CPP,CPPSummands>
      (CLASSNAME, CLASSNAME+"SummandsSet", This, extract::summands, summands);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/transport/CrossSectionSum/src/custom.cpp"
