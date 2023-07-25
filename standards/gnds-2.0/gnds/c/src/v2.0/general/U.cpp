
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "gnds/v2.0/general/U.hpp"
#include "U.h"

using namespace njoy::GNDStk;
using namespace gnds::v2_0;

using C = UClass;
using CPP = multigroup::U;

static const std::string CLASSNAME = "U";

namespace extract {
   static auto value = [](auto &obj) { return &obj.value; };
   static auto unit = [](auto &obj) { return &obj.unit; };
}


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstU
UDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2U
UDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstU
UCreateConst(
   const double value,
   const char *const unit
) {
   ConstHandle2U handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      value,
      unit
   );
   return handle;
}

// Create, general
Handle2U
UCreate(
   const double value,
   const char *const unit
) {
   ConstHandle2U handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      value,
      unit
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
UAssign(ConstHandle2U self, ConstHandle2ConstU from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
UDelete(ConstHandle2ConstU self)
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
URead(ConstHandle2U self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
UWrite(ConstHandle2ConstU self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
UPrint(ConstHandle2ConstU self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
UPrintXML(ConstHandle2ConstU self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
UPrintJSON(ConstHandle2ConstU self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// Has
int
UValueHas(ConstHandle2ConstU self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ValueHas", self, extract::value);
}

// Get
// Returns by value
double
UValueGet(ConstHandle2ConstU self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ValueGet", self, extract::value);
}

// Set
void
UValueSet(ConstHandle2U self, const double value)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ValueSet", self, extract::value, value);
}


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// Has
int
UUnitHas(ConstHandle2ConstU self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UnitHas", self, extract::unit);
}

// Get
// Returns by value
const char *
UUnitGet(ConstHandle2ConstU self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"UnitGet", self, extract::unit);
}

// Set
void
UUnitSet(ConstHandle2U self, const char *const unit)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"UnitSet", self, extract::unit, unit);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/U/src/custom.cpp"
