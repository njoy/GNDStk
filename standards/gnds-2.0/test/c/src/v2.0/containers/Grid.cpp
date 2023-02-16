
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/containers/Grid.hpp"
#include "Grid.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = GridClass;
using CPP = multigroup::Grid;

static const std::string CLASSNAME = "Grid";

namespace extract {
   static auto index = [](auto &obj) { return &obj.index; };
   static auto interpolation = [](auto &obj) { return &obj.interpolation; };
   static auto label = [](auto &obj) { return &obj.label; };
   static auto style = [](auto &obj) { return &obj.style; };
   static auto unit = [](auto &obj) { return &obj.unit; };
}

using CPPValues = containers::Values;
using CPPLink = containers::Link;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstGrid
GridDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Grid
GridDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstGrid
GridCreateConst(
   const Integer32 index,
   const enums::Interpolation interpolation,
   const XMLName label,
   const UTF8Text style,
   const XMLName unit,
) {
   ConstHandle2Grid handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      index,
      interpolation,
      label,
      style,
      unit
   );
   return handle;
}

// Create, general
Handle2Grid
GridCreate(
   const Integer32 index,
   const enums::Interpolation interpolation,
   const XMLName label,
   const UTF8Text style,
   const XMLName unit,
) {
   ConstHandle2Grid handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      index,
      interpolation,
      label,
      style,
      unit
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
GridAssign(ConstHandle2Grid self, ConstHandle2ConstGrid from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
GridDelete(ConstHandle2ConstGrid self)
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
GridRead(ConstHandle2Grid self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
GridWrite(ConstHandle2ConstGrid self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
GridPrint(ConstHandle2ConstGrid self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
GridPrintXML(ConstHandle2ConstGrid self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
GridPrintJSON(ConstHandle2ConstGrid self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: index
// -----------------------------------------------------------------------------

// Has
int
GridIndexHas(ConstHandle2ConstGrid self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"IndexHas", self, extract::index);
}

// Get
// Returns by value
Integer32
GridIndexGet(ConstHandle2ConstGrid self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"IndexGet", self, extract::index);
}

// Set
void
GridIndexSet(ConstHandle2Grid self, const Integer32 index)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"IndexSet", self, extract::index, index);
}


// -----------------------------------------------------------------------------
// Metadatum: interpolation
// -----------------------------------------------------------------------------

// Has
int
GridInterpolationHas(ConstHandle2ConstGrid self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"InterpolationHas", self, extract::interpolation);
}

// Get
// Returns by value
enums::Interpolation
GridInterpolationGet(ConstHandle2ConstGrid self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"InterpolationGet", self, extract::interpolation);
}

// Set
void
GridInterpolationSet(ConstHandle2Grid self, const enums::Interpolation interpolation)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"InterpolationSet", self, extract::interpolation, interpolation);
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
GridLabelHas(ConstHandle2ConstGrid self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
XMLName
GridLabelGet(ConstHandle2ConstGrid self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
GridLabelSet(ConstHandle2Grid self, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: style
// -----------------------------------------------------------------------------

// Has
int
GridStyleHas(ConstHandle2ConstGrid self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"StyleHas", self, extract::style);
}

// Get
// Returns by value
UTF8Text
GridStyleGet(ConstHandle2ConstGrid self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"StyleGet", self, extract::style);
}

// Set
void
GridStyleSet(ConstHandle2Grid self, const UTF8Text style)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"StyleSet", self, extract::style, style);
}


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// Has
int
GridUnitHas(ConstHandle2ConstGrid self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UnitHas", self, extract::unit);
}

// Get
// Returns by value
XMLName
GridUnitGet(ConstHandle2ConstGrid self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"UnitGet", self, extract::unit);
}

// Set
void
GridUnitSet(ConstHandle2Grid self, const XMLName unit)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"UnitSet", self, extract::unit, unit);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/containers/Grid/src/custom.cpp"
