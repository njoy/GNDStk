
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/Add.hpp"
#include "Add.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = AddClass;
using CPP = multigroup::Add;

static const std::string CLASSNAME = "Add";

namespace extract {
   static auto href = [](auto &obj) { return &obj.href; };
}


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstAdd
AddDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default, non-const
Handle2Add
AddDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstAdd
AddCreateConst(
   const char *const href
) {
   ConstHandle2Add handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      href
   );
   return handle;
}

// Create, general, non-const
Handle2Add
AddCreate(
   const char *const href
) {
   ConstHandle2Add handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      href
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
AddAssign(ConstHandle2Add self, ConstHandle2ConstAdd from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
AddDelete(ConstHandle2ConstAdd self)
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
AddRead(ConstHandle2Add self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
AddWrite(ConstHandle2ConstAdd self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
AddPrint(ConstHandle2ConstAdd self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
AddPrintXML(ConstHandle2ConstAdd self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
AddPrintJSON(ConstHandle2ConstAdd self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// Has
int
AddHrefHas(ConstHandle2ConstAdd self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"HrefHas", self, extract::href);
}

// Get
// Returns by value
const char *
AddHrefGet(ConstHandle2ConstAdd self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"HrefGet", self, extract::href);
}

// Set
void
AddHrefSet(ConstHandle2Add self, const char *const href)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"HrefSet", self, extract::href, href);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Add/src/custom.cpp"