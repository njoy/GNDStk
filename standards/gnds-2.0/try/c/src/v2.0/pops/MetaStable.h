
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
// MetaStable is the basic handle type in this file. Example:
//    // Create a default MetaStable object:
//    MetaStable handle = MetaStableDefault();
// Functions involving MetaStable are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_POPS_METASTABLE
#define C_INTERFACE_TRY_V2_0_POPS_METASTABLE

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct MetaStableClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ MetaStable
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct MetaStableClass *MetaStable;

// --- Const-aware handles.
typedef const struct MetaStableClass *const ConstHandle2ConstMetaStable;
typedef       struct MetaStableClass *const ConstHandle2MetaStable;
typedef const struct MetaStableClass *      Handle2ConstMetaStable;
typedef       struct MetaStableClass *      Handle2MetaStable;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstMetaStable
MetaStableDefaultConst();

// +++ Create, default
extern_c Handle2MetaStable
MetaStableDefault();

// --- Create, general, const
extern_c Handle2ConstMetaStable
MetaStableCreateConst(
   const XMLName id,
   const Integer32 metaStableIndex,
   const XMLName pid
);

// +++ Create, general
extern_c Handle2MetaStable
MetaStableCreate(
   const XMLName id,
   const Integer32 metaStableIndex,
   const XMLName pid
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
MetaStableAssign(ConstHandle2MetaStable This, ConstHandle2ConstMetaStable from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
MetaStableDelete(ConstHandle2ConstMetaStable This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
MetaStableRead(ConstHandle2MetaStable This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
MetaStableWrite(ConstHandle2ConstMetaStable This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
MetaStablePrint(ConstHandle2ConstMetaStable This);

// +++ Print to standard output, as XML
extern_c int
MetaStablePrintXML(ConstHandle2ConstMetaStable This);

// +++ Print to standard output, as JSON
extern_c int
MetaStablePrintJSON(ConstHandle2ConstMetaStable This);


// -----------------------------------------------------------------------------
// Metadatum: id
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MetaStableIdHas(ConstHandle2ConstMetaStable This);

// +++ Get
// +++ Returns by value
extern_c XMLName
MetaStableIdGet(ConstHandle2ConstMetaStable This);

// +++ Set
extern_c void
MetaStableIdSet(ConstHandle2MetaStable This, const XMLName id);


// -----------------------------------------------------------------------------
// Metadatum: metaStableIndex
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MetaStableMetaStableIndexHas(ConstHandle2ConstMetaStable This);

// +++ Get
// +++ Returns by value
extern_c Integer32
MetaStableMetaStableIndexGet(ConstHandle2ConstMetaStable This);

// +++ Set
extern_c void
MetaStableMetaStableIndexSet(ConstHandle2MetaStable This, const Integer32 metaStableIndex);


// -----------------------------------------------------------------------------
// Metadatum: pid
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
MetaStablePidHas(ConstHandle2ConstMetaStable This);

// +++ Get
// +++ Returns by value
extern_c XMLName
MetaStablePidGet(ConstHandle2ConstMetaStable This);

// +++ Set
extern_c void
MetaStablePidSet(ConstHandle2MetaStable This, const XMLName pid);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
