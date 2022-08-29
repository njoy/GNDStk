
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/styles/Transportable.hpp"
#include "Transportable.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = TransportableClass;
using CPP = multigroup::Transportable;

static const std::string CLASSNAME = "Transportable";

namespace extract {
   static auto conserve = [](auto &obj) { return &obj.conserve; };
   static auto label = [](auto &obj) { return &obj.label; };
   static auto multiGroup = [](auto &obj) { return &obj.multiGroup; };
}

using CPPMultiGroup = styles::MultiGroup;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstTransportable
TransportableDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Transportable
TransportableDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstTransportable
TransportableCreateConst(
   const XMLName conserve,
   const XMLName label,
   ConstHandle2ConstMultiGroup multiGroup
) {
   ConstHandle2Transportable handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      conserve,
      label,
      detail::tocpp<CPPMultiGroup>(multiGroup)
   );
   return handle;
}

// Create, general
Handle2Transportable
TransportableCreate(
   const XMLName conserve,
   const XMLName label,
   ConstHandle2ConstMultiGroup multiGroup
) {
   ConstHandle2Transportable handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      conserve,
      label,
      detail::tocpp<CPPMultiGroup>(multiGroup)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
TransportableAssign(ConstHandle2Transportable This, ConstHandle2ConstTransportable from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
TransportableDelete(ConstHandle2ConstTransportable This)
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
TransportableRead(ConstHandle2Transportable This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
TransportableWrite(ConstHandle2ConstTransportable This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
TransportablePrint(ConstHandle2ConstTransportable This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
TransportablePrintXML(ConstHandle2ConstTransportable This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
TransportablePrintJSON(ConstHandle2ConstTransportable This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: conserve
// -----------------------------------------------------------------------------

// Has
int
TransportableConserveHas(ConstHandle2ConstTransportable This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ConserveHas", This, extract::conserve);
}

// Get
// Returns by value
XMLName
TransportableConserveGet(ConstHandle2ConstTransportable This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ConserveGet", This, extract::conserve);
}

// Set
void
TransportableConserveSet(ConstHandle2Transportable This, const XMLName conserve)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ConserveSet", This, extract::conserve, conserve);
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
TransportableLabelHas(ConstHandle2ConstTransportable This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
TransportableLabelGet(ConstHandle2ConstTransportable This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
TransportableLabelSet(ConstHandle2Transportable This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Child: multiGroup
// -----------------------------------------------------------------------------

// Has
int
TransportableMultiGroupHas(ConstHandle2ConstTransportable This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"MultiGroupHas", This, extract::multiGroup);
}

// Get, const
Handle2ConstMultiGroup
TransportableMultiGroupGetConst(ConstHandle2ConstTransportable This)
{
   return detail::getField<CPP,Handle2ConstMultiGroup>
      (CLASSNAME, CLASSNAME+"MultiGroupGetConst", This, extract::multiGroup);
}

// Get, non-const
Handle2MultiGroup
TransportableMultiGroupGet(ConstHandle2Transportable This)
{
   return detail::getField<CPP,Handle2MultiGroup>
      (CLASSNAME, CLASSNAME+"MultiGroupGet", This, extract::multiGroup);
}

// Set
void
TransportableMultiGroupSet(ConstHandle2Transportable This, ConstHandle2ConstMultiGroup multiGroup)
{
   detail::setField<CPP,CPPMultiGroup>
      (CLASSNAME, CLASSNAME+"MultiGroupSet", This, extract::multiGroup, multiGroup);
}
