
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/Evaluated.hpp"
#include "Evaluated.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = EvaluatedClass;
using CPP = multigroup::Evaluated;

static const std::string CLASSNAME = "Evaluated";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto date = [](auto &obj) { return &obj.date; };
   static auto library = [](auto &obj) { return &obj.library; };
   static auto version = [](auto &obj) { return &obj.version; };
   static auto documentation = [](auto &obj) { return &obj.documentation; };
   static auto temperature = [](auto &obj) { return &obj.temperature; };
   static auto projectileEnergyDomain = [](auto &obj) { return &obj.projectileEnergyDomain; };
}

using CPPDocumentation = general::Documentation;
using CPPTemperature = general::Temperature;
using CPPProjectileEnergyDomain = general::ProjectileEnergyDomain;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstEvaluated
EvaluatedDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Evaluated
EvaluatedDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstEvaluated
EvaluatedCreateConst(
   const char *const label,
   const char *const date,
   const char *const library,
   const char *const version,
   ConstHandle2ConstDocumentation documentation,
   ConstHandle2ConstTemperature temperature,
   ConstHandle2ConstProjectileEnergyDomain projectileEnergyDomain
) {
   ConstHandle2Evaluated handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      date,
      library,
      version,
      detail::tocpp<CPPDocumentation>(documentation),
      detail::tocpp<CPPTemperature>(temperature),
      detail::tocpp<CPPProjectileEnergyDomain>(projectileEnergyDomain)
   );
   return handle;
}

