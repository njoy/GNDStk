
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

#ifndef C_INTERFACE_CODE_V2_0_GNDS_TITLE
#define C_INTERFACE_CODE_V2_0_GNDS_TITLE

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
TitleCreateConst();

// +++ Create, general
extern_c Handle2Title
TitleCreate();

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
TitleAssign(ConstHandle2Title This, ConstHandle2ConstTitle from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
TitleDelete(ConstHandle2ConstTitle This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
TitleRead(ConstHandle2Title This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
TitleWrite(ConstHandle2ConstTitle This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
TitlePrint(ConstHandle2ConstTitle This);

// +++ Print to standard output, as XML
extern_c int
TitlePrintXML(ConstHandle2ConstTitle This);

// +++ Print to standard output, as JSON
extern_c int
TitlePrintJSON(ConstHandle2ConstTitle This);


// -----------------------------------------------------------------------------
// Data vector
// -----------------------------------------------------------------------------

// ------------------------
// int
// ------------------------

// +++ Clear
extern_c void
TitleIntsClear(ConstHandle2Title This);

// +++ Get size
extern_c size_t
TitleIntsSize(ConstHandle2ConstTitle This);

// +++ Get value
// +++ By index \in [0,size)
extern_c int
TitleIntsGet(ConstHandle2ConstTitle This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
TitleIntsSet(ConstHandle2Title This, const size_t index, const int value);

// --- Get pointer to existing values, const
extern_c const int *
TitleIntsGetArrayConst(ConstHandle2ConstTitle This);

// +++ Get pointer to existing values, non-const
extern_c int *
TitleIntsGetArray(ConstHandle2Title This);

// +++ Set completely new values and size
extern_c void
TitleIntsSetArray(ConstHandle2Title This, const int *const values, const size_t size);

// ------------------------
// unsigned
// ------------------------

// +++ Clear
extern_c void
TitleUnsignedsClear(ConstHandle2Title This);

// +++ Get size
extern_c size_t
TitleUnsignedsSize(ConstHandle2ConstTitle This);

// +++ Get value
// +++ By index \in [0,size)
extern_c unsigned
TitleUnsignedsGet(ConstHandle2ConstTitle This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
TitleUnsignedsSet(ConstHandle2Title This, const size_t index, const unsigned value);

// --- Get pointer to existing values, const
extern_c const unsigned *
TitleUnsignedsGetArrayConst(ConstHandle2ConstTitle This);

// +++ Get pointer to existing values, non-const
extern_c unsigned *
TitleUnsignedsGetArray(ConstHandle2Title This);

// +++ Set completely new values and size
extern_c void
TitleUnsignedsSetArray(ConstHandle2Title This, const unsigned *const values, const size_t size);

// ------------------------
// float
// ------------------------

// +++ Clear
extern_c void
TitleFloatsClear(ConstHandle2Title This);

// +++ Get size
extern_c size_t
TitleFloatsSize(ConstHandle2ConstTitle This);

// +++ Get value
// +++ By index \in [0,size)
extern_c float
TitleFloatsGet(ConstHandle2ConstTitle This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
TitleFloatsSet(ConstHandle2Title This, const size_t index, const float value);

// --- Get pointer to existing values, const
extern_c const float *
TitleFloatsGetArrayConst(ConstHandle2ConstTitle This);

// +++ Get pointer to existing values, non-const
extern_c float *
TitleFloatsGetArray(ConstHandle2Title This);

// +++ Set completely new values and size
extern_c void
TitleFloatsSetArray(ConstHandle2Title This, const float *const values, const size_t size);

// ------------------------
// double
// ------------------------

// +++ Clear
extern_c void
TitleDoublesClear(ConstHandle2Title This);

// +++ Get size
extern_c size_t
TitleDoublesSize(ConstHandle2ConstTitle This);

// +++ Get value
// +++ By index \in [0,size)
extern_c double
TitleDoublesGet(ConstHandle2ConstTitle This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
TitleDoublesSet(ConstHandle2Title This, const size_t index, const double value);

// --- Get pointer to existing values, const
extern_c const double *
TitleDoublesGetArrayConst(ConstHandle2ConstTitle This);

// +++ Get pointer to existing values, non-const
extern_c double *
TitleDoublesGetArray(ConstHandle2Title This);

// +++ Set completely new values and size
extern_c void
TitleDoublesSetArray(ConstHandle2Title This, const double *const values, const size_t size);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
