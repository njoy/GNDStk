
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// Interface for C
// This header file is designed to work with both C and C++
// Function definitions are in this file's .cpp source

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Instructions for Users
//
// Constructs you're MORE likely to care about are preceded with:
//    // +++ remark
// Constructs you're LESS likely to care about are preceded with:
//    // --- remark
// Anything not marked as above can be ignored by most users.
//
// Table is the basic handle type in this file. Example:
//    // Create a default Table object:
//    Table handle = TableDefault();
// Functions involving Table are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_CONTAINERS_TABLE
#define C_INTERFACE_TEST_V2_0_CONTAINERS_TABLE

#include "GNDStk.h"
#include "v2.0/containers/ColumnHeaders.h"
#include "v2.0/containers/Data.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct TableClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Table
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct TableClass *Table;

// --- Const-aware handles.
typedef const struct TableClass *const ConstHandle2ConstTable;
typedef       struct TableClass *const ConstHandle2Table;
typedef const struct TableClass *      Handle2ConstTable;
typedef       struct TableClass *      Handle2Table;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstTable
TableDefaultConst();

// +++ Create, default
extern_c Handle2Table
TableDefault();

// --- Create, general, const
extern_c Handle2ConstTable
TableCreateConst(
   const Integer32 columns,
   const Integer32 rows,
   const XMLName storageOrder,
   ConstHandle2ConstColumnHeaders columnHeaders,
   ConstHandle2ConstData data
);

// +++ Create, general
extern_c Handle2Table
TableCreate(
   const Integer32 columns,
   const Integer32 rows,
   const XMLName storageOrder,
   ConstHandle2ConstColumnHeaders columnHeaders,
   ConstHandle2ConstData data
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
TableAssign(ConstHandle2Table This, ConstHandle2ConstTable from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
TableDelete(ConstHandle2ConstTable This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
TableRead(ConstHandle2Table This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
TableWrite(ConstHandle2ConstTable This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
TablePrint(ConstHandle2ConstTable This);

// +++ Print to standard output, as XML
extern_c int
TablePrintXML(ConstHandle2ConstTable This);

// +++ Print to standard output, as JSON
extern_c int
TablePrintJSON(ConstHandle2ConstTable This);


// -----------------------------------------------------------------------------
// Metadatum: columns
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
TableColumnsHas(ConstHandle2ConstTable This);

// +++ Get
// +++ Returns by value
extern_c Integer32
TableColumnsGet(ConstHandle2ConstTable This);

// +++ Set
extern_c void
TableColumnsSet(ConstHandle2Table This, const Integer32 columns);


// -----------------------------------------------------------------------------
// Metadatum: rows
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
TableRowsHas(ConstHandle2ConstTable This);

// +++ Get
// +++ Returns by value
extern_c Integer32
TableRowsGet(ConstHandle2ConstTable This);

// +++ Set
extern_c void
TableRowsSet(ConstHandle2Table This, const Integer32 rows);


// -----------------------------------------------------------------------------
// Metadatum: storageOrder
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
TableStorageOrderHas(ConstHandle2ConstTable This);

// +++ Get
// +++ Returns by value
extern_c XMLName
TableStorageOrderGet(ConstHandle2ConstTable This);

// +++ Set
extern_c void
TableStorageOrderSet(ConstHandle2Table This, const XMLName storageOrder);


// -----------------------------------------------------------------------------
// Child: columnHeaders
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
TableColumnHeadersHas(ConstHandle2ConstTable This);

// --- Get, const
extern_c Handle2ConstColumnHeaders
TableColumnHeadersGetConst(ConstHandle2ConstTable This);

// +++ Get, non-const
extern_c Handle2ColumnHeaders
TableColumnHeadersGet(ConstHandle2Table This);

// +++ Set
extern_c void
TableColumnHeadersSet(ConstHandle2Table This, ConstHandle2ConstColumnHeaders columnHeaders);


// -----------------------------------------------------------------------------
// Child: data
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
TableDataHas(ConstHandle2ConstTable This);

// --- Get, const
extern_c Handle2ConstData
TableDataGetConst(ConstHandle2ConstTable This);

// +++ Get, non-const
extern_c Handle2Data
TableDataGet(ConstHandle2Table This);

// +++ Set
extern_c void
TableDataSet(ConstHandle2Table This, ConstHandle2ConstData data);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/containers/Table/src/custom.h"

#undef extern_c
#endif
