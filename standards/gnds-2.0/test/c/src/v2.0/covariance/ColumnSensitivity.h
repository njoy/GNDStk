
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
//    // +++ comment
// Constructs you're LESS likely to care about are preceded with:
//    // --- comment
// Anything not marked as above can be ignored by most users.
//
// ColumnSensitivity is the basic handle type in this file. Example:
//    // Create a default ColumnSensitivity object:
//    ColumnSensitivity handle = ColumnSensitivityDefault();
// Functions involving ColumnSensitivity are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_COVARIANCE_COLUMNSENSITIVITY
#define C_INTERFACE_TEST_V2_0_COVARIANCE_COLUMNSENSITIVITY

#include "GNDStk.h"
#include "v2.0/containers/Array.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ColumnSensitivityClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ColumnSensitivity
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ColumnSensitivityClass *ColumnSensitivity;

// --- Const-aware handles.
typedef const struct ColumnSensitivityClass *const ConstHandle2ConstColumnSensitivity;
typedef       struct ColumnSensitivityClass *const ConstHandle2ColumnSensitivity;
typedef const struct ColumnSensitivityClass *      Handle2ConstColumnSensitivity;
typedef       struct ColumnSensitivityClass *      Handle2ColumnSensitivity;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstColumnSensitivity
ColumnSensitivityDefaultConst();

// +++ Create, default
extern_c Handle2ColumnSensitivity
ColumnSensitivityDefault();

// --- Create, general, const
extern_c Handle2ConstColumnSensitivity
ColumnSensitivityCreateConst(
   ConstHandle2ConstArray array
);

// +++ Create, general
extern_c Handle2ColumnSensitivity
ColumnSensitivityCreate(
   ConstHandle2ConstArray array
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ColumnSensitivityAssign(ConstHandle2ColumnSensitivity This, ConstHandle2ConstColumnSensitivity from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ColumnSensitivityDelete(ConstHandle2ConstColumnSensitivity This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ColumnSensitivityRead(ConstHandle2ColumnSensitivity This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ColumnSensitivityWrite(ConstHandle2ConstColumnSensitivity This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ColumnSensitivityPrint(ConstHandle2ConstColumnSensitivity This);

// +++ Print to standard output, as XML
extern_c int
ColumnSensitivityPrintXML(ConstHandle2ConstColumnSensitivity This);

// +++ Print to standard output, as JSON
extern_c int
ColumnSensitivityPrintJSON(ConstHandle2ConstColumnSensitivity This);


// -----------------------------------------------------------------------------
// Child: array
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ColumnSensitivityArrayHas(ConstHandle2ConstColumnSensitivity This);

// --- Get, const
extern_c Handle2ConstArray
ColumnSensitivityArrayGetConst(ConstHandle2ConstColumnSensitivity This);

// +++ Get, non-const
extern_c Handle2Array
ColumnSensitivityArrayGet(ConstHandle2ColumnSensitivity This);

// +++ Set
extern_c void
ColumnSensitivityArraySet(ConstHandle2ColumnSensitivity This, ConstHandle2ConstArray array);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif