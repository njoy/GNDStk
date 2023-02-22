
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/Alias.hpp"
#include "Alias.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = AliasClass;
using CPP = multigroup::Alias;

static const std::string CLASSNAME = "Alias";

namespace extract {
   static auto id = [](auto &obj) { return &obj.id; };
   static auto pid = [](auto &obj) { return &obj.pid; };
}


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstAlias
AliasDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Alias
AliasDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstAlias
AliasCreateConst(
   const char *const id,
   const char *const pid
) {
   ConstHandle2Alias handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      id,
      pid
   );
   return handle;
}

// Create, general
Handle2Alias
AliasCreate(
   const char *const id,
   const char *const pid
) {
   ConstHandle2Alias handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      id,
      pid
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
AliasAssign(ConstHandle2Alias self, ConstHandle2ConstAlias from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
AliasDelete(ConstHandle2ConstAlias self)
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
AliasRead(ConstHandle2Alias self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
AliasWrite(ConstHandle2ConstAlias self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
AliasPrint(ConstHandle2ConstAlias self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
AliasPrintXML(ConstHandle2ConstAlias self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
AliasPrintJSON(ConstHandle2ConstAlias self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: id
// -----------------------------------------------------------------------------

// Has
int
AliasIdHas(ConstHandle2ConstAlias self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"IdHas", self, extract::id);
}

// Get
// Returns by value
const char *
AliasIdGet(ConstHandle2ConstAlias self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"IdGet", self, extract::id);
}

// Set
void
AliasIdSet(ConstHandle2Alias self, const char *const id)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"IdSet", self, extract::id, id);
}


// -----------------------------------------------------------------------------
// Metadatum: pid
// -----------------------------------------------------------------------------

// Has
int
AliasPidHas(ConstHandle2ConstAlias self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"PidHas", self, extract::pid);
}

// Get
// Returns by value
const char *
AliasPidGet(ConstHandle2ConstAlias self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"PidGet", self, extract::pid);
}

// Set
void
AliasPidSet(ConstHandle2Alias self, const char *const pid)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"PidSet", self, extract::pid, pid);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Alias/src/custom.cpp"