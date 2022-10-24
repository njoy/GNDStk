
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
// Date is the basic handle type in this file. Example:
//    // Create a default Date object:
//    Date handle = DateDefault();
// Functions involving Date are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_GNDS_DATE
#define C_INTERFACE_TEST_V2_0_GNDS_DATE

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct DateClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Date
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct DateClass *Date;

// --- Const-aware handles.
typedef const struct DateClass *const ConstHandle2ConstDate;
typedef       struct DateClass *const ConstHandle2Date;
typedef const struct DateClass *      Handle2ConstDate;
typedef       struct DateClass *      Handle2Date;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstDate
DateDefaultConst();

// +++ Create, default
extern_c Handle2Date
DateDefault();

// --- Create, general, const
extern_c Handle2ConstDate
DateCreateConst(
   const char *const value,
   const enums::DateType dateType
);

// +++ Create, general
extern_c Handle2Date
DateCreate(
   const char *const value,
   const enums::DateType dateType
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
DateAssign(ConstHandle2Date This, ConstHandle2ConstDate from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
DateDelete(ConstHandle2ConstDate This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
DateRead(ConstHandle2Date This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
DateWrite(ConstHandle2ConstDate This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
DatePrint(ConstHandle2ConstDate This);

// +++ Print to standard output, as XML
extern_c int
DatePrintXML(ConstHandle2ConstDate This);

// +++ Print to standard output, as JSON
extern_c int
DatePrintJSON(ConstHandle2ConstDate This);


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DateValueHas(ConstHandle2ConstDate This);

// +++ Get
// +++ Returns by value
extern_c const char *
DateValueGet(ConstHandle2ConstDate This);

// +++ Set
extern_c void
DateValueSet(ConstHandle2Date This, const char *const value);


// -----------------------------------------------------------------------------
// Metadatum: dateType
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DateDateTypeHas(ConstHandle2ConstDate This);

// +++ Get
// +++ Returns by value
extern_c enums::DateType
DateDateTypeGet(ConstHandle2ConstDate This);

// +++ Set
extern_c void
DateDateTypeSet(ConstHandle2Date This, const enums::DateType dateType);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
