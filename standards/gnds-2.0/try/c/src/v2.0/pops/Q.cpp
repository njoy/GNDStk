
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/pops/Q.hpp"
#include "Q.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = QClass;
using CPP = multigroup::Q;

static const std::string CLASSNAME = "Q";

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
using CPPDouble = unknownNamespace::Double;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstQ
QDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Q
QDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstQ
QCreateConst(
   const XMLName label,
   const XMLName unit,
   const XMLName value,
   ConstHandle2ConstDocumentation documentation,
   ConstHandle2ConstUncertainty uncertainty,
   ConstHandle2Double *const Double, const size_t DoubleSize
) {
   ConstHandle2Q handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      unit,
      value,
      detail::tocpp<CPPDocumentation>(documentation),
      detail::tocpp<CPPUncertainty>(uncertainty),
      std::vector<CPPDouble>{}
   );
   for (size_t DoubleN = 0; DoubleN < DoubleSize; ++DoubleN)
      QDoubleAdd(handle, Double[DoubleN]);
   return handle;
}

// Create, general
Handle2Q
QCreate(
   const XMLName label,
   const XMLName unit,
   const XMLName value,
   ConstHandle2ConstDocumentation documentation,
   ConstHandle2ConstUncertainty uncertainty,
   ConstHandle2Double *const Double, const size_t DoubleSize
) {
   ConstHandle2Q handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      unit,
      value,
      detail::tocpp<CPPDocumentation>(documentation),
      detail::tocpp<CPPUncertainty>(uncertainty),
      std::vector<CPPDouble>{}
   );
   for (size_t DoubleN = 0; DoubleN < DoubleSize; ++DoubleN)
      QDoubleAdd(handle, Double[DoubleN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
QAssign(ConstHandle2Q This, ConstHandle2ConstQ from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
QDelete(ConstHandle2ConstQ This)
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
QRead(ConstHandle2Q This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
QWrite(ConstHandle2ConstQ This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
QPrint(ConstHandle2ConstQ This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
QPrintXML(ConstHandle2ConstQ This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
QPrintJSON(ConstHandle2ConstQ This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
QLabelHas(ConstHandle2ConstQ This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
QLabelGet(ConstHandle2ConstQ This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
QLabelSet(ConstHandle2Q This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// Has
int
QUnitHas(ConstHandle2ConstQ This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UnitHas", This, extract::unit);
}

// Get
// Returns by value
XMLName
QUnitGet(ConstHandle2ConstQ This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"UnitGet", This, extract::unit);
}

// Set
void
QUnitSet(ConstHandle2Q This, const XMLName unit)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"UnitSet", This, extract::unit, unit);
}


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// Has
int
QValueHas(ConstHandle2ConstQ This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ValueHas", This, extract::value);
}

// Get
// Returns by value
XMLName
QValueGet(ConstHandle2ConstQ This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ValueGet", This, extract::value);
}

// Set
void
QValueSet(ConstHandle2Q This, const XMLName value)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ValueSet", This, extract::value, value);
}


// -----------------------------------------------------------------------------
// Child: documentation
// -----------------------------------------------------------------------------

// Has
int
QDocumentationHas(ConstHandle2ConstQ This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DocumentationHas", This, extract::documentation);
}

// Get, const
Handle2ConstDocumentation
QDocumentationGetConst(ConstHandle2ConstQ This)
{
   return detail::getField<CPP,Handle2ConstDocumentation>
      (CLASSNAME, CLASSNAME+"DocumentationGetConst", This, extract::documentation);
}

// Get, non-const
Handle2Documentation
QDocumentationGet(ConstHandle2Q This)
{
   return detail::getField<CPP,Handle2Documentation>
      (CLASSNAME, CLASSNAME+"DocumentationGet", This, extract::documentation);
}

// Set
void
QDocumentationSet(ConstHandle2Q This, ConstHandle2ConstDocumentation documentation)
{
   detail::setField<CPP,CPPDocumentation>
      (CLASSNAME, CLASSNAME+"DocumentationSet", This, extract::documentation, documentation);
}


// -----------------------------------------------------------------------------
// Child: uncertainty
// -----------------------------------------------------------------------------

// Has
int
QUncertaintyHas(ConstHandle2ConstQ This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UncertaintyHas", This, extract::uncertainty);
}

// Get, const
Handle2ConstUncertainty
QUncertaintyGetConst(ConstHandle2ConstQ This)
{
   return detail::getField<CPP,Handle2ConstUncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintyGetConst", This, extract::uncertainty);
}

// Get, non-const
Handle2Uncertainty
QUncertaintyGet(ConstHandle2Q This)
{
   return detail::getField<CPP,Handle2Uncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintyGet", This, extract::uncertainty);
}

// Set
void
QUncertaintySet(ConstHandle2Q This, ConstHandle2ConstUncertainty uncertainty)
{
   detail::setField<CPP,CPPUncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintySet", This, extract::uncertainty, uncertainty);
}


// -----------------------------------------------------------------------------
// Child: Double
// -----------------------------------------------------------------------------

// Has
int
QDoubleHas(ConstHandle2ConstQ This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DoubleHas", This, extract::Double);
}

// Clear
void
QDoubleClear(ConstHandle2Q This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"DoubleClear", This, extract::Double);
}

// Size
size_t
QDoubleSize(ConstHandle2ConstQ This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"DoubleSize", This, extract::Double);
}

// Add
void
QDoubleAdd(ConstHandle2Q This, ConstHandle2ConstDouble Double)
{
   detail::addToContainer<CPP,CPPDouble>
      (CLASSNAME, CLASSNAME+"DoubleAdd", This, extract::Double, Double);
}

// Get, by index \in [0,size), const
Handle2ConstDouble
QDoubleGetConst(ConstHandle2ConstQ This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstDouble>
      (CLASSNAME, CLASSNAME+"DoubleGetConst", This, extract::Double, index_);
}

// Get, by index \in [0,size), non-const
Handle2Double
QDoubleGet(ConstHandle2Q This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Double>
      (CLASSNAME, CLASSNAME+"DoubleGet", This, extract::Double, index_);
}

// Set, by index \in [0,size)
void
QDoubleSet(
   ConstHandle2Q This,
   const size_t index_,
   ConstHandle2ConstDouble Double
) {
   detail::setByIndex<CPP,CPPDouble>
      (CLASSNAME, CLASSNAME+"DoubleSet", This, extract::Double, index_, Double);
}
