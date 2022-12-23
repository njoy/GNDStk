
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
// EnergyIntervals is the basic handle type in this file. Example:
//    // Create a default EnergyIntervals object:
//    EnergyIntervals handle = EnergyIntervalsDefault();
// Functions involving EnergyIntervals are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_RESONANCES_ENERGYINTERVALS
#define C_INTERFACE_TEST_V2_0_RESONANCES_ENERGYINTERVALS

#include "GNDStk.h"
#include "v2.0/resonances/EnergyInterval.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct EnergyIntervalsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ EnergyIntervals
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct EnergyIntervalsClass *EnergyIntervals;

// --- Const-aware handles.
typedef const struct EnergyIntervalsClass *const ConstHandle2ConstEnergyIntervals;
typedef       struct EnergyIntervalsClass *const ConstHandle2EnergyIntervals;
typedef const struct EnergyIntervalsClass *      Handle2ConstEnergyIntervals;
typedef       struct EnergyIntervalsClass *      Handle2EnergyIntervals;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstEnergyIntervals
EnergyIntervalsDefaultConst();

// +++ Create, default
extern_c Handle2EnergyIntervals
EnergyIntervalsDefault();

// --- Create, general, const
extern_c Handle2ConstEnergyIntervals
EnergyIntervalsCreateConst(
   const XMLName label,
   ConstHandle2EnergyInterval *const energyInterval, const size_t energyIntervalSize
);

// +++ Create, general
extern_c Handle2EnergyIntervals
EnergyIntervalsCreate(
   const XMLName label,
   ConstHandle2EnergyInterval *const energyInterval, const size_t energyIntervalSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
EnergyIntervalsAssign(ConstHandle2EnergyIntervals This, ConstHandle2ConstEnergyIntervals from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
EnergyIntervalsDelete(ConstHandle2ConstEnergyIntervals This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
EnergyIntervalsRead(ConstHandle2EnergyIntervals This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
EnergyIntervalsWrite(ConstHandle2ConstEnergyIntervals This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
EnergyIntervalsPrint(ConstHandle2ConstEnergyIntervals This);

// +++ Print to standard output, as XML
extern_c int
EnergyIntervalsPrintXML(ConstHandle2ConstEnergyIntervals This);

// +++ Print to standard output, as JSON
extern_c int
EnergyIntervalsPrintJSON(ConstHandle2ConstEnergyIntervals This);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
EnergyIntervalsLabelHas(ConstHandle2ConstEnergyIntervals This);

// +++ Get
// +++ Returns by value
extern_c XMLName
EnergyIntervalsLabelGet(ConstHandle2ConstEnergyIntervals This);

// +++ Set
extern_c void
EnergyIntervalsLabelSet(ConstHandle2EnergyIntervals This, const XMLName label);


// -----------------------------------------------------------------------------
// Child: energyInterval
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
EnergyIntervalsEnergyIntervalHas(ConstHandle2ConstEnergyIntervals This);

// +++ Clear
extern_c void
EnergyIntervalsEnergyIntervalClear(ConstHandle2EnergyIntervals This);

// +++ Size
extern_c size_t
EnergyIntervalsEnergyIntervalSize(ConstHandle2ConstEnergyIntervals This);

// +++ Add
extern_c void
EnergyIntervalsEnergyIntervalAdd(ConstHandle2EnergyIntervals This, ConstHandle2ConstEnergyInterval energyInterval);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstEnergyInterval
EnergyIntervalsEnergyIntervalGetConst(ConstHandle2ConstEnergyIntervals This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2EnergyInterval
EnergyIntervalsEnergyIntervalGet(ConstHandle2EnergyIntervals This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
EnergyIntervalsEnergyIntervalSet(
   ConstHandle2EnergyIntervals This,
   const size_t index_,
   ConstHandle2ConstEnergyInterval energyInterval
);

// +++ Has, by index
extern_c int
EnergyIntervalsEnergyIntervalHasByIndex(
   ConstHandle2ConstEnergyIntervals This,
   const Integer32 index
);

// --- Get, by index, const
extern_c Handle2ConstEnergyInterval
EnergyIntervalsEnergyIntervalGetByIndexConst(
   ConstHandle2ConstEnergyIntervals This,
   const Integer32 index
);

// +++ Get, by index, non-const
extern_c Handle2EnergyInterval
EnergyIntervalsEnergyIntervalGetByIndex(
   ConstHandle2EnergyIntervals This,
   const Integer32 index
);

// +++ Set, by index
extern_c void
EnergyIntervalsEnergyIntervalSetByIndex(
   ConstHandle2EnergyIntervals This,
   const Integer32 index,
   ConstHandle2ConstEnergyInterval energyInterval
);

// +++ Has, by domainMin
extern_c int
EnergyIntervalsEnergyIntervalHasByDomainMin(
   ConstHandle2ConstEnergyIntervals This,
   const Float64 domainMin
);

// --- Get, by domainMin, const
extern_c Handle2ConstEnergyInterval
EnergyIntervalsEnergyIntervalGetByDomainMinConst(
   ConstHandle2ConstEnergyIntervals This,
   const Float64 domainMin
);

// +++ Get, by domainMin, non-const
extern_c Handle2EnergyInterval
EnergyIntervalsEnergyIntervalGetByDomainMin(
   ConstHandle2EnergyIntervals This,
   const Float64 domainMin
);

// +++ Set, by domainMin
extern_c void
EnergyIntervalsEnergyIntervalSetByDomainMin(
   ConstHandle2EnergyIntervals This,
   const Float64 domainMin,
   ConstHandle2ConstEnergyInterval energyInterval
);

// +++ Has, by domainMax
extern_c int
EnergyIntervalsEnergyIntervalHasByDomainMax(
   ConstHandle2ConstEnergyIntervals This,
   const Float64 domainMax
);

// --- Get, by domainMax, const
extern_c Handle2ConstEnergyInterval
EnergyIntervalsEnergyIntervalGetByDomainMaxConst(
   ConstHandle2ConstEnergyIntervals This,
   const Float64 domainMax
);

// +++ Get, by domainMax, non-const
extern_c Handle2EnergyInterval
EnergyIntervalsEnergyIntervalGetByDomainMax(
   ConstHandle2EnergyIntervals This,
   const Float64 domainMax
);

// +++ Set, by domainMax
extern_c void
EnergyIntervalsEnergyIntervalSetByDomainMax(
   ConstHandle2EnergyIntervals This,
   const Float64 domainMax,
   ConstHandle2ConstEnergyInterval energyInterval
);

// +++ Has, by domainUnit
extern_c int
EnergyIntervalsEnergyIntervalHasByDomainUnit(
   ConstHandle2ConstEnergyIntervals This,
   const XMLName domainUnit
);

// --- Get, by domainUnit, const
extern_c Handle2ConstEnergyInterval
EnergyIntervalsEnergyIntervalGetByDomainUnitConst(
   ConstHandle2ConstEnergyIntervals This,
   const XMLName domainUnit
);

// +++ Get, by domainUnit, non-const
extern_c Handle2EnergyInterval
EnergyIntervalsEnergyIntervalGetByDomainUnit(
   ConstHandle2EnergyIntervals This,
   const XMLName domainUnit
);

// +++ Set, by domainUnit
extern_c void
EnergyIntervalsEnergyIntervalSetByDomainUnit(
   ConstHandle2EnergyIntervals This,
   const XMLName domainUnit,
   ConstHandle2ConstEnergyInterval energyInterval
);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
