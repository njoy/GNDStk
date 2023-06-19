
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2.0/documentation/CovarianceScript.hpp"
#include "CovarianceScript.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = CovarianceScriptClass;
using CPP = multigroup::CovarianceScript;

static const std::string CLASSNAME = "CovarianceScript";

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
Handle2ConstCovarianceScript
CovarianceScriptDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2CovarianceScript
CovarianceScriptDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstCovarianceScript
CovarianceScriptCreateConst(
   const XMLName encoding,
   const char *const markup,
   const XMLName label
) {
   ConstHandle2CovarianceScript handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      encoding,
      markup,
      label
   );
   return handle;
}

// Create, general
Handle2CovarianceScript
CovarianceScriptCreate(
   const XMLName encoding,
   const char *const markup,
   const XMLName label
) {
   ConstHandle2CovarianceScript handle = detail::createHandle<CPP,C>(
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
CovarianceScriptAssign(ConstHandle2CovarianceScript self, ConstHandle2ConstCovarianceScript from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
CovarianceScriptDelete(ConstHandle2ConstCovarianceScript self)
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
CovarianceScriptRead(ConstHandle2CovarianceScript self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
CovarianceScriptWrite(ConstHandle2ConstCovarianceScript self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
CovarianceScriptPrint(ConstHandle2ConstCovarianceScript self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
CovarianceScriptPrintXML(ConstHandle2ConstCovarianceScript self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
CovarianceScriptPrintJSON(ConstHandle2ConstCovarianceScript self)
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
CovarianceScriptIntsClear(ConstHandle2CovarianceScript self)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"IntsClear", self);
}

// Get size
size_t
CovarianceScriptIntsSize(ConstHandle2ConstCovarianceScript self)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"IntsSize", self);
}

// Get value
// By index \in [0,size)
int
CovarianceScriptIntsGet(ConstHandle2ConstCovarianceScript self, const size_t index)
{
   return detail::vectorGet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsGet", self, index);
}

// Set value
// By index \in [0,size)
void
CovarianceScriptIntsSet(ConstHandle2CovarianceScript self, const size_t index, const int value)
{
   detail::vectorSet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsSet", self, index, value);
}

// Get pointer to existing values, const
const int *
CovarianceScriptIntsGetArrayConst(ConstHandle2ConstCovarianceScript self)
{
   return detail::vectorGet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsGetArrayConst", self);
}

// Get pointer to existing values, non-const
int *
CovarianceScriptIntsGetArray(ConstHandle2CovarianceScript self)
{
   return detail::vectorGet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsGetArray", self);
}

// Set completely new values and size
void
CovarianceScriptIntsSetArray(ConstHandle2CovarianceScript self, const int *const values, const size_t size)
{
   return detail::vectorSet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsSetArray", self, size, values);
}

// ------------------------
// unsigned
// ------------------------

// Clear
void
CovarianceScriptUnsignedsClear(ConstHandle2CovarianceScript self)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"UnsignedsClear", self);
}

// Get size
size_t
CovarianceScriptUnsignedsSize(ConstHandle2ConstCovarianceScript self)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"UnsignedsSize", self);
}

// Get value
// By index \in [0,size)
unsigned
CovarianceScriptUnsignedsGet(ConstHandle2ConstCovarianceScript self, const size_t index)
{
   return detail::vectorGet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsGet", self, index);
}

// Set value
// By index \in [0,size)
void
CovarianceScriptUnsignedsSet(ConstHandle2CovarianceScript self, const size_t index, const unsigned value)
{
   detail::vectorSet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsSet", self, index, value);
}

// Get pointer to existing values, const
const unsigned *
CovarianceScriptUnsignedsGetArrayConst(ConstHandle2ConstCovarianceScript self)
{
   return detail::vectorGet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsGetArrayConst", self);
}

// Get pointer to existing values, non-const
unsigned *
CovarianceScriptUnsignedsGetArray(ConstHandle2CovarianceScript self)
{
   return detail::vectorGet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsGetArray", self);
}

// Set completely new values and size
void
CovarianceScriptUnsignedsSetArray(ConstHandle2CovarianceScript self, const unsigned *const values, const size_t size)
{
   return detail::vectorSet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsSetArray", self, size, values);
}

