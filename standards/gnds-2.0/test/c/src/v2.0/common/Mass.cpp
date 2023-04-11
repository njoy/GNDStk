
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2.0/common/Mass.hpp"
#include "Mass.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = MassClass;
using CPP = multigroup::Mass;

static const std::string CLASSNAME = "Mass";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto unit = [](auto &obj) { return &obj.unit; };
   static auto value = [](auto &obj) { return &obj.value; };
   static auto documentation = [](auto &obj) { return &obj.documentation; };
   static auto uncertainty = [](auto &obj) { return &obj.uncertainty; };
   static auto Double = [](auto &obj) { return &obj.Double; };
}

using CPPDocumentation = documentation::Documentation;
using CPPUncertainty = containers::Uncertainty;
using CPPDouble = containers::Double;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstMass
MassDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Mass
MassDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstMass
MassCreateConst(
   const XMLName label,
   const XMLName unit,
   const XMLName value,
   ConstHandle2ConstDocumentation documentation,
   ConstHandle2ConstUncertainty uncertainty,
   ConstHandle2Double *const Double, const size_t DoubleSize
) {
   ConstHandle2Mass handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      unit,
      value,
      detail::tocpp<CPPDocumentation>(documentation),
      detail::tocpp<CPPUncertainty>(uncertainty),
      std::vector<CPPDouble>{}
   );
   for (size_t DoubleN = 0; DoubleN < DoubleSize; ++DoubleN)
      MassDoubleAdd(handle, Double[DoubleN]);
   return handle;
}

