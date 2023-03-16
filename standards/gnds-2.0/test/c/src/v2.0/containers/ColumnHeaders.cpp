
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/containers/ColumnHeaders.hpp"
#include "ColumnHeaders.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = ColumnHeadersClass;
using CPP = multigroup::ColumnHeaders;

static const std::string CLASSNAME = "ColumnHeaders";

namespace extract {
   static auto column = [](auto &obj) { return &obj.column; };
}

using CPPColumn = containers::Column;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstColumnHeaders
ColumnHeadersDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2ColumnHeaders
ColumnHeadersDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstColumnHeaders
ColumnHeadersCreateConst(
   ConstHandle2Column *const column, const size_t columnSize
) {
   ConstHandle2ColumnHeaders handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPColumn>{}
   );
   for (size_t ColumnN = 0; ColumnN < columnSize; ++ColumnN)
      ColumnHeadersColumnAdd(handle, column[ColumnN]);
   return handle;
}

// Create, general
Handle2ColumnHeaders
ColumnHeadersCreate(
   ConstHandle2Column *const column, const size_t columnSize
) {
   ConstHandle2ColumnHeaders handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPColumn>{}
   );
   for (size_t ColumnN = 0; ColumnN < columnSize; ++ColumnN)
      ColumnHeadersColumnAdd(handle, column[ColumnN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ColumnHeadersAssign(ConstHandle2ColumnHeaders self, ConstHandle2ConstColumnHeaders from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ColumnHeadersDelete(ConstHandle2ConstColumnHeaders self)
{
   detail::deleteHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Delete", self);
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
ColumnHeadersRead(ConstHandle2ColumnHeaders self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ColumnHeadersWrite(ConstHandle2ConstColumnHeaders self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ColumnHeadersPrint(ConstHandle2ConstColumnHeaders self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ColumnHeadersPrintXML(ConstHandle2ConstColumnHeaders self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ColumnHeadersPrintJSON(ConstHandle2ConstColumnHeaders self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: column
// -----------------------------------------------------------------------------

// Has
int
ColumnHeadersColumnHas(ConstHandle2ConstColumnHeaders self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ColumnHas", self, extract::column);
}

// Clear
void
ColumnHeadersColumnClear(ConstHandle2ColumnHeaders self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"ColumnClear", self, extract::column);
}

// Size
size_t
ColumnHeadersColumnSize(ConstHandle2ConstColumnHeaders self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"ColumnSize", self, extract::column);
}

// Add
void
ColumnHeadersColumnAdd(ConstHandle2ColumnHeaders self, ConstHandle2ConstColumn column)
{
   detail::addToContainer<CPP,CPPColumn>
      (CLASSNAME, CLASSNAME+"ColumnAdd", self, extract::column, column);
}

// Get, by index \in [0,size), const
Handle2ConstColumn
ColumnHeadersColumnGetConst(ConstHandle2ConstColumnHeaders self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstColumn>
      (CLASSNAME, CLASSNAME+"ColumnGetConst", self, extract::column, index_);
}

// Get, by index \in [0,size), non-const
Handle2Column
ColumnHeadersColumnGet(ConstHandle2ColumnHeaders self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Column>
      (CLASSNAME, CLASSNAME+"ColumnGet", self, extract::column, index_);
}

// Set, by index \in [0,size)
void
ColumnHeadersColumnSet(
   ConstHandle2ColumnHeaders self,
   const size_t index_,
   ConstHandle2ConstColumn column
) {
   detail::setByIndex<CPP,CPPColumn>
      (CLASSNAME, CLASSNAME+"ColumnSet", self, extract::column, index_, column);
}

// Has, by index
int
ColumnHeadersColumnHasByIndex(
   ConstHandle2ConstColumnHeaders self,
   const Integer32 index
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ColumnHasByIndex",
       self, extract::column, meta::index, index);
}

// Get, by index, const
Handle2ConstColumn
ColumnHeadersColumnGetByIndexConst(
   ConstHandle2ConstColumnHeaders self,
   const Integer32 index
) {
   return detail::getByMetadatum<CPP,Handle2ConstColumn>
      (CLASSNAME, CLASSNAME+"ColumnGetByIndexConst",
       self, extract::column, meta::index, index);
}

// Get, by index, non-const
Handle2Column
ColumnHeadersColumnGetByIndex(
   ConstHandle2ColumnHeaders self,
   const Integer32 index
) {
   return detail::getByMetadatum<CPP,Handle2Column>
      (CLASSNAME, CLASSNAME+"ColumnGetByIndex",
       self, extract::column, meta::index, index);
}

// Set, by index
void
ColumnHeadersColumnSetByIndex(
   ConstHandle2ColumnHeaders self,
   const Integer32 index,
   ConstHandle2ConstColumn column
) {
   detail::setByMetadatum<CPP,CPPColumn>
      (CLASSNAME, CLASSNAME+"ColumnSetByIndex",
       self, extract::column, meta::index, index, column);
}

// Has, by name
int
ColumnHeadersColumnHasByName(
   ConstHandle2ConstColumnHeaders self,
   const XMLName name
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ColumnHasByName",
       self, extract::column, meta::name, name);
}

// Get, by name, const
Handle2ConstColumn
ColumnHeadersColumnGetByNameConst(
   ConstHandle2ConstColumnHeaders self,
   const XMLName name
) {
   return detail::getByMetadatum<CPP,Handle2ConstColumn>
      (CLASSNAME, CLASSNAME+"ColumnGetByNameConst",
       self, extract::column, meta::name, name);
}

// Get, by name, non-const
Handle2Column
ColumnHeadersColumnGetByName(
   ConstHandle2ColumnHeaders self,
   const XMLName name
) {
   return detail::getByMetadatum<CPP,Handle2Column>
      (CLASSNAME, CLASSNAME+"ColumnGetByName",
       self, extract::column, meta::name, name);
}

// Set, by name
void
ColumnHeadersColumnSetByName(
   ConstHandle2ColumnHeaders self,
   const XMLName name,
   ConstHandle2ConstColumn column
) {
   detail::setByMetadatum<CPP,CPPColumn>
      (CLASSNAME, CLASSNAME+"ColumnSetByName",
       self, extract::column, meta::name, name, column);
}

// Has, by unit
int
ColumnHeadersColumnHasByUnit(
   ConstHandle2ConstColumnHeaders self,
   const XMLName unit
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ColumnHasByUnit",
       self, extract::column, meta::unit, unit);
}

// Get, by unit, const
Handle2ConstColumn
ColumnHeadersColumnGetByUnitConst(
   ConstHandle2ConstColumnHeaders self,
   const XMLName unit
) {
   return detail::getByMetadatum<CPP,Handle2ConstColumn>
      (CLASSNAME, CLASSNAME+"ColumnGetByUnitConst",
       self, extract::column, meta::unit, unit);
}

// Get, by unit, non-const
Handle2Column
ColumnHeadersColumnGetByUnit(
   ConstHandle2ColumnHeaders self,
   const XMLName unit
) {
   return detail::getByMetadatum<CPP,Handle2Column>
      (CLASSNAME, CLASSNAME+"ColumnGetByUnit",
       self, extract::column, meta::unit, unit);
}

// Set, by unit
void
ColumnHeadersColumnSetByUnit(
   ConstHandle2ColumnHeaders self,
   const XMLName unit,
   ConstHandle2ConstColumn column
) {
   detail::setByMetadatum<CPP,CPPColumn>
      (CLASSNAME, CLASSNAME+"ColumnSetByUnit",
       self, extract::column, meta::unit, unit, column);
}

// Has, by types
int
ColumnHeadersColumnHasByTypes(
   ConstHandle2ConstColumnHeaders self,
   const XMLName types
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ColumnHasByTypes",
       self, extract::column, meta::types, types);
}

// Get, by types, const
Handle2ConstColumn
ColumnHeadersColumnGetByTypesConst(
   ConstHandle2ConstColumnHeaders self,
   const XMLName types
) {
   return detail::getByMetadatum<CPP,Handle2ConstColumn>
      (CLASSNAME, CLASSNAME+"ColumnGetByTypesConst",
       self, extract::column, meta::types, types);
}

// Get, by types, non-const
Handle2Column
ColumnHeadersColumnGetByTypes(
   ConstHandle2ColumnHeaders self,
   const XMLName types
) {
   return detail::getByMetadatum<CPP,Handle2Column>
      (CLASSNAME, CLASSNAME+"ColumnGetByTypes",
       self, extract::column, meta::types, types);
}

// Set, by types
void
ColumnHeadersColumnSetByTypes(
   ConstHandle2ColumnHeaders self,
   const XMLName types,
   ConstHandle2ConstColumn column
) {
   detail::setByMetadatum<CPP,CPPColumn>
      (CLASSNAME, CLASSNAME+"ColumnSetByTypes",
       self, extract::column, meta::types, types, column);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/containers/ColumnHeaders/src/custom.cpp"
