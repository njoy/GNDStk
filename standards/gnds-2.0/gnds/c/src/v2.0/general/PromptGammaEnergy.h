
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
// PromptGammaEnergy is the basic handle type in this file. Example:
//    // Create a default PromptGammaEnergy object:
//    PromptGammaEnergy handle = PromptGammaEnergyDefault();
// Functions involving PromptGammaEnergy are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_PROMPTGAMMAENERGY
#define C_INTERFACE_GNDS_V2_0_GENERAL_PROMPTGAMMAENERGY

#include "GNDStk.h"
#include "v2.0/general/Polynomial1d.h"
#include "v2.0/general/XYs1d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct PromptGammaEnergyClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ PromptGammaEnergy
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct PromptGammaEnergyClass *PromptGammaEnergy;

// --- Const-aware handles.
typedef const struct PromptGammaEnergyClass *const ConstHandle2ConstPromptGammaEnergy;
typedef       struct PromptGammaEnergyClass *const ConstHandle2PromptGammaEnergy;
typedef const struct PromptGammaEnergyClass *      Handle2ConstPromptGammaEnergy;
typedef       struct PromptGammaEnergyClass *      Handle2PromptGammaEnergy;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstPromptGammaEnergy
PromptGammaEnergyDefaultConst();

// +++ Create, default
extern_c Handle2PromptGammaEnergy
PromptGammaEnergyDefault();

// --- Create, general, const
extern_c Handle2ConstPromptGammaEnergy
PromptGammaEnergyCreateConst(
   ConstHandle2ConstPolynomial1d polynomial1d,
   ConstHandle2ConstXYs1d XYs1d
);

// +++ Create, general
extern_c Handle2PromptGammaEnergy
PromptGammaEnergyCreate(
   ConstHandle2ConstPolynomial1d polynomial1d,
   ConstHandle2ConstXYs1d XYs1d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
PromptGammaEnergyAssign(ConstHandle2PromptGammaEnergy self, ConstHandle2ConstPromptGammaEnergy from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
PromptGammaEnergyDelete(ConstHandle2ConstPromptGammaEnergy self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
PromptGammaEnergyRead(ConstHandle2PromptGammaEnergy self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
PromptGammaEnergyWrite(ConstHandle2ConstPromptGammaEnergy self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
PromptGammaEnergyPrint(ConstHandle2ConstPromptGammaEnergy self);

// +++ Print to standard output, as XML
extern_c int
PromptGammaEnergyPrintXML(ConstHandle2ConstPromptGammaEnergy self);

// +++ Print to standard output, as JSON
extern_c int
PromptGammaEnergyPrintJSON(ConstHandle2ConstPromptGammaEnergy self);


// -----------------------------------------------------------------------------
// Child: polynomial1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
PromptGammaEnergyPolynomial1dHas(ConstHandle2ConstPromptGammaEnergy self);

// --- Get, const
extern_c Handle2ConstPolynomial1d
PromptGammaEnergyPolynomial1dGetConst(ConstHandle2ConstPromptGammaEnergy self);

// +++ Get, non-const
extern_c Handle2Polynomial1d
PromptGammaEnergyPolynomial1dGet(ConstHandle2PromptGammaEnergy self);

// +++ Set
extern_c void
PromptGammaEnergyPolynomial1dSet(ConstHandle2PromptGammaEnergy self, ConstHandle2ConstPolynomial1d polynomial1d);


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
PromptGammaEnergyXYs1dHas(ConstHandle2ConstPromptGammaEnergy self);

// --- Get, const
extern_c Handle2ConstXYs1d
PromptGammaEnergyXYs1dGetConst(ConstHandle2ConstPromptGammaEnergy self);

// +++ Get, non-const
extern_c Handle2XYs1d
PromptGammaEnergyXYs1dGet(ConstHandle2PromptGammaEnergy self);

// +++ Set
extern_c void
PromptGammaEnergyXYs1dSet(ConstHandle2PromptGammaEnergy self, ConstHandle2ConstXYs1d XYs1d);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/PromptGammaEnergy/src/custom.h"

#undef extern_c
#endif
