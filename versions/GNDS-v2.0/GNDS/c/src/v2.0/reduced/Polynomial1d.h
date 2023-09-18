
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
// Polynomial1d is the basic handle type in this file. Example:
//    // Create a default Polynomial1d object:
//    Polynomial1d handle = Polynomial1dDefault();
// Functions involving Polynomial1d are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_REDUCED_POLYNOMIAL1D
#define C_INTERFACE_GNDS_V2_0_REDUCED_POLYNOMIAL1D

#include "GNDStk.h"
#include "v2.0/general/Axes.h"
#include "v2.0/general/Values.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct Polynomial1dClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Polynomial1d
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct Polynomial1dClass *Polynomial1d;

// --- Const-aware handles.
typedef const struct Polynomial1dClass *const ConstHandle2ConstPolynomial1d;
typedef       struct Polynomial1dClass *const ConstHandle2Polynomial1d;
typedef const struct Polynomial1dClass *      Handle2ConstPolynomial1d;
typedef       struct Polynomial1dClass *      Handle2Polynomial1d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstPolynomial1d
Polynomial1dDefaultConst();

// +++ Create, default
extern_c Handle2Polynomial1d
Polynomial1dDefault();

// --- Create, general, const
extern_c Handle2ConstPolynomial1d
Polynomial1dCreateConst(
   const double domainMin,
   const double domainMax,
   ConstHandle2ConstAxes axes,
   ConstHandle2ConstValues values
);

// +++ Create, general
extern_c Handle2Polynomial1d
Polynomial1dCreate(
   const double domainMin,
   const double domainMax,
   ConstHandle2ConstAxes axes,
   ConstHandle2ConstValues values
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
Polynomial1dAssign(ConstHandle2Polynomial1d self, ConstHandle2ConstPolynomial1d from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
Polynomial1dDelete(ConstHandle2ConstPolynomial1d self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
Polynomial1dRead(ConstHandle2Polynomial1d self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
Polynomial1dWrite(ConstHandle2ConstPolynomial1d self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
Polynomial1dPrint(ConstHandle2ConstPolynomial1d self);

// +++ Print to standard output, as XML
extern_c int
Polynomial1dPrintXML(ConstHandle2ConstPolynomial1d self);

// +++ Print to standard output, as JSON
extern_c int
Polynomial1dPrintJSON(ConstHandle2ConstPolynomial1d self);


// -----------------------------------------------------------------------------
// Metadatum: domainMin
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Polynomial1dDomainMinHas(ConstHandle2ConstPolynomial1d self);

// +++ Get
// +++ Returns by value
extern_c double
Polynomial1dDomainMinGet(ConstHandle2ConstPolynomial1d self);

// +++ Set
extern_c void
Polynomial1dDomainMinSet(ConstHandle2Polynomial1d self, const double domainMin);


// -----------------------------------------------------------------------------
// Metadatum: domainMax
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Polynomial1dDomainMaxHas(ConstHandle2ConstPolynomial1d self);

// +++ Get
// +++ Returns by value
extern_c double
Polynomial1dDomainMaxGet(ConstHandle2ConstPolynomial1d self);

// +++ Set
extern_c void
Polynomial1dDomainMaxSet(ConstHandle2Polynomial1d self, const double domainMax);


// -----------------------------------------------------------------------------
// Child: axes
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Polynomial1dAxesHas(ConstHandle2ConstPolynomial1d self);

// --- Get, const
extern_c Handle2ConstAxes
Polynomial1dAxesGetConst(ConstHandle2ConstPolynomial1d self);

// +++ Get
extern_c Handle2Axes
Polynomial1dAxesGet(ConstHandle2Polynomial1d self);

// +++ Set
extern_c void
Polynomial1dAxesSet(ConstHandle2Polynomial1d self, ConstHandle2ConstAxes axes);


// -----------------------------------------------------------------------------
// Child: values
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Polynomial1dValuesHas(ConstHandle2ConstPolynomial1d self);

// --- Get, const
extern_c Handle2ConstValues
Polynomial1dValuesGetConst(ConstHandle2ConstPolynomial1d self);

// +++ Get
extern_c Handle2Values
Polynomial1dValuesGet(ConstHandle2Polynomial1d self);

// +++ Set
extern_c void
Polynomial1dValuesSet(ConstHandle2Polynomial1d self, ConstHandle2ConstValues values);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/reduced/Polynomial1d/src/custom.h"

#undef extern_c
#endif
