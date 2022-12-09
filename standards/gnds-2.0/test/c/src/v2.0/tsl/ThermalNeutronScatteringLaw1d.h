
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
// ThermalNeutronScatteringLaw1d is the basic handle type in this file. Example:
//    // Create a default ThermalNeutronScatteringLaw1d object:
//    ThermalNeutronScatteringLaw1d handle = ThermalNeutronScatteringLaw1dDefault();
// Functions involving ThermalNeutronScatteringLaw1d are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_TSL_THERMALNEUTRONSCATTERINGLAW1D
#define C_INTERFACE_TEST_V2_0_TSL_THERMALNEUTRONSCATTERINGLAW1D

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ThermalNeutronScatteringLaw1dClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ThermalNeutronScatteringLaw1d
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ThermalNeutronScatteringLaw1dClass *ThermalNeutronScatteringLaw1d;

// --- Const-aware handles.
typedef const struct ThermalNeutronScatteringLaw1dClass *const ConstHandle2ConstThermalNeutronScatteringLaw1d;
typedef       struct ThermalNeutronScatteringLaw1dClass *const ConstHandle2ThermalNeutronScatteringLaw1d;
typedef const struct ThermalNeutronScatteringLaw1dClass *      Handle2ConstThermalNeutronScatteringLaw1d;
typedef       struct ThermalNeutronScatteringLaw1dClass *      Handle2ThermalNeutronScatteringLaw1d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstThermalNeutronScatteringLaw1d
ThermalNeutronScatteringLaw1dDefaultConst();

// +++ Create, default
extern_c Handle2ThermalNeutronScatteringLaw1d
ThermalNeutronScatteringLaw1dDefault();

// --- Create, general, const
extern_c Handle2ConstThermalNeutronScatteringLaw1d
ThermalNeutronScatteringLaw1dCreateConst(
   const XMLName label,
   const XMLName href
);

// +++ Create, general
extern_c Handle2ThermalNeutronScatteringLaw1d
ThermalNeutronScatteringLaw1dCreate(
   const XMLName label,
   const XMLName href
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ThermalNeutronScatteringLaw1dAssign(ConstHandle2ThermalNeutronScatteringLaw1d This, ConstHandle2ConstThermalNeutronScatteringLaw1d from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ThermalNeutronScatteringLaw1dDelete(ConstHandle2ConstThermalNeutronScatteringLaw1d This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ThermalNeutronScatteringLaw1dRead(ConstHandle2ThermalNeutronScatteringLaw1d This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ThermalNeutronScatteringLaw1dWrite(ConstHandle2ConstThermalNeutronScatteringLaw1d This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ThermalNeutronScatteringLaw1dPrint(ConstHandle2ConstThermalNeutronScatteringLaw1d This);

// +++ Print to standard output, as XML
extern_c int
ThermalNeutronScatteringLaw1dPrintXML(ConstHandle2ConstThermalNeutronScatteringLaw1d This);

// +++ Print to standard output, as JSON
extern_c int
ThermalNeutronScatteringLaw1dPrintJSON(ConstHandle2ConstThermalNeutronScatteringLaw1d This);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ThermalNeutronScatteringLaw1dLabelHas(ConstHandle2ConstThermalNeutronScatteringLaw1d This);

// +++ Get
// +++ Returns by value
extern_c XMLName
ThermalNeutronScatteringLaw1dLabelGet(ConstHandle2ConstThermalNeutronScatteringLaw1d This);

// +++ Set
extern_c void
ThermalNeutronScatteringLaw1dLabelSet(ConstHandle2ThermalNeutronScatteringLaw1d This, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ThermalNeutronScatteringLaw1dHrefHas(ConstHandle2ConstThermalNeutronScatteringLaw1d This);

// +++ Get
// +++ Returns by value
extern_c XMLName
ThermalNeutronScatteringLaw1dHrefGet(ConstHandle2ConstThermalNeutronScatteringLaw1d This);

// +++ Set
extern_c void
ThermalNeutronScatteringLaw1dHrefSet(ConstHandle2ThermalNeutronScatteringLaw1d This, const XMLName href);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
