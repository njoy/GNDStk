
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
// SpinGroup is the basic handle type in this file. Example:
//    // Create a default SpinGroup object:
//    SpinGroup handle = SpinGroupDefault();
// Functions involving SpinGroup are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_RESONANCES_SPINGROUP
#define C_INTERFACE_TEST_V2_0_RESONANCES_SPINGROUP

#include "GNDStk.h"
#include "v2.0/resonances/Channels.h"
#include "v2.0/resonances/ResonanceParameters.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct SpinGroupClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ SpinGroup
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct SpinGroupClass *SpinGroup;

// --- Const-aware handles.
typedef const struct SpinGroupClass *const ConstHandle2ConstSpinGroup;
typedef       struct SpinGroupClass *const ConstHandle2SpinGroup;
typedef const struct SpinGroupClass *      Handle2ConstSpinGroup;
typedef       struct SpinGroupClass *      Handle2SpinGroup;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstSpinGroup
SpinGroupDefaultConst();

// +++ Create, default
extern_c Handle2SpinGroup
SpinGroupDefault();

// --- Create, general, const
extern_c Handle2ConstSpinGroup
SpinGroupCreateConst(
   const XMLName label,
   const Fraction32 spin,
   const Integer32 parity,
   ConstHandle2ConstChannels channels,
   ConstHandle2ConstResonanceParameters resonanceParameters
);

// +++ Create, general
extern_c Handle2SpinGroup
SpinGroupCreate(
   const XMLName label,
   const Fraction32 spin,
   const Integer32 parity,
   ConstHandle2ConstChannels channels,
   ConstHandle2ConstResonanceParameters resonanceParameters
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
SpinGroupAssign(ConstHandle2SpinGroup self, ConstHandle2ConstSpinGroup from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
SpinGroupDelete(ConstHandle2ConstSpinGroup self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
SpinGroupRead(ConstHandle2SpinGroup self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
SpinGroupWrite(ConstHandle2ConstSpinGroup self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
SpinGroupPrint(ConstHandle2ConstSpinGroup self);

// +++ Print to standard output, as XML
extern_c int
SpinGroupPrintXML(ConstHandle2ConstSpinGroup self);

// +++ Print to standard output, as JSON
extern_c int
SpinGroupPrintJSON(ConstHandle2ConstSpinGroup self);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
SpinGroupLabelHas(ConstHandle2ConstSpinGroup self);

// +++ Get
// +++ Returns by value
extern_c XMLName
SpinGroupLabelGet(ConstHandle2ConstSpinGroup self);

// +++ Set
extern_c void
SpinGroupLabelSet(ConstHandle2SpinGroup self, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: spin
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
SpinGroupSpinHas(ConstHandle2ConstSpinGroup self);

// +++ Get
// +++ Returns by value
extern_c Fraction32
SpinGroupSpinGet(ConstHandle2ConstSpinGroup self);

// +++ Set
extern_c void
SpinGroupSpinSet(ConstHandle2SpinGroup self, const Fraction32 spin);


// -----------------------------------------------------------------------------
// Metadatum: parity
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
SpinGroupParityHas(ConstHandle2ConstSpinGroup self);

// +++ Get
// +++ Returns by value
extern_c Integer32
SpinGroupParityGet(ConstHandle2ConstSpinGroup self);

// +++ Set
extern_c void
SpinGroupParitySet(ConstHandle2SpinGroup self, const Integer32 parity);


// -----------------------------------------------------------------------------
// Child: channels
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
SpinGroupChannelsHas(ConstHandle2ConstSpinGroup self);

// --- Get, const
extern_c Handle2ConstChannels
SpinGroupChannelsGetConst(ConstHandle2ConstSpinGroup self);

// +++ Get, non-const
extern_c Handle2Channels
SpinGroupChannelsGet(ConstHandle2SpinGroup self);

// +++ Set
extern_c void
SpinGroupChannelsSet(ConstHandle2SpinGroup self, ConstHandle2ConstChannels channels);


// -----------------------------------------------------------------------------
// Child: resonanceParameters
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
SpinGroupResonanceParametersHas(ConstHandle2ConstSpinGroup self);

// --- Get, const
extern_c Handle2ConstResonanceParameters
SpinGroupResonanceParametersGetConst(ConstHandle2ConstSpinGroup self);

// +++ Get, non-const
extern_c Handle2ResonanceParameters
SpinGroupResonanceParametersGet(ConstHandle2SpinGroup self);

// +++ Set
extern_c void
SpinGroupResonanceParametersSet(ConstHandle2SpinGroup self, ConstHandle2ConstResonanceParameters resonanceParameters);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/resonances/SpinGroup/src/custom.h"

#undef extern_c
#endif
