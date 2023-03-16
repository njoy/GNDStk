
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/transport/ResonancesWithBackground.hpp"
#include "ResonancesWithBackground.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = ResonancesWithBackgroundClass;
using CPP = multigroup::ResonancesWithBackground;

static const std::string CLASSNAME = "ResonancesWithBackground";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto resonancesLink = [](auto &obj) { return &obj.resonancesLink; };
   static auto background = [](auto &obj) { return &obj.background; };
   static auto uncertainty = [](auto &obj) { return &obj.uncertainty; };
}

using CPPResonancesLink = transport::ResonancesLink;
using CPPBackground = transport::Background;
using CPPUncertainty = containers::Uncertainty;


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

// Create, default
Handle2ResonancesWithBackground
ResonancesWithBackgroundDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstResonancesWithBackground
ResonancesWithBackgroundCreateConst(
   const XMLName label,
   ConstHandle2ConstResonancesLink resonancesLink,
   ConstHandle2ConstBackground background,
   ConstHandle2ConstUncertainty uncertainty
) {
   ConstHandle2ResonancesWithBackground handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      detail::tocpp<CPPResonancesLink>(resonancesLink),
      detail::tocpp<CPPBackground>(background),
      detail::tocpp<CPPUncertainty>(uncertainty)
   );
   return handle;
}

// Create, general
Handle2ResonancesWithBackground
ResonancesWithBackgroundCreate(
   const XMLName label,
   ConstHandle2ConstResonancesLink resonancesLink,
   ConstHandle2ConstBackground background,
   ConstHandle2ConstUncertainty uncertainty
) {
   ConstHandle2ResonancesWithBackground handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      detail::tocpp<CPPResonancesLink>(resonancesLink),
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
XMLName
ResonancesWithBackgroundLabelGet(ConstHandle2ConstResonancesWithBackground self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
ResonancesWithBackgroundLabelSet(ConstHandle2ResonancesWithBackground self, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Child: resonancesLink
// -----------------------------------------------------------------------------

// Has
int
ResonancesWithBackgroundResonancesLinkHas(ConstHandle2ConstResonancesWithBackground self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ResonancesLinkHas", self, extract::resonancesLink);
}

// Get, const
Handle2ConstResonancesLink
ResonancesWithBackgroundResonancesLinkGetConst(ConstHandle2ConstResonancesWithBackground self)
{
   return detail::getField<CPP,Handle2ConstResonancesLink>
      (CLASSNAME, CLASSNAME+"ResonancesLinkGetConst", self, extract::resonancesLink);
}

// Get, non-const
Handle2ResonancesLink
ResonancesWithBackgroundResonancesLinkGet(ConstHandle2ResonancesWithBackground self)
{
   return detail::getField<CPP,Handle2ResonancesLink>
      (CLASSNAME, CLASSNAME+"ResonancesLinkGet", self, extract::resonancesLink);
}

// Set
void
ResonancesWithBackgroundResonancesLinkSet(ConstHandle2ResonancesWithBackground self, ConstHandle2ConstResonancesLink resonancesLink)
{
   detail::setField<CPP,CPPResonancesLink>
      (CLASSNAME, CLASSNAME+"ResonancesLinkSet", self, extract::resonancesLink, resonancesLink);
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

#include "v2.0/transport/ResonancesWithBackground/src/custom.cpp"
