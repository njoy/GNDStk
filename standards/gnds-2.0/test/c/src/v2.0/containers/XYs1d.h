
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
// XYs1d is the basic handle type in this file. Example:
//    // Create a default XYs1d object:
//    XYs1d handle = XYs1dDefault();
// Functions involving XYs1d are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_CONTAINERS_XYS1D
#define C_INTERFACE_TEST_V2_0_CONTAINERS_XYS1D

#include "GNDStk.h"
#include "v2.0/containers/Axes.h"
#include "v2.0/extra/Uncertainty.h"
#include "v2.0/containers/Values.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct XYs1dClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ XYs1d
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct XYs1dClass *XYs1d;

// --- Const-aware handles.
typedef const struct XYs1dClass *const ConstHandle2ConstXYs1d;
typedef       struct XYs1dClass *const ConstHandle2XYs1d;
typedef const struct XYs1dClass *      Handle2ConstXYs1d;
typedef       struct XYs1dClass *      Handle2XYs1d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstXYs1d
XYs1dDefaultConst();

// +++ Create, default
extern_c Handle2XYs1d
XYs1dDefault();

// --- Create, general, const
extern_c Handle2ConstXYs1d
XYs1dCreateConst(
   const Integer32 index,
   const enums::Interpolation interpolation,
   const XMLName label,
   const Float64 outerDomainValue,
   ConstHandle2ConstAxes axes,
   ConstHandle2ConstUncertainty uncertainty,
   ConstHandle2ConstValues values
);

// +++ Create, general
extern_c Handle2XYs1d
XYs1dCreate(
   const Integer32 index,
   const enums::Interpolation interpolation,
   const XMLName label,
   const Float64 outerDomainValue,
   ConstHandle2ConstAxes axes,
   ConstHandle2ConstUncertainty uncertainty,
   ConstHandle2ConstValues values
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
XYs1dAssign(ConstHandle2XYs1d self, ConstHandle2ConstXYs1d from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
XYs1dDelete(ConstHandle2ConstXYs1d self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
XYs1dRead(ConstHandle2XYs1d self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
XYs1dWrite(ConstHandle2ConstXYs1d self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
XYs1dPrint(ConstHandle2ConstXYs1d self);

// +++ Print to standard output, as XML
extern_c int
XYs1dPrintXML(ConstHandle2ConstXYs1d self);

// +++ Print to standard output, as JSON
extern_c int
XYs1dPrintJSON(ConstHandle2ConstXYs1d self);


// -----------------------------------------------------------------------------
// Metadatum: index
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
XYs1dIndexHas(ConstHandle2ConstXYs1d self);

// +++ Get
// +++ Returns by value
extern_c Integer32
XYs1dIndexGet(ConstHandle2ConstXYs1d self);

// +++ Set
extern_c void
XYs1dIndexSet(ConstHandle2XYs1d self, const Integer32 index);


// -----------------------------------------------------------------------------
// Metadatum: interpolation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
XYs1dInterpolationHas(ConstHandle2ConstXYs1d self);

// +++ Get
// +++ Returns by value
extern_c enums::Interpolation
XYs1dInterpolationGet(ConstHandle2ConstXYs1d self);

// +++ Set
extern_c void
XYs1dInterpolationSet(ConstHandle2XYs1d self, const enums::Interpolation interpolation);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
XYs1dLabelHas(ConstHandle2ConstXYs1d self);

// +++ Get
// +++ Returns by value
extern_c XMLName
XYs1dLabelGet(ConstHandle2ConstXYs1d self);

// +++ Set
extern_c void
XYs1dLabelSet(ConstHandle2XYs1d self, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: outerDomainValue
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
XYs1dOuterDomainValueHas(ConstHandle2ConstXYs1d self);

// +++ Get
// +++ Returns by value
extern_c Float64
XYs1dOuterDomainValueGet(ConstHandle2ConstXYs1d self);

// +++ Set
extern_c void
XYs1dOuterDomainValueSet(ConstHandle2XYs1d self, const Float64 outerDomainValue);


// -----------------------------------------------------------------------------
// Child: axes
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
XYs1dAxesHas(ConstHandle2ConstXYs1d self);

// --- Get, const
extern_c Handle2ConstAxes
XYs1dAxesGetConst(ConstHandle2ConstXYs1d self);

// +++ Get, non-const
extern_c Handle2Axes
XYs1dAxesGet(ConstHandle2XYs1d self);

// +++ Set
extern_c void
XYs1dAxesSet(ConstHandle2XYs1d self, ConstHandle2ConstAxes axes);


// -----------------------------------------------------------------------------
// Child: uncertainty
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
XYs1dUncertaintyHas(ConstHandle2ConstXYs1d self);

// --- Get, const
extern_c Handle2ConstUncertainty
XYs1dUncertaintyGetConst(ConstHandle2ConstXYs1d self);

// +++ Get, non-const
extern_c Handle2Uncertainty
XYs1dUncertaintyGet(ConstHandle2XYs1d self);

// +++ Set
extern_c void
XYs1dUncertaintySet(ConstHandle2XYs1d self, ConstHandle2ConstUncertainty uncertainty);


// -----------------------------------------------------------------------------
// Child: values
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
XYs1dValuesHas(ConstHandle2ConstXYs1d self);

// --- Get, const
extern_c Handle2ConstValues
XYs1dValuesGetConst(ConstHandle2ConstXYs1d self);

// +++ Get, non-const
extern_c Handle2Values
XYs1dValuesGet(ConstHandle2XYs1d self);

// +++ Set
extern_c void
XYs1dValuesSet(ConstHandle2XYs1d self, ConstHandle2ConstValues values);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/containers/XYs1d/src/custom.h"

#undef extern_c
#endif
