
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
// LogNormal is the basic handle type in this file. Example:
//    // Create a default LogNormal object:
//    LogNormal handle = LogNormalDefault();
// Functions involving LogNormal are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_POPS_LOGNORMAL
#define C_INTERFACE_TRY_V2_0_POPS_LOGNORMAL

#include "GNDStk.h"
#include "v2.0/unknownNamespace/Double.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct LogNormalClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ LogNormal
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct LogNormalClass *LogNormal;

// --- Const-aware handles.
typedef const struct LogNormalClass *const ConstHandle2ConstLogNormal;
typedef       struct LogNormalClass *const ConstHandle2LogNormal;
typedef const struct LogNormalClass *      Handle2ConstLogNormal;
typedef       struct LogNormalClass *      Handle2LogNormal;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstLogNormal
LogNormalDefaultConst();

// +++ Create, default
extern_c Handle2LogNormal
LogNormalDefault();

// --- Create, general, const
extern_c Handle2ConstLogNormal
LogNormalCreateConst(
   ConstHandle2ConstDouble Double
);

// +++ Create, general
extern_c Handle2LogNormal
LogNormalCreate(
   ConstHandle2ConstDouble Double
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
LogNormalAssign(ConstHandle2LogNormal This, ConstHandle2ConstLogNormal from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
LogNormalDelete(ConstHandle2ConstLogNormal This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
LogNormalRead(ConstHandle2LogNormal This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
LogNormalWrite(ConstHandle2ConstLogNormal This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
LogNormalPrint(ConstHandle2ConstLogNormal This);

// +++ Print to standard output, as XML
extern_c int
LogNormalPrintXML(ConstHandle2ConstLogNormal This);

// +++ Print to standard output, as JSON
extern_c int
LogNormalPrintJSON(ConstHandle2ConstLogNormal This);


// -----------------------------------------------------------------------------
// Child: Double
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
LogNormalDoubleHas(ConstHandle2ConstLogNormal This);

// --- Get, const
extern_c Handle2ConstDouble
LogNormalDoubleGetConst(ConstHandle2ConstLogNormal This);

// +++ Get, non-const
extern_c Handle2Double
LogNormalDoubleGet(ConstHandle2LogNormal This);

// +++ Set
extern_c void
LogNormalDoubleSet(ConstHandle2LogNormal This, ConstHandle2ConstDouble Double);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
