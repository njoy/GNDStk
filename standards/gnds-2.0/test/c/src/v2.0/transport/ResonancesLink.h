
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
// ResonancesLink is the basic handle type in this file. Example:
//    // Create a default ResonancesLink object:
//    ResonancesLink handle = ResonancesLinkDefault();
// Functions involving ResonancesLink are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_TRANSPORT_RESONANCESLINK
#define C_INTERFACE_TEST_V2_0_TRANSPORT_RESONANCESLINK

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ResonancesLinkClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ResonancesLink
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ResonancesLinkClass *ResonancesLink;

// --- Const-aware handles.
typedef const struct ResonancesLinkClass *const ConstHandle2ConstResonancesLink;
typedef       struct ResonancesLinkClass *const ConstHandle2ResonancesLink;
typedef const struct ResonancesLinkClass *      Handle2ConstResonancesLink;
typedef       struct ResonancesLinkClass *      Handle2ResonancesLink;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstResonancesLink
ResonancesLinkDefaultConst();

// +++ Create, default
extern_c Handle2ResonancesLink
ResonancesLinkDefault();

// --- Create, general, const
extern_c Handle2ConstResonancesLink
ResonancesLinkCreateConst(
   const XMLName label,
   const char *const href
);

// +++ Create, general
extern_c Handle2ResonancesLink
ResonancesLinkCreate(
   const XMLName label,
   const char *const href
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ResonancesLinkAssign(ConstHandle2ResonancesLink This, ConstHandle2ConstResonancesLink from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ResonancesLinkDelete(ConstHandle2ConstResonancesLink This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ResonancesLinkRead(ConstHandle2ResonancesLink This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ResonancesLinkWrite(ConstHandle2ConstResonancesLink This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ResonancesLinkPrint(ConstHandle2ConstResonancesLink This);

// +++ Print to standard output, as XML
extern_c int
ResonancesLinkPrintXML(ConstHandle2ConstResonancesLink This);

// +++ Print to standard output, as JSON
extern_c int
ResonancesLinkPrintJSON(ConstHandle2ConstResonancesLink This);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ResonancesLinkLabelHas(ConstHandle2ConstResonancesLink This);

// +++ Get
// +++ Returns by value
extern_c XMLName
ResonancesLinkLabelGet(ConstHandle2ConstResonancesLink This);

// +++ Set
extern_c void
ResonancesLinkLabelSet(ConstHandle2ResonancesLink This, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ResonancesLinkHrefHas(ConstHandle2ConstResonancesLink This);

// +++ Get
// +++ Returns by value
extern_c const char *
ResonancesLinkHrefGet(ConstHandle2ConstResonancesLink This);

// +++ Set
extern_c void
ResonancesLinkHrefSet(ConstHandle2ResonancesLink This, const char *const href);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
