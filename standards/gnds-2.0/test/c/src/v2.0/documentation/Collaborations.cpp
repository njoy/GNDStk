
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2.0/documentation/Collaborations.hpp"
#include "Collaborations.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = CollaborationsClass;
using CPP = multigroup::Collaborations;

static const std::string CLASSNAME = "Collaborations";

namespace extract {
   static auto collaboration = [](auto &obj) { return &obj.collaboration; };
}

using CPPCollaboration = documentation::Collaboration;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstCollaborations
CollaborationsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Collaborations
CollaborationsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstCollaborations
CollaborationsCreateConst(
   ConstHandle2Collaboration *const collaboration, const size_t collaborationSize
) {
   ConstHandle2Collaborations handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPCollaboration>{}
   );
   for (size_t CollaborationN = 0; CollaborationN < collaborationSize; ++CollaborationN)
      CollaborationsCollaborationAdd(handle, collaboration[CollaborationN]);
   return handle;
}

// Create, general
Handle2Collaborations
CollaborationsCreate(
   ConstHandle2Collaboration *const collaboration, const size_t collaborationSize
) {
   ConstHandle2Collaborations handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPCollaboration>{}
   );
   for (size_t CollaborationN = 0; CollaborationN < collaborationSize; ++CollaborationN)
      CollaborationsCollaborationAdd(handle, collaboration[CollaborationN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
CollaborationsAssign(ConstHandle2Collaborations self, ConstHandle2ConstCollaborations from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
CollaborationsDelete(ConstHandle2ConstCollaborations self)
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
CollaborationsRead(ConstHandle2Collaborations self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
CollaborationsWrite(ConstHandle2ConstCollaborations self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
CollaborationsPrint(ConstHandle2ConstCollaborations self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
CollaborationsPrintXML(ConstHandle2ConstCollaborations self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
CollaborationsPrintJSON(ConstHandle2ConstCollaborations self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: collaboration
// -----------------------------------------------------------------------------

// Has
int
CollaborationsCollaborationHas(ConstHandle2ConstCollaborations self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CollaborationHas", self, extract::collaboration);
}

// Clear
void
CollaborationsCollaborationClear(ConstHandle2Collaborations self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"CollaborationClear", self, extract::collaboration);
}

// Size
size_t
CollaborationsCollaborationSize(ConstHandle2ConstCollaborations self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"CollaborationSize", self, extract::collaboration);
}

// Add
void
CollaborationsCollaborationAdd(ConstHandle2Collaborations self, ConstHandle2ConstCollaboration collaboration)
{
   detail::addToContainer<CPP,CPPCollaboration>
      (CLASSNAME, CLASSNAME+"CollaborationAdd", self, extract::collaboration, collaboration);
}

// Get, by index \in [0,size), const
Handle2ConstCollaboration
CollaborationsCollaborationGetConst(ConstHandle2ConstCollaborations self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstCollaboration>
      (CLASSNAME, CLASSNAME+"CollaborationGetConst", self, extract::collaboration, index_);
}

// Get, by index \in [0,size), non-const
Handle2Collaboration
CollaborationsCollaborationGet(ConstHandle2Collaborations self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Collaboration>
      (CLASSNAME, CLASSNAME+"CollaborationGet", self, extract::collaboration, index_);
}

// Set, by index \in [0,size)
void
CollaborationsCollaborationSet(
   ConstHandle2Collaborations self,
   const size_t index_,
   ConstHandle2ConstCollaboration collaboration
) {
   detail::setByIndex<CPP,CPPCollaboration>
      (CLASSNAME, CLASSNAME+"CollaborationSet", self, extract::collaboration, index_, collaboration);
}

// Has, by name
int
CollaborationsCollaborationHasByName(
   ConstHandle2ConstCollaborations self,
   const UTF8Text name
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"CollaborationHasByName",
       self, extract::collaboration, meta::name, name);
}

// Get, by name, const
Handle2ConstCollaboration
CollaborationsCollaborationGetByNameConst(
   ConstHandle2ConstCollaborations self,
   const UTF8Text name
) {
   return detail::getByMetadatum<CPP,Handle2ConstCollaboration>
      (CLASSNAME, CLASSNAME+"CollaborationGetByNameConst",
       self, extract::collaboration, meta::name, name);
}

// Get, by name, non-const
Handle2Collaboration
CollaborationsCollaborationGetByName(
   ConstHandle2Collaborations self,
   const UTF8Text name
) {
   return detail::getByMetadatum<CPP,Handle2Collaboration>
      (CLASSNAME, CLASSNAME+"CollaborationGetByName",
       self, extract::collaboration, meta::name, name);
}

// Set, by name
void
CollaborationsCollaborationSetByName(
   ConstHandle2Collaborations self,
   const UTF8Text name,
   ConstHandle2ConstCollaboration collaboration
) {
   detail::setByMetadatum<CPP,CPPCollaboration>
      (CLASSNAME, CLASSNAME+"CollaborationSetByName",
       self, extract::collaboration, meta::name, name, collaboration);
}

// Has, by href
int
CollaborationsCollaborationHasByHref(
   ConstHandle2ConstCollaborations self,
   const UTF8Text href
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"CollaborationHasByHref",
       self, extract::collaboration, meta::href, href);
}

// Get, by href, const
Handle2ConstCollaboration
CollaborationsCollaborationGetByHrefConst(
   ConstHandle2ConstCollaborations self,
   const UTF8Text href
) {
   return detail::getByMetadatum<CPP,Handle2ConstCollaboration>
      (CLASSNAME, CLASSNAME+"CollaborationGetByHrefConst",
       self, extract::collaboration, meta::href, href);
}

// Get, by href, non-const
Handle2Collaboration
CollaborationsCollaborationGetByHref(
   ConstHandle2Collaborations self,
   const UTF8Text href
) {
   return detail::getByMetadatum<CPP,Handle2Collaboration>
      (CLASSNAME, CLASSNAME+"CollaborationGetByHref",
       self, extract::collaboration, meta::href, href);
}

// Set, by href
void
CollaborationsCollaborationSetByHref(
   ConstHandle2Collaborations self,
   const UTF8Text href,
   ConstHandle2ConstCollaboration collaboration
) {
   detail::setByMetadatum<CPP,CPPCollaboration>
      (CLASSNAME, CLASSNAME+"CollaborationSetByHref",
       self, extract::collaboration, meta::href, href, collaboration);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/documentation/Collaborations/src/custom.cpp"
