
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/TabulatedWidths.hpp"
#include "TabulatedWidths.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = TabulatedWidthsClass;
using CPP = multigroup::TabulatedWidths;

static const std::string CLASSNAME = "TabulatedWidths";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto approximation = [](auto &obj) { return &obj.approximation; };
   static auto useForSelfShieldingOnly = [](auto &obj) { return &obj.useForSelfShieldingOnly; };
   static auto resonanceReactions = [](auto &obj) { return &obj.resonanceReactions; };
   static auto Ls = [](auto &obj) { return &obj.Ls; };
   static auto PoPs = [](auto &obj) { return &obj.PoPs; };
   static auto scatteringRadius = [](auto &obj) { return &obj.scatteringRadius; };
}

using CPPResonanceReactions = general::ResonanceReactions;
using CPPLs = general::Ls;
using CPPPoPs = top::PoPs;
using CPPScatteringRadius = general::ScatteringRadius;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstTabulatedWidths
TabulatedWidthsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default, non-const
Handle2TabulatedWidths
TabulatedWidthsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstTabulatedWidths
TabulatedWidthsCreateConst(
   const char *const label,
   const char *const approximation,
   const bool useForSelfShieldingOnly,
   ConstHandle2ConstResonanceReactions resonanceReactions,
   ConstHandle2ConstLs Ls,
   ConstHandle2ConstPoPs PoPs,
   ConstHandle2ConstScatteringRadius scatteringRadius
) {
   ConstHandle2TabulatedWidths handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      approximation,
      useForSelfShieldingOnly,
      detail::tocpp<CPPResonanceReactions>(resonanceReactions),
      detail::tocpp<CPPLs>(Ls),
      detail::tocpp<CPPPoPs>(PoPs),
      detail::tocpp<CPPScatteringRadius>(scatteringRadius)
   );
   return handle;
}

