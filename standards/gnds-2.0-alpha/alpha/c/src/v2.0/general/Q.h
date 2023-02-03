
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
// Q is the basic handle type in this file. Example:
//    // Create a default Q object:
//    Q handle = QDefault();
// Functions involving Q are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_Q
#define C_INTERFACE_ALPHA_V2_0_GENERAL_Q

#include "GNDStk.h"
#include "v2.0/general/Double.h"
#include "v2.0/general/Constant1d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct QClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Q
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct QClass *Q;

// --- Const-aware handles.
typedef const struct QClass *const ConstHandle2ConstQ;
typedef       struct QClass *const ConstHandle2Q;
typedef const struct QClass *      Handle2ConstQ;
typedef       struct QClass *      Handle2Q;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstQ
QDefaultConst();

// +++ Create, default
extern_c Handle2Q
QDefault();

// --- Create, general, const
extern_c Handle2ConstQ
QCreateConst(
   ConstHandle2ConstDouble Double,
   ConstHandle2ConstConstant1d constant1d
);

// +++ Create, general
extern_c Handle2Q
QCreate(
   ConstHandle2ConstDouble Double,
   ConstHandle2ConstConstant1d constant1d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
QAssign(ConstHandle2Q This, ConstHandle2ConstQ from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
QDelete(ConstHandle2ConstQ This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
QRead(ConstHandle2Q This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
QWrite(ConstHandle2ConstQ This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
QPrint(ConstHandle2ConstQ This);

// +++ Print to standard output, as XML
extern_c int
QPrintXML(ConstHandle2ConstQ This);

// +++ Print to standard output, as JSON
extern_c int
QPrintJSON(ConstHandle2ConstQ This);


// -----------------------------------------------------------------------------
// Child: Double
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
QDoubleHas(ConstHandle2ConstQ This);

// --- Get, const
extern_c Handle2ConstDouble
QDoubleGetConst(ConstHandle2ConstQ This);

// +++ Get, non-const
extern_c Handle2Double
QDoubleGet(ConstHandle2Q This);

// +++ Set
extern_c void
QDoubleSet(ConstHandle2Q This, ConstHandle2ConstDouble Double);


// -----------------------------------------------------------------------------
// Child: constant1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
QConstant1dHas(ConstHandle2ConstQ This);

// --- Get, const
extern_c Handle2ConstConstant1d
QConstant1dGetConst(ConstHandle2ConstQ This);

// +++ Get, non-const
extern_c Handle2Constant1d
QConstant1dGet(ConstHandle2Q This);

// +++ Set
extern_c void
QConstant1dSet(ConstHandle2Q This, ConstHandle2ConstConstant1d constant1d);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Q/src/custom.h"

#undef extern_c
#endif
