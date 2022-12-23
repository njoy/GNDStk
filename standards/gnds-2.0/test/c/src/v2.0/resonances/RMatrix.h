
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
// RMatrix is the basic handle type in this file. Example:
//    // Create a default RMatrix object:
//    RMatrix handle = RMatrixDefault();
// Functions involving RMatrix are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_RESONANCES_RMATRIX
#define C_INTERFACE_TEST_V2_0_RESONANCES_RMATRIX

#include "GNDStk.h"
#include "v2.0/pops/PoPs_database.h"
#include "v2.0/resonances/ResonanceReactions.h"
#include "v2.0/resonances/SpinGroups.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct RMatrixClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ RMatrix
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct RMatrixClass *RMatrix;

// --- Const-aware handles.
typedef const struct RMatrixClass *const ConstHandle2ConstRMatrix;
typedef       struct RMatrixClass *const ConstHandle2RMatrix;
typedef const struct RMatrixClass *      Handle2ConstRMatrix;
typedef       struct RMatrixClass *      Handle2RMatrix;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstRMatrix
RMatrixDefaultConst();

// +++ Create, default
extern_c Handle2RMatrix
RMatrixDefault();

// --- Create, general, const
extern_c Handle2ConstRMatrix
RMatrixCreateConst(
   const XMLName label,
   const XMLName approximation,
   const enums::BoundaryCondition boundaryCondition,
   const Float64 boundaryConditionValue,
   const bool calculateChannelRadius,
   const bool calculatePenetrability,
   const bool useForSelfShieldingOnly,
   const bool supportsAngularReconstruction,
   ConstHandle2ConstPoPs_database PoPs,
   ConstHandle2ConstResonanceReactions resonanceReactions,
   ConstHandle2ConstSpinGroups spinGroups
);

