
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2.0/documentation/Dates.hpp"
#include "Dates.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = DatesClass;
using CPP = multigroup::Dates;

static const std::string CLASSNAME = "Dates";

namespace extract {
   static auto date = [](auto &obj) { return &obj.date; };
}

using CPPDate = documentation::Date;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstDates
DatesDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Dates
DatesDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstDates
DatesCreateConst(
   ConstHandle2Date *const date, const size_t dateSize
) {
   ConstHandle2Dates handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPDate>{}
   );
   for (size_t DateN = 0; DateN < dateSize; ++DateN)
      DatesDateAdd(handle, date[DateN]);
   return handle;
}

// Create, general
Handle2Dates
DatesCreate(
   ConstHandle2Date *const date, const size_t dateSize
) {
   ConstHandle2Dates handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPDate>{}
   );
   for (size_t DateN = 0; DateN < dateSize; ++DateN)
      DatesDateAdd(handle, date[DateN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
DatesAssign(ConstHandle2Dates self, ConstHandle2ConstDates from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
DatesDelete(ConstHandle2ConstDates self)
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
DatesRead(ConstHandle2Dates self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
DatesWrite(ConstHandle2ConstDates self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
DatesPrint(ConstHandle2ConstDates self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
DatesPrintXML(ConstHandle2ConstDates self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
DatesPrintJSON(ConstHandle2ConstDates self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: date
// -----------------------------------------------------------------------------

// Has
int
DatesDateHas(ConstHandle2ConstDates self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DateHas", self, extract::date);
}

// Clear
void
DatesDateClear(ConstHandle2Dates self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"DateClear", self, extract::date);
}

// Size
size_t
DatesDateSize(ConstHandle2ConstDates self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"DateSize", self, extract::date);
}

// Add
void
DatesDateAdd(ConstHandle2Dates self, ConstHandle2ConstDate date)
{
   detail::addToContainer<CPP,CPPDate>
      (CLASSNAME, CLASSNAME+"DateAdd", self, extract::date, date);
}

// Get, by index \in [0,size), const
Handle2ConstDate
DatesDateGetConst(ConstHandle2ConstDates self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstDate>
      (CLASSNAME, CLASSNAME+"DateGetConst", self, extract::date, index_);
}

// Get, by index \in [0,size), non-const
Handle2Date
DatesDateGet(ConstHandle2Dates self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Date>
      (CLASSNAME, CLASSNAME+"DateGet", self, extract::date, index_);
}

// Set, by index \in [0,size)
void
DatesDateSet(
   ConstHandle2Dates self,
   const size_t index_,
   ConstHandle2ConstDate date
) {
   detail::setByIndex<CPP,CPPDate>
      (CLASSNAME, CLASSNAME+"DateSet", self, extract::date, index_, date);
}

// Has, by dateType
int
DatesDateHasByDateType(
   ConstHandle2ConstDates self,
   const enums::DateType dateType
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"DateHasByDateType",
       self, extract::date, meta::dateType, dateType);
}

// Get, by dateType, const
Handle2ConstDate
DatesDateGetByDateTypeConst(
   ConstHandle2ConstDates self,
   const enums::DateType dateType
) {
   return detail::getByMetadatum<CPP,Handle2ConstDate>
      (CLASSNAME, CLASSNAME+"DateGetByDateTypeConst",
       self, extract::date, meta::dateType, dateType);
}

// Get, by dateType, non-const
Handle2Date
DatesDateGetByDateType(
   ConstHandle2Dates self,
   const enums::DateType dateType
) {
   return detail::getByMetadatum<CPP,Handle2Date>
      (CLASSNAME, CLASSNAME+"DateGetByDateType",
       self, extract::date, meta::dateType, dateType);
}

// Set, by dateType
void
DatesDateSetByDateType(
   ConstHandle2Dates self,
   const enums::DateType dateType,
   ConstHandle2ConstDate date
) {
   detail::setByMetadatum<CPP,CPPDate>
      (CLASSNAME, CLASSNAME+"DateSetByDateType",
       self, extract::date, meta::dateType, dateType, date);
}

// Has, by value
int
DatesDateHasByValue(
   ConstHandle2ConstDates self,
   const char *const value
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"DateHasByValue",
       self, extract::date, meta::value, value);
}

// Get, by value, const
Handle2ConstDate
DatesDateGetByValueConst(
   ConstHandle2ConstDates self,
   const char *const value
) {
   return detail::getByMetadatum<CPP,Handle2ConstDate>
      (CLASSNAME, CLASSNAME+"DateGetByValueConst",
       self, extract::date, meta::value, value);
}

// Get, by value, non-const
Handle2Date
DatesDateGetByValue(
   ConstHandle2Dates self,
   const char *const value
) {
   return detail::getByMetadatum<CPP,Handle2Date>
      (CLASSNAME, CLASSNAME+"DateGetByValue",
       self, extract::date, meta::value, value);
}

// Set, by value
void
DatesDateSetByValue(
   ConstHandle2Dates self,
   const char *const value,
   ConstHandle2ConstDate date
) {
   detail::setByMetadatum<CPP,CPPDate>
      (CLASSNAME, CLASSNAME+"DateSetByValue",
       self, extract::date, meta::value, value, date);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/documentation/Dates/src/custom.cpp"
