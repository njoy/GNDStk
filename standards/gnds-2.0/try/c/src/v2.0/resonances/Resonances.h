
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
// Resonances is the basic handle type in this file. Example:
//    // Create a default Resonances object:
//    Resonances handle = ResonancesDefault();
// Functions involving Resonances are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_RESONANCES_RESONANCES
#define C_INTERFACE_TRY_V2_0_RESONANCES_RESONANCES

#include "GNDStk.h"
#include "v2.0/resonances/ScatteringRadius.h"
#include "v2.0/resonances/HardSphereRadius.h"
#include "v2.0/resonances/Resolved.h"
#include "v2.0/resonances/Unresolved.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ResonancesClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Resonances
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ResonancesClass *Resonances;

// --- Const-aware handles.
typedef const struct ResonancesClass *const ConstHandle2ConstResonances;
typedef       struct ResonancesClass *const ConstHandle2Resonances;
typedef const struct ResonancesClass *      Handle2ConstResonances;
typedef       struct ResonancesClass *      Handle2Resonances;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstResonances
ResonancesDefaultConst();

// +++ Create, default
extern_c Handle2Resonances
ResonancesDefault();

// --- Create, general, const
extern_c Handle2ConstResonances
ResonancesCreateConst(
   const XMLName href,
   ConstHandle2ConstScatteringRadius scatteringRadius,
   ConstHandle2ConstHardSphereRadius hardSphereRadius,
   ConstHandle2Resolved *const resolved, const size_t resolvedSize,
   ConstHandle2Unresolved *const unresolved, const size_t unresolvedSize
);

