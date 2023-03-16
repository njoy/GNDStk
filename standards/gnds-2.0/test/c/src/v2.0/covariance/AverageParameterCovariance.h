
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
// AverageParameterCovariance is the basic handle type in this file. Example:
//    // Create a default AverageParameterCovariance object:
//    AverageParameterCovariance handle = AverageParameterCovarianceDefault();
// Functions involving AverageParameterCovariance are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_COVARIANCE_AVERAGEPARAMETERCOVARIANCE
#define C_INTERFACE_TEST_V2_0_COVARIANCE_AVERAGEPARAMETERCOVARIANCE

#include "GNDStk.h"
#include "v2.0/covariance/ColumnData.h"
#include "v2.0/covariance/RowData.h"
#include "v2.0/covariance/CovarianceMatrix.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct AverageParameterCovarianceClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ AverageParameterCovariance
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct AverageParameterCovarianceClass *AverageParameterCovariance;

// --- Const-aware handles.
typedef const struct AverageParameterCovarianceClass *const ConstHandle2ConstAverageParameterCovariance;
typedef       struct AverageParameterCovarianceClass *const ConstHandle2AverageParameterCovariance;
typedef const struct AverageParameterCovarianceClass *      Handle2ConstAverageParameterCovariance;
typedef       struct AverageParameterCovarianceClass *      Handle2AverageParameterCovariance;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstAverageParameterCovariance
AverageParameterCovarianceDefaultConst();

// +++ Create, default
extern_c Handle2AverageParameterCovariance
AverageParameterCovarianceDefault();

// --- Create, general, const
extern_c Handle2ConstAverageParameterCovariance
AverageParameterCovarianceCreateConst(
   const bool crossTerm,
   const XMLName label,
   ConstHandle2ConstColumnData columnData,
   ConstHandle2ConstRowData rowData,
);

// +++ Create, general
extern_c Handle2AverageParameterCovariance
AverageParameterCovarianceCreate(
   const bool crossTerm,
   const XMLName label,
   ConstHandle2ConstColumnData columnData,
   ConstHandle2ConstRowData rowData,
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
AverageParameterCovarianceAssign(ConstHandle2AverageParameterCovariance self, ConstHandle2ConstAverageParameterCovariance from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
AverageParameterCovarianceDelete(ConstHandle2ConstAverageParameterCovariance self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
AverageParameterCovarianceRead(ConstHandle2AverageParameterCovariance self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
AverageParameterCovarianceWrite(ConstHandle2ConstAverageParameterCovariance self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
AverageParameterCovariancePrint(ConstHandle2ConstAverageParameterCovariance self);

// +++ Print to standard output, as XML
extern_c int
AverageParameterCovariancePrintXML(ConstHandle2ConstAverageParameterCovariance self);

// +++ Print to standard output, as JSON
extern_c int
AverageParameterCovariancePrintJSON(ConstHandle2ConstAverageParameterCovariance self);


// -----------------------------------------------------------------------------
// Metadatum: crossTerm
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AverageParameterCovarianceCrossTermHas(ConstHandle2ConstAverageParameterCovariance self);

// +++ Get
// +++ Returns by value
extern_c bool
AverageParameterCovarianceCrossTermGet(ConstHandle2ConstAverageParameterCovariance self);

// +++ Set
extern_c void
AverageParameterCovarianceCrossTermSet(ConstHandle2AverageParameterCovariance self, const bool crossTerm);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AverageParameterCovarianceLabelHas(ConstHandle2ConstAverageParameterCovariance self);

// +++ Get
// +++ Returns by value
extern_c XMLName
AverageParameterCovarianceLabelGet(ConstHandle2ConstAverageParameterCovariance self);

// +++ Set
extern_c void
AverageParameterCovarianceLabelSet(ConstHandle2AverageParameterCovariance self, const XMLName label);


// -----------------------------------------------------------------------------
// Child: columnData
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AverageParameterCovarianceColumnDataHas(ConstHandle2ConstAverageParameterCovariance self);

// --- Get, const
extern_c Handle2ConstColumnData
AverageParameterCovarianceColumnDataGetConst(ConstHandle2ConstAverageParameterCovariance self);

// +++ Get, non-const
extern_c Handle2ColumnData
AverageParameterCovarianceColumnDataGet(ConstHandle2AverageParameterCovariance self);

// +++ Set
extern_c void
AverageParameterCovarianceColumnDataSet(ConstHandle2AverageParameterCovariance self, ConstHandle2ConstColumnData columnData);


// -----------------------------------------------------------------------------
// Child: rowData
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AverageParameterCovarianceRowDataHas(ConstHandle2ConstAverageParameterCovariance self);

// --- Get, const
extern_c Handle2ConstRowData
AverageParameterCovarianceRowDataGetConst(ConstHandle2ConstAverageParameterCovariance self);

// +++ Get, non-const
extern_c Handle2RowData
AverageParameterCovarianceRowDataGet(ConstHandle2AverageParameterCovariance self);

// +++ Set
extern_c void
AverageParameterCovarianceRowDataSet(ConstHandle2AverageParameterCovariance self, ConstHandle2ConstRowData rowData);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/covariance/AverageParameterCovariance/src/custom.h"

#undef extern_c
#endif
