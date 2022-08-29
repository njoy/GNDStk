
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
// Add is the basic handle type in this file. Example:
//    // Create a default Add object:
//    Add handle = AddDefault();
// Functions involving Add are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_TRANSPORT_ADD
#define C_INTERFACE_TRY_V2_0_TRANSPORT_ADD

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct AddClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Add
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct AddClass *Add;

// --- Const-aware handles.
typedef const struct AddClass *const ConstHandle2ConstAdd;
typedef       struct AddClass *const ConstHandle2Add;
typedef const struct AddClass *      Handle2ConstAdd;
typedef       struct AddClass *      Handle2Add;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstAdd
AddDefaultConst();

// +++ Create, default
extern_c Handle2Add
AddDefault();

// --- Create, general, const
extern_c Handle2ConstAdd
AddCreateConst(
   const char *const href
);

// +++ Create, general
extern_c Handle2Add
AddCreate(
   const char *const href
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
AddAssign(ConstHandle2Add This, ConstHandle2ConstAdd from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
AddDelete(ConstHandle2ConstAdd This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
AddRead(ConstHandle2Add This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
AddWrite(ConstHandle2ConstAdd This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
AddPrint(ConstHandle2ConstAdd This);

// +++ Print to standard output, as XML
extern_c int
AddPrintXML(ConstHandle2ConstAdd This);

// +++ Print to standard output, as JSON
extern_c int
AddPrintJSON(ConstHandle2ConstAdd This);


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AddHrefHas(ConstHandle2ConstAdd This);

// +++ Get
// +++ Returns by value
extern_c const char *
AddHrefGet(ConstHandle2ConstAdd This);

// +++ Set
extern_c void
AddHrefSet(ConstHandle2Add This, const char *const href);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
