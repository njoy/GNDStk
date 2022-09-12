
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
// Production is the basic handle type in this file. Example:
//    // Create a default Production object:
//    Production handle = ProductionDefault();
// Functions involving Production are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_TRANSPORT_PRODUCTION
#define C_INTERFACE_TEST_V2_0_TRANSPORT_PRODUCTION

#include "GNDStk.h"
#include "v2.0/transport/CrossSection.h"
#include "v2.0/transport/OutputChannel.h"

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

// +++ Create, default
extern_c Handle2Production
ProductionDefault();

// --- Create, general, const
extern_c Handle2ConstProduction
ProductionCreateConst(
   const Integer32 ENDF_MT,
   const XMLName label,
   ConstHandle2ConstCrossSection crossSection,
   ConstHandle2ConstOutputChannel outputChannel
);

// +++ Create, general
extern_c Handle2Production
ProductionCreate(
   const Integer32 ENDF_MT,
   const XMLName label,
   ConstHandle2ConstCrossSection crossSection,
   ConstHandle2ConstOutputChannel outputChannel
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ProductionAssign(ConstHandle2Production This, ConstHandle2ConstProduction from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ProductionDelete(ConstHandle2ConstProduction This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ProductionRead(ConstHandle2Production This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ProductionWrite(ConstHandle2ConstProduction This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ProductionPrint(ConstHandle2ConstProduction This);

// +++ Print to standard output, as XML
extern_c int
ProductionPrintXML(ConstHandle2ConstProduction This);

// +++ Print to standard output, as JSON
extern_c int
ProductionPrintJSON(ConstHandle2ConstProduction This);


// -----------------------------------------------------------------------------
// Metadatum: ENDF_MT
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ProductionENDFMTHas(ConstHandle2ConstProduction This);

// +++ Get
// +++ Returns by value
extern_c Integer32
ProductionENDFMTGet(ConstHandle2ConstProduction This);

// +++ Set
extern_c void
ProductionENDFMTSet(ConstHandle2Production This, const Integer32 ENDF_MT);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ProductionLabelHas(ConstHandle2ConstProduction This);

// +++ Get
// +++ Returns by value
extern_c XMLName
ProductionLabelGet(ConstHandle2ConstProduction This);

// +++ Set
extern_c void
ProductionLabelSet(ConstHandle2Production This, const XMLName label);


// -----------------------------------------------------------------------------
// Child: crossSection
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ProductionCrossSectionHas(ConstHandle2ConstProduction This);

// --- Get, const
extern_c Handle2ConstCrossSection
ProductionCrossSectionGetConst(ConstHandle2ConstProduction This);

// +++ Get, non-const
extern_c Handle2CrossSection
ProductionCrossSectionGet(ConstHandle2Production This);

// +++ Set
extern_c void
ProductionCrossSectionSet(ConstHandle2Production This, ConstHandle2ConstCrossSection crossSection);


// -----------------------------------------------------------------------------
// Child: outputChannel
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ProductionOutputChannelHas(ConstHandle2ConstProduction This);

// --- Get, const
extern_c Handle2ConstOutputChannel
ProductionOutputChannelGetConst(ConstHandle2ConstProduction This);

// +++ Get, non-const
extern_c Handle2OutputChannel
ProductionOutputChannelGet(ConstHandle2Production This);

// +++ Set
extern_c void
ProductionOutputChannelSet(ConstHandle2Production This, ConstHandle2ConstOutputChannel outputChannel);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif