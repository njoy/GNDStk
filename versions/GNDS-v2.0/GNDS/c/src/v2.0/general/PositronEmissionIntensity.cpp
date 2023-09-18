
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/PositronEmissionIntensity.hpp"
#include "PositronEmissionIntensity.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = PositronEmissionIntensityClass;
using CPP = multigroup::PositronEmissionIntensity;

static const std::string CLASSNAME = "PositronEmissionIntensity";

namespace extract {
   static auto value = [](auto &obj) { return &obj.value; };
   static auto uncertainty = [](auto &obj) { return &obj.uncertainty; };
}

using CPPUncertainty = general::Uncertainty;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstPositronEmissionIntensity
PositronEmissionIntensityDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2PositronEmissionIntensity
PositronEmissionIntensityDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstPositronEmissionIntensity
PositronEmissionIntensityCreateConst(
   const double value,
   ConstHandle2ConstUncertainty uncertainty
) {
   ConstHandle2PositronEmissionIntensity handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      value,
      detail::tocpp<CPPUncertainty>(uncertainty)
   );
   return handle;
}

// Create, general
Handle2PositronEmissionIntensity
PositronEmissionIntensityCreate(
   const double value,
   ConstHandle2ConstUncertainty uncertainty
) {
   ConstHandle2PositronEmissionIntensity handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      value,
      detail::tocpp<CPPUncertainty>(uncertainty)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
PositronEmissionIntensityAssign(ConstHandle2PositronEmissionIntensity self, ConstHandle2ConstPositronEmissionIntensity from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
PositronEmissionIntensityDelete(ConstHandle2ConstPositronEmissionIntensity self)
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
PositronEmissionIntensityRead(ConstHandle2PositronEmissionIntensity self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
PositronEmissionIntensityWrite(ConstHandle2ConstPositronEmissionIntensity self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
PositronEmissionIntensityPrint(ConstHandle2ConstPositronEmissionIntensity self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
PositronEmissionIntensityPrintXML(ConstHandle2ConstPositronEmissionIntensity self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
PositronEmissionIntensityPrintJSON(ConstHandle2ConstPositronEmissionIntensity self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// Has
int
PositronEmissionIntensityValueHas(ConstHandle2ConstPositronEmissionIntensity self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ValueHas", self, extract::value);
}

// Get
// Returns by value
double
PositronEmissionIntensityValueGet(ConstHandle2ConstPositronEmissionIntensity self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ValueGet", self, extract::value);
}

// Set
void
PositronEmissionIntensityValueSet(ConstHandle2PositronEmissionIntensity self, const double value)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ValueSet", self, extract::value, value);
}


// -----------------------------------------------------------------------------
// Child: uncertainty
// -----------------------------------------------------------------------------

// Has
int
PositronEmissionIntensityUncertaintyHas(ConstHandle2ConstPositronEmissionIntensity self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UncertaintyHas", self, extract::uncertainty);
}

// Get, const
Handle2ConstUncertainty
PositronEmissionIntensityUncertaintyGetConst(ConstHandle2ConstPositronEmissionIntensity self)
{
   return detail::getField<CPP,Handle2ConstUncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintyGetConst", self, extract::uncertainty);
}

// Get
Handle2Uncertainty
PositronEmissionIntensityUncertaintyGet(ConstHandle2PositronEmissionIntensity self)
{
   return detail::getField<CPP,Handle2Uncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintyGet", self, extract::uncertainty);
}

// Set
void
PositronEmissionIntensityUncertaintySet(ConstHandle2PositronEmissionIntensity self, ConstHandle2ConstUncertainty uncertainty)
{
   detail::setField<CPP,CPPUncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintySet", self, extract::uncertainty, uncertainty);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/PositronEmissionIntensity/src/custom.cpp"
