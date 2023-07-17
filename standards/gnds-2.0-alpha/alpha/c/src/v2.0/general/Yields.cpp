
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2.0/general/Yields.hpp"
#include "Yields.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = YieldsClass;
using CPP = multigroup::Yields;

static const std::string CLASSNAME = "Yields";

namespace extract {
   static auto nuclides = [](auto &obj) { return &obj.nuclides; };
   static auto values = [](auto &obj) { return &obj.values; };
   static auto uncertainty = [](auto &obj) { return &obj.uncertainty; };
}

using CPPNuclides = reduced::Nuclides;
using CPPValues = general::Values;
using CPPUncertainty = general::Uncertainty;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstYields
YieldsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Yields
YieldsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstYields
YieldsCreateConst(
   ConstHandle2ConstNuclides nuclides,
   ConstHandle2ConstValues values,
   ConstHandle2ConstUncertainty uncertainty
) {
   ConstHandle2Yields handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPNuclides>(nuclides),
      detail::tocpp<CPPValues>(values),
      detail::tocpp<CPPUncertainty>(uncertainty)
   );
   return handle;
}

// Create, general
Handle2Yields
YieldsCreate(
   ConstHandle2ConstNuclides nuclides,
   ConstHandle2ConstValues values,
   ConstHandle2ConstUncertainty uncertainty
) {
   ConstHandle2Yields handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPNuclides>(nuclides),
      detail::tocpp<CPPValues>(values),
      detail::tocpp<CPPUncertainty>(uncertainty)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
YieldsAssign(ConstHandle2Yields self, ConstHandle2ConstYields from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
YieldsDelete(ConstHandle2ConstYields self)
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
YieldsRead(ConstHandle2Yields self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
YieldsWrite(ConstHandle2ConstYields self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
YieldsPrint(ConstHandle2ConstYields self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
YieldsPrintXML(ConstHandle2ConstYields self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
YieldsPrintJSON(ConstHandle2ConstYields self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: nuclides
// -----------------------------------------------------------------------------

// Has
int
YieldsNuclidesHas(ConstHandle2ConstYields self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"NuclidesHas", self, extract::nuclides);
}

// Get, const
Handle2ConstNuclides
YieldsNuclidesGetConst(ConstHandle2ConstYields self)
{
   return detail::getField<CPP,Handle2ConstNuclides>
      (CLASSNAME, CLASSNAME+"NuclidesGetConst", self, extract::nuclides);
}

// Get, non-const
Handle2Nuclides
YieldsNuclidesGet(ConstHandle2Yields self)
{
   return detail::getField<CPP,Handle2Nuclides>
      (CLASSNAME, CLASSNAME+"NuclidesGet", self, extract::nuclides);
}

// Set
void
YieldsNuclidesSet(ConstHandle2Yields self, ConstHandle2ConstNuclides nuclides)
{
   detail::setField<CPP,CPPNuclides>
      (CLASSNAME, CLASSNAME+"NuclidesSet", self, extract::nuclides, nuclides);
}


// -----------------------------------------------------------------------------
// Child: values
// -----------------------------------------------------------------------------

// Has
int
YieldsValuesHas(ConstHandle2ConstYields self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ValuesHas", self, extract::values);
}

// Get, const
Handle2ConstValues
YieldsValuesGetConst(ConstHandle2ConstYields self)
{
   return detail::getField<CPP,Handle2ConstValues>
      (CLASSNAME, CLASSNAME+"ValuesGetConst", self, extract::values);
}

// Get, non-const
Handle2Values
YieldsValuesGet(ConstHandle2Yields self)
{
   return detail::getField<CPP,Handle2Values>
      (CLASSNAME, CLASSNAME+"ValuesGet", self, extract::values);
}

// Set
void
YieldsValuesSet(ConstHandle2Yields self, ConstHandle2ConstValues values)
{
   detail::setField<CPP,CPPValues>
      (CLASSNAME, CLASSNAME+"ValuesSet", self, extract::values, values);
}


// -----------------------------------------------------------------------------
// Child: uncertainty
// -----------------------------------------------------------------------------

// Has
int
YieldsUncertaintyHas(ConstHandle2ConstYields self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UncertaintyHas", self, extract::uncertainty);
}

// Get, const
Handle2ConstUncertainty
YieldsUncertaintyGetConst(ConstHandle2ConstYields self)
{
   return detail::getField<CPP,Handle2ConstUncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintyGetConst", self, extract::uncertainty);
}

// Get, non-const
Handle2Uncertainty
YieldsUncertaintyGet(ConstHandle2Yields self)
{
   return detail::getField<CPP,Handle2Uncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintyGet", self, extract::uncertainty);
}

// Set
void
YieldsUncertaintySet(ConstHandle2Yields self, ConstHandle2ConstUncertainty uncertainty)
{
   detail::setField<CPP,CPPUncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintySet", self, extract::uncertainty, uncertainty);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Yields/src/custom.cpp"
