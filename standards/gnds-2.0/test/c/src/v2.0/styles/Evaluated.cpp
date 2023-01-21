
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/styles/Evaluated.hpp"
#include "Evaluated.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = EvaluatedClass;
using CPP = multigroup::Evaluated;

static const std::string CLASSNAME = "Evaluated";

namespace extract {
   static auto date = [](auto &obj) { return &obj.date; };
   static auto label = [](auto &obj) { return &obj.label; };
   static auto derivedFrom = [](auto &obj) { return &obj.derivedFrom; };
   static auto library = [](auto &obj) { return &obj.library; };
   static auto version = [](auto &obj) { return &obj.version; };
   static auto projectileEnergyDomain = [](auto &obj) { return &obj.projectileEnergyDomain; };
   static auto temperature = [](auto &obj) { return &obj.temperature; };
   static auto documentation = [](auto &obj) { return &obj.documentation; };
}

using CPPProjectileEnergyDomain = styles::ProjectileEnergyDomain;
using CPPTemperature = styles::Temperature;
using CPPDocumentation = documentation::Documentation;


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
   const char *const date,
   const XMLName label,
   const XMLName derivedFrom,
   const XMLName library,
   const XMLName version,
   ConstHandle2ConstProjectileEnergyDomain projectileEnergyDomain,
   ConstHandle2ConstTemperature temperature,
   ConstHandle2ConstDocumentation documentation
) {
   ConstHandle2Evaluated handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      date,
      label,
      derivedFrom,
      library,
      version,
      detail::tocpp<CPPProjectileEnergyDomain>(projectileEnergyDomain),
      detail::tocpp<CPPTemperature>(temperature),
      detail::tocpp<CPPDocumentation>(documentation)
   );
   return handle;
}

