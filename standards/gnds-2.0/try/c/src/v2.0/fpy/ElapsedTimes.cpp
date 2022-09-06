
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/fpy/ElapsedTimes.hpp"
#include "ElapsedTimes.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = ElapsedTimesClass;
using CPP = multigroup::ElapsedTimes;

static const std::string CLASSNAME = "ElapsedTimes";

namespace extract {
   static auto elapsedTime = [](auto &obj) { return &obj.elapsedTime; };
}

using CPPElapsedTime = fpy::ElapsedTime;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstElapsedTimes
ElapsedTimesDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2ElapsedTimes
ElapsedTimesDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstElapsedTimes
ElapsedTimesCreateConst(
   ConstHandle2ElapsedTime *const elapsedTime, const size_t elapsedTimeSize
) {
   ConstHandle2ElapsedTimes handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPElapsedTime>{}
   );
   for (size_t ElapsedTimeN = 0; ElapsedTimeN < elapsedTimeSize; ++ElapsedTimeN)
      ElapsedTimesElapsedTimeAdd(handle, elapsedTime[ElapsedTimeN]);
   return handle;
}

// Create, general
Handle2ElapsedTimes
ElapsedTimesCreate(
   ConstHandle2ElapsedTime *const elapsedTime, const size_t elapsedTimeSize
) {
   ConstHandle2ElapsedTimes handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPElapsedTime>{}
   );
   for (size_t ElapsedTimeN = 0; ElapsedTimeN < elapsedTimeSize; ++ElapsedTimeN)
      ElapsedTimesElapsedTimeAdd(handle, elapsedTime[ElapsedTimeN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ElapsedTimesAssign(ConstHandle2ElapsedTimes This, ConstHandle2ConstElapsedTimes from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ElapsedTimesDelete(ConstHandle2ConstElapsedTimes This)
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
ElapsedTimesRead(ConstHandle2ElapsedTimes This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ElapsedTimesWrite(ConstHandle2ConstElapsedTimes This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
ElapsedTimesPrint(ConstHandle2ConstElapsedTimes This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
ElapsedTimesPrintXML(ConstHandle2ConstElapsedTimes This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
ElapsedTimesPrintJSON(ConstHandle2ConstElapsedTimes This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: elapsedTime
// -----------------------------------------------------------------------------

// Has
int
ElapsedTimesElapsedTimeHas(ConstHandle2ConstElapsedTimes This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ElapsedTimeHas", This, extract::elapsedTime);
}

// Clear
void
ElapsedTimesElapsedTimeClear(ConstHandle2ElapsedTimes This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"ElapsedTimeClear", This, extract::elapsedTime);
}

// Size
size_t
ElapsedTimesElapsedTimeSize(ConstHandle2ConstElapsedTimes This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"ElapsedTimeSize", This, extract::elapsedTime);
}

// Add
void
ElapsedTimesElapsedTimeAdd(ConstHandle2ElapsedTimes This, ConstHandle2ConstElapsedTime elapsedTime)
{
   detail::addToContainer<CPP,CPPElapsedTime>
      (CLASSNAME, CLASSNAME+"ElapsedTimeAdd", This, extract::elapsedTime, elapsedTime);
}

// Get, by index \in [0,size), const
Handle2ConstElapsedTime
ElapsedTimesElapsedTimeGetConst(ConstHandle2ConstElapsedTimes This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstElapsedTime>
      (CLASSNAME, CLASSNAME+"ElapsedTimeGetConst", This, extract::elapsedTime, index_);
}

// Get, by index \in [0,size), non-const
Handle2ElapsedTime
ElapsedTimesElapsedTimeGet(ConstHandle2ElapsedTimes This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ElapsedTime>
      (CLASSNAME, CLASSNAME+"ElapsedTimeGet", This, extract::elapsedTime, index_);
}

// Set, by index \in [0,size)
void
ElapsedTimesElapsedTimeSet(
   ConstHandle2ElapsedTimes This,
   const size_t index_,
   ConstHandle2ConstElapsedTime elapsedTime
) {
   detail::setByIndex<CPP,CPPElapsedTime>
      (CLASSNAME, CLASSNAME+"ElapsedTimeSet", This, extract::elapsedTime, index_, elapsedTime);
}

// Has, by label
int
ElapsedTimesElapsedTimeHasByLabel(
   ConstHandle2ConstElapsedTimes This,
   const XMLName label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ElapsedTimeHasByLabel",
       This, extract::elapsedTime, meta::label, label);
}

// Get, by label, const
Handle2ConstElapsedTime
ElapsedTimesElapsedTimeGetByLabelConst(
   ConstHandle2ConstElapsedTimes This,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2ConstElapsedTime>
      (CLASSNAME, CLASSNAME+"ElapsedTimeGetByLabelConst",
       This, extract::elapsedTime, meta::label, label);
}

// Get, by label, non-const
Handle2ElapsedTime
ElapsedTimesElapsedTimeGetByLabel(
   ConstHandle2ElapsedTimes This,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2ElapsedTime>
      (CLASSNAME, CLASSNAME+"ElapsedTimeGetByLabel",
       This, extract::elapsedTime, meta::label, label);
}

// Set, by label
void
ElapsedTimesElapsedTimeSetByLabel(
   ConstHandle2ElapsedTimes This,
   const XMLName label,
   ConstHandle2ConstElapsedTime elapsedTime
) {
   detail::setByMetadatum<CPP,CPPElapsedTime>
      (CLASSNAME, CLASSNAME+"ElapsedTimeSetByLabel",
       This, extract::elapsedTime, meta::label, label, elapsedTime);
}