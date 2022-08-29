
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
// CorrectionScript is the basic handle type in this file. Example:
//    // Create a default CorrectionScript object:
//    CorrectionScript handle = CorrectionScriptDefault();
// Functions involving CorrectionScript are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_DOCUMENTATION_CORRECTIONSCRIPT
#define C_INTERFACE_TRY_V2_0_DOCUMENTATION_CORRECTIONSCRIPT

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct CorrectionScriptClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ CorrectionScript
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct CorrectionScriptClass *CorrectionScript;

// --- Const-aware handles.
typedef const struct CorrectionScriptClass *const ConstHandle2ConstCorrectionScript;
typedef       struct CorrectionScriptClass *const ConstHandle2CorrectionScript;
typedef const struct CorrectionScriptClass *      Handle2ConstCorrectionScript;
typedef       struct CorrectionScriptClass *      Handle2CorrectionScript;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstCorrectionScript
CorrectionScriptDefaultConst();

// +++ Create, default
extern_c Handle2CorrectionScript
CorrectionScriptDefault();

// --- Create, general, const
extern_c Handle2ConstCorrectionScript
CorrectionScriptCreateConst(
   const XMLName encoding,
   const char *const markup,
   const XMLName label
);

// +++ Create, general
extern_c Handle2CorrectionScript
CorrectionScriptCreate(
   const XMLName encoding,
   const char *const markup,
   const XMLName label
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
CorrectionScriptAssign(ConstHandle2CorrectionScript This, ConstHandle2ConstCorrectionScript from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
CorrectionScriptDelete(ConstHandle2ConstCorrectionScript This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
CorrectionScriptRead(ConstHandle2CorrectionScript This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
CorrectionScriptWrite(ConstHandle2ConstCorrectionScript This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
CorrectionScriptPrint(ConstHandle2ConstCorrectionScript This);

// +++ Print to standard output, as XML
extern_c int
CorrectionScriptPrintXML(ConstHandle2ConstCorrectionScript This);

// +++ Print to standard output, as JSON
extern_c int
CorrectionScriptPrintJSON(ConstHandle2ConstCorrectionScript This);


// -----------------------------------------------------------------------------
// Data vector
// -----------------------------------------------------------------------------

// ------------------------
// int
// ------------------------

// +++ Clear
extern_c void
CorrectionScriptIntsClear(ConstHandle2CorrectionScript This);

// +++ Get size
extern_c size_t
CorrectionScriptIntsSize(ConstHandle2ConstCorrectionScript This);

// +++ Get value
// +++ By index \in [0,size)
extern_c int
CorrectionScriptIntsGet(ConstHandle2ConstCorrectionScript This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
CorrectionScriptIntsSet(ConstHandle2CorrectionScript This, const size_t index, const int value);

// --- Get pointer to existing values, const
extern_c const int *
CorrectionScriptIntsGetArrayConst(ConstHandle2ConstCorrectionScript This);

// +++ Get pointer to existing values, non-const
extern_c int *
CorrectionScriptIntsGetArray(ConstHandle2CorrectionScript This);

// +++ Set completely new values and size
extern_c void
CorrectionScriptIntsSetArray(ConstHandle2CorrectionScript This, const int *const values, const size_t size);

// ------------------------
// unsigned
// ------------------------

// +++ Clear
extern_c void
CorrectionScriptUnsignedsClear(ConstHandle2CorrectionScript This);

// +++ Get size
extern_c size_t
CorrectionScriptUnsignedsSize(ConstHandle2ConstCorrectionScript This);

// +++ Get value
// +++ By index \in [0,size)
extern_c unsigned
CorrectionScriptUnsignedsGet(ConstHandle2ConstCorrectionScript This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
CorrectionScriptUnsignedsSet(ConstHandle2CorrectionScript This, const size_t index, const unsigned value);

// --- Get pointer to existing values, const
extern_c const unsigned *
CorrectionScriptUnsignedsGetArrayConst(ConstHandle2ConstCorrectionScript This);

// +++ Get pointer to existing values, non-const
extern_c unsigned *
CorrectionScriptUnsignedsGetArray(ConstHandle2CorrectionScript This);

// +++ Set completely new values and size
extern_c void
CorrectionScriptUnsignedsSetArray(ConstHandle2CorrectionScript This, const unsigned *const values, const size_t size);

// ------------------------
// float
// ------------------------

// +++ Clear
extern_c void
CorrectionScriptFloatsClear(ConstHandle2CorrectionScript This);

// +++ Get size
extern_c size_t
CorrectionScriptFloatsSize(ConstHandle2ConstCorrectionScript This);

// +++ Get value
// +++ By index \in [0,size)
extern_c float
CorrectionScriptFloatsGet(ConstHandle2ConstCorrectionScript This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
CorrectionScriptFloatsSet(ConstHandle2CorrectionScript This, const size_t index, const float value);

// --- Get pointer to existing values, const
extern_c const float *
CorrectionScriptFloatsGetArrayConst(ConstHandle2ConstCorrectionScript This);

// +++ Get pointer to existing values, non-const
extern_c float *
CorrectionScriptFloatsGetArray(ConstHandle2CorrectionScript This);

// +++ Set completely new values and size
extern_c void
CorrectionScriptFloatsSetArray(ConstHandle2CorrectionScript This, const float *const values, const size_t size);

// ------------------------
// double
// ------------------------

// +++ Clear
extern_c void
CorrectionScriptDoublesClear(ConstHandle2CorrectionScript This);

// +++ Get size
extern_c size_t
CorrectionScriptDoublesSize(ConstHandle2ConstCorrectionScript This);

// +++ Get value
// +++ By index \in [0,size)
extern_c double
CorrectionScriptDoublesGet(ConstHandle2ConstCorrectionScript This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
CorrectionScriptDoublesSet(ConstHandle2CorrectionScript This, const size_t index, const double value);

// --- Get pointer to existing values, const
extern_c const double *
CorrectionScriptDoublesGetArrayConst(ConstHandle2ConstCorrectionScript This);

// +++ Get pointer to existing values, non-const
extern_c double *
CorrectionScriptDoublesGetArray(ConstHandle2CorrectionScript This);

// +++ Set completely new values and size
extern_c void
CorrectionScriptDoublesSetArray(ConstHandle2CorrectionScript This, const double *const values, const size_t size);


// -----------------------------------------------------------------------------
// Metadatum: encoding
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CorrectionScriptEncodingHas(ConstHandle2ConstCorrectionScript This);

// +++ Get
// +++ Returns by value
extern_c XMLName
CorrectionScriptEncodingGet(ConstHandle2ConstCorrectionScript This);

// +++ Set
extern_c void
CorrectionScriptEncodingSet(ConstHandle2CorrectionScript This, const XMLName encoding);


// -----------------------------------------------------------------------------
// Metadatum: markup
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CorrectionScriptMarkupHas(ConstHandle2ConstCorrectionScript This);

// +++ Get
// +++ Returns by value
extern_c const char *
CorrectionScriptMarkupGet(ConstHandle2ConstCorrectionScript This);

// +++ Set
extern_c void
CorrectionScriptMarkupSet(ConstHandle2CorrectionScript This, const char *const markup);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CorrectionScriptLabelHas(ConstHandle2ConstCorrectionScript This);

// +++ Get
// +++ Returns by value
extern_c XMLName
CorrectionScriptLabelGet(ConstHandle2ConstCorrectionScript This);

// +++ Set
extern_c void
CorrectionScriptLabelSet(ConstHandle2CorrectionScript This, const XMLName label);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
