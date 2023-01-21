
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/resonances/SpinGroup.hpp"
#include "SpinGroup.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = SpinGroupClass;
using CPP = multigroup::SpinGroup;

static const std::string CLASSNAME = "SpinGroup";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto spin = [](auto &obj) { return &obj.spin; };
   static auto parity = [](auto &obj) { return &obj.parity; };
   static auto channels = [](auto &obj) { return &obj.channels; };
   static auto resonanceParameters = [](auto &obj) { return &obj.resonanceParameters; };
}

using CPPChannels = resonances::Channels;
using CPPResonanceParameters = resonances::ResonanceParameters;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstSpinGroup
SpinGroupDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2SpinGroup
SpinGroupDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstSpinGroup
SpinGroupCreateConst(
   const XMLName label,
   const Fraction32 spin,
   const Integer32 parity,
   ConstHandle2ConstChannels channels,
   ConstHandle2ConstResonanceParameters resonanceParameters
) {
   ConstHandle2SpinGroup handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      spin,
      parity,
      detail::tocpp<CPPChannels>(channels),
      detail::tocpp<CPPResonanceParameters>(resonanceParameters)
   );
   return handle;
}

// Create, general
Handle2SpinGroup
SpinGroupCreate(
   const XMLName label,
   const Fraction32 spin,
   const Integer32 parity,
   ConstHandle2ConstChannels channels,
   ConstHandle2ConstResonanceParameters resonanceParameters
) {
   ConstHandle2SpinGroup handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      spin,
      parity,
      detail::tocpp<CPPChannels>(channels),
      detail::tocpp<CPPResonanceParameters>(resonanceParameters)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
SpinGroupAssign(ConstHandle2SpinGroup This, ConstHandle2ConstSpinGroup from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
SpinGroupDelete(ConstHandle2ConstSpinGroup This)
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
SpinGroupRead(ConstHandle2SpinGroup This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
SpinGroupWrite(ConstHandle2ConstSpinGroup This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
SpinGroupPrint(ConstHandle2ConstSpinGroup This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
SpinGroupPrintXML(ConstHandle2ConstSpinGroup This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
SpinGroupPrintJSON(ConstHandle2ConstSpinGroup This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
SpinGroupLabelHas(ConstHandle2ConstSpinGroup This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
SpinGroupLabelGet(ConstHandle2ConstSpinGroup This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
SpinGroupLabelSet(ConstHandle2SpinGroup This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: spin
// -----------------------------------------------------------------------------

// Has
int
SpinGroupSpinHas(ConstHandle2ConstSpinGroup This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SpinHas", This, extract::spin);
}

// Get
// Returns by value
Fraction32
SpinGroupSpinGet(ConstHandle2ConstSpinGroup This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"SpinGet", This, extract::spin);
}

// Set
void
SpinGroupSpinSet(ConstHandle2SpinGroup This, const Fraction32 spin)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"SpinSet", This, extract::spin, spin);
}


// -----------------------------------------------------------------------------
// Metadatum: parity
// -----------------------------------------------------------------------------

// Has
int
SpinGroupParityHas(ConstHandle2ConstSpinGroup This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ParityHas", This, extract::parity);
}

// Get
// Returns by value
Integer32
SpinGroupParityGet(ConstHandle2ConstSpinGroup This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ParityGet", This, extract::parity);
}

// Set
void
SpinGroupParitySet(ConstHandle2SpinGroup This, const Integer32 parity)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ParitySet", This, extract::parity, parity);
}


// -----------------------------------------------------------------------------
// Child: channels
// -----------------------------------------------------------------------------

// Has
int
SpinGroupChannelsHas(ConstHandle2ConstSpinGroup This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ChannelsHas", This, extract::channels);
}

// Get, const
Handle2ConstChannels
SpinGroupChannelsGetConst(ConstHandle2ConstSpinGroup This)
{
   return detail::getField<CPP,Handle2ConstChannels>
      (CLASSNAME, CLASSNAME+"ChannelsGetConst", This, extract::channels);
}

// Get, non-const
Handle2Channels
SpinGroupChannelsGet(ConstHandle2SpinGroup This)
{
   return detail::getField<CPP,Handle2Channels>
      (CLASSNAME, CLASSNAME+"ChannelsGet", This, extract::channels);
}

// Set
void
SpinGroupChannelsSet(ConstHandle2SpinGroup This, ConstHandle2ConstChannels channels)
{
   detail::setField<CPP,CPPChannels>
      (CLASSNAME, CLASSNAME+"ChannelsSet", This, extract::channels, channels);
}


// -----------------------------------------------------------------------------
// Child: resonanceParameters
// -----------------------------------------------------------------------------

// Has
int
SpinGroupResonanceParametersHas(ConstHandle2ConstSpinGroup This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ResonanceParametersHas", This, extract::resonanceParameters);
}

// Get, const
Handle2ConstResonanceParameters
SpinGroupResonanceParametersGetConst(ConstHandle2ConstSpinGroup This)
{
   return detail::getField<CPP,Handle2ConstResonanceParameters>
      (CLASSNAME, CLASSNAME+"ResonanceParametersGetConst", This, extract::resonanceParameters);
}

// Get, non-const
Handle2ResonanceParameters
SpinGroupResonanceParametersGet(ConstHandle2SpinGroup This)
{
   return detail::getField<CPP,Handle2ResonanceParameters>
      (CLASSNAME, CLASSNAME+"ResonanceParametersGet", This, extract::resonanceParameters);
}

// Set
void
SpinGroupResonanceParametersSet(ConstHandle2SpinGroup This, ConstHandle2ConstResonanceParameters resonanceParameters)
{
   detail::setField<CPP,CPPResonanceParameters>
      (CLASSNAME, CLASSNAME+"ResonanceParametersSet", This, extract::resonanceParameters, resonanceParameters);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/resonances/SpinGroup/src/custom.cpp"
