
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
// Aliases is the basic handle type in this file. Example:
//    // Create a default Aliases object:
//    Aliases handle = AliasesDefault();
// Functions involving Aliases are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_ALIASES
#define C_INTERFACE_GNDS_V2_0_GENERAL_ALIASES

#include "GNDStk.h"
#include "v2.0/general/Alias.h"
#include "v2.0/general/MetaStable.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct AliasesClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Aliases
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct AliasesClass *Aliases;

// --- Const-aware handles.
typedef const struct AliasesClass *const ConstHandle2ConstAliases;
typedef       struct AliasesClass *const ConstHandle2Aliases;
typedef const struct AliasesClass *      Handle2ConstAliases;
typedef       struct AliasesClass *      Handle2Aliases;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstAliases
AliasesDefaultConst();

// +++ Create, default
extern_c Handle2Aliases
AliasesDefault();

// --- Create, general, const
extern_c Handle2ConstAliases
AliasesCreateConst(
   ConstHandle2Alias *const alias, const size_t aliasSize,
   ConstHandle2MetaStable *const metaStable, const size_t metaStableSize
);

// +++ Create, general
extern_c Handle2Aliases
AliasesCreate(
   ConstHandle2Alias *const alias, const size_t aliasSize,
   ConstHandle2MetaStable *const metaStable, const size_t metaStableSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
AliasesAssign(ConstHandle2Aliases self, ConstHandle2ConstAliases from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
AliasesDelete(ConstHandle2ConstAliases self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
AliasesRead(ConstHandle2Aliases self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
AliasesWrite(ConstHandle2ConstAliases self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
AliasesPrint(ConstHandle2ConstAliases self);

// +++ Print to standard output, as XML
extern_c int
AliasesPrintXML(ConstHandle2ConstAliases self);

// +++ Print to standard output, as JSON
extern_c int
AliasesPrintJSON(ConstHandle2ConstAliases self);


// -----------------------------------------------------------------------------
// Child: alias
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AliasesAliasHas(ConstHandle2ConstAliases self);

// +++ Clear
extern_c void
AliasesAliasClear(ConstHandle2Aliases self);

// +++ Size
extern_c size_t
AliasesAliasSize(ConstHandle2ConstAliases self);

// +++ Add
extern_c void
AliasesAliasAdd(ConstHandle2Aliases self, ConstHandle2ConstAlias alias);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstAlias
AliasesAliasGetConst(ConstHandle2ConstAliases self, const size_t index_);

// +++ Get, by index \in [0,size)
extern_c Handle2Alias
AliasesAliasGet(ConstHandle2Aliases self, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
AliasesAliasSet(
   ConstHandle2Aliases self,
   const size_t index_,
   ConstHandle2ConstAlias alias
);

// +++ Has, by id
extern_c int
AliasesAliasHasById(
   ConstHandle2ConstAliases self,
   const char *const id
);

// --- Get, by id, const
extern_c Handle2ConstAlias
AliasesAliasGetByIdConst(
   ConstHandle2ConstAliases self,
   const char *const id
);

// +++ Get, by id
extern_c Handle2Alias
AliasesAliasGetById(
   ConstHandle2Aliases self,
   const char *const id
);

// +++ Set, by id
extern_c void
AliasesAliasSetById(
   ConstHandle2Aliases self,
   const char *const id,
   ConstHandle2ConstAlias alias
);

// +++ Has, by pid
extern_c int
AliasesAliasHasByPid(
   ConstHandle2ConstAliases self,
   const char *const pid
);

// --- Get, by pid, const
extern_c Handle2ConstAlias
AliasesAliasGetByPidConst(
   ConstHandle2ConstAliases self,
   const char *const pid
);

// +++ Get, by pid
extern_c Handle2Alias
AliasesAliasGetByPid(
   ConstHandle2Aliases self,
   const char *const pid
);

// +++ Set, by pid
extern_c void
AliasesAliasSetByPid(
   ConstHandle2Aliases self,
   const char *const pid,
   ConstHandle2ConstAlias alias
);


// -----------------------------------------------------------------------------
// Child: metaStable
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AliasesMetaStableHas(ConstHandle2ConstAliases self);

// +++ Clear
extern_c void
AliasesMetaStableClear(ConstHandle2Aliases self);

// +++ Size
extern_c size_t
AliasesMetaStableSize(ConstHandle2ConstAliases self);

// +++ Add
extern_c void
AliasesMetaStableAdd(ConstHandle2Aliases self, ConstHandle2ConstMetaStable metaStable);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstMetaStable
AliasesMetaStableGetConst(ConstHandle2ConstAliases self, const size_t index_);

// +++ Get, by index \in [0,size)
extern_c Handle2MetaStable
AliasesMetaStableGet(ConstHandle2Aliases self, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
AliasesMetaStableSet(
   ConstHandle2Aliases self,
   const size_t index_,
   ConstHandle2ConstMetaStable metaStable
);

// +++ Has, by id
extern_c int
AliasesMetaStableHasById(
   ConstHandle2ConstAliases self,
   const char *const id
);

// --- Get, by id, const
extern_c Handle2ConstMetaStable
AliasesMetaStableGetByIdConst(
   ConstHandle2ConstAliases self,
   const char *const id
);

// +++ Get, by id
extern_c Handle2MetaStable
AliasesMetaStableGetById(
   ConstHandle2Aliases self,
   const char *const id
);

// +++ Set, by id
extern_c void
AliasesMetaStableSetById(
   ConstHandle2Aliases self,
   const char *const id,
   ConstHandle2ConstMetaStable metaStable
);

// +++ Has, by pid
extern_c int
AliasesMetaStableHasByPid(
   ConstHandle2ConstAliases self,
   const char *const pid
);

// --- Get, by pid, const
extern_c Handle2ConstMetaStable
AliasesMetaStableGetByPidConst(
   ConstHandle2ConstAliases self,
   const char *const pid
);

// +++ Get, by pid
extern_c Handle2MetaStable
AliasesMetaStableGetByPid(
   ConstHandle2Aliases self,
   const char *const pid
);

// +++ Set, by pid
extern_c void
AliasesMetaStableSetByPid(
   ConstHandle2Aliases self,
   const char *const pid,
   ConstHandle2ConstMetaStable metaStable
);

// +++ Has, by metaStableIndex
extern_c int
AliasesMetaStableHasByMetaStableIndex(
   ConstHandle2ConstAliases self,
   const int metaStableIndex
);

// --- Get, by metaStableIndex, const
extern_c Handle2ConstMetaStable
AliasesMetaStableGetByMetaStableIndexConst(
   ConstHandle2ConstAliases self,
   const int metaStableIndex
);

// +++ Get, by metaStableIndex
extern_c Handle2MetaStable
AliasesMetaStableGetByMetaStableIndex(
   ConstHandle2Aliases self,
   const int metaStableIndex
);

// +++ Set, by metaStableIndex
extern_c void
AliasesMetaStableSetByMetaStableIndex(
   ConstHandle2Aliases self,
   const int metaStableIndex,
   ConstHandle2ConstMetaStable metaStable
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Aliases/src/custom.h"

#undef extern_c
#endif
