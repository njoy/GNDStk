
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

#ifndef C_INTERFACE_TEST_V2_0_TRANSPORT_INCOMPLETEREACTIONS
#define C_INTERFACE_TEST_V2_0_TRANSPORT_INCOMPLETEREACTIONS

#include "GNDStk.h"
#include "v2.0/transport/Reaction.h"

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

// +++ Create, default
extern_c Handle2IncompleteReactions
IncompleteReactionsDefault();

// --- Create, general, const
extern_c Handle2ConstIncompleteReactions
IncompleteReactionsCreateConst(
   ConstHandle2ConstReaction reaction
);

// +++ Create, general
extern_c Handle2IncompleteReactions
IncompleteReactionsCreate(
   ConstHandle2ConstReaction reaction
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
IncompleteReactionsAssign(ConstHandle2IncompleteReactions This, ConstHandle2ConstIncompleteReactions from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
IncompleteReactionsDelete(ConstHandle2ConstIncompleteReactions This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
IncompleteReactionsRead(ConstHandle2IncompleteReactions This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
IncompleteReactionsWrite(ConstHandle2ConstIncompleteReactions This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
IncompleteReactionsPrint(ConstHandle2ConstIncompleteReactions This);

// +++ Print to standard output, as XML
extern_c int
IncompleteReactionsPrintXML(ConstHandle2ConstIncompleteReactions This);

// +++ Print to standard output, as JSON
extern_c int
IncompleteReactionsPrintJSON(ConstHandle2ConstIncompleteReactions This);


// -----------------------------------------------------------------------------
// Child: reaction
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
IncompleteReactionsReactionHas(ConstHandle2ConstIncompleteReactions This);

// --- Get, const
extern_c Handle2ConstReaction
IncompleteReactionsReactionGetConst(ConstHandle2ConstIncompleteReactions This);

// +++ Get, non-const
extern_c Handle2Reaction
IncompleteReactionsReactionGet(ConstHandle2IncompleteReactions This);

// +++ Set
extern_c void
IncompleteReactionsReactionSet(ConstHandle2IncompleteReactions This, ConstHandle2ConstReaction reaction);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
