
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/g2d/Array.hpp"
#include "Array.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = ArrayClass;
using CPP = multigroup::Array;

static const std::string CLASSNAME = "Array";

namespace extract {
   static auto shape = [](auto &obj) { return &obj.shape; };
   static auto compression = [](auto &obj) { return &obj.compression; };
   static auto symmetry = [](auto &obj) { return &obj.symmetry; };
   static auto values = [](auto &obj) { return &obj.values; };
}

using CPPValues = general::Values;


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

// Create, default, non-const
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
   ConstHandle2ConstValues values
) {
   ConstHandle2Array handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      shape,
      compression,
      symmetry,
      detail::tocpp<CPPValues>(values)
   );
   return handle;
}

// Create, general, non-const
Handle2Array
ArrayCreate(
   const char *const shape,
   const char *const compression,
   const char *const symmetry,
   ConstHandle2ConstValues values
) {
   ConstHandle2Array handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      shape,
      compression,
      symmetry,
      detail::tocpp<CPPValues>(values)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ArrayAssign(ConstHandle2Array self, ConstHandle2ConstArray from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ArrayDelete(ConstHandle2ConstArray self)
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
ArrayRead(ConstHandle2Array self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ArrayWrite(ConstHandle2ConstArray self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ArrayPrint(ConstHandle2ConstArray self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ArrayPrintXML(ConstHandle2ConstArray self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ArrayPrintJSON(ConstHandle2ConstArray self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: shape
// -----------------------------------------------------------------------------

// Has
int
ArrayShapeHas(ConstHandle2ConstArray self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ShapeHas", self, extract::shape);
}

// Get
// Returns by value
const char *
ArrayShapeGet(ConstHandle2ConstArray self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ShapeGet", self, extract::shape);
}

// Set
void
ArrayShapeSet(ConstHandle2Array self, const char *const shape)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ShapeSet", self, extract::shape, shape);
}


// -----------------------------------------------------------------------------
// Metadatum: compression
// -----------------------------------------------------------------------------

// Has
int
ArrayCompressionHas(ConstHandle2ConstArray self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CompressionHas", self, extract::compression);
}

// Get
// Returns by value
const char *
ArrayCompressionGet(ConstHandle2ConstArray self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"CompressionGet", self, extract::compression);
}

// Set
void
ArrayCompressionSet(ConstHandle2Array self, const char *const compression)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"CompressionSet", self, extract::compression, compression);
}


// -----------------------------------------------------------------------------
// Metadatum: symmetry
// -----------------------------------------------------------------------------

// Has
int
ArraySymmetryHas(ConstHandle2ConstArray self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SymmetryHas", self, extract::symmetry);
}

// Get
// Returns by value
const char *
ArraySymmetryGet(ConstHandle2ConstArray self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"SymmetryGet", self, extract::symmetry);
}

// Set
void
ArraySymmetrySet(ConstHandle2Array self, const char *const symmetry)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"SymmetrySet", self, extract::symmetry, symmetry);
}


// -----------------------------------------------------------------------------
// Child: values
// -----------------------------------------------------------------------------

// Has
int
ArrayValuesHas(ConstHandle2ConstArray self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ValuesHas", self, extract::values);
}

// Get, const
Handle2ConstValues
ArrayValuesGetConst(ConstHandle2ConstArray self)
{
   return detail::getField<CPP,Handle2ConstValues>
      (CLASSNAME, CLASSNAME+"ValuesGetConst", self, extract::values);
}

// Get, non-const
Handle2Values
ArrayValuesGet(ConstHandle2Array self)
{
   return detail::getField<CPP,Handle2Values>
      (CLASSNAME, CLASSNAME+"ValuesGet", self, extract::values);
}

// Set
void
ArrayValuesSet(ConstHandle2Array self, ConstHandle2ConstValues values)
{
   detail::setField<CPP,CPPValues>
      (CLASSNAME, CLASSNAME+"ValuesSet", self, extract::values, values);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/g2d/Array/src/custom.cpp"