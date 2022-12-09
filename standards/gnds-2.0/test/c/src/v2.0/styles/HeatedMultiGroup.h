
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
// HeatedMultiGroup is the basic handle type in this file. Example:
//    // Create a default HeatedMultiGroup object:
//    HeatedMultiGroup handle = HeatedMultiGroupDefault();
// Functions involving HeatedMultiGroup are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_STYLES_HEATEDMULTIGROUP
#define C_INTERFACE_TEST_V2_0_STYLES_HEATEDMULTIGROUP

#include "GNDStk.h"
#include "v2.0/styles/Transportables.h"
#include "v2.0/styles/Flux.h"
#include "v2.0/styles/InverseSpeed.h"
#include "v2.0/documentation/Documentation.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct HeatedMultiGroupClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ HeatedMultiGroup
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct HeatedMultiGroupClass *HeatedMultiGroup;

// --- Const-aware handles.
typedef const struct HeatedMultiGroupClass *const ConstHandle2ConstHeatedMultiGroup;
typedef       struct HeatedMultiGroupClass *const ConstHandle2HeatedMultiGroup;
typedef const struct HeatedMultiGroupClass *      Handle2ConstHeatedMultiGroup;
typedef       struct HeatedMultiGroupClass *      Handle2HeatedMultiGroup;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstHeatedMultiGroup
HeatedMultiGroupDefaultConst();

// +++ Create, default
extern_c Handle2HeatedMultiGroup
HeatedMultiGroupDefault();

// --- Create, general, const
extern_c Handle2ConstHeatedMultiGroup
HeatedMultiGroupCreateConst(
   const char *const date,
   const XMLName derivedFrom,
   const XMLName label,
   ConstHandle2ConstTransportables transportables,
   ConstHandle2ConstFlux flux,
   ConstHandle2ConstInverseSpeed inverseSpeed,
   ConstHandle2ConstDocumentation documentation
);

// +++ Create, general
extern_c Handle2HeatedMultiGroup
HeatedMultiGroupCreate(
   const char *const date,
   const XMLName derivedFrom,
   const XMLName label,
   ConstHandle2ConstTransportables transportables,
   ConstHandle2ConstFlux flux,
   ConstHandle2ConstInverseSpeed inverseSpeed,
   ConstHandle2ConstDocumentation documentation
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
HeatedMultiGroupAssign(ConstHandle2HeatedMultiGroup This, ConstHandle2ConstHeatedMultiGroup from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
HeatedMultiGroupDelete(ConstHandle2ConstHeatedMultiGroup This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
HeatedMultiGroupRead(ConstHandle2HeatedMultiGroup This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
HeatedMultiGroupWrite(ConstHandle2ConstHeatedMultiGroup This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
HeatedMultiGroupPrint(ConstHandle2ConstHeatedMultiGroup This);

// +++ Print to standard output, as XML
extern_c int
HeatedMultiGroupPrintXML(ConstHandle2ConstHeatedMultiGroup This);

// +++ Print to standard output, as JSON
extern_c int
HeatedMultiGroupPrintJSON(ConstHandle2ConstHeatedMultiGroup This);


// -----------------------------------------------------------------------------
// Metadatum: date
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
HeatedMultiGroupDateHas(ConstHandle2ConstHeatedMultiGroup This);

// +++ Get
// +++ Returns by value
extern_c const char *
HeatedMultiGroupDateGet(ConstHandle2ConstHeatedMultiGroup This);

// +++ Set
extern_c void
HeatedMultiGroupDateSet(ConstHandle2HeatedMultiGroup This, const char *const date);


// -----------------------------------------------------------------------------
// Metadatum: derivedFrom
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
HeatedMultiGroupDerivedFromHas(ConstHandle2ConstHeatedMultiGroup This);

// +++ Get
// +++ Returns by value
extern_c XMLName
HeatedMultiGroupDerivedFromGet(ConstHandle2ConstHeatedMultiGroup This);

// +++ Set
extern_c void
HeatedMultiGroupDerivedFromSet(ConstHandle2HeatedMultiGroup This, const XMLName derivedFrom);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
HeatedMultiGroupLabelHas(ConstHandle2ConstHeatedMultiGroup This);

// +++ Get
// +++ Returns by value
extern_c XMLName
HeatedMultiGroupLabelGet(ConstHandle2ConstHeatedMultiGroup This);

// +++ Set
extern_c void
HeatedMultiGroupLabelSet(ConstHandle2HeatedMultiGroup This, const XMLName label);


// -----------------------------------------------------------------------------
// Child: transportables
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
HeatedMultiGroupTransportablesHas(ConstHandle2ConstHeatedMultiGroup This);

// --- Get, const
extern_c Handle2ConstTransportables
HeatedMultiGroupTransportablesGetConst(ConstHandle2ConstHeatedMultiGroup This);

// +++ Get, non-const
extern_c Handle2Transportables
HeatedMultiGroupTransportablesGet(ConstHandle2HeatedMultiGroup This);

// +++ Set
extern_c void
HeatedMultiGroupTransportablesSet(ConstHandle2HeatedMultiGroup This, ConstHandle2ConstTransportables transportables);


// -----------------------------------------------------------------------------
// Child: flux
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
HeatedMultiGroupFluxHas(ConstHandle2ConstHeatedMultiGroup This);

// --- Get, const
extern_c Handle2ConstFlux
HeatedMultiGroupFluxGetConst(ConstHandle2ConstHeatedMultiGroup This);

// +++ Get, non-const
extern_c Handle2Flux
HeatedMultiGroupFluxGet(ConstHandle2HeatedMultiGroup This);

// +++ Set
extern_c void
HeatedMultiGroupFluxSet(ConstHandle2HeatedMultiGroup This, ConstHandle2ConstFlux flux);


// -----------------------------------------------------------------------------
// Child: inverseSpeed
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
HeatedMultiGroupInverseSpeedHas(ConstHandle2ConstHeatedMultiGroup This);

// --- Get, const
extern_c Handle2ConstInverseSpeed
HeatedMultiGroupInverseSpeedGetConst(ConstHandle2ConstHeatedMultiGroup This);

// +++ Get, non-const
extern_c Handle2InverseSpeed
HeatedMultiGroupInverseSpeedGet(ConstHandle2HeatedMultiGroup This);

// +++ Set
extern_c void
HeatedMultiGroupInverseSpeedSet(ConstHandle2HeatedMultiGroup This, ConstHandle2ConstInverseSpeed inverseSpeed);


// -----------------------------------------------------------------------------
// Child: documentation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
HeatedMultiGroupDocumentationHas(ConstHandle2ConstHeatedMultiGroup This);

// --- Get, const
extern_c Handle2ConstDocumentation
HeatedMultiGroupDocumentationGetConst(ConstHandle2ConstHeatedMultiGroup This);

// +++ Get, non-const
extern_c Handle2Documentation
HeatedMultiGroupDocumentationGet(ConstHandle2HeatedMultiGroup This);

// +++ Set
extern_c void
HeatedMultiGroupDocumentationSet(ConstHandle2HeatedMultiGroup This, ConstHandle2ConstDocumentation documentation);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
