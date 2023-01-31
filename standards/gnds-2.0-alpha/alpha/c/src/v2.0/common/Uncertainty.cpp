
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/common/Uncertainty.hpp"
#include "Uncertainty.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = UncertaintyClass;
using CPP = multigroup::Uncertainty;

static const std::string CLASSNAME = "Uncertainty";

namespace extract {
   static auto covariance = [](auto &obj) { return &obj.covariance; };
   static auto standard = [](auto &obj) { return &obj.standard; };
   static auto listOfCovariances = [](auto &obj) { return &obj.listOfCovariances; };
   static auto polynomial1d = [](auto &obj) { return &obj.polynomial1d; };
}

using CPPCovariance = common::Covariance;
using CPPStandard = sfy::Standard;
using CPPListOfCovariances = mean::ListOfCovariances;
using CPPPolynomial1d = reduced::Polynomial1d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstUncertainty
UncertaintyDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Uncertainty
UncertaintyDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstUncertainty
UncertaintyCreateConst(
   ConstHandle2ConstCovariance covariance,
   ConstHandle2ConstStandard standard,
   ConstHandle2ConstListOfCovariances listOfCovariances,
   ConstHandle2ConstPolynomial1d polynomial1d
) {
   ConstHandle2Uncertainty handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPCovariance>(covariance),
      detail::tocpp<CPPStandard>(standard),
      detail::tocpp<CPPListOfCovariances>(listOfCovariances),
      detail::tocpp<CPPPolynomial1d>(polynomial1d)
   );
   return handle;
}

// Create, general
Handle2Uncertainty
UncertaintyCreate(
   ConstHandle2ConstCovariance covariance,
   ConstHandle2ConstStandard standard,
   ConstHandle2ConstListOfCovariances listOfCovariances,
   ConstHandle2ConstPolynomial1d polynomial1d
) {
   ConstHandle2Uncertainty handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPCovariance>(covariance),
      detail::tocpp<CPPStandard>(standard),
      detail::tocpp<CPPListOfCovariances>(listOfCovariances),
      detail::tocpp<CPPPolynomial1d>(polynomial1d)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
UncertaintyAssign(ConstHandle2Uncertainty This, ConstHandle2ConstUncertainty from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
UncertaintyDelete(ConstHandle2ConstUncertainty This)
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
UncertaintyRead(ConstHandle2Uncertainty This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
UncertaintyWrite(ConstHandle2ConstUncertainty This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
UncertaintyPrint(ConstHandle2ConstUncertainty This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
UncertaintyPrintXML(ConstHandle2ConstUncertainty This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
UncertaintyPrintJSON(ConstHandle2ConstUncertainty This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: covariance
// -----------------------------------------------------------------------------

// Has
int
UncertaintyCovarianceHas(ConstHandle2ConstUncertainty This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CovarianceHas", This, extract::covariance);
}

// Get, const
Handle2ConstCovariance
UncertaintyCovarianceGetConst(ConstHandle2ConstUncertainty This)
{
   return detail::getField<CPP,Handle2ConstCovariance>
      (CLASSNAME, CLASSNAME+"CovarianceGetConst", This, extract::covariance);
}

// Get, non-const
Handle2Covariance
UncertaintyCovarianceGet(ConstHandle2Uncertainty This)
{
   return detail::getField<CPP,Handle2Covariance>
      (CLASSNAME, CLASSNAME+"CovarianceGet", This, extract::covariance);
}

// Set
void
UncertaintyCovarianceSet(ConstHandle2Uncertainty This, ConstHandle2ConstCovariance covariance)
{
   detail::setField<CPP,CPPCovariance>
      (CLASSNAME, CLASSNAME+"CovarianceSet", This, extract::covariance, covariance);
}


// -----------------------------------------------------------------------------
// Child: standard
// -----------------------------------------------------------------------------

// Has
int
UncertaintyStandardHas(ConstHandle2ConstUncertainty This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"StandardHas", This, extract::standard);
}

// Get, const
Handle2ConstStandard
UncertaintyStandardGetConst(ConstHandle2ConstUncertainty This)
{
   return detail::getField<CPP,Handle2ConstStandard>
      (CLASSNAME, CLASSNAME+"StandardGetConst", This, extract::standard);
}

// Get, non-const
Handle2Standard
UncertaintyStandardGet(ConstHandle2Uncertainty This)
{
   return detail::getField<CPP,Handle2Standard>
      (CLASSNAME, CLASSNAME+"StandardGet", This, extract::standard);
}

// Set
void
UncertaintyStandardSet(ConstHandle2Uncertainty This, ConstHandle2ConstStandard standard)
{
   detail::setField<CPP,CPPStandard>
      (CLASSNAME, CLASSNAME+"StandardSet", This, extract::standard, standard);
}


// -----------------------------------------------------------------------------
// Child: listOfCovariances
// -----------------------------------------------------------------------------

// Has
int
UncertaintyListOfCovariancesHas(ConstHandle2ConstUncertainty This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ListOfCovariancesHas", This, extract::listOfCovariances);
}

// Get, const
Handle2ConstListOfCovariances
UncertaintyListOfCovariancesGetConst(ConstHandle2ConstUncertainty This)
{
   return detail::getField<CPP,Handle2ConstListOfCovariances>
      (CLASSNAME, CLASSNAME+"ListOfCovariancesGetConst", This, extract::listOfCovariances);
}

// Get, non-const
Handle2ListOfCovariances
UncertaintyListOfCovariancesGet(ConstHandle2Uncertainty This)
{
   return detail::getField<CPP,Handle2ListOfCovariances>
      (CLASSNAME, CLASSNAME+"ListOfCovariancesGet", This, extract::listOfCovariances);
}

// Set
void
UncertaintyListOfCovariancesSet(ConstHandle2Uncertainty This, ConstHandle2ConstListOfCovariances listOfCovariances)
{
   detail::setField<CPP,CPPListOfCovariances>
      (CLASSNAME, CLASSNAME+"ListOfCovariancesSet", This, extract::listOfCovariances, listOfCovariances);
}


// -----------------------------------------------------------------------------
// Child: polynomial1d
// -----------------------------------------------------------------------------

// Has
int
UncertaintyPolynomial1dHas(ConstHandle2ConstUncertainty This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Polynomial1dHas", This, extract::polynomial1d);
}

// Get, const
Handle2ConstPolynomial1d
UncertaintyPolynomial1dGetConst(ConstHandle2ConstUncertainty This)
{
   return detail::getField<CPP,Handle2ConstPolynomial1d>
      (CLASSNAME, CLASSNAME+"Polynomial1dGetConst", This, extract::polynomial1d);
}

// Get, non-const
Handle2Polynomial1d
UncertaintyPolynomial1dGet(ConstHandle2Uncertainty This)
{
   return detail::getField<CPP,Handle2Polynomial1d>
      (CLASSNAME, CLASSNAME+"Polynomial1dGet", This, extract::polynomial1d);
}

// Set
void
UncertaintyPolynomial1dSet(ConstHandle2Uncertainty This, ConstHandle2ConstPolynomial1d polynomial1d)
{
   detail::setField<CPP,CPPPolynomial1d>
      (CLASSNAME, CLASSNAME+"Polynomial1dSet", This, extract::polynomial1d, polynomial1d);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/common/Uncertainty/src/custom.cpp"
