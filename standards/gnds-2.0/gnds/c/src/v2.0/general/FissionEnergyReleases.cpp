
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "gnds/v2.0/general/FissionEnergyReleases.hpp"
#include "FissionEnergyReleases.h"

using namespace njoy::GNDStk;
using namespace gnds::v2_0;

using C = FissionEnergyReleasesClass;
using CPP = multigroup::FissionEnergyReleases;

static const std::string CLASSNAME = "FissionEnergyReleases";

namespace extract {
   static auto fissionEnergyRelease = [](auto &obj) { return &obj.fissionEnergyRelease; };
}

using CPPFissionEnergyRelease = general::FissionEnergyRelease;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstFissionEnergyReleases
FissionEnergyReleasesDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2FissionEnergyReleases
FissionEnergyReleasesDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstFissionEnergyReleases
FissionEnergyReleasesCreateConst(
   ConstHandle2FissionEnergyRelease *const fissionEnergyRelease, const size_t fissionEnergyReleaseSize
) {
   ConstHandle2FissionEnergyReleases handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPFissionEnergyRelease>{}
   );
   for (size_t FissionEnergyReleaseN = 0; FissionEnergyReleaseN < fissionEnergyReleaseSize; ++FissionEnergyReleaseN)
      FissionEnergyReleasesFissionEnergyReleaseAdd(handle, fissionEnergyRelease[FissionEnergyReleaseN]);
   return handle;
}

// Create, general
Handle2FissionEnergyReleases
FissionEnergyReleasesCreate(
   ConstHandle2FissionEnergyRelease *const fissionEnergyRelease, const size_t fissionEnergyReleaseSize
) {
   ConstHandle2FissionEnergyReleases handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPFissionEnergyRelease>{}
   );
   for (size_t FissionEnergyReleaseN = 0; FissionEnergyReleaseN < fissionEnergyReleaseSize; ++FissionEnergyReleaseN)
      FissionEnergyReleasesFissionEnergyReleaseAdd(handle, fissionEnergyRelease[FissionEnergyReleaseN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
FissionEnergyReleasesAssign(ConstHandle2FissionEnergyReleases self, ConstHandle2ConstFissionEnergyReleases from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
FissionEnergyReleasesDelete(ConstHandle2ConstFissionEnergyReleases self)
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
FissionEnergyReleasesRead(ConstHandle2FissionEnergyReleases self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
FissionEnergyReleasesWrite(ConstHandle2ConstFissionEnergyReleases self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
FissionEnergyReleasesPrint(ConstHandle2ConstFissionEnergyReleases self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
FissionEnergyReleasesPrintXML(ConstHandle2ConstFissionEnergyReleases self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
FissionEnergyReleasesPrintJSON(ConstHandle2ConstFissionEnergyReleases self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: fissionEnergyRelease
// -----------------------------------------------------------------------------

// Has
int
FissionEnergyReleasesFissionEnergyReleaseHas(ConstHandle2ConstFissionEnergyReleases self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"FissionEnergyReleaseHas", self, extract::fissionEnergyRelease);
}

// Clear
void
FissionEnergyReleasesFissionEnergyReleaseClear(ConstHandle2FissionEnergyReleases self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"FissionEnergyReleaseClear", self, extract::fissionEnergyRelease);
}

// Size
size_t
FissionEnergyReleasesFissionEnergyReleaseSize(ConstHandle2ConstFissionEnergyReleases self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"FissionEnergyReleaseSize", self, extract::fissionEnergyRelease);
}

// Add
void
FissionEnergyReleasesFissionEnergyReleaseAdd(ConstHandle2FissionEnergyReleases self, ConstHandle2ConstFissionEnergyRelease fissionEnergyRelease)
{
   detail::addToContainer<CPP,CPPFissionEnergyRelease>
      (CLASSNAME, CLASSNAME+"FissionEnergyReleaseAdd", self, extract::fissionEnergyRelease, fissionEnergyRelease);
}

// Get, by index \in [0,size), const
Handle2ConstFissionEnergyRelease
FissionEnergyReleasesFissionEnergyReleaseGetConst(ConstHandle2ConstFissionEnergyReleases self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstFissionEnergyRelease>
      (CLASSNAME, CLASSNAME+"FissionEnergyReleaseGetConst", self, extract::fissionEnergyRelease, index_);
}

// Get, by index \in [0,size), non-const
Handle2FissionEnergyRelease
FissionEnergyReleasesFissionEnergyReleaseGet(ConstHandle2FissionEnergyReleases self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2FissionEnergyRelease>
      (CLASSNAME, CLASSNAME+"FissionEnergyReleaseGet", self, extract::fissionEnergyRelease, index_);
}

// Set, by index \in [0,size)
void
FissionEnergyReleasesFissionEnergyReleaseSet(
   ConstHandle2FissionEnergyReleases self,
   const size_t index_,
   ConstHandle2ConstFissionEnergyRelease fissionEnergyRelease
) {
   detail::setByIndex<CPP,CPPFissionEnergyRelease>
      (CLASSNAME, CLASSNAME+"FissionEnergyReleaseSet", self, extract::fissionEnergyRelease, index_, fissionEnergyRelease);
}

// Has, by label
int
FissionEnergyReleasesFissionEnergyReleaseHasByLabel(
   ConstHandle2ConstFissionEnergyReleases self,
   const char *const label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"FissionEnergyReleaseHasByLabel",
       self, extract::fissionEnergyRelease, meta::label, label);
}

// Get, by label, const
Handle2ConstFissionEnergyRelease
FissionEnergyReleasesFissionEnergyReleaseGetByLabelConst(
   ConstHandle2ConstFissionEnergyReleases self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2ConstFissionEnergyRelease>
      (CLASSNAME, CLASSNAME+"FissionEnergyReleaseGetByLabelConst",
       self, extract::fissionEnergyRelease, meta::label, label);
}

// Get, by label, non-const
Handle2FissionEnergyRelease
FissionEnergyReleasesFissionEnergyReleaseGetByLabel(
   ConstHandle2FissionEnergyReleases self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2FissionEnergyRelease>
      (CLASSNAME, CLASSNAME+"FissionEnergyReleaseGetByLabel",
       self, extract::fissionEnergyRelease, meta::label, label);
}

// Set, by label
void
FissionEnergyReleasesFissionEnergyReleaseSetByLabel(
   ConstHandle2FissionEnergyReleases self,
   const char *const label,
   ConstHandle2ConstFissionEnergyRelease fissionEnergyRelease
) {
   detail::setByMetadatum<CPP,CPPFissionEnergyRelease>
      (CLASSNAME, CLASSNAME+"FissionEnergyReleaseSetByLabel",
       self, extract::fissionEnergyRelease, meta::label, label, fissionEnergyRelease);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/FissionEnergyReleases/src/custom.cpp"
