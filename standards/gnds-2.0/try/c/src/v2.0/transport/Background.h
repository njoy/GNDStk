
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
// Background is the basic handle type in this file. Example:
//    // Create a default Background object:
//    Background handle = BackgroundDefault();
// Functions involving Background are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_TRANSPORT_BACKGROUND
#define C_INTERFACE_TRY_V2_0_TRANSPORT_BACKGROUND

#include "GNDStk.h"
#include "v2.0/transport/ResolvedRegion.h"
#include "v2.0/transport/UnresolvedRegion.h"
#include "v2.0/transport/FastRegion.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct BackgroundClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Background
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct BackgroundClass *Background;

// --- Const-aware handles.
typedef const struct BackgroundClass *const ConstHandle2ConstBackground;
typedef       struct BackgroundClass *const ConstHandle2Background;
typedef const struct BackgroundClass *      Handle2ConstBackground;
typedef       struct BackgroundClass *      Handle2Background;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstBackground
BackgroundDefaultConst();

// +++ Create, default
extern_c Handle2Background
BackgroundDefault();

// --- Create, general, const
extern_c Handle2ConstBackground
BackgroundCreateConst(
   ConstHandle2ConstResolvedRegion resolvedRegion,
   ConstHandle2ConstUnresolvedRegion unresolvedRegion,
   ConstHandle2ConstFastRegion fastRegion
);

// +++ Create, general
extern_c Handle2Background
BackgroundCreate(
   ConstHandle2ConstResolvedRegion resolvedRegion,
   ConstHandle2ConstUnresolvedRegion unresolvedRegion,
   ConstHandle2ConstFastRegion fastRegion
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
BackgroundAssign(ConstHandle2Background This, ConstHandle2ConstBackground from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
BackgroundDelete(ConstHandle2ConstBackground This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
BackgroundRead(ConstHandle2Background This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
BackgroundWrite(ConstHandle2ConstBackground This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
BackgroundPrint(ConstHandle2ConstBackground This);

// +++ Print to standard output, as XML
extern_c int
BackgroundPrintXML(ConstHandle2ConstBackground This);

// +++ Print to standard output, as JSON
extern_c int
BackgroundPrintJSON(ConstHandle2ConstBackground This);


// -----------------------------------------------------------------------------
// Child: resolvedRegion
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BackgroundResolvedRegionHas(ConstHandle2ConstBackground This);

// --- Get, const
extern_c Handle2ConstResolvedRegion
BackgroundResolvedRegionGetConst(ConstHandle2ConstBackground This);

// +++ Get, non-const
extern_c Handle2ResolvedRegion
BackgroundResolvedRegionGet(ConstHandle2Background This);

// +++ Set
extern_c void
BackgroundResolvedRegionSet(ConstHandle2Background This, ConstHandle2ConstResolvedRegion resolvedRegion);


// -----------------------------------------------------------------------------
// Child: unresolvedRegion
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BackgroundUnresolvedRegionHas(ConstHandle2ConstBackground This);

// --- Get, const
extern_c Handle2ConstUnresolvedRegion
BackgroundUnresolvedRegionGetConst(ConstHandle2ConstBackground This);

// +++ Get, non-const
extern_c Handle2UnresolvedRegion
BackgroundUnresolvedRegionGet(ConstHandle2Background This);

// +++ Set
extern_c void
BackgroundUnresolvedRegionSet(ConstHandle2Background This, ConstHandle2ConstUnresolvedRegion unresolvedRegion);


// -----------------------------------------------------------------------------
// Child: fastRegion
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BackgroundFastRegionHas(ConstHandle2ConstBackground This);

// --- Get, const
extern_c Handle2ConstFastRegion
BackgroundFastRegionGetConst(ConstHandle2ConstBackground This);

// +++ Get, non-const
extern_c Handle2FastRegion
BackgroundFastRegionGet(ConstHandle2Background This);

// +++ Set
extern_c void
BackgroundFastRegionSet(ConstHandle2Background This, ConstHandle2ConstFastRegion fastRegion);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif