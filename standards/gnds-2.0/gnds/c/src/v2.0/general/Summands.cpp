
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "gnds/v2.0/general/Summands.hpp"
#include "Summands.h"

using namespace njoy::GNDStk;
using namespace gnds::v2_0;

using C = SummandsClass;
using CPP = multigroup::Summands;

static const std::string CLASSNAME = "Summands";

namespace extract {
   static auto add = [](auto &obj) { return &obj.add; };
}

using CPPAdd = general::Add;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstSummands
SummandsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Summands
SummandsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstSummands
SummandsCreateConst(
   ConstHandle2Add *const add, const size_t addSize
) {
   ConstHandle2Summands handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPAdd>{}
   );
   for (size_t AddN = 0; AddN < addSize; ++AddN)
      SummandsAddAdd(handle, add[AddN]);
   return handle;
}

// Create, general
Handle2Summands
SummandsCreate(
   ConstHandle2Add *const add, const size_t addSize
) {
   ConstHandle2Summands handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPAdd>{}
   );
   for (size_t AddN = 0; AddN < addSize; ++AddN)
      SummandsAddAdd(handle, add[AddN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
SummandsAssign(ConstHandle2Summands self, ConstHandle2ConstSummands from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
SummandsDelete(ConstHandle2ConstSummands self)
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
SummandsRead(ConstHandle2Summands self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
SummandsWrite(ConstHandle2ConstSummands self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
SummandsPrint(ConstHandle2ConstSummands self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
SummandsPrintXML(ConstHandle2ConstSummands self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
SummandsPrintJSON(ConstHandle2ConstSummands self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: add
// -----------------------------------------------------------------------------

// Has
int
SummandsAddHas(ConstHandle2ConstSummands self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AddHas", self, extract::add);
}

// Clear
void
SummandsAddClear(ConstHandle2Summands self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"AddClear", self, extract::add);
}

// Size
size_t
SummandsAddSize(ConstHandle2ConstSummands self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"AddSize", self, extract::add);
}

// Add
void
SummandsAddAdd(ConstHandle2Summands self, ConstHandle2ConstAdd add)
{
   detail::addToContainer<CPP,CPPAdd>
      (CLASSNAME, CLASSNAME+"AddAdd", self, extract::add, add);
}

// Get, by index \in [0,size), const
Handle2ConstAdd
SummandsAddGetConst(ConstHandle2ConstSummands self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstAdd>
      (CLASSNAME, CLASSNAME+"AddGetConst", self, extract::add, index_);
}

// Get, by index \in [0,size), non-const
Handle2Add
SummandsAddGet(ConstHandle2Summands self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Add>
      (CLASSNAME, CLASSNAME+"AddGet", self, extract::add, index_);
}

// Set, by index \in [0,size)
void
SummandsAddSet(
   ConstHandle2Summands self,
   const size_t index_,
   ConstHandle2ConstAdd add
) {
   detail::setByIndex<CPP,CPPAdd>
      (CLASSNAME, CLASSNAME+"AddSet", self, extract::add, index_, add);
}

// Has, by href
int
SummandsAddHasByHref(
   ConstHandle2ConstSummands self,
   const char *const href
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"AddHasByHref",
       self, extract::add, meta::href, href);
}

// Get, by href, const
Handle2ConstAdd
SummandsAddGetByHrefConst(
   ConstHandle2ConstSummands self,
   const char *const href
) {
   return detail::getByMetadatum<CPP,Handle2ConstAdd>
      (CLASSNAME, CLASSNAME+"AddGetByHrefConst",
       self, extract::add, meta::href, href);
}

// Get, by href, non-const
Handle2Add
SummandsAddGetByHref(
   ConstHandle2Summands self,
   const char *const href
) {
   return detail::getByMetadatum<CPP,Handle2Add>
      (CLASSNAME, CLASSNAME+"AddGetByHref",
       self, extract::add, meta::href, href);
}

// Set, by href
void
SummandsAddSetByHref(
   ConstHandle2Summands self,
   const char *const href,
   ConstHandle2ConstAdd add
) {
   detail::setByMetadatum<CPP,CPPAdd>
      (CLASSNAME, CLASSNAME+"AddSetByHref",
       self, extract::add, meta::href, href, add);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Summands/src/custom.cpp"
