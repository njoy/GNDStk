
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/pops/DecayMode.hpp"
#include "DecayMode.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = DecayModeClass;
using CPP = multigroup::DecayMode;

static const std::string CLASSNAME = "DecayMode";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto mode = [](auto &obj) { return &obj.mode; };
   static auto probability = [](auto &obj) { return &obj.probability; };
   static auto internalConversionCoefficients = [](auto &obj) { return &obj.internalConversionCoefficients; };
   static auto photonEmissionProbabilities = [](auto &obj) { return &obj.photonEmissionProbabilities; };
   static auto Q = [](auto &obj) { return &obj.Q; };
   static auto decayPath = [](auto &obj) { return &obj.decayPath; };
   static auto spectra = [](auto &obj) { return &obj.spectra; };
}

using CPPProbability = pops::Probability;
using CPPInternalConversionCoefficients = pops::InternalConversionCoefficients;
using CPPPhotonEmissionProbabilities = pops::PhotonEmissionProbabilities;
using CPPQ = pops::Q;
using CPPDecayPath = pops::DecayPath;
using CPPSpectra = pops::Spectra;


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
   const XMLName label,
   const enums::DecayType mode,
   ConstHandle2ConstProbability probability,
   ConstHandle2ConstInternalConversionCoefficients internalConversionCoefficients,
   ConstHandle2ConstPhotonEmissionProbabilities photonEmissionProbabilities,
   ConstHandle2ConstQ Q,
   ConstHandle2ConstDecayPath decayPath,
   ConstHandle2ConstSpectra spectra
) {
   ConstHandle2DecayMode handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      mode,
      detail::tocpp<CPPProbability>(probability),
      detail::tocpp<CPPInternalConversionCoefficients>(internalConversionCoefficients),
      detail::tocpp<CPPPhotonEmissionProbabilities>(photonEmissionProbabilities),
      detail::tocpp<CPPQ>(Q),
      detail::tocpp<CPPDecayPath>(decayPath),
      detail::tocpp<CPPSpectra>(spectra)
   );
   return handle;
}

