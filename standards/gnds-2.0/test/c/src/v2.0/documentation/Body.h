
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
// Body is the basic handle type in this file. Example:
//    // Create a default Body object:
//    Body handle = BodyDefault();
// Functions involving Body are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_DOCUMENTATION_BODY
#define C_INTERFACE_TEST_V2_0_DOCUMENTATION_BODY

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct BodyClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Body
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct BodyClass *Body;

// --- Const-aware handles.
typedef const struct BodyClass *const ConstHandle2ConstBody;
typedef       struct BodyClass *const ConstHandle2Body;
typedef const struct BodyClass *      Handle2ConstBody;
typedef       struct BodyClass *      Handle2Body;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstBody
BodyDefaultConst();

// +++ Create, default
extern_c Handle2Body
BodyDefault();

// --- Create, general, const
extern_c Handle2ConstBody
BodyCreateConst(
   const XMLName encoding,
   const char *const markup,
   const XMLName label
);

// +++ Create, general
extern_c Handle2Body
BodyCreate(
   const XMLName encoding,
   const char *const markup,
   const XMLName label
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
BodyAssign(ConstHandle2Body This, ConstHandle2ConstBody from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
BodyDelete(ConstHandle2ConstBody This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
BodyRead(ConstHandle2Body This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
BodyWrite(ConstHandle2ConstBody This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
BodyPrint(ConstHandle2ConstBody This);

// +++ Print to standard output, as XML
extern_c int
BodyPrintXML(ConstHandle2ConstBody This);

// +++ Print to standard output, as JSON
extern_c int
BodyPrintJSON(ConstHandle2ConstBody This);


// -----------------------------------------------------------------------------
// Data vector
// -----------------------------------------------------------------------------

// ------------------------
// int
// ------------------------

// +++ Clear
extern_c void
BodyIntsClear(ConstHandle2Body This);

// +++ Get size
extern_c size_t
BodyIntsSize(ConstHandle2ConstBody This);

// +++ Get value
// +++ By index \in [0,size)
extern_c int
BodyIntsGet(ConstHandle2ConstBody This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
BodyIntsSet(ConstHandle2Body This, const size_t index, const int value);

// --- Get pointer to existing values, const
extern_c const int *
BodyIntsGetArrayConst(ConstHandle2ConstBody This);

// +++ Get pointer to existing values, non-const
extern_c int *
BodyIntsGetArray(ConstHandle2Body This);

// +++ Set completely new values and size
extern_c void
BodyIntsSetArray(ConstHandle2Body This, const int *const values, const size_t size);

// ------------------------
// unsigned
// ------------------------

// +++ Clear
extern_c void
BodyUnsignedsClear(ConstHandle2Body This);

// +++ Get size
extern_c size_t
BodyUnsignedsSize(ConstHandle2ConstBody This);

// +++ Get value
// +++ By index \in [0,size)
extern_c unsigned
BodyUnsignedsGet(ConstHandle2ConstBody This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
BodyUnsignedsSet(ConstHandle2Body This, const size_t index, const unsigned value);

// --- Get pointer to existing values, const
extern_c const unsigned *
BodyUnsignedsGetArrayConst(ConstHandle2ConstBody This);

// +++ Get pointer to existing values, non-const
extern_c unsigned *
BodyUnsignedsGetArray(ConstHandle2Body This);

// +++ Set completely new values and size
extern_c void
BodyUnsignedsSetArray(ConstHandle2Body This, const unsigned *const values, const size_t size);

// ------------------------
// float
// ------------------------

// +++ Clear
extern_c void
BodyFloatsClear(ConstHandle2Body This);

// +++ Get size
extern_c size_t
BodyFloatsSize(ConstHandle2ConstBody This);

// +++ Get value
// +++ By index \in [0,size)
extern_c float
BodyFloatsGet(ConstHandle2ConstBody This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
BodyFloatsSet(ConstHandle2Body This, const size_t index, const float value);

// --- Get pointer to existing values, const
extern_c const float *
BodyFloatsGetArrayConst(ConstHandle2ConstBody This);

// +++ Get pointer to existing values, non-const
extern_c float *
BodyFloatsGetArray(ConstHandle2Body This);

// +++ Set completely new values and size
extern_c void
BodyFloatsSetArray(ConstHandle2Body This, const float *const values, const size_t size);

// ------------------------
// double
// ------------------------

// +++ Clear
extern_c void
BodyDoublesClear(ConstHandle2Body This);

// +++ Get size
extern_c size_t
BodyDoublesSize(ConstHandle2ConstBody This);

// +++ Get value
// +++ By index \in [0,size)
extern_c double
BodyDoublesGet(ConstHandle2ConstBody This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
BodyDoublesSet(ConstHandle2Body This, const size_t index, const double value);

// --- Get pointer to existing values, const
extern_c const double *
BodyDoublesGetArrayConst(ConstHandle2ConstBody This);

// +++ Get pointer to existing values, non-const
extern_c double *
BodyDoublesGetArray(ConstHandle2Body This);

// +++ Set completely new values and size
extern_c void
BodyDoublesSetArray(ConstHandle2Body This, const double *const values, const size_t size);


// -----------------------------------------------------------------------------
// Metadatum: encoding
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BodyEncodingHas(ConstHandle2ConstBody This);

// +++ Get
// +++ Returns by value
extern_c XMLName
BodyEncodingGet(ConstHandle2ConstBody This);

// +++ Set
extern_c void
BodyEncodingSet(ConstHandle2Body This, const XMLName encoding);


// -----------------------------------------------------------------------------
// Metadatum: markup
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BodyMarkupHas(ConstHandle2ConstBody This);

// +++ Get
// +++ Returns by value
extern_c const char *
BodyMarkupGet(ConstHandle2ConstBody This);

// +++ Set
extern_c void
BodyMarkupSet(ConstHandle2Body This, const char *const markup);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
BodyLabelHas(ConstHandle2ConstBody This);

// +++ Get
// +++ Returns by value
extern_c XMLName
BodyLabelGet(ConstHandle2ConstBody This);

// +++ Set
extern_c void
BodyLabelSet(ConstHandle2Body This, const XMLName label);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/documentation/Body/src/custom.h"

#undef extern_c
#endif
