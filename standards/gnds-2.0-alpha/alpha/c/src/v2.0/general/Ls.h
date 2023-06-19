
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
// Ls is the basic handle type in this file. Example:
//    // Create a default Ls object:
//    Ls handle = LsDefault();
// Functions involving Ls are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_LS
#define C_INTERFACE_ALPHA_V2_0_GENERAL_LS

#include "GNDStk.h"
#include "v2.0/general/L.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct LsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Ls
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct LsClass *Ls;

// --- Const-aware handles.
typedef const struct LsClass *const ConstHandle2ConstLs;
typedef       struct LsClass *const ConstHandle2Ls;
typedef const struct LsClass *      Handle2ConstLs;
typedef       struct LsClass *      Handle2Ls;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstLs
LsDefaultConst();

// +++ Create, default
extern_c Handle2Ls
LsDefault();

// --- Create, general, const
extern_c Handle2ConstLs
LsCreateConst(
   ConstHandle2L *const L, const size_t LSize
);

// +++ Create, general
extern_c Handle2Ls
LsCreate(
   ConstHandle2L *const L, const size_t LSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
LsAssign(ConstHandle2Ls self, ConstHandle2ConstLs from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
LsDelete(ConstHandle2ConstLs self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
LsRead(ConstHandle2Ls self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
LsWrite(ConstHandle2ConstLs self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
LsPrint(ConstHandle2ConstLs self);

// +++ Print to standard output, as XML
extern_c int
LsPrintXML(ConstHandle2ConstLs self);

// +++ Print to standard output, as JSON
extern_c int
LsPrintJSON(ConstHandle2ConstLs self);


// -----------------------------------------------------------------------------
// Child: L
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
LsLHas(ConstHandle2ConstLs self);

// +++ Clear
extern_c void
LsLClear(ConstHandle2Ls self);

// +++ Size
extern_c size_t
LsLSize(ConstHandle2ConstLs self);

// +++ Add
extern_c void
LsLAdd(ConstHandle2Ls self, ConstHandle2ConstL L);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstL
LsLGetConst(ConstHandle2ConstLs self, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2L
LsLGet(ConstHandle2Ls self, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
LsLSet(
   ConstHandle2Ls self,
   const size_t index_,
   ConstHandle2ConstL L
);

// +++ Has, by label
extern_c int
LsLHasByLabel(
   ConstHandle2ConstLs self,
   const char *const label
);

// --- Get, by label, const
extern_c Handle2ConstL
LsLGetByLabelConst(
   ConstHandle2ConstLs self,
   const char *const label
);

// +++ Get, by label, non-const
extern_c Handle2L
LsLGetByLabel(
   ConstHandle2Ls self,
   const char *const label
);

// +++ Set, by label
extern_c void
LsLSetByLabel(
   ConstHandle2Ls self,
   const char *const label,
   ConstHandle2ConstL L
);

// +++ Has, by value
extern_c int
LsLHasByValue(
   ConstHandle2ConstLs self,
   const int value
);

// --- Get, by value, const
extern_c Handle2ConstL
LsLGetByValueConst(
   ConstHandle2ConstLs self,
   const int value
);

// +++ Get, by value, non-const
extern_c Handle2L
LsLGetByValue(
   ConstHandle2Ls self,
   const int value
);

// +++ Set, by value
extern_c void
LsLSetByValue(
   ConstHandle2Ls self,
   const int value,
   ConstHandle2ConstL L
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Ls/src/custom.h"

#undef extern_c
#endif
