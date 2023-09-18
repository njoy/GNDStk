
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/ResolvedRegion.hpp"
#include "ResolvedRegion.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = ResolvedRegionClass;
using CPP = multigroup::ResolvedRegion;

static const std::string CLASSNAME = "ResolvedRegion";

namespace extract {
   static auto XYs1d = [](auto &obj) { return &obj.XYs1d; };
   static auto regions1d = [](auto &obj) { return &obj.regions1d; };
}

using CPPXYs1d = general::XYs1d;
using CPPRegions1d = general::Regions1d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstResolvedRegion
ResolvedRegionDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2ResolvedRegion
ResolvedRegionDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstResolvedRegion
ResolvedRegionCreateConst(
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstRegions1d regions1d
) {
   ConstHandle2ResolvedRegion handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPXYs1d>(XYs1d),
      detail::tocpp<CPPRegions1d>(regions1d)
   );
   return handle;
}

// Create, general
Handle2ResolvedRegion
ResolvedRegionCreate(
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstRegions1d regions1d
) {
   ConstHandle2ResolvedRegion handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPXYs1d>(XYs1d),
      detail::tocpp<CPPRegions1d>(regions1d)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ResolvedRegionAssign(ConstHandle2ResolvedRegion self, ConstHandle2ConstResolvedRegion from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ResolvedRegionDelete(ConstHandle2ConstResolvedRegion self)
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
ResolvedRegionRead(ConstHandle2ResolvedRegion self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ResolvedRegionWrite(ConstHandle2ConstResolvedRegion self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ResolvedRegionPrint(ConstHandle2ConstResolvedRegion self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ResolvedRegionPrintXML(ConstHandle2ConstResolvedRegion self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ResolvedRegionPrintJSON(ConstHandle2ConstResolvedRegion self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// Has
int
ResolvedRegionXYs1dHas(ConstHandle2ConstResolvedRegion self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"XYs1dHas", self, extract::XYs1d);
}

// Get, const
Handle2ConstXYs1d
ResolvedRegionXYs1dGetConst(ConstHandle2ConstResolvedRegion self)
{
   return detail::getField<CPP,Handle2ConstXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGetConst", self, extract::XYs1d);
}

// Get
Handle2XYs1d
ResolvedRegionXYs1dGet(ConstHandle2ResolvedRegion self)
{
   return detail::getField<CPP,Handle2XYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGet", self, extract::XYs1d);
}

// Set
void
ResolvedRegionXYs1dSet(ConstHandle2ResolvedRegion self, ConstHandle2ConstXYs1d XYs1d)
{
   detail::setField<CPP,CPPXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dSet", self, extract::XYs1d, XYs1d);
}


// -----------------------------------------------------------------------------
// Child: regions1d
// -----------------------------------------------------------------------------

// Has
int
ResolvedRegionRegions1dHas(ConstHandle2ConstResolvedRegion self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Regions1dHas", self, extract::regions1d);
}

// Get, const
Handle2ConstRegions1d
ResolvedRegionRegions1dGetConst(ConstHandle2ConstResolvedRegion self)
{
   return detail::getField<CPP,Handle2ConstRegions1d>
      (CLASSNAME, CLASSNAME+"Regions1dGetConst", self, extract::regions1d);
}

// Get
Handle2Regions1d
ResolvedRegionRegions1dGet(ConstHandle2ResolvedRegion self)
{
   return detail::getField<CPP,Handle2Regions1d>
      (CLASSNAME, CLASSNAME+"Regions1dGet", self, extract::regions1d);
}

// Set
void
ResolvedRegionRegions1dSet(ConstHandle2ResolvedRegion self, ConstHandle2ConstRegions1d regions1d)
{
   detail::setField<CPP,CPPRegions1d>
      (CLASSNAME, CLASSNAME+"Regions1dSet", self, extract::regions1d, regions1d);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/ResolvedRegion/src/custom.cpp"