// +++ Create, general
extern_c Handle2Resonances
ResonancesCreate(
   const XMLName href,
   ConstHandle2ConstScatteringRadius scatteringRadius,
   ConstHandle2ConstHardSphereRadius hardSphereRadius,
   ConstHandle2Resolved *const resolved, const size_t resolvedSize,
   ConstHandle2Unresolved *const unresolved, const size_t unresolvedSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ResonancesAssign(ConstHandle2Resonances This, ConstHandle2ConstResonances from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ResonancesDelete(ConstHandle2ConstResonances This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ResonancesRead(ConstHandle2Resonances This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ResonancesWrite(ConstHandle2ConstResonances This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ResonancesPrint(ConstHandle2ConstResonances This);

// +++ Print to standard output, as XML
extern_c int
ResonancesPrintXML(ConstHandle2ConstResonances This);

// +++ Print to standard output, as JSON
extern_c int
ResonancesPrintJSON(ConstHandle2ConstResonances This);


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ResonancesHrefHas(ConstHandle2ConstResonances This);

// +++ Get
// +++ Returns by value
extern_c XMLName
ResonancesHrefGet(ConstHandle2ConstResonances This);

// +++ Set
extern_c void
ResonancesHrefSet(ConstHandle2Resonances This, const XMLName href);


// -----------------------------------------------------------------------------
// Child: scatteringRadius
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ResonancesScatteringRadiusHas(ConstHandle2ConstResonances This);

// --- Get, const
extern_c Handle2ConstScatteringRadius
ResonancesScatteringRadiusGetConst(ConstHandle2ConstResonances This);

// +++ Get, non-const
extern_c Handle2ScatteringRadius
ResonancesScatteringRadiusGet(ConstHandle2Resonances This);

// +++ Set
extern_c void
ResonancesScatteringRadiusSet(ConstHandle2Resonances This, ConstHandle2ConstScatteringRadius scatteringRadius);


// -----------------------------------------------------------------------------
// Child: hardSphereRadius
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ResonancesHardSphereRadiusHas(ConstHandle2ConstResonances This);

// --- Get, const
extern_c Handle2ConstHardSphereRadius
ResonancesHardSphereRadiusGetConst(ConstHandle2ConstResonances This);

// +++ Get, non-const
extern_c Handle2HardSphereRadius
ResonancesHardSphereRadiusGet(ConstHandle2Resonances This);

// +++ Set
extern_c void
ResonancesHardSphereRadiusSet(ConstHandle2Resonances This, ConstHandle2ConstHardSphereRadius hardSphereRadius);


// -----------------------------------------------------------------------------
// Child: resolved
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ResonancesResolvedHas(ConstHandle2ConstResonances This);

// +++ Clear
extern_c void
ResonancesResolvedClear(ConstHandle2Resonances This);

// +++ Size
extern_c size_t
ResonancesResolvedSize(ConstHandle2ConstResonances This);

// +++ Add
extern_c void
ResonancesResolvedAdd(ConstHandle2Resonances This, ConstHandle2ConstResolved resolved);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstResolved
ResonancesResolvedGetConst(ConstHandle2ConstResonances This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Resolved
ResonancesResolvedGet(ConstHandle2Resonances This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
ResonancesResolvedSet(
   ConstHandle2Resonances This,
   const size_t index_,
   ConstHandle2ConstResolved resolved
);

// +++ Has, by domainMin
extern_c int
ResonancesResolvedHasByDomainMin(
   ConstHandle2ConstResonances This,
   const Float64 domainMin
);

// --- Get, by domainMin, const
extern_c Handle2ConstResolved
ResonancesResolvedGetByDomainMinConst(
   ConstHandle2ConstResonances This,
   const Float64 domainMin
);

// +++ Get, by domainMin, non-const
extern_c Handle2Resolved
ResonancesResolvedGetByDomainMin(
   ConstHandle2Resonances This,
   const Float64 domainMin
);

// +++ Set, by domainMin
extern_c void
ResonancesResolvedSetByDomainMin(
   ConstHandle2Resonances This,
   const Float64 domainMin,
   ConstHandle2ConstResolved resolved
);

// +++ Has, by domainMax
extern_c int
ResonancesResolvedHasByDomainMax(
   ConstHandle2ConstResonances This,
   const Float64 domainMax
);

// --- Get, by domainMax, const
extern_c Handle2ConstResolved
ResonancesResolvedGetByDomainMaxConst(
   ConstHandle2ConstResonances This,
   const Float64 domainMax
);

// +++ Get, by domainMax, non-const
extern_c Handle2Resolved
ResonancesResolvedGetByDomainMax(
   ConstHandle2Resonances This,
   const Float64 domainMax
);

// +++ Set, by domainMax
extern_c void
ResonancesResolvedSetByDomainMax(
   ConstHandle2Resonances This,
   const Float64 domainMax,
   ConstHandle2ConstResolved resolved
);

// +++ Has, by domainUnit
extern_c int
ResonancesResolvedHasByDomainUnit(
   ConstHandle2ConstResonances This,
   const XMLName domainUnit
);

// --- Get, by domainUnit, const
extern_c Handle2ConstResolved
ResonancesResolvedGetByDomainUnitConst(
   ConstHandle2ConstResonances This,
   const XMLName domainUnit
);

// +++ Get, by domainUnit, non-const
extern_c Handle2Resolved
ResonancesResolvedGetByDomainUnit(
   ConstHandle2Resonances This,
   const XMLName domainUnit
);

// +++ Set, by domainUnit
extern_c void
ResonancesResolvedSetByDomainUnit(
   ConstHandle2Resonances This,
   const XMLName domainUnit,
   ConstHandle2ConstResolved resolved
);


// -----------------------------------------------------------------------------
// Child: unresolved
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ResonancesUnresolvedHas(ConstHandle2ConstResonances This);

// +++ Clear
extern_c void
ResonancesUnresolvedClear(ConstHandle2Resonances This);

// +++ Size
extern_c size_t
ResonancesUnresolvedSize(ConstHandle2ConstResonances This);

// +++ Add
extern_c void
ResonancesUnresolvedAdd(ConstHandle2Resonances This, ConstHandle2ConstUnresolved unresolved);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstUnresolved
ResonancesUnresolvedGetConst(ConstHandle2ConstResonances This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Unresolved
ResonancesUnresolvedGet(ConstHandle2Resonances This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
ResonancesUnresolvedSet(
   ConstHandle2Resonances This,
   const size_t index_,
   ConstHandle2ConstUnresolved unresolved
);

// +++ Has, by domainMin
extern_c int
ResonancesUnresolvedHasByDomainMin(
   ConstHandle2ConstResonances This,
   const Float64 domainMin
);

// --- Get, by domainMin, const
extern_c Handle2ConstUnresolved
ResonancesUnresolvedGetByDomainMinConst(
   ConstHandle2ConstResonances This,
   const Float64 domainMin
);

// +++ Get, by domainMin, non-const
extern_c Handle2Unresolved
ResonancesUnresolvedGetByDomainMin(
   ConstHandle2Resonances This,
   const Float64 domainMin
);

// +++ Set, by domainMin
extern_c void
ResonancesUnresolvedSetByDomainMin(
   ConstHandle2Resonances This,
   const Float64 domainMin,
   ConstHandle2ConstUnresolved unresolved
);

// +++ Has, by domainMax
extern_c int
ResonancesUnresolvedHasByDomainMax(
   ConstHandle2ConstResonances This,
   const Float64 domainMax
);

// --- Get, by domainMax, const
extern_c Handle2ConstUnresolved
ResonancesUnresolvedGetByDomainMaxConst(
   ConstHandle2ConstResonances This,
   const Float64 domainMax
);

// +++ Get, by domainMax, non-const
extern_c Handle2Unresolved
ResonancesUnresolvedGetByDomainMax(
   ConstHandle2Resonances This,
   const Float64 domainMax
);

// +++ Set, by domainMax
extern_c void
ResonancesUnresolvedSetByDomainMax(
   ConstHandle2Resonances This,
   const Float64 domainMax,
   ConstHandle2ConstUnresolved unresolved
);

// +++ Has, by domainUnit
extern_c int
ResonancesUnresolvedHasByDomainUnit(
   ConstHandle2ConstResonances This,
   const XMLName domainUnit
);

// --- Get, by domainUnit, const
extern_c Handle2ConstUnresolved
ResonancesUnresolvedGetByDomainUnitConst(
   ConstHandle2ConstResonances This,
   const XMLName domainUnit
);

// +++ Get, by domainUnit, non-const
extern_c Handle2Unresolved
ResonancesUnresolvedGetByDomainUnit(
   ConstHandle2Resonances This,
   const XMLName domainUnit
);

// +++ Set, by domainUnit
extern_c void
ResonancesUnresolvedSetByDomainUnit(
   ConstHandle2Resonances This,
   const XMLName domainUnit,
   ConstHandle2ConstUnresolved unresolved
);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif