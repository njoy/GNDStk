
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
// F is the basic handle type in this file. Example:
//    // Create a default F object:
//    F handle = FDefault();
// Functions involving F are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_MEAN_F
#define C_INTERFACE_ALPHA_V2_0_MEAN_F

#include "GNDStk.h"
#include "v2.0/mean/XYs2d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct FClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ F
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct FClass *F;

// --- Const-aware handles.
typedef const struct FClass *const ConstHandle2ConstF;
typedef       struct FClass *const ConstHandle2F;
typedef const struct FClass *      Handle2ConstF;
typedef       struct FClass *      Handle2F;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstF
FDefaultConst();

// +++ Create, default
extern_c Handle2F
FDefault();

// --- Create, general, const
extern_c Handle2ConstF
FCreateConst(
   ConstHandle2ConstXYs2d XYs2d
);

// +++ Create, general
extern_c Handle2F
FCreate(
   ConstHandle2ConstXYs2d XYs2d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
FAssign(ConstHandle2F This, ConstHandle2ConstF from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
FDelete(ConstHandle2ConstF This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
FRead(ConstHandle2F This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
FWrite(ConstHandle2ConstF This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
FPrint(ConstHandle2ConstF This);

// +++ Print to standard output, as XML
extern_c int
FPrintXML(ConstHandle2ConstF This);

// +++ Print to standard output, as JSON
extern_c int
FPrintJSON(ConstHandle2ConstF This);


// -----------------------------------------------------------------------------
// Child: XYs2d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
FXYs2dHas(ConstHandle2ConstF This);

// --- Get, const
extern_c Handle2ConstXYs2d
FXYs2dGetConst(ConstHandle2ConstF This);

// +++ Get, non-const
extern_c Handle2XYs2d
FXYs2dGet(ConstHandle2F This);

// +++ Set
extern_c void
FXYs2dSet(ConstHandle2F This, ConstHandle2ConstXYs2d XYs2d);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/mean/F/src/custom.h"

#undef extern_c
#endif
