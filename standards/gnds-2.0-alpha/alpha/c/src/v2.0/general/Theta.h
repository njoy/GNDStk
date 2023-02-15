
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
// Theta is the basic handle type in this file. Example:
//    // Create a default Theta object:
//    Theta handle = ThetaDefault();
// Functions involving Theta are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_THETA
#define C_INTERFACE_ALPHA_V2_0_GENERAL_THETA

#include "GNDStk.h"
#include "v2.0/general/XYs1d.h"
#include "v2.0/general/Regions1d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ThetaClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Theta
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ThetaClass *Theta;

// --- Const-aware handles.
typedef const struct ThetaClass *const ConstHandle2ConstTheta;
typedef       struct ThetaClass *const ConstHandle2Theta;
typedef const struct ThetaClass *      Handle2ConstTheta;
typedef       struct ThetaClass *      Handle2Theta;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstTheta
ThetaDefaultConst();

// +++ Create, default
extern_c Handle2Theta
ThetaDefault();

// --- Create, general, const
extern_c Handle2ConstTheta
ThetaCreateConst(
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstRegions1d regions1d
);

// +++ Create, general
extern_c Handle2Theta
ThetaCreate(
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstRegions1d regions1d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ThetaAssign(ConstHandle2Theta self, ConstHandle2ConstTheta from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ThetaDelete(ConstHandle2ConstTheta self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ThetaRead(ConstHandle2Theta self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ThetaWrite(ConstHandle2ConstTheta self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ThetaPrint(ConstHandle2ConstTheta self);

// +++ Print to standard output, as XML
extern_c int
ThetaPrintXML(ConstHandle2ConstTheta self);

// +++ Print to standard output, as JSON
extern_c int
ThetaPrintJSON(ConstHandle2ConstTheta self);


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ThetaXYs1dHas(ConstHandle2ConstTheta self);

// --- Get, const
extern_c Handle2ConstXYs1d
ThetaXYs1dGetConst(ConstHandle2ConstTheta self);

// +++ Get, non-const
extern_c Handle2XYs1d
ThetaXYs1dGet(ConstHandle2Theta self);

// +++ Set
extern_c void
ThetaXYs1dSet(ConstHandle2Theta self, ConstHandle2ConstXYs1d XYs1d);


// -----------------------------------------------------------------------------
// Child: regions1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ThetaRegions1dHas(ConstHandle2ConstTheta self);

// --- Get, const
extern_c Handle2ConstRegions1d
ThetaRegions1dGetConst(ConstHandle2ConstTheta self);

// +++ Get, non-const
extern_c Handle2Regions1d
ThetaRegions1dGet(ConstHandle2Theta self);

// +++ Set
extern_c void
ThetaRegions1dSet(ConstHandle2Theta self, ConstHandle2ConstRegions1d regions1d);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Theta/src/custom.h"

#undef extern_c
#endif
