
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/styles/AngularDistributionReconstructed.hpp"
#include "AngularDistributionReconstructed.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = AngularDistributionReconstructedClass;
using CPP = multigroup::AngularDistributionReconstructed;

static const std::string CLASSNAME = "AngularDistributionReconstructed";

namespace extract {
   static auto date = [](auto &obj) { return &obj.date; };
   static auto label = [](auto &obj) { return &obj.label; };
   static auto derivedFrom = [](auto &obj) { return &obj.derivedFrom; };
   static auto temperature = [](auto &obj) { return &obj.temperature; };
   static auto documentation = [](auto &obj) { return &obj.documentation; };
}

using CPPTemperature = styles::Temperature;
using CPPDocumentation = documentation::Documentation;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstAngularDistributionReconstructed
AngularDistributionReconstructedDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2AngularDistributionReconstructed
AngularDistributionReconstructedDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstAngularDistributionReconstructed
AngularDistributionReconstructedCreateConst(
   const char *const date,
   const XMLName label,
   const XMLName derivedFrom,
   ConstHandle2ConstTemperature temperature,
   ConstHandle2ConstDocumentation documentation
) {
   ConstHandle2AngularDistributionReconstructed handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      date,
      label,
      derivedFrom,
      detail::tocpp<CPPTemperature>(temperature),
      detail::tocpp<CPPDocumentation>(documentation)
   );
   return handle;
}

// Create, general
Handle2AngularDistributionReconstructed
AngularDistributionReconstructedCreate(
   const char *const date,
   const XMLName label,
   const XMLName derivedFrom,
   ConstHandle2ConstTemperature temperature,
   ConstHandle2ConstDocumentation documentation
) {
   ConstHandle2AngularDistributionReconstructed handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      date,
      label,
      derivedFrom,
      detail::tocpp<CPPTemperature>(temperature),
      detail::tocpp<CPPDocumentation>(documentation)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
AngularDistributionReconstructedAssign(ConstHandle2AngularDistributionReconstructed This, ConstHandle2ConstAngularDistributionReconstructed from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
AngularDistributionReconstructedDelete(ConstHandle2ConstAngularDistributionReconstructed This)
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
AngularDistributionReconstructedRead(ConstHandle2AngularDistributionReconstructed This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
AngularDistributionReconstructedWrite(ConstHandle2ConstAngularDistributionReconstructed This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
AngularDistributionReconstructedPrint(ConstHandle2ConstAngularDistributionReconstructed This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
AngularDistributionReconstructedPrintXML(ConstHandle2ConstAngularDistributionReconstructed This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
AngularDistributionReconstructedPrintJSON(ConstHandle2ConstAngularDistributionReconstructed This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: date
// -----------------------------------------------------------------------------

// Has
int
AngularDistributionReconstructedDateHas(ConstHandle2ConstAngularDistributionReconstructed This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DateHas", This, extract::date);
}

// Get
// Returns by value
const char *
AngularDistributionReconstructedDateGet(ConstHandle2ConstAngularDistributionReconstructed This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DateGet", This, extract::date);
}

// Set
void
AngularDistributionReconstructedDateSet(ConstHandle2AngularDistributionReconstructed This, const char *const date)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DateSet", This, extract::date, date);
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
AngularDistributionReconstructedLabelHas(ConstHandle2ConstAngularDistributionReconstructed This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
AngularDistributionReconstructedLabelGet(ConstHandle2ConstAngularDistributionReconstructed This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
AngularDistributionReconstructedLabelSet(ConstHandle2AngularDistributionReconstructed This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: derivedFrom
// -----------------------------------------------------------------------------

// Has
int
AngularDistributionReconstructedDerivedFromHas(ConstHandle2ConstAngularDistributionReconstructed This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DerivedFromHas", This, extract::derivedFrom);
}

// Get
// Returns by value
XMLName
AngularDistributionReconstructedDerivedFromGet(ConstHandle2ConstAngularDistributionReconstructed This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DerivedFromGet", This, extract::derivedFrom);
}

// Set
void
AngularDistributionReconstructedDerivedFromSet(ConstHandle2AngularDistributionReconstructed This, const XMLName derivedFrom)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DerivedFromSet", This, extract::derivedFrom, derivedFrom);
}


// -----------------------------------------------------------------------------
// Child: temperature
// -----------------------------------------------------------------------------

// Has
int
AngularDistributionReconstructedTemperatureHas(ConstHandle2ConstAngularDistributionReconstructed This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"TemperatureHas", This, extract::temperature);
}

// Get, const
Handle2ConstTemperature
AngularDistributionReconstructedTemperatureGetConst(ConstHandle2ConstAngularDistributionReconstructed This)
{
   return detail::getField<CPP,Handle2ConstTemperature>
      (CLASSNAME, CLASSNAME+"TemperatureGetConst", This, extract::temperature);
}

// Get, non-const
Handle2Temperature
AngularDistributionReconstructedTemperatureGet(ConstHandle2AngularDistributionReconstructed This)
{
   return detail::getField<CPP,Handle2Temperature>
      (CLASSNAME, CLASSNAME+"TemperatureGet", This, extract::temperature);
}

// Set
void
AngularDistributionReconstructedTemperatureSet(ConstHandle2AngularDistributionReconstructed This, ConstHandle2ConstTemperature temperature)
{
   detail::setField<CPP,CPPTemperature>
      (CLASSNAME, CLASSNAME+"TemperatureSet", This, extract::temperature, temperature);
}


// -----------------------------------------------------------------------------
// Child: documentation
// -----------------------------------------------------------------------------

// Has
int
AngularDistributionReconstructedDocumentationHas(ConstHandle2ConstAngularDistributionReconstructed This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DocumentationHas", This, extract::documentation);
}

// Get, const
Handle2ConstDocumentation
AngularDistributionReconstructedDocumentationGetConst(ConstHandle2ConstAngularDistributionReconstructed This)
{
   return detail::getField<CPP,Handle2ConstDocumentation>
      (CLASSNAME, CLASSNAME+"DocumentationGetConst", This, extract::documentation);
}

// Get, non-const
Handle2Documentation
AngularDistributionReconstructedDocumentationGet(ConstHandle2AngularDistributionReconstructed This)
{
   return detail::getField<CPP,Handle2Documentation>
      (CLASSNAME, CLASSNAME+"DocumentationGet", This, extract::documentation);
}

// Set
void
AngularDistributionReconstructedDocumentationSet(ConstHandle2AngularDistributionReconstructed This, ConstHandle2ConstDocumentation documentation)
{
   detail::setField<CPP,CPPDocumentation>
      (CLASSNAME, CLASSNAME+"DocumentationSet", This, extract::documentation, documentation);
}
