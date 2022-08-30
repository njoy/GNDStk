
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/pops/Spin.hpp"
#include "Spin.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = SpinClass;
using CPP = multigroup::Spin;

static const std::string CLASSNAME = "Spin";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto unit = [](auto &obj) { return &obj.unit; };
   static auto value = [](auto &obj) { return &obj.value; };
   static auto documentation = [](auto &obj) { return &obj.documentation; };
   static auto uncertainty = [](auto &obj) { return &obj.uncertainty; };
   static auto fraction = [](auto &obj) { return &obj.fraction; };
}

using CPPDocumentation = documentation::Documentation;
using CPPUncertainty = pops::Uncertainty;
using CPPFraction = containers::Fraction;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstSpin
SpinDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Spin
SpinDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstSpin
SpinCreateConst(
   const XMLName label,
   const XMLName unit,
   const XMLName value,
   ConstHandle2ConstDocumentation documentation,
   ConstHandle2ConstUncertainty uncertainty,
   ConstHandle2Fraction *const fraction, const size_t fractionSize
) {
   ConstHandle2Spin handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      unit,
      value,
      detail::tocpp<CPPDocumentation>(documentation),
      detail::tocpp<CPPUncertainty>(uncertainty),
      std::vector<CPPFraction>{}
   );
   for (size_t FractionN = 0; FractionN < fractionSize; ++FractionN)
      SpinFractionAdd(handle, fraction[FractionN]);
   return handle;
}

