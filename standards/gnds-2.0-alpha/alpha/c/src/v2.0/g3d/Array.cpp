
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/g3d/Array.hpp"
#include "Array.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = ArrayClass;
using CPP = multigroup::Array;

static const std::string CLASSNAME = "Array";

namespace extract {
   static auto shape = [](auto &obj) { return &obj.shape; };
   static auto compression = [](auto &obj) { return &obj.compression; };
   static auto symmetry = [](auto &obj) { return &obj.symmetry; };
   static auto starts = [](auto &obj) { return &obj.starts; };
   static auto lengths = [](auto &obj) { return &obj.lengths; };
   static auto values = [](auto &obj) { return &obj.values; };
}

using CPPStarts = g3d::Starts;
using CPPLengths = g3d::Lengths;
using CPPValues = common::Values;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstArray
ArrayDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Array
ArrayDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstArray
ArrayCreateConst(
   const char *const shape,
   const char *const compression,
   const char *const symmetry,
   ConstHandle2ConstStarts starts,
   ConstHandle2ConstLengths lengths,
   ConstHandle2ConstValues values
) {
   ConstHandle2Array handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      shape,
      compression,
      symmetry,
      detail::tocpp<CPPStarts>(starts),
      detail::tocpp<CPPLengths>(lengths),
      detail::tocpp<CPPValues>(values)
   );
   return handle;
}

// Create, general
Handle2Array
ArrayCreate(
   const char *const shape,
   const char *const compression,
   const char *const symmetry,
   ConstHandle2ConstStarts starts,
   ConstHandle2ConstLengths lengths,
   ConstHandle2ConstValues values
) {
   ConstHandle2Array handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      shape,
      compression,
      symmetry,
      detail::tocpp<CPPStarts>(starts),
      detail::tocpp<CPPLengths>(lengths),
      detail::tocpp<CPPValues>(values)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ArrayAssign(ConstHandle2Array This, ConstHandle2ConstArray from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ArrayDelete(ConstHandle2ConstArray This)
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
ArrayRead(ConstHandle2Array This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ArrayWrite(ConstHandle2ConstArray This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
ArrayPrint(ConstHandle2ConstArray This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
ArrayPrintXML(ConstHandle2ConstArray This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
ArrayPrintJSON(ConstHandle2ConstArray This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: shape
// -----------------------------------------------------------------------------

// Has
int
ArrayShapeHas(ConstHandle2ConstArray This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ShapeHas", This, extract::shape);
}

// Get
// Returns by value
const char *
ArrayShapeGet(ConstHandle2ConstArray This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ShapeGet", This, extract::shape);
}

// Set
void
ArrayShapeSet(ConstHandle2Array This, const char *const shape)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ShapeSet", This, extract::shape, shape);
}


// -----------------------------------------------------------------------------
// Metadatum: compression
// -----------------------------------------------------------------------------

// Has
int
ArrayCompressionHas(ConstHandle2ConstArray This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CompressionHas", This, extract::compression);
}

// Get
// Returns by value
const char *
ArrayCompressionGet(ConstHandle2ConstArray This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"CompressionGet", This, extract::compression);
}

// Set
void
ArrayCompressionSet(ConstHandle2Array This, const char *const compression)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"CompressionSet", This, extract::compression, compression);
}


// -----------------------------------------------------------------------------
// Metadatum: symmetry
// -----------------------------------------------------------------------------

// Has
int
ArraySymmetryHas(ConstHandle2ConstArray This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SymmetryHas", This, extract::symmetry);
}

// Get
// Returns by value
const char *
ArraySymmetryGet(ConstHandle2ConstArray This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"SymmetryGet", This, extract::symmetry);
}

// Set
void
ArraySymmetrySet(ConstHandle2Array This, const char *const symmetry)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"SymmetrySet", This, extract::symmetry, symmetry);
}


// -----------------------------------------------------------------------------
// Child: starts
// -----------------------------------------------------------------------------

// Has
int
ArrayStartsHas(ConstHandle2ConstArray This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"StartsHas", This, extract::starts);
}

// Get, const
Handle2ConstStarts
ArrayStartsGetConst(ConstHandle2ConstArray This)
{
   return detail::getField<CPP,Handle2ConstStarts>
      (CLASSNAME, CLASSNAME+"StartsGetConst", This, extract::starts);
}

// Get, non-const
Handle2Starts
ArrayStartsGet(ConstHandle2Array This)
{
   return detail::getField<CPP,Handle2Starts>
      (CLASSNAME, CLASSNAME+"StartsGet", This, extract::starts);
}

// Set
void
ArrayStartsSet(ConstHandle2Array This, ConstHandle2ConstStarts starts)
{
   detail::setField<CPP,CPPStarts>
      (CLASSNAME, CLASSNAME+"StartsSet", This, extract::starts, starts);
}


// -----------------------------------------------------------------------------
// Child: lengths
// -----------------------------------------------------------------------------

// Has
int
ArrayLengthsHas(ConstHandle2ConstArray This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LengthsHas", This, extract::lengths);
}

// Get, const
Handle2ConstLengths
ArrayLengthsGetConst(ConstHandle2ConstArray This)
{
   return detail::getField<CPP,Handle2ConstLengths>
      (CLASSNAME, CLASSNAME+"LengthsGetConst", This, extract::lengths);
}

// Get, non-const
Handle2Lengths
ArrayLengthsGet(ConstHandle2Array This)
{
   return detail::getField<CPP,Handle2Lengths>
      (CLASSNAME, CLASSNAME+"LengthsGet", This, extract::lengths);
}

// Set
void
ArrayLengthsSet(ConstHandle2Array This, ConstHandle2ConstLengths lengths)
{
   detail::setField<CPP,CPPLengths>
      (CLASSNAME, CLASSNAME+"LengthsSet", This, extract::lengths, lengths);
}


// -----------------------------------------------------------------------------
// Child: values
// -----------------------------------------------------------------------------

// Has
int
ArrayValuesHas(ConstHandle2ConstArray This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ValuesHas", This, extract::values);
}

// Get, const
Handle2ConstValues
ArrayValuesGetConst(ConstHandle2ConstArray This)
{
   return detail::getField<CPP,Handle2ConstValues>
      (CLASSNAME, CLASSNAME+"ValuesGetConst", This, extract::values);
}

// Get, non-const
Handle2Values
ArrayValuesGet(ConstHandle2Array This)
{
   return detail::getField<CPP,Handle2Values>
      (CLASSNAME, CLASSNAME+"ValuesGet", This, extract::values);
}

// Set
void
ArrayValuesSet(ConstHandle2Array This, ConstHandle2ConstValues values)
{
   detail::setField<CPP,CPPValues>
      (CLASSNAME, CLASSNAME+"ValuesSet", This, extract::values, values);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/g3d/Array/src/custom.cpp"
