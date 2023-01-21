
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
// Note is the basic handle type in this file. Example:
//    // Create a default Note object:
//    Note handle = NoteDefault();
// Functions involving Note are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_DOCUMENTATION_NOTE
#define C_INTERFACE_TEST_V2_0_DOCUMENTATION_NOTE

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct NoteClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Note
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct NoteClass *Note;

// --- Const-aware handles.
typedef const struct NoteClass *const ConstHandle2ConstNote;
typedef       struct NoteClass *const ConstHandle2Note;
typedef const struct NoteClass *      Handle2ConstNote;
typedef       struct NoteClass *      Handle2Note;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstNote
NoteDefaultConst();

// +++ Create, default
extern_c Handle2Note
NoteDefault();

// --- Create, general, const
extern_c Handle2ConstNote
NoteCreateConst(
   const XMLName encoding,
   const char *const markup,
   const XMLName label
);

// +++ Create, general
extern_c Handle2Note
NoteCreate(
   const XMLName encoding,
   const char *const markup,
   const XMLName label
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
NoteAssign(ConstHandle2Note This, ConstHandle2ConstNote from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
NoteDelete(ConstHandle2ConstNote This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
NoteRead(ConstHandle2Note This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
NoteWrite(ConstHandle2ConstNote This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
NotePrint(ConstHandle2ConstNote This);

// +++ Print to standard output, as XML
extern_c int
NotePrintXML(ConstHandle2ConstNote This);

// +++ Print to standard output, as JSON
extern_c int
NotePrintJSON(ConstHandle2ConstNote This);


// -----------------------------------------------------------------------------
// Data vector
// -----------------------------------------------------------------------------

// ------------------------
// int
// ------------------------

// +++ Clear
extern_c void
NoteIntsClear(ConstHandle2Note This);

// +++ Get size
extern_c size_t
NoteIntsSize(ConstHandle2ConstNote This);

// +++ Get value
// +++ By index \in [0,size)
extern_c int
NoteIntsGet(ConstHandle2ConstNote This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
NoteIntsSet(ConstHandle2Note This, const size_t index, const int value);

// --- Get pointer to existing values, const
extern_c const int *
NoteIntsGetArrayConst(ConstHandle2ConstNote This);

// +++ Get pointer to existing values, non-const
extern_c int *
NoteIntsGetArray(ConstHandle2Note This);

// +++ Set completely new values and size
extern_c void
NoteIntsSetArray(ConstHandle2Note This, const int *const values, const size_t size);

// ------------------------
// unsigned
// ------------------------

// +++ Clear
extern_c void
NoteUnsignedsClear(ConstHandle2Note This);

// +++ Get size
extern_c size_t
NoteUnsignedsSize(ConstHandle2ConstNote This);

// +++ Get value
// +++ By index \in [0,size)
extern_c unsigned
NoteUnsignedsGet(ConstHandle2ConstNote This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
NoteUnsignedsSet(ConstHandle2Note This, const size_t index, const unsigned value);

// --- Get pointer to existing values, const
extern_c const unsigned *
NoteUnsignedsGetArrayConst(ConstHandle2ConstNote This);

// +++ Get pointer to existing values, non-const
extern_c unsigned *
NoteUnsignedsGetArray(ConstHandle2Note This);

// +++ Set completely new values and size
extern_c void
NoteUnsignedsSetArray(ConstHandle2Note This, const unsigned *const values, const size_t size);

// ------------------------
// float
// ------------------------

// +++ Clear
extern_c void
NoteFloatsClear(ConstHandle2Note This);

// +++ Get size
extern_c size_t
NoteFloatsSize(ConstHandle2ConstNote This);

// +++ Get value
// +++ By index \in [0,size)
extern_c float
NoteFloatsGet(ConstHandle2ConstNote This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
NoteFloatsSet(ConstHandle2Note This, const size_t index, const float value);

// --- Get pointer to existing values, const
extern_c const float *
NoteFloatsGetArrayConst(ConstHandle2ConstNote This);

// +++ Get pointer to existing values, non-const
extern_c float *
NoteFloatsGetArray(ConstHandle2Note This);

// +++ Set completely new values and size
extern_c void
NoteFloatsSetArray(ConstHandle2Note This, const float *const values, const size_t size);

// ------------------------
// double
// ------------------------

// +++ Clear
extern_c void
NoteDoublesClear(ConstHandle2Note This);

// +++ Get size
extern_c size_t
NoteDoublesSize(ConstHandle2ConstNote This);

// +++ Get value
// +++ By index \in [0,size)
extern_c double
NoteDoublesGet(ConstHandle2ConstNote This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
NoteDoublesSet(ConstHandle2Note This, const size_t index, const double value);

// --- Get pointer to existing values, const
extern_c const double *
NoteDoublesGetArrayConst(ConstHandle2ConstNote This);

// +++ Get pointer to existing values, non-const
extern_c double *
NoteDoublesGetArray(ConstHandle2Note This);

// +++ Set completely new values and size
extern_c void
NoteDoublesSetArray(ConstHandle2Note This, const double *const values, const size_t size);


// -----------------------------------------------------------------------------
// Metadatum: encoding
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NoteEncodingHas(ConstHandle2ConstNote This);

// +++ Get
// +++ Returns by value
extern_c XMLName
NoteEncodingGet(ConstHandle2ConstNote This);

// +++ Set
extern_c void
NoteEncodingSet(ConstHandle2Note This, const XMLName encoding);


// -----------------------------------------------------------------------------
// Metadatum: markup
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NoteMarkupHas(ConstHandle2ConstNote This);

// +++ Get
// +++ Returns by value
extern_c const char *
NoteMarkupGet(ConstHandle2ConstNote This);

// +++ Set
extern_c void
NoteMarkupSet(ConstHandle2Note This, const char *const markup);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
NoteLabelHas(ConstHandle2ConstNote This);

// +++ Get
// +++ Returns by value
extern_c XMLName
NoteLabelGet(ConstHandle2ConstNote This);

// +++ Set
extern_c void
NoteLabelSet(ConstHandle2Note This, const XMLName label);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/documentation/Note/src/custom.h"

#undef extern_c
#endif
