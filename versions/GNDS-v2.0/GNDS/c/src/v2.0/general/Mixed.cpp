
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/Mixed.hpp"
#include "Mixed.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = MixedClass;
using CPP = multigroup::Mixed;

static const std::string CLASSNAME = "Mixed";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto covarianceMatrix = [](auto &obj) { return &obj.covarianceMatrix; };
   static auto sum = [](auto &obj) { return &obj.sum; };
   static auto shortRangeSelfScalingVariance = [](auto &obj) { return &obj.shortRangeSelfScalingVariance; };
}

using CPPCovarianceMatrix = general::CovarianceMatrix;
using CPPSum = general::Sum;
using CPPShortRangeSelfScalingVariance = general::ShortRangeSelfScalingVariance;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstMixed
MixedDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Mixed
MixedDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstMixed
MixedCreateConst(
   const char *const label,
   ConstHandle2CovarianceMatrix *const covarianceMatrix, const size_t covarianceMatrixSize,
   ConstHandle2Sum *const sum, const size_t sumSize,
   ConstHandle2ConstShortRangeSelfScalingVariance shortRangeSelfScalingVariance
) {
   ConstHandle2Mixed handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      std::vector<CPPCovarianceMatrix>{},
      std::vector<CPPSum>{},
      detail::tocpp<CPPShortRangeSelfScalingVariance>(shortRangeSelfScalingVariance)
   );
   for (size_t CovarianceMatrixN = 0; CovarianceMatrixN < covarianceMatrixSize; ++CovarianceMatrixN)
      MixedCovarianceMatrixAdd(handle, covarianceMatrix[CovarianceMatrixN]);
   for (size_t SumN = 0; SumN < sumSize; ++SumN)
      MixedSumAdd(handle, sum[SumN]);
   return handle;
}

// Create, general
Handle2Mixed
MixedCreate(
   const char *const label,
   ConstHandle2CovarianceMatrix *const covarianceMatrix, const size_t covarianceMatrixSize,
   ConstHandle2Sum *const sum, const size_t sumSize,
   ConstHandle2ConstShortRangeSelfScalingVariance shortRangeSelfScalingVariance
) {
   ConstHandle2Mixed handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      std::vector<CPPCovarianceMatrix>{},
      std::vector<CPPSum>{},
      detail::tocpp<CPPShortRangeSelfScalingVariance>(shortRangeSelfScalingVariance)
   );
   for (size_t CovarianceMatrixN = 0; CovarianceMatrixN < covarianceMatrixSize; ++CovarianceMatrixN)
      MixedCovarianceMatrixAdd(handle, covarianceMatrix[CovarianceMatrixN]);
   for (size_t SumN = 0; SumN < sumSize; ++SumN)
      MixedSumAdd(handle, sum[SumN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
MixedAssign(ConstHandle2Mixed self, ConstHandle2ConstMixed from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
MixedDelete(ConstHandle2ConstMixed self)
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
MixedRead(ConstHandle2Mixed self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
MixedWrite(ConstHandle2ConstMixed self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
MixedPrint(ConstHandle2ConstMixed self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
MixedPrintXML(ConstHandle2ConstMixed self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
MixedPrintJSON(ConstHandle2ConstMixed self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
MixedLabelHas(ConstHandle2ConstMixed self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
const char *
MixedLabelGet(ConstHandle2ConstMixed self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
MixedLabelSet(ConstHandle2Mixed self, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Child: covarianceMatrix
// -----------------------------------------------------------------------------

// Has
int
MixedCovarianceMatrixHas(ConstHandle2ConstMixed self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CovarianceMatrixHas", self, extract::covarianceMatrix);
}

// Clear
void
MixedCovarianceMatrixClear(ConstHandle2Mixed self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"CovarianceMatrixClear", self, extract::covarianceMatrix);
}

// Size
size_t
MixedCovarianceMatrixSize(ConstHandle2ConstMixed self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"CovarianceMatrixSize", self, extract::covarianceMatrix);
}

// Add
void
MixedCovarianceMatrixAdd(ConstHandle2Mixed self, ConstHandle2ConstCovarianceMatrix covarianceMatrix)
{
   detail::addToContainer<CPP,CPPCovarianceMatrix>
      (CLASSNAME, CLASSNAME+"CovarianceMatrixAdd", self, extract::covarianceMatrix, covarianceMatrix);
}

// Get, by index \in [0,size), const
Handle2ConstCovarianceMatrix
MixedCovarianceMatrixGetConst(ConstHandle2ConstMixed self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstCovarianceMatrix>
      (CLASSNAME, CLASSNAME+"CovarianceMatrixGetConst", self, extract::covarianceMatrix, index_);
}

// Get, by index \in [0,size)
Handle2CovarianceMatrix
MixedCovarianceMatrixGet(ConstHandle2Mixed self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2CovarianceMatrix>
      (CLASSNAME, CLASSNAME+"CovarianceMatrixGet", self, extract::covarianceMatrix, index_);
}

// Set, by index \in [0,size)
void
MixedCovarianceMatrixSet(
   ConstHandle2Mixed self,
   const size_t index_,
   ConstHandle2ConstCovarianceMatrix covarianceMatrix
) {
   detail::setByIndex<CPP,CPPCovarianceMatrix>
      (CLASSNAME, CLASSNAME+"CovarianceMatrixSet", self, extract::covarianceMatrix, index_, covarianceMatrix);
}

// ------------------------
// Re: metadatum label
// ------------------------

// Has, by label
int
MixedCovarianceMatrixHasByLabel(
   ConstHandle2ConstMixed self,
   const char *const label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"CovarianceMatrixHasByLabel",
       self, extract::covarianceMatrix, meta::label, label);
}

// Get, by label, const
Handle2ConstCovarianceMatrix
MixedCovarianceMatrixGetByLabelConst(
   ConstHandle2ConstMixed self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2ConstCovarianceMatrix>
      (CLASSNAME, CLASSNAME+"CovarianceMatrixGetByLabelConst",
       self, extract::covarianceMatrix, meta::label, label);
}

// Get, by label
Handle2CovarianceMatrix
MixedCovarianceMatrixGetByLabel(
   ConstHandle2Mixed self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2CovarianceMatrix>
      (CLASSNAME, CLASSNAME+"CovarianceMatrixGetByLabel",
       self, extract::covarianceMatrix, meta::label, label);
}

// Set, by label
void
MixedCovarianceMatrixSetByLabel(
   ConstHandle2Mixed self,
   const char *const label,
   ConstHandle2ConstCovarianceMatrix covarianceMatrix
) {
   detail::setByMetadatum<CPP,CPPCovarianceMatrix>
      (CLASSNAME, CLASSNAME+"CovarianceMatrixSetByLabel",
       self, extract::covarianceMatrix, meta::label, label, covarianceMatrix);
}

// ------------------------
// Re: metadatum type
// ------------------------

// Has, by type
int
MixedCovarianceMatrixHasByType(
   ConstHandle2ConstMixed self,
   const char *const type
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"CovarianceMatrixHasByType",
       self, extract::covarianceMatrix, meta::type, type);
}

// Get, by type, const
Handle2ConstCovarianceMatrix
MixedCovarianceMatrixGetByTypeConst(
   ConstHandle2ConstMixed self,
   const char *const type
) {
   return detail::getByMetadatum<CPP,Handle2ConstCovarianceMatrix>
      (CLASSNAME, CLASSNAME+"CovarianceMatrixGetByTypeConst",
       self, extract::covarianceMatrix, meta::type, type);
}

// Get, by type
Handle2CovarianceMatrix
MixedCovarianceMatrixGetByType(
   ConstHandle2Mixed self,
   const char *const type
) {
   return detail::getByMetadatum<CPP,Handle2CovarianceMatrix>
      (CLASSNAME, CLASSNAME+"CovarianceMatrixGetByType",
       self, extract::covarianceMatrix, meta::type, type);
}

// Set, by type
void
MixedCovarianceMatrixSetByType(
   ConstHandle2Mixed self,
   const char *const type,
   ConstHandle2ConstCovarianceMatrix covarianceMatrix
) {
   detail::setByMetadatum<CPP,CPPCovarianceMatrix>
      (CLASSNAME, CLASSNAME+"CovarianceMatrixSetByType",
       self, extract::covarianceMatrix, meta::type, type, covarianceMatrix);
}

// ------------------------
// Re: metadatum productFrame
// ------------------------

// Has, by productFrame
int
MixedCovarianceMatrixHasByProductFrame(
   ConstHandle2ConstMixed self,
   const char *const productFrame
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"CovarianceMatrixHasByProductFrame",
       self, extract::covarianceMatrix, meta::productFrame, productFrame);
}

// Get, by productFrame, const
Handle2ConstCovarianceMatrix
MixedCovarianceMatrixGetByProductFrameConst(
   ConstHandle2ConstMixed self,
   const char *const productFrame
) {
   return detail::getByMetadatum<CPP,Handle2ConstCovarianceMatrix>
      (CLASSNAME, CLASSNAME+"CovarianceMatrixGetByProductFrameConst",
       self, extract::covarianceMatrix, meta::productFrame, productFrame);
}

// Get, by productFrame
Handle2CovarianceMatrix
MixedCovarianceMatrixGetByProductFrame(
   ConstHandle2Mixed self,
   const char *const productFrame
) {
   return detail::getByMetadatum<CPP,Handle2CovarianceMatrix>
      (CLASSNAME, CLASSNAME+"CovarianceMatrixGetByProductFrame",
       self, extract::covarianceMatrix, meta::productFrame, productFrame);
}

// Set, by productFrame
void
MixedCovarianceMatrixSetByProductFrame(
   ConstHandle2Mixed self,
   const char *const productFrame,
   ConstHandle2ConstCovarianceMatrix covarianceMatrix
) {
   detail::setByMetadatum<CPP,CPPCovarianceMatrix>
      (CLASSNAME, CLASSNAME+"CovarianceMatrixSetByProductFrame",
       self, extract::covarianceMatrix, meta::productFrame, productFrame, covarianceMatrix);
}


// -----------------------------------------------------------------------------
// Child: sum
// -----------------------------------------------------------------------------

// Has
int
MixedSumHas(ConstHandle2ConstMixed self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SumHas", self, extract::sum);
}

// Clear
void
MixedSumClear(ConstHandle2Mixed self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"SumClear", self, extract::sum);
}

// Size
size_t
MixedSumSize(ConstHandle2ConstMixed self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"SumSize", self, extract::sum);
}

// Add
void
MixedSumAdd(ConstHandle2Mixed self, ConstHandle2ConstSum sum)
{
   detail::addToContainer<CPP,CPPSum>
      (CLASSNAME, CLASSNAME+"SumAdd", self, extract::sum, sum);
}

// Get, by index \in [0,size), const
Handle2ConstSum
MixedSumGetConst(ConstHandle2ConstMixed self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstSum>
      (CLASSNAME, CLASSNAME+"SumGetConst", self, extract::sum, index_);
}

// Get, by index \in [0,size)
Handle2Sum
MixedSumGet(ConstHandle2Mixed self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Sum>
      (CLASSNAME, CLASSNAME+"SumGet", self, extract::sum, index_);
}

// Set, by index \in [0,size)
void
MixedSumSet(
   ConstHandle2Mixed self,
   const size_t index_,
   ConstHandle2ConstSum sum
) {
   detail::setByIndex<CPP,CPPSum>
      (CLASSNAME, CLASSNAME+"SumSet", self, extract::sum, index_, sum);
}

// ------------------------
// Re: metadatum label
// ------------------------

// Has, by label
int
MixedSumHasByLabel(
   ConstHandle2ConstMixed self,
   const char *const label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"SumHasByLabel",
       self, extract::sum, meta::label, label);
}

// Get, by label, const
Handle2ConstSum
MixedSumGetByLabelConst(
   ConstHandle2ConstMixed self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2ConstSum>
      (CLASSNAME, CLASSNAME+"SumGetByLabelConst",
       self, extract::sum, meta::label, label);
}

// Get, by label
Handle2Sum
MixedSumGetByLabel(
   ConstHandle2Mixed self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2Sum>
      (CLASSNAME, CLASSNAME+"SumGetByLabel",
       self, extract::sum, meta::label, label);
}

// Set, by label
void
MixedSumSetByLabel(
   ConstHandle2Mixed self,
   const char *const label,
   ConstHandle2ConstSum sum
) {
   detail::setByMetadatum<CPP,CPPSum>
      (CLASSNAME, CLASSNAME+"SumSetByLabel",
       self, extract::sum, meta::label, label, sum);
}

// ------------------------
// Re: metadatum domainMin
// ------------------------

// Has, by domainMin
int
MixedSumHasByDomainMin(
   ConstHandle2ConstMixed self,
   const double domainMin
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"SumHasByDomainMin",
       self, extract::sum, meta::domainMin, domainMin);
}

// Get, by domainMin, const
Handle2ConstSum
MixedSumGetByDomainMinConst(
   ConstHandle2ConstMixed self,
   const double domainMin
) {
   return detail::getByMetadatum<CPP,Handle2ConstSum>
      (CLASSNAME, CLASSNAME+"SumGetByDomainMinConst",
       self, extract::sum, meta::domainMin, domainMin);
}

// Get, by domainMin
Handle2Sum
MixedSumGetByDomainMin(
   ConstHandle2Mixed self,
   const double domainMin
) {
   return detail::getByMetadatum<CPP,Handle2Sum>
      (CLASSNAME, CLASSNAME+"SumGetByDomainMin",
       self, extract::sum, meta::domainMin, domainMin);
}

// Set, by domainMin
void
MixedSumSetByDomainMin(
   ConstHandle2Mixed self,
   const double domainMin,
   ConstHandle2ConstSum sum
) {
   detail::setByMetadatum<CPP,CPPSum>
      (CLASSNAME, CLASSNAME+"SumSetByDomainMin",
       self, extract::sum, meta::domainMin, domainMin, sum);
}

// ------------------------
// Re: metadatum domainMax
// ------------------------

// Has, by domainMax
int
MixedSumHasByDomainMax(
   ConstHandle2ConstMixed self,
   const double domainMax
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"SumHasByDomainMax",
       self, extract::sum, meta::domainMax, domainMax);
}

// Get, by domainMax, const
Handle2ConstSum
MixedSumGetByDomainMaxConst(
   ConstHandle2ConstMixed self,
   const double domainMax
) {
   return detail::getByMetadatum<CPP,Handle2ConstSum>
      (CLASSNAME, CLASSNAME+"SumGetByDomainMaxConst",
       self, extract::sum, meta::domainMax, domainMax);
}

// Get, by domainMax
Handle2Sum
MixedSumGetByDomainMax(
   ConstHandle2Mixed self,
   const double domainMax
) {
   return detail::getByMetadatum<CPP,Handle2Sum>
      (CLASSNAME, CLASSNAME+"SumGetByDomainMax",
       self, extract::sum, meta::domainMax, domainMax);
}

// Set, by domainMax
void
MixedSumSetByDomainMax(
   ConstHandle2Mixed self,
   const double domainMax,
   ConstHandle2ConstSum sum
) {
   detail::setByMetadatum<CPP,CPPSum>
      (CLASSNAME, CLASSNAME+"SumSetByDomainMax",
       self, extract::sum, meta::domainMax, domainMax, sum);
}

// ------------------------
// Re: metadatum domainUnit
// ------------------------

// Has, by domainUnit
int
MixedSumHasByDomainUnit(
   ConstHandle2ConstMixed self,
   const char *const domainUnit
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"SumHasByDomainUnit",
       self, extract::sum, meta::domainUnit, domainUnit);
}

