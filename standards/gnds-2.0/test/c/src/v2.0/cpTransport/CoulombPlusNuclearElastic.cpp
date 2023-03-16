
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/cpTransport/CoulombPlusNuclearElastic.hpp"
#include "CoulombPlusNuclearElastic.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = CoulombPlusNuclearElasticClass;
using CPP = multigroup::CoulombPlusNuclearElastic;

static const std::string CLASSNAME = "CoulombPlusNuclearElastic";

namespace extract {
   static auto href = [](auto &obj) { return &obj.href; };
   static auto identicalParticles = [](auto &obj) { return &obj.identicalParticles; };
   static auto label = [](auto &obj) { return &obj.label; };
   static auto pid = [](auto &obj) { return &obj.pid; };
   static auto productFrame = [](auto &obj) { return &obj.productFrame; };
   static auto RutherfordScattering = [](auto &obj) { return &obj.RutherfordScattering; };
   static auto nuclearAmplitudeExpansion = [](auto &obj) { return &obj.nuclearAmplitudeExpansion; };
}

using CPPRutherfordScattering = cpTransport::RutherfordScattering;
using CPPNuclearAmplitudeExpansion = cpTransport::NuclearAmplitudeExpansion;


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
   const XMLName href,
   const bool identicalParticles,
   const XMLName label,
   const XMLName pid,
   const enums::Frame productFrame,
   ConstHandle2ConstRutherfordScattering RutherfordScattering,
   ConstHandle2ConstNuclearAmplitudeExpansion nuclearAmplitudeExpansion
) {
   ConstHandle2CoulombPlusNuclearElastic handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      href,
      identicalParticles,
      label,
      pid,
      productFrame,
      detail::tocpp<CPPRutherfordScattering>(RutherfordScattering),
      detail::tocpp<CPPNuclearAmplitudeExpansion>(nuclearAmplitudeExpansion)
   );
   return handle;
}

// Create, general
Handle2CoulombPlusNuclearElastic
CoulombPlusNuclearElasticCreate(
   const XMLName href,
   const bool identicalParticles,
   const XMLName label,
   const XMLName pid,
   const enums::Frame productFrame,
   ConstHandle2ConstRutherfordScattering RutherfordScattering,
   ConstHandle2ConstNuclearAmplitudeExpansion nuclearAmplitudeExpansion
) {
   ConstHandle2CoulombPlusNuclearElastic handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      href,
      identicalParticles,
      label,
      pid,
      productFrame,
      detail::tocpp<CPPRutherfordScattering>(RutherfordScattering),
      detail::tocpp<CPPNuclearAmplitudeExpansion>(nuclearAmplitudeExpansion)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
CoulombPlusNuclearElasticAssign(ConstHandle2CoulombPlusNuclearElastic self, ConstHandle2ConstCoulombPlusNuclearElastic from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
CoulombPlusNuclearElasticDelete(ConstHandle2ConstCoulombPlusNuclearElastic self)
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
CoulombPlusNuclearElasticRead(ConstHandle2CoulombPlusNuclearElastic self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
CoulombPlusNuclearElasticWrite(ConstHandle2ConstCoulombPlusNuclearElastic self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
CoulombPlusNuclearElasticPrint(ConstHandle2ConstCoulombPlusNuclearElastic self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
CoulombPlusNuclearElasticPrintXML(ConstHandle2ConstCoulombPlusNuclearElastic self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
CoulombPlusNuclearElasticPrintJSON(ConstHandle2ConstCoulombPlusNuclearElastic self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// Has
int
CoulombPlusNuclearElasticHrefHas(ConstHandle2ConstCoulombPlusNuclearElastic self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"HrefHas", self, extract::href);
}

// Get
// Returns by value
XMLName
CoulombPlusNuclearElasticHrefGet(ConstHandle2ConstCoulombPlusNuclearElastic self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"HrefGet", self, extract::href);
}

// Set
void
CoulombPlusNuclearElasticHrefSet(ConstHandle2CoulombPlusNuclearElastic self, const XMLName href)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"HrefSet", self, extract::href, href);
}


// -----------------------------------------------------------------------------
// Metadatum: identicalParticles
// -----------------------------------------------------------------------------

// Has
int
CoulombPlusNuclearElasticIdenticalParticlesHas(ConstHandle2ConstCoulombPlusNuclearElastic self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"IdenticalParticlesHas", self, extract::identicalParticles);
}

// Get
// Returns by value
bool
CoulombPlusNuclearElasticIdenticalParticlesGet(ConstHandle2ConstCoulombPlusNuclearElastic self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"IdenticalParticlesGet", self, extract::identicalParticles);
}

// Set
void
CoulombPlusNuclearElasticIdenticalParticlesSet(ConstHandle2CoulombPlusNuclearElastic self, const bool identicalParticles)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"IdenticalParticlesSet", self, extract::identicalParticles, identicalParticles);
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
CoulombPlusNuclearElasticLabelHas(ConstHandle2ConstCoulombPlusNuclearElastic self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
XMLName
CoulombPlusNuclearElasticLabelGet(ConstHandle2ConstCoulombPlusNuclearElastic self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
CoulombPlusNuclearElasticLabelSet(ConstHandle2CoulombPlusNuclearElastic self, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: pid
// -----------------------------------------------------------------------------

// Has
int
CoulombPlusNuclearElasticPidHas(ConstHandle2ConstCoulombPlusNuclearElastic self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"PidHas", self, extract::pid);
}

// Get
// Returns by value
XMLName
CoulombPlusNuclearElasticPidGet(ConstHandle2ConstCoulombPlusNuclearElastic self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"PidGet", self, extract::pid);
}

// Set
void
CoulombPlusNuclearElasticPidSet(ConstHandle2CoulombPlusNuclearElastic self, const XMLName pid)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"PidSet", self, extract::pid, pid);
}


