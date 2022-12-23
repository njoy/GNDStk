
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
// Pdf_in_xs_pdf_cdf1d is the basic handle type in this file. Example:
//    // Create a default Pdf_in_xs_pdf_cdf1d object:
//    Pdf_in_xs_pdf_cdf1d handle = Pdf_in_xs_pdf_cdf1dDefault();
// Functions involving Pdf_in_xs_pdf_cdf1d are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_CONTAINERS_PDF_IN_XS_PDF_CDF1D
#define C_INTERFACE_TEST_V2_0_CONTAINERS_PDF_IN_XS_PDF_CDF1D

#include "GNDStk.h"
#include "v2.0/containers/Values.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct Pdf_in_xs_pdf_cdf1dClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Pdf_in_xs_pdf_cdf1d
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct Pdf_in_xs_pdf_cdf1dClass *Pdf_in_xs_pdf_cdf1d;

// --- Const-aware handles.
typedef const struct Pdf_in_xs_pdf_cdf1dClass *const ConstHandle2ConstPdf_in_xs_pdf_cdf1d;
typedef       struct Pdf_in_xs_pdf_cdf1dClass *const ConstHandle2Pdf_in_xs_pdf_cdf1d;
typedef const struct Pdf_in_xs_pdf_cdf1dClass *      Handle2ConstPdf_in_xs_pdf_cdf1d;
typedef       struct Pdf_in_xs_pdf_cdf1dClass *      Handle2Pdf_in_xs_pdf_cdf1d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstPdf_in_xs_pdf_cdf1d
Pdf_in_xs_pdf_cdf1dDefaultConst();

// +++ Create, default
extern_c Handle2Pdf_in_xs_pdf_cdf1d
Pdf_in_xs_pdf_cdf1dDefault();

// --- Create, general, const
extern_c Handle2ConstPdf_in_xs_pdf_cdf1d
Pdf_in_xs_pdf_cdf1dCreateConst(
   ConstHandle2ConstValues values
);

// +++ Create, general
extern_c Handle2Pdf_in_xs_pdf_cdf1d
Pdf_in_xs_pdf_cdf1dCreate(
   ConstHandle2ConstValues values
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
Pdf_in_xs_pdf_cdf1dAssign(ConstHandle2Pdf_in_xs_pdf_cdf1d This, ConstHandle2ConstPdf_in_xs_pdf_cdf1d from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
Pdf_in_xs_pdf_cdf1dDelete(ConstHandle2ConstPdf_in_xs_pdf_cdf1d This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
Pdf_in_xs_pdf_cdf1dRead(ConstHandle2Pdf_in_xs_pdf_cdf1d This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
Pdf_in_xs_pdf_cdf1dWrite(ConstHandle2ConstPdf_in_xs_pdf_cdf1d This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
Pdf_in_xs_pdf_cdf1dPrint(ConstHandle2ConstPdf_in_xs_pdf_cdf1d This);

// +++ Print to standard output, as XML
extern_c int
Pdf_in_xs_pdf_cdf1dPrintXML(ConstHandle2ConstPdf_in_xs_pdf_cdf1d This);

// +++ Print to standard output, as JSON
extern_c int
Pdf_in_xs_pdf_cdf1dPrintJSON(ConstHandle2ConstPdf_in_xs_pdf_cdf1d This);


// -----------------------------------------------------------------------------
// Child: values
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
Pdf_in_xs_pdf_cdf1dValuesHas(ConstHandle2ConstPdf_in_xs_pdf_cdf1d This);

// --- Get, const
extern_c Handle2ConstValues
Pdf_in_xs_pdf_cdf1dValuesGetConst(ConstHandle2ConstPdf_in_xs_pdf_cdf1d This);

// +++ Get, non-const
extern_c Handle2Values
Pdf_in_xs_pdf_cdf1dValuesGet(ConstHandle2Pdf_in_xs_pdf_cdf1d This);

// +++ Set
extern_c void
Pdf_in_xs_pdf_cdf1dValuesSet(ConstHandle2Pdf_in_xs_pdf_cdf1d This, ConstHandle2ConstValues values);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
