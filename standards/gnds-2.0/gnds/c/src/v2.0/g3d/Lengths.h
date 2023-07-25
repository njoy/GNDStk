
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
// Lengths is the basic handle type in this file. Example:
//    // Create a default Lengths object:
//    Lengths handle = LengthsDefault();
// Functions involving Lengths are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_G3D_LENGTHS
#define C_INTERFACE_GNDS_V2_0_G3D_LENGTHS

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct LengthsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Lengths
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct LengthsClass *Lengths;

// --- Const-aware handles.
typedef const struct LengthsClass *const ConstHandle2ConstLengths;
typedef       struct LengthsClass *const ConstHandle2Lengths;
typedef const struct LengthsClass *      Handle2ConstLengths;
typedef       struct LengthsClass *      Handle2Lengths;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstLengths
LengthsDefaultConst();

// +++ Create, default
extern_c Handle2Lengths
LengthsDefault();

// --- Create, general, const
extern_c Handle2ConstLengths
LengthsCreateConst(
   const char *const valueType,
   const char *const label
);

// +++ Create, general
extern_c Handle2Lengths
LengthsCreate(
   const char *const valueType,
   const char *const label
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
LengthsAssign(ConstHandle2Lengths self, ConstHandle2ConstLengths from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
LengthsDelete(ConstHandle2ConstLengths self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
LengthsRead(ConstHandle2Lengths self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
LengthsWrite(ConstHandle2ConstLengths self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
LengthsPrint(ConstHandle2ConstLengths self);

// +++ Print to standard output, as XML
extern_c int
LengthsPrintXML(ConstHandle2ConstLengths self);

// +++ Print to standard output, as JSON
extern_c int
LengthsPrintJSON(ConstHandle2ConstLengths self);


// -----------------------------------------------------------------------------
// Data vector
// -----------------------------------------------------------------------------

// +++ Clear
extern_c void
LengthsIntsClear(ConstHandle2Lengths self);

// +++ Get size
extern_c size_t
LengthsIntsSize(ConstHandle2ConstLengths self);

// +++ Get value
// +++ By index \in [0,size)
extern_c int
LengthsIntsGet(ConstHandle2ConstLengths self, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
LengthsIntsSet(ConstHandle2Lengths self, const size_t index, const int value);

// --- Get pointer to existing values, const
extern_c const int *
LengthsIntsGetArrayConst(ConstHandle2ConstLengths self);

// +++ Get pointer to existing values, non-const
extern_c int *
LengthsIntsGetArray(ConstHandle2Lengths self);

// +++ Set completely new values and size
extern_c void
LengthsIntsSetArray(ConstHandle2Lengths self, const int *const values, const size_t size);


// -----------------------------------------------------------------------------
// Metadatum: valueType
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
LengthsValueTypeHas(ConstHandle2ConstLengths self);

// +++ Get
// +++ Returns by value
extern_c const char *
LengthsValueTypeGet(ConstHandle2ConstLengths self);

// +++ Set
extern_c void
LengthsValueTypeSet(ConstHandle2Lengths self, const char *const valueType);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
LengthsLabelHas(ConstHandle2ConstLengths self);

// +++ Get
// +++ Returns by value
extern_c const char *
LengthsLabelGet(ConstHandle2ConstLengths self);

// +++ Set
extern_c void
LengthsLabelSet(ConstHandle2Lengths self, const char *const label);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/g3d/Lengths/src/custom.h"

#undef extern_c
#endif
