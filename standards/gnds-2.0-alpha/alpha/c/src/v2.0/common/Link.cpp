
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/common/Link.hpp"
#include "Link.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = LinkClass;
using CPP = multigroup::Link;

static const std::string CLASSNAME = "Link";

namespace extract {
   static auto href = [](auto &obj) { return &obj.href; };
}


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstLink
LinkDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Link
LinkDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstLink
LinkCreateConst(
   const char *const href
) {
   ConstHandle2Link handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      href
   );
   return handle;
}

// Create, general
Handle2Link
LinkCreate(
   const char *const href
) {
   ConstHandle2Link handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      href
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
LinkAssign(ConstHandle2Link This, ConstHandle2ConstLink from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
LinkDelete(ConstHandle2ConstLink This)
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
LinkRead(ConstHandle2Link This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
LinkWrite(ConstHandle2ConstLink This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
LinkPrint(ConstHandle2ConstLink This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
LinkPrintXML(ConstHandle2ConstLink This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
LinkPrintJSON(ConstHandle2ConstLink This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// Has
int
LinkHrefHas(ConstHandle2ConstLink This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"HrefHas", This, extract::href);
}

// Get
// Returns by value
const char *
LinkHrefGet(ConstHandle2ConstLink This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"HrefGet", This, extract::href);
}

// Set
void
LinkHrefSet(ConstHandle2Link This, const char *const href)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"HrefSet", This, extract::href, href);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/common/Link/src/custom.cpp"
