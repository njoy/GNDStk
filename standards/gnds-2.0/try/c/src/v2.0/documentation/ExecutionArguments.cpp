
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/documentation/ExecutionArguments.hpp"
#include "ExecutionArguments.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = ExecutionArgumentsClass;
using CPP = multigroup::ExecutionArguments;

static const std::string CLASSNAME = "ExecutionArguments";

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
Handle2ConstExecutionArguments
ExecutionArgumentsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2ExecutionArguments
ExecutionArgumentsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstExecutionArguments
ExecutionArgumentsCreateConst(
   const XMLName encoding,
   const char *const markup,
   const XMLName label
) {
   ConstHandle2ExecutionArguments handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      encoding,
      markup,
      label
   );
   return handle;
}

// Create, general
Handle2ExecutionArguments
ExecutionArgumentsCreate(
   const XMLName encoding,
   const char *const markup,
   const XMLName label
) {
   ConstHandle2ExecutionArguments handle = detail::createHandle<CPP,C>(
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
ExecutionArgumentsAssign(ConstHandle2ExecutionArguments This, ConstHandle2ConstExecutionArguments from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ExecutionArgumentsDelete(ConstHandle2ConstExecutionArguments This)
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
ExecutionArgumentsRead(ConstHandle2ExecutionArguments This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ExecutionArgumentsWrite(ConstHandle2ConstExecutionArguments This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
ExecutionArgumentsPrint(ConstHandle2ConstExecutionArguments This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
ExecutionArgumentsPrintXML(ConstHandle2ConstExecutionArguments This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
ExecutionArgumentsPrintJSON(ConstHandle2ConstExecutionArguments This)
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
ExecutionArgumentsIntsClear(ConstHandle2ExecutionArguments This)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"IntsClear", This);
}

// Get size
size_t
ExecutionArgumentsIntsSize(ConstHandle2ConstExecutionArguments This)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"IntsSize", This);
}

// Get value
// By index \in [0,size)
int
ExecutionArgumentsIntsGet(ConstHandle2ConstExecutionArguments This, const size_t index)
{
   return detail::vectorGet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsGet", This, index);
}

// Set value
// By index \in [0,size)
void
ExecutionArgumentsIntsSet(ConstHandle2ExecutionArguments This, const size_t index, const int value)
{
   detail::vectorSet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsSet", This, index, value);
}

// Get pointer to existing values, const
const int *
ExecutionArgumentsIntsGetArrayConst(ConstHandle2ConstExecutionArguments This)
{
   return detail::vectorGet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsGetArrayConst", This);
}

// Get pointer to existing values, non-const
int *
ExecutionArgumentsIntsGetArray(ConstHandle2ExecutionArguments This)
{
   return detail::vectorGet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsGetArray", This);
}

// Set completely new values and size
void
ExecutionArgumentsIntsSetArray(ConstHandle2ExecutionArguments This, const int *const values, const size_t size)
{
   return detail::vectorSet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsSetArray", This, size, values);
}

// ------------------------
// unsigned
// ------------------------

// Clear
void
ExecutionArgumentsUnsignedsClear(ConstHandle2ExecutionArguments This)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"UnsignedsClear", This);
}

// Get size
size_t
ExecutionArgumentsUnsignedsSize(ConstHandle2ConstExecutionArguments This)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"UnsignedsSize", This);
}

// Get value
// By index \in [0,size)
unsigned
ExecutionArgumentsUnsignedsGet(ConstHandle2ConstExecutionArguments This, const size_t index)
{
   return detail::vectorGet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsGet", This, index);
}

// Set value
// By index \in [0,size)
void
ExecutionArgumentsUnsignedsSet(ConstHandle2ExecutionArguments This, const size_t index, const unsigned value)
{
   detail::vectorSet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsSet", This, index, value);
}

// Get pointer to existing values, const
const unsigned *
ExecutionArgumentsUnsignedsGetArrayConst(ConstHandle2ConstExecutionArguments This)
{
   return detail::vectorGet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsGetArrayConst", This);
}

// Get pointer to existing values, non-const
unsigned *
ExecutionArgumentsUnsignedsGetArray(ConstHandle2ExecutionArguments This)
{
   return detail::vectorGet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsGetArray", This);
}

