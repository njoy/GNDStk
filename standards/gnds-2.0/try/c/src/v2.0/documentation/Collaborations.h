
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
// Collaborations is the basic handle type in this file. Example:
//    // Create a default Collaborations object:
//    Collaborations handle = CollaborationsDefault();
// Functions involving Collaborations are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_DOCUMENTATION_COLLABORATIONS
#define C_INTERFACE_TRY_V2_0_DOCUMENTATION_COLLABORATIONS

#include "GNDStk.h"
#include "v2.0/documentation/Collaboration.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct CollaborationsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Collaborations
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct CollaborationsClass *Collaborations;

// --- Const-aware handles.
typedef const struct CollaborationsClass *const ConstHandle2ConstCollaborations;
typedef       struct CollaborationsClass *const ConstHandle2Collaborations;
typedef const struct CollaborationsClass *      Handle2ConstCollaborations;
typedef       struct CollaborationsClass *      Handle2Collaborations;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstCollaborations
CollaborationsDefaultConst();

// +++ Create, default
extern_c Handle2Collaborations
CollaborationsDefault();

// --- Create, general, const
extern_c Handle2ConstCollaborations
CollaborationsCreateConst(
   ConstHandle2Collaboration *const collaboration, const size_t collaborationSize
);

// +++ Create, general
extern_c Handle2Collaborations
CollaborationsCreate(
   ConstHandle2Collaboration *const collaboration, const size_t collaborationSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
CollaborationsAssign(ConstHandle2Collaborations This, ConstHandle2ConstCollaborations from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
CollaborationsDelete(ConstHandle2ConstCollaborations This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
CollaborationsRead(ConstHandle2Collaborations This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
CollaborationsWrite(ConstHandle2ConstCollaborations This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
CollaborationsPrint(ConstHandle2ConstCollaborations This);

// +++ Print to standard output, as XML
extern_c int
CollaborationsPrintXML(ConstHandle2ConstCollaborations This);

// +++ Print to standard output, as JSON
extern_c int
CollaborationsPrintJSON(ConstHandle2ConstCollaborations This);


// -----------------------------------------------------------------------------
// Child: collaboration
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
CollaborationsCollaborationHas(ConstHandle2ConstCollaborations This);

// +++ Clear
extern_c void
CollaborationsCollaborationClear(ConstHandle2Collaborations This);

// +++ Size
extern_c size_t
CollaborationsCollaborationSize(ConstHandle2ConstCollaborations This);

// +++ Add
extern_c void
CollaborationsCollaborationAdd(ConstHandle2Collaborations This, ConstHandle2ConstCollaboration collaboration);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstCollaboration
CollaborationsCollaborationGetConst(ConstHandle2ConstCollaborations This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Collaboration
CollaborationsCollaborationGet(ConstHandle2Collaborations This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
CollaborationsCollaborationSet(
   ConstHandle2Collaborations This,
   const size_t index_,
   ConstHandle2ConstCollaboration collaboration
);

// +++ Has, by name
extern_c int
CollaborationsCollaborationHasByName(
   ConstHandle2ConstCollaborations This,
   const UTF8Text name
);

// --- Get, by name, const
extern_c Handle2ConstCollaboration
CollaborationsCollaborationGetByNameConst(
   ConstHandle2ConstCollaborations This,
   const UTF8Text name
);

// +++ Get, by name, non-const
extern_c Handle2Collaboration
CollaborationsCollaborationGetByName(
   ConstHandle2Collaborations This,
   const UTF8Text name
);

// +++ Set, by name
extern_c void
CollaborationsCollaborationSetByName(
   ConstHandle2Collaborations This,
   const UTF8Text name,
   ConstHandle2ConstCollaboration collaboration
);

// +++ Has, by href
extern_c int
CollaborationsCollaborationHasByHref(
   ConstHandle2ConstCollaborations This,
   const UTF8Text href
);

// --- Get, by href, const
extern_c Handle2ConstCollaboration
CollaborationsCollaborationGetByHrefConst(
   ConstHandle2ConstCollaborations This,
   const UTF8Text href
);

// +++ Get, by href, non-const
extern_c Handle2Collaboration
CollaborationsCollaborationGetByHref(
   ConstHandle2Collaborations This,
   const UTF8Text href
);

// +++ Set, by href
extern_c void
CollaborationsCollaborationSetByHref(
   ConstHandle2Collaborations This,
   const UTF8Text href,
   ConstHandle2ConstCollaboration collaboration
);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif