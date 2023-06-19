
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
// Abstract is the basic handle type in this file. Example:
//    // Create a default Abstract object:
//    Abstract handle = AbstractDefault();
// Functions involving Abstract are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_DOCUMENTATION_ABSTRACT
#define C_INTERFACE_TEST_V2_0_DOCUMENTATION_ABSTRACT

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct AbstractClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Abstract
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct AbstractClass *Abstract;

// --- Const-aware handles.
typedef const struct AbstractClass *const ConstHandle2ConstAbstract;
typedef       struct AbstractClass *const ConstHandle2Abstract;
typedef const struct AbstractClass *      Handle2ConstAbstract;
typedef       struct AbstractClass *      Handle2Abstract;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstAbstract
AbstractDefaultConst();

// +++ Create, default
extern_c Handle2Abstract
AbstractDefault();

// --- Create, general, const
extern_c Handle2ConstAbstract
AbstractCreateConst(
   const XMLName encoding,
   const char *const markup,
   const XMLName label
);

// +++ Create, general
extern_c Handle2Abstract
AbstractCreate(
   const XMLName encoding,
   const char *const markup,
   const XMLName label
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
AbstractAssign(ConstHandle2Abstract self, ConstHandle2ConstAbstract from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
AbstractDelete(ConstHandle2ConstAbstract self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
AbstractRead(ConstHandle2Abstract self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
AbstractWrite(ConstHandle2ConstAbstract self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
AbstractPrint(ConstHandle2ConstAbstract self);

// +++ Print to standard output, as XML
extern_c int
AbstractPrintXML(ConstHandle2ConstAbstract self);

// +++ Print to standard output, as JSON
extern_c int
AbstractPrintJSON(ConstHandle2ConstAbstract self);


// -----------------------------------------------------------------------------
// Data vector
// -----------------------------------------------------------------------------

// ------------------------
// int
// ------------------------

// +++ Clear
extern_c void
AbstractIntsClear(ConstHandle2Abstract self);

// +++ Get size
extern_c size_t
AbstractIntsSize(ConstHandle2ConstAbstract self);

// +++ Get value
// +++ By index \in [0,size)
extern_c int
AbstractIntsGet(ConstHandle2ConstAbstract self, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
AbstractIntsSet(ConstHandle2Abstract self, const size_t index, const int value);

// --- Get pointer to existing values, const
extern_c const int *
AbstractIntsGetArrayConst(ConstHandle2ConstAbstract self);

// +++ Get pointer to existing values, non-const
extern_c int *
AbstractIntsGetArray(ConstHandle2Abstract self);

// +++ Set completely new values and size
extern_c void
AbstractIntsSetArray(ConstHandle2Abstract self, const int *const values, const size_t size);

// ------------------------
// unsigned
// ------------------------

// +++ Clear
extern_c void
AbstractUnsignedsClear(ConstHandle2Abstract self);

// +++ Get size
extern_c size_t
AbstractUnsignedsSize(ConstHandle2ConstAbstract self);

// +++ Get value
// +++ By index \in [0,size)
extern_c unsigned
AbstractUnsignedsGet(ConstHandle2ConstAbstract self, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
AbstractUnsignedsSet(ConstHandle2Abstract self, const size_t index, const unsigned value);

// --- Get pointer to existing values, const
extern_c const unsigned *
AbstractUnsignedsGetArrayConst(ConstHandle2ConstAbstract self);

// +++ Get pointer to existing values, non-const
extern_c unsigned *
AbstractUnsignedsGetArray(ConstHandle2Abstract self);

// +++ Set completely new values and size
extern_c void
AbstractUnsignedsSetArray(ConstHandle2Abstract self, const unsigned *const values, const size_t size);

// ------------------------
// float
// ------------------------

// +++ Clear
extern_c void
AbstractFloatsClear(ConstHandle2Abstract self);

// +++ Get size
extern_c size_t
AbstractFloatsSize(ConstHandle2ConstAbstract self);

// +++ Get value
// +++ By index \in [0,size)
extern_c float
AbstractFloatsGet(ConstHandle2ConstAbstract self, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
AbstractFloatsSet(ConstHandle2Abstract self, const size_t index, const float value);

// --- Get pointer to existing values, const
extern_c const float *
AbstractFloatsGetArrayConst(ConstHandle2ConstAbstract self);

// +++ Get pointer to existing values, non-const
extern_c float *
AbstractFloatsGetArray(ConstHandle2Abstract self);

// +++ Set completely new values and size
extern_c void
AbstractFloatsSetArray(ConstHandle2Abstract self, const float *const values, const size_t size);

// ------------------------
// double
// ------------------------

// +++ Clear
extern_c void
AbstractDoublesClear(ConstHandle2Abstract self);

// +++ Get size
extern_c size_t
AbstractDoublesSize(ConstHandle2ConstAbstract self);

// +++ Get value
// +++ By index \in [0,size)
extern_c double
AbstractDoublesGet(ConstHandle2ConstAbstract self, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
AbstractDoublesSet(ConstHandle2Abstract self, const size_t index, const double value);

// --- Get pointer to existing values, const
extern_c const double *
AbstractDoublesGetArrayConst(ConstHandle2ConstAbstract self);

// +++ Get pointer to existing values, non-const
extern_c double *
AbstractDoublesGetArray(ConstHandle2Abstract self);

// +++ Set completely new values and size
extern_c void
AbstractDoublesSetArray(ConstHandle2Abstract self, const double *const values, const size_t size);


// -----------------------------------------------------------------------------
// Metadatum: encoding
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AbstractEncodingHas(ConstHandle2ConstAbstract self);

// +++ Get
// +++ Returns by value
extern_c XMLName
AbstractEncodingGet(ConstHandle2ConstAbstract self);

// +++ Set
extern_c void
AbstractEncodingSet(ConstHandle2Abstract self, const XMLName encoding);


// -----------------------------------------------------------------------------
// Metadatum: markup
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AbstractMarkupHas(ConstHandle2ConstAbstract self);

// +++ Get
// +++ Returns by value
extern_c const char *
AbstractMarkupGet(ConstHandle2ConstAbstract self);

// +++ Set
extern_c void
AbstractMarkupSet(ConstHandle2Abstract self, const char *const markup);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
AbstractLabelHas(ConstHandle2ConstAbstract self);

// +++ Get
// +++ Returns by value
extern_c XMLName
AbstractLabelGet(ConstHandle2ConstAbstract self);

// +++ Set
extern_c void
AbstractLabelSet(ConstHandle2Abstract self, const XMLName label);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/documentation/Abstract/src/custom.h"

#undef extern_c
#endif
