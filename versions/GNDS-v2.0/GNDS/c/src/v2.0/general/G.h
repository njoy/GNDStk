
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
// G is the basic handle type in this file. Example:
//    // Create a default G object:
//    G handle = GDefault();
// Functions involving G are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_G
#define C_INTERFACE_GNDS_V2_0_GENERAL_G

#include "GNDStk.h"
#include "v2.0/general/XYs1d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct GClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ G
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct GClass *G;

// --- Const-aware handles.
typedef const struct GClass *const ConstHandle2ConstG;
typedef       struct GClass *const ConstHandle2G;
typedef const struct GClass *      Handle2ConstG;
typedef       struct GClass *      Handle2G;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstG
GDefaultConst();

// +++ Create, default, non-const
extern_c Handle2G
GDefault();

// --- Create, general, const
extern_c Handle2ConstG
GCreateConst(
   ConstHandle2ConstXYs1d XYs1d
);

// +++ Create, general, non-const
extern_c Handle2G
GCreate(
   ConstHandle2ConstXYs1d XYs1d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
GAssign(ConstHandle2G self, ConstHandle2ConstG from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
GDelete(ConstHandle2ConstG self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
GRead(ConstHandle2G self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
GWrite(ConstHandle2ConstG self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
GPrint(ConstHandle2ConstG self);

// +++ Print to standard output, as XML
extern_c int
GPrintXML(ConstHandle2ConstG self);

// +++ Print to standard output, as JSON
extern_c int
GPrintJSON(ConstHandle2ConstG self);


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
GXYs1dHas(ConstHandle2ConstG self);

// --- Get, const
extern_c Handle2ConstXYs1d
GXYs1dGetConst(ConstHandle2ConstG self);

// +++ Get, non-const
extern_c Handle2XYs1d
GXYs1dGet(ConstHandle2G self);

// +++ Set
extern_c void
GXYs1dSet(ConstHandle2G self, ConstHandle2ConstXYs1d XYs1d);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/G/src/custom.h"

#undef extern_c
#endif