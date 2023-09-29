
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
// Channel is the basic handle type in this file. Example:
//    // Create a default Channel object:
//    Channel handle = ChannelDefault();
// Functions involving Channel are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_CHANNEL
#define C_INTERFACE_GNDS_V2_0_GENERAL_CHANNEL

#include "GNDStk.h"
#include "v2.0/general/ScatteringRadius.h"
#include "v2.0/general/HardSphereRadius.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ChannelClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Channel
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ChannelClass *Channel;

// --- Const-aware handles.
typedef const struct ChannelClass *const ConstHandle2ConstChannel;
typedef       struct ChannelClass *const ConstHandle2Channel;
typedef const struct ChannelClass *      Handle2ConstChannel;
typedef       struct ChannelClass *      Handle2Channel;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstChannel
ChannelDefaultConst();

// +++ Create, default, non-const
extern_c Handle2Channel
ChannelDefault();

// --- Create, general, const
extern_c Handle2ConstChannel
ChannelCreateConst(
   const char *const label,
   const char *const resonanceReaction,
   const int L,
   const int channelSpin,
   const int columnIndex,
   ConstHandle2ConstScatteringRadius scatteringRadius,
   ConstHandle2ConstHardSphereRadius hardSphereRadius
);

// +++ Create, general, non-const
extern_c Handle2Channel
ChannelCreate(
   const char *const label,
   const char *const resonanceReaction,
   const int L,
   const int channelSpin,
   const int columnIndex,
   ConstHandle2ConstScatteringRadius scatteringRadius,
   ConstHandle2ConstHardSphereRadius hardSphereRadius
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ChannelAssign(ConstHandle2Channel self, ConstHandle2ConstChannel from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ChannelDelete(ConstHandle2ConstChannel self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ChannelRead(ConstHandle2Channel self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ChannelWrite(ConstHandle2ConstChannel self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ChannelPrint(ConstHandle2ConstChannel self);

// +++ Print to standard output, as XML
extern_c int
ChannelPrintXML(ConstHandle2ConstChannel self);

// +++ Print to standard output, as JSON
extern_c int
ChannelPrintJSON(ConstHandle2ConstChannel self);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ChannelLabelHas(ConstHandle2ConstChannel self);

// +++ Get
// +++ Returns by value
extern_c const char *
ChannelLabelGet(ConstHandle2ConstChannel self);

// +++ Set
extern_c void
ChannelLabelSet(ConstHandle2Channel self, const char *const label);


// -----------------------------------------------------------------------------
// Metadatum: resonanceReaction
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ChannelResonanceReactionHas(ConstHandle2ConstChannel self);

// +++ Get
// +++ Returns by value
extern_c const char *
ChannelResonanceReactionGet(ConstHandle2ConstChannel self);

// +++ Set
extern_c void
ChannelResonanceReactionSet(ConstHandle2Channel self, const char *const resonanceReaction);


// -----------------------------------------------------------------------------
// Metadatum: L
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ChannelLHas(ConstHandle2ConstChannel self);

// +++ Get
// +++ Returns by value
extern_c int
ChannelLGet(ConstHandle2ConstChannel self);

// +++ Set
extern_c void
ChannelLSet(ConstHandle2Channel self, const int L);


// -----------------------------------------------------------------------------
// Metadatum: channelSpin
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ChannelChannelSpinHas(ConstHandle2ConstChannel self);

// +++ Get
// +++ Returns by value
extern_c int
ChannelChannelSpinGet(ConstHandle2ConstChannel self);

// +++ Set
extern_c void
ChannelChannelSpinSet(ConstHandle2Channel self, const int channelSpin);


// -----------------------------------------------------------------------------
// Metadatum: columnIndex
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ChannelColumnIndexHas(ConstHandle2ConstChannel self);

// +++ Get
// +++ Returns by value
extern_c int
ChannelColumnIndexGet(ConstHandle2ConstChannel self);

// +++ Set
extern_c void
ChannelColumnIndexSet(ConstHandle2Channel self, const int columnIndex);


// -----------------------------------------------------------------------------
// Child: scatteringRadius
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ChannelScatteringRadiusHas(ConstHandle2ConstChannel self);

// --- Get, const
extern_c Handle2ConstScatteringRadius
ChannelScatteringRadiusGetConst(ConstHandle2ConstChannel self);

// +++ Get, non-const
extern_c Handle2ScatteringRadius
ChannelScatteringRadiusGet(ConstHandle2Channel self);

// +++ Set
extern_c void
ChannelScatteringRadiusSet(ConstHandle2Channel self, ConstHandle2ConstScatteringRadius scatteringRadius);


// -----------------------------------------------------------------------------
// Child: hardSphereRadius
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ChannelHardSphereRadiusHas(ConstHandle2ConstChannel self);

// --- Get, const
extern_c Handle2ConstHardSphereRadius
ChannelHardSphereRadiusGetConst(ConstHandle2ConstChannel self);

// +++ Get, non-const
extern_c Handle2HardSphereRadius
ChannelHardSphereRadiusGet(ConstHandle2Channel self);

// +++ Set
extern_c void
ChannelHardSphereRadiusSet(ConstHandle2Channel self, ConstHandle2ConstHardSphereRadius hardSphereRadius);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Channel/src/custom.h"

#undef extern_c
#endif
