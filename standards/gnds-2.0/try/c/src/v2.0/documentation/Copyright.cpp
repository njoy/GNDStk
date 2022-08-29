
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/documentation/Copyright.hpp"
#include "Copyright.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = CopyrightClass;
using CPP = multigroup::Copyright;

static const std::string CLASSNAME = "Copyright";

namespace extract {
   static auto encoding = [](auto &obj) { return &obj.encoding; };
   static auto markup = [](auto &obj) { return &obj.markup; };
   static auto label = [](auto &obj) { return &obj.label; };
   static auto href = [](auto &obj) { return &obj.href; };
}


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstCopyright
CopyrightDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Copyright
CopyrightDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstCopyright
CopyrightCreateConst(
   const XMLName encoding,
   const char *const markup,
   const XMLName label,
   const UTF8Text href
) {
   ConstHandle2Copyright handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      encoding,
      markup,
      label,
      href
   );
   return handle;
}

// Create, general
Handle2Copyright
CopyrightCreate(
   const XMLName encoding,
   const char *const markup,
   const XMLName label,
   const UTF8Text href
) {
   ConstHandle2Copyright handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      encoding,
      markup,
      label,
      href
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
CopyrightAssign(ConstHandle2Copyright This, ConstHandle2ConstCopyright from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
CopyrightDelete(ConstHandle2ConstCopyright This)
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
CopyrightRead(ConstHandle2Copyright This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
CopyrightWrite(ConstHandle2ConstCopyright This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
CopyrightPrint(ConstHandle2ConstCopyright This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
CopyrightPrintXML(ConstHandle2ConstCopyright This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
CopyrightPrintJSON(ConstHandle2ConstCopyright This)
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
CopyrightIntsClear(ConstHandle2Copyright This)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"IntsClear", This);
}

// Get size
size_t
CopyrightIntsSize(ConstHandle2ConstCopyright This)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"IntsSize", This);
}

// Get value
// By index \in [0,size)
int
CopyrightIntsGet(ConstHandle2ConstCopyright This, const size_t index)
{
   return detail::vectorGet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsGet", This, index);
}

// Set value
// By index \in [0,size)
void
CopyrightIntsSet(ConstHandle2Copyright This, const size_t index, const int value)
{
   detail::vectorSet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsSet", This, index, value);
}

// Get pointer to existing values, const
const int *
CopyrightIntsGetArrayConst(ConstHandle2ConstCopyright This)
{
   return detail::vectorGet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsGetArrayConst", This);
}

// Get pointer to existing values, non-const
int *
CopyrightIntsGetArray(ConstHandle2Copyright This)
{
   return detail::vectorGet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsGetArray", This);
}

// Set completely new values and size
void
CopyrightIntsSetArray(ConstHandle2Copyright This, const int *const values, const size_t size)
{
   return detail::vectorSet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsSetArray", This, size, values);
}

// ------------------------
// unsigned
// ------------------------

// Clear
void
CopyrightUnsignedsClear(ConstHandle2Copyright This)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"UnsignedsClear", This);
}

// Get size
size_t
CopyrightUnsignedsSize(ConstHandle2ConstCopyright This)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"UnsignedsSize", This);
}

// Get value
// By index \in [0,size)
unsigned
CopyrightUnsignedsGet(ConstHandle2ConstCopyright This, const size_t index)
{
   return detail::vectorGet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsGet", This, index);
}

// Set value
// By index \in [0,size)
void
CopyrightUnsignedsSet(ConstHandle2Copyright This, const size_t index, const unsigned value)
{
   detail::vectorSet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsSet", This, index, value);
}

// Get pointer to existing values, const
const unsigned *
CopyrightUnsignedsGetArrayConst(ConstHandle2ConstCopyright This)
{
   return detail::vectorGet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsGetArrayConst", This);
}

// Get pointer to existing values, non-const
unsigned *
CopyrightUnsignedsGetArray(ConstHandle2Copyright This)
{
   return detail::vectorGet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsGetArray", This);
}

// Set completely new values and size
void
CopyrightUnsignedsSetArray(ConstHandle2Copyright This, const unsigned *const values, const size_t size)
{
   return detail::vectorSet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsSetArray", This, size, values);
}

