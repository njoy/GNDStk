
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/transport/FastRegion.hpp"
#include "FastRegion.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = FastRegionClass;
using CPP = multigroup::FastRegion;

static const std::string CLASSNAME = "FastRegion";

namespace extract {
}

using CPPXYs1d = containers::XYs1d;
using CPPRegions1d = containers::Regions1d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstFastRegion
FastRegionDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2FastRegion
FastRegionDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstFastRegion
FastRegionCreateConst(
) {
   ConstHandle2FastRegion handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst"
   );
   return handle;
}

// Create, general
Handle2FastRegion
FastRegionCreate(
) {
   ConstHandle2FastRegion handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create"
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
FastRegionAssign(ConstHandle2FastRegion self, ConstHandle2ConstFastRegion from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
FastRegionDelete(ConstHandle2ConstFastRegion self)
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
FastRegionRead(ConstHandle2FastRegion self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
FastRegionWrite(ConstHandle2ConstFastRegion self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
FastRegionPrint(ConstHandle2ConstFastRegion self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
FastRegionPrintXML(ConstHandle2ConstFastRegion self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
FastRegionPrintJSON(ConstHandle2ConstFastRegion self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/transport/FastRegion/src/custom.cpp"
