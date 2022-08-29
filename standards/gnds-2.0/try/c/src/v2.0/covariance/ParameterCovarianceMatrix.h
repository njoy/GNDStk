
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
// ParameterCovarianceMatrix is the basic handle type in this file. Example:
//    // Create a default ParameterCovarianceMatrix object:
//    ParameterCovarianceMatrix handle = ParameterCovarianceMatrixDefault();
// Functions involving ParameterCovarianceMatrix are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_COVARIANCE_PARAMETERCOVARIANCEMATRIX
#define C_INTERFACE_TRY_V2_0_COVARIANCE_PARAMETERCOVARIANCEMATRIX

#include "GNDStk.h"
#include "v2.0/covariance/Parameters.h"
#include "v2.0/unknownNamespace/Array.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ParameterCovarianceMatrixClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ParameterCovarianceMatrix
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ParameterCovarianceMatrixClass *ParameterCovarianceMatrix;

// --- Const-aware handles.
typedef const struct ParameterCovarianceMatrixClass *const ConstHandle2ConstParameterCovarianceMatrix;
typedef       struct ParameterCovarianceMatrixClass *const ConstHandle2ParameterCovarianceMatrix;
typedef const struct ParameterCovarianceMatrixClass *      Handle2ConstParameterCovarianceMatrix;
typedef       struct ParameterCovarianceMatrixClass *      Handle2ParameterCovarianceMatrix;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstParameterCovarianceMatrix
ParameterCovarianceMatrixDefaultConst();

// +++ Create, default
extern_c Handle2ParameterCovarianceMatrix
ParameterCovarianceMatrixDefault();

// --- Create, general, const
extern_c Handle2ConstParameterCovarianceMatrix
ParameterCovarianceMatrixCreateConst(
   const XMLName label,
   const XMLName type,
   ConstHandle2ConstParameters parameters,
   ConstHandle2ConstArray array
);

// +++ Create, general
extern_c Handle2ParameterCovarianceMatrix
ParameterCovarianceMatrixCreate(
   const XMLName label,
   const XMLName type,
   ConstHandle2ConstParameters parameters,
   ConstHandle2ConstArray array
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ParameterCovarianceMatrixAssign(ConstHandle2ParameterCovarianceMatrix This, ConstHandle2ConstParameterCovarianceMatrix from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ParameterCovarianceMatrixDelete(ConstHandle2ConstParameterCovarianceMatrix This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ParameterCovarianceMatrixRead(ConstHandle2ParameterCovarianceMatrix This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ParameterCovarianceMatrixWrite(ConstHandle2ConstParameterCovarianceMatrix This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ParameterCovarianceMatrixPrint(ConstHandle2ConstParameterCovarianceMatrix This);

// +++ Print to standard output, as XML
extern_c int
ParameterCovarianceMatrixPrintXML(ConstHandle2ConstParameterCovarianceMatrix This);

// +++ Print to standard output, as JSON
extern_c int
ParameterCovarianceMatrixPrintJSON(ConstHandle2ConstParameterCovarianceMatrix This);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ParameterCovarianceMatrixLabelHas(ConstHandle2ConstParameterCovarianceMatrix This);

// +++ Get
// +++ Returns by value
extern_c XMLName
ParameterCovarianceMatrixLabelGet(ConstHandle2ConstParameterCovarianceMatrix This);

// +++ Set
extern_c void
ParameterCovarianceMatrixLabelSet(ConstHandle2ParameterCovarianceMatrix This, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: type
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ParameterCovarianceMatrixTypeHas(ConstHandle2ConstParameterCovarianceMatrix This);

// +++ Get
// +++ Returns by value
extern_c XMLName
ParameterCovarianceMatrixTypeGet(ConstHandle2ConstParameterCovarianceMatrix This);

// +++ Set
extern_c void
ParameterCovarianceMatrixTypeSet(ConstHandle2ParameterCovarianceMatrix This, const XMLName type);


// -----------------------------------------------------------------------------
// Child: parameters
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ParameterCovarianceMatrixParametersHas(ConstHandle2ConstParameterCovarianceMatrix This);

// --- Get, const
extern_c Handle2ConstParameters
ParameterCovarianceMatrixParametersGetConst(ConstHandle2ConstParameterCovarianceMatrix This);

// +++ Get, non-const
extern_c Handle2Parameters
ParameterCovarianceMatrixParametersGet(ConstHandle2ParameterCovarianceMatrix This);

// +++ Set
extern_c void
ParameterCovarianceMatrixParametersSet(ConstHandle2ParameterCovarianceMatrix This, ConstHandle2ConstParameters parameters);


// -----------------------------------------------------------------------------
// Child: array
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ParameterCovarianceMatrixArrayHas(ConstHandle2ConstParameterCovarianceMatrix This);

// --- Get, const
extern_c Handle2ConstArray
ParameterCovarianceMatrixArrayGetConst(ConstHandle2ConstParameterCovarianceMatrix This);

// +++ Get, non-const
extern_c Handle2Array
ParameterCovarianceMatrixArrayGet(ConstHandle2ParameterCovarianceMatrix This);

// +++ Set
extern_c void
ParameterCovarianceMatrixArraySet(ConstHandle2ParameterCovarianceMatrix This, ConstHandle2ConstArray array);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
