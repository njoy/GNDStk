
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
// Integer is the basic handle type in this file. Example:
//    // Create a default Integer object:
//    Integer handle = IntegerDefault();
// Functions involving Integer are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_CONTAINERS_INTEGER
#define C_INTERFACE_TRY_V2_0_CONTAINERS_INTEGER

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct IntegerClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Integer
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct IntegerClass *Integer;

// --- Const-aware handles.
typedef const struct IntegerClass *const ConstHandle2ConstInteger;
typedef       struct IntegerClass *const ConstHandle2Integer;
typedef const struct IntegerClass *      Handle2ConstInteger;
typedef       struct IntegerClass *      Handle2Integer;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstInteger
IntegerDefaultConst();

// +++ Create, default
extern_c Handle2Integer
IntegerDefault();

// --- Create, general, const
extern_c Handle2ConstInteger
IntegerCreateConst(
   const XMLName label,
   const XMLName unit,
   const Integer32 value
);

// +++ Create, general
extern_c Handle2Integer
IntegerCreate(
   const XMLName label,
   const XMLName unit,
   const Integer32 value
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
IntegerAssign(ConstHandle2Integer This, ConstHandle2ConstInteger from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
IntegerDelete(ConstHandle2ConstInteger This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
IntegerRead(ConstHandle2Integer This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
IntegerWrite(ConstHandle2ConstInteger This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
IntegerPrint(ConstHandle2ConstInteger This);

// +++ Print to standard output, as XML
extern_c int
IntegerPrintXML(ConstHandle2ConstInteger This);

// +++ Print to standard output, as JSON
extern_c int
IntegerPrintJSON(ConstHandle2ConstInteger This);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
IntegerLabelHas(ConstHandle2ConstInteger This);

// +++ Get
// +++ Returns by value
extern_c XMLName
IntegerLabelGet(ConstHandle2ConstInteger This);

// +++ Set
extern_c void
IntegerLabelSet(ConstHandle2Integer This, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
IntegerUnitHas(ConstHandle2ConstInteger This);

// +++ Get
// +++ Returns by value
extern_c XMLName
IntegerUnitGet(ConstHandle2ConstInteger This);

// +++ Set
extern_c void
IntegerUnitSet(ConstHandle2Integer This, const XMLName unit);


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
IntegerValueHas(ConstHandle2ConstInteger This);

// +++ Get
// +++ Returns by value
extern_c Integer32
IntegerValueGet(ConstHandle2ConstInteger This);

// +++ Set
extern_c void
IntegerValueSet(ConstHandle2Integer This, const Integer32 value);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
