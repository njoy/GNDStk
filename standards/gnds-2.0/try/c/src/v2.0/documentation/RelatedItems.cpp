
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/documentation/RelatedItems.hpp"
#include "RelatedItems.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = RelatedItemsClass;
using CPP = multigroup::RelatedItems;

static const std::string CLASSNAME = "RelatedItems";

namespace extract {
   static auto relatedItem = [](auto &obj) { return &obj.relatedItem; };
}

using CPPRelatedItem = documentation::RelatedItem;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstRelatedItems
RelatedItemsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2RelatedItems
RelatedItemsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstRelatedItems
RelatedItemsCreateConst(
   ConstHandle2RelatedItem *const relatedItem, const size_t relatedItemSize
) {
   ConstHandle2RelatedItems handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPRelatedItem>{}
   );
   for (size_t RelatedItemN = 0; RelatedItemN < relatedItemSize; ++RelatedItemN)
      RelatedItemsRelatedItemAdd(handle, relatedItem[RelatedItemN]);
   return handle;
}

// Create, general
Handle2RelatedItems
RelatedItemsCreate(
   ConstHandle2RelatedItem *const relatedItem, const size_t relatedItemSize
) {
   ConstHandle2RelatedItems handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPRelatedItem>{}
   );
   for (size_t RelatedItemN = 0; RelatedItemN < relatedItemSize; ++RelatedItemN)
      RelatedItemsRelatedItemAdd(handle, relatedItem[RelatedItemN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
RelatedItemsAssign(ConstHandle2RelatedItems This, ConstHandle2ConstRelatedItems from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
RelatedItemsDelete(ConstHandle2ConstRelatedItems This)
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
RelatedItemsRead(ConstHandle2RelatedItems This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
RelatedItemsWrite(ConstHandle2ConstRelatedItems This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
RelatedItemsPrint(ConstHandle2ConstRelatedItems This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
RelatedItemsPrintXML(ConstHandle2ConstRelatedItems This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
RelatedItemsPrintJSON(ConstHandle2ConstRelatedItems This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: relatedItem
// -----------------------------------------------------------------------------

// Has
int
RelatedItemsRelatedItemHas(ConstHandle2ConstRelatedItems This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"RelatedItemHas", This, extract::relatedItem);
}

// Clear
void
RelatedItemsRelatedItemClear(ConstHandle2RelatedItems This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"RelatedItemClear", This, extract::relatedItem);
}

// Size
size_t
RelatedItemsRelatedItemSize(ConstHandle2ConstRelatedItems This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"RelatedItemSize", This, extract::relatedItem);
}

// Add
void
RelatedItemsRelatedItemAdd(ConstHandle2RelatedItems This, ConstHandle2ConstRelatedItem relatedItem)
{
   detail::addToContainer<CPP,CPPRelatedItem>
      (CLASSNAME, CLASSNAME+"RelatedItemAdd", This, extract::relatedItem, relatedItem);
}

// Get, by index \in [0,size), const
Handle2ConstRelatedItem
RelatedItemsRelatedItemGetConst(ConstHandle2ConstRelatedItems This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstRelatedItem>
      (CLASSNAME, CLASSNAME+"RelatedItemGetConst", This, extract::relatedItem, index_);
}

// Get, by index \in [0,size), non-const
Handle2RelatedItem
RelatedItemsRelatedItemGet(ConstHandle2RelatedItems This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2RelatedItem>
      (CLASSNAME, CLASSNAME+"RelatedItemGet", This, extract::relatedItem, index_);
}

// Set, by index \in [0,size)
void
RelatedItemsRelatedItemSet(
   ConstHandle2RelatedItems This,
   const size_t index_,
   ConstHandle2ConstRelatedItem relatedItem
) {
   detail::setByIndex<CPP,CPPRelatedItem>
      (CLASSNAME, CLASSNAME+"RelatedItemSet", This, extract::relatedItem, index_, relatedItem);
}

// Has, by name
int
RelatedItemsRelatedItemHasByName(
   ConstHandle2ConstRelatedItems This,
   const UTF8Text name
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"RelatedItemHasByName",
       This, extract::relatedItem, meta::name, name);
}

// Get, by name, const
Handle2ConstRelatedItem
RelatedItemsRelatedItemGetByNameConst(
   ConstHandle2ConstRelatedItems This,
   const UTF8Text name
) {
   return detail::getByMetadatum<CPP,Handle2ConstRelatedItem>
      (CLASSNAME, CLASSNAME+"RelatedItemGetByNameConst",
       This, extract::relatedItem, meta::name, name);
}

// Get, by name, non-const
Handle2RelatedItem
RelatedItemsRelatedItemGetByName(
   ConstHandle2RelatedItems This,
   const UTF8Text name
) {
   return detail::getByMetadatum<CPP,Handle2RelatedItem>
      (CLASSNAME, CLASSNAME+"RelatedItemGetByName",
       This, extract::relatedItem, meta::name, name);
}

// Set, by name
void
RelatedItemsRelatedItemSetByName(
   ConstHandle2RelatedItems This,
   const UTF8Text name,
   ConstHandle2ConstRelatedItem relatedItem
) {
   detail::setByMetadatum<CPP,CPPRelatedItem>
      (CLASSNAME, CLASSNAME+"RelatedItemSetByName",
       This, extract::relatedItem, meta::name, name, relatedItem);
}

// Has, by href
int
RelatedItemsRelatedItemHasByHref(
   ConstHandle2ConstRelatedItems This,
   const UTF8Text href
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"RelatedItemHasByHref",
       This, extract::relatedItem, meta::href, href);
}

// Get, by href, const
Handle2ConstRelatedItem
RelatedItemsRelatedItemGetByHrefConst(
   ConstHandle2ConstRelatedItems This,
   const UTF8Text href
) {
   return detail::getByMetadatum<CPP,Handle2ConstRelatedItem>
      (CLASSNAME, CLASSNAME+"RelatedItemGetByHrefConst",
       This, extract::relatedItem, meta::href, href);
}

// Get, by href, non-const
Handle2RelatedItem
RelatedItemsRelatedItemGetByHref(
   ConstHandle2RelatedItems This,
   const UTF8Text href
) {
   return detail::getByMetadatum<CPP,Handle2RelatedItem>
      (CLASSNAME, CLASSNAME+"RelatedItemGetByHref",
       This, extract::relatedItem, meta::href, href);
}

// Set, by href
void
RelatedItemsRelatedItemSetByHref(
   ConstHandle2RelatedItems This,
   const UTF8Text href,
   ConstHandle2ConstRelatedItem relatedItem
) {
   detail::setByMetadatum<CPP,CPPRelatedItem>
      (CLASSNAME, CLASSNAME+"RelatedItemSetByHref",
       This, extract::relatedItem, meta::href, href, relatedItem);
}

// Has, by relationType
int
RelatedItemsRelatedItemHasByRelationType(
   ConstHandle2ConstRelatedItems This,
   const enums::RelationType relationType
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"RelatedItemHasByRelationType",
       This, extract::relatedItem, meta::relationType, relationType);
}

// Get, by relationType, const
Handle2ConstRelatedItem
RelatedItemsRelatedItemGetByRelationTypeConst(
   ConstHandle2ConstRelatedItems This,
   const enums::RelationType relationType
) {
   return detail::getByMetadatum<CPP,Handle2ConstRelatedItem>
      (CLASSNAME, CLASSNAME+"RelatedItemGetByRelationTypeConst",
       This, extract::relatedItem, meta::relationType, relationType);
}

// Get, by relationType, non-const
Handle2RelatedItem
RelatedItemsRelatedItemGetByRelationType(
   ConstHandle2RelatedItems This,
   const enums::RelationType relationType
) {
   return detail::getByMetadatum<CPP,Handle2RelatedItem>
      (CLASSNAME, CLASSNAME+"RelatedItemGetByRelationType",
       This, extract::relatedItem, meta::relationType, relationType);
}

// Set, by relationType
void
RelatedItemsRelatedItemSetByRelationType(
   ConstHandle2RelatedItems This,
   const enums::RelationType relationType,
   ConstHandle2ConstRelatedItem relatedItem
) {
   detail::setByMetadatum<CPP,CPPRelatedItem>
      (CLASSNAME, CLASSNAME+"RelatedItemSetByRelationType",
       This, extract::relatedItem, meta::relationType, relationType, relatedItem);
}
