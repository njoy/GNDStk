
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
// BraggEnergy is the basic handle type in this file. Example:
//    // Create a default BraggEnergy object:
//    BraggEnergy handle = BraggEnergyDefault();
// Functions involving BraggEnergy are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_TSL_BRAGGENERGY
#define C_INTERFACE_TEST_V2_0_TSL_BRAGGENERGY

#include "GNDStk.h"
#include "v2.0/containers/XYs1d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct BraggEnergyClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ BraggEnergy
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct BraggEnergyClass *BraggEnergy;

// --- Const-aware handles.
typedef const struct BraggEnergyClass *const ConstHandle2ConstBraggEnergy;
typedef       struct BraggEnergyClass *const ConstHandle2BraggEnergy;
typedef const struct BraggEnergyClass *      Handle2ConstBraggEnergy;
typedef       struct BraggEnergyClass *      Handle2BraggEnergy;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstBraggEnergy
BraggEnergyDefaultConst();

// +++ Create, default
extern_c Handle2BraggEnergy
BraggEnergyDefault();

// --- Create, general, const
extern_c Handle2ConstBraggEnergy
BraggEnergyCreateConst(
   ConstHandle2ConstXYs1d XYs1d
);

// +++ Create, general
extern_c Handle2BraggEnergy
BraggEnergyCreate(
   ConstHandle2ConstXYs1d XYs1d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
BraggEnergyAssign(ConstHandle2BraggEnergy self, ConstHandle2ConstBraggEnergy from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
BraggEnergyDelete(ConstHandle2ConstBraggEnergy self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
BraggEnergyRead(ConstHandle2BraggEnergy self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
BraggEnergyWrite(ConstHandle2ConstBraggEnergy self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
BraggEnergyPrint(ConstHandle2ConstBraggEnergy self);

// +++ Print to standard output, as XML
extern_c int
BraggEnergyPrintXML(ConstHandle2ConstBraggEnergy self);

// +++ Print to standard output, as JSON
extern_c int
BraggEnergyPrintJSON(ConstHandle2ConstBraggEnergy self);


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BraggEnergyXYs1dHas(ConstHandle2ConstBraggEnergy self);

// --- Get, const
extern_c Handle2ConstXYs1d
BraggEnergyXYs1dGetConst(ConstHandle2ConstBraggEnergy self);

// +++ Get, non-const
extern_c Handle2XYs1d
BraggEnergyXYs1dGet(ConstHandle2BraggEnergy self);

// +++ Set
extern_c void
BraggEnergyXYs1dSet(ConstHandle2BraggEnergy self, ConstHandle2ConstXYs1d XYs1d);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/tsl/BraggEnergy/src/custom.h"

#undef extern_c
#endif