// Create, general
Handle2Spin
SpinCreate(
   const XMLName label,
   const XMLName unit,
   const XMLName value,
   ConstHandle2ConstDocumentation documentation,
   ConstHandle2ConstUncertainty uncertainty,
   ConstHandle2Fraction *const fraction, const size_t fractionSize
) {
   ConstHandle2Spin handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      unit,
      value,
      detail::tocpp<CPPDocumentation>(documentation),
      detail::tocpp<CPPUncertainty>(uncertainty),
      std::vector<CPPFraction>{}
   );
   for (size_t FractionN = 0; FractionN < fractionSize; ++FractionN)
      SpinFractionAdd(handle, fraction[FractionN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
SpinAssign(ConstHandle2Spin This, ConstHandle2ConstSpin from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
SpinDelete(ConstHandle2ConstSpin This)
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
SpinRead(ConstHandle2Spin This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
SpinWrite(ConstHandle2ConstSpin This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
SpinPrint(ConstHandle2ConstSpin This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
SpinPrintXML(ConstHandle2ConstSpin This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
SpinPrintJSON(ConstHandle2ConstSpin This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
SpinLabelHas(ConstHandle2ConstSpin This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
SpinLabelGet(ConstHandle2ConstSpin This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
SpinLabelSet(ConstHandle2Spin This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// Has
int
SpinUnitHas(ConstHandle2ConstSpin This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UnitHas", This, extract::unit);
}

// Get
// Returns by value
XMLName
SpinUnitGet(ConstHandle2ConstSpin This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"UnitGet", This, extract::unit);
}

// Set
void
SpinUnitSet(ConstHandle2Spin This, const XMLName unit)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"UnitSet", This, extract::unit, unit);
}


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// Has
int
SpinValueHas(ConstHandle2ConstSpin This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ValueHas", This, extract::value);
}

// Get
// Returns by value
XMLName
SpinValueGet(ConstHandle2ConstSpin This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ValueGet", This, extract::value);
}

// Set
void
SpinValueSet(ConstHandle2Spin This, const XMLName value)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ValueSet", This, extract::value, value);
}


// -----------------------------------------------------------------------------
// Child: documentation
// -----------------------------------------------------------------------------

// Has
int
SpinDocumentationHas(ConstHandle2ConstSpin This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DocumentationHas", This, extract::documentation);
}

// Get, const
Handle2ConstDocumentation
SpinDocumentationGetConst(ConstHandle2ConstSpin This)
{
   return detail::getField<CPP,Handle2ConstDocumentation>
      (CLASSNAME, CLASSNAME+"DocumentationGetConst", This, extract::documentation);
}

// Get, non-const
Handle2Documentation
SpinDocumentationGet(ConstHandle2Spin This)
{
   return detail::getField<CPP,Handle2Documentation>
      (CLASSNAME, CLASSNAME+"DocumentationGet", This, extract::documentation);
}

// Set
void
SpinDocumentationSet(ConstHandle2Spin This, ConstHandle2ConstDocumentation documentation)
{
   detail::setField<CPP,CPPDocumentation>
      (CLASSNAME, CLASSNAME+"DocumentationSet", This, extract::documentation, documentation);
}


// -----------------------------------------------------------------------------
// Child: uncertainty
// -----------------------------------------------------------------------------

// Has
int
SpinUncertaintyHas(ConstHandle2ConstSpin This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UncertaintyHas", This, extract::uncertainty);
}

// Get, const
Handle2ConstUncertainty
SpinUncertaintyGetConst(ConstHandle2ConstSpin This)
{
   return detail::getField<CPP,Handle2ConstUncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintyGetConst", This, extract::uncertainty);
}

// Get, non-const
Handle2Uncertainty
SpinUncertaintyGet(ConstHandle2Spin This)
{
   return detail::getField<CPP,Handle2Uncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintyGet", This, extract::uncertainty);
}

// Set
void
SpinUncertaintySet(ConstHandle2Spin This, ConstHandle2ConstUncertainty uncertainty)
{
   detail::setField<CPP,CPPUncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintySet", This, extract::uncertainty, uncertainty);
}


// -----------------------------------------------------------------------------
// Child: fraction
// -----------------------------------------------------------------------------

// Has
int
SpinFractionHas(ConstHandle2ConstSpin This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"FractionHas", This, extract::fraction);
}

// Clear
void
SpinFractionClear(ConstHandle2Spin This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"FractionClear", This, extract::fraction);
}

// Size
size_t
SpinFractionSize(ConstHandle2ConstSpin This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"FractionSize", This, extract::fraction);
}

// Add
void
SpinFractionAdd(ConstHandle2Spin This, ConstHandle2ConstFraction fraction)
{
   detail::addToContainer<CPP,CPPFraction>
      (CLASSNAME, CLASSNAME+"FractionAdd", This, extract::fraction, fraction);
}

// Get, by index \in [0,size), const
Handle2ConstFraction
SpinFractionGetConst(ConstHandle2ConstSpin This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstFraction>
      (CLASSNAME, CLASSNAME+"FractionGetConst", This, extract::fraction, index_);
}

// Get, by index \in [0,size), non-const
Handle2Fraction
SpinFractionGet(ConstHandle2Spin This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Fraction>
      (CLASSNAME, CLASSNAME+"FractionGet", This, extract::fraction, index_);
}

// Set, by index \in [0,size)
void
SpinFractionSet(
   ConstHandle2Spin This,
   const size_t index_,
   ConstHandle2ConstFraction fraction
) {
   detail::setByIndex<CPP,CPPFraction>
      (CLASSNAME, CLASSNAME+"FractionSet", This, extract::fraction, index_, fraction);
}

// Has, by label
int
SpinFractionHasByLabel(
   ConstHandle2ConstSpin This,
   const XMLName label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"FractionHasByLabel",
       This, extract::fraction, meta::label, label);
}

// Get, by label, const
Handle2ConstFraction
SpinFractionGetByLabelConst(
   ConstHandle2ConstSpin This,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2ConstFraction>
      (CLASSNAME, CLASSNAME+"FractionGetByLabelConst",
       This, extract::fraction, meta::label, label);
}

// Get, by label, non-const
Handle2Fraction
SpinFractionGetByLabel(
   ConstHandle2Spin This,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2Fraction>
      (CLASSNAME, CLASSNAME+"FractionGetByLabel",
       This, extract::fraction, meta::label, label);
}

// Set, by label
void
SpinFractionSetByLabel(
   ConstHandle2Spin This,
   const XMLName label,
   ConstHandle2ConstFraction fraction
) {
   detail::setByMetadatum<CPP,CPPFraction>
      (CLASSNAME, CLASSNAME+"FractionSetByLabel",
       This, extract::fraction, meta::label, label, fraction);
}

// Has, by unit
int
SpinFractionHasByUnit(
   ConstHandle2ConstSpin This,
   const XMLName unit
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"FractionHasByUnit",
       This, extract::fraction, meta::unit, unit);
}

// Get, by unit, const
Handle2ConstFraction
SpinFractionGetByUnitConst(
   ConstHandle2ConstSpin This,
   const XMLName unit
) {
   return detail::getByMetadatum<CPP,Handle2ConstFraction>
      (CLASSNAME, CLASSNAME+"FractionGetByUnitConst",
       This, extract::fraction, meta::unit, unit);
}

// Get, by unit, non-const
Handle2Fraction
SpinFractionGetByUnit(
   ConstHandle2Spin This,
   const XMLName unit
) {
   return detail::getByMetadatum<CPP,Handle2Fraction>
      (CLASSNAME, CLASSNAME+"FractionGetByUnit",
       This, extract::fraction, meta::unit, unit);
}

// Set, by unit
void
SpinFractionSetByUnit(
   ConstHandle2Spin This,
   const XMLName unit,
   ConstHandle2ConstFraction fraction
) {
   detail::setByMetadatum<CPP,CPPFraction>
      (CLASSNAME, CLASSNAME+"FractionSetByUnit",
       This, extract::fraction, meta::unit, unit, fraction);
}

// Has, by value
int
SpinFractionHasByValue(
   ConstHandle2ConstSpin This,
   const Fraction32 value
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"FractionHasByValue",
       This, extract::fraction, meta::value, value);
}

// Get, by value, const
Handle2ConstFraction
SpinFractionGetByValueConst(
   ConstHandle2ConstSpin This,
   const Fraction32 value
) {
   return detail::getByMetadatum<CPP,Handle2ConstFraction>
      (CLASSNAME, CLASSNAME+"FractionGetByValueConst",
       This, extract::fraction, meta::value, value);
}

// Get, by value, non-const
Handle2Fraction
SpinFractionGetByValue(
   ConstHandle2Spin This,
   const Fraction32 value
) {
   return detail::getByMetadatum<CPP,Handle2Fraction>
      (CLASSNAME, CLASSNAME+"FractionGetByValue",
       This, extract::fraction, meta::value, value);
}

// Set, by value
void
SpinFractionSetByValue(
   ConstHandle2Spin This,
   const Fraction32 value,
   ConstHandle2ConstFraction fraction
) {
   detail::setByMetadatum<CPP,CPPFraction>
      (CLASSNAME, CLASSNAME+"FractionSetByValue",
       This, extract::fraction, meta::value, value, fraction);
}
