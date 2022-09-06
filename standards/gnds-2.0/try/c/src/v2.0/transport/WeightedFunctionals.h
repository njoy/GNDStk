
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
// WeightedFunctionals is the basic handle type in this file. Example:
//    // Create a default WeightedFunctionals object:
//    WeightedFunctionals handle = WeightedFunctionalsDefault();
// Functions involving WeightedFunctionals are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_TRANSPORT_WEIGHTEDFUNCTIONALS
#define C_INTERFACE_TRY_V2_0_TRANSPORT_WEIGHTEDFUNCTIONALS

#include "GNDStk.h"
#include "v2.0/transport/Weighted.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct WeightedFunctionalsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ WeightedFunctionals
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct WeightedFunctionalsClass *WeightedFunctionals;

// --- Const-aware handles.
typedef const struct WeightedFunctionalsClass *const ConstHandle2ConstWeightedFunctionals;
typedef       struct WeightedFunctionalsClass *const ConstHandle2WeightedFunctionals;
typedef const struct WeightedFunctionalsClass *      Handle2ConstWeightedFunctionals;
typedef       struct WeightedFunctionalsClass *      Handle2WeightedFunctionals;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstWeightedFunctionals
WeightedFunctionalsDefaultConst();

// +++ Create, default
extern_c Handle2WeightedFunctionals
WeightedFunctionalsDefault();

// --- Create, general, const
extern_c Handle2ConstWeightedFunctionals
WeightedFunctionalsCreateConst(
   ConstHandle2ConstWeighted weighted
);

// +++ Create, general
extern_c Handle2WeightedFunctionals
WeightedFunctionalsCreate(
   ConstHandle2ConstWeighted weighted
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
WeightedFunctionalsAssign(ConstHandle2WeightedFunctionals This, ConstHandle2ConstWeightedFunctionals from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
WeightedFunctionalsDelete(ConstHandle2ConstWeightedFunctionals This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
WeightedFunctionalsRead(ConstHandle2WeightedFunctionals This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
WeightedFunctionalsWrite(ConstHandle2ConstWeightedFunctionals This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
WeightedFunctionalsPrint(ConstHandle2ConstWeightedFunctionals This);

// +++ Print to standard output, as XML
extern_c int
WeightedFunctionalsPrintXML(ConstHandle2ConstWeightedFunctionals This);

// +++ Print to standard output, as JSON
extern_c int
WeightedFunctionalsPrintJSON(ConstHandle2ConstWeightedFunctionals This);


// -----------------------------------------------------------------------------
// Child: weighted
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
WeightedFunctionalsWeightedHas(ConstHandle2ConstWeightedFunctionals This);

// --- Get, const
extern_c Handle2ConstWeighted
WeightedFunctionalsWeightedGetConst(ConstHandle2ConstWeightedFunctionals This);

// +++ Get, non-const
extern_c Handle2Weighted
WeightedFunctionalsWeightedGet(ConstHandle2WeightedFunctionals This);

// +++ Set
extern_c void
WeightedFunctionalsWeightedSet(ConstHandle2WeightedFunctionals This, ConstHandle2ConstWeighted weighted);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif