
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
// ThermalNeutronScatteringLaw_coherentElastic is the basic handle type in this file. Example:
//    // Create a default ThermalNeutronScatteringLaw_coherentElastic object:
//    ThermalNeutronScatteringLaw_coherentElastic handle = ThermalNeutronScatteringLaw_coherentElasticDefault();
// Functions involving ThermalNeutronScatteringLaw_coherentElastic are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_THERMALNEUTRONSCATTERINGLAW_COHERENTELASTIC
#define C_INTERFACE_GNDS_V2_0_GENERAL_THERMALNEUTRONSCATTERINGLAW_COHERENTELASTIC

#include "GNDStk.h"
#include "v2.0/general/S_table.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ThermalNeutronScatteringLaw_coherentElasticClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ThermalNeutronScatteringLaw_coherentElastic
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ThermalNeutronScatteringLaw_coherentElasticClass *ThermalNeutronScatteringLaw_coherentElastic;

// --- Const-aware handles.
typedef const struct ThermalNeutronScatteringLaw_coherentElasticClass *const ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic;
typedef       struct ThermalNeutronScatteringLaw_coherentElasticClass *const ConstHandle2ThermalNeutronScatteringLaw_coherentElastic;
typedef const struct ThermalNeutronScatteringLaw_coherentElasticClass *      Handle2ConstThermalNeutronScatteringLaw_coherentElastic;
typedef       struct ThermalNeutronScatteringLaw_coherentElasticClass *      Handle2ThermalNeutronScatteringLaw_coherentElastic;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstThermalNeutronScatteringLaw_coherentElastic
ThermalNeutronScatteringLaw_coherentElasticDefaultConst();

// +++ Create, default
extern_c Handle2ThermalNeutronScatteringLaw_coherentElastic
ThermalNeutronScatteringLaw_coherentElasticDefault();

// --- Create, general, const
extern_c Handle2ConstThermalNeutronScatteringLaw_coherentElastic
ThermalNeutronScatteringLaw_coherentElasticCreateConst(
   const char *const label,
   const char *const pid,
   const char *const productFrame,
   ConstHandle2ConstS_table S_table
);

// +++ Create, general
extern_c Handle2ThermalNeutronScatteringLaw_coherentElastic
ThermalNeutronScatteringLaw_coherentElasticCreate(
   const char *const label,
   const char *const pid,
   const char *const productFrame,
   ConstHandle2ConstS_table S_table
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ThermalNeutronScatteringLaw_coherentElasticAssign(ConstHandle2ThermalNeutronScatteringLaw_coherentElastic self, ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ThermalNeutronScatteringLaw_coherentElasticDelete(ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ThermalNeutronScatteringLaw_coherentElasticRead(ConstHandle2ThermalNeutronScatteringLaw_coherentElastic self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ThermalNeutronScatteringLaw_coherentElasticWrite(ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ThermalNeutronScatteringLaw_coherentElasticPrint(ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic self);

// +++ Print to standard output, as XML
extern_c int
ThermalNeutronScatteringLaw_coherentElasticPrintXML(ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic self);

// +++ Print to standard output, as JSON
extern_c int
ThermalNeutronScatteringLaw_coherentElasticPrintJSON(ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic self);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ThermalNeutronScatteringLaw_coherentElasticLabelHas(ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic self);

// +++ Get
// +++ Returns by value
extern_c const char *
ThermalNeutronScatteringLaw_coherentElasticLabelGet(ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic self);

// +++ Set
extern_c void
ThermalNeutronScatteringLaw_coherentElasticLabelSet(ConstHandle2ThermalNeutronScatteringLaw_coherentElastic self, const char *const label);


// -----------------------------------------------------------------------------
// Metadatum: pid
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ThermalNeutronScatteringLaw_coherentElasticPidHas(ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic self);

// +++ Get
// +++ Returns by value
extern_c const char *
ThermalNeutronScatteringLaw_coherentElasticPidGet(ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic self);

// +++ Set
extern_c void
ThermalNeutronScatteringLaw_coherentElasticPidSet(ConstHandle2ThermalNeutronScatteringLaw_coherentElastic self, const char *const pid);


// -----------------------------------------------------------------------------
// Metadatum: productFrame
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ThermalNeutronScatteringLaw_coherentElasticProductFrameHas(ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic self);

// +++ Get
// +++ Returns by value
extern_c const char *
ThermalNeutronScatteringLaw_coherentElasticProductFrameGet(ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic self);

// +++ Set
extern_c void
ThermalNeutronScatteringLaw_coherentElasticProductFrameSet(ConstHandle2ThermalNeutronScatteringLaw_coherentElastic self, const char *const productFrame);


// -----------------------------------------------------------------------------
// Child: S_table
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ThermalNeutronScatteringLaw_coherentElasticS_tableHas(ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic self);

// --- Get, const
extern_c Handle2ConstS_table
ThermalNeutronScatteringLaw_coherentElasticS_tableGetConst(ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic self);

// +++ Get, non-const
extern_c Handle2S_table
ThermalNeutronScatteringLaw_coherentElasticS_tableGet(ConstHandle2ThermalNeutronScatteringLaw_coherentElastic self);

// +++ Set
extern_c void
ThermalNeutronScatteringLaw_coherentElasticS_tableSet(ConstHandle2ThermalNeutronScatteringLaw_coherentElastic self, ConstHandle2ConstS_table S_table);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/ThermalNeutronScatteringLaw_coherentElastic/src/custom.h"

#undef extern_c
#endif