// -----------------------------------------------------------------------------
// Metadatum: productFrame
// -----------------------------------------------------------------------------

// Has
int
CoulombPlusNuclearElasticProductFrameHas(ConstHandle2ConstCoulombPlusNuclearElastic self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ProductFrameHas", self, extract::productFrame);
}

// Get
// Returns by value
enums::Frame
CoulombPlusNuclearElasticProductFrameGet(ConstHandle2ConstCoulombPlusNuclearElastic self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ProductFrameGet", self, extract::productFrame);
}

// Set
void
CoulombPlusNuclearElasticProductFrameSet(ConstHandle2CoulombPlusNuclearElastic self, const enums::Frame productFrame)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ProductFrameSet", self, extract::productFrame, productFrame);
}


// -----------------------------------------------------------------------------
// Child: RutherfordScattering
// -----------------------------------------------------------------------------

// Has
int
CoulombPlusNuclearElasticRutherfordScatteringHas(ConstHandle2ConstCoulombPlusNuclearElastic self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"RutherfordScatteringHas", self, extract::RutherfordScattering);
}

// Get, const
Handle2ConstRutherfordScattering
CoulombPlusNuclearElasticRutherfordScatteringGetConst(ConstHandle2ConstCoulombPlusNuclearElastic self)
{
   return detail::getField<CPP,Handle2ConstRutherfordScattering>
      (CLASSNAME, CLASSNAME+"RutherfordScatteringGetConst", self, extract::RutherfordScattering);
}

// Get, non-const
Handle2RutherfordScattering
CoulombPlusNuclearElasticRutherfordScatteringGet(ConstHandle2CoulombPlusNuclearElastic self)
{
   return detail::getField<CPP,Handle2RutherfordScattering>
      (CLASSNAME, CLASSNAME+"RutherfordScatteringGet", self, extract::RutherfordScattering);
}

// Set
void
CoulombPlusNuclearElasticRutherfordScatteringSet(ConstHandle2CoulombPlusNuclearElastic self, ConstHandle2ConstRutherfordScattering RutherfordScattering)
{
   detail::setField<CPP,CPPRutherfordScattering>
      (CLASSNAME, CLASSNAME+"RutherfordScatteringSet", self, extract::RutherfordScattering, RutherfordScattering);
}


// -----------------------------------------------------------------------------
// Child: nuclearAmplitudeExpansion
// -----------------------------------------------------------------------------

// Has
int
CoulombPlusNuclearElasticNuclearAmplitudeExpansionHas(ConstHandle2ConstCoulombPlusNuclearElastic self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"NuclearAmplitudeExpansionHas", self, extract::nuclearAmplitudeExpansion);
}

// Get, const
Handle2ConstNuclearAmplitudeExpansion
CoulombPlusNuclearElasticNuclearAmplitudeExpansionGetConst(ConstHandle2ConstCoulombPlusNuclearElastic self)
{
   return detail::getField<CPP,Handle2ConstNuclearAmplitudeExpansion>
      (CLASSNAME, CLASSNAME+"NuclearAmplitudeExpansionGetConst", self, extract::nuclearAmplitudeExpansion);
}

// Get, non-const
Handle2NuclearAmplitudeExpansion
CoulombPlusNuclearElasticNuclearAmplitudeExpansionGet(ConstHandle2CoulombPlusNuclearElastic self)
{
   return detail::getField<CPP,Handle2NuclearAmplitudeExpansion>
      (CLASSNAME, CLASSNAME+"NuclearAmplitudeExpansionGet", self, extract::nuclearAmplitudeExpansion);
}

// Set
void
CoulombPlusNuclearElasticNuclearAmplitudeExpansionSet(ConstHandle2CoulombPlusNuclearElastic self, ConstHandle2ConstNuclearAmplitudeExpansion nuclearAmplitudeExpansion)
{
   detail::setField<CPP,CPPNuclearAmplitudeExpansion>
      (CLASSNAME, CLASSNAME+"NuclearAmplitudeExpansionSet", self, extract::nuclearAmplitudeExpansion, nuclearAmplitudeExpansion);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/cpTransport/CoulombPlusNuclearElastic/src/custom.cpp"
