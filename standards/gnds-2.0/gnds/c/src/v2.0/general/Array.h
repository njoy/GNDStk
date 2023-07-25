
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

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_ARRAY
#define C_INTERFACE_GNDS_V2_0_GENERAL_ARRAY

#include "GNDStk.h"
#include "v2.0/general/Values.h"

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
   ConstHandle2ConstValues values
);

// +++ Create, general
extern_c Handle2Array
ArrayCreate(
   const char *const shape,
   const char *const compression,
   ConstHandle2ConstValues values
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ArrayAssign(ConstHandle2Array self, ConstHandle2ConstArray from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ArrayDelete(ConstHandle2ConstArray self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ArrayRead(ConstHandle2Array self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ArrayWrite(ConstHandle2ConstArray self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ArrayPrint(ConstHandle2ConstArray self);

// +++ Print to standard output, as XML
extern_c int
ArrayPrintXML(ConstHandle2ConstArray self);

// +++ Print to standard output, as JSON
extern_c int
ArrayPrintJSON(ConstHandle2ConstArray self);


// -----------------------------------------------------------------------------
// Metadatum: shape
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ArrayShapeHas(ConstHandle2ConstArray self);

// +++ Get
// +++ Returns by value
extern_c const char *
ArrayShapeGet(ConstHandle2ConstArray self);

// +++ Set
extern_c void
ArrayShapeSet(ConstHandle2Array self, const char *const shape);


// -----------------------------------------------------------------------------
// Metadatum: compression
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ArrayCompressionHas(ConstHandle2ConstArray self);

// +++ Get
// +++ Returns by value
extern_c const char *
ArrayCompressionGet(ConstHandle2ConstArray self);

// +++ Set
extern_c void
ArrayCompressionSet(ConstHandle2Array self, const char *const compression);


// -----------------------------------------------------------------------------
// Child: values
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ArrayValuesHas(ConstHandle2ConstArray self);

// --- Get, const
extern_c Handle2ConstValues
ArrayValuesGetConst(ConstHandle2ConstArray self);

// +++ Get, non-const
extern_c Handle2Values
ArrayValuesGet(ConstHandle2Array self);

// +++ Set
extern_c void
ArrayValuesSet(ConstHandle2Array self, ConstHandle2ConstValues values);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Array/src/custom.h"

#undef extern_c
#endif
