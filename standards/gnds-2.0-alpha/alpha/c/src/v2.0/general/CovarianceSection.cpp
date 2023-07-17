
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2.0/general/CovarianceSection.hpp"
#include "CovarianceSection.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = CovarianceSectionClass;
using CPP = multigroup::CovarianceSection;

static const std::string CLASSNAME = "CovarianceSection";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto crossTerm = [](auto &obj) { return &obj.crossTerm; };
   static auto rowData = [](auto &obj) { return &obj.rowData; };
   static auto columnData = [](auto &obj) { return &obj.columnData; };
   static auto covarianceMatrix = [](auto &obj) { return &obj.covarianceMatrix; };
   static auto mixed = [](auto &obj) { return &obj.mixed; };
   static auto sum = [](auto &obj) { return &obj.sum; };
}

using CPPRowData = general::RowData;
using CPPColumnData = general::ColumnData;
using CPPCovarianceMatrix = general::CovarianceMatrix;
using CPPMixed = general::Mixed;
using CPPSum = general::Sum;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstCovarianceSection
CovarianceSectionDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2CovarianceSection
CovarianceSectionDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstCovarianceSection
CovarianceSectionCreateConst(
   const char *const label,
   const bool crossTerm,
   ConstHandle2ConstRowData rowData,
   ConstHandle2ConstColumnData columnData,
   ConstHandle2ConstCovarianceMatrix covarianceMatrix,
   ConstHandle2ConstMixed mixed,
   ConstHandle2ConstSum sum
) {
   ConstHandle2CovarianceSection handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      crossTerm,
      detail::tocpp<CPPRowData>(rowData),
      detail::tocpp<CPPColumnData>(columnData),
      detail::tocpp<CPPCovarianceMatrix>(covarianceMatrix),
      detail::tocpp<CPPMixed>(mixed),
      detail::tocpp<CPPSum>(sum)
   );
   return handle;
}

