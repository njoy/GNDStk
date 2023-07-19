
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2.0/containers/Gridded1d.hpp"
#include "Gridded1d.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = Gridded1dClass;
using CPP = multigroup::Gridded1d;

static const std::string CLASSNAME = "Gridded1d";

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
Handle2ConstGridded1d
Gridded1dDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Gridded1d
Gridded1dDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstGridded1d
Gridded1dCreateConst(
   const XMLName label,
   ConstHandle2ConstArray array,
   ConstHandle2ConstAxes axes
) {
   ConstHandle2Gridded1d handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      detail::tocpp<CPPArray>(array),
      detail::tocpp<CPPAxes>(axes)
   );
   return handle;
}

// Create, general
Handle2Gridded1d
Gridded1dCreate(
   const XMLName label,
   ConstHandle2ConstArray array,
   ConstHandle2ConstAxes axes
) {
   ConstHandle2Gridded1d handle = detail::createHandle<CPP,C>(
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
Gridded1dAssign(ConstHandle2Gridded1d self, ConstHandle2ConstGridded1d from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
Gridded1dDelete(ConstHandle2ConstGridded1d self)
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
Gridded1dRead(ConstHandle2Gridded1d self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
Gridded1dWrite(ConstHandle2ConstGridded1d self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
Gridded1dPrint(ConstHandle2ConstGridded1d self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
Gridded1dPrintXML(ConstHandle2ConstGridded1d self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
Gridded1dPrintJSON(ConstHandle2ConstGridded1d self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
Gridded1dLabelHas(ConstHandle2ConstGridded1d self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
XMLName
Gridded1dLabelGet(ConstHandle2ConstGridded1d self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
Gridded1dLabelSet(ConstHandle2Gridded1d self, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Child: array
// -----------------------------------------------------------------------------

// Has
int
Gridded1dArrayHas(ConstHandle2ConstGridded1d self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ArrayHas", self, extract::array);
}

// Get, const
Handle2ConstArray
Gridded1dArrayGetConst(ConstHandle2ConstGridded1d self)
{
   return detail::getField<CPP,Handle2ConstArray>
      (CLASSNAME, CLASSNAME+"ArrayGetConst", self, extract::array);
}

// Get, non-const
Handle2Array
Gridded1dArrayGet(ConstHandle2Gridded1d self)
{
   return detail::getField<CPP,Handle2Array>
      (CLASSNAME, CLASSNAME+"ArrayGet", self, extract::array);
}

// Set
void
Gridded1dArraySet(ConstHandle2Gridded1d self, ConstHandle2ConstArray array)
{
   detail::setField<CPP,CPPArray>
      (CLASSNAME, CLASSNAME+"ArraySet", self, extract::array, array);
}


// -----------------------------------------------------------------------------
// Child: axes
// -----------------------------------------------------------------------------

// Has
int
Gridded1dAxesHas(ConstHandle2ConstGridded1d self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AxesHas", self, extract::axes);
}

// Get, const
Handle2ConstAxes
Gridded1dAxesGetConst(ConstHandle2ConstGridded1d self)
{
   return detail::getField<CPP,Handle2ConstAxes>
      (CLASSNAME, CLASSNAME+"AxesGetConst", self, extract::axes);
}

// Get, non-const
Handle2Axes
Gridded1dAxesGet(ConstHandle2Gridded1d self)
{
   return detail::getField<CPP,Handle2Axes>
      (CLASSNAME, CLASSNAME+"AxesGet", self, extract::axes);
}

// Set
void
Gridded1dAxesSet(ConstHandle2Gridded1d self, ConstHandle2ConstAxes axes)
{
   detail::setField<CPP,CPPAxes>
      (CLASSNAME, CLASSNAME+"AxesSet", self, extract::axes, axes);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/containers/Gridded1d/src/custom.cpp"
