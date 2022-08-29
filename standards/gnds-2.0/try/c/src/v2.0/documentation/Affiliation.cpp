
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/documentation/Affiliation.hpp"
#include "Affiliation.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = AffiliationClass;
using CPP = multigroup::Affiliation;

static const std::string CLASSNAME = "Affiliation";

namespace extract {
   static auto name = [](auto &obj) { return &obj.name; };
   static auto href = [](auto &obj) { return &obj.href; };
}


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstAffiliation
AffiliationDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Affiliation
AffiliationDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstAffiliation
AffiliationCreateConst(
   const UTF8Text name,
   const UTF8Text href
) {
   ConstHandle2Affiliation handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      name,
      href
   );
   return handle;
}

// Create, general
Handle2Affiliation
AffiliationCreate(
   const UTF8Text name,
   const UTF8Text href
) {
   ConstHandle2Affiliation handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      name,
      href
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
AffiliationAssign(ConstHandle2Affiliation This, ConstHandle2ConstAffiliation from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
AffiliationDelete(ConstHandle2ConstAffiliation This)
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
AffiliationRead(ConstHandle2Affiliation This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
AffiliationWrite(ConstHandle2ConstAffiliation This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
AffiliationPrint(ConstHandle2ConstAffiliation This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
AffiliationPrintXML(ConstHandle2ConstAffiliation This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
AffiliationPrintJSON(ConstHandle2ConstAffiliation This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: name
// -----------------------------------------------------------------------------

// Has
int
AffiliationNameHas(ConstHandle2ConstAffiliation This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"NameHas", This, extract::name);
}

// Get
// Returns by value
UTF8Text
AffiliationNameGet(ConstHandle2ConstAffiliation This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"NameGet", This, extract::name);
}

// Set
void
AffiliationNameSet(ConstHandle2Affiliation This, const UTF8Text name)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"NameSet", This, extract::name, name);
}


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// Has
int
AffiliationHrefHas(ConstHandle2ConstAffiliation This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"HrefHas", This, extract::href);
}

// Get
// Returns by value
UTF8Text
AffiliationHrefGet(ConstHandle2ConstAffiliation This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"HrefGet", This, extract::href);
}

// Set
void
AffiliationHrefSet(ConstHandle2Affiliation This, const UTF8Text href)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"HrefSet", This, extract::href, href);
}
