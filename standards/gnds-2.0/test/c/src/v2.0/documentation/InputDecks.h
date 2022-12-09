
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
// InputDecks is the basic handle type in this file. Example:
//    // Create a default InputDecks object:
//    InputDecks handle = InputDecksDefault();
// Functions involving InputDecks are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_DOCUMENTATION_INPUTDECKS
#define C_INTERFACE_TEST_V2_0_DOCUMENTATION_INPUTDECKS

#include "GNDStk.h"
#include "v2.0/documentation/InputDeck.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct InputDecksClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ InputDecks
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct InputDecksClass *InputDecks;

// --- Const-aware handles.
typedef const struct InputDecksClass *const ConstHandle2ConstInputDecks;
typedef       struct InputDecksClass *const ConstHandle2InputDecks;
typedef const struct InputDecksClass *      Handle2ConstInputDecks;
typedef       struct InputDecksClass *      Handle2InputDecks;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstInputDecks
InputDecksDefaultConst();

// +++ Create, default
extern_c Handle2InputDecks
InputDecksDefault();

// --- Create, general, const
extern_c Handle2ConstInputDecks
InputDecksCreateConst(
   ConstHandle2InputDeck *const inputDeck, const size_t inputDeckSize
);

// +++ Create, general
extern_c Handle2InputDecks
InputDecksCreate(
   ConstHandle2InputDeck *const inputDeck, const size_t inputDeckSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
InputDecksAssign(ConstHandle2InputDecks This, ConstHandle2ConstInputDecks from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
InputDecksDelete(ConstHandle2ConstInputDecks This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
InputDecksRead(ConstHandle2InputDecks This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
InputDecksWrite(ConstHandle2ConstInputDecks This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
InputDecksPrint(ConstHandle2ConstInputDecks This);

// +++ Print to standard output, as XML
extern_c int
InputDecksPrintXML(ConstHandle2ConstInputDecks This);

// +++ Print to standard output, as JSON
extern_c int
InputDecksPrintJSON(ConstHandle2ConstInputDecks This);


// -----------------------------------------------------------------------------
// Child: inputDeck
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
InputDecksInputDeckHas(ConstHandle2ConstInputDecks This);

// +++ Clear
extern_c void
InputDecksInputDeckClear(ConstHandle2InputDecks This);

// +++ Size
extern_c size_t
InputDecksInputDeckSize(ConstHandle2ConstInputDecks This);

// +++ Add
extern_c void
InputDecksInputDeckAdd(ConstHandle2InputDecks This, ConstHandle2ConstInputDeck inputDeck);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstInputDeck
InputDecksInputDeckGetConst(ConstHandle2ConstInputDecks This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2InputDeck
InputDecksInputDeckGet(ConstHandle2InputDecks This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
InputDecksInputDeckSet(
   ConstHandle2InputDecks This,
   const size_t index_,
   ConstHandle2ConstInputDeck inputDeck
);

// +++ Has, by encoding
extern_c int
InputDecksInputDeckHasByEncoding(
   ConstHandle2ConstInputDecks This,
   const XMLName encoding
);

// --- Get, by encoding, const
extern_c Handle2ConstInputDeck
InputDecksInputDeckGetByEncodingConst(
   ConstHandle2ConstInputDecks This,
   const XMLName encoding
);

// +++ Get, by encoding, non-const
extern_c Handle2InputDeck
InputDecksInputDeckGetByEncoding(
   ConstHandle2InputDecks This,
   const XMLName encoding
);

// +++ Set, by encoding
extern_c void
InputDecksInputDeckSetByEncoding(
   ConstHandle2InputDecks This,
   const XMLName encoding,
   ConstHandle2ConstInputDeck inputDeck
);

// +++ Has, by markup
extern_c int
InputDecksInputDeckHasByMarkup(
   ConstHandle2ConstInputDecks This,
   const char *const markup
);

// --- Get, by markup, const
extern_c Handle2ConstInputDeck
InputDecksInputDeckGetByMarkupConst(
   ConstHandle2ConstInputDecks This,
   const char *const markup
);

// +++ Get, by markup, non-const
extern_c Handle2InputDeck
InputDecksInputDeckGetByMarkup(
   ConstHandle2InputDecks This,
   const char *const markup
);

// +++ Set, by markup
extern_c void
InputDecksInputDeckSetByMarkup(
   ConstHandle2InputDecks This,
   const char *const markup,
   ConstHandle2ConstInputDeck inputDeck
);

// +++ Has, by label
extern_c int
InputDecksInputDeckHasByLabel(
   ConstHandle2ConstInputDecks This,
   const XMLName label
);

// --- Get, by label, const
extern_c Handle2ConstInputDeck
InputDecksInputDeckGetByLabelConst(
   ConstHandle2ConstInputDecks This,
   const XMLName label
);

// +++ Get, by label, non-const
extern_c Handle2InputDeck
InputDecksInputDeckGetByLabel(
   ConstHandle2InputDecks This,
   const XMLName label
);

// +++ Set, by label
extern_c void
InputDecksInputDeckSetByLabel(
   ConstHandle2InputDecks This,
   const XMLName label,
   ConstHandle2ConstInputDeck inputDeck
);

// +++ Has, by filename
extern_c int
InputDecksInputDeckHasByFilename(
   ConstHandle2ConstInputDecks This,
   const XMLName filename
);

// --- Get, by filename, const
extern_c Handle2ConstInputDeck
InputDecksInputDeckGetByFilenameConst(
   ConstHandle2ConstInputDecks This,
   const XMLName filename
);

// +++ Get, by filename, non-const
extern_c Handle2InputDeck
InputDecksInputDeckGetByFilename(
   ConstHandle2InputDecks This,
   const XMLName filename
);

// +++ Set, by filename
extern_c void
InputDecksInputDeckSetByFilename(
   ConstHandle2InputDecks This,
   const XMLName filename,
   ConstHandle2ConstInputDeck inputDeck
);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
