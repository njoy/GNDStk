
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
// ENDFconversionFlags is the basic handle type in this file. Example:
//    // Create a default ENDFconversionFlags object:
//    ENDFconversionFlags handle = ENDFconversionFlagsDefault();
// Functions involving ENDFconversionFlags are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_APPDATA_ENDFCONVERSIONFLAGS
#define C_INTERFACE_TEST_V2_0_APPDATA_ENDFCONVERSIONFLAGS

#include "GNDStk.h"
#include "v2.0/appData/Conversion.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ENDFconversionFlagsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ENDFconversionFlags
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ENDFconversionFlagsClass *ENDFconversionFlags;

// --- Const-aware handles.
typedef const struct ENDFconversionFlagsClass *const ConstHandle2ConstENDFconversionFlags;
typedef       struct ENDFconversionFlagsClass *const ConstHandle2ENDFconversionFlags;
typedef const struct ENDFconversionFlagsClass *      Handle2ConstENDFconversionFlags;
typedef       struct ENDFconversionFlagsClass *      Handle2ENDFconversionFlags;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstENDFconversionFlags
ENDFconversionFlagsDefaultConst();

// +++ Create, default
extern_c Handle2ENDFconversionFlags
ENDFconversionFlagsDefault();

// --- Create, general, const
extern_c Handle2ConstENDFconversionFlags
ENDFconversionFlagsCreateConst(
   ConstHandle2ConstConversion conversion
);

// +++ Create, general
extern_c Handle2ENDFconversionFlags
ENDFconversionFlagsCreate(
   ConstHandle2ConstConversion conversion
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ENDFconversionFlagsAssign(ConstHandle2ENDFconversionFlags This, ConstHandle2ConstENDFconversionFlags from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ENDFconversionFlagsDelete(ConstHandle2ConstENDFconversionFlags This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ENDFconversionFlagsRead(ConstHandle2ENDFconversionFlags This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ENDFconversionFlagsWrite(ConstHandle2ConstENDFconversionFlags This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ENDFconversionFlagsPrint(ConstHandle2ConstENDFconversionFlags This);

// +++ Print to standard output, as XML
extern_c int
ENDFconversionFlagsPrintXML(ConstHandle2ConstENDFconversionFlags This);

// +++ Print to standard output, as JSON
extern_c int
ENDFconversionFlagsPrintJSON(ConstHandle2ConstENDFconversionFlags This);


// -----------------------------------------------------------------------------
// Child: conversion
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ENDFconversionFlagsConversionHas(ConstHandle2ConstENDFconversionFlags This);

// --- Get, const
extern_c Handle2ConstConversion
ENDFconversionFlagsConversionGetConst(ConstHandle2ConstENDFconversionFlags This);

// +++ Get, non-const
extern_c Handle2Conversion
ENDFconversionFlagsConversionGet(ConstHandle2ENDFconversionFlags This);

// +++ Set
extern_c void
ENDFconversionFlagsConversionSet(ConstHandle2ENDFconversionFlags This, ConstHandle2ConstConversion conversion);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
