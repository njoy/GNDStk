
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/Ls.hpp"
#include "Ls.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = LsClass;
using CPP = multigroup::Ls;

static const std::string CLASSNAME = "Ls";

namespace extract {
   static auto L = [](auto &obj) { return &obj.L; };
}

using CPPL = general::L;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstLs
LsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Ls
LsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstLs
LsCreateConst(
   ConstHandle2L *const L, const size_t LSize
) {
   ConstHandle2Ls handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPL>{}
   );
   for (size_t LN = 0; LN < LSize; ++LN)
      LsLAdd(handle, L[LN]);
   return handle;
}

// Create, general
Handle2Ls
LsCreate(
   ConstHandle2L *const L, const size_t LSize
) {
   ConstHandle2Ls handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPL>{}
   );
   for (size_t LN = 0; LN < LSize; ++LN)
      LsLAdd(handle, L[LN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
LsAssign(ConstHandle2Ls self, ConstHandle2ConstLs from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
LsDelete(ConstHandle2ConstLs self)
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
LsRead(ConstHandle2Ls self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
LsWrite(ConstHandle2ConstLs self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
LsPrint(ConstHandle2ConstLs self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
LsPrintXML(ConstHandle2ConstLs self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
LsPrintJSON(ConstHandle2ConstLs self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: L
// -----------------------------------------------------------------------------

// Has
int
LsLHas(ConstHandle2ConstLs self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LHas", self, extract::L);
}

// Clear
void
LsLClear(ConstHandle2Ls self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"LClear", self, extract::L);
}

// Size
size_t
LsLSize(ConstHandle2ConstLs self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"LSize", self, extract::L);
}

// Add
void
LsLAdd(ConstHandle2Ls self, ConstHandle2ConstL L)
{
   detail::addToContainer<CPP,CPPL>
      (CLASSNAME, CLASSNAME+"LAdd", self, extract::L, L);
}

// Get, by index \in [0,size), const
Handle2ConstL
LsLGetConst(ConstHandle2ConstLs self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstL>
      (CLASSNAME, CLASSNAME+"LGetConst", self, extract::L, index_);
}

// Get, by index \in [0,size)
Handle2L
LsLGet(ConstHandle2Ls self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2L>
      (CLASSNAME, CLASSNAME+"LGet", self, extract::L, index_);
}

// Set, by index \in [0,size)
void
LsLSet(
   ConstHandle2Ls self,
   const size_t index_,
   ConstHandle2ConstL L
) {
   detail::setByIndex<CPP,CPPL>
      (CLASSNAME, CLASSNAME+"LSet", self, extract::L, index_, L);
}

// Has, by label
int
LsLHasByLabel(
   ConstHandle2ConstLs self,
   const char *const label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"LHasByLabel",
       self, extract::L, meta::label, label);
}

// Get, by label, const
Handle2ConstL
LsLGetByLabelConst(
   ConstHandle2ConstLs self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2ConstL>
      (CLASSNAME, CLASSNAME+"LGetByLabelConst",
       self, extract::L, meta::label, label);
}

// Get, by label
Handle2L
LsLGetByLabel(
   ConstHandle2Ls self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2L>
      (CLASSNAME, CLASSNAME+"LGetByLabel",
       self, extract::L, meta::label, label);
}

// Set, by label
void
LsLSetByLabel(
   ConstHandle2Ls self,
   const char *const label,
   ConstHandle2ConstL L
) {
   detail::setByMetadatum<CPP,CPPL>
      (CLASSNAME, CLASSNAME+"LSetByLabel",
       self, extract::L, meta::label, label, L);
}

// Has, by value
int
LsLHasByValue(
   ConstHandle2ConstLs self,
   const int value
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"LHasByValue",
       self, extract::L, meta::value, value);
}

// Get, by value, const
Handle2ConstL
LsLGetByValueConst(
   ConstHandle2ConstLs self,
   const int value
) {
   return detail::getByMetadatum<CPP,Handle2ConstL>
      (CLASSNAME, CLASSNAME+"LGetByValueConst",
       self, extract::L, meta::value, value);
}

// Get, by value
Handle2L
LsLGetByValue(
   ConstHandle2Ls self,
   const int value
) {
   return detail::getByMetadatum<CPP,Handle2L>
      (CLASSNAME, CLASSNAME+"LGetByValue",
       self, extract::L, meta::value, value);
}

// Set, by value
void
LsLSetByValue(
   ConstHandle2Ls self,
   const int value,
   ConstHandle2ConstL L
) {
   detail::setByMetadatum<CPP,CPPL>
      (CLASSNAME, CLASSNAME+"LSetByValue",
       self, extract::L, meta::value, value, L);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Ls/src/custom.cpp"
