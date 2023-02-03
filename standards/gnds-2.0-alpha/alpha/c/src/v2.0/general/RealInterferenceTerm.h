
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
// RealInterferenceTerm is the basic handle type in this file. Example:
//    // Create a default RealInterferenceTerm object:
//    RealInterferenceTerm handle = RealInterferenceTermDefault();
// Functions involving RealInterferenceTerm are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_REALINTERFERENCETERM
#define C_INTERFACE_ALPHA_V2_0_GENERAL_REALINTERFERENCETERM

#include "GNDStk.h"
#include "v2.0/general/Regions2d.h"
#include "v2.0/general/XYs2d.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct RealInterferenceTermClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ RealInterferenceTerm
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct RealInterferenceTermClass *RealInterferenceTerm;

// --- Const-aware handles.
typedef const struct RealInterferenceTermClass *const ConstHandle2ConstRealInterferenceTerm;
typedef       struct RealInterferenceTermClass *const ConstHandle2RealInterferenceTerm;
typedef const struct RealInterferenceTermClass *      Handle2ConstRealInterferenceTerm;
typedef       struct RealInterferenceTermClass *      Handle2RealInterferenceTerm;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstRealInterferenceTerm
RealInterferenceTermDefaultConst();

// +++ Create, default
extern_c Handle2RealInterferenceTerm
RealInterferenceTermDefault();

// --- Create, general, const
extern_c Handle2ConstRealInterferenceTerm
RealInterferenceTermCreateConst(
   ConstHandle2ConstRegions2d regions2d,
   ConstHandle2ConstXYs2d XYs2d
);

// +++ Create, general
extern_c Handle2RealInterferenceTerm
RealInterferenceTermCreate(
   ConstHandle2ConstRegions2d regions2d,
   ConstHandle2ConstXYs2d XYs2d
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
RealInterferenceTermAssign(ConstHandle2RealInterferenceTerm This, ConstHandle2ConstRealInterferenceTerm from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
RealInterferenceTermDelete(ConstHandle2ConstRealInterferenceTerm This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
RealInterferenceTermRead(ConstHandle2RealInterferenceTerm This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
RealInterferenceTermWrite(ConstHandle2ConstRealInterferenceTerm This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
RealInterferenceTermPrint(ConstHandle2ConstRealInterferenceTerm This);

// +++ Print to standard output, as XML
extern_c int
RealInterferenceTermPrintXML(ConstHandle2ConstRealInterferenceTerm This);

// +++ Print to standard output, as JSON
extern_c int
RealInterferenceTermPrintJSON(ConstHandle2ConstRealInterferenceTerm This);


// -----------------------------------------------------------------------------
// Child: regions2d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
RealInterferenceTermRegions2dHas(ConstHandle2ConstRealInterferenceTerm This);

// --- Get, const
extern_c Handle2ConstRegions2d
RealInterferenceTermRegions2dGetConst(ConstHandle2ConstRealInterferenceTerm This);

// +++ Get, non-const
extern_c Handle2Regions2d
RealInterferenceTermRegions2dGet(ConstHandle2RealInterferenceTerm This);

// +++ Set
extern_c void
RealInterferenceTermRegions2dSet(ConstHandle2RealInterferenceTerm This, ConstHandle2ConstRegions2d regions2d);


// -----------------------------------------------------------------------------
// Child: XYs2d
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
RealInterferenceTermXYs2dHas(ConstHandle2ConstRealInterferenceTerm This);

// --- Get, const
extern_c Handle2ConstXYs2d
RealInterferenceTermXYs2dGetConst(ConstHandle2ConstRealInterferenceTerm This);

// +++ Get, non-const
extern_c Handle2XYs2d
RealInterferenceTermXYs2dGet(ConstHandle2RealInterferenceTerm This);

// +++ Set
extern_c void
RealInterferenceTermXYs2dSet(ConstHandle2RealInterferenceTerm This, ConstHandle2ConstXYs2d XYs2d);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/RealInterferenceTerm/src/custom.h"

#undef extern_c
#endif
