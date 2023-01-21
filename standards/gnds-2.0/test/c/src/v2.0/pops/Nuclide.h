
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

#ifndef C_INTERFACE_TEST_V2_0_POPS_NUCLIDE
#define C_INTERFACE_TEST_V2_0_POPS_NUCLIDE

#include "GNDStk.h"
#include "v2.0/pops/Charge.h"
#include "v2.0/pops/Mass.h"
#include "v2.0/pops/Spin.h"
#include "v2.0/pops/Parity.h"
#include "v2.0/pops/Nucleus.h"
#include "v2.0/pops/DecayData.h"
#include "v2.0/fissionFragmentData/FissionFragmentData.h"

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
   const XMLName id,
   ConstHandle2ConstCharge charge,
   ConstHandle2ConstMass mass,
   ConstHandle2ConstSpin spin,
   ConstHandle2ConstParity parity,
   ConstHandle2ConstNucleus nucleus,
   ConstHandle2ConstDecayData decayData,
   ConstHandle2ConstFissionFragmentData fissionFragmentData
);

// +++ Create, general
extern_c Handle2Nuclide
NuclideCreate(
   const XMLName id,
   ConstHandle2ConstCharge charge,
   ConstHandle2ConstMass mass,
   ConstHandle2ConstSpin spin,
   ConstHandle2ConstParity parity,
   ConstHandle2ConstNucleus nucleus,
   ConstHandle2ConstDecayData decayData,
   ConstHandle2ConstFissionFragmentData fissionFragmentData
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
NuclideAssign(ConstHandle2Nuclide This, ConstHandle2ConstNuclide from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
NuclideDelete(ConstHandle2ConstNuclide This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
NuclideRead(ConstHandle2Nuclide This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
NuclideWrite(ConstHandle2ConstNuclide This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
NuclidePrint(ConstHandle2ConstNuclide This);

// +++ Print to standard output, as XML
extern_c int
NuclidePrintXML(ConstHandle2ConstNuclide This);

// +++ Print to standard output, as JSON
extern_c int
NuclidePrintJSON(ConstHandle2ConstNuclide This);


// -----------------------------------------------------------------------------
// Metadatum: id
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NuclideIdHas(ConstHandle2ConstNuclide This);

// +++ Get
// +++ Returns by value
extern_c XMLName
NuclideIdGet(ConstHandle2ConstNuclide This);

// +++ Set
extern_c void
NuclideIdSet(ConstHandle2Nuclide This, const XMLName id);


// -----------------------------------------------------------------------------
// Child: charge
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NuclideChargeHas(ConstHandle2ConstNuclide This);

// --- Get, const
extern_c Handle2ConstCharge
NuclideChargeGetConst(ConstHandle2ConstNuclide This);

// +++ Get, non-const
extern_c Handle2Charge
NuclideChargeGet(ConstHandle2Nuclide This);

// +++ Set
extern_c void
NuclideChargeSet(ConstHandle2Nuclide This, ConstHandle2ConstCharge charge);


// -----------------------------------------------------------------------------
// Child: mass
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NuclideMassHas(ConstHandle2ConstNuclide This);

// --- Get, const
extern_c Handle2ConstMass
NuclideMassGetConst(ConstHandle2ConstNuclide This);

// +++ Get, non-const
extern_c Handle2Mass
NuclideMassGet(ConstHandle2Nuclide This);

// +++ Set
extern_c void
NuclideMassSet(ConstHandle2Nuclide This, ConstHandle2ConstMass mass);


// -----------------------------------------------------------------------------
// Child: spin
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NuclideSpinHas(ConstHandle2ConstNuclide This);

// --- Get, const
extern_c Handle2ConstSpin
NuclideSpinGetConst(ConstHandle2ConstNuclide This);

// +++ Get, non-const
extern_c Handle2Spin
NuclideSpinGet(ConstHandle2Nuclide This);

// +++ Set
extern_c void
NuclideSpinSet(ConstHandle2Nuclide This, ConstHandle2ConstSpin spin);


// -----------------------------------------------------------------------------
// Child: parity
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NuclideParityHas(ConstHandle2ConstNuclide This);

// --- Get, const
extern_c Handle2ConstParity
NuclideParityGetConst(ConstHandle2ConstNuclide This);

// +++ Get, non-const
extern_c Handle2Parity
NuclideParityGet(ConstHandle2Nuclide This);

// +++ Set
extern_c void
NuclideParitySet(ConstHandle2Nuclide This, ConstHandle2ConstParity parity);


// -----------------------------------------------------------------------------
// Child: nucleus
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NuclideNucleusHas(ConstHandle2ConstNuclide This);

// --- Get, const
extern_c Handle2ConstNucleus
NuclideNucleusGetConst(ConstHandle2ConstNuclide This);

// +++ Get, non-const
extern_c Handle2Nucleus
NuclideNucleusGet(ConstHandle2Nuclide This);

// +++ Set
extern_c void
NuclideNucleusSet(ConstHandle2Nuclide This, ConstHandle2ConstNucleus nucleus);


// -----------------------------------------------------------------------------
// Child: decayData
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NuclideDecayDataHas(ConstHandle2ConstNuclide This);

// --- Get, const
extern_c Handle2ConstDecayData
NuclideDecayDataGetConst(ConstHandle2ConstNuclide This);

// +++ Get, non-const
extern_c Handle2DecayData
NuclideDecayDataGet(ConstHandle2Nuclide This);

// +++ Set
extern_c void
NuclideDecayDataSet(ConstHandle2Nuclide This, ConstHandle2ConstDecayData decayData);


// -----------------------------------------------------------------------------
// Child: fissionFragmentData
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NuclideFissionFragmentDataHas(ConstHandle2ConstNuclide This);

// --- Get, const
extern_c Handle2ConstFissionFragmentData
NuclideFissionFragmentDataGetConst(ConstHandle2ConstNuclide This);

// +++ Get, non-const
extern_c Handle2FissionFragmentData
NuclideFissionFragmentDataGet(ConstHandle2Nuclide This);

// +++ Set
extern_c void
NuclideFissionFragmentDataSet(ConstHandle2Nuclide This, ConstHandle2ConstFissionFragmentData fissionFragmentData);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/pops/Nuclide/src/custom.h"

#undef extern_c
#endif
