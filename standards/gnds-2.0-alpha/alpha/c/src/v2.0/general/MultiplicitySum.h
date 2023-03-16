
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
// MultiplicitySum is the basic handle type in this file. Example:
//    // Create a default MultiplicitySum object:
//    MultiplicitySum handle = MultiplicitySumDefault();
// Functions involving MultiplicitySum are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_MULTIPLICITYSUM
#define C_INTERFACE_ALPHA_V2_0_GENERAL_MULTIPLICITYSUM

#include "GNDStk.h"
#include "v2.0/general/Multiplicity.h"
#include "v2.0/general/Summands.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct MultiplicitySumClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ MultiplicitySum
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct MultiplicitySumClass *MultiplicitySum;

// --- Const-aware handles.
typedef const struct MultiplicitySumClass *const ConstHandle2ConstMultiplicitySum;
typedef       struct MultiplicitySumClass *const ConstHandle2MultiplicitySum;
typedef const struct MultiplicitySumClass *      Handle2ConstMultiplicitySum;
typedef       struct MultiplicitySumClass *      Handle2MultiplicitySum;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstMultiplicitySum
MultiplicitySumDefaultConst();

// +++ Create, default
extern_c Handle2MultiplicitySum
MultiplicitySumDefault();

// --- Create, general, const
extern_c Handle2ConstMultiplicitySum
MultiplicitySumCreateConst(
   const char *const label,
   const int ENDF_MT,
   ConstHandle2ConstMultiplicity multiplicity,
   ConstHandle2ConstSummands summands
);

// +++ Create, general
extern_c Handle2MultiplicitySum
MultiplicitySumCreate(
   const char *const label,
   const int ENDF_MT,
   ConstHandle2ConstMultiplicity multiplicity,
   ConstHandle2ConstSummands summands
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
MultiplicitySumAssign(ConstHandle2MultiplicitySum self, ConstHandle2ConstMultiplicitySum from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
MultiplicitySumDelete(ConstHandle2ConstMultiplicitySum self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
MultiplicitySumRead(ConstHandle2MultiplicitySum self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
MultiplicitySumWrite(ConstHandle2ConstMultiplicitySum self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
MultiplicitySumPrint(ConstHandle2ConstMultiplicitySum self);

// +++ Print to standard output, as XML
extern_c int
MultiplicitySumPrintXML(ConstHandle2ConstMultiplicitySum self);

// +++ Print to standard output, as JSON
extern_c int
MultiplicitySumPrintJSON(ConstHandle2ConstMultiplicitySum self);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MultiplicitySumLabelHas(ConstHandle2ConstMultiplicitySum self);

// +++ Get
// +++ Returns by value
extern_c const char *
MultiplicitySumLabelGet(ConstHandle2ConstMultiplicitySum self);

// +++ Set
extern_c void
MultiplicitySumLabelSet(ConstHandle2MultiplicitySum self, const char *const label);


// -----------------------------------------------------------------------------
// Metadatum: ENDF_MT
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MultiplicitySumENDFMTHas(ConstHandle2ConstMultiplicitySum self);

// +++ Get
// +++ Returns by value
extern_c int
MultiplicitySumENDFMTGet(ConstHandle2ConstMultiplicitySum self);

// +++ Set
extern_c void
MultiplicitySumENDFMTSet(ConstHandle2MultiplicitySum self, const int ENDF_MT);


// -----------------------------------------------------------------------------
// Child: multiplicity
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MultiplicitySumMultiplicityHas(ConstHandle2ConstMultiplicitySum self);

// --- Get, const
extern_c Handle2ConstMultiplicity
MultiplicitySumMultiplicityGetConst(ConstHandle2ConstMultiplicitySum self);

// +++ Get, non-const
extern_c Handle2Multiplicity
MultiplicitySumMultiplicityGet(ConstHandle2MultiplicitySum self);

// +++ Set
extern_c void
MultiplicitySumMultiplicitySet(ConstHandle2MultiplicitySum self, ConstHandle2ConstMultiplicity multiplicity);


// -----------------------------------------------------------------------------
// Child: summands
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MultiplicitySumSummandsHas(ConstHandle2ConstMultiplicitySum self);

// --- Get, const
extern_c Handle2ConstSummands
MultiplicitySumSummandsGetConst(ConstHandle2ConstMultiplicitySum self);

// +++ Get, non-const
extern_c Handle2Summands
MultiplicitySumSummandsGet(ConstHandle2MultiplicitySum self);

// +++ Set
extern_c void
MultiplicitySumSummandsSet(ConstHandle2MultiplicitySum self, ConstHandle2ConstSummands summands);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/MultiplicitySum/src/custom.h"

#undef extern_c
#endif
