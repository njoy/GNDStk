
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/SpinGroups.hpp"
#include "SpinGroups.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = SpinGroupsClass;
using CPP = multigroup::SpinGroups;

static const std::string CLASSNAME = "SpinGroups";

namespace extract {
   static auto spinGroup = [](auto &obj) { return &obj.spinGroup; };
}

using CPPSpinGroup = general::SpinGroup;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstSpinGroups
SpinGroupsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2SpinGroups
SpinGroupsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstSpinGroups
SpinGroupsCreateConst(
   ConstHandle2SpinGroup *const spinGroup, const size_t spinGroupSize
) {
   ConstHandle2SpinGroups handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPSpinGroup>{}
   );
   for (size_t SpinGroupN = 0; SpinGroupN < spinGroupSize; ++SpinGroupN)
      SpinGroupsSpinGroupAdd(handle, spinGroup[SpinGroupN]);
   return handle;
}

// Create, general
Handle2SpinGroups
SpinGroupsCreate(
   ConstHandle2SpinGroup *const spinGroup, const size_t spinGroupSize
) {
   ConstHandle2SpinGroups handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPSpinGroup>{}
   );
   for (size_t SpinGroupN = 0; SpinGroupN < spinGroupSize; ++SpinGroupN)
      SpinGroupsSpinGroupAdd(handle, spinGroup[SpinGroupN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
SpinGroupsAssign(ConstHandle2SpinGroups self, ConstHandle2ConstSpinGroups from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
SpinGroupsDelete(ConstHandle2ConstSpinGroups self)
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
SpinGroupsRead(ConstHandle2SpinGroups self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
SpinGroupsWrite(ConstHandle2ConstSpinGroups self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
SpinGroupsPrint(ConstHandle2ConstSpinGroups self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
SpinGroupsPrintXML(ConstHandle2ConstSpinGroups self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
SpinGroupsPrintJSON(ConstHandle2ConstSpinGroups self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: spinGroup
// -----------------------------------------------------------------------------

// Has
int
SpinGroupsSpinGroupHas(ConstHandle2ConstSpinGroups self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SpinGroupHas", self, extract::spinGroup);
}

// Clear
void
SpinGroupsSpinGroupClear(ConstHandle2SpinGroups self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"SpinGroupClear", self, extract::spinGroup);
}

// Size
size_t
SpinGroupsSpinGroupSize(ConstHandle2ConstSpinGroups self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"SpinGroupSize", self, extract::spinGroup);
}

// Add
void
SpinGroupsSpinGroupAdd(ConstHandle2SpinGroups self, ConstHandle2ConstSpinGroup spinGroup)
{
   detail::addToContainer<CPP,CPPSpinGroup>
      (CLASSNAME, CLASSNAME+"SpinGroupAdd", self, extract::spinGroup, spinGroup);
}

// Get, by index \in [0,size), const
Handle2ConstSpinGroup
SpinGroupsSpinGroupGetConst(ConstHandle2ConstSpinGroups self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstSpinGroup>
      (CLASSNAME, CLASSNAME+"SpinGroupGetConst", self, extract::spinGroup, index_);
}

// Get, by index \in [0,size)
Handle2SpinGroup
SpinGroupsSpinGroupGet(ConstHandle2SpinGroups self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2SpinGroup>
      (CLASSNAME, CLASSNAME+"SpinGroupGet", self, extract::spinGroup, index_);
}

// Set, by index \in [0,size)
void
SpinGroupsSpinGroupSet(
   ConstHandle2SpinGroups self,
   const size_t index_,
   ConstHandle2ConstSpinGroup spinGroup
) {
   detail::setByIndex<CPP,CPPSpinGroup>
      (CLASSNAME, CLASSNAME+"SpinGroupSet", self, extract::spinGroup, index_, spinGroup);
}

// ------------------------
// Re: metadatum label
// ------------------------

// Has, by label
int
SpinGroupsSpinGroupHasByLabel(
   ConstHandle2ConstSpinGroups self,
   const char *const label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"SpinGroupHasByLabel",
       self, extract::spinGroup, meta::label, label);
}

// Get, by label, const
Handle2ConstSpinGroup
SpinGroupsSpinGroupGetByLabelConst(
   ConstHandle2ConstSpinGroups self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2ConstSpinGroup>
      (CLASSNAME, CLASSNAME+"SpinGroupGetByLabelConst",
       self, extract::spinGroup, meta::label, label);
}

// Get, by label
Handle2SpinGroup
SpinGroupsSpinGroupGetByLabel(
   ConstHandle2SpinGroups self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2SpinGroup>
      (CLASSNAME, CLASSNAME+"SpinGroupGetByLabel",
       self, extract::spinGroup, meta::label, label);
}

// Set, by label
void
SpinGroupsSpinGroupSetByLabel(
   ConstHandle2SpinGroups self,
   const char *const label,
   ConstHandle2ConstSpinGroup spinGroup
) {
   detail::setByMetadatum<CPP,CPPSpinGroup>
      (CLASSNAME, CLASSNAME+"SpinGroupSetByLabel",
       self, extract::spinGroup, meta::label, label, spinGroup);
}

// ------------------------
// Re: metadatum spin
// ------------------------

// Has, by spin
int
SpinGroupsSpinGroupHasBySpin(
   ConstHandle2ConstSpinGroups self,
   const int spin
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"SpinGroupHasBySpin",
       self, extract::spinGroup, meta::spin, spin);
}

// Get, by spin, const
Handle2ConstSpinGroup
SpinGroupsSpinGroupGetBySpinConst(
   ConstHandle2ConstSpinGroups self,
   const int spin
) {
   return detail::getByMetadatum<CPP,Handle2ConstSpinGroup>
      (CLASSNAME, CLASSNAME+"SpinGroupGetBySpinConst",
       self, extract::spinGroup, meta::spin, spin);
}

// Get, by spin
Handle2SpinGroup
SpinGroupsSpinGroupGetBySpin(
   ConstHandle2SpinGroups self,
   const int spin
) {
   return detail::getByMetadatum<CPP,Handle2SpinGroup>
      (CLASSNAME, CLASSNAME+"SpinGroupGetBySpin",
       self, extract::spinGroup, meta::spin, spin);
}

// Set, by spin
void
SpinGroupsSpinGroupSetBySpin(
   ConstHandle2SpinGroups self,
   const int spin,
   ConstHandle2ConstSpinGroup spinGroup
) {
   detail::setByMetadatum<CPP,CPPSpinGroup>
      (CLASSNAME, CLASSNAME+"SpinGroupSetBySpin",
       self, extract::spinGroup, meta::spin, spin, spinGroup);
}

// ------------------------
// Re: metadatum parity
// ------------------------

// Has, by parity
int
SpinGroupsSpinGroupHasByParity(
   ConstHandle2ConstSpinGroups self,
   const int parity
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"SpinGroupHasByParity",
       self, extract::spinGroup, meta::parity, parity);
}

// Get, by parity, const
Handle2ConstSpinGroup
SpinGroupsSpinGroupGetByParityConst(
   ConstHandle2ConstSpinGroups self,
   const int parity
) {
   return detail::getByMetadatum<CPP,Handle2ConstSpinGroup>
      (CLASSNAME, CLASSNAME+"SpinGroupGetByParityConst",
       self, extract::spinGroup, meta::parity, parity);
}

// Get, by parity
Handle2SpinGroup
SpinGroupsSpinGroupGetByParity(
   ConstHandle2SpinGroups self,
   const int parity
) {
   return detail::getByMetadatum<CPP,Handle2SpinGroup>
      (CLASSNAME, CLASSNAME+"SpinGroupGetByParity",
       self, extract::spinGroup, meta::parity, parity);
}

// Set, by parity
void
SpinGroupsSpinGroupSetByParity(
   ConstHandle2SpinGroups self,
   const int parity,
   ConstHandle2ConstSpinGroup spinGroup
) {
   detail::setByMetadatum<CPP,CPPSpinGroup>
      (CLASSNAME, CLASSNAME+"SpinGroupSetByParity",
       self, extract::spinGroup, meta::parity, parity, spinGroup);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/SpinGroups/src/custom.cpp"
