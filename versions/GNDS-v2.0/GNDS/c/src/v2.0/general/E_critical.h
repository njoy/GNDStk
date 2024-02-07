
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
// E_critical is the basic handle type in this file. Example:
//    // Create a default E_critical object:
//    E_critical handle = E_criticalDefault();
// Functions involving E_critical are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_E_CRITICAL
#define C_INTERFACE_GNDS_V2_0_GENERAL_E_CRITICAL

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct E_criticalClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ E_critical
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct E_criticalClass *E_critical;

// --- Const-aware handles.
typedef const struct E_criticalClass *const ConstHandle2ConstE_critical;
typedef       struct E_criticalClass *const ConstHandle2E_critical;
typedef const struct E_criticalClass *      Handle2ConstE_critical;
typedef       struct E_criticalClass *      Handle2E_critical;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstE_critical
E_criticalDefaultConst();

// +++ Create, default, non-const
extern_c Handle2E_critical
E_criticalDefault();

// --- Create, general, const
extern_c Handle2ConstE_critical
E_criticalCreateConst(
   const double value,
   const char *const unit
);

// +++ Create, general, non-const
extern_c Handle2E_critical
E_criticalCreate(
   const double value,
   const char *const unit
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
E_criticalAssign(ConstHandle2E_critical self, ConstHandle2ConstE_critical from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
E_criticalDelete(ConstHandle2ConstE_critical self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
E_criticalRead(ConstHandle2E_critical self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
E_criticalWrite(ConstHandle2ConstE_critical self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
E_criticalPrint(ConstHandle2ConstE_critical self);

// +++ Print to standard output, as XML
extern_c int
E_criticalPrintXML(ConstHandle2ConstE_critical self);

// +++ Print to standard output, as JSON
extern_c int
E_criticalPrintJSON(ConstHandle2ConstE_critical self);


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
E_criticalValueHas(ConstHandle2ConstE_critical self);

// +++ Get
// +++ Returns by value
extern_c double
E_criticalValueGet(ConstHandle2ConstE_critical self);

// +++ Set
extern_c void
E_criticalValueSet(ConstHandle2E_critical self, const double value);


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
E_criticalUnitHas(ConstHandle2ConstE_critical self);

// +++ Get
// +++ Returns by value
extern_c const char *
E_criticalUnitGet(ConstHandle2ConstE_critical self);

// +++ Set
extern_c void
E_criticalUnitSet(ConstHandle2E_critical self, const char *const unit);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/E_critical/src/custom.h"

#undef extern_c
#endif