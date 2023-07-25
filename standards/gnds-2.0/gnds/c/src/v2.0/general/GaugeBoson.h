
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
// GaugeBoson is the basic handle type in this file. Example:
//    // Create a default GaugeBoson object:
//    GaugeBoson handle = GaugeBosonDefault();
// Functions involving GaugeBoson are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_GAUGEBOSON
#define C_INTERFACE_GNDS_V2_0_GENERAL_GAUGEBOSON

#include "GNDStk.h"
#include "v2.0/general/Mass.h"
#include "v2.0/general/Spin.h"
#include "v2.0/general/Parity.h"
#include "v2.0/general/Charge.h"
#include "v2.0/general/Halflife.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct GaugeBosonClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ GaugeBoson
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct GaugeBosonClass *GaugeBoson;

// --- Const-aware handles.
typedef const struct GaugeBosonClass *const ConstHandle2ConstGaugeBoson;
typedef       struct GaugeBosonClass *const ConstHandle2GaugeBoson;
typedef const struct GaugeBosonClass *      Handle2ConstGaugeBoson;
typedef       struct GaugeBosonClass *      Handle2GaugeBoson;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstGaugeBoson
GaugeBosonDefaultConst();

// +++ Create, default
extern_c Handle2GaugeBoson
GaugeBosonDefault();

// --- Create, general, const
extern_c Handle2ConstGaugeBoson
GaugeBosonCreateConst(
   const char *const id,
   ConstHandle2ConstMass mass,
   ConstHandle2ConstSpin spin,
   ConstHandle2ConstParity parity,
   ConstHandle2ConstCharge charge,
   ConstHandle2ConstHalflife halflife
);

// +++ Create, general
extern_c Handle2GaugeBoson
GaugeBosonCreate(
   const char *const id,
   ConstHandle2ConstMass mass,
   ConstHandle2ConstSpin spin,
   ConstHandle2ConstParity parity,
   ConstHandle2ConstCharge charge,
   ConstHandle2ConstHalflife halflife
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
GaugeBosonAssign(ConstHandle2GaugeBoson self, ConstHandle2ConstGaugeBoson from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
GaugeBosonDelete(ConstHandle2ConstGaugeBoson self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
GaugeBosonRead(ConstHandle2GaugeBoson self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
GaugeBosonWrite(ConstHandle2ConstGaugeBoson self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
GaugeBosonPrint(ConstHandle2ConstGaugeBoson self);

// +++ Print to standard output, as XML
extern_c int
GaugeBosonPrintXML(ConstHandle2ConstGaugeBoson self);

// +++ Print to standard output, as JSON
extern_c int
GaugeBosonPrintJSON(ConstHandle2ConstGaugeBoson self);


// -----------------------------------------------------------------------------
// Metadatum: id
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
GaugeBosonIdHas(ConstHandle2ConstGaugeBoson self);

// +++ Get
// +++ Returns by value
extern_c const char *
GaugeBosonIdGet(ConstHandle2ConstGaugeBoson self);

// +++ Set
extern_c void
GaugeBosonIdSet(ConstHandle2GaugeBoson self, const char *const id);


// -----------------------------------------------------------------------------
// Child: mass
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
GaugeBosonMassHas(ConstHandle2ConstGaugeBoson self);

// --- Get, const
extern_c Handle2ConstMass
GaugeBosonMassGetConst(ConstHandle2ConstGaugeBoson self);

// +++ Get, non-const
extern_c Handle2Mass
GaugeBosonMassGet(ConstHandle2GaugeBoson self);

// +++ Set
extern_c void
GaugeBosonMassSet(ConstHandle2GaugeBoson self, ConstHandle2ConstMass mass);


// -----------------------------------------------------------------------------
// Child: spin
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
GaugeBosonSpinHas(ConstHandle2ConstGaugeBoson self);

// --- Get, const
extern_c Handle2ConstSpin
GaugeBosonSpinGetConst(ConstHandle2ConstGaugeBoson self);

// +++ Get, non-const
extern_c Handle2Spin
GaugeBosonSpinGet(ConstHandle2GaugeBoson self);

// +++ Set
extern_c void
GaugeBosonSpinSet(ConstHandle2GaugeBoson self, ConstHandle2ConstSpin spin);


// -----------------------------------------------------------------------------
// Child: parity
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
GaugeBosonParityHas(ConstHandle2ConstGaugeBoson self);

// --- Get, const
extern_c Handle2ConstParity
GaugeBosonParityGetConst(ConstHandle2ConstGaugeBoson self);

// +++ Get, non-const
extern_c Handle2Parity
GaugeBosonParityGet(ConstHandle2GaugeBoson self);

// +++ Set
extern_c void
GaugeBosonParitySet(ConstHandle2GaugeBoson self, ConstHandle2ConstParity parity);


// -----------------------------------------------------------------------------
// Child: charge
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
GaugeBosonChargeHas(ConstHandle2ConstGaugeBoson self);

// --- Get, const
extern_c Handle2ConstCharge
GaugeBosonChargeGetConst(ConstHandle2ConstGaugeBoson self);

// +++ Get, non-const
extern_c Handle2Charge
GaugeBosonChargeGet(ConstHandle2GaugeBoson self);

// +++ Set
extern_c void
GaugeBosonChargeSet(ConstHandle2GaugeBoson self, ConstHandle2ConstCharge charge);


// -----------------------------------------------------------------------------
// Child: halflife
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
GaugeBosonHalflifeHas(ConstHandle2ConstGaugeBoson self);

// --- Get, const
extern_c Handle2ConstHalflife
GaugeBosonHalflifeGetConst(ConstHandle2ConstGaugeBoson self);

// +++ Get, non-const
extern_c Handle2Halflife
GaugeBosonHalflifeGet(ConstHandle2GaugeBoson self);

// +++ Set
extern_c void
GaugeBosonHalflifeSet(ConstHandle2GaugeBoson self, ConstHandle2ConstHalflife halflife);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/GaugeBoson/src/custom.h"

#undef extern_c
#endif
