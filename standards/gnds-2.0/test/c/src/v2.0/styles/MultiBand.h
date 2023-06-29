
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
// MultiBand is the basic handle type in this file. Example:
//    // Create a default MultiBand object:
//    MultiBand handle = MultiBandDefault();
// Functions involving MultiBand are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_STYLES_MULTIBAND
#define C_INTERFACE_TEST_V2_0_STYLES_MULTIBAND

#include "GNDStk.h"
#include "v2.0/documentation/Documentation.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct MultiBandClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ MultiBand
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct MultiBandClass *MultiBand;

// --- Const-aware handles.
typedef const struct MultiBandClass *const ConstHandle2ConstMultiBand;
typedef       struct MultiBandClass *const ConstHandle2MultiBand;
typedef const struct MultiBandClass *      Handle2ConstMultiBand;
typedef       struct MultiBandClass *      Handle2MultiBand;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstMultiBand
MultiBandDefaultConst();

// +++ Create, default
extern_c Handle2MultiBand
MultiBandDefault();

// --- Create, general, const
extern_c Handle2ConstMultiBand
MultiBandCreateConst(
   const char *const date,
   const XMLName derivedFrom,
   const XMLName label,
   const Integer32 numberOfBands,
   ConstHandle2ConstDocumentation documentation
);

// +++ Create, general
extern_c Handle2MultiBand
MultiBandCreate(
   const char *const date,
   const XMLName derivedFrom,
   const XMLName label,
   const Integer32 numberOfBands,
   ConstHandle2ConstDocumentation documentation
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
MultiBandAssign(ConstHandle2MultiBand self, ConstHandle2ConstMultiBand from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
MultiBandDelete(ConstHandle2ConstMultiBand self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
MultiBandRead(ConstHandle2MultiBand self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
MultiBandWrite(ConstHandle2ConstMultiBand self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
MultiBandPrint(ConstHandle2ConstMultiBand self);

// +++ Print to standard output, as XML
extern_c int
MultiBandPrintXML(ConstHandle2ConstMultiBand self);

// +++ Print to standard output, as JSON
extern_c int
MultiBandPrintJSON(ConstHandle2ConstMultiBand self);


// -----------------------------------------------------------------------------
// Metadatum: date
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MultiBandDateHas(ConstHandle2ConstMultiBand self);

// +++ Get
// +++ Returns by value
extern_c const char *
MultiBandDateGet(ConstHandle2ConstMultiBand self);

// +++ Set
extern_c void
MultiBandDateSet(ConstHandle2MultiBand self, const char *const date);


// -----------------------------------------------------------------------------
// Metadatum: derivedFrom
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MultiBandDerivedFromHas(ConstHandle2ConstMultiBand self);

// +++ Get
// +++ Returns by value
extern_c XMLName
MultiBandDerivedFromGet(ConstHandle2ConstMultiBand self);

// +++ Set
extern_c void
MultiBandDerivedFromSet(ConstHandle2MultiBand self, const XMLName derivedFrom);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MultiBandLabelHas(ConstHandle2ConstMultiBand self);

// +++ Get
// +++ Returns by value
extern_c XMLName
MultiBandLabelGet(ConstHandle2ConstMultiBand self);

// +++ Set
extern_c void
MultiBandLabelSet(ConstHandle2MultiBand self, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: numberOfBands
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MultiBandNumberOfBandsHas(ConstHandle2ConstMultiBand self);

// +++ Get
// +++ Returns by value
extern_c Integer32
MultiBandNumberOfBandsGet(ConstHandle2ConstMultiBand self);

// +++ Set
extern_c void
MultiBandNumberOfBandsSet(ConstHandle2MultiBand self, const Integer32 numberOfBands);


// -----------------------------------------------------------------------------
// Child: documentation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MultiBandDocumentationHas(ConstHandle2ConstMultiBand self);

// --- Get, const
extern_c Handle2ConstDocumentation
MultiBandDocumentationGetConst(ConstHandle2ConstMultiBand self);

// +++ Get, non-const
extern_c Handle2Documentation
MultiBandDocumentationGet(ConstHandle2MultiBand self);

// +++ Set
extern_c void
MultiBandDocumentationSet(ConstHandle2MultiBand self, ConstHandle2ConstDocumentation documentation);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/styles/MultiBand/src/custom.h"

#undef extern_c
#endif
