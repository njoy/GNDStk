
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
// CovarianceScript is the basic handle type in this file. Example:
//    // Create a default CovarianceScript object:
//    CovarianceScript handle = CovarianceScriptDefault();
// Functions involving CovarianceScript are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_DOCUMENTATION_COVARIANCESCRIPT
#define C_INTERFACE_TRY_V2_0_DOCUMENTATION_COVARIANCESCRIPT

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct CovarianceScriptClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ CovarianceScript
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct CovarianceScriptClass *CovarianceScript;

// --- Const-aware handles.
typedef const struct CovarianceScriptClass *const ConstHandle2ConstCovarianceScript;
typedef       struct CovarianceScriptClass *const ConstHandle2CovarianceScript;
typedef const struct CovarianceScriptClass *      Handle2ConstCovarianceScript;
typedef       struct CovarianceScriptClass *      Handle2CovarianceScript;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstCovarianceScript
CovarianceScriptDefaultConst();

// +++ Create, default
extern_c Handle2CovarianceScript
CovarianceScriptDefault();

// --- Create, general, const
extern_c Handle2ConstCovarianceScript
CovarianceScriptCreateConst(
   const XMLName encoding,
   const char *const markup,
   const XMLName label
);

// +++ Create, general
extern_c Handle2CovarianceScript
CovarianceScriptCreate(
   const XMLName encoding,
   const char *const markup,
   const XMLName label
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
CovarianceScriptAssign(ConstHandle2CovarianceScript This, ConstHandle2ConstCovarianceScript from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
CovarianceScriptDelete(ConstHandle2ConstCovarianceScript This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
CovarianceScriptRead(ConstHandle2CovarianceScript This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
CovarianceScriptWrite(ConstHandle2ConstCovarianceScript This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
CovarianceScriptPrint(ConstHandle2ConstCovarianceScript This);

// +++ Print to standard output, as XML
extern_c int
CovarianceScriptPrintXML(ConstHandle2ConstCovarianceScript This);

// +++ Print to standard output, as JSON
extern_c int
CovarianceScriptPrintJSON(ConstHandle2ConstCovarianceScript This);


// -----------------------------------------------------------------------------
// Data vector
// -----------------------------------------------------------------------------

// ------------------------
// int
// ------------------------

// +++ Clear
extern_c void
CovarianceScriptIntsClear(ConstHandle2CovarianceScript This);

// +++ Get size
extern_c size_t
CovarianceScriptIntsSize(ConstHandle2ConstCovarianceScript This);

// +++ Get value
// +++ By index \in [0,size)
extern_c int
CovarianceScriptIntsGet(ConstHandle2ConstCovarianceScript This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
CovarianceScriptIntsSet(ConstHandle2CovarianceScript This, const size_t index, const int value);

// --- Get pointer to existing values, const
extern_c const int *
CovarianceScriptIntsGetArrayConst(ConstHandle2ConstCovarianceScript This);

// +++ Get pointer to existing values, non-const
extern_c int *
CovarianceScriptIntsGetArray(ConstHandle2CovarianceScript This);

// +++ Set completely new values and size
extern_c void
CovarianceScriptIntsSetArray(ConstHandle2CovarianceScript This, const int *const values, const size_t size);

// ------------------------
// unsigned
// ------------------------

// +++ Clear
extern_c void
CovarianceScriptUnsignedsClear(ConstHandle2CovarianceScript This);

// +++ Get size
extern_c size_t
CovarianceScriptUnsignedsSize(ConstHandle2ConstCovarianceScript This);

// +++ Get value
// +++ By index \in [0,size)
extern_c unsigned
CovarianceScriptUnsignedsGet(ConstHandle2ConstCovarianceScript This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
CovarianceScriptUnsignedsSet(ConstHandle2CovarianceScript This, const size_t index, const unsigned value);

// --- Get pointer to existing values, const
extern_c const unsigned *
CovarianceScriptUnsignedsGetArrayConst(ConstHandle2ConstCovarianceScript This);

// +++ Get pointer to existing values, non-const
extern_c unsigned *
CovarianceScriptUnsignedsGetArray(ConstHandle2CovarianceScript This);

// +++ Set completely new values and size
extern_c void
CovarianceScriptUnsignedsSetArray(ConstHandle2CovarianceScript This, const unsigned *const values, const size_t size);

// ------------------------
// float
// ------------------------

// +++ Clear
extern_c void
CovarianceScriptFloatsClear(ConstHandle2CovarianceScript This);

// +++ Get size
extern_c size_t
CovarianceScriptFloatsSize(ConstHandle2ConstCovarianceScript This);

// +++ Get value
// +++ By index \in [0,size)
extern_c float
CovarianceScriptFloatsGet(ConstHandle2ConstCovarianceScript This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
CovarianceScriptFloatsSet(ConstHandle2CovarianceScript This, const size_t index, const float value);

// --- Get pointer to existing values, const
extern_c const float *
CovarianceScriptFloatsGetArrayConst(ConstHandle2ConstCovarianceScript This);

// +++ Get pointer to existing values, non-const
extern_c float *
CovarianceScriptFloatsGetArray(ConstHandle2CovarianceScript This);

// +++ Set completely new values and size
extern_c void
CovarianceScriptFloatsSetArray(ConstHandle2CovarianceScript This, const float *const values, const size_t size);

// ------------------------
// double
// ------------------------

// +++ Clear
extern_c void
CovarianceScriptDoublesClear(ConstHandle2CovarianceScript This);

// +++ Get size
extern_c size_t
CovarianceScriptDoublesSize(ConstHandle2ConstCovarianceScript This);

// +++ Get value
// +++ By index \in [0,size)
extern_c double
CovarianceScriptDoublesGet(ConstHandle2ConstCovarianceScript This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
CovarianceScriptDoublesSet(ConstHandle2CovarianceScript This, const size_t index, const double value);

// --- Get pointer to existing values, const
extern_c const double *
CovarianceScriptDoublesGetArrayConst(ConstHandle2ConstCovarianceScript This);

// +++ Get pointer to existing values, non-const
extern_c double *
CovarianceScriptDoublesGetArray(ConstHandle2CovarianceScript This);

// +++ Set completely new values and size
extern_c void
CovarianceScriptDoublesSetArray(ConstHandle2CovarianceScript This, const double *const values, const size_t size);


// -----------------------------------------------------------------------------
// Metadatum: encoding
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CovarianceScriptEncodingHas(ConstHandle2ConstCovarianceScript This);

// +++ Get
// +++ Returns by value
extern_c XMLName
CovarianceScriptEncodingGet(ConstHandle2ConstCovarianceScript This);

// +++ Set
extern_c void
CovarianceScriptEncodingSet(ConstHandle2CovarianceScript This, const XMLName encoding);


// -----------------------------------------------------------------------------
// Metadatum: markup
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CovarianceScriptMarkupHas(ConstHandle2ConstCovarianceScript This);

// +++ Get
// +++ Returns by value
extern_c const char *
CovarianceScriptMarkupGet(ConstHandle2ConstCovarianceScript This);

// +++ Set
extern_c void
CovarianceScriptMarkupSet(ConstHandle2CovarianceScript This, const char *const markup);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CovarianceScriptLabelHas(ConstHandle2ConstCovarianceScript This);

// +++ Get
// +++ Returns by value
extern_c XMLName
CovarianceScriptLabelGet(ConstHandle2ConstCovarianceScript This);

// +++ Set
extern_c void
CovarianceScriptLabelSet(ConstHandle2CovarianceScript This, const XMLName label);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif