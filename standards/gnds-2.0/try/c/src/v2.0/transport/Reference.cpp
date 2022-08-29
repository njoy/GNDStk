
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/transport/Reference.hpp"
#include "Reference.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = ReferenceClass;
using CPP = multigroup::Reference;

static const std::string CLASSNAME = "Reference";

namespace extract {
   static auto href = [](auto &obj) { return &obj.href; };
   static auto label = [](auto &obj) { return &obj.label; };
}


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstReference
ReferenceDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Reference
ReferenceDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstReference
ReferenceCreateConst(
   const char *const href,
   const XMLName label
) {
   ConstHandle2Reference handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      href,
      label
   );
   return handle;
}

// Create, general
Handle2Reference
ReferenceCreate(
   const char *const href,
   const XMLName label
) {
   ConstHandle2Reference handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      href,
      label
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ReferenceAssign(ConstHandle2Reference This, ConstHandle2ConstReference from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ReferenceDelete(ConstHandle2ConstReference This)
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
ReferenceRead(ConstHandle2Reference This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ReferenceWrite(ConstHandle2ConstReference This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
ReferencePrint(ConstHandle2ConstReference This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
ReferencePrintXML(ConstHandle2ConstReference This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
ReferencePrintJSON(ConstHandle2ConstReference This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// Has
int
ReferenceHrefHas(ConstHandle2ConstReference This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"HrefHas", This, extract::href);
}

// Get
// Returns by value
const char *
ReferenceHrefGet(ConstHandle2ConstReference This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"HrefGet", This, extract::href);
}

// Set
void
ReferenceHrefSet(ConstHandle2Reference This, const char *const href)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"HrefSet", This, extract::href, href);
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
ReferenceLabelHas(ConstHandle2ConstReference This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
ReferenceLabelGet(ConstHandle2ConstReference This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
ReferenceLabelSet(ConstHandle2Reference This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}
