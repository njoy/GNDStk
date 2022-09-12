
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/resonances/ExternalRMatrix.hpp"
#include "ExternalRMatrix.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = ExternalRMatrixClass;
using CPP = multigroup::ExternalRMatrix;

static const std::string CLASSNAME = "ExternalRMatrix";

namespace extract {
   static auto type = [](auto &obj) { return &obj.type; };
   static auto Double = [](auto &obj) { return &obj.Double; };
}

using CPPDouble = containers::Double;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstExternalRMatrix
ExternalRMatrixDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2ExternalRMatrix
ExternalRMatrixDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstExternalRMatrix
ExternalRMatrixCreateConst(
   const XMLName type,
   ConstHandle2Double *const Double, const size_t DoubleSize
) {
   ConstHandle2ExternalRMatrix handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      type,
      std::vector<CPPDouble>{}
   );
   for (size_t DoubleN = 0; DoubleN < DoubleSize; ++DoubleN)
      ExternalRMatrixDoubleAdd(handle, Double[DoubleN]);
   return handle;
}

// Create, general
Handle2ExternalRMatrix
ExternalRMatrixCreate(
   const XMLName type,
   ConstHandle2Double *const Double, const size_t DoubleSize
) {
   ConstHandle2ExternalRMatrix handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      type,
      std::vector<CPPDouble>{}
   );
   for (size_t DoubleN = 0; DoubleN < DoubleSize; ++DoubleN)
      ExternalRMatrixDoubleAdd(handle, Double[DoubleN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ExternalRMatrixAssign(ConstHandle2ExternalRMatrix This, ConstHandle2ConstExternalRMatrix from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ExternalRMatrixDelete(ConstHandle2ConstExternalRMatrix This)
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
ExternalRMatrixRead(ConstHandle2ExternalRMatrix This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ExternalRMatrixWrite(ConstHandle2ConstExternalRMatrix This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
ExternalRMatrixPrint(ConstHandle2ConstExternalRMatrix This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
ExternalRMatrixPrintXML(ConstHandle2ConstExternalRMatrix This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
ExternalRMatrixPrintJSON(ConstHandle2ConstExternalRMatrix This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: type
// -----------------------------------------------------------------------------

// Has
int
ExternalRMatrixTypeHas(ConstHandle2ConstExternalRMatrix This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"TypeHas", This, extract::type);
}

// Get
// Returns by value
XMLName
ExternalRMatrixTypeGet(ConstHandle2ConstExternalRMatrix This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"TypeGet", This, extract::type);
}

// Set
void
ExternalRMatrixTypeSet(ConstHandle2ExternalRMatrix This, const XMLName type)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"TypeSet", This, extract::type, type);
}


// -----------------------------------------------------------------------------
// Child: Double
// -----------------------------------------------------------------------------

// Has
int
ExternalRMatrixDoubleHas(ConstHandle2ConstExternalRMatrix This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DoubleHas", This, extract::Double);
}

// Clear
void
ExternalRMatrixDoubleClear(ConstHandle2ExternalRMatrix This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"DoubleClear", This, extract::Double);
}

// Size
size_t
ExternalRMatrixDoubleSize(ConstHandle2ConstExternalRMatrix This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"DoubleSize", This, extract::Double);
}

// Add
void
ExternalRMatrixDoubleAdd(ConstHandle2ExternalRMatrix This, ConstHandle2ConstDouble Double)
{
   detail::addToContainer<CPP,CPPDouble>
      (CLASSNAME, CLASSNAME+"DoubleAdd", This, extract::Double, Double);
}

// Get, by index \in [0,size), const
Handle2ConstDouble
ExternalRMatrixDoubleGetConst(ConstHandle2ConstExternalRMatrix This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstDouble>
      (CLASSNAME, CLASSNAME+"DoubleGetConst", This, extract::Double, index_);
}

// Get, by index \in [0,size), non-const
Handle2Double
ExternalRMatrixDoubleGet(ConstHandle2ExternalRMatrix This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Double>
      (CLASSNAME, CLASSNAME+"DoubleGet", This, extract::Double, index_);
}

// Set, by index \in [0,size)
void
ExternalRMatrixDoubleSet(
   ConstHandle2ExternalRMatrix This,
   const size_t index_,
   ConstHandle2ConstDouble Double
) {
   detail::setByIndex<CPP,CPPDouble>
      (CLASSNAME, CLASSNAME+"DoubleSet", This, extract::Double, index_, Double);
}

// Has, by label
int
ExternalRMatrixDoubleHasByLabel(
   ConstHandle2ConstExternalRMatrix This,
   const XMLName label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"DoubleHasByLabel",
       This, extract::Double, meta::label, label);
}

// Get, by label, const
Handle2ConstDouble
ExternalRMatrixDoubleGetByLabelConst(
   ConstHandle2ConstExternalRMatrix This,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2ConstDouble>
      (CLASSNAME, CLASSNAME+"DoubleGetByLabelConst",
       This, extract::Double, meta::label, label);
}

// Get, by label, non-const
Handle2Double
ExternalRMatrixDoubleGetByLabel(
   ConstHandle2ExternalRMatrix This,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2Double>
      (CLASSNAME, CLASSNAME+"DoubleGetByLabel",
       This, extract::Double, meta::label, label);
}

// Set, by label
void
ExternalRMatrixDoubleSetByLabel(
   ConstHandle2ExternalRMatrix This,
   const XMLName label,
   ConstHandle2ConstDouble Double
) {
   detail::setByMetadatum<CPP,CPPDouble>
      (CLASSNAME, CLASSNAME+"DoubleSetByLabel",
       This, extract::Double, meta::label, label, Double);
}

// Has, by unit
int
ExternalRMatrixDoubleHasByUnit(
   ConstHandle2ConstExternalRMatrix This,
   const XMLName unit
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"DoubleHasByUnit",
       This, extract::Double, meta::unit, unit);
}

