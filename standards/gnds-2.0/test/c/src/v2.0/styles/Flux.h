
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
// Flux is the basic handle type in this file. Example:
//    // Create a default Flux object:
//    Flux handle = FluxDefault();
// Functions involving Flux are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_STYLES_FLUX
#define C_INTERFACE_TEST_V2_0_STYLES_FLUX

#include "GNDStk.h"
#include "v2.0/containers/XYs2d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct FluxClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Flux
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct FluxClass *Flux;

// --- Const-aware handles.
typedef const struct FluxClass *const ConstHandle2ConstFlux;
typedef       struct FluxClass *const ConstHandle2Flux;
typedef const struct FluxClass *      Handle2ConstFlux;
typedef       struct FluxClass *      Handle2Flux;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstFlux
FluxDefaultConst();

// +++ Create, default
extern_c Handle2Flux
FluxDefault();

// --- Create, general, const
extern_c Handle2ConstFlux
FluxCreateConst(
   const XMLName label,
   ConstHandle2ConstXYs2d XYs2d
);

// +++ Create, general
extern_c Handle2Flux
FluxCreate(
   const XMLName label,
   ConstHandle2ConstXYs2d XYs2d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
FluxAssign(ConstHandle2Flux This, ConstHandle2ConstFlux from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
FluxDelete(ConstHandle2ConstFlux This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
FluxRead(ConstHandle2Flux This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
FluxWrite(ConstHandle2ConstFlux This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
FluxPrint(ConstHandle2ConstFlux This);

// +++ Print to standard output, as XML
extern_c int
FluxPrintXML(ConstHandle2ConstFlux This);

// +++ Print to standard output, as JSON
extern_c int
FluxPrintJSON(ConstHandle2ConstFlux This);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
FluxLabelHas(ConstHandle2ConstFlux This);

// +++ Get
// +++ Returns by value
extern_c XMLName
FluxLabelGet(ConstHandle2ConstFlux This);

// +++ Set
extern_c void
FluxLabelSet(ConstHandle2Flux This, const XMLName label);


// -----------------------------------------------------------------------------
// Child: XYs2d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
FluxXYs2dHas(ConstHandle2ConstFlux This);

// --- Get, const
extern_c Handle2ConstXYs2d
FluxXYs2dGetConst(ConstHandle2ConstFlux This);

// +++ Get, non-const
extern_c Handle2XYs2d
FluxXYs2dGet(ConstHandle2Flux This);

// +++ Set
extern_c void
FluxXYs2dSet(ConstHandle2Flux This, ConstHandle2ConstXYs2d XYs2d);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
