
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/BreitWigner.hpp"
#include "BreitWigner.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = BreitWignerClass;
using CPP = multigroup::BreitWigner;

static const std::string CLASSNAME = "BreitWigner";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto approximation = [](auto &obj) { return &obj.approximation; };
   static auto calculateChannelRadius = [](auto &obj) { return &obj.calculateChannelRadius; };
   static auto resonanceParameters = [](auto &obj) { return &obj.resonanceParameters; };
   static auto PoPs = [](auto &obj) { return &obj.PoPs; };
   static auto scatteringRadius = [](auto &obj) { return &obj.scatteringRadius; };
}

using CPPResonanceParameters = general::ResonanceParameters;
using CPPPoPs = top::PoPs;
using CPPScatteringRadius = general::ScatteringRadius;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstBreitWigner
BreitWignerDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2BreitWigner
BreitWignerDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstBreitWigner
BreitWignerCreateConst(
   const char *const label,
   const char *const approximation,
   const bool calculateChannelRadius,
   ConstHandle2ConstResonanceParameters resonanceParameters,
   ConstHandle2ConstPoPs PoPs,
   ConstHandle2ConstScatteringRadius scatteringRadius
) {
   ConstHandle2BreitWigner handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      approximation,
      calculateChannelRadius,
      detail::tocpp<CPPResonanceParameters>(resonanceParameters),
      detail::tocpp<CPPPoPs>(PoPs),
      detail::tocpp<CPPScatteringRadius>(scatteringRadius)
   );
   return handle;
}

