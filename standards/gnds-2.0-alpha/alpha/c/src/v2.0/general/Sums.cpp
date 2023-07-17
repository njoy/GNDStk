
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2.0/general/Sums.hpp"
#include "Sums.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = SumsClass;
using CPP = multigroup::Sums;

static const std::string CLASSNAME = "Sums";

namespace extract {
   static auto crossSectionSums = [](auto &obj) { return &obj.crossSectionSums; };
   static auto multiplicitySums = [](auto &obj) { return &obj.multiplicitySums; };
}

using CPPCrossSectionSums = general::CrossSectionSums;
using CPPMultiplicitySums = general::MultiplicitySums;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstSums
SumsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Sums
SumsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstSums
SumsCreateConst(
   ConstHandle2ConstCrossSectionSums crossSectionSums,
   ConstHandle2ConstMultiplicitySums multiplicitySums
) {
   ConstHandle2Sums handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPCrossSectionSums>(crossSectionSums),
      detail::tocpp<CPPMultiplicitySums>(multiplicitySums)
   );
   return handle;
}

// Create, general
Handle2Sums
SumsCreate(
   ConstHandle2ConstCrossSectionSums crossSectionSums,
   ConstHandle2ConstMultiplicitySums multiplicitySums
) {
   ConstHandle2Sums handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPCrossSectionSums>(crossSectionSums),
      detail::tocpp<CPPMultiplicitySums>(multiplicitySums)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
SumsAssign(ConstHandle2Sums self, ConstHandle2ConstSums from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
SumsDelete(ConstHandle2ConstSums self)
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
SumsRead(ConstHandle2Sums self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
SumsWrite(ConstHandle2ConstSums self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
SumsPrint(ConstHandle2ConstSums self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
SumsPrintXML(ConstHandle2ConstSums self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
SumsPrintJSON(ConstHandle2ConstSums self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: crossSectionSums
// -----------------------------------------------------------------------------

// Has
int
SumsCrossSectionSumsHas(ConstHandle2ConstSums self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CrossSectionSumsHas", self, extract::crossSectionSums);
}

// Get, const
Handle2ConstCrossSectionSums
SumsCrossSectionSumsGetConst(ConstHandle2ConstSums self)
{
   return detail::getField<CPP,Handle2ConstCrossSectionSums>
      (CLASSNAME, CLASSNAME+"CrossSectionSumsGetConst", self, extract::crossSectionSums);
}

// Get, non-const
Handle2CrossSectionSums
SumsCrossSectionSumsGet(ConstHandle2Sums self)
{
   return detail::getField<CPP,Handle2CrossSectionSums>
      (CLASSNAME, CLASSNAME+"CrossSectionSumsGet", self, extract::crossSectionSums);
}

// Set
void
SumsCrossSectionSumsSet(ConstHandle2Sums self, ConstHandle2ConstCrossSectionSums crossSectionSums)
{
   detail::setField<CPP,CPPCrossSectionSums>
      (CLASSNAME, CLASSNAME+"CrossSectionSumsSet", self, extract::crossSectionSums, crossSectionSums);
}


// -----------------------------------------------------------------------------
// Child: multiplicitySums
// -----------------------------------------------------------------------------

// Has
int
SumsMultiplicitySumsHas(ConstHandle2ConstSums self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"MultiplicitySumsHas", self, extract::multiplicitySums);
}

// Get, const
Handle2ConstMultiplicitySums
SumsMultiplicitySumsGetConst(ConstHandle2ConstSums self)
{
   return detail::getField<CPP,Handle2ConstMultiplicitySums>
      (CLASSNAME, CLASSNAME+"MultiplicitySumsGetConst", self, extract::multiplicitySums);
}

// Get, non-const
Handle2MultiplicitySums
SumsMultiplicitySumsGet(ConstHandle2Sums self)
{
   return detail::getField<CPP,Handle2MultiplicitySums>
      (CLASSNAME, CLASSNAME+"MultiplicitySumsGet", self, extract::multiplicitySums);
}

// Set
void
SumsMultiplicitySumsSet(ConstHandle2Sums self, ConstHandle2ConstMultiplicitySums multiplicitySums)
{
   detail::setField<CPP,CPPMultiplicitySums>
      (CLASSNAME, CLASSNAME+"MultiplicitySumsSet", self, extract::multiplicitySums, multiplicitySums);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Sums/src/custom.cpp"
