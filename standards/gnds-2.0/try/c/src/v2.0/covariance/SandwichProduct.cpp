
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/covariance/SandwichProduct.hpp"
#include "SandwichProduct.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = SandwichProductClass;
using CPP = multigroup::SandwichProduct;

static const std::string CLASSNAME = "SandwichProduct";

namespace extract {
   static auto axes = [](auto &obj) { return &obj.axes; };
   static auto covariance = [](auto &obj) { return &obj.covariance; };
   static auto rowSensitivity = [](auto &obj) { return &obj.rowSensitivity; };
   static auto columnSensitivity = [](auto &obj) { return &obj.columnSensitivity; };
}

using CPPAxes = unknownNamespace::Axes;
using CPPCovariance = covariance::Covariance;
using CPPRowSensitivity = covariance::RowSensitivity;
using CPPColumnSensitivity = covariance::ColumnSensitivity;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstSandwichProduct
SandwichProductDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2SandwichProduct
SandwichProductDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstSandwichProduct
SandwichProductCreateConst(
   ConstHandle2ConstAxes axes,
   ConstHandle2ConstCovariance covariance,
   ConstHandle2ConstRowSensitivity rowSensitivity,
   ConstHandle2ConstColumnSensitivity columnSensitivity
) {
   ConstHandle2SandwichProduct handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPAxes>(axes),
      detail::tocpp<CPPCovariance>(covariance),
      detail::tocpp<CPPRowSensitivity>(rowSensitivity),
      detail::tocpp<CPPColumnSensitivity>(columnSensitivity)
   );
   return handle;
}

// Create, general
Handle2SandwichProduct
SandwichProductCreate(
   ConstHandle2ConstAxes axes,
   ConstHandle2ConstCovariance covariance,
   ConstHandle2ConstRowSensitivity rowSensitivity,
   ConstHandle2ConstColumnSensitivity columnSensitivity
) {
   ConstHandle2SandwichProduct handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPAxes>(axes),
      detail::tocpp<CPPCovariance>(covariance),
      detail::tocpp<CPPRowSensitivity>(rowSensitivity),
      detail::tocpp<CPPColumnSensitivity>(columnSensitivity)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
SandwichProductAssign(ConstHandle2SandwichProduct This, ConstHandle2ConstSandwichProduct from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
SandwichProductDelete(ConstHandle2ConstSandwichProduct This)
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
SandwichProductRead(ConstHandle2SandwichProduct This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
SandwichProductWrite(ConstHandle2ConstSandwichProduct This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
SandwichProductPrint(ConstHandle2ConstSandwichProduct This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
SandwichProductPrintXML(ConstHandle2ConstSandwichProduct This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
SandwichProductPrintJSON(ConstHandle2ConstSandwichProduct This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: axes
// -----------------------------------------------------------------------------

// Has
int
SandwichProductAxesHas(ConstHandle2ConstSandwichProduct This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AxesHas", This, extract::axes);
}

// Get, const
Handle2ConstAxes
SandwichProductAxesGetConst(ConstHandle2ConstSandwichProduct This)
{
   return detail::getField<CPP,Handle2ConstAxes>
      (CLASSNAME, CLASSNAME+"AxesGetConst", This, extract::axes);
}

// Get, non-const
Handle2Axes
SandwichProductAxesGet(ConstHandle2SandwichProduct This)
{
   return detail::getField<CPP,Handle2Axes>
      (CLASSNAME, CLASSNAME+"AxesGet", This, extract::axes);
}

// Set
void
SandwichProductAxesSet(ConstHandle2SandwichProduct This, ConstHandle2ConstAxes axes)
{
   detail::setField<CPP,CPPAxes>
      (CLASSNAME, CLASSNAME+"AxesSet", This, extract::axes, axes);
}


// -----------------------------------------------------------------------------
// Child: covariance
// -----------------------------------------------------------------------------

// Has
int
SandwichProductCovarianceHas(ConstHandle2ConstSandwichProduct This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CovarianceHas", This, extract::covariance);
}

// Get, const
Handle2ConstCovariance
SandwichProductCovarianceGetConst(ConstHandle2ConstSandwichProduct This)
{
   return detail::getField<CPP,Handle2ConstCovariance>
      (CLASSNAME, CLASSNAME+"CovarianceGetConst", This, extract::covariance);
}

// Get, non-const
Handle2Covariance
SandwichProductCovarianceGet(ConstHandle2SandwichProduct This)
{
   return detail::getField<CPP,Handle2Covariance>
      (CLASSNAME, CLASSNAME+"CovarianceGet", This, extract::covariance);
}

// Set
void
SandwichProductCovarianceSet(ConstHandle2SandwichProduct This, ConstHandle2ConstCovariance covariance)
{
   detail::setField<CPP,CPPCovariance>
      (CLASSNAME, CLASSNAME+"CovarianceSet", This, extract::covariance, covariance);
}


// -----------------------------------------------------------------------------
// Child: rowSensitivity
// -----------------------------------------------------------------------------

// Has
int
SandwichProductRowSensitivityHas(ConstHandle2ConstSandwichProduct This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"RowSensitivityHas", This, extract::rowSensitivity);
}

// Get, const
Handle2ConstRowSensitivity
SandwichProductRowSensitivityGetConst(ConstHandle2ConstSandwichProduct This)
{
   return detail::getField<CPP,Handle2ConstRowSensitivity>
      (CLASSNAME, CLASSNAME+"RowSensitivityGetConst", This, extract::rowSensitivity);
}

// Get, non-const
Handle2RowSensitivity
SandwichProductRowSensitivityGet(ConstHandle2SandwichProduct This)
{
   return detail::getField<CPP,Handle2RowSensitivity>
      (CLASSNAME, CLASSNAME+"RowSensitivityGet", This, extract::rowSensitivity);
}

// Set
void
SandwichProductRowSensitivitySet(ConstHandle2SandwichProduct This, ConstHandle2ConstRowSensitivity rowSensitivity)
{
   detail::setField<CPP,CPPRowSensitivity>
      (CLASSNAME, CLASSNAME+"RowSensitivitySet", This, extract::rowSensitivity, rowSensitivity);
}


// -----------------------------------------------------------------------------
// Child: columnSensitivity
// -----------------------------------------------------------------------------

// Has
int
SandwichProductColumnSensitivityHas(ConstHandle2ConstSandwichProduct This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ColumnSensitivityHas", This, extract::columnSensitivity);
}

// Get, const
Handle2ConstColumnSensitivity
SandwichProductColumnSensitivityGetConst(ConstHandle2ConstSandwichProduct This)
{
   return detail::getField<CPP,Handle2ConstColumnSensitivity>
      (CLASSNAME, CLASSNAME+"ColumnSensitivityGetConst", This, extract::columnSensitivity);
}

// Get, non-const
Handle2ColumnSensitivity
SandwichProductColumnSensitivityGet(ConstHandle2SandwichProduct This)
{
   return detail::getField<CPP,Handle2ColumnSensitivity>
      (CLASSNAME, CLASSNAME+"ColumnSensitivityGet", This, extract::columnSensitivity);
}

// Set
void
SandwichProductColumnSensitivitySet(ConstHandle2SandwichProduct This, ConstHandle2ConstColumnSensitivity columnSensitivity)
{
   detail::setField<CPP,CPPColumnSensitivity>
      (CLASSNAME, CLASSNAME+"ColumnSensitivitySet", This, extract::columnSensitivity, columnSensitivity);
}
