
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/WeightedFunctionals.hpp"
#include "WeightedFunctionals.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = WeightedFunctionalsClass;
using CPP = multigroup::WeightedFunctionals;

static const std::string CLASSNAME = "WeightedFunctionals";

namespace extract {
   static auto weighted = [](auto &obj) { return &obj.weighted; };
}

using CPPWeighted = general::Weighted;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstWeightedFunctionals
WeightedFunctionalsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2WeightedFunctionals
WeightedFunctionalsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstWeightedFunctionals
WeightedFunctionalsCreateConst(
   ConstHandle2Weighted *const weighted, const size_t weightedSize
) {
   ConstHandle2WeightedFunctionals handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPWeighted>{}
   );
   for (size_t WeightedN = 0; WeightedN < weightedSize; ++WeightedN)
      WeightedFunctionalsWeightedAdd(handle, weighted[WeightedN]);
   return handle;
}

// Create, general
Handle2WeightedFunctionals
WeightedFunctionalsCreate(
   ConstHandle2Weighted *const weighted, const size_t weightedSize
) {
   ConstHandle2WeightedFunctionals handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPWeighted>{}
   );
   for (size_t WeightedN = 0; WeightedN < weightedSize; ++WeightedN)
      WeightedFunctionalsWeightedAdd(handle, weighted[WeightedN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
WeightedFunctionalsAssign(ConstHandle2WeightedFunctionals self, ConstHandle2ConstWeightedFunctionals from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
WeightedFunctionalsDelete(ConstHandle2ConstWeightedFunctionals self)
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
WeightedFunctionalsRead(ConstHandle2WeightedFunctionals self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
WeightedFunctionalsWrite(ConstHandle2ConstWeightedFunctionals self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
WeightedFunctionalsPrint(ConstHandle2ConstWeightedFunctionals self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
WeightedFunctionalsPrintXML(ConstHandle2ConstWeightedFunctionals self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
WeightedFunctionalsPrintJSON(ConstHandle2ConstWeightedFunctionals self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: weighted
// -----------------------------------------------------------------------------

// Has
int
WeightedFunctionalsWeightedHas(ConstHandle2ConstWeightedFunctionals self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"WeightedHas", self, extract::weighted);
}

// Clear
void
WeightedFunctionalsWeightedClear(ConstHandle2WeightedFunctionals self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"WeightedClear", self, extract::weighted);
}

// Size
size_t
WeightedFunctionalsWeightedSize(ConstHandle2ConstWeightedFunctionals self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"WeightedSize", self, extract::weighted);
}

// Add
void
WeightedFunctionalsWeightedAdd(ConstHandle2WeightedFunctionals self, ConstHandle2ConstWeighted weighted)
{
   detail::addToContainer<CPP,CPPWeighted>
      (CLASSNAME, CLASSNAME+"WeightedAdd", self, extract::weighted, weighted);
}

// Get, by index \in [0,size), const
Handle2ConstWeighted
WeightedFunctionalsWeightedGetConst(ConstHandle2ConstWeightedFunctionals self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstWeighted>
      (CLASSNAME, CLASSNAME+"WeightedGetConst", self, extract::weighted, index_);
}

// Get, by index \in [0,size), non-const
Handle2Weighted
WeightedFunctionalsWeightedGet(ConstHandle2WeightedFunctionals self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Weighted>
      (CLASSNAME, CLASSNAME+"WeightedGet", self, extract::weighted, index_);
}

// Set, by index \in [0,size)
void
WeightedFunctionalsWeightedSet(
   ConstHandle2WeightedFunctionals self,
   const size_t index_,
   ConstHandle2ConstWeighted weighted
) {
   detail::setByIndex<CPP,CPPWeighted>
      (CLASSNAME, CLASSNAME+"WeightedSet", self, extract::weighted, index_, weighted);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/WeightedFunctionals/src/custom.cpp"
