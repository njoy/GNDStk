
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/styles/MultiBand.hpp"
#include "MultiBand.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = MultiBandClass;
using CPP = multigroup::MultiBand;

static const std::string CLASSNAME = "MultiBand";

namespace extract {
   static auto date = [](auto &obj) { return &obj.date; };
   static auto derivedFrom = [](auto &obj) { return &obj.derivedFrom; };
   static auto label = [](auto &obj) { return &obj.label; };
   static auto numberOfBands = [](auto &obj) { return &obj.numberOfBands; };
   static auto documentation = [](auto &obj) { return &obj.documentation; };
}

using CPPDocumentation = documentation::Documentation;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstMultiBand
MultiBandDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2MultiBand
MultiBandDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstMultiBand
MultiBandCreateConst(
   const char *const date,
   const XMLName derivedFrom,
   const XMLName label,
   const Integer32 numberOfBands,
   ConstHandle2ConstDocumentation documentation
) {
   ConstHandle2MultiBand handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      date,
      derivedFrom,
      label,
      numberOfBands,
      detail::tocpp<CPPDocumentation>(documentation)
   );
   return handle;
}

// Create, general
Handle2MultiBand
MultiBandCreate(
   const char *const date,
   const XMLName derivedFrom,
   const XMLName label,
   const Integer32 numberOfBands,
   ConstHandle2ConstDocumentation documentation
) {
   ConstHandle2MultiBand handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      date,
      derivedFrom,
      label,
      numberOfBands,
      detail::tocpp<CPPDocumentation>(documentation)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
MultiBandAssign(ConstHandle2MultiBand self, ConstHandle2ConstMultiBand from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
MultiBandDelete(ConstHandle2ConstMultiBand self)
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
MultiBandRead(ConstHandle2MultiBand self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
MultiBandWrite(ConstHandle2ConstMultiBand self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
MultiBandPrint(ConstHandle2ConstMultiBand self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
MultiBandPrintXML(ConstHandle2ConstMultiBand self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
MultiBandPrintJSON(ConstHandle2ConstMultiBand self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: date
// -----------------------------------------------------------------------------

// Has
int
MultiBandDateHas(ConstHandle2ConstMultiBand self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DateHas", self, extract::date);
}

// Get
// Returns by value
const char *
MultiBandDateGet(ConstHandle2ConstMultiBand self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DateGet", self, extract::date);
}

// Set
void
MultiBandDateSet(ConstHandle2MultiBand self, const char *const date)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DateSet", self, extract::date, date);
}


// -----------------------------------------------------------------------------
// Metadatum: derivedFrom
// -----------------------------------------------------------------------------

// Has
int
MultiBandDerivedFromHas(ConstHandle2ConstMultiBand self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DerivedFromHas", self, extract::derivedFrom);
}

// Get
// Returns by value
XMLName
MultiBandDerivedFromGet(ConstHandle2ConstMultiBand self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DerivedFromGet", self, extract::derivedFrom);
}

// Set
void
MultiBandDerivedFromSet(ConstHandle2MultiBand self, const XMLName derivedFrom)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DerivedFromSet", self, extract::derivedFrom, derivedFrom);
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
MultiBandLabelHas(ConstHandle2ConstMultiBand self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
XMLName
MultiBandLabelGet(ConstHandle2ConstMultiBand self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
MultiBandLabelSet(ConstHandle2MultiBand self, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: numberOfBands
// -----------------------------------------------------------------------------

// Has
int
MultiBandNumberOfBandsHas(ConstHandle2ConstMultiBand self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"NumberOfBandsHas", self, extract::numberOfBands);
}

// Get
// Returns by value
Integer32
MultiBandNumberOfBandsGet(ConstHandle2ConstMultiBand self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"NumberOfBandsGet", self, extract::numberOfBands);
}

// Set
void
MultiBandNumberOfBandsSet(ConstHandle2MultiBand self, const Integer32 numberOfBands)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"NumberOfBandsSet", self, extract::numberOfBands, numberOfBands);
}


// -----------------------------------------------------------------------------
// Child: documentation
// -----------------------------------------------------------------------------

// Has
int
MultiBandDocumentationHas(ConstHandle2ConstMultiBand self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DocumentationHas", self, extract::documentation);
}

// Get, const
Handle2ConstDocumentation
MultiBandDocumentationGetConst(ConstHandle2ConstMultiBand self)
{
   return detail::getField<CPP,Handle2ConstDocumentation>
      (CLASSNAME, CLASSNAME+"DocumentationGetConst", self, extract::documentation);
}

// Get, non-const
Handle2Documentation
MultiBandDocumentationGet(ConstHandle2MultiBand self)
{
   return detail::getField<CPP,Handle2Documentation>
      (CLASSNAME, CLASSNAME+"DocumentationGet", self, extract::documentation);
}

// Set
void
MultiBandDocumentationSet(ConstHandle2MultiBand self, ConstHandle2ConstDocumentation documentation)
{
   detail::setField<CPP,CPPDocumentation>
      (CLASSNAME, CLASSNAME+"DocumentationSet", self, extract::documentation, documentation);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/styles/MultiBand/src/custom.cpp"
