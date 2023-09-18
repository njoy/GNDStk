
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/Gridded2d.hpp"
#include "Gridded2d.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = Gridded2dClass;
using CPP = multigroup::Gridded2d;

static const std::string CLASSNAME = "Gridded2d";

namespace extract {
   static auto axes = [](auto &obj) { return &obj.axes; };
   static auto array = [](auto &obj) { return &obj.array; };
}

using CPPAxes = general::Axes;
using CPPArray = g2d::Array;


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
   ConstHandle2ConstAxes axes,
   ConstHandle2ConstArray array
) {
   ConstHandle2Gridded2d handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPAxes>(axes),
      detail::tocpp<CPPArray>(array)
   );
   return handle;
}

// Create, general
Handle2Gridded2d
Gridded2dCreate(
   ConstHandle2ConstAxes axes,
   ConstHandle2ConstArray array
) {
   ConstHandle2Gridded2d handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPAxes>(axes),
      detail::tocpp<CPPArray>(array)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
Gridded2dAssign(ConstHandle2Gridded2d self, ConstHandle2ConstGridded2d from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
Gridded2dDelete(ConstHandle2ConstGridded2d self)
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
Gridded2dRead(ConstHandle2Gridded2d self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
Gridded2dWrite(ConstHandle2ConstGridded2d self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
Gridded2dPrint(ConstHandle2ConstGridded2d self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
Gridded2dPrintXML(ConstHandle2ConstGridded2d self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
Gridded2dPrintJSON(ConstHandle2ConstGridded2d self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: axes
// -----------------------------------------------------------------------------

// Has
int
Gridded2dAxesHas(ConstHandle2ConstGridded2d self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AxesHas", self, extract::axes);
}

// Get, const
Handle2ConstAxes
Gridded2dAxesGetConst(ConstHandle2ConstGridded2d self)
{
   return detail::getField<CPP,Handle2ConstAxes>
      (CLASSNAME, CLASSNAME+"AxesGetConst", self, extract::axes);
}

// Get
Handle2Axes
Gridded2dAxesGet(ConstHandle2Gridded2d self)
{
   return detail::getField<CPP,Handle2Axes>
      (CLASSNAME, CLASSNAME+"AxesGet", self, extract::axes);
}

// Set
void
Gridded2dAxesSet(ConstHandle2Gridded2d self, ConstHandle2ConstAxes axes)
{
   detail::setField<CPP,CPPAxes>
      (CLASSNAME, CLASSNAME+"AxesSet", self, extract::axes, axes);
}


// -----------------------------------------------------------------------------
// Child: array
// -----------------------------------------------------------------------------

// Has
int
Gridded2dArrayHas(ConstHandle2ConstGridded2d self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ArrayHas", self, extract::array);
}

// Get, const
Handle2ConstArray
Gridded2dArrayGetConst(ConstHandle2ConstGridded2d self)
{
   return detail::getField<CPP,Handle2ConstArray>
      (CLASSNAME, CLASSNAME+"ArrayGetConst", self, extract::array);
}

// Get
Handle2Array
Gridded2dArrayGet(ConstHandle2Gridded2d self)
{
   return detail::getField<CPP,Handle2Array>
      (CLASSNAME, CLASSNAME+"ArrayGet", self, extract::array);
}

// Set
void
Gridded2dArraySet(ConstHandle2Gridded2d self, ConstHandle2ConstArray array)
{
   detail::setField<CPP,CPPArray>
      (CLASSNAME, CLASSNAME+"ArraySet", self, extract::array, array);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Gridded2d/src/custom.cpp"
