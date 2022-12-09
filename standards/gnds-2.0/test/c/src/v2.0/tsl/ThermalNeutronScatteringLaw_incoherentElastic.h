
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
// ThermalNeutronScatteringLaw_incoherentElastic is the basic handle type in this file. Example:
//    // Create a default ThermalNeutronScatteringLaw_incoherentElastic object:
//    ThermalNeutronScatteringLaw_incoherentElastic handle = ThermalNeutronScatteringLaw_incoherentElasticDefault();
// Functions involving ThermalNeutronScatteringLaw_incoherentElastic are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_TSL_THERMALNEUTRONSCATTERINGLAW_INCOHERENTELASTIC
#define C_INTERFACE_TEST_V2_0_TSL_THERMALNEUTRONSCATTERINGLAW_INCOHERENTELASTIC

#include "GNDStk.h"
#include "v2.0/tsl/BoundAtomCrossSection.h"
#include "v2.0/tsl/DebyeWallerIntegral.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ThermalNeutronScatteringLaw_incoherentElasticClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ThermalNeutronScatteringLaw_incoherentElastic
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ThermalNeutronScatteringLaw_incoherentElasticClass *ThermalNeutronScatteringLaw_incoherentElastic;

// --- Const-aware handles.
typedef const struct ThermalNeutronScatteringLaw_incoherentElasticClass *const ConstHandle2ConstThermalNeutronScatteringLaw_incoherentElastic;
typedef       struct ThermalNeutronScatteringLaw_incoherentElasticClass *const ConstHandle2ThermalNeutronScatteringLaw_incoherentElastic;
typedef const struct ThermalNeutronScatteringLaw_incoherentElasticClass *      Handle2ConstThermalNeutronScatteringLaw_incoherentElastic;
typedef       struct ThermalNeutronScatteringLaw_incoherentElasticClass *      Handle2ThermalNeutronScatteringLaw_incoherentElastic;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstThermalNeutronScatteringLaw_incoherentElastic
ThermalNeutronScatteringLaw_incoherentElasticDefaultConst();

// +++ Create, default
extern_c Handle2ThermalNeutronScatteringLaw_incoherentElastic
ThermalNeutronScatteringLaw_incoherentElasticDefault();

// --- Create, general, const
extern_c Handle2ConstThermalNeutronScatteringLaw_incoherentElastic
ThermalNeutronScatteringLaw_incoherentElasticCreateConst(
   const XMLName label,
   const XMLName pid,
   const enums::Frame productFrame,
   ConstHandle2ConstBoundAtomCrossSection boundAtomCrossSection,
   ConstHandle2ConstDebyeWallerIntegral DebyeWallerIntegral
);

