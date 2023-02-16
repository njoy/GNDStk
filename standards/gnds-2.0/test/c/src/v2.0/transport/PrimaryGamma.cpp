
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/transport/PrimaryGamma.hpp"
#include "PrimaryGamma.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = PrimaryGammaClass;
using CPP = multigroup::PrimaryGamma;

static const std::string CLASSNAME = "PrimaryGamma";

namespace extract {
   static auto domainMax = [](auto &obj) { return &obj.domainMax; };
   static auto domainMin = [](auto &obj) { return &obj.domainMin; };
   static auto value = [](auto &obj) { return &obj.value; };
   static auto finalState = [](auto &obj) { return &obj.finalState; };
   static auto axes = [](auto &obj) { return &obj.axes; };
}

using CPPAxes = containers::Axes;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstPrimaryGamma
PrimaryGammaDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2PrimaryGamma
PrimaryGammaDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstPrimaryGamma
PrimaryGammaCreateConst(
   const Float64 domainMax,
   const Float64 domainMin,
   const Float64 value,
   const XMLName finalState,
   ConstHandle2ConstAxes axes
) {
   ConstHandle2PrimaryGamma handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      domainMax,
      domainMin,
      value,
      finalState,
      detail::tocpp<CPPAxes>(axes)
   );
   return handle;
}

// Create, general
Handle2PrimaryGamma
PrimaryGammaCreate(
   const Float64 domainMax,
   const Float64 domainMin,
   const Float64 value,
   const XMLName finalState,
   ConstHandle2ConstAxes axes
) {
   ConstHandle2PrimaryGamma handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      domainMax,
      domainMin,
      value,
      finalState,
      detail::tocpp<CPPAxes>(axes)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
PrimaryGammaAssign(ConstHandle2PrimaryGamma self, ConstHandle2ConstPrimaryGamma from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
PrimaryGammaDelete(ConstHandle2ConstPrimaryGamma self)
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
PrimaryGammaRead(ConstHandle2PrimaryGamma self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
PrimaryGammaWrite(ConstHandle2ConstPrimaryGamma self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
PrimaryGammaPrint(ConstHandle2ConstPrimaryGamma self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
PrimaryGammaPrintXML(ConstHandle2ConstPrimaryGamma self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
PrimaryGammaPrintJSON(ConstHandle2ConstPrimaryGamma self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: domainMax
// -----------------------------------------------------------------------------

// Has
int
PrimaryGammaDomainMaxHas(ConstHandle2ConstPrimaryGamma self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMaxHas", self, extract::domainMax);
}

// Get
// Returns by value
Float64
PrimaryGammaDomainMaxGet(ConstHandle2ConstPrimaryGamma self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMaxGet", self, extract::domainMax);
}

// Set
void
PrimaryGammaDomainMaxSet(ConstHandle2PrimaryGamma self, const Float64 domainMax)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMaxSet", self, extract::domainMax, domainMax);
}


// -----------------------------------------------------------------------------
// Metadatum: domainMin
// -----------------------------------------------------------------------------

// Has
int
PrimaryGammaDomainMinHas(ConstHandle2ConstPrimaryGamma self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMinHas", self, extract::domainMin);
}

// Get
// Returns by value
Float64
PrimaryGammaDomainMinGet(ConstHandle2ConstPrimaryGamma self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMinGet", self, extract::domainMin);
}

// Set
void
PrimaryGammaDomainMinSet(ConstHandle2PrimaryGamma self, const Float64 domainMin)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMinSet", self, extract::domainMin, domainMin);
}


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// Has
int
PrimaryGammaValueHas(ConstHandle2ConstPrimaryGamma self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ValueHas", self, extract::value);
}

// Get
// Returns by value
Float64
PrimaryGammaValueGet(ConstHandle2ConstPrimaryGamma self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ValueGet", self, extract::value);
}

// Set
void
PrimaryGammaValueSet(ConstHandle2PrimaryGamma self, const Float64 value)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ValueSet", self, extract::value, value);
}


// -----------------------------------------------------------------------------
// Metadatum: finalState
// -----------------------------------------------------------------------------

// Has
int
PrimaryGammaFinalStateHas(ConstHandle2ConstPrimaryGamma self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"FinalStateHas", self, extract::finalState);
}

// Get
// Returns by value
XMLName
PrimaryGammaFinalStateGet(ConstHandle2ConstPrimaryGamma self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"FinalStateGet", self, extract::finalState);
}

// Set
void
PrimaryGammaFinalStateSet(ConstHandle2PrimaryGamma self, const XMLName finalState)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"FinalStateSet", self, extract::finalState, finalState);
}


// -----------------------------------------------------------------------------
// Child: axes
// -----------------------------------------------------------------------------

// Has
int
PrimaryGammaAxesHas(ConstHandle2ConstPrimaryGamma self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AxesHas", self, extract::axes);
}

// Get, const
Handle2ConstAxes
PrimaryGammaAxesGetConst(ConstHandle2ConstPrimaryGamma self)
{
   return detail::getField<CPP,Handle2ConstAxes>
      (CLASSNAME, CLASSNAME+"AxesGetConst", self, extract::axes);
}

// Get, non-const
Handle2Axes
PrimaryGammaAxesGet(ConstHandle2PrimaryGamma self)
{
   return detail::getField<CPP,Handle2Axes>
      (CLASSNAME, CLASSNAME+"AxesGet", self, extract::axes);
}

// Set
void
PrimaryGammaAxesSet(ConstHandle2PrimaryGamma self, ConstHandle2ConstAxes axes)
{
   detail::setField<CPP,CPPAxes>
      (CLASSNAME, CLASSNAME+"AxesSet", self, extract::axes, axes);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/transport/PrimaryGamma/src/custom.cpp"
