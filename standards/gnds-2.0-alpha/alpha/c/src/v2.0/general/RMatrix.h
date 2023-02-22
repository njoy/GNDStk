
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

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_RMATRIX
#define C_INTERFACE_ALPHA_V2_0_GENERAL_RMATRIX

#include "GNDStk.h"
#include "v2.0/top/PoPs.h"
#include "v2.0/general/ResonanceReactions.h"
#include "v2.0/general/SpinGroups.h"

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
   const char *const label,
   const char *const approximation,
   const char *const boundaryCondition,
   const bool calculateChannelRadius,
   const bool supportsAngularReconstruction,
   ConstHandle2ConstPoPs PoPs,
   ConstHandle2ConstResonanceReactions resonanceReactions,
   ConstHandle2ConstSpinGroups spinGroups
);

// +++ Create, general
extern_c Handle2RMatrix
RMatrixCreate(
   const char *const label,
   const char *const approximation,
   const char *const boundaryCondition,
   const bool calculateChannelRadius,
   const bool supportsAngularReconstruction,
   ConstHandle2ConstPoPs PoPs,
   ConstHandle2ConstResonanceReactions resonanceReactions,
   ConstHandle2ConstSpinGroups spinGroups
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
RMatrixAssign(ConstHandle2RMatrix self, ConstHandle2ConstRMatrix from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
RMatrixDelete(ConstHandle2ConstRMatrix self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
RMatrixRead(ConstHandle2RMatrix self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
RMatrixWrite(ConstHandle2ConstRMatrix self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
RMatrixPrint(ConstHandle2ConstRMatrix self);

// +++ Print to standard output, as XML
extern_c int
RMatrixPrintXML(ConstHandle2ConstRMatrix self);

// +++ Print to standard output, as JSON
extern_c int
RMatrixPrintJSON(ConstHandle2ConstRMatrix self);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
RMatrixLabelHas(ConstHandle2ConstRMatrix self);

// +++ Get
// +++ Returns by value
extern_c const char *
RMatrixLabelGet(ConstHandle2ConstRMatrix self);

// +++ Set
extern_c void
RMatrixLabelSet(ConstHandle2RMatrix self, const char *const label);


// -----------------------------------------------------------------------------
// Metadatum: approximation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
RMatrixApproximationHas(ConstHandle2ConstRMatrix self);

// +++ Get
// +++ Returns by value
extern_c const char *
RMatrixApproximationGet(ConstHandle2ConstRMatrix self);

// +++ Set
extern_c void
RMatrixApproximationSet(ConstHandle2RMatrix self, const char *const approximation);


// -----------------------------------------------------------------------------
// Metadatum: boundaryCondition
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
RMatrixBoundaryConditionHas(ConstHandle2ConstRMatrix self);

// +++ Get
// +++ Returns by value
extern_c const char *
RMatrixBoundaryConditionGet(ConstHandle2ConstRMatrix self);

// +++ Set
extern_c void
RMatrixBoundaryConditionSet(ConstHandle2RMatrix self, const char *const boundaryCondition);


// -----------------------------------------------------------------------------
// Metadatum: calculateChannelRadius
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
RMatrixCalculateChannelRadiusHas(ConstHandle2ConstRMatrix self);

// +++ Get
// +++ Returns by value
extern_c bool
RMatrixCalculateChannelRadiusGet(ConstHandle2ConstRMatrix self);

// +++ Set
extern_c void
RMatrixCalculateChannelRadiusSet(ConstHandle2RMatrix self, const bool calculateChannelRadius);


// -----------------------------------------------------------------------------
// Metadatum: supportsAngularReconstruction
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
RMatrixSupportsAngularReconstructionHas(ConstHandle2ConstRMatrix self);

// +++ Get
// +++ Returns by value
extern_c bool
RMatrixSupportsAngularReconstructionGet(ConstHandle2ConstRMatrix self);

// +++ Set
extern_c void
RMatrixSupportsAngularReconstructionSet(ConstHandle2RMatrix self, const bool supportsAngularReconstruction);


// -----------------------------------------------------------------------------
// Child: PoPs
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
RMatrixPoPsHas(ConstHandle2ConstRMatrix self);

// --- Get, const
extern_c Handle2ConstPoPs
RMatrixPoPsGetConst(ConstHandle2ConstRMatrix self);

// +++ Get, non-const
extern_c Handle2PoPs
RMatrixPoPsGet(ConstHandle2RMatrix self);

// +++ Set
extern_c void
RMatrixPoPsSet(ConstHandle2RMatrix self, ConstHandle2ConstPoPs PoPs);


// -----------------------------------------------------------------------------
// Child: resonanceReactions
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
RMatrixResonanceReactionsHas(ConstHandle2ConstRMatrix self);

// --- Get, const
extern_c Handle2ConstResonanceReactions
RMatrixResonanceReactionsGetConst(ConstHandle2ConstRMatrix self);

// +++ Get, non-const
extern_c Handle2ResonanceReactions
RMatrixResonanceReactionsGet(ConstHandle2RMatrix self);

// +++ Set
extern_c void
RMatrixResonanceReactionsSet(ConstHandle2RMatrix self, ConstHandle2ConstResonanceReactions resonanceReactions);


// -----------------------------------------------------------------------------
// Child: spinGroups
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
RMatrixSpinGroupsHas(ConstHandle2ConstRMatrix self);

// --- Get, const
extern_c Handle2ConstSpinGroups
RMatrixSpinGroupsGetConst(ConstHandle2ConstRMatrix self);

// +++ Get, non-const
extern_c Handle2SpinGroups
RMatrixSpinGroupsGet(ConstHandle2RMatrix self);

// +++ Set
extern_c void
RMatrixSpinGroupsSet(ConstHandle2RMatrix self, ConstHandle2ConstSpinGroups spinGroups);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/RMatrix/src/custom.h"

#undef extern_c
#endif