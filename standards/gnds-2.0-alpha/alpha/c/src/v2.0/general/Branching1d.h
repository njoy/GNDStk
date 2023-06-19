
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
// Branching1d is the basic handle type in this file. Example:
//    // Create a default Branching1d object:
//    Branching1d handle = Branching1dDefault();
// Functions involving Branching1d are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_BRANCHING1D
#define C_INTERFACE_ALPHA_V2_0_GENERAL_BRANCHING1D

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct Branching1dClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Branching1d
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct Branching1dClass *Branching1d;

// --- Const-aware handles.
typedef const struct Branching1dClass *const ConstHandle2ConstBranching1d;
typedef       struct Branching1dClass *const ConstHandle2Branching1d;
typedef const struct Branching1dClass *      Handle2ConstBranching1d;
typedef       struct Branching1dClass *      Handle2Branching1d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstBranching1d
Branching1dDefaultConst();

// +++ Create, default
extern_c Handle2Branching1d
Branching1dDefault();

// --- Create, general, const
extern_c Handle2ConstBranching1d
Branching1dCreateConst(
   const char *const label
);

// +++ Create, general
extern_c Handle2Branching1d
Branching1dCreate(
   const char *const label
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
Branching1dAssign(ConstHandle2Branching1d self, ConstHandle2ConstBranching1d from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
Branching1dDelete(ConstHandle2ConstBranching1d self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
Branching1dRead(ConstHandle2Branching1d self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
Branching1dWrite(ConstHandle2ConstBranching1d self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
Branching1dPrint(ConstHandle2ConstBranching1d self);

// +++ Print to standard output, as XML
extern_c int
Branching1dPrintXML(ConstHandle2ConstBranching1d self);

// +++ Print to standard output, as JSON
extern_c int
Branching1dPrintJSON(ConstHandle2ConstBranching1d self);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Branching1dLabelHas(ConstHandle2ConstBranching1d self);

// +++ Get
// +++ Returns by value
extern_c const char *
Branching1dLabelGet(ConstHandle2ConstBranching1d self);

// +++ Set
extern_c void
Branching1dLabelSet(ConstHandle2Branching1d self, const char *const label);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Branching1d/src/custom.h"

#undef extern_c
#endif
