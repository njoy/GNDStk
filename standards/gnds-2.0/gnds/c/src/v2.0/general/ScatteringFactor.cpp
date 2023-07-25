
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "gnds/v2.0/general/ScatteringFactor.hpp"
#include "ScatteringFactor.h"

using namespace njoy::GNDStk;
using namespace gnds::v2_0;

using C = ScatteringFactorClass;
using CPP = multigroup::ScatteringFactor;

static const std::string CLASSNAME = "ScatteringFactor";

namespace extract {
   static auto XYs1d = [](auto &obj) { return &obj.XYs1d; };
}

using CPPXYs1d = general::XYs1d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstScatteringFactor
ScatteringFactorDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2ScatteringFactor
ScatteringFactorDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstScatteringFactor
ScatteringFactorCreateConst(
   ConstHandle2ConstXYs1d XYs1d
) {
   ConstHandle2ScatteringFactor handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPXYs1d>(XYs1d)
   );
   return handle;
}

// Create, general
Handle2ScatteringFactor
ScatteringFactorCreate(
   ConstHandle2ConstXYs1d XYs1d
) {
   ConstHandle2ScatteringFactor handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPXYs1d>(XYs1d)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ScatteringFactorAssign(ConstHandle2ScatteringFactor self, ConstHandle2ConstScatteringFactor from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ScatteringFactorDelete(ConstHandle2ConstScatteringFactor self)
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
ScatteringFactorRead(ConstHandle2ScatteringFactor self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ScatteringFactorWrite(ConstHandle2ConstScatteringFactor self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ScatteringFactorPrint(ConstHandle2ConstScatteringFactor self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ScatteringFactorPrintXML(ConstHandle2ConstScatteringFactor self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ScatteringFactorPrintJSON(ConstHandle2ConstScatteringFactor self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// Has
int
ScatteringFactorXYs1dHas(ConstHandle2ConstScatteringFactor self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"XYs1dHas", self, extract::XYs1d);
}

// Get, const
Handle2ConstXYs1d
ScatteringFactorXYs1dGetConst(ConstHandle2ConstScatteringFactor self)
{
   return detail::getField<CPP,Handle2ConstXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGetConst", self, extract::XYs1d);
}

// Get, non-const
Handle2XYs1d
ScatteringFactorXYs1dGet(ConstHandle2ScatteringFactor self)
{
   return detail::getField<CPP,Handle2XYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGet", self, extract::XYs1d);
}

// Set
void
ScatteringFactorXYs1dSet(ConstHandle2ScatteringFactor self, ConstHandle2ConstXYs1d XYs1d)
{
   detail::setField<CPP,CPPXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dSet", self, extract::XYs1d, XYs1d);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/ScatteringFactor/src/custom.cpp"
