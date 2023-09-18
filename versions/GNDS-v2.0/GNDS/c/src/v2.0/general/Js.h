
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
// Js is the basic handle type in this file. Example:
//    // Create a default Js object:
//    Js handle = JsDefault();
// Functions involving Js are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_JS
#define C_INTERFACE_GNDS_V2_0_GENERAL_JS

#include "GNDStk.h"
#include "v2.0/general/J.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct JsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Js
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct JsClass *Js;

// --- Const-aware handles.
typedef const struct JsClass *const ConstHandle2ConstJs;
typedef       struct JsClass *const ConstHandle2Js;
typedef const struct JsClass *      Handle2ConstJs;
typedef       struct JsClass *      Handle2Js;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstJs
JsDefaultConst();

// +++ Create, default
extern_c Handle2Js
JsDefault();

// --- Create, general, const
extern_c Handle2ConstJs
JsCreateConst(
   ConstHandle2J *const J, const size_t JSize
);

// +++ Create, general
extern_c Handle2Js
JsCreate(
   ConstHandle2J *const J, const size_t JSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
JsAssign(ConstHandle2Js self, ConstHandle2ConstJs from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
JsDelete(ConstHandle2ConstJs self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
JsRead(ConstHandle2Js self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
JsWrite(ConstHandle2ConstJs self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
JsPrint(ConstHandle2ConstJs self);

// +++ Print to standard output, as XML
extern_c int
JsPrintXML(ConstHandle2ConstJs self);

// +++ Print to standard output, as JSON
extern_c int
JsPrintJSON(ConstHandle2ConstJs self);


// -----------------------------------------------------------------------------
// Child: J
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
JsJHas(ConstHandle2ConstJs self);

// +++ Clear
extern_c void
JsJClear(ConstHandle2Js self);

// +++ Size
extern_c size_t
JsJSize(ConstHandle2ConstJs self);

// +++ Add
extern_c void
JsJAdd(ConstHandle2Js self, ConstHandle2ConstJ J);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstJ
JsJGetConst(ConstHandle2ConstJs self, const size_t index_);

// +++ Get, by index \in [0,size)
extern_c Handle2J
JsJGet(ConstHandle2Js self, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
JsJSet(
   ConstHandle2Js self,
   const size_t index_,
   ConstHandle2ConstJ J
);

// +++ Has, by label
extern_c int
JsJHasByLabel(
   ConstHandle2ConstJs self,
   const char *const label
);

// --- Get, by label, const
extern_c Handle2ConstJ
JsJGetByLabelConst(
   ConstHandle2ConstJs self,
   const char *const label
);

// +++ Get, by label
extern_c Handle2J
JsJGetByLabel(
   ConstHandle2Js self,
   const char *const label
);

// +++ Set, by label
extern_c void
JsJSetByLabel(
   ConstHandle2Js self,
   const char *const label,
   ConstHandle2ConstJ J
);

// +++ Has, by value
extern_c int
JsJHasByValue(
   ConstHandle2ConstJs self,
   const int value
);

// --- Get, by value, const
extern_c Handle2ConstJ
JsJGetByValueConst(
   ConstHandle2ConstJs self,
   const int value
);

// +++ Get, by value
extern_c Handle2J
JsJGetByValue(
   ConstHandle2Js self,
   const int value
);

// +++ Set, by value
extern_c void
JsJSetByValue(
   ConstHandle2Js self,
   const int value,
   ConstHandle2ConstJ J
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Js/src/custom.h"

#undef extern_c
#endif
