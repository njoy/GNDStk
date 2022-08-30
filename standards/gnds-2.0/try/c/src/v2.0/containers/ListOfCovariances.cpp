
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/containers/ListOfCovariances.hpp"
#include "ListOfCovariances.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = ListOfCovariancesClass;
using CPP = multigroup::ListOfCovariances;

static const std::string CLASSNAME = "ListOfCovariances";

namespace extract {
   static auto covariance = [](auto &obj) { return &obj.covariance; };
}

using CPPCovariance = containers::Covariance;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstListOfCovariances
ListOfCovariancesDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2ListOfCovariances
ListOfCovariancesDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstListOfCovariances
ListOfCovariancesCreateConst(
   ConstHandle2Covariance *const covariance, const size_t covarianceSize
) {
   ConstHandle2ListOfCovariances handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPCovariance>{}
   );
   for (size_t CovarianceN = 0; CovarianceN < covarianceSize; ++CovarianceN)
      ListOfCovariancesCovarianceAdd(handle, covariance[CovarianceN]);
   return handle;
}

// Create, general
Handle2ListOfCovariances
ListOfCovariancesCreate(
   ConstHandle2Covariance *const covariance, const size_t covarianceSize
) {
   ConstHandle2ListOfCovariances handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPCovariance>{}
   );
   for (size_t CovarianceN = 0; CovarianceN < covarianceSize; ++CovarianceN)
      ListOfCovariancesCovarianceAdd(handle, covariance[CovarianceN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ListOfCovariancesAssign(ConstHandle2ListOfCovariances This, ConstHandle2ConstListOfCovariances from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ListOfCovariancesDelete(ConstHandle2ConstListOfCovariances This)
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
ListOfCovariancesRead(ConstHandle2ListOfCovariances This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ListOfCovariancesWrite(ConstHandle2ConstListOfCovariances This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
ListOfCovariancesPrint(ConstHandle2ConstListOfCovariances This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
ListOfCovariancesPrintXML(ConstHandle2ConstListOfCovariances This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
ListOfCovariancesPrintJSON(ConstHandle2ConstListOfCovariances This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: covariance
// -----------------------------------------------------------------------------

// Has
int
ListOfCovariancesCovarianceHas(ConstHandle2ConstListOfCovariances This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CovarianceHas", This, extract::covariance);
}

// Clear
void
ListOfCovariancesCovarianceClear(ConstHandle2ListOfCovariances This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"CovarianceClear", This, extract::covariance);
}

// Size
size_t
ListOfCovariancesCovarianceSize(ConstHandle2ConstListOfCovariances This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"CovarianceSize", This, extract::covariance);
}

// Add
void
ListOfCovariancesCovarianceAdd(ConstHandle2ListOfCovariances This, ConstHandle2ConstCovariance covariance)
{
   detail::addToContainer<CPP,CPPCovariance>
      (CLASSNAME, CLASSNAME+"CovarianceAdd", This, extract::covariance, covariance);
}

// Get, by index \in [0,size), const
Handle2ConstCovariance
ListOfCovariancesCovarianceGetConst(ConstHandle2ConstListOfCovariances This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstCovariance>
      (CLASSNAME, CLASSNAME+"CovarianceGetConst", This, extract::covariance, index_);
}

// Get, by index \in [0,size), non-const
Handle2Covariance
ListOfCovariancesCovarianceGet(ConstHandle2ListOfCovariances This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Covariance>
      (CLASSNAME, CLASSNAME+"CovarianceGet", This, extract::covariance, index_);
}

// Set, by index \in [0,size)
void
ListOfCovariancesCovarianceSet(
   ConstHandle2ListOfCovariances This,
   const size_t index_,
   ConstHandle2ConstCovariance covariance
) {
   detail::setByIndex<CPP,CPPCovariance>
      (CLASSNAME, CLASSNAME+"CovarianceSet", This, extract::covariance, index_, covariance);
}

// Has, by label
int
ListOfCovariancesCovarianceHasByLabel(
   ConstHandle2ConstListOfCovariances This,
   const XMLName label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"CovarianceHasByLabel",
       This, extract::covariance, meta::label, label);
}

// Get, by label, const
Handle2ConstCovariance
ListOfCovariancesCovarianceGetByLabelConst(
   ConstHandle2ConstListOfCovariances This,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2ConstCovariance>
      (CLASSNAME, CLASSNAME+"CovarianceGetByLabelConst",
       This, extract::covariance, meta::label, label);
}

// Get, by label, non-const
Handle2Covariance
ListOfCovariancesCovarianceGetByLabel(
   ConstHandle2ListOfCovariances This,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2Covariance>
      (CLASSNAME, CLASSNAME+"CovarianceGetByLabel",
       This, extract::covariance, meta::label, label);
}

// Set, by label
void
ListOfCovariancesCovarianceSetByLabel(
   ConstHandle2ListOfCovariances This,
   const XMLName label,
   ConstHandle2ConstCovariance covariance
) {
   detail::setByMetadatum<CPP,CPPCovariance>
      (CLASSNAME, CLASSNAME+"CovarianceSetByLabel",
       This, extract::covariance, meta::label, label, covariance);
}

// Has, by href
int
ListOfCovariancesCovarianceHasByHref(
   ConstHandle2ConstListOfCovariances This,
   const char *const href
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"CovarianceHasByHref",
       This, extract::covariance, meta::href, href);
}

// Get, by href, const
Handle2ConstCovariance
ListOfCovariancesCovarianceGetByHrefConst(
   ConstHandle2ConstListOfCovariances This,
   const char *const href
) {
   return detail::getByMetadatum<CPP,Handle2ConstCovariance>
      (CLASSNAME, CLASSNAME+"CovarianceGetByHrefConst",
       This, extract::covariance, meta::href, href);
}

// Get, by href, non-const
Handle2Covariance
ListOfCovariancesCovarianceGetByHref(
   ConstHandle2ListOfCovariances This,
   const char *const href
) {
   return detail::getByMetadatum<CPP,Handle2Covariance>
      (CLASSNAME, CLASSNAME+"CovarianceGetByHref",
       This, extract::covariance, meta::href, href);
}

// Set, by href
void
ListOfCovariancesCovarianceSetByHref(
   ConstHandle2ListOfCovariances This,
   const char *const href,
   ConstHandle2ConstCovariance covariance
) {
   detail::setByMetadatum<CPP,CPPCovariance>
      (CLASSNAME, CLASSNAME+"CovarianceSetByHref",
       This, extract::covariance, meta::href, href, covariance);
}
