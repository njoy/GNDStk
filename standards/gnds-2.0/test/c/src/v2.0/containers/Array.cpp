
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/containers/Array.hpp"
#include "Array.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = ArrayClass;
using CPP = multigroup::Array;

static const std::string CLASSNAME = "Array";

namespace extract {
   static auto shape = [](auto &obj) { return &obj.shape; };
   static auto compression = [](auto &obj) { return &obj.compression; };
   static auto symmetry = [](auto &obj) { return &obj.symmetry; };
   static auto permutation = [](auto &obj) { return &obj.permutation; };
   static auto storageOrder = [](auto &obj) { return &obj.storageOrder; };
   static auto offset = [](auto &obj) { return &obj.offset; };
   static auto values = [](auto &obj) { return &obj.values; };
   static auto array = [](auto &obj) { return &obj.array; };
}

using CPPValues = containers::Values;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstArray
ArrayDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Array
ArrayDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstArray
ArrayCreateConst(
   const IntegerTuple shape,
   const UTF8Text compression,
   const UTF8Text symmetry,
   const UTF8Text permutation,
   const UTF8Text storageOrder,
   const IntegerTuple offset,
   ConstHandle2Values *const values, const size_t valuesSize,
   ConstHandle2Array *const array, const size_t arraySize
) {
   ConstHandle2Array handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      shape,
      compression,
      symmetry,
      permutation,
      storageOrder,
      offset,
      std::vector<CPPValues>{},
      std::vector<CPPArray>{}
   );
   for (size_t ValuesN = 0; ValuesN < valuesSize; ++ValuesN)
      ArrayValuesAdd(handle, values[ValuesN]);
   for (size_t ArrayN = 0; ArrayN < arraySize; ++ArrayN)
      ArrayArrayAdd(handle, array[ArrayN]);
   return handle;
}

// Create, general
Handle2Array
ArrayCreate(
   const IntegerTuple shape,
   const UTF8Text compression,
   const UTF8Text symmetry,
   const UTF8Text permutation,
   const UTF8Text storageOrder,
   const IntegerTuple offset,
   ConstHandle2Values *const values, const size_t valuesSize,
   ConstHandle2Array *const array, const size_t arraySize
) {
   ConstHandle2Array handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      shape,
      compression,
      symmetry,
      permutation,
      storageOrder,
      offset,
      std::vector<CPPValues>{},
      std::vector<CPPArray>{}
   );
   for (size_t ValuesN = 0; ValuesN < valuesSize; ++ValuesN)
      ArrayValuesAdd(handle, values[ValuesN]);
   for (size_t ArrayN = 0; ArrayN < arraySize; ++ArrayN)
      ArrayArrayAdd(handle, array[ArrayN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ArrayAssign(ConstHandle2Array This, ConstHandle2ConstArray from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ArrayDelete(ConstHandle2ConstArray This)
{
   detail::deleteHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Delete", This);
}


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// Read from file
// File can be XML, JSON, or HDF5.
// We'll examine the file's contents to determine its type automatically.
int
ArrayRead(ConstHandle2Array This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ArrayWrite(ConstHandle2ConstArray This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
ArrayPrint(ConstHandle2ConstArray This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
ArrayPrintXML(ConstHandle2ConstArray This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
ArrayPrintJSON(ConstHandle2ConstArray This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: shape
// -----------------------------------------------------------------------------

// Has
int
ArrayShapeHas(ConstHandle2ConstArray This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ShapeHas", This, extract::shape);
}

// Get
// Returns by value
IntegerTuple
ArrayShapeGet(ConstHandle2ConstArray This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ShapeGet", This, extract::shape);
}

// Set
void
ArrayShapeSet(ConstHandle2Array This, const IntegerTuple shape)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ShapeSet", This, extract::shape, shape);
}


// -----------------------------------------------------------------------------
// Metadatum: compression
// -----------------------------------------------------------------------------

// Has
int
ArrayCompressionHas(ConstHandle2ConstArray This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CompressionHas", This, extract::compression);
}

// Get
// Returns by value
UTF8Text
ArrayCompressionGet(ConstHandle2ConstArray This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"CompressionGet", This, extract::compression);
}

// Set
void
ArrayCompressionSet(ConstHandle2Array This, const UTF8Text compression)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"CompressionSet", This, extract::compression, compression);
}


// -----------------------------------------------------------------------------
// Metadatum: symmetry
// -----------------------------------------------------------------------------

// Has
int
ArraySymmetryHas(ConstHandle2ConstArray This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SymmetryHas", This, extract::symmetry);
}

// Get
// Returns by value
UTF8Text
ArraySymmetryGet(ConstHandle2ConstArray This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"SymmetryGet", This, extract::symmetry);
}

// Set
void
ArraySymmetrySet(ConstHandle2Array This, const UTF8Text symmetry)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"SymmetrySet", This, extract::symmetry, symmetry);
}


// -----------------------------------------------------------------------------
// Metadatum: permutation
// -----------------------------------------------------------------------------

// Has
int
ArrayPermutationHas(ConstHandle2ConstArray This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"PermutationHas", This, extract::permutation);
}

