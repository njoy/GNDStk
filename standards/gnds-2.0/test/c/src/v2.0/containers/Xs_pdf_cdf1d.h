
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
// Xs_pdf_cdf1d is the basic handle type in this file. Example:
//    // Create a default Xs_pdf_cdf1d object:
//    Xs_pdf_cdf1d handle = Xs_pdf_cdf1dDefault();
// Functions involving Xs_pdf_cdf1d are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_CONTAINERS_XS_PDF_CDF1D
#define C_INTERFACE_TEST_V2_0_CONTAINERS_XS_PDF_CDF1D

#include "GNDStk.h"
#include "v2.0/containers/Xs_in_xs_pdf_cdf1d.h"
#include "v2.0/containers/Pdf.h"
#include "v2.0/containers/Cdf_in_xs_pdf_cdf1d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct Xs_pdf_cdf1dClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Xs_pdf_cdf1d
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct Xs_pdf_cdf1dClass *Xs_pdf_cdf1d;

// --- Const-aware handles.
typedef const struct Xs_pdf_cdf1dClass *const ConstHandle2ConstXs_pdf_cdf1d;
typedef       struct Xs_pdf_cdf1dClass *const ConstHandle2Xs_pdf_cdf1d;
typedef const struct Xs_pdf_cdf1dClass *      Handle2ConstXs_pdf_cdf1d;
typedef       struct Xs_pdf_cdf1dClass *      Handle2Xs_pdf_cdf1d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstXs_pdf_cdf1d
Xs_pdf_cdf1dDefaultConst();

// +++ Create, default
extern_c Handle2Xs_pdf_cdf1d
Xs_pdf_cdf1dDefault();

// --- Create, general, const
extern_c Handle2ConstXs_pdf_cdf1d
Xs_pdf_cdf1dCreateConst(
   const Float64 outerDomainValue,
   ConstHandle2ConstXs_in_xs_pdf_cdf1d xs_in_xs_pdf_cdf1d,
   ConstHandle2ConstPdf pdf,
   ConstHandle2ConstCdf_in_xs_pdf_cdf1d cdf_in_xs_pdf_cdf1d
);

// +++ Create, general
extern_c Handle2Xs_pdf_cdf1d
Xs_pdf_cdf1dCreate(
   const Float64 outerDomainValue,
   ConstHandle2ConstXs_in_xs_pdf_cdf1d xs_in_xs_pdf_cdf1d,
   ConstHandle2ConstPdf pdf,
   ConstHandle2ConstCdf_in_xs_pdf_cdf1d cdf_in_xs_pdf_cdf1d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
Xs_pdf_cdf1dAssign(ConstHandle2Xs_pdf_cdf1d self, ConstHandle2ConstXs_pdf_cdf1d from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
Xs_pdf_cdf1dDelete(ConstHandle2ConstXs_pdf_cdf1d self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
Xs_pdf_cdf1dRead(ConstHandle2Xs_pdf_cdf1d self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
Xs_pdf_cdf1dWrite(ConstHandle2ConstXs_pdf_cdf1d self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
Xs_pdf_cdf1dPrint(ConstHandle2ConstXs_pdf_cdf1d self);

// +++ Print to standard output, as XML
extern_c int
Xs_pdf_cdf1dPrintXML(ConstHandle2ConstXs_pdf_cdf1d self);

// +++ Print to standard output, as JSON
extern_c int
Xs_pdf_cdf1dPrintJSON(ConstHandle2ConstXs_pdf_cdf1d self);


// -----------------------------------------------------------------------------
// Metadatum: outerDomainValue
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Xs_pdf_cdf1dOuterDomainValueHas(ConstHandle2ConstXs_pdf_cdf1d self);

// +++ Get
// +++ Returns by value
extern_c Float64
Xs_pdf_cdf1dOuterDomainValueGet(ConstHandle2ConstXs_pdf_cdf1d self);

// +++ Set
extern_c void
Xs_pdf_cdf1dOuterDomainValueSet(ConstHandle2Xs_pdf_cdf1d self, const Float64 outerDomainValue);


// -----------------------------------------------------------------------------
// Child: xs_in_xs_pdf_cdf1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Xs_pdf_cdf1dXs_in_xs_pdf_cdf1dHas(ConstHandle2ConstXs_pdf_cdf1d self);

// --- Get, const
extern_c Handle2ConstXs_in_xs_pdf_cdf1d
Xs_pdf_cdf1dXs_in_xs_pdf_cdf1dGetConst(ConstHandle2ConstXs_pdf_cdf1d self);

// +++ Get, non-const
extern_c Handle2Xs_in_xs_pdf_cdf1d
Xs_pdf_cdf1dXs_in_xs_pdf_cdf1dGet(ConstHandle2Xs_pdf_cdf1d self);

// +++ Set
extern_c void
Xs_pdf_cdf1dXs_in_xs_pdf_cdf1dSet(ConstHandle2Xs_pdf_cdf1d self, ConstHandle2ConstXs_in_xs_pdf_cdf1d xs_in_xs_pdf_cdf1d);


// -----------------------------------------------------------------------------
// Child: pdf
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Xs_pdf_cdf1dPdfHas(ConstHandle2ConstXs_pdf_cdf1d self);

// --- Get, const
extern_c Handle2ConstPdf
Xs_pdf_cdf1dPdfGetConst(ConstHandle2ConstXs_pdf_cdf1d self);

// +++ Get, non-const
extern_c Handle2Pdf
Xs_pdf_cdf1dPdfGet(ConstHandle2Xs_pdf_cdf1d self);

// +++ Set
extern_c void
Xs_pdf_cdf1dPdfSet(ConstHandle2Xs_pdf_cdf1d self, ConstHandle2ConstPdf pdf);


// -----------------------------------------------------------------------------
// Child: cdf_in_xs_pdf_cdf1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Xs_pdf_cdf1dCdf_in_xs_pdf_cdf1dHas(ConstHandle2ConstXs_pdf_cdf1d self);

// --- Get, const
extern_c Handle2ConstCdf_in_xs_pdf_cdf1d
Xs_pdf_cdf1dCdf_in_xs_pdf_cdf1dGetConst(ConstHandle2ConstXs_pdf_cdf1d self);

// +++ Get, non-const
extern_c Handle2Cdf_in_xs_pdf_cdf1d
Xs_pdf_cdf1dCdf_in_xs_pdf_cdf1dGet(ConstHandle2Xs_pdf_cdf1d self);

// +++ Set
extern_c void
Xs_pdf_cdf1dCdf_in_xs_pdf_cdf1dSet(ConstHandle2Xs_pdf_cdf1d self, ConstHandle2ConstCdf_in_xs_pdf_cdf1d cdf_in_xs_pdf_cdf1d);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/containers/Xs_pdf_cdf1d/src/custom.h"

#undef extern_c
#endif
