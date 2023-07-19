
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
// E_max is the basic handle type in this file. Example:
//    // Create a default E_max object:
//    E_max handle = E_maxDefault();
// Functions involving E_max are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_E_MAX
#define C_INTERFACE_ALPHA_V2_0_GENERAL_E_MAX

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct E_maxClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ E_max
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct E_maxClass *E_max;

// --- Const-aware handles.
typedef const struct E_maxClass *const ConstHandle2ConstE_max;
typedef       struct E_maxClass *const ConstHandle2E_max;
typedef const struct E_maxClass *      Handle2ConstE_max;
typedef       struct E_maxClass *      Handle2E_max;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstE_max
E_maxDefaultConst();

// +++ Create, default
extern_c Handle2E_max
E_maxDefault();

// --- Create, general, const
extern_c Handle2ConstE_max
E_maxCreateConst(
   const double value,
   const char *const unit
);

// +++ Create, general
extern_c Handle2E_max
E_maxCreate(
   const double value,
   const char *const unit
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
E_maxAssign(ConstHandle2E_max self, ConstHandle2ConstE_max from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
E_maxDelete(ConstHandle2ConstE_max self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
E_maxRead(ConstHandle2E_max self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
E_maxWrite(ConstHandle2ConstE_max self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
E_maxPrint(ConstHandle2ConstE_max self);

// +++ Print to standard output, as XML
extern_c int
E_maxPrintXML(ConstHandle2ConstE_max self);

// +++ Print to standard output, as JSON
extern_c int
E_maxPrintJSON(ConstHandle2ConstE_max self);


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
E_maxValueHas(ConstHandle2ConstE_max self);

// +++ Get
// +++ Returns by value
extern_c double
E_maxValueGet(ConstHandle2ConstE_max self);

// +++ Set
extern_c void
E_maxValueSet(ConstHandle2E_max self, const double value);


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
E_maxUnitHas(ConstHandle2ConstE_max self);

// +++ Get
// +++ Returns by value
extern_c const char *
E_maxUnitGet(ConstHandle2ConstE_max self);

// +++ Set
extern_c void
E_maxUnitSet(ConstHandle2E_max self, const char *const unit);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/E_max/src/custom.h"

#undef extern_c
#endif
