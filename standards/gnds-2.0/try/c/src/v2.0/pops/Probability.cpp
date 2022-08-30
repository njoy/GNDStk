
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/pops/Probability.hpp"
#include "Probability.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = ProbabilityClass;
using CPP = multigroup::Probability;

static const std::string CLASSNAME = "Probability";

namespace extract {
   static auto Double = [](auto &obj) { return &obj.Double; };
}

using CPPDouble = containers::Double;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstProbability
ProbabilityDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Probability
ProbabilityDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstProbability
ProbabilityCreateConst(
   ConstHandle2Double *const Double, const size_t DoubleSize
) {
   ConstHandle2Probability handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPDouble>{}
   );
   for (size_t DoubleN = 0; DoubleN < DoubleSize; ++DoubleN)
      ProbabilityDoubleAdd(handle, Double[DoubleN]);
   return handle;
}

// Create, general
Handle2Probability
ProbabilityCreate(
   ConstHandle2Double *const Double, const size_t DoubleSize
) {
   ConstHandle2Probability handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPDouble>{}
   );
   for (size_t DoubleN = 0; DoubleN < DoubleSize; ++DoubleN)
      ProbabilityDoubleAdd(handle, Double[DoubleN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ProbabilityAssign(ConstHandle2Probability This, ConstHandle2ConstProbability from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ProbabilityDelete(ConstHandle2ConstProbability This)
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
ProbabilityRead(ConstHandle2Probability This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ProbabilityWrite(ConstHandle2ConstProbability This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
ProbabilityPrint(ConstHandle2ConstProbability This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
ProbabilityPrintXML(ConstHandle2ConstProbability This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
ProbabilityPrintJSON(ConstHandle2ConstProbability This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: Double
// -----------------------------------------------------------------------------

// Has
int
ProbabilityDoubleHas(ConstHandle2ConstProbability This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DoubleHas", This, extract::Double);
}

// Clear
void
ProbabilityDoubleClear(ConstHandle2Probability This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"DoubleClear", This, extract::Double);
}

// Size
size_t
ProbabilityDoubleSize(ConstHandle2ConstProbability This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"DoubleSize", This, extract::Double);
}

// Add
void
ProbabilityDoubleAdd(ConstHandle2Probability This, ConstHandle2ConstDouble Double)
{
   detail::addToContainer<CPP,CPPDouble>
      (CLASSNAME, CLASSNAME+"DoubleAdd", This, extract::Double, Double);
}

// Get, by index \in [0,size), const
Handle2ConstDouble
ProbabilityDoubleGetConst(ConstHandle2ConstProbability This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstDouble>
      (CLASSNAME, CLASSNAME+"DoubleGetConst", This, extract::Double, index_);
}

// Get, by index \in [0,size), non-const
Handle2Double
ProbabilityDoubleGet(ConstHandle2Probability This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Double>
      (CLASSNAME, CLASSNAME+"DoubleGet", This, extract::Double, index_);
}

// Set, by index \in [0,size)
void
ProbabilityDoubleSet(
   ConstHandle2Probability This,
   const size_t index_,
   ConstHandle2ConstDouble Double
) {
   detail::setByIndex<CPP,CPPDouble>
      (CLASSNAME, CLASSNAME+"DoubleSet", This, extract::Double, index_, Double);
}

// Has, by label
int
ProbabilityDoubleHasByLabel(
   ConstHandle2ConstProbability This,
   const XMLName label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"DoubleHasByLabel",
       This, extract::Double, meta::label, label);
}

// Get, by label, const
Handle2ConstDouble
ProbabilityDoubleGetByLabelConst(
   ConstHandle2ConstProbability This,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2ConstDouble>
      (CLASSNAME, CLASSNAME+"DoubleGetByLabelConst",
       This, extract::Double, meta::label, label);
}

// Get, by label, non-const
Handle2Double
ProbabilityDoubleGetByLabel(
   ConstHandle2Probability This,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2Double>
      (CLASSNAME, CLASSNAME+"DoubleGetByLabel",
       This, extract::Double, meta::label, label);
}

// Set, by label
void
ProbabilityDoubleSetByLabel(
   ConstHandle2Probability This,
   const XMLName label,
   ConstHandle2ConstDouble Double
) {
   detail::setByMetadatum<CPP,CPPDouble>
      (CLASSNAME, CLASSNAME+"DoubleSetByLabel",
       This, extract::Double, meta::label, label, Double);
}

// Has, by unit
int
ProbabilityDoubleHasByUnit(
   ConstHandle2ConstProbability This,
   const XMLName unit
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"DoubleHasByUnit",
       This, extract::Double, meta::unit, unit);
}

// Get, by unit, const
Handle2ConstDouble
ProbabilityDoubleGetByUnitConst(
   ConstHandle2ConstProbability This,
   const XMLName unit
) {
   return detail::getByMetadatum<CPP,Handle2ConstDouble>
      (CLASSNAME, CLASSNAME+"DoubleGetByUnitConst",
       This, extract::Double, meta::unit, unit);
}

// Get, by unit, non-const
Handle2Double
ProbabilityDoubleGetByUnit(
   ConstHandle2Probability This,
   const XMLName unit
) {
   return detail::getByMetadatum<CPP,Handle2Double>
      (CLASSNAME, CLASSNAME+"DoubleGetByUnit",
       This, extract::Double, meta::unit, unit);
}

// Set, by unit
void
ProbabilityDoubleSetByUnit(
   ConstHandle2Probability This,
   const XMLName unit,
   ConstHandle2ConstDouble Double
) {
   detail::setByMetadatum<CPP,CPPDouble>
      (CLASSNAME, CLASSNAME+"DoubleSetByUnit",
       This, extract::Double, meta::unit, unit, Double);
}

// Has, by value
int
ProbabilityDoubleHasByValue(
   ConstHandle2ConstProbability This,
   const Float64 value
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"DoubleHasByValue",
       This, extract::Double, meta::value, value);
}

// Get, by value, const
Handle2ConstDouble
ProbabilityDoubleGetByValueConst(
   ConstHandle2ConstProbability This,
   const Float64 value
) {
   return detail::getByMetadatum<CPP,Handle2ConstDouble>
      (CLASSNAME, CLASSNAME+"DoubleGetByValueConst",
       This, extract::Double, meta::value, value);
}

// Get, by value, non-const
Handle2Double
ProbabilityDoubleGetByValue(
   ConstHandle2Probability This,
   const Float64 value
) {
   return detail::getByMetadatum<CPP,Handle2Double>
      (CLASSNAME, CLASSNAME+"DoubleGetByValue",
       This, extract::Double, meta::value, value);
}

// Set, by value
void
ProbabilityDoubleSetByValue(
   ConstHandle2Probability This,
   const Float64 value,
   ConstHandle2ConstDouble Double
) {
   detail::setByMetadatum<CPP,CPPDouble>
      (CLASSNAME, CLASSNAME+"DoubleSetByValue",
       This, extract::Double, meta::value, value, Double);
}
