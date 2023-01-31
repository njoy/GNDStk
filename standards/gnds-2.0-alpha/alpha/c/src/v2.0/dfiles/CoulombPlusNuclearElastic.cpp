
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/dfiles/CoulombPlusNuclearElastic.hpp"
#include "CoulombPlusNuclearElastic.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = CoulombPlusNuclearElasticClass;
using CPP = multigroup::CoulombPlusNuclearElastic;

static const std::string CLASSNAME = "CoulombPlusNuclearElastic";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto href = [](auto &obj) { return &obj.href; };
   static auto pid = [](auto &obj) { return &obj.pid; };
   static auto productFrame = [](auto &obj) { return &obj.productFrame; };
   static auto identicalParticles = [](auto &obj) { return &obj.identicalParticles; };
   static auto RutherfordScattering = [](auto &obj) { return &obj.RutherfordScattering; };
   static auto nuclearAmplitudeExpansion = [](auto &obj) { return &obj.nuclearAmplitudeExpansion; };
   static auto nuclearPlusInterference = [](auto &obj) { return &obj.nuclearPlusInterference; };
}

using CPPRutherfordScattering = dfiles::RutherfordScattering;
using CPPNuclearAmplitudeExpansion = dfiles::NuclearAmplitudeExpansion;
using CPPNuclearPlusInterference = dfiles::NuclearPlusInterference;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstCoulombPlusNuclearElastic
CoulombPlusNuclearElasticDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2CoulombPlusNuclearElastic
CoulombPlusNuclearElasticDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstCoulombPlusNuclearElastic
CoulombPlusNuclearElasticCreateConst(
   const char *const label,
   const char *const href,
   const char *const pid,
   const char *const productFrame,
   const bool identicalParticles,
   ConstHandle2ConstRutherfordScattering RutherfordScattering,
   ConstHandle2ConstNuclearAmplitudeExpansion nuclearAmplitudeExpansion,
   ConstHandle2ConstNuclearPlusInterference nuclearPlusInterference
) {
   ConstHandle2CoulombPlusNuclearElastic handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      href,
      pid,
      productFrame,
      identicalParticles,
      detail::tocpp<CPPRutherfordScattering>(RutherfordScattering),
      detail::tocpp<CPPNuclearAmplitudeExpansion>(nuclearAmplitudeExpansion),
      detail::tocpp<CPPNuclearPlusInterference>(nuclearPlusInterference)
   );
   return handle;
}

