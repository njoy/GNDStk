
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/styles/Bondarenko.hpp"
#include "Bondarenko.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = BondarenkoClass;
using CPP = multigroup::Bondarenko;

static const std::string CLASSNAME = "Bondarenko";

namespace extract {
   static auto date = [](auto &obj) { return &obj.date; };
   static auto derivedFrom = [](auto &obj) { return &obj.derivedFrom; };
   static auto label = [](auto &obj) { return &obj.label; };
   static auto sigmaZeros = [](auto &obj) { return &obj.sigmaZeros; };
   static auto documentation = [](auto &obj) { return &obj.documentation; };
}

using CPPSigmaZeros = styles::SigmaZeros;
using CPPDocumentation = documentation::Documentation;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstBondarenko
BondarenkoDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Bondarenko
BondarenkoDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstBondarenko
BondarenkoCreateConst(
   const char *const date,
   const XMLName derivedFrom,
   const XMLName label,
   ConstHandle2ConstSigmaZeros sigmaZeros,
   ConstHandle2ConstDocumentation documentation
) {
   ConstHandle2Bondarenko handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      date,
      derivedFrom,
      label,
      detail::tocpp<CPPSigmaZeros>(sigmaZeros),
      detail::tocpp<CPPDocumentation>(documentation)
   );
   return handle;
}

// Create, general
Handle2Bondarenko
BondarenkoCreate(
   const char *const date,
   const XMLName derivedFrom,
   const XMLName label,
   ConstHandle2ConstSigmaZeros sigmaZeros,
   ConstHandle2ConstDocumentation documentation
) {
   ConstHandle2Bondarenko handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      date,
      derivedFrom,
      label,
      detail::tocpp<CPPSigmaZeros>(sigmaZeros),
      detail::tocpp<CPPDocumentation>(documentation)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
BondarenkoAssign(ConstHandle2Bondarenko self, ConstHandle2ConstBondarenko from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
BondarenkoDelete(ConstHandle2ConstBondarenko self)
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
BondarenkoRead(ConstHandle2Bondarenko self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
BondarenkoWrite(ConstHandle2ConstBondarenko self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
BondarenkoPrint(ConstHandle2ConstBondarenko self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
BondarenkoPrintXML(ConstHandle2ConstBondarenko self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
BondarenkoPrintJSON(ConstHandle2ConstBondarenko self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: date
// -----------------------------------------------------------------------------

// Has
int
BondarenkoDateHas(ConstHandle2ConstBondarenko self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DateHas", self, extract::date);
}

// Get
// Returns by value
const char *
BondarenkoDateGet(ConstHandle2ConstBondarenko self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DateGet", self, extract::date);
}

// Set
void
BondarenkoDateSet(ConstHandle2Bondarenko self, const char *const date)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DateSet", self, extract::date, date);
}


// -----------------------------------------------------------------------------
// Metadatum: derivedFrom
// -----------------------------------------------------------------------------

// Has
int
BondarenkoDerivedFromHas(ConstHandle2ConstBondarenko self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DerivedFromHas", self, extract::derivedFrom);
}

// Get
// Returns by value
XMLName
BondarenkoDerivedFromGet(ConstHandle2ConstBondarenko self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DerivedFromGet", self, extract::derivedFrom);
}

// Set
void
BondarenkoDerivedFromSet(ConstHandle2Bondarenko self, const XMLName derivedFrom)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DerivedFromSet", self, extract::derivedFrom, derivedFrom);
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
BondarenkoLabelHas(ConstHandle2ConstBondarenko self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
XMLName
BondarenkoLabelGet(ConstHandle2ConstBondarenko self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
BondarenkoLabelSet(ConstHandle2Bondarenko self, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Child: sigmaZeros
// -----------------------------------------------------------------------------

// Has
int
BondarenkoSigmaZerosHas(ConstHandle2ConstBondarenko self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SigmaZerosHas", self, extract::sigmaZeros);
}

// Get, const
Handle2ConstSigmaZeros
BondarenkoSigmaZerosGetConst(ConstHandle2ConstBondarenko self)
{
   return detail::getField<CPP,Handle2ConstSigmaZeros>
      (CLASSNAME, CLASSNAME+"SigmaZerosGetConst", self, extract::sigmaZeros);
}

// Get, non-const
Handle2SigmaZeros
BondarenkoSigmaZerosGet(ConstHandle2Bondarenko self)
{
   return detail::getField<CPP,Handle2SigmaZeros>
      (CLASSNAME, CLASSNAME+"SigmaZerosGet", self, extract::sigmaZeros);
}

// Set
void
BondarenkoSigmaZerosSet(ConstHandle2Bondarenko self, ConstHandle2ConstSigmaZeros sigmaZeros)
{
   detail::setField<CPP,CPPSigmaZeros>
      (CLASSNAME, CLASSNAME+"SigmaZerosSet", self, extract::sigmaZeros, sigmaZeros);
}


// -----------------------------------------------------------------------------
// Child: documentation
// -----------------------------------------------------------------------------

// Has
int
BondarenkoDocumentationHas(ConstHandle2ConstBondarenko self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DocumentationHas", self, extract::documentation);
}

// Get, const
Handle2ConstDocumentation
BondarenkoDocumentationGetConst(ConstHandle2ConstBondarenko self)
{
   return detail::getField<CPP,Handle2ConstDocumentation>
      (CLASSNAME, CLASSNAME+"DocumentationGetConst", self, extract::documentation);
}

// Get, non-const
Handle2Documentation
BondarenkoDocumentationGet(ConstHandle2Bondarenko self)
{
   return detail::getField<CPP,Handle2Documentation>
      (CLASSNAME, CLASSNAME+"DocumentationGet", self, extract::documentation);
}

// Set
void
BondarenkoDocumentationSet(ConstHandle2Bondarenko self, ConstHandle2ConstDocumentation documentation)
{
   detail::setField<CPP,CPPDocumentation>
      (CLASSNAME, CLASSNAME+"DocumentationSet", self, extract::documentation, documentation);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/styles/Bondarenko/src/custom.cpp"
