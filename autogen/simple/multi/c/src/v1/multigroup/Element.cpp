
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "multi/v1/multigroup/Element.hpp"
#include "Element.h"

using namespace njoy::GNDStk;
using namespace multi::v1;

using C = ElementClass;
using CPP = multigroup::Element;

static const std::string CLASSNAME = "Element";

namespace extract {
   static auto symbol = [](auto &obj) { return &obj.symbol; };
   static auto atomic_number = [](auto &obj) { return &obj.atomic_number; };
   static auto isotope = [](auto &obj) { return &obj.isotope; };
   static auto foobar = [](auto &obj) { return &obj.foobar; };
}

using CPPIsotope = multigroup::Isotope;
using CPPFoobar = multigroup::Foobar;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstElement
ElementDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Element
ElementDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstElement
ElementCreateConst(
   const char *const symbol,
   const int atomic_number,
   ConstHandle2ConstIsotope *const isotope, const size_t isotopeSize,
   ConstHandle2ConstFoobar foobar
) {
   ConstHandle2Element handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      symbol,
      atomic_number,
      std::vector<CPPIsotope>{},
      detail::tocpp<CPPFoobar>(foobar)
   );
   for (size_t IsotopeN = 0; IsotopeN < isotopeSize; ++IsotopeN)
      ElementIsotopeAdd(handle, isotope[IsotopeN]);
   return handle;
}

// Create, general
Handle2Element
ElementCreate(
   const char *const symbol,
   const int atomic_number,
   ConstHandle2ConstIsotope *const isotope, const size_t isotopeSize,
   ConstHandle2ConstFoobar foobar
) {
   ConstHandle2Element handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      symbol,
      atomic_number,
      std::vector<CPPIsotope>{},
      detail::tocpp<CPPFoobar>(foobar)
   );
   for (size_t IsotopeN = 0; IsotopeN < isotopeSize; ++IsotopeN)
      ElementIsotopeAdd(handle, isotope[IsotopeN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ElementAssign(ConstHandle2Element This, ConstHandle2ConstElement from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ElementDelete(ConstHandle2ConstElement This)
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
ElementRead(ConstHandle2Element This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ElementWrite(ConstHandle2ConstElement This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
ElementPrint(ConstHandle2ConstElement This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
ElementPrintXML(ConstHandle2ConstElement This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
ElementPrintJSON(ConstHandle2ConstElement This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: symbol
// -----------------------------------------------------------------------------

// Has
int
ElementSymbolHas(ConstHandle2ConstElement This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SymbolHas", This, extract::symbol);
}

// Get
// Returns by value
const char *
ElementSymbolGet(ConstHandle2ConstElement This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"SymbolGet", This, extract::symbol);
}

// Set
void
ElementSymbolSet(ConstHandle2Element This, const char *const symbol)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"SymbolSet", This, extract::symbol, symbol);
}


// -----------------------------------------------------------------------------
// Metadatum: atomic_number
// -----------------------------------------------------------------------------

// Get
// Returns by value
int
ElementAtomicNumberGet(ConstHandle2ConstElement This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"AtomicNumberGet", This, extract::atomic_number);
}

// Set
void
ElementAtomicNumberSet(ConstHandle2Element This, const int atomic_number)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"AtomicNumberSet", This, extract::atomic_number, atomic_number);
}


// -----------------------------------------------------------------------------
// Child: isotope
// -----------------------------------------------------------------------------

// Clear
void
ElementIsotopeClear(ConstHandle2Element This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"IsotopeClear", This, extract::isotope);
}

// Size
size_t
ElementIsotopeSize(ConstHandle2ConstElement This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"IsotopeSize", This, extract::isotope);
}

// Add
void
ElementIsotopeAdd(ConstHandle2Element This, ConstHandle2ConstIsotope isotope)
{
   detail::addToContainer<CPP,CPPIsotope>
      (CLASSNAME, CLASSNAME+"IsotopeAdd", This, extract::isotope, isotope);
}

// Get, by index \in [0,size), const
Handle2ConstIsotope
ElementIsotopeGetConst(ConstHandle2ConstElement This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstIsotope>
      (CLASSNAME, CLASSNAME+"IsotopeGetConst", This, extract::isotope, index_);
}

// Get, by index \in [0,size), non-const
Handle2Isotope
ElementIsotopeGet(ConstHandle2Element This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Isotope>
      (CLASSNAME, CLASSNAME+"IsotopeGet", This, extract::isotope, index_);
}

// Set, by index \in [0,size)
void
ElementIsotopeSet(
   ConstHandle2Element This,
   const size_t index_,
   ConstHandle2ConstIsotope isotope
) {
   detail::setByIndex<CPP,CPPIsotope>
      (CLASSNAME, CLASSNAME+"IsotopeSet", This, extract::isotope, index_, isotope);
}

// Has, by mass_number
int
ElementIsotopeHasByMassNumber(
   ConstHandle2ConstElement This,
   const int mass_number
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"IsotopeHasByMassNumber",
       This, extract::isotope, meta::mass_number, mass_number);
}

// Get, by mass_number, const
Handle2ConstIsotope
ElementIsotopeGetByMassNumberConst(
   ConstHandle2ConstElement This,
   const int mass_number
) {
   return detail::getByMetadatum<CPP,Handle2ConstIsotope>
      (CLASSNAME, CLASSNAME+"IsotopeGetByMassNumberConst",
       This, extract::isotope, meta::mass_number, mass_number);
}

// Get, by mass_number, non-const
Handle2Isotope
ElementIsotopeGetByMassNumber(
   ConstHandle2Element This,
   const int mass_number
) {
   return detail::getByMetadatum<CPP,Handle2Isotope>
      (CLASSNAME, CLASSNAME+"IsotopeGetByMassNumber",
       This, extract::isotope, meta::mass_number, mass_number);
}

// Set, by mass_number
void
ElementIsotopeSetByMassNumber(
   ConstHandle2Element This,
   const int mass_number,
   ConstHandle2ConstIsotope isotope
) {
   detail::setByMetadatum<CPP,CPPIsotope>
      (CLASSNAME, CLASSNAME+"IsotopeSetByMassNumber",
       This, extract::isotope, meta::mass_number, mass_number, isotope);
}


// -----------------------------------------------------------------------------
// Child: foobar
// -----------------------------------------------------------------------------

// Has
int
ElementFoobarHas(ConstHandle2ConstElement This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"FoobarHas", This, extract::foobar);
}

// Get, const
Handle2ConstFoobar
ElementFoobarGetConst(ConstHandle2ConstElement This)
{
   return detail::getField<CPP,Handle2ConstFoobar>
      (CLASSNAME, CLASSNAME+"FoobarGetConst", This, extract::foobar);
}

// Get, non-const
Handle2Foobar
ElementFoobarGet(ConstHandle2Element This)
{
   return detail::getField<CPP,Handle2Foobar>
      (CLASSNAME, CLASSNAME+"FoobarGet", This, extract::foobar);
}

// Set
void
ElementFoobarSet(ConstHandle2Element This, ConstHandle2ConstFoobar foobar)
{
   detail::setField<CPP,CPPFoobar>
      (CLASSNAME, CLASSNAME+"FoobarSet", This, extract::foobar, foobar);
}
