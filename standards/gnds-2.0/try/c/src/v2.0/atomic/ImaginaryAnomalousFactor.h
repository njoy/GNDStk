
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
// ImaginaryAnomalousFactor is the basic handle type in this file. Example:
//    // Create a default ImaginaryAnomalousFactor object:
//    ImaginaryAnomalousFactor handle = ImaginaryAnomalousFactorDefault();
// Functions involving ImaginaryAnomalousFactor are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_ATOMIC_IMAGINARYANOMALOUSFACTOR
#define C_INTERFACE_TRY_V2_0_ATOMIC_IMAGINARYANOMALOUSFACTOR

#include "GNDStk.h"
#include "v2.0/containers/XYs1d.h"
#include "v2.0/containers/Regions1d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ImaginaryAnomalousFactorClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ImaginaryAnomalousFactor
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ImaginaryAnomalousFactorClass *ImaginaryAnomalousFactor;

// --- Const-aware handles.
typedef const struct ImaginaryAnomalousFactorClass *const ConstHandle2ConstImaginaryAnomalousFactor;
typedef       struct ImaginaryAnomalousFactorClass *const ConstHandle2ImaginaryAnomalousFactor;
typedef const struct ImaginaryAnomalousFactorClass *      Handle2ConstImaginaryAnomalousFactor;
typedef       struct ImaginaryAnomalousFactorClass *      Handle2ImaginaryAnomalousFactor;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstImaginaryAnomalousFactor
ImaginaryAnomalousFactorDefaultConst();

// +++ Create, default
extern_c Handle2ImaginaryAnomalousFactor
ImaginaryAnomalousFactorDefault();

// --- Create, general, const
extern_c Handle2ConstImaginaryAnomalousFactor
ImaginaryAnomalousFactorCreateConst(
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstRegions1d regions1d
);

// +++ Create, general
extern_c Handle2ImaginaryAnomalousFactor
ImaginaryAnomalousFactorCreate(
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstRegions1d regions1d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ImaginaryAnomalousFactorAssign(ConstHandle2ImaginaryAnomalousFactor This, ConstHandle2ConstImaginaryAnomalousFactor from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ImaginaryAnomalousFactorDelete(ConstHandle2ConstImaginaryAnomalousFactor This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ImaginaryAnomalousFactorRead(ConstHandle2ImaginaryAnomalousFactor This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ImaginaryAnomalousFactorWrite(ConstHandle2ConstImaginaryAnomalousFactor This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ImaginaryAnomalousFactorPrint(ConstHandle2ConstImaginaryAnomalousFactor This);

// +++ Print to standard output, as XML
extern_c int
ImaginaryAnomalousFactorPrintXML(ConstHandle2ConstImaginaryAnomalousFactor This);

// +++ Print to standard output, as JSON
extern_c int
ImaginaryAnomalousFactorPrintJSON(ConstHandle2ConstImaginaryAnomalousFactor This);


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ImaginaryAnomalousFactorXYs1dHas(ConstHandle2ConstImaginaryAnomalousFactor This);

// --- Get, const
extern_c Handle2ConstXYs1d
ImaginaryAnomalousFactorXYs1dGetConst(ConstHandle2ConstImaginaryAnomalousFactor This);

// +++ Get, non-const
extern_c Handle2XYs1d
ImaginaryAnomalousFactorXYs1dGet(ConstHandle2ImaginaryAnomalousFactor This);

// +++ Set
extern_c void
ImaginaryAnomalousFactorXYs1dSet(ConstHandle2ImaginaryAnomalousFactor This, ConstHandle2ConstXYs1d XYs1d);


// -----------------------------------------------------------------------------
// Child: regions1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ImaginaryAnomalousFactorRegions1dHas(ConstHandle2ConstImaginaryAnomalousFactor This);

// --- Get, const
extern_c Handle2ConstRegions1d
ImaginaryAnomalousFactorRegions1dGetConst(ConstHandle2ConstImaginaryAnomalousFactor This);

// +++ Get, non-const
extern_c Handle2Regions1d
ImaginaryAnomalousFactorRegions1dGet(ConstHandle2ImaginaryAnomalousFactor This);

// +++ Set
extern_c void
ImaginaryAnomalousFactorRegions1dSet(ConstHandle2ImaginaryAnomalousFactor This, ConstHandle2ConstRegions1d regions1d);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif