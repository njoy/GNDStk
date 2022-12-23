
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
// ComputerCode is the basic handle type in this file. Example:
//    // Create a default ComputerCode object:
//    ComputerCode handle = ComputerCodeDefault();
// Functions involving ComputerCode are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_DOCUMENTATION_COMPUTERCODE
#define C_INTERFACE_TEST_V2_0_DOCUMENTATION_COMPUTERCODE

#include "GNDStk.h"
#include "v2.0/documentation/ExecutionArguments.h"
#include "v2.0/documentation/CodeRepo.h"
#include "v2.0/documentation/Note.h"
#include "v2.0/documentation/InputDecks.h"
#include "v2.0/documentation/OutputDecks.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ComputerCodeClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ComputerCode
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ComputerCodeClass *ComputerCode;

// --- Const-aware handles.
typedef const struct ComputerCodeClass *const ConstHandle2ConstComputerCode;
typedef       struct ComputerCodeClass *const ConstHandle2ComputerCode;
typedef const struct ComputerCodeClass *      Handle2ConstComputerCode;
typedef       struct ComputerCodeClass *      Handle2ComputerCode;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstComputerCode
ComputerCodeDefaultConst();

// +++ Create, default
extern_c Handle2ComputerCode
ComputerCodeDefault();

// --- Create, general, const
extern_c Handle2ConstComputerCode
ComputerCodeCreateConst(
   const XMLName label,
   const UTF8Text name,
   const XMLName version,
   ConstHandle2ConstExecutionArguments executionArguments,
   ConstHandle2ConstCodeRepo codeRepo,
   ConstHandle2ConstNote note,
   ConstHandle2ConstInputDecks inputDecks,
   ConstHandle2ConstOutputDecks outputDecks
);

// +++ Create, general
extern_c Handle2ComputerCode
ComputerCodeCreate(
   const XMLName label,
   const UTF8Text name,
   const XMLName version,
   ConstHandle2ConstExecutionArguments executionArguments,
   ConstHandle2ConstCodeRepo codeRepo,
   ConstHandle2ConstNote note,
   ConstHandle2ConstInputDecks inputDecks,
   ConstHandle2ConstOutputDecks outputDecks
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ComputerCodeAssign(ConstHandle2ComputerCode This, ConstHandle2ConstComputerCode from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ComputerCodeDelete(ConstHandle2ConstComputerCode This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ComputerCodeRead(ConstHandle2ComputerCode This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ComputerCodeWrite(ConstHandle2ConstComputerCode This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ComputerCodePrint(ConstHandle2ConstComputerCode This);

// +++ Print to standard output, as XML
extern_c int
ComputerCodePrintXML(ConstHandle2ConstComputerCode This);

// +++ Print to standard output, as JSON
extern_c int
ComputerCodePrintJSON(ConstHandle2ConstComputerCode This);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ComputerCodeLabelHas(ConstHandle2ConstComputerCode This);

// +++ Get
// +++ Returns by value
extern_c XMLName
ComputerCodeLabelGet(ConstHandle2ConstComputerCode This);

// +++ Set
extern_c void
ComputerCodeLabelSet(ConstHandle2ComputerCode This, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: name
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ComputerCodeNameHas(ConstHandle2ConstComputerCode This);

// +++ Get
// +++ Returns by value
extern_c UTF8Text
ComputerCodeNameGet(ConstHandle2ConstComputerCode This);

// +++ Set
extern_c void
ComputerCodeNameSet(ConstHandle2ComputerCode This, const UTF8Text name);


// -----------------------------------------------------------------------------
// Metadatum: version
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ComputerCodeVersionHas(ConstHandle2ConstComputerCode This);

// +++ Get
// +++ Returns by value
extern_c XMLName
ComputerCodeVersionGet(ConstHandle2ConstComputerCode This);

// +++ Set
extern_c void
ComputerCodeVersionSet(ConstHandle2ComputerCode This, const XMLName version);


// -----------------------------------------------------------------------------
// Child: executionArguments
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ComputerCodeExecutionArgumentsHas(ConstHandle2ConstComputerCode This);

// --- Get, const
extern_c Handle2ConstExecutionArguments
ComputerCodeExecutionArgumentsGetConst(ConstHandle2ConstComputerCode This);

// +++ Get, non-const
extern_c Handle2ExecutionArguments
ComputerCodeExecutionArgumentsGet(ConstHandle2ComputerCode This);

// +++ Set
extern_c void
ComputerCodeExecutionArgumentsSet(ConstHandle2ComputerCode This, ConstHandle2ConstExecutionArguments executionArguments);


// -----------------------------------------------------------------------------
// Child: codeRepo
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ComputerCodeCodeRepoHas(ConstHandle2ConstComputerCode This);

// --- Get, const
extern_c Handle2ConstCodeRepo
ComputerCodeCodeRepoGetConst(ConstHandle2ConstComputerCode This);

// +++ Get, non-const
extern_c Handle2CodeRepo
ComputerCodeCodeRepoGet(ConstHandle2ComputerCode This);

// +++ Set
extern_c void
ComputerCodeCodeRepoSet(ConstHandle2ComputerCode This, ConstHandle2ConstCodeRepo codeRepo);


// -----------------------------------------------------------------------------
// Child: note
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ComputerCodeNoteHas(ConstHandle2ConstComputerCode This);

// --- Get, const
extern_c Handle2ConstNote
ComputerCodeNoteGetConst(ConstHandle2ConstComputerCode This);

// +++ Get, non-const
extern_c Handle2Note
ComputerCodeNoteGet(ConstHandle2ComputerCode This);

// +++ Set
extern_c void
ComputerCodeNoteSet(ConstHandle2ComputerCode This, ConstHandle2ConstNote note);


// -----------------------------------------------------------------------------
// Child: inputDecks
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ComputerCodeInputDecksHas(ConstHandle2ConstComputerCode This);

// --- Get, const
extern_c Handle2ConstInputDecks
ComputerCodeInputDecksGetConst(ConstHandle2ConstComputerCode This);

// +++ Get, non-const
extern_c Handle2InputDecks
ComputerCodeInputDecksGet(ConstHandle2ComputerCode This);

// +++ Set
extern_c void
ComputerCodeInputDecksSet(ConstHandle2ComputerCode This, ConstHandle2ConstInputDecks inputDecks);


// -----------------------------------------------------------------------------
// Child: outputDecks
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ComputerCodeOutputDecksHas(ConstHandle2ConstComputerCode This);

// --- Get, const
extern_c Handle2ConstOutputDecks
ComputerCodeOutputDecksGetConst(ConstHandle2ConstComputerCode This);

// +++ Get, non-const
extern_c Handle2OutputDecks
ComputerCodeOutputDecksGet(ConstHandle2ComputerCode This);

// +++ Set
extern_c void
ComputerCodeOutputDecksSet(ConstHandle2ComputerCode This, ConstHandle2ConstOutputDecks outputDecks);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
