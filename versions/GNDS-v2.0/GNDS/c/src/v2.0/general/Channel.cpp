
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/Channel.hpp"
#include "Channel.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = ChannelClass;
using CPP = multigroup::Channel;

static const std::string CLASSNAME = "Channel";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto resonanceReaction = [](auto &obj) { return &obj.resonanceReaction; };
   static auto L = [](auto &obj) { return &obj.L; };
   static auto channelSpin = [](auto &obj) { return &obj.channelSpin; };
   static auto columnIndex = [](auto &obj) { return &obj.columnIndex; };
   static auto scatteringRadius = [](auto &obj) { return &obj.scatteringRadius; };
   static auto hardSphereRadius = [](auto &obj) { return &obj.hardSphereRadius; };
}

using CPPScatteringRadius = general::ScatteringRadius;
using CPPHardSphereRadius = general::HardSphereRadius;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstChannel
ChannelDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default, non-const
Handle2Channel
ChannelDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstChannel
ChannelCreateConst(
   const char *const label,
   const char *const resonanceReaction,
   const int L,
   const int channelSpin,
   const int columnIndex,
   ConstHandle2ConstScatteringRadius scatteringRadius,
   ConstHandle2ConstHardSphereRadius hardSphereRadius
) {
   ConstHandle2Channel handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      resonanceReaction,
      L,
      channelSpin,
      columnIndex,
      detail::tocpp<CPPScatteringRadius>(scatteringRadius),
      detail::tocpp<CPPHardSphereRadius>(hardSphereRadius)
   );
   return handle;
}

// Create, general, non-const
Handle2Channel
ChannelCreate(
   const char *const label,
   const char *const resonanceReaction,
   const int L,
   const int channelSpin,
   const int columnIndex,
   ConstHandle2ConstScatteringRadius scatteringRadius,
   ConstHandle2ConstHardSphereRadius hardSphereRadius
) {
   ConstHandle2Channel handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      resonanceReaction,
      L,
      channelSpin,
      columnIndex,
      detail::tocpp<CPPScatteringRadius>(scatteringRadius),
      detail::tocpp<CPPHardSphereRadius>(hardSphereRadius)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ChannelAssign(ConstHandle2Channel self, ConstHandle2ConstChannel from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ChannelDelete(ConstHandle2ConstChannel self)
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
ChannelRead(ConstHandle2Channel self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ChannelWrite(ConstHandle2ConstChannel self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ChannelPrint(ConstHandle2ConstChannel self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ChannelPrintXML(ConstHandle2ConstChannel self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ChannelPrintJSON(ConstHandle2ConstChannel self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
ChannelLabelHas(ConstHandle2ConstChannel self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
const char *
ChannelLabelGet(ConstHandle2ConstChannel self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
ChannelLabelSet(ConstHandle2Channel self, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: resonanceReaction
// -----------------------------------------------------------------------------

// Has
int
ChannelResonanceReactionHas(ConstHandle2ConstChannel self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ResonanceReactionHas", self, extract::resonanceReaction);
}

// Get
// Returns by value
const char *
ChannelResonanceReactionGet(ConstHandle2ConstChannel self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ResonanceReactionGet", self, extract::resonanceReaction);
}

// Set
void
ChannelResonanceReactionSet(ConstHandle2Channel self, const char *const resonanceReaction)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ResonanceReactionSet", self, extract::resonanceReaction, resonanceReaction);
}


// -----------------------------------------------------------------------------
// Metadatum: L
// -----------------------------------------------------------------------------

// Has
int
ChannelLHas(ConstHandle2ConstChannel self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LHas", self, extract::L);
}

// Get
// Returns by value
int
ChannelLGet(ConstHandle2ConstChannel self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LGet", self, extract::L);
}

// Set
void
ChannelLSet(ConstHandle2Channel self, const int L)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LSet", self, extract::L, L);
}


// -----------------------------------------------------------------------------
// Metadatum: channelSpin
// -----------------------------------------------------------------------------

// Has
int
ChannelChannelSpinHas(ConstHandle2ConstChannel self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ChannelSpinHas", self, extract::channelSpin);
}

// Get
// Returns by value
int
ChannelChannelSpinGet(ConstHandle2ConstChannel self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ChannelSpinGet", self, extract::channelSpin);
}

// Set
void
ChannelChannelSpinSet(ConstHandle2Channel self, const int channelSpin)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ChannelSpinSet", self, extract::channelSpin, channelSpin);
}


// -----------------------------------------------------------------------------
// Metadatum: columnIndex
// -----------------------------------------------------------------------------

// Has
int
ChannelColumnIndexHas(ConstHandle2ConstChannel self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ColumnIndexHas", self, extract::columnIndex);
}

// Get
// Returns by value
int
ChannelColumnIndexGet(ConstHandle2ConstChannel self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ColumnIndexGet", self, extract::columnIndex);
}

// Set
void
ChannelColumnIndexSet(ConstHandle2Channel self, const int columnIndex)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ColumnIndexSet", self, extract::columnIndex, columnIndex);
}


// -----------------------------------------------------------------------------
// Child: scatteringRadius
// -----------------------------------------------------------------------------

// Has
int
ChannelScatteringRadiusHas(ConstHandle2ConstChannel self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ScatteringRadiusHas", self, extract::scatteringRadius);
}

// Get, const
Handle2ConstScatteringRadius
ChannelScatteringRadiusGetConst(ConstHandle2ConstChannel self)
{
   return detail::getField<CPP,Handle2ConstScatteringRadius>
      (CLASSNAME, CLASSNAME+"ScatteringRadiusGetConst", self, extract::scatteringRadius);
}

// Get, non-const
Handle2ScatteringRadius
ChannelScatteringRadiusGet(ConstHandle2Channel self)
{
   return detail::getField<CPP,Handle2ScatteringRadius>
      (CLASSNAME, CLASSNAME+"ScatteringRadiusGet", self, extract::scatteringRadius);
}

// Set
void
ChannelScatteringRadiusSet(ConstHandle2Channel self, ConstHandle2ConstScatteringRadius scatteringRadius)
{
   detail::setField<CPP,CPPScatteringRadius>
      (CLASSNAME, CLASSNAME+"ScatteringRadiusSet", self, extract::scatteringRadius, scatteringRadius);
}


// -----------------------------------------------------------------------------
// Child: hardSphereRadius
// -----------------------------------------------------------------------------

// Has
int
ChannelHardSphereRadiusHas(ConstHandle2ConstChannel self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"HardSphereRadiusHas", self, extract::hardSphereRadius);
}

// Get, const
Handle2ConstHardSphereRadius
ChannelHardSphereRadiusGetConst(ConstHandle2ConstChannel self)
{
   return detail::getField<CPP,Handle2ConstHardSphereRadius>
      (CLASSNAME, CLASSNAME+"HardSphereRadiusGetConst", self, extract::hardSphereRadius);
}

// Get, non-const
Handle2HardSphereRadius
ChannelHardSphereRadiusGet(ConstHandle2Channel self)
{
   return detail::getField<CPP,Handle2HardSphereRadius>
      (CLASSNAME, CLASSNAME+"HardSphereRadiusGet", self, extract::hardSphereRadius);
}

// Set
void
ChannelHardSphereRadiusSet(ConstHandle2Channel self, ConstHandle2ConstHardSphereRadius hardSphereRadius)
{
   detail::setField<CPP,CPPHardSphereRadius>
      (CLASSNAME, CLASSNAME+"HardSphereRadiusSet", self, extract::hardSphereRadius, hardSphereRadius);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Channel/src/custom.cpp"
