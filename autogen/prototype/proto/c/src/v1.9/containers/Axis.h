
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
// Axis is the basic handle type in this file. Example:
//    // Create a default Axis object:
//    Axis handle = AxisDefault();
// Functions involving Axis are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_PROTO_V1_9_CONTAINERS_AXIS
#define C_INTERFACE_PROTO_V1_9_CONTAINERS_AXIS

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct AxisClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Axis
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct AxisClass *Axis;

// --- Const-aware handles.
typedef const struct AxisClass *const ConstHandle2ConstAxis;
typedef       struct AxisClass *const ConstHandle2Axis;
typedef const struct AxisClass *      Handle2ConstAxis;
typedef       struct AxisClass *      Handle2Axis;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstAxis
AxisDefaultConst();

// +++ Create, default
extern_c Handle2Axis
AxisDefault();

// --- Create, general, const
extern_c Handle2ConstAxis
AxisCreateConst(
   const int index,
   const char *const label,
   const char *const unit
);

// +++ Create, general
extern_c Handle2Axis
AxisCreate(
   const int index,
   const char *const label,
   const char *const unit
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
AxisAssign(ConstHandle2Axis This, ConstHandle2ConstAxis from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
AxisDelete(ConstHandle2ConstAxis This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
AxisRead(ConstHandle2Axis This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
AxisWrite(ConstHandle2ConstAxis This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
AxisPrint(ConstHandle2ConstAxis This);

// +++ Print to standard output, as XML
extern_c int
AxisPrintXML(ConstHandle2ConstAxis This);

// +++ Print to standard output, as JSON
extern_c int
AxisPrintJSON(ConstHandle2ConstAxis This);


// -----------------------------------------------------------------------------
// Metadatum: index
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AxisIndexHas(ConstHandle2ConstAxis This);

// +++ Get
// +++ Returns by value
extern_c int
AxisIndexGet(ConstHandle2ConstAxis This);

// +++ Set
extern_c void
AxisIndexSet(ConstHandle2Axis This, const int index);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AxisLabelHas(ConstHandle2ConstAxis This);

// +++ Get
// +++ Returns by value
extern_c const char *
AxisLabelGet(ConstHandle2ConstAxis This);

// +++ Set
extern_c void
AxisLabelSet(ConstHandle2Axis This, const char *const label);


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AxisUnitHas(ConstHandle2ConstAxis This);

// +++ Get
// +++ Returns by value
extern_c const char *
AxisUnitGet(ConstHandle2ConstAxis This);

// +++ Set
extern_c void
AxisUnitSet(ConstHandle2Axis This, const char *const unit);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
