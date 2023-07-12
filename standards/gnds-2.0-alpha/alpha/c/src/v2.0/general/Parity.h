
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
// Parity is the basic handle type in this file. Example:
//    // Create a default Parity object:
//    Parity handle = ParityDefault();
// Functions involving Parity are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_PARITY
#define C_INTERFACE_ALPHA_V2_0_GENERAL_PARITY

#include "GNDStk.h"
#include "v2.0/general/Integer.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ParityClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Parity
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ParityClass *Parity;

// --- Const-aware handles.
typedef const struct ParityClass *const ConstHandle2ConstParity;
typedef       struct ParityClass *const ConstHandle2Parity;
typedef const struct ParityClass *      Handle2ConstParity;
typedef       struct ParityClass *      Handle2Parity;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstParity
ParityDefaultConst();

// +++ Create, default
extern_c Handle2Parity
ParityDefault();

// --- Create, general, const
extern_c Handle2ConstParity
ParityCreateConst(
   ConstHandle2ConstInteger integer
);

// +++ Create, general
extern_c Handle2Parity
ParityCreate(
   ConstHandle2ConstInteger integer
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ParityAssign(ConstHandle2Parity self, ConstHandle2ConstParity from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ParityDelete(ConstHandle2ConstParity self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ParityRead(ConstHandle2Parity self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ParityWrite(ConstHandle2ConstParity self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ParityPrint(ConstHandle2ConstParity self);

// +++ Print to standard output, as XML
extern_c int
ParityPrintXML(ConstHandle2ConstParity self);

// +++ Print to standard output, as JSON
extern_c int
ParityPrintJSON(ConstHandle2ConstParity self);


// -----------------------------------------------------------------------------
// Child: integer
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ParityIntegerHas(ConstHandle2ConstParity self);

// --- Get, const
extern_c Handle2ConstInteger
ParityIntegerGetConst(ConstHandle2ConstParity self);

// +++ Get, non-const
extern_c Handle2Integer
ParityIntegerGet(ConstHandle2Parity self);

// +++ Set
extern_c void
ParityIntegerSet(ConstHandle2Parity self, ConstHandle2ConstInteger integer);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Parity/src/custom.h"

#undef extern_c
#endif
