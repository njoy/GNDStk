
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
// CovarianceSections is the basic handle type in this file. Example:
//    // Create a default CovarianceSections object:
//    CovarianceSections handle = CovarianceSectionsDefault();
// Functions involving CovarianceSections are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_COVARIANCE_COVARIANCESECTIONS
#define C_INTERFACE_TEST_V2_0_COVARIANCE_COVARIANCESECTIONS

#include "GNDStk.h"
#include "v2.0/covariance/CovarianceSection.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct CovarianceSectionsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ CovarianceSections
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct CovarianceSectionsClass *CovarianceSections;

// --- Const-aware handles.
typedef const struct CovarianceSectionsClass *const ConstHandle2ConstCovarianceSections;
typedef       struct CovarianceSectionsClass *const ConstHandle2CovarianceSections;
typedef const struct CovarianceSectionsClass *      Handle2ConstCovarianceSections;
typedef       struct CovarianceSectionsClass *      Handle2CovarianceSections;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstCovarianceSections
CovarianceSectionsDefaultConst();

// +++ Create, default
extern_c Handle2CovarianceSections
CovarianceSectionsDefault();

// --- Create, general, const
extern_c Handle2ConstCovarianceSections
CovarianceSectionsCreateConst(
   ConstHandle2CovarianceSection *const covarianceSection, const size_t covarianceSectionSize
);

// +++ Create, general
extern_c Handle2CovarianceSections
CovarianceSectionsCreate(
   ConstHandle2CovarianceSection *const covarianceSection, const size_t covarianceSectionSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
CovarianceSectionsAssign(ConstHandle2CovarianceSections self, ConstHandle2ConstCovarianceSections from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
CovarianceSectionsDelete(ConstHandle2ConstCovarianceSections self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
CovarianceSectionsRead(ConstHandle2CovarianceSections self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
CovarianceSectionsWrite(ConstHandle2ConstCovarianceSections self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
CovarianceSectionsPrint(ConstHandle2ConstCovarianceSections self);

// +++ Print to standard output, as XML
extern_c int
CovarianceSectionsPrintXML(ConstHandle2ConstCovarianceSections self);

// +++ Print to standard output, as JSON
extern_c int
CovarianceSectionsPrintJSON(ConstHandle2ConstCovarianceSections self);


// -----------------------------------------------------------------------------
// Child: covarianceSection
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CovarianceSectionsCovarianceSectionHas(ConstHandle2ConstCovarianceSections self);

// +++ Clear
extern_c void
CovarianceSectionsCovarianceSectionClear(ConstHandle2CovarianceSections self);

// +++ Size
extern_c size_t
CovarianceSectionsCovarianceSectionSize(ConstHandle2ConstCovarianceSections self);

// +++ Add
extern_c void
CovarianceSectionsCovarianceSectionAdd(ConstHandle2CovarianceSections self, ConstHandle2ConstCovarianceSection covarianceSection);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstCovarianceSection
CovarianceSectionsCovarianceSectionGetConst(ConstHandle2ConstCovarianceSections self, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2CovarianceSection
CovarianceSectionsCovarianceSectionGet(ConstHandle2CovarianceSections self, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
CovarianceSectionsCovarianceSectionSet(
   ConstHandle2CovarianceSections self,
   const size_t index_,
   ConstHandle2ConstCovarianceSection covarianceSection
);

// +++ Has, by crossTerm
extern_c int
CovarianceSectionsCovarianceSectionHasByCrossTerm(
   ConstHandle2ConstCovarianceSections self,
   const bool crossTerm
);

// --- Get, by crossTerm, const
extern_c Handle2ConstCovarianceSection
CovarianceSectionsCovarianceSectionGetByCrossTermConst(
   ConstHandle2ConstCovarianceSections self,
   const bool crossTerm
);

// +++ Get, by crossTerm, non-const
extern_c Handle2CovarianceSection
CovarianceSectionsCovarianceSectionGetByCrossTerm(
   ConstHandle2CovarianceSections self,
   const bool crossTerm
);

// +++ Set, by crossTerm
extern_c void
CovarianceSectionsCovarianceSectionSetByCrossTerm(
   ConstHandle2CovarianceSections self,
   const bool crossTerm,
   ConstHandle2ConstCovarianceSection covarianceSection
);

// +++ Has, by label
extern_c int
CovarianceSectionsCovarianceSectionHasByLabel(
   ConstHandle2ConstCovarianceSections self,
   const XMLName label
);

// --- Get, by label, const
extern_c Handle2ConstCovarianceSection
CovarianceSectionsCovarianceSectionGetByLabelConst(
   ConstHandle2ConstCovarianceSections self,
   const XMLName label
);

// +++ Get, by label, non-const
extern_c Handle2CovarianceSection
CovarianceSectionsCovarianceSectionGetByLabel(
   ConstHandle2CovarianceSections self,
   const XMLName label
);

// +++ Set, by label
extern_c void
CovarianceSectionsCovarianceSectionSetByLabel(
   ConstHandle2CovarianceSections self,
   const XMLName label,
   ConstHandle2ConstCovarianceSection covarianceSection
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/covariance/CovarianceSections/src/custom.h"

#undef extern_c
#endif