// Create, general
Handle2Evaluated
EvaluatedCreate(
   const char *const date,
   const XMLName label,
   const XMLName derivedFrom,
   const XMLName library,
   const XMLName version,
   ConstHandle2ConstProjectileEnergyDomain projectileEnergyDomain,
   ConstHandle2ConstTemperature temperature,
   ConstHandle2ConstDocumentation documentation
) {
   ConstHandle2Evaluated handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      date,
      label,
      derivedFrom,
      library,
      version,
      detail::tocpp<CPPProjectileEnergyDomain>(projectileEnergyDomain),
      detail::tocpp<CPPTemperature>(temperature),
      detail::tocpp<CPPDocumentation>(documentation)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
EvaluatedAssign(ConstHandle2Evaluated This, ConstHandle2ConstEvaluated from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
EvaluatedDelete(ConstHandle2ConstEvaluated This)
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
EvaluatedRead(ConstHandle2Evaluated This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
EvaluatedWrite(ConstHandle2ConstEvaluated This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
EvaluatedPrint(ConstHandle2ConstEvaluated This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
EvaluatedPrintXML(ConstHandle2ConstEvaluated This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
EvaluatedPrintJSON(ConstHandle2ConstEvaluated This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: date
// -----------------------------------------------------------------------------

// Has
int
EvaluatedDateHas(ConstHandle2ConstEvaluated This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DateHas", This, extract::date);
}

// Get
// Returns by value
const char *
EvaluatedDateGet(ConstHandle2ConstEvaluated This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DateGet", This, extract::date);
}

// Set
void
EvaluatedDateSet(ConstHandle2Evaluated This, const char *const date)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DateSet", This, extract::date, date);
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
EvaluatedLabelHas(ConstHandle2ConstEvaluated This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
EvaluatedLabelGet(ConstHandle2ConstEvaluated This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
EvaluatedLabelSet(ConstHandle2Evaluated This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: derivedFrom
// -----------------------------------------------------------------------------

// Has
int
EvaluatedDerivedFromHas(ConstHandle2ConstEvaluated This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DerivedFromHas", This, extract::derivedFrom);
}

// Get
// Returns by value
XMLName
EvaluatedDerivedFromGet(ConstHandle2ConstEvaluated This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DerivedFromGet", This, extract::derivedFrom);
}

// Set
void
EvaluatedDerivedFromSet(ConstHandle2Evaluated This, const XMLName derivedFrom)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DerivedFromSet", This, extract::derivedFrom, derivedFrom);
}


// -----------------------------------------------------------------------------
// Metadatum: library
// -----------------------------------------------------------------------------

// Has
int
EvaluatedLibraryHas(ConstHandle2ConstEvaluated This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LibraryHas", This, extract::library);
}

// Get
// Returns by value
XMLName
EvaluatedLibraryGet(ConstHandle2ConstEvaluated This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LibraryGet", This, extract::library);
}

// Set
void
EvaluatedLibrarySet(ConstHandle2Evaluated This, const XMLName library)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LibrarySet", This, extract::library, library);
}


// -----------------------------------------------------------------------------
// Metadatum: version
// -----------------------------------------------------------------------------

// Has
int
EvaluatedVersionHas(ConstHandle2ConstEvaluated This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"VersionHas", This, extract::version);
}

// Get
// Returns by value
XMLName
EvaluatedVersionGet(ConstHandle2ConstEvaluated This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"VersionGet", This, extract::version);
}

// Set
void
EvaluatedVersionSet(ConstHandle2Evaluated This, const XMLName version)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"VersionSet", This, extract::version, version);
}


// -----------------------------------------------------------------------------
// Child: projectileEnergyDomain
// -----------------------------------------------------------------------------

// Has
int
EvaluatedProjectileEnergyDomainHas(ConstHandle2ConstEvaluated This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ProjectileEnergyDomainHas", This, extract::projectileEnergyDomain);
}

// Get, const
Handle2ConstProjectileEnergyDomain
EvaluatedProjectileEnergyDomainGetConst(ConstHandle2ConstEvaluated This)
{
   return detail::getField<CPP,Handle2ConstProjectileEnergyDomain>
      (CLASSNAME, CLASSNAME+"ProjectileEnergyDomainGetConst", This, extract::projectileEnergyDomain);
}

// Get, non-const
Handle2ProjectileEnergyDomain
EvaluatedProjectileEnergyDomainGet(ConstHandle2Evaluated This)
{
   return detail::getField<CPP,Handle2ProjectileEnergyDomain>
      (CLASSNAME, CLASSNAME+"ProjectileEnergyDomainGet", This, extract::projectileEnergyDomain);
}

// Set
void
EvaluatedProjectileEnergyDomainSet(ConstHandle2Evaluated This, ConstHandle2ConstProjectileEnergyDomain projectileEnergyDomain)
{
   detail::setField<CPP,CPPProjectileEnergyDomain>
      (CLASSNAME, CLASSNAME+"ProjectileEnergyDomainSet", This, extract::projectileEnergyDomain, projectileEnergyDomain);
}


// -----------------------------------------------------------------------------
// Child: temperature
// -----------------------------------------------------------------------------

// Has
int
EvaluatedTemperatureHas(ConstHandle2ConstEvaluated This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"TemperatureHas", This, extract::temperature);
}

// Get, const
Handle2ConstTemperature
EvaluatedTemperatureGetConst(ConstHandle2ConstEvaluated This)
{
   return detail::getField<CPP,Handle2ConstTemperature>
      (CLASSNAME, CLASSNAME+"TemperatureGetConst", This, extract::temperature);
}

// Get, non-const
Handle2Temperature
EvaluatedTemperatureGet(ConstHandle2Evaluated This)
{
   return detail::getField<CPP,Handle2Temperature>
      (CLASSNAME, CLASSNAME+"TemperatureGet", This, extract::temperature);
}

// Set
void
EvaluatedTemperatureSet(ConstHandle2Evaluated This, ConstHandle2ConstTemperature temperature)
{
   detail::setField<CPP,CPPTemperature>
      (CLASSNAME, CLASSNAME+"TemperatureSet", This, extract::temperature, temperature);
}


// -----------------------------------------------------------------------------
// Child: documentation
// -----------------------------------------------------------------------------

// Has
int
EvaluatedDocumentationHas(ConstHandle2ConstEvaluated This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DocumentationHas", This, extract::documentation);
}

// Get, const
Handle2ConstDocumentation
EvaluatedDocumentationGetConst(ConstHandle2ConstEvaluated This)
{
   return detail::getField<CPP,Handle2ConstDocumentation>
      (CLASSNAME, CLASSNAME+"DocumentationGetConst", This, extract::documentation);
}

// Get, non-const
Handle2Documentation
EvaluatedDocumentationGet(ConstHandle2Evaluated This)
{
   return detail::getField<CPP,Handle2Documentation>
      (CLASSNAME, CLASSNAME+"DocumentationGet", This, extract::documentation);
}

// Set
void
EvaluatedDocumentationSet(ConstHandle2Evaluated This, ConstHandle2ConstDocumentation documentation)
{
   detail::setField<CPP,CPPDocumentation>
      (CLASSNAME, CLASSNAME+"DocumentationSet", This, extract::documentation, documentation);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/styles/Evaluated/src/custom.cpp"