// Get, by unit, const
Handle2ConstDouble
ExternalRMatrixDoubleGetByUnitConst(
   ConstHandle2ConstExternalRMatrix This,
   const XMLName unit
) {
   return detail::getByMetadatum<CPP,Handle2ConstDouble>
      (CLASSNAME, CLASSNAME+"DoubleGetByUnitConst",
       This, extract::Double, meta::unit, unit);
}

// Get, by unit, non-const
Handle2Double
ExternalRMatrixDoubleGetByUnit(
   ConstHandle2ExternalRMatrix This,
   const XMLName unit
) {
   return detail::getByMetadatum<CPP,Handle2Double>
      (CLASSNAME, CLASSNAME+"DoubleGetByUnit",
       This, extract::Double, meta::unit, unit);
}

// Set, by unit
void
ExternalRMatrixDoubleSetByUnit(
   ConstHandle2ExternalRMatrix This,
   const XMLName unit,
   ConstHandle2ConstDouble Double
) {
   detail::setByMetadatum<CPP,CPPDouble>
      (CLASSNAME, CLASSNAME+"DoubleSetByUnit",
       This, extract::Double, meta::unit, unit, Double);
}

// Has, by value
int
ExternalRMatrixDoubleHasByValue(
   ConstHandle2ConstExternalRMatrix This,
   const Float64 value
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"DoubleHasByValue",
       This, extract::Double, meta::value, value);
}

// Get, by value, const
Handle2ConstDouble
ExternalRMatrixDoubleGetByValueConst(
   ConstHandle2ConstExternalRMatrix This,
   const Float64 value
) {
   return detail::getByMetadatum<CPP,Handle2ConstDouble>
      (CLASSNAME, CLASSNAME+"DoubleGetByValueConst",
       This, extract::Double, meta::value, value);
}

// Get, by value, non-const
Handle2Double
ExternalRMatrixDoubleGetByValue(
   ConstHandle2ExternalRMatrix This,
   const Float64 value
) {
   return detail::getByMetadatum<CPP,Handle2Double>
      (CLASSNAME, CLASSNAME+"DoubleGetByValue",
       This, extract::Double, meta::value, value);
}

// Set, by value
void
ExternalRMatrixDoubleSetByValue(
   ConstHandle2ExternalRMatrix This,
   const Float64 value,
   ConstHandle2ConstDouble Double
) {
   detail::setByMetadatum<CPP,CPPDouble>
      (CLASSNAME, CLASSNAME+"DoubleSetByValue",
       This, extract::Double, meta::value, value, Double);
}