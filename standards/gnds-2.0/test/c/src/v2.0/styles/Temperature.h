
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
// Temperature is the basic handle type in this file. Example:
//    // Create a default Temperature object:
//    Temperature handle = TemperatureDefault();
// Functions involving Temperature are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_STYLES_TEMPERATURE
#define C_INTERFACE_TEST_V2_0_STYLES_TEMPERATURE

#include "GNDStk.h"
#include "v2.0/documentation/Documentation.h"
#include "v2.0/pops/Uncertainty.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct TemperatureClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Temperature
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct TemperatureClass *Temperature;

// --- Const-aware handles.
typedef const struct TemperatureClass *const ConstHandle2ConstTemperature;
typedef       struct TemperatureClass *const ConstHandle2Temperature;
typedef const struct TemperatureClass *      Handle2ConstTemperature;
typedef       struct TemperatureClass *      Handle2Temperature;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstTemperature
TemperatureDefaultConst();

// +++ Create, default
extern_c Handle2Temperature
TemperatureDefault();

// --- Create, general, const
extern_c Handle2ConstTemperature
TemperatureCreateConst(
   const XMLName label,
   const Float64 value,
   const XMLName unit,
   ConstHandle2ConstDocumentation documentation,
   ConstHandle2ConstUncertainty uncertainty
);

// +++ Create, general
extern_c Handle2Temperature
TemperatureCreate(
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
TemperatureAssign(ConstHandle2Temperature self, ConstHandle2ConstTemperature from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
TemperatureDelete(ConstHandle2ConstTemperature self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
TemperatureRead(ConstHandle2Temperature self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
TemperatureWrite(ConstHandle2ConstTemperature self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
TemperaturePrint(ConstHandle2ConstTemperature self);

// +++ Print to standard output, as XML
extern_c int
TemperaturePrintXML(ConstHandle2ConstTemperature self);

// +++ Print to standard output, as JSON
extern_c int
TemperaturePrintJSON(ConstHandle2ConstTemperature self);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
TemperatureLabelHas(ConstHandle2ConstTemperature self);

// +++ Get
// +++ Returns by value
extern_c XMLName
TemperatureLabelGet(ConstHandle2ConstTemperature self);

// +++ Set
extern_c void
TemperatureLabelSet(ConstHandle2Temperature self, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
TemperatureValueHas(ConstHandle2ConstTemperature self);

// +++ Get
// +++ Returns by value
extern_c Float64
TemperatureValueGet(ConstHandle2ConstTemperature self);

// +++ Set
extern_c void
TemperatureValueSet(ConstHandle2Temperature self, const Float64 value);


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
TemperatureUnitHas(ConstHandle2ConstTemperature self);

// +++ Get
// +++ Returns by value
extern_c XMLName
TemperatureUnitGet(ConstHandle2ConstTemperature self);

// +++ Set
extern_c void
TemperatureUnitSet(ConstHandle2Temperature self, const XMLName unit);


// -----------------------------------------------------------------------------
// Child: documentation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
TemperatureDocumentationHas(ConstHandle2ConstTemperature self);

// --- Get, const
extern_c Handle2ConstDocumentation
TemperatureDocumentationGetConst(ConstHandle2ConstTemperature self);

// +++ Get, non-const
extern_c Handle2Documentation
TemperatureDocumentationGet(ConstHandle2Temperature self);

// +++ Set
extern_c void
TemperatureDocumentationSet(ConstHandle2Temperature self, ConstHandle2ConstDocumentation documentation);


// -----------------------------------------------------------------------------
// Child: uncertainty
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
TemperatureUncertaintyHas(ConstHandle2ConstTemperature self);

// --- Get, const
extern_c Handle2ConstUncertainty
TemperatureUncertaintyGetConst(ConstHandle2ConstTemperature self);

// +++ Get, non-const
extern_c Handle2Uncertainty
TemperatureUncertaintyGet(ConstHandle2Temperature self);

// +++ Set
extern_c void
TemperatureUncertaintySet(ConstHandle2Temperature self, ConstHandle2ConstUncertainty uncertainty);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/styles/Temperature/src/custom.h"

#undef extern_c
#endif
