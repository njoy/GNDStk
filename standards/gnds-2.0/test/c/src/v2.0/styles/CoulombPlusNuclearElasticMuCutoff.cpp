
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/styles/CoulombPlusNuclearElasticMuCutoff.hpp"
#include "CoulombPlusNuclearElasticMuCutoff.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = CoulombPlusNuclearElasticMuCutoffClass;
using CPP = multigroup::CoulombPlusNuclearElasticMuCutoff;

static const std::string CLASSNAME = "CoulombPlusNuclearElasticMuCutoff";

namespace extract {
   static auto date = [](auto &obj) { return &obj.date; };
   static auto derivedFrom = [](auto &obj) { return &obj.derivedFrom; };
   static auto label = [](auto &obj) { return &obj.label; };
   static auto muCutoff = [](auto &obj) { return &obj.muCutoff; };
   static auto documentation = [](auto &obj) { return &obj.documentation; };
}

using CPPDocumentation = documentation::Documentation;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstCoulombPlusNuclearElasticMuCutoff
CoulombPlusNuclearElasticMuCutoffDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2CoulombPlusNuclearElasticMuCutoff
CoulombPlusNuclearElasticMuCutoffDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstCoulombPlusNuclearElasticMuCutoff
CoulombPlusNuclearElasticMuCutoffCreateConst(
   const char *const date,
   const XMLName derivedFrom,
   const XMLName label,
   const Float64 muCutoff,
   ConstHandle2ConstDocumentation documentation
) {
   ConstHandle2CoulombPlusNuclearElasticMuCutoff handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      date,
      derivedFrom,
      label,
      muCutoff,
      detail::tocpp<CPPDocumentation>(documentation)
   );
   return handle;
}

// Create, general
Handle2CoulombPlusNuclearElasticMuCutoff
CoulombPlusNuclearElasticMuCutoffCreate(
   const char *const date,
   const XMLName derivedFrom,
   const XMLName label,
   const Float64 muCutoff,
   ConstHandle2ConstDocumentation documentation
) {
   ConstHandle2CoulombPlusNuclearElasticMuCutoff handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      date,
      derivedFrom,
      label,
      muCutoff,
      detail::tocpp<CPPDocumentation>(documentation)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
CoulombPlusNuclearElasticMuCutoffAssign(ConstHandle2CoulombPlusNuclearElasticMuCutoff self, ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
CoulombPlusNuclearElasticMuCutoffDelete(ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff self)
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
CoulombPlusNuclearElasticMuCutoffRead(ConstHandle2CoulombPlusNuclearElasticMuCutoff self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
CoulombPlusNuclearElasticMuCutoffWrite(ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
CoulombPlusNuclearElasticMuCutoffPrint(ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
CoulombPlusNuclearElasticMuCutoffPrintXML(ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
CoulombPlusNuclearElasticMuCutoffPrintJSON(ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: date
// -----------------------------------------------------------------------------

// Has
int
CoulombPlusNuclearElasticMuCutoffDateHas(ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DateHas", self, extract::date);
}

// Get
// Returns by value
const char *
CoulombPlusNuclearElasticMuCutoffDateGet(ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DateGet", self, extract::date);
}

// Set
void
CoulombPlusNuclearElasticMuCutoffDateSet(ConstHandle2CoulombPlusNuclearElasticMuCutoff self, const char *const date)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DateSet", self, extract::date, date);
}


// -----------------------------------------------------------------------------
// Metadatum: derivedFrom
// -----------------------------------------------------------------------------

// Has
int
CoulombPlusNuclearElasticMuCutoffDerivedFromHas(ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DerivedFromHas", self, extract::derivedFrom);
}

// Get
// Returns by value
XMLName
CoulombPlusNuclearElasticMuCutoffDerivedFromGet(ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DerivedFromGet", self, extract::derivedFrom);
}

// Set
void
CoulombPlusNuclearElasticMuCutoffDerivedFromSet(ConstHandle2CoulombPlusNuclearElasticMuCutoff self, const XMLName derivedFrom)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DerivedFromSet", self, extract::derivedFrom, derivedFrom);
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
CoulombPlusNuclearElasticMuCutoffLabelHas(ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
XMLName
CoulombPlusNuclearElasticMuCutoffLabelGet(ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
CoulombPlusNuclearElasticMuCutoffLabelSet(ConstHandle2CoulombPlusNuclearElasticMuCutoff self, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: muCutoff
// -----------------------------------------------------------------------------

// Has
int
CoulombPlusNuclearElasticMuCutoffMuCutoffHas(ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"MuCutoffHas", self, extract::muCutoff);
}

// Get
// Returns by value
Float64
CoulombPlusNuclearElasticMuCutoffMuCutoffGet(ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"MuCutoffGet", self, extract::muCutoff);
}

// Set
void
CoulombPlusNuclearElasticMuCutoffMuCutoffSet(ConstHandle2CoulombPlusNuclearElasticMuCutoff self, const Float64 muCutoff)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"MuCutoffSet", self, extract::muCutoff, muCutoff);
}


// -----------------------------------------------------------------------------
// Child: documentation
// -----------------------------------------------------------------------------

// Has
int
CoulombPlusNuclearElasticMuCutoffDocumentationHas(ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DocumentationHas", self, extract::documentation);
}

// Get, const
Handle2ConstDocumentation
CoulombPlusNuclearElasticMuCutoffDocumentationGetConst(ConstHandle2ConstCoulombPlusNuclearElasticMuCutoff self)
{
   return detail::getField<CPP,Handle2ConstDocumentation>
      (CLASSNAME, CLASSNAME+"DocumentationGetConst", self, extract::documentation);
}

// Get, non-const
Handle2Documentation
CoulombPlusNuclearElasticMuCutoffDocumentationGet(ConstHandle2CoulombPlusNuclearElasticMuCutoff self)
{
   return detail::getField<CPP,Handle2Documentation>
      (CLASSNAME, CLASSNAME+"DocumentationGet", self, extract::documentation);
}

// Set
void
CoulombPlusNuclearElasticMuCutoffDocumentationSet(ConstHandle2CoulombPlusNuclearElasticMuCutoff self, ConstHandle2ConstDocumentation documentation)
{
   detail::setField<CPP,CPPDocumentation>
      (CLASSNAME, CLASSNAME+"DocumentationSet", self, extract::documentation, documentation);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/styles/CoulombPlusNuclearElasticMuCutoff/src/custom.cpp"
