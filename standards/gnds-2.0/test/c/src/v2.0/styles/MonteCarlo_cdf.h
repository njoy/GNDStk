
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
// MonteCarlo_cdf is the basic handle type in this file. Example:
//    // Create a default MonteCarlo_cdf object:
//    MonteCarlo_cdf handle = MonteCarlo_cdfDefault();
// Functions involving MonteCarlo_cdf are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_STYLES_MONTECARLO_CDF
#define C_INTERFACE_TEST_V2_0_STYLES_MONTECARLO_CDF

#include "GNDStk.h"
#include "v2.0/documentation/Documentation.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct MonteCarlo_cdfClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ MonteCarlo_cdf
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct MonteCarlo_cdfClass *MonteCarlo_cdf;

// --- Const-aware handles.
typedef const struct MonteCarlo_cdfClass *const ConstHandle2ConstMonteCarlo_cdf;
typedef       struct MonteCarlo_cdfClass *const ConstHandle2MonteCarlo_cdf;
typedef const struct MonteCarlo_cdfClass *      Handle2ConstMonteCarlo_cdf;
typedef       struct MonteCarlo_cdfClass *      Handle2MonteCarlo_cdf;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstMonteCarlo_cdf
MonteCarlo_cdfDefaultConst();

// +++ Create, default
extern_c Handle2MonteCarlo_cdf
MonteCarlo_cdfDefault();

// --- Create, general, const
extern_c Handle2ConstMonteCarlo_cdf
MonteCarlo_cdfCreateConst(
   const char *const date,
   const XMLName derivedFrom,
   const XMLName label,
   ConstHandle2ConstDocumentation documentation
);

// +++ Create, general
extern_c Handle2MonteCarlo_cdf
MonteCarlo_cdfCreate(
   const char *const date,
   const XMLName derivedFrom,
   const XMLName label,
   ConstHandle2ConstDocumentation documentation
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
MonteCarlo_cdfAssign(ConstHandle2MonteCarlo_cdf This, ConstHandle2ConstMonteCarlo_cdf from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
MonteCarlo_cdfDelete(ConstHandle2ConstMonteCarlo_cdf This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
MonteCarlo_cdfRead(ConstHandle2MonteCarlo_cdf This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
MonteCarlo_cdfWrite(ConstHandle2ConstMonteCarlo_cdf This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
MonteCarlo_cdfPrint(ConstHandle2ConstMonteCarlo_cdf This);

// +++ Print to standard output, as XML
extern_c int
MonteCarlo_cdfPrintXML(ConstHandle2ConstMonteCarlo_cdf This);

// +++ Print to standard output, as JSON
extern_c int
MonteCarlo_cdfPrintJSON(ConstHandle2ConstMonteCarlo_cdf This);


// -----------------------------------------------------------------------------
// Metadatum: date
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MonteCarlo_cdfDateHas(ConstHandle2ConstMonteCarlo_cdf This);

// +++ Get
// +++ Returns by value
extern_c const char *
MonteCarlo_cdfDateGet(ConstHandle2ConstMonteCarlo_cdf This);

// +++ Set
extern_c void
MonteCarlo_cdfDateSet(ConstHandle2MonteCarlo_cdf This, const char *const date);


// -----------------------------------------------------------------------------
// Metadatum: derivedFrom
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MonteCarlo_cdfDerivedFromHas(ConstHandle2ConstMonteCarlo_cdf This);

// +++ Get
// +++ Returns by value
extern_c XMLName
MonteCarlo_cdfDerivedFromGet(ConstHandle2ConstMonteCarlo_cdf This);

// +++ Set
extern_c void
MonteCarlo_cdfDerivedFromSet(ConstHandle2MonteCarlo_cdf This, const XMLName derivedFrom);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MonteCarlo_cdfLabelHas(ConstHandle2ConstMonteCarlo_cdf This);

// +++ Get
// +++ Returns by value
extern_c XMLName
MonteCarlo_cdfLabelGet(ConstHandle2ConstMonteCarlo_cdf This);

// +++ Set
extern_c void
MonteCarlo_cdfLabelSet(ConstHandle2MonteCarlo_cdf This, const XMLName label);


// -----------------------------------------------------------------------------
// Child: documentation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MonteCarlo_cdfDocumentationHas(ConstHandle2ConstMonteCarlo_cdf This);

// --- Get, const
extern_c Handle2ConstDocumentation
MonteCarlo_cdfDocumentationGetConst(ConstHandle2ConstMonteCarlo_cdf This);

// +++ Get, non-const
extern_c Handle2Documentation
MonteCarlo_cdfDocumentationGet(ConstHandle2MonteCarlo_cdf This);

// +++ Set
extern_c void
MonteCarlo_cdfDocumentationSet(ConstHandle2MonteCarlo_cdf This, ConstHandle2ConstDocumentation documentation);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/styles/MonteCarlo_cdf/src/custom.h"

#undef extern_c
#endif
