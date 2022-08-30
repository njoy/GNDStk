
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
// DelayedGammaEnergy is the basic handle type in this file. Example:
//    // Create a default DelayedGammaEnergy object:
//    DelayedGammaEnergy handle = DelayedGammaEnergyDefault();
// Functions involving DelayedGammaEnergy are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_FISSIONTRANSPORT_DELAYEDGAMMAENERGY
#define C_INTERFACE_TRY_V2_0_FISSIONTRANSPORT_DELAYEDGAMMAENERGY

#include "GNDStk.h"
#include "v2.0/containers/Polynomial1d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct DelayedGammaEnergyClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ DelayedGammaEnergy
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct DelayedGammaEnergyClass *DelayedGammaEnergy;

// --- Const-aware handles.
typedef const struct DelayedGammaEnergyClass *const ConstHandle2ConstDelayedGammaEnergy;
typedef       struct DelayedGammaEnergyClass *const ConstHandle2DelayedGammaEnergy;
typedef const struct DelayedGammaEnergyClass *      Handle2ConstDelayedGammaEnergy;
typedef       struct DelayedGammaEnergyClass *      Handle2DelayedGammaEnergy;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstDelayedGammaEnergy
DelayedGammaEnergyDefaultConst();

// +++ Create, default
extern_c Handle2DelayedGammaEnergy
DelayedGammaEnergyDefault();

// --- Create, general, const
extern_c Handle2ConstDelayedGammaEnergy
DelayedGammaEnergyCreateConst(
   ConstHandle2ConstPolynomial1d polynomial1d
);

// +++ Create, general
extern_c Handle2DelayedGammaEnergy
DelayedGammaEnergyCreate(
   ConstHandle2ConstPolynomial1d polynomial1d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
DelayedGammaEnergyAssign(ConstHandle2DelayedGammaEnergy This, ConstHandle2ConstDelayedGammaEnergy from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
DelayedGammaEnergyDelete(ConstHandle2ConstDelayedGammaEnergy This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
DelayedGammaEnergyRead(ConstHandle2DelayedGammaEnergy This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
DelayedGammaEnergyWrite(ConstHandle2ConstDelayedGammaEnergy This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
DelayedGammaEnergyPrint(ConstHandle2ConstDelayedGammaEnergy This);

// +++ Print to standard output, as XML
extern_c int
DelayedGammaEnergyPrintXML(ConstHandle2ConstDelayedGammaEnergy This);

// +++ Print to standard output, as JSON
extern_c int
DelayedGammaEnergyPrintJSON(ConstHandle2ConstDelayedGammaEnergy This);


// -----------------------------------------------------------------------------
// Child: polynomial1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DelayedGammaEnergyPolynomial1dHas(ConstHandle2ConstDelayedGammaEnergy This);

// --- Get, const
extern_c Handle2ConstPolynomial1d
DelayedGammaEnergyPolynomial1dGetConst(ConstHandle2ConstDelayedGammaEnergy This);

// +++ Get, non-const
extern_c Handle2Polynomial1d
DelayedGammaEnergyPolynomial1dGet(ConstHandle2DelayedGammaEnergy This);

// +++ Set
extern_c void
DelayedGammaEnergyPolynomial1dSet(ConstHandle2DelayedGammaEnergy This, ConstHandle2ConstPolynomial1d polynomial1d);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
