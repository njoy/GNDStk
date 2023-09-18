
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/OrphanProducts.hpp"
#include "OrphanProducts.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = OrphanProductsClass;
using CPP = multigroup::OrphanProducts;

static const std::string CLASSNAME = "OrphanProducts";

namespace extract {
   static auto orphanProduct = [](auto &obj) { return &obj.orphanProduct; };
}

using CPPOrphanProduct = general::OrphanProduct;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstOrphanProducts
OrphanProductsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2OrphanProducts
OrphanProductsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstOrphanProducts
OrphanProductsCreateConst(
   ConstHandle2OrphanProduct *const orphanProduct, const size_t orphanProductSize
) {
   ConstHandle2OrphanProducts handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPOrphanProduct>{}
   );
   for (size_t OrphanProductN = 0; OrphanProductN < orphanProductSize; ++OrphanProductN)
      OrphanProductsOrphanProductAdd(handle, orphanProduct[OrphanProductN]);
   return handle;
}

// Create, general
Handle2OrphanProducts
OrphanProductsCreate(
   ConstHandle2OrphanProduct *const orphanProduct, const size_t orphanProductSize
) {
   ConstHandle2OrphanProducts handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPOrphanProduct>{}
   );
   for (size_t OrphanProductN = 0; OrphanProductN < orphanProductSize; ++OrphanProductN)
      OrphanProductsOrphanProductAdd(handle, orphanProduct[OrphanProductN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
OrphanProductsAssign(ConstHandle2OrphanProducts self, ConstHandle2ConstOrphanProducts from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
OrphanProductsDelete(ConstHandle2ConstOrphanProducts self)
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
OrphanProductsRead(ConstHandle2OrphanProducts self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
OrphanProductsWrite(ConstHandle2ConstOrphanProducts self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
OrphanProductsPrint(ConstHandle2ConstOrphanProducts self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
OrphanProductsPrintXML(ConstHandle2ConstOrphanProducts self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
OrphanProductsPrintJSON(ConstHandle2ConstOrphanProducts self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: orphanProduct
// -----------------------------------------------------------------------------

// Has
int
OrphanProductsOrphanProductHas(ConstHandle2ConstOrphanProducts self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"OrphanProductHas", self, extract::orphanProduct);
}

// Clear
void
OrphanProductsOrphanProductClear(ConstHandle2OrphanProducts self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"OrphanProductClear", self, extract::orphanProduct);
}

// Size
size_t
OrphanProductsOrphanProductSize(ConstHandle2ConstOrphanProducts self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"OrphanProductSize", self, extract::orphanProduct);
}

// Add
void
OrphanProductsOrphanProductAdd(ConstHandle2OrphanProducts self, ConstHandle2ConstOrphanProduct orphanProduct)
{
   detail::addToContainer<CPP,CPPOrphanProduct>
      (CLASSNAME, CLASSNAME+"OrphanProductAdd", self, extract::orphanProduct, orphanProduct);
}

// Get, by index \in [0,size), const
Handle2ConstOrphanProduct
OrphanProductsOrphanProductGetConst(ConstHandle2ConstOrphanProducts self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstOrphanProduct>
      (CLASSNAME, CLASSNAME+"OrphanProductGetConst", self, extract::orphanProduct, index_);
}

// Get, by index \in [0,size)
Handle2OrphanProduct
OrphanProductsOrphanProductGet(ConstHandle2OrphanProducts self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2OrphanProduct>
      (CLASSNAME, CLASSNAME+"OrphanProductGet", self, extract::orphanProduct, index_);
}

// Set, by index \in [0,size)
void
OrphanProductsOrphanProductSet(
   ConstHandle2OrphanProducts self,
   const size_t index_,
   ConstHandle2ConstOrphanProduct orphanProduct
) {
   detail::setByIndex<CPP,CPPOrphanProduct>
      (CLASSNAME, CLASSNAME+"OrphanProductSet", self, extract::orphanProduct, index_, orphanProduct);
}

// Has, by label
int
OrphanProductsOrphanProductHasByLabel(
   ConstHandle2ConstOrphanProducts self,
   const char *const label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"OrphanProductHasByLabel",
       self, extract::orphanProduct, meta::label, label);
}

// Get, by label, const
Handle2ConstOrphanProduct
OrphanProductsOrphanProductGetByLabelConst(
   ConstHandle2ConstOrphanProducts self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2ConstOrphanProduct>
      (CLASSNAME, CLASSNAME+"OrphanProductGetByLabelConst",
       self, extract::orphanProduct, meta::label, label);
}

// Get, by label
Handle2OrphanProduct
OrphanProductsOrphanProductGetByLabel(
   ConstHandle2OrphanProducts self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2OrphanProduct>
      (CLASSNAME, CLASSNAME+"OrphanProductGetByLabel",
       self, extract::orphanProduct, meta::label, label);
}

// Set, by label
void
OrphanProductsOrphanProductSetByLabel(
   ConstHandle2OrphanProducts self,
   const char *const label,
   ConstHandle2ConstOrphanProduct orphanProduct
) {
   detail::setByMetadatum<CPP,CPPOrphanProduct>
      (CLASSNAME, CLASSNAME+"OrphanProductSetByLabel",
       self, extract::orphanProduct, meta::label, label, orphanProduct);
}

// Has, by ENDF_MT
int
OrphanProductsOrphanProductHasByENDFMT(
   ConstHandle2ConstOrphanProducts self,
   const int ENDF_MT
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"OrphanProductHasByENDFMT",
       self, extract::orphanProduct, meta::ENDF_MT, ENDF_MT);
}

// Get, by ENDF_MT, const
Handle2ConstOrphanProduct
OrphanProductsOrphanProductGetByENDFMTConst(
   ConstHandle2ConstOrphanProducts self,
   const int ENDF_MT
) {
   return detail::getByMetadatum<CPP,Handle2ConstOrphanProduct>
      (CLASSNAME, CLASSNAME+"OrphanProductGetByENDFMTConst",
       self, extract::orphanProduct, meta::ENDF_MT, ENDF_MT);
}

// Get, by ENDF_MT
Handle2OrphanProduct
OrphanProductsOrphanProductGetByENDFMT(
   ConstHandle2OrphanProducts self,
   const int ENDF_MT
) {
   return detail::getByMetadatum<CPP,Handle2OrphanProduct>
      (CLASSNAME, CLASSNAME+"OrphanProductGetByENDFMT",
       self, extract::orphanProduct, meta::ENDF_MT, ENDF_MT);
}

// Set, by ENDF_MT
void
OrphanProductsOrphanProductSetByENDFMT(
   ConstHandle2OrphanProducts self,
   const int ENDF_MT,
   ConstHandle2ConstOrphanProduct orphanProduct
) {
   detail::setByMetadatum<CPP,CPPOrphanProduct>
      (CLASSNAME, CLASSNAME+"OrphanProductSetByENDFMT",
       self, extract::orphanProduct, meta::ENDF_MT, ENDF_MT, orphanProduct);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/OrphanProducts/src/custom.cpp"
