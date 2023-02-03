
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
// Sums is the basic handle type in this file. Example:
//    // Create a default Sums object:
//    Sums handle = SumsDefault();
// Functions involving Sums are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_SUMS
#define C_INTERFACE_ALPHA_V2_0_GENERAL_SUMS

#include "GNDStk.h"
#include "v2.0/general/CrossSectionSums.h"
#include "v2.0/general/MultiplicitySums.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct SumsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Sums
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct SumsClass *Sums;

// --- Const-aware handles.
typedef const struct SumsClass *const ConstHandle2ConstSums;
typedef       struct SumsClass *const ConstHandle2Sums;
typedef const struct SumsClass *      Handle2ConstSums;
typedef       struct SumsClass *      Handle2Sums;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstSums
SumsDefaultConst();

// +++ Create, default
extern_c Handle2Sums
SumsDefault();

// --- Create, general, const
extern_c Handle2ConstSums
SumsCreateConst(
   ConstHandle2ConstCrossSectionSums crossSectionSums,
   ConstHandle2ConstMultiplicitySums multiplicitySums
);

// +++ Create, general
extern_c Handle2Sums
SumsCreate(
   ConstHandle2ConstCrossSectionSums crossSectionSums,
   ConstHandle2ConstMultiplicitySums multiplicitySums
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
SumsAssign(ConstHandle2Sums This, ConstHandle2ConstSums from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
SumsDelete(ConstHandle2ConstSums This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
SumsRead(ConstHandle2Sums This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
SumsWrite(ConstHandle2ConstSums This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
SumsPrint(ConstHandle2ConstSums This);

// +++ Print to standard output, as XML
extern_c int
SumsPrintXML(ConstHandle2ConstSums This);

// +++ Print to standard output, as JSON
extern_c int
SumsPrintJSON(ConstHandle2ConstSums This);


// -----------------------------------------------------------------------------
// Child: crossSectionSums
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
SumsCrossSectionSumsHas(ConstHandle2ConstSums This);

// --- Get, const
extern_c Handle2ConstCrossSectionSums
SumsCrossSectionSumsGetConst(ConstHandle2ConstSums This);

// +++ Get, non-const
extern_c Handle2CrossSectionSums
SumsCrossSectionSumsGet(ConstHandle2Sums This);

// +++ Set
extern_c void
SumsCrossSectionSumsSet(ConstHandle2Sums This, ConstHandle2ConstCrossSectionSums crossSectionSums);


// -----------------------------------------------------------------------------
// Child: multiplicitySums
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
SumsMultiplicitySumsHas(ConstHandle2ConstSums This);

// --- Get, const
extern_c Handle2ConstMultiplicitySums
SumsMultiplicitySumsGetConst(ConstHandle2ConstSums This);

// +++ Get, non-const
extern_c Handle2MultiplicitySums
SumsMultiplicitySumsGet(ConstHandle2Sums This);

// +++ Set
extern_c void
SumsMultiplicitySumsSet(ConstHandle2Sums This, ConstHandle2ConstMultiplicitySums multiplicitySums);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Sums/src/custom.h"

#undef extern_c
#endif