// Set completely new values and size
void
ExecutionArgumentsUnsignedsSetArray(ConstHandle2ExecutionArguments This, const unsigned *const values, const size_t size)
{
   return detail::vectorSet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsSetArray", This, size, values);
}

// ------------------------
// float
// ------------------------

// Clear
void
ExecutionArgumentsFloatsClear(ConstHandle2ExecutionArguments This)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"FloatsClear", This);
}

// Get size
size_t
ExecutionArgumentsFloatsSize(ConstHandle2ConstExecutionArguments This)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"FloatsSize", This);
}

// Get value
// By index \in [0,size)
float
ExecutionArgumentsFloatsGet(ConstHandle2ConstExecutionArguments This, const size_t index)
{
   return detail::vectorGet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsGet", This, index);
}

// Set value
// By index \in [0,size)
void
ExecutionArgumentsFloatsSet(ConstHandle2ExecutionArguments This, const size_t index, const float value)
{
   detail::vectorSet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsSet", This, index, value);
}

// Get pointer to existing values, const
const float *
ExecutionArgumentsFloatsGetArrayConst(ConstHandle2ConstExecutionArguments This)
{
   return detail::vectorGet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsGetArrayConst", This);
}

// Get pointer to existing values, non-const
float *
ExecutionArgumentsFloatsGetArray(ConstHandle2ExecutionArguments This)
{
   return detail::vectorGet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsGetArray", This);
}

// Set completely new values and size
void
ExecutionArgumentsFloatsSetArray(ConstHandle2ExecutionArguments This, const float *const values, const size_t size)
{
   return detail::vectorSet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsSetArray", This, size, values);
}

// ------------------------
// double
// ------------------------

// Clear
void
ExecutionArgumentsDoublesClear(ConstHandle2ExecutionArguments This)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"DoublesClear", This);
}

// Get size
size_t
ExecutionArgumentsDoublesSize(ConstHandle2ConstExecutionArguments This)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"DoublesSize", This);
}

// Get value
// By index \in [0,size)
double
ExecutionArgumentsDoublesGet(ConstHandle2ConstExecutionArguments This, const size_t index)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGet", This, index);
}

// Set value
// By index \in [0,size)
void
ExecutionArgumentsDoublesSet(ConstHandle2ExecutionArguments This, const size_t index, const double value)
{
   detail::vectorSet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesSet", This, index, value);
}

// Get pointer to existing values, const
const double *
ExecutionArgumentsDoublesGetArrayConst(ConstHandle2ConstExecutionArguments This)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGetArrayConst", This);
}

// Get pointer to existing values, non-const
double *
ExecutionArgumentsDoublesGetArray(ConstHandle2ExecutionArguments This)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGetArray", This);
}

// Set completely new values and size
void
ExecutionArgumentsDoublesSetArray(ConstHandle2ExecutionArguments This, const double *const values, const size_t size)
{
   return detail::vectorSet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesSetArray", This, size, values);
}


// -----------------------------------------------------------------------------
// Metadatum: encoding
// -----------------------------------------------------------------------------

// Has
int
ExecutionArgumentsEncodingHas(ConstHandle2ConstExecutionArguments This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EncodingHas", This, extract::encoding);
}

// Get
// Returns by value
XMLName
ExecutionArgumentsEncodingGet(ConstHandle2ConstExecutionArguments This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"EncodingGet", This, extract::encoding);
}

// Set
void
ExecutionArgumentsEncodingSet(ConstHandle2ExecutionArguments This, const XMLName encoding)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"EncodingSet", This, extract::encoding, encoding);
}


// -----------------------------------------------------------------------------
// Metadatum: markup
// -----------------------------------------------------------------------------

// Has
int
ExecutionArgumentsMarkupHas(ConstHandle2ConstExecutionArguments This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"MarkupHas", This, extract::markup);
}

// Get
// Returns by value
const char *
ExecutionArgumentsMarkupGet(ConstHandle2ConstExecutionArguments This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"MarkupGet", This, extract::markup);
}

// Set
void
ExecutionArgumentsMarkupSet(ConstHandle2ExecutionArguments This, const char *const markup)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"MarkupSet", This, extract::markup, markup);
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
ExecutionArgumentsLabelHas(ConstHandle2ConstExecutionArguments This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
ExecutionArgumentsLabelGet(ConstHandle2ConstExecutionArguments This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
ExecutionArgumentsLabelSet(ConstHandle2ExecutionArguments This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}