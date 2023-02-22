
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
// DiscreteGamma is the basic handle type in this file. Example:
//    // Create a default DiscreteGamma object:
//    DiscreteGamma handle = DiscreteGammaDefault();
// Functions involving DiscreteGamma are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_DISCRETEGAMMA
#define C_INTERFACE_ALPHA_V2_0_GENERAL_DISCRETEGAMMA

#include "GNDStk.h"
#include "v2.0/general/Axes.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct DiscreteGammaClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ DiscreteGamma
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct DiscreteGammaClass *DiscreteGamma;

// --- Const-aware handles.
typedef const struct DiscreteGammaClass *const ConstHandle2ConstDiscreteGamma;
typedef       struct DiscreteGammaClass *const ConstHandle2DiscreteGamma;
typedef const struct DiscreteGammaClass *      Handle2ConstDiscreteGamma;
typedef       struct DiscreteGammaClass *      Handle2DiscreteGamma;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstDiscreteGamma
DiscreteGammaDefaultConst();

// +++ Create, default
extern_c Handle2DiscreteGamma
DiscreteGammaDefault();

// --- Create, general, const
extern_c Handle2ConstDiscreteGamma
DiscreteGammaCreateConst(
   const double value,
   const double domainMin,
   const double domainMax,
   ConstHandle2ConstAxes axes
);

// +++ Create, general
extern_c Handle2DiscreteGamma
DiscreteGammaCreate(
   const double value,
   const double domainMin,
   const double domainMax,
   ConstHandle2ConstAxes axes
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
DiscreteGammaAssign(ConstHandle2DiscreteGamma self, ConstHandle2ConstDiscreteGamma from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
DiscreteGammaDelete(ConstHandle2ConstDiscreteGamma self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
DiscreteGammaRead(ConstHandle2DiscreteGamma self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
DiscreteGammaWrite(ConstHandle2ConstDiscreteGamma self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
DiscreteGammaPrint(ConstHandle2ConstDiscreteGamma self);

// +++ Print to standard output, as XML
extern_c int
DiscreteGammaPrintXML(ConstHandle2ConstDiscreteGamma self);

// +++ Print to standard output, as JSON
extern_c int
DiscreteGammaPrintJSON(ConstHandle2ConstDiscreteGamma self);


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DiscreteGammaValueHas(ConstHandle2ConstDiscreteGamma self);

// +++ Get
// +++ Returns by value
extern_c double
DiscreteGammaValueGet(ConstHandle2ConstDiscreteGamma self);

// +++ Set
extern_c void
DiscreteGammaValueSet(ConstHandle2DiscreteGamma self, const double value);


// -----------------------------------------------------------------------------
// Metadatum: domainMin
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DiscreteGammaDomainMinHas(ConstHandle2ConstDiscreteGamma self);

// +++ Get
// +++ Returns by value
extern_c double
DiscreteGammaDomainMinGet(ConstHandle2ConstDiscreteGamma self);

// +++ Set
extern_c void
DiscreteGammaDomainMinSet(ConstHandle2DiscreteGamma self, const double domainMin);


// -----------------------------------------------------------------------------
// Metadatum: domainMax
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DiscreteGammaDomainMaxHas(ConstHandle2ConstDiscreteGamma self);

// +++ Get
// +++ Returns by value
extern_c double
DiscreteGammaDomainMaxGet(ConstHandle2ConstDiscreteGamma self);

// +++ Set
extern_c void
DiscreteGammaDomainMaxSet(ConstHandle2DiscreteGamma self, const double domainMax);


// -----------------------------------------------------------------------------
// Child: axes
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DiscreteGammaAxesHas(ConstHandle2ConstDiscreteGamma self);

// --- Get, const
extern_c Handle2ConstAxes
DiscreteGammaAxesGetConst(ConstHandle2ConstDiscreteGamma self);

// +++ Get, non-const
extern_c Handle2Axes
DiscreteGammaAxesGet(ConstHandle2DiscreteGamma self);

// +++ Set
extern_c void
DiscreteGammaAxesSet(ConstHandle2DiscreteGamma self, ConstHandle2ConstAxes axes);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/DiscreteGamma/src/custom.h"

#undef extern_c
#endif