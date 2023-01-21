
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
// Standard is the basic handle type in this file. Example:
//    // Create a default Standard object:
//    Standard handle = StandardDefault();
// Functions involving Standard are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_POPS_STANDARD
#define C_INTERFACE_TEST_V2_0_POPS_STANDARD

#include "GNDStk.h"
#include "v2.0/extra/Double.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct StandardClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Standard
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct StandardClass *Standard;

// --- Const-aware handles.
typedef const struct StandardClass *const ConstHandle2ConstStandard;
typedef       struct StandardClass *const ConstHandle2Standard;
typedef const struct StandardClass *      Handle2ConstStandard;
typedef       struct StandardClass *      Handle2Standard;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstStandard
StandardDefaultConst();

// +++ Create, default
extern_c Handle2Standard
StandardDefault();

// --- Create, general, const
extern_c Handle2ConstStandard
StandardCreateConst(
   ConstHandle2ConstDouble Double
);

// +++ Create, general
extern_c Handle2Standard
StandardCreate(
   ConstHandle2ConstDouble Double
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
StandardAssign(ConstHandle2Standard This, ConstHandle2ConstStandard from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
StandardDelete(ConstHandle2ConstStandard This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
StandardRead(ConstHandle2Standard This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
StandardWrite(ConstHandle2ConstStandard This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
StandardPrint(ConstHandle2ConstStandard This);

// +++ Print to standard output, as XML
extern_c int
StandardPrintXML(ConstHandle2ConstStandard This);

// +++ Print to standard output, as JSON
extern_c int
StandardPrintJSON(ConstHandle2ConstStandard This);


// -----------------------------------------------------------------------------
// Child: Double
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
StandardDoubleHas(ConstHandle2ConstStandard This);

// --- Get, const
extern_c Handle2ConstDouble
StandardDoubleGetConst(ConstHandle2ConstStandard This);

// +++ Get, non-const
extern_c Handle2Double
StandardDoubleGet(ConstHandle2Standard This);

// +++ Set
extern_c void
StandardDoubleSet(ConstHandle2Standard This, ConstHandle2ConstDouble Double);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/pops/Standard/src/custom.h"

#undef extern_c
#endif
