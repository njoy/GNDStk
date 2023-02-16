
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/documentation/Version.hpp"
#include "Version.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = VersionClass;
using CPP = multigroup::Version;

static const std::string CLASSNAME = "Version";

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
Handle2ConstVersion
VersionDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Version
VersionDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstVersion
VersionCreateConst(
   const XMLName encoding,
   const char *const markup,
   const XMLName label
) {
   ConstHandle2Version handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      encoding,
      markup,
      label
   );
   return handle;
}

// Create, general
Handle2Version
VersionCreate(
   const XMLName encoding,
   const char *const markup,
   const XMLName label
) {
   ConstHandle2Version handle = detail::createHandle<CPP,C>(
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
VersionAssign(ConstHandle2Version self, ConstHandle2ConstVersion from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
VersionDelete(ConstHandle2ConstVersion self)
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
VersionRead(ConstHandle2Version self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
VersionWrite(ConstHandle2ConstVersion self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
VersionPrint(ConstHandle2ConstVersion self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
VersionPrintXML(ConstHandle2ConstVersion self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
VersionPrintJSON(ConstHandle2ConstVersion self)
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
VersionIntsClear(ConstHandle2Version self)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"IntsClear", self);
}

// Get size
size_t
VersionIntsSize(ConstHandle2ConstVersion self)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"IntsSize", self);
}

// Get value
// By index \in [0,size)
int
VersionIntsGet(ConstHandle2ConstVersion self, const size_t index)
{
   return detail::vectorGet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsGet", self, index);
}

// Set value
// By index \in [0,size)
void
VersionIntsSet(ConstHandle2Version self, const size_t index, const int value)
{
   detail::vectorSet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsSet", self, index, value);
}

// Get pointer to existing values, const
const int *
VersionIntsGetArrayConst(ConstHandle2ConstVersion self)
{
   return detail::vectorGet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsGetArrayConst", self);
}

// Get pointer to existing values, non-const
int *
VersionIntsGetArray(ConstHandle2Version self)
{
   return detail::vectorGet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsGetArray", self);
}

// Set completely new values and size
void
VersionIntsSetArray(ConstHandle2Version self, const int *const values, const size_t size)
{
   return detail::vectorSet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsSetArray", self, size, values);
}

// ------------------------
// unsigned
// ------------------------

// Clear
void
VersionUnsignedsClear(ConstHandle2Version self)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"UnsignedsClear", self);
}

// Get size
size_t
VersionUnsignedsSize(ConstHandle2ConstVersion self)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"UnsignedsSize", self);
}

// Get value
// By index \in [0,size)
unsigned
VersionUnsignedsGet(ConstHandle2ConstVersion self, const size_t index)
{
   return detail::vectorGet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsGet", self, index);
}

// Set value
// By index \in [0,size)
void
VersionUnsignedsSet(ConstHandle2Version self, const size_t index, const unsigned value)
{
   detail::vectorSet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsSet", self, index, value);
}

// Get pointer to existing values, const
const unsigned *
VersionUnsignedsGetArrayConst(ConstHandle2ConstVersion self)
{
   return detail::vectorGet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsGetArrayConst", self);
}

// Get pointer to existing values, non-const
unsigned *
VersionUnsignedsGetArray(ConstHandle2Version self)
{
   return detail::vectorGet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsGetArray", self);
}

// Set completely new values and size
void
VersionUnsignedsSetArray(ConstHandle2Version self, const unsigned *const values, const size_t size)
{
   return detail::vectorSet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsSetArray", self, size, values);
}

// ------------------------
// float
// ------------------------

// Clear
void
VersionFloatsClear(ConstHandle2Version self)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"FloatsClear", self);
}

// Get size
size_t
VersionFloatsSize(ConstHandle2ConstVersion self)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"FloatsSize", self);
}

// Get value
// By index \in [0,size)
float
VersionFloatsGet(ConstHandle2ConstVersion self, const size_t index)
{
   return detail::vectorGet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsGet", self, index);
}

// Set value
// By index \in [0,size)
void
VersionFloatsSet(ConstHandle2Version self, const size_t index, const float value)
{
   detail::vectorSet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsSet", self, index, value);
}

// Get pointer to existing values, const
const float *
VersionFloatsGetArrayConst(ConstHandle2ConstVersion self)
{
   return detail::vectorGet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsGetArrayConst", self);
}

// Get pointer to existing values, non-const
float *
VersionFloatsGetArray(ConstHandle2Version self)
{
   return detail::vectorGet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsGetArray", self);
}

// Set completely new values and size
void
VersionFloatsSetArray(ConstHandle2Version self, const float *const values, const size_t size)
{
   return detail::vectorSet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsSetArray", self, size, values);
}

// ------------------------
// double
// ------------------------

// Clear
void
VersionDoublesClear(ConstHandle2Version self)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"DoublesClear", self);
}

// Get size
size_t
VersionDoublesSize(ConstHandle2ConstVersion self)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"DoublesSize", self);
}

// Get value
// By index \in [0,size)
double
VersionDoublesGet(ConstHandle2ConstVersion self, const size_t index)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGet", self, index);
}

// Set value
// By index \in [0,size)
void
VersionDoublesSet(ConstHandle2Version self, const size_t index, const double value)
{
   detail::vectorSet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesSet", self, index, value);
}

// Get pointer to existing values, const
const double *
VersionDoublesGetArrayConst(ConstHandle2ConstVersion self)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGetArrayConst", self);
}

// Get pointer to existing values, non-const
double *
VersionDoublesGetArray(ConstHandle2Version self)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGetArray", self);
}

// Set completely new values and size
void
VersionDoublesSetArray(ConstHandle2Version self, const double *const values, const size_t size)
{
   return detail::vectorSet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesSetArray", self, size, values);
}


// -----------------------------------------------------------------------------
// Metadatum: encoding
// -----------------------------------------------------------------------------

// Has
int
VersionEncodingHas(ConstHandle2ConstVersion self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EncodingHas", self, extract::encoding);
}

// Get
// Returns by value
XMLName
VersionEncodingGet(ConstHandle2ConstVersion self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"EncodingGet", self, extract::encoding);
}

// Set
void
VersionEncodingSet(ConstHandle2Version self, const XMLName encoding)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"EncodingSet", self, extract::encoding, encoding);
}


// -----------------------------------------------------------------------------
// Metadatum: markup
// -----------------------------------------------------------------------------

// Has
int
VersionMarkupHas(ConstHandle2ConstVersion self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"MarkupHas", self, extract::markup);
}

// Get
// Returns by value
const char *
VersionMarkupGet(ConstHandle2ConstVersion self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"MarkupGet", self, extract::markup);
}

// Set
void
VersionMarkupSet(ConstHandle2Version self, const char *const markup)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"MarkupSet", self, extract::markup, markup);
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
VersionLabelHas(ConstHandle2ConstVersion self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
XMLName
VersionLabelGet(ConstHandle2ConstVersion self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
VersionLabelSet(ConstHandle2Version self, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/documentation/Version/src/custom.cpp"
