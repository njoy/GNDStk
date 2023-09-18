
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
// XYs3d is the basic handle type in this file. Example:
//    // Create a default XYs3d object:
//    XYs3d handle = XYs3dDefault();
// Functions involving XYs3d are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_XYS3D
#define C_INTERFACE_GNDS_V2_0_GENERAL_XYS3D

#include "GNDStk.h"
#include "v2.0/general/Axes.h"
#include "v2.0/general/Function2ds.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct XYs3dClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ XYs3d
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct XYs3dClass *XYs3d;

// --- Const-aware handles.
typedef const struct XYs3dClass *const ConstHandle2ConstXYs3d;
typedef       struct XYs3dClass *const ConstHandle2XYs3d;
typedef const struct XYs3dClass *      Handle2ConstXYs3d;
typedef       struct XYs3dClass *      Handle2XYs3d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstXYs3d
XYs3dDefaultConst();

// +++ Create, default
extern_c Handle2XYs3d
XYs3dDefault();

// --- Create, general, const
extern_c Handle2ConstXYs3d
XYs3dCreateConst(
   const char *const interpolationQualifier,
   ConstHandle2ConstAxes axes,
   ConstHandle2Function2ds *const function2ds, const size_t function2dsSize
);

// +++ Create, general
extern_c Handle2XYs3d
XYs3dCreate(
   const char *const interpolationQualifier,
   ConstHandle2ConstAxes axes,
   ConstHandle2Function2ds *const function2ds, const size_t function2dsSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
XYs3dAssign(ConstHandle2XYs3d self, ConstHandle2ConstXYs3d from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
XYs3dDelete(ConstHandle2ConstXYs3d self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
XYs3dRead(ConstHandle2XYs3d self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
XYs3dWrite(ConstHandle2ConstXYs3d self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
XYs3dPrint(ConstHandle2ConstXYs3d self);

// +++ Print to standard output, as XML
extern_c int
XYs3dPrintXML(ConstHandle2ConstXYs3d self);

// +++ Print to standard output, as JSON
extern_c int
XYs3dPrintJSON(ConstHandle2ConstXYs3d self);


// -----------------------------------------------------------------------------
// Metadatum: interpolationQualifier
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
XYs3dInterpolationQualifierHas(ConstHandle2ConstXYs3d self);

// +++ Get
// +++ Returns by value
extern_c const char *
XYs3dInterpolationQualifierGet(ConstHandle2ConstXYs3d self);

// +++ Set
extern_c void
XYs3dInterpolationQualifierSet(ConstHandle2XYs3d self, const char *const interpolationQualifier);


// -----------------------------------------------------------------------------
// Child: axes
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
XYs3dAxesHas(ConstHandle2ConstXYs3d self);

// --- Get, const
extern_c Handle2ConstAxes
XYs3dAxesGetConst(ConstHandle2ConstXYs3d self);

// +++ Get
extern_c Handle2Axes
XYs3dAxesGet(ConstHandle2XYs3d self);

// +++ Set
extern_c void
XYs3dAxesSet(ConstHandle2XYs3d self, ConstHandle2ConstAxes axes);


// -----------------------------------------------------------------------------
// Child: function2ds
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
XYs3dFunction2dsHas(ConstHandle2ConstXYs3d self);

// +++ Clear
extern_c void
XYs3dFunction2dsClear(ConstHandle2XYs3d self);

// +++ Size
extern_c size_t
XYs3dFunction2dsSize(ConstHandle2ConstXYs3d self);

// +++ Add
extern_c void
XYs3dFunction2dsAdd(ConstHandle2XYs3d self, ConstHandle2ConstFunction2ds function2ds);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstFunction2ds
XYs3dFunction2dsGetConst(ConstHandle2ConstXYs3d self, const size_t index_);

// +++ Get, by index \in [0,size)
extern_c Handle2Function2ds
XYs3dFunction2dsGet(ConstHandle2XYs3d self, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
XYs3dFunction2dsSet(
   ConstHandle2XYs3d self,
   const size_t index_,
   ConstHandle2ConstFunction2ds function2ds
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/XYs3d/src/custom.h"

#undef extern_c
#endif
