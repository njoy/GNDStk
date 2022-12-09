
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
// OutputDecks is the basic handle type in this file. Example:
//    // Create a default OutputDecks object:
//    OutputDecks handle = OutputDecksDefault();
// Functions involving OutputDecks are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_DOCUMENTATION_OUTPUTDECKS
#define C_INTERFACE_TEST_V2_0_DOCUMENTATION_OUTPUTDECKS

#include "GNDStk.h"
#include "v2.0/documentation/OutputDeck.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct OutputDecksClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ OutputDecks
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct OutputDecksClass *OutputDecks;

// --- Const-aware handles.
typedef const struct OutputDecksClass *const ConstHandle2ConstOutputDecks;
typedef       struct OutputDecksClass *const ConstHandle2OutputDecks;
typedef const struct OutputDecksClass *      Handle2ConstOutputDecks;
typedef       struct OutputDecksClass *      Handle2OutputDecks;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstOutputDecks
OutputDecksDefaultConst();

// +++ Create, default
extern_c Handle2OutputDecks
OutputDecksDefault();

// --- Create, general, const
extern_c Handle2ConstOutputDecks
OutputDecksCreateConst(
   ConstHandle2OutputDeck *const outputDeck, const size_t outputDeckSize
);

// +++ Create, general
extern_c Handle2OutputDecks
OutputDecksCreate(
   ConstHandle2OutputDeck *const outputDeck, const size_t outputDeckSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
OutputDecksAssign(ConstHandle2OutputDecks This, ConstHandle2ConstOutputDecks from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
OutputDecksDelete(ConstHandle2ConstOutputDecks This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
OutputDecksRead(ConstHandle2OutputDecks This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
OutputDecksWrite(ConstHandle2ConstOutputDecks This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
OutputDecksPrint(ConstHandle2ConstOutputDecks This);

// +++ Print to standard output, as XML
extern_c int
OutputDecksPrintXML(ConstHandle2ConstOutputDecks This);

// +++ Print to standard output, as JSON
extern_c int
OutputDecksPrintJSON(ConstHandle2ConstOutputDecks This);


// -----------------------------------------------------------------------------
// Child: outputDeck
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
OutputDecksOutputDeckHas(ConstHandle2ConstOutputDecks This);

// +++ Clear
extern_c void
OutputDecksOutputDeckClear(ConstHandle2OutputDecks This);

// +++ Size
extern_c size_t
OutputDecksOutputDeckSize(ConstHandle2ConstOutputDecks This);

// +++ Add
extern_c void
OutputDecksOutputDeckAdd(ConstHandle2OutputDecks This, ConstHandle2ConstOutputDeck outputDeck);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstOutputDeck
OutputDecksOutputDeckGetConst(ConstHandle2ConstOutputDecks This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2OutputDeck
OutputDecksOutputDeckGet(ConstHandle2OutputDecks This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
OutputDecksOutputDeckSet(
   ConstHandle2OutputDecks This,
   const size_t index_,
   ConstHandle2ConstOutputDeck outputDeck
);

// +++ Has, by encoding
extern_c int
OutputDecksOutputDeckHasByEncoding(
   ConstHandle2ConstOutputDecks This,
   const XMLName encoding
);

// --- Get, by encoding, const
extern_c Handle2ConstOutputDeck
OutputDecksOutputDeckGetByEncodingConst(
   ConstHandle2ConstOutputDecks This,
   const XMLName encoding
);

// +++ Get, by encoding, non-const
extern_c Handle2OutputDeck
OutputDecksOutputDeckGetByEncoding(
   ConstHandle2OutputDecks This,
   const XMLName encoding
);

// +++ Set, by encoding
extern_c void
OutputDecksOutputDeckSetByEncoding(
   ConstHandle2OutputDecks This,
   const XMLName encoding,
   ConstHandle2ConstOutputDeck outputDeck
);

// +++ Has, by markup
extern_c int
OutputDecksOutputDeckHasByMarkup(
   ConstHandle2ConstOutputDecks This,
   const char *const markup
);

// --- Get, by markup, const
extern_c Handle2ConstOutputDeck
OutputDecksOutputDeckGetByMarkupConst(
   ConstHandle2ConstOutputDecks This,
   const char *const markup
);

// +++ Get, by markup, non-const
extern_c Handle2OutputDeck
OutputDecksOutputDeckGetByMarkup(
   ConstHandle2OutputDecks This,
   const char *const markup
);

// +++ Set, by markup
extern_c void
OutputDecksOutputDeckSetByMarkup(
   ConstHandle2OutputDecks This,
   const char *const markup,
   ConstHandle2ConstOutputDeck outputDeck
);

// +++ Has, by label
extern_c int
OutputDecksOutputDeckHasByLabel(
   ConstHandle2ConstOutputDecks This,
   const XMLName label
);

// --- Get, by label, const
extern_c Handle2ConstOutputDeck
OutputDecksOutputDeckGetByLabelConst(
   ConstHandle2ConstOutputDecks This,
   const XMLName label
);

// +++ Get, by label, non-const
extern_c Handle2OutputDeck
OutputDecksOutputDeckGetByLabel(
   ConstHandle2OutputDecks This,
   const XMLName label
);

// +++ Set, by label
extern_c void
OutputDecksOutputDeckSetByLabel(
   ConstHandle2OutputDecks This,
   const XMLName label,
   ConstHandle2ConstOutputDeck outputDeck
);

// +++ Has, by filename
extern_c int
OutputDecksOutputDeckHasByFilename(
   ConstHandle2ConstOutputDecks This,
   const XMLName filename
);

// --- Get, by filename, const
extern_c Handle2ConstOutputDeck
OutputDecksOutputDeckGetByFilenameConst(
   ConstHandle2ConstOutputDecks This,
   const XMLName filename
);

// +++ Get, by filename, non-const
extern_c Handle2OutputDeck
OutputDecksOutputDeckGetByFilename(
   ConstHandle2OutputDecks This,
   const XMLName filename
);

// +++ Set, by filename
extern_c void
OutputDecksOutputDeckSetByFilename(
   ConstHandle2OutputDecks This,
   const XMLName filename,
   ConstHandle2ConstOutputDeck outputDeck
);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