// Create, general
Handle2Evaluated
EvaluatedCreate(
   const char *const label,
   const char *const date,
   const char *const library,
   const char *const version,
   ConstHandle2ConstDocumentation documentation,
   ConstHandle2ConstTemperature temperature,
   ConstHandle2ConstProjectileEnergyDomain projectileEnergyDomain
) {
   ConstHandle2Evaluated handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      date,
      library,
      version,
      detail::tocpp<CPPDocumentation>(documentation),
      detail::tocpp<CPPTemperature>(temperature),
      detail::tocpp<CPPProjectileEnergyDomain>(projectileEnergyDomain)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
EvaluatedAssign(ConstHandle2Evaluated self, ConstHandle2ConstEvaluated from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
EvaluatedDelete(ConstHandle2ConstEvaluated self)
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
EvaluatedRead(ConstHandle2Evaluated self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
EvaluatedWrite(ConstHandle2ConstEvaluated self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
EvaluatedPrint(ConstHandle2ConstEvaluated self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
EvaluatedPrintXML(ConstHandle2ConstEvaluated self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
EvaluatedPrintJSON(ConstHandle2ConstEvaluated self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
EvaluatedLabelHas(ConstHandle2ConstEvaluated self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
const char *
EvaluatedLabelGet(ConstHandle2ConstEvaluated self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
EvaluatedLabelSet(ConstHandle2Evaluated self, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: date
// -----------------------------------------------------------------------------

// Has
int
EvaluatedDateHas(ConstHandle2ConstEvaluated self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DateHas", self, extract::date);
}

// Get
// Returns by value
const char *
EvaluatedDateGet(ConstHandle2ConstEvaluated self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DateGet", self, extract::date);
}

// Set
void
EvaluatedDateSet(ConstHandle2Evaluated self, const char *const date)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DateSet", self, extract::date, date);
}


// -----------------------------------------------------------------------------
// Metadatum: library
// -----------------------------------------------------------------------------

// Has
int
EvaluatedLibraryHas(ConstHandle2ConstEvaluated self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LibraryHas", self, extract::library);
}

// Get
// Returns by value
const char *
EvaluatedLibraryGet(ConstHandle2ConstEvaluated self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LibraryGet", self, extract::library);
}

// Set
void
EvaluatedLibrarySet(ConstHandle2Evaluated self, const char *const library)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LibrarySet", self, extract::library, library);
}


// -----------------------------------------------------------------------------
// Metadatum: version
// -----------------------------------------------------------------------------

// Has
int
EvaluatedVersionHas(ConstHandle2ConstEvaluated self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"VersionHas", self, extract::version);
}

// Get
// Returns by value
const char *
EvaluatedVersionGet(ConstHandle2ConstEvaluated self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"VersionGet", self, extract::version);
}

// Set
void
EvaluatedVersionSet(ConstHandle2Evaluated self, const char *const version)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"VersionSet", self, extract::version, version);
}


// -----------------------------------------------------------------------------
// Child: documentation
// -----------------------------------------------------------------------------

// Has
int
EvaluatedDocumentationHas(ConstHandle2ConstEvaluated self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DocumentationHas", self, extract::documentation);
}

// Get, const
Handle2ConstDocumentation
EvaluatedDocumentationGetConst(ConstHandle2ConstEvaluated self)
{
   return detail::getField<CPP,Handle2ConstDocumentation>
      (CLASSNAME, CLASSNAME+"DocumentationGetConst", self, extract::documentation);
}

// Get, non-const
Handle2Documentation
EvaluatedDocumentationGet(ConstHandle2Evaluated self)
{
   return detail::getField<CPP,Handle2Documentation>
      (CLASSNAME, CLASSNAME+"DocumentationGet", self, extract::documentation);
}

// Set
void
EvaluatedDocumentationSet(ConstHandle2Evaluated self, ConstHandle2ConstDocumentation documentation)
{
   detail::setField<CPP,CPPDocumentation>
      (CLASSNAME, CLASSNAME+"DocumentationSet", self, extract::documentation, documentation);
}


// -----------------------------------------------------------------------------
// Child: temperature
// -----------------------------------------------------------------------------

// Has
int
EvaluatedTemperatureHas(ConstHandle2ConstEvaluated self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"TemperatureHas", self, extract::temperature);
}

// Get, const
Handle2ConstTemperature
EvaluatedTemperatureGetConst(ConstHandle2ConstEvaluated self)
{
   return detail::getField<CPP,Handle2ConstTemperature>
      (CLASSNAME, CLASSNAME+"TemperatureGetConst", self, extract::temperature);
}

// Get, non-const
Handle2Temperature
EvaluatedTemperatureGet(ConstHandle2Evaluated self)
{
   return detail::getField<CPP,Handle2Temperature>
      (CLASSNAME, CLASSNAME+"TemperatureGet", self, extract::temperature);
}

// Set
void
EvaluatedTemperatureSet(ConstHandle2Evaluated self, ConstHandle2ConstTemperature temperature)
{
   detail::setField<CPP,CPPTemperature>
      (CLASSNAME, CLASSNAME+"TemperatureSet", self, extract::temperature, temperature);
}


// -----------------------------------------------------------------------------
// Child: projectileEnergyDomain
// -----------------------------------------------------------------------------

// Has
int
EvaluatedProjectileEnergyDomainHas(ConstHandle2ConstEvaluated self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ProjectileEnergyDomainHas", self, extract::projectileEnergyDomain);
}

// Get, const
Handle2ConstProjectileEnergyDomain
EvaluatedProjectileEnergyDomainGetConst(ConstHandle2ConstEvaluated self)
{
   return detail::getField<CPP,Handle2ConstProjectileEnergyDomain>
      (CLASSNAME, CLASSNAME+"ProjectileEnergyDomainGetConst", self, extract::projectileEnergyDomain);
}

// Get, non-const
Handle2ProjectileEnergyDomain
EvaluatedProjectileEnergyDomainGet(ConstHandle2Evaluated self)
{
   return detail::getField<CPP,Handle2ProjectileEnergyDomain>
      (CLASSNAME, CLASSNAME+"ProjectileEnergyDomainGet", self, extract::projectileEnergyDomain);
}

// Set
void
EvaluatedProjectileEnergyDomainSet(ConstHandle2Evaluated self, ConstHandle2ConstProjectileEnergyDomain projectileEnergyDomain)
{
   detail::setField<CPP,CPPProjectileEnergyDomain>
      (CLASSNAME, CLASSNAME+"ProjectileEnergyDomainSet", self, extract::projectileEnergyDomain, projectileEnergyDomain);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Evaluated/src/custom.cpp"
