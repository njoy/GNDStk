
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/pops/BindingEnergy.hpp"
#include "BindingEnergy.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = BindingEnergyClass;
using CPP = multigroup::BindingEnergy;

static const std::string CLASSNAME = "BindingEnergy";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto unit = [](auto &obj) { return &obj.unit; };
   static auto value = [](auto &obj) { return &obj.value; };
   static auto documentation = [](auto &obj) { return &obj.documentation; };
   static auto uncertainty = [](auto &obj) { return &obj.uncertainty; };
   static auto Double = [](auto &obj) { return &obj.Double; };
}

using CPPDocumentation = documentation::Documentation;
using CPPUncertainty = pops::Uncertainty;
using CPPDouble = containers::Double;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstBindingEnergy
BindingEnergyDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2BindingEnergy
BindingEnergyDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstBindingEnergy
BindingEnergyCreateConst(
   const XMLName label,
   const XMLName unit,
   const XMLName value,
   ConstHandle2ConstDocumentation documentation,
   ConstHandle2ConstUncertainty uncertainty,
   ConstHandle2Double *const Double, const size_t DoubleSize
) {
   ConstHandle2BindingEnergy handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      unit,
      value,
      detail::tocpp<CPPDocumentation>(documentation),
      detail::tocpp<CPPUncertainty>(uncertainty),
      std::vector<CPPDouble>{}
   );
   for (size_t DoubleN = 0; DoubleN < DoubleSize; ++DoubleN)
      BindingEnergyDoubleAdd(handle, Double[DoubleN]);
   return handle;
}

