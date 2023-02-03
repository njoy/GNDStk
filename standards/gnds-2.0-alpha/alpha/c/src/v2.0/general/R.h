
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
// R is the basic handle type in this file. Example:
//    // Create a default R object:
//    R handle = RDefault();
// Functions involving R are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_R
#define C_INTERFACE_ALPHA_V2_0_GENERAL_R

#include "GNDStk.h"
#include "v2.0/general/XYs2d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct RClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ R
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct RClass *R;

// --- Const-aware handles.
typedef const struct RClass *const ConstHandle2ConstR;
typedef       struct RClass *const ConstHandle2R;
typedef const struct RClass *      Handle2ConstR;
typedef       struct RClass *      Handle2R;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstR
RDefaultConst();

// +++ Create, default
extern_c Handle2R
RDefault();

// --- Create, general, const
extern_c Handle2ConstR
RCreateConst(
   ConstHandle2ConstXYs2d XYs2d
);

// +++ Create, general
extern_c Handle2R
RCreate(
   ConstHandle2ConstXYs2d XYs2d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
RAssign(ConstHandle2R This, ConstHandle2ConstR from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
RDelete(ConstHandle2ConstR This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
RRead(ConstHandle2R This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
RWrite(ConstHandle2ConstR This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
RPrint(ConstHandle2ConstR This);

// +++ Print to standard output, as XML
extern_c int
RPrintXML(ConstHandle2ConstR This);

// +++ Print to standard output, as JSON
extern_c int
RPrintJSON(ConstHandle2ConstR This);


// -----------------------------------------------------------------------------
// Child: XYs2d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
RXYs2dHas(ConstHandle2ConstR This);

// --- Get, const
extern_c Handle2ConstXYs2d
RXYs2dGetConst(ConstHandle2ConstR This);

// +++ Get, non-const
extern_c Handle2XYs2d
RXYs2dGet(ConstHandle2R This);

// +++ Set
extern_c void
RXYs2dSet(ConstHandle2R This, ConstHandle2ConstXYs2d XYs2d);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/R/src/custom.h"

#undef extern_c
#endif
