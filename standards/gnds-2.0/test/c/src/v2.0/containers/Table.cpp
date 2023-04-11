
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2.0/containers/Table.hpp"
#include "Table.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = TableClass;
using CPP = multigroup::Table;

static const std::string CLASSNAME = "Table";

namespace extract {
   static auto columns = [](auto &obj) { return &obj.columns; };
   static auto rows = [](auto &obj) { return &obj.rows; };
   static auto storageOrder = [](auto &obj) { return &obj.storageOrder; };
   static auto columnHeaders = [](auto &obj) { return &obj.columnHeaders; };
   static auto data = [](auto &obj) { return &obj.data; };
}

using CPPColumnHeaders = containers::ColumnHeaders;
using CPPData = containers::Data;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstTable
TableDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Table
TableDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstTable
TableCreateConst(
   const Integer32 columns,
   const Integer32 rows,
   const XMLName storageOrder,
   ConstHandle2ConstColumnHeaders columnHeaders,
   ConstHandle2ConstData data
) {
   ConstHandle2Table handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      columns,
      rows,
      storageOrder,
      detail::tocpp<CPPColumnHeaders>(columnHeaders),
      detail::tocpp<CPPData>(data)
   );
   return handle;
}

// Create, general
Handle2Table
TableCreate(
   const Integer32 columns,
   const Integer32 rows,
   const XMLName storageOrder,
   ConstHandle2ConstColumnHeaders columnHeaders,
   ConstHandle2ConstData data
) {
   ConstHandle2Table handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      columns,
      rows,
      storageOrder,
      detail::tocpp<CPPColumnHeaders>(columnHeaders),
      detail::tocpp<CPPData>(data)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
TableAssign(ConstHandle2Table self, ConstHandle2ConstTable from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
TableDelete(ConstHandle2ConstTable self)
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
TableRead(ConstHandle2Table self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
TableWrite(ConstHandle2ConstTable self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
TablePrint(ConstHandle2ConstTable self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
TablePrintXML(ConstHandle2ConstTable self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
TablePrintJSON(ConstHandle2ConstTable self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: columns
// -----------------------------------------------------------------------------

// Has
int
TableColumnsHas(ConstHandle2ConstTable self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ColumnsHas", self, extract::columns);
}

// Get
// Returns by value
Integer32
TableColumnsGet(ConstHandle2ConstTable self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ColumnsGet", self, extract::columns);
}

// Set
void
TableColumnsSet(ConstHandle2Table self, const Integer32 columns)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ColumnsSet", self, extract::columns, columns);
}


// -----------------------------------------------------------------------------
// Metadatum: rows
// -----------------------------------------------------------------------------

// Has
int
TableRowsHas(ConstHandle2ConstTable self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"RowsHas", self, extract::rows);
}

// Get
// Returns by value
Integer32
TableRowsGet(ConstHandle2ConstTable self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"RowsGet", self, extract::rows);
}

// Set
void
TableRowsSet(ConstHandle2Table self, const Integer32 rows)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"RowsSet", self, extract::rows, rows);
}


// -----------------------------------------------------------------------------
// Metadatum: storageOrder
// -----------------------------------------------------------------------------

// Has
int
TableStorageOrderHas(ConstHandle2ConstTable self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"StorageOrderHas", self, extract::storageOrder);
}

// Get
// Returns by value
XMLName
TableStorageOrderGet(ConstHandle2ConstTable self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"StorageOrderGet", self, extract::storageOrder);
}

// Set
void
TableStorageOrderSet(ConstHandle2Table self, const XMLName storageOrder)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"StorageOrderSet", self, extract::storageOrder, storageOrder);
}


// -----------------------------------------------------------------------------
// Child: columnHeaders
// -----------------------------------------------------------------------------

// Has
int
TableColumnHeadersHas(ConstHandle2ConstTable self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ColumnHeadersHas", self, extract::columnHeaders);
}

// Get, const
Handle2ConstColumnHeaders
TableColumnHeadersGetConst(ConstHandle2ConstTable self)
{
   return detail::getField<CPP,Handle2ConstColumnHeaders>
      (CLASSNAME, CLASSNAME+"ColumnHeadersGetConst", self, extract::columnHeaders);
}

// Get, non-const
Handle2ColumnHeaders
TableColumnHeadersGet(ConstHandle2Table self)
{
   return detail::getField<CPP,Handle2ColumnHeaders>
      (CLASSNAME, CLASSNAME+"ColumnHeadersGet", self, extract::columnHeaders);
}

// Set
void
TableColumnHeadersSet(ConstHandle2Table self, ConstHandle2ConstColumnHeaders columnHeaders)
{
   detail::setField<CPP,CPPColumnHeaders>
      (CLASSNAME, CLASSNAME+"ColumnHeadersSet", self, extract::columnHeaders, columnHeaders);
}


// -----------------------------------------------------------------------------
// Child: data
// -----------------------------------------------------------------------------

// Has
int
TableDataHas(ConstHandle2ConstTable self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DataHas", self, extract::data);
}

// Get, const
Handle2ConstData
TableDataGetConst(ConstHandle2ConstTable self)
{
   return detail::getField<CPP,Handle2ConstData>
      (CLASSNAME, CLASSNAME+"DataGetConst", self, extract::data);
}

// Get, non-const
Handle2Data
TableDataGet(ConstHandle2Table self)
{
   return detail::getField<CPP,Handle2Data>
      (CLASSNAME, CLASSNAME+"DataGet", self, extract::data);
}

// Set
void
TableDataSet(ConstHandle2Table self, ConstHandle2ConstData data)
{
   detail::setField<CPP,CPPData>
      (CLASSNAME, CLASSNAME+"DataSet", self, extract::data, data);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/containers/Table/src/custom.cpp"
