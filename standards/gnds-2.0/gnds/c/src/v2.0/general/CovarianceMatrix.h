
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
// CovarianceMatrix is the basic handle type in this file. Example:
//    // Create a default CovarianceMatrix object:
//    CovarianceMatrix handle = CovarianceMatrixDefault();
// Functions involving CovarianceMatrix are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_COVARIANCEMATRIX
#define C_INTERFACE_GNDS_V2_0_GENERAL_COVARIANCEMATRIX

#include "GNDStk.h"
#include "v2.0/general/Gridded2d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct CovarianceMatrixClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ CovarianceMatrix
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct CovarianceMatrixClass *CovarianceMatrix;

// --- Const-aware handles.
typedef const struct CovarianceMatrixClass *const ConstHandle2ConstCovarianceMatrix;
typedef       struct CovarianceMatrixClass *const ConstHandle2CovarianceMatrix;
typedef const struct CovarianceMatrixClass *      Handle2ConstCovarianceMatrix;
typedef       struct CovarianceMatrixClass *      Handle2CovarianceMatrix;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstCovarianceMatrix
CovarianceMatrixDefaultConst();

// +++ Create, default
extern_c Handle2CovarianceMatrix
CovarianceMatrixDefault();

// --- Create, general, const
extern_c Handle2ConstCovarianceMatrix
CovarianceMatrixCreateConst(
   const char *const label,
   const char *const type,
   const char *const productFrame,
   ConstHandle2ConstGridded2d gridded2d
);

// +++ Create, general
extern_c Handle2CovarianceMatrix
CovarianceMatrixCreate(
   const char *const label,
   const char *const type,
   const char *const productFrame,
   ConstHandle2ConstGridded2d gridded2d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
CovarianceMatrixAssign(ConstHandle2CovarianceMatrix self, ConstHandle2ConstCovarianceMatrix from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
CovarianceMatrixDelete(ConstHandle2ConstCovarianceMatrix self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
CovarianceMatrixRead(ConstHandle2CovarianceMatrix self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
CovarianceMatrixWrite(ConstHandle2ConstCovarianceMatrix self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
CovarianceMatrixPrint(ConstHandle2ConstCovarianceMatrix self);

// +++ Print to standard output, as XML
extern_c int
CovarianceMatrixPrintXML(ConstHandle2ConstCovarianceMatrix self);

// +++ Print to standard output, as JSON
extern_c int
CovarianceMatrixPrintJSON(ConstHandle2ConstCovarianceMatrix self);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CovarianceMatrixLabelHas(ConstHandle2ConstCovarianceMatrix self);

// +++ Get
// +++ Returns by value
extern_c const char *
CovarianceMatrixLabelGet(ConstHandle2ConstCovarianceMatrix self);

// +++ Set
extern_c void
CovarianceMatrixLabelSet(ConstHandle2CovarianceMatrix self, const char *const label);


// -----------------------------------------------------------------------------
// Metadatum: type
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CovarianceMatrixTypeHas(ConstHandle2ConstCovarianceMatrix self);

// +++ Get
// +++ Returns by value
extern_c const char *
CovarianceMatrixTypeGet(ConstHandle2ConstCovarianceMatrix self);

// +++ Set
extern_c void
CovarianceMatrixTypeSet(ConstHandle2CovarianceMatrix self, const char *const type);


// -----------------------------------------------------------------------------
// Metadatum: productFrame
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CovarianceMatrixProductFrameHas(ConstHandle2ConstCovarianceMatrix self);

// +++ Get
// +++ Returns by value
extern_c const char *
CovarianceMatrixProductFrameGet(ConstHandle2ConstCovarianceMatrix self);

// +++ Set
extern_c void
CovarianceMatrixProductFrameSet(ConstHandle2CovarianceMatrix self, const char *const productFrame);


// -----------------------------------------------------------------------------
// Child: gridded2d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CovarianceMatrixGridded2dHas(ConstHandle2ConstCovarianceMatrix self);

// --- Get, const
extern_c Handle2ConstGridded2d
CovarianceMatrixGridded2dGetConst(ConstHandle2ConstCovarianceMatrix self);

// +++ Get, non-const
extern_c Handle2Gridded2d
CovarianceMatrixGridded2dGet(ConstHandle2CovarianceMatrix self);

// +++ Set
extern_c void
CovarianceMatrixGridded2dSet(ConstHandle2CovarianceMatrix self, ConstHandle2ConstGridded2d gridded2d);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/CovarianceMatrix/src/custom.h"

#undef extern_c
#endif
