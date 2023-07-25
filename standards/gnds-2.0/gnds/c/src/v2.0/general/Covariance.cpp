
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "gnds/v2.0/general/Covariance.hpp"
#include "Covariance.h"

using namespace njoy::GNDStk;
using namespace gnds::v2_0;

using C = CovarianceClass;
using CPP = multigroup::Covariance;

static const std::string CLASSNAME = "Covariance";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto href = [](auto &obj) { return &obj.href; };
   static auto array = [](auto &obj) { return &obj.array; };
}

using CPPArray = general::Array;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstCovariance
CovarianceDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Covariance
CovarianceDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstCovariance
CovarianceCreateConst(
   const char *const label,
   const char *const href,
   ConstHandle2ConstArray array
) {
   ConstHandle2Covariance handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      href,
      detail::tocpp<CPPArray>(array)
   );
   return handle;
}

// Create, general
Handle2Covariance
CovarianceCreate(
   const char *const label,
   const char *const href,
   ConstHandle2ConstArray array
) {
   ConstHandle2Covariance handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      href,
      detail::tocpp<CPPArray>(array)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
CovarianceAssign(ConstHandle2Covariance self, ConstHandle2ConstCovariance from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
CovarianceDelete(ConstHandle2ConstCovariance self)
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
CovarianceRead(ConstHandle2Covariance self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
CovarianceWrite(ConstHandle2ConstCovariance self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
CovariancePrint(ConstHandle2ConstCovariance self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
CovariancePrintXML(ConstHandle2ConstCovariance self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
CovariancePrintJSON(ConstHandle2ConstCovariance self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
CovarianceLabelHas(ConstHandle2ConstCovariance self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
const char *
CovarianceLabelGet(ConstHandle2ConstCovariance self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
CovarianceLabelSet(ConstHandle2Covariance self, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// Has
int
CovarianceHrefHas(ConstHandle2ConstCovariance self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"HrefHas", self, extract::href);
}

// Get
// Returns by value
const char *
CovarianceHrefGet(ConstHandle2ConstCovariance self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"HrefGet", self, extract::href);
}

// Set
void
CovarianceHrefSet(ConstHandle2Covariance self, const char *const href)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"HrefSet", self, extract::href, href);
}


// -----------------------------------------------------------------------------
// Child: array
// -----------------------------------------------------------------------------

// Has
int
CovarianceArrayHas(ConstHandle2ConstCovariance self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ArrayHas", self, extract::array);
}

// Get, const
Handle2ConstArray
CovarianceArrayGetConst(ConstHandle2ConstCovariance self)
{
   return detail::getField<CPP,Handle2ConstArray>
      (CLASSNAME, CLASSNAME+"ArrayGetConst", self, extract::array);
}

// Get, non-const
Handle2Array
CovarianceArrayGet(ConstHandle2Covariance self)
{
   return detail::getField<CPP,Handle2Array>
      (CLASSNAME, CLASSNAME+"ArrayGet", self, extract::array);
}

// Set
void
CovarianceArraySet(ConstHandle2Covariance self, ConstHandle2ConstArray array)
{
   detail::setField<CPP,CPPArray>
      (CLASSNAME, CLASSNAME+"ArraySet", self, extract::array, array);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Covariance/src/custom.cpp"
