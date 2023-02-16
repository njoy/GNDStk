
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
// B is the basic handle type in this file. Example:
//    // Create a default B object:
//    B handle = BDefault();
// Functions involving B are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_FISSIONTRANSPORT_B
#define C_INTERFACE_TEST_V2_0_FISSIONTRANSPORT_B

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct BClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ B
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct BClass *B;

// --- Const-aware handles.
typedef const struct BClass *const ConstHandle2ConstB;
typedef       struct BClass *const ConstHandle2B;
typedef const struct BClass *      Handle2ConstB;
typedef       struct BClass *      Handle2B;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstB
BDefaultConst();

// +++ Create, default
extern_c Handle2B
BDefault();

// --- Create, general, const
extern_c Handle2ConstB
BCreateConst();

// +++ Create, general
extern_c Handle2B
BCreate();

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
BAssign(ConstHandle2B self, ConstHandle2ConstB from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
BDelete(ConstHandle2ConstB self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
BRead(ConstHandle2B self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
BWrite(ConstHandle2ConstB self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
BPrint(ConstHandle2ConstB self);

// +++ Print to standard output, as XML
extern_c int
BPrintXML(ConstHandle2ConstB self);

// +++ Print to standard output, as JSON
extern_c int
BPrintJSON(ConstHandle2ConstB self);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/fissionTransport/B/src/custom.h"

#undef extern_c
#endif
