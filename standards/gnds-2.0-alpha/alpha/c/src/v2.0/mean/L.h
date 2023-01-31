
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
// L is the basic handle type in this file. Example:
//    // Create a default L object:
//    L handle = LDefault();
// Functions involving L are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_MEAN_L
#define C_INTERFACE_ALPHA_V2_0_MEAN_L

#include "GNDStk.h"
#include "v2.0/mean/Js.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct LClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ L
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct LClass *L;

// --- Const-aware handles.
typedef const struct LClass *const ConstHandle2ConstL;
typedef       struct LClass *const ConstHandle2L;
typedef const struct LClass *      Handle2ConstL;
typedef       struct LClass *      Handle2L;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstL
LDefaultConst();

// +++ Create, default
extern_c Handle2L
LDefault();

// --- Create, general, const
extern_c Handle2ConstL
LCreateConst(
   const char *const label,
   const int value,
   ConstHandle2ConstJs Js
);

// +++ Create, general
extern_c Handle2L
LCreate(
   const char *const label,
   const int value,
   ConstHandle2ConstJs Js
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
LAssign(ConstHandle2L This, ConstHandle2ConstL from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
LDelete(ConstHandle2ConstL This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
LRead(ConstHandle2L This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
LWrite(ConstHandle2ConstL This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
LPrint(ConstHandle2ConstL This);

// +++ Print to standard output, as XML
extern_c int
LPrintXML(ConstHandle2ConstL This);

// +++ Print to standard output, as JSON
extern_c int
LPrintJSON(ConstHandle2ConstL This);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
LLabelHas(ConstHandle2ConstL This);

// +++ Get
// +++ Returns by value
extern_c const char *
LLabelGet(ConstHandle2ConstL This);

// +++ Set
extern_c void
LLabelSet(ConstHandle2L This, const char *const label);


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
LValueHas(ConstHandle2ConstL This);

// +++ Get
// +++ Returns by value
extern_c int
LValueGet(ConstHandle2ConstL This);

// +++ Set
extern_c void
LValueSet(ConstHandle2L This, const int value);


// -----------------------------------------------------------------------------
// Child: Js
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
LJsHas(ConstHandle2ConstL This);

// --- Get, const
extern_c Handle2ConstJs
LJsGetConst(ConstHandle2ConstL This);

// +++ Get, non-const
extern_c Handle2Js
LJsGet(ConstHandle2L This);

// +++ Set
extern_c void
LJsSet(ConstHandle2L This, ConstHandle2ConstJs Js);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/mean/L/src/custom.h"

#undef extern_c
#endif
