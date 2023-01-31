
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
// EnergyAngular is the basic handle type in this file. Example:
//    // Create a default EnergyAngular object:
//    EnergyAngular handle = EnergyAngularDefault();
// Functions involving EnergyAngular are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_MEAN_ENERGYANGULAR
#define C_INTERFACE_ALPHA_V2_0_MEAN_ENERGYANGULAR

#include "GNDStk.h"
#include "v2.0/mean/XYs3d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct EnergyAngularClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ EnergyAngular
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct EnergyAngularClass *EnergyAngular;

// --- Const-aware handles.
typedef const struct EnergyAngularClass *const ConstHandle2ConstEnergyAngular;
typedef       struct EnergyAngularClass *const ConstHandle2EnergyAngular;
typedef const struct EnergyAngularClass *      Handle2ConstEnergyAngular;
typedef       struct EnergyAngularClass *      Handle2EnergyAngular;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstEnergyAngular
EnergyAngularDefaultConst();

// +++ Create, default
extern_c Handle2EnergyAngular
EnergyAngularDefault();

// --- Create, general, const
extern_c Handle2ConstEnergyAngular
EnergyAngularCreateConst(
   const char *const label,
   const char *const productFrame,
   ConstHandle2ConstXYs3d XYs3d
);

// +++ Create, general
extern_c Handle2EnergyAngular
EnergyAngularCreate(
   const char *const label,
   const char *const productFrame,
   ConstHandle2ConstXYs3d XYs3d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
EnergyAngularAssign(ConstHandle2EnergyAngular This, ConstHandle2ConstEnergyAngular from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
EnergyAngularDelete(ConstHandle2ConstEnergyAngular This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
EnergyAngularRead(ConstHandle2EnergyAngular This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
EnergyAngularWrite(ConstHandle2ConstEnergyAngular This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
EnergyAngularPrint(ConstHandle2ConstEnergyAngular This);

// +++ Print to standard output, as XML
extern_c int
EnergyAngularPrintXML(ConstHandle2ConstEnergyAngular This);

// +++ Print to standard output, as JSON
extern_c int
EnergyAngularPrintJSON(ConstHandle2ConstEnergyAngular This);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
EnergyAngularLabelHas(ConstHandle2ConstEnergyAngular This);

// +++ Get
// +++ Returns by value
extern_c const char *
EnergyAngularLabelGet(ConstHandle2ConstEnergyAngular This);

// +++ Set
extern_c void
EnergyAngularLabelSet(ConstHandle2EnergyAngular This, const char *const label);


// -----------------------------------------------------------------------------
// Metadatum: productFrame
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
EnergyAngularProductFrameHas(ConstHandle2ConstEnergyAngular This);

// +++ Get
// +++ Returns by value
extern_c const char *
EnergyAngularProductFrameGet(ConstHandle2ConstEnergyAngular This);

// +++ Set
extern_c void
EnergyAngularProductFrameSet(ConstHandle2EnergyAngular This, const char *const productFrame);


// -----------------------------------------------------------------------------
// Child: XYs3d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
EnergyAngularXYs3dHas(ConstHandle2ConstEnergyAngular This);

// --- Get, const
extern_c Handle2ConstXYs3d
EnergyAngularXYs3dGetConst(ConstHandle2ConstEnergyAngular This);

// +++ Get, non-const
extern_c Handle2XYs3d
EnergyAngularXYs3dGet(ConstHandle2EnergyAngular This);

// +++ Set
extern_c void
EnergyAngularXYs3dSet(ConstHandle2EnergyAngular This, ConstHandle2ConstXYs3d XYs3d);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/mean/EnergyAngular/src/custom.h"

#undef extern_c
#endif
