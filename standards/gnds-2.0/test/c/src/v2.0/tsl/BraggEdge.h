
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
// BraggEdge is the basic handle type in this file. Example:
//    // Create a default BraggEdge object:
//    BraggEdge handle = BraggEdgeDefault();
// Functions involving BraggEdge are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_TSL_BRAGGEDGE
#define C_INTERFACE_TEST_V2_0_TSL_BRAGGEDGE

#include "GNDStk.h"
#include "v2.0/tsl/BraggEnergy.h"
#include "v2.0/tsl/StructureFactor.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct BraggEdgeClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ BraggEdge
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct BraggEdgeClass *BraggEdge;

// --- Const-aware handles.
typedef const struct BraggEdgeClass *const ConstHandle2ConstBraggEdge;
typedef       struct BraggEdgeClass *const ConstHandle2BraggEdge;
typedef const struct BraggEdgeClass *      Handle2ConstBraggEdge;
typedef       struct BraggEdgeClass *      Handle2BraggEdge;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstBraggEdge
BraggEdgeDefaultConst();

// +++ Create, default
extern_c Handle2BraggEdge
BraggEdgeDefault();

// --- Create, general, const
extern_c Handle2ConstBraggEdge
BraggEdgeCreateConst(
   const XMLName label,
   ConstHandle2ConstBraggEnergy BraggEnergy,
   ConstHandle2ConstStructureFactor structureFactor
);

// +++ Create, general
extern_c Handle2BraggEdge
BraggEdgeCreate(
   const XMLName label,
   ConstHandle2ConstBraggEnergy BraggEnergy,
   ConstHandle2ConstStructureFactor structureFactor
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
BraggEdgeAssign(ConstHandle2BraggEdge self, ConstHandle2ConstBraggEdge from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
BraggEdgeDelete(ConstHandle2ConstBraggEdge self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
BraggEdgeRead(ConstHandle2BraggEdge self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
BraggEdgeWrite(ConstHandle2ConstBraggEdge self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
BraggEdgePrint(ConstHandle2ConstBraggEdge self);

// +++ Print to standard output, as XML
extern_c int
BraggEdgePrintXML(ConstHandle2ConstBraggEdge self);

// +++ Print to standard output, as JSON
extern_c int
BraggEdgePrintJSON(ConstHandle2ConstBraggEdge self);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BraggEdgeLabelHas(ConstHandle2ConstBraggEdge self);

// +++ Get
// +++ Returns by value
extern_c XMLName
BraggEdgeLabelGet(ConstHandle2ConstBraggEdge self);

// +++ Set
extern_c void
BraggEdgeLabelSet(ConstHandle2BraggEdge self, const XMLName label);


// -----------------------------------------------------------------------------
// Child: BraggEnergy
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BraggEdgeBraggEnergyHas(ConstHandle2ConstBraggEdge self);

// --- Get, const
extern_c Handle2ConstBraggEnergy
BraggEdgeBraggEnergyGetConst(ConstHandle2ConstBraggEdge self);

// +++ Get, non-const
extern_c Handle2BraggEnergy
BraggEdgeBraggEnergyGet(ConstHandle2BraggEdge self);

// +++ Set
extern_c void
BraggEdgeBraggEnergySet(ConstHandle2BraggEdge self, ConstHandle2ConstBraggEnergy BraggEnergy);


// -----------------------------------------------------------------------------
// Child: structureFactor
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BraggEdgeStructureFactorHas(ConstHandle2ConstBraggEdge self);

// --- Get, const
extern_c Handle2ConstStructureFactor
BraggEdgeStructureFactorGetConst(ConstHandle2ConstBraggEdge self);

// +++ Get, non-const
extern_c Handle2StructureFactor
BraggEdgeStructureFactorGet(ConstHandle2BraggEdge self);

// +++ Set
extern_c void
BraggEdgeStructureFactorSet(ConstHandle2BraggEdge self, ConstHandle2ConstStructureFactor structureFactor);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/tsl/BraggEdge/src/custom.h"

#undef extern_c
#endif
