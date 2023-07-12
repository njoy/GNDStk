
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2.0/containers/Column.hpp"
#include "Column.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = ColumnClass;
using CPP = multigroup::Column;

static const std::string CLASSNAME = "Column";

namespace extract {
   static auto index = [](auto &obj) { return &obj.index; };
   static auto name = [](auto &obj) { return &obj.name; };
   static auto unit = [](auto &obj) { return &obj.unit; };
   static auto types = [](auto &obj) { return &obj.types; };
}


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstColumn
ColumnDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Column
ColumnDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstColumn
ColumnCreateConst(
   const Integer32 index,
   const XMLName name,
   const XMLName unit,
   const XMLName types
) {
   ConstHandle2Column handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      index,
      name,
      unit,
      types
   );
   return handle;
}

// Create, general
Handle2Column
ColumnCreate(
   const Integer32 index,
   const XMLName name,
   const XMLName unit,
   const XMLName types
) {
   ConstHandle2Column handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      index,
      name,
      unit,
      types
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ColumnAssign(ConstHandle2Column self, ConstHandle2ConstColumn from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ColumnDelete(ConstHandle2ConstColumn self)
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
ColumnRead(ConstHandle2Column self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ColumnWrite(ConstHandle2ConstColumn self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ColumnPrint(ConstHandle2ConstColumn self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ColumnPrintXML(ConstHandle2ConstColumn self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ColumnPrintJSON(ConstHandle2ConstColumn self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: index
// -----------------------------------------------------------------------------

// Has
int
ColumnIndexHas(ConstHandle2ConstColumn self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"IndexHas", self, extract::index);
}

// Get
// Returns by value
Integer32
ColumnIndexGet(ConstHandle2ConstColumn self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"IndexGet", self, extract::index);
}

// Set
void
ColumnIndexSet(ConstHandle2Column self, const Integer32 index)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"IndexSet", self, extract::index, index);
}


// -----------------------------------------------------------------------------
// Metadatum: name
// -----------------------------------------------------------------------------

// Has
int
ColumnNameHas(ConstHandle2ConstColumn self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"NameHas", self, extract::name);
}

// Get
// Returns by value
XMLName
ColumnNameGet(ConstHandle2ConstColumn self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"NameGet", self, extract::name);
}

// Set
void
ColumnNameSet(ConstHandle2Column self, const XMLName name)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"NameSet", self, extract::name, name);
}


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// Has
int
ColumnUnitHas(ConstHandle2ConstColumn self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UnitHas", self, extract::unit);
}

// Get
// Returns by value
XMLName
ColumnUnitGet(ConstHandle2ConstColumn self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"UnitGet", self, extract::unit);
}

// Set
void
ColumnUnitSet(ConstHandle2Column self, const XMLName unit)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"UnitSet", self, extract::unit, unit);
}


// -----------------------------------------------------------------------------
// Metadatum: types
// -----------------------------------------------------------------------------

// Has
int
ColumnTypesHas(ConstHandle2ConstColumn self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"TypesHas", self, extract::types);
}

// Get
// Returns by value
XMLName
ColumnTypesGet(ConstHandle2ConstColumn self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"TypesGet", self, extract::types);
}

// Set
void
ColumnTypesSet(ConstHandle2Column self, const XMLName types)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"TypesSet", self, extract::types, types);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/containers/Column/src/custom.cpp"
