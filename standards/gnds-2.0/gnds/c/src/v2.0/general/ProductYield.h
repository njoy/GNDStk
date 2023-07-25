
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
// ProductYield is the basic handle type in this file. Example:
//    // Create a default ProductYield object:
//    ProductYield handle = ProductYieldDefault();
// Functions involving ProductYield are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_PRODUCTYIELD
#define C_INTERFACE_GNDS_V2_0_GENERAL_PRODUCTYIELD

#include "GNDStk.h"
#include "v2.0/reduced/Nuclides.h"
#include "v2.0/general/ElapsedTimes.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ProductYieldClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ProductYield
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ProductYieldClass *ProductYield;

// --- Const-aware handles.
typedef const struct ProductYieldClass *const ConstHandle2ConstProductYield;
typedef       struct ProductYieldClass *const ConstHandle2ProductYield;
typedef const struct ProductYieldClass *      Handle2ConstProductYield;
typedef       struct ProductYieldClass *      Handle2ProductYield;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstProductYield
ProductYieldDefaultConst();

// +++ Create, default
extern_c Handle2ProductYield
ProductYieldDefault();

// --- Create, general, const
extern_c Handle2ConstProductYield
ProductYieldCreateConst(
   const char *const label,
   ConstHandle2ConstNuclides nuclides,
   ConstHandle2ConstElapsedTimes elapsedTimes
);

// +++ Create, general
extern_c Handle2ProductYield
ProductYieldCreate(
   const char *const label,
   ConstHandle2ConstNuclides nuclides,
   ConstHandle2ConstElapsedTimes elapsedTimes
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ProductYieldAssign(ConstHandle2ProductYield self, ConstHandle2ConstProductYield from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ProductYieldDelete(ConstHandle2ConstProductYield self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ProductYieldRead(ConstHandle2ProductYield self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ProductYieldWrite(ConstHandle2ConstProductYield self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ProductYieldPrint(ConstHandle2ConstProductYield self);

// +++ Print to standard output, as XML
extern_c int
ProductYieldPrintXML(ConstHandle2ConstProductYield self);

// +++ Print to standard output, as JSON
extern_c int
ProductYieldPrintJSON(ConstHandle2ConstProductYield self);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ProductYieldLabelHas(ConstHandle2ConstProductYield self);

// +++ Get
// +++ Returns by value
extern_c const char *
ProductYieldLabelGet(ConstHandle2ConstProductYield self);

// +++ Set
extern_c void
ProductYieldLabelSet(ConstHandle2ProductYield self, const char *const label);


// -----------------------------------------------------------------------------
// Child: nuclides
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ProductYieldNuclidesHas(ConstHandle2ConstProductYield self);

// --- Get, const
extern_c Handle2ConstNuclides
ProductYieldNuclidesGetConst(ConstHandle2ConstProductYield self);

// +++ Get, non-const
extern_c Handle2Nuclides
ProductYieldNuclidesGet(ConstHandle2ProductYield self);

// +++ Set
extern_c void
ProductYieldNuclidesSet(ConstHandle2ProductYield self, ConstHandle2ConstNuclides nuclides);


// -----------------------------------------------------------------------------
// Child: elapsedTimes
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ProductYieldElapsedTimesHas(ConstHandle2ConstProductYield self);

// --- Get, const
extern_c Handle2ConstElapsedTimes
ProductYieldElapsedTimesGetConst(ConstHandle2ConstProductYield self);

// +++ Get, non-const
extern_c Handle2ElapsedTimes
ProductYieldElapsedTimesGet(ConstHandle2ProductYield self);

// +++ Set
extern_c void
ProductYieldElapsedTimesSet(ConstHandle2ProductYield self, ConstHandle2ConstElapsedTimes elapsedTimes);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/ProductYield/src/custom.h"

#undef extern_c
#endif
