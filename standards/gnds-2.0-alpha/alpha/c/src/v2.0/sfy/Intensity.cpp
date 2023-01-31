
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/sfy/Intensity.hpp"
#include "Intensity.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = IntensityClass;
using CPP = multigroup::Intensity;

static const std::string CLASSNAME = "Intensity";

namespace extract {
   static auto value = [](auto &obj) { return &obj.value; };
   static auto uncertainty = [](auto &obj) { return &obj.uncertainty; };
}

using CPPUncertainty = common::Uncertainty;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstIntensity
IntensityDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Intensity
IntensityDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstIntensity
IntensityCreateConst(
   const double value,
   ConstHandle2ConstUncertainty uncertainty
) {
   ConstHandle2Intensity handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      value,
      detail::tocpp<CPPUncertainty>(uncertainty)
   );
   return handle;
}

// Create, general
Handle2Intensity
IntensityCreate(
   const double value,
   ConstHandle2ConstUncertainty uncertainty
) {
   ConstHandle2Intensity handle = detail::createHandle<CPP,C>(
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
IntensityAssign(ConstHandle2Intensity This, ConstHandle2ConstIntensity from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
IntensityDelete(ConstHandle2ConstIntensity This)
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
IntensityRead(ConstHandle2Intensity This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
IntensityWrite(ConstHandle2ConstIntensity This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
IntensityPrint(ConstHandle2ConstIntensity This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
IntensityPrintXML(ConstHandle2ConstIntensity This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
IntensityPrintJSON(ConstHandle2ConstIntensity This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// Has
int
IntensityValueHas(ConstHandle2ConstIntensity This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ValueHas", This, extract::value);
}

// Get
// Returns by value
double
IntensityValueGet(ConstHandle2ConstIntensity This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ValueGet", This, extract::value);
}

// Set
void
IntensityValueSet(ConstHandle2Intensity This, const double value)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ValueSet", This, extract::value, value);
}


// -----------------------------------------------------------------------------
// Child: uncertainty
// -----------------------------------------------------------------------------

// Has
int
IntensityUncertaintyHas(ConstHandle2ConstIntensity This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UncertaintyHas", This, extract::uncertainty);
}

// Get, const
Handle2ConstUncertainty
IntensityUncertaintyGetConst(ConstHandle2ConstIntensity This)
{
   return detail::getField<CPP,Handle2ConstUncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintyGetConst", This, extract::uncertainty);
}

// Get, non-const
Handle2Uncertainty
IntensityUncertaintyGet(ConstHandle2Intensity This)
{
   return detail::getField<CPP,Handle2Uncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintyGet", This, extract::uncertainty);
}

// Set
void
IntensityUncertaintySet(ConstHandle2Intensity This, ConstHandle2ConstUncertainty uncertainty)
{
   detail::setField<CPP,CPPUncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintySet", This, extract::uncertainty, uncertainty);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/sfy/Intensity/src/custom.cpp"
