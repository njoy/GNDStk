
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/Resonances.hpp"
#include "Resonances.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = ResonancesClass;
using CPP = multigroup::Resonances;

static const std::string CLASSNAME = "Resonances";

namespace extract {
   static auto href = [](auto &obj) { return &obj.href; };
   static auto scatteringRadius = [](auto &obj) { return &obj.scatteringRadius; };
   static auto resolved = [](auto &obj) { return &obj.resolved; };
   static auto unresolved = [](auto &obj) { return &obj.unresolved; };
}

using CPPScatteringRadius = general::ScatteringRadius;
using CPPResolved = general::Resolved;
using CPPUnresolved = general::Unresolved;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstResonances
ResonancesDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Resonances
ResonancesDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstResonances
ResonancesCreateConst(
   const char *const href,
   ConstHandle2ConstScatteringRadius scatteringRadius,
   ConstHandle2ConstResolved resolved,
   ConstHandle2ConstUnresolved unresolved
) {
   ConstHandle2Resonances handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      href,
      detail::tocpp<CPPScatteringRadius>(scatteringRadius),
      detail::tocpp<CPPResolved>(resolved),
      detail::tocpp<CPPUnresolved>(unresolved)
   );
   return handle;
}

// Create, general
Handle2Resonances
ResonancesCreate(
   const char *const href,
   ConstHandle2ConstScatteringRadius scatteringRadius,
   ConstHandle2ConstResolved resolved,
   ConstHandle2ConstUnresolved unresolved
) {
   ConstHandle2Resonances handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      href,
      detail::tocpp<CPPScatteringRadius>(scatteringRadius),
      detail::tocpp<CPPResolved>(resolved),
      detail::tocpp<CPPUnresolved>(unresolved)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ResonancesAssign(ConstHandle2Resonances self, ConstHandle2ConstResonances from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ResonancesDelete(ConstHandle2ConstResonances self)
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
ResonancesRead(ConstHandle2Resonances self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ResonancesWrite(ConstHandle2ConstResonances self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ResonancesPrint(ConstHandle2ConstResonances self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ResonancesPrintXML(ConstHandle2ConstResonances self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ResonancesPrintJSON(ConstHandle2ConstResonances self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// Has
int
ResonancesHrefHas(ConstHandle2ConstResonances self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"HrefHas", self, extract::href);
}

// Get
// Returns by value
const char *
ResonancesHrefGet(ConstHandle2ConstResonances self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"HrefGet", self, extract::href);
}

// Set
void
ResonancesHrefSet(ConstHandle2Resonances self, const char *const href)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"HrefSet", self, extract::href, href);
}


// -----------------------------------------------------------------------------
// Child: scatteringRadius
// -----------------------------------------------------------------------------

// Has
int
ResonancesScatteringRadiusHas(ConstHandle2ConstResonances self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ScatteringRadiusHas", self, extract::scatteringRadius);
}

// Get, const
Handle2ConstScatteringRadius
ResonancesScatteringRadiusGetConst(ConstHandle2ConstResonances self)
{
   return detail::getField<CPP,Handle2ConstScatteringRadius>
      (CLASSNAME, CLASSNAME+"ScatteringRadiusGetConst", self, extract::scatteringRadius);
}

// Get
Handle2ScatteringRadius
ResonancesScatteringRadiusGet(ConstHandle2Resonances self)
{
   return detail::getField<CPP,Handle2ScatteringRadius>
      (CLASSNAME, CLASSNAME+"ScatteringRadiusGet", self, extract::scatteringRadius);
}

// Set
void
ResonancesScatteringRadiusSet(ConstHandle2Resonances self, ConstHandle2ConstScatteringRadius scatteringRadius)
{
   detail::setField<CPP,CPPScatteringRadius>
      (CLASSNAME, CLASSNAME+"ScatteringRadiusSet", self, extract::scatteringRadius, scatteringRadius);
}


// -----------------------------------------------------------------------------
// Child: resolved
// -----------------------------------------------------------------------------

// Has
int
ResonancesResolvedHas(ConstHandle2ConstResonances self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ResolvedHas", self, extract::resolved);
}

// Get, const
Handle2ConstResolved
ResonancesResolvedGetConst(ConstHandle2ConstResonances self)
{
   return detail::getField<CPP,Handle2ConstResolved>
      (CLASSNAME, CLASSNAME+"ResolvedGetConst", self, extract::resolved);
}

// Get
Handle2Resolved
ResonancesResolvedGet(ConstHandle2Resonances self)
{
   return detail::getField<CPP,Handle2Resolved>
      (CLASSNAME, CLASSNAME+"ResolvedGet", self, extract::resolved);
}

// Set
void
ResonancesResolvedSet(ConstHandle2Resonances self, ConstHandle2ConstResolved resolved)
{
   detail::setField<CPP,CPPResolved>
      (CLASSNAME, CLASSNAME+"ResolvedSet", self, extract::resolved, resolved);
}


// -----------------------------------------------------------------------------
// Child: unresolved
// -----------------------------------------------------------------------------

// Has
int
ResonancesUnresolvedHas(ConstHandle2ConstResonances self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UnresolvedHas", self, extract::unresolved);
}

// Get, const
Handle2ConstUnresolved
ResonancesUnresolvedGetConst(ConstHandle2ConstResonances self)
{
   return detail::getField<CPP,Handle2ConstUnresolved>
      (CLASSNAME, CLASSNAME+"UnresolvedGetConst", self, extract::unresolved);
}

// Get
Handle2Unresolved
ResonancesUnresolvedGet(ConstHandle2Resonances self)
{
   return detail::getField<CPP,Handle2Unresolved>
      (CLASSNAME, CLASSNAME+"UnresolvedGet", self, extract::unresolved);
}

// Set
void
ResonancesUnresolvedSet(ConstHandle2Resonances self, ConstHandle2ConstUnresolved unresolved)
{
   detail::setField<CPP,CPPUnresolved>
      (CLASSNAME, CLASSNAME+"UnresolvedSet", self, extract::unresolved, unresolved);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Resonances/src/custom.cpp"
