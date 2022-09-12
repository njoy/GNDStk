
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/covariance/AverageParameterCovariance.hpp"
#include "AverageParameterCovariance.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = AverageParameterCovarianceClass;
using CPP = multigroup::AverageParameterCovariance;

static const std::string CLASSNAME = "AverageParameterCovariance";

namespace extract {
   static auto crossTerm = [](auto &obj) { return &obj.crossTerm; };
   static auto label = [](auto &obj) { return &obj.label; };
   static auto columnData = [](auto &obj) { return &obj.columnData; };
   static auto rowData = [](auto &obj) { return &obj.rowData; };
}

using CPPColumnData = covariance::ColumnData;
using CPPRowData = covariance::RowData;
using CPPCovarianceMatrix = covariance::CovarianceMatrix;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstAverageParameterCovariance
AverageParameterCovarianceDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2AverageParameterCovariance
AverageParameterCovarianceDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstAverageParameterCovariance
AverageParameterCovarianceCreateConst(
   const bool crossTerm,
   const XMLName label,
   ConstHandle2ConstColumnData columnData,
   ConstHandle2ConstRowData rowData,
) {
   ConstHandle2AverageParameterCovariance handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      crossTerm,
      label,
      detail::tocpp<CPPColumnData>(columnData),
      detail::tocpp<CPPRowData>(rowData)
   );
   return handle;
}

// Create, general
Handle2AverageParameterCovariance
AverageParameterCovarianceCreate(
   const bool crossTerm,
   const XMLName label,
   ConstHandle2ConstColumnData columnData,
   ConstHandle2ConstRowData rowData,
) {
   ConstHandle2AverageParameterCovariance handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      crossTerm,
      label,
      detail::tocpp<CPPColumnData>(columnData),
      detail::tocpp<CPPRowData>(rowData)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
AverageParameterCovarianceAssign(ConstHandle2AverageParameterCovariance This, ConstHandle2ConstAverageParameterCovariance from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
AverageParameterCovarianceDelete(ConstHandle2ConstAverageParameterCovariance This)
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
AverageParameterCovarianceRead(ConstHandle2AverageParameterCovariance This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
AverageParameterCovarianceWrite(ConstHandle2ConstAverageParameterCovariance This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
AverageParameterCovariancePrint(ConstHandle2ConstAverageParameterCovariance This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
AverageParameterCovariancePrintXML(ConstHandle2ConstAverageParameterCovariance This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
AverageParameterCovariancePrintJSON(ConstHandle2ConstAverageParameterCovariance This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: crossTerm
// -----------------------------------------------------------------------------

// Has
int
AverageParameterCovarianceCrossTermHas(ConstHandle2ConstAverageParameterCovariance This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CrossTermHas", This, extract::crossTerm);
}

// Get
// Returns by value
bool
AverageParameterCovarianceCrossTermGet(ConstHandle2ConstAverageParameterCovariance This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"CrossTermGet", This, extract::crossTerm);
}

// Set
void
AverageParameterCovarianceCrossTermSet(ConstHandle2AverageParameterCovariance This, const bool crossTerm)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"CrossTermSet", This, extract::crossTerm, crossTerm);
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
AverageParameterCovarianceLabelHas(ConstHandle2ConstAverageParameterCovariance This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
AverageParameterCovarianceLabelGet(ConstHandle2ConstAverageParameterCovariance This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
AverageParameterCovarianceLabelSet(ConstHandle2AverageParameterCovariance This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Child: columnData
// -----------------------------------------------------------------------------

// Has
int
AverageParameterCovarianceColumnDataHas(ConstHandle2ConstAverageParameterCovariance This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ColumnDataHas", This, extract::columnData);
}

// Get, const
Handle2ConstColumnData
AverageParameterCovarianceColumnDataGetConst(ConstHandle2ConstAverageParameterCovariance This)
{
   return detail::getField<CPP,Handle2ConstColumnData>
      (CLASSNAME, CLASSNAME+"ColumnDataGetConst", This, extract::columnData);
}

// Get, non-const
Handle2ColumnData
AverageParameterCovarianceColumnDataGet(ConstHandle2AverageParameterCovariance This)
{
   return detail::getField<CPP,Handle2ColumnData>
      (CLASSNAME, CLASSNAME+"ColumnDataGet", This, extract::columnData);
}

// Set
void
AverageParameterCovarianceColumnDataSet(ConstHandle2AverageParameterCovariance This, ConstHandle2ConstColumnData columnData)
{
   detail::setField<CPP,CPPColumnData>
      (CLASSNAME, CLASSNAME+"ColumnDataSet", This, extract::columnData, columnData);
}


// -----------------------------------------------------------------------------
// Child: rowData
// -----------------------------------------------------------------------------

// Has
int
AverageParameterCovarianceRowDataHas(ConstHandle2ConstAverageParameterCovariance This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"RowDataHas", This, extract::rowData);
}

// Get, const
Handle2ConstRowData
AverageParameterCovarianceRowDataGetConst(ConstHandle2ConstAverageParameterCovariance This)
{
   return detail::getField<CPP,Handle2ConstRowData>
      (CLASSNAME, CLASSNAME+"RowDataGetConst", This, extract::rowData);
}

// Get, non-const
Handle2RowData
AverageParameterCovarianceRowDataGet(ConstHandle2AverageParameterCovariance This)
{
   return detail::getField<CPP,Handle2RowData>
      (CLASSNAME, CLASSNAME+"RowDataGet", This, extract::rowData);
}

// Set
void
AverageParameterCovarianceRowDataSet(ConstHandle2AverageParameterCovariance This, ConstHandle2ConstRowData rowData)
{
   detail::setField<CPP,CPPRowData>
      (CLASSNAME, CLASSNAME+"RowDataSet", This, extract::rowData, rowData);
}