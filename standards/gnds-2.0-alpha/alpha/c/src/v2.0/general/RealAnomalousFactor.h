
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
// RealAnomalousFactor is the basic handle type in this file. Example:
//    // Create a default RealAnomalousFactor object:
//    RealAnomalousFactor handle = RealAnomalousFactorDefault();
// Functions involving RealAnomalousFactor are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_REALANOMALOUSFACTOR
#define C_INTERFACE_ALPHA_V2_0_GENERAL_REALANOMALOUSFACTOR

#include "GNDStk.h"
#include "v2.0/general/XYs1d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct RealAnomalousFactorClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ RealAnomalousFactor
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct RealAnomalousFactorClass *RealAnomalousFactor;

// --- Const-aware handles.
typedef const struct RealAnomalousFactorClass *const ConstHandle2ConstRealAnomalousFactor;
typedef       struct RealAnomalousFactorClass *const ConstHandle2RealAnomalousFactor;
typedef const struct RealAnomalousFactorClass *      Handle2ConstRealAnomalousFactor;
typedef       struct RealAnomalousFactorClass *      Handle2RealAnomalousFactor;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstRealAnomalousFactor
RealAnomalousFactorDefaultConst();

// +++ Create, default
extern_c Handle2RealAnomalousFactor
RealAnomalousFactorDefault();

// --- Create, general, const
extern_c Handle2ConstRealAnomalousFactor
RealAnomalousFactorCreateConst(
   ConstHandle2ConstXYs1d XYs1d
);

// +++ Create, general
extern_c Handle2RealAnomalousFactor
RealAnomalousFactorCreate(
   ConstHandle2ConstXYs1d XYs1d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
RealAnomalousFactorAssign(ConstHandle2RealAnomalousFactor This, ConstHandle2ConstRealAnomalousFactor from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
RealAnomalousFactorDelete(ConstHandle2ConstRealAnomalousFactor This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
RealAnomalousFactorRead(ConstHandle2RealAnomalousFactor This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
RealAnomalousFactorWrite(ConstHandle2ConstRealAnomalousFactor This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
RealAnomalousFactorPrint(ConstHandle2ConstRealAnomalousFactor This);

// +++ Print to standard output, as XML
extern_c int
RealAnomalousFactorPrintXML(ConstHandle2ConstRealAnomalousFactor This);

// +++ Print to standard output, as JSON
extern_c int
RealAnomalousFactorPrintJSON(ConstHandle2ConstRealAnomalousFactor This);


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
RealAnomalousFactorXYs1dHas(ConstHandle2ConstRealAnomalousFactor This);

// --- Get, const
extern_c Handle2ConstXYs1d
RealAnomalousFactorXYs1dGetConst(ConstHandle2ConstRealAnomalousFactor This);

// +++ Get, non-const
extern_c Handle2XYs1d
RealAnomalousFactorXYs1dGet(ConstHandle2RealAnomalousFactor This);

// +++ Set
extern_c void
RealAnomalousFactorXYs1dSet(ConstHandle2RealAnomalousFactor This, ConstHandle2ConstXYs1d XYs1d);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/RealAnomalousFactor/src/custom.h"

#undef extern_c
#endif
