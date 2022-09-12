
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
// Resolved is the basic handle type in this file. Example:
//    // Create a default Resolved object:
//    Resolved handle = ResolvedDefault();
// Functions involving Resolved are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_RESONANCES_RESOLVED
#define C_INTERFACE_TEST_V2_0_RESONANCES_RESOLVED

#include "GNDStk.h"
#include "v2.0/resonances/RMatrix.h"
#include "v2.0/resonances/BreitWigner.h"
#include "v2.0/resonances/EnergyIntervals.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ResolvedClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Resolved
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ResolvedClass *Resolved;

// --- Const-aware handles.
typedef const struct ResolvedClass *const ConstHandle2ConstResolved;
typedef       struct ResolvedClass *const ConstHandle2Resolved;
typedef const struct ResolvedClass *      Handle2ConstResolved;
typedef       struct ResolvedClass *      Handle2Resolved;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstResolved
ResolvedDefaultConst();

// +++ Create, default
extern_c Handle2Resolved
ResolvedDefault();

// --- Create, general, const
extern_c Handle2ConstResolved
ResolvedCreateConst(
   const Float64 domainMin,
   const Float64 domainMax,
   const XMLName domainUnit,
);

// +++ Create, general
extern_c Handle2Resolved
ResolvedCreate(
   const Float64 domainMin,
   const Float64 domainMax,
   const XMLName domainUnit,
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ResolvedAssign(ConstHandle2Resolved This, ConstHandle2ConstResolved from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ResolvedDelete(ConstHandle2ConstResolved This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ResolvedRead(ConstHandle2Resolved This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ResolvedWrite(ConstHandle2ConstResolved This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ResolvedPrint(ConstHandle2ConstResolved This);

// +++ Print to standard output, as XML
extern_c int
ResolvedPrintXML(ConstHandle2ConstResolved This);

// +++ Print to standard output, as JSON
extern_c int
ResolvedPrintJSON(ConstHandle2ConstResolved This);


// -----------------------------------------------------------------------------
// Metadatum: domainMin
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ResolvedDomainMinHas(ConstHandle2ConstResolved This);

// +++ Get
// +++ Returns by value
extern_c Float64
ResolvedDomainMinGet(ConstHandle2ConstResolved This);

// +++ Set
extern_c void
ResolvedDomainMinSet(ConstHandle2Resolved This, const Float64 domainMin);


// -----------------------------------------------------------------------------
// Metadatum: domainMax
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ResolvedDomainMaxHas(ConstHandle2ConstResolved This);

// +++ Get
// +++ Returns by value
extern_c Float64
ResolvedDomainMaxGet(ConstHandle2ConstResolved This);

// +++ Set
extern_c void
ResolvedDomainMaxSet(ConstHandle2Resolved This, const Float64 domainMax);


// -----------------------------------------------------------------------------
// Metadatum: domainUnit
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ResolvedDomainUnitHas(ConstHandle2ConstResolved This);

// +++ Get
// +++ Returns by value
extern_c XMLName
ResolvedDomainUnitGet(ConstHandle2ConstResolved This);

// +++ Set
extern_c void
ResolvedDomainUnitSet(ConstHandle2Resolved This, const XMLName domainUnit);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif