
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
// Atomic is the basic handle type in this file. Example:
//    // Create a default Atomic object:
//    Atomic handle = AtomicDefault();
// Functions involving Atomic are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_POPS_ATOMIC
#define C_INTERFACE_TEST_V2_0_POPS_ATOMIC

#include "GNDStk.h"
#include "v2.0/pops/Configurations.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct AtomicClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Atomic
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct AtomicClass *Atomic;

// --- Const-aware handles.
typedef const struct AtomicClass *const ConstHandle2ConstAtomic;
typedef       struct AtomicClass *const ConstHandle2Atomic;
typedef const struct AtomicClass *      Handle2ConstAtomic;
typedef       struct AtomicClass *      Handle2Atomic;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstAtomic
AtomicDefaultConst();

// +++ Create, default
extern_c Handle2Atomic
AtomicDefault();

// --- Create, general, const
extern_c Handle2ConstAtomic
AtomicCreateConst(
   ConstHandle2ConstConfigurations configurations
);

// +++ Create, general
extern_c Handle2Atomic
AtomicCreate(
   ConstHandle2ConstConfigurations configurations
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
AtomicAssign(ConstHandle2Atomic This, ConstHandle2ConstAtomic from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
AtomicDelete(ConstHandle2ConstAtomic This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
AtomicRead(ConstHandle2Atomic This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
AtomicWrite(ConstHandle2ConstAtomic This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
AtomicPrint(ConstHandle2ConstAtomic This);

// +++ Print to standard output, as XML
extern_c int
AtomicPrintXML(ConstHandle2ConstAtomic This);

// +++ Print to standard output, as JSON
extern_c int
AtomicPrintJSON(ConstHandle2ConstAtomic This);


// -----------------------------------------------------------------------------
// Child: configurations
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AtomicConfigurationsHas(ConstHandle2ConstAtomic This);

// --- Get, const
extern_c Handle2ConstConfigurations
AtomicConfigurationsGetConst(ConstHandle2ConstAtomic This);

// +++ Get, non-const
extern_c Handle2Configurations
AtomicConfigurationsGet(ConstHandle2Atomic This);

// +++ Set
extern_c void
AtomicConfigurationsSet(ConstHandle2Atomic This, ConstHandle2ConstConfigurations configurations);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
