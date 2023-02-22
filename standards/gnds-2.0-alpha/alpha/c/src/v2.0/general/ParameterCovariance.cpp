
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/ParameterCovariance.hpp"
#include "ParameterCovariance.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = ParameterCovarianceClass;
using CPP = multigroup::ParameterCovariance;

static const std::string CLASSNAME = "ParameterCovariance";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto rowData = [](auto &obj) { return &obj.rowData; };
   static auto parameterCovarianceMatrix = [](auto &obj) { return &obj.parameterCovarianceMatrix; };
}

using CPPRowData = general::RowData;
using CPPParameterCovarianceMatrix = general::ParameterCovarianceMatrix;


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
   const char *const label,
   ConstHandle2ConstRowData rowData,
   ConstHandle2ConstParameterCovarianceMatrix parameterCovarianceMatrix
) {
   ConstHandle2ParameterCovariance handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      detail::tocpp<CPPRowData>(rowData),
      detail::tocpp<CPPParameterCovarianceMatrix>(parameterCovarianceMatrix)
   );
   return handle;
}

// Create, general
Handle2ParameterCovariance
ParameterCovarianceCreate(
   const char *const label,
   ConstHandle2ConstRowData rowData,
   ConstHandle2ConstParameterCovarianceMatrix parameterCovarianceMatrix
) {
   ConstHandle2ParameterCovariance handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      detail::tocpp<CPPRowData>(rowData),
      detail::tocpp<CPPParameterCovarianceMatrix>(parameterCovarianceMatrix)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ParameterCovarianceAssign(ConstHandle2ParameterCovariance self, ConstHandle2ConstParameterCovariance from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ParameterCovarianceDelete(ConstHandle2ConstParameterCovariance self)
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
ParameterCovarianceRead(ConstHandle2ParameterCovariance self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ParameterCovarianceWrite(ConstHandle2ConstParameterCovariance self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ParameterCovariancePrint(ConstHandle2ConstParameterCovariance self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ParameterCovariancePrintXML(ConstHandle2ConstParameterCovariance self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ParameterCovariancePrintJSON(ConstHandle2ConstParameterCovariance self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
ParameterCovarianceLabelHas(ConstHandle2ConstParameterCovariance self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
const char *
ParameterCovarianceLabelGet(ConstHandle2ConstParameterCovariance self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
ParameterCovarianceLabelSet(ConstHandle2ParameterCovariance self, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Child: rowData
// -----------------------------------------------------------------------------

// Has
int
ParameterCovarianceRowDataHas(ConstHandle2ConstParameterCovariance self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"RowDataHas", self, extract::rowData);
}

// Get, const
Handle2ConstRowData
ParameterCovarianceRowDataGetConst(ConstHandle2ConstParameterCovariance self)
{
   return detail::getField<CPP,Handle2ConstRowData>
      (CLASSNAME, CLASSNAME+"RowDataGetConst", self, extract::rowData);
}

// Get, non-const
Handle2RowData
ParameterCovarianceRowDataGet(ConstHandle2ParameterCovariance self)
{
   return detail::getField<CPP,Handle2RowData>
      (CLASSNAME, CLASSNAME+"RowDataGet", self, extract::rowData);
}

// Set
void
ParameterCovarianceRowDataSet(ConstHandle2ParameterCovariance self, ConstHandle2ConstRowData rowData)
{
   detail::setField<CPP,CPPRowData>
      (CLASSNAME, CLASSNAME+"RowDataSet", self, extract::rowData, rowData);
}


// -----------------------------------------------------------------------------
// Child: parameterCovarianceMatrix
// -----------------------------------------------------------------------------

// Has
int
ParameterCovarianceParameterCovarianceMatrixHas(ConstHandle2ConstParameterCovariance self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ParameterCovarianceMatrixHas", self, extract::parameterCovarianceMatrix);
}

// Get, const
Handle2ConstParameterCovarianceMatrix
ParameterCovarianceParameterCovarianceMatrixGetConst(ConstHandle2ConstParameterCovariance self)
{
   return detail::getField<CPP,Handle2ConstParameterCovarianceMatrix>
      (CLASSNAME, CLASSNAME+"ParameterCovarianceMatrixGetConst", self, extract::parameterCovarianceMatrix);
}

// Get, non-const
Handle2ParameterCovarianceMatrix
ParameterCovarianceParameterCovarianceMatrixGet(ConstHandle2ParameterCovariance self)
{
   return detail::getField<CPP,Handle2ParameterCovarianceMatrix>
      (CLASSNAME, CLASSNAME+"ParameterCovarianceMatrixGet", self, extract::parameterCovarianceMatrix);
}

// Set
void
ParameterCovarianceParameterCovarianceMatrixSet(ConstHandle2ParameterCovariance self, ConstHandle2ConstParameterCovarianceMatrix parameterCovarianceMatrix)
{
   detail::setField<CPP,CPPParameterCovarianceMatrix>
      (CLASSNAME, CLASSNAME+"ParameterCovarianceMatrixSet", self, extract::parameterCovarianceMatrix, parameterCovarianceMatrix);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/ParameterCovariance/src/custom.cpp"