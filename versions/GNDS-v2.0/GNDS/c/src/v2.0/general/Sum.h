
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
// Sum is the basic handle type in this file. Example:
//    // Create a default Sum object:
//    Sum handle = SumDefault();
// Functions involving Sum are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_SUM
#define C_INTERFACE_GNDS_V2_0_GENERAL_SUM

#include "GNDStk.h"
#include "v2.0/general/Summand.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct SumClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Sum
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct SumClass *Sum;

// --- Const-aware handles.
typedef const struct SumClass *const ConstHandle2ConstSum;
typedef       struct SumClass *const ConstHandle2Sum;
typedef const struct SumClass *      Handle2ConstSum;
typedef       struct SumClass *      Handle2Sum;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstSum
SumDefaultConst();

// +++ Create, default, non-const
extern_c Handle2Sum
SumDefault();

// --- Create, general, const
extern_c Handle2ConstSum
SumCreateConst(
   const char *const label,
   const double domainMin,
   const double domainMax,
   const char *const domainUnit,
   ConstHandle2Summand *const summand, const size_t summandSize
);

// +++ Create, general, non-const
extern_c Handle2Sum
SumCreate(
   const char *const label,
   const double domainMin,
   const double domainMax,
   const char *const domainUnit,
   ConstHandle2Summand *const summand, const size_t summandSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
SumAssign(ConstHandle2Sum self, ConstHandle2ConstSum from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
SumDelete(ConstHandle2ConstSum self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
SumRead(ConstHandle2Sum self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
SumWrite(ConstHandle2ConstSum self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
SumPrint(ConstHandle2ConstSum self);

// +++ Print to standard output, as XML
extern_c int
SumPrintXML(ConstHandle2ConstSum self);

// +++ Print to standard output, as JSON
extern_c int
SumPrintJSON(ConstHandle2ConstSum self);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
SumLabelHas(ConstHandle2ConstSum self);

// +++ Get
// +++ Returns by value
extern_c const char *
SumLabelGet(ConstHandle2ConstSum self);

// +++ Set
extern_c void
SumLabelSet(ConstHandle2Sum self, const char *const label);


// -----------------------------------------------------------------------------
// Metadatum: domainMin
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
SumDomainMinHas(ConstHandle2ConstSum self);

// +++ Get
// +++ Returns by value
extern_c double
SumDomainMinGet(ConstHandle2ConstSum self);

// +++ Set
extern_c void
SumDomainMinSet(ConstHandle2Sum self, const double domainMin);


// -----------------------------------------------------------------------------
// Metadatum: domainMax
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
SumDomainMaxHas(ConstHandle2ConstSum self);

// +++ Get
// +++ Returns by value
extern_c double
SumDomainMaxGet(ConstHandle2ConstSum self);

// +++ Set
extern_c void
SumDomainMaxSet(ConstHandle2Sum self, const double domainMax);


// -----------------------------------------------------------------------------
// Metadatum: domainUnit
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
SumDomainUnitHas(ConstHandle2ConstSum self);

// +++ Get
// +++ Returns by value
extern_c const char *
SumDomainUnitGet(ConstHandle2ConstSum self);

// +++ Set
extern_c void
SumDomainUnitSet(ConstHandle2Sum self, const char *const domainUnit);


// -----------------------------------------------------------------------------
// Child: summand
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
SumSummandHas(ConstHandle2ConstSum self);

// +++ Clear
extern_c void
SumSummandClear(ConstHandle2Sum self);

// +++ Size
extern_c size_t
SumSummandSize(ConstHandle2ConstSum self);

// +++ Add
extern_c void
SumSummandAdd(ConstHandle2Sum self, ConstHandle2ConstSummand summand);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstSummand
SumSummandGetConst(ConstHandle2ConstSum self, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Summand
SumSummandGet(ConstHandle2Sum self, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
SumSummandSet(
   ConstHandle2Sum self,
   const size_t index_,
   ConstHandle2ConstSummand summand
);

// ------------------------
// Re: metadatum ENDF_MFMT
// ------------------------

// +++ Has, by ENDF_MFMT
extern_c int
SumSummandHasByENDFMFMT(
   ConstHandle2ConstSum self,
   const char *const ENDF_MFMT
);

// --- Get, by ENDF_MFMT, const
extern_c Handle2ConstSummand
SumSummandGetByENDFMFMTConst(
   ConstHandle2ConstSum self,
   const char *const ENDF_MFMT
);

// +++ Get, by ENDF_MFMT, non-const
extern_c Handle2Summand
SumSummandGetByENDFMFMT(
   ConstHandle2Sum self,
   const char *const ENDF_MFMT
);

// +++ Set, by ENDF_MFMT
extern_c void
SumSummandSetByENDFMFMT(
   ConstHandle2Sum self,
   const char *const ENDF_MFMT,
   ConstHandle2ConstSummand summand
);

// ------------------------
// Re: metadatum coefficient
// ------------------------

// +++ Has, by coefficient
extern_c int
SumSummandHasByCoefficient(
   ConstHandle2ConstSum self,
   const char *const coefficient
);

// --- Get, by coefficient, const
extern_c Handle2ConstSummand
SumSummandGetByCoefficientConst(
   ConstHandle2ConstSum self,
   const char *const coefficient
);

// +++ Get, by coefficient, non-const
extern_c Handle2Summand
SumSummandGetByCoefficient(
   ConstHandle2Sum self,
   const char *const coefficient
);

// +++ Set, by coefficient
extern_c void
SumSummandSetByCoefficient(
   ConstHandle2Sum self,
   const char *const coefficient,
   ConstHandle2ConstSummand summand
);

// ------------------------
// Re: metadatum href
// ------------------------

// +++ Has, by href
extern_c int
SumSummandHasByHref(
   ConstHandle2ConstSum self,
   const char *const href
);

// --- Get, by href, const
extern_c Handle2ConstSummand
SumSummandGetByHrefConst(
   ConstHandle2ConstSum self,
   const char *const href
);

// +++ Get, by href, non-const
extern_c Handle2Summand
SumSummandGetByHref(
   ConstHandle2Sum self,
   const char *const href
);

// +++ Set, by href
extern_c void
SumSummandSetByHref(
   ConstHandle2Sum self,
   const char *const href,
   ConstHandle2ConstSummand summand
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Sum/src/custom.h"

#undef extern_c
#endif
