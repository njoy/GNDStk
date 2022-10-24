
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
// Evaluated is the basic handle type in this file. Example:
//    // Create a default Evaluated object:
//    Evaluated handle = EvaluatedDefault();
// Functions involving Evaluated are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_CODE_V2_0_GNDS_EVALUATED
#define C_INTERFACE_CODE_V2_0_GNDS_EVALUATED

#include "GNDStk.h"
#include "v2.0/gnds/Documentation.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct EvaluatedClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Evaluated
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct EvaluatedClass *Evaluated;

// --- Const-aware handles.
typedef const struct EvaluatedClass *const ConstHandle2ConstEvaluated;
typedef       struct EvaluatedClass *const ConstHandle2Evaluated;
typedef const struct EvaluatedClass *      Handle2ConstEvaluated;
typedef       struct EvaluatedClass *      Handle2Evaluated;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstEvaluated
EvaluatedDefaultConst();

// +++ Create, default
extern_c Handle2Evaluated
EvaluatedDefault();

// --- Create, general, const
extern_c Handle2ConstEvaluated
EvaluatedCreateConst(
   const char *const label,
   const char *const date,
   const char *const library,
   const char *const version,
   ConstHandle2ConstDocumentation documentation
);

// +++ Create, general
extern_c Handle2Evaluated
EvaluatedCreate(
   const char *const label,
   const char *const date,
   const char *const library,
   const char *const version,
   ConstHandle2ConstDocumentation documentation
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
EvaluatedAssign(ConstHandle2Evaluated This, ConstHandle2ConstEvaluated from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
EvaluatedDelete(ConstHandle2ConstEvaluated This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
EvaluatedRead(ConstHandle2Evaluated This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
EvaluatedWrite(ConstHandle2ConstEvaluated This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
EvaluatedPrint(ConstHandle2ConstEvaluated This);

// +++ Print to standard output, as XML
extern_c int
EvaluatedPrintXML(ConstHandle2ConstEvaluated This);

// +++ Print to standard output, as JSON
extern_c int
EvaluatedPrintJSON(ConstHandle2ConstEvaluated This);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
EvaluatedLabelHas(ConstHandle2ConstEvaluated This);

// +++ Get
// +++ Returns by value
extern_c const char *
EvaluatedLabelGet(ConstHandle2ConstEvaluated This);

// +++ Set
extern_c void
EvaluatedLabelSet(ConstHandle2Evaluated This, const char *const label);


// -----------------------------------------------------------------------------
// Metadatum: date
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
EvaluatedDateHas(ConstHandle2ConstEvaluated This);

// +++ Get
// +++ Returns by value
extern_c const char *
EvaluatedDateGet(ConstHandle2ConstEvaluated This);

// +++ Set
extern_c void
EvaluatedDateSet(ConstHandle2Evaluated This, const char *const date);


// -----------------------------------------------------------------------------
// Metadatum: library
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
EvaluatedLibraryHas(ConstHandle2ConstEvaluated This);

// +++ Get
// +++ Returns by value
extern_c const char *
EvaluatedLibraryGet(ConstHandle2ConstEvaluated This);

// +++ Set
extern_c void
EvaluatedLibrarySet(ConstHandle2Evaluated This, const char *const library);


// -----------------------------------------------------------------------------
// Metadatum: version
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
EvaluatedVersionHas(ConstHandle2ConstEvaluated This);

// +++ Get
// +++ Returns by value
extern_c const char *
EvaluatedVersionGet(ConstHandle2ConstEvaluated This);

// +++ Set
extern_c void
EvaluatedVersionSet(ConstHandle2Evaluated This, const char *const version);


// -----------------------------------------------------------------------------
// Child: documentation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
EvaluatedDocumentationHas(ConstHandle2ConstEvaluated This);

// --- Get, const
extern_c Handle2ConstDocumentation
EvaluatedDocumentationGetConst(ConstHandle2ConstEvaluated This);

// +++ Get, non-const
extern_c Handle2Documentation
EvaluatedDocumentationGet(ConstHandle2Evaluated This);

// +++ Set
extern_c void
EvaluatedDocumentationSet(ConstHandle2Evaluated This, ConstHandle2ConstDocumentation documentation);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
