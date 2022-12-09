
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
// AverageProductMomentum is the basic handle type in this file. Example:
//    // Create a default AverageProductMomentum object:
//    AverageProductMomentum handle = AverageProductMomentumDefault();
// Functions involving AverageProductMomentum are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_PROCESSED_AVERAGEPRODUCTMOMENTUM
#define C_INTERFACE_TEST_V2_0_PROCESSED_AVERAGEPRODUCTMOMENTUM

#include "GNDStk.h"
#include "v2.0/containers/XYs1d.h"
#include "v2.0/containers/Gridded1d.h"
#include "v2.0/containers/Regions1d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct AverageProductMomentumClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ AverageProductMomentum
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct AverageProductMomentumClass *AverageProductMomentum;

// --- Const-aware handles.
typedef const struct AverageProductMomentumClass *const ConstHandle2ConstAverageProductMomentum;
typedef       struct AverageProductMomentumClass *const ConstHandle2AverageProductMomentum;
typedef const struct AverageProductMomentumClass *      Handle2ConstAverageProductMomentum;
typedef       struct AverageProductMomentumClass *      Handle2AverageProductMomentum;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstAverageProductMomentum
AverageProductMomentumDefaultConst();

// +++ Create, default
extern_c Handle2AverageProductMomentum
AverageProductMomentumDefault();

// --- Create, general, const
extern_c Handle2ConstAverageProductMomentum
AverageProductMomentumCreateConst(
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstGridded1d gridded1d,
   ConstHandle2ConstRegions1d regions1d
);

// +++ Create, general
extern_c Handle2AverageProductMomentum
AverageProductMomentumCreate(
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstGridded1d gridded1d,
   ConstHandle2ConstRegions1d regions1d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
AverageProductMomentumAssign(ConstHandle2AverageProductMomentum This, ConstHandle2ConstAverageProductMomentum from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
AverageProductMomentumDelete(ConstHandle2ConstAverageProductMomentum This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
AverageProductMomentumRead(ConstHandle2AverageProductMomentum This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
AverageProductMomentumWrite(ConstHandle2ConstAverageProductMomentum This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
AverageProductMomentumPrint(ConstHandle2ConstAverageProductMomentum This);

// +++ Print to standard output, as XML
extern_c int
AverageProductMomentumPrintXML(ConstHandle2ConstAverageProductMomentum This);

// +++ Print to standard output, as JSON
extern_c int
AverageProductMomentumPrintJSON(ConstHandle2ConstAverageProductMomentum This);


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AverageProductMomentumXYs1dHas(ConstHandle2ConstAverageProductMomentum This);

// --- Get, const
extern_c Handle2ConstXYs1d
AverageProductMomentumXYs1dGetConst(ConstHandle2ConstAverageProductMomentum This);

// +++ Get, non-const
extern_c Handle2XYs1d
AverageProductMomentumXYs1dGet(ConstHandle2AverageProductMomentum This);

// +++ Set
extern_c void
AverageProductMomentumXYs1dSet(ConstHandle2AverageProductMomentum This, ConstHandle2ConstXYs1d XYs1d);


// -----------------------------------------------------------------------------
// Child: gridded1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AverageProductMomentumGridded1dHas(ConstHandle2ConstAverageProductMomentum This);

// --- Get, const
extern_c Handle2ConstGridded1d
AverageProductMomentumGridded1dGetConst(ConstHandle2ConstAverageProductMomentum This);

// +++ Get, non-const
extern_c Handle2Gridded1d
AverageProductMomentumGridded1dGet(ConstHandle2AverageProductMomentum This);

// +++ Set
extern_c void
AverageProductMomentumGridded1dSet(ConstHandle2AverageProductMomentum This, ConstHandle2ConstGridded1d gridded1d);


// -----------------------------------------------------------------------------
// Child: regions1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AverageProductMomentumRegions1dHas(ConstHandle2ConstAverageProductMomentum This);

// --- Get, const
extern_c Handle2ConstRegions1d
AverageProductMomentumRegions1dGetConst(ConstHandle2ConstAverageProductMomentum This);

// +++ Get, non-const
extern_c Handle2Regions1d
AverageProductMomentumRegions1dGet(ConstHandle2AverageProductMomentum This);

// +++ Set
extern_c void
AverageProductMomentumRegions1dSet(ConstHandle2AverageProductMomentum This, ConstHandle2ConstRegions1d regions1d);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
