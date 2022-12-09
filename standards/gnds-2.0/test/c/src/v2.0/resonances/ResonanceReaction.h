
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
// ResonanceReaction is the basic handle type in this file. Example:
//    // Create a default ResonanceReaction object:
//    ResonanceReaction handle = ResonanceReactionDefault();
// Functions involving ResonanceReaction are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_RESONANCES_RESONANCEREACTION
#define C_INTERFACE_TEST_V2_0_RESONANCES_RESONANCEREACTION

#include "GNDStk.h"
#include "v2.0/common/Q.h"
#include "v2.0/resonances/ScatteringRadius.h"
#include "v2.0/resonances/HardSphereRadius.h"
#include "v2.0/containers/Link.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ResonanceReactionClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ResonanceReaction
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ResonanceReactionClass *ResonanceReaction;

// --- Const-aware handles.
typedef const struct ResonanceReactionClass *const ConstHandle2ConstResonanceReaction;
typedef       struct ResonanceReactionClass *const ConstHandle2ResonanceReaction;
typedef const struct ResonanceReactionClass *      Handle2ConstResonanceReaction;
typedef       struct ResonanceReactionClass *      Handle2ResonanceReaction;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstResonanceReaction
ResonanceReactionDefaultConst();

// +++ Create, default
extern_c Handle2ResonanceReaction
ResonanceReactionDefault();

// --- Create, general, const
extern_c Handle2ConstResonanceReaction
ResonanceReactionCreateConst(
   const XMLName label,
   const XMLName ejectile,
   const Float64 boundaryConditionValue,
   const bool eliminated,
   ConstHandle2ConstQ Q,
   ConstHandle2ConstScatteringRadius scatteringRadius,
   ConstHandle2ConstHardSphereRadius hardSphereRadius,
   ConstHandle2ConstLink link
);

// +++ Create, general
extern_c Handle2ResonanceReaction
ResonanceReactionCreate(
   const XMLName label,
   const XMLName ejectile,
   const Float64 boundaryConditionValue,
   const bool eliminated,
   ConstHandle2ConstQ Q,
   ConstHandle2ConstScatteringRadius scatteringRadius,
   ConstHandle2ConstHardSphereRadius hardSphereRadius,
   ConstHandle2ConstLink link
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ResonanceReactionAssign(ConstHandle2ResonanceReaction This, ConstHandle2ConstResonanceReaction from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ResonanceReactionDelete(ConstHandle2ConstResonanceReaction This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ResonanceReactionRead(ConstHandle2ResonanceReaction This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ResonanceReactionWrite(ConstHandle2ConstResonanceReaction This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ResonanceReactionPrint(ConstHandle2ConstResonanceReaction This);

// +++ Print to standard output, as XML
extern_c int
ResonanceReactionPrintXML(ConstHandle2ConstResonanceReaction This);

// +++ Print to standard output, as JSON
extern_c int
ResonanceReactionPrintJSON(ConstHandle2ConstResonanceReaction This);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ResonanceReactionLabelHas(ConstHandle2ConstResonanceReaction This);

// +++ Get
// +++ Returns by value
extern_c XMLName
ResonanceReactionLabelGet(ConstHandle2ConstResonanceReaction This);

// +++ Set
extern_c void
ResonanceReactionLabelSet(ConstHandle2ResonanceReaction This, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: ejectile
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ResonanceReactionEjectileHas(ConstHandle2ConstResonanceReaction This);

// +++ Get
// +++ Returns by value
extern_c XMLName
ResonanceReactionEjectileGet(ConstHandle2ConstResonanceReaction This);

// +++ Set
extern_c void
ResonanceReactionEjectileSet(ConstHandle2ResonanceReaction This, const XMLName ejectile);


// -----------------------------------------------------------------------------
// Metadatum: boundaryConditionValue
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ResonanceReactionBoundaryConditionValueHas(ConstHandle2ConstResonanceReaction This);

// +++ Get
// +++ Returns by value
extern_c Float64
ResonanceReactionBoundaryConditionValueGet(ConstHandle2ConstResonanceReaction This);

// +++ Set
extern_c void
ResonanceReactionBoundaryConditionValueSet(ConstHandle2ResonanceReaction This, const Float64 boundaryConditionValue);


// -----------------------------------------------------------------------------
// Metadatum: eliminated
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ResonanceReactionEliminatedHas(ConstHandle2ConstResonanceReaction This);

// +++ Get
// +++ Returns by value
extern_c bool
ResonanceReactionEliminatedGet(ConstHandle2ConstResonanceReaction This);

// +++ Set
extern_c void
ResonanceReactionEliminatedSet(ConstHandle2ResonanceReaction This, const bool eliminated);


// -----------------------------------------------------------------------------
// Child: Q
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ResonanceReactionQHas(ConstHandle2ConstResonanceReaction This);

// --- Get, const
extern_c Handle2ConstQ
ResonanceReactionQGetConst(ConstHandle2ConstResonanceReaction This);

// +++ Get, non-const
extern_c Handle2Q
ResonanceReactionQGet(ConstHandle2ResonanceReaction This);

// +++ Set
extern_c void
ResonanceReactionQSet(ConstHandle2ResonanceReaction This, ConstHandle2ConstQ Q);


// -----------------------------------------------------------------------------
// Child: scatteringRadius
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ResonanceReactionScatteringRadiusHas(ConstHandle2ConstResonanceReaction This);

// --- Get, const
extern_c Handle2ConstScatteringRadius
ResonanceReactionScatteringRadiusGetConst(ConstHandle2ConstResonanceReaction This);

// +++ Get, non-const
extern_c Handle2ScatteringRadius
ResonanceReactionScatteringRadiusGet(ConstHandle2ResonanceReaction This);

// +++ Set
extern_c void
ResonanceReactionScatteringRadiusSet(ConstHandle2ResonanceReaction This, ConstHandle2ConstScatteringRadius scatteringRadius);


// -----------------------------------------------------------------------------
// Child: hardSphereRadius
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ResonanceReactionHardSphereRadiusHas(ConstHandle2ConstResonanceReaction This);

// --- Get, const
extern_c Handle2ConstHardSphereRadius
ResonanceReactionHardSphereRadiusGetConst(ConstHandle2ConstResonanceReaction This);

// +++ Get, non-const
extern_c Handle2HardSphereRadius
ResonanceReactionHardSphereRadiusGet(ConstHandle2ResonanceReaction This);

// +++ Set
extern_c void
ResonanceReactionHardSphereRadiusSet(ConstHandle2ResonanceReaction This, ConstHandle2ConstHardSphereRadius hardSphereRadius);


// -----------------------------------------------------------------------------
// Child: link
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ResonanceReactionLinkHas(ConstHandle2ConstResonanceReaction This);

// --- Get, const
extern_c Handle2ConstLink
ResonanceReactionLinkGetConst(ConstHandle2ConstResonanceReaction This);

// +++ Get, non-const
extern_c Handle2Link
ResonanceReactionLinkGet(ConstHandle2ResonanceReaction This);

// +++ Set
extern_c void
ResonanceReactionLinkSet(ConstHandle2ResonanceReaction This, ConstHandle2ConstLink link);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
