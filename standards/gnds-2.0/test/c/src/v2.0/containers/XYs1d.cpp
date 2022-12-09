
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/containers/XYs1d.hpp"
#include "XYs1d.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = XYs1dClass;
using CPP = multigroup::XYs1d;

static const std::string CLASSNAME = "XYs1d";

namespace extract {
   static auto index = [](auto &obj) { return &obj.index; };
   static auto interpolation = [](auto &obj) { return &obj.interpolation; };
   static auto label = [](auto &obj) { return &obj.label; };
   static auto outerDomainValue = [](auto &obj) { return &obj.outerDomainValue; };
   static auto axes = [](auto &obj) { return &obj.axes; };
   static auto uncertainty = [](auto &obj) { return &obj.uncertainty; };
   static auto values = [](auto &obj) { return &obj.values; };
}

using CPPAxes = containers::Axes;
using CPPUncertainty = extra::Uncertainty;
using CPPValues = containers::Values;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstXYs1d
XYs1dDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2XYs1d
XYs1dDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstXYs1d
XYs1dCreateConst(
   const Integer32 index,
   const enums::Interpolation interpolation,
   const XMLName label,
   const Float64 outerDomainValue,
   ConstHandle2ConstAxes axes,
   ConstHandle2ConstUncertainty uncertainty,
   ConstHandle2ConstValues values
) {
   ConstHandle2XYs1d handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      index,
      interpolation,
      label,
      outerDomainValue,
      detail::tocpp<CPPAxes>(axes),
      detail::tocpp<CPPUncertainty>(uncertainty),
      detail::tocpp<CPPValues>(values)
   );
   return handle;
}

// Create, general
Handle2XYs1d
XYs1dCreate(
   const Integer32 index,
   const enums::Interpolation interpolation,
   const XMLName label,
   const Float64 outerDomainValue,
   ConstHandle2ConstAxes axes,
   ConstHandle2ConstUncertainty uncertainty,
   ConstHandle2ConstValues values
) {
   ConstHandle2XYs1d handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      index,
      interpolation,
      label,
      outerDomainValue,
      detail::tocpp<CPPAxes>(axes),
      detail::tocpp<CPPUncertainty>(uncertainty),
      detail::tocpp<CPPValues>(values)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
XYs1dAssign(ConstHandle2XYs1d This, ConstHandle2ConstXYs1d from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
XYs1dDelete(ConstHandle2ConstXYs1d This)
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
XYs1dRead(ConstHandle2XYs1d This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
XYs1dWrite(ConstHandle2ConstXYs1d This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
XYs1dPrint(ConstHandle2ConstXYs1d This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
XYs1dPrintXML(ConstHandle2ConstXYs1d This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
XYs1dPrintJSON(ConstHandle2ConstXYs1d This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: index
// -----------------------------------------------------------------------------

// Has
int
XYs1dIndexHas(ConstHandle2ConstXYs1d This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"IndexHas", This, extract::index);
}

// Get
// Returns by value
Integer32
XYs1dIndexGet(ConstHandle2ConstXYs1d This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"IndexGet", This, extract::index);
}

// Set
void
XYs1dIndexSet(ConstHandle2XYs1d This, const Integer32 index)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"IndexSet", This, extract::index, index);
}


// -----------------------------------------------------------------------------
// Metadatum: interpolation
// -----------------------------------------------------------------------------

// Has
int
XYs1dInterpolationHas(ConstHandle2ConstXYs1d This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"InterpolationHas", This, extract::interpolation);
}

// Get
// Returns by value
enums::Interpolation
XYs1dInterpolationGet(ConstHandle2ConstXYs1d This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"InterpolationGet", This, extract::interpolation);
}

// Set
void
XYs1dInterpolationSet(ConstHandle2XYs1d This, const enums::Interpolation interpolation)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"InterpolationSet", This, extract::interpolation, interpolation);
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
XYs1dLabelHas(ConstHandle2ConstXYs1d This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
XYs1dLabelGet(ConstHandle2ConstXYs1d This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
XYs1dLabelSet(ConstHandle2XYs1d This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: outerDomainValue
// -----------------------------------------------------------------------------

// Has
int
XYs1dOuterDomainValueHas(ConstHandle2ConstXYs1d This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"OuterDomainValueHas", This, extract::outerDomainValue);
}

// Get
// Returns by value
Float64
XYs1dOuterDomainValueGet(ConstHandle2ConstXYs1d This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"OuterDomainValueGet", This, extract::outerDomainValue);
}

// Set
void
XYs1dOuterDomainValueSet(ConstHandle2XYs1d This, const Float64 outerDomainValue)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"OuterDomainValueSet", This, extract::outerDomainValue, outerDomainValue);
}


// -----------------------------------------------------------------------------
// Child: axes
// -----------------------------------------------------------------------------

// Has
int
XYs1dAxesHas(ConstHandle2ConstXYs1d This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AxesHas", This, extract::axes);
}

// Get, const
Handle2ConstAxes
XYs1dAxesGetConst(ConstHandle2ConstXYs1d This)
{
   return detail::getField<CPP,Handle2ConstAxes>
      (CLASSNAME, CLASSNAME+"AxesGetConst", This, extract::axes);
}

// Get, non-const
Handle2Axes
XYs1dAxesGet(ConstHandle2XYs1d This)
{
   return detail::getField<CPP,Handle2Axes>
      (CLASSNAME, CLASSNAME+"AxesGet", This, extract::axes);
}

// Set
void
XYs1dAxesSet(ConstHandle2XYs1d This, ConstHandle2ConstAxes axes)
{
   detail::setField<CPP,CPPAxes>
      (CLASSNAME, CLASSNAME+"AxesSet", This, extract::axes, axes);
}


// -----------------------------------------------------------------------------
// Child: uncertainty
// -----------------------------------------------------------------------------

// Has
int
XYs1dUncertaintyHas(ConstHandle2ConstXYs1d This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UncertaintyHas", This, extract::uncertainty);
}

// Get, const
Handle2ConstUncertainty
XYs1dUncertaintyGetConst(ConstHandle2ConstXYs1d This)
{
   return detail::getField<CPP,Handle2ConstUncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintyGetConst", This, extract::uncertainty);
}

// Get, non-const
Handle2Uncertainty
XYs1dUncertaintyGet(ConstHandle2XYs1d This)
{
   return detail::getField<CPP,Handle2Uncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintyGet", This, extract::uncertainty);
}

// Set
void
XYs1dUncertaintySet(ConstHandle2XYs1d This, ConstHandle2ConstUncertainty uncertainty)
{
   detail::setField<CPP,CPPUncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintySet", This, extract::uncertainty, uncertainty);
}


// -----------------------------------------------------------------------------
// Child: values
// -----------------------------------------------------------------------------

// Has
int
XYs1dValuesHas(ConstHandle2ConstXYs1d This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ValuesHas", This, extract::values);
}

// Get, const
Handle2ConstValues
XYs1dValuesGetConst(ConstHandle2ConstXYs1d This)
{
   return detail::getField<CPP,Handle2ConstValues>
      (CLASSNAME, CLASSNAME+"ValuesGetConst", This, extract::values);
}

// Get, non-const
Handle2Values
XYs1dValuesGet(ConstHandle2XYs1d This)
{
   return detail::getField<CPP,Handle2Values>
      (CLASSNAME, CLASSNAME+"ValuesGet", This, extract::values);
}

// Set
void
XYs1dValuesSet(ConstHandle2XYs1d This, ConstHandle2ConstValues values)
{
   detail::setField<CPP,CPPValues>
      (CLASSNAME, CLASSNAME+"ValuesSet", This, extract::values, values);
}