// Create, general
Handle2Mass
MassCreate(
   const XMLName label,
   const XMLName unit,
   const XMLName value,
   ConstHandle2ConstDocumentation documentation,
   ConstHandle2ConstUncertainty uncertainty,
   ConstHandle2Double *const Double, const size_t DoubleSize
) {
   ConstHandle2Mass handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      unit,
      value,
      detail::tocpp<CPPDocumentation>(documentation),
      detail::tocpp<CPPUncertainty>(uncertainty),
      std::vector<CPPDouble>{}
   );
   for (size_t DoubleN = 0; DoubleN < DoubleSize; ++DoubleN)
      MassDoubleAdd(handle, Double[DoubleN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
MassAssign(ConstHandle2Mass self, ConstHandle2ConstMass from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
MassDelete(ConstHandle2ConstMass self)
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
MassRead(ConstHandle2Mass self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
MassWrite(ConstHandle2ConstMass self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
MassPrint(ConstHandle2ConstMass self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
MassPrintXML(ConstHandle2ConstMass self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
MassPrintJSON(ConstHandle2ConstMass self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
MassLabelHas(ConstHandle2ConstMass self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
XMLName
MassLabelGet(ConstHandle2ConstMass self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
MassLabelSet(ConstHandle2Mass self, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// Has
int
MassUnitHas(ConstHandle2ConstMass self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UnitHas", self, extract::unit);
}

// Get
// Returns by value
XMLName
MassUnitGet(ConstHandle2ConstMass self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"UnitGet", self, extract::unit);
}

// Set
void
MassUnitSet(ConstHandle2Mass self, const XMLName unit)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"UnitSet", self, extract::unit, unit);
}


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// Has
int
MassValueHas(ConstHandle2ConstMass self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ValueHas", self, extract::value);
}

// Get
// Returns by value
XMLName
MassValueGet(ConstHandle2ConstMass self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ValueGet", self, extract::value);
}

// Set
void
MassValueSet(ConstHandle2Mass self, const XMLName value)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ValueSet", self, extract::value, value);
}


// -----------------------------------------------------------------------------
// Child: documentation
// -----------------------------------------------------------------------------

// Has
int
MassDocumentationHas(ConstHandle2ConstMass self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DocumentationHas", self, extract::documentation);
}

// Get, const
Handle2ConstDocumentation
MassDocumentationGetConst(ConstHandle2ConstMass self)
{
   return detail::getField<CPP,Handle2ConstDocumentation>
      (CLASSNAME, CLASSNAME+"DocumentationGetConst", self, extract::documentation);
}

// Get, non-const
Handle2Documentation
MassDocumentationGet(ConstHandle2Mass self)
{
   return detail::getField<CPP,Handle2Documentation>
      (CLASSNAME, CLASSNAME+"DocumentationGet", self, extract::documentation);
}

// Set
void
MassDocumentationSet(ConstHandle2Mass self, ConstHandle2ConstDocumentation documentation)
{
   detail::setField<CPP,CPPDocumentation>
      (CLASSNAME, CLASSNAME+"DocumentationSet", self, extract::documentation, documentation);
}


// -----------------------------------------------------------------------------
// Child: uncertainty
// -----------------------------------------------------------------------------

// Has
int
MassUncertaintyHas(ConstHandle2ConstMass self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UncertaintyHas", self, extract::uncertainty);
}

// Get, const
Handle2ConstUncertainty
MassUncertaintyGetConst(ConstHandle2ConstMass self)
{
   return detail::getField<CPP,Handle2ConstUncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintyGetConst", self, extract::uncertainty);
}

// Get, non-const
Handle2Uncertainty
MassUncertaintyGet(ConstHandle2Mass self)
{
   return detail::getField<CPP,Handle2Uncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintyGet", self, extract::uncertainty);
}

// Set
void
MassUncertaintySet(ConstHandle2Mass self, ConstHandle2ConstUncertainty uncertainty)
{
   detail::setField<CPP,CPPUncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintySet", self, extract::uncertainty, uncertainty);
}


// -----------------------------------------------------------------------------
// Child: Double
// -----------------------------------------------------------------------------

// Has
int
MassDoubleHas(ConstHandle2ConstMass self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DoubleHas", self, extract::Double);
}

// Clear
void
MassDoubleClear(ConstHandle2Mass self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"DoubleClear", self, extract::Double);
}

// Size
size_t
MassDoubleSize(ConstHandle2ConstMass self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"DoubleSize", self, extract::Double);
}

// Add
void
MassDoubleAdd(ConstHandle2Mass self, ConstHandle2ConstDouble Double)
{
   detail::addToContainer<CPP,CPPDouble>
      (CLASSNAME, CLASSNAME+"DoubleAdd", self, extract::Double, Double);
}

// Get, by index \in [0,size), const
Handle2ConstDouble
MassDoubleGetConst(ConstHandle2ConstMass self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstDouble>
      (CLASSNAME, CLASSNAME+"DoubleGetConst", self, extract::Double, index_);
}

// Get, by index \in [0,size), non-const
Handle2Double
MassDoubleGet(ConstHandle2Mass self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Double>
      (CLASSNAME, CLASSNAME+"DoubleGet", self, extract::Double, index_);
}

// Set, by index \in [0,size)
void
MassDoubleSet(
   ConstHandle2Mass self,
   const size_t index_,
   ConstHandle2ConstDouble Double
) {
   detail::setByIndex<CPP,CPPDouble>
      (CLASSNAME, CLASSNAME+"DoubleSet", self, extract::Double, index_, Double);
}

// Has, by label
int
MassDoubleHasByLabel(
   ConstHandle2ConstMass self,
   const XMLName label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"DoubleHasByLabel",
       self, extract::Double, meta::label, label);
}

// Get, by label, const
Handle2ConstDouble
MassDoubleGetByLabelConst(
   ConstHandle2ConstMass self,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2ConstDouble>
      (CLASSNAME, CLASSNAME+"DoubleGetByLabelConst",
       self, extract::Double, meta::label, label);
}

// Get, by label, non-const
Handle2Double
MassDoubleGetByLabel(
   ConstHandle2Mass self,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2Double>
      (CLASSNAME, CLASSNAME+"DoubleGetByLabel",
       self, extract::Double, meta::label, label);
}

// Set, by label
void
MassDoubleSetByLabel(
   ConstHandle2Mass self,
   const XMLName label,
   ConstHandle2ConstDouble Double
) {
   detail::setByMetadatum<CPP,CPPDouble>
      (CLASSNAME, CLASSNAME+"DoubleSetByLabel",
       self, extract::Double, meta::label, label, Double);
}

// Has, by unit
int
MassDoubleHasByUnit(
   ConstHandle2ConstMass self,
   const XMLName unit
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"DoubleHasByUnit",
       self, extract::Double, meta::unit, unit);
}

// Get, by unit, const
Handle2ConstDouble
MassDoubleGetByUnitConst(
   ConstHandle2ConstMass self,
   const XMLName unit
) {
   return detail::getByMetadatum<CPP,Handle2ConstDouble>
      (CLASSNAME, CLASSNAME+"DoubleGetByUnitConst",
       self, extract::Double, meta::unit, unit);
}

// Get, by unit, non-const
Handle2Double
MassDoubleGetByUnit(
   ConstHandle2Mass self,
   const XMLName unit
) {
   return detail::getByMetadatum<CPP,Handle2Double>
      (CLASSNAME, CLASSNAME+"DoubleGetByUnit",
       self, extract::Double, meta::unit, unit);
}

// Set, by unit
void
MassDoubleSetByUnit(
   ConstHandle2Mass self,
   const XMLName unit,
   ConstHandle2ConstDouble Double
) {
   detail::setByMetadatum<CPP,CPPDouble>
      (CLASSNAME, CLASSNAME+"DoubleSetByUnit",
       self, extract::Double, meta::unit, unit, Double);
}

// Has, by value
int
MassDoubleHasByValue(
   ConstHandle2ConstMass self,
   const Float64 value
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"DoubleHasByValue",
       self, extract::Double, meta::value, value);
}

// Get, by value, const
Handle2ConstDouble
MassDoubleGetByValueConst(
   ConstHandle2ConstMass self,
   const Float64 value
) {
   return detail::getByMetadatum<CPP,Handle2ConstDouble>
      (CLASSNAME, CLASSNAME+"DoubleGetByValueConst",
       self, extract::Double, meta::value, value);
}

// Get, by value, non-const
Handle2Double
MassDoubleGetByValue(
   ConstHandle2Mass self,
   const Float64 value
) {
   return detail::getByMetadatum<CPP,Handle2Double>
      (CLASSNAME, CLASSNAME+"DoubleGetByValue",
       self, extract::Double, meta::value, value);
}

// Set, by value
void
MassDoubleSetByValue(
   ConstHandle2Mass self,
   const Float64 value,
   ConstHandle2ConstDouble Double
) {
   detail::setByMetadatum<CPP,CPPDouble>
      (CLASSNAME, CLASSNAME+"DoubleSetByValue",
       self, extract::Double, meta::value, value, Double);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/common/Mass/src/custom.cpp"
