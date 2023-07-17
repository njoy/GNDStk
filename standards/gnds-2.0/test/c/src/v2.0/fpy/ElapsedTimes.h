
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
// ElapsedTimes is the basic handle type in this file. Example:
//    // Create a default ElapsedTimes object:
//    ElapsedTimes handle = ElapsedTimesDefault();
// Functions involving ElapsedTimes are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_FPY_ELAPSEDTIMES
#define C_INTERFACE_TEST_V2_0_FPY_ELAPSEDTIMES

#include "GNDStk.h"
#include "v2.0/fpy/ElapsedTime.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ElapsedTimesClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ElapsedTimes
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ElapsedTimesClass *ElapsedTimes;

// --- Const-aware handles.
typedef const struct ElapsedTimesClass *const ConstHandle2ConstElapsedTimes;
typedef       struct ElapsedTimesClass *const ConstHandle2ElapsedTimes;
typedef const struct ElapsedTimesClass *      Handle2ConstElapsedTimes;
typedef       struct ElapsedTimesClass *      Handle2ElapsedTimes;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstElapsedTimes
ElapsedTimesDefaultConst();

// +++ Create, default
extern_c Handle2ElapsedTimes
ElapsedTimesDefault();

// --- Create, general, const
extern_c Handle2ConstElapsedTimes
ElapsedTimesCreateConst(
   ConstHandle2ElapsedTime *const elapsedTime, const size_t elapsedTimeSize
);

// +++ Create, general
extern_c Handle2ElapsedTimes
ElapsedTimesCreate(
   ConstHandle2ElapsedTime *const elapsedTime, const size_t elapsedTimeSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ElapsedTimesAssign(ConstHandle2ElapsedTimes self, ConstHandle2ConstElapsedTimes from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ElapsedTimesDelete(ConstHandle2ConstElapsedTimes self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ElapsedTimesRead(ConstHandle2ElapsedTimes self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ElapsedTimesWrite(ConstHandle2ConstElapsedTimes self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ElapsedTimesPrint(ConstHandle2ConstElapsedTimes self);

// +++ Print to standard output, as XML
extern_c int
ElapsedTimesPrintXML(ConstHandle2ConstElapsedTimes self);

// +++ Print to standard output, as JSON
extern_c int
ElapsedTimesPrintJSON(ConstHandle2ConstElapsedTimes self);


// -----------------------------------------------------------------------------
// Child: elapsedTime
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ElapsedTimesElapsedTimeHas(ConstHandle2ConstElapsedTimes self);

// +++ Clear
extern_c void
ElapsedTimesElapsedTimeClear(ConstHandle2ElapsedTimes self);

// +++ Size
extern_c size_t
ElapsedTimesElapsedTimeSize(ConstHandle2ConstElapsedTimes self);

// +++ Add
extern_c void
ElapsedTimesElapsedTimeAdd(ConstHandle2ElapsedTimes self, ConstHandle2ConstElapsedTime elapsedTime);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstElapsedTime
ElapsedTimesElapsedTimeGetConst(ConstHandle2ConstElapsedTimes self, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2ElapsedTime
ElapsedTimesElapsedTimeGet(ConstHandle2ElapsedTimes self, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
ElapsedTimesElapsedTimeSet(
   ConstHandle2ElapsedTimes self,
   const size_t index_,
   ConstHandle2ConstElapsedTime elapsedTime
);

// +++ Has, by label
extern_c int
ElapsedTimesElapsedTimeHasByLabel(
   ConstHandle2ConstElapsedTimes self,
   const XMLName label
);

// --- Get, by label, const
extern_c Handle2ConstElapsedTime
ElapsedTimesElapsedTimeGetByLabelConst(
   ConstHandle2ConstElapsedTimes self,
   const XMLName label
);

// +++ Get, by label, non-const
extern_c Handle2ElapsedTime
ElapsedTimesElapsedTimeGetByLabel(
   ConstHandle2ElapsedTimes self,
   const XMLName label
);

// +++ Set, by label
extern_c void
ElapsedTimesElapsedTimeSetByLabel(
   ConstHandle2ElapsedTimes self,
   const XMLName label,
   ConstHandle2ConstElapsedTime elapsedTime
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/fpy/ElapsedTimes/src/custom.h"

#undef extern_c
#endif
