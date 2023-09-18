
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
// NonNeutrinoEnergy is the basic handle type in this file. Example:
//    // Create a default NonNeutrinoEnergy object:
//    NonNeutrinoEnergy handle = NonNeutrinoEnergyDefault();
// Functions involving NonNeutrinoEnergy are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_NONNEUTRINOENERGY
#define C_INTERFACE_GNDS_V2_0_GENERAL_NONNEUTRINOENERGY

#include "GNDStk.h"
#include "v2.0/general/Polynomial1d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct NonNeutrinoEnergyClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ NonNeutrinoEnergy
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct NonNeutrinoEnergyClass *NonNeutrinoEnergy;

// --- Const-aware handles.
typedef const struct NonNeutrinoEnergyClass *const ConstHandle2ConstNonNeutrinoEnergy;
typedef       struct NonNeutrinoEnergyClass *const ConstHandle2NonNeutrinoEnergy;
typedef const struct NonNeutrinoEnergyClass *      Handle2ConstNonNeutrinoEnergy;
typedef       struct NonNeutrinoEnergyClass *      Handle2NonNeutrinoEnergy;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstNonNeutrinoEnergy
NonNeutrinoEnergyDefaultConst();

// +++ Create, default
extern_c Handle2NonNeutrinoEnergy
NonNeutrinoEnergyDefault();

// --- Create, general, const
extern_c Handle2ConstNonNeutrinoEnergy
NonNeutrinoEnergyCreateConst(
   ConstHandle2ConstPolynomial1d polynomial1d
);

// +++ Create, general
extern_c Handle2NonNeutrinoEnergy
NonNeutrinoEnergyCreate(
   ConstHandle2ConstPolynomial1d polynomial1d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
NonNeutrinoEnergyAssign(ConstHandle2NonNeutrinoEnergy self, ConstHandle2ConstNonNeutrinoEnergy from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
NonNeutrinoEnergyDelete(ConstHandle2ConstNonNeutrinoEnergy self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
NonNeutrinoEnergyRead(ConstHandle2NonNeutrinoEnergy self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
NonNeutrinoEnergyWrite(ConstHandle2ConstNonNeutrinoEnergy self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
NonNeutrinoEnergyPrint(ConstHandle2ConstNonNeutrinoEnergy self);

// +++ Print to standard output, as XML
extern_c int
NonNeutrinoEnergyPrintXML(ConstHandle2ConstNonNeutrinoEnergy self);

// +++ Print to standard output, as JSON
extern_c int
NonNeutrinoEnergyPrintJSON(ConstHandle2ConstNonNeutrinoEnergy self);


// -----------------------------------------------------------------------------
// Child: polynomial1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NonNeutrinoEnergyPolynomial1dHas(ConstHandle2ConstNonNeutrinoEnergy self);

// --- Get, const
extern_c Handle2ConstPolynomial1d
NonNeutrinoEnergyPolynomial1dGetConst(ConstHandle2ConstNonNeutrinoEnergy self);

// +++ Get
extern_c Handle2Polynomial1d
NonNeutrinoEnergyPolynomial1dGet(ConstHandle2NonNeutrinoEnergy self);

// +++ Set
extern_c void
NonNeutrinoEnergyPolynomial1dSet(ConstHandle2NonNeutrinoEnergy self, ConstHandle2ConstPolynomial1d polynomial1d);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/NonNeutrinoEnergy/src/custom.h"

#undef extern_c
#endif
