
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
// Uncertainty is the basic handle type in this file. Example:
//    // Create a default Uncertainty object:
//    Uncertainty handle = UncertaintyDefault();
// Functions involving Uncertainty are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_POPS_UNCERTAINTY
#define C_INTERFACE_TEST_V2_0_POPS_UNCERTAINTY

#include "GNDStk.h"
#include "v2.0/pops/Standard.h"
#include "v2.0/pops/LogNormal.h"
#include "v2.0/pops/ConfidenceIntervals.h"
#include "v2.0/pops/Pdf.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct UncertaintyClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Uncertainty
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct UncertaintyClass *Uncertainty;

// --- Const-aware handles.
typedef const struct UncertaintyClass *const ConstHandle2ConstUncertainty;
typedef       struct UncertaintyClass *const ConstHandle2Uncertainty;
typedef const struct UncertaintyClass *      Handle2ConstUncertainty;
typedef       struct UncertaintyClass *      Handle2Uncertainty;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstUncertainty
UncertaintyDefaultConst();

// +++ Create, default
extern_c Handle2Uncertainty
UncertaintyDefault();

// --- Create, general, const
extern_c Handle2ConstUncertainty
UncertaintyCreateConst(
   ConstHandle2ConstStandard standard,
   ConstHandle2ConstLogNormal logNormal,
   ConstHandle2ConstConfidenceIntervals confidenceIntervals,
   ConstHandle2ConstPdf pdf
);

// +++ Create, general
extern_c Handle2Uncertainty
UncertaintyCreate(
   ConstHandle2ConstStandard standard,
   ConstHandle2ConstLogNormal logNormal,
   ConstHandle2ConstConfidenceIntervals confidenceIntervals,
   ConstHandle2ConstPdf pdf
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
UncertaintyAssign(ConstHandle2Uncertainty This, ConstHandle2ConstUncertainty from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
UncertaintyDelete(ConstHandle2ConstUncertainty This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
UncertaintyRead(ConstHandle2Uncertainty This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
UncertaintyWrite(ConstHandle2ConstUncertainty This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
UncertaintyPrint(ConstHandle2ConstUncertainty This);

// +++ Print to standard output, as XML
extern_c int
UncertaintyPrintXML(ConstHandle2ConstUncertainty This);

// +++ Print to standard output, as JSON
extern_c int
UncertaintyPrintJSON(ConstHandle2ConstUncertainty This);


// -----------------------------------------------------------------------------
// Child: standard
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
UncertaintyStandardHas(ConstHandle2ConstUncertainty This);

// --- Get, const
extern_c Handle2ConstStandard
UncertaintyStandardGetConst(ConstHandle2ConstUncertainty This);

// +++ Get, non-const
extern_c Handle2Standard
UncertaintyStandardGet(ConstHandle2Uncertainty This);

// +++ Set
extern_c void
UncertaintyStandardSet(ConstHandle2Uncertainty This, ConstHandle2ConstStandard standard);


// -----------------------------------------------------------------------------
// Child: logNormal
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
UncertaintyLogNormalHas(ConstHandle2ConstUncertainty This);

// --- Get, const
extern_c Handle2ConstLogNormal
UncertaintyLogNormalGetConst(ConstHandle2ConstUncertainty This);

// +++ Get, non-const
extern_c Handle2LogNormal
UncertaintyLogNormalGet(ConstHandle2Uncertainty This);

// +++ Set
extern_c void
UncertaintyLogNormalSet(ConstHandle2Uncertainty This, ConstHandle2ConstLogNormal logNormal);


// -----------------------------------------------------------------------------
// Child: confidenceIntervals
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
UncertaintyConfidenceIntervalsHas(ConstHandle2ConstUncertainty This);

// --- Get, const
extern_c Handle2ConstConfidenceIntervals
UncertaintyConfidenceIntervalsGetConst(ConstHandle2ConstUncertainty This);

// +++ Get, non-const
extern_c Handle2ConfidenceIntervals
UncertaintyConfidenceIntervalsGet(ConstHandle2Uncertainty This);

// +++ Set
extern_c void
UncertaintyConfidenceIntervalsSet(ConstHandle2Uncertainty This, ConstHandle2ConstConfidenceIntervals confidenceIntervals);


// -----------------------------------------------------------------------------
// Child: pdf
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
UncertaintyPdfHas(ConstHandle2ConstUncertainty This);

// --- Get, const
extern_c Handle2ConstPdf
UncertaintyPdfGetConst(ConstHandle2ConstUncertainty This);

// +++ Get, non-const
extern_c Handle2Pdf
UncertaintyPdfGet(ConstHandle2Uncertainty This);

// +++ Set
extern_c void
UncertaintyPdfSet(ConstHandle2Uncertainty This, ConstHandle2ConstPdf pdf);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
