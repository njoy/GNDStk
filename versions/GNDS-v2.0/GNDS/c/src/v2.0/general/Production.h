
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
// Production is the basic handle type in this file. Example:
//    // Create a default Production object:
//    Production handle = ProductionDefault();
// Functions involving Production are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_PRODUCTION
#define C_INTERFACE_GNDS_V2_0_GENERAL_PRODUCTION

#include "GNDStk.h"
#include "v2.0/general/CrossSection.h"
#include "v2.0/general/OutputChannel.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ProductionClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Production
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ProductionClass *Production;

// --- Const-aware handles.
typedef const struct ProductionClass *const ConstHandle2ConstProduction;
typedef       struct ProductionClass *const ConstHandle2Production;
typedef const struct ProductionClass *      Handle2ConstProduction;
typedef       struct ProductionClass *      Handle2Production;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstProduction
ProductionDefaultConst();

// +++ Create, default, non-const
extern_c Handle2Production
ProductionDefault();

// --- Create, general, const
extern_c Handle2ConstProduction
ProductionCreateConst(
   const char *const label,
   const int ENDF_MT,
   ConstHandle2ConstCrossSection crossSection,
   ConstHandle2ConstOutputChannel outputChannel
);

// +++ Create, general, non-const
extern_c Handle2Production
ProductionCreate(
   const char *const label,
   const int ENDF_MT,
   ConstHandle2ConstCrossSection crossSection,
   ConstHandle2ConstOutputChannel outputChannel
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ProductionAssign(ConstHandle2Production self, ConstHandle2ConstProduction from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ProductionDelete(ConstHandle2ConstProduction self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ProductionRead(ConstHandle2Production self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ProductionWrite(ConstHandle2ConstProduction self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ProductionPrint(ConstHandle2ConstProduction self);

// +++ Print to standard output, as XML
extern_c int
ProductionPrintXML(ConstHandle2ConstProduction self);

// +++ Print to standard output, as JSON
extern_c int
ProductionPrintJSON(ConstHandle2ConstProduction self);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ProductionLabelHas(ConstHandle2ConstProduction self);

// +++ Get
// +++ Returns by value
extern_c const char *
ProductionLabelGet(ConstHandle2ConstProduction self);

// +++ Set
extern_c void
ProductionLabelSet(ConstHandle2Production self, const char *const label);


// -----------------------------------------------------------------------------
// Metadatum: ENDF_MT
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ProductionENDFMTHas(ConstHandle2ConstProduction self);

// +++ Get
// +++ Returns by value
extern_c int
ProductionENDFMTGet(ConstHandle2ConstProduction self);

// +++ Set
extern_c void
ProductionENDFMTSet(ConstHandle2Production self, const int ENDF_MT);


// -----------------------------------------------------------------------------
// Child: crossSection
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ProductionCrossSectionHas(ConstHandle2ConstProduction self);

// --- Get, const
extern_c Handle2ConstCrossSection
ProductionCrossSectionGetConst(ConstHandle2ConstProduction self);

// +++ Get, non-const
extern_c Handle2CrossSection
ProductionCrossSectionGet(ConstHandle2Production self);

// +++ Set
extern_c void
ProductionCrossSectionSet(ConstHandle2Production self, ConstHandle2ConstCrossSection crossSection);


// -----------------------------------------------------------------------------
// Child: outputChannel
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ProductionOutputChannelHas(ConstHandle2ConstProduction self);

// --- Get, const
extern_c Handle2ConstOutputChannel
ProductionOutputChannelGetConst(ConstHandle2ConstProduction self);

// +++ Get, non-const
extern_c Handle2OutputChannel
ProductionOutputChannelGet(ConstHandle2Production self);

// +++ Set
extern_c void
ProductionOutputChannelSet(ConstHandle2Production self, ConstHandle2ConstOutputChannel outputChannel);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Production/src/custom.h"

#undef extern_c
#endif
