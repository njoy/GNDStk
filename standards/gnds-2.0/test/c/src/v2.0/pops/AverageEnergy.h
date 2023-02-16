
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
// AverageEnergy is the basic handle type in this file. Example:
//    // Create a default AverageEnergy object:
//    AverageEnergy handle = AverageEnergyDefault();
// Functions involving AverageEnergy are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_POPS_AVERAGEENERGY
#define C_INTERFACE_TEST_V2_0_POPS_AVERAGEENERGY

#include "GNDStk.h"
#include "v2.0/documentation/Documentation.h"
#include "v2.0/pops/Uncertainty.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct AverageEnergyClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ AverageEnergy
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct AverageEnergyClass *AverageEnergy;

// --- Const-aware handles.
typedef const struct AverageEnergyClass *const ConstHandle2ConstAverageEnergy;
typedef       struct AverageEnergyClass *const ConstHandle2AverageEnergy;
typedef const struct AverageEnergyClass *      Handle2ConstAverageEnergy;
typedef       struct AverageEnergyClass *      Handle2AverageEnergy;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstAverageEnergy
AverageEnergyDefaultConst();

// +++ Create, default
extern_c Handle2AverageEnergy
AverageEnergyDefault();

// --- Create, general, const
extern_c Handle2ConstAverageEnergy
AverageEnergyCreateConst(
   const XMLName label,
   const Float64 value,
   const XMLName unit,
   ConstHandle2ConstDocumentation documentation,
   ConstHandle2ConstUncertainty uncertainty
);

// +++ Create, general
extern_c Handle2AverageEnergy
AverageEnergyCreate(
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
AverageEnergyAssign(ConstHandle2AverageEnergy self, ConstHandle2ConstAverageEnergy from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
AverageEnergyDelete(ConstHandle2ConstAverageEnergy self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
AverageEnergyRead(ConstHandle2AverageEnergy self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
AverageEnergyWrite(ConstHandle2ConstAverageEnergy self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
AverageEnergyPrint(ConstHandle2ConstAverageEnergy self);

// +++ Print to standard output, as XML
extern_c int
AverageEnergyPrintXML(ConstHandle2ConstAverageEnergy self);

// +++ Print to standard output, as JSON
extern_c int
AverageEnergyPrintJSON(ConstHandle2ConstAverageEnergy self);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AverageEnergyLabelHas(ConstHandle2ConstAverageEnergy self);

// +++ Get
// +++ Returns by value
extern_c XMLName
AverageEnergyLabelGet(ConstHandle2ConstAverageEnergy self);

// +++ Set
extern_c void
AverageEnergyLabelSet(ConstHandle2AverageEnergy self, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AverageEnergyValueHas(ConstHandle2ConstAverageEnergy self);

// +++ Get
// +++ Returns by value
extern_c Float64
AverageEnergyValueGet(ConstHandle2ConstAverageEnergy self);

// +++ Set
extern_c void
AverageEnergyValueSet(ConstHandle2AverageEnergy self, const Float64 value);


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AverageEnergyUnitHas(ConstHandle2ConstAverageEnergy self);

// +++ Get
// +++ Returns by value
extern_c XMLName
AverageEnergyUnitGet(ConstHandle2ConstAverageEnergy self);

// +++ Set
extern_c void
AverageEnergyUnitSet(ConstHandle2AverageEnergy self, const XMLName unit);


// -----------------------------------------------------------------------------
// Child: documentation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AverageEnergyDocumentationHas(ConstHandle2ConstAverageEnergy self);

// --- Get, const
extern_c Handle2ConstDocumentation
AverageEnergyDocumentationGetConst(ConstHandle2ConstAverageEnergy self);

// +++ Get, non-const
extern_c Handle2Documentation
AverageEnergyDocumentationGet(ConstHandle2AverageEnergy self);

// +++ Set
extern_c void
AverageEnergyDocumentationSet(ConstHandle2AverageEnergy self, ConstHandle2ConstDocumentation documentation);


// -----------------------------------------------------------------------------
// Child: uncertainty
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AverageEnergyUncertaintyHas(ConstHandle2ConstAverageEnergy self);

// --- Get, const
extern_c Handle2ConstUncertainty
AverageEnergyUncertaintyGetConst(ConstHandle2ConstAverageEnergy self);

// +++ Get, non-const
extern_c Handle2Uncertainty
AverageEnergyUncertaintyGet(ConstHandle2AverageEnergy self);

// +++ Set
extern_c void
AverageEnergyUncertaintySet(ConstHandle2AverageEnergy self, ConstHandle2ConstUncertainty uncertainty);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/pops/AverageEnergy/src/custom.h"

#undef extern_c
#endif
