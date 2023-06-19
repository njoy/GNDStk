
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
// Array is the basic handle type in this file. Example:
//    // Create a default Array object:
//    Array handle = ArrayDefault();
// Functions involving Array are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_CONTAINERS_ARRAY
#define C_INTERFACE_TEST_V2_0_CONTAINERS_ARRAY

#include "GNDStk.h"
#include "v2.0/containers/Values.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ArrayClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Array
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ArrayClass *Array;

// --- Const-aware handles.
typedef const struct ArrayClass *const ConstHandle2ConstArray;
typedef       struct ArrayClass *const ConstHandle2Array;
typedef const struct ArrayClass *      Handle2ConstArray;
typedef       struct ArrayClass *      Handle2Array;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstArray
ArrayDefaultConst();

// +++ Create, default
extern_c Handle2Array
ArrayDefault();

// --- Create, general, const
extern_c Handle2ConstArray
ArrayCreateConst(
   const IntegerTuple shape,
   const UTF8Text compression,
   const UTF8Text symmetry,
   const UTF8Text permutation,
   const UTF8Text storageOrder,
   const IntegerTuple offset,
   ConstHandle2Values *const values, const size_t valuesSize,
   ConstHandle2Array *const array, const size_t arraySize
);

// +++ Create, general
extern_c Handle2Array
ArrayCreate(
   const IntegerTuple shape,
   const UTF8Text compression,
   const UTF8Text symmetry,
   const UTF8Text permutation,
   const UTF8Text storageOrder,
   const IntegerTuple offset,
   ConstHandle2Values *const values, const size_t valuesSize,
   ConstHandle2Array *const array, const size_t arraySize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ArrayAssign(ConstHandle2Array self, ConstHandle2ConstArray from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ArrayDelete(ConstHandle2ConstArray self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ArrayRead(ConstHandle2Array self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ArrayWrite(ConstHandle2ConstArray self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ArrayPrint(ConstHandle2ConstArray self);

// +++ Print to standard output, as XML
extern_c int
ArrayPrintXML(ConstHandle2ConstArray self);

// +++ Print to standard output, as JSON
extern_c int
ArrayPrintJSON(ConstHandle2ConstArray self);


// -----------------------------------------------------------------------------
// Metadatum: shape
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ArrayShapeHas(ConstHandle2ConstArray self);

// +++ Get
// +++ Returns by value
extern_c IntegerTuple
ArrayShapeGet(ConstHandle2ConstArray self);

// +++ Set
extern_c void
ArrayShapeSet(ConstHandle2Array self, const IntegerTuple shape);


// -----------------------------------------------------------------------------
// Metadatum: compression
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ArrayCompressionHas(ConstHandle2ConstArray self);

// +++ Get
// +++ Returns by value
extern_c UTF8Text
ArrayCompressionGet(ConstHandle2ConstArray self);

// +++ Set
extern_c void
ArrayCompressionSet(ConstHandle2Array self, const UTF8Text compression);


// -----------------------------------------------------------------------------
// Metadatum: symmetry
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ArraySymmetryHas(ConstHandle2ConstArray self);

// +++ Get
// +++ Returns by value
extern_c UTF8Text
ArraySymmetryGet(ConstHandle2ConstArray self);

// +++ Set
extern_c void
ArraySymmetrySet(ConstHandle2Array self, const UTF8Text symmetry);


// -----------------------------------------------------------------------------
// Metadatum: permutation
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ArrayPermutationHas(ConstHandle2ConstArray self);

// +++ Get
// +++ Returns by value
extern_c UTF8Text
ArrayPermutationGet(ConstHandle2ConstArray self);

// +++ Set
extern_c void
ArrayPermutationSet(ConstHandle2Array self, const UTF8Text permutation);


// -----------------------------------------------------------------------------
// Metadatum: storageOrder
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ArrayStorageOrderHas(ConstHandle2ConstArray self);

// +++ Get
// +++ Returns by value
extern_c UTF8Text
ArrayStorageOrderGet(ConstHandle2ConstArray self);

// +++ Set
extern_c void
ArrayStorageOrderSet(ConstHandle2Array self, const UTF8Text storageOrder);


// -----------------------------------------------------------------------------
// Metadatum: offset
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ArrayOffsetHas(ConstHandle2ConstArray self);

// +++ Get
// +++ Returns by value
extern_c IntegerTuple
ArrayOffsetGet(ConstHandle2ConstArray self);

// +++ Set
extern_c void
ArrayOffsetSet(ConstHandle2Array self, const IntegerTuple offset);


// -----------------------------------------------------------------------------
// Child: values
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ArrayValuesHas(ConstHandle2ConstArray self);

// +++ Clear
extern_c void
ArrayValuesClear(ConstHandle2Array self);

// +++ Size
extern_c size_t
ArrayValuesSize(ConstHandle2ConstArray self);

// +++ Add
extern_c void
ArrayValuesAdd(ConstHandle2Array self, ConstHandle2ConstValues values);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstValues
ArrayValuesGetConst(ConstHandle2ConstArray self, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Values
ArrayValuesGet(ConstHandle2Array self, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
ArrayValuesSet(
   ConstHandle2Array self,
   const size_t index_,
   ConstHandle2ConstValues values
);

// +++ Has, by valueType
extern_c int
ArrayValuesHasByValueType(
   ConstHandle2ConstArray self,
   const UTF8Text valueType
);

// --- Get, by valueType, const
extern_c Handle2ConstValues
ArrayValuesGetByValueTypeConst(
   ConstHandle2ConstArray self,
   const UTF8Text valueType
);

// +++ Get, by valueType, non-const
extern_c Handle2Values
ArrayValuesGetByValueType(
   ConstHandle2Array self,
   const UTF8Text valueType
);

// +++ Set, by valueType
extern_c void
ArrayValuesSetByValueType(
   ConstHandle2Array self,
   const UTF8Text valueType,
   ConstHandle2ConstValues values
);

// +++ Has, by start
extern_c int
ArrayValuesHasByStart(
   ConstHandle2ConstArray self,
   const Integer32 start
);

// --- Get, by start, const
extern_c Handle2ConstValues
ArrayValuesGetByStartConst(
   ConstHandle2ConstArray self,
   const Integer32 start
);

// +++ Get, by start, non-const
extern_c Handle2Values
ArrayValuesGetByStart(
   ConstHandle2Array self,
   const Integer32 start
);

// +++ Set, by start
extern_c void
ArrayValuesSetByStart(
   ConstHandle2Array self,
   const Integer32 start,
   ConstHandle2ConstValues values
);

// +++ Has, by length
extern_c int
ArrayValuesHasByLength(
   ConstHandle2ConstArray self,
   const Integer32 length
);

// --- Get, by length, const
extern_c Handle2ConstValues
ArrayValuesGetByLengthConst(
   ConstHandle2ConstArray self,
   const Integer32 length
);

// +++ Get, by length, non-const
extern_c Handle2Values
ArrayValuesGetByLength(
   ConstHandle2Array self,
   const Integer32 length
);

// +++ Set, by length
extern_c void
ArrayValuesSetByLength(
   ConstHandle2Array self,
   const Integer32 length,
   ConstHandle2ConstValues values
);

// +++ Has, by href
extern_c int
ArrayValuesHasByHref(
   ConstHandle2ConstArray self,
   const UTF8Text href
);

// --- Get, by href, const
extern_c Handle2ConstValues
ArrayValuesGetByHrefConst(
   ConstHandle2ConstArray self,
   const UTF8Text href
);

// +++ Get, by href, non-const
extern_c Handle2Values
ArrayValuesGetByHref(
   ConstHandle2Array self,
   const UTF8Text href
);

// +++ Set, by href
extern_c void
ArrayValuesSetByHref(
   ConstHandle2Array self,
   const UTF8Text href,
   ConstHandle2ConstValues values
);

// +++ Has, by startIndex
extern_c int
ArrayValuesHasByStartIndex(
   ConstHandle2ConstArray self,
   const Integer32 startIndex
);

// --- Get, by startIndex, const
extern_c Handle2ConstValues
ArrayValuesGetByStartIndexConst(
   ConstHandle2ConstArray self,
   const Integer32 startIndex
);

// +++ Get, by startIndex, non-const
extern_c Handle2Values
ArrayValuesGetByStartIndex(
   ConstHandle2Array self,
   const Integer32 startIndex
);

// +++ Set, by startIndex
extern_c void
ArrayValuesSetByStartIndex(
   ConstHandle2Array self,
   const Integer32 startIndex,
   ConstHandle2ConstValues values
);

// +++ Has, by count
extern_c int
ArrayValuesHasByCount(
   ConstHandle2ConstArray self,
   const Integer32 count
);

// --- Get, by count, const
extern_c Handle2ConstValues
ArrayValuesGetByCountConst(
   ConstHandle2ConstArray self,
   const Integer32 count
);

// +++ Get, by count, non-const
extern_c Handle2Values
ArrayValuesGetByCount(
   ConstHandle2Array self,
   const Integer32 count
);

// +++ Set, by count
extern_c void
ArrayValuesSetByCount(
   ConstHandle2Array self,
   const Integer32 count,
   ConstHandle2ConstValues values
);


// -----------------------------------------------------------------------------
// Child: array
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ArrayArrayHas(ConstHandle2ConstArray self);

// +++ Clear
extern_c void
ArrayArrayClear(ConstHandle2Array self);

// +++ Size
extern_c size_t
ArrayArraySize(ConstHandle2ConstArray self);

// +++ Add
extern_c void
ArrayArrayAdd(ConstHandle2Array self, ConstHandle2ConstArray array);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstArray
ArrayArrayGetConst(ConstHandle2ConstArray self, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Array
ArrayArrayGet(ConstHandle2Array self, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
ArrayArraySet(
   ConstHandle2Array self,
   const size_t index_,
   ConstHandle2ConstArray array
);

// +++ Has, by shape
extern_c int
ArrayArrayHasByShape(
   ConstHandle2ConstArray self,
   const IntegerTuple shape
);

// --- Get, by shape, const
extern_c Handle2ConstArray
ArrayArrayGetByShapeConst(
   ConstHandle2ConstArray self,
   const IntegerTuple shape
);

// +++ Get, by shape, non-const
extern_c Handle2Array
ArrayArrayGetByShape(
   ConstHandle2Array self,
   const IntegerTuple shape
);

// +++ Set, by shape
extern_c void
ArrayArraySetByShape(
   ConstHandle2Array self,
   const IntegerTuple shape,
   ConstHandle2ConstArray array
);

// +++ Has, by compression
extern_c int
ArrayArrayHasByCompression(
   ConstHandle2ConstArray self,
   const UTF8Text compression
);

// --- Get, by compression, const
extern_c Handle2ConstArray
ArrayArrayGetByCompressionConst(
   ConstHandle2ConstArray self,
   const UTF8Text compression
);

// +++ Get, by compression, non-const
extern_c Handle2Array
ArrayArrayGetByCompression(
   ConstHandle2Array self,
   const UTF8Text compression
);

// +++ Set, by compression
extern_c void
ArrayArraySetByCompression(
   ConstHandle2Array self,
   const UTF8Text compression,
   ConstHandle2ConstArray array
);

// +++ Has, by symmetry
extern_c int
ArrayArrayHasBySymmetry(
   ConstHandle2ConstArray self,
   const UTF8Text symmetry
);

// --- Get, by symmetry, const
extern_c Handle2ConstArray
ArrayArrayGetBySymmetryConst(
   ConstHandle2ConstArray self,
   const UTF8Text symmetry
);

// +++ Get, by symmetry, non-const
extern_c Handle2Array
ArrayArrayGetBySymmetry(
   ConstHandle2Array self,
   const UTF8Text symmetry
);

// +++ Set, by symmetry
extern_c void
ArrayArraySetBySymmetry(
   ConstHandle2Array self,
   const UTF8Text symmetry,
   ConstHandle2ConstArray array
);

// +++ Has, by permutation
extern_c int
ArrayArrayHasByPermutation(
   ConstHandle2ConstArray self,
   const UTF8Text permutation
);

// --- Get, by permutation, const
extern_c Handle2ConstArray
ArrayArrayGetByPermutationConst(
   ConstHandle2ConstArray self,
   const UTF8Text permutation
);

// +++ Get, by permutation, non-const
extern_c Handle2Array
ArrayArrayGetByPermutation(
   ConstHandle2Array self,
   const UTF8Text permutation
);

// +++ Set, by permutation
extern_c void
ArrayArraySetByPermutation(
   ConstHandle2Array self,
   const UTF8Text permutation,
   ConstHandle2ConstArray array
);

// +++ Has, by storageOrder
extern_c int
ArrayArrayHasByStorageOrder(
   ConstHandle2ConstArray self,
   const UTF8Text storageOrder
);

// --- Get, by storageOrder, const
extern_c Handle2ConstArray
ArrayArrayGetByStorageOrderConst(
   ConstHandle2ConstArray self,
   const UTF8Text storageOrder
);

// +++ Get, by storageOrder, non-const
extern_c Handle2Array
ArrayArrayGetByStorageOrder(
   ConstHandle2Array self,
   const UTF8Text storageOrder
);

// +++ Set, by storageOrder
extern_c void
ArrayArraySetByStorageOrder(
   ConstHandle2Array self,
   const UTF8Text storageOrder,
   ConstHandle2ConstArray array
);

// +++ Has, by offset
extern_c int
ArrayArrayHasByOffset(
   ConstHandle2ConstArray self,
   const IntegerTuple offset
);

// --- Get, by offset, const
extern_c Handle2ConstArray
ArrayArrayGetByOffsetConst(
   ConstHandle2ConstArray self,
   const IntegerTuple offset
);

// +++ Get, by offset, non-const
extern_c Handle2Array
ArrayArrayGetByOffset(
   ConstHandle2Array self,
   const IntegerTuple offset
);

// +++ Set, by offset
extern_c void
ArrayArraySetByOffset(
   ConstHandle2Array self,
   const IntegerTuple offset,
   ConstHandle2ConstArray array
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/containers/Array/src/custom.h"

#undef extern_c
#endif
