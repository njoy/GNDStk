
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
// Regions1d is the basic handle type in this file. Example:
//    // Create a default Regions1d object:
//    Regions1d handle = Regions1dDefault();
// Functions involving Regions1d are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_REGIONS1D
#define C_INTERFACE_GNDS_V2_0_GENERAL_REGIONS1D

#include "GNDStk.h"
#include "v2.0/general/Axes.h"
#include "v2.0/general/Uncertainty.h"
#include "v2.0/reduced/Function1ds.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct Regions1dClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Regions1d
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct Regions1dClass *Regions1d;

// --- Const-aware handles.
typedef const struct Regions1dClass *const ConstHandle2ConstRegions1d;
typedef       struct Regions1dClass *const ConstHandle2Regions1d;
typedef const struct Regions1dClass *      Handle2ConstRegions1d;
typedef       struct Regions1dClass *      Handle2Regions1d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstRegions1d
Regions1dDefaultConst();

// +++ Create, default, non-const
extern_c Handle2Regions1d
Regions1dDefault();

// --- Create, general, const
extern_c Handle2ConstRegions1d
Regions1dCreateConst(
   const char *const label,
   const double outerDomainValue,
   ConstHandle2ConstAxes axes,
   ConstHandle2ConstUncertainty uncertainty,
   ConstHandle2ConstFunction1ds function1ds
);

// +++ Create, general, non-const
extern_c Handle2Regions1d
Regions1dCreate(
   const char *const label,
   const double outerDomainValue,
   ConstHandle2ConstAxes axes,
   ConstHandle2ConstUncertainty uncertainty,
   ConstHandle2ConstFunction1ds function1ds
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
Regions1dAssign(ConstHandle2Regions1d self, ConstHandle2ConstRegions1d from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
Regions1dDelete(ConstHandle2ConstRegions1d self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
Regions1dRead(ConstHandle2Regions1d self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
Regions1dWrite(ConstHandle2ConstRegions1d self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
Regions1dPrint(ConstHandle2ConstRegions1d self);

// +++ Print to standard output, as XML
extern_c int
Regions1dPrintXML(ConstHandle2ConstRegions1d self);

// +++ Print to standard output, as JSON
extern_c int
Regions1dPrintJSON(ConstHandle2ConstRegions1d self);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Regions1dLabelHas(ConstHandle2ConstRegions1d self);

// +++ Get
// +++ Returns by value
extern_c const char *
Regions1dLabelGet(ConstHandle2ConstRegions1d self);

// +++ Set
extern_c void
Regions1dLabelSet(ConstHandle2Regions1d self, const char *const label);


// -----------------------------------------------------------------------------
// Metadatum: outerDomainValue
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Regions1dOuterDomainValueHas(ConstHandle2ConstRegions1d self);

// +++ Get
// +++ Returns by value
extern_c double
Regions1dOuterDomainValueGet(ConstHandle2ConstRegions1d self);

// +++ Set
extern_c void
Regions1dOuterDomainValueSet(ConstHandle2Regions1d self, const double outerDomainValue);


// -----------------------------------------------------------------------------
// Child: axes
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Regions1dAxesHas(ConstHandle2ConstRegions1d self);

// --- Get, const
extern_c Handle2ConstAxes
Regions1dAxesGetConst(ConstHandle2ConstRegions1d self);

// +++ Get, non-const
extern_c Handle2Axes
Regions1dAxesGet(ConstHandle2Regions1d self);

// +++ Set
extern_c void
Regions1dAxesSet(ConstHandle2Regions1d self, ConstHandle2ConstAxes axes);


// -----------------------------------------------------------------------------
// Child: uncertainty
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Regions1dUncertaintyHas(ConstHandle2ConstRegions1d self);

// --- Get, const
extern_c Handle2ConstUncertainty
Regions1dUncertaintyGetConst(ConstHandle2ConstRegions1d self);

// +++ Get, non-const
extern_c Handle2Uncertainty
Regions1dUncertaintyGet(ConstHandle2Regions1d self);

// +++ Set
extern_c void
Regions1dUncertaintySet(ConstHandle2Regions1d self, ConstHandle2ConstUncertainty uncertainty);


// -----------------------------------------------------------------------------
// Child: function1ds
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Regions1dFunction1dsHas(ConstHandle2ConstRegions1d self);

// --- Get, const
extern_c Handle2ConstFunction1ds
Regions1dFunction1dsGetConst(ConstHandle2ConstRegions1d self);

// +++ Get, non-const
extern_c Handle2Function1ds
Regions1dFunction1dsGet(ConstHandle2Regions1d self);

// +++ Set
extern_c void
Regions1dFunction1dsSet(ConstHandle2Regions1d self, ConstHandle2ConstFunction1ds function1ds);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Regions1d/src/custom.h"

#undef extern_c
#endif
