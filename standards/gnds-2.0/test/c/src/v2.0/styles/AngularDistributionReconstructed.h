
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
// AngularDistributionReconstructed is the basic handle type in this file. Example:
//    // Create a default AngularDistributionReconstructed object:
//    AngularDistributionReconstructed handle = AngularDistributionReconstructedDefault();
// Functions involving AngularDistributionReconstructed are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_STYLES_ANGULARDISTRIBUTIONRECONSTRUCTED
#define C_INTERFACE_TEST_V2_0_STYLES_ANGULARDISTRIBUTIONRECONSTRUCTED

#include "GNDStk.h"
#include "v2.0/styles/Temperature.h"
#include "v2.0/documentation/Documentation.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct AngularDistributionReconstructedClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ AngularDistributionReconstructed
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct AngularDistributionReconstructedClass *AngularDistributionReconstructed;

// --- Const-aware handles.
typedef const struct AngularDistributionReconstructedClass *const ConstHandle2ConstAngularDistributionReconstructed;
typedef       struct AngularDistributionReconstructedClass *const ConstHandle2AngularDistributionReconstructed;
typedef const struct AngularDistributionReconstructedClass *      Handle2ConstAngularDistributionReconstructed;
typedef       struct AngularDistributionReconstructedClass *      Handle2AngularDistributionReconstructed;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstAngularDistributionReconstructed
AngularDistributionReconstructedDefaultConst();

// +++ Create, default
extern_c Handle2AngularDistributionReconstructed
AngularDistributionReconstructedDefault();

// --- Create, general, const
extern_c Handle2ConstAngularDistributionReconstructed
AngularDistributionReconstructedCreateConst(
   const char *const date,
   const XMLName label,
   const XMLName derivedFrom,
   ConstHandle2ConstTemperature temperature,
   ConstHandle2ConstDocumentation documentation
);

// +++ Create, general
extern_c Handle2AngularDistributionReconstructed
AngularDistributionReconstructedCreate(
   const char *const date,
   const XMLName label,
   const XMLName derivedFrom,
   ConstHandle2ConstTemperature temperature,
   ConstHandle2ConstDocumentation documentation
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
AngularDistributionReconstructedAssign(ConstHandle2AngularDistributionReconstructed self, ConstHandle2ConstAngularDistributionReconstructed from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
AngularDistributionReconstructedDelete(ConstHandle2ConstAngularDistributionReconstructed self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
AngularDistributionReconstructedRead(ConstHandle2AngularDistributionReconstructed self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
AngularDistributionReconstructedWrite(ConstHandle2ConstAngularDistributionReconstructed self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
AngularDistributionReconstructedPrint(ConstHandle2ConstAngularDistributionReconstructed self);

// +++ Print to standard output, as XML
extern_c int
AngularDistributionReconstructedPrintXML(ConstHandle2ConstAngularDistributionReconstructed self);

// +++ Print to standard output, as JSON
extern_c int
AngularDistributionReconstructedPrintJSON(ConstHandle2ConstAngularDistributionReconstructed self);


// -----------------------------------------------------------------------------
// Metadatum: date
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AngularDistributionReconstructedDateHas(ConstHandle2ConstAngularDistributionReconstructed self);

// +++ Get
// +++ Returns by value
extern_c const char *
AngularDistributionReconstructedDateGet(ConstHandle2ConstAngularDistributionReconstructed self);

// +++ Set
extern_c void
AngularDistributionReconstructedDateSet(ConstHandle2AngularDistributionReconstructed self, const char *const date);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AngularDistributionReconstructedLabelHas(ConstHandle2ConstAngularDistributionReconstructed self);

// +++ Get
// +++ Returns by value
extern_c XMLName
AngularDistributionReconstructedLabelGet(ConstHandle2ConstAngularDistributionReconstructed self);

// +++ Set
extern_c void
AngularDistributionReconstructedLabelSet(ConstHandle2AngularDistributionReconstructed self, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: derivedFrom
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AngularDistributionReconstructedDerivedFromHas(ConstHandle2ConstAngularDistributionReconstructed self);

// +++ Get
// +++ Returns by value
extern_c XMLName
AngularDistributionReconstructedDerivedFromGet(ConstHandle2ConstAngularDistributionReconstructed self);

// +++ Set
extern_c void
AngularDistributionReconstructedDerivedFromSet(ConstHandle2AngularDistributionReconstructed self, const XMLName derivedFrom);


// -----------------------------------------------------------------------------
// Child: temperature
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AngularDistributionReconstructedTemperatureHas(ConstHandle2ConstAngularDistributionReconstructed self);

// --- Get, const
extern_c Handle2ConstTemperature
AngularDistributionReconstructedTemperatureGetConst(ConstHandle2ConstAngularDistributionReconstructed self);

// +++ Get, non-const
extern_c Handle2Temperature
AngularDistributionReconstructedTemperatureGet(ConstHandle2AngularDistributionReconstructed self);

// +++ Set
extern_c void
AngularDistributionReconstructedTemperatureSet(ConstHandle2AngularDistributionReconstructed self, ConstHandle2ConstTemperature temperature);


// -----------------------------------------------------------------------------
// Child: documentation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AngularDistributionReconstructedDocumentationHas(ConstHandle2ConstAngularDistributionReconstructed self);

// --- Get, const
extern_c Handle2ConstDocumentation
AngularDistributionReconstructedDocumentationGetConst(ConstHandle2ConstAngularDistributionReconstructed self);

// +++ Get, non-const
extern_c Handle2Documentation
AngularDistributionReconstructedDocumentationGet(ConstHandle2AngularDistributionReconstructed self);

// +++ Set
extern_c void
AngularDistributionReconstructedDocumentationSet(ConstHandle2AngularDistributionReconstructed self, ConstHandle2ConstDocumentation documentation);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/styles/AngularDistributionReconstructed/src/custom.h"

#undef extern_c
#endif