// Create, general
Handle2BreitWigner
BreitWignerCreate(
   const char *const label,
   const char *const approximation,
   const bool calculateChannelRadius,
   ConstHandle2ConstResonanceParameters resonanceParameters,
   ConstHandle2ConstPoPs PoPs,
   ConstHandle2ConstScatteringRadius scatteringRadius
) {
   ConstHandle2BreitWigner handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      approximation,
      calculateChannelRadius,
      detail::tocpp<CPPResonanceParameters>(resonanceParameters),
      detail::tocpp<CPPPoPs>(PoPs),
      detail::tocpp<CPPScatteringRadius>(scatteringRadius)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
BreitWignerAssign(ConstHandle2BreitWigner This, ConstHandle2ConstBreitWigner from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
BreitWignerDelete(ConstHandle2ConstBreitWigner This)
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
BreitWignerRead(ConstHandle2BreitWigner This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
BreitWignerWrite(ConstHandle2ConstBreitWigner This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
BreitWignerPrint(ConstHandle2ConstBreitWigner This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
BreitWignerPrintXML(ConstHandle2ConstBreitWigner This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
BreitWignerPrintJSON(ConstHandle2ConstBreitWigner This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
BreitWignerLabelHas(ConstHandle2ConstBreitWigner This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
const char *
BreitWignerLabelGet(ConstHandle2ConstBreitWigner This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
BreitWignerLabelSet(ConstHandle2BreitWigner This, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: approximation
// -----------------------------------------------------------------------------

// Has
int
BreitWignerApproximationHas(ConstHandle2ConstBreitWigner This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ApproximationHas", This, extract::approximation);
}

// Get
// Returns by value
const char *
BreitWignerApproximationGet(ConstHandle2ConstBreitWigner This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ApproximationGet", This, extract::approximation);
}

// Set
void
BreitWignerApproximationSet(ConstHandle2BreitWigner This, const char *const approximation)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ApproximationSet", This, extract::approximation, approximation);
}


// -----------------------------------------------------------------------------
// Metadatum: calculateChannelRadius
// -----------------------------------------------------------------------------

// Has
int
BreitWignerCalculateChannelRadiusHas(ConstHandle2ConstBreitWigner This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CalculateChannelRadiusHas", This, extract::calculateChannelRadius);
}

// Get
// Returns by value
bool
BreitWignerCalculateChannelRadiusGet(ConstHandle2ConstBreitWigner This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"CalculateChannelRadiusGet", This, extract::calculateChannelRadius);
}

// Set
void
BreitWignerCalculateChannelRadiusSet(ConstHandle2BreitWigner This, const bool calculateChannelRadius)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"CalculateChannelRadiusSet", This, extract::calculateChannelRadius, calculateChannelRadius);
}


// -----------------------------------------------------------------------------
// Child: resonanceParameters
// -----------------------------------------------------------------------------

// Has
int
BreitWignerResonanceParametersHas(ConstHandle2ConstBreitWigner This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ResonanceParametersHas", This, extract::resonanceParameters);
}

// Get, const
Handle2ConstResonanceParameters
BreitWignerResonanceParametersGetConst(ConstHandle2ConstBreitWigner This)
{
   return detail::getField<CPP,Handle2ConstResonanceParameters>
      (CLASSNAME, CLASSNAME+"ResonanceParametersGetConst", This, extract::resonanceParameters);
}

// Get, non-const
Handle2ResonanceParameters
BreitWignerResonanceParametersGet(ConstHandle2BreitWigner This)
{
   return detail::getField<CPP,Handle2ResonanceParameters>
      (CLASSNAME, CLASSNAME+"ResonanceParametersGet", This, extract::resonanceParameters);
}

// Set
void
BreitWignerResonanceParametersSet(ConstHandle2BreitWigner This, ConstHandle2ConstResonanceParameters resonanceParameters)
{
   detail::setField<CPP,CPPResonanceParameters>
      (CLASSNAME, CLASSNAME+"ResonanceParametersSet", This, extract::resonanceParameters, resonanceParameters);
}


// -----------------------------------------------------------------------------
// Child: PoPs
// -----------------------------------------------------------------------------

// Has
int
BreitWignerPoPsHas(ConstHandle2ConstBreitWigner This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"PoPsHas", This, extract::PoPs);
}

// Get, const
Handle2ConstPoPs
BreitWignerPoPsGetConst(ConstHandle2ConstBreitWigner This)
{
   return detail::getField<CPP,Handle2ConstPoPs>
      (CLASSNAME, CLASSNAME+"PoPsGetConst", This, extract::PoPs);
}

// Get, non-const
Handle2PoPs
BreitWignerPoPsGet(ConstHandle2BreitWigner This)
{
   return detail::getField<CPP,Handle2PoPs>
      (CLASSNAME, CLASSNAME+"PoPsGet", This, extract::PoPs);
}

// Set
void
BreitWignerPoPsSet(ConstHandle2BreitWigner This, ConstHandle2ConstPoPs PoPs)
{
   detail::setField<CPP,CPPPoPs>
      (CLASSNAME, CLASSNAME+"PoPsSet", This, extract::PoPs, PoPs);
}


// -----------------------------------------------------------------------------
// Child: scatteringRadius
// -----------------------------------------------------------------------------

// Has
int
BreitWignerScatteringRadiusHas(ConstHandle2ConstBreitWigner This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ScatteringRadiusHas", This, extract::scatteringRadius);
}

// Get, const
Handle2ConstScatteringRadius
BreitWignerScatteringRadiusGetConst(ConstHandle2ConstBreitWigner This)
{
   return detail::getField<CPP,Handle2ConstScatteringRadius>
      (CLASSNAME, CLASSNAME+"ScatteringRadiusGetConst", This, extract::scatteringRadius);
}

// Get, non-const
Handle2ScatteringRadius
BreitWignerScatteringRadiusGet(ConstHandle2BreitWigner This)
{
   return detail::getField<CPP,Handle2ScatteringRadius>
      (CLASSNAME, CLASSNAME+"ScatteringRadiusGet", This, extract::scatteringRadius);
}

// Set
void
BreitWignerScatteringRadiusSet(ConstHandle2BreitWigner This, ConstHandle2ConstScatteringRadius scatteringRadius)
{
   detail::setField<CPP,CPPScatteringRadius>
      (CLASSNAME, CLASSNAME+"ScatteringRadiusSet", This, extract::scatteringRadius, scatteringRadius);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/BreitWigner/src/custom.cpp"
