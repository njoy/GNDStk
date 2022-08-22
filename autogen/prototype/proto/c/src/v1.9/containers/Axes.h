
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
// Axes is the basic handle type in this file. Example:
//    // Create a default Axes object:
//    Axes handle = AxesDefault();
// Functions involving Axes are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_PROTO_V1_9_CONTAINERS_AXES
#define C_INTERFACE_PROTO_V1_9_CONTAINERS_AXES

#include "GNDStk.h"
#include "v1.9/containers/Axis.h"
#include "v1.9/containers/Grid.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct AxesClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Axes
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct AxesClass *Axes;

// --- Const-aware handles.
typedef const struct AxesClass *const ConstHandle2ConstAxes;
typedef       struct AxesClass *const ConstHandle2Axes;
typedef const struct AxesClass *      Handle2ConstAxes;
typedef       struct AxesClass *      Handle2Axes;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstAxes
AxesDefaultConst();

// +++ Create, default
extern_c Handle2Axes
AxesDefault();

// --- Create, general, const
extern_c Handle2ConstAxes
AxesCreateConst(
   const char *const href,
);

// +++ Create, general
extern_c Handle2Axes
AxesCreate(
   const char *const href,
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
AxesAssign(ConstHandle2Axes This, ConstHandle2ConstAxes from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
AxesDelete(ConstHandle2ConstAxes This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
AxesRead(ConstHandle2Axes This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
AxesWrite(ConstHandle2ConstAxes This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
AxesPrint(ConstHandle2ConstAxes This);

// +++ Print to standard output, as XML
extern_c int
AxesPrintXML(ConstHandle2ConstAxes This);

// +++ Print to standard output, as JSON
extern_c int
AxesPrintJSON(ConstHandle2ConstAxes This);


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AxesHrefHas(ConstHandle2ConstAxes This);

// +++ Get
// +++ Returns by value
extern_c const char *
AxesHrefGet(ConstHandle2ConstAxes This);

// +++ Set
extern_c void
AxesHrefSet(ConstHandle2Axes This, const char *const href);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
