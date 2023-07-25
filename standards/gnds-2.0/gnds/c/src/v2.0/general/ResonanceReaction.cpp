
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "gnds/v2.0/general/ResonanceReaction.hpp"
#include "ResonanceReaction.h"

using namespace njoy::GNDStk;
using namespace gnds::v2_0;

using C = ResonanceReactionClass;
using CPP = multigroup::ResonanceReaction;

static const std::string CLASSNAME = "ResonanceReaction";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto ejectile = [](auto &obj) { return &obj.ejectile; };
   static auto eliminated = [](auto &obj) { return &obj.eliminated; };
   static auto link = [](auto &obj) { return &obj.link; };
   static auto hardSphereRadius = [](auto &obj) { return &obj.hardSphereRadius; };
   static auto Q = [](auto &obj) { return &obj.Q; };
   static auto scatteringRadius = [](auto &obj) { return &obj.scatteringRadius; };
}

using CPPLink = general::Link;
using CPPHardSphereRadius = general::HardSphereRadius;
using CPPQ = general::Q;
using CPPScatteringRadius = general::ScatteringRadius;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstResonanceReaction
ResonanceReactionDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2ResonanceReaction
ResonanceReactionDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstResonanceReaction
ResonanceReactionCreateConst(
   const char *const label,
   const char *const ejectile,
   const bool eliminated,
   ConstHandle2ConstLink link,
   ConstHandle2ConstHardSphereRadius hardSphereRadius,
   ConstHandle2ConstQ Q,
   ConstHandle2ConstScatteringRadius scatteringRadius
) {
   ConstHandle2ResonanceReaction handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      ejectile,
      eliminated,
      detail::tocpp<CPPLink>(link),
      detail::tocpp<CPPHardSphereRadius>(hardSphereRadius),
      detail::tocpp<CPPQ>(Q),
      detail::tocpp<CPPScatteringRadius>(scatteringRadius)
   );
   return handle;
}

// Create, general
Handle2ResonanceReaction
ResonanceReactionCreate(
   const char *const label,
   const char *const ejectile,
   const bool eliminated,
   ConstHandle2ConstLink link,
   ConstHandle2ConstHardSphereRadius hardSphereRadius,
   ConstHandle2ConstQ Q,
   ConstHandle2ConstScatteringRadius scatteringRadius
) {
   ConstHandle2ResonanceReaction handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      ejectile,
      eliminated,
      detail::tocpp<CPPLink>(link),
      detail::tocpp<CPPHardSphereRadius>(hardSphereRadius),
      detail::tocpp<CPPQ>(Q),
      detail::tocpp<CPPScatteringRadius>(scatteringRadius)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ResonanceReactionAssign(ConstHandle2ResonanceReaction self, ConstHandle2ConstResonanceReaction from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ResonanceReactionDelete(ConstHandle2ConstResonanceReaction self)
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
ResonanceReactionRead(ConstHandle2ResonanceReaction self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ResonanceReactionWrite(ConstHandle2ConstResonanceReaction self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ResonanceReactionPrint(ConstHandle2ConstResonanceReaction self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ResonanceReactionPrintXML(ConstHandle2ConstResonanceReaction self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ResonanceReactionPrintJSON(ConstHandle2ConstResonanceReaction self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
ResonanceReactionLabelHas(ConstHandle2ConstResonanceReaction self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
const char *
ResonanceReactionLabelGet(ConstHandle2ConstResonanceReaction self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
ResonanceReactionLabelSet(ConstHandle2ResonanceReaction self, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: ejectile
// -----------------------------------------------------------------------------

// Has
int
ResonanceReactionEjectileHas(ConstHandle2ConstResonanceReaction self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EjectileHas", self, extract::ejectile);
}

// Get
// Returns by value
const char *
ResonanceReactionEjectileGet(ConstHandle2ConstResonanceReaction self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"EjectileGet", self, extract::ejectile);
}

// Set
void
ResonanceReactionEjectileSet(ConstHandle2ResonanceReaction self, const char *const ejectile)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"EjectileSet", self, extract::ejectile, ejectile);
}


// -----------------------------------------------------------------------------
// Metadatum: eliminated
// -----------------------------------------------------------------------------

// Has
int
ResonanceReactionEliminatedHas(ConstHandle2ConstResonanceReaction self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EliminatedHas", self, extract::eliminated);
}

// Get
// Returns by value
bool
ResonanceReactionEliminatedGet(ConstHandle2ConstResonanceReaction self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"EliminatedGet", self, extract::eliminated);
}

// Set
void
ResonanceReactionEliminatedSet(ConstHandle2ResonanceReaction self, const bool eliminated)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"EliminatedSet", self, extract::eliminated, eliminated);
}


// -----------------------------------------------------------------------------
// Child: link
// -----------------------------------------------------------------------------

// Has
int
ResonanceReactionLinkHas(ConstHandle2ConstResonanceReaction self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LinkHas", self, extract::link);
}

// Get, const
Handle2ConstLink
ResonanceReactionLinkGetConst(ConstHandle2ConstResonanceReaction self)
{
   return detail::getField<CPP,Handle2ConstLink>
      (CLASSNAME, CLASSNAME+"LinkGetConst", self, extract::link);
}

// Get, non-const
Handle2Link
ResonanceReactionLinkGet(ConstHandle2ResonanceReaction self)
{
   return detail::getField<CPP,Handle2Link>
      (CLASSNAME, CLASSNAME+"LinkGet", self, extract::link);
}

// Set
void
ResonanceReactionLinkSet(ConstHandle2ResonanceReaction self, ConstHandle2ConstLink link)
{
   detail::setField<CPP,CPPLink>
      (CLASSNAME, CLASSNAME+"LinkSet", self, extract::link, link);
}


// -----------------------------------------------------------------------------
// Child: hardSphereRadius
// -----------------------------------------------------------------------------

// Has
int
ResonanceReactionHardSphereRadiusHas(ConstHandle2ConstResonanceReaction self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"HardSphereRadiusHas", self, extract::hardSphereRadius);
}

// Get, const
Handle2ConstHardSphereRadius
ResonanceReactionHardSphereRadiusGetConst(ConstHandle2ConstResonanceReaction self)
{
   return detail::getField<CPP,Handle2ConstHardSphereRadius>
      (CLASSNAME, CLASSNAME+"HardSphereRadiusGetConst", self, extract::hardSphereRadius);
}

// Get, non-const
Handle2HardSphereRadius
ResonanceReactionHardSphereRadiusGet(ConstHandle2ResonanceReaction self)
{
   return detail::getField<CPP,Handle2HardSphereRadius>
      (CLASSNAME, CLASSNAME+"HardSphereRadiusGet", self, extract::hardSphereRadius);
}

// Set
void
ResonanceReactionHardSphereRadiusSet(ConstHandle2ResonanceReaction self, ConstHandle2ConstHardSphereRadius hardSphereRadius)
{
   detail::setField<CPP,CPPHardSphereRadius>
      (CLASSNAME, CLASSNAME+"HardSphereRadiusSet", self, extract::hardSphereRadius, hardSphereRadius);
}


// -----------------------------------------------------------------------------
// Child: Q
// -----------------------------------------------------------------------------

// Has
int
ResonanceReactionQHas(ConstHandle2ConstResonanceReaction self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"QHas", self, extract::Q);
}

// Get, const
Handle2ConstQ
ResonanceReactionQGetConst(ConstHandle2ConstResonanceReaction self)
{
   return detail::getField<CPP,Handle2ConstQ>
      (CLASSNAME, CLASSNAME+"QGetConst", self, extract::Q);
}

// Get, non-const
Handle2Q
ResonanceReactionQGet(ConstHandle2ResonanceReaction self)
{
   return detail::getField<CPP,Handle2Q>
      (CLASSNAME, CLASSNAME+"QGet", self, extract::Q);
}

// Set
void
ResonanceReactionQSet(ConstHandle2ResonanceReaction self, ConstHandle2ConstQ Q)
{
   detail::setField<CPP,CPPQ>
      (CLASSNAME, CLASSNAME+"QSet", self, extract::Q, Q);
}


// -----------------------------------------------------------------------------
// Child: scatteringRadius
// -----------------------------------------------------------------------------

// Has
int
ResonanceReactionScatteringRadiusHas(ConstHandle2ConstResonanceReaction self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ScatteringRadiusHas", self, extract::scatteringRadius);
}

// Get, const
Handle2ConstScatteringRadius
ResonanceReactionScatteringRadiusGetConst(ConstHandle2ConstResonanceReaction self)
{
   return detail::getField<CPP,Handle2ConstScatteringRadius>
      (CLASSNAME, CLASSNAME+"ScatteringRadiusGetConst", self, extract::scatteringRadius);
}

// Get, non-const
Handle2ScatteringRadius
ResonanceReactionScatteringRadiusGet(ConstHandle2ResonanceReaction self)
{
   return detail::getField<CPP,Handle2ScatteringRadius>
      (CLASSNAME, CLASSNAME+"ScatteringRadiusGet", self, extract::scatteringRadius);
}

// Set
void
ResonanceReactionScatteringRadiusSet(ConstHandle2ResonanceReaction self, ConstHandle2ConstScatteringRadius scatteringRadius)
{
   detail::setField<CPP,CPPScatteringRadius>
      (CLASSNAME, CLASSNAME+"ScatteringRadiusSet", self, extract::scatteringRadius, scatteringRadius);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/ResonanceReaction/src/custom.cpp"
