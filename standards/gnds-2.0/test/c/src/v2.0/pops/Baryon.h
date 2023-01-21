
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
// Baryon is the basic handle type in this file. Example:
//    // Create a default Baryon object:
//    Baryon handle = BaryonDefault();
// Functions involving Baryon are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_POPS_BARYON
#define C_INTERFACE_TEST_V2_0_POPS_BARYON

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
struct BaryonClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Baryon
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct BaryonClass *Baryon;

// --- Const-aware handles.
typedef const struct BaryonClass *const ConstHandle2ConstBaryon;
typedef       struct BaryonClass *const ConstHandle2Baryon;
typedef const struct BaryonClass *      Handle2ConstBaryon;
typedef       struct BaryonClass *      Handle2Baryon;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstBaryon
BaryonDefaultConst();

// +++ Create, default
extern_c Handle2Baryon
BaryonDefault();

// --- Create, general, const
extern_c Handle2ConstBaryon
BaryonCreateConst(
   const XMLName id,
   ConstHandle2ConstCharge charge,
   ConstHandle2ConstHalflife halflife,
   ConstHandle2ConstMass mass,
   ConstHandle2ConstSpin spin,
   ConstHandle2ConstParity parity,
   ConstHandle2ConstDecayData decayData
);

// +++ Create, general
extern_c Handle2Baryon
BaryonCreate(
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
BaryonAssign(ConstHandle2Baryon This, ConstHandle2ConstBaryon from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
BaryonDelete(ConstHandle2ConstBaryon This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
BaryonRead(ConstHandle2Baryon This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
BaryonWrite(ConstHandle2ConstBaryon This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
BaryonPrint(ConstHandle2ConstBaryon This);

// +++ Print to standard output, as XML
extern_c int
BaryonPrintXML(ConstHandle2ConstBaryon This);

// +++ Print to standard output, as JSON
extern_c int
BaryonPrintJSON(ConstHandle2ConstBaryon This);


// -----------------------------------------------------------------------------
// Metadatum: id
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BaryonIdHas(ConstHandle2ConstBaryon This);

// +++ Get
// +++ Returns by value
extern_c XMLName
BaryonIdGet(ConstHandle2ConstBaryon This);

// +++ Set
extern_c void
BaryonIdSet(ConstHandle2Baryon This, const XMLName id);


// -----------------------------------------------------------------------------
// Child: charge
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BaryonChargeHas(ConstHandle2ConstBaryon This);

// --- Get, const
extern_c Handle2ConstCharge
BaryonChargeGetConst(ConstHandle2ConstBaryon This);

// +++ Get, non-const
extern_c Handle2Charge
BaryonChargeGet(ConstHandle2Baryon This);

// +++ Set
extern_c void
BaryonChargeSet(ConstHandle2Baryon This, ConstHandle2ConstCharge charge);


// -----------------------------------------------------------------------------
// Child: halflife
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BaryonHalflifeHas(ConstHandle2ConstBaryon This);

// --- Get, const
extern_c Handle2ConstHalflife
BaryonHalflifeGetConst(ConstHandle2ConstBaryon This);

// +++ Get, non-const
extern_c Handle2Halflife
BaryonHalflifeGet(ConstHandle2Baryon This);

// +++ Set
extern_c void
BaryonHalflifeSet(ConstHandle2Baryon This, ConstHandle2ConstHalflife halflife);


// -----------------------------------------------------------------------------
// Child: mass
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BaryonMassHas(ConstHandle2ConstBaryon This);

// --- Get, const
extern_c Handle2ConstMass
BaryonMassGetConst(ConstHandle2ConstBaryon This);

// +++ Get, non-const
extern_c Handle2Mass
BaryonMassGet(ConstHandle2Baryon This);

// +++ Set
extern_c void
BaryonMassSet(ConstHandle2Baryon This, ConstHandle2ConstMass mass);


// -----------------------------------------------------------------------------
// Child: spin
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BaryonSpinHas(ConstHandle2ConstBaryon This);

// --- Get, const
extern_c Handle2ConstSpin
BaryonSpinGetConst(ConstHandle2ConstBaryon This);

// +++ Get, non-const
extern_c Handle2Spin
BaryonSpinGet(ConstHandle2Baryon This);

// +++ Set
extern_c void
BaryonSpinSet(ConstHandle2Baryon This, ConstHandle2ConstSpin spin);


// -----------------------------------------------------------------------------
// Child: parity
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BaryonParityHas(ConstHandle2ConstBaryon This);

// --- Get, const
extern_c Handle2ConstParity
BaryonParityGetConst(ConstHandle2ConstBaryon This);

// +++ Get, non-const
extern_c Handle2Parity
BaryonParityGet(ConstHandle2Baryon This);

// +++ Set
extern_c void
BaryonParitySet(ConstHandle2Baryon This, ConstHandle2ConstParity parity);


// -----------------------------------------------------------------------------
// Child: decayData
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BaryonDecayDataHas(ConstHandle2ConstBaryon This);

// --- Get, const
extern_c Handle2ConstDecayData
BaryonDecayDataGetConst(ConstHandle2ConstBaryon This);

// +++ Get, non-const
extern_c Handle2DecayData
BaryonDecayDataGet(ConstHandle2Baryon This);

// +++ Set
extern_c void
BaryonDecayDataSet(ConstHandle2Baryon This, ConstHandle2ConstDecayData decayData);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/pops/Baryon/src/custom.h"

#undef extern_c
#endif
