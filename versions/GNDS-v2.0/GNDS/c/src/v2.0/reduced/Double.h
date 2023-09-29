
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
// Double is the basic handle type in this file. Example:
//    // Create a default Double object:
//    Double handle = DoubleDefault();
// Functions involving Double are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_REDUCED_DOUBLE
#define C_INTERFACE_GNDS_V2_0_REDUCED_DOUBLE

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct DoubleClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Double
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct DoubleClass *Double;

// --- Const-aware handles.
typedef const struct DoubleClass *const ConstHandle2ConstDouble;
typedef       struct DoubleClass *const ConstHandle2Double;
typedef const struct DoubleClass *      Handle2ConstDouble;
typedef       struct DoubleClass *      Handle2Double;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstDouble
DoubleDefaultConst();

// +++ Create, default, non-const
extern_c Handle2Double
DoubleDefault();

// --- Create, general, const
extern_c Handle2ConstDouble
DoubleCreateConst(
   const double value
);

// +++ Create, general, non-const
extern_c Handle2Double
DoubleCreate(
   const double value
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
DoubleAssign(ConstHandle2Double self, ConstHandle2ConstDouble from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
DoubleDelete(ConstHandle2ConstDouble self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
DoubleRead(ConstHandle2Double self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
DoubleWrite(ConstHandle2ConstDouble self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
DoublePrint(ConstHandle2ConstDouble self);

// +++ Print to standard output, as XML
extern_c int
DoublePrintXML(ConstHandle2ConstDouble self);

// +++ Print to standard output, as JSON
extern_c int
DoublePrintJSON(ConstHandle2ConstDouble self);


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DoubleValueHas(ConstHandle2ConstDouble self);

// +++ Get
// +++ Returns by value
extern_c double
DoubleValueGet(ConstHandle2ConstDouble self);

// +++ Set
extern_c void
DoubleValueSet(ConstHandle2Double self, const double value);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/reduced/Double/src/custom.h"

#undef extern_c
#endif
