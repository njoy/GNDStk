
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
// Continuum is the basic handle type in this file. Example:
//    // Create a default Continuum object:
//    Continuum handle = ContinuumDefault();
// Functions involving Continuum are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_CONTINUUM
#define C_INTERFACE_ALPHA_V2_0_GENERAL_CONTINUUM

#include "GNDStk.h"
#include "v2.0/general/XYs1d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ContinuumClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Continuum
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ContinuumClass *Continuum;

// --- Const-aware handles.
typedef const struct ContinuumClass *const ConstHandle2ConstContinuum;
typedef       struct ContinuumClass *const ConstHandle2Continuum;
typedef const struct ContinuumClass *      Handle2ConstContinuum;
typedef       struct ContinuumClass *      Handle2Continuum;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstContinuum
ContinuumDefaultConst();

// +++ Create, default
extern_c Handle2Continuum
ContinuumDefault();

// --- Create, general, const
extern_c Handle2ConstContinuum
ContinuumCreateConst(
   ConstHandle2ConstXYs1d XYs1d
);

// +++ Create, general
extern_c Handle2Continuum
ContinuumCreate(
   ConstHandle2ConstXYs1d XYs1d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ContinuumAssign(ConstHandle2Continuum This, ConstHandle2ConstContinuum from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ContinuumDelete(ConstHandle2ConstContinuum This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ContinuumRead(ConstHandle2Continuum This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ContinuumWrite(ConstHandle2ConstContinuum This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ContinuumPrint(ConstHandle2ConstContinuum This);

// +++ Print to standard output, as XML
extern_c int
ContinuumPrintXML(ConstHandle2ConstContinuum This);

// +++ Print to standard output, as JSON
extern_c int
ContinuumPrintJSON(ConstHandle2ConstContinuum This);


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ContinuumXYs1dHas(ConstHandle2ConstContinuum This);

// --- Get, const
extern_c Handle2ConstXYs1d
ContinuumXYs1dGetConst(ConstHandle2ConstContinuum This);

// +++ Get, non-const
extern_c Handle2XYs1d
ContinuumXYs1dGet(ConstHandle2Continuum This);

// +++ Set
extern_c void
ContinuumXYs1dSet(ConstHandle2Continuum This, ConstHandle2ConstXYs1d XYs1d);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Continuum/src/custom.h"

#undef extern_c
#endif
