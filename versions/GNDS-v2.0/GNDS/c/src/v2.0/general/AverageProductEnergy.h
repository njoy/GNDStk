
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
// AverageProductEnergy is the basic handle type in this file. Example:
//    // Create a default AverageProductEnergy object:
//    AverageProductEnergy handle = AverageProductEnergyDefault();
// Functions involving AverageProductEnergy are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_AVERAGEPRODUCTENERGY
#define C_INTERFACE_GNDS_V2_0_GENERAL_AVERAGEPRODUCTENERGY

#include "GNDStk.h"
#include "v2.0/general/XYs1d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct AverageProductEnergyClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ AverageProductEnergy
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct AverageProductEnergyClass *AverageProductEnergy;

// --- Const-aware handles.
typedef const struct AverageProductEnergyClass *const ConstHandle2ConstAverageProductEnergy;
typedef       struct AverageProductEnergyClass *const ConstHandle2AverageProductEnergy;
typedef const struct AverageProductEnergyClass *      Handle2ConstAverageProductEnergy;
typedef       struct AverageProductEnergyClass *      Handle2AverageProductEnergy;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstAverageProductEnergy
AverageProductEnergyDefaultConst();

// +++ Create, default, non-const
extern_c Handle2AverageProductEnergy
AverageProductEnergyDefault();

// --- Create, general, const
extern_c Handle2ConstAverageProductEnergy
AverageProductEnergyCreateConst(
   ConstHandle2ConstXYs1d XYs1d
);

// +++ Create, general, non-const
extern_c Handle2AverageProductEnergy
AverageProductEnergyCreate(
   ConstHandle2ConstXYs1d XYs1d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
AverageProductEnergyAssign(ConstHandle2AverageProductEnergy self, ConstHandle2ConstAverageProductEnergy from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
AverageProductEnergyDelete(ConstHandle2ConstAverageProductEnergy self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
AverageProductEnergyRead(ConstHandle2AverageProductEnergy self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
AverageProductEnergyWrite(ConstHandle2ConstAverageProductEnergy self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
AverageProductEnergyPrint(ConstHandle2ConstAverageProductEnergy self);

// +++ Print to standard output, as XML
extern_c int
AverageProductEnergyPrintXML(ConstHandle2ConstAverageProductEnergy self);

// +++ Print to standard output, as JSON
extern_c int
AverageProductEnergyPrintJSON(ConstHandle2ConstAverageProductEnergy self);


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AverageProductEnergyXYs1dHas(ConstHandle2ConstAverageProductEnergy self);

// --- Get, const
extern_c Handle2ConstXYs1d
AverageProductEnergyXYs1dGetConst(ConstHandle2ConstAverageProductEnergy self);

// +++ Get, non-const
extern_c Handle2XYs1d
AverageProductEnergyXYs1dGet(ConstHandle2AverageProductEnergy self);

// +++ Set
extern_c void
AverageProductEnergyXYs1dSet(ConstHandle2AverageProductEnergy self, ConstHandle2ConstXYs1d XYs1d);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/AverageProductEnergy/src/custom.h"

#undef extern_c
#endif