
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/ChemicalElement.hpp"
#include "ChemicalElement.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = ChemicalElementClass;
using CPP = multigroup::ChemicalElement;

static const std::string CLASSNAME = "ChemicalElement";

namespace extract {
   static auto symbol = [](auto &obj) { return &obj.symbol; };
   static auto Z = [](auto &obj) { return &obj.Z; };
   static auto name = [](auto &obj) { return &obj.name; };
   static auto atomic = [](auto &obj) { return &obj.atomic; };
   static auto isotopes = [](auto &obj) { return &obj.isotopes; };
}

using CPPAtomic = general::Atomic;
using CPPIsotopes = general::Isotopes;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstChemicalElement
ChemicalElementDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2ChemicalElement
ChemicalElementDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstChemicalElement
ChemicalElementCreateConst(
   const char *const symbol,
   const int Z,
   const char *const name,
   ConstHandle2ConstAtomic atomic,
   ConstHandle2ConstIsotopes isotopes
) {
   ConstHandle2ChemicalElement handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      symbol,
      Z,
      name,
      detail::tocpp<CPPAtomic>(atomic),
      detail::tocpp<CPPIsotopes>(isotopes)
   );
   return handle;
}

// Create, general
Handle2ChemicalElement
ChemicalElementCreate(
   const char *const symbol,
   const int Z,
   const char *const name,
   ConstHandle2ConstAtomic atomic,
   ConstHandle2ConstIsotopes isotopes
) {
   ConstHandle2ChemicalElement handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      symbol,
      Z,
      name,
      detail::tocpp<CPPAtomic>(atomic),
      detail::tocpp<CPPIsotopes>(isotopes)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ChemicalElementAssign(ConstHandle2ChemicalElement self, ConstHandle2ConstChemicalElement from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ChemicalElementDelete(ConstHandle2ConstChemicalElement self)
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
ChemicalElementRead(ConstHandle2ChemicalElement self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ChemicalElementWrite(ConstHandle2ConstChemicalElement self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ChemicalElementPrint(ConstHandle2ConstChemicalElement self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ChemicalElementPrintXML(ConstHandle2ConstChemicalElement self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ChemicalElementPrintJSON(ConstHandle2ConstChemicalElement self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: symbol
// -----------------------------------------------------------------------------

// Has
int
ChemicalElementSymbolHas(ConstHandle2ConstChemicalElement self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SymbolHas", self, extract::symbol);
}

// Get
// Returns by value
const char *
ChemicalElementSymbolGet(ConstHandle2ConstChemicalElement self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"SymbolGet", self, extract::symbol);
}

// Set
void
ChemicalElementSymbolSet(ConstHandle2ChemicalElement self, const char *const symbol)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"SymbolSet", self, extract::symbol, symbol);
}


// -----------------------------------------------------------------------------
// Metadatum: Z
// -----------------------------------------------------------------------------

// Has
int
ChemicalElementZHas(ConstHandle2ConstChemicalElement self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ZHas", self, extract::Z);
}

// Get
// Returns by value
int
ChemicalElementZGet(ConstHandle2ConstChemicalElement self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ZGet", self, extract::Z);
}

// Set
void
ChemicalElementZSet(ConstHandle2ChemicalElement self, const int Z)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ZSet", self, extract::Z, Z);
}


// -----------------------------------------------------------------------------
// Metadatum: name
// -----------------------------------------------------------------------------

// Has
int
ChemicalElementNameHas(ConstHandle2ConstChemicalElement self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"NameHas", self, extract::name);
}

// Get
// Returns by value
const char *
ChemicalElementNameGet(ConstHandle2ConstChemicalElement self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"NameGet", self, extract::name);
}

// Set
void
ChemicalElementNameSet(ConstHandle2ChemicalElement self, const char *const name)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"NameSet", self, extract::name, name);
}


// -----------------------------------------------------------------------------
// Child: atomic
// -----------------------------------------------------------------------------

// Has
int
ChemicalElementAtomicHas(ConstHandle2ConstChemicalElement self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AtomicHas", self, extract::atomic);
}

// Get, const
Handle2ConstAtomic
ChemicalElementAtomicGetConst(ConstHandle2ConstChemicalElement self)
{
   return detail::getField<CPP,Handle2ConstAtomic>
      (CLASSNAME, CLASSNAME+"AtomicGetConst", self, extract::atomic);
}

// Get, non-const
Handle2Atomic
ChemicalElementAtomicGet(ConstHandle2ChemicalElement self)
{
   return detail::getField<CPP,Handle2Atomic>
      (CLASSNAME, CLASSNAME+"AtomicGet", self, extract::atomic);
}

// Set
void
ChemicalElementAtomicSet(ConstHandle2ChemicalElement self, ConstHandle2ConstAtomic atomic)
{
   detail::setField<CPP,CPPAtomic>
      (CLASSNAME, CLASSNAME+"AtomicSet", self, extract::atomic, atomic);
}


// -----------------------------------------------------------------------------
// Child: isotopes
// -----------------------------------------------------------------------------

// Has
int
ChemicalElementIsotopesHas(ConstHandle2ConstChemicalElement self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"IsotopesHas", self, extract::isotopes);
}

// Get, const
Handle2ConstIsotopes
ChemicalElementIsotopesGetConst(ConstHandle2ConstChemicalElement self)
{
   return detail::getField<CPP,Handle2ConstIsotopes>
      (CLASSNAME, CLASSNAME+"IsotopesGetConst", self, extract::isotopes);
}

// Get, non-const
Handle2Isotopes
ChemicalElementIsotopesGet(ConstHandle2ChemicalElement self)
{
   return detail::getField<CPP,Handle2Isotopes>
      (CLASSNAME, CLASSNAME+"IsotopesGet", self, extract::isotopes);
}

// Set
void
ChemicalElementIsotopesSet(ConstHandle2ChemicalElement self, ConstHandle2ConstIsotopes isotopes)
{
   detail::setField<CPP,CPPIsotopes>
      (CLASSNAME, CLASSNAME+"IsotopesSet", self, extract::isotopes, isotopes);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/ChemicalElement/src/custom.cpp"