
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
// ExforDataSets is the basic handle type in this file. Example:
//    // Create a default ExforDataSets object:
//    ExforDataSets handle = ExforDataSetsDefault();
// Functions involving ExforDataSets are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_DOCUMENTATION_EXFORDATASETS
#define C_INTERFACE_TEST_V2_0_DOCUMENTATION_EXFORDATASETS

#include "GNDStk.h"
#include "v2.0/documentation/ExforDataSet.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ExforDataSetsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ExforDataSets
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ExforDataSetsClass *ExforDataSets;

// --- Const-aware handles.
typedef const struct ExforDataSetsClass *const ConstHandle2ConstExforDataSets;
typedef       struct ExforDataSetsClass *const ConstHandle2ExforDataSets;
typedef const struct ExforDataSetsClass *      Handle2ConstExforDataSets;
typedef       struct ExforDataSetsClass *      Handle2ExforDataSets;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstExforDataSets
ExforDataSetsDefaultConst();

// +++ Create, default
extern_c Handle2ExforDataSets
ExforDataSetsDefault();

// --- Create, general, const
extern_c Handle2ConstExforDataSets
ExforDataSetsCreateConst(
   ConstHandle2ExforDataSet *const exforDataSet, const size_t exforDataSetSize
);

// +++ Create, general
extern_c Handle2ExforDataSets
ExforDataSetsCreate(
   ConstHandle2ExforDataSet *const exforDataSet, const size_t exforDataSetSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ExforDataSetsAssign(ConstHandle2ExforDataSets This, ConstHandle2ConstExforDataSets from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ExforDataSetsDelete(ConstHandle2ConstExforDataSets This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ExforDataSetsRead(ConstHandle2ExforDataSets This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ExforDataSetsWrite(ConstHandle2ConstExforDataSets This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ExforDataSetsPrint(ConstHandle2ConstExforDataSets This);

// +++ Print to standard output, as XML
extern_c int
ExforDataSetsPrintXML(ConstHandle2ConstExforDataSets This);

// +++ Print to standard output, as JSON
extern_c int
ExforDataSetsPrintJSON(ConstHandle2ConstExforDataSets This);


// -----------------------------------------------------------------------------
// Child: exforDataSet
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ExforDataSetsExforDataSetHas(ConstHandle2ConstExforDataSets This);

// +++ Clear
extern_c void
ExforDataSetsExforDataSetClear(ConstHandle2ExforDataSets This);

// +++ Size
extern_c size_t
ExforDataSetsExforDataSetSize(ConstHandle2ConstExforDataSets This);

// +++ Add
extern_c void
ExforDataSetsExforDataSetAdd(ConstHandle2ExforDataSets This, ConstHandle2ConstExforDataSet exforDataSet);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstExforDataSet
ExforDataSetsExforDataSetGetConst(ConstHandle2ConstExforDataSets This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2ExforDataSet
ExforDataSetsExforDataSetGet(ConstHandle2ExforDataSets This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
ExforDataSetsExforDataSetSet(
   ConstHandle2ExforDataSets This,
   const size_t index_,
   ConstHandle2ConstExforDataSet exforDataSet
);

// +++ Has, by subentry
extern_c int
ExforDataSetsExforDataSetHasBySubentry(
   ConstHandle2ConstExforDataSets This,
   const XMLName subentry
);

// --- Get, by subentry, const
extern_c Handle2ConstExforDataSet
ExforDataSetsExforDataSetGetBySubentryConst(
   ConstHandle2ConstExforDataSets This,
   const XMLName subentry
);

// +++ Get, by subentry, non-const
extern_c Handle2ExforDataSet
ExforDataSetsExforDataSetGetBySubentry(
   ConstHandle2ExforDataSets This,
   const XMLName subentry
);

// +++ Set, by subentry
extern_c void
ExforDataSetsExforDataSetSetBySubentry(
   ConstHandle2ExforDataSets This,
   const XMLName subentry,
   ConstHandle2ConstExforDataSet exforDataSet
);

// +++ Has, by retrievalDate
extern_c int
ExforDataSetsExforDataSetHasByRetrievalDate(
   ConstHandle2ConstExforDataSets This,
   const char *const retrievalDate
);

// --- Get, by retrievalDate, const
extern_c Handle2ConstExforDataSet
ExforDataSetsExforDataSetGetByRetrievalDateConst(
   ConstHandle2ConstExforDataSets This,
   const char *const retrievalDate
);

// +++ Get, by retrievalDate, non-const
extern_c Handle2ExforDataSet
ExforDataSetsExforDataSetGetByRetrievalDate(
   ConstHandle2ExforDataSets This,
   const char *const retrievalDate
);

// +++ Set, by retrievalDate
extern_c void
ExforDataSetsExforDataSetSetByRetrievalDate(
   ConstHandle2ExforDataSets This,
   const char *const retrievalDate,
   ConstHandle2ConstExforDataSet exforDataSet
);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
