
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/documentation/Date.hpp"
#include "Date.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = DateClass;
using CPP = multigroup::Date;

static const std::string CLASSNAME = "Date";

namespace extract {
   static auto dateType = [](auto &obj) { return &obj.dateType; };
   static auto value = [](auto &obj) { return &obj.value; };
}


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstDate
DateDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Date
DateDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstDate
DateCreateConst(
   const enums::DateType dateType,
   const char *const value
) {
   ConstHandle2Date handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      dateType,
      value
   );
   return handle;
}

// Create, general
Handle2Date
DateCreate(
   const enums::DateType dateType,
   const char *const value
) {
   ConstHandle2Date handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      dateType,
      value
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
DateAssign(ConstHandle2Date self, ConstHandle2ConstDate from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
DateDelete(ConstHandle2ConstDate self)
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
DateRead(ConstHandle2Date self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
DateWrite(ConstHandle2ConstDate self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
DatePrint(ConstHandle2ConstDate self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
DatePrintXML(ConstHandle2ConstDate self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
DatePrintJSON(ConstHandle2ConstDate self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: dateType
// -----------------------------------------------------------------------------

// Has
int
DateDateTypeHas(ConstHandle2ConstDate self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DateTypeHas", self, extract::dateType);
}

// Get
// Returns by value
enums::DateType
DateDateTypeGet(ConstHandle2ConstDate self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DateTypeGet", self, extract::dateType);
}

// Set
void
DateDateTypeSet(ConstHandle2Date self, const enums::DateType dateType)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DateTypeSet", self, extract::dateType, dateType);
}


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// Has
int
DateValueHas(ConstHandle2ConstDate self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ValueHas", self, extract::value);
}

// Get
// Returns by value
const char *
DateValueGet(ConstHandle2ConstDate self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ValueGet", self, extract::value);
}

// Set
void
DateValueSet(ConstHandle2Date self, const char *const value)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ValueSet", self, extract::value, value);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/documentation/Date/src/custom.cpp"
