
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
// Angular is the basic handle type in this file. Example:
//    // Create a default Angular object:
//    Angular handle = AngularDefault();
// Functions involving Angular are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_ANGULAR
#define C_INTERFACE_ALPHA_V2_0_GENERAL_ANGULAR

#include "GNDStk.h"
#include "v2.0/general/Isotropic2d.h"
#include "v2.0/general/XYs2d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct AngularClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Angular
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct AngularClass *Angular;

// --- Const-aware handles.
typedef const struct AngularClass *const ConstHandle2ConstAngular;
typedef       struct AngularClass *const ConstHandle2Angular;
typedef const struct AngularClass *      Handle2ConstAngular;
typedef       struct AngularClass *      Handle2Angular;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstAngular
AngularDefaultConst();

// +++ Create, default
extern_c Handle2Angular
AngularDefault();

// --- Create, general, const
extern_c Handle2ConstAngular
AngularCreateConst(
   ConstHandle2ConstIsotropic2d isotropic2d,
   ConstHandle2ConstXYs2d XYs2d
);

// +++ Create, general
extern_c Handle2Angular
AngularCreate(
   ConstHandle2ConstIsotropic2d isotropic2d,
   ConstHandle2ConstXYs2d XYs2d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
AngularAssign(ConstHandle2Angular This, ConstHandle2ConstAngular from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
AngularDelete(ConstHandle2ConstAngular This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
AngularRead(ConstHandle2Angular This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
AngularWrite(ConstHandle2ConstAngular This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
AngularPrint(ConstHandle2ConstAngular This);

// +++ Print to standard output, as XML
extern_c int
AngularPrintXML(ConstHandle2ConstAngular This);

// +++ Print to standard output, as JSON
extern_c int
AngularPrintJSON(ConstHandle2ConstAngular This);


// -----------------------------------------------------------------------------
// Child: isotropic2d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AngularIsotropic2dHas(ConstHandle2ConstAngular This);

// --- Get, const
extern_c Handle2ConstIsotropic2d
AngularIsotropic2dGetConst(ConstHandle2ConstAngular This);

// +++ Get, non-const
extern_c Handle2Isotropic2d
AngularIsotropic2dGet(ConstHandle2Angular This);

// +++ Set
extern_c void
AngularIsotropic2dSet(ConstHandle2Angular This, ConstHandle2ConstIsotropic2d isotropic2d);


// -----------------------------------------------------------------------------
// Child: XYs2d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AngularXYs2dHas(ConstHandle2ConstAngular This);

// --- Get, const
extern_c Handle2ConstXYs2d
AngularXYs2dGetConst(ConstHandle2ConstAngular This);

// +++ Get, non-const
extern_c Handle2XYs2d
AngularXYs2dGet(ConstHandle2Angular This);

// +++ Set
extern_c void
AngularXYs2dSet(ConstHandle2Angular This, ConstHandle2ConstXYs2d XYs2d);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Angular/src/custom.h"

#undef extern_c
#endif
