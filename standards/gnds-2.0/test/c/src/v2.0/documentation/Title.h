
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
// Title is the basic handle type in this file. Example:
//    // Create a default Title object:
//    Title handle = TitleDefault();
// Functions involving Title are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_DOCUMENTATION_TITLE
#define C_INTERFACE_TEST_V2_0_DOCUMENTATION_TITLE

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct TitleClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Title
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct TitleClass *Title;

// --- Const-aware handles.
typedef const struct TitleClass *const ConstHandle2ConstTitle;
typedef       struct TitleClass *const ConstHandle2Title;
typedef const struct TitleClass *      Handle2ConstTitle;
typedef       struct TitleClass *      Handle2Title;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstTitle
TitleDefaultConst();

// +++ Create, default
extern_c Handle2Title
TitleDefault();

// --- Create, general, const
extern_c Handle2ConstTitle
TitleCreateConst(
   const XMLName encoding,
   const char *const markup,
   const XMLName label
);

// +++ Create, general
extern_c Handle2Title
TitleCreate(
   const XMLName encoding,
   const char *const markup,
   const XMLName label
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
TitleAssign(ConstHandle2Title self, ConstHandle2ConstTitle from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
TitleDelete(ConstHandle2ConstTitle self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
TitleRead(ConstHandle2Title self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
TitleWrite(ConstHandle2ConstTitle self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
TitlePrint(ConstHandle2ConstTitle self);

// +++ Print to standard output, as XML
extern_c int
TitlePrintXML(ConstHandle2ConstTitle self);

// +++ Print to standard output, as JSON
extern_c int
TitlePrintJSON(ConstHandle2ConstTitle self);


// -----------------------------------------------------------------------------
// Data vector
// -----------------------------------------------------------------------------

// ------------------------
// int
// ------------------------

// +++ Clear
extern_c void
TitleIntsClear(ConstHandle2Title self);

// +++ Get size
extern_c size_t
TitleIntsSize(ConstHandle2ConstTitle self);

// +++ Get value
// +++ By index \in [0,size)
extern_c int
TitleIntsGet(ConstHandle2ConstTitle self, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
TitleIntsSet(ConstHandle2Title self, const size_t index, const int value);

// --- Get pointer to existing values, const
extern_c const int *
TitleIntsGetArrayConst(ConstHandle2ConstTitle self);

// +++ Get pointer to existing values, non-const
extern_c int *
TitleIntsGetArray(ConstHandle2Title self);

// +++ Set completely new values and size
extern_c void
TitleIntsSetArray(ConstHandle2Title self, const int *const values, const size_t size);

// ------------------------
// unsigned
// ------------------------

// +++ Clear
extern_c void
TitleUnsignedsClear(ConstHandle2Title self);

// +++ Get size
extern_c size_t
TitleUnsignedsSize(ConstHandle2ConstTitle self);

// +++ Get value
// +++ By index \in [0,size)
extern_c unsigned
TitleUnsignedsGet(ConstHandle2ConstTitle self, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
TitleUnsignedsSet(ConstHandle2Title self, const size_t index, const unsigned value);

// --- Get pointer to existing values, const
extern_c const unsigned *
TitleUnsignedsGetArrayConst(ConstHandle2ConstTitle self);

// +++ Get pointer to existing values, non-const
extern_c unsigned *
TitleUnsignedsGetArray(ConstHandle2Title self);

// +++ Set completely new values and size
extern_c void
TitleUnsignedsSetArray(ConstHandle2Title self, const unsigned *const values, const size_t size);

// ------------------------
// float
// ------------------------

// +++ Clear
extern_c void
TitleFloatsClear(ConstHandle2Title self);

// +++ Get size
extern_c size_t
TitleFloatsSize(ConstHandle2ConstTitle self);

// +++ Get value
// +++ By index \in [0,size)
extern_c float
TitleFloatsGet(ConstHandle2ConstTitle self, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
TitleFloatsSet(ConstHandle2Title self, const size_t index, const float value);

// --- Get pointer to existing values, const
extern_c const float *
TitleFloatsGetArrayConst(ConstHandle2ConstTitle self);

// +++ Get pointer to existing values, non-const
extern_c float *
TitleFloatsGetArray(ConstHandle2Title self);

// +++ Set completely new values and size
extern_c void
TitleFloatsSetArray(ConstHandle2Title self, const float *const values, const size_t size);

// ------------------------
// double
// ------------------------

// +++ Clear
extern_c void
TitleDoublesClear(ConstHandle2Title self);

// +++ Get size
extern_c size_t
TitleDoublesSize(ConstHandle2ConstTitle self);

// +++ Get value
// +++ By index \in [0,size)
extern_c double
TitleDoublesGet(ConstHandle2ConstTitle self, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
TitleDoublesSet(ConstHandle2Title self, const size_t index, const double value);

// --- Get pointer to existing values, const
extern_c const double *
TitleDoublesGetArrayConst(ConstHandle2ConstTitle self);

// +++ Get pointer to existing values, non-const
extern_c double *
TitleDoublesGetArray(ConstHandle2Title self);

// +++ Set completely new values and size
extern_c void
TitleDoublesSetArray(ConstHandle2Title self, const double *const values, const size_t size);


// -----------------------------------------------------------------------------
// Metadatum: encoding
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
TitleEncodingHas(ConstHandle2ConstTitle self);

// +++ Get
// +++ Returns by value
extern_c XMLName
TitleEncodingGet(ConstHandle2ConstTitle self);

// +++ Set
extern_c void
TitleEncodingSet(ConstHandle2Title self, const XMLName encoding);


// -----------------------------------------------------------------------------
// Metadatum: markup
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
TitleMarkupHas(ConstHandle2ConstTitle self);

// +++ Get
// +++ Returns by value
extern_c const char *
TitleMarkupGet(ConstHandle2ConstTitle self);

// +++ Set
extern_c void
TitleMarkupSet(ConstHandle2Title self, const char *const markup);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
TitleLabelHas(ConstHandle2ConstTitle self);

// +++ Get
// +++ Returns by value
extern_c XMLName
TitleLabelGet(ConstHandle2ConstTitle self);

// +++ Set
extern_c void
TitleLabelSet(ConstHandle2Title self, const XMLName label);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/documentation/Title/src/custom.h"

#undef extern_c
#endif
