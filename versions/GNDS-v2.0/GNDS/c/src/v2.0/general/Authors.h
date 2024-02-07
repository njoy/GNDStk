
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
// Authors is the basic handle type in this file. Example:
//    // Create a default Authors object:
//    Authors handle = AuthorsDefault();
// Functions involving Authors are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_AUTHORS
#define C_INTERFACE_GNDS_V2_0_GENERAL_AUTHORS

#include "GNDStk.h"
#include "v2.0/general/Author.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct AuthorsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Authors
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct AuthorsClass *Authors;

// --- Const-aware handles.
typedef const struct AuthorsClass *const ConstHandle2ConstAuthors;
typedef       struct AuthorsClass *const ConstHandle2Authors;
typedef const struct AuthorsClass *      Handle2ConstAuthors;
typedef       struct AuthorsClass *      Handle2Authors;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstAuthors
AuthorsDefaultConst();

// +++ Create, default, non-const
extern_c Handle2Authors
AuthorsDefault();

// --- Create, general, const
extern_c Handle2ConstAuthors
AuthorsCreateConst(
   ConstHandle2Author *const author, const size_t authorSize
);

// +++ Create, general, non-const
extern_c Handle2Authors
AuthorsCreate(
   ConstHandle2Author *const author, const size_t authorSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
AuthorsAssign(ConstHandle2Authors self, ConstHandle2ConstAuthors from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
AuthorsDelete(ConstHandle2ConstAuthors self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
AuthorsRead(ConstHandle2Authors self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
AuthorsWrite(ConstHandle2ConstAuthors self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
AuthorsPrint(ConstHandle2ConstAuthors self);

// +++ Print to standard output, as XML
extern_c int
AuthorsPrintXML(ConstHandle2ConstAuthors self);

// +++ Print to standard output, as JSON
extern_c int
AuthorsPrintJSON(ConstHandle2ConstAuthors self);


// -----------------------------------------------------------------------------
// Child: author
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AuthorsAuthorHas(ConstHandle2ConstAuthors self);

// +++ Clear
extern_c void
AuthorsAuthorClear(ConstHandle2Authors self);

// +++ Size
extern_c size_t
AuthorsAuthorSize(ConstHandle2ConstAuthors self);

// +++ Add
extern_c void
AuthorsAuthorAdd(ConstHandle2Authors self, ConstHandle2ConstAuthor author);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstAuthor
AuthorsAuthorGetConst(ConstHandle2ConstAuthors self, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Author
AuthorsAuthorGet(ConstHandle2Authors self, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
AuthorsAuthorSet(
   ConstHandle2Authors self,
   const size_t index_,
   ConstHandle2ConstAuthor author
);

// ------------------------
// Re: metadatum name
// ------------------------

// +++ Has, by name
extern_c int
AuthorsAuthorHasByName(
   ConstHandle2ConstAuthors self,
   const char *const name
);

// --- Get, by name, const
extern_c Handle2ConstAuthor
AuthorsAuthorGetByNameConst(
   ConstHandle2ConstAuthors self,
   const char *const name
);

// +++ Get, by name, non-const
extern_c Handle2Author
AuthorsAuthorGetByName(
   ConstHandle2Authors self,
   const char *const name
);

// +++ Set, by name
extern_c void
AuthorsAuthorSetByName(
   ConstHandle2Authors self,
   const char *const name,
   ConstHandle2ConstAuthor author
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Authors/src/custom.h"

#undef extern_c
#endif