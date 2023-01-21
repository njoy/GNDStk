
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
// RelatedItem is the basic handle type in this file. Example:
//    // Create a default RelatedItem object:
//    RelatedItem handle = RelatedItemDefault();
// Functions involving RelatedItem are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_DOCUMENTATION_RELATEDITEM
#define C_INTERFACE_TEST_V2_0_DOCUMENTATION_RELATEDITEM

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct RelatedItemClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ RelatedItem
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct RelatedItemClass *RelatedItem;

// --- Const-aware handles.
typedef const struct RelatedItemClass *const ConstHandle2ConstRelatedItem;
typedef       struct RelatedItemClass *const ConstHandle2RelatedItem;
typedef const struct RelatedItemClass *      Handle2ConstRelatedItem;
typedef       struct RelatedItemClass *      Handle2RelatedItem;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstRelatedItem
RelatedItemDefaultConst();

// +++ Create, default
extern_c Handle2RelatedItem
RelatedItemDefault();

// --- Create, general, const
extern_c Handle2ConstRelatedItem
RelatedItemCreateConst(
   const UTF8Text name,
   const UTF8Text href,
   const enums::RelationType relationType
);

// +++ Create, general
extern_c Handle2RelatedItem
RelatedItemCreate(
   const UTF8Text name,
   const UTF8Text href,
   const enums::RelationType relationType
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
RelatedItemAssign(ConstHandle2RelatedItem This, ConstHandle2ConstRelatedItem from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
RelatedItemDelete(ConstHandle2ConstRelatedItem This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
RelatedItemRead(ConstHandle2RelatedItem This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
RelatedItemWrite(ConstHandle2ConstRelatedItem This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
RelatedItemPrint(ConstHandle2ConstRelatedItem This);

// +++ Print to standard output, as XML
extern_c int
RelatedItemPrintXML(ConstHandle2ConstRelatedItem This);

// +++ Print to standard output, as JSON
extern_c int
RelatedItemPrintJSON(ConstHandle2ConstRelatedItem This);


// -----------------------------------------------------------------------------
// Metadatum: name
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
RelatedItemNameHas(ConstHandle2ConstRelatedItem This);

// +++ Get
// +++ Returns by value
extern_c UTF8Text
RelatedItemNameGet(ConstHandle2ConstRelatedItem This);

// +++ Set
extern_c void
RelatedItemNameSet(ConstHandle2RelatedItem This, const UTF8Text name);


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
RelatedItemHrefHas(ConstHandle2ConstRelatedItem This);

// +++ Get
// +++ Returns by value
extern_c UTF8Text
RelatedItemHrefGet(ConstHandle2ConstRelatedItem This);

// +++ Set
extern_c void
RelatedItemHrefSet(ConstHandle2RelatedItem This, const UTF8Text href);


// -----------------------------------------------------------------------------
// Metadatum: relationType
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
RelatedItemRelationTypeHas(ConstHandle2ConstRelatedItem This);

// +++ Get
// +++ Returns by value
extern_c enums::RelationType
RelatedItemRelationTypeGet(ConstHandle2ConstRelatedItem This);

// +++ Set
extern_c void
RelatedItemRelationTypeSet(ConstHandle2RelatedItem This, const enums::RelationType relationType);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/documentation/RelatedItem/src/custom.h"

#undef extern_c
#endif
