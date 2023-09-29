
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/ResonancesWithBackground.hpp"
#include "ResonancesWithBackground.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = ResonancesWithBackgroundClass;
using CPP = multigroup::ResonancesWithBackground;

static const std::string CLASSNAME = "ResonancesWithBackground";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto resonances = [](auto &obj) { return &obj.resonances; };
   static auto background = [](auto &obj) { return &obj.background; };
   static auto uncertainty = [](auto &obj) { return &obj.uncertainty; };
}

using CPPResonances = general::Resonances;
using CPPBackground = general::Background;
using CPPUncertainty = general::Uncertainty;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstResonancesWithBackground
ResonancesWithBackgroundDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default, non-const
Handle2ResonancesWithBackground
ResonancesWithBackgroundDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstResonancesWithBackground
ResonancesWithBackgroundCreateConst(
   const char *const label,
   ConstHandle2ConstResonances resonances,
   ConstHandle2ConstBackground background,
   ConstHandle2ConstUncertainty uncertainty
) {
   ConstHandle2ResonancesWithBackground handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      detail::tocpp<CPPResonances>(resonances),
      detail::tocpp<CPPBackground>(background),
      detail::tocpp<CPPUncertainty>(uncertainty)
   );
   return handle;
}

// Create, general, non-const
Handle2ResonancesWithBackground
ResonancesWithBackgroundCreate(
   const char *const label,
   ConstHandle2ConstResonances resonances,
   ConstHandle2ConstBackground background,
   ConstHandle2ConstUncertainty uncertainty
) {
   ConstHandle2ResonancesWithBackground handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      detail::tocpp<CPPResonances>(resonances),
      detail::tocpp<CPPBackground>(background),
      detail::tocpp<CPPUncertainty>(uncertainty)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ResonancesWithBackgroundAssign(ConstHandle2ResonancesWithBackground self, ConstHandle2ConstResonancesWithBackground from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ResonancesWithBackgroundDelete(ConstHandle2ConstResonancesWithBackground self)
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
ResonancesWithBackgroundRead(ConstHandle2ResonancesWithBackground self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ResonancesWithBackgroundWrite(ConstHandle2ConstResonancesWithBackground self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ResonancesWithBackgroundPrint(ConstHandle2ConstResonancesWithBackground self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ResonancesWithBackgroundPrintXML(ConstHandle2ConstResonancesWithBackground self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ResonancesWithBackgroundPrintJSON(ConstHandle2ConstResonancesWithBackground self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
ResonancesWithBackgroundLabelHas(ConstHandle2ConstResonancesWithBackground self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
const char *
ResonancesWithBackgroundLabelGet(ConstHandle2ConstResonancesWithBackground self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
ResonancesWithBackgroundLabelSet(ConstHandle2ResonancesWithBackground self, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Child: resonances
// -----------------------------------------------------------------------------

// Has
int
ResonancesWithBackgroundResonancesHas(ConstHandle2ConstResonancesWithBackground self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ResonancesHas", self, extract::resonances);
}

// Get, const
Handle2ConstResonances
ResonancesWithBackgroundResonancesGetConst(ConstHandle2ConstResonancesWithBackground self)
{
   return detail::getField<CPP,Handle2ConstResonances>
      (CLASSNAME, CLASSNAME+"ResonancesGetConst", self, extract::resonances);
}

// Get, non-const
Handle2Resonances
ResonancesWithBackgroundResonancesGet(ConstHandle2ResonancesWithBackground self)
{
   return detail::getField<CPP,Handle2Resonances>
      (CLASSNAME, CLASSNAME+"ResonancesGet", self, extract::resonances);
}

// Set
void
ResonancesWithBackgroundResonancesSet(ConstHandle2ResonancesWithBackground self, ConstHandle2ConstResonances resonances)
{
   detail::setField<CPP,CPPResonances>
      (CLASSNAME, CLASSNAME+"ResonancesSet", self, extract::resonances, resonances);
}


// -----------------------------------------------------------------------------
// Child: background
// -----------------------------------------------------------------------------

// Has
int
ResonancesWithBackgroundBackgroundHas(ConstHandle2ConstResonancesWithBackground self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"BackgroundHas", self, extract::background);
}

// Get, const
Handle2ConstBackground
ResonancesWithBackgroundBackgroundGetConst(ConstHandle2ConstResonancesWithBackground self)
{
   return detail::getField<CPP,Handle2ConstBackground>
      (CLASSNAME, CLASSNAME+"BackgroundGetConst", self, extract::background);
}

// Get, non-const
Handle2Background
ResonancesWithBackgroundBackgroundGet(ConstHandle2ResonancesWithBackground self)
{
   return detail::getField<CPP,Handle2Background>
      (CLASSNAME, CLASSNAME+"BackgroundGet", self, extract::background);
}

// Set
void
ResonancesWithBackgroundBackgroundSet(ConstHandle2ResonancesWithBackground self, ConstHandle2ConstBackground background)
{
   detail::setField<CPP,CPPBackground>
      (CLASSNAME, CLASSNAME+"BackgroundSet", self, extract::background, background);
}


// -----------------------------------------------------------------------------
// Child: uncertainty
// -----------------------------------------------------------------------------

// Has
int
ResonancesWithBackgroundUncertaintyHas(ConstHandle2ConstResonancesWithBackground self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UncertaintyHas", self, extract::uncertainty);
}

// Get, const
Handle2ConstUncertainty
ResonancesWithBackgroundUncertaintyGetConst(ConstHandle2ConstResonancesWithBackground self)
{
   return detail::getField<CPP,Handle2ConstUncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintyGetConst", self, extract::uncertainty);
}

// Get, non-const
Handle2Uncertainty
ResonancesWithBackgroundUncertaintyGet(ConstHandle2ResonancesWithBackground self)
{
   return detail::getField<CPP,Handle2Uncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintyGet", self, extract::uncertainty);
}

// Set
void
ResonancesWithBackgroundUncertaintySet(ConstHandle2ResonancesWithBackground self, ConstHandle2ConstUncertainty uncertainty)
{
   detail::setField<CPP,CPPUncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintySet", self, extract::uncertainty, uncertainty);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/ResonancesWithBackground/src/custom.cpp"
