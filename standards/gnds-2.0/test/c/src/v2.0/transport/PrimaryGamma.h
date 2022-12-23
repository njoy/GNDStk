
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
// PrimaryGamma is the basic handle type in this file. Example:
//    // Create a default PrimaryGamma object:
//    PrimaryGamma handle = PrimaryGammaDefault();
// Functions involving PrimaryGamma are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_TRANSPORT_PRIMARYGAMMA
#define C_INTERFACE_TEST_V2_0_TRANSPORT_PRIMARYGAMMA

#include "GNDStk.h"
#include "v2.0/containers/Axes.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct PrimaryGammaClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ PrimaryGamma
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct PrimaryGammaClass *PrimaryGamma;

// --- Const-aware handles.
typedef const struct PrimaryGammaClass *const ConstHandle2ConstPrimaryGamma;
typedef       struct PrimaryGammaClass *const ConstHandle2PrimaryGamma;
typedef const struct PrimaryGammaClass *      Handle2ConstPrimaryGamma;
typedef       struct PrimaryGammaClass *      Handle2PrimaryGamma;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstPrimaryGamma
PrimaryGammaDefaultConst();

// +++ Create, default
extern_c Handle2PrimaryGamma
PrimaryGammaDefault();

// --- Create, general, const
extern_c Handle2ConstPrimaryGamma
PrimaryGammaCreateConst(
   const Float64 domainMax,
   const Float64 domainMin,
   const Float64 value,
   const XMLName finalState,
   ConstHandle2ConstAxes axes
);

// +++ Create, general
extern_c Handle2PrimaryGamma
PrimaryGammaCreate(
   const Float64 domainMax,
   const Float64 domainMin,
   const Float64 value,
   const XMLName finalState,
   ConstHandle2ConstAxes axes
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
PrimaryGammaAssign(ConstHandle2PrimaryGamma This, ConstHandle2ConstPrimaryGamma from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
PrimaryGammaDelete(ConstHandle2ConstPrimaryGamma This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
PrimaryGammaRead(ConstHandle2PrimaryGamma This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
PrimaryGammaWrite(ConstHandle2ConstPrimaryGamma This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
PrimaryGammaPrint(ConstHandle2ConstPrimaryGamma This);

// +++ Print to standard output, as XML
extern_c int
PrimaryGammaPrintXML(ConstHandle2ConstPrimaryGamma This);

// +++ Print to standard output, as JSON
extern_c int
PrimaryGammaPrintJSON(ConstHandle2ConstPrimaryGamma This);


// -----------------------------------------------------------------------------
// Metadatum: domainMax
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
PrimaryGammaDomainMaxHas(ConstHandle2ConstPrimaryGamma This);

// +++ Get
// +++ Returns by value
extern_c Float64
PrimaryGammaDomainMaxGet(ConstHandle2ConstPrimaryGamma This);

// +++ Set
extern_c void
PrimaryGammaDomainMaxSet(ConstHandle2PrimaryGamma This, const Float64 domainMax);


// -----------------------------------------------------------------------------
// Metadatum: domainMin
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
PrimaryGammaDomainMinHas(ConstHandle2ConstPrimaryGamma This);

// +++ Get
// +++ Returns by value
extern_c Float64
PrimaryGammaDomainMinGet(ConstHandle2ConstPrimaryGamma This);

// +++ Set
extern_c void
PrimaryGammaDomainMinSet(ConstHandle2PrimaryGamma This, const Float64 domainMin);


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
PrimaryGammaValueHas(ConstHandle2ConstPrimaryGamma This);

// +++ Get
// +++ Returns by value
extern_c Float64
PrimaryGammaValueGet(ConstHandle2ConstPrimaryGamma This);

// +++ Set
extern_c void
PrimaryGammaValueSet(ConstHandle2PrimaryGamma This, const Float64 value);


// -----------------------------------------------------------------------------
// Metadatum: finalState
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
PrimaryGammaFinalStateHas(ConstHandle2ConstPrimaryGamma This);

// +++ Get
// +++ Returns by value
extern_c XMLName
PrimaryGammaFinalStateGet(ConstHandle2ConstPrimaryGamma This);

// +++ Set
extern_c void
PrimaryGammaFinalStateSet(ConstHandle2PrimaryGamma This, const XMLName finalState);


// -----------------------------------------------------------------------------
// Child: axes
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
PrimaryGammaAxesHas(ConstHandle2ConstPrimaryGamma This);

// --- Get, const
extern_c Handle2ConstAxes
PrimaryGammaAxesGetConst(ConstHandle2ConstPrimaryGamma This);

// +++ Get, non-const
extern_c Handle2Axes
PrimaryGammaAxesGet(ConstHandle2PrimaryGamma This);

// +++ Set
extern_c void
PrimaryGammaAxesSet(ConstHandle2PrimaryGamma This, ConstHandle2ConstAxes axes);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
