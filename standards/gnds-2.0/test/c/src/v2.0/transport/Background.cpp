
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/transport/Background.hpp"
#include "Background.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = BackgroundClass;
using CPP = multigroup::Background;

static const std::string CLASSNAME = "Background";

namespace extract {
   static auto resolvedRegion = [](auto &obj) { return &obj.resolvedRegion; };
   static auto unresolvedRegion = [](auto &obj) { return &obj.unresolvedRegion; };
   static auto fastRegion = [](auto &obj) { return &obj.fastRegion; };
}

using CPPResolvedRegion = transport::ResolvedRegion;
using CPPUnresolvedRegion = transport::UnresolvedRegion;
using CPPFastRegion = transport::FastRegion;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstBackground
BackgroundDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Background
BackgroundDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstBackground
BackgroundCreateConst(
   ConstHandle2ConstResolvedRegion resolvedRegion,
   ConstHandle2ConstUnresolvedRegion unresolvedRegion,
   ConstHandle2ConstFastRegion fastRegion
) {
   ConstHandle2Background handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPResolvedRegion>(resolvedRegion),
      detail::tocpp<CPPUnresolvedRegion>(unresolvedRegion),
      detail::tocpp<CPPFastRegion>(fastRegion)
   );
   return handle;
}

// Create, general
Handle2Background
BackgroundCreate(
   ConstHandle2ConstResolvedRegion resolvedRegion,
   ConstHandle2ConstUnresolvedRegion unresolvedRegion,
   ConstHandle2ConstFastRegion fastRegion
) {
   ConstHandle2Background handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPResolvedRegion>(resolvedRegion),
      detail::tocpp<CPPUnresolvedRegion>(unresolvedRegion),
      detail::tocpp<CPPFastRegion>(fastRegion)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
BackgroundAssign(ConstHandle2Background This, ConstHandle2ConstBackground from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
BackgroundDelete(ConstHandle2ConstBackground This)
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
BackgroundRead(ConstHandle2Background This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
BackgroundWrite(ConstHandle2ConstBackground This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
BackgroundPrint(ConstHandle2ConstBackground This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
BackgroundPrintXML(ConstHandle2ConstBackground This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
BackgroundPrintJSON(ConstHandle2ConstBackground This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: resolvedRegion
// -----------------------------------------------------------------------------

// Has
int
BackgroundResolvedRegionHas(ConstHandle2ConstBackground This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ResolvedRegionHas", This, extract::resolvedRegion);
}

// Get, const
Handle2ConstResolvedRegion
BackgroundResolvedRegionGetConst(ConstHandle2ConstBackground This)
{
   return detail::getField<CPP,Handle2ConstResolvedRegion>
      (CLASSNAME, CLASSNAME+"ResolvedRegionGetConst", This, extract::resolvedRegion);
}

// Get, non-const
Handle2ResolvedRegion
BackgroundResolvedRegionGet(ConstHandle2Background This)
{
   return detail::getField<CPP,Handle2ResolvedRegion>
      (CLASSNAME, CLASSNAME+"ResolvedRegionGet", This, extract::resolvedRegion);
}

// Set
void
BackgroundResolvedRegionSet(ConstHandle2Background This, ConstHandle2ConstResolvedRegion resolvedRegion)
{
   detail::setField<CPP,CPPResolvedRegion>
      (CLASSNAME, CLASSNAME+"ResolvedRegionSet", This, extract::resolvedRegion, resolvedRegion);
}


// -----------------------------------------------------------------------------
// Child: unresolvedRegion
// -----------------------------------------------------------------------------

// Has
int
BackgroundUnresolvedRegionHas(ConstHandle2ConstBackground This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UnresolvedRegionHas", This, extract::unresolvedRegion);
}

// Get, const
Handle2ConstUnresolvedRegion
BackgroundUnresolvedRegionGetConst(ConstHandle2ConstBackground This)
{
   return detail::getField<CPP,Handle2ConstUnresolvedRegion>
      (CLASSNAME, CLASSNAME+"UnresolvedRegionGetConst", This, extract::unresolvedRegion);
}

// Get, non-const
Handle2UnresolvedRegion
BackgroundUnresolvedRegionGet(ConstHandle2Background This)
{
   return detail::getField<CPP,Handle2UnresolvedRegion>
      (CLASSNAME, CLASSNAME+"UnresolvedRegionGet", This, extract::unresolvedRegion);
}

// Set
void
BackgroundUnresolvedRegionSet(ConstHandle2Background This, ConstHandle2ConstUnresolvedRegion unresolvedRegion)
{
   detail::setField<CPP,CPPUnresolvedRegion>
      (CLASSNAME, CLASSNAME+"UnresolvedRegionSet", This, extract::unresolvedRegion, unresolvedRegion);
}


// -----------------------------------------------------------------------------
// Child: fastRegion
// -----------------------------------------------------------------------------

// Has
int
BackgroundFastRegionHas(ConstHandle2ConstBackground This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"FastRegionHas", This, extract::fastRegion);
}

// Get, const
Handle2ConstFastRegion
BackgroundFastRegionGetConst(ConstHandle2ConstBackground This)
{
   return detail::getField<CPP,Handle2ConstFastRegion>
      (CLASSNAME, CLASSNAME+"FastRegionGetConst", This, extract::fastRegion);
}

// Get, non-const
Handle2FastRegion
BackgroundFastRegionGet(ConstHandle2Background This)
{
   return detail::getField<CPP,Handle2FastRegion>
      (CLASSNAME, CLASSNAME+"FastRegionGet", This, extract::fastRegion);
}

// Set
void
BackgroundFastRegionSet(ConstHandle2Background This, ConstHandle2ConstFastRegion fastRegion)
{
   detail::setField<CPP,CPPFastRegion>
      (CLASSNAME, CLASSNAME+"FastRegionSet", This, extract::fastRegion, fastRegion);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/transport/Background/src/custom.cpp"
