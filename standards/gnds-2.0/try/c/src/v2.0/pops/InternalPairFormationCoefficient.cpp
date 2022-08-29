
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/pops/InternalPairFormationCoefficient.hpp"
#include "InternalPairFormationCoefficient.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = InternalPairFormationCoefficientClass;
using CPP = multigroup::InternalPairFormationCoefficient;

static const std::string CLASSNAME = "InternalPairFormationCoefficient";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto value = [](auto &obj) { return &obj.value; };
   static auto unit = [](auto &obj) { return &obj.unit; };
   static auto documentation = [](auto &obj) { return &obj.documentation; };
   static auto uncertainty = [](auto &obj) { return &obj.uncertainty; };
}

using CPPDocumentation = documentation::Documentation;
using CPPUncertainty = pops::Uncertainty;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstInternalPairFormationCoefficient
InternalPairFormationCoefficientDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2InternalPairFormationCoefficient
InternalPairFormationCoefficientDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstInternalPairFormationCoefficient
InternalPairFormationCoefficientCreateConst(
   const XMLName label,
   const Float64 value,
   const XMLName unit,
   ConstHandle2ConstDocumentation documentation,
   ConstHandle2ConstUncertainty uncertainty
) {
   ConstHandle2InternalPairFormationCoefficient handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      value,
      unit,
      detail::tocpp<CPPDocumentation>(documentation),
      detail::tocpp<CPPUncertainty>(uncertainty)
   );
   return handle;
}

// Create, general
Handle2InternalPairFormationCoefficient
InternalPairFormationCoefficientCreate(
   const XMLName label,
   const Float64 value,
   const XMLName unit,
   ConstHandle2ConstDocumentation documentation,
   ConstHandle2ConstUncertainty uncertainty
) {
   ConstHandle2InternalPairFormationCoefficient handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      value,
      unit,
      detail::tocpp<CPPDocumentation>(documentation),
      detail::tocpp<CPPUncertainty>(uncertainty)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
InternalPairFormationCoefficientAssign(ConstHandle2InternalPairFormationCoefficient This, ConstHandle2ConstInternalPairFormationCoefficient from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
InternalPairFormationCoefficientDelete(ConstHandle2ConstInternalPairFormationCoefficient This)
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
InternalPairFormationCoefficientRead(ConstHandle2InternalPairFormationCoefficient This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
InternalPairFormationCoefficientWrite(ConstHandle2ConstInternalPairFormationCoefficient This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
InternalPairFormationCoefficientPrint(ConstHandle2ConstInternalPairFormationCoefficient This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
InternalPairFormationCoefficientPrintXML(ConstHandle2ConstInternalPairFormationCoefficient This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
InternalPairFormationCoefficientPrintJSON(ConstHandle2ConstInternalPairFormationCoefficient This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
InternalPairFormationCoefficientLabelHas(ConstHandle2ConstInternalPairFormationCoefficient This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
InternalPairFormationCoefficientLabelGet(ConstHandle2ConstInternalPairFormationCoefficient This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
InternalPairFormationCoefficientLabelSet(ConstHandle2InternalPairFormationCoefficient This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// Has
int
InternalPairFormationCoefficientValueHas(ConstHandle2ConstInternalPairFormationCoefficient This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ValueHas", This, extract::value);
}

// Get
// Returns by value
Float64
InternalPairFormationCoefficientValueGet(ConstHandle2ConstInternalPairFormationCoefficient This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ValueGet", This, extract::value);
}

// Set
void
InternalPairFormationCoefficientValueSet(ConstHandle2InternalPairFormationCoefficient This, const Float64 value)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ValueSet", This, extract::value, value);
}


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// Has
int
InternalPairFormationCoefficientUnitHas(ConstHandle2ConstInternalPairFormationCoefficient This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UnitHas", This, extract::unit);
}

// Get
// Returns by value
XMLName
InternalPairFormationCoefficientUnitGet(ConstHandle2ConstInternalPairFormationCoefficient This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"UnitGet", This, extract::unit);
}

// Set
void
InternalPairFormationCoefficientUnitSet(ConstHandle2InternalPairFormationCoefficient This, const XMLName unit)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"UnitSet", This, extract::unit, unit);
}


// -----------------------------------------------------------------------------
// Child: documentation
// -----------------------------------------------------------------------------

// Has
int
InternalPairFormationCoefficientDocumentationHas(ConstHandle2ConstInternalPairFormationCoefficient This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DocumentationHas", This, extract::documentation);
}

// Get, const
Handle2ConstDocumentation
InternalPairFormationCoefficientDocumentationGetConst(ConstHandle2ConstInternalPairFormationCoefficient This)
{
   return detail::getField<CPP,Handle2ConstDocumentation>
      (CLASSNAME, CLASSNAME+"DocumentationGetConst", This, extract::documentation);
}

// Get, non-const
Handle2Documentation
InternalPairFormationCoefficientDocumentationGet(ConstHandle2InternalPairFormationCoefficient This)
{
   return detail::getField<CPP,Handle2Documentation>
      (CLASSNAME, CLASSNAME+"DocumentationGet", This, extract::documentation);
}

// Set
void
InternalPairFormationCoefficientDocumentationSet(ConstHandle2InternalPairFormationCoefficient This, ConstHandle2ConstDocumentation documentation)
{
   detail::setField<CPP,CPPDocumentation>
      (CLASSNAME, CLASSNAME+"DocumentationSet", This, extract::documentation, documentation);
}


// -----------------------------------------------------------------------------
// Child: uncertainty
// -----------------------------------------------------------------------------

// Has
int
InternalPairFormationCoefficientUncertaintyHas(ConstHandle2ConstInternalPairFormationCoefficient This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UncertaintyHas", This, extract::uncertainty);
}

// Get, const
Handle2ConstUncertainty
InternalPairFormationCoefficientUncertaintyGetConst(ConstHandle2ConstInternalPairFormationCoefficient This)
{
   return detail::getField<CPP,Handle2ConstUncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintyGetConst", This, extract::uncertainty);
}

// Get, non-const
Handle2Uncertainty
InternalPairFormationCoefficientUncertaintyGet(ConstHandle2InternalPairFormationCoefficient This)
{
   return detail::getField<CPP,Handle2Uncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintyGet", This, extract::uncertainty);
}

// Set
void
InternalPairFormationCoefficientUncertaintySet(ConstHandle2InternalPairFormationCoefficient This, ConstHandle2ConstUncertainty uncertainty)
{
   detail::setField<CPP,CPPUncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintySet", This, extract::uncertainty, uncertainty);
}
