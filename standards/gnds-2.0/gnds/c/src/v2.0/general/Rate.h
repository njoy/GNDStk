
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
// Rate is the basic handle type in this file. Example:
//    // Create a default Rate object:
//    Rate handle = RateDefault();
// Functions involving Rate are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_RATE
#define C_INTERFACE_GNDS_V2_0_GENERAL_RATE

#include "GNDStk.h"
#include "v2.0/general/Double.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct RateClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Rate
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct RateClass *Rate;

// --- Const-aware handles.
typedef const struct RateClass *const ConstHandle2ConstRate;
typedef       struct RateClass *const ConstHandle2Rate;
typedef const struct RateClass *      Handle2ConstRate;
typedef       struct RateClass *      Handle2Rate;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstRate
RateDefaultConst();

// +++ Create, default
extern_c Handle2Rate
RateDefault();

// --- Create, general, const
extern_c Handle2ConstRate
RateCreateConst(
   ConstHandle2ConstDouble Double
);

// +++ Create, general
extern_c Handle2Rate
RateCreate(
   ConstHandle2ConstDouble Double
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
RateAssign(ConstHandle2Rate self, ConstHandle2ConstRate from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
RateDelete(ConstHandle2ConstRate self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
RateRead(ConstHandle2Rate self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
RateWrite(ConstHandle2ConstRate self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
RatePrint(ConstHandle2ConstRate self);

// +++ Print to standard output, as XML
extern_c int
RatePrintXML(ConstHandle2ConstRate self);

// +++ Print to standard output, as JSON
extern_c int
RatePrintJSON(ConstHandle2ConstRate self);


// -----------------------------------------------------------------------------
// Child: Double
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
RateDoubleHas(ConstHandle2ConstRate self);

// --- Get, const
extern_c Handle2ConstDouble
RateDoubleGetConst(ConstHandle2ConstRate self);

// +++ Get, non-const
extern_c Handle2Double
RateDoubleGet(ConstHandle2Rate self);

// +++ Set
extern_c void
RateDoubleSet(ConstHandle2Rate self, ConstHandle2ConstDouble Double);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Rate/src/custom.h"

#undef extern_c
#endif
