
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
// Q is the basic handle type in this file. Example:
//    // Create a default Q object:
//    Q handle = QDefault();
// Functions involving Q are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_COMMON_Q
#define C_INTERFACE_TEST_V2_0_COMMON_Q

#include "GNDStk.h"
#include "v2.0/documentation/Documentation.h"
#include "v2.0/containers/Uncertainty.h"
#include "v2.0/containers/Constant1d.h"
#include "v2.0/containers/XYs1d.h"
#include "v2.0/containers/Regions1d.h"
#include "v2.0/containers/Polynomial1d.h"
#include "v2.0/containers/Gridded1d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct QClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Q
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct QClass *Q;

// --- Const-aware handles.
typedef const struct QClass *const ConstHandle2ConstQ;
typedef       struct QClass *const ConstHandle2Q;
typedef const struct QClass *      Handle2ConstQ;
typedef       struct QClass *      Handle2Q;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstQ
QDefaultConst();

// +++ Create, default
extern_c Handle2Q
QDefault();

// --- Create, general, const
extern_c Handle2ConstQ
QCreateConst(
   const XMLName label,
   const XMLName unit,
   const XMLName value,
   ConstHandle2ConstDocumentation documentation,
   ConstHandle2ConstUncertainty uncertainty,
);

// +++ Create, general
extern_c Handle2Q
QCreate(
   const XMLName label,
   const XMLName unit,
   const XMLName value,
   ConstHandle2ConstDocumentation documentation,
   ConstHandle2ConstUncertainty uncertainty,
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
QAssign(ConstHandle2Q This, ConstHandle2ConstQ from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
QDelete(ConstHandle2ConstQ This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
QRead(ConstHandle2Q This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
QWrite(ConstHandle2ConstQ This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
QPrint(ConstHandle2ConstQ This);

// +++ Print to standard output, as XML
extern_c int
QPrintXML(ConstHandle2ConstQ This);

// +++ Print to standard output, as JSON
extern_c int
QPrintJSON(ConstHandle2ConstQ This);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
QLabelHas(ConstHandle2ConstQ This);

// +++ Get
// +++ Returns by value
extern_c XMLName
QLabelGet(ConstHandle2ConstQ This);

// +++ Set
extern_c void
QLabelSet(ConstHandle2Q This, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
QUnitHas(ConstHandle2ConstQ This);

// +++ Get
// +++ Returns by value
extern_c XMLName
QUnitGet(ConstHandle2ConstQ This);

// +++ Set
extern_c void
QUnitSet(ConstHandle2Q This, const XMLName unit);


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
QValueHas(ConstHandle2ConstQ This);

// +++ Get
// +++ Returns by value
extern_c XMLName
QValueGet(ConstHandle2ConstQ This);

// +++ Set
extern_c void
QValueSet(ConstHandle2Q This, const XMLName value);


// -----------------------------------------------------------------------------
// Child: documentation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
QDocumentationHas(ConstHandle2ConstQ This);

// --- Get, const
extern_c Handle2ConstDocumentation
QDocumentationGetConst(ConstHandle2ConstQ This);

// +++ Get, non-const
extern_c Handle2Documentation
QDocumentationGet(ConstHandle2Q This);

// +++ Set
extern_c void
QDocumentationSet(ConstHandle2Q This, ConstHandle2ConstDocumentation documentation);


// -----------------------------------------------------------------------------
// Child: uncertainty
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
QUncertaintyHas(ConstHandle2ConstQ This);

// --- Get, const
extern_c Handle2ConstUncertainty
QUncertaintyGetConst(ConstHandle2ConstQ This);

// +++ Get, non-const
extern_c Handle2Uncertainty
QUncertaintyGet(ConstHandle2Q This);

// +++ Set
extern_c void
QUncertaintySet(ConstHandle2Q This, ConstHandle2ConstUncertainty uncertainty);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
