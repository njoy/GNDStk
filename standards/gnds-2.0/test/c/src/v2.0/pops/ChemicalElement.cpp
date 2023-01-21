
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/pops/ChemicalElement.hpp"
#include "ChemicalElement.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

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

using CPPAtomic = pops::Atomic;
using CPPIsotopes = pops::Isotopes;


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
   const XMLName symbol,
   const Integer32 Z,
   const XMLName name,
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
   const XMLName symbol,
   const Integer32 Z,
   const XMLName name,
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
ChemicalElementAssign(ConstHandle2ChemicalElement This, ConstHandle2ConstChemicalElement from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ChemicalElementDelete(ConstHandle2ConstChemicalElement This)
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
ChemicalElementRead(ConstHandle2ChemicalElement This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ChemicalElementWrite(ConstHandle2ConstChemicalElement This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
ChemicalElementPrint(ConstHandle2ConstChemicalElement This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
ChemicalElementPrintXML(ConstHandle2ConstChemicalElement This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
ChemicalElementPrintJSON(ConstHandle2ConstChemicalElement This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: symbol
// -----------------------------------------------------------------------------

// Has
int
ChemicalElementSymbolHas(ConstHandle2ConstChemicalElement This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SymbolHas", This, extract::symbol);
}

// Get
// Returns by value
XMLName
ChemicalElementSymbolGet(ConstHandle2ConstChemicalElement This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"SymbolGet", This, extract::symbol);
}

// Set
void
ChemicalElementSymbolSet(ConstHandle2ChemicalElement This, const XMLName symbol)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"SymbolSet", This, extract::symbol, symbol);
}


// -----------------------------------------------------------------------------
// Metadatum: Z
// -----------------------------------------------------------------------------

// Has
int
ChemicalElementZHas(ConstHandle2ConstChemicalElement This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ZHas", This, extract::Z);
}

// Get
// Returns by value
Integer32
ChemicalElementZGet(ConstHandle2ConstChemicalElement This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ZGet", This, extract::Z);
}

// Set
void
ChemicalElementZSet(ConstHandle2ChemicalElement This, const Integer32 Z)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ZSet", This, extract::Z, Z);
}


// -----------------------------------------------------------------------------
// Metadatum: name
// -----------------------------------------------------------------------------

// Has
int
ChemicalElementNameHas(ConstHandle2ConstChemicalElement This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"NameHas", This, extract::name);
}

// Get
// Returns by value
XMLName
ChemicalElementNameGet(ConstHandle2ConstChemicalElement This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"NameGet", This, extract::name);
}

// Set
void
ChemicalElementNameSet(ConstHandle2ChemicalElement This, const XMLName name)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"NameSet", This, extract::name, name);
}


// -----------------------------------------------------------------------------
// Child: atomic
// -----------------------------------------------------------------------------

// Has
int
ChemicalElementAtomicHas(ConstHandle2ConstChemicalElement This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AtomicHas", This, extract::atomic);
}

// Get, const
Handle2ConstAtomic
ChemicalElementAtomicGetConst(ConstHandle2ConstChemicalElement This)
{
   return detail::getField<CPP,Handle2ConstAtomic>
      (CLASSNAME, CLASSNAME+"AtomicGetConst", This, extract::atomic);
}

// Get, non-const
Handle2Atomic
ChemicalElementAtomicGet(ConstHandle2ChemicalElement This)
{
   return detail::getField<CPP,Handle2Atomic>
      (CLASSNAME, CLASSNAME+"AtomicGet", This, extract::atomic);
}

// Set
void
ChemicalElementAtomicSet(ConstHandle2ChemicalElement This, ConstHandle2ConstAtomic atomic)
{
   detail::setField<CPP,CPPAtomic>
      (CLASSNAME, CLASSNAME+"AtomicSet", This, extract::atomic, atomic);
}


// -----------------------------------------------------------------------------
// Child: isotopes
// -----------------------------------------------------------------------------

// Has
int
ChemicalElementIsotopesHas(ConstHandle2ConstChemicalElement This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"IsotopesHas", This, extract::isotopes);
}

// Get, const
Handle2ConstIsotopes
ChemicalElementIsotopesGetConst(ConstHandle2ConstChemicalElement This)
{
   return detail::getField<CPP,Handle2ConstIsotopes>
      (CLASSNAME, CLASSNAME+"IsotopesGetConst", This, extract::isotopes);
}

// Get, non-const
Handle2Isotopes
ChemicalElementIsotopesGet(ConstHandle2ChemicalElement This)
{
   return detail::getField<CPP,Handle2Isotopes>
      (CLASSNAME, CLASSNAME+"IsotopesGet", This, extract::isotopes);
}

// Set
void
ChemicalElementIsotopesSet(ConstHandle2ChemicalElement This, ConstHandle2ConstIsotopes isotopes)
{
   detail::setField<CPP,CPPIsotopes>
      (CLASSNAME, CLASSNAME+"IsotopesSet", This, extract::isotopes, isotopes);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/pops/ChemicalElement/src/custom.cpp"
