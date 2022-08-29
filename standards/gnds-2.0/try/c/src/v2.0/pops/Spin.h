
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
// Spin is the basic handle type in this file. Example:
//    // Create a default Spin object:
//    Spin handle = SpinDefault();
// Functions involving Spin are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_POPS_SPIN
#define C_INTERFACE_TRY_V2_0_POPS_SPIN

#include "GNDStk.h"
#include "v2.0/documentation/Documentation.h"
#include "v2.0/pops/Uncertainty.h"
#include "v2.0/unknownNamespace/Fraction.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct SpinClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Spin
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct SpinClass *Spin;

// --- Const-aware handles.
typedef const struct SpinClass *const ConstHandle2ConstSpin;
typedef       struct SpinClass *const ConstHandle2Spin;
typedef const struct SpinClass *      Handle2ConstSpin;
typedef       struct SpinClass *      Handle2Spin;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstSpin
SpinDefaultConst();

// +++ Create, default
extern_c Handle2Spin
SpinDefault();

// --- Create, general, const
extern_c Handle2ConstSpin
SpinCreateConst(
   const XMLName label,
   const XMLName unit,
   const XMLName value,
   ConstHandle2ConstDocumentation documentation,
   ConstHandle2ConstUncertainty uncertainty,
   ConstHandle2Fraction *const fraction, const size_t fractionSize
);

// +++ Create, general
extern_c Handle2Spin
SpinCreate(
   const XMLName label,
   const XMLName unit,
   const XMLName value,
   ConstHandle2ConstDocumentation documentation,
   ConstHandle2ConstUncertainty uncertainty,
   ConstHandle2Fraction *const fraction, const size_t fractionSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
SpinAssign(ConstHandle2Spin This, ConstHandle2ConstSpin from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
SpinDelete(ConstHandle2ConstSpin This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
SpinRead(ConstHandle2Spin This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
SpinWrite(ConstHandle2ConstSpin This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
SpinPrint(ConstHandle2ConstSpin This);

// +++ Print to standard output, as XML
extern_c int
SpinPrintXML(ConstHandle2ConstSpin This);

// +++ Print to standard output, as JSON
extern_c int
SpinPrintJSON(ConstHandle2ConstSpin This);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
SpinLabelHas(ConstHandle2ConstSpin This);

// +++ Get
// +++ Returns by value
extern_c XMLName
SpinLabelGet(ConstHandle2ConstSpin This);

// +++ Set
extern_c void
SpinLabelSet(ConstHandle2Spin This, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
SpinUnitHas(ConstHandle2ConstSpin This);

// +++ Get
// +++ Returns by value
extern_c XMLName
SpinUnitGet(ConstHandle2ConstSpin This);

// +++ Set
extern_c void
SpinUnitSet(ConstHandle2Spin This, const XMLName unit);


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
SpinValueHas(ConstHandle2ConstSpin This);

// +++ Get
// +++ Returns by value
extern_c XMLName
SpinValueGet(ConstHandle2ConstSpin This);

// +++ Set
extern_c void
SpinValueSet(ConstHandle2Spin This, const XMLName value);


// -----------------------------------------------------------------------------
// Child: documentation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
SpinDocumentationHas(ConstHandle2ConstSpin This);

// --- Get, const
extern_c Handle2ConstDocumentation
SpinDocumentationGetConst(ConstHandle2ConstSpin This);

// +++ Get, non-const
extern_c Handle2Documentation
SpinDocumentationGet(ConstHandle2Spin This);

// +++ Set
extern_c void
SpinDocumentationSet(ConstHandle2Spin This, ConstHandle2ConstDocumentation documentation);


// -----------------------------------------------------------------------------
// Child: uncertainty
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
SpinUncertaintyHas(ConstHandle2ConstSpin This);

// --- Get, const
extern_c Handle2ConstUncertainty
SpinUncertaintyGetConst(ConstHandle2ConstSpin This);

// +++ Get, non-const
extern_c Handle2Uncertainty
SpinUncertaintyGet(ConstHandle2Spin This);

// +++ Set
extern_c void
SpinUncertaintySet(ConstHandle2Spin This, ConstHandle2ConstUncertainty uncertainty);


// -----------------------------------------------------------------------------
// Child: fraction
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
SpinFractionHas(ConstHandle2ConstSpin This);

// +++ Clear
extern_c void
SpinFractionClear(ConstHandle2Spin This);

// +++ Size
extern_c size_t
SpinFractionSize(ConstHandle2ConstSpin This);

// +++ Add
extern_c void
SpinFractionAdd(ConstHandle2Spin This, ConstHandle2ConstFraction fraction);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstFraction
SpinFractionGetConst(ConstHandle2ConstSpin This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Fraction
SpinFractionGet(ConstHandle2Spin This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
SpinFractionSet(
   ConstHandle2Spin This,
   const size_t index_,
   ConstHandle2ConstFraction fraction
);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
