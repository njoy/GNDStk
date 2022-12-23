
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
// RowSensitivity is the basic handle type in this file. Example:
//    // Create a default RowSensitivity object:
//    RowSensitivity handle = RowSensitivityDefault();
// Functions involving RowSensitivity are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_COVARIANCE_ROWSENSITIVITY
#define C_INTERFACE_TEST_V2_0_COVARIANCE_ROWSENSITIVITY

#include "GNDStk.h"
#include "v2.0/containers/Array.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct RowSensitivityClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ RowSensitivity
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct RowSensitivityClass *RowSensitivity;

// --- Const-aware handles.
typedef const struct RowSensitivityClass *const ConstHandle2ConstRowSensitivity;
typedef       struct RowSensitivityClass *const ConstHandle2RowSensitivity;
typedef const struct RowSensitivityClass *      Handle2ConstRowSensitivity;
typedef       struct RowSensitivityClass *      Handle2RowSensitivity;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstRowSensitivity
RowSensitivityDefaultConst();

// +++ Create, default
extern_c Handle2RowSensitivity
RowSensitivityDefault();

// --- Create, general, const
extern_c Handle2ConstRowSensitivity
RowSensitivityCreateConst(
   ConstHandle2ConstArray array
);

// +++ Create, general
extern_c Handle2RowSensitivity
RowSensitivityCreate(
   ConstHandle2ConstArray array
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
RowSensitivityAssign(ConstHandle2RowSensitivity This, ConstHandle2ConstRowSensitivity from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
RowSensitivityDelete(ConstHandle2ConstRowSensitivity This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
RowSensitivityRead(ConstHandle2RowSensitivity This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
RowSensitivityWrite(ConstHandle2ConstRowSensitivity This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
RowSensitivityPrint(ConstHandle2ConstRowSensitivity This);

// +++ Print to standard output, as XML
extern_c int
RowSensitivityPrintXML(ConstHandle2ConstRowSensitivity This);

// +++ Print to standard output, as JSON
extern_c int
RowSensitivityPrintJSON(ConstHandle2ConstRowSensitivity This);


// -----------------------------------------------------------------------------
// Child: array
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
RowSensitivityArrayHas(ConstHandle2ConstRowSensitivity This);

// --- Get, const
extern_c Handle2ConstArray
RowSensitivityArrayGetConst(ConstHandle2ConstRowSensitivity This);

// +++ Get, non-const
extern_c Handle2Array
RowSensitivityArrayGet(ConstHandle2RowSensitivity This);

// +++ Set
extern_c void
RowSensitivityArraySet(ConstHandle2RowSensitivity This, ConstHandle2ConstArray array);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
