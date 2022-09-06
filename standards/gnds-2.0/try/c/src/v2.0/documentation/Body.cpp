
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/documentation/Body.hpp"
#include "Body.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = BodyClass;
using CPP = multigroup::Body;

static const std::string CLASSNAME = "Body";

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
Handle2ConstBody
BodyDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Body
BodyDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstBody
BodyCreateConst(
   const XMLName encoding,
   const char *const markup,
   const XMLName label
) {
   ConstHandle2Body handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      encoding,
      markup,
      label
   );
   return handle;
}

// Create, general
Handle2Body
BodyCreate(
   const XMLName encoding,
   const char *const markup,
   const XMLName label
) {
   ConstHandle2Body handle = detail::createHandle<CPP,C>(
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
BodyAssign(ConstHandle2Body This, ConstHandle2ConstBody from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
BodyDelete(ConstHandle2ConstBody This)
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
BodyRead(ConstHandle2Body This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
BodyWrite(ConstHandle2ConstBody This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
BodyPrint(ConstHandle2ConstBody This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
BodyPrintXML(ConstHandle2ConstBody This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
BodyPrintJSON(ConstHandle2ConstBody This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Data vector
// -----------------------------------------------------------------------------

// ------------------------
// int
// ------------------------

// Clear
void
BodyIntsClear(ConstHandle2Body This)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"IntsClear", This);
}

// Get size
size_t
BodyIntsSize(ConstHandle2ConstBody This)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"IntsSize", This);
}

// Get value
// By index \in [0,size)
int
BodyIntsGet(ConstHandle2ConstBody This, const size_t index)
{
   return detail::vectorGet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsGet", This, index);
}

// Set value
// By index \in [0,size)
void
BodyIntsSet(ConstHandle2Body This, const size_t index, const int value)
{
   detail::vectorSet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsSet", This, index, value);
}

// Get pointer to existing values, const
const int *
BodyIntsGetArrayConst(ConstHandle2ConstBody This)
{
   return detail::vectorGet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsGetArrayConst", This);
}

// Get pointer to existing values, non-const
int *
BodyIntsGetArray(ConstHandle2Body This)
{
   return detail::vectorGet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsGetArray", This);
}

// Set completely new values and size
void
BodyIntsSetArray(ConstHandle2Body This, const int *const values, const size_t size)
{
   return detail::vectorSet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsSetArray", This, size, values);
}

// ------------------------
// unsigned
// ------------------------

// Clear
void
BodyUnsignedsClear(ConstHandle2Body This)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"UnsignedsClear", This);
}

// Get size
size_t
BodyUnsignedsSize(ConstHandle2ConstBody This)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"UnsignedsSize", This);
}

// Get value
// By index \in [0,size)
unsigned
BodyUnsignedsGet(ConstHandle2ConstBody This, const size_t index)
{
   return detail::vectorGet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsGet", This, index);
}

// Set value
// By index \in [0,size)
void
BodyUnsignedsSet(ConstHandle2Body This, const size_t index, const unsigned value)
{
   detail::vectorSet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsSet", This, index, value);
}

// Get pointer to existing values, const
const unsigned *
BodyUnsignedsGetArrayConst(ConstHandle2ConstBody This)
{
   return detail::vectorGet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsGetArrayConst", This);
}

// Get pointer to existing values, non-const
unsigned *
BodyUnsignedsGetArray(ConstHandle2Body This)
{
   return detail::vectorGet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsGetArray", This);
}

// Set completely new values and size
void
BodyUnsignedsSetArray(ConstHandle2Body This, const unsigned *const values, const size_t size)
{
   return detail::vectorSet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsSetArray", This, size, values);
}

// ------------------------
// float
// ------------------------

// Clear
void
BodyFloatsClear(ConstHandle2Body This)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"FloatsClear", This);
}

// Get size
size_t
BodyFloatsSize(ConstHandle2ConstBody This)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"FloatsSize", This);
}

// Get value
// By index \in [0,size)
float
BodyFloatsGet(ConstHandle2ConstBody This, const size_t index)
{
   return detail::vectorGet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsGet", This, index);
}

// Set value
// By index \in [0,size)
void
BodyFloatsSet(ConstHandle2Body This, const size_t index, const float value)
{
   detail::vectorSet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsSet", This, index, value);
}

// Get pointer to existing values, const
const float *
BodyFloatsGetArrayConst(ConstHandle2ConstBody This)
{
   return detail::vectorGet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsGetArrayConst", This);
}

// Get pointer to existing values, non-const
float *
BodyFloatsGetArray(ConstHandle2Body This)
{
   return detail::vectorGet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsGetArray", This);
}

// Set completely new values and size
void
BodyFloatsSetArray(ConstHandle2Body This, const float *const values, const size_t size)
{
   return detail::vectorSet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsSetArray", This, size, values);
}

// ------------------------
// double
// ------------------------

// Clear
void
BodyDoublesClear(ConstHandle2Body This)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"DoublesClear", This);
}

// Get size
size_t
BodyDoublesSize(ConstHandle2ConstBody This)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"DoublesSize", This);
}

// Get value
// By index \in [0,size)
double
BodyDoublesGet(ConstHandle2ConstBody This, const size_t index)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGet", This, index);
}

// Set value
// By index \in [0,size)
void
BodyDoublesSet(ConstHandle2Body This, const size_t index, const double value)
{
   detail::vectorSet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesSet", This, index, value);
}

// Get pointer to existing values, const
const double *
BodyDoublesGetArrayConst(ConstHandle2ConstBody This)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGetArrayConst", This);
}

// Get pointer to existing values, non-const
double *
BodyDoublesGetArray(ConstHandle2Body This)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGetArray", This);
}

// Set completely new values and size
void
BodyDoublesSetArray(ConstHandle2Body This, const double *const values, const size_t size)
{
   return detail::vectorSet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesSetArray", This, size, values);
}


// -----------------------------------------------------------------------------
// Metadatum: encoding
// -----------------------------------------------------------------------------

// Has
int
BodyEncodingHas(ConstHandle2ConstBody This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EncodingHas", This, extract::encoding);
}

// Get
// Returns by value
XMLName
BodyEncodingGet(ConstHandle2ConstBody This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"EncodingGet", This, extract::encoding);
}

// Set
void
BodyEncodingSet(ConstHandle2Body This, const XMLName encoding)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"EncodingSet", This, extract::encoding, encoding);
}


// -----------------------------------------------------------------------------
// Metadatum: markup
// -----------------------------------------------------------------------------

// Has
int
BodyMarkupHas(ConstHandle2ConstBody This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"MarkupHas", This, extract::markup);
}

// Get
// Returns by value
const char *
BodyMarkupGet(ConstHandle2ConstBody This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"MarkupGet", This, extract::markup);
}

// Set
void
BodyMarkupSet(ConstHandle2Body This, const char *const markup)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"MarkupSet", This, extract::markup, markup);
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
BodyLabelHas(ConstHandle2ConstBody This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
BodyLabelGet(ConstHandle2ConstBody This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
BodyLabelSet(ConstHandle2Body This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}