// ------------------------
// float
// ------------------------

// Clear
void
CopyrightFloatsClear(ConstHandle2Copyright This)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"FloatsClear", This);
}

// Get size
size_t
CopyrightFloatsSize(ConstHandle2ConstCopyright This)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"FloatsSize", This);
}

// Get value
// By index \in [0,size)
float
CopyrightFloatsGet(ConstHandle2ConstCopyright This, const size_t index)
{
   return detail::vectorGet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsGet", This, index);
}

// Set value
// By index \in [0,size)
void
CopyrightFloatsSet(ConstHandle2Copyright This, const size_t index, const float value)
{
   detail::vectorSet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsSet", This, index, value);
}

// Get pointer to existing values, const
const float *
CopyrightFloatsGetArrayConst(ConstHandle2ConstCopyright This)
{
   return detail::vectorGet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsGetArrayConst", This);
}

// Get pointer to existing values, non-const
float *
CopyrightFloatsGetArray(ConstHandle2Copyright This)
{
   return detail::vectorGet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsGetArray", This);
}

// Set completely new values and size
void
CopyrightFloatsSetArray(ConstHandle2Copyright This, const float *const values, const size_t size)
{
   return detail::vectorSet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsSetArray", This, size, values);
}

// ------------------------
// double
// ------------------------

// Clear
void
CopyrightDoublesClear(ConstHandle2Copyright This)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"DoublesClear", This);
}

// Get size
size_t
CopyrightDoublesSize(ConstHandle2ConstCopyright This)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"DoublesSize", This);
}

// Get value
// By index \in [0,size)
double
CopyrightDoublesGet(ConstHandle2ConstCopyright This, const size_t index)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGet", This, index);
}

// Set value
// By index \in [0,size)
void
CopyrightDoublesSet(ConstHandle2Copyright This, const size_t index, const double value)
{
   detail::vectorSet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesSet", This, index, value);
}

// Get pointer to existing values, const
const double *
CopyrightDoublesGetArrayConst(ConstHandle2ConstCopyright This)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGetArrayConst", This);
}

// Get pointer to existing values, non-const
double *
CopyrightDoublesGetArray(ConstHandle2Copyright This)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGetArray", This);
}

// Set completely new values and size
void
CopyrightDoublesSetArray(ConstHandle2Copyright This, const double *const values, const size_t size)
{
   return detail::vectorSet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesSetArray", This, size, values);
}


// -----------------------------------------------------------------------------
// Metadatum: encoding
// -----------------------------------------------------------------------------

// Has
int
CopyrightEncodingHas(ConstHandle2ConstCopyright This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EncodingHas", This, extract::encoding);
}

// Get
// Returns by value
XMLName
CopyrightEncodingGet(ConstHandle2ConstCopyright This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"EncodingGet", This, extract::encoding);
}

// Set
void
CopyrightEncodingSet(ConstHandle2Copyright This, const XMLName encoding)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"EncodingSet", This, extract::encoding, encoding);
}


// -----------------------------------------------------------------------------
// Metadatum: markup
// -----------------------------------------------------------------------------

// Has
int
CopyrightMarkupHas(ConstHandle2ConstCopyright This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"MarkupHas", This, extract::markup);
}

// Get
// Returns by value
const char *
CopyrightMarkupGet(ConstHandle2ConstCopyright This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"MarkupGet", This, extract::markup);
}

// Set
void
CopyrightMarkupSet(ConstHandle2Copyright This, const char *const markup)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"MarkupSet", This, extract::markup, markup);
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
CopyrightLabelHas(ConstHandle2ConstCopyright This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
CopyrightLabelGet(ConstHandle2ConstCopyright This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
CopyrightLabelSet(ConstHandle2Copyright This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// Has
int
CopyrightHrefHas(ConstHandle2ConstCopyright This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"HrefHas", This, extract::href);
}

// Get
// Returns by value
UTF8Text
CopyrightHrefGet(ConstHandle2ConstCopyright This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"HrefGet", This, extract::href);
}

// Set
void
CopyrightHrefSet(ConstHandle2Copyright This, const UTF8Text href)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"HrefSet", This, extract::href, href);
}