// Get, by domainUnit, const
Handle2ConstSum
MixedSumGetByDomainUnitConst(
   ConstHandle2ConstMixed self,
   const char *const domainUnit
) {
   return detail::getByMetadatum<CPP,Handle2ConstSum>
      (CLASSNAME, CLASSNAME+"SumGetByDomainUnitConst",
       self, extract::sum, meta::domainUnit, domainUnit);
}

// Get, by domainUnit
Handle2Sum
MixedSumGetByDomainUnit(
   ConstHandle2Mixed self,
   const char *const domainUnit
) {
   return detail::getByMetadatum<CPP,Handle2Sum>
      (CLASSNAME, CLASSNAME+"SumGetByDomainUnit",
       self, extract::sum, meta::domainUnit, domainUnit);
}

// Set, by domainUnit
void
MixedSumSetByDomainUnit(
   ConstHandle2Mixed self,
   const char *const domainUnit,
   ConstHandle2ConstSum sum
) {
   detail::setByMetadatum<CPP,CPPSum>
      (CLASSNAME, CLASSNAME+"SumSetByDomainUnit",
       self, extract::sum, meta::domainUnit, domainUnit, sum);
}


// -----------------------------------------------------------------------------
// Child: shortRangeSelfScalingVariance
// -----------------------------------------------------------------------------

