
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2.0/general/ProductYields.hpp"
#include "ProductYields.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = ProductYieldsClass;
using CPP = multigroup::ProductYields;

static const std::string CLASSNAME = "ProductYields";

namespace extract {
   static auto productYield = [](auto &obj) { return &obj.productYield; };
}

using CPPProductYield = general::ProductYield;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstProductYields
ProductYieldsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2ProductYields
ProductYieldsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstProductYields
ProductYieldsCreateConst(
   ConstHandle2ProductYield *const productYield, const size_t productYieldSize
) {
   ConstHandle2ProductYields handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPProductYield>{}
   );
   for (size_t ProductYieldN = 0; ProductYieldN < productYieldSize; ++ProductYieldN)
      ProductYieldsProductYieldAdd(handle, productYield[ProductYieldN]);
   return handle;
}

// Create, general
Handle2ProductYields
ProductYieldsCreate(
   ConstHandle2ProductYield *const productYield, const size_t productYieldSize
) {
   ConstHandle2ProductYields handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPProductYield>{}
   );
   for (size_t ProductYieldN = 0; ProductYieldN < productYieldSize; ++ProductYieldN)
      ProductYieldsProductYieldAdd(handle, productYield[ProductYieldN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ProductYieldsAssign(ConstHandle2ProductYields self, ConstHandle2ConstProductYields from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ProductYieldsDelete(ConstHandle2ConstProductYields self)
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
ProductYieldsRead(ConstHandle2ProductYields self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ProductYieldsWrite(ConstHandle2ConstProductYields self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ProductYieldsPrint(ConstHandle2ConstProductYields self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ProductYieldsPrintXML(ConstHandle2ConstProductYields self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ProductYieldsPrintJSON(ConstHandle2ConstProductYields self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: productYield
// -----------------------------------------------------------------------------

// Has
int
ProductYieldsProductYieldHas(ConstHandle2ConstProductYields self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ProductYieldHas", self, extract::productYield);
}

// Clear
void
ProductYieldsProductYieldClear(ConstHandle2ProductYields self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"ProductYieldClear", self, extract::productYield);
}

// Size
size_t
ProductYieldsProductYieldSize(ConstHandle2ConstProductYields self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"ProductYieldSize", self, extract::productYield);
}

// Add
void
ProductYieldsProductYieldAdd(ConstHandle2ProductYields self, ConstHandle2ConstProductYield productYield)
{
   detail::addToContainer<CPP,CPPProductYield>
      (CLASSNAME, CLASSNAME+"ProductYieldAdd", self, extract::productYield, productYield);
}

// Get, by index \in [0,size), const
Handle2ConstProductYield
ProductYieldsProductYieldGetConst(ConstHandle2ConstProductYields self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstProductYield>
      (CLASSNAME, CLASSNAME+"ProductYieldGetConst", self, extract::productYield, index_);
}

// Get, by index \in [0,size), non-const
Handle2ProductYield
ProductYieldsProductYieldGet(ConstHandle2ProductYields self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ProductYield>
      (CLASSNAME, CLASSNAME+"ProductYieldGet", self, extract::productYield, index_);
}

// Set, by index \in [0,size)
void
ProductYieldsProductYieldSet(
   ConstHandle2ProductYields self,
   const size_t index_,
   ConstHandle2ConstProductYield productYield
) {
   detail::setByIndex<CPP,CPPProductYield>
      (CLASSNAME, CLASSNAME+"ProductYieldSet", self, extract::productYield, index_, productYield);
}

// Has, by label
int
ProductYieldsProductYieldHasByLabel(
   ConstHandle2ConstProductYields self,
   const char *const label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ProductYieldHasByLabel",
       self, extract::productYield, meta::label, label);
}

// Get, by label, const
Handle2ConstProductYield
ProductYieldsProductYieldGetByLabelConst(
   ConstHandle2ConstProductYields self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2ConstProductYield>
      (CLASSNAME, CLASSNAME+"ProductYieldGetByLabelConst",
       self, extract::productYield, meta::label, label);
}

// Get, by label, non-const
Handle2ProductYield
ProductYieldsProductYieldGetByLabel(
   ConstHandle2ProductYields self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2ProductYield>
      (CLASSNAME, CLASSNAME+"ProductYieldGetByLabel",
       self, extract::productYield, meta::label, label);
}

// Set, by label
void
ProductYieldsProductYieldSetByLabel(
   ConstHandle2ProductYields self,
   const char *const label,
   ConstHandle2ConstProductYield productYield
) {
   detail::setByMetadatum<CPP,CPPProductYield>
      (CLASSNAME, CLASSNAME+"ProductYieldSetByLabel",
       self, extract::productYield, meta::label, label, productYield);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/ProductYields/src/custom.cpp"
