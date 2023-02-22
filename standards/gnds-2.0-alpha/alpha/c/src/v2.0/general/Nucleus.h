
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
// Nucleus is the basic handle type in this file. Example:
//    // Create a default Nucleus object:
//    Nucleus handle = NucleusDefault();
// Functions involving Nucleus are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_NUCLEUS
#define C_INTERFACE_ALPHA_V2_0_GENERAL_NUCLEUS

#include "GNDStk.h"
#include "v2.0/general/Mass.h"
#include "v2.0/general/Spin.h"
#include "v2.0/general/Parity.h"
#include "v2.0/general/Charge.h"
#include "v2.0/general/Halflife.h"
#include "v2.0/general/Energy.h"
#include "v2.0/general/DecayData.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct NucleusClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Nucleus
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct NucleusClass *Nucleus;

// --- Const-aware handles.
typedef const struct NucleusClass *const ConstHandle2ConstNucleus;
typedef       struct NucleusClass *const ConstHandle2Nucleus;
typedef const struct NucleusClass *      Handle2ConstNucleus;
typedef       struct NucleusClass *      Handle2Nucleus;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstNucleus
NucleusDefaultConst();

// +++ Create, default
extern_c Handle2Nucleus
NucleusDefault();

// --- Create, general, const
extern_c Handle2ConstNucleus
NucleusCreateConst(
   const char *const id,
   const int index,
   ConstHandle2ConstMass mass,
   ConstHandle2ConstSpin spin,
   ConstHandle2ConstParity parity,
   ConstHandle2ConstCharge charge,
   ConstHandle2ConstHalflife halflife,
   ConstHandle2ConstEnergy energy,
   ConstHandle2ConstDecayData decayData
);

// +++ Create, general
extern_c Handle2Nucleus
NucleusCreate(
   const char *const id,
   const int index,
   ConstHandle2ConstMass mass,
   ConstHandle2ConstSpin spin,
   ConstHandle2ConstParity parity,
   ConstHandle2ConstCharge charge,
   ConstHandle2ConstHalflife halflife,
   ConstHandle2ConstEnergy energy,
   ConstHandle2ConstDecayData decayData
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
NucleusAssign(ConstHandle2Nucleus self, ConstHandle2ConstNucleus from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
NucleusDelete(ConstHandle2ConstNucleus self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
NucleusRead(ConstHandle2Nucleus self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
NucleusWrite(ConstHandle2ConstNucleus self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
NucleusPrint(ConstHandle2ConstNucleus self);

// +++ Print to standard output, as XML
extern_c int
NucleusPrintXML(ConstHandle2ConstNucleus self);

// +++ Print to standard output, as JSON
extern_c int
NucleusPrintJSON(ConstHandle2ConstNucleus self);


// -----------------------------------------------------------------------------
// Metadatum: id
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NucleusIdHas(ConstHandle2ConstNucleus self);

// +++ Get
// +++ Returns by value
extern_c const char *
NucleusIdGet(ConstHandle2ConstNucleus self);

// +++ Set
extern_c void
NucleusIdSet(ConstHandle2Nucleus self, const char *const id);


// -----------------------------------------------------------------------------
// Metadatum: index
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NucleusIndexHas(ConstHandle2ConstNucleus self);

// +++ Get
// +++ Returns by value
extern_c int
NucleusIndexGet(ConstHandle2ConstNucleus self);

// +++ Set
extern_c void
NucleusIndexSet(ConstHandle2Nucleus self, const int index);


// -----------------------------------------------------------------------------
// Child: mass
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NucleusMassHas(ConstHandle2ConstNucleus self);

// --- Get, const
extern_c Handle2ConstMass
NucleusMassGetConst(ConstHandle2ConstNucleus self);

// +++ Get, non-const
extern_c Handle2Mass
NucleusMassGet(ConstHandle2Nucleus self);

// +++ Set
extern_c void
NucleusMassSet(ConstHandle2Nucleus self, ConstHandle2ConstMass mass);


// -----------------------------------------------------------------------------
// Child: spin
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NucleusSpinHas(ConstHandle2ConstNucleus self);

// --- Get, const
extern_c Handle2ConstSpin
NucleusSpinGetConst(ConstHandle2ConstNucleus self);

// +++ Get, non-const
extern_c Handle2Spin
NucleusSpinGet(ConstHandle2Nucleus self);

// +++ Set
extern_c void
NucleusSpinSet(ConstHandle2Nucleus self, ConstHandle2ConstSpin spin);


// -----------------------------------------------------------------------------
// Child: parity
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NucleusParityHas(ConstHandle2ConstNucleus self);

// --- Get, const
extern_c Handle2ConstParity
NucleusParityGetConst(ConstHandle2ConstNucleus self);

// +++ Get, non-const
extern_c Handle2Parity
NucleusParityGet(ConstHandle2Nucleus self);

// +++ Set
extern_c void
NucleusParitySet(ConstHandle2Nucleus self, ConstHandle2ConstParity parity);


// -----------------------------------------------------------------------------
// Child: charge
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NucleusChargeHas(ConstHandle2ConstNucleus self);

// --- Get, const
extern_c Handle2ConstCharge
NucleusChargeGetConst(ConstHandle2ConstNucleus self);

// +++ Get, non-const
extern_c Handle2Charge
NucleusChargeGet(ConstHandle2Nucleus self);

// +++ Set
extern_c void
NucleusChargeSet(ConstHandle2Nucleus self, ConstHandle2ConstCharge charge);


// -----------------------------------------------------------------------------
// Child: halflife
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NucleusHalflifeHas(ConstHandle2ConstNucleus self);

// --- Get, const
extern_c Handle2ConstHalflife
NucleusHalflifeGetConst(ConstHandle2ConstNucleus self);

// +++ Get, non-const
extern_c Handle2Halflife
NucleusHalflifeGet(ConstHandle2Nucleus self);

// +++ Set
extern_c void
NucleusHalflifeSet(ConstHandle2Nucleus self, ConstHandle2ConstHalflife halflife);


// -----------------------------------------------------------------------------
// Child: energy
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NucleusEnergyHas(ConstHandle2ConstNucleus self);

// --- Get, const
extern_c Handle2ConstEnergy
NucleusEnergyGetConst(ConstHandle2ConstNucleus self);

// +++ Get, non-const
extern_c Handle2Energy
NucleusEnergyGet(ConstHandle2Nucleus self);

// +++ Set
extern_c void
NucleusEnergySet(ConstHandle2Nucleus self, ConstHandle2ConstEnergy energy);


// -----------------------------------------------------------------------------
// Child: decayData
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NucleusDecayDataHas(ConstHandle2ConstNucleus self);

// --- Get, const
extern_c Handle2ConstDecayData
NucleusDecayDataGetConst(ConstHandle2ConstNucleus self);

// +++ Get, non-const
extern_c Handle2DecayData
NucleusDecayDataGet(ConstHandle2Nucleus self);

// +++ Set
extern_c void
NucleusDecayDataSet(ConstHandle2Nucleus self, ConstHandle2ConstDecayData decayData);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Nucleus/src/custom.h"

#undef extern_c
#endif