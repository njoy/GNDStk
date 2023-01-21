
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
// AngularEnergyMC is the basic handle type in this file. Example:
//    // Create a default AngularEnergyMC object:
//    AngularEnergyMC handle = AngularEnergyMCDefault();
// Functions involving AngularEnergyMC are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_PROCESSED_ANGULARENERGYMC
#define C_INTERFACE_TEST_V2_0_PROCESSED_ANGULARENERGYMC

#include "GNDStk.h"
#include "v2.0/transport/Angular_uncorrelated.h"
#include "v2.0/transport/AngularEnergy.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct AngularEnergyMCClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ AngularEnergyMC
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct AngularEnergyMCClass *AngularEnergyMC;

// --- Const-aware handles.
typedef const struct AngularEnergyMCClass *const ConstHandle2ConstAngularEnergyMC;
typedef       struct AngularEnergyMCClass *const ConstHandle2AngularEnergyMC;
typedef const struct AngularEnergyMCClass *      Handle2ConstAngularEnergyMC;
typedef       struct AngularEnergyMCClass *      Handle2AngularEnergyMC;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstAngularEnergyMC
AngularEnergyMCDefaultConst();

// +++ Create, default
extern_c Handle2AngularEnergyMC
AngularEnergyMCDefault();

// --- Create, general, const
extern_c Handle2ConstAngularEnergyMC
AngularEnergyMCCreateConst(
   const XMLName label,
   const XMLName productFrame,
   ConstHandle2ConstAngular_uncorrelated angular_uncorrelated,
   ConstHandle2ConstAngularEnergy angularEnergy
);

// +++ Create, general
extern_c Handle2AngularEnergyMC
AngularEnergyMCCreate(
   const XMLName label,
   const XMLName productFrame,
   ConstHandle2ConstAngular_uncorrelated angular_uncorrelated,
   ConstHandle2ConstAngularEnergy angularEnergy
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
AngularEnergyMCAssign(ConstHandle2AngularEnergyMC This, ConstHandle2ConstAngularEnergyMC from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
AngularEnergyMCDelete(ConstHandle2ConstAngularEnergyMC This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
AngularEnergyMCRead(ConstHandle2AngularEnergyMC This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
AngularEnergyMCWrite(ConstHandle2ConstAngularEnergyMC This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
AngularEnergyMCPrint(ConstHandle2ConstAngularEnergyMC This);

// +++ Print to standard output, as XML
extern_c int
AngularEnergyMCPrintXML(ConstHandle2ConstAngularEnergyMC This);

// +++ Print to standard output, as JSON
extern_c int
AngularEnergyMCPrintJSON(ConstHandle2ConstAngularEnergyMC This);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AngularEnergyMCLabelHas(ConstHandle2ConstAngularEnergyMC This);

// +++ Get
// +++ Returns by value
extern_c XMLName
AngularEnergyMCLabelGet(ConstHandle2ConstAngularEnergyMC This);

// +++ Set
extern_c void
AngularEnergyMCLabelSet(ConstHandle2AngularEnergyMC This, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: productFrame
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AngularEnergyMCProductFrameHas(ConstHandle2ConstAngularEnergyMC This);

// +++ Get
// +++ Returns by value
extern_c XMLName
AngularEnergyMCProductFrameGet(ConstHandle2ConstAngularEnergyMC This);

// +++ Set
extern_c void
AngularEnergyMCProductFrameSet(ConstHandle2AngularEnergyMC This, const XMLName productFrame);


// -----------------------------------------------------------------------------
// Child: angular_uncorrelated
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AngularEnergyMCAngular_uncorrelatedHas(ConstHandle2ConstAngularEnergyMC This);

// --- Get, const
extern_c Handle2ConstAngular_uncorrelated
AngularEnergyMCAngular_uncorrelatedGetConst(ConstHandle2ConstAngularEnergyMC This);

// +++ Get, non-const
extern_c Handle2Angular_uncorrelated
AngularEnergyMCAngular_uncorrelatedGet(ConstHandle2AngularEnergyMC This);

// +++ Set
extern_c void
AngularEnergyMCAngular_uncorrelatedSet(ConstHandle2AngularEnergyMC This, ConstHandle2ConstAngular_uncorrelated angular_uncorrelated);


// -----------------------------------------------------------------------------
// Child: angularEnergy
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AngularEnergyMCAngularEnergyHas(ConstHandle2ConstAngularEnergyMC This);

// --- Get, const
extern_c Handle2ConstAngularEnergy
AngularEnergyMCAngularEnergyGetConst(ConstHandle2ConstAngularEnergyMC This);

// +++ Get, non-const
extern_c Handle2AngularEnergy
AngularEnergyMCAngularEnergyGet(ConstHandle2AngularEnergyMC This);

// +++ Set
extern_c void
AngularEnergyMCAngularEnergySet(ConstHandle2AngularEnergyMC This, ConstHandle2ConstAngularEnergy angularEnergy);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/processed/AngularEnergyMC/src/custom.h"

#undef extern_c
#endif
