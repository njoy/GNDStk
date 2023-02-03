
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
// Alias is the basic handle type in this file. Example:
//    // Create a default Alias object:
//    Alias handle = AliasDefault();
// Functions involving Alias are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_ALIAS
#define C_INTERFACE_ALPHA_V2_0_GENERAL_ALIAS

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct AliasClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Alias
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct AliasClass *Alias;

// --- Const-aware handles.
typedef const struct AliasClass *const ConstHandle2ConstAlias;
typedef       struct AliasClass *const ConstHandle2Alias;
typedef const struct AliasClass *      Handle2ConstAlias;
typedef       struct AliasClass *      Handle2Alias;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstAlias
AliasDefaultConst();

// +++ Create, default
extern_c Handle2Alias
AliasDefault();

// --- Create, general, const
extern_c Handle2ConstAlias
AliasCreateConst(
   const char *const id,
   const char *const pid
);

// +++ Create, general
extern_c Handle2Alias
AliasCreate(
   const char *const id,
   const char *const pid
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
AliasAssign(ConstHandle2Alias This, ConstHandle2ConstAlias from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
AliasDelete(ConstHandle2ConstAlias This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
AliasRead(ConstHandle2Alias This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
AliasWrite(ConstHandle2ConstAlias This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
AliasPrint(ConstHandle2ConstAlias This);

// +++ Print to standard output, as XML
extern_c int
AliasPrintXML(ConstHandle2ConstAlias This);

// +++ Print to standard output, as JSON
extern_c int
AliasPrintJSON(ConstHandle2ConstAlias This);


// -----------------------------------------------------------------------------
// Metadatum: id
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AliasIdHas(ConstHandle2ConstAlias This);

// +++ Get
// +++ Returns by value
extern_c const char *
AliasIdGet(ConstHandle2ConstAlias This);

// +++ Set
extern_c void
AliasIdSet(ConstHandle2Alias This, const char *const id);


// -----------------------------------------------------------------------------
// Metadatum: pid
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AliasPidHas(ConstHandle2ConstAlias This);

// +++ Get
// +++ Returns by value
extern_c const char *
AliasPidGet(ConstHandle2ConstAlias This);

// +++ Set
extern_c void
AliasPidSet(ConstHandle2Alias This, const char *const pid);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Alias/src/custom.h"

#undef extern_c
#endif
