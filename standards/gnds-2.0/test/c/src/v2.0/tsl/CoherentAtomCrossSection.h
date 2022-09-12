
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
// CoherentAtomCrossSection is the basic handle type in this file. Example:
//    // Create a default CoherentAtomCrossSection object:
//    CoherentAtomCrossSection handle = CoherentAtomCrossSectionDefault();
// Functions involving CoherentAtomCrossSection are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_TSL_COHERENTATOMCROSSSECTION
#define C_INTERFACE_TEST_V2_0_TSL_COHERENTATOMCROSSSECTION

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct CoherentAtomCrossSectionClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ CoherentAtomCrossSection
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct CoherentAtomCrossSectionClass *CoherentAtomCrossSection;

// --- Const-aware handles.
typedef const struct CoherentAtomCrossSectionClass *const ConstHandle2ConstCoherentAtomCrossSection;
typedef       struct CoherentAtomCrossSectionClass *const ConstHandle2CoherentAtomCrossSection;
typedef const struct CoherentAtomCrossSectionClass *      Handle2ConstCoherentAtomCrossSection;
typedef       struct CoherentAtomCrossSectionClass *      Handle2CoherentAtomCrossSection;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstCoherentAtomCrossSection
CoherentAtomCrossSectionDefaultConst();

// +++ Create, default
extern_c Handle2CoherentAtomCrossSection
CoherentAtomCrossSectionDefault();

// --- Create, general, const
extern_c Handle2ConstCoherentAtomCrossSection
CoherentAtomCrossSectionCreateConst(
   const XMLName unit,
   const Float64 value
);

// +++ Create, general
extern_c Handle2CoherentAtomCrossSection
CoherentAtomCrossSectionCreate(
   const XMLName unit,
   const Float64 value
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
CoherentAtomCrossSectionAssign(ConstHandle2CoherentAtomCrossSection This, ConstHandle2ConstCoherentAtomCrossSection from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
CoherentAtomCrossSectionDelete(ConstHandle2ConstCoherentAtomCrossSection This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
CoherentAtomCrossSectionRead(ConstHandle2CoherentAtomCrossSection This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
CoherentAtomCrossSectionWrite(ConstHandle2ConstCoherentAtomCrossSection This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
CoherentAtomCrossSectionPrint(ConstHandle2ConstCoherentAtomCrossSection This);

// +++ Print to standard output, as XML
extern_c int
CoherentAtomCrossSectionPrintXML(ConstHandle2ConstCoherentAtomCrossSection This);

// +++ Print to standard output, as JSON
extern_c int
CoherentAtomCrossSectionPrintJSON(ConstHandle2ConstCoherentAtomCrossSection This);


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CoherentAtomCrossSectionUnitHas(ConstHandle2ConstCoherentAtomCrossSection This);

// +++ Get
// +++ Returns by value
extern_c XMLName
CoherentAtomCrossSectionUnitGet(ConstHandle2ConstCoherentAtomCrossSection This);

// +++ Set
extern_c void
CoherentAtomCrossSectionUnitSet(ConstHandle2CoherentAtomCrossSection This, const XMLName unit);


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CoherentAtomCrossSectionValueHas(ConstHandle2ConstCoherentAtomCrossSection This);

// +++ Get
// +++ Returns by value
extern_c Float64
CoherentAtomCrossSectionValueGet(ConstHandle2ConstCoherentAtomCrossSection This);

// +++ Set
extern_c void
CoherentAtomCrossSectionValueSet(ConstHandle2CoherentAtomCrossSection This, const Float64 value);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif