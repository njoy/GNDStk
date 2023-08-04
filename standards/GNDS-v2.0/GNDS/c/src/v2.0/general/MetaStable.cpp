
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/MetaStable.hpp"
#include "MetaStable.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = MetaStableClass;
using CPP = multigroup::MetaStable;

static const std::string CLASSNAME = "MetaStable";

namespace extract {
   static auto id = [](auto &obj) { return &obj.id; };
   static auto pid = [](auto &obj) { return &obj.pid; };
   static auto metaStableIndex = [](auto &obj) { return &obj.metaStableIndex; };
}


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstMetaStable
MetaStableDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2MetaStable
MetaStableDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstMetaStable
MetaStableCreateConst(
   const char *const id,
   const char *const pid,
   const int metaStableIndex
) {
   ConstHandle2MetaStable handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      id,
      pid,
      metaStableIndex
   );
   return handle;
}

// Create, general
Handle2MetaStable
MetaStableCreate(
   const char *const id,
   const char *const pid,
   const int metaStableIndex
) {
   ConstHandle2MetaStable handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      id,
      pid,
      metaStableIndex
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
MetaStableAssign(ConstHandle2MetaStable self, ConstHandle2ConstMetaStable from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
MetaStableDelete(ConstHandle2ConstMetaStable self)
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
MetaStableRead(ConstHandle2MetaStable self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
MetaStableWrite(ConstHandle2ConstMetaStable self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
MetaStablePrint(ConstHandle2ConstMetaStable self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
MetaStablePrintXML(ConstHandle2ConstMetaStable self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
MetaStablePrintJSON(ConstHandle2ConstMetaStable self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: id
// -----------------------------------------------------------------------------

// Has
int
MetaStableIdHas(ConstHandle2ConstMetaStable self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"IdHas", self, extract::id);
}

// Get
// Returns by value
const char *
MetaStableIdGet(ConstHandle2ConstMetaStable self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"IdGet", self, extract::id);
}

// Set
void
MetaStableIdSet(ConstHandle2MetaStable self, const char *const id)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"IdSet", self, extract::id, id);
}


// -----------------------------------------------------------------------------
// Metadatum: pid
// -----------------------------------------------------------------------------

// Has
int
MetaStablePidHas(ConstHandle2ConstMetaStable self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"PidHas", self, extract::pid);
}

// Get
// Returns by value
const char *
MetaStablePidGet(ConstHandle2ConstMetaStable self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"PidGet", self, extract::pid);
}

// Set
void
MetaStablePidSet(ConstHandle2MetaStable self, const char *const pid)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"PidSet", self, extract::pid, pid);
}


// -----------------------------------------------------------------------------
// Metadatum: metaStableIndex
// -----------------------------------------------------------------------------

// Has
int
MetaStableMetaStableIndexHas(ConstHandle2ConstMetaStable self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"MetaStableIndexHas", self, extract::metaStableIndex);
}

// Get
// Returns by value
int
MetaStableMetaStableIndexGet(ConstHandle2ConstMetaStable self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"MetaStableIndexGet", self, extract::metaStableIndex);
}

// Set
void
MetaStableMetaStableIndexSet(ConstHandle2MetaStable self, const int metaStableIndex)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"MetaStableIndexSet", self, extract::metaStableIndex, metaStableIndex);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/MetaStable/src/custom.cpp"