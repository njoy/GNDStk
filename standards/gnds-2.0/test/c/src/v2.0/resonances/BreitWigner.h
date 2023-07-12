
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
// BreitWigner is the basic handle type in this file. Example:
//    // Create a default BreitWigner object:
//    BreitWigner handle = BreitWignerDefault();
// Functions involving BreitWigner are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_RESONANCES_BREITWIGNER
#define C_INTERFACE_TEST_V2_0_RESONANCES_BREITWIGNER

#include "GNDStk.h"
#include "v2.0/pops/PoPs_database.h"
#include "v2.0/resonances/ScatteringRadius.h"
#include "v2.0/resonances/HardSphereRadius.h"
#include "v2.0/resonances/ResonanceParameters.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct BreitWignerClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ BreitWigner
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct BreitWignerClass *BreitWigner;

// --- Const-aware handles.
typedef const struct BreitWignerClass *const ConstHandle2ConstBreitWigner;
typedef       struct BreitWignerClass *const ConstHandle2BreitWigner;
typedef const struct BreitWignerClass *      Handle2ConstBreitWigner;
typedef       struct BreitWignerClass *      Handle2BreitWigner;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstBreitWigner
BreitWignerDefaultConst();

// +++ Create, default
extern_c Handle2BreitWigner
BreitWignerDefault();

// --- Create, general, const
extern_c Handle2ConstBreitWigner
BreitWignerCreateConst(
   const XMLName label,
   const XMLName approximation,
   const bool calculateChannelRadius,
   const bool useForSelfShieldingOnly,
   ConstHandle2ConstPoPs_database PoPs_database,
   ConstHandle2ConstScatteringRadius scatteringRadius,
   ConstHandle2ConstHardSphereRadius hardSphereRadius,
   ConstHandle2ConstResonanceParameters resonanceParameters
);

// +++ Create, general
extern_c Handle2BreitWigner
BreitWignerCreate(
   const XMLName label,
   const XMLName approximation,
   const bool calculateChannelRadius,
   const bool useForSelfShieldingOnly,
   ConstHandle2ConstPoPs_database PoPs_database,
   ConstHandle2ConstScatteringRadius scatteringRadius,
   ConstHandle2ConstHardSphereRadius hardSphereRadius,
   ConstHandle2ConstResonanceParameters resonanceParameters
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
BreitWignerAssign(ConstHandle2BreitWigner self, ConstHandle2ConstBreitWigner from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
BreitWignerDelete(ConstHandle2ConstBreitWigner self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
BreitWignerRead(ConstHandle2BreitWigner self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
BreitWignerWrite(ConstHandle2ConstBreitWigner self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
BreitWignerPrint(ConstHandle2ConstBreitWigner self);

// +++ Print to standard output, as XML
extern_c int
BreitWignerPrintXML(ConstHandle2ConstBreitWigner self);

// +++ Print to standard output, as JSON
extern_c int
BreitWignerPrintJSON(ConstHandle2ConstBreitWigner self);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BreitWignerLabelHas(ConstHandle2ConstBreitWigner self);

// +++ Get
// +++ Returns by value
extern_c XMLName
BreitWignerLabelGet(ConstHandle2ConstBreitWigner self);

// +++ Set
extern_c void
BreitWignerLabelSet(ConstHandle2BreitWigner self, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: approximation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BreitWignerApproximationHas(ConstHandle2ConstBreitWigner self);

// +++ Get
// +++ Returns by value
extern_c XMLName
BreitWignerApproximationGet(ConstHandle2ConstBreitWigner self);

// +++ Set
extern_c void
BreitWignerApproximationSet(ConstHandle2BreitWigner self, const XMLName approximation);


// -----------------------------------------------------------------------------
// Metadatum: calculateChannelRadius
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BreitWignerCalculateChannelRadiusHas(ConstHandle2ConstBreitWigner self);

// +++ Get
// +++ Returns by value
extern_c bool
BreitWignerCalculateChannelRadiusGet(ConstHandle2ConstBreitWigner self);

// +++ Set
extern_c void
BreitWignerCalculateChannelRadiusSet(ConstHandle2BreitWigner self, const bool calculateChannelRadius);


// -----------------------------------------------------------------------------
// Metadatum: useForSelfShieldingOnly
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BreitWignerUseForSelfShieldingOnlyHas(ConstHandle2ConstBreitWigner self);

// +++ Get
// +++ Returns by value
extern_c bool
BreitWignerUseForSelfShieldingOnlyGet(ConstHandle2ConstBreitWigner self);

// +++ Set
extern_c void
BreitWignerUseForSelfShieldingOnlySet(ConstHandle2BreitWigner self, const bool useForSelfShieldingOnly);


// -----------------------------------------------------------------------------
// Child: PoPs_database
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BreitWignerPoPs_databaseHas(ConstHandle2ConstBreitWigner self);

// --- Get, const
extern_c Handle2ConstPoPs_database
BreitWignerPoPs_databaseGetConst(ConstHandle2ConstBreitWigner self);

// +++ Get, non-const
extern_c Handle2PoPs_database
BreitWignerPoPs_databaseGet(ConstHandle2BreitWigner self);

// +++ Set
extern_c void
BreitWignerPoPs_databaseSet(ConstHandle2BreitWigner self, ConstHandle2ConstPoPs_database PoPs_database);


// -----------------------------------------------------------------------------
// Child: scatteringRadius
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BreitWignerScatteringRadiusHas(ConstHandle2ConstBreitWigner self);

// --- Get, const
extern_c Handle2ConstScatteringRadius
BreitWignerScatteringRadiusGetConst(ConstHandle2ConstBreitWigner self);

// +++ Get, non-const
extern_c Handle2ScatteringRadius
BreitWignerScatteringRadiusGet(ConstHandle2BreitWigner self);

// +++ Set
extern_c void
BreitWignerScatteringRadiusSet(ConstHandle2BreitWigner self, ConstHandle2ConstScatteringRadius scatteringRadius);


// -----------------------------------------------------------------------------
// Child: hardSphereRadius
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BreitWignerHardSphereRadiusHas(ConstHandle2ConstBreitWigner self);

// --- Get, const
extern_c Handle2ConstHardSphereRadius
BreitWignerHardSphereRadiusGetConst(ConstHandle2ConstBreitWigner self);

// +++ Get, non-const
extern_c Handle2HardSphereRadius
BreitWignerHardSphereRadiusGet(ConstHandle2BreitWigner self);

// +++ Set
extern_c void
BreitWignerHardSphereRadiusSet(ConstHandle2BreitWigner self, ConstHandle2ConstHardSphereRadius hardSphereRadius);


// -----------------------------------------------------------------------------
// Child: resonanceParameters
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BreitWignerResonanceParametersHas(ConstHandle2ConstBreitWigner self);

// --- Get, const
extern_c Handle2ConstResonanceParameters
BreitWignerResonanceParametersGetConst(ConstHandle2ConstBreitWigner self);

// +++ Get, non-const
extern_c Handle2ResonanceParameters
BreitWignerResonanceParametersGet(ConstHandle2BreitWigner self);

// +++ Set
extern_c void
BreitWignerResonanceParametersSet(ConstHandle2BreitWigner self, ConstHandle2ConstResonanceParameters resonanceParameters);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/resonances/BreitWigner/src/custom.h"

#undef extern_c
#endif
