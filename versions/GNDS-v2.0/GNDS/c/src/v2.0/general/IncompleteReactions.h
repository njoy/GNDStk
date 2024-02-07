
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
// IncompleteReactions is the basic handle type in this file. Example:
//    // Create a default IncompleteReactions object:
//    IncompleteReactions handle = IncompleteReactionsDefault();
// Functions involving IncompleteReactions are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_INCOMPLETEREACTIONS
#define C_INTERFACE_GNDS_V2_0_GENERAL_INCOMPLETEREACTIONS

#include "GNDStk.h"
#include "v2.0/general/Reaction.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct IncompleteReactionsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ IncompleteReactions
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct IncompleteReactionsClass *IncompleteReactions;

// --- Const-aware handles.
typedef const struct IncompleteReactionsClass *const ConstHandle2ConstIncompleteReactions;
typedef       struct IncompleteReactionsClass *const ConstHandle2IncompleteReactions;
typedef const struct IncompleteReactionsClass *      Handle2ConstIncompleteReactions;
typedef       struct IncompleteReactionsClass *      Handle2IncompleteReactions;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstIncompleteReactions
IncompleteReactionsDefaultConst();

// +++ Create, default, non-const
extern_c Handle2IncompleteReactions
IncompleteReactionsDefault();

// --- Create, general, const
extern_c Handle2ConstIncompleteReactions
IncompleteReactionsCreateConst(
   ConstHandle2Reaction *const reaction, const size_t reactionSize
);

// +++ Create, general, non-const
extern_c Handle2IncompleteReactions
IncompleteReactionsCreate(
   ConstHandle2Reaction *const reaction, const size_t reactionSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
IncompleteReactionsAssign(ConstHandle2IncompleteReactions self, ConstHandle2ConstIncompleteReactions from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
IncompleteReactionsDelete(ConstHandle2ConstIncompleteReactions self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
IncompleteReactionsRead(ConstHandle2IncompleteReactions self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
IncompleteReactionsWrite(ConstHandle2ConstIncompleteReactions self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
IncompleteReactionsPrint(ConstHandle2ConstIncompleteReactions self);

// +++ Print to standard output, as XML
extern_c int
IncompleteReactionsPrintXML(ConstHandle2ConstIncompleteReactions self);

// +++ Print to standard output, as JSON
extern_c int
IncompleteReactionsPrintJSON(ConstHandle2ConstIncompleteReactions self);


// -----------------------------------------------------------------------------
// Child: reaction
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
IncompleteReactionsReactionHas(ConstHandle2ConstIncompleteReactions self);

// +++ Clear
extern_c void
IncompleteReactionsReactionClear(ConstHandle2IncompleteReactions self);

// +++ Size
extern_c size_t
IncompleteReactionsReactionSize(ConstHandle2ConstIncompleteReactions self);

// +++ Add
extern_c void
IncompleteReactionsReactionAdd(ConstHandle2IncompleteReactions self, ConstHandle2ConstReaction reaction);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstReaction
IncompleteReactionsReactionGetConst(ConstHandle2ConstIncompleteReactions self, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Reaction
IncompleteReactionsReactionGet(ConstHandle2IncompleteReactions self, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
IncompleteReactionsReactionSet(
   ConstHandle2IncompleteReactions self,
   const size_t index_,
   ConstHandle2ConstReaction reaction
);

// ------------------------
// Re: metadatum label
// ------------------------

// +++ Has, by label
extern_c int
IncompleteReactionsReactionHasByLabel(
   ConstHandle2ConstIncompleteReactions self,
   const char *const label
);

// --- Get, by label, const
extern_c Handle2ConstReaction
IncompleteReactionsReactionGetByLabelConst(
   ConstHandle2ConstIncompleteReactions self,
   const char *const label
);

// +++ Get, by label, non-const
extern_c Handle2Reaction
IncompleteReactionsReactionGetByLabel(
   ConstHandle2IncompleteReactions self,
   const char *const label
);

// +++ Set, by label
extern_c void
IncompleteReactionsReactionSetByLabel(
   ConstHandle2IncompleteReactions self,
   const char *const label,
   ConstHandle2ConstReaction reaction
);

// ------------------------
// Re: metadatum ENDF_MT
// ------------------------

// +++ Has, by ENDF_MT
extern_c int
IncompleteReactionsReactionHasByENDFMT(
   ConstHandle2ConstIncompleteReactions self,
   const int ENDF_MT
);

// --- Get, by ENDF_MT, const
extern_c Handle2ConstReaction
IncompleteReactionsReactionGetByENDFMTConst(
   ConstHandle2ConstIncompleteReactions self,
   const int ENDF_MT
);

// +++ Get, by ENDF_MT, non-const
extern_c Handle2Reaction
IncompleteReactionsReactionGetByENDFMT(
   ConstHandle2IncompleteReactions self,
   const int ENDF_MT
);

// +++ Set, by ENDF_MT
extern_c void
IncompleteReactionsReactionSetByENDFMT(
   ConstHandle2IncompleteReactions self,
   const int ENDF_MT,
   ConstHandle2ConstReaction reaction
);

// ------------------------
// Re: metadatum fissionGenre
// ------------------------

// +++ Has, by fissionGenre
extern_c int
IncompleteReactionsReactionHasByFissionGenre(
   ConstHandle2ConstIncompleteReactions self,
   const char *const fissionGenre
);

// --- Get, by fissionGenre, const
extern_c Handle2ConstReaction
IncompleteReactionsReactionGetByFissionGenreConst(
   ConstHandle2ConstIncompleteReactions self,
   const char *const fissionGenre
);

// +++ Get, by fissionGenre, non-const
extern_c Handle2Reaction
IncompleteReactionsReactionGetByFissionGenre(
   ConstHandle2IncompleteReactions self,
   const char *const fissionGenre
);

// +++ Set, by fissionGenre
extern_c void
IncompleteReactionsReactionSetByFissionGenre(
   ConstHandle2IncompleteReactions self,
   const char *const fissionGenre,
   ConstHandle2ConstReaction reaction
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/IncompleteReactions/src/custom.h"

#undef extern_c
#endif