
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/FissionEnergyRelease.hpp"
#include "FissionEnergyRelease.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = FissionEnergyReleaseClass;
using CPP = multigroup::FissionEnergyRelease;

static const std::string CLASSNAME = "FissionEnergyRelease";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto promptProductKE = [](auto &obj) { return &obj.promptProductKE; };
   static auto promptNeutronKE = [](auto &obj) { return &obj.promptNeutronKE; };
   static auto delayedNeutronKE = [](auto &obj) { return &obj.delayedNeutronKE; };
   static auto promptGammaEnergy = [](auto &obj) { return &obj.promptGammaEnergy; };
   static auto delayedGammaEnergy = [](auto &obj) { return &obj.delayedGammaEnergy; };
   static auto delayedBetaEnergy = [](auto &obj) { return &obj.delayedBetaEnergy; };
   static auto neutrinoEnergy = [](auto &obj) { return &obj.neutrinoEnergy; };
   static auto nonNeutrinoEnergy = [](auto &obj) { return &obj.nonNeutrinoEnergy; };
   static auto totalEnergy = [](auto &obj) { return &obj.totalEnergy; };
}

using CPPPromptProductKE = general::PromptProductKE;
using CPPPromptNeutronKE = general::PromptNeutronKE;
using CPPDelayedNeutronKE = general::DelayedNeutronKE;
using CPPPromptGammaEnergy = general::PromptGammaEnergy;
using CPPDelayedGammaEnergy = general::DelayedGammaEnergy;
using CPPDelayedBetaEnergy = general::DelayedBetaEnergy;
using CPPNeutrinoEnergy = general::NeutrinoEnergy;
using CPPNonNeutrinoEnergy = general::NonNeutrinoEnergy;
using CPPTotalEnergy = general::TotalEnergy;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstFissionEnergyRelease
FissionEnergyReleaseDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2FissionEnergyRelease
FissionEnergyReleaseDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstFissionEnergyRelease
FissionEnergyReleaseCreateConst(
   const char *const label,
   ConstHandle2ConstPromptProductKE promptProductKE,
   ConstHandle2ConstPromptNeutronKE promptNeutronKE,
   ConstHandle2ConstDelayedNeutronKE delayedNeutronKE,
   ConstHandle2ConstPromptGammaEnergy promptGammaEnergy,
   ConstHandle2ConstDelayedGammaEnergy delayedGammaEnergy,
   ConstHandle2ConstDelayedBetaEnergy delayedBetaEnergy,
   ConstHandle2ConstNeutrinoEnergy neutrinoEnergy,
   ConstHandle2ConstNonNeutrinoEnergy nonNeutrinoEnergy,
   ConstHandle2ConstTotalEnergy totalEnergy
) {
   ConstHandle2FissionEnergyRelease handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      detail::tocpp<CPPPromptProductKE>(promptProductKE),
      detail::tocpp<CPPPromptNeutronKE>(promptNeutronKE),
      detail::tocpp<CPPDelayedNeutronKE>(delayedNeutronKE),
      detail::tocpp<CPPPromptGammaEnergy>(promptGammaEnergy),
      detail::tocpp<CPPDelayedGammaEnergy>(delayedGammaEnergy),
      detail::tocpp<CPPDelayedBetaEnergy>(delayedBetaEnergy),
      detail::tocpp<CPPNeutrinoEnergy>(neutrinoEnergy),
      detail::tocpp<CPPNonNeutrinoEnergy>(nonNeutrinoEnergy),
      detail::tocpp<CPPTotalEnergy>(totalEnergy)
   );
   return handle;
}

