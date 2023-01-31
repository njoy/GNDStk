
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/mean/Column.hpp"
#include "Column.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = ColumnClass;
using CPP = multigroup::Column;

static const std::string CLASSNAME = "Column";

namespace extract {
   static auto index = [](auto &obj) { return &obj.index; };
   static auto name = [](auto &obj) { return &obj.name; };
   static auto unit = [](auto &obj) { return &obj.unit; };
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
   const int index,
   const char *const name,
   const char *const unit
) {
   ConstHandle2Column handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      index,
      name,
      unit
   );
   return handle;
}

// Create, general
Handle2Column
ColumnCreate(
   const int index,
   const char *const name,
   const char *const unit
) {
   ConstHandle2Column handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      index,
      name,
      unit
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ColumnAssign(ConstHandle2Column This, ConstHandle2ConstColumn from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ColumnDelete(ConstHandle2ConstColumn This)
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
ColumnRead(ConstHandle2Column This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ColumnWrite(ConstHandle2ConstColumn This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
ColumnPrint(ConstHandle2ConstColumn This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
ColumnPrintXML(ConstHandle2ConstColumn This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
ColumnPrintJSON(ConstHandle2ConstColumn This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: index
// -----------------------------------------------------------------------------

// Has
int
ColumnIndexHas(ConstHandle2ConstColumn This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"IndexHas", This, extract::index);
}

// Get
// Returns by value
int
ColumnIndexGet(ConstHandle2ConstColumn This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"IndexGet", This, extract::index);
}

// Set
void
ColumnIndexSet(ConstHandle2Column This, const int index)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"IndexSet", This, extract::index, index);
}


// -----------------------------------------------------------------------------
// Metadatum: name
// -----------------------------------------------------------------------------

// Has
int
ColumnNameHas(ConstHandle2ConstColumn This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"NameHas", This, extract::name);
}

// Get
// Returns by value
const char *
ColumnNameGet(ConstHandle2ConstColumn This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"NameGet", This, extract::name);
}

// Set
void
ColumnNameSet(ConstHandle2Column This, const char *const name)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"NameSet", This, extract::name, name);
}


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// Has
int
ColumnUnitHas(ConstHandle2ConstColumn This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UnitHas", This, extract::unit);
}

// Get
// Returns by value
const char *
ColumnUnitGet(ConstHandle2ConstColumn This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"UnitGet", This, extract::unit);
}

// Set
void
ColumnUnitSet(ConstHandle2Column This, const char *const unit)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"UnitSet", This, extract::unit, unit);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/mean/Column/src/custom.cpp"
