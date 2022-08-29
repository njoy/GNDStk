
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
// ExperimentalDataSets is the basic handle type in this file. Example:
//    // Create a default ExperimentalDataSets object:
//    ExperimentalDataSets handle = ExperimentalDataSetsDefault();
// Functions involving ExperimentalDataSets are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_DOCUMENTATION_EXPERIMENTALDATASETS
#define C_INTERFACE_TRY_V2_0_DOCUMENTATION_EXPERIMENTALDATASETS

#include "GNDStk.h"
#include "v2.0/documentation/ExforDataSets.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ExperimentalDataSetsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ExperimentalDataSets
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ExperimentalDataSetsClass *ExperimentalDataSets;

// --- Const-aware handles.
typedef const struct ExperimentalDataSetsClass *const ConstHandle2ConstExperimentalDataSets;
typedef       struct ExperimentalDataSetsClass *const ConstHandle2ExperimentalDataSets;
typedef const struct ExperimentalDataSetsClass *      Handle2ConstExperimentalDataSets;
typedef       struct ExperimentalDataSetsClass *      Handle2ExperimentalDataSets;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstExperimentalDataSets
ExperimentalDataSetsDefaultConst();

// +++ Create, default
extern_c Handle2ExperimentalDataSets
ExperimentalDataSetsDefault();

// --- Create, general, const
extern_c Handle2ConstExperimentalDataSets
ExperimentalDataSetsCreateConst(
   ConstHandle2ConstExforDataSets exforDataSets
);

// +++ Create, general
extern_c Handle2ExperimentalDataSets
ExperimentalDataSetsCreate(
   ConstHandle2ConstExforDataSets exforDataSets
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ExperimentalDataSetsAssign(ConstHandle2ExperimentalDataSets This, ConstHandle2ConstExperimentalDataSets from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ExperimentalDataSetsDelete(ConstHandle2ConstExperimentalDataSets This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ExperimentalDataSetsRead(ConstHandle2ExperimentalDataSets This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ExperimentalDataSetsWrite(ConstHandle2ConstExperimentalDataSets This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ExperimentalDataSetsPrint(ConstHandle2ConstExperimentalDataSets This);

// +++ Print to standard output, as XML
extern_c int
ExperimentalDataSetsPrintXML(ConstHandle2ConstExperimentalDataSets This);

// +++ Print to standard output, as JSON
extern_c int
ExperimentalDataSetsPrintJSON(ConstHandle2ConstExperimentalDataSets This);


// -----------------------------------------------------------------------------
// Child: exforDataSets
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ExperimentalDataSetsExforDataSetsHas(ConstHandle2ConstExperimentalDataSets This);

// --- Get, const
extern_c Handle2ConstExforDataSets
ExperimentalDataSetsExforDataSetsGetConst(ConstHandle2ConstExperimentalDataSets This);

// +++ Get, non-const
extern_c Handle2ExforDataSets
ExperimentalDataSetsExforDataSetsGet(ConstHandle2ExperimentalDataSets This);

// +++ Set
extern_c void
ExperimentalDataSetsExforDataSetsSet(ConstHandle2ExperimentalDataSets This, ConstHandle2ConstExforDataSets exforDataSets);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
