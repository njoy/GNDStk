
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/DecayMode.hpp"
#include "DecayMode.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = DecayModeClass;
using CPP = multigroup::DecayMode;

static const std::string CLASSNAME = "DecayMode";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto mode = [](auto &obj) { return &obj.mode; };
   static auto probability = [](auto &obj) { return &obj.probability; };
   static auto decayPath = [](auto &obj) { return &obj.decayPath; };
   static auto photonEmissionProbabilities = [](auto &obj) { return &obj.photonEmissionProbabilities; };
   static auto Q = [](auto &obj) { return &obj.Q; };
   static auto spectra = [](auto &obj) { return &obj.spectra; };
}

using CPPProbability = general::Probability;
using CPPDecayPath = general::DecayPath;
using CPPPhotonEmissionProbabilities = general::PhotonEmissionProbabilities;
using CPPQ = general::Q;
using CPPSpectra = general::Spectra;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstDecayMode
DecayModeDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2DecayMode
DecayModeDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstDecayMode
DecayModeCreateConst(
   const char *const label,
   const char *const mode,
   ConstHandle2ConstProbability probability,
   ConstHandle2ConstDecayPath decayPath,
   ConstHandle2ConstPhotonEmissionProbabilities photonEmissionProbabilities,
   ConstHandle2ConstQ Q,
   ConstHandle2ConstSpectra spectra
) {
   ConstHandle2DecayMode handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      mode,
      detail::tocpp<CPPProbability>(probability),
      detail::tocpp<CPPDecayPath>(decayPath),
      detail::tocpp<CPPPhotonEmissionProbabilities>(photonEmissionProbabilities),
      detail::tocpp<CPPQ>(Q),
      detail::tocpp<CPPSpectra>(spectra)
   );
   return handle;
}

