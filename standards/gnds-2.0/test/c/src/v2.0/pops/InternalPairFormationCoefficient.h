
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
// InternalPairFormationCoefficient is the basic handle type in this file. Example:
//    // Create a default InternalPairFormationCoefficient object:
//    InternalPairFormationCoefficient handle = InternalPairFormationCoefficientDefault();
// Functions involving InternalPairFormationCoefficient are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_POPS_INTERNALPAIRFORMATIONCOEFFICIENT
#define C_INTERFACE_TEST_V2_0_POPS_INTERNALPAIRFORMATIONCOEFFICIENT

#include "GNDStk.h"
#include "v2.0/documentation/Documentation.h"
#include "v2.0/pops/Uncertainty.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct InternalPairFormationCoefficientClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ InternalPairFormationCoefficient
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct InternalPairFormationCoefficientClass *InternalPairFormationCoefficient;

// --- Const-aware handles.
typedef const struct InternalPairFormationCoefficientClass *const ConstHandle2ConstInternalPairFormationCoefficient;
typedef       struct InternalPairFormationCoefficientClass *const ConstHandle2InternalPairFormationCoefficient;
typedef const struct InternalPairFormationCoefficientClass *      Handle2ConstInternalPairFormationCoefficient;
typedef       struct InternalPairFormationCoefficientClass *      Handle2InternalPairFormationCoefficient;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstInternalPairFormationCoefficient
InternalPairFormationCoefficientDefaultConst();

// +++ Create, default
extern_c Handle2InternalPairFormationCoefficient
InternalPairFormationCoefficientDefault();

// --- Create, general, const
extern_c Handle2ConstInternalPairFormationCoefficient
InternalPairFormationCoefficientCreateConst(
   const XMLName label,
   const Float64 value,
   const XMLName unit,
   ConstHandle2ConstDocumentation documentation,
   ConstHandle2ConstUncertainty uncertainty
);

// +++ Create, general
extern_c Handle2InternalPairFormationCoefficient
InternalPairFormationCoefficientCreate(
   const XMLName label,
   const Float64 value,
   const XMLName unit,
   ConstHandle2ConstDocumentation documentation,
   ConstHandle2ConstUncertainty uncertainty
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
InternalPairFormationCoefficientAssign(ConstHandle2InternalPairFormationCoefficient self, ConstHandle2ConstInternalPairFormationCoefficient from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
InternalPairFormationCoefficientDelete(ConstHandle2ConstInternalPairFormationCoefficient self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
InternalPairFormationCoefficientRead(ConstHandle2InternalPairFormationCoefficient self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
InternalPairFormationCoefficientWrite(ConstHandle2ConstInternalPairFormationCoefficient self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
InternalPairFormationCoefficientPrint(ConstHandle2ConstInternalPairFormationCoefficient self);

// +++ Print to standard output, as XML
extern_c int
InternalPairFormationCoefficientPrintXML(ConstHandle2ConstInternalPairFormationCoefficient self);

// +++ Print to standard output, as JSON
extern_c int
InternalPairFormationCoefficientPrintJSON(ConstHandle2ConstInternalPairFormationCoefficient self);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
InternalPairFormationCoefficientLabelHas(ConstHandle2ConstInternalPairFormationCoefficient self);

// +++ Get
// +++ Returns by value
extern_c XMLName
InternalPairFormationCoefficientLabelGet(ConstHandle2ConstInternalPairFormationCoefficient self);

// +++ Set
extern_c void
InternalPairFormationCoefficientLabelSet(ConstHandle2InternalPairFormationCoefficient self, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
InternalPairFormationCoefficientValueHas(ConstHandle2ConstInternalPairFormationCoefficient self);

// +++ Get
// +++ Returns by value
extern_c Float64
InternalPairFormationCoefficientValueGet(ConstHandle2ConstInternalPairFormationCoefficient self);

// +++ Set
extern_c void
InternalPairFormationCoefficientValueSet(ConstHandle2InternalPairFormationCoefficient self, const Float64 value);


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
InternalPairFormationCoefficientUnitHas(ConstHandle2ConstInternalPairFormationCoefficient self);

// +++ Get
// +++ Returns by value
extern_c XMLName
InternalPairFormationCoefficientUnitGet(ConstHandle2ConstInternalPairFormationCoefficient self);

// +++ Set
extern_c void
InternalPairFormationCoefficientUnitSet(ConstHandle2InternalPairFormationCoefficient self, const XMLName unit);


// -----------------------------------------------------------------------------
// Child: documentation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
InternalPairFormationCoefficientDocumentationHas(ConstHandle2ConstInternalPairFormationCoefficient self);

// --- Get, const
extern_c Handle2ConstDocumentation
InternalPairFormationCoefficientDocumentationGetConst(ConstHandle2ConstInternalPairFormationCoefficient self);

// +++ Get, non-const
extern_c Handle2Documentation
InternalPairFormationCoefficientDocumentationGet(ConstHandle2InternalPairFormationCoefficient self);

// +++ Set
extern_c void
InternalPairFormationCoefficientDocumentationSet(ConstHandle2InternalPairFormationCoefficient self, ConstHandle2ConstDocumentation documentation);


// -----------------------------------------------------------------------------
// Child: uncertainty
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
InternalPairFormationCoefficientUncertaintyHas(ConstHandle2ConstInternalPairFormationCoefficient self);

// --- Get, const
extern_c Handle2ConstUncertainty
InternalPairFormationCoefficientUncertaintyGetConst(ConstHandle2ConstInternalPairFormationCoefficient self);

// +++ Get, non-const
extern_c Handle2Uncertainty
InternalPairFormationCoefficientUncertaintyGet(ConstHandle2InternalPairFormationCoefficient self);

// +++ Set
extern_c void
InternalPairFormationCoefficientUncertaintySet(ConstHandle2InternalPairFormationCoefficient self, ConstHandle2ConstUncertainty uncertainty);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/pops/InternalPairFormationCoefficient/src/custom.h"

#undef extern_c
#endif
