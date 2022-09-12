
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
// Foobar is the basic handle type in this file. Example:
//    // Create a default Foobar object:
//    Foobar handle = FoobarDefault();
// Functions involving Foobar are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_MULTI_V1_MULTIGROUP_FOOBAR
#define C_INTERFACE_MULTI_V1_MULTIGROUP_FOOBAR

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct FoobarClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Foobar
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct FoobarClass *Foobar;

// --- Const-aware handles.
typedef const struct FoobarClass *const ConstHandle2ConstFoobar;
typedef       struct FoobarClass *const ConstHandle2Foobar;
typedef const struct FoobarClass *      Handle2ConstFoobar;
typedef       struct FoobarClass *      Handle2Foobar;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstFoobar
FoobarDefaultConst();

// +++ Create, default
extern_c Handle2Foobar
FoobarDefault();

// --- Create, general, const
extern_c Handle2ConstFoobar
FoobarCreateConst(
   const char *const value
);

// +++ Create, general
extern_c Handle2Foobar
FoobarCreate(
   const char *const value
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
FoobarAssign(ConstHandle2Foobar This, ConstHandle2ConstFoobar from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
FoobarDelete(ConstHandle2ConstFoobar This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
FoobarRead(ConstHandle2Foobar This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
FoobarWrite(ConstHandle2ConstFoobar This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
FoobarPrint(ConstHandle2ConstFoobar This);

// +++ Print to standard output, as XML
extern_c int
FoobarPrintXML(ConstHandle2ConstFoobar This);

// +++ Print to standard output, as JSON
extern_c int
FoobarPrintJSON(ConstHandle2ConstFoobar This);


// -----------------------------------------------------------------------------
// Data vector
// -----------------------------------------------------------------------------

// +++ Clear
extern_c void
FoobarDoublesClear(ConstHandle2Foobar This);

// +++ Get size
extern_c size_t
FoobarDoublesSize(ConstHandle2ConstFoobar This);

// +++ Get value
// +++ By index \in [0,size)
extern_c double
FoobarDoublesGet(ConstHandle2ConstFoobar This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
FoobarDoublesSet(ConstHandle2Foobar This, const size_t index, const double value);

// --- Get pointer to existing values, const
extern_c const double *
FoobarDoublesGetArrayConst(ConstHandle2ConstFoobar This);

// +++ Get pointer to existing values, non-const
extern_c double *
FoobarDoublesGetArray(ConstHandle2Foobar This);

// +++ Set completely new values and size
extern_c void
FoobarDoublesSetArray(ConstHandle2Foobar This, const double *const values, const size_t size);


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
FoobarValueHas(ConstHandle2ConstFoobar This);

// +++ Get
// +++ Returns by value
extern_c const char *
FoobarValueGet(ConstHandle2ConstFoobar This);

// +++ Set
extern_c void
FoobarValueSet(ConstHandle2Foobar This, const char *const value);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
