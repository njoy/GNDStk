
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
// OrphanProduct is the basic handle type in this file. Example:
//    // Create a default OrphanProduct object:
//    OrphanProduct handle = OrphanProductDefault();
// Functions involving OrphanProduct are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_ORPHANPRODUCT
#define C_INTERFACE_ALPHA_V2_0_GENERAL_ORPHANPRODUCT

#include "GNDStk.h"
#include "v2.0/general/CrossSection.h"
#include "v2.0/general/OutputChannel.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct OrphanProductClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ OrphanProduct
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct OrphanProductClass *OrphanProduct;

// --- Const-aware handles.
typedef const struct OrphanProductClass *const ConstHandle2ConstOrphanProduct;
typedef       struct OrphanProductClass *const ConstHandle2OrphanProduct;
typedef const struct OrphanProductClass *      Handle2ConstOrphanProduct;
typedef       struct OrphanProductClass *      Handle2OrphanProduct;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstOrphanProduct
OrphanProductDefaultConst();

// +++ Create, default
extern_c Handle2OrphanProduct
OrphanProductDefault();

// --- Create, general, const
extern_c Handle2ConstOrphanProduct
OrphanProductCreateConst(
   const char *const label,
   const int ENDF_MT,
   ConstHandle2ConstCrossSection crossSection,
   ConstHandle2ConstOutputChannel outputChannel
);

// +++ Create, general
extern_c Handle2OrphanProduct
OrphanProductCreate(
   const char *const label,
   const int ENDF_MT,
   ConstHandle2ConstCrossSection crossSection,
   ConstHandle2ConstOutputChannel outputChannel
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
OrphanProductAssign(ConstHandle2OrphanProduct self, ConstHandle2ConstOrphanProduct from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
OrphanProductDelete(ConstHandle2ConstOrphanProduct self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
OrphanProductRead(ConstHandle2OrphanProduct self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
OrphanProductWrite(ConstHandle2ConstOrphanProduct self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
OrphanProductPrint(ConstHandle2ConstOrphanProduct self);

// +++ Print to standard output, as XML
extern_c int
OrphanProductPrintXML(ConstHandle2ConstOrphanProduct self);

// +++ Print to standard output, as JSON
extern_c int
OrphanProductPrintJSON(ConstHandle2ConstOrphanProduct self);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
OrphanProductLabelHas(ConstHandle2ConstOrphanProduct self);

// +++ Get
// +++ Returns by value
extern_c const char *
OrphanProductLabelGet(ConstHandle2ConstOrphanProduct self);

// +++ Set
extern_c void
OrphanProductLabelSet(ConstHandle2OrphanProduct self, const char *const label);


// -----------------------------------------------------------------------------
// Metadatum: ENDF_MT
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
OrphanProductENDFMTHas(ConstHandle2ConstOrphanProduct self);

// +++ Get
// +++ Returns by value
extern_c int
OrphanProductENDFMTGet(ConstHandle2ConstOrphanProduct self);

// +++ Set
extern_c void
OrphanProductENDFMTSet(ConstHandle2OrphanProduct self, const int ENDF_MT);


// -----------------------------------------------------------------------------
// Child: crossSection
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
OrphanProductCrossSectionHas(ConstHandle2ConstOrphanProduct self);

// --- Get, const
extern_c Handle2ConstCrossSection
OrphanProductCrossSectionGetConst(ConstHandle2ConstOrphanProduct self);

// +++ Get, non-const
extern_c Handle2CrossSection
OrphanProductCrossSectionGet(ConstHandle2OrphanProduct self);

// +++ Set
extern_c void
OrphanProductCrossSectionSet(ConstHandle2OrphanProduct self, ConstHandle2ConstCrossSection crossSection);


// -----------------------------------------------------------------------------
// Child: outputChannel
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
OrphanProductOutputChannelHas(ConstHandle2ConstOrphanProduct self);

// --- Get, const
extern_c Handle2ConstOutputChannel
OrphanProductOutputChannelGetConst(ConstHandle2ConstOrphanProduct self);

// +++ Get, non-const
extern_c Handle2OutputChannel
OrphanProductOutputChannelGet(ConstHandle2OrphanProduct self);

// +++ Set
extern_c void
OrphanProductOutputChannelSet(ConstHandle2OrphanProduct self, ConstHandle2ConstOutputChannel outputChannel);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/OrphanProduct/src/custom.h"

#undef extern_c
#endif
