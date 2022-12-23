
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
// Link is the basic handle type in this file. Example:
//    // Create a default Link object:
//    Link handle = LinkDefault();
// Functions involving Link are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_CONTAINERS_LINK
#define C_INTERFACE_TEST_V2_0_CONTAINERS_LINK

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct LinkClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Link
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct LinkClass *Link;

// --- Const-aware handles.
typedef const struct LinkClass *const ConstHandle2ConstLink;
typedef       struct LinkClass *const ConstHandle2Link;
typedef const struct LinkClass *      Handle2ConstLink;
typedef       struct LinkClass *      Handle2Link;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstLink
LinkDefaultConst();

// +++ Create, default
extern_c Handle2Link
LinkDefault();

// --- Create, general, const
extern_c Handle2ConstLink
LinkCreateConst(
   const char *const href
);

// +++ Create, general
extern_c Handle2Link
LinkCreate(
   const char *const href
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
LinkAssign(ConstHandle2Link This, ConstHandle2ConstLink from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
LinkDelete(ConstHandle2ConstLink This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
LinkRead(ConstHandle2Link This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
LinkWrite(ConstHandle2ConstLink This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
LinkPrint(ConstHandle2ConstLink This);

// +++ Print to standard output, as XML
extern_c int
LinkPrintXML(ConstHandle2ConstLink This);

// +++ Print to standard output, as JSON
extern_c int
LinkPrintJSON(ConstHandle2ConstLink This);


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
LinkHrefHas(ConstHandle2ConstLink This);

// +++ Get
// +++ Returns by value
extern_c const char *
LinkHrefGet(ConstHandle2ConstLink This);

// +++ Set
extern_c void
LinkHrefSet(ConstHandle2Link This, const char *const href);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
