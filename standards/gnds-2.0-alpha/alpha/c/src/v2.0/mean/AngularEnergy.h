
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
// AngularEnergy is the basic handle type in this file. Example:
//    // Create a default AngularEnergy object:
//    AngularEnergy handle = AngularEnergyDefault();
// Functions involving AngularEnergy are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_MEAN_ANGULARENERGY
#define C_INTERFACE_ALPHA_V2_0_MEAN_ANGULARENERGY

#include "GNDStk.h"
#include "v2.0/mean/XYs3d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct AngularEnergyClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ AngularEnergy
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct AngularEnergyClass *AngularEnergy;

// --- Const-aware handles.
typedef const struct AngularEnergyClass *const ConstHandle2ConstAngularEnergy;
typedef       struct AngularEnergyClass *const ConstHandle2AngularEnergy;
typedef const struct AngularEnergyClass *      Handle2ConstAngularEnergy;
typedef       struct AngularEnergyClass *      Handle2AngularEnergy;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstAngularEnergy
AngularEnergyDefaultConst();

// +++ Create, default
extern_c Handle2AngularEnergy
AngularEnergyDefault();

// --- Create, general, const
extern_c Handle2ConstAngularEnergy
AngularEnergyCreateConst(
   const char *const label,
   const char *const productFrame,
   ConstHandle2ConstXYs3d XYs3d
);

// +++ Create, general
extern_c Handle2AngularEnergy
AngularEnergyCreate(
   const char *const label,
   const char *const productFrame,
   ConstHandle2ConstXYs3d XYs3d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
AngularEnergyAssign(ConstHandle2AngularEnergy This, ConstHandle2ConstAngularEnergy from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
AngularEnergyDelete(ConstHandle2ConstAngularEnergy This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
AngularEnergyRead(ConstHandle2AngularEnergy This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
AngularEnergyWrite(ConstHandle2ConstAngularEnergy This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
AngularEnergyPrint(ConstHandle2ConstAngularEnergy This);

// +++ Print to standard output, as XML
extern_c int
AngularEnergyPrintXML(ConstHandle2ConstAngularEnergy This);

// +++ Print to standard output, as JSON
extern_c int
AngularEnergyPrintJSON(ConstHandle2ConstAngularEnergy This);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AngularEnergyLabelHas(ConstHandle2ConstAngularEnergy This);

// +++ Get
// +++ Returns by value
extern_c const char *
AngularEnergyLabelGet(ConstHandle2ConstAngularEnergy This);

// +++ Set
extern_c void
AngularEnergyLabelSet(ConstHandle2AngularEnergy This, const char *const label);


// -----------------------------------------------------------------------------
// Metadatum: productFrame
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AngularEnergyProductFrameHas(ConstHandle2ConstAngularEnergy This);

// +++ Get
// +++ Returns by value
extern_c const char *
AngularEnergyProductFrameGet(ConstHandle2ConstAngularEnergy This);

// +++ Set
extern_c void
AngularEnergyProductFrameSet(ConstHandle2AngularEnergy This, const char *const productFrame);


// -----------------------------------------------------------------------------
// Child: XYs3d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AngularEnergyXYs3dHas(ConstHandle2ConstAngularEnergy This);

// --- Get, const
extern_c Handle2ConstXYs3d
AngularEnergyXYs3dGetConst(ConstHandle2ConstAngularEnergy This);

// +++ Get, non-const
extern_c Handle2XYs3d
AngularEnergyXYs3dGet(ConstHandle2AngularEnergy This);

// +++ Set
extern_c void
AngularEnergyXYs3dSet(ConstHandle2AngularEnergy This, ConstHandle2ConstXYs3d XYs3d);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/mean/AngularEnergy/src/custom.h"

#undef extern_c
#endif
