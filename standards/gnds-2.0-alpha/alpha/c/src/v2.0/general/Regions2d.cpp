
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/Regions2d.hpp"
#include "Regions2d.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = Regions2dClass;
using CPP = multigroup::Regions2d;

static const std::string CLASSNAME = "Regions2d";

namespace extract {
   static auto axes = [](auto &obj) { return &obj.axes; };
   static auto function2ds = [](auto &obj) { return &obj.function2ds; };
   static auto uncertainty = [](auto &obj) { return &obj.uncertainty; };
}

using CPPAxes = general::Axes;
using CPPFunction2ds = general::Function2ds;
using CPPUncertainty = general::Uncertainty;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstRegions2d
Regions2dDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Regions2d
Regions2dDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstRegions2d
Regions2dCreateConst(
   ConstHandle2ConstAxes axes,
   ConstHandle2ConstFunction2ds function2ds,
   ConstHandle2ConstUncertainty uncertainty
) {
   ConstHandle2Regions2d handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPAxes>(axes),
      detail::tocpp<CPPFunction2ds>(function2ds),
      detail::tocpp<CPPUncertainty>(uncertainty)
   );
   return handle;
}

// Create, general
Handle2Regions2d
Regions2dCreate(
   ConstHandle2ConstAxes axes,
   ConstHandle2ConstFunction2ds function2ds,
   ConstHandle2ConstUncertainty uncertainty
) {
   ConstHandle2Regions2d handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPAxes>(axes),
      detail::tocpp<CPPFunction2ds>(function2ds),
      detail::tocpp<CPPUncertainty>(uncertainty)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
Regions2dAssign(ConstHandle2Regions2d self, ConstHandle2ConstRegions2d from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
Regions2dDelete(ConstHandle2ConstRegions2d self)
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
Regions2dRead(ConstHandle2Regions2d self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
Regions2dWrite(ConstHandle2ConstRegions2d self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
Regions2dPrint(ConstHandle2ConstRegions2d self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
Regions2dPrintXML(ConstHandle2ConstRegions2d self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
Regions2dPrintJSON(ConstHandle2ConstRegions2d self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: axes
// -----------------------------------------------------------------------------

// Has
int
Regions2dAxesHas(ConstHandle2ConstRegions2d self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AxesHas", self, extract::axes);
}

// Get, const
Handle2ConstAxes
Regions2dAxesGetConst(ConstHandle2ConstRegions2d self)
{
   return detail::getField<CPP,Handle2ConstAxes>
      (CLASSNAME, CLASSNAME+"AxesGetConst", self, extract::axes);
}

// Get, non-const
Handle2Axes
Regions2dAxesGet(ConstHandle2Regions2d self)
{
   return detail::getField<CPP,Handle2Axes>
      (CLASSNAME, CLASSNAME+"AxesGet", self, extract::axes);
}

// Set
void
Regions2dAxesSet(ConstHandle2Regions2d self, ConstHandle2ConstAxes axes)
{
   detail::setField<CPP,CPPAxes>
      (CLASSNAME, CLASSNAME+"AxesSet", self, extract::axes, axes);
}


// -----------------------------------------------------------------------------
// Child: function2ds
// -----------------------------------------------------------------------------

// Has
int
Regions2dFunction2dsHas(ConstHandle2ConstRegions2d self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Function2dsHas", self, extract::function2ds);
}

// Get, const
Handle2ConstFunction2ds
Regions2dFunction2dsGetConst(ConstHandle2ConstRegions2d self)
{
   return detail::getField<CPP,Handle2ConstFunction2ds>
      (CLASSNAME, CLASSNAME+"Function2dsGetConst", self, extract::function2ds);
}

// Get, non-const
Handle2Function2ds
Regions2dFunction2dsGet(ConstHandle2Regions2d self)
{
   return detail::getField<CPP,Handle2Function2ds>
      (CLASSNAME, CLASSNAME+"Function2dsGet", self, extract::function2ds);
}

// Set
void
Regions2dFunction2dsSet(ConstHandle2Regions2d self, ConstHandle2ConstFunction2ds function2ds)
{
   detail::setField<CPP,CPPFunction2ds>
      (CLASSNAME, CLASSNAME+"Function2dsSet", self, extract::function2ds, function2ds);
}


// -----------------------------------------------------------------------------
// Child: uncertainty
// -----------------------------------------------------------------------------

// Has
int
Regions2dUncertaintyHas(ConstHandle2ConstRegions2d self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UncertaintyHas", self, extract::uncertainty);
}

// Get, const
Handle2ConstUncertainty
Regions2dUncertaintyGetConst(ConstHandle2ConstRegions2d self)
{
   return detail::getField<CPP,Handle2ConstUncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintyGetConst", self, extract::uncertainty);
}

// Get, non-const
Handle2Uncertainty
Regions2dUncertaintyGet(ConstHandle2Regions2d self)
{
   return detail::getField<CPP,Handle2Uncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintyGet", self, extract::uncertainty);
}

// Set
void
Regions2dUncertaintySet(ConstHandle2Regions2d self, ConstHandle2ConstUncertainty uncertainty)
{
   detail::setField<CPP,CPPUncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintySet", self, extract::uncertainty, uncertainty);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Regions2d/src/custom.cpp"
