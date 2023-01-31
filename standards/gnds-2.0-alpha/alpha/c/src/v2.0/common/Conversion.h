
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
// Conversion is the basic handle type in this file. Example:
//    // Create a default Conversion object:
//    Conversion handle = ConversionDefault();
// Functions involving Conversion are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_COMMON_CONVERSION
#define C_INTERFACE_ALPHA_V2_0_COMMON_CONVERSION

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ConversionClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Conversion
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ConversionClass *Conversion;

// --- Const-aware handles.
typedef const struct ConversionClass *const ConstHandle2ConstConversion;
typedef       struct ConversionClass *const ConstHandle2Conversion;
typedef const struct ConversionClass *      Handle2ConstConversion;
typedef       struct ConversionClass *      Handle2Conversion;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstConversion
ConversionDefaultConst();

// +++ Create, default
extern_c Handle2Conversion
ConversionDefault();

// --- Create, general, const
extern_c Handle2ConstConversion
ConversionCreateConst(
   const char *const flags,
   const char *const href
);

// +++ Create, general
extern_c Handle2Conversion
ConversionCreate(
   const char *const flags,
   const char *const href
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ConversionAssign(ConstHandle2Conversion This, ConstHandle2ConstConversion from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ConversionDelete(ConstHandle2ConstConversion This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ConversionRead(ConstHandle2Conversion This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ConversionWrite(ConstHandle2ConstConversion This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ConversionPrint(ConstHandle2ConstConversion This);

// +++ Print to standard output, as XML
extern_c int
ConversionPrintXML(ConstHandle2ConstConversion This);

// +++ Print to standard output, as JSON
extern_c int
ConversionPrintJSON(ConstHandle2ConstConversion This);


// -----------------------------------------------------------------------------
// Metadatum: flags
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ConversionFlagsHas(ConstHandle2ConstConversion This);

// +++ Get
// +++ Returns by value
extern_c const char *
ConversionFlagsGet(ConstHandle2ConstConversion This);

// +++ Set
extern_c void
ConversionFlagsSet(ConstHandle2Conversion This, const char *const flags);


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ConversionHrefHas(ConstHandle2ConstConversion This);

// +++ Get
// +++ Returns by value
extern_c const char *
ConversionHrefGet(ConstHandle2ConstConversion This);

// +++ Set
extern_c void
ConversionHrefSet(ConstHandle2Conversion This, const char *const href);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/common/Conversion/src/custom.h"

#undef extern_c
#endif
