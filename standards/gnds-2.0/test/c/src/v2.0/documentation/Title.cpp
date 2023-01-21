
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/documentation/Title.hpp"
#include "Title.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = TitleClass;
using CPP = multigroup::Title;

static const std::string CLASSNAME = "Title";

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
Handle2ConstTitle
TitleDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Title
TitleDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstTitle
TitleCreateConst(
   const XMLName encoding,
   const char *const markup,
   const XMLName label
) {
   ConstHandle2Title handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      encoding,
      markup,
      label
   );
   return handle;
}

// Create, general
Handle2Title
TitleCreate(
   const XMLName encoding,
   const char *const markup,
   const XMLName label
) {
   ConstHandle2Title handle = detail::createHandle<CPP,C>(
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
TitleAssign(ConstHandle2Title This, ConstHandle2ConstTitle from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
TitleDelete(ConstHandle2ConstTitle This)
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
TitleRead(ConstHandle2Title This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
TitleWrite(ConstHandle2ConstTitle This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
TitlePrint(ConstHandle2ConstTitle This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
TitlePrintXML(ConstHandle2ConstTitle This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
TitlePrintJSON(ConstHandle2ConstTitle This)
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
TitleIntsClear(ConstHandle2Title This)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"IntsClear", This);
}

// Get size
size_t
TitleIntsSize(ConstHandle2ConstTitle This)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"IntsSize", This);
}

// Get value
// By index \in [0,size)
int
TitleIntsGet(ConstHandle2ConstTitle This, const size_t index)
{
   return detail::vectorGet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsGet", This, index);
}

// Set value
// By index \in [0,size)
void
TitleIntsSet(ConstHandle2Title This, const size_t index, const int value)
{
   detail::vectorSet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsSet", This, index, value);
}

// Get pointer to existing values, const
const int *
TitleIntsGetArrayConst(ConstHandle2ConstTitle This)
{
   return detail::vectorGet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsGetArrayConst", This);
}

// Get pointer to existing values, non-const
int *
TitleIntsGetArray(ConstHandle2Title This)
{
   return detail::vectorGet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsGetArray", This);
}

// Set completely new values and size
void
TitleIntsSetArray(ConstHandle2Title This, const int *const values, const size_t size)
{
   return detail::vectorSet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsSetArray", This, size, values);
}

// ------------------------
// unsigned
// ------------------------

// Clear
void
TitleUnsignedsClear(ConstHandle2Title This)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"UnsignedsClear", This);
}

// Get size
size_t
TitleUnsignedsSize(ConstHandle2ConstTitle This)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"UnsignedsSize", This);
}

// Get value
// By index \in [0,size)
unsigned
TitleUnsignedsGet(ConstHandle2ConstTitle This, const size_t index)
{
   return detail::vectorGet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsGet", This, index);
}

// Set value
// By index \in [0,size)
void
TitleUnsignedsSet(ConstHandle2Title This, const size_t index, const unsigned value)
{
   detail::vectorSet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsSet", This, index, value);
}

// Get pointer to existing values, const
const unsigned *
TitleUnsignedsGetArrayConst(ConstHandle2ConstTitle This)
{
   return detail::vectorGet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsGetArrayConst", This);
}

// Get pointer to existing values, non-const
unsigned *
TitleUnsignedsGetArray(ConstHandle2Title This)
{
   return detail::vectorGet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsGetArray", This);
}

// Set completely new values and size
void
TitleUnsignedsSetArray(ConstHandle2Title This, const unsigned *const values, const size_t size)
{
   return detail::vectorSet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsSetArray", This, size, values);
}

// ------------------------
// float
// ------------------------

// Clear
void
TitleFloatsClear(ConstHandle2Title This)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"FloatsClear", This);
}

// Get size
size_t
TitleFloatsSize(ConstHandle2ConstTitle This)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"FloatsSize", This);
}

// Get value
// By index \in [0,size)
float
TitleFloatsGet(ConstHandle2ConstTitle This, const size_t index)
{
   return detail::vectorGet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsGet", This, index);
}

// Set value
// By index \in [0,size)
void
TitleFloatsSet(ConstHandle2Title This, const size_t index, const float value)
{
   detail::vectorSet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsSet", This, index, value);
}

// Get pointer to existing values, const
const float *
TitleFloatsGetArrayConst(ConstHandle2ConstTitle This)
{
   return detail::vectorGet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsGetArrayConst", This);
}

// Get pointer to existing values, non-const
float *
TitleFloatsGetArray(ConstHandle2Title This)
{
   return detail::vectorGet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsGetArray", This);
}

// Set completely new values and size
void
TitleFloatsSetArray(ConstHandle2Title This, const float *const values, const size_t size)
{
   return detail::vectorSet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsSetArray", This, size, values);
}

// ------------------------
// double
// ------------------------

// Clear
void
TitleDoublesClear(ConstHandle2Title This)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"DoublesClear", This);
}

// Get size
size_t
TitleDoublesSize(ConstHandle2ConstTitle This)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"DoublesSize", This);
}

// Get value
// By index \in [0,size)
double
TitleDoublesGet(ConstHandle2ConstTitle This, const size_t index)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGet", This, index);
}

// Set value
// By index \in [0,size)
void
TitleDoublesSet(ConstHandle2Title This, const size_t index, const double value)
{
   detail::vectorSet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesSet", This, index, value);
}

// Get pointer to existing values, const
const double *
TitleDoublesGetArrayConst(ConstHandle2ConstTitle This)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGetArrayConst", This);
}

// Get pointer to existing values, non-const
double *
TitleDoublesGetArray(ConstHandle2Title This)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGetArray", This);
}

// Set completely new values and size
void
TitleDoublesSetArray(ConstHandle2Title This, const double *const values, const size_t size)
{
   return detail::vectorSet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesSetArray", This, size, values);
}


// -----------------------------------------------------------------------------
// Metadatum: encoding
// -----------------------------------------------------------------------------

// Has
int
TitleEncodingHas(ConstHandle2ConstTitle This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EncodingHas", This, extract::encoding);
}

// Get
// Returns by value
XMLName
TitleEncodingGet(ConstHandle2ConstTitle This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"EncodingGet", This, extract::encoding);
}

// Set
void
TitleEncodingSet(ConstHandle2Title This, const XMLName encoding)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"EncodingSet", This, extract::encoding, encoding);
}


// -----------------------------------------------------------------------------
// Metadatum: markup
// -----------------------------------------------------------------------------

// Has
int
TitleMarkupHas(ConstHandle2ConstTitle This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"MarkupHas", This, extract::markup);
}

// Get
// Returns by value
const char *
TitleMarkupGet(ConstHandle2ConstTitle This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"MarkupGet", This, extract::markup);
}

// Set
void
TitleMarkupSet(ConstHandle2Title This, const char *const markup)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"MarkupSet", This, extract::markup, markup);
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
TitleLabelHas(ConstHandle2ConstTitle This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
TitleLabelGet(ConstHandle2ConstTitle This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
TitleLabelSet(ConstHandle2Title This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/documentation/Title/src/custom.cpp"