// +++ Create, general
extern_c Handle2ThermalNeutronScatteringLaw_incoherentElastic
ThermalNeutronScatteringLaw_incoherentElasticCreate(
   const XMLName label,
   const XMLName pid,
   const enums::Frame productFrame,
   ConstHandle2ConstBoundAtomCrossSection boundAtomCrossSection,
   ConstHandle2ConstDebyeWallerIntegral DebyeWallerIntegral
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ThermalNeutronScatteringLaw_incoherentElasticAssign(ConstHandle2ThermalNeutronScatteringLaw_incoherentElastic This, ConstHandle2ConstThermalNeutronScatteringLaw_incoherentElastic from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ThermalNeutronScatteringLaw_incoherentElasticDelete(ConstHandle2ConstThermalNeutronScatteringLaw_incoherentElastic This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ThermalNeutronScatteringLaw_incoherentElasticRead(ConstHandle2ThermalNeutronScatteringLaw_incoherentElastic This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ThermalNeutronScatteringLaw_incoherentElasticWrite(ConstHandle2ConstThermalNeutronScatteringLaw_incoherentElastic This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ThermalNeutronScatteringLaw_incoherentElasticPrint(ConstHandle2ConstThermalNeutronScatteringLaw_incoherentElastic This);

// +++ Print to standard output, as XML
extern_c int
ThermalNeutronScatteringLaw_incoherentElasticPrintXML(ConstHandle2ConstThermalNeutronScatteringLaw_incoherentElastic This);

// +++ Print to standard output, as JSON
extern_c int
ThermalNeutronScatteringLaw_incoherentElasticPrintJSON(ConstHandle2ConstThermalNeutronScatteringLaw_incoherentElastic This);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ThermalNeutronScatteringLaw_incoherentElasticLabelHas(ConstHandle2ConstThermalNeutronScatteringLaw_incoherentElastic This);

// +++ Get
// +++ Returns by value
extern_c XMLName
ThermalNeutronScatteringLaw_incoherentElasticLabelGet(ConstHandle2ConstThermalNeutronScatteringLaw_incoherentElastic This);

// +++ Set
extern_c void
ThermalNeutronScatteringLaw_incoherentElasticLabelSet(ConstHandle2ThermalNeutronScatteringLaw_incoherentElastic This, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: pid
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ThermalNeutronScatteringLaw_incoherentElasticPidHas(ConstHandle2ConstThermalNeutronScatteringLaw_incoherentElastic This);

// +++ Get
// +++ Returns by value
extern_c XMLName
ThermalNeutronScatteringLaw_incoherentElasticPidGet(ConstHandle2ConstThermalNeutronScatteringLaw_incoherentElastic This);

// +++ Set
extern_c void
ThermalNeutronScatteringLaw_incoherentElasticPidSet(ConstHandle2ThermalNeutronScatteringLaw_incoherentElastic This, const XMLName pid);


// -----------------------------------------------------------------------------
// Metadatum: productFrame
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ThermalNeutronScatteringLaw_incoherentElasticProductFrameHas(ConstHandle2ConstThermalNeutronScatteringLaw_incoherentElastic This);

// +++ Get
// +++ Returns by value
extern_c enums::Frame
ThermalNeutronScatteringLaw_incoherentElasticProductFrameGet(ConstHandle2ConstThermalNeutronScatteringLaw_incoherentElastic This);

// +++ Set
extern_c void
ThermalNeutronScatteringLaw_incoherentElasticProductFrameSet(ConstHandle2ThermalNeutronScatteringLaw_incoherentElastic This, const enums::Frame productFrame);


// -----------------------------------------------------------------------------
// Child: boundAtomCrossSection
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ThermalNeutronScatteringLaw_incoherentElasticBoundAtomCrossSectionHas(ConstHandle2ConstThermalNeutronScatteringLaw_incoherentElastic This);

// --- Get, const
extern_c Handle2ConstBoundAtomCrossSection
ThermalNeutronScatteringLaw_incoherentElasticBoundAtomCrossSectionGetConst(ConstHandle2ConstThermalNeutronScatteringLaw_incoherentElastic This);

// +++ Get, non-const
extern_c Handle2BoundAtomCrossSection
ThermalNeutronScatteringLaw_incoherentElasticBoundAtomCrossSectionGet(ConstHandle2ThermalNeutronScatteringLaw_incoherentElastic This);

// +++ Set
extern_c void
ThermalNeutronScatteringLaw_incoherentElasticBoundAtomCrossSectionSet(ConstHandle2ThermalNeutronScatteringLaw_incoherentElastic This, ConstHandle2ConstBoundAtomCrossSection boundAtomCrossSection);


// -----------------------------------------------------------------------------
// Child: DebyeWallerIntegral
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ThermalNeutronScatteringLaw_incoherentElasticDebyeWallerIntegralHas(ConstHandle2ConstThermalNeutronScatteringLaw_incoherentElastic This);

// --- Get, const
extern_c Handle2ConstDebyeWallerIntegral
ThermalNeutronScatteringLaw_incoherentElasticDebyeWallerIntegralGetConst(ConstHandle2ConstThermalNeutronScatteringLaw_incoherentElastic This);

// +++ Get, non-const
extern_c Handle2DebyeWallerIntegral
ThermalNeutronScatteringLaw_incoherentElasticDebyeWallerIntegralGet(ConstHandle2ThermalNeutronScatteringLaw_incoherentElastic This);

// +++ Set
extern_c void
ThermalNeutronScatteringLaw_incoherentElasticDebyeWallerIntegralSet(ConstHandle2ThermalNeutronScatteringLaw_incoherentElastic This, ConstHandle2ConstDebyeWallerIntegral DebyeWallerIntegral);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
