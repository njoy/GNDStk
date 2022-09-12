
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
// CrossSection is the basic handle type in this file. Example:
//    // Create a default CrossSection object:
//    CrossSection handle = CrossSectionDefault();
// Functions involving CrossSection are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_TRANSPORT_CROSSSECTION
#define C_INTERFACE_TEST_V2_0_TRANSPORT_CROSSSECTION

#include "GNDStk.h"
#include "v2.0/containers/XYs1d.h"
#include "v2.0/containers/Regions1d.h"
#include "v2.0/transport/ResonancesWithBackground.h"
#include "v2.0/cpTransport/CoulombPlusNuclearElastic.h"
#include "v2.0/tsl/ThermalNeutronScatteringLaw1d.h"
#include "v2.0/transport/Reference.h"
#include "v2.0/containers/Gridded1d.h"
#include "v2.0/containers/Ys1d.h"
#include "v2.0/transport/URR_probabilityTables1d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct CrossSectionClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ CrossSection
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct CrossSectionClass *CrossSection;

// --- Const-aware handles.
typedef const struct CrossSectionClass *const ConstHandle2ConstCrossSection;
typedef       struct CrossSectionClass *const ConstHandle2CrossSection;
typedef const struct CrossSectionClass *      Handle2ConstCrossSection;
typedef       struct CrossSectionClass *      Handle2CrossSection;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstCrossSection
CrossSectionDefaultConst();

// +++ Create, default
extern_c Handle2CrossSection
CrossSectionDefault();

// --- Create, general, const
extern_c Handle2ConstCrossSection
CrossSectionCreateConst(
   const XMLName label,
);

// +++ Create, general
extern_c Handle2CrossSection
CrossSectionCreate(
   const XMLName label,
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
CrossSectionAssign(ConstHandle2CrossSection This, ConstHandle2ConstCrossSection from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
CrossSectionDelete(ConstHandle2ConstCrossSection This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
CrossSectionRead(ConstHandle2CrossSection This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
CrossSectionWrite(ConstHandle2ConstCrossSection This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
CrossSectionPrint(ConstHandle2ConstCrossSection This);

// +++ Print to standard output, as XML
extern_c int
CrossSectionPrintXML(ConstHandle2ConstCrossSection This);

// +++ Print to standard output, as JSON
extern_c int
CrossSectionPrintJSON(ConstHandle2ConstCrossSection This);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CrossSectionLabelHas(ConstHandle2ConstCrossSection This);

// +++ Get
// +++ Returns by value
extern_c XMLName
CrossSectionLabelGet(ConstHandle2ConstCrossSection This);

// +++ Set
extern_c void
CrossSectionLabelSet(ConstHandle2CrossSection This, const XMLName label);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif