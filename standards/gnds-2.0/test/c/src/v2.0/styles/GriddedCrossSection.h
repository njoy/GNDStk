
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
// GriddedCrossSection is the basic handle type in this file. Example:
//    // Create a default GriddedCrossSection object:
//    GriddedCrossSection handle = GriddedCrossSectionDefault();
// Functions involving GriddedCrossSection are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_STYLES_GRIDDEDCROSSSECTION
#define C_INTERFACE_TEST_V2_0_STYLES_GRIDDEDCROSSSECTION

#include "GNDStk.h"
#include "v2.0/containers/Grid.h"
#include "v2.0/documentation/Documentation.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct GriddedCrossSectionClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ GriddedCrossSection
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct GriddedCrossSectionClass *GriddedCrossSection;

// --- Const-aware handles.
typedef const struct GriddedCrossSectionClass *const ConstHandle2ConstGriddedCrossSection;
typedef       struct GriddedCrossSectionClass *const ConstHandle2GriddedCrossSection;
typedef const struct GriddedCrossSectionClass *      Handle2ConstGriddedCrossSection;
typedef       struct GriddedCrossSectionClass *      Handle2GriddedCrossSection;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstGriddedCrossSection
GriddedCrossSectionDefaultConst();

// +++ Create, default
extern_c Handle2GriddedCrossSection
GriddedCrossSectionDefault();

// --- Create, general, const
extern_c Handle2ConstGriddedCrossSection
GriddedCrossSectionCreateConst(
   const char *const date,
   const XMLName derivedFrom,
   const XMLName label,
   ConstHandle2ConstGrid grid,
   ConstHandle2ConstDocumentation documentation
);

// +++ Create, general
extern_c Handle2GriddedCrossSection
GriddedCrossSectionCreate(
   const char *const date,
   const XMLName derivedFrom,
   const XMLName label,
   ConstHandle2ConstGrid grid,
   ConstHandle2ConstDocumentation documentation
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
GriddedCrossSectionAssign(ConstHandle2GriddedCrossSection This, ConstHandle2ConstGriddedCrossSection from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
GriddedCrossSectionDelete(ConstHandle2ConstGriddedCrossSection This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
GriddedCrossSectionRead(ConstHandle2GriddedCrossSection This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
GriddedCrossSectionWrite(ConstHandle2ConstGriddedCrossSection This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
GriddedCrossSectionPrint(ConstHandle2ConstGriddedCrossSection This);

// +++ Print to standard output, as XML
extern_c int
GriddedCrossSectionPrintXML(ConstHandle2ConstGriddedCrossSection This);

// +++ Print to standard output, as JSON
extern_c int
GriddedCrossSectionPrintJSON(ConstHandle2ConstGriddedCrossSection This);


// -----------------------------------------------------------------------------
// Metadatum: date
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
GriddedCrossSectionDateHas(ConstHandle2ConstGriddedCrossSection This);

// +++ Get
// +++ Returns by value
extern_c const char *
GriddedCrossSectionDateGet(ConstHandle2ConstGriddedCrossSection This);

// +++ Set
extern_c void
GriddedCrossSectionDateSet(ConstHandle2GriddedCrossSection This, const char *const date);


// -----------------------------------------------------------------------------
// Metadatum: derivedFrom
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
GriddedCrossSectionDerivedFromHas(ConstHandle2ConstGriddedCrossSection This);

// +++ Get
// +++ Returns by value
extern_c XMLName
GriddedCrossSectionDerivedFromGet(ConstHandle2ConstGriddedCrossSection This);

// +++ Set
extern_c void
GriddedCrossSectionDerivedFromSet(ConstHandle2GriddedCrossSection This, const XMLName derivedFrom);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
GriddedCrossSectionLabelHas(ConstHandle2ConstGriddedCrossSection This);

// +++ Get
// +++ Returns by value
extern_c XMLName
GriddedCrossSectionLabelGet(ConstHandle2ConstGriddedCrossSection This);

// +++ Set
extern_c void
GriddedCrossSectionLabelSet(ConstHandle2GriddedCrossSection This, const XMLName label);


// -----------------------------------------------------------------------------
// Child: grid
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
GriddedCrossSectionGridHas(ConstHandle2ConstGriddedCrossSection This);

// --- Get, const
extern_c Handle2ConstGrid
GriddedCrossSectionGridGetConst(ConstHandle2ConstGriddedCrossSection This);

// +++ Get, non-const
extern_c Handle2Grid
GriddedCrossSectionGridGet(ConstHandle2GriddedCrossSection This);

// +++ Set
extern_c void
GriddedCrossSectionGridSet(ConstHandle2GriddedCrossSection This, ConstHandle2ConstGrid grid);


// -----------------------------------------------------------------------------
// Child: documentation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
GriddedCrossSectionDocumentationHas(ConstHandle2ConstGriddedCrossSection This);

// --- Get, const
extern_c Handle2ConstDocumentation
GriddedCrossSectionDocumentationGetConst(ConstHandle2ConstGriddedCrossSection This);

// +++ Get, non-const
extern_c Handle2Documentation
GriddedCrossSectionDocumentationGet(ConstHandle2GriddedCrossSection This);

// +++ Set
extern_c void
GriddedCrossSectionDocumentationSet(ConstHandle2GriddedCrossSection This, ConstHandle2ConstDocumentation documentation);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
