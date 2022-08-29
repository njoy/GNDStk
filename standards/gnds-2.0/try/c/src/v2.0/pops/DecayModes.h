
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
// DecayModes is the basic handle type in this file. Example:
//    // Create a default DecayModes object:
//    DecayModes handle = DecayModesDefault();
// Functions involving DecayModes are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_POPS_DECAYMODES
#define C_INTERFACE_TRY_V2_0_POPS_DECAYMODES

#include "GNDStk.h"
#include "v2.0/pops/DecayMode.h"

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
DecayModesAssign(ConstHandle2DecayModes This, ConstHandle2ConstDecayModes from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
DecayModesDelete(ConstHandle2ConstDecayModes This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
DecayModesRead(ConstHandle2DecayModes This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
DecayModesWrite(ConstHandle2ConstDecayModes This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
DecayModesPrint(ConstHandle2ConstDecayModes This);

// +++ Print to standard output, as XML
extern_c int
DecayModesPrintXML(ConstHandle2ConstDecayModes This);

// +++ Print to standard output, as JSON
extern_c int
DecayModesPrintJSON(ConstHandle2ConstDecayModes This);


// -----------------------------------------------------------------------------
// Child: decayMode
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DecayModesDecayModeHas(ConstHandle2ConstDecayModes This);

// +++ Clear
extern_c void
DecayModesDecayModeClear(ConstHandle2DecayModes This);

// +++ Size
extern_c size_t
DecayModesDecayModeSize(ConstHandle2ConstDecayModes This);

// +++ Add
extern_c void
DecayModesDecayModeAdd(ConstHandle2DecayModes This, ConstHandle2ConstDecayMode decayMode);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstDecayMode
DecayModesDecayModeGetConst(ConstHandle2ConstDecayModes This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2DecayMode
DecayModesDecayModeGet(ConstHandle2DecayModes This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
DecayModesDecayModeSet(
   ConstHandle2DecayModes This,
   const size_t index_,
   ConstHandle2ConstDecayMode decayMode
);

// +++ Has, by label
extern_c int
DecayModesDecayModeHasByLabel(
   ConstHandle2ConstDecayModes This,
   const XMLName label
);

// --- Get, by label, const
extern_c Handle2ConstDecayMode
DecayModesDecayModeGetByLabelConst(
   ConstHandle2ConstDecayModes This,
   const XMLName label
);

// +++ Get, by label, non-const
extern_c Handle2DecayMode
DecayModesDecayModeGetByLabel(
   ConstHandle2DecayModes This,
   const XMLName label
);

// +++ Set, by label
extern_c void
DecayModesDecayModeSetByLabel(
   ConstHandle2DecayModes This,
   const XMLName label,
   ConstHandle2ConstDecayMode decayMode
);

// +++ Has, by mode
extern_c int
DecayModesDecayModeHasByMode(
   ConstHandle2ConstDecayModes This,
   const enums::DecayType mode
);

// --- Get, by mode, const
extern_c Handle2ConstDecayMode
DecayModesDecayModeGetByModeConst(
   ConstHandle2ConstDecayModes This,
   const enums::DecayType mode
);

// +++ Get, by mode, non-const
extern_c Handle2DecayMode
DecayModesDecayModeGetByMode(
   ConstHandle2DecayModes This,
   const enums::DecayType mode
);

// +++ Set, by mode
extern_c void
DecayModesDecayModeSetByMode(
   ConstHandle2DecayModes This,
   const enums::DecayType mode,
   ConstHandle2ConstDecayMode decayMode
);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