// +++ Create, general
extern_c Handle2RMatrix
RMatrixCreate(
   const XMLName label,
   const XMLName approximation,
   const enums::BoundaryCondition boundaryCondition,
   const Float64 boundaryConditionValue,
   const bool calculateChannelRadius,
   const bool calculatePenetrability,
   const bool useForSelfShieldingOnly,
   const bool supportsAngularReconstruction,
   ConstHandle2ConstPoPs_database PoPs,
   ConstHandle2ConstResonanceReactions resonanceReactions,
   ConstHandle2ConstSpinGroups spinGroups
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
RMatrixAssign(ConstHandle2RMatrix This, ConstHandle2ConstRMatrix from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
RMatrixDelete(ConstHandle2ConstRMatrix This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
RMatrixRead(ConstHandle2RMatrix This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
RMatrixWrite(ConstHandle2ConstRMatrix This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
RMatrixPrint(ConstHandle2ConstRMatrix This);

// +++ Print to standard output, as XML
extern_c int
RMatrixPrintXML(ConstHandle2ConstRMatrix This);

// +++ Print to standard output, as JSON
extern_c int
RMatrixPrintJSON(ConstHandle2ConstRMatrix This);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
RMatrixLabelHas(ConstHandle2ConstRMatrix This);

// +++ Get
// +++ Returns by value
extern_c XMLName
RMatrixLabelGet(ConstHandle2ConstRMatrix This);

// +++ Set
extern_c void
RMatrixLabelSet(ConstHandle2RMatrix This, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: approximation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
RMatrixApproximationHas(ConstHandle2ConstRMatrix This);

// +++ Get
// +++ Returns by value
extern_c XMLName
RMatrixApproximationGet(ConstHandle2ConstRMatrix This);

// +++ Set
extern_c void
RMatrixApproximationSet(ConstHandle2RMatrix This, const XMLName approximation);


// -----------------------------------------------------------------------------
// Metadatum: boundaryCondition
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
RMatrixBoundaryConditionHas(ConstHandle2ConstRMatrix This);

// +++ Get
// +++ Returns by value
extern_c enums::BoundaryCondition
RMatrixBoundaryConditionGet(ConstHandle2ConstRMatrix This);

// +++ Set
extern_c void
RMatrixBoundaryConditionSet(ConstHandle2RMatrix This, const enums::BoundaryCondition boundaryCondition);


// -----------------------------------------------------------------------------
// Metadatum: boundaryConditionValue
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
RMatrixBoundaryConditionValueHas(ConstHandle2ConstRMatrix This);

// +++ Get
// +++ Returns by value
extern_c Float64
RMatrixBoundaryConditionValueGet(ConstHandle2ConstRMatrix This);

// +++ Set
extern_c void
RMatrixBoundaryConditionValueSet(ConstHandle2RMatrix This, const Float64 boundaryConditionValue);


// -----------------------------------------------------------------------------
// Metadatum: calculateChannelRadius
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
RMatrixCalculateChannelRadiusHas(ConstHandle2ConstRMatrix This);

// +++ Get
// +++ Returns by value
extern_c bool
RMatrixCalculateChannelRadiusGet(ConstHandle2ConstRMatrix This);

// +++ Set
extern_c void
RMatrixCalculateChannelRadiusSet(ConstHandle2RMatrix This, const bool calculateChannelRadius);


// -----------------------------------------------------------------------------
// Metadatum: calculatePenetrability
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
RMatrixCalculatePenetrabilityHas(ConstHandle2ConstRMatrix This);

// +++ Get
// +++ Returns by value
extern_c bool
RMatrixCalculatePenetrabilityGet(ConstHandle2ConstRMatrix This);

// +++ Set
extern_c void
RMatrixCalculatePenetrabilitySet(ConstHandle2RMatrix This, const bool calculatePenetrability);


// -----------------------------------------------------------------------------
// Metadatum: useForSelfShieldingOnly
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
RMatrixUseForSelfShieldingOnlyHas(ConstHandle2ConstRMatrix This);

// +++ Get
// +++ Returns by value
extern_c bool
RMatrixUseForSelfShieldingOnlyGet(ConstHandle2ConstRMatrix This);

// +++ Set
extern_c void
RMatrixUseForSelfShieldingOnlySet(ConstHandle2RMatrix This, const bool useForSelfShieldingOnly);


// -----------------------------------------------------------------------------
// Metadatum: supportsAngularReconstruction
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
RMatrixSupportsAngularReconstructionHas(ConstHandle2ConstRMatrix This);

// +++ Get
// +++ Returns by value
extern_c bool
RMatrixSupportsAngularReconstructionGet(ConstHandle2ConstRMatrix This);

// +++ Set
extern_c void
RMatrixSupportsAngularReconstructionSet(ConstHandle2RMatrix This, const bool supportsAngularReconstruction);


// -----------------------------------------------------------------------------
// Child: PoPs
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
RMatrixPoPs_databaseHas(ConstHandle2ConstRMatrix This);

// --- Get, const
extern_c Handle2ConstPoPs_database
RMatrixPoPs_databaseGetConst(ConstHandle2ConstRMatrix This);

// +++ Get, non-const
extern_c Handle2PoPs_database
RMatrixPoPs_databaseGet(ConstHandle2RMatrix This);

// +++ Set
extern_c void
RMatrixPoPs_databaseSet(ConstHandle2RMatrix This, ConstHandle2ConstPoPs_database PoPs);


// -----------------------------------------------------------------------------
// Child: resonanceReactions
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
RMatrixResonanceReactionsHas(ConstHandle2ConstRMatrix This);

// --- Get, const
extern_c Handle2ConstResonanceReactions
RMatrixResonanceReactionsGetConst(ConstHandle2ConstRMatrix This);

// +++ Get, non-const
extern_c Handle2ResonanceReactions
RMatrixResonanceReactionsGet(ConstHandle2RMatrix This);

// +++ Set
extern_c void
RMatrixResonanceReactionsSet(ConstHandle2RMatrix This, ConstHandle2ConstResonanceReactions resonanceReactions);


// -----------------------------------------------------------------------------
// Child: spinGroups
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
RMatrixSpinGroupsHas(ConstHandle2ConstRMatrix This);

// --- Get, const
extern_c Handle2ConstSpinGroups
RMatrixSpinGroupsGetConst(ConstHandle2ConstRMatrix This);

// +++ Get, non-const
extern_c Handle2SpinGroups
RMatrixSpinGroupsGet(ConstHandle2RMatrix This);

// +++ Set
extern_c void
RMatrixSpinGroupsSet(ConstHandle2RMatrix This, ConstHandle2ConstSpinGroups spinGroups);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
