
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/transport/MultiplicitySums.hpp"
#include "MultiplicitySums.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = MultiplicitySumsClass;
using CPP = multigroup::MultiplicitySums;

static const std::string CLASSNAME = "MultiplicitySums";

namespace extract {
   static auto multiplicitySum = [](auto &obj) { return &obj.multiplicitySum; };
}

using CPPMultiplicitySum = transport::MultiplicitySum;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstMultiplicitySums
MultiplicitySumsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2MultiplicitySums
MultiplicitySumsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstMultiplicitySums
MultiplicitySumsCreateConst(
   ConstHandle2MultiplicitySum *const multiplicitySum, const size_t multiplicitySumSize
) {
   ConstHandle2MultiplicitySums handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPMultiplicitySum>{}
   );
   for (size_t MultiplicitySumN = 0; MultiplicitySumN < multiplicitySumSize; ++MultiplicitySumN)
      MultiplicitySumsMultiplicitySumAdd(handle, multiplicitySum[MultiplicitySumN]);
   return handle;
}

// Create, general
Handle2MultiplicitySums
MultiplicitySumsCreate(
   ConstHandle2MultiplicitySum *const multiplicitySum, const size_t multiplicitySumSize
) {
   ConstHandle2MultiplicitySums handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPMultiplicitySum>{}
   );
   for (size_t MultiplicitySumN = 0; MultiplicitySumN < multiplicitySumSize; ++MultiplicitySumN)
      MultiplicitySumsMultiplicitySumAdd(handle, multiplicitySum[MultiplicitySumN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
MultiplicitySumsAssign(ConstHandle2MultiplicitySums This, ConstHandle2ConstMultiplicitySums from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
MultiplicitySumsDelete(ConstHandle2ConstMultiplicitySums This)
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
MultiplicitySumsRead(ConstHandle2MultiplicitySums This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
MultiplicitySumsWrite(ConstHandle2ConstMultiplicitySums This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
MultiplicitySumsPrint(ConstHandle2ConstMultiplicitySums This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
MultiplicitySumsPrintXML(ConstHandle2ConstMultiplicitySums This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
MultiplicitySumsPrintJSON(ConstHandle2ConstMultiplicitySums This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: multiplicitySum
// -----------------------------------------------------------------------------

// Has
int
MultiplicitySumsMultiplicitySumHas(ConstHandle2ConstMultiplicitySums This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"MultiplicitySumHas", This, extract::multiplicitySum);
}

// Clear
void
MultiplicitySumsMultiplicitySumClear(ConstHandle2MultiplicitySums This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"MultiplicitySumClear", This, extract::multiplicitySum);
}

// Size
size_t
MultiplicitySumsMultiplicitySumSize(ConstHandle2ConstMultiplicitySums This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"MultiplicitySumSize", This, extract::multiplicitySum);
}

// Add
void
MultiplicitySumsMultiplicitySumAdd(ConstHandle2MultiplicitySums This, ConstHandle2ConstMultiplicitySum multiplicitySum)
{
   detail::addToContainer<CPP,CPPMultiplicitySum>
      (CLASSNAME, CLASSNAME+"MultiplicitySumAdd", This, extract::multiplicitySum, multiplicitySum);
}

// Get, by index \in [0,size), const
Handle2ConstMultiplicitySum
MultiplicitySumsMultiplicitySumGetConst(ConstHandle2ConstMultiplicitySums This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstMultiplicitySum>
      (CLASSNAME, CLASSNAME+"MultiplicitySumGetConst", This, extract::multiplicitySum, index_);
}

// Get, by index \in [0,size), non-const
Handle2MultiplicitySum
MultiplicitySumsMultiplicitySumGet(ConstHandle2MultiplicitySums This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2MultiplicitySum>
      (CLASSNAME, CLASSNAME+"MultiplicitySumGet", This, extract::multiplicitySum, index_);
}

// Set, by index \in [0,size)
void
MultiplicitySumsMultiplicitySumSet(
   ConstHandle2MultiplicitySums This,
   const size_t index_,
   ConstHandle2ConstMultiplicitySum multiplicitySum
) {
   detail::setByIndex<CPP,CPPMultiplicitySum>
      (CLASSNAME, CLASSNAME+"MultiplicitySumSet", This, extract::multiplicitySum, index_, multiplicitySum);
}

// Has, by ENDF_MT
int
MultiplicitySumsMultiplicitySumHasByENDFMT(
   ConstHandle2ConstMultiplicitySums This,
   const Integer32 ENDF_MT
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"MultiplicitySumHasByENDFMT",
       This, extract::multiplicitySum, meta::ENDF_MT, ENDF_MT);
}

// Get, by ENDF_MT, const
Handle2ConstMultiplicitySum
MultiplicitySumsMultiplicitySumGetByENDFMTConst(
   ConstHandle2ConstMultiplicitySums This,
   const Integer32 ENDF_MT
) {
   return detail::getByMetadatum<CPP,Handle2ConstMultiplicitySum>
      (CLASSNAME, CLASSNAME+"MultiplicitySumGetByENDFMTConst",
       This, extract::multiplicitySum, meta::ENDF_MT, ENDF_MT);
}

// Get, by ENDF_MT, non-const
Handle2MultiplicitySum
MultiplicitySumsMultiplicitySumGetByENDFMT(
   ConstHandle2MultiplicitySums This,
   const Integer32 ENDF_MT
) {
   return detail::getByMetadatum<CPP,Handle2MultiplicitySum>
      (CLASSNAME, CLASSNAME+"MultiplicitySumGetByENDFMT",
       This, extract::multiplicitySum, meta::ENDF_MT, ENDF_MT);
}

// Set, by ENDF_MT
void
MultiplicitySumsMultiplicitySumSetByENDFMT(
   ConstHandle2MultiplicitySums This,
   const Integer32 ENDF_MT,
   ConstHandle2ConstMultiplicitySum multiplicitySum
) {
   detail::setByMetadatum<CPP,CPPMultiplicitySum>
      (CLASSNAME, CLASSNAME+"MultiplicitySumSetByENDFMT",
       This, extract::multiplicitySum, meta::ENDF_MT, ENDF_MT, multiplicitySum);
}

// Has, by label
int
MultiplicitySumsMultiplicitySumHasByLabel(
   ConstHandle2ConstMultiplicitySums This,
   const XMLName label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"MultiplicitySumHasByLabel",
       This, extract::multiplicitySum, meta::label, label);
}

// Get, by label, const
Handle2ConstMultiplicitySum
MultiplicitySumsMultiplicitySumGetByLabelConst(
   ConstHandle2ConstMultiplicitySums This,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2ConstMultiplicitySum>
      (CLASSNAME, CLASSNAME+"MultiplicitySumGetByLabelConst",
       This, extract::multiplicitySum, meta::label, label);
}

// Get, by label, non-const
Handle2MultiplicitySum
MultiplicitySumsMultiplicitySumGetByLabel(
   ConstHandle2MultiplicitySums This,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2MultiplicitySum>
      (CLASSNAME, CLASSNAME+"MultiplicitySumGetByLabel",
       This, extract::multiplicitySum, meta::label, label);
}

// Set, by label
void
MultiplicitySumsMultiplicitySumSetByLabel(
   ConstHandle2MultiplicitySums This,
   const XMLName label,
   ConstHandle2ConstMultiplicitySum multiplicitySum
) {
   detail::setByMetadatum<CPP,CPPMultiplicitySum>
      (CLASSNAME, CLASSNAME+"MultiplicitySumSetByLabel",
       This, extract::multiplicitySum, meta::label, label, multiplicitySum);
}
