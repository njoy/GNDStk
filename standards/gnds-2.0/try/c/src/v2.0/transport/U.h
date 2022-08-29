
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
// U is the basic handle type in this file. Example:
//    // Create a default U object:
//    U handle = UDefault();
// Functions involving U are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_TRANSPORT_U
#define C_INTERFACE_TRY_V2_0_TRANSPORT_U

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct UClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ U
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct UClass *U;

// --- Const-aware handles.
typedef const struct UClass *const ConstHandle2ConstU;
typedef       struct UClass *const ConstHandle2U;
typedef const struct UClass *      Handle2ConstU;
typedef       struct UClass *      Handle2U;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstU
UDefaultConst();

// +++ Create, default
extern_c Handle2U
UDefault();

// --- Create, general, const
extern_c Handle2ConstU
UCreateConst(
   const XMLName unit,
   const Float64 value
);

// +++ Create, general
extern_c Handle2U
UCreate(
   const XMLName unit,
   const Float64 value
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
UAssign(ConstHandle2U This, ConstHandle2ConstU from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
UDelete(ConstHandle2ConstU This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
URead(ConstHandle2U This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
UWrite(ConstHandle2ConstU This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
UPrint(ConstHandle2ConstU This);

// +++ Print to standard output, as XML
extern_c int
UPrintXML(ConstHandle2ConstU This);

// +++ Print to standard output, as JSON
extern_c int
UPrintJSON(ConstHandle2ConstU This);


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
UUnitHas(ConstHandle2ConstU This);

// +++ Get
// +++ Returns by value
extern_c XMLName
UUnitGet(ConstHandle2ConstU This);

// +++ Set
extern_c void
UUnitSet(ConstHandle2U This, const XMLName unit);


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
UValueHas(ConstHandle2ConstU This);

// +++ Get
// +++ Returns by value
extern_c Float64
UValueGet(ConstHandle2ConstU This);

// +++ Set
extern_c void
UValueSet(ConstHandle2U This, const Float64 value);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
