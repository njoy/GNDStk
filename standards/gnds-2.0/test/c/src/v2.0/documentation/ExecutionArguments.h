
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
// ExecutionArguments is the basic handle type in this file. Example:
//    // Create a default ExecutionArguments object:
//    ExecutionArguments handle = ExecutionArgumentsDefault();
// Functions involving ExecutionArguments are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_DOCUMENTATION_EXECUTIONARGUMENTS
#define C_INTERFACE_TEST_V2_0_DOCUMENTATION_EXECUTIONARGUMENTS

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ExecutionArgumentsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ExecutionArguments
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ExecutionArgumentsClass *ExecutionArguments;

// --- Const-aware handles.
typedef const struct ExecutionArgumentsClass *const ConstHandle2ConstExecutionArguments;
typedef       struct ExecutionArgumentsClass *const ConstHandle2ExecutionArguments;
typedef const struct ExecutionArgumentsClass *      Handle2ConstExecutionArguments;
typedef       struct ExecutionArgumentsClass *      Handle2ExecutionArguments;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstExecutionArguments
ExecutionArgumentsDefaultConst();

// +++ Create, default
extern_c Handle2ExecutionArguments
ExecutionArgumentsDefault();

// --- Create, general, const
extern_c Handle2ConstExecutionArguments
ExecutionArgumentsCreateConst(
   const XMLName encoding,
   const char *const markup,
   const XMLName label
);

