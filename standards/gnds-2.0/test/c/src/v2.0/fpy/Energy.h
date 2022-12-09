
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
// Energy is the basic handle type in this file. Example:
//    // Create a default Energy object:
//    Energy handle = EnergyDefault();
// Functions involving Energy are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_FPY_ENERGY
#define C_INTERFACE_TEST_V2_0_FPY_ENERGY

#include "GNDStk.h"
#include "v2.0/containers/Double.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct EnergyClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Energy
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct EnergyClass *Energy;

// --- Const-aware handles.
typedef const struct EnergyClass *const ConstHandle2ConstEnergy;
typedef       struct EnergyClass *const ConstHandle2Energy;
typedef const struct EnergyClass *      Handle2ConstEnergy;
typedef       struct EnergyClass *      Handle2Energy;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstEnergy
EnergyDefaultConst();

// +++ Create, default
extern_c Handle2Energy
EnergyDefault();

// --- Create, general, const
extern_c Handle2ConstEnergy
EnergyCreateConst(
   ConstHandle2ConstDouble Double
);

// +++ Create, general
extern_c Handle2Energy
EnergyCreate(
   ConstHandle2ConstDouble Double
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
EnergyAssign(ConstHandle2Energy This, ConstHandle2ConstEnergy from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
EnergyDelete(ConstHandle2ConstEnergy This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
EnergyRead(ConstHandle2Energy This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
EnergyWrite(ConstHandle2ConstEnergy This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
EnergyPrint(ConstHandle2ConstEnergy This);

// +++ Print to standard output, as XML
extern_c int
EnergyPrintXML(ConstHandle2ConstEnergy This);

// +++ Print to standard output, as JSON
extern_c int
EnergyPrintJSON(ConstHandle2ConstEnergy This);


// -----------------------------------------------------------------------------
// Child: Double
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
EnergyDoubleHas(ConstHandle2ConstEnergy This);

// --- Get, const
extern_c Handle2ConstDouble
EnergyDoubleGetConst(ConstHandle2ConstEnergy This);

// +++ Get, non-const
extern_c Handle2Double
EnergyDoubleGet(ConstHandle2Energy This);

// +++ Set
extern_c void
EnergyDoubleSet(ConstHandle2Energy This, ConstHandle2ConstDouble Double);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
