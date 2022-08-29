
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
// BindingEnergy is the basic handle type in this file. Example:
//    // Create a default BindingEnergy object:
//    BindingEnergy handle = BindingEnergyDefault();
// Functions involving BindingEnergy are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_POPS_BINDINGENERGY
#define C_INTERFACE_TRY_V2_0_POPS_BINDINGENERGY

#include "GNDStk.h"
#include "v2.0/documentation/Documentation.h"
#include "v2.0/pops/Uncertainty.h"
#include "v2.0/unknownNamespace/Double.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct BindingEnergyClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ BindingEnergy
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct BindingEnergyClass *BindingEnergy;

// --- Const-aware handles.
typedef const struct BindingEnergyClass *const ConstHandle2ConstBindingEnergy;
typedef       struct BindingEnergyClass *const ConstHandle2BindingEnergy;
typedef const struct BindingEnergyClass *      Handle2ConstBindingEnergy;
typedef       struct BindingEnergyClass *      Handle2BindingEnergy;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstBindingEnergy
BindingEnergyDefaultConst();

// +++ Create, default
extern_c Handle2BindingEnergy
BindingEnergyDefault();

// --- Create, general, const
extern_c Handle2ConstBindingEnergy
BindingEnergyCreateConst(
   const XMLName label,
   const XMLName unit,
   const XMLName value,
   ConstHandle2ConstDocumentation documentation,
   ConstHandle2ConstUncertainty uncertainty,
   ConstHandle2Double *const Double, const size_t DoubleSize
);

// +++ Create, general
extern_c Handle2BindingEnergy
BindingEnergyCreate(
   const XMLName label,
   const XMLName unit,
   const XMLName value,
   ConstHandle2ConstDocumentation documentation,
   ConstHandle2ConstUncertainty uncertainty,
   ConstHandle2Double *const Double, const size_t DoubleSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
BindingEnergyAssign(ConstHandle2BindingEnergy This, ConstHandle2ConstBindingEnergy from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
BindingEnergyDelete(ConstHandle2ConstBindingEnergy This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
BindingEnergyRead(ConstHandle2BindingEnergy This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
BindingEnergyWrite(ConstHandle2ConstBindingEnergy This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
BindingEnergyPrint(ConstHandle2ConstBindingEnergy This);

// +++ Print to standard output, as XML
extern_c int
BindingEnergyPrintXML(ConstHandle2ConstBindingEnergy This);

// +++ Print to standard output, as JSON
extern_c int
BindingEnergyPrintJSON(ConstHandle2ConstBindingEnergy This);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BindingEnergyLabelHas(ConstHandle2ConstBindingEnergy This);

// +++ Get
// +++ Returns by value
extern_c XMLName
BindingEnergyLabelGet(ConstHandle2ConstBindingEnergy This);

// +++ Set
extern_c void
BindingEnergyLabelSet(ConstHandle2BindingEnergy This, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BindingEnergyUnitHas(ConstHandle2ConstBindingEnergy This);

// +++ Get
// +++ Returns by value
extern_c XMLName
BindingEnergyUnitGet(ConstHandle2ConstBindingEnergy This);

// +++ Set
extern_c void
BindingEnergyUnitSet(ConstHandle2BindingEnergy This, const XMLName unit);


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BindingEnergyValueHas(ConstHandle2ConstBindingEnergy This);

// +++ Get
// +++ Returns by value
extern_c XMLName
BindingEnergyValueGet(ConstHandle2ConstBindingEnergy This);

// +++ Set
extern_c void
BindingEnergyValueSet(ConstHandle2BindingEnergy This, const XMLName value);


// -----------------------------------------------------------------------------
// Child: documentation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BindingEnergyDocumentationHas(ConstHandle2ConstBindingEnergy This);

// --- Get, const
extern_c Handle2ConstDocumentation
BindingEnergyDocumentationGetConst(ConstHandle2ConstBindingEnergy This);

// +++ Get, non-const
extern_c Handle2Documentation
BindingEnergyDocumentationGet(ConstHandle2BindingEnergy This);

// +++ Set
extern_c void
BindingEnergyDocumentationSet(ConstHandle2BindingEnergy This, ConstHandle2ConstDocumentation documentation);


// -----------------------------------------------------------------------------
// Child: uncertainty
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BindingEnergyUncertaintyHas(ConstHandle2ConstBindingEnergy This);

// --- Get, const
extern_c Handle2ConstUncertainty
BindingEnergyUncertaintyGetConst(ConstHandle2ConstBindingEnergy This);

// +++ Get, non-const
extern_c Handle2Uncertainty
BindingEnergyUncertaintyGet(ConstHandle2BindingEnergy This);

// +++ Set
extern_c void
BindingEnergyUncertaintySet(ConstHandle2BindingEnergy This, ConstHandle2ConstUncertainty uncertainty);


// -----------------------------------------------------------------------------
// Child: Double
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BindingEnergyDoubleHas(ConstHandle2ConstBindingEnergy This);

// +++ Clear
extern_c void
BindingEnergyDoubleClear(ConstHandle2BindingEnergy This);

// +++ Size
extern_c size_t
BindingEnergyDoubleSize(ConstHandle2ConstBindingEnergy This);

// +++ Add
extern_c void
BindingEnergyDoubleAdd(ConstHandle2BindingEnergy This, ConstHandle2ConstDouble Double);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstDouble
BindingEnergyDoubleGetConst(ConstHandle2ConstBindingEnergy This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Double
BindingEnergyDoubleGet(ConstHandle2BindingEnergy This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
BindingEnergyDoubleSet(
   ConstHandle2BindingEnergy This,
   const size_t index_,
   ConstHandle2ConstDouble Double
);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