// Create, general, non-const
Handle2TabulatedWidths
TabulatedWidthsCreate(
   const char *const label,
   const char *const approximation,
   const bool useForSelfShieldingOnly,
   ConstHandle2ConstResonanceReactions resonanceReactions,
   ConstHandle2ConstLs Ls,
   ConstHandle2ConstPoPs PoPs,
   ConstHandle2ConstScatteringRadius scatteringRadius
) {
   ConstHandle2TabulatedWidths handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      approximation,
      useForSelfShieldingOnly,
      detail::tocpp<CPPResonanceReactions>(resonanceReactions),
      detail::tocpp<CPPLs>(Ls),
      detail::tocpp<CPPPoPs>(PoPs),
      detail::tocpp<CPPScatteringRadius>(scatteringRadius)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
TabulatedWidthsAssign(ConstHandle2TabulatedWidths self, ConstHandle2ConstTabulatedWidths from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
TabulatedWidthsDelete(ConstHandle2ConstTabulatedWidths self)
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
TabulatedWidthsRead(ConstHandle2TabulatedWidths self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
TabulatedWidthsWrite(ConstHandle2ConstTabulatedWidths self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
TabulatedWidthsPrint(ConstHandle2ConstTabulatedWidths self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
TabulatedWidthsPrintXML(ConstHandle2ConstTabulatedWidths self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
TabulatedWidthsPrintJSON(ConstHandle2ConstTabulatedWidths self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
TabulatedWidthsLabelHas(ConstHandle2ConstTabulatedWidths self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
const char *
TabulatedWidthsLabelGet(ConstHandle2ConstTabulatedWidths self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
TabulatedWidthsLabelSet(ConstHandle2TabulatedWidths self, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: approximation
// -----------------------------------------------------------------------------

// Has
int
TabulatedWidthsApproximationHas(ConstHandle2ConstTabulatedWidths self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ApproximationHas", self, extract::approximation);
}

// Get
// Returns by value
const char *
TabulatedWidthsApproximationGet(ConstHandle2ConstTabulatedWidths self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ApproximationGet", self, extract::approximation);
}

// Set
void
TabulatedWidthsApproximationSet(ConstHandle2TabulatedWidths self, const char *const approximation)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ApproximationSet", self, extract::approximation, approximation);
}


// -----------------------------------------------------------------------------
// Metadatum: useForSelfShieldingOnly
// -----------------------------------------------------------------------------

// Has
int
TabulatedWidthsUseForSelfShieldingOnlyHas(ConstHandle2ConstTabulatedWidths self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UseForSelfShieldingOnlyHas", self, extract::useForSelfShieldingOnly);
}

// Get
// Returns by value
bool
TabulatedWidthsUseForSelfShieldingOnlyGet(ConstHandle2ConstTabulatedWidths self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"UseForSelfShieldingOnlyGet", self, extract::useForSelfShieldingOnly);
}

// Set
void
TabulatedWidthsUseForSelfShieldingOnlySet(ConstHandle2TabulatedWidths self, const bool useForSelfShieldingOnly)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"UseForSelfShieldingOnlySet", self, extract::useForSelfShieldingOnly, useForSelfShieldingOnly);
}


// -----------------------------------------------------------------------------
// Child: resonanceReactions
// -----------------------------------------------------------------------------

// Has
int
TabulatedWidthsResonanceReactionsHas(ConstHandle2ConstTabulatedWidths self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ResonanceReactionsHas", self, extract::resonanceReactions);
}

// Get, const
Handle2ConstResonanceReactions
TabulatedWidthsResonanceReactionsGetConst(ConstHandle2ConstTabulatedWidths self)
{
   return detail::getField<CPP,Handle2ConstResonanceReactions>
      (CLASSNAME, CLASSNAME+"ResonanceReactionsGetConst", self, extract::resonanceReactions);
}

// Get, non-const
Handle2ResonanceReactions
TabulatedWidthsResonanceReactionsGet(ConstHandle2TabulatedWidths self)
{
   return detail::getField<CPP,Handle2ResonanceReactions>
      (CLASSNAME, CLASSNAME+"ResonanceReactionsGet", self, extract::resonanceReactions);
}

// Set
void
TabulatedWidthsResonanceReactionsSet(ConstHandle2TabulatedWidths self, ConstHandle2ConstResonanceReactions resonanceReactions)
{
   detail::setField<CPP,CPPResonanceReactions>
      (CLASSNAME, CLASSNAME+"ResonanceReactionsSet", self, extract::resonanceReactions, resonanceReactions);
}


// -----------------------------------------------------------------------------
// Child: Ls
// -----------------------------------------------------------------------------

// Has
int
TabulatedWidthsLsHas(ConstHandle2ConstTabulatedWidths self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LsHas", self, extract::Ls);
}

// Get, const
Handle2ConstLs
TabulatedWidthsLsGetConst(ConstHandle2ConstTabulatedWidths self)
{
   return detail::getField<CPP,Handle2ConstLs>
      (CLASSNAME, CLASSNAME+"LsGetConst", self, extract::Ls);
}

// Get, non-const
Handle2Ls
TabulatedWidthsLsGet(ConstHandle2TabulatedWidths self)
{
   return detail::getField<CPP,Handle2Ls>
      (CLASSNAME, CLASSNAME+"LsGet", self, extract::Ls);
}

// Set
void
TabulatedWidthsLsSet(ConstHandle2TabulatedWidths self, ConstHandle2ConstLs Ls)
{
   detail::setField<CPP,CPPLs>
      (CLASSNAME, CLASSNAME+"LsSet", self, extract::Ls, Ls);
}


// -----------------------------------------------------------------------------
// Child: PoPs
// -----------------------------------------------------------------------------

// Has
int
TabulatedWidthsPoPsHas(ConstHandle2ConstTabulatedWidths self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"PoPsHas", self, extract::PoPs);
}

// Get, const
Handle2ConstPoPs
TabulatedWidthsPoPsGetConst(ConstHandle2ConstTabulatedWidths self)
{
   return detail::getField<CPP,Handle2ConstPoPs>
      (CLASSNAME, CLASSNAME+"PoPsGetConst", self, extract::PoPs);
}

// Get, non-const
Handle2PoPs
TabulatedWidthsPoPsGet(ConstHandle2TabulatedWidths self)
{
   return detail::getField<CPP,Handle2PoPs>
      (CLASSNAME, CLASSNAME+"PoPsGet", self, extract::PoPs);
}

// Set
void
TabulatedWidthsPoPsSet(ConstHandle2TabulatedWidths self, ConstHandle2ConstPoPs PoPs)
{
   detail::setField<CPP,CPPPoPs>
      (CLASSNAME, CLASSNAME+"PoPsSet", self, extract::PoPs, PoPs);
}


// -----------------------------------------------------------------------------
// Child: scatteringRadius
// -----------------------------------------------------------------------------

// Has
int
TabulatedWidthsScatteringRadiusHas(ConstHandle2ConstTabulatedWidths self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ScatteringRadiusHas", self, extract::scatteringRadius);
}

// Get, const
Handle2ConstScatteringRadius
TabulatedWidthsScatteringRadiusGetConst(ConstHandle2ConstTabulatedWidths self)
{
   return detail::getField<CPP,Handle2ConstScatteringRadius>
      (CLASSNAME, CLASSNAME+"ScatteringRadiusGetConst", self, extract::scatteringRadius);
}

// Get, non-const
Handle2ScatteringRadius
TabulatedWidthsScatteringRadiusGet(ConstHandle2TabulatedWidths self)
{
   return detail::getField<CPP,Handle2ScatteringRadius>
      (CLASSNAME, CLASSNAME+"ScatteringRadiusGet", self, extract::scatteringRadius);
}

// Set
void
TabulatedWidthsScatteringRadiusSet(ConstHandle2TabulatedWidths self, ConstHandle2ConstScatteringRadius scatteringRadius)
{
   detail::setField<CPP,CPPScatteringRadius>
      (CLASSNAME, CLASSNAME+"ScatteringRadiusSet", self, extract::scatteringRadius, scatteringRadius);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/TabulatedWidths/src/custom.cpp"