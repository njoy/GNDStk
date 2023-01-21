
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/containers/Gridded2d.hpp"
#include "Gridded2d.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = Gridded2dClass;
using CPP = multigroup::Gridded2d;

static const std::string CLASSNAME = "Gridded2d";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto array = [](auto &obj) { return &obj.array; };
   static auto axes = [](auto &obj) { return &obj.axes; };
}

using CPPArray = containers::Array;
using CPPAxes = containers::Axes;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstGridded2d
Gridded2dDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Gridded2d
Gridded2dDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstGridded2d
Gridded2dCreateConst(
   const XMLName label,
   ConstHandle2ConstArray array,
   ConstHandle2ConstAxes axes
) {
   ConstHandle2Gridded2d handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      detail::tocpp<CPPArray>(array),
      detail::tocpp<CPPAxes>(axes)
   );
   return handle;
}

// Create, general
Handle2Gridded2d
Gridded2dCreate(
   const XMLName label,
   ConstHandle2ConstArray array,
   ConstHandle2ConstAxes axes
) {
   ConstHandle2Gridded2d handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      detail::tocpp<CPPArray>(array),
      detail::tocpp<CPPAxes>(axes)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
Gridded2dAssign(ConstHandle2Gridded2d This, ConstHandle2ConstGridded2d from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
Gridded2dDelete(ConstHandle2ConstGridded2d This)
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
Gridded2dRead(ConstHandle2Gridded2d This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
Gridded2dWrite(ConstHandle2ConstGridded2d This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
Gridded2dPrint(ConstHandle2ConstGridded2d This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
Gridded2dPrintXML(ConstHandle2ConstGridded2d This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
Gridded2dPrintJSON(ConstHandle2ConstGridded2d This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
Gridded2dLabelHas(ConstHandle2ConstGridded2d This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
Gridded2dLabelGet(ConstHandle2ConstGridded2d This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
Gridded2dLabelSet(ConstHandle2Gridded2d This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Child: array
// -----------------------------------------------------------------------------

// Has
int
Gridded2dArrayHas(ConstHandle2ConstGridded2d This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ArrayHas", This, extract::array);
}

// Get, const
Handle2ConstArray
Gridded2dArrayGetConst(ConstHandle2ConstGridded2d This)
{
   return detail::getField<CPP,Handle2ConstArray>
      (CLASSNAME, CLASSNAME+"ArrayGetConst", This, extract::array);
}

// Get, non-const
Handle2Array
Gridded2dArrayGet(ConstHandle2Gridded2d This)
{
   return detail::getField<CPP,Handle2Array>
      (CLASSNAME, CLASSNAME+"ArrayGet", This, extract::array);
}

// Set
void
Gridded2dArraySet(ConstHandle2Gridded2d This, ConstHandle2ConstArray array)
{
   detail::setField<CPP,CPPArray>
      (CLASSNAME, CLASSNAME+"ArraySet", This, extract::array, array);
}


// -----------------------------------------------------------------------------
// Child: axes
// -----------------------------------------------------------------------------

// Has
int
Gridded2dAxesHas(ConstHandle2ConstGridded2d This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AxesHas", This, extract::axes);
}

// Get, const
Handle2ConstAxes
Gridded2dAxesGetConst(ConstHandle2ConstGridded2d This)
{
   return detail::getField<CPP,Handle2ConstAxes>
      (CLASSNAME, CLASSNAME+"AxesGetConst", This, extract::axes);
}

// Get, non-const
Handle2Axes
Gridded2dAxesGet(ConstHandle2Gridded2d This)
{
   return detail::getField<CPP,Handle2Axes>
      (CLASSNAME, CLASSNAME+"AxesGet", This, extract::axes);
}

// Set
void
Gridded2dAxesSet(ConstHandle2Gridded2d This, ConstHandle2ConstAxes axes)
{
   detail::setField<CPP,CPPAxes>
      (CLASSNAME, CLASSNAME+"AxesSet", This, extract::axes, axes);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/containers/Gridded2d/src/custom.cpp"