// Get
// Returns by value
UTF8Text
ArrayPermutationGet(ConstHandle2ConstArray This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"PermutationGet", This, extract::permutation);
}

// Set
void
ArrayPermutationSet(ConstHandle2Array This, const UTF8Text permutation)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"PermutationSet", This, extract::permutation, permutation);
}


// -----------------------------------------------------------------------------
// Metadatum: storageOrder
// -----------------------------------------------------------------------------

// Has
int
ArrayStorageOrderHas(ConstHandle2ConstArray This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"StorageOrderHas", This, extract::storageOrder);
}

// Get
// Returns by value
UTF8Text
ArrayStorageOrderGet(ConstHandle2ConstArray This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"StorageOrderGet", This, extract::storageOrder);
}

// Set
void
ArrayStorageOrderSet(ConstHandle2Array This, const UTF8Text storageOrder)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"StorageOrderSet", This, extract::storageOrder, storageOrder);
}


// -----------------------------------------------------------------------------
// Metadatum: offset
// -----------------------------------------------------------------------------

// Has
int
ArrayOffsetHas(ConstHandle2ConstArray This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"OffsetHas", This, extract::offset);
}

// Get
// Returns by value
IntegerTuple
ArrayOffsetGet(ConstHandle2ConstArray This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"OffsetGet", This, extract::offset);
}

// Set
void
ArrayOffsetSet(ConstHandle2Array This, const IntegerTuple offset)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"OffsetSet", This, extract::offset, offset);
}


// -----------------------------------------------------------------------------
// Child: values
// -----------------------------------------------------------------------------

// Has
int
ArrayValuesHas(ConstHandle2ConstArray This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ValuesHas", This, extract::values);
}

// Clear
void
ArrayValuesClear(ConstHandle2Array This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"ValuesClear", This, extract::values);
}

// Size
size_t
ArrayValuesSize(ConstHandle2ConstArray This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"ValuesSize", This, extract::values);
}

// Add
void
ArrayValuesAdd(ConstHandle2Array This, ConstHandle2ConstValues values)
{
   detail::addToContainer<CPP,CPPValues>
      (CLASSNAME, CLASSNAME+"ValuesAdd", This, extract::values, values);
}

// Get, by index \in [0,size), const
Handle2ConstValues
ArrayValuesGetConst(ConstHandle2ConstArray This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstValues>
      (CLASSNAME, CLASSNAME+"ValuesGetConst", This, extract::values, index_);
}

// Get, by index \in [0,size), non-const
Handle2Values
ArrayValuesGet(ConstHandle2Array This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Values>
      (CLASSNAME, CLASSNAME+"ValuesGet", This, extract::values, index_);
}

// Set, by index \in [0,size)
void
ArrayValuesSet(
   ConstHandle2Array This,
   const size_t index_,
   ConstHandle2ConstValues values
) {
   detail::setByIndex<CPP,CPPValues>
      (CLASSNAME, CLASSNAME+"ValuesSet", This, extract::values, index_, values);
}

// Has, by valueType
int
ArrayValuesHasByValueType(
   ConstHandle2ConstArray This,
   const UTF8Text valueType
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ValuesHasByValueType",
       This, extract::values, meta::valueType, valueType);
}

