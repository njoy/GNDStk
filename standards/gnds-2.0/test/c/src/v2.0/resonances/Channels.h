
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
// Channels is the basic handle type in this file. Example:
//    // Create a default Channels object:
//    Channels handle = ChannelsDefault();
// Functions involving Channels are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_RESONANCES_CHANNELS
#define C_INTERFACE_TEST_V2_0_RESONANCES_CHANNELS

#include "GNDStk.h"
#include "v2.0/resonances/Channel.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ChannelsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Channels
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ChannelsClass *Channels;

// --- Const-aware handles.
typedef const struct ChannelsClass *const ConstHandle2ConstChannels;
typedef       struct ChannelsClass *const ConstHandle2Channels;
typedef const struct ChannelsClass *      Handle2ConstChannels;
typedef       struct ChannelsClass *      Handle2Channels;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstChannels
ChannelsDefaultConst();

// +++ Create, default
extern_c Handle2Channels
ChannelsDefault();

// --- Create, general, const
extern_c Handle2ConstChannels
ChannelsCreateConst(
   ConstHandle2Channel *const channel, const size_t channelSize
);

// +++ Create, general
extern_c Handle2Channels
ChannelsCreate(
   ConstHandle2Channel *const channel, const size_t channelSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ChannelsAssign(ConstHandle2Channels This, ConstHandle2ConstChannels from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ChannelsDelete(ConstHandle2ConstChannels This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ChannelsRead(ConstHandle2Channels This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ChannelsWrite(ConstHandle2ConstChannels This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ChannelsPrint(ConstHandle2ConstChannels This);

// +++ Print to standard output, as XML
extern_c int
ChannelsPrintXML(ConstHandle2ConstChannels This);

// +++ Print to standard output, as JSON
extern_c int
ChannelsPrintJSON(ConstHandle2ConstChannels This);


// -----------------------------------------------------------------------------
// Child: channel
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ChannelsChannelHas(ConstHandle2ConstChannels This);

// +++ Clear
extern_c void
ChannelsChannelClear(ConstHandle2Channels This);

// +++ Size
extern_c size_t
ChannelsChannelSize(ConstHandle2ConstChannels This);

// +++ Add
extern_c void
ChannelsChannelAdd(ConstHandle2Channels This, ConstHandle2ConstChannel channel);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstChannel
ChannelsChannelGetConst(ConstHandle2ConstChannels This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Channel
ChannelsChannelGet(ConstHandle2Channels This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
ChannelsChannelSet(
   ConstHandle2Channels This,
   const size_t index_,
   ConstHandle2ConstChannel channel
);

// +++ Has, by label
extern_c int
ChannelsChannelHasByLabel(
   ConstHandle2ConstChannels This,
   const XMLName label
);

// --- Get, by label, const
extern_c Handle2ConstChannel
ChannelsChannelGetByLabelConst(
   ConstHandle2ConstChannels This,
   const XMLName label
);

// +++ Get, by label, non-const
extern_c Handle2Channel
ChannelsChannelGetByLabel(
   ConstHandle2Channels This,
   const XMLName label
);

// +++ Set, by label
extern_c void
ChannelsChannelSetByLabel(
   ConstHandle2Channels This,
   const XMLName label,
   ConstHandle2ConstChannel channel
);

// +++ Has, by resonanceReaction
extern_c int
ChannelsChannelHasByResonanceReaction(
   ConstHandle2ConstChannels This,
   const char *const resonanceReaction
);

// --- Get, by resonanceReaction, const
extern_c Handle2ConstChannel
ChannelsChannelGetByResonanceReactionConst(
   ConstHandle2ConstChannels This,
   const char *const resonanceReaction
);

// +++ Get, by resonanceReaction, non-const
extern_c Handle2Channel
ChannelsChannelGetByResonanceReaction(
   ConstHandle2Channels This,
   const char *const resonanceReaction
);

// +++ Set, by resonanceReaction
extern_c void
ChannelsChannelSetByResonanceReaction(
   ConstHandle2Channels This,
   const char *const resonanceReaction,
   ConstHandle2ConstChannel channel
);

// +++ Has, by L
extern_c int
ChannelsChannelHasByL(
   ConstHandle2ConstChannels This,
   const Integer32 L
);

// --- Get, by L, const
extern_c Handle2ConstChannel
ChannelsChannelGetByLConst(
   ConstHandle2ConstChannels This,
   const Integer32 L
);

// +++ Get, by L, non-const
extern_c Handle2Channel
ChannelsChannelGetByL(
   ConstHandle2Channels This,
   const Integer32 L
);

// +++ Set, by L
extern_c void
ChannelsChannelSetByL(
   ConstHandle2Channels This,
   const Integer32 L,
   ConstHandle2ConstChannel channel
);

// +++ Has, by channelSpin
extern_c int
ChannelsChannelHasByChannelSpin(
   ConstHandle2ConstChannels This,
   const Fraction32 channelSpin
);

// --- Get, by channelSpin, const
extern_c Handle2ConstChannel
ChannelsChannelGetByChannelSpinConst(
   ConstHandle2ConstChannels This,
   const Fraction32 channelSpin
);

// +++ Get, by channelSpin, non-const
extern_c Handle2Channel
ChannelsChannelGetByChannelSpin(
   ConstHandle2Channels This,
   const Fraction32 channelSpin
);

// +++ Set, by channelSpin
extern_c void
ChannelsChannelSetByChannelSpin(
   ConstHandle2Channels This,
   const Fraction32 channelSpin,
   ConstHandle2ConstChannel channel
);

// +++ Has, by boundaryConditionValue
extern_c int
ChannelsChannelHasByBoundaryConditionValue(
   ConstHandle2ConstChannels This,
   const Float64 boundaryConditionValue
);

// --- Get, by boundaryConditionValue, const
extern_c Handle2ConstChannel
ChannelsChannelGetByBoundaryConditionValueConst(
   ConstHandle2ConstChannels This,
   const Float64 boundaryConditionValue
);

// +++ Get, by boundaryConditionValue, non-const
extern_c Handle2Channel
ChannelsChannelGetByBoundaryConditionValue(
   ConstHandle2Channels This,
   const Float64 boundaryConditionValue
);

// +++ Set, by boundaryConditionValue
extern_c void
ChannelsChannelSetByBoundaryConditionValue(
   ConstHandle2Channels This,
   const Float64 boundaryConditionValue,
   ConstHandle2ConstChannel channel
);

// +++ Has, by columnIndex
extern_c int
ChannelsChannelHasByColumnIndex(
   ConstHandle2ConstChannels This,
   const Integer32 columnIndex
);

// --- Get, by columnIndex, const
extern_c Handle2ConstChannel
ChannelsChannelGetByColumnIndexConst(
   ConstHandle2ConstChannels This,
   const Integer32 columnIndex
);

// +++ Get, by columnIndex, non-const
extern_c Handle2Channel
ChannelsChannelGetByColumnIndex(
   ConstHandle2Channels This,
   const Integer32 columnIndex
);

// +++ Set, by columnIndex
extern_c void
ChannelsChannelSetByColumnIndex(
   ConstHandle2Channels This,
   const Integer32 columnIndex,
   ConstHandle2ConstChannel channel
);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
