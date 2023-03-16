
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/documentation/EndfCompatible.hpp"
#include "EndfCompatible.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = EndfCompatibleClass;
using CPP = multigroup::EndfCompatible;

static const std::string CLASSNAME = "EndfCompatible";

namespace extract {
   static auto encoding = [](auto &obj) { return &obj.encoding; };
   static auto markup = [](auto &obj) { return &obj.markup; };
   static auto label = [](auto &obj) { return &obj.label; };
}


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstEndfCompatible
EndfCompatibleDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2EndfCompatible
EndfCompatibleDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstEndfCompatible
EndfCompatibleCreateConst(
   const XMLName encoding,
   const char *const markup,
   const XMLName label
) {
   ConstHandle2EndfCompatible handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      encoding,
      markup,
      label
   );
   return handle;
}

// Create, general
Handle2EndfCompatible
EndfCompatibleCreate(
   const XMLName encoding,
   const char *const markup,
   const XMLName label
) {
   ConstHandle2EndfCompatible handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      encoding,
      markup,
      label
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
EndfCompatibleAssign(ConstHandle2EndfCompatible self, ConstHandle2ConstEndfCompatible from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
EndfCompatibleDelete(ConstHandle2ConstEndfCompatible self)
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
EndfCompatibleRead(ConstHandle2EndfCompatible self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
EndfCompatibleWrite(ConstHandle2ConstEndfCompatible self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
EndfCompatiblePrint(ConstHandle2ConstEndfCompatible self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
EndfCompatiblePrintXML(ConstHandle2ConstEndfCompatible self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
EndfCompatiblePrintJSON(ConstHandle2ConstEndfCompatible self)
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
EndfCompatibleIntsClear(ConstHandle2EndfCompatible self)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"IntsClear", self);
}

// Get size
size_t
EndfCompatibleIntsSize(ConstHandle2ConstEndfCompatible self)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"IntsSize", self);
}

// Get value
// By index \in [0,size)
int
EndfCompatibleIntsGet(ConstHandle2ConstEndfCompatible self, const size_t index)
{
   return detail::vectorGet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsGet", self, index);
}

// Set value
// By index \in [0,size)
void
EndfCompatibleIntsSet(ConstHandle2EndfCompatible self, const size_t index, const int value)
{
   detail::vectorSet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsSet", self, index, value);
}

// Get pointer to existing values, const
const int *
EndfCompatibleIntsGetArrayConst(ConstHandle2ConstEndfCompatible self)
{
   return detail::vectorGet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsGetArrayConst", self);
}

// Get pointer to existing values, non-const
int *
EndfCompatibleIntsGetArray(ConstHandle2EndfCompatible self)
{
   return detail::vectorGet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsGetArray", self);
}

// Set completely new values and size
void
EndfCompatibleIntsSetArray(ConstHandle2EndfCompatible self, const int *const values, const size_t size)
{
   return detail::vectorSet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsSetArray", self, size, values);
}

// ------------------------
// unsigned
// ------------------------

// Clear
void
EndfCompatibleUnsignedsClear(ConstHandle2EndfCompatible self)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"UnsignedsClear", self);
}

// Get size
size_t
EndfCompatibleUnsignedsSize(ConstHandle2ConstEndfCompatible self)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"UnsignedsSize", self);
}

// Get value
// By index \in [0,size)
unsigned
EndfCompatibleUnsignedsGet(ConstHandle2ConstEndfCompatible self, const size_t index)
{
   return detail::vectorGet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsGet", self, index);
}

// Set value
// By index \in [0,size)
void
EndfCompatibleUnsignedsSet(ConstHandle2EndfCompatible self, const size_t index, const unsigned value)
{
   detail::vectorSet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsSet", self, index, value);
}

// Get pointer to existing values, const
const unsigned *
EndfCompatibleUnsignedsGetArrayConst(ConstHandle2ConstEndfCompatible self)
{
   return detail::vectorGet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsGetArrayConst", self);
}

// Get pointer to existing values, non-const
unsigned *
EndfCompatibleUnsignedsGetArray(ConstHandle2EndfCompatible self)
{
   return detail::vectorGet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsGetArray", self);
}

