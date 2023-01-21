
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
// Pdf is the basic handle type in this file. Example:
//    // Create a default Pdf object:
//    Pdf handle = PdfDefault();
// Functions involving Pdf are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_POPS_PDF
#define C_INTERFACE_TEST_V2_0_POPS_PDF

#include "GNDStk.h"
#include "v2.0/containers/XYs1d.h"
#include "v2.0/containers/Regions1d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct PdfClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Pdf
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct PdfClass *Pdf;

// --- Const-aware handles.
typedef const struct PdfClass *const ConstHandle2ConstPdf;
typedef       struct PdfClass *const ConstHandle2Pdf;
typedef const struct PdfClass *      Handle2ConstPdf;
typedef       struct PdfClass *      Handle2Pdf;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstPdf
PdfDefaultConst();

// +++ Create, default
extern_c Handle2Pdf
PdfDefault();

// --- Create, general, const
extern_c Handle2ConstPdf
PdfCreateConst(
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstRegions1d regions1d
);

// +++ Create, general
extern_c Handle2Pdf
PdfCreate(
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstRegions1d regions1d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
PdfAssign(ConstHandle2Pdf This, ConstHandle2ConstPdf from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
PdfDelete(ConstHandle2ConstPdf This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
PdfRead(ConstHandle2Pdf This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
PdfWrite(ConstHandle2ConstPdf This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
PdfPrint(ConstHandle2ConstPdf This);

// +++ Print to standard output, as XML
extern_c int
PdfPrintXML(ConstHandle2ConstPdf This);

// +++ Print to standard output, as JSON
extern_c int
PdfPrintJSON(ConstHandle2ConstPdf This);


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
PdfXYs1dHas(ConstHandle2ConstPdf This);

// --- Get, const
extern_c Handle2ConstXYs1d
PdfXYs1dGetConst(ConstHandle2ConstPdf This);

// +++ Get, non-const
extern_c Handle2XYs1d
PdfXYs1dGet(ConstHandle2Pdf This);

// +++ Set
extern_c void
PdfXYs1dSet(ConstHandle2Pdf This, ConstHandle2ConstXYs1d XYs1d);


// -----------------------------------------------------------------------------
// Child: regions1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
PdfRegions1dHas(ConstHandle2ConstPdf This);

// --- Get, const
extern_c Handle2ConstRegions1d
PdfRegions1dGetConst(ConstHandle2ConstPdf This);

// +++ Get, non-const
extern_c Handle2Regions1d
PdfRegions1dGet(ConstHandle2Pdf This);

// +++ Set
extern_c void
PdfRegions1dSet(ConstHandle2Pdf This, ConstHandle2ConstRegions1d regions1d);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/pops/Pdf/src/custom.h"

#undef extern_c
#endif