// Create, general
Handle2DecayMode
DecayModeCreate(
   const char *const label,
   const char *const mode,
   ConstHandle2ConstProbability probability,
   ConstHandle2ConstDecayPath decayPath,
   ConstHandle2ConstPhotonEmissionProbabilities photonEmissionProbabilities,
   ConstHandle2ConstQ Q,
   ConstHandle2ConstSpectra spectra
) {
   ConstHandle2DecayMode handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      mode,
      detail::tocpp<CPPProbability>(probability),
      detail::tocpp<CPPDecayPath>(decayPath),
      detail::tocpp<CPPPhotonEmissionProbabilities>(photonEmissionProbabilities),
      detail::tocpp<CPPQ>(Q),
      detail::tocpp<CPPSpectra>(spectra)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
DecayModeAssign(ConstHandle2DecayMode self, ConstHandle2ConstDecayMode from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
DecayModeDelete(ConstHandle2ConstDecayMode self)
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
DecayModeRead(ConstHandle2DecayMode self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
DecayModeWrite(ConstHandle2ConstDecayMode self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
DecayModePrint(ConstHandle2ConstDecayMode self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
DecayModePrintXML(ConstHandle2ConstDecayMode self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
DecayModePrintJSON(ConstHandle2ConstDecayMode self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
DecayModeLabelHas(ConstHandle2ConstDecayMode self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
const char *
DecayModeLabelGet(ConstHandle2ConstDecayMode self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
DecayModeLabelSet(ConstHandle2DecayMode self, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: mode
// -----------------------------------------------------------------------------

// Has
int
DecayModeModeHas(ConstHandle2ConstDecayMode self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ModeHas", self, extract::mode);
}

// Get
// Returns by value
const char *
DecayModeModeGet(ConstHandle2ConstDecayMode self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ModeGet", self, extract::mode);
}

// Set
void
DecayModeModeSet(ConstHandle2DecayMode self, const char *const mode)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ModeSet", self, extract::mode, mode);
}


// -----------------------------------------------------------------------------
// Child: probability
// -----------------------------------------------------------------------------

// Has
int
DecayModeProbabilityHas(ConstHandle2ConstDecayMode self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ProbabilityHas", self, extract::probability);
}

// Get, const
Handle2ConstProbability
DecayModeProbabilityGetConst(ConstHandle2ConstDecayMode self)
{
   return detail::getField<CPP,Handle2ConstProbability>
      (CLASSNAME, CLASSNAME+"ProbabilityGetConst", self, extract::probability);
}

// Get, non-const
Handle2Probability
DecayModeProbabilityGet(ConstHandle2DecayMode self)
{
   return detail::getField<CPP,Handle2Probability>
      (CLASSNAME, CLASSNAME+"ProbabilityGet", self, extract::probability);
}

// Set
void
DecayModeProbabilitySet(ConstHandle2DecayMode self, ConstHandle2ConstProbability probability)
{
   detail::setField<CPP,CPPProbability>
      (CLASSNAME, CLASSNAME+"ProbabilitySet", self, extract::probability, probability);
}


// -----------------------------------------------------------------------------
// Child: decayPath
// -----------------------------------------------------------------------------

// Has
int
DecayModeDecayPathHas(ConstHandle2ConstDecayMode self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DecayPathHas", self, extract::decayPath);
}

// Get, const
Handle2ConstDecayPath
DecayModeDecayPathGetConst(ConstHandle2ConstDecayMode self)
{
   return detail::getField<CPP,Handle2ConstDecayPath>
      (CLASSNAME, CLASSNAME+"DecayPathGetConst", self, extract::decayPath);
}

// Get, non-const
Handle2DecayPath
DecayModeDecayPathGet(ConstHandle2DecayMode self)
{
   return detail::getField<CPP,Handle2DecayPath>
      (CLASSNAME, CLASSNAME+"DecayPathGet", self, extract::decayPath);
}

// Set
void
DecayModeDecayPathSet(ConstHandle2DecayMode self, ConstHandle2ConstDecayPath decayPath)
{
   detail::setField<CPP,CPPDecayPath>
      (CLASSNAME, CLASSNAME+"DecayPathSet", self, extract::decayPath, decayPath);
}


// -----------------------------------------------------------------------------
// Child: photonEmissionProbabilities
// -----------------------------------------------------------------------------

// Has
int
DecayModePhotonEmissionProbabilitiesHas(ConstHandle2ConstDecayMode self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"PhotonEmissionProbabilitiesHas", self, extract::photonEmissionProbabilities);
}

// Get, const
Handle2ConstPhotonEmissionProbabilities
DecayModePhotonEmissionProbabilitiesGetConst(ConstHandle2ConstDecayMode self)
{
   return detail::getField<CPP,Handle2ConstPhotonEmissionProbabilities>
      (CLASSNAME, CLASSNAME+"PhotonEmissionProbabilitiesGetConst", self, extract::photonEmissionProbabilities);
}

// Get, non-const
Handle2PhotonEmissionProbabilities
DecayModePhotonEmissionProbabilitiesGet(ConstHandle2DecayMode self)
{
   return detail::getField<CPP,Handle2PhotonEmissionProbabilities>
      (CLASSNAME, CLASSNAME+"PhotonEmissionProbabilitiesGet", self, extract::photonEmissionProbabilities);
}

// Set
void
DecayModePhotonEmissionProbabilitiesSet(ConstHandle2DecayMode self, ConstHandle2ConstPhotonEmissionProbabilities photonEmissionProbabilities)
{
   detail::setField<CPP,CPPPhotonEmissionProbabilities>
      (CLASSNAME, CLASSNAME+"PhotonEmissionProbabilitiesSet", self, extract::photonEmissionProbabilities, photonEmissionProbabilities);
}


// -----------------------------------------------------------------------------
// Child: Q
// -----------------------------------------------------------------------------

// Has
int
DecayModeQHas(ConstHandle2ConstDecayMode self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"QHas", self, extract::Q);
}

// Get, const
Handle2ConstQ
DecayModeQGetConst(ConstHandle2ConstDecayMode self)
{
   return detail::getField<CPP,Handle2ConstQ>
      (CLASSNAME, CLASSNAME+"QGetConst", self, extract::Q);
}

// Get, non-const
Handle2Q
DecayModeQGet(ConstHandle2DecayMode self)
{
   return detail::getField<CPP,Handle2Q>
      (CLASSNAME, CLASSNAME+"QGet", self, extract::Q);
}

// Set
void
DecayModeQSet(ConstHandle2DecayMode self, ConstHandle2ConstQ Q)
{
   detail::setField<CPP,CPPQ>
      (CLASSNAME, CLASSNAME+"QSet", self, extract::Q, Q);
}


// -----------------------------------------------------------------------------
// Child: spectra
// -----------------------------------------------------------------------------

// Has
int
DecayModeSpectraHas(ConstHandle2ConstDecayMode self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SpectraHas", self, extract::spectra);
}

// Get, const
Handle2ConstSpectra
DecayModeSpectraGetConst(ConstHandle2ConstDecayMode self)
{
   return detail::getField<CPP,Handle2ConstSpectra>
      (CLASSNAME, CLASSNAME+"SpectraGetConst", self, extract::spectra);
}

// Get, non-const
Handle2Spectra
DecayModeSpectraGet(ConstHandle2DecayMode self)
{
   return detail::getField<CPP,Handle2Spectra>
      (CLASSNAME, CLASSNAME+"SpectraGet", self, extract::spectra);
}

// Set
void
DecayModeSpectraSet(ConstHandle2DecayMode self, ConstHandle2ConstSpectra spectra)
{
   detail::setField<CPP,CPPSpectra>
      (CLASSNAME, CLASSNAME+"SpectraSet", self, extract::spectra, spectra);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/DecayMode/src/custom.cpp"
