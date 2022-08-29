
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/documentation/Abstract.hpp"
#include "Abstract.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = AbstractClass;
using CPP = multigroup::Abstract;

static const std::string CLASSNAME = "Abstract";

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
Handle2ConstAbstract
AbstractDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Abstract
AbstractDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstAbstract
AbstractCreateConst(
   const XMLName encoding,
   const char *const markup,
   const XMLName label
) {
   ConstHandle2Abstract handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      encoding,
      markup,
      label
   );
   return handle;
}

// Create, general
Handle2Abstract
AbstractCreate(
   const XMLName encoding,
   const char *const markup,
   const XMLName label
) {
   ConstHandle2Abstract handle = detail::createHandle<CPP,C>(
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
AbstractAssign(ConstHandle2Abstract This, ConstHandle2ConstAbstract from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
AbstractDelete(ConstHandle2ConstAbstract This)
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
AbstractRead(ConstHandle2Abstract This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
AbstractWrite(ConstHandle2ConstAbstract This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
AbstractPrint(ConstHandle2ConstAbstract This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
AbstractPrintXML(ConstHandle2ConstAbstract This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
AbstractPrintJSON(ConstHandle2ConstAbstract This)
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
AbstractIntsClear(ConstHandle2Abstract This)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"IntsClear", This);
}

// Get size
size_t
AbstractIntsSize(ConstHandle2ConstAbstract This)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"IntsSize", This);
}

// Get value
// By index \in [0,size)
int
AbstractIntsGet(ConstHandle2ConstAbstract This, const size_t index)
{
   return detail::vectorGet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsGet", This, index);
}

// Set value
// By index \in [0,size)
void
AbstractIntsSet(ConstHandle2Abstract This, const size_t index, const int value)
{
   detail::vectorSet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsSet", This, index, value);
}

// Get pointer to existing values, const
const int *
AbstractIntsGetArrayConst(ConstHandle2ConstAbstract This)
{
   return detail::vectorGet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsGetArrayConst", This);
}

// Get pointer to existing values, non-const
int *
AbstractIntsGetArray(ConstHandle2Abstract This)
{
   return detail::vectorGet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsGetArray", This);
}

// Set completely new values and size
void
AbstractIntsSetArray(ConstHandle2Abstract This, const int *const values, const size_t size)
{
   return detail::vectorSet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsSetArray", This, size, values);
}

// ------------------------
// unsigned
// ------------------------

// Clear
void
AbstractUnsignedsClear(ConstHandle2Abstract This)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"UnsignedsClear", This);
}

// Get size
size_t
AbstractUnsignedsSize(ConstHandle2ConstAbstract This)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"UnsignedsSize", This);
}

// Get value
// By index \in [0,size)
unsigned
AbstractUnsignedsGet(ConstHandle2ConstAbstract This, const size_t index)
{
   return detail::vectorGet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsGet", This, index);
}

// Set value
// By index \in [0,size)
void
AbstractUnsignedsSet(ConstHandle2Abstract This, const size_t index, const unsigned value)
{
   detail::vectorSet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsSet", This, index, value);
}

// Get pointer to existing values, const
const unsigned *
AbstractUnsignedsGetArrayConst(ConstHandle2ConstAbstract This)
{
   return detail::vectorGet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsGetArrayConst", This);
}

// Get pointer to existing values, non-const
unsigned *
AbstractUnsignedsGetArray(ConstHandle2Abstract This)
{
   return detail::vectorGet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsGetArray", This);
}

// Set completely new values and size
void
AbstractUnsignedsSetArray(ConstHandle2Abstract This, const unsigned *const values, const size_t size)
{
   return detail::vectorSet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsSetArray", This, size, values);
}

// ------------------------
// float
// ------------------------

// Clear
void
AbstractFloatsClear(ConstHandle2Abstract This)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"FloatsClear", This);
}

// Get size
size_t
AbstractFloatsSize(ConstHandle2ConstAbstract This)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"FloatsSize", This);
}

// Get value
// By index \in [0,size)
float
AbstractFloatsGet(ConstHandle2ConstAbstract This, const size_t index)
{
   return detail::vectorGet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsGet", This, index);
}

// Set value
// By index \in [0,size)
void
AbstractFloatsSet(ConstHandle2Abstract This, const size_t index, const float value)
{
   detail::vectorSet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsSet", This, index, value);
}

// Get pointer to existing values, const
const float *
AbstractFloatsGetArrayConst(ConstHandle2ConstAbstract This)
{
   return detail::vectorGet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsGetArrayConst", This);
}

// Get pointer to existing values, non-const
float *
AbstractFloatsGetArray(ConstHandle2Abstract This)
{
   return detail::vectorGet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsGetArray", This);
}

// Set completely new values and size
void
AbstractFloatsSetArray(ConstHandle2Abstract This, const float *const values, const size_t size)
{
   return detail::vectorSet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsSetArray", This, size, values);
}

// ------------------------
// double
// ------------------------

// Clear
void
AbstractDoublesClear(ConstHandle2Abstract This)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"DoublesClear", This);
}

// Get size
size_t
AbstractDoublesSize(ConstHandle2ConstAbstract This)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"DoublesSize", This);
}

// Get value
// By index \in [0,size)
double
AbstractDoublesGet(ConstHandle2ConstAbstract This, const size_t index)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGet", This, index);
}

// Set value
// By index \in [0,size)
void
AbstractDoublesSet(ConstHandle2Abstract This, const size_t index, const double value)
{
   detail::vectorSet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesSet", This, index, value);
}

// Get pointer to existing values, const
const double *
AbstractDoublesGetArrayConst(ConstHandle2ConstAbstract This)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGetArrayConst", This);
}

// Get pointer to existing values, non-const
double *
AbstractDoublesGetArray(ConstHandle2Abstract This)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGetArray", This);
}

// Set completely new values and size
void
AbstractDoublesSetArray(ConstHandle2Abstract This, const double *const values, const size_t size)
{
   return detail::vectorSet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesSetArray", This, size, values);
}


// -----------------------------------------------------------------------------
// Metadatum: encoding
// -----------------------------------------------------------------------------

// Has
int
AbstractEncodingHas(ConstHandle2ConstAbstract This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EncodingHas", This, extract::encoding);
}

// Get
// Returns by value
XMLName
AbstractEncodingGet(ConstHandle2ConstAbstract This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"EncodingGet", This, extract::encoding);
}

// Set
void
AbstractEncodingSet(ConstHandle2Abstract This, const XMLName encoding)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"EncodingSet", This, extract::encoding, encoding);
}


// -----------------------------------------------------------------------------
// Metadatum: markup
// -----------------------------------------------------------------------------

// Has
int
AbstractMarkupHas(ConstHandle2ConstAbstract This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"MarkupHas", This, extract::markup);
}

// Get
// Returns by value
const char *
AbstractMarkupGet(ConstHandle2ConstAbstract This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"MarkupGet", This, extract::markup);
}

// Set
void
AbstractMarkupSet(ConstHandle2Abstract This, const char *const markup)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"MarkupSet", This, extract::markup, markup);
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
AbstractLabelHas(ConstHandle2ConstAbstract This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
AbstractLabelGet(ConstHandle2ConstAbstract This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
AbstractLabelSet(ConstHandle2Abstract This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}