// ------------------------
// float
// ------------------------

// Clear
void
CovarianceScriptFloatsClear(ConstHandle2CovarianceScript self)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"FloatsClear", self);
}

// Get size
size_t
CovarianceScriptFloatsSize(ConstHandle2ConstCovarianceScript self)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"FloatsSize", self);
}

// Get value
// By index \in [0,size)
float
CovarianceScriptFloatsGet(ConstHandle2ConstCovarianceScript self, const size_t index)
{
   return detail::vectorGet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsGet", self, index);
}

// Set value
// By index \in [0,size)
void
CovarianceScriptFloatsSet(ConstHandle2CovarianceScript self, const size_t index, const float value)
{
   detail::vectorSet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsSet", self, index, value);
}

// Get pointer to existing values, const
const float *
CovarianceScriptFloatsGetArrayConst(ConstHandle2ConstCovarianceScript self)
{
   return detail::vectorGet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsGetArrayConst", self);
}

// Get pointer to existing values, non-const
float *
CovarianceScriptFloatsGetArray(ConstHandle2CovarianceScript self)
{
   return detail::vectorGet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsGetArray", self);
}

// Set completely new values and size
void
CovarianceScriptFloatsSetArray(ConstHandle2CovarianceScript self, const float *const values, const size_t size)
{
   return detail::vectorSet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsSetArray", self, size, values);
}

// ------------------------
// double
// ------------------------

// Clear
void
CovarianceScriptDoublesClear(ConstHandle2CovarianceScript self)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"DoublesClear", self);
}

// Get size
size_t
CovarianceScriptDoublesSize(ConstHandle2ConstCovarianceScript self)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"DoublesSize", self);
}

// Get value
// By index \in [0,size)
double
CovarianceScriptDoublesGet(ConstHandle2ConstCovarianceScript self, const size_t index)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGet", self, index);
}

// Set value
// By index \in [0,size)
void
CovarianceScriptDoublesSet(ConstHandle2CovarianceScript self, const size_t index, const double value)
{
   detail::vectorSet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesSet", self, index, value);
}

// Get pointer to existing values, const
const double *
CovarianceScriptDoublesGetArrayConst(ConstHandle2ConstCovarianceScript self)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGetArrayConst", self);
}

// Get pointer to existing values, non-const
double *
CovarianceScriptDoublesGetArray(ConstHandle2CovarianceScript self)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGetArray", self);
}

// Set completely new values and size
void
CovarianceScriptDoublesSetArray(ConstHandle2CovarianceScript self, const double *const values, const size_t size)
{
   return detail::vectorSet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesSetArray", self, size, values);
}


// -----------------------------------------------------------------------------
// Metadatum: encoding
// -----------------------------------------------------------------------------

// Has
int
CovarianceScriptEncodingHas(ConstHandle2ConstCovarianceScript self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EncodingHas", self, extract::encoding);
}

// Get
// Returns by value
XMLName
CovarianceScriptEncodingGet(ConstHandle2ConstCovarianceScript self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"EncodingGet", self, extract::encoding);
}

// Set
void
CovarianceScriptEncodingSet(ConstHandle2CovarianceScript self, const XMLName encoding)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"EncodingSet", self, extract::encoding, encoding);
}


// -----------------------------------------------------------------------------
// Metadatum: markup
// -----------------------------------------------------------------------------

// Has
int
CovarianceScriptMarkupHas(ConstHandle2ConstCovarianceScript self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"MarkupHas", self, extract::markup);
}

// Get
// Returns by value
const char *
CovarianceScriptMarkupGet(ConstHandle2ConstCovarianceScript self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"MarkupGet", self, extract::markup);
}

// Set
void
CovarianceScriptMarkupSet(ConstHandle2CovarianceScript self, const char *const markup)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"MarkupSet", self, extract::markup, markup);
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
CovarianceScriptLabelHas(ConstHandle2ConstCovarianceScript self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
XMLName
CovarianceScriptLabelGet(ConstHandle2ConstCovarianceScript self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
CovarianceScriptLabelSet(ConstHandle2CovarianceScript self, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/documentation/CovarianceScript/src/custom.cpp"
