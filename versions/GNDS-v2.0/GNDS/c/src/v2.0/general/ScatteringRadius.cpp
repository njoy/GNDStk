
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/ScatteringRadius.hpp"
#include "ScatteringRadius.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = ScatteringRadiusClass;
using CPP = multigroup::ScatteringRadius;

static const std::string CLASSNAME = "ScatteringRadius";

namespace extract {
   static auto constant1d = [](auto &obj) { return &obj.constant1d; };
   static auto XYs1d = [](auto &obj) { return &obj.XYs1d; };
}

using CPPConstant1d = general::Constant1d;
using CPPXYs1d = general::XYs1d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstScatteringRadius
ScatteringRadiusDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2ScatteringRadius
ScatteringRadiusDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstScatteringRadius
ScatteringRadiusCreateConst(
   ConstHandle2ConstConstant1d constant1d,
   ConstHandle2ConstXYs1d XYs1d
) {
   ConstHandle2ScatteringRadius handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPConstant1d>(constant1d),
      detail::tocpp<CPPXYs1d>(XYs1d)
   );
   return handle;
}

// Create, general
Handle2ScatteringRadius
ScatteringRadiusCreate(
   ConstHandle2ConstConstant1d constant1d,
   ConstHandle2ConstXYs1d XYs1d
) {
   ConstHandle2ScatteringRadius handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPConstant1d>(constant1d),
      detail::tocpp<CPPXYs1d>(XYs1d)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ScatteringRadiusAssign(ConstHandle2ScatteringRadius self, ConstHandle2ConstScatteringRadius from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ScatteringRadiusDelete(ConstHandle2ConstScatteringRadius self)
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
ScatteringRadiusRead(ConstHandle2ScatteringRadius self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ScatteringRadiusWrite(ConstHandle2ConstScatteringRadius self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ScatteringRadiusPrint(ConstHandle2ConstScatteringRadius self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ScatteringRadiusPrintXML(ConstHandle2ConstScatteringRadius self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ScatteringRadiusPrintJSON(ConstHandle2ConstScatteringRadius self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: constant1d
// -----------------------------------------------------------------------------

// Has
int
ScatteringRadiusConstant1dHas(ConstHandle2ConstScatteringRadius self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Constant1dHas", self, extract::constant1d);
}

// Get, const
Handle2ConstConstant1d
ScatteringRadiusConstant1dGetConst(ConstHandle2ConstScatteringRadius self)
{
   return detail::getField<CPP,Handle2ConstConstant1d>
      (CLASSNAME, CLASSNAME+"Constant1dGetConst", self, extract::constant1d);
}

// Get
Handle2Constant1d
ScatteringRadiusConstant1dGet(ConstHandle2ScatteringRadius self)
{
   return detail::getField<CPP,Handle2Constant1d>
      (CLASSNAME, CLASSNAME+"Constant1dGet", self, extract::constant1d);
}

// Set
void
ScatteringRadiusConstant1dSet(ConstHandle2ScatteringRadius self, ConstHandle2ConstConstant1d constant1d)
{
   detail::setField<CPP,CPPConstant1d>
      (CLASSNAME, CLASSNAME+"Constant1dSet", self, extract::constant1d, constant1d);
}


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// Has
int
ScatteringRadiusXYs1dHas(ConstHandle2ConstScatteringRadius self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"XYs1dHas", self, extract::XYs1d);
}

// Get, const
Handle2ConstXYs1d
ScatteringRadiusXYs1dGetConst(ConstHandle2ConstScatteringRadius self)
{
   return detail::getField<CPP,Handle2ConstXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGetConst", self, extract::XYs1d);
}

// Get
Handle2XYs1d
ScatteringRadiusXYs1dGet(ConstHandle2ScatteringRadius self)
{
   return detail::getField<CPP,Handle2XYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGet", self, extract::XYs1d);
}

// Set
void
ScatteringRadiusXYs1dSet(ConstHandle2ScatteringRadius self, ConstHandle2ConstXYs1d XYs1d)
{
   detail::setField<CPP,CPPXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dSet", self, extract::XYs1d, XYs1d);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/ScatteringRadius/src/custom.cpp"
