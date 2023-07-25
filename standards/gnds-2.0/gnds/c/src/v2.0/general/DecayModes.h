
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
// DecayModes is the basic handle type in this file. Example:
//    // Create a default DecayModes object:
//    DecayModes handle = DecayModesDefault();
// Functions involving DecayModes are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_DECAYMODES
#define C_INTERFACE_GNDS_V2_0_GENERAL_DECAYMODES

#include "GNDStk.h"
#include "v2.0/general/DecayMode.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct DecayModesClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ DecayModes
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct DecayModesClass *DecayModes;

// --- Const-aware handles.
typedef const struct DecayModesClass *const ConstHandle2ConstDecayModes;
typedef       struct DecayModesClass *const ConstHandle2DecayModes;
typedef const struct DecayModesClass *      Handle2ConstDecayModes;
typedef       struct DecayModesClass *      Handle2DecayModes;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstDecayModes
DecayModesDefaultConst();

// +++ Create, default
extern_c Handle2DecayModes
DecayModesDefault();

// --- Create, general, const
extern_c Handle2ConstDecayModes
DecayModesCreateConst(
   ConstHandle2DecayMode *const decayMode, const size_t decayModeSize
);

// +++ Create, general
extern_c Handle2DecayModes
DecayModesCreate(
   ConstHandle2DecayMode *const decayMode, const size_t decayModeSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
DecayModesAssign(ConstHandle2DecayModes self, ConstHandle2ConstDecayModes from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
DecayModesDelete(ConstHandle2ConstDecayModes self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
DecayModesRead(ConstHandle2DecayModes self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
DecayModesWrite(ConstHandle2ConstDecayModes self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
DecayModesPrint(ConstHandle2ConstDecayModes self);

// +++ Print to standard output, as XML
extern_c int
DecayModesPrintXML(ConstHandle2ConstDecayModes self);

// +++ Print to standard output, as JSON
extern_c int
DecayModesPrintJSON(ConstHandle2ConstDecayModes self);


// -----------------------------------------------------------------------------
// Child: decayMode
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DecayModesDecayModeHas(ConstHandle2ConstDecayModes self);

// +++ Clear
extern_c void
DecayModesDecayModeClear(ConstHandle2DecayModes self);

// +++ Size
extern_c size_t
DecayModesDecayModeSize(ConstHandle2ConstDecayModes self);

// +++ Add
extern_c void
DecayModesDecayModeAdd(ConstHandle2DecayModes self, ConstHandle2ConstDecayMode decayMode);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstDecayMode
DecayModesDecayModeGetConst(ConstHandle2ConstDecayModes self, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2DecayMode
DecayModesDecayModeGet(ConstHandle2DecayModes self, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
DecayModesDecayModeSet(
   ConstHandle2DecayModes self,
   const size_t index_,
   ConstHandle2ConstDecayMode decayMode
);

// +++ Has, by label
extern_c int
DecayModesDecayModeHasByLabel(
   ConstHandle2ConstDecayModes self,
   const char *const label
);

// --- Get, by label, const
extern_c Handle2ConstDecayMode
DecayModesDecayModeGetByLabelConst(
   ConstHandle2ConstDecayModes self,
   const char *const label
);

// +++ Get, by label, non-const
extern_c Handle2DecayMode
DecayModesDecayModeGetByLabel(
   ConstHandle2DecayModes self,
   const char *const label
);

// +++ Set, by label
extern_c void
DecayModesDecayModeSetByLabel(
   ConstHandle2DecayModes self,
   const char *const label,
   ConstHandle2ConstDecayMode decayMode
);

// +++ Has, by mode
extern_c int
DecayModesDecayModeHasByMode(
   ConstHandle2ConstDecayModes self,
   const char *const mode
);

// --- Get, by mode, const
extern_c Handle2ConstDecayMode
DecayModesDecayModeGetByModeConst(
   ConstHandle2ConstDecayModes self,
   const char *const mode
);

// +++ Get, by mode, non-const
extern_c Handle2DecayMode
DecayModesDecayModeGetByMode(
   ConstHandle2DecayModes self,
   const char *const mode
);

// +++ Set, by mode
extern_c void
DecayModesDecayModeSetByMode(
   ConstHandle2DecayModes self,
   const char *const mode,
   ConstHandle2ConstDecayMode decayMode
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/DecayModes/src/custom.h"

#undef extern_c
#endif
