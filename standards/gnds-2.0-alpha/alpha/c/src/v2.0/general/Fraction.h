
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
// Fraction is the basic handle type in this file. Example:
//    // Create a default Fraction object:
//    Fraction handle = FractionDefault();
// Functions involving Fraction are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_FRACTION
#define C_INTERFACE_ALPHA_V2_0_GENERAL_FRACTION

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct FractionClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Fraction
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct FractionClass *Fraction;

// --- Const-aware handles.
typedef const struct FractionClass *const ConstHandle2ConstFraction;
typedef       struct FractionClass *const ConstHandle2Fraction;
typedef const struct FractionClass *      Handle2ConstFraction;
typedef       struct FractionClass *      Handle2Fraction;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstFraction
FractionDefaultConst();

// +++ Create, default
extern_c Handle2Fraction
FractionDefault();

// --- Create, general, const
extern_c Handle2ConstFraction
FractionCreateConst(
   const char *const label,
   const char *const value,
   const char *const unit
);

// +++ Create, general
extern_c Handle2Fraction
FractionCreate(
   const char *const label,
   const char *const value,
   const char *const unit
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
FractionAssign(ConstHandle2Fraction self, ConstHandle2ConstFraction from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
FractionDelete(ConstHandle2ConstFraction self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
FractionRead(ConstHandle2Fraction self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
FractionWrite(ConstHandle2ConstFraction self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
FractionPrint(ConstHandle2ConstFraction self);

// +++ Print to standard output, as XML
extern_c int
FractionPrintXML(ConstHandle2ConstFraction self);

// +++ Print to standard output, as JSON
extern_c int
FractionPrintJSON(ConstHandle2ConstFraction self);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
FractionLabelHas(ConstHandle2ConstFraction self);

// +++ Get
// +++ Returns by value
extern_c const char *
FractionLabelGet(ConstHandle2ConstFraction self);

// +++ Set
extern_c void
FractionLabelSet(ConstHandle2Fraction self, const char *const label);


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
FractionValueHas(ConstHandle2ConstFraction self);

// +++ Get
// +++ Returns by value
extern_c const char *
FractionValueGet(ConstHandle2ConstFraction self);

// +++ Set
extern_c void
FractionValueSet(ConstHandle2Fraction self, const char *const value);


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
FractionUnitHas(ConstHandle2ConstFraction self);

// +++ Get
// +++ Returns by value
extern_c const char *
FractionUnitGet(ConstHandle2ConstFraction self);

// +++ Set
extern_c void
FractionUnitSet(ConstHandle2Fraction self, const char *const unit);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Fraction/src/custom.h"

#undef extern_c
#endif
