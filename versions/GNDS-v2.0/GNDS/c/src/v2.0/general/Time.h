
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
// Time is the basic handle type in this file. Example:
//    // Create a default Time object:
//    Time handle = TimeDefault();
// Functions involving Time are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_TIME
#define C_INTERFACE_GNDS_V2_0_GENERAL_TIME

#include "GNDStk.h"
#include "v2.0/general/Double.h"
#include "v2.0/general/String.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct TimeClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Time
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct TimeClass *Time;

// --- Const-aware handles.
typedef const struct TimeClass *const ConstHandle2ConstTime;
typedef       struct TimeClass *const ConstHandle2Time;
typedef const struct TimeClass *      Handle2ConstTime;
typedef       struct TimeClass *      Handle2Time;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstTime
TimeDefaultConst();

// +++ Create, default, non-const
extern_c Handle2Time
TimeDefault();

// --- Create, general, const
extern_c Handle2ConstTime
TimeCreateConst(
   ConstHandle2ConstDouble Double,
   ConstHandle2ConstString string
);

// +++ Create, general, non-const
extern_c Handle2Time
TimeCreate(
   ConstHandle2ConstDouble Double,
   ConstHandle2ConstString string
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
TimeAssign(ConstHandle2Time self, ConstHandle2ConstTime from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
TimeDelete(ConstHandle2ConstTime self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
TimeRead(ConstHandle2Time self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
TimeWrite(ConstHandle2ConstTime self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
TimePrint(ConstHandle2ConstTime self);

// +++ Print to standard output, as XML
extern_c int
TimePrintXML(ConstHandle2ConstTime self);

// +++ Print to standard output, as JSON
extern_c int
TimePrintJSON(ConstHandle2ConstTime self);


// -----------------------------------------------------------------------------
// Child: Double
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
TimeDoubleHas(ConstHandle2ConstTime self);

// --- Get, const
extern_c Handle2ConstDouble
TimeDoubleGetConst(ConstHandle2ConstTime self);

// +++ Get, non-const
extern_c Handle2Double
TimeDoubleGet(ConstHandle2Time self);

// +++ Set
extern_c void
TimeDoubleSet(ConstHandle2Time self, ConstHandle2ConstDouble Double);


// -----------------------------------------------------------------------------
// Child: string
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
TimeStringHas(ConstHandle2ConstTime self);

// --- Get, const
extern_c Handle2ConstString
TimeStringGetConst(ConstHandle2ConstTime self);

// +++ Get, non-const
extern_c Handle2String
TimeStringGet(ConstHandle2Time self);

// +++ Set
extern_c void
TimeStringSet(ConstHandle2Time self, ConstHandle2ConstString string);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Time/src/custom.h"

#undef extern_c
#endif