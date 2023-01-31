
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
// Array is the basic handle type in this file. Example:
//    // Create a default Array object:
//    Array handle = ArrayDefault();
// Functions involving Array are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_G2D_ARRAY
#define C_INTERFACE_ALPHA_V2_0_G2D_ARRAY

#include "GNDStk.h"
#include "v2.0/common/Values.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ArrayClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Array
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ArrayClass *Array;

// --- Const-aware handles.
typedef const struct ArrayClass *const ConstHandle2ConstArray;
typedef       struct ArrayClass *const ConstHandle2Array;
typedef const struct ArrayClass *      Handle2ConstArray;
typedef       struct ArrayClass *      Handle2Array;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstArray
ArrayDefaultConst();

// +++ Create, default
extern_c Handle2Array
ArrayDefault();

// --- Create, general, const
extern_c Handle2ConstArray
ArrayCreateConst(
   const char *const shape,
   const char *const compression,
   const char *const symmetry,
   ConstHandle2ConstValues values
);

// +++ Create, general
extern_c Handle2Array
ArrayCreate(
   const char *const shape,
   const char *const compression,
   const char *const symmetry,
   ConstHandle2ConstValues values
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ArrayAssign(ConstHandle2Array This, ConstHandle2ConstArray from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ArrayDelete(ConstHandle2ConstArray This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ArrayRead(ConstHandle2Array This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ArrayWrite(ConstHandle2ConstArray This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ArrayPrint(ConstHandle2ConstArray This);

// +++ Print to standard output, as XML
extern_c int
ArrayPrintXML(ConstHandle2ConstArray This);

// +++ Print to standard output, as JSON
extern_c int
ArrayPrintJSON(ConstHandle2ConstArray This);


// -----------------------------------------------------------------------------
// Metadatum: shape
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ArrayShapeHas(ConstHandle2ConstArray This);

// +++ Get
// +++ Returns by value
extern_c const char *
ArrayShapeGet(ConstHandle2ConstArray This);

// +++ Set
extern_c void
ArrayShapeSet(ConstHandle2Array This, const char *const shape);


// -----------------------------------------------------------------------------
// Metadatum: compression
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ArrayCompressionHas(ConstHandle2ConstArray This);

// +++ Get
// +++ Returns by value
extern_c const char *
ArrayCompressionGet(ConstHandle2ConstArray This);

// +++ Set
extern_c void
ArrayCompressionSet(ConstHandle2Array This, const char *const compression);


// -----------------------------------------------------------------------------
// Metadatum: symmetry
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ArraySymmetryHas(ConstHandle2ConstArray This);

// +++ Get
// +++ Returns by value
extern_c const char *
ArraySymmetryGet(ConstHandle2ConstArray This);

// +++ Set
extern_c void
ArraySymmetrySet(ConstHandle2Array This, const char *const symmetry);


// -----------------------------------------------------------------------------
// Child: values
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ArrayValuesHas(ConstHandle2ConstArray This);

// --- Get, const
extern_c Handle2ConstValues
ArrayValuesGetConst(ConstHandle2ConstArray This);

// +++ Get, non-const
extern_c Handle2Values
ArrayValuesGet(ConstHandle2Array This);

// +++ Set
extern_c void
ArrayValuesSet(ConstHandle2Array This, ConstHandle2ConstValues values);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/g2d/Array/src/custom.h"

#undef extern_c
#endif
