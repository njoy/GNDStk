
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2.0/containers/Values.hpp"
#include "Values.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = ValuesClass;
using CPP = multigroup::Values;

static const std::string CLASSNAME = "Values";

namespace extract {
   static auto valueType = [](auto &obj) { return &obj.valueType; };
   static auto start = [](auto &obj) { return &obj.start; };
   static auto length = [](auto &obj) { return &obj.length; };
   static auto href = [](auto &obj) { return &obj.href; };
   static auto startIndex = [](auto &obj) { return &obj.startIndex; };
   static auto count = [](auto &obj) { return &obj.count; };
}


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstValues
ValuesDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Values
ValuesDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstValues
ValuesCreateConst(
   const UTF8Text valueType,
   const Integer32 start,
   const Integer32 length,
   const UTF8Text href,
   const Integer32 startIndex,
   const Integer32 count
) {
   ConstHandle2Values handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      valueType,
      start,
      length,
      href,
      startIndex,
      count
   );
   return handle;
}

// Create, general
Handle2Values
ValuesCreate(
   const UTF8Text valueType,
   const Integer32 start,
   const Integer32 length,
   const UTF8Text href,
   const Integer32 startIndex,
   const Integer32 count
) {
   ConstHandle2Values handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      valueType,
      start,
      length,
      href,
      startIndex,
      count
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ValuesAssign(ConstHandle2Values self, ConstHandle2ConstValues from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ValuesDelete(ConstHandle2ConstValues self)
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
ValuesRead(ConstHandle2Values self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ValuesWrite(ConstHandle2ConstValues self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ValuesPrint(ConstHandle2ConstValues self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ValuesPrintXML(ConstHandle2ConstValues self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ValuesPrintJSON(ConstHandle2ConstValues self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Data vector
// -----------------------------------------------------------------------------

// ------------------------
// int
// ------------------------

// Clear
void
ValuesIntsClear(ConstHandle2Values self)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"IntsClear", self);
}

// Get size
size_t
ValuesIntsSize(ConstHandle2ConstValues self)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"IntsSize", self);
}

// Get value
// By index \in [0,size)
int
ValuesIntsGet(ConstHandle2ConstValues self, const size_t index)
{
   return detail::vectorGet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsGet", self, index);
}

// Set value
// By index \in [0,size)
void
ValuesIntsSet(ConstHandle2Values self, const size_t index, const int value)
{
   detail::vectorSet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsSet", self, index, value);
}

// Get pointer to existing values, const
const int *
ValuesIntsGetArrayConst(ConstHandle2ConstValues self)
{
   return detail::vectorGet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsGetArrayConst", self);
}

// Get pointer to existing values, non-const
int *
ValuesIntsGetArray(ConstHandle2Values self)
{
   return detail::vectorGet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsGetArray", self);
}

// Set completely new values and size
void
ValuesIntsSetArray(ConstHandle2Values self, const int *const values, const size_t size)
{
   return detail::vectorSet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsSetArray", self, size, values);
}

// ------------------------
// unsigned
// ------------------------

// Clear
void
ValuesUnsignedsClear(ConstHandle2Values self)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"UnsignedsClear", self);
}

// Get size
size_t
ValuesUnsignedsSize(ConstHandle2ConstValues self)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"UnsignedsSize", self);
}

// Get value
// By index \in [0,size)
unsigned
ValuesUnsignedsGet(ConstHandle2ConstValues self, const size_t index)
{
   return detail::vectorGet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsGet", self, index);
}

// Set value
// By index \in [0,size)
void
ValuesUnsignedsSet(ConstHandle2Values self, const size_t index, const unsigned value)
{
   detail::vectorSet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsSet", self, index, value);
}

// Get pointer to existing values, const
const unsigned *
ValuesUnsignedsGetArrayConst(ConstHandle2ConstValues self)
{
   return detail::vectorGet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsGetArrayConst", self);
}

// Get pointer to existing values, non-const
unsigned *
ValuesUnsignedsGetArray(ConstHandle2Values self)
{
   return detail::vectorGet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsGetArray", self);
}

// Set completely new values and size
void
ValuesUnsignedsSetArray(ConstHandle2Values self, const unsigned *const values, const size_t size)
{
   return detail::vectorSet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsSetArray", self, size, values);
}

// ------------------------
// float
// ------------------------

// Clear
void
ValuesFloatsClear(ConstHandle2Values self)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"FloatsClear", self);
}

// Get size
size_t
ValuesFloatsSize(ConstHandle2ConstValues self)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"FloatsSize", self);
}

// Get value
// By index \in [0,size)
float
ValuesFloatsGet(ConstHandle2ConstValues self, const size_t index)
{
   return detail::vectorGet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsGet", self, index);
}