// Create, general
Handle2FissionEnergyRelease
FissionEnergyReleaseCreate(
   const char *const label,
   ConstHandle2ConstPromptProductKE promptProductKE,
   ConstHandle2ConstPromptNeutronKE promptNeutronKE,
   ConstHandle2ConstDelayedNeutronKE delayedNeutronKE,
   ConstHandle2ConstPromptGammaEnergy promptGammaEnergy,
   ConstHandle2ConstDelayedGammaEnergy delayedGammaEnergy,
   ConstHandle2ConstDelayedBetaEnergy delayedBetaEnergy,
   ConstHandle2ConstNeutrinoEnergy neutrinoEnergy,
   ConstHandle2ConstNonNeutrinoEnergy nonNeutrinoEnergy,
   ConstHandle2ConstTotalEnergy totalEnergy
) {
   ConstHandle2FissionEnergyRelease handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      detail::tocpp<CPPPromptProductKE>(promptProductKE),
      detail::tocpp<CPPPromptNeutronKE>(promptNeutronKE),
      detail::tocpp<CPPDelayedNeutronKE>(delayedNeutronKE),
      detail::tocpp<CPPPromptGammaEnergy>(promptGammaEnergy),
      detail::tocpp<CPPDelayedGammaEnergy>(delayedGammaEnergy),
      detail::tocpp<CPPDelayedBetaEnergy>(delayedBetaEnergy),
      detail::tocpp<CPPNeutrinoEnergy>(neutrinoEnergy),
      detail::tocpp<CPPNonNeutrinoEnergy>(nonNeutrinoEnergy),
      detail::tocpp<CPPTotalEnergy>(totalEnergy)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
FissionEnergyReleaseAssign(ConstHandle2FissionEnergyRelease This, ConstHandle2ConstFissionEnergyRelease from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
FissionEnergyReleaseDelete(ConstHandle2ConstFissionEnergyRelease This)
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
FissionEnergyReleaseRead(ConstHandle2FissionEnergyRelease This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
FissionEnergyReleaseWrite(ConstHandle2ConstFissionEnergyRelease This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
FissionEnergyReleasePrint(ConstHandle2ConstFissionEnergyRelease This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
FissionEnergyReleasePrintXML(ConstHandle2ConstFissionEnergyRelease This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
FissionEnergyReleasePrintJSON(ConstHandle2ConstFissionEnergyRelease This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
FissionEnergyReleaseLabelHas(ConstHandle2ConstFissionEnergyRelease This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
const char *
FissionEnergyReleaseLabelGet(ConstHandle2ConstFissionEnergyRelease This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
FissionEnergyReleaseLabelSet(ConstHandle2FissionEnergyRelease This, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Child: promptProductKE
// -----------------------------------------------------------------------------

// Has
int
FissionEnergyReleasePromptProductKEHas(ConstHandle2ConstFissionEnergyRelease This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"PromptProductKEHas", This, extract::promptProductKE);
}

// Get, const
Handle2ConstPromptProductKE
FissionEnergyReleasePromptProductKEGetConst(ConstHandle2ConstFissionEnergyRelease This)
{
   return detail::getField<CPP,Handle2ConstPromptProductKE>
      (CLASSNAME, CLASSNAME+"PromptProductKEGetConst", This, extract::promptProductKE);
}

// Get, non-const
Handle2PromptProductKE
FissionEnergyReleasePromptProductKEGet(ConstHandle2FissionEnergyRelease This)
{
   return detail::getField<CPP,Handle2PromptProductKE>
      (CLASSNAME, CLASSNAME+"PromptProductKEGet", This, extract::promptProductKE);
}

// Set
void
FissionEnergyReleasePromptProductKESet(ConstHandle2FissionEnergyRelease This, ConstHandle2ConstPromptProductKE promptProductKE)
{
   detail::setField<CPP,CPPPromptProductKE>
      (CLASSNAME, CLASSNAME+"PromptProductKESet", This, extract::promptProductKE, promptProductKE);
}


// -----------------------------------------------------------------------------
// Child: promptNeutronKE
// -----------------------------------------------------------------------------

// Has
int
FissionEnergyReleasePromptNeutronKEHas(ConstHandle2ConstFissionEnergyRelease This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"PromptNeutronKEHas", This, extract::promptNeutronKE);
}

// Get, const
Handle2ConstPromptNeutronKE
FissionEnergyReleasePromptNeutronKEGetConst(ConstHandle2ConstFissionEnergyRelease This)
{
   return detail::getField<CPP,Handle2ConstPromptNeutronKE>
      (CLASSNAME, CLASSNAME+"PromptNeutronKEGetConst", This, extract::promptNeutronKE);
}

// Get, non-const
Handle2PromptNeutronKE
FissionEnergyReleasePromptNeutronKEGet(ConstHandle2FissionEnergyRelease This)
{
   return detail::getField<CPP,Handle2PromptNeutronKE>
      (CLASSNAME, CLASSNAME+"PromptNeutronKEGet", This, extract::promptNeutronKE);
}

// Set
void
FissionEnergyReleasePromptNeutronKESet(ConstHandle2FissionEnergyRelease This, ConstHandle2ConstPromptNeutronKE promptNeutronKE)
{
   detail::setField<CPP,CPPPromptNeutronKE>
      (CLASSNAME, CLASSNAME+"PromptNeutronKESet", This, extract::promptNeutronKE, promptNeutronKE);
}


// -----------------------------------------------------------------------------
// Child: delayedNeutronKE
// -----------------------------------------------------------------------------

// Has
int
FissionEnergyReleaseDelayedNeutronKEHas(ConstHandle2ConstFissionEnergyRelease This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DelayedNeutronKEHas", This, extract::delayedNeutronKE);
}

// Get, const
Handle2ConstDelayedNeutronKE
FissionEnergyReleaseDelayedNeutronKEGetConst(ConstHandle2ConstFissionEnergyRelease This)
{
   return detail::getField<CPP,Handle2ConstDelayedNeutronKE>
      (CLASSNAME, CLASSNAME+"DelayedNeutronKEGetConst", This, extract::delayedNeutronKE);
}

// Get, non-const
Handle2DelayedNeutronKE
FissionEnergyReleaseDelayedNeutronKEGet(ConstHandle2FissionEnergyRelease This)
{
   return detail::getField<CPP,Handle2DelayedNeutronKE>
      (CLASSNAME, CLASSNAME+"DelayedNeutronKEGet", This, extract::delayedNeutronKE);
}

// Set
void
FissionEnergyReleaseDelayedNeutronKESet(ConstHandle2FissionEnergyRelease This, ConstHandle2ConstDelayedNeutronKE delayedNeutronKE)
{
   detail::setField<CPP,CPPDelayedNeutronKE>
      (CLASSNAME, CLASSNAME+"DelayedNeutronKESet", This, extract::delayedNeutronKE, delayedNeutronKE);
}


// -----------------------------------------------------------------------------
// Child: promptGammaEnergy
// -----------------------------------------------------------------------------

// Has
int
FissionEnergyReleasePromptGammaEnergyHas(ConstHandle2ConstFissionEnergyRelease This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"PromptGammaEnergyHas", This, extract::promptGammaEnergy);
}

// Get, const
Handle2ConstPromptGammaEnergy
FissionEnergyReleasePromptGammaEnergyGetConst(ConstHandle2ConstFissionEnergyRelease This)
{
   return detail::getField<CPP,Handle2ConstPromptGammaEnergy>
      (CLASSNAME, CLASSNAME+"PromptGammaEnergyGetConst", This, extract::promptGammaEnergy);
}

// Get, non-const
Handle2PromptGammaEnergy
FissionEnergyReleasePromptGammaEnergyGet(ConstHandle2FissionEnergyRelease This)
{
   return detail::getField<CPP,Handle2PromptGammaEnergy>
      (CLASSNAME, CLASSNAME+"PromptGammaEnergyGet", This, extract::promptGammaEnergy);
}

// Set
void
FissionEnergyReleasePromptGammaEnergySet(ConstHandle2FissionEnergyRelease This, ConstHandle2ConstPromptGammaEnergy promptGammaEnergy)
{
   detail::setField<CPP,CPPPromptGammaEnergy>
      (CLASSNAME, CLASSNAME+"PromptGammaEnergySet", This, extract::promptGammaEnergy, promptGammaEnergy);
}


// -----------------------------------------------------------------------------
// Child: delayedGammaEnergy
// -----------------------------------------------------------------------------

// Has
int
FissionEnergyReleaseDelayedGammaEnergyHas(ConstHandle2ConstFissionEnergyRelease This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DelayedGammaEnergyHas", This, extract::delayedGammaEnergy);
}

// Get, const
Handle2ConstDelayedGammaEnergy
FissionEnergyReleaseDelayedGammaEnergyGetConst(ConstHandle2ConstFissionEnergyRelease This)
{
   return detail::getField<CPP,Handle2ConstDelayedGammaEnergy>
      (CLASSNAME, CLASSNAME+"DelayedGammaEnergyGetConst", This, extract::delayedGammaEnergy);
}

// Get, non-const
Handle2DelayedGammaEnergy
FissionEnergyReleaseDelayedGammaEnergyGet(ConstHandle2FissionEnergyRelease This)
{
   return detail::getField<CPP,Handle2DelayedGammaEnergy>
      (CLASSNAME, CLASSNAME+"DelayedGammaEnergyGet", This, extract::delayedGammaEnergy);
}

// Set
void
FissionEnergyReleaseDelayedGammaEnergySet(ConstHandle2FissionEnergyRelease This, ConstHandle2ConstDelayedGammaEnergy delayedGammaEnergy)
{
   detail::setField<CPP,CPPDelayedGammaEnergy>
      (CLASSNAME, CLASSNAME+"DelayedGammaEnergySet", This, extract::delayedGammaEnergy, delayedGammaEnergy);
}


// -----------------------------------------------------------------------------
// Child: delayedBetaEnergy
// -----------------------------------------------------------------------------

// Has
int
FissionEnergyReleaseDelayedBetaEnergyHas(ConstHandle2ConstFissionEnergyRelease This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DelayedBetaEnergyHas", This, extract::delayedBetaEnergy);
}

// Get, const
Handle2ConstDelayedBetaEnergy
FissionEnergyReleaseDelayedBetaEnergyGetConst(ConstHandle2ConstFissionEnergyRelease This)
{
   return detail::getField<CPP,Handle2ConstDelayedBetaEnergy>
      (CLASSNAME, CLASSNAME+"DelayedBetaEnergyGetConst", This, extract::delayedBetaEnergy);
}

// Get, non-const
Handle2DelayedBetaEnergy
FissionEnergyReleaseDelayedBetaEnergyGet(ConstHandle2FissionEnergyRelease This)
{
   return detail::getField<CPP,Handle2DelayedBetaEnergy>
      (CLASSNAME, CLASSNAME+"DelayedBetaEnergyGet", This, extract::delayedBetaEnergy);
}

// Set
void
FissionEnergyReleaseDelayedBetaEnergySet(ConstHandle2FissionEnergyRelease This, ConstHandle2ConstDelayedBetaEnergy delayedBetaEnergy)
{
   detail::setField<CPP,CPPDelayedBetaEnergy>
      (CLASSNAME, CLASSNAME+"DelayedBetaEnergySet", This, extract::delayedBetaEnergy, delayedBetaEnergy);
}


// -----------------------------------------------------------------------------
// Child: neutrinoEnergy
// -----------------------------------------------------------------------------

// Has
int
FissionEnergyReleaseNeutrinoEnergyHas(ConstHandle2ConstFissionEnergyRelease This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"NeutrinoEnergyHas", This, extract::neutrinoEnergy);
}

// Get, const
Handle2ConstNeutrinoEnergy
FissionEnergyReleaseNeutrinoEnergyGetConst(ConstHandle2ConstFissionEnergyRelease This)
{
   return detail::getField<CPP,Handle2ConstNeutrinoEnergy>
      (CLASSNAME, CLASSNAME+"NeutrinoEnergyGetConst", This, extract::neutrinoEnergy);
}

// Get, non-const
Handle2NeutrinoEnergy
FissionEnergyReleaseNeutrinoEnergyGet(ConstHandle2FissionEnergyRelease This)
{
   return detail::getField<CPP,Handle2NeutrinoEnergy>
      (CLASSNAME, CLASSNAME+"NeutrinoEnergyGet", This, extract::neutrinoEnergy);
}

// Set
void
FissionEnergyReleaseNeutrinoEnergySet(ConstHandle2FissionEnergyRelease This, ConstHandle2ConstNeutrinoEnergy neutrinoEnergy)
{
   detail::setField<CPP,CPPNeutrinoEnergy>
      (CLASSNAME, CLASSNAME+"NeutrinoEnergySet", This, extract::neutrinoEnergy, neutrinoEnergy);
}


// -----------------------------------------------------------------------------
// Child: nonNeutrinoEnergy
// -----------------------------------------------------------------------------

// Has
int
FissionEnergyReleaseNonNeutrinoEnergyHas(ConstHandle2ConstFissionEnergyRelease This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"NonNeutrinoEnergyHas", This, extract::nonNeutrinoEnergy);
}

// Get, const
Handle2ConstNonNeutrinoEnergy
FissionEnergyReleaseNonNeutrinoEnergyGetConst(ConstHandle2ConstFissionEnergyRelease This)
{
   return detail::getField<CPP,Handle2ConstNonNeutrinoEnergy>
      (CLASSNAME, CLASSNAME+"NonNeutrinoEnergyGetConst", This, extract::nonNeutrinoEnergy);
}

// Get, non-const
Handle2NonNeutrinoEnergy
FissionEnergyReleaseNonNeutrinoEnergyGet(ConstHandle2FissionEnergyRelease This)
{
   return detail::getField<CPP,Handle2NonNeutrinoEnergy>
      (CLASSNAME, CLASSNAME+"NonNeutrinoEnergyGet", This, extract::nonNeutrinoEnergy);
}

// Set
void
FissionEnergyReleaseNonNeutrinoEnergySet(ConstHandle2FissionEnergyRelease This, ConstHandle2ConstNonNeutrinoEnergy nonNeutrinoEnergy)
{
   detail::setField<CPP,CPPNonNeutrinoEnergy>
      (CLASSNAME, CLASSNAME+"NonNeutrinoEnergySet", This, extract::nonNeutrinoEnergy, nonNeutrinoEnergy);
}


// -----------------------------------------------------------------------------
// Child: totalEnergy
// -----------------------------------------------------------------------------

// Has
int
FissionEnergyReleaseTotalEnergyHas(ConstHandle2ConstFissionEnergyRelease This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"TotalEnergyHas", This, extract::totalEnergy);
}

// Get, const
Handle2ConstTotalEnergy
FissionEnergyReleaseTotalEnergyGetConst(ConstHandle2ConstFissionEnergyRelease This)
{
   return detail::getField<CPP,Handle2ConstTotalEnergy>
      (CLASSNAME, CLASSNAME+"TotalEnergyGetConst", This, extract::totalEnergy);
}

// Get, non-const
Handle2TotalEnergy
FissionEnergyReleaseTotalEnergyGet(ConstHandle2FissionEnergyRelease This)
{
   return detail::getField<CPP,Handle2TotalEnergy>
      (CLASSNAME, CLASSNAME+"TotalEnergyGet", This, extract::totalEnergy);
}

// Set
void
FissionEnergyReleaseTotalEnergySet(ConstHandle2FissionEnergyRelease This, ConstHandle2ConstTotalEnergy totalEnergy)
{
   detail::setField<CPP,CPPTotalEnergy>
      (CLASSNAME, CLASSNAME+"TotalEnergySet", This, extract::totalEnergy, totalEnergy);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/FissionEnergyRelease/src/custom.cpp"
