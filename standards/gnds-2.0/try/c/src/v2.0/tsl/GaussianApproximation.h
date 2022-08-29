
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
// GaussianApproximation is the basic handle type in this file. Example:
//    // Create a default GaussianApproximation object:
//    GaussianApproximation handle = GaussianApproximationDefault();
// Functions involving GaussianApproximation are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_TSL_GAUSSIANAPPROXIMATION
#define C_INTERFACE_TRY_V2_0_TSL_GAUSSIANAPPROXIMATION

#include "GNDStk.h"
#include "v2.0/tsl/PhononSpectrum.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct GaussianApproximationClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ GaussianApproximation
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct GaussianApproximationClass *GaussianApproximation;

// --- Const-aware handles.
typedef const struct GaussianApproximationClass *const ConstHandle2ConstGaussianApproximation;
typedef       struct GaussianApproximationClass *const ConstHandle2GaussianApproximation;
typedef const struct GaussianApproximationClass *      Handle2ConstGaussianApproximation;
typedef       struct GaussianApproximationClass *      Handle2GaussianApproximation;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstGaussianApproximation
GaussianApproximationDefaultConst();

// +++ Create, default
extern_c Handle2GaussianApproximation
GaussianApproximationDefault();

// --- Create, general, const
extern_c Handle2ConstGaussianApproximation
GaussianApproximationCreateConst(
   ConstHandle2ConstPhononSpectrum phononSpectrum
);

// +++ Create, general
extern_c Handle2GaussianApproximation
GaussianApproximationCreate(
   ConstHandle2ConstPhononSpectrum phononSpectrum
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
GaussianApproximationAssign(ConstHandle2GaussianApproximation This, ConstHandle2ConstGaussianApproximation from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
GaussianApproximationDelete(ConstHandle2ConstGaussianApproximation This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
GaussianApproximationRead(ConstHandle2GaussianApproximation This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
GaussianApproximationWrite(ConstHandle2ConstGaussianApproximation This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
GaussianApproximationPrint(ConstHandle2ConstGaussianApproximation This);

// +++ Print to standard output, as XML
extern_c int
GaussianApproximationPrintXML(ConstHandle2ConstGaussianApproximation This);

// +++ Print to standard output, as JSON
extern_c int
GaussianApproximationPrintJSON(ConstHandle2ConstGaussianApproximation This);


// -----------------------------------------------------------------------------
// Child: phononSpectrum
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
GaussianApproximationPhononSpectrumHas(ConstHandle2ConstGaussianApproximation This);

// --- Get, const
extern_c Handle2ConstPhononSpectrum
GaussianApproximationPhononSpectrumGetConst(ConstHandle2ConstGaussianApproximation This);

// +++ Get, non-const
extern_c Handle2PhononSpectrum
GaussianApproximationPhononSpectrumGet(ConstHandle2GaussianApproximation This);

// +++ Set
extern_c void
GaussianApproximationPhononSpectrumSet(ConstHandle2GaussianApproximation This, ConstHandle2ConstPhononSpectrum phononSpectrum);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
