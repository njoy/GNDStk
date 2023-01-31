
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
// Reactions is the basic handle type in this file. Example:
//    // Create a default Reactions object:
//    Reactions handle = ReactionsDefault();
// Functions involving Reactions are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_COMMON_REACTIONS
#define C_INTERFACE_ALPHA_V2_0_COMMON_REACTIONS

#include "GNDStk.h"
#include "v2.0/common/Reaction.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ReactionsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Reactions
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ReactionsClass *Reactions;

// --- Const-aware handles.
typedef const struct ReactionsClass *const ConstHandle2ConstReactions;
typedef       struct ReactionsClass *const ConstHandle2Reactions;
typedef const struct ReactionsClass *      Handle2ConstReactions;
typedef       struct ReactionsClass *      Handle2Reactions;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstReactions
ReactionsDefaultConst();

// +++ Create, default
extern_c Handle2Reactions
ReactionsDefault();

// --- Create, general, const
extern_c Handle2ConstReactions
ReactionsCreateConst(
   ConstHandle2Reaction *const reaction, const size_t reactionSize
);

// +++ Create, general
extern_c Handle2Reactions
ReactionsCreate(
   ConstHandle2Reaction *const reaction, const size_t reactionSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ReactionsAssign(ConstHandle2Reactions This, ConstHandle2ConstReactions from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ReactionsDelete(ConstHandle2ConstReactions This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ReactionsRead(ConstHandle2Reactions This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ReactionsWrite(ConstHandle2ConstReactions This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ReactionsPrint(ConstHandle2ConstReactions This);

// +++ Print to standard output, as XML
extern_c int
ReactionsPrintXML(ConstHandle2ConstReactions This);

// +++ Print to standard output, as JSON
extern_c int
ReactionsPrintJSON(ConstHandle2ConstReactions This);


// -----------------------------------------------------------------------------
// Child: reaction
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ReactionsReactionHas(ConstHandle2ConstReactions This);

// +++ Clear
extern_c void
ReactionsReactionClear(ConstHandle2Reactions This);

// +++ Size
extern_c size_t
ReactionsReactionSize(ConstHandle2ConstReactions This);

// +++ Add
extern_c void
ReactionsReactionAdd(ConstHandle2Reactions This, ConstHandle2ConstReaction reaction);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstReaction
ReactionsReactionGetConst(ConstHandle2ConstReactions This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Reaction
ReactionsReactionGet(ConstHandle2Reactions This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
ReactionsReactionSet(
   ConstHandle2Reactions This,
   const size_t index_,
   ConstHandle2ConstReaction reaction
);

// +++ Has, by label
extern_c int
ReactionsReactionHasByLabel(
   ConstHandle2ConstReactions This,
   const char *const label
);

// --- Get, by label, const
extern_c Handle2ConstReaction
ReactionsReactionGetByLabelConst(
   ConstHandle2ConstReactions This,
   const char *const label
);

// +++ Get, by label, non-const
extern_c Handle2Reaction
ReactionsReactionGetByLabel(
   ConstHandle2Reactions This,
   const char *const label
);

// +++ Set, by label
extern_c void
ReactionsReactionSetByLabel(
   ConstHandle2Reactions This,
   const char *const label,
   ConstHandle2ConstReaction reaction
);

// +++ Has, by ENDF_MT
extern_c int
ReactionsReactionHasByENDFMT(
   ConstHandle2ConstReactions This,
   const int ENDF_MT
);

// --- Get, by ENDF_MT, const
extern_c Handle2ConstReaction
ReactionsReactionGetByENDFMTConst(
   ConstHandle2ConstReactions This,
   const int ENDF_MT
);

// +++ Get, by ENDF_MT, non-const
extern_c Handle2Reaction
ReactionsReactionGetByENDFMT(
   ConstHandle2Reactions This,
   const int ENDF_MT
);

// +++ Set, by ENDF_MT
extern_c void
ReactionsReactionSetByENDFMT(
   ConstHandle2Reactions This,
   const int ENDF_MT,
   ConstHandle2ConstReaction reaction
);

// +++ Has, by fissionGenre
extern_c int
ReactionsReactionHasByFissionGenre(
   ConstHandle2ConstReactions This,
   const char *const fissionGenre
);

// --- Get, by fissionGenre, const
extern_c Handle2ConstReaction
ReactionsReactionGetByFissionGenreConst(
   ConstHandle2ConstReactions This,
   const char *const fissionGenre
);

// +++ Get, by fissionGenre, non-const
extern_c Handle2Reaction
ReactionsReactionGetByFissionGenre(
   ConstHandle2Reactions This,
   const char *const fissionGenre
);

// +++ Set, by fissionGenre
extern_c void
ReactionsReactionSetByFissionGenre(
   ConstHandle2Reactions This,
   const char *const fissionGenre,
   ConstHandle2ConstReaction reaction
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/common/Reactions/src/custom.h"

#undef extern_c
#endif
