
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
// Q is the basic handle type in this file. Example:
//    // Create a default Q object:
//    Q handle = QDefault();
// Functions involving Q are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_POPS_Q
#define C_INTERFACE_TRY_V2_0_POPS_Q

#include "GNDStk.h"
#include "v2.0/documentation/Documentation.h"
#include "v2.0/pops/Uncertainty.h"
#include "v2.0/containers/Double.h"

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
   ConstHandle2Double *const Double, const size_t DoubleSize
);

// +++ Create, general
extern_c Handle2Q
QCreate(
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
// Child: Double
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
QDoubleHas(ConstHandle2ConstQ This);

// +++ Clear
extern_c void
QDoubleClear(ConstHandle2Q This);

// +++ Size
extern_c size_t
QDoubleSize(ConstHandle2ConstQ This);

// +++ Add
extern_c void
QDoubleAdd(ConstHandle2Q This, ConstHandle2ConstDouble Double);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstDouble
QDoubleGetConst(ConstHandle2ConstQ This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Double
QDoubleGet(ConstHandle2Q This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
QDoubleSet(
   ConstHandle2Q This,
   const size_t index_,
   ConstHandle2ConstDouble Double
);

// +++ Has, by label
extern_c int
QDoubleHasByLabel(
   ConstHandle2ConstQ This,
   const XMLName label
);

// --- Get, by label, const
extern_c Handle2ConstDouble
QDoubleGetByLabelConst(
   ConstHandle2ConstQ This,
   const XMLName label
);

// +++ Get, by label, non-const
extern_c Handle2Double
QDoubleGetByLabel(
   ConstHandle2Q This,
   const XMLName label
);

// +++ Set, by label
extern_c void
QDoubleSetByLabel(
   ConstHandle2Q This,
   const XMLName label,
   ConstHandle2ConstDouble Double
);

// +++ Has, by unit
extern_c int
QDoubleHasByUnit(
   ConstHandle2ConstQ This,
   const XMLName unit
);

// --- Get, by unit, const
extern_c Handle2ConstDouble
QDoubleGetByUnitConst(
   ConstHandle2ConstQ This,
   const XMLName unit
);

// +++ Get, by unit, non-const
extern_c Handle2Double
QDoubleGetByUnit(
   ConstHandle2Q This,
   const XMLName unit
);

// +++ Set, by unit
extern_c void
QDoubleSetByUnit(
   ConstHandle2Q This,
   const XMLName unit,
   ConstHandle2ConstDouble Double
);

// +++ Has, by value
extern_c int
QDoubleHasByValue(
   ConstHandle2ConstQ This,
   const Float64 value
);

// --- Get, by value, const
extern_c Handle2ConstDouble
QDoubleGetByValueConst(
   ConstHandle2ConstQ This,
   const Float64 value
);

// +++ Get, by value, non-const
extern_c Handle2Double
QDoubleGetByValue(
   ConstHandle2Q This,
   const Float64 value
);

// +++ Set, by value
extern_c void
QDoubleSetByValue(
   ConstHandle2Q This,
   const Float64 value,
   ConstHandle2ConstDouble Double
);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
