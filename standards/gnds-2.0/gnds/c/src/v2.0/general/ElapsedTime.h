
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
// ElapsedTime is the basic handle type in this file. Example:
//    // Create a default ElapsedTime object:
//    ElapsedTime handle = ElapsedTimeDefault();
// Functions involving ElapsedTime are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_ELAPSEDTIME
#define C_INTERFACE_GNDS_V2_0_GENERAL_ELAPSEDTIME

#include "GNDStk.h"
#include "v2.0/general/Time.h"
#include "v2.0/general/Yields.h"
#include "v2.0/general/IncidentEnergies.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ElapsedTimeClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ElapsedTime
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ElapsedTimeClass *ElapsedTime;

// --- Const-aware handles.
typedef const struct ElapsedTimeClass *const ConstHandle2ConstElapsedTime;
typedef       struct ElapsedTimeClass *const ConstHandle2ElapsedTime;
typedef const struct ElapsedTimeClass *      Handle2ConstElapsedTime;
typedef       struct ElapsedTimeClass *      Handle2ElapsedTime;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstElapsedTime
ElapsedTimeDefaultConst();

// +++ Create, default
extern_c Handle2ElapsedTime
ElapsedTimeDefault();

// --- Create, general, const
extern_c Handle2ConstElapsedTime
ElapsedTimeCreateConst(
   const char *const label,
   ConstHandle2ConstTime time,
   ConstHandle2ConstYields yields,
   ConstHandle2ConstIncidentEnergies incidentEnergies
);

// +++ Create, general
extern_c Handle2ElapsedTime
ElapsedTimeCreate(
   const char *const label,
   ConstHandle2ConstTime time,
   ConstHandle2ConstYields yields,
   ConstHandle2ConstIncidentEnergies incidentEnergies
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ElapsedTimeAssign(ConstHandle2ElapsedTime self, ConstHandle2ConstElapsedTime from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ElapsedTimeDelete(ConstHandle2ConstElapsedTime self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ElapsedTimeRead(ConstHandle2ElapsedTime self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ElapsedTimeWrite(ConstHandle2ConstElapsedTime self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ElapsedTimePrint(ConstHandle2ConstElapsedTime self);

// +++ Print to standard output, as XML
extern_c int
ElapsedTimePrintXML(ConstHandle2ConstElapsedTime self);

// +++ Print to standard output, as JSON
extern_c int
ElapsedTimePrintJSON(ConstHandle2ConstElapsedTime self);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ElapsedTimeLabelHas(ConstHandle2ConstElapsedTime self);

// +++ Get
// +++ Returns by value
extern_c const char *
ElapsedTimeLabelGet(ConstHandle2ConstElapsedTime self);

// +++ Set
extern_c void
ElapsedTimeLabelSet(ConstHandle2ElapsedTime self, const char *const label);


// -----------------------------------------------------------------------------
// Child: time
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ElapsedTimeTimeHas(ConstHandle2ConstElapsedTime self);

// --- Get, const
extern_c Handle2ConstTime
ElapsedTimeTimeGetConst(ConstHandle2ConstElapsedTime self);

// +++ Get, non-const
extern_c Handle2Time
ElapsedTimeTimeGet(ConstHandle2ElapsedTime self);

// +++ Set
extern_c void
ElapsedTimeTimeSet(ConstHandle2ElapsedTime self, ConstHandle2ConstTime time);


// -----------------------------------------------------------------------------
// Child: yields
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ElapsedTimeYieldsHas(ConstHandle2ConstElapsedTime self);

// --- Get, const
extern_c Handle2ConstYields
ElapsedTimeYieldsGetConst(ConstHandle2ConstElapsedTime self);

// +++ Get, non-const
extern_c Handle2Yields
ElapsedTimeYieldsGet(ConstHandle2ElapsedTime self);

// +++ Set
extern_c void
ElapsedTimeYieldsSet(ConstHandle2ElapsedTime self, ConstHandle2ConstYields yields);


// -----------------------------------------------------------------------------
// Child: incidentEnergies
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ElapsedTimeIncidentEnergiesHas(ConstHandle2ConstElapsedTime self);

// --- Get, const
extern_c Handle2ConstIncidentEnergies
ElapsedTimeIncidentEnergiesGetConst(ConstHandle2ConstElapsedTime self);

// +++ Get, non-const
extern_c Handle2IncidentEnergies
ElapsedTimeIncidentEnergiesGet(ConstHandle2ElapsedTime self);

// +++ Set
extern_c void
ElapsedTimeIncidentEnergiesSet(ConstHandle2ElapsedTime self, ConstHandle2ConstIncidentEnergies incidentEnergies);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/ElapsedTime/src/custom.h"

#undef extern_c
#endif
