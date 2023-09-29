
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
// Unorthodoxes is the basic handle type in this file. Example:
//    // Create a default Unorthodoxes object:
//    Unorthodoxes handle = UnorthodoxesDefault();
// Functions involving Unorthodoxes are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_UNORTHODOXES
#define C_INTERFACE_GNDS_V2_0_GENERAL_UNORTHODOXES

#include "GNDStk.h"
#include "v2.0/general/Unorthodox.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct UnorthodoxesClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Unorthodoxes
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct UnorthodoxesClass *Unorthodoxes;

// --- Const-aware handles.
typedef const struct UnorthodoxesClass *const ConstHandle2ConstUnorthodoxes;
typedef       struct UnorthodoxesClass *const ConstHandle2Unorthodoxes;
typedef const struct UnorthodoxesClass *      Handle2ConstUnorthodoxes;
typedef       struct UnorthodoxesClass *      Handle2Unorthodoxes;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstUnorthodoxes
UnorthodoxesDefaultConst();

// +++ Create, default
extern_c Handle2Unorthodoxes
UnorthodoxesDefault();

// --- Create, general, const
extern_c Handle2ConstUnorthodoxes
UnorthodoxesCreateConst(
   ConstHandle2Unorthodox *const unorthodox, const size_t unorthodoxSize
);

// +++ Create, general
extern_c Handle2Unorthodoxes
UnorthodoxesCreate(
   ConstHandle2Unorthodox *const unorthodox, const size_t unorthodoxSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
UnorthodoxesAssign(ConstHandle2Unorthodoxes self, ConstHandle2ConstUnorthodoxes from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
UnorthodoxesDelete(ConstHandle2ConstUnorthodoxes self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
UnorthodoxesRead(ConstHandle2Unorthodoxes self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
UnorthodoxesWrite(ConstHandle2ConstUnorthodoxes self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
UnorthodoxesPrint(ConstHandle2ConstUnorthodoxes self);

// +++ Print to standard output, as XML
extern_c int
UnorthodoxesPrintXML(ConstHandle2ConstUnorthodoxes self);

// +++ Print to standard output, as JSON
extern_c int
UnorthodoxesPrintJSON(ConstHandle2ConstUnorthodoxes self);


// -----------------------------------------------------------------------------
// Child: unorthodox
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
UnorthodoxesUnorthodoxHas(ConstHandle2ConstUnorthodoxes self);

// +++ Clear
extern_c void
UnorthodoxesUnorthodoxClear(ConstHandle2Unorthodoxes self);

// +++ Size
extern_c size_t
UnorthodoxesUnorthodoxSize(ConstHandle2ConstUnorthodoxes self);

// +++ Add
extern_c void
UnorthodoxesUnorthodoxAdd(ConstHandle2Unorthodoxes self, ConstHandle2ConstUnorthodox unorthodox);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstUnorthodox
UnorthodoxesUnorthodoxGetConst(ConstHandle2ConstUnorthodoxes self, const size_t index_);

// +++ Get, by index \in [0,size)
extern_c Handle2Unorthodox
UnorthodoxesUnorthodoxGet(ConstHandle2Unorthodoxes self, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
UnorthodoxesUnorthodoxSet(
   ConstHandle2Unorthodoxes self,
   const size_t index_,
   ConstHandle2ConstUnorthodox unorthodox
);

// ------------------------
// Re: metadatum id
// ------------------------

// +++ Has, by id
extern_c int
UnorthodoxesUnorthodoxHasById(
   ConstHandle2ConstUnorthodoxes self,
   const char *const id
);

// --- Get, by id, const
extern_c Handle2ConstUnorthodox
UnorthodoxesUnorthodoxGetByIdConst(
   ConstHandle2ConstUnorthodoxes self,
   const char *const id
);

// +++ Get, by id
extern_c Handle2Unorthodox
UnorthodoxesUnorthodoxGetById(
   ConstHandle2Unorthodoxes self,
   const char *const id
);

// +++ Set, by id
extern_c void
UnorthodoxesUnorthodoxSetById(
   ConstHandle2Unorthodoxes self,
   const char *const id,
   ConstHandle2ConstUnorthodox unorthodox
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Unorthodoxes/src/custom.h"

#undef extern_c
#endif
