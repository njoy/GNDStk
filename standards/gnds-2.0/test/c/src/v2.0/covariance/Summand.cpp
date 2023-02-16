
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/covariance/Summand.hpp"
#include "Summand.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = SummandClass;
using CPP = multigroup::Summand;

static const std::string CLASSNAME = "Summand";

namespace extract {
   static auto ENDF_MFMT = [](auto &obj) { return &obj.ENDF_MFMT; };
   static auto coefficient = [](auto &obj) { return &obj.coefficient; };
   static auto href = [](auto &obj) { return &obj.href; };
}


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstSummand
SummandDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Summand
SummandDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstSummand
SummandCreateConst(
   const XMLName ENDF_MFMT,
   const Float64 coefficient,
   const char *const href
) {
   ConstHandle2Summand handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      ENDF_MFMT,
      coefficient,
      href
   );
   return handle;
}

// Create, general
Handle2Summand
SummandCreate(
   const XMLName ENDF_MFMT,
   const Float64 coefficient,
   const char *const href
) {
   ConstHandle2Summand handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      ENDF_MFMT,
      coefficient,
      href
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
SummandAssign(ConstHandle2Summand self, ConstHandle2ConstSummand from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
SummandDelete(ConstHandle2ConstSummand self)
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
SummandRead(ConstHandle2Summand self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
SummandWrite(ConstHandle2ConstSummand self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
SummandPrint(ConstHandle2ConstSummand self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
SummandPrintXML(ConstHandle2ConstSummand self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
SummandPrintJSON(ConstHandle2ConstSummand self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: ENDF_MFMT
// -----------------------------------------------------------------------------

// Has
int
SummandENDFMFMTHas(ConstHandle2ConstSummand self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ENDFMFMTHas", self, extract::ENDF_MFMT);
}

// Get
// Returns by value
XMLName
SummandENDFMFMTGet(ConstHandle2ConstSummand self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ENDFMFMTGet", self, extract::ENDF_MFMT);
}

// Set
void
SummandENDFMFMTSet(ConstHandle2Summand self, const XMLName ENDF_MFMT)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ENDFMFMTSet", self, extract::ENDF_MFMT, ENDF_MFMT);
}


// -----------------------------------------------------------------------------
// Metadatum: coefficient
// -----------------------------------------------------------------------------

// Has
int
SummandCoefficientHas(ConstHandle2ConstSummand self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CoefficientHas", self, extract::coefficient);
}

// Get
// Returns by value
Float64
SummandCoefficientGet(ConstHandle2ConstSummand self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"CoefficientGet", self, extract::coefficient);
}

// Set
void
SummandCoefficientSet(ConstHandle2Summand self, const Float64 coefficient)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"CoefficientSet", self, extract::coefficient, coefficient);
}


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// Has
int
SummandHrefHas(ConstHandle2ConstSummand self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"HrefHas", self, extract::href);
}

// Get
// Returns by value
const char *
SummandHrefGet(ConstHandle2ConstSummand self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"HrefGet", self, extract::href);
}

// Set
void
SummandHrefSet(ConstHandle2Summand self, const char *const href)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"HrefSet", self, extract::href, href);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/covariance/Summand/src/custom.cpp"
