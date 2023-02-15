
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/XYs3d.hpp"
#include "XYs3d.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = XYs3dClass;
using CPP = multigroup::XYs3d;

static const std::string CLASSNAME = "XYs3d";

namespace extract {
   static auto interpolationQualifier = [](auto &obj) { return &obj.interpolationQualifier; };
   static auto axes = [](auto &obj) { return &obj.axes; };
   static auto function2ds = [](auto &obj) { return &obj.function2ds; };
}

using CPPAxes = general::Axes;
using CPPFunction2ds = general::Function2ds;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstXYs3d
XYs3dDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2XYs3d
XYs3dDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstXYs3d
XYs3dCreateConst(
   const char *const interpolationQualifier,
   ConstHandle2ConstAxes axes,
   ConstHandle2Function2ds *const function2ds, const size_t function2dsSize
) {
   ConstHandle2XYs3d handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      interpolationQualifier,
      detail::tocpp<CPPAxes>(axes),
      std::vector<CPPFunction2ds>{}
   );
   for (size_t Function2dsN = 0; Function2dsN < function2dsSize; ++Function2dsN)
      XYs3dFunction2dsAdd(handle, function2ds[Function2dsN]);
   return handle;
}

// Create, general
Handle2XYs3d
XYs3dCreate(
   const char *const interpolationQualifier,
   ConstHandle2ConstAxes axes,
   ConstHandle2Function2ds *const function2ds, const size_t function2dsSize
) {
   ConstHandle2XYs3d handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      interpolationQualifier,
      detail::tocpp<CPPAxes>(axes),
      std::vector<CPPFunction2ds>{}
   );
   for (size_t Function2dsN = 0; Function2dsN < function2dsSize; ++Function2dsN)
      XYs3dFunction2dsAdd(handle, function2ds[Function2dsN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
XYs3dAssign(ConstHandle2XYs3d self, ConstHandle2ConstXYs3d from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
XYs3dDelete(ConstHandle2ConstXYs3d self)
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
XYs3dRead(ConstHandle2XYs3d self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
XYs3dWrite(ConstHandle2ConstXYs3d self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
XYs3dPrint(ConstHandle2ConstXYs3d self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
XYs3dPrintXML(ConstHandle2ConstXYs3d self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
XYs3dPrintJSON(ConstHandle2ConstXYs3d self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: interpolationQualifier
// -----------------------------------------------------------------------------

// Has
int
XYs3dInterpolationQualifierHas(ConstHandle2ConstXYs3d self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"InterpolationQualifierHas", self, extract::interpolationQualifier);
}

// Get
// Returns by value
const char *
XYs3dInterpolationQualifierGet(ConstHandle2ConstXYs3d self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"InterpolationQualifierGet", self, extract::interpolationQualifier);
}

// Set
void
XYs3dInterpolationQualifierSet(ConstHandle2XYs3d self, const char *const interpolationQualifier)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"InterpolationQualifierSet", self, extract::interpolationQualifier, interpolationQualifier);
}


// -----------------------------------------------------------------------------
// Child: axes
// -----------------------------------------------------------------------------

// Has
int
XYs3dAxesHas(ConstHandle2ConstXYs3d self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AxesHas", self, extract::axes);
}

// Get, const
Handle2ConstAxes
XYs3dAxesGetConst(ConstHandle2ConstXYs3d self)
{
   return detail::getField<CPP,Handle2ConstAxes>
      (CLASSNAME, CLASSNAME+"AxesGetConst", self, extract::axes);
}

// Get, non-const
Handle2Axes
XYs3dAxesGet(ConstHandle2XYs3d self)
{
   return detail::getField<CPP,Handle2Axes>
      (CLASSNAME, CLASSNAME+"AxesGet", self, extract::axes);
}

// Set
void
XYs3dAxesSet(ConstHandle2XYs3d self, ConstHandle2ConstAxes axes)
{
   detail::setField<CPP,CPPAxes>
      (CLASSNAME, CLASSNAME+"AxesSet", self, extract::axes, axes);
}


// -----------------------------------------------------------------------------
// Child: function2ds
// -----------------------------------------------------------------------------

// Has
int
XYs3dFunction2dsHas(ConstHandle2ConstXYs3d self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Function2dsHas", self, extract::function2ds);
}

// Clear
void
XYs3dFunction2dsClear(ConstHandle2XYs3d self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"Function2dsClear", self, extract::function2ds);
}

// Size
size_t
XYs3dFunction2dsSize(ConstHandle2ConstXYs3d self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"Function2dsSize", self, extract::function2ds);
}

// Add
void
XYs3dFunction2dsAdd(ConstHandle2XYs3d self, ConstHandle2ConstFunction2ds function2ds)
{
   detail::addToContainer<CPP,CPPFunction2ds>
      (CLASSNAME, CLASSNAME+"Function2dsAdd", self, extract::function2ds, function2ds);
}

// Get, by index \in [0,size), const
Handle2ConstFunction2ds
XYs3dFunction2dsGetConst(ConstHandle2ConstXYs3d self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstFunction2ds>
      (CLASSNAME, CLASSNAME+"Function2dsGetConst", self, extract::function2ds, index_);
}

// Get, by index \in [0,size), non-const
Handle2Function2ds
XYs3dFunction2dsGet(ConstHandle2XYs3d self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Function2ds>
      (CLASSNAME, CLASSNAME+"Function2dsGet", self, extract::function2ds, index_);
}

// Set, by index \in [0,size)
void
XYs3dFunction2dsSet(
   ConstHandle2XYs3d self,
   const size_t index_,
   ConstHandle2ConstFunction2ds function2ds
) {
   detail::setByIndex<CPP,CPPFunction2ds>
      (CLASSNAME, CLASSNAME+"Function2dsSet", self, extract::function2ds, index_, function2ds);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/XYs3d/src/custom.cpp"
