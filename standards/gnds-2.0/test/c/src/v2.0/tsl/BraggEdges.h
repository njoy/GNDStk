
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
// BraggEdges is the basic handle type in this file. Example:
//    // Create a default BraggEdges object:
//    BraggEdges handle = BraggEdgesDefault();
// Functions involving BraggEdges are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_TSL_BRAGGEDGES
#define C_INTERFACE_TEST_V2_0_TSL_BRAGGEDGES

#include "GNDStk.h"
#include "v2.0/tsl/BraggEdge.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct BraggEdgesClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ BraggEdges
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct BraggEdgesClass *BraggEdges;

// --- Const-aware handles.
typedef const struct BraggEdgesClass *const ConstHandle2ConstBraggEdges;
typedef       struct BraggEdgesClass *const ConstHandle2BraggEdges;
typedef const struct BraggEdgesClass *      Handle2ConstBraggEdges;
typedef       struct BraggEdgesClass *      Handle2BraggEdges;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstBraggEdges
BraggEdgesDefaultConst();

// +++ Create, default
extern_c Handle2BraggEdges
BraggEdgesDefault();

// --- Create, general, const
extern_c Handle2ConstBraggEdges
BraggEdgesCreateConst(
   ConstHandle2BraggEdge *const BraggEdge, const size_t BraggEdgeSize
);

// +++ Create, general
extern_c Handle2BraggEdges
BraggEdgesCreate(
   ConstHandle2BraggEdge *const BraggEdge, const size_t BraggEdgeSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
BraggEdgesAssign(ConstHandle2BraggEdges self, ConstHandle2ConstBraggEdges from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
BraggEdgesDelete(ConstHandle2ConstBraggEdges self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
BraggEdgesRead(ConstHandle2BraggEdges self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
BraggEdgesWrite(ConstHandle2ConstBraggEdges self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
BraggEdgesPrint(ConstHandle2ConstBraggEdges self);

// +++ Print to standard output, as XML
extern_c int
BraggEdgesPrintXML(ConstHandle2ConstBraggEdges self);

// +++ Print to standard output, as JSON
extern_c int
BraggEdgesPrintJSON(ConstHandle2ConstBraggEdges self);


// -----------------------------------------------------------------------------
// Child: BraggEdge
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BraggEdgesBraggEdgeHas(ConstHandle2ConstBraggEdges self);

// +++ Clear
extern_c void
BraggEdgesBraggEdgeClear(ConstHandle2BraggEdges self);

// +++ Size
extern_c size_t
BraggEdgesBraggEdgeSize(ConstHandle2ConstBraggEdges self);

// +++ Add
extern_c void
BraggEdgesBraggEdgeAdd(ConstHandle2BraggEdges self, ConstHandle2ConstBraggEdge BraggEdge);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstBraggEdge
BraggEdgesBraggEdgeGetConst(ConstHandle2ConstBraggEdges self, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2BraggEdge
BraggEdgesBraggEdgeGet(ConstHandle2BraggEdges self, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
BraggEdgesBraggEdgeSet(
   ConstHandle2BraggEdges self,
   const size_t index_,
   ConstHandle2ConstBraggEdge BraggEdge
);

// +++ Has, by label
extern_c int
BraggEdgesBraggEdgeHasByLabel(
   ConstHandle2ConstBraggEdges self,
   const XMLName label
);

// --- Get, by label, const
extern_c Handle2ConstBraggEdge
BraggEdgesBraggEdgeGetByLabelConst(
   ConstHandle2ConstBraggEdges self,
   const XMLName label
);

// +++ Get, by label, non-const
extern_c Handle2BraggEdge
BraggEdgesBraggEdgeGetByLabel(
   ConstHandle2BraggEdges self,
   const XMLName label
);

// +++ Set, by label
extern_c void
BraggEdgesBraggEdgeSetByLabel(
   ConstHandle2BraggEdges self,
   const XMLName label,
   ConstHandle2ConstBraggEdge BraggEdge
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/tsl/BraggEdges/src/custom.h"

#undef extern_c
#endif
