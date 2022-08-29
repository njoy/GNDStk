
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
// Bibliography is the basic handle type in this file. Example:
//    // Create a default Bibliography object:
//    Bibliography handle = BibliographyDefault();
// Functions involving Bibliography are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_DOCUMENTATION_BIBLIOGRAPHY
#define C_INTERFACE_TRY_V2_0_DOCUMENTATION_BIBLIOGRAPHY

#include "GNDStk.h"
#include "v2.0/documentation/Bibitem.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct BibliographyClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Bibliography
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct BibliographyClass *Bibliography;

// --- Const-aware handles.
typedef const struct BibliographyClass *const ConstHandle2ConstBibliography;
typedef       struct BibliographyClass *const ConstHandle2Bibliography;
typedef const struct BibliographyClass *      Handle2ConstBibliography;
typedef       struct BibliographyClass *      Handle2Bibliography;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstBibliography
BibliographyDefaultConst();

// +++ Create, default
extern_c Handle2Bibliography
BibliographyDefault();

// --- Create, general, const
extern_c Handle2ConstBibliography
BibliographyCreateConst(
   ConstHandle2Bibitem *const bibitem, const size_t bibitemSize
);

// +++ Create, general
extern_c Handle2Bibliography
BibliographyCreate(
   ConstHandle2Bibitem *const bibitem, const size_t bibitemSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
BibliographyAssign(ConstHandle2Bibliography This, ConstHandle2ConstBibliography from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
BibliographyDelete(ConstHandle2ConstBibliography This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
BibliographyRead(ConstHandle2Bibliography This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
BibliographyWrite(ConstHandle2ConstBibliography This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
BibliographyPrint(ConstHandle2ConstBibliography This);

// +++ Print to standard output, as XML
extern_c int
BibliographyPrintXML(ConstHandle2ConstBibliography This);

// +++ Print to standard output, as JSON
extern_c int
BibliographyPrintJSON(ConstHandle2ConstBibliography This);


// -----------------------------------------------------------------------------
// Child: bibitem
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BibliographyBibitemHas(ConstHandle2ConstBibliography This);

// +++ Clear
extern_c void
BibliographyBibitemClear(ConstHandle2Bibliography This);

// +++ Size
extern_c size_t
BibliographyBibitemSize(ConstHandle2ConstBibliography This);

// +++ Add
extern_c void
BibliographyBibitemAdd(ConstHandle2Bibliography This, ConstHandle2ConstBibitem bibitem);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstBibitem
BibliographyBibitemGetConst(ConstHandle2ConstBibliography This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Bibitem
BibliographyBibitemGet(ConstHandle2Bibliography This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
BibliographyBibitemSet(
   ConstHandle2Bibliography This,
   const size_t index_,
   ConstHandle2ConstBibitem bibitem
);

// +++ Has, by encoding
extern_c int
BibliographyBibitemHasByEncoding(
   ConstHandle2ConstBibliography This,
   const XMLName encoding
);

// --- Get, by encoding, const
extern_c Handle2ConstBibitem
BibliographyBibitemGetByEncodingConst(
   ConstHandle2ConstBibliography This,
   const XMLName encoding
);

// +++ Get, by encoding, non-const
extern_c Handle2Bibitem
BibliographyBibitemGetByEncoding(
   ConstHandle2Bibliography This,
   const XMLName encoding
);

// +++ Set, by encoding
extern_c void
BibliographyBibitemSetByEncoding(
   ConstHandle2Bibliography This,
   const XMLName encoding,
   ConstHandle2ConstBibitem bibitem
);

// +++ Has, by markup
extern_c int
BibliographyBibitemHasByMarkup(
   ConstHandle2ConstBibliography This,
   const char *const markup
);

// --- Get, by markup, const
extern_c Handle2ConstBibitem
BibliographyBibitemGetByMarkupConst(
   ConstHandle2ConstBibliography This,
   const char *const markup
);

// +++ Get, by markup, non-const
extern_c Handle2Bibitem
BibliographyBibitemGetByMarkup(
   ConstHandle2Bibliography This,
   const char *const markup
);

// +++ Set, by markup
extern_c void
BibliographyBibitemSetByMarkup(
   ConstHandle2Bibliography This,
   const char *const markup,
   ConstHandle2ConstBibitem bibitem
);

// +++ Has, by label
extern_c int
BibliographyBibitemHasByLabel(
   ConstHandle2ConstBibliography This,
   const XMLName label
);

// --- Get, by label, const
extern_c Handle2ConstBibitem
BibliographyBibitemGetByLabelConst(
   ConstHandle2ConstBibliography This,
   const XMLName label
);

// +++ Get, by label, non-const
extern_c Handle2Bibitem
BibliographyBibitemGetByLabel(
   ConstHandle2Bibliography This,
   const XMLName label
);

// +++ Set, by label
extern_c void
BibliographyBibitemSetByLabel(
   ConstHandle2Bibliography This,
   const XMLName label,
   ConstHandle2ConstBibitem bibitem
);

// +++ Has, by xref
extern_c int
BibliographyBibitemHasByXref(
   ConstHandle2ConstBibliography This,
   const XMLName xref
);

// --- Get, by xref, const
extern_c Handle2ConstBibitem
BibliographyBibitemGetByXrefConst(
   ConstHandle2ConstBibliography This,
   const XMLName xref
);

// +++ Get, by xref, non-const
extern_c Handle2Bibitem
BibliographyBibitemGetByXref(
   ConstHandle2Bibliography This,
   const XMLName xref
);

// +++ Set, by xref
extern_c void
BibliographyBibitemSetByXref(
   ConstHandle2Bibliography This,
   const XMLName xref,
   ConstHandle2ConstBibitem bibitem
);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
