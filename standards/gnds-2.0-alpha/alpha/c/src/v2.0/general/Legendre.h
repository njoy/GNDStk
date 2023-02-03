
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
// Legendre is the basic handle type in this file. Example:
//    // Create a default Legendre object:
//    Legendre handle = LegendreDefault();
// Functions involving Legendre are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_LEGENDRE
#define C_INTERFACE_ALPHA_V2_0_GENERAL_LEGENDRE

#include "GNDStk.h"
#include "v2.0/general/Values.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct LegendreClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Legendre
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct LegendreClass *Legendre;

// --- Const-aware handles.
typedef const struct LegendreClass *const ConstHandle2ConstLegendre;
typedef       struct LegendreClass *const ConstHandle2Legendre;
typedef const struct LegendreClass *      Handle2ConstLegendre;
typedef       struct LegendreClass *      Handle2Legendre;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstLegendre
LegendreDefaultConst();

// +++ Create, default
extern_c Handle2Legendre
LegendreDefault();

// --- Create, general, const
extern_c Handle2ConstLegendre
LegendreCreateConst(
   const double outerDomainValue,
   ConstHandle2ConstValues values
);

// +++ Create, general
extern_c Handle2Legendre
LegendreCreate(
   const double outerDomainValue,
   ConstHandle2ConstValues values
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
LegendreAssign(ConstHandle2Legendre This, ConstHandle2ConstLegendre from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
LegendreDelete(ConstHandle2ConstLegendre This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
LegendreRead(ConstHandle2Legendre This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
LegendreWrite(ConstHandle2ConstLegendre This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
LegendrePrint(ConstHandle2ConstLegendre This);

// +++ Print to standard output, as XML
extern_c int
LegendrePrintXML(ConstHandle2ConstLegendre This);

// +++ Print to standard output, as JSON
extern_c int
LegendrePrintJSON(ConstHandle2ConstLegendre This);


// -----------------------------------------------------------------------------
// Metadatum: outerDomainValue
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
LegendreOuterDomainValueHas(ConstHandle2ConstLegendre This);

// +++ Get
// +++ Returns by value
extern_c double
LegendreOuterDomainValueGet(ConstHandle2ConstLegendre This);

// +++ Set
extern_c void
LegendreOuterDomainValueSet(ConstHandle2Legendre This, const double outerDomainValue);


// -----------------------------------------------------------------------------
// Child: values
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
LegendreValuesHas(ConstHandle2ConstLegendre This);

// --- Get, const
extern_c Handle2ConstValues
LegendreValuesGetConst(ConstHandle2ConstLegendre This);

// +++ Get, non-const
extern_c Handle2Values
LegendreValuesGet(ConstHandle2Legendre This);

// +++ Set
extern_c void
LegendreValuesSet(ConstHandle2Legendre This, ConstHandle2ConstValues values);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Legendre/src/custom.h"

#undef extern_c
#endif
