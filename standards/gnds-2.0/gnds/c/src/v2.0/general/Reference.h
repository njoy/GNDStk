
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
// Reference is the basic handle type in this file. Example:
//    // Create a default Reference object:
//    Reference handle = ReferenceDefault();
// Functions involving Reference are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_REFERENCE
#define C_INTERFACE_GNDS_V2_0_GENERAL_REFERENCE

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ReferenceClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Reference
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ReferenceClass *Reference;

// --- Const-aware handles.
typedef const struct ReferenceClass *const ConstHandle2ConstReference;
typedef       struct ReferenceClass *const ConstHandle2Reference;
typedef const struct ReferenceClass *      Handle2ConstReference;
typedef       struct ReferenceClass *      Handle2Reference;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstReference
ReferenceDefaultConst();

// +++ Create, default
extern_c Handle2Reference
ReferenceDefault();

// --- Create, general, const
extern_c Handle2ConstReference
ReferenceCreateConst(
   const char *const label,
   const char *const href
);

// +++ Create, general
extern_c Handle2Reference
ReferenceCreate(
   const char *const label,
   const char *const href
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ReferenceAssign(ConstHandle2Reference self, ConstHandle2ConstReference from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ReferenceDelete(ConstHandle2ConstReference self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ReferenceRead(ConstHandle2Reference self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ReferenceWrite(ConstHandle2ConstReference self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ReferencePrint(ConstHandle2ConstReference self);

// +++ Print to standard output, as XML
extern_c int
ReferencePrintXML(ConstHandle2ConstReference self);

// +++ Print to standard output, as JSON
extern_c int
ReferencePrintJSON(ConstHandle2ConstReference self);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ReferenceLabelHas(ConstHandle2ConstReference self);

// +++ Get
// +++ Returns by value
extern_c const char *
ReferenceLabelGet(ConstHandle2ConstReference self);

// +++ Set
extern_c void
ReferenceLabelSet(ConstHandle2Reference self, const char *const label);


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ReferenceHrefHas(ConstHandle2ConstReference self);

// +++ Get
// +++ Returns by value
extern_c const char *
ReferenceHrefGet(ConstHandle2ConstReference self);

// +++ Set
extern_c void
ReferenceHrefSet(ConstHandle2Reference self, const char *const href);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Reference/src/custom.h"

#undef extern_c
#endif
