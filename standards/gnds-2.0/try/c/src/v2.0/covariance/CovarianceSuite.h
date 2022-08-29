
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
// CovarianceSuite is the basic handle type in this file. Example:
//    // Create a default CovarianceSuite object:
//    CovarianceSuite handle = CovarianceSuiteDefault();
// Functions involving CovarianceSuite are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_COVARIANCE_COVARIANCESUITE
#define C_INTERFACE_TRY_V2_0_COVARIANCE_COVARIANCESUITE

#include "GNDStk.h"
#include "v2.0/common/ExternalFiles.h"
#include "v2.0/styles/Styles.h"
#include "v2.0/covariance/CovarianceSections.h"
#include "v2.0/covariance/ParameterCovariances.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct CovarianceSuiteClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ CovarianceSuite
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct CovarianceSuiteClass *CovarianceSuite;

// --- Const-aware handles.
typedef const struct CovarianceSuiteClass *const ConstHandle2ConstCovarianceSuite;
typedef       struct CovarianceSuiteClass *const ConstHandle2CovarianceSuite;
typedef const struct CovarianceSuiteClass *      Handle2ConstCovarianceSuite;
typedef       struct CovarianceSuiteClass *      Handle2CovarianceSuite;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstCovarianceSuite
CovarianceSuiteDefaultConst();

// +++ Create, default
extern_c Handle2CovarianceSuite
CovarianceSuiteDefault();

// --- Create, general, const
extern_c Handle2ConstCovarianceSuite
CovarianceSuiteCreateConst(
   const XMLName evaluation,
   const XMLName projectile,
   const XMLName target,
   const enums::Interaction interaction,
   const Float64 version,
   ConstHandle2ConstExternalFiles externalFiles,
   ConstHandle2ConstStyles styles,
   ConstHandle2ConstCovarianceSections covarianceSections,
   ConstHandle2ConstParameterCovariances parameterCovariances
);

// +++ Create, general
extern_c Handle2CovarianceSuite
CovarianceSuiteCreate(
   const XMLName evaluation,
   const XMLName projectile,
   const XMLName target,
   const enums::Interaction interaction,
   const Float64 version,
   ConstHandle2ConstExternalFiles externalFiles,
   ConstHandle2ConstStyles styles,
   ConstHandle2ConstCovarianceSections covarianceSections,
   ConstHandle2ConstParameterCovariances parameterCovariances
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
CovarianceSuiteAssign(ConstHandle2CovarianceSuite This, ConstHandle2ConstCovarianceSuite from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
CovarianceSuiteDelete(ConstHandle2ConstCovarianceSuite This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
CovarianceSuiteRead(ConstHandle2CovarianceSuite This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
CovarianceSuiteWrite(ConstHandle2ConstCovarianceSuite This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
CovarianceSuitePrint(ConstHandle2ConstCovarianceSuite This);

// +++ Print to standard output, as XML
extern_c int
CovarianceSuitePrintXML(ConstHandle2ConstCovarianceSuite This);

// +++ Print to standard output, as JSON
extern_c int
CovarianceSuitePrintJSON(ConstHandle2ConstCovarianceSuite This);


// -----------------------------------------------------------------------------
// Metadatum: evaluation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CovarianceSuiteEvaluationHas(ConstHandle2ConstCovarianceSuite This);

// +++ Get
// +++ Returns by value
extern_c XMLName
CovarianceSuiteEvaluationGet(ConstHandle2ConstCovarianceSuite This);

// +++ Set
extern_c void
CovarianceSuiteEvaluationSet(ConstHandle2CovarianceSuite This, const XMLName evaluation);


// -----------------------------------------------------------------------------
// Metadatum: projectile
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CovarianceSuiteProjectileHas(ConstHandle2ConstCovarianceSuite This);

// +++ Get
// +++ Returns by value
extern_c XMLName
CovarianceSuiteProjectileGet(ConstHandle2ConstCovarianceSuite This);

// +++ Set
extern_c void
CovarianceSuiteProjectileSet(ConstHandle2CovarianceSuite This, const XMLName projectile);


// -----------------------------------------------------------------------------
// Metadatum: target
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CovarianceSuiteTargetHas(ConstHandle2ConstCovarianceSuite This);

// +++ Get
// +++ Returns by value
extern_c XMLName
CovarianceSuiteTargetGet(ConstHandle2ConstCovarianceSuite This);

// +++ Set
extern_c void
CovarianceSuiteTargetSet(ConstHandle2CovarianceSuite This, const XMLName target);


// -----------------------------------------------------------------------------
// Metadatum: interaction
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CovarianceSuiteInteractionHas(ConstHandle2ConstCovarianceSuite This);

// +++ Get
// +++ Returns by value
extern_c enums::Interaction
CovarianceSuiteInteractionGet(ConstHandle2ConstCovarianceSuite This);

// +++ Set
extern_c void
CovarianceSuiteInteractionSet(ConstHandle2CovarianceSuite This, const enums::Interaction interaction);


// -----------------------------------------------------------------------------
// Metadatum: version
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CovarianceSuiteVersionHas(ConstHandle2ConstCovarianceSuite This);

// +++ Get
// +++ Returns by value
extern_c Float64
CovarianceSuiteVersionGet(ConstHandle2ConstCovarianceSuite This);

// +++ Set
extern_c void
CovarianceSuiteVersionSet(ConstHandle2CovarianceSuite This, const Float64 version);


// -----------------------------------------------------------------------------
// Child: externalFiles
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CovarianceSuiteExternalFilesHas(ConstHandle2ConstCovarianceSuite This);

// --- Get, const
extern_c Handle2ConstExternalFiles
CovarianceSuiteExternalFilesGetConst(ConstHandle2ConstCovarianceSuite This);

// +++ Get, non-const
extern_c Handle2ExternalFiles
CovarianceSuiteExternalFilesGet(ConstHandle2CovarianceSuite This);

// +++ Set
extern_c void
CovarianceSuiteExternalFilesSet(ConstHandle2CovarianceSuite This, ConstHandle2ConstExternalFiles externalFiles);


// -----------------------------------------------------------------------------
// Child: styles
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CovarianceSuiteStylesHas(ConstHandle2ConstCovarianceSuite This);

// --- Get, const
extern_c Handle2ConstStyles
CovarianceSuiteStylesGetConst(ConstHandle2ConstCovarianceSuite This);

// +++ Get, non-const
extern_c Handle2Styles
CovarianceSuiteStylesGet(ConstHandle2CovarianceSuite This);

// +++ Set
extern_c void
CovarianceSuiteStylesSet(ConstHandle2CovarianceSuite This, ConstHandle2ConstStyles styles);


// -----------------------------------------------------------------------------
// Child: covarianceSections
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CovarianceSuiteCovarianceSectionsHas(ConstHandle2ConstCovarianceSuite This);

// --- Get, const
extern_c Handle2ConstCovarianceSections
CovarianceSuiteCovarianceSectionsGetConst(ConstHandle2ConstCovarianceSuite This);

// +++ Get, non-const
extern_c Handle2CovarianceSections
CovarianceSuiteCovarianceSectionsGet(ConstHandle2CovarianceSuite This);

// +++ Set
extern_c void
CovarianceSuiteCovarianceSectionsSet(ConstHandle2CovarianceSuite This, ConstHandle2ConstCovarianceSections covarianceSections);


// -----------------------------------------------------------------------------
// Child: parameterCovariances
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CovarianceSuiteParameterCovariancesHas(ConstHandle2ConstCovarianceSuite This);

// --- Get, const
extern_c Handle2ConstParameterCovariances
CovarianceSuiteParameterCovariancesGetConst(ConstHandle2ConstCovarianceSuite This);

// +++ Get, non-const
extern_c Handle2ParameterCovariances
CovarianceSuiteParameterCovariancesGet(ConstHandle2CovarianceSuite This);

// +++ Set
extern_c void
CovarianceSuiteParameterCovariancesSet(ConstHandle2CovarianceSuite This, ConstHandle2ConstParameterCovariances parameterCovariances);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
