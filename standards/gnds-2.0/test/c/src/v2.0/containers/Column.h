
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
// Column is the basic handle type in this file. Example:
//    // Create a default Column object:
//    Column handle = ColumnDefault();
// Functions involving Column are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_CONTAINERS_COLUMN
#define C_INTERFACE_TEST_V2_0_CONTAINERS_COLUMN

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ColumnClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Column
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ColumnClass *Column;

// --- Const-aware handles.
typedef const struct ColumnClass *const ConstHandle2ConstColumn;
typedef       struct ColumnClass *const ConstHandle2Column;
typedef const struct ColumnClass *      Handle2ConstColumn;
typedef       struct ColumnClass *      Handle2Column;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstColumn
ColumnDefaultConst();

// +++ Create, default
extern_c Handle2Column
ColumnDefault();

// --- Create, general, const
extern_c Handle2ConstColumn
ColumnCreateConst(
   const Integer32 index,
   const XMLName name,
   const XMLName unit,
   const XMLName types
);

// +++ Create, general
extern_c Handle2Column
ColumnCreate(
   const Integer32 index,
   const XMLName name,
   const XMLName unit,
   const XMLName types
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ColumnAssign(ConstHandle2Column This, ConstHandle2ConstColumn from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ColumnDelete(ConstHandle2ConstColumn This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ColumnRead(ConstHandle2Column This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ColumnWrite(ConstHandle2ConstColumn This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ColumnPrint(ConstHandle2ConstColumn This);

// +++ Print to standard output, as XML
extern_c int
ColumnPrintXML(ConstHandle2ConstColumn This);

// +++ Print to standard output, as JSON
extern_c int
ColumnPrintJSON(ConstHandle2ConstColumn This);


// -----------------------------------------------------------------------------
// Metadatum: index
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ColumnIndexHas(ConstHandle2ConstColumn This);

// +++ Get
// +++ Returns by value
extern_c Integer32
ColumnIndexGet(ConstHandle2ConstColumn This);

// +++ Set
extern_c void
ColumnIndexSet(ConstHandle2Column This, const Integer32 index);


// -----------------------------------------------------------------------------
// Metadatum: name
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ColumnNameHas(ConstHandle2ConstColumn This);

// +++ Get
// +++ Returns by value
extern_c XMLName
ColumnNameGet(ConstHandle2ConstColumn This);

// +++ Set
extern_c void
ColumnNameSet(ConstHandle2Column This, const XMLName name);


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ColumnUnitHas(ConstHandle2ConstColumn This);

// +++ Get
// +++ Returns by value
extern_c XMLName
ColumnUnitGet(ConstHandle2ConstColumn This);

// +++ Set
extern_c void
ColumnUnitSet(ConstHandle2Column This, const XMLName unit);


// -----------------------------------------------------------------------------
// Metadatum: types
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ColumnTypesHas(ConstHandle2ConstColumn This);

// +++ Get
// +++ Returns by value
extern_c XMLName
ColumnTypesGet(ConstHandle2ConstColumn This);

// +++ Set
extern_c void
ColumnTypesSet(ConstHandle2Column This, const XMLName types);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
