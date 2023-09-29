
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
// Reaction is the basic handle type in this file. Example:
//    // Create a default Reaction object:
//    Reaction handle = ReactionDefault();
// Functions involving Reaction are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_PROTO_V1_9_TRANSPORT_REACTION
#define C_INTERFACE_PROTO_V1_9_TRANSPORT_REACTION

#include "GNDStk.h"
#include "v1.9/transport/CrossSection.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ReactionClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Reaction
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ReactionClass *Reaction;

// --- Const-aware handles.
typedef const struct ReactionClass *const ConstHandle2ConstReaction;
typedef       struct ReactionClass *const ConstHandle2Reaction;
typedef const struct ReactionClass *      Handle2ConstReaction;
typedef       struct ReactionClass *      Handle2Reaction;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstReaction
ReactionDefaultConst();

// +++ Create, default
extern_c Handle2Reaction
ReactionDefault();

// --- Create, general, const
extern_c Handle2ConstReaction
ReactionCreateConst(
   const int ENDF_MT,
   const char *const fissionGenre,
   const char *const label,
   ConstHandle2ConstCrossSection crossSection
);

// +++ Create, general
extern_c Handle2Reaction
ReactionCreate(
   const int ENDF_MT,
   const char *const fissionGenre,
   const char *const label,
   ConstHandle2ConstCrossSection crossSection
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ReactionAssign(ConstHandle2Reaction self, ConstHandle2ConstReaction from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ReactionDelete(ConstHandle2ConstReaction self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ReactionRead(ConstHandle2Reaction self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ReactionWrite(ConstHandle2ConstReaction self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ReactionPrint(ConstHandle2ConstReaction self);

// +++ Print to standard output, as XML
extern_c int
ReactionPrintXML(ConstHandle2ConstReaction self);

// +++ Print to standard output, as JSON
extern_c int
ReactionPrintJSON(ConstHandle2ConstReaction self);


// -----------------------------------------------------------------------------
// Metadatum: ENDF_MT
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ReactionENDFMTHas(ConstHandle2ConstReaction self);

// +++ Get
// +++ Returns by value
extern_c int
ReactionENDFMTGet(ConstHandle2ConstReaction self);

// +++ Set
extern_c void
ReactionENDFMTSet(ConstHandle2Reaction self, const int ENDF_MT);


// -----------------------------------------------------------------------------
// Metadatum: fissionGenre
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ReactionFissionGenreHas(ConstHandle2ConstReaction self);

// +++ Get
// +++ Returns by value
extern_c const char *
ReactionFissionGenreGet(ConstHandle2ConstReaction self);

// +++ Set
extern_c void
ReactionFissionGenreSet(ConstHandle2Reaction self, const char *const fissionGenre);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ReactionLabelHas(ConstHandle2ConstReaction self);

// +++ Get
// +++ Returns by value
extern_c const char *
ReactionLabelGet(ConstHandle2ConstReaction self);

// +++ Set
extern_c void
ReactionLabelSet(ConstHandle2Reaction self, const char *const label);


// -----------------------------------------------------------------------------
// Child: crossSection
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ReactionCrossSectionHas(ConstHandle2ConstReaction self);

// --- Get, const
extern_c Handle2ConstCrossSection
ReactionCrossSectionGetConst(ConstHandle2ConstReaction self);

// +++ Get, non-const
extern_c Handle2CrossSection
ReactionCrossSectionGet(ConstHandle2Reaction self);

// +++ Set
extern_c void
ReactionCrossSectionSet(ConstHandle2Reaction self, ConstHandle2ConstCrossSection crossSection);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v1.9/transport/Reaction/src/custom.h"

#undef extern_c
#endif
