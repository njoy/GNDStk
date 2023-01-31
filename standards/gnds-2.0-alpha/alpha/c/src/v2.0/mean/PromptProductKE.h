
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
// PromptProductKE is the basic handle type in this file. Example:
//    // Create a default PromptProductKE object:
//    PromptProductKE handle = PromptProductKEDefault();
// Functions involving PromptProductKE are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_MEAN_PROMPTPRODUCTKE
#define C_INTERFACE_ALPHA_V2_0_MEAN_PROMPTPRODUCTKE

#include "GNDStk.h"
#include "v2.0/common/Polynomial1d.h"
#include "v2.0/common/XYs1d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct PromptProductKEClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ PromptProductKE
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct PromptProductKEClass *PromptProductKE;

// --- Const-aware handles.
typedef const struct PromptProductKEClass *const ConstHandle2ConstPromptProductKE;
typedef       struct PromptProductKEClass *const ConstHandle2PromptProductKE;
typedef const struct PromptProductKEClass *      Handle2ConstPromptProductKE;
typedef       struct PromptProductKEClass *      Handle2PromptProductKE;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstPromptProductKE
PromptProductKEDefaultConst();

// +++ Create, default
extern_c Handle2PromptProductKE
PromptProductKEDefault();

// --- Create, general, const
extern_c Handle2ConstPromptProductKE
PromptProductKECreateConst(
   ConstHandle2ConstPolynomial1d polynomial1d,
   ConstHandle2ConstXYs1d XYs1d
);

// +++ Create, general
extern_c Handle2PromptProductKE
PromptProductKECreate(
   ConstHandle2ConstPolynomial1d polynomial1d,
   ConstHandle2ConstXYs1d XYs1d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
PromptProductKEAssign(ConstHandle2PromptProductKE This, ConstHandle2ConstPromptProductKE from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
PromptProductKEDelete(ConstHandle2ConstPromptProductKE This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
PromptProductKERead(ConstHandle2PromptProductKE This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
PromptProductKEWrite(ConstHandle2ConstPromptProductKE This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
PromptProductKEPrint(ConstHandle2ConstPromptProductKE This);

// +++ Print to standard output, as XML
extern_c int
PromptProductKEPrintXML(ConstHandle2ConstPromptProductKE This);

// +++ Print to standard output, as JSON
extern_c int
PromptProductKEPrintJSON(ConstHandle2ConstPromptProductKE This);


// -----------------------------------------------------------------------------
// Child: polynomial1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
PromptProductKEPolynomial1dHas(ConstHandle2ConstPromptProductKE This);

// --- Get, const
extern_c Handle2ConstPolynomial1d
PromptProductKEPolynomial1dGetConst(ConstHandle2ConstPromptProductKE This);

// +++ Get, non-const
extern_c Handle2Polynomial1d
PromptProductKEPolynomial1dGet(ConstHandle2PromptProductKE This);

// +++ Set
extern_c void
PromptProductKEPolynomial1dSet(ConstHandle2PromptProductKE This, ConstHandle2ConstPolynomial1d polynomial1d);


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
PromptProductKEXYs1dHas(ConstHandle2ConstPromptProductKE This);

// --- Get, const
extern_c Handle2ConstXYs1d
PromptProductKEXYs1dGetConst(ConstHandle2ConstPromptProductKE This);

// +++ Get, non-const
extern_c Handle2XYs1d
PromptProductKEXYs1dGet(ConstHandle2PromptProductKE This);

// +++ Set
extern_c void
PromptProductKEXYs1dSet(ConstHandle2PromptProductKE This, ConstHandle2ConstXYs1d XYs1d);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/mean/PromptProductKE/src/custom.h"

#undef extern_c
#endif
