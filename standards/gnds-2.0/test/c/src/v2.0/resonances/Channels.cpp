
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2.0/resonances/Channels.hpp"
#include "Channels.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = ChannelsClass;
using CPP = multigroup::Channels;

static const std::string CLASSNAME = "Channels";

namespace extract {
   static auto channel = [](auto &obj) { return &obj.channel; };
}

using CPPChannel = resonances::Channel;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstChannels
ChannelsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Channels
ChannelsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstChannels
ChannelsCreateConst(
   ConstHandle2Channel *const channel, const size_t channelSize
) {
   ConstHandle2Channels handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPChannel>{}
   );
   for (size_t ChannelN = 0; ChannelN < channelSize; ++ChannelN)
      ChannelsChannelAdd(handle, channel[ChannelN]);
   return handle;
}

// Create, general
Handle2Channels
ChannelsCreate(
   ConstHandle2Channel *const channel, const size_t channelSize
) {
   ConstHandle2Channels handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPChannel>{}
   );
   for (size_t ChannelN = 0; ChannelN < channelSize; ++ChannelN)
      ChannelsChannelAdd(handle, channel[ChannelN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ChannelsAssign(ConstHandle2Channels self, ConstHandle2ConstChannels from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ChannelsDelete(ConstHandle2ConstChannels self)
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
ChannelsRead(ConstHandle2Channels self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ChannelsWrite(ConstHandle2ConstChannels self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ChannelsPrint(ConstHandle2ConstChannels self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ChannelsPrintXML(ConstHandle2ConstChannels self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ChannelsPrintJSON(ConstHandle2ConstChannels self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: channel
// -----------------------------------------------------------------------------

// Has
int
ChannelsChannelHas(ConstHandle2ConstChannels self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ChannelHas", self, extract::channel);
}

// Clear
void
ChannelsChannelClear(ConstHandle2Channels self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"ChannelClear", self, extract::channel);
}

// Size
size_t
ChannelsChannelSize(ConstHandle2ConstChannels self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"ChannelSize", self, extract::channel);
}

// Add
void
ChannelsChannelAdd(ConstHandle2Channels self, ConstHandle2ConstChannel channel)
{
   detail::addToContainer<CPP,CPPChannel>
      (CLASSNAME, CLASSNAME+"ChannelAdd", self, extract::channel, channel);
}

// Get, by index \in [0,size), const
Handle2ConstChannel
ChannelsChannelGetConst(ConstHandle2ConstChannels self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstChannel>
      (CLASSNAME, CLASSNAME+"ChannelGetConst", self, extract::channel, index_);
}

// Get, by index \in [0,size), non-const
Handle2Channel
ChannelsChannelGet(ConstHandle2Channels self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Channel>
      (CLASSNAME, CLASSNAME+"ChannelGet", self, extract::channel, index_);
}

// Set, by index \in [0,size)
void
ChannelsChannelSet(
   ConstHandle2Channels self,
   const size_t index_,
   ConstHandle2ConstChannel channel
) {
   detail::setByIndex<CPP,CPPChannel>
      (CLASSNAME, CLASSNAME+"ChannelSet", self, extract::channel, index_, channel);
}

// Has, by label
int
ChannelsChannelHasByLabel(
   ConstHandle2ConstChannels self,
   const XMLName label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ChannelHasByLabel",
       self, extract::channel, meta::label, label);
}

// Get, by label, const
Handle2ConstChannel
ChannelsChannelGetByLabelConst(
   ConstHandle2ConstChannels self,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2ConstChannel>
      (CLASSNAME, CLASSNAME+"ChannelGetByLabelConst",
       self, extract::channel, meta::label, label);
}

// Get, by label, non-const
Handle2Channel
ChannelsChannelGetByLabel(
   ConstHandle2Channels self,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2Channel>
      (CLASSNAME, CLASSNAME+"ChannelGetByLabel",
       self, extract::channel, meta::label, label);
}

// Set, by label
void
ChannelsChannelSetByLabel(
   ConstHandle2Channels self,
   const XMLName label,
   ConstHandle2ConstChannel channel
) {
   detail::setByMetadatum<CPP,CPPChannel>
      (CLASSNAME, CLASSNAME+"ChannelSetByLabel",
       self, extract::channel, meta::label, label, channel);
}

// Has, by resonanceReaction
int
ChannelsChannelHasByResonanceReaction(
   ConstHandle2ConstChannels self,
   const char *const resonanceReaction
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ChannelHasByResonanceReaction",
       self, extract::channel, meta::resonanceReaction, resonanceReaction);
}

// Get, by resonanceReaction, const
Handle2ConstChannel
ChannelsChannelGetByResonanceReactionConst(
   ConstHandle2ConstChannels self,
   const char *const resonanceReaction
) {
   return detail::getByMetadatum<CPP,Handle2ConstChannel>
      (CLASSNAME, CLASSNAME+"ChannelGetByResonanceReactionConst",
       self, extract::channel, meta::resonanceReaction, resonanceReaction);
}

// Get, by resonanceReaction, non-const
Handle2Channel
ChannelsChannelGetByResonanceReaction(
   ConstHandle2Channels self,
   const char *const resonanceReaction
) {
   return detail::getByMetadatum<CPP,Handle2Channel>
      (CLASSNAME, CLASSNAME+"ChannelGetByResonanceReaction",
       self, extract::channel, meta::resonanceReaction, resonanceReaction);
}

// Set, by resonanceReaction
void
ChannelsChannelSetByResonanceReaction(
   ConstHandle2Channels self,
   const char *const resonanceReaction,
   ConstHandle2ConstChannel channel
) {
   detail::setByMetadatum<CPP,CPPChannel>
      (CLASSNAME, CLASSNAME+"ChannelSetByResonanceReaction",
       self, extract::channel, meta::resonanceReaction, resonanceReaction, channel);
}

// Has, by L
int
ChannelsChannelHasByL(
   ConstHandle2ConstChannels self,
   const Integer32 L
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ChannelHasByL",
       self, extract::channel, meta::L, L);
}

// Get, by L, const
Handle2ConstChannel
ChannelsChannelGetByLConst(
   ConstHandle2ConstChannels self,
   const Integer32 L
) {
   return detail::getByMetadatum<CPP,Handle2ConstChannel>
      (CLASSNAME, CLASSNAME+"ChannelGetByLConst",
       self, extract::channel, meta::L, L);
}

// Get, by L, non-const
Handle2Channel
ChannelsChannelGetByL(
   ConstHandle2Channels self,
   const Integer32 L
) {
   return detail::getByMetadatum<CPP,Handle2Channel>
      (CLASSNAME, CLASSNAME+"ChannelGetByL",
       self, extract::channel, meta::L, L);
}

// Set, by L
void
ChannelsChannelSetByL(
   ConstHandle2Channels self,
   const Integer32 L,
   ConstHandle2ConstChannel channel
) {
   detail::setByMetadatum<CPP,CPPChannel>
      (CLASSNAME, CLASSNAME+"ChannelSetByL",
       self, extract::channel, meta::L, L, channel);
}

// Has, by channelSpin
int
ChannelsChannelHasByChannelSpin(
   ConstHandle2ConstChannels self,
   const Fraction32 channelSpin
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ChannelHasByChannelSpin",
       self, extract::channel, meta::channelSpin, channelSpin);
}

// Get, by channelSpin, const
Handle2ConstChannel
ChannelsChannelGetByChannelSpinConst(
   ConstHandle2ConstChannels self,
   const Fraction32 channelSpin
) {
   return detail::getByMetadatum<CPP,Handle2ConstChannel>
      (CLASSNAME, CLASSNAME+"ChannelGetByChannelSpinConst",
       self, extract::channel, meta::channelSpin, channelSpin);
}

// Get, by channelSpin, non-const
Handle2Channel
ChannelsChannelGetByChannelSpin(
   ConstHandle2Channels self,
   const Fraction32 channelSpin
) {
   return detail::getByMetadatum<CPP,Handle2Channel>
      (CLASSNAME, CLASSNAME+"ChannelGetByChannelSpin",
       self, extract::channel, meta::channelSpin, channelSpin);
}

// Set, by channelSpin
void
ChannelsChannelSetByChannelSpin(
   ConstHandle2Channels self,
   const Fraction32 channelSpin,
   ConstHandle2ConstChannel channel
) {
   detail::setByMetadatum<CPP,CPPChannel>
      (CLASSNAME, CLASSNAME+"ChannelSetByChannelSpin",
       self, extract::channel, meta::channelSpin, channelSpin, channel);
}

// Has, by boundaryConditionValue
int
ChannelsChannelHasByBoundaryConditionValue(
   ConstHandle2ConstChannels self,
   const Float64 boundaryConditionValue
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ChannelHasByBoundaryConditionValue",
       self, extract::channel, meta::boundaryConditionValue, boundaryConditionValue);
}

// Get, by boundaryConditionValue, const
Handle2ConstChannel
ChannelsChannelGetByBoundaryConditionValueConst(
   ConstHandle2ConstChannels self,
   const Float64 boundaryConditionValue
) {
   return detail::getByMetadatum<CPP,Handle2ConstChannel>
      (CLASSNAME, CLASSNAME+"ChannelGetByBoundaryConditionValueConst",
       self, extract::channel, meta::boundaryConditionValue, boundaryConditionValue);
}

// Get, by boundaryConditionValue, non-const
Handle2Channel
ChannelsChannelGetByBoundaryConditionValue(
   ConstHandle2Channels self,
   const Float64 boundaryConditionValue
) {
   return detail::getByMetadatum<CPP,Handle2Channel>
      (CLASSNAME, CLASSNAME+"ChannelGetByBoundaryConditionValue",
       self, extract::channel, meta::boundaryConditionValue, boundaryConditionValue);
}

// Set, by boundaryConditionValue
void
ChannelsChannelSetByBoundaryConditionValue(
   ConstHandle2Channels self,
   const Float64 boundaryConditionValue,
   ConstHandle2ConstChannel channel
) {
   detail::setByMetadatum<CPP,CPPChannel>
      (CLASSNAME, CLASSNAME+"ChannelSetByBoundaryConditionValue",
       self, extract::channel, meta::boundaryConditionValue, boundaryConditionValue, channel);
}

// Has, by columnIndex
int
ChannelsChannelHasByColumnIndex(
   ConstHandle2ConstChannels self,
   const Integer32 columnIndex
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ChannelHasByColumnIndex",
       self, extract::channel, meta::columnIndex, columnIndex);
}

// Get, by columnIndex, const
Handle2ConstChannel
ChannelsChannelGetByColumnIndexConst(
   ConstHandle2ConstChannels self,
   const Integer32 columnIndex
) {
   return detail::getByMetadatum<CPP,Handle2ConstChannel>
      (CLASSNAME, CLASSNAME+"ChannelGetByColumnIndexConst",
       self, extract::channel, meta::columnIndex, columnIndex);
}

// Get, by columnIndex, non-const
Handle2Channel
ChannelsChannelGetByColumnIndex(
   ConstHandle2Channels self,
   const Integer32 columnIndex
) {
   return detail::getByMetadatum<CPP,Handle2Channel>
      (CLASSNAME, CLASSNAME+"ChannelGetByColumnIndex",
       self, extract::channel, meta::columnIndex, columnIndex);
}

// Set, by columnIndex
void
ChannelsChannelSetByColumnIndex(
   ConstHandle2Channels self,
   const Integer32 columnIndex,
   ConstHandle2ConstChannel channel
) {
   detail::setByMetadatum<CPP,CPPChannel>
      (CLASSNAME, CLASSNAME+"ChannelSetByColumnIndex",
       self, extract::channel, meta::columnIndex, columnIndex, channel);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/resonances/Channels/src/custom.cpp"