// Create, general
Handle2DecayMode
DecayModeCreate(
   const XMLName label,
   const enums::DecayType mode,
   ConstHandle2ConstProbability probability,
   ConstHandle2ConstInternalConversionCoefficients internalConversionCoefficients,
   ConstHandle2ConstPhotonEmissionProbabilities photonEmissionProbabilities,
   ConstHandle2ConstQ Q,
   ConstHandle2ConstDecayPath decayPath,
   ConstHandle2ConstSpectra spectra
) {
   ConstHandle2DecayMode handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      mode,
      detail::tocpp<CPPProbability>(probability),
      detail::tocpp<CPPInternalConversionCoefficients>(internalConversionCoefficients),
      detail::tocpp<CPPPhotonEmissionProbabilities>(photonEmissionProbabilities),
      detail::tocpp<CPPQ>(Q),
      detail::tocpp<CPPDecayPath>(decayPath),
      detail::tocpp<CPPSpectra>(spectra)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
DecayModeAssign(ConstHandle2DecayMode This, ConstHandle2ConstDecayMode from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
DecayModeDelete(ConstHandle2ConstDecayMode This)
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
DecayModeRead(ConstHandle2DecayMode This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
DecayModeWrite(ConstHandle2ConstDecayMode This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
DecayModePrint(ConstHandle2ConstDecayMode This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
DecayModePrintXML(ConstHandle2ConstDecayMode This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
DecayModePrintJSON(ConstHandle2ConstDecayMode This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
DecayModeLabelHas(ConstHandle2ConstDecayMode This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
DecayModeLabelGet(ConstHandle2ConstDecayMode This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
DecayModeLabelSet(ConstHandle2DecayMode This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: mode
// -----------------------------------------------------------------------------

// Has
int
DecayModeModeHas(ConstHandle2ConstDecayMode This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ModeHas", This, extract::mode);
}

// Get
// Returns by value
enums::DecayType
DecayModeModeGet(ConstHandle2ConstDecayMode This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ModeGet", This, extract::mode);
}

// Set
void
DecayModeModeSet(ConstHandle2DecayMode This, const enums::DecayType mode)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ModeSet", This, extract::mode, mode);
}


// -----------------------------------------------------------------------------
// Child: probability
// -----------------------------------------------------------------------------

// Has
int
DecayModeProbabilityHas(ConstHandle2ConstDecayMode This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ProbabilityHas", This, extract::probability);
}

// Get, const
Handle2ConstProbability
DecayModeProbabilityGetConst(ConstHandle2ConstDecayMode This)
{
   return detail::getField<CPP,Handle2ConstProbability>
      (CLASSNAME, CLASSNAME+"ProbabilityGetConst", This, extract::probability);
}

// Get, non-const
Handle2Probability
DecayModeProbabilityGet(ConstHandle2DecayMode This)
{
   return detail::getField<CPP,Handle2Probability>
      (CLASSNAME, CLASSNAME+"ProbabilityGet", This, extract::probability);
}

// Set
void
DecayModeProbabilitySet(ConstHandle2DecayMode This, ConstHandle2ConstProbability probability)
{
   detail::setField<CPP,CPPProbability>
      (CLASSNAME, CLASSNAME+"ProbabilitySet", This, extract::probability, probability);
}


// -----------------------------------------------------------------------------
// Child: internalConversionCoefficients
// -----------------------------------------------------------------------------

// Has
int
DecayModeInternalConversionCoefficientsHas(ConstHandle2ConstDecayMode This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"InternalConversionCoefficientsHas", This, extract::internalConversionCoefficients);
}

// Get, const
Handle2ConstInternalConversionCoefficients
DecayModeInternalConversionCoefficientsGetConst(ConstHandle2ConstDecayMode This)
{
   return detail::getField<CPP,Handle2ConstInternalConversionCoefficients>
      (CLASSNAME, CLASSNAME+"InternalConversionCoefficientsGetConst", This, extract::internalConversionCoefficients);
}

// Get, non-const
Handle2InternalConversionCoefficients
DecayModeInternalConversionCoefficientsGet(ConstHandle2DecayMode This)
{
   return detail::getField<CPP,Handle2InternalConversionCoefficients>
      (CLASSNAME, CLASSNAME+"InternalConversionCoefficientsGet", This, extract::internalConversionCoefficients);
}

// Set
void
DecayModeInternalConversionCoefficientsSet(ConstHandle2DecayMode This, ConstHandle2ConstInternalConversionCoefficients internalConversionCoefficients)
{
   detail::setField<CPP,CPPInternalConversionCoefficients>
      (CLASSNAME, CLASSNAME+"InternalConversionCoefficientsSet", This, extract::internalConversionCoefficients, internalConversionCoefficients);
}


// -----------------------------------------------------------------------------
// Child: photonEmissionProbabilities
// -----------------------------------------------------------------------------

// Has
int
DecayModePhotonEmissionProbabilitiesHas(ConstHandle2ConstDecayMode This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"PhotonEmissionProbabilitiesHas", This, extract::photonEmissionProbabilities);
}

// Get, const
Handle2ConstPhotonEmissionProbabilities
DecayModePhotonEmissionProbabilitiesGetConst(ConstHandle2ConstDecayMode This)
{
   return detail::getField<CPP,Handle2ConstPhotonEmissionProbabilities>
      (CLASSNAME, CLASSNAME+"PhotonEmissionProbabilitiesGetConst", This, extract::photonEmissionProbabilities);
}

// Get, non-const
Handle2PhotonEmissionProbabilities
DecayModePhotonEmissionProbabilitiesGet(ConstHandle2DecayMode This)
{
   return detail::getField<CPP,Handle2PhotonEmissionProbabilities>
      (CLASSNAME, CLASSNAME+"PhotonEmissionProbabilitiesGet", This, extract::photonEmissionProbabilities);
}

// Set
void
DecayModePhotonEmissionProbabilitiesSet(ConstHandle2DecayMode This, ConstHandle2ConstPhotonEmissionProbabilities photonEmissionProbabilities)
{
   detail::setField<CPP,CPPPhotonEmissionProbabilities>
      (CLASSNAME, CLASSNAME+"PhotonEmissionProbabilitiesSet", This, extract::photonEmissionProbabilities, photonEmissionProbabilities);
}


// -----------------------------------------------------------------------------
// Child: Q
// -----------------------------------------------------------------------------

// Has
int
DecayModeQHas(ConstHandle2ConstDecayMode This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"QHas", This, extract::Q);
}

// Get, const
Handle2ConstQ
DecayModeQGetConst(ConstHandle2ConstDecayMode This)
{
   return detail::getField<CPP,Handle2ConstQ>
      (CLASSNAME, CLASSNAME+"QGetConst", This, extract::Q);
}

// Get, non-const
Handle2Q
DecayModeQGet(ConstHandle2DecayMode This)
{
   return detail::getField<CPP,Handle2Q>
      (CLASSNAME, CLASSNAME+"QGet", This, extract::Q);
}

// Set
void
DecayModeQSet(ConstHandle2DecayMode This, ConstHandle2ConstQ Q)
{
   detail::setField<CPP,CPPQ>
      (CLASSNAME, CLASSNAME+"QSet", This, extract::Q, Q);
}


// -----------------------------------------------------------------------------
// Child: decayPath
// -----------------------------------------------------------------------------

// Has
int
DecayModeDecayPathHas(ConstHandle2ConstDecayMode This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DecayPathHas", This, extract::decayPath);
}

// Get, const
Handle2ConstDecayPath
DecayModeDecayPathGetConst(ConstHandle2ConstDecayMode This)
{
   return detail::getField<CPP,Handle2ConstDecayPath>
      (CLASSNAME, CLASSNAME+"DecayPathGetConst", This, extract::decayPath);
}

// Get, non-const
Handle2DecayPath
DecayModeDecayPathGet(ConstHandle2DecayMode This)
{
   return detail::getField<CPP,Handle2DecayPath>
      (CLASSNAME, CLASSNAME+"DecayPathGet", This, extract::decayPath);
}

// Set
void
DecayModeDecayPathSet(ConstHandle2DecayMode This, ConstHandle2ConstDecayPath decayPath)
{
   detail::setField<CPP,CPPDecayPath>
      (CLASSNAME, CLASSNAME+"DecayPathSet", This, extract::decayPath, decayPath);
}


// -----------------------------------------------------------------------------
// Child: spectra
// -----------------------------------------------------------------------------

// Has
int
DecayModeSpectraHas(ConstHandle2ConstDecayMode This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SpectraHas", This, extract::spectra);
}

// Get, const
Handle2ConstSpectra
DecayModeSpectraGetConst(ConstHandle2ConstDecayMode This)
{
   return detail::getField<CPP,Handle2ConstSpectra>
      (CLASSNAME, CLASSNAME+"SpectraGetConst", This, extract::spectra);
}

// Get, non-const
Handle2Spectra
DecayModeSpectraGet(ConstHandle2DecayMode This)
{
   return detail::getField<CPP,Handle2Spectra>
      (CLASSNAME, CLASSNAME+"SpectraGet", This, extract::spectra);
}

// Set
void
DecayModeSpectraSet(ConstHandle2DecayMode This, ConstHandle2ConstSpectra spectra)
{
   detail::setField<CPP,CPPSpectra>
      (CLASSNAME, CLASSNAME+"SpectraSet", This, extract::spectra, spectra);
}