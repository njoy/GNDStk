
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
//    // +++ comment
// Constructs you're LESS likely to care about are preceded with:
//    // --- comment
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

#ifndef C_INTERFACE_PROTO_V1_9_CONTAINERS_GRID
#define C_INTERFACE_PROTO_V1_9_CONTAINERS_GRID

#include "GNDStk.h"
#include "v1.9/containers/Values.h"
#include "v1.9/containers/Link.h"

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
   const enums::Interpolation interpolation,
   const char *const label,
   const enums::GridStyle style,
   const char *const unit,
);

// +++ Create, general
extern_c Handle2Grid
GridCreate(
   const int index,
   const enums::Interpolation interpolation,
   const char *const label,
   const enums::GridStyle style,
   const char *const unit,
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
GridAssign(ConstHandle2Grid This, ConstHandle2ConstGrid from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
GridDelete(ConstHandle2ConstGrid This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
GridRead(ConstHandle2Grid This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
GridWrite(ConstHandle2ConstGrid This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
GridPrint(ConstHandle2ConstGrid This);

// +++ Print to standard output, as XML
extern_c int
GridPrintXML(ConstHandle2ConstGrid This);

// +++ Print to standard output, as JSON
extern_c int
GridPrintJSON(ConstHandle2ConstGrid This);


// -----------------------------------------------------------------------------
// Metadatum: index
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
GridIndexHas(ConstHandle2ConstGrid This);

// +++ Get
// +++ Returns by value
extern_c int
GridIndexGet(ConstHandle2ConstGrid This);

// +++ Set
extern_c void
GridIndexSet(ConstHandle2Grid This, const int index);


// -----------------------------------------------------------------------------
// Metadatum: interpolation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
GridInterpolationHas(ConstHandle2ConstGrid This);

// +++ Get
// +++ Returns by value
extern_c enums::Interpolation
GridInterpolationGet(ConstHandle2ConstGrid This);

// +++ Set
extern_c void
GridInterpolationSet(ConstHandle2Grid This, const enums::Interpolation interpolation);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
GridLabelHas(ConstHandle2ConstGrid This);

// +++ Get
// +++ Returns by value
extern_c const char *
GridLabelGet(ConstHandle2ConstGrid This);

// +++ Set
extern_c void
GridLabelSet(ConstHandle2Grid This, const char *const label);


// -----------------------------------------------------------------------------
// Metadatum: style
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
GridStyleHas(ConstHandle2ConstGrid This);

// +++ Get
// +++ Returns by value
extern_c enums::GridStyle
GridStyleGet(ConstHandle2ConstGrid This);

// +++ Set
extern_c void
GridStyleSet(ConstHandle2Grid This, const enums::GridStyle style);


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
GridUnitHas(ConstHandle2ConstGrid This);

// +++ Get
// +++ Returns by value
extern_c const char *
GridUnitGet(ConstHandle2ConstGrid This);

// +++ Set
extern_c void
GridUnitSet(ConstHandle2Grid This, const char *const unit);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
