
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
// String is the basic handle type in this file. Example:
//    // Create a default String object:
//    String handle = StringDefault();
// Functions involving String are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_STRING
#define C_INTERFACE_GNDS_V2_0_GENERAL_STRING

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct StringClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ String
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct StringClass *String;

// --- Const-aware handles.
typedef const struct StringClass *const ConstHandle2ConstString;
typedef       struct StringClass *const ConstHandle2String;
typedef const struct StringClass *      Handle2ConstString;
typedef       struct StringClass *      Handle2String;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstString
StringDefaultConst();

// +++ Create, default
extern_c Handle2String
StringDefault();

// --- Create, general, const
extern_c Handle2ConstString
StringCreateConst(
   const char *const label,
   const char *const value,
   const char *const unit
);

// +++ Create, general
extern_c Handle2String
StringCreate(
   const char *const label,
   const char *const value,
   const char *const unit
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
StringAssign(ConstHandle2String self, ConstHandle2ConstString from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
StringDelete(ConstHandle2ConstString self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
StringRead(ConstHandle2String self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
StringWrite(ConstHandle2ConstString self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
StringPrint(ConstHandle2ConstString self);

// +++ Print to standard output, as XML
extern_c int
StringPrintXML(ConstHandle2ConstString self);

// +++ Print to standard output, as JSON
extern_c int
StringPrintJSON(ConstHandle2ConstString self);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
StringLabelHas(ConstHandle2ConstString self);

// +++ Get
// +++ Returns by value
extern_c const char *
StringLabelGet(ConstHandle2ConstString self);

// +++ Set
extern_c void
StringLabelSet(ConstHandle2String self, const char *const label);


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
StringValueHas(ConstHandle2ConstString self);

// +++ Get
// +++ Returns by value
extern_c const char *
StringValueGet(ConstHandle2ConstString self);

// +++ Set
extern_c void
StringValueSet(ConstHandle2String self, const char *const value);


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
StringUnitHas(ConstHandle2ConstString self);

// +++ Get
// +++ Returns by value
extern_c const char *
StringUnitGet(ConstHandle2ConstString self);

// +++ Set
extern_c void
StringUnitSet(ConstHandle2String self, const char *const unit);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/String/src/custom.h"

#undef extern_c
#endif
