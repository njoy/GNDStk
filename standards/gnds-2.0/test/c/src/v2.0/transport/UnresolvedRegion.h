
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
// UnresolvedRegion is the basic handle type in this file. Example:
//    // Create a default UnresolvedRegion object:
//    UnresolvedRegion handle = UnresolvedRegionDefault();
// Functions involving UnresolvedRegion are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_TRANSPORT_UNRESOLVEDREGION
#define C_INTERFACE_TEST_V2_0_TRANSPORT_UNRESOLVEDREGION

#include "GNDStk.h"
#include "v2.0/containers/XYs1d.h"
#include "v2.0/containers/Regions1d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct UnresolvedRegionClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ UnresolvedRegion
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct UnresolvedRegionClass *UnresolvedRegion;

// --- Const-aware handles.
typedef const struct UnresolvedRegionClass *const ConstHandle2ConstUnresolvedRegion;
typedef       struct UnresolvedRegionClass *const ConstHandle2UnresolvedRegion;
typedef const struct UnresolvedRegionClass *      Handle2ConstUnresolvedRegion;
typedef       struct UnresolvedRegionClass *      Handle2UnresolvedRegion;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstUnresolvedRegion
UnresolvedRegionDefaultConst();

// +++ Create, default
extern_c Handle2UnresolvedRegion
UnresolvedRegionDefault();

// --- Create, general, const
extern_c Handle2ConstUnresolvedRegion
UnresolvedRegionCreateConst(
);

// +++ Create, general
extern_c Handle2UnresolvedRegion
UnresolvedRegionCreate(
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
UnresolvedRegionAssign(ConstHandle2UnresolvedRegion This, ConstHandle2ConstUnresolvedRegion from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
UnresolvedRegionDelete(ConstHandle2ConstUnresolvedRegion This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
UnresolvedRegionRead(ConstHandle2UnresolvedRegion This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
UnresolvedRegionWrite(ConstHandle2ConstUnresolvedRegion This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
UnresolvedRegionPrint(ConstHandle2ConstUnresolvedRegion This);

// +++ Print to standard output, as XML
extern_c int
UnresolvedRegionPrintXML(ConstHandle2ConstUnresolvedRegion This);

// +++ Print to standard output, as JSON
extern_c int
UnresolvedRegionPrintJSON(ConstHandle2ConstUnresolvedRegion This);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/transport/UnresolvedRegion/src/custom.h"

#undef extern_c
#endif