// Create, general
Handle2CoulombPlusNuclearElastic
CoulombPlusNuclearElasticCreate(
   const char *const label,
   const char *const href,
   const char *const pid,
   const char *const productFrame,
   const bool identicalParticles,
   ConstHandle2ConstRutherfordScattering RutherfordScattering,
   ConstHandle2ConstNuclearAmplitudeExpansion nuclearAmplitudeExpansion,
   ConstHandle2ConstNuclearPlusInterference nuclearPlusInterference
) {
   ConstHandle2CoulombPlusNuclearElastic handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      href,
      pid,
      productFrame,
      identicalParticles,
      detail::tocpp<CPPRutherfordScattering>(RutherfordScattering),
      detail::tocpp<CPPNuclearAmplitudeExpansion>(nuclearAmplitudeExpansion),
      detail::tocpp<CPPNuclearPlusInterference>(nuclearPlusInterference)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
CoulombPlusNuclearElasticAssign(ConstHandle2CoulombPlusNuclearElastic This, ConstHandle2ConstCoulombPlusNuclearElastic from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
CoulombPlusNuclearElasticDelete(ConstHandle2ConstCoulombPlusNuclearElastic This)
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
CoulombPlusNuclearElasticRead(ConstHandle2CoulombPlusNuclearElastic This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
CoulombPlusNuclearElasticWrite(ConstHandle2ConstCoulombPlusNuclearElastic This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
CoulombPlusNuclearElasticPrint(ConstHandle2ConstCoulombPlusNuclearElastic This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
CoulombPlusNuclearElasticPrintXML(ConstHandle2ConstCoulombPlusNuclearElastic This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
CoulombPlusNuclearElasticPrintJSON(ConstHandle2ConstCoulombPlusNuclearElastic This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
CoulombPlusNuclearElasticLabelHas(ConstHandle2ConstCoulombPlusNuclearElastic This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
const char *
CoulombPlusNuclearElasticLabelGet(ConstHandle2ConstCoulombPlusNuclearElastic This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
CoulombPlusNuclearElasticLabelSet(ConstHandle2CoulombPlusNuclearElastic This, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// Has
int
CoulombPlusNuclearElasticHrefHas(ConstHandle2ConstCoulombPlusNuclearElastic This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"HrefHas", This, extract::href);
}

// Get
// Returns by value
const char *
CoulombPlusNuclearElasticHrefGet(ConstHandle2ConstCoulombPlusNuclearElastic This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"HrefGet", This, extract::href);
}

// Set
void
CoulombPlusNuclearElasticHrefSet(ConstHandle2CoulombPlusNuclearElastic This, const char *const href)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"HrefSet", This, extract::href, href);
}


// -----------------------------------------------------------------------------
// Metadatum: pid
// -----------------------------------------------------------------------------

// Has
int
CoulombPlusNuclearElasticPidHas(ConstHandle2ConstCoulombPlusNuclearElastic This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"PidHas", This, extract::pid);
}

// Get
// Returns by value
const char *
CoulombPlusNuclearElasticPidGet(ConstHandle2ConstCoulombPlusNuclearElastic This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"PidGet", This, extract::pid);
}

// Set
void
CoulombPlusNuclearElasticPidSet(ConstHandle2CoulombPlusNuclearElastic This, const char *const pid)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"PidSet", This, extract::pid, pid);
}


// -----------------------------------------------------------------------------
// Metadatum: productFrame
// -----------------------------------------------------------------------------

// Has
int
CoulombPlusNuclearElasticProductFrameHas(ConstHandle2ConstCoulombPlusNuclearElastic This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ProductFrameHas", This, extract::productFrame);
}

// Get
// Returns by value
const char *
CoulombPlusNuclearElasticProductFrameGet(ConstHandle2ConstCoulombPlusNuclearElastic This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ProductFrameGet", This, extract::productFrame);
}

// Set
void
CoulombPlusNuclearElasticProductFrameSet(ConstHandle2CoulombPlusNuclearElastic This, const char *const productFrame)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ProductFrameSet", This, extract::productFrame, productFrame);
}


// -----------------------------------------------------------------------------
// Metadatum: identicalParticles
// -----------------------------------------------------------------------------

// Has
int
CoulombPlusNuclearElasticIdenticalParticlesHas(ConstHandle2ConstCoulombPlusNuclearElastic This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"IdenticalParticlesHas", This, extract::identicalParticles);
}

// Get
// Returns by value
bool
CoulombPlusNuclearElasticIdenticalParticlesGet(ConstHandle2ConstCoulombPlusNuclearElastic This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"IdenticalParticlesGet", This, extract::identicalParticles);
}

// Set
void
CoulombPlusNuclearElasticIdenticalParticlesSet(ConstHandle2CoulombPlusNuclearElastic This, const bool identicalParticles)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"IdenticalParticlesSet", This, extract::identicalParticles, identicalParticles);
}


// -----------------------------------------------------------------------------
// Child: RutherfordScattering
// -----------------------------------------------------------------------------

// Has
int
CoulombPlusNuclearElasticRutherfordScatteringHas(ConstHandle2ConstCoulombPlusNuclearElastic This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"RutherfordScatteringHas", This, extract::RutherfordScattering);
}

// Get, const
Handle2ConstRutherfordScattering
CoulombPlusNuclearElasticRutherfordScatteringGetConst(ConstHandle2ConstCoulombPlusNuclearElastic This)
{
   return detail::getField<CPP,Handle2ConstRutherfordScattering>
      (CLASSNAME, CLASSNAME+"RutherfordScatteringGetConst", This, extract::RutherfordScattering);
}

// Get, non-const
Handle2RutherfordScattering
CoulombPlusNuclearElasticRutherfordScatteringGet(ConstHandle2CoulombPlusNuclearElastic This)
{
   return detail::getField<CPP,Handle2RutherfordScattering>
      (CLASSNAME, CLASSNAME+"RutherfordScatteringGet", This, extract::RutherfordScattering);
}

