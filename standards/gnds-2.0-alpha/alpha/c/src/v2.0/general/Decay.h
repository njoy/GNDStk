
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
// Decay is the basic handle type in this file. Example:
//    // Create a default Decay object:
//    Decay handle = DecayDefault();
// Functions involving Decay are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_DECAY
#define C_INTERFACE_ALPHA_V2_0_GENERAL_DECAY

#include "GNDStk.h"
#include "v2.0/general/Products.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct DecayClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Decay
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct DecayClass *Decay;

// --- Const-aware handles.
typedef const struct DecayClass *const ConstHandle2ConstDecay;
typedef       struct DecayClass *const ConstHandle2Decay;
typedef const struct DecayClass *      Handle2ConstDecay;
typedef       struct DecayClass *      Handle2Decay;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstDecay
DecayDefaultConst();

// +++ Create, default
extern_c Handle2Decay
DecayDefault();

// --- Create, general, const
extern_c Handle2ConstDecay
DecayCreateConst(
   const int index,
   const char *const mode,
   const bool complete,
   ConstHandle2ConstProducts products
);

// +++ Create, general
extern_c Handle2Decay
DecayCreate(
   const int index,
   const char *const mode,
   const bool complete,
   ConstHandle2ConstProducts products
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
DecayAssign(ConstHandle2Decay self, ConstHandle2ConstDecay from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
DecayDelete(ConstHandle2ConstDecay self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
DecayRead(ConstHandle2Decay self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
DecayWrite(ConstHandle2ConstDecay self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
DecayPrint(ConstHandle2ConstDecay self);

// +++ Print to standard output, as XML
extern_c int
DecayPrintXML(ConstHandle2ConstDecay self);

// +++ Print to standard output, as JSON
extern_c int
DecayPrintJSON(ConstHandle2ConstDecay self);


// -----------------------------------------------------------------------------
// Metadatum: index
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DecayIndexHas(ConstHandle2ConstDecay self);

// +++ Get
// +++ Returns by value
extern_c int
DecayIndexGet(ConstHandle2ConstDecay self);

// +++ Set
extern_c void
DecayIndexSet(ConstHandle2Decay self, const int index);


// -----------------------------------------------------------------------------
// Metadatum: mode
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DecayModeHas(ConstHandle2ConstDecay self);

// +++ Get
// +++ Returns by value
extern_c const char *
DecayModeGet(ConstHandle2ConstDecay self);

// +++ Set
extern_c void
DecayModeSet(ConstHandle2Decay self, const char *const mode);


// -----------------------------------------------------------------------------
// Metadatum: complete
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DecayCompleteHas(ConstHandle2ConstDecay self);

// +++ Get
// +++ Returns by value
extern_c bool
DecayCompleteGet(ConstHandle2ConstDecay self);

// +++ Set
extern_c void
DecayCompleteSet(ConstHandle2Decay self, const bool complete);


// -----------------------------------------------------------------------------
// Child: products
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DecayProductsHas(ConstHandle2ConstDecay self);

// --- Get, const
extern_c Handle2ConstProducts
DecayProductsGetConst(ConstHandle2ConstDecay self);

// +++ Get, non-const
extern_c Handle2Products
DecayProductsGet(ConstHandle2Decay self);

// +++ Set
extern_c void
DecayProductsSet(ConstHandle2Decay self, ConstHandle2ConstProducts products);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Decay/src/custom.h"

#undef extern_c
#endif
