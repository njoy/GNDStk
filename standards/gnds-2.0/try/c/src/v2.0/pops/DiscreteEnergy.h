
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
// DiscreteEnergy is the basic handle type in this file. Example:
//    // Create a default DiscreteEnergy object:
//    DiscreteEnergy handle = DiscreteEnergyDefault();
// Functions involving DiscreteEnergy are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_POPS_DISCRETEENERGY
#define C_INTERFACE_TRY_V2_0_POPS_DISCRETEENERGY

#include "GNDStk.h"
#include "v2.0/documentation/Documentation.h"
#include "v2.0/pops/Uncertainty.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct DiscreteEnergyClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ DiscreteEnergy
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct DiscreteEnergyClass *DiscreteEnergy;

// --- Const-aware handles.
typedef const struct DiscreteEnergyClass *const ConstHandle2ConstDiscreteEnergy;
typedef       struct DiscreteEnergyClass *const ConstHandle2DiscreteEnergy;
typedef const struct DiscreteEnergyClass *      Handle2ConstDiscreteEnergy;
typedef       struct DiscreteEnergyClass *      Handle2DiscreteEnergy;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstDiscreteEnergy
DiscreteEnergyDefaultConst();

// +++ Create, default
extern_c Handle2DiscreteEnergy
DiscreteEnergyDefault();

// --- Create, general, const
extern_c Handle2ConstDiscreteEnergy
DiscreteEnergyCreateConst(
   const XMLName label,
   const Float64 value,
   const XMLName unit,
   ConstHandle2ConstDocumentation documentation,
   ConstHandle2ConstUncertainty uncertainty
);

// +++ Create, general
extern_c Handle2DiscreteEnergy
DiscreteEnergyCreate(
   const XMLName label,
   const Float64 value,
   const XMLName unit,
   ConstHandle2ConstDocumentation documentation,
   ConstHandle2ConstUncertainty uncertainty
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
DiscreteEnergyAssign(ConstHandle2DiscreteEnergy This, ConstHandle2ConstDiscreteEnergy from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
DiscreteEnergyDelete(ConstHandle2ConstDiscreteEnergy This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
DiscreteEnergyRead(ConstHandle2DiscreteEnergy This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
DiscreteEnergyWrite(ConstHandle2ConstDiscreteEnergy This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
DiscreteEnergyPrint(ConstHandle2ConstDiscreteEnergy This);

// +++ Print to standard output, as XML
extern_c int
DiscreteEnergyPrintXML(ConstHandle2ConstDiscreteEnergy This);

// +++ Print to standard output, as JSON
extern_c int
DiscreteEnergyPrintJSON(ConstHandle2ConstDiscreteEnergy This);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DiscreteEnergyLabelHas(ConstHandle2ConstDiscreteEnergy This);

// +++ Get
// +++ Returns by value
extern_c XMLName
DiscreteEnergyLabelGet(ConstHandle2ConstDiscreteEnergy This);

// +++ Set
extern_c void
DiscreteEnergyLabelSet(ConstHandle2DiscreteEnergy This, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DiscreteEnergyValueHas(ConstHandle2ConstDiscreteEnergy This);

// +++ Get
// +++ Returns by value
extern_c Float64
DiscreteEnergyValueGet(ConstHandle2ConstDiscreteEnergy This);

// +++ Set
extern_c void
DiscreteEnergyValueSet(ConstHandle2DiscreteEnergy This, const Float64 value);


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DiscreteEnergyUnitHas(ConstHandle2ConstDiscreteEnergy This);

// +++ Get
// +++ Returns by value
extern_c XMLName
DiscreteEnergyUnitGet(ConstHandle2ConstDiscreteEnergy This);

// +++ Set
extern_c void
DiscreteEnergyUnitSet(ConstHandle2DiscreteEnergy This, const XMLName unit);


// -----------------------------------------------------------------------------
// Child: documentation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DiscreteEnergyDocumentationHas(ConstHandle2ConstDiscreteEnergy This);

// --- Get, const
extern_c Handle2ConstDocumentation
DiscreteEnergyDocumentationGetConst(ConstHandle2ConstDiscreteEnergy This);

// +++ Get, non-const
extern_c Handle2Documentation
DiscreteEnergyDocumentationGet(ConstHandle2DiscreteEnergy This);

// +++ Set
extern_c void
DiscreteEnergyDocumentationSet(ConstHandle2DiscreteEnergy This, ConstHandle2ConstDocumentation documentation);


// -----------------------------------------------------------------------------
// Child: uncertainty
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DiscreteEnergyUncertaintyHas(ConstHandle2ConstDiscreteEnergy This);

// --- Get, const
extern_c Handle2ConstUncertainty
DiscreteEnergyUncertaintyGetConst(ConstHandle2ConstDiscreteEnergy This);

// +++ Get, non-const
extern_c Handle2Uncertainty
DiscreteEnergyUncertaintyGet(ConstHandle2DiscreteEnergy This);

// +++ Set
extern_c void
DiscreteEnergyUncertaintySet(ConstHandle2DiscreteEnergy This, ConstHandle2ConstUncertainty uncertainty);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
