
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
// Values is the basic handle type in this file. Example:
//    // Create a default Values object:
//    Values handle = ValuesDefault();
// Functions involving Values are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_CONTAINERS_VALUES
#define C_INTERFACE_TEST_V2_0_CONTAINERS_VALUES

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ValuesClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Values
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ValuesClass *Values;

// --- Const-aware handles.
typedef const struct ValuesClass *const ConstHandle2ConstValues;
typedef       struct ValuesClass *const ConstHandle2Values;
typedef const struct ValuesClass *      Handle2ConstValues;
typedef       struct ValuesClass *      Handle2Values;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstValues
ValuesDefaultConst();

// +++ Create, default
extern_c Handle2Values
ValuesDefault();

// --- Create, general, const
extern_c Handle2ConstValues
ValuesCreateConst(
   const UTF8Text valueType,
   const Integer32 start,
   const Integer32 length,
   const UTF8Text href,
   const Integer32 startIndex,
   const Integer32 count
);

// +++ Create, general
extern_c Handle2Values
ValuesCreate(
   const UTF8Text valueType,
   const Integer32 start,
   const Integer32 length,
   const UTF8Text href,
   const Integer32 startIndex,
   const Integer32 count
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ValuesAssign(ConstHandle2Values This, ConstHandle2ConstValues from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ValuesDelete(ConstHandle2ConstValues This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ValuesRead(ConstHandle2Values This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ValuesWrite(ConstHandle2ConstValues This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ValuesPrint(ConstHandle2ConstValues This);

// +++ Print to standard output, as XML
extern_c int
ValuesPrintXML(ConstHandle2ConstValues This);

// +++ Print to standard output, as JSON
extern_c int
ValuesPrintJSON(ConstHandle2ConstValues This);


// -----------------------------------------------------------------------------
// Data vector
// -----------------------------------------------------------------------------

// ------------------------
// int
// ------------------------

// +++ Clear
extern_c void
ValuesIntsClear(ConstHandle2Values This);

// +++ Get size
extern_c size_t
ValuesIntsSize(ConstHandle2ConstValues This);

// +++ Get value
// +++ By index \in [0,size)
extern_c int
ValuesIntsGet(ConstHandle2ConstValues This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
ValuesIntsSet(ConstHandle2Values This, const size_t index, const int value);

// --- Get pointer to existing values, const
extern_c const int *
ValuesIntsGetArrayConst(ConstHandle2ConstValues This);

// +++ Get pointer to existing values, non-const
extern_c int *
ValuesIntsGetArray(ConstHandle2Values This);

// +++ Set completely new values and size
extern_c void
ValuesIntsSetArray(ConstHandle2Values This, const int *const values, const size_t size);

// ------------------------
// unsigned
// ------------------------

// +++ Clear
extern_c void
ValuesUnsignedsClear(ConstHandle2Values This);

// +++ Get size
extern_c size_t
ValuesUnsignedsSize(ConstHandle2ConstValues This);

// +++ Get value
// +++ By index \in [0,size)
extern_c unsigned
ValuesUnsignedsGet(ConstHandle2ConstValues This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
ValuesUnsignedsSet(ConstHandle2Values This, const size_t index, const unsigned value);

// --- Get pointer to existing values, const
extern_c const unsigned *
ValuesUnsignedsGetArrayConst(ConstHandle2ConstValues This);

// +++ Get pointer to existing values, non-const
extern_c unsigned *
ValuesUnsignedsGetArray(ConstHandle2Values This);

// +++ Set completely new values and size
extern_c void
ValuesUnsignedsSetArray(ConstHandle2Values This, const unsigned *const values, const size_t size);

// ------------------------
// float
// ------------------------

// +++ Clear
extern_c void
ValuesFloatsClear(ConstHandle2Values This);

// +++ Get size
extern_c size_t
ValuesFloatsSize(ConstHandle2ConstValues This);

// +++ Get value
// +++ By index \in [0,size)
extern_c float
ValuesFloatsGet(ConstHandle2ConstValues This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
ValuesFloatsSet(ConstHandle2Values This, const size_t index, const float value);

// --- Get pointer to existing values, const
extern_c const float *
ValuesFloatsGetArrayConst(ConstHandle2ConstValues This);

// +++ Get pointer to existing values, non-const
extern_c float *
ValuesFloatsGetArray(ConstHandle2Values This);

// +++ Set completely new values and size
extern_c void
ValuesFloatsSetArray(ConstHandle2Values This, const float *const values, const size_t size);

// ------------------------
// double
// ------------------------

// +++ Clear
extern_c void
ValuesDoublesClear(ConstHandle2Values This);

// +++ Get size
extern_c size_t
ValuesDoublesSize(ConstHandle2ConstValues This);

// +++ Get value
// +++ By index \in [0,size)
extern_c double
ValuesDoublesGet(ConstHandle2ConstValues This, const size_t index);

// +++ Set value
// +++ By index \in [0,size)
extern_c void
ValuesDoublesSet(ConstHandle2Values This, const size_t index, const double value);

// --- Get pointer to existing values, const
extern_c const double *
ValuesDoublesGetArrayConst(ConstHandle2ConstValues This);

// +++ Get pointer to existing values, non-const
extern_c double *
ValuesDoublesGetArray(ConstHandle2Values This);

// +++ Set completely new values and size
extern_c void
ValuesDoublesSetArray(ConstHandle2Values This, const double *const values, const size_t size);


// -----------------------------------------------------------------------------
// Metadatum: valueType
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ValuesValueTypeHas(ConstHandle2ConstValues This);

// +++ Get
// +++ Returns by value
extern_c UTF8Text
ValuesValueTypeGet(ConstHandle2ConstValues This);

// +++ Set
extern_c void
ValuesValueTypeSet(ConstHandle2Values This, const UTF8Text valueType);


// -----------------------------------------------------------------------------
// Metadatum: start
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ValuesStartHas(ConstHandle2ConstValues This);

// +++ Get
// +++ Returns by value
extern_c Integer32
ValuesStartGet(ConstHandle2ConstValues This);

// +++ Set
extern_c void
ValuesStartSet(ConstHandle2Values This, const Integer32 start);


// -----------------------------------------------------------------------------
// Metadatum: length
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ValuesLengthHas(ConstHandle2ConstValues This);

// +++ Get
// +++ Returns by value
extern_c Integer32
ValuesLengthGet(ConstHandle2ConstValues This);

// +++ Set
extern_c void
ValuesLengthSet(ConstHandle2Values This, const Integer32 length);


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ValuesHrefHas(ConstHandle2ConstValues This);

// +++ Get
// +++ Returns by value
extern_c UTF8Text
ValuesHrefGet(ConstHandle2ConstValues This);

// +++ Set
extern_c void
ValuesHrefSet(ConstHandle2Values This, const UTF8Text href);


// -----------------------------------------------------------------------------
// Metadatum: startIndex
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ValuesStartIndexHas(ConstHandle2ConstValues This);

// +++ Get
// +++ Returns by value
extern_c Integer32
ValuesStartIndexGet(ConstHandle2ConstValues This);

// +++ Set
extern_c void
ValuesStartIndexSet(ConstHandle2Values This, const Integer32 startIndex);


// -----------------------------------------------------------------------------
// Metadatum: count
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ValuesCountHas(ConstHandle2ConstValues This);

// +++ Get
// +++ Returns by value
extern_c Integer32
ValuesCountGet(ConstHandle2ConstValues This);

// +++ Set
extern_c void
ValuesCountSet(ConstHandle2Values This, const Integer32 count);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
