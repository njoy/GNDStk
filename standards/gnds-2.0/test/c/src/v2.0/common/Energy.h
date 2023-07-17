
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
// Energy is the basic handle type in this file. Example:
//    // Create a default Energy object:
//    Energy handle = EnergyDefault();
// Functions involving Energy are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_COMMON_ENERGY
#define C_INTERFACE_TEST_V2_0_COMMON_ENERGY

#include "GNDStk.h"
#include "v2.0/documentation/Documentation.h"
#include "v2.0/containers/Uncertainty.h"
#include "v2.0/containers/Double.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct EnergyClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Energy
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct EnergyClass *Energy;

// --- Const-aware handles.
typedef const struct EnergyClass *const ConstHandle2ConstEnergy;
typedef       struct EnergyClass *const ConstHandle2Energy;
typedef const struct EnergyClass *      Handle2ConstEnergy;
typedef       struct EnergyClass *      Handle2Energy;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstEnergy
EnergyDefaultConst();

// +++ Create, default
extern_c Handle2Energy
EnergyDefault();

// --- Create, general, const
extern_c Handle2ConstEnergy
EnergyCreateConst(
   const XMLName label,
   const XMLName unit,
   const XMLName value,
   ConstHandle2ConstDocumentation documentation,
   ConstHandle2ConstUncertainty uncertainty,
   ConstHandle2Double *const Double, const size_t DoubleSize
);

// +++ Create, general
extern_c Handle2Energy
EnergyCreate(
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
EnergyAssign(ConstHandle2Energy self, ConstHandle2ConstEnergy from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
EnergyDelete(ConstHandle2ConstEnergy self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
EnergyRead(ConstHandle2Energy self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
EnergyWrite(ConstHandle2ConstEnergy self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
EnergyPrint(ConstHandle2ConstEnergy self);

// +++ Print to standard output, as XML
extern_c int
EnergyPrintXML(ConstHandle2ConstEnergy self);

// +++ Print to standard output, as JSON
extern_c int
EnergyPrintJSON(ConstHandle2ConstEnergy self);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
EnergyLabelHas(ConstHandle2ConstEnergy self);

// +++ Get
// +++ Returns by value
extern_c XMLName
EnergyLabelGet(ConstHandle2ConstEnergy self);

// +++ Set
extern_c void
EnergyLabelSet(ConstHandle2Energy self, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
EnergyUnitHas(ConstHandle2ConstEnergy self);

// +++ Get
// +++ Returns by value
extern_c XMLName
EnergyUnitGet(ConstHandle2ConstEnergy self);

// +++ Set
extern_c void
EnergyUnitSet(ConstHandle2Energy self, const XMLName unit);


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
EnergyValueHas(ConstHandle2ConstEnergy self);

// +++ Get
// +++ Returns by value
extern_c XMLName
EnergyValueGet(ConstHandle2ConstEnergy self);

// +++ Set
extern_c void
EnergyValueSet(ConstHandle2Energy self, const XMLName value);


// -----------------------------------------------------------------------------
// Child: documentation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
EnergyDocumentationHas(ConstHandle2ConstEnergy self);

// --- Get, const
extern_c Handle2ConstDocumentation
EnergyDocumentationGetConst(ConstHandle2ConstEnergy self);

// +++ Get, non-const
extern_c Handle2Documentation
EnergyDocumentationGet(ConstHandle2Energy self);

// +++ Set
extern_c void
EnergyDocumentationSet(ConstHandle2Energy self, ConstHandle2ConstDocumentation documentation);


// -----------------------------------------------------------------------------
// Child: uncertainty
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
EnergyUncertaintyHas(ConstHandle2ConstEnergy self);

// --- Get, const
extern_c Handle2ConstUncertainty
EnergyUncertaintyGetConst(ConstHandle2ConstEnergy self);

// +++ Get, non-const
extern_c Handle2Uncertainty
EnergyUncertaintyGet(ConstHandle2Energy self);

// +++ Set
extern_c void
EnergyUncertaintySet(ConstHandle2Energy self, ConstHandle2ConstUncertainty uncertainty);


// -----------------------------------------------------------------------------
// Child: Double
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
EnergyDoubleHas(ConstHandle2ConstEnergy self);

// +++ Clear
extern_c void
EnergyDoubleClear(ConstHandle2Energy self);

// +++ Size
extern_c size_t
EnergyDoubleSize(ConstHandle2ConstEnergy self);

// +++ Add
extern_c void
EnergyDoubleAdd(ConstHandle2Energy self, ConstHandle2ConstDouble Double);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstDouble
EnergyDoubleGetConst(ConstHandle2ConstEnergy self, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Double
EnergyDoubleGet(ConstHandle2Energy self, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
EnergyDoubleSet(
   ConstHandle2Energy self,
   const size_t index_,
   ConstHandle2ConstDouble Double
);

// +++ Has, by label
extern_c int
EnergyDoubleHasByLabel(
   ConstHandle2ConstEnergy self,
   const XMLName label
);

// --- Get, by label, const
extern_c Handle2ConstDouble
EnergyDoubleGetByLabelConst(
   ConstHandle2ConstEnergy self,
   const XMLName label
);

// +++ Get, by label, non-const
extern_c Handle2Double
EnergyDoubleGetByLabel(
   ConstHandle2Energy self,
   const XMLName label
);

// +++ Set, by label
extern_c void
EnergyDoubleSetByLabel(
   ConstHandle2Energy self,
   const XMLName label,
   ConstHandle2ConstDouble Double
);

// +++ Has, by unit
extern_c int
EnergyDoubleHasByUnit(
   ConstHandle2ConstEnergy self,
   const XMLName unit
);

// --- Get, by unit, const
extern_c Handle2ConstDouble
EnergyDoubleGetByUnitConst(
   ConstHandle2ConstEnergy self,
   const XMLName unit
);

// +++ Get, by unit, non-const
extern_c Handle2Double
EnergyDoubleGetByUnit(
   ConstHandle2Energy self,
   const XMLName unit
);

// +++ Set, by unit
extern_c void
EnergyDoubleSetByUnit(
   ConstHandle2Energy self,
   const XMLName unit,
   ConstHandle2ConstDouble Double
);

// +++ Has, by value
extern_c int
EnergyDoubleHasByValue(
   ConstHandle2ConstEnergy self,
   const Float64 value
);

// --- Get, by value, const
extern_c Handle2ConstDouble
EnergyDoubleGetByValueConst(
   ConstHandle2ConstEnergy self,
   const Float64 value
);

// +++ Get, by value, non-const
extern_c Handle2Double
EnergyDoubleGetByValue(
   ConstHandle2Energy self,
   const Float64 value
);

// +++ Set, by value
extern_c void
EnergyDoubleSetByValue(
   ConstHandle2Energy self,
   const Float64 value,
   ConstHandle2ConstDouble Double
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/common/Energy/src/custom.h"

#undef extern_c
#endif
