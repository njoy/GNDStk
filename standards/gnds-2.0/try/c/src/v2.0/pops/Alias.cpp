
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/pops/Alias.hpp"
#include "Alias.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

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
   const XMLName id,
   const XMLName pid
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
   const XMLName id,
   const XMLName pid
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
AliasAssign(ConstHandle2Alias This, ConstHandle2ConstAlias from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
AliasDelete(ConstHandle2ConstAlias This)
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
AliasRead(ConstHandle2Alias This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
AliasWrite(ConstHandle2ConstAlias This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
AliasPrint(ConstHandle2ConstAlias This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
AliasPrintXML(ConstHandle2ConstAlias This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
AliasPrintJSON(ConstHandle2ConstAlias This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: id
// -----------------------------------------------------------------------------

// Has
int
AliasIdHas(ConstHandle2ConstAlias This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"IdHas", This, extract::id);
}

// Get
// Returns by value
XMLName
AliasIdGet(ConstHandle2ConstAlias This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"IdGet", This, extract::id);
}

// Set
void
AliasIdSet(ConstHandle2Alias This, const XMLName id)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"IdSet", This, extract::id, id);
}


// -----------------------------------------------------------------------------
// Metadatum: pid
// -----------------------------------------------------------------------------

// Has
int
AliasPidHas(ConstHandle2ConstAlias This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"PidHas", This, extract::pid);
}

// Get
// Returns by value
XMLName
AliasPidGet(ConstHandle2ConstAlias This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"PidGet", This, extract::pid);
}

// Set
void
AliasPidSet(ConstHandle2Alias This, const XMLName pid)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"PidSet", This, extract::pid, pid);
}