// Set value
// By index \in [0,size)
void
ValuesFloatsSet(ConstHandle2Values self, const size_t index, const float value)
{
   detail::vectorSet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsSet", self, index, value);
}

// Get pointer to existing values, const
const float *
ValuesFloatsGetArrayConst(ConstHandle2ConstValues self)
{
   return detail::vectorGet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsGetArrayConst", self);
}

// Get pointer to existing values, non-const
float *
ValuesFloatsGetArray(ConstHandle2Values self)
{
   return detail::vectorGet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsGetArray", self);
}

// Set completely new values and size
void
ValuesFloatsSetArray(ConstHandle2Values self, const float *const values, const size_t size)
{
   return detail::vectorSet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsSetArray", self, size, values);
}

// ------------------------
// double
// ------------------------

// Clear
void
ValuesDoublesClear(ConstHandle2Values self)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"DoublesClear", self);
}

// Get size
size_t
ValuesDoublesSize(ConstHandle2ConstValues self)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"DoublesSize", self);
}

// Get value
// By index \in [0,size)
double
ValuesDoublesGet(ConstHandle2ConstValues self, const size_t index)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGet", self, index);
}

// Set value
// By index \in [0,size)
void
ValuesDoublesSet(ConstHandle2Values self, const size_t index, const double value)
{
   detail::vectorSet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesSet", self, index, value);
}

// Get pointer to existing values, const
const double *
ValuesDoublesGetArrayConst(ConstHandle2ConstValues self)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGetArrayConst", self);
}

// Get pointer to existing values, non-const
double *
ValuesDoublesGetArray(ConstHandle2Values self)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGetArray", self);
}

// Set completely new values and size
void
ValuesDoublesSetArray(ConstHandle2Values self, const double *const values, const size_t size)
{
   return detail::vectorSet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesSetArray", self, size, values);
}


// -----------------------------------------------------------------------------
// Metadatum: valueType
// -----------------------------------------------------------------------------

// Has
int
ValuesValueTypeHas(ConstHandle2ConstValues self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ValueTypeHas", self, extract::valueType);
}

// Get
// Returns by value
UTF8Text
ValuesValueTypeGet(ConstHandle2ConstValues self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ValueTypeGet", self, extract::valueType);
}

// Set
void
ValuesValueTypeSet(ConstHandle2Values self, const UTF8Text valueType)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ValueTypeSet", self, extract::valueType, valueType);
}


// -----------------------------------------------------------------------------
// Metadatum: start
// -----------------------------------------------------------------------------

// Has
int
ValuesStartHas(ConstHandle2ConstValues self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"StartHas", self, extract::start);
}

// Get
// Returns by value
Integer32
ValuesStartGet(ConstHandle2ConstValues self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"StartGet", self, extract::start);
}

// Set
void
ValuesStartSet(ConstHandle2Values self, const Integer32 start)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"StartSet", self, extract::start, start);
}


// -----------------------------------------------------------------------------
// Metadatum: length
// -----------------------------------------------------------------------------

// Has
int
ValuesLengthHas(ConstHandle2ConstValues self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LengthHas", self, extract::length);
}

// Get
// Returns by value
Integer32
ValuesLengthGet(ConstHandle2ConstValues self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LengthGet", self, extract::length);
}

// Set
void
ValuesLengthSet(ConstHandle2Values self, const Integer32 length)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LengthSet", self, extract::length, length);
}


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// Has
int
ValuesHrefHas(ConstHandle2ConstValues self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"HrefHas", self, extract::href);
}

// Get
// Returns by value
UTF8Text
ValuesHrefGet(ConstHandle2ConstValues self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"HrefGet", self, extract::href);
}

// Set
void
ValuesHrefSet(ConstHandle2Values self, const UTF8Text href)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"HrefSet", self, extract::href, href);
}


// -----------------------------------------------------------------------------
// Metadatum: startIndex
// -----------------------------------------------------------------------------

// Has
int
ValuesStartIndexHas(ConstHandle2ConstValues self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"StartIndexHas", self, extract::startIndex);
}

// Get
// Returns by value
Integer32
ValuesStartIndexGet(ConstHandle2ConstValues self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"StartIndexGet", self, extract::startIndex);
}

// Set
void
ValuesStartIndexSet(ConstHandle2Values self, const Integer32 startIndex)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"StartIndexSet", self, extract::startIndex, startIndex);
}


// -----------------------------------------------------------------------------
// Metadatum: count
// -----------------------------------------------------------------------------

// Has
int
ValuesCountHas(ConstHandle2ConstValues self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CountHas", self, extract::count);
}

// Get
// Returns by value
Integer32
ValuesCountGet(ConstHandle2ConstValues self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"CountGet", self, extract::count);
}

// Set
void
ValuesCountSet(ConstHandle2Values self, const Integer32 count)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"CountSet", self, extract::count, count);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/containers/Values/src/custom.cpp"
