
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/tsl/E_max.hpp"
#include "E_max.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = E_maxClass;
using CPP = multigroup::E_max;

static const std::string CLASSNAME = "E_max";

namespace extract {
   static auto unit = [](auto &obj) { return &obj.unit; };
   static auto value = [](auto &obj) { return &obj.value; };
}


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstE_max
E_maxDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2E_max
E_maxDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstE_max
E_maxCreateConst(
   const XMLName unit,
   const Float64 value
) {
   ConstHandle2E_max handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      unit,
      value
   );
   return handle;
}

// Create, general
Handle2E_max
E_maxCreate(
   const XMLName unit,
   const Float64 value
) {
   ConstHandle2E_max handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      unit,
      value
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
E_maxAssign(ConstHandle2E_max This, ConstHandle2ConstE_max from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
E_maxDelete(ConstHandle2ConstE_max This)
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
E_maxRead(ConstHandle2E_max This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
E_maxWrite(ConstHandle2ConstE_max This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
E_maxPrint(ConstHandle2ConstE_max This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
E_maxPrintXML(ConstHandle2ConstE_max This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
E_maxPrintJSON(ConstHandle2ConstE_max This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// Has
int
E_maxUnitHas(ConstHandle2ConstE_max This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UnitHas", This, extract::unit);
}

// Get
// Returns by value
XMLName
E_maxUnitGet(ConstHandle2ConstE_max This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"UnitGet", This, extract::unit);
}

// Set
void
E_maxUnitSet(ConstHandle2E_max This, const XMLName unit)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"UnitSet", This, extract::unit, unit);
}


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// Has
int
E_maxValueHas(ConstHandle2ConstE_max This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ValueHas", This, extract::value);
}

// Get
// Returns by value
Float64
E_maxValueGet(ConstHandle2ConstE_max This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ValueGet", This, extract::value);
}

// Set
void
E_maxValueSet(ConstHandle2E_max This, const Float64 value)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ValueSet", This, extract::value, value);
}
