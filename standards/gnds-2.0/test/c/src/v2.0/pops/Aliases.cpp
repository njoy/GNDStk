
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/pops/Aliases.hpp"
#include "Aliases.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = AliasesClass;
using CPP = multigroup::Aliases;

static const std::string CLASSNAME = "Aliases";

namespace extract {
   static auto alias = [](auto &obj) { return &obj.alias; };
   static auto metaStable = [](auto &obj) { return &obj.metaStable; };
}

using CPPAlias = pops::Alias;
using CPPMetaStable = pops::MetaStable;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstAliases
AliasesDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Aliases
AliasesDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstAliases
AliasesCreateConst(
   ConstHandle2Alias *const alias, const size_t aliasSize,
   ConstHandle2MetaStable *const metaStable, const size_t metaStableSize
) {
   ConstHandle2Aliases handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPAlias>{},
      std::vector<CPPMetaStable>{}
   );
   for (size_t AliasN = 0; AliasN < aliasSize; ++AliasN)
      AliasesAliasAdd(handle, alias[AliasN]);
   for (size_t MetaStableN = 0; MetaStableN < metaStableSize; ++MetaStableN)
      AliasesMetaStableAdd(handle, metaStable[MetaStableN]);
   return handle;
}

// Create, general
Handle2Aliases
AliasesCreate(
   ConstHandle2Alias *const alias, const size_t aliasSize,
   ConstHandle2MetaStable *const metaStable, const size_t metaStableSize
) {
   ConstHandle2Aliases handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPAlias>{},
      std::vector<CPPMetaStable>{}
   );
   for (size_t AliasN = 0; AliasN < aliasSize; ++AliasN)
      AliasesAliasAdd(handle, alias[AliasN]);
   for (size_t MetaStableN = 0; MetaStableN < metaStableSize; ++MetaStableN)
      AliasesMetaStableAdd(handle, metaStable[MetaStableN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
AliasesAssign(ConstHandle2Aliases This, ConstHandle2ConstAliases from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
AliasesDelete(ConstHandle2ConstAliases This)
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
AliasesRead(ConstHandle2Aliases This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
AliasesWrite(ConstHandle2ConstAliases This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
AliasesPrint(ConstHandle2ConstAliases This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
AliasesPrintXML(ConstHandle2ConstAliases This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
AliasesPrintJSON(ConstHandle2ConstAliases This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: alias
// -----------------------------------------------------------------------------

// Has
int
AliasesAliasHas(ConstHandle2ConstAliases This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AliasHas", This, extract::alias);
}

// Clear
void
AliasesAliasClear(ConstHandle2Aliases This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"AliasClear", This, extract::alias);
}

// Size
size_t
AliasesAliasSize(ConstHandle2ConstAliases This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"AliasSize", This, extract::alias);
}

// Add
void
AliasesAliasAdd(ConstHandle2Aliases This, ConstHandle2ConstAlias alias)
{
   detail::addToContainer<CPP,CPPAlias>
      (CLASSNAME, CLASSNAME+"AliasAdd", This, extract::alias, alias);
}

// Get, by index \in [0,size), const
Handle2ConstAlias
AliasesAliasGetConst(ConstHandle2ConstAliases This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstAlias>
      (CLASSNAME, CLASSNAME+"AliasGetConst", This, extract::alias, index_);
}

// Get, by index \in [0,size), non-const
Handle2Alias
AliasesAliasGet(ConstHandle2Aliases This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Alias>
      (CLASSNAME, CLASSNAME+"AliasGet", This, extract::alias, index_);
}

// Set, by index \in [0,size)
void
AliasesAliasSet(
   ConstHandle2Aliases This,
   const size_t index_,
   ConstHandle2ConstAlias alias
) {
   detail::setByIndex<CPP,CPPAlias>
      (CLASSNAME, CLASSNAME+"AliasSet", This, extract::alias, index_, alias);
}

// Has, by id
int
AliasesAliasHasById(
   ConstHandle2ConstAliases This,
   const XMLName id
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"AliasHasById",
       This, extract::alias, meta::id, id);
}

// Get, by id, const
Handle2ConstAlias
AliasesAliasGetByIdConst(
   ConstHandle2ConstAliases This,
   const XMLName id
) {
   return detail::getByMetadatum<CPP,Handle2ConstAlias>
      (CLASSNAME, CLASSNAME+"AliasGetByIdConst",
       This, extract::alias, meta::id, id);
}

// Get, by id, non-const
Handle2Alias
AliasesAliasGetById(
   ConstHandle2Aliases This,
   const XMLName id
) {
   return detail::getByMetadatum<CPP,Handle2Alias>
      (CLASSNAME, CLASSNAME+"AliasGetById",
       This, extract::alias, meta::id, id);
}

// Set, by id
void
AliasesAliasSetById(
   ConstHandle2Aliases This,
   const XMLName id,
   ConstHandle2ConstAlias alias
) {
   detail::setByMetadatum<CPP,CPPAlias>
      (CLASSNAME, CLASSNAME+"AliasSetById",
       This, extract::alias, meta::id, id, alias);
}

// Has, by pid
int
AliasesAliasHasByPid(
   ConstHandle2ConstAliases This,
   const XMLName pid
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"AliasHasByPid",
       This, extract::alias, meta::pid, pid);
}

// Get, by pid, const
Handle2ConstAlias
AliasesAliasGetByPidConst(
   ConstHandle2ConstAliases This,
   const XMLName pid
) {
   return detail::getByMetadatum<CPP,Handle2ConstAlias>
      (CLASSNAME, CLASSNAME+"AliasGetByPidConst",
       This, extract::alias, meta::pid, pid);
}

// Get, by pid, non-const
Handle2Alias
AliasesAliasGetByPid(
   ConstHandle2Aliases This,
   const XMLName pid
) {
   return detail::getByMetadatum<CPP,Handle2Alias>
      (CLASSNAME, CLASSNAME+"AliasGetByPid",
       This, extract::alias, meta::pid, pid);
}

// Set, by pid
void
AliasesAliasSetByPid(
   ConstHandle2Aliases This,
   const XMLName pid,
   ConstHandle2ConstAlias alias
) {
   detail::setByMetadatum<CPP,CPPAlias>
      (CLASSNAME, CLASSNAME+"AliasSetByPid",
       This, extract::alias, meta::pid, pid, alias);
}


// -----------------------------------------------------------------------------
// Child: metaStable
// -----------------------------------------------------------------------------

// Has
int
AliasesMetaStableHas(ConstHandle2ConstAliases This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"MetaStableHas", This, extract::metaStable);
}

// Clear
void
AliasesMetaStableClear(ConstHandle2Aliases This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"MetaStableClear", This, extract::metaStable);
}

// Size
size_t
AliasesMetaStableSize(ConstHandle2ConstAliases This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"MetaStableSize", This, extract::metaStable);
}

// Add
void
AliasesMetaStableAdd(ConstHandle2Aliases This, ConstHandle2ConstMetaStable metaStable)
{
   detail::addToContainer<CPP,CPPMetaStable>
      (CLASSNAME, CLASSNAME+"MetaStableAdd", This, extract::metaStable, metaStable);
}

// Get, by index \in [0,size), const
Handle2ConstMetaStable
AliasesMetaStableGetConst(ConstHandle2ConstAliases This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstMetaStable>
      (CLASSNAME, CLASSNAME+"MetaStableGetConst", This, extract::metaStable, index_);
}

// Get, by index \in [0,size), non-const
Handle2MetaStable
AliasesMetaStableGet(ConstHandle2Aliases This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2MetaStable>
      (CLASSNAME, CLASSNAME+"MetaStableGet", This, extract::metaStable, index_);
}

// Set, by index \in [0,size)
void
AliasesMetaStableSet(
   ConstHandle2Aliases This,
   const size_t index_,
   ConstHandle2ConstMetaStable metaStable
) {
   detail::setByIndex<CPP,CPPMetaStable>
      (CLASSNAME, CLASSNAME+"MetaStableSet", This, extract::metaStable, index_, metaStable);
}

// Has, by id
int
AliasesMetaStableHasById(
   ConstHandle2ConstAliases This,
   const XMLName id
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"MetaStableHasById",
       This, extract::metaStable, meta::id, id);
}

// Get, by id, const
Handle2ConstMetaStable
AliasesMetaStableGetByIdConst(
   ConstHandle2ConstAliases This,
   const XMLName id
) {
   return detail::getByMetadatum<CPP,Handle2ConstMetaStable>
      (CLASSNAME, CLASSNAME+"MetaStableGetByIdConst",
       This, extract::metaStable, meta::id, id);
}

// Get, by id, non-const
Handle2MetaStable
AliasesMetaStableGetById(
   ConstHandle2Aliases This,
   const XMLName id
) {
   return detail::getByMetadatum<CPP,Handle2MetaStable>
      (CLASSNAME, CLASSNAME+"MetaStableGetById",
       This, extract::metaStable, meta::id, id);
}

// Set, by id
void
AliasesMetaStableSetById(
   ConstHandle2Aliases This,
   const XMLName id,
   ConstHandle2ConstMetaStable metaStable
) {
   detail::setByMetadatum<CPP,CPPMetaStable>
      (CLASSNAME, CLASSNAME+"MetaStableSetById",
       This, extract::metaStable, meta::id, id, metaStable);
}

// Has, by metaStableIndex
int
AliasesMetaStableHasByMetaStableIndex(
   ConstHandle2ConstAliases This,
   const Integer32 metaStableIndex
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"MetaStableHasByMetaStableIndex",
       This, extract::metaStable, meta::metaStableIndex, metaStableIndex);
}

// Get, by metaStableIndex, const
Handle2ConstMetaStable
AliasesMetaStableGetByMetaStableIndexConst(
   ConstHandle2ConstAliases This,
   const Integer32 metaStableIndex
) {
   return detail::getByMetadatum<CPP,Handle2ConstMetaStable>
      (CLASSNAME, CLASSNAME+"MetaStableGetByMetaStableIndexConst",
       This, extract::metaStable, meta::metaStableIndex, metaStableIndex);
}

// Get, by metaStableIndex, non-const
Handle2MetaStable
AliasesMetaStableGetByMetaStableIndex(
   ConstHandle2Aliases This,
   const Integer32 metaStableIndex
) {
   return detail::getByMetadatum<CPP,Handle2MetaStable>
      (CLASSNAME, CLASSNAME+"MetaStableGetByMetaStableIndex",
       This, extract::metaStable, meta::metaStableIndex, metaStableIndex);
}

// Set, by metaStableIndex
void
AliasesMetaStableSetByMetaStableIndex(
   ConstHandle2Aliases This,
   const Integer32 metaStableIndex,
   ConstHandle2ConstMetaStable metaStable
) {
   detail::setByMetadatum<CPP,CPPMetaStable>
      (CLASSNAME, CLASSNAME+"MetaStableSetByMetaStableIndex",
       This, extract::metaStable, meta::metaStableIndex, metaStableIndex, metaStable);
}

// Has, by pid
int
AliasesMetaStableHasByPid(
   ConstHandle2ConstAliases This,
   const XMLName pid
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"MetaStableHasByPid",
       This, extract::metaStable, meta::pid, pid);
}

// Get, by pid, const
Handle2ConstMetaStable
AliasesMetaStableGetByPidConst(
   ConstHandle2ConstAliases This,
   const XMLName pid
) {
   return detail::getByMetadatum<CPP,Handle2ConstMetaStable>
      (CLASSNAME, CLASSNAME+"MetaStableGetByPidConst",
       This, extract::metaStable, meta::pid, pid);
}

// Get, by pid, non-const
Handle2MetaStable
AliasesMetaStableGetByPid(
   ConstHandle2Aliases This,
   const XMLName pid
) {
   return detail::getByMetadatum<CPP,Handle2MetaStable>
      (CLASSNAME, CLASSNAME+"MetaStableGetByPid",
       This, extract::metaStable, meta::pid, pid);
}

// Set, by pid
void
AliasesMetaStableSetByPid(
   ConstHandle2Aliases This,
   const XMLName pid,
   ConstHandle2ConstMetaStable metaStable
) {
   detail::setByMetadatum<CPP,CPPMetaStable>
      (CLASSNAME, CLASSNAME+"MetaStableSetByPid",
       This, extract::metaStable, meta::pid, pid, metaStable);
}