// Create, general
Handle2BindingEnergy
BindingEnergyCreate(
   const XMLName label,
   const XMLName unit,
   const XMLName value,
   ConstHandle2ConstDocumentation documentation,
   ConstHandle2ConstUncertainty uncertainty,
   ConstHandle2Double *const Double, const size_t DoubleSize
) {
   ConstHandle2BindingEnergy handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      unit,
      value,
      detail::tocpp<CPPDocumentation>(documentation),
      detail::tocpp<CPPUncertainty>(uncertainty),
      std::vector<CPPDouble>{}
   );
   for (size_t DoubleN = 0; DoubleN < DoubleSize; ++DoubleN)
      BindingEnergyDoubleAdd(handle, Double[DoubleN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
BindingEnergyAssign(ConstHandle2BindingEnergy This, ConstHandle2ConstBindingEnergy from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
BindingEnergyDelete(ConstHandle2ConstBindingEnergy This)
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
BindingEnergyRead(ConstHandle2BindingEnergy This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
BindingEnergyWrite(ConstHandle2ConstBindingEnergy This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
BindingEnergyPrint(ConstHandle2ConstBindingEnergy This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
BindingEnergyPrintXML(ConstHandle2ConstBindingEnergy This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
BindingEnergyPrintJSON(ConstHandle2ConstBindingEnergy This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
BindingEnergyLabelHas(ConstHandle2ConstBindingEnergy This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
BindingEnergyLabelGet(ConstHandle2ConstBindingEnergy This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
BindingEnergyLabelSet(ConstHandle2BindingEnergy This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// Has
int
BindingEnergyUnitHas(ConstHandle2ConstBindingEnergy This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UnitHas", This, extract::unit);
}

// Get
// Returns by value
XMLName
BindingEnergyUnitGet(ConstHandle2ConstBindingEnergy This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"UnitGet", This, extract::unit);
}

// Set
void
BindingEnergyUnitSet(ConstHandle2BindingEnergy This, const XMLName unit)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"UnitSet", This, extract::unit, unit);
}


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// Has
int
BindingEnergyValueHas(ConstHandle2ConstBindingEnergy This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ValueHas", This, extract::value);
}

// Get
// Returns by value
XMLName
BindingEnergyValueGet(ConstHandle2ConstBindingEnergy This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ValueGet", This, extract::value);
}

// Set
void
BindingEnergyValueSet(ConstHandle2BindingEnergy This, const XMLName value)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ValueSet", This, extract::value, value);
}


// -----------------------------------------------------------------------------
// Child: documentation
// -----------------------------------------------------------------------------

// Has
int
BindingEnergyDocumentationHas(ConstHandle2ConstBindingEnergy This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DocumentationHas", This, extract::documentation);
}

// Get, const
Handle2ConstDocumentation
BindingEnergyDocumentationGetConst(ConstHandle2ConstBindingEnergy This)
{
   return detail::getField<CPP,Handle2ConstDocumentation>
      (CLASSNAME, CLASSNAME+"DocumentationGetConst", This, extract::documentation);
}

// Get, non-const
Handle2Documentation
BindingEnergyDocumentationGet(ConstHandle2BindingEnergy This)
{
   return detail::getField<CPP,Handle2Documentation>
      (CLASSNAME, CLASSNAME+"DocumentationGet", This, extract::documentation);
}

// Set
void
BindingEnergyDocumentationSet(ConstHandle2BindingEnergy This, ConstHandle2ConstDocumentation documentation)
{
   detail::setField<CPP,CPPDocumentation>
      (CLASSNAME, CLASSNAME+"DocumentationSet", This, extract::documentation, documentation);
}


// -----------------------------------------------------------------------------
// Child: uncertainty
// -----------------------------------------------------------------------------

// Has
int
BindingEnergyUncertaintyHas(ConstHandle2ConstBindingEnergy This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UncertaintyHas", This, extract::uncertainty);
}

// Get, const
Handle2ConstUncertainty
BindingEnergyUncertaintyGetConst(ConstHandle2ConstBindingEnergy This)
{
   return detail::getField<CPP,Handle2ConstUncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintyGetConst", This, extract::uncertainty);
}

// Get, non-const
Handle2Uncertainty
BindingEnergyUncertaintyGet(ConstHandle2BindingEnergy This)
{
   return detail::getField<CPP,Handle2Uncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintyGet", This, extract::uncertainty);
}

// Set
void
BindingEnergyUncertaintySet(ConstHandle2BindingEnergy This, ConstHandle2ConstUncertainty uncertainty)
{
   detail::setField<CPP,CPPUncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintySet", This, extract::uncertainty, uncertainty);
}


// -----------------------------------------------------------------------------
// Child: Double
// -----------------------------------------------------------------------------

// Has
int
BindingEnergyDoubleHas(ConstHandle2ConstBindingEnergy This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DoubleHas", This, extract::Double);
}

// Clear
void
BindingEnergyDoubleClear(ConstHandle2BindingEnergy This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"DoubleClear", This, extract::Double);
}

// Size
size_t
BindingEnergyDoubleSize(ConstHandle2ConstBindingEnergy This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"DoubleSize", This, extract::Double);
}

// Add
void
BindingEnergyDoubleAdd(ConstHandle2BindingEnergy This, ConstHandle2ConstDouble Double)
{
   detail::addToContainer<CPP,CPPDouble>
      (CLASSNAME, CLASSNAME+"DoubleAdd", This, extract::Double, Double);
}

// Get, by index \in [0,size), const
Handle2ConstDouble
BindingEnergyDoubleGetConst(ConstHandle2ConstBindingEnergy This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstDouble>
      (CLASSNAME, CLASSNAME+"DoubleGetConst", This, extract::Double, index_);
}

// Get, by index \in [0,size), non-const
Handle2Double
BindingEnergyDoubleGet(ConstHandle2BindingEnergy This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Double>
      (CLASSNAME, CLASSNAME+"DoubleGet", This, extract::Double, index_);
}

// Set, by index \in [0,size)
void
BindingEnergyDoubleSet(
   ConstHandle2BindingEnergy This,
   const size_t index_,
   ConstHandle2ConstDouble Double
) {
   detail::setByIndex<CPP,CPPDouble>
      (CLASSNAME, CLASSNAME+"DoubleSet", This, extract::Double, index_, Double);
}

// Has, by label
int
BindingEnergyDoubleHasByLabel(
   ConstHandle2ConstBindingEnergy This,
   const XMLName label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"DoubleHasByLabel",
       This, extract::Double, meta::label, label);
}

// Get, by label, const
Handle2ConstDouble
BindingEnergyDoubleGetByLabelConst(
   ConstHandle2ConstBindingEnergy This,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2ConstDouble>
      (CLASSNAME, CLASSNAME+"DoubleGetByLabelConst",
       This, extract::Double, meta::label, label);
}

// Get, by label, non-const
Handle2Double
BindingEnergyDoubleGetByLabel(
   ConstHandle2BindingEnergy This,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2Double>
      (CLASSNAME, CLASSNAME+"DoubleGetByLabel",
       This, extract::Double, meta::label, label);
}

// Set, by label
void
BindingEnergyDoubleSetByLabel(
   ConstHandle2BindingEnergy This,
   const XMLName label,
   ConstHandle2ConstDouble Double
) {
   detail::setByMetadatum<CPP,CPPDouble>
      (CLASSNAME, CLASSNAME+"DoubleSetByLabel",
       This, extract::Double, meta::label, label, Double);
}

// Has, by unit
int
BindingEnergyDoubleHasByUnit(
   ConstHandle2ConstBindingEnergy This,
   const XMLName unit
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"DoubleHasByUnit",
       This, extract::Double, meta::unit, unit);
}

// Get, by unit, const
Handle2ConstDouble
BindingEnergyDoubleGetByUnitConst(
   ConstHandle2ConstBindingEnergy This,
   const XMLName unit
) {
   return detail::getByMetadatum<CPP,Handle2ConstDouble>
      (CLASSNAME, CLASSNAME+"DoubleGetByUnitConst",
       This, extract::Double, meta::unit, unit);
}

// Get, by unit, non-const
Handle2Double
BindingEnergyDoubleGetByUnit(
   ConstHandle2BindingEnergy This,
   const XMLName unit
) {
   return detail::getByMetadatum<CPP,Handle2Double>
      (CLASSNAME, CLASSNAME+"DoubleGetByUnit",
       This, extract::Double, meta::unit, unit);
}

// Set, by unit
void
BindingEnergyDoubleSetByUnit(
   ConstHandle2BindingEnergy This,
   const XMLName unit,
   ConstHandle2ConstDouble Double
) {
   detail::setByMetadatum<CPP,CPPDouble>
      (CLASSNAME, CLASSNAME+"DoubleSetByUnit",
       This, extract::Double, meta::unit, unit, Double);
}

// Has, by value
int
BindingEnergyDoubleHasByValue(
   ConstHandle2ConstBindingEnergy This,
   const Float64 value
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"DoubleHasByValue",
       This, extract::Double, meta::value, value);
}

// Get, by value, const
Handle2ConstDouble
BindingEnergyDoubleGetByValueConst(
   ConstHandle2ConstBindingEnergy This,
   const Float64 value
) {
   return detail::getByMetadatum<CPP,Handle2ConstDouble>
      (CLASSNAME, CLASSNAME+"DoubleGetByValueConst",
       This, extract::Double, meta::value, value);
}

// Get, by value, non-const
Handle2Double
BindingEnergyDoubleGetByValue(
   ConstHandle2BindingEnergy This,
   const Float64 value
) {
   return detail::getByMetadatum<CPP,Handle2Double>
      (CLASSNAME, CLASSNAME+"DoubleGetByValue",
       This, extract::Double, meta::value, value);
}

// Set, by value
void
BindingEnergyDoubleSetByValue(
   ConstHandle2BindingEnergy This,
   const Float64 value,
   ConstHandle2ConstDouble Double
) {
   detail::setByMetadatum<CPP,CPPDouble>
      (CLASSNAME, CLASSNAME+"DoubleSetByValue",
       This, extract::Double, meta::value, value, Double);
}
