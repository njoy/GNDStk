
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/transport/DiscreteGamma.hpp"
#include "DiscreteGamma.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = DiscreteGammaClass;
using CPP = multigroup::DiscreteGamma;

static const std::string CLASSNAME = "DiscreteGamma";

namespace extract {
   static auto domainMax = [](auto &obj) { return &obj.domainMax; };
   static auto domainMin = [](auto &obj) { return &obj.domainMin; };
   static auto value = [](auto &obj) { return &obj.value; };
   static auto axes = [](auto &obj) { return &obj.axes; };
}

using CPPAxes = containers::Axes;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstDiscreteGamma
DiscreteGammaDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2DiscreteGamma
DiscreteGammaDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstDiscreteGamma
DiscreteGammaCreateConst(
   const Float64 domainMax,
   const Float64 domainMin,
   const Float64 value,
   ConstHandle2ConstAxes axes
) {
   ConstHandle2DiscreteGamma handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      domainMax,
      domainMin,
      value,
      detail::tocpp<CPPAxes>(axes)
   );
   return handle;
}

// Create, general
Handle2DiscreteGamma
DiscreteGammaCreate(
   const Float64 domainMax,
   const Float64 domainMin,
   const Float64 value,
   ConstHandle2ConstAxes axes
) {
   ConstHandle2DiscreteGamma handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      domainMax,
      domainMin,
      value,
      detail::tocpp<CPPAxes>(axes)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
DiscreteGammaAssign(ConstHandle2DiscreteGamma self, ConstHandle2ConstDiscreteGamma from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
DiscreteGammaDelete(ConstHandle2ConstDiscreteGamma self)
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
DiscreteGammaRead(ConstHandle2DiscreteGamma self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
DiscreteGammaWrite(ConstHandle2ConstDiscreteGamma self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
DiscreteGammaPrint(ConstHandle2ConstDiscreteGamma self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
DiscreteGammaPrintXML(ConstHandle2ConstDiscreteGamma self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
DiscreteGammaPrintJSON(ConstHandle2ConstDiscreteGamma self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: domainMax
// -----------------------------------------------------------------------------

// Has
int
DiscreteGammaDomainMaxHas(ConstHandle2ConstDiscreteGamma self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMaxHas", self, extract::domainMax);
}

// Get
// Returns by value
Float64
DiscreteGammaDomainMaxGet(ConstHandle2ConstDiscreteGamma self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMaxGet", self, extract::domainMax);
}

// Set
void
DiscreteGammaDomainMaxSet(ConstHandle2DiscreteGamma self, const Float64 domainMax)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMaxSet", self, extract::domainMax, domainMax);
}


// -----------------------------------------------------------------------------
// Metadatum: domainMin
// -----------------------------------------------------------------------------

// Has
int
DiscreteGammaDomainMinHas(ConstHandle2ConstDiscreteGamma self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMinHas", self, extract::domainMin);
}

// Get
// Returns by value
Float64
DiscreteGammaDomainMinGet(ConstHandle2ConstDiscreteGamma self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMinGet", self, extract::domainMin);
}

// Set
void
DiscreteGammaDomainMinSet(ConstHandle2DiscreteGamma self, const Float64 domainMin)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMinSet", self, extract::domainMin, domainMin);
}


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// Has
int
DiscreteGammaValueHas(ConstHandle2ConstDiscreteGamma self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ValueHas", self, extract::value);
}

// Get
// Returns by value
Float64
DiscreteGammaValueGet(ConstHandle2ConstDiscreteGamma self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ValueGet", self, extract::value);
}

// Set
void
DiscreteGammaValueSet(ConstHandle2DiscreteGamma self, const Float64 value)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ValueSet", self, extract::value, value);
}


// -----------------------------------------------------------------------------
// Child: axes
// -----------------------------------------------------------------------------

// Has
int
DiscreteGammaAxesHas(ConstHandle2ConstDiscreteGamma self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AxesHas", self, extract::axes);
}

// Get, const
Handle2ConstAxes
DiscreteGammaAxesGetConst(ConstHandle2ConstDiscreteGamma self)
{
   return detail::getField<CPP,Handle2ConstAxes>
      (CLASSNAME, CLASSNAME+"AxesGetConst", self, extract::axes);
}

// Get, non-const
Handle2Axes
DiscreteGammaAxesGet(ConstHandle2DiscreteGamma self)
{
   return detail::getField<CPP,Handle2Axes>
      (CLASSNAME, CLASSNAME+"AxesGet", self, extract::axes);
}

// Set
void
DiscreteGammaAxesSet(ConstHandle2DiscreteGamma self, ConstHandle2ConstAxes axes)
{
   detail::setField<CPP,CPPAxes>
      (CLASSNAME, CLASSNAME+"AxesSet", self, extract::axes, axes);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/transport/DiscreteGamma/src/custom.cpp"
