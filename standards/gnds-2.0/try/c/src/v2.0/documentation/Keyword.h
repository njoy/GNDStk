
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
// Keyword is the basic handle type in this file. Example:
//    // Create a default Keyword object:
//    Keyword handle = KeywordDefault();
// Functions involving Keyword are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_DOCUMENTATION_KEYWORD
#define C_INTERFACE_TRY_V2_0_DOCUMENTATION_KEYWORD

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct KeywordClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Keyword
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct KeywordClass *Keyword;

// --- Const-aware handles.
typedef const struct KeywordClass *const ConstHandle2ConstKeyword;
typedef       struct KeywordClass *const ConstHandle2Keyword;
typedef const struct KeywordClass *      Handle2ConstKeyword;
typedef       struct KeywordClass *      Handle2Keyword;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstKeyword
KeywordDefaultConst();

// +++ Create, default
extern_c Handle2Keyword
KeywordDefault();

// --- Create, general, const
extern_c Handle2ConstKeyword
KeywordCreateConst(
   const XMLName encoding,
   const char *const markup,
   const XMLName label,
   const XMLName type
);

// +++ Create, general
extern_c Handle2Keyword
KeywordCreate(
   const XMLName encoding,
   const char *const markup,
   const XMLName label,
   const XMLName type
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
KeywordAssign(ConstHandle2Keyword This, ConstHandle2ConstKeyword from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
KeywordDelete(ConstHandle2ConstKeyword This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
KeywordRead(ConstHandle2Keyword This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
KeywordWrite(ConstHandle2ConstKeyword This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
KeywordPrint(ConstHandle2ConstKeyword This);

// +++ Print to standard output, as XML
extern_c int
KeywordPrintXML(ConstHandle2ConstKeyword This);

// +++ Print to standard output, as JSON
extern_c int
KeywordPrintJSON(ConstHandle2ConstKeyword This);


// -----------------------------------------------------------------------------
// Data vector
// -----------------------------------------------------------------------------

// ------------------------
// int
// ------------------------

// +++ Clear
extern_c void
KeywordIntsClear(ConstHandle2Keyword This);

// +++ Get size
extern_c size_t
KeywordIntsSize(ConstHandle2ConstKeyword This);

// +++ Get value
// +++ By index \in [0,size)
extern_c int
KeywordIntsGet(ConstHandle2ConstKeyword This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
KeywordIntsSet(ConstHandle2Keyword This, const size_t index, const int value);

// --- Get pointer to existing values, const
extern_c const int *
KeywordIntsGetArrayConst(ConstHandle2ConstKeyword This);

// +++ Get pointer to existing values, non-const
extern_c int *
KeywordIntsGetArray(ConstHandle2Keyword This);

// +++ Set completely new values and size
extern_c void
KeywordIntsSetArray(ConstHandle2Keyword This, const int *const values, const size_t size);

// ------------------------
// unsigned
// ------------------------

// +++ Clear
extern_c void
KeywordUnsignedsClear(ConstHandle2Keyword This);

// +++ Get size
extern_c size_t
KeywordUnsignedsSize(ConstHandle2ConstKeyword This);

// +++ Get value
// +++ By index \in [0,size)
extern_c unsigned
KeywordUnsignedsGet(ConstHandle2ConstKeyword This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
KeywordUnsignedsSet(ConstHandle2Keyword This, const size_t index, const unsigned value);

// --- Get pointer to existing values, const
extern_c const unsigned *
KeywordUnsignedsGetArrayConst(ConstHandle2ConstKeyword This);

// +++ Get pointer to existing values, non-const
extern_c unsigned *
KeywordUnsignedsGetArray(ConstHandle2Keyword This);

// +++ Set completely new values and size
extern_c void
KeywordUnsignedsSetArray(ConstHandle2Keyword This, const unsigned *const values, const size_t size);

// ------------------------
// float
// ------------------------

// +++ Clear
extern_c void
KeywordFloatsClear(ConstHandle2Keyword This);

// +++ Get size
extern_c size_t
KeywordFloatsSize(ConstHandle2ConstKeyword This);

// +++ Get value
// +++ By index \in [0,size)
extern_c float
KeywordFloatsGet(ConstHandle2ConstKeyword This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
KeywordFloatsSet(ConstHandle2Keyword This, const size_t index, const float value);

// --- Get pointer to existing values, const
extern_c const float *
KeywordFloatsGetArrayConst(ConstHandle2ConstKeyword This);

// +++ Get pointer to existing values, non-const
extern_c float *
KeywordFloatsGetArray(ConstHandle2Keyword This);

// +++ Set completely new values and size
extern_c void
KeywordFloatsSetArray(ConstHandle2Keyword This, const float *const values, const size_t size);

// ------------------------
// double
// ------------------------

// +++ Clear
extern_c void
KeywordDoublesClear(ConstHandle2Keyword This);

// +++ Get size
extern_c size_t
KeywordDoublesSize(ConstHandle2ConstKeyword This);

// +++ Get value
// +++ By index \in [0,size)
extern_c double
KeywordDoublesGet(ConstHandle2ConstKeyword This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
KeywordDoublesSet(ConstHandle2Keyword This, const size_t index, const double value);

// --- Get pointer to existing values, const
extern_c const double *
KeywordDoublesGetArrayConst(ConstHandle2ConstKeyword This);

// +++ Get pointer to existing values, non-const
extern_c double *
KeywordDoublesGetArray(ConstHandle2Keyword This);

// +++ Set completely new values and size
extern_c void
KeywordDoublesSetArray(ConstHandle2Keyword This, const double *const values, const size_t size);


// -----------------------------------------------------------------------------
// Metadatum: encoding
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
KeywordEncodingHas(ConstHandle2ConstKeyword This);

// +++ Get
// +++ Returns by value
extern_c XMLName
KeywordEncodingGet(ConstHandle2ConstKeyword This);

// +++ Set
extern_c void
KeywordEncodingSet(ConstHandle2Keyword This, const XMLName encoding);


// -----------------------------------------------------------------------------
// Metadatum: markup
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
KeywordMarkupHas(ConstHandle2ConstKeyword This);

// +++ Get
// +++ Returns by value
extern_c const char *
KeywordMarkupGet(ConstHandle2ConstKeyword This);

// +++ Set
extern_c void
KeywordMarkupSet(ConstHandle2Keyword This, const char *const markup);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
KeywordLabelHas(ConstHandle2ConstKeyword This);

// +++ Get
// +++ Returns by value
extern_c XMLName
KeywordLabelGet(ConstHandle2ConstKeyword This);

// +++ Set
extern_c void
KeywordLabelSet(ConstHandle2Keyword This, const XMLName label);


// -----------------------------------------------------------------------------
// Metadatum: type
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
KeywordTypeHas(ConstHandle2ConstKeyword This);

// +++ Get
// +++ Returns by value
extern_c XMLName
KeywordTypeGet(ConstHandle2ConstKeyword This);

// +++ Set
extern_c void
KeywordTypeSet(ConstHandle2Keyword This, const XMLName type);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