// Has
int
MixedShortRangeSelfScalingVarianceHas(ConstHandle2ConstMixed self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ShortRangeSelfScalingVarianceHas", self, extract::shortRangeSelfScalingVariance);
}

// Get, const
Handle2ConstShortRangeSelfScalingVariance
MixedShortRangeSelfScalingVarianceGetConst(ConstHandle2ConstMixed self)
{
   return detail::getField<CPP,Handle2ConstShortRangeSelfScalingVariance>
      (CLASSNAME, CLASSNAME+"ShortRangeSelfScalingVarianceGetConst", self, extract::shortRangeSelfScalingVariance);
}

// Get
Handle2ShortRangeSelfScalingVariance
MixedShortRangeSelfScalingVarianceGet(ConstHandle2Mixed self)
{
   return detail::getField<CPP,Handle2ShortRangeSelfScalingVariance>
      (CLASSNAME, CLASSNAME+"ShortRangeSelfScalingVarianceGet", self, extract::shortRangeSelfScalingVariance);
}

// Set
void
MixedShortRangeSelfScalingVarianceSet(ConstHandle2Mixed self, ConstHandle2ConstShortRangeSelfScalingVariance shortRangeSelfScalingVariance)
{
   detail::setField<CPP,CPPShortRangeSelfScalingVariance>
      (CLASSNAME, CLASSNAME+"ShortRangeSelfScalingVarianceSet", self, extract::shortRangeSelfScalingVariance, shortRangeSelfScalingVariance);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Mixed/src/custom.cpp"
