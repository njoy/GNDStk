
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
// Styles is the basic handle type in this file. Example:
//    // Create a default Styles object:
//    Styles handle = StylesDefault();
// Functions involving Styles are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_COMMON_STYLES
#define C_INTERFACE_ALPHA_V2_0_COMMON_STYLES

#include "GNDStk.h"
#include "v2.0/common/Evaluated.h"
#include "v2.0/mean/CrossSectionReconstructed.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct StylesClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Styles
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct StylesClass *Styles;

// --- Const-aware handles.
typedef const struct StylesClass *const ConstHandle2ConstStyles;
typedef       struct StylesClass *const ConstHandle2Styles;
typedef const struct StylesClass *      Handle2ConstStyles;
typedef       struct StylesClass *      Handle2Styles;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstStyles
StylesDefaultConst();

// +++ Create, default
extern_c Handle2Styles
StylesDefault();

// --- Create, general, const
extern_c Handle2ConstStyles
StylesCreateConst(
   ConstHandle2ConstEvaluated evaluated,
   ConstHandle2ConstCrossSectionReconstructed crossSectionReconstructed
);

// +++ Create, general
extern_c Handle2Styles
StylesCreate(
   ConstHandle2ConstEvaluated evaluated,
   ConstHandle2ConstCrossSectionReconstructed crossSectionReconstructed
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
StylesAssign(ConstHandle2Styles This, ConstHandle2ConstStyles from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
StylesDelete(ConstHandle2ConstStyles This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
StylesRead(ConstHandle2Styles This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
StylesWrite(ConstHandle2ConstStyles This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
StylesPrint(ConstHandle2ConstStyles This);

// +++ Print to standard output, as XML
extern_c int
StylesPrintXML(ConstHandle2ConstStyles This);

// +++ Print to standard output, as JSON
extern_c int
StylesPrintJSON(ConstHandle2ConstStyles This);


// -----------------------------------------------------------------------------
// Child: evaluated
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
StylesEvaluatedHas(ConstHandle2ConstStyles This);

// --- Get, const
extern_c Handle2ConstEvaluated
StylesEvaluatedGetConst(ConstHandle2ConstStyles This);

// +++ Get, non-const
extern_c Handle2Evaluated
StylesEvaluatedGet(ConstHandle2Styles This);

// +++ Set
extern_c void
StylesEvaluatedSet(ConstHandle2Styles This, ConstHandle2ConstEvaluated evaluated);


// -----------------------------------------------------------------------------
// Child: crossSectionReconstructed
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
StylesCrossSectionReconstructedHas(ConstHandle2ConstStyles This);

// --- Get, const
extern_c Handle2ConstCrossSectionReconstructed
StylesCrossSectionReconstructedGetConst(ConstHandle2ConstStyles This);

// +++ Get, non-const
extern_c Handle2CrossSectionReconstructed
StylesCrossSectionReconstructedGet(ConstHandle2Styles This);

// +++ Set
extern_c void
StylesCrossSectionReconstructedSet(ConstHandle2Styles This, ConstHandle2ConstCrossSectionReconstructed crossSectionReconstructed);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/common/Styles/src/custom.h"

#undef extern_c
#endif