// Set
void
CoulombPlusNuclearElasticRutherfordScatteringSet(ConstHandle2CoulombPlusNuclearElastic This, ConstHandle2ConstRutherfordScattering RutherfordScattering)
{
   detail::setField<CPP,CPPRutherfordScattering>
      (CLASSNAME, CLASSNAME+"RutherfordScatteringSet", This, extract::RutherfordScattering, RutherfordScattering);
}


// -----------------------------------------------------------------------------
// Child: nuclearAmplitudeExpansion
// -----------------------------------------------------------------------------

// Has
int
CoulombPlusNuclearElasticNuclearAmplitudeExpansionHas(ConstHandle2ConstCoulombPlusNuclearElastic This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"NuclearAmplitudeExpansionHas", This, extract::nuclearAmplitudeExpansion);
}

// Get, const
Handle2ConstNuclearAmplitudeExpansion
CoulombPlusNuclearElasticNuclearAmplitudeExpansionGetConst(ConstHandle2ConstCoulombPlusNuclearElastic This)
{
   return detail::getField<CPP,Handle2ConstNuclearAmplitudeExpansion>
      (CLASSNAME, CLASSNAME+"NuclearAmplitudeExpansionGetConst", This, extract::nuclearAmplitudeExpansion);
}

// Get, non-const
Handle2NuclearAmplitudeExpansion
CoulombPlusNuclearElasticNuclearAmplitudeExpansionGet(ConstHandle2CoulombPlusNuclearElastic This)
{
   return detail::getField<CPP,Handle2NuclearAmplitudeExpansion>
      (CLASSNAME, CLASSNAME+"NuclearAmplitudeExpansionGet", This, extract::nuclearAmplitudeExpansion);
}

// Set
void
CoulombPlusNuclearElasticNuclearAmplitudeExpansionSet(ConstHandle2CoulombPlusNuclearElastic This, ConstHandle2ConstNuclearAmplitudeExpansion nuclearAmplitudeExpansion)
{
   detail::setField<CPP,CPPNuclearAmplitudeExpansion>
      (CLASSNAME, CLASSNAME+"NuclearAmplitudeExpansionSet", This, extract::nuclearAmplitudeExpansion, nuclearAmplitudeExpansion);
}


// -----------------------------------------------------------------------------
// Child: nuclearPlusInterference
// -----------------------------------------------------------------------------

// Has
int
CoulombPlusNuclearElasticNuclearPlusInterferenceHas(ConstHandle2ConstCoulombPlusNuclearElastic This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"NuclearPlusInterferenceHas", This, extract::nuclearPlusInterference);
}

// Get, const
Handle2ConstNuclearPlusInterference
CoulombPlusNuclearElasticNuclearPlusInterferenceGetConst(ConstHandle2ConstCoulombPlusNuclearElastic This)
{
   return detail::getField<CPP,Handle2ConstNuclearPlusInterference>
      (CLASSNAME, CLASSNAME+"NuclearPlusInterferenceGetConst", This, extract::nuclearPlusInterference);
}

// Get, non-const
Handle2NuclearPlusInterference
CoulombPlusNuclearElasticNuclearPlusInterferenceGet(ConstHandle2CoulombPlusNuclearElastic This)
{
   return detail::getField<CPP,Handle2NuclearPlusInterference>
      (CLASSNAME, CLASSNAME+"NuclearPlusInterferenceGet", This, extract::nuclearPlusInterference);
}

// Set
void
CoulombPlusNuclearElasticNuclearPlusInterferenceSet(ConstHandle2CoulombPlusNuclearElastic This, ConstHandle2ConstNuclearPlusInterference nuclearPlusInterference)
{
   detail::setField<CPP,CPPNuclearPlusInterference>
      (CLASSNAME, CLASSNAME+"NuclearPlusInterferenceSet", This, extract::nuclearPlusInterference, nuclearPlusInterference);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/dfiles/CoulombPlusNuclearElastic/src/custom.cpp"
