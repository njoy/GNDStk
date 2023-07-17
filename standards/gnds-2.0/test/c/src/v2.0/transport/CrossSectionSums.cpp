
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2.0/transport/CrossSectionSums.hpp"
#include "CrossSectionSums.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = CrossSectionSumsClass;
using CPP = multigroup::CrossSectionSums;

static const std::string CLASSNAME = "CrossSectionSums";

namespace extract {
   static auto crossSectionSum = [](auto &obj) { return &obj.crossSectionSum; };
}

using CPPCrossSectionSum = transport::CrossSectionSum;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstCrossSectionSums
CrossSectionSumsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2CrossSectionSums
CrossSectionSumsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstCrossSectionSums
CrossSectionSumsCreateConst(
   ConstHandle2CrossSectionSum *const crossSectionSum, const size_t crossSectionSumSize
) {
   ConstHandle2CrossSectionSums handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPCrossSectionSum>{}
   );
   for (size_t CrossSectionSumN = 0; CrossSectionSumN < crossSectionSumSize; ++CrossSectionSumN)
      CrossSectionSumsCrossSectionSumAdd(handle, crossSectionSum[CrossSectionSumN]);
   return handle;
}

// Create, general
Handle2CrossSectionSums
CrossSectionSumsCreate(
   ConstHandle2CrossSectionSum *const crossSectionSum, const size_t crossSectionSumSize
) {
   ConstHandle2CrossSectionSums handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPCrossSectionSum>{}
   );
   for (size_t CrossSectionSumN = 0; CrossSectionSumN < crossSectionSumSize; ++CrossSectionSumN)
      CrossSectionSumsCrossSectionSumAdd(handle, crossSectionSum[CrossSectionSumN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
CrossSectionSumsAssign(ConstHandle2CrossSectionSums self, ConstHandle2ConstCrossSectionSums from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
CrossSectionSumsDelete(ConstHandle2ConstCrossSectionSums self)
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
CrossSectionSumsRead(ConstHandle2CrossSectionSums self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
CrossSectionSumsWrite(ConstHandle2ConstCrossSectionSums self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
CrossSectionSumsPrint(ConstHandle2ConstCrossSectionSums self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
CrossSectionSumsPrintXML(ConstHandle2ConstCrossSectionSums self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
CrossSectionSumsPrintJSON(ConstHandle2ConstCrossSectionSums self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: crossSectionSum
// -----------------------------------------------------------------------------

// Has
int
CrossSectionSumsCrossSectionSumHas(ConstHandle2ConstCrossSectionSums self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CrossSectionSumHas", self, extract::crossSectionSum);
}

// Clear
void
CrossSectionSumsCrossSectionSumClear(ConstHandle2CrossSectionSums self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"CrossSectionSumClear", self, extract::crossSectionSum);
}

// Size
size_t
CrossSectionSumsCrossSectionSumSize(ConstHandle2ConstCrossSectionSums self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"CrossSectionSumSize", self, extract::crossSectionSum);
}

// Add
void
CrossSectionSumsCrossSectionSumAdd(ConstHandle2CrossSectionSums self, ConstHandle2ConstCrossSectionSum crossSectionSum)
{
   detail::addToContainer<CPP,CPPCrossSectionSum>
      (CLASSNAME, CLASSNAME+"CrossSectionSumAdd", self, extract::crossSectionSum, crossSectionSum);
}

// Get, by index \in [0,size), const
Handle2ConstCrossSectionSum
CrossSectionSumsCrossSectionSumGetConst(ConstHandle2ConstCrossSectionSums self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstCrossSectionSum>
      (CLASSNAME, CLASSNAME+"CrossSectionSumGetConst", self, extract::crossSectionSum, index_);
}

// Get, by index \in [0,size), non-const
Handle2CrossSectionSum
CrossSectionSumsCrossSectionSumGet(ConstHandle2CrossSectionSums self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2CrossSectionSum>
      (CLASSNAME, CLASSNAME+"CrossSectionSumGet", self, extract::crossSectionSum, index_);
}

// Set, by index \in [0,size)
void
CrossSectionSumsCrossSectionSumSet(
   ConstHandle2CrossSectionSums self,
   const size_t index_,
   ConstHandle2ConstCrossSectionSum crossSectionSum
) {
   detail::setByIndex<CPP,CPPCrossSectionSum>
      (CLASSNAME, CLASSNAME+"CrossSectionSumSet", self, extract::crossSectionSum, index_, crossSectionSum);
}

// Has, by ENDF_MT
int
CrossSectionSumsCrossSectionSumHasByENDFMT(
   ConstHandle2ConstCrossSectionSums self,
   const Integer32 ENDF_MT
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"CrossSectionSumHasByENDFMT",
       self, extract::crossSectionSum, meta::ENDF_MT, ENDF_MT);
}

// Get, by ENDF_MT, const
Handle2ConstCrossSectionSum
CrossSectionSumsCrossSectionSumGetByENDFMTConst(
   ConstHandle2ConstCrossSectionSums self,
   const Integer32 ENDF_MT
) {
   return detail::getByMetadatum<CPP,Handle2ConstCrossSectionSum>
      (CLASSNAME, CLASSNAME+"CrossSectionSumGetByENDFMTConst",
       self, extract::crossSectionSum, meta::ENDF_MT, ENDF_MT);
}

// Get, by ENDF_MT, non-const
Handle2CrossSectionSum
CrossSectionSumsCrossSectionSumGetByENDFMT(
   ConstHandle2CrossSectionSums self,
   const Integer32 ENDF_MT
) {
   return detail::getByMetadatum<CPP,Handle2CrossSectionSum>
      (CLASSNAME, CLASSNAME+"CrossSectionSumGetByENDFMT",
       self, extract::crossSectionSum, meta::ENDF_MT, ENDF_MT);
}

// Set, by ENDF_MT
void
CrossSectionSumsCrossSectionSumSetByENDFMT(
   ConstHandle2CrossSectionSums self,
   const Integer32 ENDF_MT,
   ConstHandle2ConstCrossSectionSum crossSectionSum
) {
   detail::setByMetadatum<CPP,CPPCrossSectionSum>
      (CLASSNAME, CLASSNAME+"CrossSectionSumSetByENDFMT",
       self, extract::crossSectionSum, meta::ENDF_MT, ENDF_MT, crossSectionSum);
}

// Has, by label
int
CrossSectionSumsCrossSectionSumHasByLabel(
   ConstHandle2ConstCrossSectionSums self,
   const XMLName label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"CrossSectionSumHasByLabel",
       self, extract::crossSectionSum, meta::label, label);
}

// Get, by label, const
Handle2ConstCrossSectionSum
CrossSectionSumsCrossSectionSumGetByLabelConst(
   ConstHandle2ConstCrossSectionSums self,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2ConstCrossSectionSum>
      (CLASSNAME, CLASSNAME+"CrossSectionSumGetByLabelConst",
       self, extract::crossSectionSum, meta::label, label);
}

// Get, by label, non-const
Handle2CrossSectionSum
CrossSectionSumsCrossSectionSumGetByLabel(
   ConstHandle2CrossSectionSums self,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2CrossSectionSum>
      (CLASSNAME, CLASSNAME+"CrossSectionSumGetByLabel",
       self, extract::crossSectionSum, meta::label, label);
}

// Set, by label
void
CrossSectionSumsCrossSectionSumSetByLabel(
   ConstHandle2CrossSectionSums self,
   const XMLName label,
   ConstHandle2ConstCrossSectionSum crossSectionSum
) {
   detail::setByMetadatum<CPP,CPPCrossSectionSum>
      (CLASSNAME, CLASSNAME+"CrossSectionSumSetByLabel",
       self, extract::crossSectionSum, meta::label, label, crossSectionSum);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/transport/CrossSectionSums/src/custom.cpp"