// Get, by valueType, const
Handle2ConstValues
ArrayValuesGetByValueTypeConst(
   ConstHandle2ConstArray This,
   const UTF8Text valueType
) {
   return detail::getByMetadatum<CPP,Handle2ConstValues>
      (CLASSNAME, CLASSNAME+"ValuesGetByValueTypeConst",
       This, extract::values, meta::valueType, valueType);
}

// Get, by valueType, non-const
Handle2Values
ArrayValuesGetByValueType(
   ConstHandle2Array This,
   const UTF8Text valueType
) {
   return detail::getByMetadatum<CPP,Handle2Values>
      (CLASSNAME, CLASSNAME+"ValuesGetByValueType",
       This, extract::values, meta::valueType, valueType);
}

// Set, by valueType
void
ArrayValuesSetByValueType(
   ConstHandle2Array This,
   const UTF8Text valueType,
   ConstHandle2ConstValues values
) {
   detail::setByMetadatum<CPP,CPPValues>
      (CLASSNAME, CLASSNAME+"ValuesSetByValueType",
       This, extract::values, meta::valueType, valueType, values);
}

// Has, by start
int
ArrayValuesHasByStart(
   ConstHandle2ConstArray This,
   const Integer32 start
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ValuesHasByStart",
       This, extract::values, meta::start, start);
}

// Get, by start, const
Handle2ConstValues
ArrayValuesGetByStartConst(
   ConstHandle2ConstArray This,
   const Integer32 start
) {
   return detail::getByMetadatum<CPP,Handle2ConstValues>
      (CLASSNAME, CLASSNAME+"ValuesGetByStartConst",
       This, extract::values, meta::start, start);
}

// Get, by start, non-const
Handle2Values
ArrayValuesGetByStart(
   ConstHandle2Array This,
   const Integer32 start
) {
   return detail::getByMetadatum<CPP,Handle2Values>
      (CLASSNAME, CLASSNAME+"ValuesGetByStart",
       This, extract::values, meta::start, start);
}

// Set, by start
void
ArrayValuesSetByStart(
   ConstHandle2Array This,
   const Integer32 start,
   ConstHandle2ConstValues values
) {
   detail::setByMetadatum<CPP,CPPValues>
      (CLASSNAME, CLASSNAME+"ValuesSetByStart",
       This, extract::values, meta::start, start, values);
}

// Has, by length
int
ArrayValuesHasByLength(
   ConstHandle2ConstArray This,
   const Integer32 length
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ValuesHasByLength",
       This, extract::values, meta::length, length);
}

// Get, by length, const
Handle2ConstValues
ArrayValuesGetByLengthConst(
   ConstHandle2ConstArray This,
   const Integer32 length
) {
   return detail::getByMetadatum<CPP,Handle2ConstValues>
      (CLASSNAME, CLASSNAME+"ValuesGetByLengthConst",
       This, extract::values, meta::length, length);
}

// Get, by length, non-const
Handle2Values
ArrayValuesGetByLength(
   ConstHandle2Array This,
   const Integer32 length
) {
   return detail::getByMetadatum<CPP,Handle2Values>
      (CLASSNAME, CLASSNAME+"ValuesGetByLength",
       This, extract::values, meta::length, length);
}

// Set, by length
void
ArrayValuesSetByLength(
   ConstHandle2Array This,
   const Integer32 length,
   ConstHandle2ConstValues values
) {
   detail::setByMetadatum<CPP,CPPValues>
      (CLASSNAME, CLASSNAME+"ValuesSetByLength",
       This, extract::values, meta::length, length, values);
}

// Has, by href
int
ArrayValuesHasByHref(
   ConstHandle2ConstArray This,
   const UTF8Text href
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ValuesHasByHref",
       This, extract::values, meta::href, href);
}

// Get, by href, const
Handle2ConstValues
ArrayValuesGetByHrefConst(
   ConstHandle2ConstArray This,
   const UTF8Text href
) {
   return detail::getByMetadatum<CPP,Handle2ConstValues>
      (CLASSNAME, CLASSNAME+"ValuesGetByHrefConst",
       This, extract::values, meta::href, href);
}

// Get, by href, non-const
Handle2Values
ArrayValuesGetByHref(
   ConstHandle2Array This,
   const UTF8Text href
) {
   return detail::getByMetadatum<CPP,Handle2Values>
      (CLASSNAME, CLASSNAME+"ValuesGetByHref",
       This, extract::values, meta::href, href);
}

// Set, by href
void
ArrayValuesSetByHref(
   ConstHandle2Array This,
   const UTF8Text href,
   ConstHandle2ConstValues values
) {
   detail::setByMetadatum<CPP,CPPValues>
      (CLASSNAME, CLASSNAME+"ValuesSetByHref",
       This, extract::values, meta::href, href, values);
}

// Has, by startIndex
int
ArrayValuesHasByStartIndex(
   ConstHandle2ConstArray This,
   const Integer32 startIndex
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ValuesHasByStartIndex",
       This, extract::values, meta::startIndex, startIndex);
}

// Get, by startIndex, const
Handle2ConstValues
ArrayValuesGetByStartIndexConst(
   ConstHandle2ConstArray This,
   const Integer32 startIndex
) {
   return detail::getByMetadatum<CPP,Handle2ConstValues>
      (CLASSNAME, CLASSNAME+"ValuesGetByStartIndexConst",
       This, extract::values, meta::startIndex, startIndex);
}

// Get, by startIndex, non-const
Handle2Values
ArrayValuesGetByStartIndex(
   ConstHandle2Array This,
   const Integer32 startIndex
) {
   return detail::getByMetadatum<CPP,Handle2Values>
      (CLASSNAME, CLASSNAME+"ValuesGetByStartIndex",
       This, extract::values, meta::startIndex, startIndex);
}

// Set, by startIndex
void
ArrayValuesSetByStartIndex(
   ConstHandle2Array This,
   const Integer32 startIndex,
   ConstHandle2ConstValues values
) {
   detail::setByMetadatum<CPP,CPPValues>
      (CLASSNAME, CLASSNAME+"ValuesSetByStartIndex",
       This, extract::values, meta::startIndex, startIndex, values);
}

// Has, by count
int
ArrayValuesHasByCount(
   ConstHandle2ConstArray This,
   const Integer32 count
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ValuesHasByCount",
       This, extract::values, meta::count, count);
}

// Get, by count, const
Handle2ConstValues
ArrayValuesGetByCountConst(
   ConstHandle2ConstArray This,
   const Integer32 count
) {
   return detail::getByMetadatum<CPP,Handle2ConstValues>
      (CLASSNAME, CLASSNAME+"ValuesGetByCountConst",
       This, extract::values, meta::count, count);
}

// Get, by count, non-const
Handle2Values
ArrayValuesGetByCount(
   ConstHandle2Array This,
   const Integer32 count
) {
   return detail::getByMetadatum<CPP,Handle2Values>
      (CLASSNAME, CLASSNAME+"ValuesGetByCount",
       This, extract::values, meta::count, count);
}

// Set, by count
void
ArrayValuesSetByCount(
   ConstHandle2Array This,
   const Integer32 count,
   ConstHandle2ConstValues values
) {
   detail::setByMetadatum<CPP,CPPValues>
      (CLASSNAME, CLASSNAME+"ValuesSetByCount",
       This, extract::values, meta::count, count, values);
}


// -----------------------------------------------------------------------------
// Child: array
// -----------------------------------------------------------------------------

// Has
int
ArrayArrayHas(ConstHandle2ConstArray This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ArrayHas", This, extract::array);
}

// Clear
void
ArrayArrayClear(ConstHandle2Array This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"ArrayClear", This, extract::array);
}

// Size
size_t
ArrayArraySize(ConstHandle2ConstArray This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"ArraySize", This, extract::array);
}

// Add
void
ArrayArrayAdd(ConstHandle2Array This, ConstHandle2ConstArray array)
{
   detail::addToContainer<CPP,CPPArray>
      (CLASSNAME, CLASSNAME+"ArrayAdd", This, extract::array, array);
}

// Get, by index \in [0,size), const
Handle2ConstArray
ArrayArrayGetConst(ConstHandle2ConstArray This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstArray>
      (CLASSNAME, CLASSNAME+"ArrayGetConst", This, extract::array, index_);
}

// Get, by index \in [0,size), non-const
Handle2Array
ArrayArrayGet(ConstHandle2Array This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Array>
      (CLASSNAME, CLASSNAME+"ArrayGet", This, extract::array, index_);
}

// Set, by index \in [0,size)
void
ArrayArraySet(
   ConstHandle2Array This,
   const size_t index_,
   ConstHandle2ConstArray array
) {
   detail::setByIndex<CPP,CPPArray>
      (CLASSNAME, CLASSNAME+"ArraySet", This, extract::array, index_, array);
}

// Has, by shape
int
ArrayArrayHasByShape(
   ConstHandle2ConstArray This,
   const IntegerTuple shape
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ArrayHasByShape",
       This, extract::array, meta::shape, shape);
}

// Get, by shape, const
Handle2ConstArray
ArrayArrayGetByShapeConst(
   ConstHandle2ConstArray This,
   const IntegerTuple shape
) {
   return detail::getByMetadatum<CPP,Handle2ConstArray>
      (CLASSNAME, CLASSNAME+"ArrayGetByShapeConst",
       This, extract::array, meta::shape, shape);
}

// Get, by shape, non-const
Handle2Array
ArrayArrayGetByShape(
   ConstHandle2Array This,
   const IntegerTuple shape
) {
   return detail::getByMetadatum<CPP,Handle2Array>
      (CLASSNAME, CLASSNAME+"ArrayGetByShape",
       This, extract::array, meta::shape, shape);
}

// Set, by shape
void
ArrayArraySetByShape(
   ConstHandle2Array This,
   const IntegerTuple shape,
   ConstHandle2ConstArray array
) {
   detail::setByMetadatum<CPP,CPPArray>
      (CLASSNAME, CLASSNAME+"ArraySetByShape",
       This, extract::array, meta::shape, shape, array);
}

// Has, by compression
int
ArrayArrayHasByCompression(
   ConstHandle2ConstArray This,
   const UTF8Text compression
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ArrayHasByCompression",
       This, extract::array, meta::compression, compression);
}

// Get, by compression, const
Handle2ConstArray
ArrayArrayGetByCompressionConst(
   ConstHandle2ConstArray This,
   const UTF8Text compression
) {
   return detail::getByMetadatum<CPP,Handle2ConstArray>
      (CLASSNAME, CLASSNAME+"ArrayGetByCompressionConst",
       This, extract::array, meta::compression, compression);
}

// Get, by compression, non-const
Handle2Array
ArrayArrayGetByCompression(
   ConstHandle2Array This,
   const UTF8Text compression
) {
   return detail::getByMetadatum<CPP,Handle2Array>
      (CLASSNAME, CLASSNAME+"ArrayGetByCompression",
       This, extract::array, meta::compression, compression);
}

// Set, by compression
void
ArrayArraySetByCompression(
   ConstHandle2Array This,
   const UTF8Text compression,
   ConstHandle2ConstArray array
) {
   detail::setByMetadatum<CPP,CPPArray>
      (CLASSNAME, CLASSNAME+"ArraySetByCompression",
       This, extract::array, meta::compression, compression, array);
}

// Has, by symmetry
int
ArrayArrayHasBySymmetry(
   ConstHandle2ConstArray This,
   const UTF8Text symmetry
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ArrayHasBySymmetry",
       This, extract::array, meta::symmetry, symmetry);
}

// Get, by symmetry, const
Handle2ConstArray
ArrayArrayGetBySymmetryConst(
   ConstHandle2ConstArray This,
   const UTF8Text symmetry
) {
   return detail::getByMetadatum<CPP,Handle2ConstArray>
      (CLASSNAME, CLASSNAME+"ArrayGetBySymmetryConst",
       This, extract::array, meta::symmetry, symmetry);
}

// Get, by symmetry, non-const
Handle2Array
ArrayArrayGetBySymmetry(
   ConstHandle2Array This,
   const UTF8Text symmetry
) {
   return detail::getByMetadatum<CPP,Handle2Array>
      (CLASSNAME, CLASSNAME+"ArrayGetBySymmetry",
       This, extract::array, meta::symmetry, symmetry);
}

// Set, by symmetry
void
ArrayArraySetBySymmetry(
   ConstHandle2Array This,
   const UTF8Text symmetry,
   ConstHandle2ConstArray array
) {
   detail::setByMetadatum<CPP,CPPArray>
      (CLASSNAME, CLASSNAME+"ArraySetBySymmetry",
       This, extract::array, meta::symmetry, symmetry, array);
}

// Has, by permutation
int
ArrayArrayHasByPermutation(
   ConstHandle2ConstArray This,
   const UTF8Text permutation
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ArrayHasByPermutation",
       This, extract::array, meta::permutation, permutation);
}

// Get, by permutation, const
Handle2ConstArray
ArrayArrayGetByPermutationConst(
   ConstHandle2ConstArray This,
   const UTF8Text permutation
) {
   return detail::getByMetadatum<CPP,Handle2ConstArray>
      (CLASSNAME, CLASSNAME+"ArrayGetByPermutationConst",
       This, extract::array, meta::permutation, permutation);
}

// Get, by permutation, non-const
Handle2Array
ArrayArrayGetByPermutation(
   ConstHandle2Array This,
   const UTF8Text permutation
) {
   return detail::getByMetadatum<CPP,Handle2Array>
      (CLASSNAME, CLASSNAME+"ArrayGetByPermutation",
       This, extract::array, meta::permutation, permutation);
}

// Set, by permutation
void
ArrayArraySetByPermutation(
   ConstHandle2Array This,
   const UTF8Text permutation,
   ConstHandle2ConstArray array
) {
   detail::setByMetadatum<CPP,CPPArray>
      (CLASSNAME, CLASSNAME+"ArraySetByPermutation",
       This, extract::array, meta::permutation, permutation, array);
}

// Has, by storageOrder
int
ArrayArrayHasByStorageOrder(
   ConstHandle2ConstArray This,
   const UTF8Text storageOrder
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ArrayHasByStorageOrder",
       This, extract::array, meta::storageOrder, storageOrder);
}

// Get, by storageOrder, const
Handle2ConstArray
ArrayArrayGetByStorageOrderConst(
   ConstHandle2ConstArray This,
   const UTF8Text storageOrder
) {
   return detail::getByMetadatum<CPP,Handle2ConstArray>
      (CLASSNAME, CLASSNAME+"ArrayGetByStorageOrderConst",
       This, extract::array, meta::storageOrder, storageOrder);
}

// Get, by storageOrder, non-const
Handle2Array
ArrayArrayGetByStorageOrder(
   ConstHandle2Array This,
   const UTF8Text storageOrder
) {
   return detail::getByMetadatum<CPP,Handle2Array>
      (CLASSNAME, CLASSNAME+"ArrayGetByStorageOrder",
       This, extract::array, meta::storageOrder, storageOrder);
}

// Set, by storageOrder
void
ArrayArraySetByStorageOrder(
   ConstHandle2Array This,
   const UTF8Text storageOrder,
   ConstHandle2ConstArray array
) {
   detail::setByMetadatum<CPP,CPPArray>
      (CLASSNAME, CLASSNAME+"ArraySetByStorageOrder",
       This, extract::array, meta::storageOrder, storageOrder, array);
}

// Has, by offset
int
ArrayArrayHasByOffset(
   ConstHandle2ConstArray This,
   const IntegerTuple offset
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ArrayHasByOffset",
       This, extract::array, meta::offset, offset);
}

// Get, by offset, const
Handle2ConstArray
ArrayArrayGetByOffsetConst(
   ConstHandle2ConstArray This,
   const IntegerTuple offset
) {
   return detail::getByMetadatum<CPP,Handle2ConstArray>
      (CLASSNAME, CLASSNAME+"ArrayGetByOffsetConst",
       This, extract::array, meta::offset, offset);
}

// Get, by offset, non-const
Handle2Array
ArrayArrayGetByOffset(
   ConstHandle2Array This,
   const IntegerTuple offset
) {
   return detail::getByMetadatum<CPP,Handle2Array>
      (CLASSNAME, CLASSNAME+"ArrayGetByOffset",
       This, extract::array, meta::offset, offset);
}

// Set, by offset
void
ArrayArraySetByOffset(
   ConstHandle2Array This,
   const IntegerTuple offset,
   ConstHandle2ConstArray array
) {
   detail::setByMetadatum<CPP,CPPArray>
      (CLASSNAME, CLASSNAME+"ArraySetByOffset",
       This, extract::array, meta::offset, offset, array);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/containers/Array/src/custom.cpp"
