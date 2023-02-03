
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
// DelayedNeutronKE is the basic handle type in this file. Example:
//    // Create a default DelayedNeutronKE object:
//    DelayedNeutronKE handle = DelayedNeutronKEDefault();
// Functions involving DelayedNeutronKE are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_DELAYEDNEUTRONKE
#define C_INTERFACE_ALPHA_V2_0_GENERAL_DELAYEDNEUTRONKE

#include "GNDStk.h"
#include "v2.0/general/Polynomial1d.h"
#include "v2.0/general/XYs1d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct DelayedNeutronKEClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ DelayedNeutronKE
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct DelayedNeutronKEClass *DelayedNeutronKE;

// --- Const-aware handles.
typedef const struct DelayedNeutronKEClass *const ConstHandle2ConstDelayedNeutronKE;
typedef       struct DelayedNeutronKEClass *const ConstHandle2DelayedNeutronKE;
typedef const struct DelayedNeutronKEClass *      Handle2ConstDelayedNeutronKE;
typedef       struct DelayedNeutronKEClass *      Handle2DelayedNeutronKE;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstDelayedNeutronKE
DelayedNeutronKEDefaultConst();

// +++ Create, default
extern_c Handle2DelayedNeutronKE
DelayedNeutronKEDefault();

// --- Create, general, const
extern_c Handle2ConstDelayedNeutronKE
DelayedNeutronKECreateConst(
   ConstHandle2ConstPolynomial1d polynomial1d,
   ConstHandle2ConstXYs1d XYs1d
);

// +++ Create, general
extern_c Handle2DelayedNeutronKE
DelayedNeutronKECreate(
   ConstHandle2ConstPolynomial1d polynomial1d,
   ConstHandle2ConstXYs1d XYs1d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
DelayedNeutronKEAssign(ConstHandle2DelayedNeutronKE This, ConstHandle2ConstDelayedNeutronKE from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
DelayedNeutronKEDelete(ConstHandle2ConstDelayedNeutronKE This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
DelayedNeutronKERead(ConstHandle2DelayedNeutronKE This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
DelayedNeutronKEWrite(ConstHandle2ConstDelayedNeutronKE This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
DelayedNeutronKEPrint(ConstHandle2ConstDelayedNeutronKE This);

// +++ Print to standard output, as XML
extern_c int
DelayedNeutronKEPrintXML(ConstHandle2ConstDelayedNeutronKE This);

// +++ Print to standard output, as JSON
extern_c int
DelayedNeutronKEPrintJSON(ConstHandle2ConstDelayedNeutronKE This);


// -----------------------------------------------------------------------------
// Child: polynomial1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DelayedNeutronKEPolynomial1dHas(ConstHandle2ConstDelayedNeutronKE This);

// --- Get, const
extern_c Handle2ConstPolynomial1d
DelayedNeutronKEPolynomial1dGetConst(ConstHandle2ConstDelayedNeutronKE This);

// +++ Get, non-const
extern_c Handle2Polynomial1d
DelayedNeutronKEPolynomial1dGet(ConstHandle2DelayedNeutronKE This);

// +++ Set
extern_c void
DelayedNeutronKEPolynomial1dSet(ConstHandle2DelayedNeutronKE This, ConstHandle2ConstPolynomial1d polynomial1d);


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DelayedNeutronKEXYs1dHas(ConstHandle2ConstDelayedNeutronKE This);

// --- Get, const
extern_c Handle2ConstXYs1d
DelayedNeutronKEXYs1dGetConst(ConstHandle2ConstDelayedNeutronKE This);

// +++ Get, non-const
extern_c Handle2XYs1d
DelayedNeutronKEXYs1dGet(ConstHandle2DelayedNeutronKE This);

// +++ Set
extern_c void
DelayedNeutronKEXYs1dSet(ConstHandle2DelayedNeutronKE This, ConstHandle2ConstXYs1d XYs1d);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/DelayedNeutronKE/src/custom.h"

#undef extern_c
#endif