// Create, general
Handle2CovarianceSection
CovarianceSectionCreate(
   const char *const label,
   const bool crossTerm,
   ConstHandle2ConstRowData rowData,
   ConstHandle2ConstColumnData columnData,
   ConstHandle2ConstCovarianceMatrix covarianceMatrix,
   ConstHandle2ConstMixed mixed,
   ConstHandle2ConstSum sum
) {
   ConstHandle2CovarianceSection handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      crossTerm,
      detail::tocpp<CPPRowData>(rowData),
      detail::tocpp<CPPColumnData>(columnData),
      detail::tocpp<CPPCovarianceMatrix>(covarianceMatrix),
      detail::tocpp<CPPMixed>(mixed),
      detail::tocpp<CPPSum>(sum)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
CovarianceSectionAssign(ConstHandle2CovarianceSection self, ConstHandle2ConstCovarianceSection from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
CovarianceSectionDelete(ConstHandle2ConstCovarianceSection self)
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
CovarianceSectionRead(ConstHandle2CovarianceSection self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
CovarianceSectionWrite(ConstHandle2ConstCovarianceSection self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
CovarianceSectionPrint(ConstHandle2ConstCovarianceSection self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
CovarianceSectionPrintXML(ConstHandle2ConstCovarianceSection self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
CovarianceSectionPrintJSON(ConstHandle2ConstCovarianceSection self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
CovarianceSectionLabelHas(ConstHandle2ConstCovarianceSection self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
const char *
CovarianceSectionLabelGet(ConstHandle2ConstCovarianceSection self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
CovarianceSectionLabelSet(ConstHandle2CovarianceSection self, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: crossTerm
// -----------------------------------------------------------------------------

// Has
int
CovarianceSectionCrossTermHas(ConstHandle2ConstCovarianceSection self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CrossTermHas", self, extract::crossTerm);
}

// Get
// Returns by value
bool
CovarianceSectionCrossTermGet(ConstHandle2ConstCovarianceSection self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"CrossTermGet", self, extract::crossTerm);
}

// Set
void
CovarianceSectionCrossTermSet(ConstHandle2CovarianceSection self, const bool crossTerm)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"CrossTermSet", self, extract::crossTerm, crossTerm);
}


// -----------------------------------------------------------------------------
// Child: rowData
// -----------------------------------------------------------------------------

// Has
int
CovarianceSectionRowDataHas(ConstHandle2ConstCovarianceSection self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"RowDataHas", self, extract::rowData);
}

// Get, const
Handle2ConstRowData
CovarianceSectionRowDataGetConst(ConstHandle2ConstCovarianceSection self)
{
   return detail::getField<CPP,Handle2ConstRowData>
      (CLASSNAME, CLASSNAME+"RowDataGetConst", self, extract::rowData);
}

// Get, non-const
Handle2RowData
CovarianceSectionRowDataGet(ConstHandle2CovarianceSection self)
{
   return detail::getField<CPP,Handle2RowData>
      (CLASSNAME, CLASSNAME+"RowDataGet", self, extract::rowData);
}

// Set
void
CovarianceSectionRowDataSet(ConstHandle2CovarianceSection self, ConstHandle2ConstRowData rowData)
{
   detail::setField<CPP,CPPRowData>
      (CLASSNAME, CLASSNAME+"RowDataSet", self, extract::rowData, rowData);
}


// -----------------------------------------------------------------------------
// Child: columnData
// -----------------------------------------------------------------------------

// Has
int
CovarianceSectionColumnDataHas(ConstHandle2ConstCovarianceSection self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ColumnDataHas", self, extract::columnData);
}

// Get, const
Handle2ConstColumnData
CovarianceSectionColumnDataGetConst(ConstHandle2ConstCovarianceSection self)
{
   return detail::getField<CPP,Handle2ConstColumnData>
      (CLASSNAME, CLASSNAME+"ColumnDataGetConst", self, extract::columnData);
}

// Get, non-const
Handle2ColumnData
CovarianceSectionColumnDataGet(ConstHandle2CovarianceSection self)
{
   return detail::getField<CPP,Handle2ColumnData>
      (CLASSNAME, CLASSNAME+"ColumnDataGet", self, extract::columnData);
}

// Set
void
CovarianceSectionColumnDataSet(ConstHandle2CovarianceSection self, ConstHandle2ConstColumnData columnData)
{
   detail::setField<CPP,CPPColumnData>
      (CLASSNAME, CLASSNAME+"ColumnDataSet", self, extract::columnData, columnData);
}


// -----------------------------------------------------------------------------
// Child: covarianceMatrix
// -----------------------------------------------------------------------------

// Has
int
CovarianceSectionCovarianceMatrixHas(ConstHandle2ConstCovarianceSection self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CovarianceMatrixHas", self, extract::covarianceMatrix);
}

// Get, const
Handle2ConstCovarianceMatrix
CovarianceSectionCovarianceMatrixGetConst(ConstHandle2ConstCovarianceSection self)
{
   return detail::getField<CPP,Handle2ConstCovarianceMatrix>
      (CLASSNAME, CLASSNAME+"CovarianceMatrixGetConst", self, extract::covarianceMatrix);
}

// Get, non-const
Handle2CovarianceMatrix
CovarianceSectionCovarianceMatrixGet(ConstHandle2CovarianceSection self)
{
   return detail::getField<CPP,Handle2CovarianceMatrix>
      (CLASSNAME, CLASSNAME+"CovarianceMatrixGet", self, extract::covarianceMatrix);
}

// Set
void
CovarianceSectionCovarianceMatrixSet(ConstHandle2CovarianceSection self, ConstHandle2ConstCovarianceMatrix covarianceMatrix)
{
   detail::setField<CPP,CPPCovarianceMatrix>
      (CLASSNAME, CLASSNAME+"CovarianceMatrixSet", self, extract::covarianceMatrix, covarianceMatrix);
}


// -----------------------------------------------------------------------------
// Child: mixed
// -----------------------------------------------------------------------------

// Has
int
CovarianceSectionMixedHas(ConstHandle2ConstCovarianceSection self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"MixedHas", self, extract::mixed);
}

// Get, const
Handle2ConstMixed
CovarianceSectionMixedGetConst(ConstHandle2ConstCovarianceSection self)
{
   return detail::getField<CPP,Handle2ConstMixed>
      (CLASSNAME, CLASSNAME+"MixedGetConst", self, extract::mixed);
}

// Get, non-const
Handle2Mixed
CovarianceSectionMixedGet(ConstHandle2CovarianceSection self)
{
   return detail::getField<CPP,Handle2Mixed>
      (CLASSNAME, CLASSNAME+"MixedGet", self, extract::mixed);
}

// Set
void
CovarianceSectionMixedSet(ConstHandle2CovarianceSection self, ConstHandle2ConstMixed mixed)
{
   detail::setField<CPP,CPPMixed>
      (CLASSNAME, CLASSNAME+"MixedSet", self, extract::mixed, mixed);
}


// -----------------------------------------------------------------------------
// Child: sum
// -----------------------------------------------------------------------------

// Has
int
CovarianceSectionSumHas(ConstHandle2ConstCovarianceSection self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SumHas", self, extract::sum);
}

// Get, const
Handle2ConstSum
CovarianceSectionSumGetConst(ConstHandle2ConstCovarianceSection self)
{
   return detail::getField<CPP,Handle2ConstSum>
      (CLASSNAME, CLASSNAME+"SumGetConst", self, extract::sum);
}

// Get, non-const
Handle2Sum
CovarianceSectionSumGet(ConstHandle2CovarianceSection self)
{
   return detail::getField<CPP,Handle2Sum>
      (CLASSNAME, CLASSNAME+"SumGet", self, extract::sum);
}

// Set
void
CovarianceSectionSumSet(ConstHandle2CovarianceSection self, ConstHandle2ConstSum sum)
{
   detail::setField<CPP,CPPSum>
      (CLASSNAME, CLASSNAME+"SumSet", self, extract::sum, sum);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/CovarianceSection/src/custom.cpp"