// Set completely new values and size
void
EndfCompatibleUnsignedsSetArray(ConstHandle2EndfCompatible self, const unsigned *const values, const size_t size)
{
   return detail::vectorSet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsSetArray", self, size, values);
}

// ------------------------
// float
// ------------------------

// Clear
void
EndfCompatibleFloatsClear(ConstHandle2EndfCompatible self)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"FloatsClear", self);
}

// Get size
size_t
EndfCompatibleFloatsSize(ConstHandle2ConstEndfCompatible self)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"FloatsSize", self);
}

// Get value
// By index \in [0,size)
float
EndfCompatibleFloatsGet(ConstHandle2ConstEndfCompatible self, const size_t index)
{
   return detail::vectorGet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsGet", self, index);
}

// Set value
// By index \in [0,size)
void
EndfCompatibleFloatsSet(ConstHandle2EndfCompatible self, const size_t index, const float value)
{
   detail::vectorSet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsSet", self, index, value);
}

// Get pointer to existing values, const
const float *
EndfCompatibleFloatsGetArrayConst(ConstHandle2ConstEndfCompatible self)
{
   return detail::vectorGet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsGetArrayConst", self);
}

// Get pointer to existing values, non-const
float *
EndfCompatibleFloatsGetArray(ConstHandle2EndfCompatible self)
{
   return detail::vectorGet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsGetArray", self);
}

// Set completely new values and size
void
EndfCompatibleFloatsSetArray(ConstHandle2EndfCompatible self, const float *const values, const size_t size)
{
   return detail::vectorSet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsSetArray", self, size, values);
}

// ------------------------
// double
// ------------------------

// Clear
void
EndfCompatibleDoublesClear(ConstHandle2EndfCompatible self)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"DoublesClear", self);
}

// Get size
size_t
EndfCompatibleDoublesSize(ConstHandle2ConstEndfCompatible self)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"DoublesSize", self);
}

// Get value
// By index \in [0,size)
double
EndfCompatibleDoublesGet(ConstHandle2ConstEndfCompatible self, const size_t index)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGet", self, index);
}

// Set value
// By index \in [0,size)
void
EndfCompatibleDoublesSet(ConstHandle2EndfCompatible self, const size_t index, const double value)
{
   detail::vectorSet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesSet", self, index, value);
}

// Get pointer to existing values, const
const double *
EndfCompatibleDoublesGetArrayConst(ConstHandle2ConstEndfCompatible self)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGetArrayConst", self);
}

// Get pointer to existing values, non-const
double *
EndfCompatibleDoublesGetArray(ConstHandle2EndfCompatible self)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGetArray", self);
}

// Set completely new values and size
void
EndfCompatibleDoublesSetArray(ConstHandle2EndfCompatible self, const double *const values, const size_t size)
{
   return detail::vectorSet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesSetArray", self, size, values);
}


// -----------------------------------------------------------------------------
// Metadatum: encoding
// -----------------------------------------------------------------------------

// Has
int
EndfCompatibleEncodingHas(ConstHandle2ConstEndfCompatible self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EncodingHas", self, extract::encoding);
}

// Get
// Returns by value
XMLName
EndfCompatibleEncodingGet(ConstHandle2ConstEndfCompatible self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"EncodingGet", self, extract::encoding);
}

// Set
void
EndfCompatibleEncodingSet(ConstHandle2EndfCompatible self, const XMLName encoding)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"EncodingSet", self, extract::encoding, encoding);
}


// -----------------------------------------------------------------------------
// Metadatum: markup
// -----------------------------------------------------------------------------

// Has
int
EndfCompatibleMarkupHas(ConstHandle2ConstEndfCompatible self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"MarkupHas", self, extract::markup);
}

// Get
// Returns by value
const char *
EndfCompatibleMarkupGet(ConstHandle2ConstEndfCompatible self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"MarkupGet", self, extract::markup);
}

// Set
void
EndfCompatibleMarkupSet(ConstHandle2EndfCompatible self, const char *const markup)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"MarkupSet", self, extract::markup, markup);
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
EndfCompatibleLabelHas(ConstHandle2ConstEndfCompatible self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
XMLName
EndfCompatibleLabelGet(ConstHandle2ConstEndfCompatible self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
EndfCompatibleLabelSet(ConstHandle2EndfCompatible self, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/documentation/EndfCompatible/src/custom.cpp"
