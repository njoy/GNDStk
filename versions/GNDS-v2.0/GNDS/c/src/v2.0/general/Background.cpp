
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/Background.hpp"
#include "Background.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = BackgroundClass;
using CPP = multigroup::Background;

static const std::string CLASSNAME = "Background";

namespace extract {
   static auto resolvedRegion = [](auto &obj) { return &obj.resolvedRegion; };
   static auto fastRegion = [](auto &obj) { return &obj.fastRegion; };
   static auto unresolvedRegion = [](auto &obj) { return &obj.unresolvedRegion; };
}

using CPPResolvedRegion = general::ResolvedRegion;
using CPPFastRegion = general::FastRegion;
using CPPUnresolvedRegion = general::UnresolvedRegion;


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

// Create, default, non-const
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
   ConstHandle2ConstFastRegion fastRegion,
   ConstHandle2ConstUnresolvedRegion unresolvedRegion
) {
   ConstHandle2Background handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPResolvedRegion>(resolvedRegion),
      detail::tocpp<CPPFastRegion>(fastRegion),
      detail::tocpp<CPPUnresolvedRegion>(unresolvedRegion)
   );
   return handle;
}

// Create, general, non-const
Handle2Background
BackgroundCreate(
   ConstHandle2ConstResolvedRegion resolvedRegion,
   ConstHandle2ConstFastRegion fastRegion,
   ConstHandle2ConstUnresolvedRegion unresolvedRegion
) {
   ConstHandle2Background handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPResolvedRegion>(resolvedRegion),
      detail::tocpp<CPPFastRegion>(fastRegion),
      detail::tocpp<CPPUnresolvedRegion>(unresolvedRegion)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
BackgroundAssign(ConstHandle2Background self, ConstHandle2ConstBackground from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
BackgroundDelete(ConstHandle2ConstBackground self)
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
BackgroundRead(ConstHandle2Background self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
BackgroundWrite(ConstHandle2ConstBackground self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
BackgroundPrint(ConstHandle2ConstBackground self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
BackgroundPrintXML(ConstHandle2ConstBackground self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
BackgroundPrintJSON(ConstHandle2ConstBackground self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: resolvedRegion
// -----------------------------------------------------------------------------

// Has
int
BackgroundResolvedRegionHas(ConstHandle2ConstBackground self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ResolvedRegionHas", self, extract::resolvedRegion);
}

// Get, const
Handle2ConstResolvedRegion
BackgroundResolvedRegionGetConst(ConstHandle2ConstBackground self)
{
   return detail::getField<CPP,Handle2ConstResolvedRegion>
      (CLASSNAME, CLASSNAME+"ResolvedRegionGetConst", self, extract::resolvedRegion);
}

// Get, non-const
Handle2ResolvedRegion
BackgroundResolvedRegionGet(ConstHandle2Background self)
{
   return detail::getField<CPP,Handle2ResolvedRegion>
      (CLASSNAME, CLASSNAME+"ResolvedRegionGet", self, extract::resolvedRegion);
}

// Set
void
BackgroundResolvedRegionSet(ConstHandle2Background self, ConstHandle2ConstResolvedRegion resolvedRegion)
{
   detail::setField<CPP,CPPResolvedRegion>
      (CLASSNAME, CLASSNAME+"ResolvedRegionSet", self, extract::resolvedRegion, resolvedRegion);
}


// -----------------------------------------------------------------------------
// Child: fastRegion
// -----------------------------------------------------------------------------

// Has
int
BackgroundFastRegionHas(ConstHandle2ConstBackground self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"FastRegionHas", self, extract::fastRegion);
}

// Get, const
Handle2ConstFastRegion
BackgroundFastRegionGetConst(ConstHandle2ConstBackground self)
{
   return detail::getField<CPP,Handle2ConstFastRegion>
      (CLASSNAME, CLASSNAME+"FastRegionGetConst", self, extract::fastRegion);
}

// Get, non-const
Handle2FastRegion
BackgroundFastRegionGet(ConstHandle2Background self)
{
   return detail::getField<CPP,Handle2FastRegion>
      (CLASSNAME, CLASSNAME+"FastRegionGet", self, extract::fastRegion);
}

// Set
void
BackgroundFastRegionSet(ConstHandle2Background self, ConstHandle2ConstFastRegion fastRegion)
{
   detail::setField<CPP,CPPFastRegion>
      (CLASSNAME, CLASSNAME+"FastRegionSet", self, extract::fastRegion, fastRegion);
}


// -----------------------------------------------------------------------------
// Child: unresolvedRegion
// -----------------------------------------------------------------------------

// Has
int
BackgroundUnresolvedRegionHas(ConstHandle2ConstBackground self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UnresolvedRegionHas", self, extract::unresolvedRegion);
}

// Get, const
Handle2ConstUnresolvedRegion
BackgroundUnresolvedRegionGetConst(ConstHandle2ConstBackground self)
{
   return detail::getField<CPP,Handle2ConstUnresolvedRegion>
      (CLASSNAME, CLASSNAME+"UnresolvedRegionGetConst", self, extract::unresolvedRegion);
}

// Get, non-const
Handle2UnresolvedRegion
BackgroundUnresolvedRegionGet(ConstHandle2Background self)
{
   return detail::getField<CPP,Handle2UnresolvedRegion>
      (CLASSNAME, CLASSNAME+"UnresolvedRegionGet", self, extract::unresolvedRegion);
}

// Set
void
BackgroundUnresolvedRegionSet(ConstHandle2Background self, ConstHandle2ConstUnresolvedRegion unresolvedRegion)
{
   detail::setField<CPP,CPPUnresolvedRegion>
      (CLASSNAME, CLASSNAME+"UnresolvedRegionSet", self, extract::unresolvedRegion, unresolvedRegion);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Background/src/custom.cpp"
