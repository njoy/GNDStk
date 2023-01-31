
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
// ResolvedRegion is the basic handle type in this file. Example:
//    // Create a default ResolvedRegion object:
//    ResolvedRegion handle = ResolvedRegionDefault();
// Functions involving ResolvedRegion are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_MEAN_RESOLVEDREGION
#define C_INTERFACE_ALPHA_V2_0_MEAN_RESOLVEDREGION

#include "GNDStk.h"
#include "v2.0/common/XYs1d.h"
#include "v2.0/mean/Regions1d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ResolvedRegionClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ResolvedRegion
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ResolvedRegionClass *ResolvedRegion;

// --- Const-aware handles.
typedef const struct ResolvedRegionClass *const ConstHandle2ConstResolvedRegion;
typedef       struct ResolvedRegionClass *const ConstHandle2ResolvedRegion;
typedef const struct ResolvedRegionClass *      Handle2ConstResolvedRegion;
typedef       struct ResolvedRegionClass *      Handle2ResolvedRegion;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstResolvedRegion
ResolvedRegionDefaultConst();

// +++ Create, default
extern_c Handle2ResolvedRegion
ResolvedRegionDefault();

// --- Create, general, const
extern_c Handle2ConstResolvedRegion
ResolvedRegionCreateConst(
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstRegions1d regions1d
);

// +++ Create, general
extern_c Handle2ResolvedRegion
ResolvedRegionCreate(
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstRegions1d regions1d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ResolvedRegionAssign(ConstHandle2ResolvedRegion This, ConstHandle2ConstResolvedRegion from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ResolvedRegionDelete(ConstHandle2ConstResolvedRegion This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ResolvedRegionRead(ConstHandle2ResolvedRegion This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ResolvedRegionWrite(ConstHandle2ConstResolvedRegion This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ResolvedRegionPrint(ConstHandle2ConstResolvedRegion This);

// +++ Print to standard output, as XML
extern_c int
ResolvedRegionPrintXML(ConstHandle2ConstResolvedRegion This);

// +++ Print to standard output, as JSON
extern_c int
ResolvedRegionPrintJSON(ConstHandle2ConstResolvedRegion This);


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ResolvedRegionXYs1dHas(ConstHandle2ConstResolvedRegion This);

// --- Get, const
extern_c Handle2ConstXYs1d
ResolvedRegionXYs1dGetConst(ConstHandle2ConstResolvedRegion This);

// +++ Get, non-const
extern_c Handle2XYs1d
ResolvedRegionXYs1dGet(ConstHandle2ResolvedRegion This);

// +++ Set
extern_c void
ResolvedRegionXYs1dSet(ConstHandle2ResolvedRegion This, ConstHandle2ConstXYs1d XYs1d);


// -----------------------------------------------------------------------------
// Child: regions1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ResolvedRegionRegions1dHas(ConstHandle2ConstResolvedRegion This);

// --- Get, const
extern_c Handle2ConstRegions1d
ResolvedRegionRegions1dGetConst(ConstHandle2ConstResolvedRegion This);

// +++ Get, non-const
extern_c Handle2Regions1d
ResolvedRegionRegions1dGet(ConstHandle2ResolvedRegion This);

// +++ Set
extern_c void
ResolvedRegionRegions1dSet(ConstHandle2ResolvedRegion This, ConstHandle2ConstRegions1d regions1d);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/mean/ResolvedRegion/src/custom.h"

#undef extern_c
#endif
