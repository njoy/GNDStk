
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
// AvailableMomentum is the basic handle type in this file. Example:
//    // Create a default AvailableMomentum object:
//    AvailableMomentum handle = AvailableMomentumDefault();
// Functions involving AvailableMomentum are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_PROCESSED_AVAILABLEMOMENTUM
#define C_INTERFACE_TEST_V2_0_PROCESSED_AVAILABLEMOMENTUM

#include "GNDStk.h"
#include "v2.0/containers/XYs1d.h"
#include "v2.0/containers/Gridded1d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct AvailableMomentumClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ AvailableMomentum
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct AvailableMomentumClass *AvailableMomentum;

// --- Const-aware handles.
typedef const struct AvailableMomentumClass *const ConstHandle2ConstAvailableMomentum;
typedef       struct AvailableMomentumClass *const ConstHandle2AvailableMomentum;
typedef const struct AvailableMomentumClass *      Handle2ConstAvailableMomentum;
typedef       struct AvailableMomentumClass *      Handle2AvailableMomentum;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstAvailableMomentum
AvailableMomentumDefaultConst();

// +++ Create, default
extern_c Handle2AvailableMomentum
AvailableMomentumDefault();

// --- Create, general, const
extern_c Handle2ConstAvailableMomentum
AvailableMomentumCreateConst(
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstGridded1d gridded1d
);

// +++ Create, general
extern_c Handle2AvailableMomentum
AvailableMomentumCreate(
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstGridded1d gridded1d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
AvailableMomentumAssign(ConstHandle2AvailableMomentum This, ConstHandle2ConstAvailableMomentum from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
AvailableMomentumDelete(ConstHandle2ConstAvailableMomentum This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
AvailableMomentumRead(ConstHandle2AvailableMomentum This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
AvailableMomentumWrite(ConstHandle2ConstAvailableMomentum This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
AvailableMomentumPrint(ConstHandle2ConstAvailableMomentum This);

// +++ Print to standard output, as XML
extern_c int
AvailableMomentumPrintXML(ConstHandle2ConstAvailableMomentum This);

// +++ Print to standard output, as JSON
extern_c int
AvailableMomentumPrintJSON(ConstHandle2ConstAvailableMomentum This);


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AvailableMomentumXYs1dHas(ConstHandle2ConstAvailableMomentum This);

// --- Get, const
extern_c Handle2ConstXYs1d
AvailableMomentumXYs1dGetConst(ConstHandle2ConstAvailableMomentum This);

// +++ Get, non-const
extern_c Handle2XYs1d
AvailableMomentumXYs1dGet(ConstHandle2AvailableMomentum This);

// +++ Set
extern_c void
AvailableMomentumXYs1dSet(ConstHandle2AvailableMomentum This, ConstHandle2ConstXYs1d XYs1d);


// -----------------------------------------------------------------------------
// Child: gridded1d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AvailableMomentumGridded1dHas(ConstHandle2ConstAvailableMomentum This);

// --- Get, const
extern_c Handle2ConstGridded1d
AvailableMomentumGridded1dGetConst(ConstHandle2ConstAvailableMomentum This);

// +++ Get, non-const
extern_c Handle2Gridded1d
AvailableMomentumGridded1dGet(ConstHandle2AvailableMomentum This);

// +++ Set
extern_c void
AvailableMomentumGridded1dSet(ConstHandle2AvailableMomentum This, ConstHandle2ConstGridded1d gridded1d);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
