
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/styles/Transportables.hpp"
#include "Transportables.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = TransportablesClass;
using CPP = multigroup::Transportables;

static const std::string CLASSNAME = "Transportables";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto transportable = [](auto &obj) { return &obj.transportable; };
}

using CPPTransportable = styles::Transportable;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstTransportables
TransportablesDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Transportables
TransportablesDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstTransportables
TransportablesCreateConst(
   const XMLName label,
   ConstHandle2Transportable *const transportable, const size_t transportableSize
) {
   ConstHandle2Transportables handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      std::vector<CPPTransportable>{}
   );
   for (size_t TransportableN = 0; TransportableN < transportableSize; ++TransportableN)
      TransportablesTransportableAdd(handle, transportable[TransportableN]);
   return handle;
}

// Create, general
Handle2Transportables
TransportablesCreate(
   const XMLName label,
   ConstHandle2Transportable *const transportable, const size_t transportableSize
) {
   ConstHandle2Transportables handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      std::vector<CPPTransportable>{}
   );
   for (size_t TransportableN = 0; TransportableN < transportableSize; ++TransportableN)
      TransportablesTransportableAdd(handle, transportable[TransportableN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
TransportablesAssign(ConstHandle2Transportables self, ConstHandle2ConstTransportables from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
TransportablesDelete(ConstHandle2ConstTransportables self)
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
TransportablesRead(ConstHandle2Transportables self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
TransportablesWrite(ConstHandle2ConstTransportables self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
TransportablesPrint(ConstHandle2ConstTransportables self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
TransportablesPrintXML(ConstHandle2ConstTransportables self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
TransportablesPrintJSON(ConstHandle2ConstTransportables self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
TransportablesLabelHas(ConstHandle2ConstTransportables self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
XMLName
TransportablesLabelGet(ConstHandle2ConstTransportables self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
TransportablesLabelSet(ConstHandle2Transportables self, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Child: transportable
// -----------------------------------------------------------------------------

// Has
int
TransportablesTransportableHas(ConstHandle2ConstTransportables self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"TransportableHas", self, extract::transportable);
}

// Clear
void
TransportablesTransportableClear(ConstHandle2Transportables self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"TransportableClear", self, extract::transportable);
}

// Size
size_t
TransportablesTransportableSize(ConstHandle2ConstTransportables self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"TransportableSize", self, extract::transportable);
}

// Add
void
TransportablesTransportableAdd(ConstHandle2Transportables self, ConstHandle2ConstTransportable transportable)
{
   detail::addToContainer<CPP,CPPTransportable>
      (CLASSNAME, CLASSNAME+"TransportableAdd", self, extract::transportable, transportable);
}

// Get, by index \in [0,size), const
Handle2ConstTransportable
TransportablesTransportableGetConst(ConstHandle2ConstTransportables self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstTransportable>
      (CLASSNAME, CLASSNAME+"TransportableGetConst", self, extract::transportable, index_);
}

// Get, by index \in [0,size), non-const
Handle2Transportable
TransportablesTransportableGet(ConstHandle2Transportables self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Transportable>
      (CLASSNAME, CLASSNAME+"TransportableGet", self, extract::transportable, index_);
}

// Set, by index \in [0,size)
void
TransportablesTransportableSet(
   ConstHandle2Transportables self,
   const size_t index_,
   ConstHandle2ConstTransportable transportable
) {
   detail::setByIndex<CPP,CPPTransportable>
      (CLASSNAME, CLASSNAME+"TransportableSet", self, extract::transportable, index_, transportable);
}

// Has, by conserve
int
TransportablesTransportableHasByConserve(
   ConstHandle2ConstTransportables self,
   const XMLName conserve
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"TransportableHasByConserve",
       self, extract::transportable, meta::conserve, conserve);
}

// Get, by conserve, const
Handle2ConstTransportable
TransportablesTransportableGetByConserveConst(
   ConstHandle2ConstTransportables self,
   const XMLName conserve
) {
   return detail::getByMetadatum<CPP,Handle2ConstTransportable>
      (CLASSNAME, CLASSNAME+"TransportableGetByConserveConst",
       self, extract::transportable, meta::conserve, conserve);
}

// Get, by conserve, non-const
Handle2Transportable
TransportablesTransportableGetByConserve(
   ConstHandle2Transportables self,
   const XMLName conserve
) {
   return detail::getByMetadatum<CPP,Handle2Transportable>
      (CLASSNAME, CLASSNAME+"TransportableGetByConserve",
       self, extract::transportable, meta::conserve, conserve);
}

// Set, by conserve
void
TransportablesTransportableSetByConserve(
   ConstHandle2Transportables self,
   const XMLName conserve,
   ConstHandle2ConstTransportable transportable
) {
   detail::setByMetadatum<CPP,CPPTransportable>
      (CLASSNAME, CLASSNAME+"TransportableSetByConserve",
       self, extract::transportable, meta::conserve, conserve, transportable);
}

// Has, by label
int
TransportablesTransportableHasByLabel(
   ConstHandle2ConstTransportables self,
   const XMLName label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"TransportableHasByLabel",
       self, extract::transportable, meta::label, label);
}

// Get, by label, const
Handle2ConstTransportable
TransportablesTransportableGetByLabelConst(
   ConstHandle2ConstTransportables self,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2ConstTransportable>
      (CLASSNAME, CLASSNAME+"TransportableGetByLabelConst",
       self, extract::transportable, meta::label, label);
}

// Get, by label, non-const
Handle2Transportable
TransportablesTransportableGetByLabel(
   ConstHandle2Transportables self,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2Transportable>
      (CLASSNAME, CLASSNAME+"TransportableGetByLabel",
       self, extract::transportable, meta::label, label);
}

// Set, by label
void
TransportablesTransportableSetByLabel(
   ConstHandle2Transportables self,
   const XMLName label,
   ConstHandle2ConstTransportable transportable
) {
   detail::setByMetadatum<CPP,CPPTransportable>
      (CLASSNAME, CLASSNAME+"TransportableSetByLabel",
       self, extract::transportable, meta::label, label, transportable);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/styles/Transportables/src/custom.cpp"
