
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/covariance/ParameterCovariance.hpp"
#include "ParameterCovariance.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = ParameterCovarianceClass;
using CPP = multigroup::ParameterCovariance;

static const std::string CLASSNAME = "ParameterCovariance";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto rowData = [](auto &obj) { return &obj.rowData; };
   static auto parameterCovarianceMatrix = [](auto &obj) { return &obj.parameterCovarianceMatrix; };
}

using CPPRowData = covariance::RowData;
using CPPParameterCovarianceMatrix = covariance::ParameterCovarianceMatrix;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstParameterCovariance
ParameterCovarianceDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2ParameterCovariance
ParameterCovarianceDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstParameterCovariance
ParameterCovarianceCreateConst(
   const XMLName label,
   ConstHandle2ConstRowData rowData,
   ConstHandle2ParameterCovarianceMatrix *const parameterCovarianceMatrix, const size_t parameterCovarianceMatrixSize
) {
   ConstHandle2ParameterCovariance handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      detail::tocpp<CPPRowData>(rowData),
      std::vector<CPPParameterCovarianceMatrix>{}
   );
   for (size_t ParameterCovarianceMatrixN = 0; ParameterCovarianceMatrixN < parameterCovarianceMatrixSize; ++ParameterCovarianceMatrixN)
      ParameterCovarianceParameterCovarianceMatrixAdd(handle, parameterCovarianceMatrix[ParameterCovarianceMatrixN]);
   return handle;
}

