
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
// ScatteringRadius is the basic handle type in this file. Example:
//    // Create a default ScatteringRadius object:
//    ScatteringRadius handle = ScatteringRadiusDefault();
// Functions involving ScatteringRadius are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_SCATTERINGRADIUS
#define C_INTERFACE_ALPHA_V2_0_GENERAL_SCATTERINGRADIUS

#include "GNDStk.h"
#include "v2.0/general/Constant1d.h"
#include "v2.0/general/XYs1d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ScatteringRadiusClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ScatteringRadius
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ScatteringRadiusClass *ScatteringRadius;

// --- Const-aware handles.
typedef const struct ScatteringRadiusClass *const ConstHandle2ConstScatteringRadius;
typedef       struct ScatteringRadiusClass *const ConstHandle2ScatteringRadius;
typedef const struct ScatteringRadiusClass *      Handle2ConstScatteringRadius;
typedef       struct ScatteringRadiusClass *      Handle2ScatteringRadius;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstScatteringRadius
ScatteringRadiusDefaultConst();

// +++ Create, default
extern_c Handle2ScatteringRadius
ScatteringRadiusDefault();

// --- Create, general, const
extern_c Handle2ConstScatteringRadius
ScatteringRadiusCreateConst(
   ConstHandle2ConstConstant1d constant1d,
   ConstHandle2ConstXYs1d XYs1d
);

// +++ Create, general
extern_c Handle2ScatteringRadius
ScatteringRadiusCreate(
   ConstHandle2ConstConstant1d constant1d,
   ConstHandle2ConstXYs1d XYs1d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ScatteringRadiusAssign(ConstHandle2ScatteringRadius This, ConstHandle2ConstScatteringRadius from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ScatteringRadiusDelete(ConstHandle2ConstScatteringRadius This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ScatteringRadiusRead(ConstHandle2ScatteringRadius This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ScatteringRadiusWrite(ConstHandle2ConstScatteringRadius This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ScatteringRadiusPrint(ConstHandle2ConstScatteringRadius This);

// +++ Print to standard output, as XML
extern_c int
ScatteringRadiusPrintXML(ConstHandle2ConstScatteringRadius This);

// +++ Print to standard output, as JSON
extern_c int
ScatteringRadiusPrintJSON(ConstHandle2ConstScatteringRadius This);


// -----------------------------------------------------------------------------
// Child: constant1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ScatteringRadiusConstant1dHas(ConstHandle2ConstScatteringRadius This);

// --- Get, const
extern_c Handle2ConstConstant1d
ScatteringRadiusConstant1dGetConst(ConstHandle2ConstScatteringRadius This);

// +++ Get, non-const
extern_c Handle2Constant1d
ScatteringRadiusConstant1dGet(ConstHandle2ScatteringRadius This);

// +++ Set
extern_c void
ScatteringRadiusConstant1dSet(ConstHandle2ScatteringRadius This, ConstHandle2ConstConstant1d constant1d);


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ScatteringRadiusXYs1dHas(ConstHandle2ConstScatteringRadius This);

// --- Get, const
extern_c Handle2ConstXYs1d
ScatteringRadiusXYs1dGetConst(ConstHandle2ConstScatteringRadius This);

// +++ Get, non-const
extern_c Handle2XYs1d
ScatteringRadiusXYs1dGet(ConstHandle2ScatteringRadius This);

// +++ Set
extern_c void
ScatteringRadiusXYs1dSet(ConstHandle2ScatteringRadius This, ConstHandle2ConstXYs1d XYs1d);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/ScatteringRadius/src/custom.h"

#undef extern_c
#endif