// +++ Create, general
extern_c Handle2ExecutionArguments
ExecutionArgumentsCreate(
   const XMLName encoding,
   const char *const markup,
   const XMLName label
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ExecutionArgumentsAssign(ConstHandle2ExecutionArguments self, ConstHandle2ConstExecutionArguments from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ExecutionArgumentsDelete(ConstHandle2ConstExecutionArguments self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ExecutionArgumentsRead(ConstHandle2ExecutionArguments self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ExecutionArgumentsWrite(ConstHandle2ConstExecutionArguments self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ExecutionArgumentsPrint(ConstHandle2ConstExecutionArguments self);

// +++ Print to standard output, as XML
extern_c int
ExecutionArgumentsPrintXML(ConstHandle2ConstExecutionArguments self);

// +++ Print to standard output, as JSON
extern_c int
ExecutionArgumentsPrintJSON(ConstHandle2ConstExecutionArguments self);


// -----------------------------------------------------------------------------
// Data vector
// -----------------------------------------------------------------------------

// ------------------------
// int
// ------------------------

// +++ Clear
extern_c void
ExecutionArgumentsIntsClear(ConstHandle2ExecutionArguments self);

// +++ Get size
extern_c size_t
ExecutionArgumentsIntsSize(ConstHandle2ConstExecutionArguments self);

// +++ Get value
// +++ By index \in [0,size)
extern_c int
ExecutionArgumentsIntsGet(ConstHandle2ConstExecutionArguments self, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
ExecutionArgumentsIntsSet(ConstHandle2ExecutionArguments self, const size_t index, const int value);

// --- Get pointer to existing values, const
extern_c const int *
ExecutionArgumentsIntsGetArrayConst(ConstHandle2ConstExecutionArguments self);

// +++ Get pointer to existing values, non-const
extern_c int *
ExecutionArgumentsIntsGetArray(ConstHandle2ExecutionArguments self);

// +++ Set completely new values and size
extern_c void
ExecutionArgumentsIntsSetArray(ConstHandle2ExecutionArguments self, const int *const values, const size_t size);

// ------------------------
// unsigned
// ------------------------

// +++ Clear
extern_c void
ExecutionArgumentsUnsignedsClear(ConstHandle2ExecutionArguments self);

// +++ Get size
extern_c size_t
ExecutionArgumentsUnsignedsSize(ConstHandle2ConstExecutionArguments self);

// +++ Get value
// +++ By index \in [0,size)
extern_c unsigned
ExecutionArgumentsUnsignedsGet(ConstHandle2ConstExecutionArguments self, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
ExecutionArgumentsUnsignedsSet(ConstHandle2ExecutionArguments self, const size_t index, const unsigned value);

// --- Get pointer to existing values, const
extern_c const unsigned *
ExecutionArgumentsUnsignedsGetArrayConst(ConstHandle2ConstExecutionArguments self);

// +++ Get pointer to existing values, non-const
extern_c unsigned *
ExecutionArgumentsUnsignedsGetArray(ConstHandle2ExecutionArguments self);

// +++ Set completely new values and size
extern_c void
ExecutionArgumentsUnsignedsSetArray(ConstHandle2ExecutionArguments self, const unsigned *const values, const size_t size);

// ------------------------
// float
// ------------------------

// +++ Clear
extern_c void
ExecutionArgumentsFloatsClear(ConstHandle2ExecutionArguments self);

// +++ Get size
extern_c size_t
ExecutionArgumentsFloatsSize(ConstHandle2ConstExecutionArguments self);

// +++ Get value
// +++ By index \in [0,size)
extern_c float
ExecutionArgumentsFloatsGet(ConstHandle2ConstExecutionArguments self, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
ExecutionArgumentsFloatsSet(ConstHandle2ExecutionArguments self, const size_t index, const float value);

// --- Get pointer to existing values, const
extern_c const float *
ExecutionArgumentsFloatsGetArrayConst(ConstHandle2ConstExecutionArguments self);

// +++ Get pointer to existing values, non-const
extern_c float *
ExecutionArgumentsFloatsGetArray(ConstHandle2ExecutionArguments self);

// +++ Set completely new values and size
extern_c void
ExecutionArgumentsFloatsSetArray(ConstHandle2ExecutionArguments self, const float *const values, const size_t size);

// ------------------------
// double
// ------------------------

// +++ Clear
extern_c void
ExecutionArgumentsDoublesClear(ConstHandle2ExecutionArguments self);

// +++ Get size
extern_c size_t
ExecutionArgumentsDoublesSize(ConstHandle2ConstExecutionArguments self);

// +++ Get value
// +++ By index \in [0,size)
extern_c double
ExecutionArgumentsDoublesGet(ConstHandle2ConstExecutionArguments self, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
ExecutionArgumentsDoublesSet(ConstHandle2ExecutionArguments self, const size_t index, const double value);

// --- Get pointer to existing values, const
extern_c const double *
ExecutionArgumentsDoublesGetArrayConst(ConstHandle2ConstExecutionArguments self);

// +++ Get pointer to existing values, non-const
extern_c double *
ExecutionArgumentsDoublesGetArray(ConstHandle2ExecutionArguments self);

// +++ Set completely new values and size
extern_c void
ExecutionArgumentsDoublesSetArray(ConstHandle2ExecutionArguments self, const double *const values, const size_t size);


// -----------------------------------------------------------------------------
// Metadatum: encoding
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ExecutionArgumentsEncodingHas(ConstHandle2ConstExecutionArguments self);

// +++ Get
// +++ Returns by value
extern_c XMLName
ExecutionArgumentsEncodingGet(ConstHandle2ConstExecutionArguments self);

// +++ Set
extern_c void
ExecutionArgumentsEncodingSet(ConstHandle2ExecutionArguments self, const XMLName encoding);


// -----------------------------------------------------------------------------
// Metadatum: markup
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ExecutionArgumentsMarkupHas(ConstHandle2ConstExecutionArguments self);

// +++ Get
// +++ Returns by value
extern_c const char *
ExecutionArgumentsMarkupGet(ConstHandle2ConstExecutionArguments self);

// +++ Set
extern_c void
ExecutionArgumentsMarkupSet(ConstHandle2ExecutionArguments self, const char *const markup);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ExecutionArgumentsLabelHas(ConstHandle2ConstExecutionArguments self);

// +++ Get
// +++ Returns by value
extern_c XMLName
ExecutionArgumentsLabelGet(ConstHandle2ConstExecutionArguments self);

// +++ Set
extern_c void
ExecutionArgumentsLabelSet(ConstHandle2ExecutionArguments self, const XMLName label);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/documentation/ExecutionArguments/src/custom.h"

#undef extern_c
#endif
