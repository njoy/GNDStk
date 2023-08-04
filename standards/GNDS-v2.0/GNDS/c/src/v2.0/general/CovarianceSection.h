
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
// CovarianceSection is the basic handle type in this file. Example:
//    // Create a default CovarianceSection object:
//    CovarianceSection handle = CovarianceSectionDefault();
// Functions involving CovarianceSection are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_COVARIANCESECTION
#define C_INTERFACE_GNDS_V2_0_GENERAL_COVARIANCESECTION

#include "GNDStk.h"
#include "v2.0/general/RowData.h"
#include "v2.0/general/ColumnData.h"
#include "v2.0/general/CovarianceMatrix.h"
#include "v2.0/general/Mixed.h"
#include "v2.0/general/Sum.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct CovarianceSectionClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ CovarianceSection
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct CovarianceSectionClass *CovarianceSection;

// --- Const-aware handles.
typedef const struct CovarianceSectionClass *const ConstHandle2ConstCovarianceSection;
typedef       struct CovarianceSectionClass *const ConstHandle2CovarianceSection;
typedef const struct CovarianceSectionClass *      Handle2ConstCovarianceSection;
typedef       struct CovarianceSectionClass *      Handle2CovarianceSection;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstCovarianceSection
CovarianceSectionDefaultConst();

// +++ Create, default
extern_c Handle2CovarianceSection
CovarianceSectionDefault();

// --- Create, general, const
extern_c Handle2ConstCovarianceSection
CovarianceSectionCreateConst(
   const char *const label,
   const bool crossTerm,
   ConstHandle2ConstRowData rowData,
   ConstHandle2ConstColumnData columnData,
   ConstHandle2ConstCovarianceMatrix covarianceMatrix,
   ConstHandle2ConstMixed mixed,
   ConstHandle2ConstSum sum
);

// +++ Create, general
extern_c Handle2CovarianceSection
CovarianceSectionCreate(
   const char *const label,
   const bool crossTerm,
   ConstHandle2ConstRowData rowData,
   ConstHandle2ConstColumnData columnData,
   ConstHandle2ConstCovarianceMatrix covarianceMatrix,
   ConstHandle2ConstMixed mixed,
   ConstHandle2ConstSum sum
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
CovarianceSectionAssign(ConstHandle2CovarianceSection self, ConstHandle2ConstCovarianceSection from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
CovarianceSectionDelete(ConstHandle2ConstCovarianceSection self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
CovarianceSectionRead(ConstHandle2CovarianceSection self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
CovarianceSectionWrite(ConstHandle2ConstCovarianceSection self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
CovarianceSectionPrint(ConstHandle2ConstCovarianceSection self);

// +++ Print to standard output, as XML
extern_c int
CovarianceSectionPrintXML(ConstHandle2ConstCovarianceSection self);

// +++ Print to standard output, as JSON
extern_c int
CovarianceSectionPrintJSON(ConstHandle2ConstCovarianceSection self);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CovarianceSectionLabelHas(ConstHandle2ConstCovarianceSection self);

// +++ Get
// +++ Returns by value
extern_c const char *
CovarianceSectionLabelGet(ConstHandle2ConstCovarianceSection self);

// +++ Set
extern_c void
CovarianceSectionLabelSet(ConstHandle2CovarianceSection self, const char *const label);


// -----------------------------------------------------------------------------
// Metadatum: crossTerm
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CovarianceSectionCrossTermHas(ConstHandle2ConstCovarianceSection self);

// +++ Get
// +++ Returns by value
extern_c bool
CovarianceSectionCrossTermGet(ConstHandle2ConstCovarianceSection self);

// +++ Set
extern_c void
CovarianceSectionCrossTermSet(ConstHandle2CovarianceSection self, const bool crossTerm);


// -----------------------------------------------------------------------------
// Child: rowData
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CovarianceSectionRowDataHas(ConstHandle2ConstCovarianceSection self);

// --- Get, const
extern_c Handle2ConstRowData
CovarianceSectionRowDataGetConst(ConstHandle2ConstCovarianceSection self);

// +++ Get, non-const
extern_c Handle2RowData
CovarianceSectionRowDataGet(ConstHandle2CovarianceSection self);

// +++ Set
extern_c void
CovarianceSectionRowDataSet(ConstHandle2CovarianceSection self, ConstHandle2ConstRowData rowData);


// -----------------------------------------------------------------------------
// Child: columnData
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CovarianceSectionColumnDataHas(ConstHandle2ConstCovarianceSection self);

// --- Get, const
extern_c Handle2ConstColumnData
CovarianceSectionColumnDataGetConst(ConstHandle2ConstCovarianceSection self);

// +++ Get, non-const
extern_c Handle2ColumnData
CovarianceSectionColumnDataGet(ConstHandle2CovarianceSection self);

// +++ Set
extern_c void
CovarianceSectionColumnDataSet(ConstHandle2CovarianceSection self, ConstHandle2ConstColumnData columnData);


// -----------------------------------------------------------------------------
// Child: covarianceMatrix
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CovarianceSectionCovarianceMatrixHas(ConstHandle2ConstCovarianceSection self);

// --- Get, const
extern_c Handle2ConstCovarianceMatrix
CovarianceSectionCovarianceMatrixGetConst(ConstHandle2ConstCovarianceSection self);

// +++ Get, non-const
extern_c Handle2CovarianceMatrix
CovarianceSectionCovarianceMatrixGet(ConstHandle2CovarianceSection self);

// +++ Set
extern_c void
CovarianceSectionCovarianceMatrixSet(ConstHandle2CovarianceSection self, ConstHandle2ConstCovarianceMatrix covarianceMatrix);


// -----------------------------------------------------------------------------
// Child: mixed
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CovarianceSectionMixedHas(ConstHandle2ConstCovarianceSection self);

// --- Get, const
extern_c Handle2ConstMixed
CovarianceSectionMixedGetConst(ConstHandle2ConstCovarianceSection self);

// +++ Get, non-const
extern_c Handle2Mixed
CovarianceSectionMixedGet(ConstHandle2CovarianceSection self);

// +++ Set
extern_c void
CovarianceSectionMixedSet(ConstHandle2CovarianceSection self, ConstHandle2ConstMixed mixed);


// -----------------------------------------------------------------------------
// Child: sum
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CovarianceSectionSumHas(ConstHandle2ConstCovarianceSection self);

// --- Get, const
extern_c Handle2ConstSum
CovarianceSectionSumGetConst(ConstHandle2ConstCovarianceSection self);

// +++ Get, non-const
extern_c Handle2Sum
CovarianceSectionSumGet(ConstHandle2CovarianceSection self);

// +++ Set
extern_c void
CovarianceSectionSumSet(ConstHandle2CovarianceSection self, ConstHandle2ConstSum sum);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/CovarianceSection/src/custom.h"

#undef extern_c
#endif