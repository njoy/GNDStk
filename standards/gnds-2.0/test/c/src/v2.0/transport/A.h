
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
// A is the basic handle type in this file. Example:
//    // Create a default A object:
//    A handle = ADefault();
// Functions involving A are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_TRANSPORT_A
#define C_INTERFACE_TEST_V2_0_TRANSPORT_A

#include "GNDStk.h"
#include "v2.0/containers/XYs2d.h"
#include "v2.0/containers/Regions2d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct AClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ A
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct AClass *A;

// --- Const-aware handles.
typedef const struct AClass *const ConstHandle2ConstA;
typedef       struct AClass *const ConstHandle2A;
typedef const struct AClass *      Handle2ConstA;
typedef       struct AClass *      Handle2A;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstA
ADefaultConst();

// +++ Create, default
extern_c Handle2A
ADefault();

// --- Create, general, const
extern_c Handle2ConstA
ACreateConst(
);

// +++ Create, general
extern_c Handle2A
ACreate(
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
AAssign(ConstHandle2A This, ConstHandle2ConstA from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ADelete(ConstHandle2ConstA This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ARead(ConstHandle2A This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
AWrite(ConstHandle2ConstA This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
APrint(ConstHandle2ConstA This);

// +++ Print to standard output, as XML
extern_c int
APrintXML(ConstHandle2ConstA This);

// +++ Print to standard output, as JSON
extern_c int
APrintJSON(ConstHandle2ConstA This);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/transport/A/src/custom.h"

#undef extern_c
#endif
