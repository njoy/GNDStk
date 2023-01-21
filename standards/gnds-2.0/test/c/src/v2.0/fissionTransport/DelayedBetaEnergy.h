
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
// DelayedBetaEnergy is the basic handle type in this file. Example:
//    // Create a default DelayedBetaEnergy object:
//    DelayedBetaEnergy handle = DelayedBetaEnergyDefault();
// Functions involving DelayedBetaEnergy are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_FISSIONTRANSPORT_DELAYEDBETAENERGY
#define C_INTERFACE_TEST_V2_0_FISSIONTRANSPORT_DELAYEDBETAENERGY

#include "GNDStk.h"
#include "v2.0/containers/Polynomial1d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct DelayedBetaEnergyClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ DelayedBetaEnergy
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct DelayedBetaEnergyClass *DelayedBetaEnergy;

// --- Const-aware handles.
typedef const struct DelayedBetaEnergyClass *const ConstHandle2ConstDelayedBetaEnergy;
typedef       struct DelayedBetaEnergyClass *const ConstHandle2DelayedBetaEnergy;
typedef const struct DelayedBetaEnergyClass *      Handle2ConstDelayedBetaEnergy;
typedef       struct DelayedBetaEnergyClass *      Handle2DelayedBetaEnergy;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstDelayedBetaEnergy
DelayedBetaEnergyDefaultConst();

// +++ Create, default
extern_c Handle2DelayedBetaEnergy
DelayedBetaEnergyDefault();

// --- Create, general, const
extern_c Handle2ConstDelayedBetaEnergy
DelayedBetaEnergyCreateConst(
   ConstHandle2ConstPolynomial1d polynomial1d
);

// +++ Create, general
extern_c Handle2DelayedBetaEnergy
DelayedBetaEnergyCreate(
   ConstHandle2ConstPolynomial1d polynomial1d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
DelayedBetaEnergyAssign(ConstHandle2DelayedBetaEnergy This, ConstHandle2ConstDelayedBetaEnergy from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
DelayedBetaEnergyDelete(ConstHandle2ConstDelayedBetaEnergy This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
DelayedBetaEnergyRead(ConstHandle2DelayedBetaEnergy This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
DelayedBetaEnergyWrite(ConstHandle2ConstDelayedBetaEnergy This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
DelayedBetaEnergyPrint(ConstHandle2ConstDelayedBetaEnergy This);

// +++ Print to standard output, as XML
extern_c int
DelayedBetaEnergyPrintXML(ConstHandle2ConstDelayedBetaEnergy This);

// +++ Print to standard output, as JSON
extern_c int
DelayedBetaEnergyPrintJSON(ConstHandle2ConstDelayedBetaEnergy This);


// -----------------------------------------------------------------------------
// Child: polynomial1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DelayedBetaEnergyPolynomial1dHas(ConstHandle2ConstDelayedBetaEnergy This);

// --- Get, const
extern_c Handle2ConstPolynomial1d
DelayedBetaEnergyPolynomial1dGetConst(ConstHandle2ConstDelayedBetaEnergy This);

// +++ Get, non-const
extern_c Handle2Polynomial1d
DelayedBetaEnergyPolynomial1dGet(ConstHandle2DelayedBetaEnergy This);

// +++ Set
extern_c void
DelayedBetaEnergyPolynomial1dSet(ConstHandle2DelayedBetaEnergy This, ConstHandle2ConstPolynomial1d polynomial1d);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/fissionTransport/DelayedBetaEnergy/src/custom.h"

#undef extern_c
#endif
