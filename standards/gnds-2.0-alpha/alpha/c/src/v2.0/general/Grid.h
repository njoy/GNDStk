
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
// Grid is the basic handle type in this file. Example:
//    // Create a default Grid object:
//    Grid handle = GridDefault();
// Functions involving Grid are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_GRID
#define C_INTERFACE_ALPHA_V2_0_GENERAL_GRID

#include "GNDStk.h"
#include "v2.0/general/Link.h"
#include "v2.0/general/Values.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct GridClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Grid
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct GridClass *Grid;

// --- Const-aware handles.
typedef const struct GridClass *const ConstHandle2ConstGrid;
typedef       struct GridClass *const ConstHandle2Grid;
typedef const struct GridClass *      Handle2ConstGrid;
typedef       struct GridClass *      Handle2Grid;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstGrid
GridDefaultConst();

// +++ Create, default
extern_c Handle2Grid
GridDefault();

// --- Create, general, const
extern_c Handle2ConstGrid
GridCreateConst(
   const int index,
   const char *const label,
   const char *const unit,
   const char *const style,
   const char *const interpolation,
   ConstHandle2ConstLink link,
   ConstHandle2ConstValues values
);

// +++ Create, general
extern_c Handle2Grid
GridCreate(
   const int index,
   const char *const label,
   const char *const unit,
   const char *const style,
   const char *const interpolation,
   ConstHandle2ConstLink link,
   ConstHandle2ConstValues values
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
GridAssign(ConstHandle2Grid self, ConstHandle2ConstGrid from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
GridDelete(ConstHandle2ConstGrid self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
GridRead(ConstHandle2Grid self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
GridWrite(ConstHandle2ConstGrid self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
GridPrint(ConstHandle2ConstGrid self);

// +++ Print to standard output, as XML
extern_c int
GridPrintXML(ConstHandle2ConstGrid self);

// +++ Print to standard output, as JSON
extern_c int
GridPrintJSON(ConstHandle2ConstGrid self);


// -----------------------------------------------------------------------------
// Metadatum: index
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
GridIndexHas(ConstHandle2ConstGrid self);

// +++ Get
// +++ Returns by value
extern_c int
GridIndexGet(ConstHandle2ConstGrid self);

// +++ Set
extern_c void
GridIndexSet(ConstHandle2Grid self, const int index);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
GridLabelHas(ConstHandle2ConstGrid self);

// +++ Get
// +++ Returns by value
extern_c const char *
GridLabelGet(ConstHandle2ConstGrid self);

// +++ Set
extern_c void
GridLabelSet(ConstHandle2Grid self, const char *const label);


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
GridUnitHas(ConstHandle2ConstGrid self);

// +++ Get
// +++ Returns by value
extern_c const char *
GridUnitGet(ConstHandle2ConstGrid self);

// +++ Set
extern_c void
GridUnitSet(ConstHandle2Grid self, const char *const unit);


// -----------------------------------------------------------------------------
// Metadatum: style
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
GridStyleHas(ConstHandle2ConstGrid self);

// +++ Get
// +++ Returns by value
extern_c const char *
GridStyleGet(ConstHandle2ConstGrid self);

// +++ Set
extern_c void
GridStyleSet(ConstHandle2Grid self, const char *const style);


// -----------------------------------------------------------------------------
// Metadatum: interpolation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
GridInterpolationHas(ConstHandle2ConstGrid self);

// +++ Get
// +++ Returns by value
extern_c const char *
GridInterpolationGet(ConstHandle2ConstGrid self);

// +++ Set
extern_c void
GridInterpolationSet(ConstHandle2Grid self, const char *const interpolation);


// -----------------------------------------------------------------------------
// Child: link
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
GridLinkHas(ConstHandle2ConstGrid self);

// --- Get, const
extern_c Handle2ConstLink
GridLinkGetConst(ConstHandle2ConstGrid self);

// +++ Get, non-const
extern_c Handle2Link
GridLinkGet(ConstHandle2Grid self);

// +++ Set
extern_c void
GridLinkSet(ConstHandle2Grid self, ConstHandle2ConstLink link);


// -----------------------------------------------------------------------------
// Child: values
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
GridValuesHas(ConstHandle2ConstGrid self);

// --- Get, const
extern_c Handle2ConstValues
GridValuesGetConst(ConstHandle2ConstGrid self);

// +++ Get, non-const
extern_c Handle2Values
GridValuesGet(ConstHandle2Grid self);

// +++ Set
extern_c void
GridValuesSet(ConstHandle2Grid self, ConstHandle2ConstValues values);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Grid/src/custom.h"

#undef extern_c
#endif
