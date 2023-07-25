
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
// Constant1d is the basic handle type in this file. Example:
//    // Create a default Constant1d object:
//    Constant1d handle = Constant1dDefault();
// Functions involving Constant1d are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_CONSTANT1D
#define C_INTERFACE_GNDS_V2_0_GENERAL_CONSTANT1D

#include "GNDStk.h"
#include "v2.0/general/Axes.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct Constant1dClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Constant1d
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct Constant1dClass *Constant1d;

// --- Const-aware handles.
typedef const struct Constant1dClass *const ConstHandle2ConstConstant1d;
typedef       struct Constant1dClass *const ConstHandle2Constant1d;
typedef const struct Constant1dClass *      Handle2ConstConstant1d;
typedef       struct Constant1dClass *      Handle2Constant1d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstConstant1d
Constant1dDefaultConst();

// +++ Create, default
extern_c Handle2Constant1d
Constant1dDefault();

// --- Create, general, const
extern_c Handle2ConstConstant1d
Constant1dCreateConst(
   const char *const label,
   const double value,
   const double domainMin,
   const double domainMax,
   ConstHandle2ConstAxes axes
);

// +++ Create, general
extern_c Handle2Constant1d
Constant1dCreate(
   const char *const label,
   const double value,
   const double domainMin,
   const double domainMax,
   ConstHandle2ConstAxes axes
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
Constant1dAssign(ConstHandle2Constant1d self, ConstHandle2ConstConstant1d from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
Constant1dDelete(ConstHandle2ConstConstant1d self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
Constant1dRead(ConstHandle2Constant1d self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
Constant1dWrite(ConstHandle2ConstConstant1d self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
Constant1dPrint(ConstHandle2ConstConstant1d self);

// +++ Print to standard output, as XML
extern_c int
Constant1dPrintXML(ConstHandle2ConstConstant1d self);

// +++ Print to standard output, as JSON
extern_c int
Constant1dPrintJSON(ConstHandle2ConstConstant1d self);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Constant1dLabelHas(ConstHandle2ConstConstant1d self);

// +++ Get
// +++ Returns by value
extern_c const char *
Constant1dLabelGet(ConstHandle2ConstConstant1d self);

// +++ Set
extern_c void
Constant1dLabelSet(ConstHandle2Constant1d self, const char *const label);


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Constant1dValueHas(ConstHandle2ConstConstant1d self);

// +++ Get
// +++ Returns by value
extern_c double
Constant1dValueGet(ConstHandle2ConstConstant1d self);

// +++ Set
extern_c void
Constant1dValueSet(ConstHandle2Constant1d self, const double value);


// -----------------------------------------------------------------------------
// Metadatum: domainMin
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Constant1dDomainMinHas(ConstHandle2ConstConstant1d self);

// +++ Get
// +++ Returns by value
extern_c double
Constant1dDomainMinGet(ConstHandle2ConstConstant1d self);

// +++ Set
extern_c void
Constant1dDomainMinSet(ConstHandle2Constant1d self, const double domainMin);


// -----------------------------------------------------------------------------
// Metadatum: domainMax
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Constant1dDomainMaxHas(ConstHandle2ConstConstant1d self);

// +++ Get
// +++ Returns by value
extern_c double
Constant1dDomainMaxGet(ConstHandle2ConstConstant1d self);

// +++ Set
extern_c void
Constant1dDomainMaxSet(ConstHandle2Constant1d self, const double domainMax);


// -----------------------------------------------------------------------------
// Child: axes
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Constant1dAxesHas(ConstHandle2ConstConstant1d self);

// --- Get, const
extern_c Handle2ConstAxes
Constant1dAxesGetConst(ConstHandle2ConstConstant1d self);

// +++ Get, non-const
extern_c Handle2Axes
Constant1dAxesGet(ConstHandle2Constant1d self);

// +++ Set
extern_c void
Constant1dAxesSet(ConstHandle2Constant1d self, ConstHandle2ConstAxes axes);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Constant1d/src/custom.h"

#undef extern_c
#endif
