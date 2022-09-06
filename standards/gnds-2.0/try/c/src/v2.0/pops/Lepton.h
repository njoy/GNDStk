
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
// Lepton is the basic handle type in this file. Example:
//    // Create a default Lepton object:
//    Lepton handle = LeptonDefault();
// Functions involving Lepton are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_POPS_LEPTON
#define C_INTERFACE_TRY_V2_0_POPS_LEPTON

#include "GNDStk.h"
#include "v2.0/pops/Charge.h"
#include "v2.0/pops/Halflife.h"
#include "v2.0/pops/Mass.h"
#include "v2.0/pops/Spin.h"
#include "v2.0/pops/Parity.h"
#include "v2.0/pops/DecayData.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct LeptonClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Lepton
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct LeptonClass *Lepton;

// --- Const-aware handles.
typedef const struct LeptonClass *const ConstHandle2ConstLepton;
typedef       struct LeptonClass *const ConstHandle2Lepton;
typedef const struct LeptonClass *      Handle2ConstLepton;
typedef       struct LeptonClass *      Handle2Lepton;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstLepton
LeptonDefaultConst();

// +++ Create, default
extern_c Handle2Lepton
LeptonDefault();

// --- Create, general, const
extern_c Handle2ConstLepton
LeptonCreateConst(
   const XMLName generation,
   const XMLName id,
   ConstHandle2ConstCharge charge,
   ConstHandle2ConstHalflife halflife,
   ConstHandle2ConstMass mass,
   ConstHandle2ConstSpin spin,
   ConstHandle2ConstParity parity,
   ConstHandle2ConstDecayData decayData
);

// +++ Create, general
extern_c Handle2Lepton
LeptonCreate(
   const XMLName generation,
   const XMLName id,
   ConstHandle2ConstCharge charge,
   ConstHandle2ConstHalflife halflife,
   ConstHandle2ConstMass mass,
   ConstHandle2ConstSpin spin,
   ConstHandle2ConstParity parity,
   ConstHandle2ConstDecayData decayData
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
LeptonAssign(ConstHandle2Lepton This, ConstHandle2ConstLepton from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
LeptonDelete(ConstHandle2ConstLepton This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
LeptonRead(ConstHandle2Lepton This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
LeptonWrite(ConstHandle2ConstLepton This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
LeptonPrint(ConstHandle2ConstLepton This);

// +++ Print to standard output, as XML
extern_c int
LeptonPrintXML(ConstHandle2ConstLepton This);

// +++ Print to standard output, as JSON
extern_c int
LeptonPrintJSON(ConstHandle2ConstLepton This);


// -----------------------------------------------------------------------------
// Metadatum: generation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
LeptonGenerationHas(ConstHandle2ConstLepton This);

// +++ Get
// +++ Returns by value
extern_c XMLName
LeptonGenerationGet(ConstHandle2ConstLepton This);

// +++ Set
extern_c void
LeptonGenerationSet(ConstHandle2Lepton This, const XMLName generation);


// -----------------------------------------------------------------------------
// Metadatum: id
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
LeptonIdHas(ConstHandle2ConstLepton This);

// +++ Get
// +++ Returns by value
extern_c XMLName
LeptonIdGet(ConstHandle2ConstLepton This);

// +++ Set
extern_c void
LeptonIdSet(ConstHandle2Lepton This, const XMLName id);


// -----------------------------------------------------------------------------
// Child: charge
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
LeptonChargeHas(ConstHandle2ConstLepton This);

// --- Get, const
extern_c Handle2ConstCharge
LeptonChargeGetConst(ConstHandle2ConstLepton This);

// +++ Get, non-const
extern_c Handle2Charge
LeptonChargeGet(ConstHandle2Lepton This);

// +++ Set
extern_c void
LeptonChargeSet(ConstHandle2Lepton This, ConstHandle2ConstCharge charge);


// -----------------------------------------------------------------------------
// Child: halflife
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
LeptonHalflifeHas(ConstHandle2ConstLepton This);

// --- Get, const
extern_c Handle2ConstHalflife
LeptonHalflifeGetConst(ConstHandle2ConstLepton This);

// +++ Get, non-const
extern_c Handle2Halflife
LeptonHalflifeGet(ConstHandle2Lepton This);

// +++ Set
extern_c void
LeptonHalflifeSet(ConstHandle2Lepton This, ConstHandle2ConstHalflife halflife);


// -----------------------------------------------------------------------------
// Child: mass
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
LeptonMassHas(ConstHandle2ConstLepton This);

// --- Get, const
extern_c Handle2ConstMass
LeptonMassGetConst(ConstHandle2ConstLepton This);

// +++ Get, non-const
extern_c Handle2Mass
LeptonMassGet(ConstHandle2Lepton This);

// +++ Set
extern_c void
LeptonMassSet(ConstHandle2Lepton This, ConstHandle2ConstMass mass);


// -----------------------------------------------------------------------------
// Child: spin
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
LeptonSpinHas(ConstHandle2ConstLepton This);

// --- Get, const
extern_c Handle2ConstSpin
LeptonSpinGetConst(ConstHandle2ConstLepton This);

// +++ Get, non-const
extern_c Handle2Spin
LeptonSpinGet(ConstHandle2Lepton This);

// +++ Set
extern_c void
LeptonSpinSet(ConstHandle2Lepton This, ConstHandle2ConstSpin spin);


// -----------------------------------------------------------------------------
// Child: parity
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
LeptonParityHas(ConstHandle2ConstLepton This);

// --- Get, const
extern_c Handle2ConstParity
LeptonParityGetConst(ConstHandle2ConstLepton This);

// +++ Get, non-const
extern_c Handle2Parity
LeptonParityGet(ConstHandle2Lepton This);

// +++ Set
extern_c void
LeptonParitySet(ConstHandle2Lepton This, ConstHandle2ConstParity parity);


// -----------------------------------------------------------------------------
// Child: decayData
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
LeptonDecayDataHas(ConstHandle2ConstLepton This);

// --- Get, const
extern_c Handle2ConstDecayData
LeptonDecayDataGetConst(ConstHandle2ConstLepton This);

// +++ Get, non-const
extern_c Handle2DecayData
LeptonDecayDataGet(ConstHandle2Lepton This);

// +++ Set
extern_c void
LeptonDecayDataSet(ConstHandle2Lepton This, ConstHandle2ConstDecayData decayData);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif