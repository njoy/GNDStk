
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2.0/general/Aliases.hpp"
#include "Aliases.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = AliasesClass;
using CPP = multigroup::Aliases;

static const std::string CLASSNAME = "Aliases";

namespace extract {
   static auto alias = [](auto &obj) { return &obj.alias; };
   static auto metaStable = [](auto &obj) { return &obj.metaStable; };
}

using CPPAlias = general::Alias;
using CPPMetaStable = general::MetaStable;


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
AliasesAssign(ConstHandle2Aliases self, ConstHandle2ConstAliases from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
AliasesDelete(ConstHandle2ConstAliases self)
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
AliasesRead(ConstHandle2Aliases self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
AliasesWrite(ConstHandle2ConstAliases self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
AliasesPrint(ConstHandle2ConstAliases self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
AliasesPrintXML(ConstHandle2ConstAliases self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
AliasesPrintJSON(ConstHandle2ConstAliases self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: alias
// -----------------------------------------------------------------------------

// Has
int
AliasesAliasHas(ConstHandle2ConstAliases self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AliasHas", self, extract::alias);
}

// Clear
void
AliasesAliasClear(ConstHandle2Aliases self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"AliasClear", self, extract::alias);
}

// Size
size_t
AliasesAliasSize(ConstHandle2ConstAliases self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"AliasSize", self, extract::alias);
}

// Add
void
AliasesAliasAdd(ConstHandle2Aliases self, ConstHandle2ConstAlias alias)
{
   detail::addToContainer<CPP,CPPAlias>
      (CLASSNAME, CLASSNAME+"AliasAdd", self, extract::alias, alias);
}

// Get, by index \in [0,size), const
Handle2ConstAlias
AliasesAliasGetConst(ConstHandle2ConstAliases self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstAlias>
      (CLASSNAME, CLASSNAME+"AliasGetConst", self, extract::alias, index_);
}

// Get, by index \in [0,size), non-const
Handle2Alias
AliasesAliasGet(ConstHandle2Aliases self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Alias>
      (CLASSNAME, CLASSNAME+"AliasGet", self, extract::alias, index_);
}

// Set, by index \in [0,size)
void
AliasesAliasSet(
   ConstHandle2Aliases self,
   const size_t index_,
   ConstHandle2ConstAlias alias
) {
   detail::setByIndex<CPP,CPPAlias>
      (CLASSNAME, CLASSNAME+"AliasSet", self, extract::alias, index_, alias);
}

// Has, by id
int
AliasesAliasHasById(
   ConstHandle2ConstAliases self,
   const char *const id
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"AliasHasById",
       self, extract::alias, meta::id, id);
}

// Get, by id, const
Handle2ConstAlias
AliasesAliasGetByIdConst(
   ConstHandle2ConstAliases self,
   const char *const id
) {
   return detail::getByMetadatum<CPP,Handle2ConstAlias>
      (CLASSNAME, CLASSNAME+"AliasGetByIdConst",
       self, extract::alias, meta::id, id);
}

// Get, by id, non-const
Handle2Alias
AliasesAliasGetById(
   ConstHandle2Aliases self,
   const char *const id
) {
   return detail::getByMetadatum<CPP,Handle2Alias>
      (CLASSNAME, CLASSNAME+"AliasGetById",
       self, extract::alias, meta::id, id);
}

// Set, by id
void
AliasesAliasSetById(
   ConstHandle2Aliases self,
   const char *const id,
   ConstHandle2ConstAlias alias
) {
   detail::setByMetadatum<CPP,CPPAlias>
      (CLASSNAME, CLASSNAME+"AliasSetById",
       self, extract::alias, meta::id, id, alias);
}

// Has, by pid
int
AliasesAliasHasByPid(
   ConstHandle2ConstAliases self,
   const char *const pid
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"AliasHasByPid",
       self, extract::alias, meta::pid, pid);
}

// Get, by pid, const
Handle2ConstAlias
AliasesAliasGetByPidConst(
   ConstHandle2ConstAliases self,
   const char *const pid
) {
   return detail::getByMetadatum<CPP,Handle2ConstAlias>
      (CLASSNAME, CLASSNAME+"AliasGetByPidConst",
       self, extract::alias, meta::pid, pid);
}

// Get, by pid, non-const
Handle2Alias
AliasesAliasGetByPid(
   ConstHandle2Aliases self,
   const char *const pid
) {
   return detail::getByMetadatum<CPP,Handle2Alias>
      (CLASSNAME, CLASSNAME+"AliasGetByPid",
       self, extract::alias, meta::pid, pid);
}

// Set, by pid
void
AliasesAliasSetByPid(
   ConstHandle2Aliases self,
   const char *const pid,
   ConstHandle2ConstAlias alias
) {
   detail::setByMetadatum<CPP,CPPAlias>
      (CLASSNAME, CLASSNAME+"AliasSetByPid",
       self, extract::alias, meta::pid, pid, alias);
}


// -----------------------------------------------------------------------------
// Child: metaStable
// -----------------------------------------------------------------------------

// Has
int
AliasesMetaStableHas(ConstHandle2ConstAliases self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"MetaStableHas", self, extract::metaStable);
}

// Clear
void
AliasesMetaStableClear(ConstHandle2Aliases self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"MetaStableClear", self, extract::metaStable);
}

// Size
size_t
AliasesMetaStableSize(ConstHandle2ConstAliases self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"MetaStableSize", self, extract::metaStable);
}

// Add
void
AliasesMetaStableAdd(ConstHandle2Aliases self, ConstHandle2ConstMetaStable metaStable)
{
   detail::addToContainer<CPP,CPPMetaStable>
      (CLASSNAME, CLASSNAME+"MetaStableAdd", self, extract::metaStable, metaStable);
}

// Get, by index \in [0,size), const
Handle2ConstMetaStable
AliasesMetaStableGetConst(ConstHandle2ConstAliases self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstMetaStable>
      (CLASSNAME, CLASSNAME+"MetaStableGetConst", self, extract::metaStable, index_);
}

// Get, by index \in [0,size), non-const
Handle2MetaStable
AliasesMetaStableGet(ConstHandle2Aliases self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2MetaStable>
      (CLASSNAME, CLASSNAME+"MetaStableGet", self, extract::metaStable, index_);
}

// Set, by index \in [0,size)
void
AliasesMetaStableSet(
   ConstHandle2Aliases self,
   const size_t index_,
   ConstHandle2ConstMetaStable metaStable
) {
   detail::setByIndex<CPP,CPPMetaStable>
      (CLASSNAME, CLASSNAME+"MetaStableSet", self, extract::metaStable, index_, metaStable);
}

// Has, by id
int
AliasesMetaStableHasById(
   ConstHandle2ConstAliases self,
   const char *const id
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"MetaStableHasById",
       self, extract::metaStable, meta::id, id);
}

// Get, by id, const
Handle2ConstMetaStable
AliasesMetaStableGetByIdConst(
   ConstHandle2ConstAliases self,
   const char *const id
) {
   return detail::getByMetadatum<CPP,Handle2ConstMetaStable>
      (CLASSNAME, CLASSNAME+"MetaStableGetByIdConst",
       self, extract::metaStable, meta::id, id);
}

// Get, by id, non-const
Handle2MetaStable
AliasesMetaStableGetById(
   ConstHandle2Aliases self,
   const char *const id
) {
   return detail::getByMetadatum<CPP,Handle2MetaStable>
      (CLASSNAME, CLASSNAME+"MetaStableGetById",
       self, extract::metaStable, meta::id, id);
}

// Set, by id
void
AliasesMetaStableSetById(
   ConstHandle2Aliases self,
   const char *const id,
   ConstHandle2ConstMetaStable metaStable
) {
   detail::setByMetadatum<CPP,CPPMetaStable>
      (CLASSNAME, CLASSNAME+"MetaStableSetById",
       self, extract::metaStable, meta::id, id, metaStable);
}

// Has, by pid
int
AliasesMetaStableHasByPid(
   ConstHandle2ConstAliases self,
   const char *const pid
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"MetaStableHasByPid",
       self, extract::metaStable, meta::pid, pid);
}

// Get, by pid, const
Handle2ConstMetaStable
AliasesMetaStableGetByPidConst(
   ConstHandle2ConstAliases self,
   const char *const pid
) {
   return detail::getByMetadatum<CPP,Handle2ConstMetaStable>
      (CLASSNAME, CLASSNAME+"MetaStableGetByPidConst",
       self, extract::metaStable, meta::pid, pid);
}

// Get, by pid, non-const
Handle2MetaStable
AliasesMetaStableGetByPid(
   ConstHandle2Aliases self,
   const char *const pid
) {
   return detail::getByMetadatum<CPP,Handle2MetaStable>
      (CLASSNAME, CLASSNAME+"MetaStableGetByPid",
       self, extract::metaStable, meta::pid, pid);
}

// Set, by pid
void
AliasesMetaStableSetByPid(
   ConstHandle2Aliases self,
   const char *const pid,
   ConstHandle2ConstMetaStable metaStable
) {
   detail::setByMetadatum<CPP,CPPMetaStable>
      (CLASSNAME, CLASSNAME+"MetaStableSetByPid",
       self, extract::metaStable, meta::pid, pid, metaStable);
}

// Has, by metaStableIndex
int
AliasesMetaStableHasByMetaStableIndex(
   ConstHandle2ConstAliases self,
   const int metaStableIndex
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"MetaStableHasByMetaStableIndex",
       self, extract::metaStable, meta::metaStableIndex, metaStableIndex);
}

// Get, by metaStableIndex, const
Handle2ConstMetaStable
AliasesMetaStableGetByMetaStableIndexConst(
   ConstHandle2ConstAliases self,
   const int metaStableIndex
) {
   return detail::getByMetadatum<CPP,Handle2ConstMetaStable>
      (CLASSNAME, CLASSNAME+"MetaStableGetByMetaStableIndexConst",
       self, extract::metaStable, meta::metaStableIndex, metaStableIndex);
}

// Get, by metaStableIndex, non-const
Handle2MetaStable
AliasesMetaStableGetByMetaStableIndex(
   ConstHandle2Aliases self,
   const int metaStableIndex
) {
   return detail::getByMetadatum<CPP,Handle2MetaStable>
      (CLASSNAME, CLASSNAME+"MetaStableGetByMetaStableIndex",
       self, extract::metaStable, meta::metaStableIndex, metaStableIndex);
}

// Set, by metaStableIndex
void
AliasesMetaStableSetByMetaStableIndex(
   ConstHandle2Aliases self,
   const int metaStableIndex,
   ConstHandle2ConstMetaStable metaStable
) {
   detail::setByMetadatum<CPP,CPPMetaStable>
      (CLASSNAME, CLASSNAME+"MetaStableSetByMetaStableIndex",
       self, extract::metaStable, meta::metaStableIndex, metaStableIndex, metaStable);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Aliases/src/custom.cpp"
