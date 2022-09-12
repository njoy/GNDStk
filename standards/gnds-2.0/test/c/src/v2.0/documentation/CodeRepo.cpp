
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/documentation/CodeRepo.hpp"
#include "CodeRepo.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = CodeRepoClass;
using CPP = multigroup::CodeRepo;

static const std::string CLASSNAME = "CodeRepo";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto revisionSystem = [](auto &obj) { return &obj.revisionSystem; };
   static auto href = [](auto &obj) { return &obj.href; };
   static auto revisionID = [](auto &obj) { return &obj.revisionID; };
}


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstCodeRepo
CodeRepoDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2CodeRepo
CodeRepoDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstCodeRepo
CodeRepoCreateConst(
   const XMLName label,
   const XMLName revisionSystem,
   const XMLName href,
   const XMLName revisionID
) {
   ConstHandle2CodeRepo handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      revisionSystem,
      href,
      revisionID
   );
   return handle;
}

// Create, general
Handle2CodeRepo
CodeRepoCreate(
   const XMLName label,
   const XMLName revisionSystem,
   const XMLName href,
   const XMLName revisionID
) {
   ConstHandle2CodeRepo handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      revisionSystem,
      href,
      revisionID
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
CodeRepoAssign(ConstHandle2CodeRepo This, ConstHandle2ConstCodeRepo from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
CodeRepoDelete(ConstHandle2ConstCodeRepo This)
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
CodeRepoRead(ConstHandle2CodeRepo This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
CodeRepoWrite(ConstHandle2ConstCodeRepo This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
CodeRepoPrint(ConstHandle2ConstCodeRepo This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
CodeRepoPrintXML(ConstHandle2ConstCodeRepo This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
CodeRepoPrintJSON(ConstHandle2ConstCodeRepo This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
CodeRepoLabelHas(ConstHandle2ConstCodeRepo This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
CodeRepoLabelGet(ConstHandle2ConstCodeRepo This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
CodeRepoLabelSet(ConstHandle2CodeRepo This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: revisionSystem
// -----------------------------------------------------------------------------

// Has
int
CodeRepoRevisionSystemHas(ConstHandle2ConstCodeRepo This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"RevisionSystemHas", This, extract::revisionSystem);
}

// Get
// Returns by value
XMLName
CodeRepoRevisionSystemGet(ConstHandle2ConstCodeRepo This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"RevisionSystemGet", This, extract::revisionSystem);
}

// Set
void
CodeRepoRevisionSystemSet(ConstHandle2CodeRepo This, const XMLName revisionSystem)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"RevisionSystemSet", This, extract::revisionSystem, revisionSystem);
}


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// Has
int
CodeRepoHrefHas(ConstHandle2ConstCodeRepo This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"HrefHas", This, extract::href);
}

// Get
// Returns by value
XMLName
CodeRepoHrefGet(ConstHandle2ConstCodeRepo This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"HrefGet", This, extract::href);
}

// Set
void
CodeRepoHrefSet(ConstHandle2CodeRepo This, const XMLName href)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"HrefSet", This, extract::href, href);
}


// -----------------------------------------------------------------------------
// Metadatum: revisionID
// -----------------------------------------------------------------------------

// Has
int
CodeRepoRevisionIDHas(ConstHandle2ConstCodeRepo This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"RevisionIDHas", This, extract::revisionID);
}

// Get
// Returns by value
XMLName
CodeRepoRevisionIDGet(ConstHandle2ConstCodeRepo This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"RevisionIDGet", This, extract::revisionID);
}

// Set
void
CodeRepoRevisionIDSet(ConstHandle2CodeRepo This, const XMLName revisionID)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"RevisionIDSet", This, extract::revisionID, revisionID);
}