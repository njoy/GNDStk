
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/Sum.hpp"
#include "Sum.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = SumClass;
using CPP = multigroup::Sum;

static const std::string CLASSNAME = "Sum";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto domainMin = [](auto &obj) { return &obj.domainMin; };
   static auto domainMax = [](auto &obj) { return &obj.domainMax; };
   static auto domainUnit = [](auto &obj) { return &obj.domainUnit; };
   static auto summand = [](auto &obj) { return &obj.summand; };
}

using CPPSummand = general::Summand;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstSum
SumDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Sum
SumDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstSum
SumCreateConst(
   const char *const label,
   const double domainMin,
   const double domainMax,
   const char *const domainUnit,
   ConstHandle2Summand *const summand, const size_t summandSize
) {
   ConstHandle2Sum handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      domainMin,
      domainMax,
      domainUnit,
      std::vector<CPPSummand>{}
   );
   for (size_t SummandN = 0; SummandN < summandSize; ++SummandN)
      SumSummandAdd(handle, summand[SummandN]);
   return handle;
}

// Create, general
Handle2Sum
SumCreate(
   const char *const label,
   const double domainMin,
   const double domainMax,
   const char *const domainUnit,
   ConstHandle2Summand *const summand, const size_t summandSize
) {
   ConstHandle2Sum handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      domainMin,
      domainMax,
      domainUnit,
      std::vector<CPPSummand>{}
   );
   for (size_t SummandN = 0; SummandN < summandSize; ++SummandN)
      SumSummandAdd(handle, summand[SummandN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
SumAssign(ConstHandle2Sum This, ConstHandle2ConstSum from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
SumDelete(ConstHandle2ConstSum This)
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
SumRead(ConstHandle2Sum This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
SumWrite(ConstHandle2ConstSum This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
SumPrint(ConstHandle2ConstSum This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
SumPrintXML(ConstHandle2ConstSum This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
SumPrintJSON(ConstHandle2ConstSum This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
SumLabelHas(ConstHandle2ConstSum This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
const char *
SumLabelGet(ConstHandle2ConstSum This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
SumLabelSet(ConstHandle2Sum This, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: domainMin
// -----------------------------------------------------------------------------

// Has
int
SumDomainMinHas(ConstHandle2ConstSum This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMinHas", This, extract::domainMin);
}

// Get
// Returns by value
double
SumDomainMinGet(ConstHandle2ConstSum This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMinGet", This, extract::domainMin);
}

// Set
void
SumDomainMinSet(ConstHandle2Sum This, const double domainMin)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMinSet", This, extract::domainMin, domainMin);
}


// -----------------------------------------------------------------------------
// Metadatum: domainMax
// -----------------------------------------------------------------------------

// Has
int
SumDomainMaxHas(ConstHandle2ConstSum This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMaxHas", This, extract::domainMax);
}

// Get
// Returns by value
double
SumDomainMaxGet(ConstHandle2ConstSum This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMaxGet", This, extract::domainMax);
}

// Set
void
SumDomainMaxSet(ConstHandle2Sum This, const double domainMax)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMaxSet", This, extract::domainMax, domainMax);
}


// -----------------------------------------------------------------------------
// Metadatum: domainUnit
// -----------------------------------------------------------------------------

// Has
int
SumDomainUnitHas(ConstHandle2ConstSum This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DomainUnitHas", This, extract::domainUnit);
}

// Get
// Returns by value
const char *
SumDomainUnitGet(ConstHandle2ConstSum This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DomainUnitGet", This, extract::domainUnit);
}

// Set
void
SumDomainUnitSet(ConstHandle2Sum This, const char *const domainUnit)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DomainUnitSet", This, extract::domainUnit, domainUnit);
}


// -----------------------------------------------------------------------------
// Child: summand
// -----------------------------------------------------------------------------

// Has
int
SumSummandHas(ConstHandle2ConstSum This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SummandHas", This, extract::summand);
}

// Clear
void
SumSummandClear(ConstHandle2Sum This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"SummandClear", This, extract::summand);
}

// Size
size_t
SumSummandSize(ConstHandle2ConstSum This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"SummandSize", This, extract::summand);
}

// Add
void
SumSummandAdd(ConstHandle2Sum This, ConstHandle2ConstSummand summand)
{
   detail::addToContainer<CPP,CPPSummand>
      (CLASSNAME, CLASSNAME+"SummandAdd", This, extract::summand, summand);
}

// Get, by index \in [0,size), const
Handle2ConstSummand
SumSummandGetConst(ConstHandle2ConstSum This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstSummand>
      (CLASSNAME, CLASSNAME+"SummandGetConst", This, extract::summand, index_);
}

// Get, by index \in [0,size), non-const
Handle2Summand
SumSummandGet(ConstHandle2Sum This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Summand>
      (CLASSNAME, CLASSNAME+"SummandGet", This, extract::summand, index_);
}

// Set, by index \in [0,size)
void
SumSummandSet(
   ConstHandle2Sum This,
   const size_t index_,
   ConstHandle2ConstSummand summand
) {
   detail::setByIndex<CPP,CPPSummand>
      (CLASSNAME, CLASSNAME+"SummandSet", This, extract::summand, index_, summand);
}

// Has, by ENDF_MFMT
int
SumSummandHasByENDFMFMT(
   ConstHandle2ConstSum This,
   const char *const ENDF_MFMT
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"SummandHasByENDFMFMT",
       This, extract::summand, meta::ENDF_MFMT, ENDF_MFMT);
}

// Get, by ENDF_MFMT, const
Handle2ConstSummand
SumSummandGetByENDFMFMTConst(
   ConstHandle2ConstSum This,
   const char *const ENDF_MFMT
) {
   return detail::getByMetadatum<CPP,Handle2ConstSummand>
      (CLASSNAME, CLASSNAME+"SummandGetByENDFMFMTConst",
       This, extract::summand, meta::ENDF_MFMT, ENDF_MFMT);
}

// Get, by ENDF_MFMT, non-const
Handle2Summand
SumSummandGetByENDFMFMT(
   ConstHandle2Sum This,
   const char *const ENDF_MFMT
) {
   return detail::getByMetadatum<CPP,Handle2Summand>
      (CLASSNAME, CLASSNAME+"SummandGetByENDFMFMT",
       This, extract::summand, meta::ENDF_MFMT, ENDF_MFMT);
}

// Set, by ENDF_MFMT
void
SumSummandSetByENDFMFMT(
   ConstHandle2Sum This,
   const char *const ENDF_MFMT,
   ConstHandle2ConstSummand summand
) {
   detail::setByMetadatum<CPP,CPPSummand>
      (CLASSNAME, CLASSNAME+"SummandSetByENDFMFMT",
       This, extract::summand, meta::ENDF_MFMT, ENDF_MFMT, summand);
}

// Has, by coefficient
int
SumSummandHasByCoefficient(
   ConstHandle2ConstSum This,
   const char *const coefficient
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"SummandHasByCoefficient",
       This, extract::summand, meta::coefficient, coefficient);
}

// Get, by coefficient, const
Handle2ConstSummand
SumSummandGetByCoefficientConst(
   ConstHandle2ConstSum This,
   const char *const coefficient
) {
   return detail::getByMetadatum<CPP,Handle2ConstSummand>
      (CLASSNAME, CLASSNAME+"SummandGetByCoefficientConst",
       This, extract::summand, meta::coefficient, coefficient);
}

// Get, by coefficient, non-const
Handle2Summand
SumSummandGetByCoefficient(
   ConstHandle2Sum This,
   const char *const coefficient
) {
   return detail::getByMetadatum<CPP,Handle2Summand>
      (CLASSNAME, CLASSNAME+"SummandGetByCoefficient",
       This, extract::summand, meta::coefficient, coefficient);
}

// Set, by coefficient
void
SumSummandSetByCoefficient(
   ConstHandle2Sum This,
   const char *const coefficient,
   ConstHandle2ConstSummand summand
) {
   detail::setByMetadatum<CPP,CPPSummand>
      (CLASSNAME, CLASSNAME+"SummandSetByCoefficient",
       This, extract::summand, meta::coefficient, coefficient, summand);
}

// Has, by href
int
SumSummandHasByHref(
   ConstHandle2ConstSum This,
   const char *const href
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"SummandHasByHref",
       This, extract::summand, meta::href, href);
}

// Get, by href, const
Handle2ConstSummand
SumSummandGetByHrefConst(
   ConstHandle2ConstSum This,
   const char *const href
) {
   return detail::getByMetadatum<CPP,Handle2ConstSummand>
      (CLASSNAME, CLASSNAME+"SummandGetByHrefConst",
       This, extract::summand, meta::href, href);
}

// Get, by href, non-const
Handle2Summand
SumSummandGetByHref(
   ConstHandle2Sum This,
   const char *const href
) {
   return detail::getByMetadatum<CPP,Handle2Summand>
      (CLASSNAME, CLASSNAME+"SummandGetByHref",
       This, extract::summand, meta::href, href);
}

// Set, by href
void
SumSummandSetByHref(
   ConstHandle2Sum This,
   const char *const href,
   ConstHandle2ConstSummand summand
) {
   detail::setByMetadatum<CPP,CPPSummand>
      (CLASSNAME, CLASSNAME+"SummandSetByHref",
       This, extract::summand, meta::href, href, summand);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Sum/src/custom.cpp"