// Create, general
Handle2ParameterCovariance
ParameterCovarianceCreate(
   const XMLName label,
   ConstHandle2ConstRowData rowData,
   ConstHandle2ParameterCovarianceMatrix *const parameterCovarianceMatrix, const size_t parameterCovarianceMatrixSize
) {
   ConstHandle2ParameterCovariance handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      detail::tocpp<CPPRowData>(rowData),
      std::vector<CPPParameterCovarianceMatrix>{}
   );
   for (size_t ParameterCovarianceMatrixN = 0; ParameterCovarianceMatrixN < parameterCovarianceMatrixSize; ++ParameterCovarianceMatrixN)
      ParameterCovarianceParameterCovarianceMatrixAdd(handle, parameterCovarianceMatrix[ParameterCovarianceMatrixN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ParameterCovarianceAssign(ConstHandle2ParameterCovariance This, ConstHandle2ConstParameterCovariance from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ParameterCovarianceDelete(ConstHandle2ConstParameterCovariance This)
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
ParameterCovarianceRead(ConstHandle2ParameterCovariance This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ParameterCovarianceWrite(ConstHandle2ConstParameterCovariance This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
ParameterCovariancePrint(ConstHandle2ConstParameterCovariance This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
ParameterCovariancePrintXML(ConstHandle2ConstParameterCovariance This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
ParameterCovariancePrintJSON(ConstHandle2ConstParameterCovariance This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
ParameterCovarianceLabelHas(ConstHandle2ConstParameterCovariance This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
ParameterCovarianceLabelGet(ConstHandle2ConstParameterCovariance This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
ParameterCovarianceLabelSet(ConstHandle2ParameterCovariance This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Child: rowData
// -----------------------------------------------------------------------------

// Has
int
ParameterCovarianceRowDataHas(ConstHandle2ConstParameterCovariance This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"RowDataHas", This, extract::rowData);
}

// Get, const
Handle2ConstRowData
ParameterCovarianceRowDataGetConst(ConstHandle2ConstParameterCovariance This)
{
   return detail::getField<CPP,Handle2ConstRowData>
      (CLASSNAME, CLASSNAME+"RowDataGetConst", This, extract::rowData);
}

// Get, non-const
Handle2RowData
ParameterCovarianceRowDataGet(ConstHandle2ParameterCovariance This)
{
   return detail::getField<CPP,Handle2RowData>
      (CLASSNAME, CLASSNAME+"RowDataGet", This, extract::rowData);
}

// Set
void
ParameterCovarianceRowDataSet(ConstHandle2ParameterCovariance This, ConstHandle2ConstRowData rowData)
{
   detail::setField<CPP,CPPRowData>
      (CLASSNAME, CLASSNAME+"RowDataSet", This, extract::rowData, rowData);
}


// -----------------------------------------------------------------------------
// Child: parameterCovarianceMatrix
// -----------------------------------------------------------------------------

// Has
int
ParameterCovarianceParameterCovarianceMatrixHas(ConstHandle2ConstParameterCovariance This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ParameterCovarianceMatrixHas", This, extract::parameterCovarianceMatrix);
}

// Clear
void
ParameterCovarianceParameterCovarianceMatrixClear(ConstHandle2ParameterCovariance This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"ParameterCovarianceMatrixClear", This, extract::parameterCovarianceMatrix);
}

// Size
size_t
ParameterCovarianceParameterCovarianceMatrixSize(ConstHandle2ConstParameterCovariance This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"ParameterCovarianceMatrixSize", This, extract::parameterCovarianceMatrix);
}

// Add
void
ParameterCovarianceParameterCovarianceMatrixAdd(ConstHandle2ParameterCovariance This, ConstHandle2ConstParameterCovarianceMatrix parameterCovarianceMatrix)
{
   detail::addToContainer<CPP,CPPParameterCovarianceMatrix>
      (CLASSNAME, CLASSNAME+"ParameterCovarianceMatrixAdd", This, extract::parameterCovarianceMatrix, parameterCovarianceMatrix);
}

// Get, by index \in [0,size), const
Handle2ConstParameterCovarianceMatrix
ParameterCovarianceParameterCovarianceMatrixGetConst(ConstHandle2ConstParameterCovariance This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstParameterCovarianceMatrix>
      (CLASSNAME, CLASSNAME+"ParameterCovarianceMatrixGetConst", This, extract::parameterCovarianceMatrix, index_);
}

// Get, by index \in [0,size), non-const
Handle2ParameterCovarianceMatrix
ParameterCovarianceParameterCovarianceMatrixGet(ConstHandle2ParameterCovariance This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ParameterCovarianceMatrix>
      (CLASSNAME, CLASSNAME+"ParameterCovarianceMatrixGet", This, extract::parameterCovarianceMatrix, index_);
}

// Set, by index \in [0,size)
void
ParameterCovarianceParameterCovarianceMatrixSet(
   ConstHandle2ParameterCovariance This,
   const size_t index_,
   ConstHandle2ConstParameterCovarianceMatrix parameterCovarianceMatrix
) {
   detail::setByIndex<CPP,CPPParameterCovarianceMatrix>
      (CLASSNAME, CLASSNAME+"ParameterCovarianceMatrixSet", This, extract::parameterCovarianceMatrix, index_, parameterCovarianceMatrix);
}

// Has, by label
int
ParameterCovarianceParameterCovarianceMatrixHasByLabel(
   ConstHandle2ConstParameterCovariance This,
   const XMLName label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ParameterCovarianceMatrixHasByLabel",
       This, extract::parameterCovarianceMatrix, meta::label, label);
}

// Get, by label, const
Handle2ConstParameterCovarianceMatrix
ParameterCovarianceParameterCovarianceMatrixGetByLabelConst(
   ConstHandle2ConstParameterCovariance This,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2ConstParameterCovarianceMatrix>
      (CLASSNAME, CLASSNAME+"ParameterCovarianceMatrixGetByLabelConst",
       This, extract::parameterCovarianceMatrix, meta::label, label);
}

// Get, by label, non-const
Handle2ParameterCovarianceMatrix
ParameterCovarianceParameterCovarianceMatrixGetByLabel(
   ConstHandle2ParameterCovariance This,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2ParameterCovarianceMatrix>
      (CLASSNAME, CLASSNAME+"ParameterCovarianceMatrixGetByLabel",
       This, extract::parameterCovarianceMatrix, meta::label, label);
}

// Set, by label
void
ParameterCovarianceParameterCovarianceMatrixSetByLabel(
   ConstHandle2ParameterCovariance This,
   const XMLName label,
   ConstHandle2ConstParameterCovarianceMatrix parameterCovarianceMatrix
) {
   detail::setByMetadatum<CPP,CPPParameterCovarianceMatrix>
      (CLASSNAME, CLASSNAME+"ParameterCovarianceMatrixSetByLabel",
       This, extract::parameterCovarianceMatrix, meta::label, label, parameterCovarianceMatrix);
}

// Has, by type
int
ParameterCovarianceParameterCovarianceMatrixHasByType(
   ConstHandle2ConstParameterCovariance This,
   const XMLName type
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ParameterCovarianceMatrixHasByType",
       This, extract::parameterCovarianceMatrix, meta::type, type);
}

// Get, by type, const
Handle2ConstParameterCovarianceMatrix
ParameterCovarianceParameterCovarianceMatrixGetByTypeConst(
   ConstHandle2ConstParameterCovariance This,
   const XMLName type
) {
   return detail::getByMetadatum<CPP,Handle2ConstParameterCovarianceMatrix>
      (CLASSNAME, CLASSNAME+"ParameterCovarianceMatrixGetByTypeConst",
       This, extract::parameterCovarianceMatrix, meta::type, type);
}

// Get, by type, non-const
Handle2ParameterCovarianceMatrix
ParameterCovarianceParameterCovarianceMatrixGetByType(
   ConstHandle2ParameterCovariance This,
   const XMLName type
) {
   return detail::getByMetadatum<CPP,Handle2ParameterCovarianceMatrix>
      (CLASSNAME, CLASSNAME+"ParameterCovarianceMatrixGetByType",
       This, extract::parameterCovarianceMatrix, meta::type, type);
}

// Set, by type
void
ParameterCovarianceParameterCovarianceMatrixSetByType(
   ConstHandle2ParameterCovariance This,
   const XMLName type,
   ConstHandle2ConstParameterCovarianceMatrix parameterCovarianceMatrix
) {
   detail::setByMetadatum<CPP,CPPParameterCovarianceMatrix>
      (CLASSNAME, CLASSNAME+"ParameterCovarianceMatrixSetByType",
       This, extract::parameterCovarianceMatrix, meta::type, type, parameterCovarianceMatrix);
}