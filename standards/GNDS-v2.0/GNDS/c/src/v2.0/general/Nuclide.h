
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
// Nuclide is the basic handle type in this file. Example:
//    // Create a default Nuclide object:
//    Nuclide handle = NuclideDefault();
// Functions involving Nuclide are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_NUCLIDE
#define C_INTERFACE_GNDS_V2_0_GENERAL_NUCLIDE

#include "GNDStk.h"
#include "v2.0/general/Mass.h"
#include "v2.0/general/Charge.h"
#include "v2.0/general/Nucleus.h"
#include "v2.0/general/DecayData.h"
#include "v2.0/top/FissionFragmentData.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct NuclideClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Nuclide
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct NuclideClass *Nuclide;

// --- Const-aware handles.
typedef const struct NuclideClass *const ConstHandle2ConstNuclide;
typedef       struct NuclideClass *const ConstHandle2Nuclide;
typedef const struct NuclideClass *      Handle2ConstNuclide;
typedef       struct NuclideClass *      Handle2Nuclide;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstNuclide
NuclideDefaultConst();

// +++ Create, default
extern_c Handle2Nuclide
NuclideDefault();

// --- Create, general, const
extern_c Handle2ConstNuclide
NuclideCreateConst(
   const char *const id,
   ConstHandle2ConstMass mass,
   ConstHandle2ConstCharge charge,
   ConstHandle2ConstNucleus nucleus,
   ConstHandle2ConstDecayData decayData,
   ConstHandle2ConstFissionFragmentData fissionFragmentData
);

// +++ Create, general
extern_c Handle2Nuclide
NuclideCreate(
   const char *const id,
   ConstHandle2ConstMass mass,
   ConstHandle2ConstCharge charge,
   ConstHandle2ConstNucleus nucleus,
   ConstHandle2ConstDecayData decayData,
   ConstHandle2ConstFissionFragmentData fissionFragmentData
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
NuclideAssign(ConstHandle2Nuclide self, ConstHandle2ConstNuclide from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
NuclideDelete(ConstHandle2ConstNuclide self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
NuclideRead(ConstHandle2Nuclide self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
NuclideWrite(ConstHandle2ConstNuclide self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
NuclidePrint(ConstHandle2ConstNuclide self);

// +++ Print to standard output, as XML
extern_c int
NuclidePrintXML(ConstHandle2ConstNuclide self);

// +++ Print to standard output, as JSON
extern_c int
NuclidePrintJSON(ConstHandle2ConstNuclide self);


// -----------------------------------------------------------------------------
// Metadatum: id
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NuclideIdHas(ConstHandle2ConstNuclide self);

// +++ Get
// +++ Returns by value
extern_c const char *
NuclideIdGet(ConstHandle2ConstNuclide self);

// +++ Set
extern_c void
NuclideIdSet(ConstHandle2Nuclide self, const char *const id);


// -----------------------------------------------------------------------------
// Child: mass
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NuclideMassHas(ConstHandle2ConstNuclide self);

// --- Get, const
extern_c Handle2ConstMass
NuclideMassGetConst(ConstHandle2ConstNuclide self);

// +++ Get, non-const
extern_c Handle2Mass
NuclideMassGet(ConstHandle2Nuclide self);

// +++ Set
extern_c void
NuclideMassSet(ConstHandle2Nuclide self, ConstHandle2ConstMass mass);


// -----------------------------------------------------------------------------
// Child: charge
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NuclideChargeHas(ConstHandle2ConstNuclide self);

// --- Get, const
extern_c Handle2ConstCharge
NuclideChargeGetConst(ConstHandle2ConstNuclide self);

// +++ Get, non-const
extern_c Handle2Charge
NuclideChargeGet(ConstHandle2Nuclide self);

// +++ Set
extern_c void
NuclideChargeSet(ConstHandle2Nuclide self, ConstHandle2ConstCharge charge);


// -----------------------------------------------------------------------------
// Child: nucleus
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NuclideNucleusHas(ConstHandle2ConstNuclide self);

// --- Get, const
extern_c Handle2ConstNucleus
NuclideNucleusGetConst(ConstHandle2ConstNuclide self);

// +++ Get, non-const
extern_c Handle2Nucleus
NuclideNucleusGet(ConstHandle2Nuclide self);

// +++ Set
extern_c void
NuclideNucleusSet(ConstHandle2Nuclide self, ConstHandle2ConstNucleus nucleus);


// -----------------------------------------------------------------------------
// Child: decayData
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NuclideDecayDataHas(ConstHandle2ConstNuclide self);

// --- Get, const
extern_c Handle2ConstDecayData
NuclideDecayDataGetConst(ConstHandle2ConstNuclide self);

// +++ Get, non-const
extern_c Handle2DecayData
NuclideDecayDataGet(ConstHandle2Nuclide self);

// +++ Set
extern_c void
NuclideDecayDataSet(ConstHandle2Nuclide self, ConstHandle2ConstDecayData decayData);


// -----------------------------------------------------------------------------
// Child: fissionFragmentData
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NuclideFissionFragmentDataHas(ConstHandle2ConstNuclide self);

// --- Get, const
extern_c Handle2ConstFissionFragmentData
NuclideFissionFragmentDataGetConst(ConstHandle2ConstNuclide self);

// +++ Get, non-const
extern_c Handle2FissionFragmentData
NuclideFissionFragmentDataGet(ConstHandle2Nuclide self);

// +++ Set
extern_c void
NuclideFissionFragmentDataSet(ConstHandle2Nuclide self, ConstHandle2ConstFissionFragmentData fissionFragmentData);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Nuclide/src/custom.h"

#undef extern_c
#endif