
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
// ParameterCovariances is the basic handle type in this file. Example:
//    // Create a default ParameterCovariances object:
//    ParameterCovariances handle = ParameterCovariancesDefault();
// Functions involving ParameterCovariances are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_COVARIANCE_PARAMETERCOVARIANCES
#define C_INTERFACE_TEST_V2_0_COVARIANCE_PARAMETERCOVARIANCES

#include "GNDStk.h"
#include "v2.0/covariance/AverageParameterCovariance.h"
#include "v2.0/covariance/ParameterCovariance.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ParameterCovariancesClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ParameterCovariances
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ParameterCovariancesClass *ParameterCovariances;

// --- Const-aware handles.
typedef const struct ParameterCovariancesClass *const ConstHandle2ConstParameterCovariances;
typedef       struct ParameterCovariancesClass *const ConstHandle2ParameterCovariances;
typedef const struct ParameterCovariancesClass *      Handle2ConstParameterCovariances;
typedef       struct ParameterCovariancesClass *      Handle2ParameterCovariances;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstParameterCovariances
ParameterCovariancesDefaultConst();

// +++ Create, default
extern_c Handle2ParameterCovariances
ParameterCovariancesDefault();

// --- Create, general, const
extern_c Handle2ConstParameterCovariances
ParameterCovariancesCreateConst(
   ConstHandle2AverageParameterCovariance *const averageParameterCovariance, const size_t averageParameterCovarianceSize,
   ConstHandle2ParameterCovariance *const parameterCovariance, const size_t parameterCovarianceSize
);

// +++ Create, general
extern_c Handle2ParameterCovariances
ParameterCovariancesCreate(
   ConstHandle2AverageParameterCovariance *const averageParameterCovariance, const size_t averageParameterCovarianceSize,
   ConstHandle2ParameterCovariance *const parameterCovariance, const size_t parameterCovarianceSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ParameterCovariancesAssign(ConstHandle2ParameterCovariances self, ConstHandle2ConstParameterCovariances from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ParameterCovariancesDelete(ConstHandle2ConstParameterCovariances self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ParameterCovariancesRead(ConstHandle2ParameterCovariances self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ParameterCovariancesWrite(ConstHandle2ConstParameterCovariances self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ParameterCovariancesPrint(ConstHandle2ConstParameterCovariances self);

// +++ Print to standard output, as XML
extern_c int
ParameterCovariancesPrintXML(ConstHandle2ConstParameterCovariances self);

// +++ Print to standard output, as JSON
extern_c int
ParameterCovariancesPrintJSON(ConstHandle2ConstParameterCovariances self);


// -----------------------------------------------------------------------------
// Child: averageParameterCovariance
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ParameterCovariancesAverageParameterCovarianceHas(ConstHandle2ConstParameterCovariances self);

// +++ Clear
extern_c void
ParameterCovariancesAverageParameterCovarianceClear(ConstHandle2ParameterCovariances self);

// +++ Size
extern_c size_t
ParameterCovariancesAverageParameterCovarianceSize(ConstHandle2ConstParameterCovariances self);

// +++ Add
extern_c void
ParameterCovariancesAverageParameterCovarianceAdd(ConstHandle2ParameterCovariances self, ConstHandle2ConstAverageParameterCovariance averageParameterCovariance);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstAverageParameterCovariance
ParameterCovariancesAverageParameterCovarianceGetConst(ConstHandle2ConstParameterCovariances self, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2AverageParameterCovariance
ParameterCovariancesAverageParameterCovarianceGet(ConstHandle2ParameterCovariances self, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
ParameterCovariancesAverageParameterCovarianceSet(
   ConstHandle2ParameterCovariances self,
   const size_t index_,
   ConstHandle2ConstAverageParameterCovariance averageParameterCovariance
);

// +++ Has, by crossTerm
extern_c int
ParameterCovariancesAverageParameterCovarianceHasByCrossTerm(
   ConstHandle2ConstParameterCovariances self,
   const bool crossTerm
);

// --- Get, by crossTerm, const
extern_c Handle2ConstAverageParameterCovariance
ParameterCovariancesAverageParameterCovarianceGetByCrossTermConst(
   ConstHandle2ConstParameterCovariances self,
   const bool crossTerm
);

// +++ Get, by crossTerm, non-const
extern_c Handle2AverageParameterCovariance
ParameterCovariancesAverageParameterCovarianceGetByCrossTerm(
   ConstHandle2ParameterCovariances self,
   const bool crossTerm
);

// +++ Set, by crossTerm
extern_c void
ParameterCovariancesAverageParameterCovarianceSetByCrossTerm(
   ConstHandle2ParameterCovariances self,
   const bool crossTerm,
   ConstHandle2ConstAverageParameterCovariance averageParameterCovariance
);

// +++ Has, by label
extern_c int
ParameterCovariancesAverageParameterCovarianceHasByLabel(
   ConstHandle2ConstParameterCovariances self,
   const XMLName label
);

// --- Get, by label, const
extern_c Handle2ConstAverageParameterCovariance
ParameterCovariancesAverageParameterCovarianceGetByLabelConst(
   ConstHandle2ConstParameterCovariances self,
   const XMLName label
);

// +++ Get, by label, non-const
extern_c Handle2AverageParameterCovariance
ParameterCovariancesAverageParameterCovarianceGetByLabel(
   ConstHandle2ParameterCovariances self,
   const XMLName label
);

// +++ Set, by label
extern_c void
ParameterCovariancesAverageParameterCovarianceSetByLabel(
   ConstHandle2ParameterCovariances self,
   const XMLName label,
   ConstHandle2ConstAverageParameterCovariance averageParameterCovariance
);


// -----------------------------------------------------------------------------
// Child: parameterCovariance
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ParameterCovariancesParameterCovarianceHas(ConstHandle2ConstParameterCovariances self);

// +++ Clear
extern_c void
ParameterCovariancesParameterCovarianceClear(ConstHandle2ParameterCovariances self);

// +++ Size
extern_c size_t
ParameterCovariancesParameterCovarianceSize(ConstHandle2ConstParameterCovariances self);

// +++ Add
extern_c void
ParameterCovariancesParameterCovarianceAdd(ConstHandle2ParameterCovariances self, ConstHandle2ConstParameterCovariance parameterCovariance);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstParameterCovariance
ParameterCovariancesParameterCovarianceGetConst(ConstHandle2ConstParameterCovariances self, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2ParameterCovariance
ParameterCovariancesParameterCovarianceGet(ConstHandle2ParameterCovariances self, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
ParameterCovariancesParameterCovarianceSet(
   ConstHandle2ParameterCovariances self,
   const size_t index_,
   ConstHandle2ConstParameterCovariance parameterCovariance
);

// +++ Has, by label
extern_c int
ParameterCovariancesParameterCovarianceHasByLabel(
   ConstHandle2ConstParameterCovariances self,
   const XMLName label
);

// --- Get, by label, const
extern_c Handle2ConstParameterCovariance
ParameterCovariancesParameterCovarianceGetByLabelConst(
   ConstHandle2ConstParameterCovariances self,
   const XMLName label
);

// +++ Get, by label, non-const
extern_c Handle2ParameterCovariance
ParameterCovariancesParameterCovarianceGetByLabel(
   ConstHandle2ParameterCovariances self,
   const XMLName label
);

// +++ Set, by label
extern_c void
ParameterCovariancesParameterCovarianceSetByLabel(
   ConstHandle2ParameterCovariances self,
   const XMLName label,
   ConstHandle2ConstParameterCovariance parameterCovariance
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/covariance/ParameterCovariances/src/custom.h"

#undef extern_c
#endif
