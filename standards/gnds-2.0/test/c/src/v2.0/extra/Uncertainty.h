
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
// Uncertainty is the basic handle type in this file. Example:
//    // Create a default Uncertainty object:
//    Uncertainty handle = UncertaintyDefault();
// Functions involving Uncertainty are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_EXTRA_UNCERTAINTY
#define C_INTERFACE_TEST_V2_0_EXTRA_UNCERTAINTY

#include "GNDStk.h"
#include "v2.0/containers/Standard.h"
#include "v2.0/containers/LogNormal.h"
#include "v2.0/containers/ConfidenceIntervals.h"
#include "v2.0/containers/Covariance.h"
#include "v2.0/containers/ListOfCovariances.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct UncertaintyClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Uncertainty
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct UncertaintyClass *Uncertainty;

// --- Const-aware handles.
typedef const struct UncertaintyClass *const ConstHandle2ConstUncertainty;
typedef       struct UncertaintyClass *const ConstHandle2Uncertainty;
typedef const struct UncertaintyClass *      Handle2ConstUncertainty;
typedef       struct UncertaintyClass *      Handle2Uncertainty;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstUncertainty
UncertaintyDefaultConst();

// +++ Create, default
extern_c Handle2Uncertainty
UncertaintyDefault();

// --- Create, general, const
extern_c Handle2ConstUncertainty
UncertaintyCreateConst(
   ConstHandle2ConstStandard standard,
   ConstHandle2ConstLogNormal logNormal,
   ConstHandle2ConstConfidenceIntervals confidenceIntervals,
   ConstHandle2ConstCovariance covariance,
   ConstHandle2ConstListOfCovariances listOfCovariances
);

// +++ Create, general
extern_c Handle2Uncertainty
UncertaintyCreate(
   ConstHandle2ConstStandard standard,
   ConstHandle2ConstLogNormal logNormal,
   ConstHandle2ConstConfidenceIntervals confidenceIntervals,
   ConstHandle2ConstCovariance covariance,
   ConstHandle2ConstListOfCovariances listOfCovariances
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
UncertaintyAssign(ConstHandle2Uncertainty self, ConstHandle2ConstUncertainty from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
UncertaintyDelete(ConstHandle2ConstUncertainty self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
UncertaintyRead(ConstHandle2Uncertainty self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
UncertaintyWrite(ConstHandle2ConstUncertainty self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
UncertaintyPrint(ConstHandle2ConstUncertainty self);

// +++ Print to standard output, as XML
extern_c int
UncertaintyPrintXML(ConstHandle2ConstUncertainty self);

// +++ Print to standard output, as JSON
extern_c int
UncertaintyPrintJSON(ConstHandle2ConstUncertainty self);


// -----------------------------------------------------------------------------
// Child: standard
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
UncertaintyStandardHas(ConstHandle2ConstUncertainty self);

// --- Get, const
extern_c Handle2ConstStandard
UncertaintyStandardGetConst(ConstHandle2ConstUncertainty self);

// +++ Get, non-const
extern_c Handle2Standard
UncertaintyStandardGet(ConstHandle2Uncertainty self);

// +++ Set
extern_c void
UncertaintyStandardSet(ConstHandle2Uncertainty self, ConstHandle2ConstStandard standard);


// -----------------------------------------------------------------------------
// Child: logNormal
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
UncertaintyLogNormalHas(ConstHandle2ConstUncertainty self);

// --- Get, const
extern_c Handle2ConstLogNormal
UncertaintyLogNormalGetConst(ConstHandle2ConstUncertainty self);

// +++ Get, non-const
extern_c Handle2LogNormal
UncertaintyLogNormalGet(ConstHandle2Uncertainty self);

// +++ Set
extern_c void
UncertaintyLogNormalSet(ConstHandle2Uncertainty self, ConstHandle2ConstLogNormal logNormal);


// -----------------------------------------------------------------------------
// Child: confidenceIntervals
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
UncertaintyConfidenceIntervalsHas(ConstHandle2ConstUncertainty self);

// --- Get, const
extern_c Handle2ConstConfidenceIntervals
UncertaintyConfidenceIntervalsGetConst(ConstHandle2ConstUncertainty self);

// +++ Get, non-const
extern_c Handle2ConfidenceIntervals
UncertaintyConfidenceIntervalsGet(ConstHandle2Uncertainty self);

// +++ Set
extern_c void
UncertaintyConfidenceIntervalsSet(ConstHandle2Uncertainty self, ConstHandle2ConstConfidenceIntervals confidenceIntervals);


// -----------------------------------------------------------------------------
// Child: covariance
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
UncertaintyCovarianceHas(ConstHandle2ConstUncertainty self);

// --- Get, const
extern_c Handle2ConstCovariance
UncertaintyCovarianceGetConst(ConstHandle2ConstUncertainty self);

// +++ Get, non-const
extern_c Handle2Covariance
UncertaintyCovarianceGet(ConstHandle2Uncertainty self);

// +++ Set
extern_c void
UncertaintyCovarianceSet(ConstHandle2Uncertainty self, ConstHandle2ConstCovariance covariance);


// -----------------------------------------------------------------------------
// Child: listOfCovariances
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
UncertaintyListOfCovariancesHas(ConstHandle2ConstUncertainty self);

// --- Get, const
extern_c Handle2ConstListOfCovariances
UncertaintyListOfCovariancesGetConst(ConstHandle2ConstUncertainty self);

// +++ Get, non-const
extern_c Handle2ListOfCovariances
UncertaintyListOfCovariancesGet(ConstHandle2Uncertainty self);

// +++ Set
extern_c void
UncertaintyListOfCovariancesSet(ConstHandle2Uncertainty self, ConstHandle2ConstListOfCovariances listOfCovariances);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/extra/Uncertainty/src/custom.h"

#undef extern_c
#endif
