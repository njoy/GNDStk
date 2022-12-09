
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
// Ys1d is the basic handle type in this file. Example:
//    // Create a default Ys1d object:
//    Ys1d handle = Ys1dDefault();
// Functions involving Ys1d are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_CONTAINERS_YS1D
#define C_INTERFACE_TEST_V2_0_CONTAINERS_YS1D

#include "GNDStk.h"
#include "v2.0/containers/Axes.h"
#include "v2.0/containers/Values.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct Ys1dClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Ys1d
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct Ys1dClass *Ys1d;

// --- Const-aware handles.
typedef const struct Ys1dClass *const ConstHandle2ConstYs1d;
typedef       struct Ys1dClass *const ConstHandle2Ys1d;
typedef const struct Ys1dClass *      Handle2ConstYs1d;
typedef       struct Ys1dClass *      Handle2Ys1d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstYs1d
Ys1dDefaultConst();

// +++ Create, default
extern_c Handle2Ys1d
Ys1dDefault();

// --- Create, general, const
extern_c Handle2ConstYs1d
Ys1dCreateConst(
   const enums::Interpolation interpolation,
   const XMLName label,
   ConstHandle2ConstAxes axes,
   ConstHandle2ConstValues values
);

// +++ Create, general
extern_c Handle2Ys1d
Ys1dCreate(
   const enums::Interpolation interpolation,
   const XMLName label,
   ConstHandle2ConstAxes axes,
   ConstHandle2ConstValues values
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
Ys1dAssign(ConstHandle2Ys1d This, ConstHandle2ConstYs1d from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
Ys1dDelete(ConstHandle2ConstYs1d This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
Ys1dRead(ConstHandle2Ys1d This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
Ys1dWrite(ConstHandle2ConstYs1d This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
Ys1dPrint(ConstHandle2ConstYs1d This);

// +++ Print to standard output, as XML
extern_c int
Ys1dPrintXML(ConstHandle2ConstYs1d This);

// +++ Print to standard output, as JSON
extern_c int
Ys1dPrintJSON(ConstHandle2ConstYs1d This);


// -----------------------------------------------------------------------------
// Metadatum: interpolation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Ys1dInterpolationHas(ConstHandle2ConstYs1d This);

// +++ Get
// +++ Returns by value
extern_c enums::Interpolation
Ys1dInterpolationGet(ConstHandle2ConstYs1d This);

// +++ Set
extern_c void
Ys1dInterpolationSet(ConstHandle2Ys1d This, const enums::Interpolation interpolation);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Ys1dLabelHas(ConstHandle2ConstYs1d This);

// +++ Get
// +++ Returns by value
extern_c XMLName
Ys1dLabelGet(ConstHandle2ConstYs1d This);

// +++ Set
extern_c void
Ys1dLabelSet(ConstHandle2Ys1d This, const XMLName label);


// -----------------------------------------------------------------------------
// Child: axes
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Ys1dAxesHas(ConstHandle2ConstYs1d This);

// --- Get, const
extern_c Handle2ConstAxes
Ys1dAxesGetConst(ConstHandle2ConstYs1d This);

// +++ Get, non-const
extern_c Handle2Axes
Ys1dAxesGet(ConstHandle2Ys1d This);

// +++ Set
extern_c void
Ys1dAxesSet(ConstHandle2Ys1d This, ConstHandle2ConstAxes axes);


// -----------------------------------------------------------------------------
// Child: values
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Ys1dValuesHas(ConstHandle2ConstYs1d This);

// --- Get, const
extern_c Handle2ConstValues
Ys1dValuesGetConst(ConstHandle2ConstYs1d This);

// +++ Get, non-const
extern_c Handle2Values
Ys1dValuesGet(ConstHandle2Ys1d This);

// +++ Set
extern_c void
Ys1dValuesSet(ConstHandle2Ys1d This, ConstHandle2ConstValues values);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
