
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

using CPPFoobar = multigroup::Foobar;
using CPPIsotope = multigroup::Isotope;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create: default, const
Handle2ConstElement
ElementDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, "ElementDefaultConst");
}

// Create: default
Handle2Element
ElementDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, "ElementDefault");
}

// Create: general, const
Handle2ConstElement
ElementCreateConst(
   const char *const symbol,
   const int atomic_number,
   ConstHandle2ConstIsotope *const isotope, const size_t isotopeSize,
   ConstHandle2ConstFoobar foobar
) {
   ConstHandle2Element handle = detail::createHandle<CPP,C>(
      CLASSNAME, "ElementCreateConst",
      symbol,
      atomic_number,
      std::vector<CPPIsotope>{},
      detail::tocpp<CPPFoobar>(foobar)
   );
   for (size_t IsotopeN = 0; IsotopeN < isotopeSize; ++IsotopeN)
      ElementIsotopeAdd(handle, isotope[IsotopeN]);
   return handle;
}

// Create: general
Handle2Element
ElementCreate(
   const char *const symbol,
   const int atomic_number,
   ConstHandle2ConstIsotope *const isotope, const size_t isotopeSize,
   ConstHandle2ConstFoobar foobar
) {
   ConstHandle2Element handle = detail::createHandle<CPP,C>(
      CLASSNAME, "ElementCreate",
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
void
ElementAssign(ConstHandle2Element This, ConstHandle2ConstElement from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, "ElementAssign", This, from);
}

// Delete
void
ElementDelete(ConstHandle2ConstElement This)
{
   detail::deleteHandle<CPP,C>
      (CLASSNAME, "ElementDelete", This);
}


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// Read
int
ElementRead(ConstHandle2Element This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, "ElementRead", This, filename);
}

// Write
int
ElementWrite(ConstHandle2ConstElement This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, "ElementWrite", This, filename);
}

// Print to standard output
int
ElementPrint(ConstHandle2ConstElement This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, "ElementPrint", This);
}

// Print to standard output, as XML
int
ElementPrintXML(ConstHandle2ConstElement This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, "ElementPrintXML", This, "XML");
}

// Print to standard output, as JSON
int
ElementPrintJSON(ConstHandle2ConstElement This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, "ElementPrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Re: symbol
// -----------------------------------------------------------------------------

// Has
int
ElementSymbolHas(ConstHandle2ConstElement This)
{
   return detail::hasMetadatum<CPP>
      (CLASSNAME, "ElementSymbolHas", This, extract::symbol);
}

// Get
const char *
ElementSymbolGet(ConstHandle2ConstElement This)
{
   return detail::getMetadatum<CPP>
      (CLASSNAME, "ElementSymbolGet", This, extract::symbol);
}

// Set
void
ElementSymbolSet(ConstHandle2Element This, const char *const symbol)
{
   detail::setMetadatum<CPP>
      (CLASSNAME, "ElementSymbolSet", This, extract::symbol, symbol);
}


// -----------------------------------------------------------------------------
// Re: atomic_number
// -----------------------------------------------------------------------------

// Has
int
ElementAtomicNumberHas(ConstHandle2ConstElement This)
{
   return detail::hasMetadatum<CPP>
      (CLASSNAME, "ElementAtomicNumberHas", This, extract::atomic_number);
}

// Get
int
ElementAtomicNumberGet(ConstHandle2ConstElement This)
{
   return detail::getMetadatum<CPP>
      (CLASSNAME, "ElementAtomicNumberGet", This, extract::atomic_number);
}

// Set
void
ElementAtomicNumberSet(ConstHandle2Element This, const int atomic_number)
{
   detail::setMetadatum<CPP>
      (CLASSNAME, "ElementAtomicNumberSet", This, extract::atomic_number, atomic_number);
}


// -----------------------------------------------------------------------------
// Re: isotope
// -----------------------------------------------------------------------------

// Clear
void
ElementIsotopeClear(ConstHandle2Element This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, "ElementIsotopeClear", This, extract::isotope);
}

// Size
size_t
ElementIsotopeSize(ConstHandle2ConstElement This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, "ElementIsotopeSize", This, extract::isotope);
}

// Has
int
ElementIsotopeHas(ConstHandle2ConstElement This)
{
   return detail::hasMetadatum<CPP>
      (CLASSNAME, "ElementIsotopeHas", This, extract::isotope);
}

// Add
void
ElementIsotopeAdd(ConstHandle2Element This, ConstHandle2ConstIsotope isotope)
{
   detail::addToContainer<CPP,CPPIsotope>
      (CLASSNAME, "ElementIsotopeAdd", This, extract::isotope, isotope);
}

// Get, by index \in [0,size), const
Handle2ConstIsotope
ElementIsotopeGetConst(ConstHandle2ConstElement This, const size_t index)
{
   return detail::getByIndex<CPP,Handle2ConstIsotope>
      (CLASSNAME, "ElementIsotopeGetConst", This, extract::isotope, index);
}

// Get, by index \in [0,size), non-const
Handle2Isotope
ElementIsotopeGet(ConstHandle2Element This, const size_t index)
{
   return detail::getByIndex<CPP,Handle2Isotope>
      (CLASSNAME, "ElementIsotopeGet", This, extract::isotope, index);
}

// Set, by index \in [0,size)
void
ElementIsotopeSet(
   ConstHandle2Element This,
   const size_t index,
   ConstHandle2ConstIsotope isotope
) {
   detail::setByIndex<CPP,CPPIsotope>
      (CLASSNAME, "ElementIsotopeSet", This, extract::isotope, index, isotope);
}

// Has, by mass_number
int
ElementIsotopeHasByMassNumber(
   ConstHandle2ConstElement This,
   const int mass_number
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, "ElementIsotopeHasByMassNumber",
       This, extract::isotope, meta::mass_number, mass_number);
}

// Get, by mass_number, const
Handle2ConstIsotope
ElementIsotopeGetByMassNumberConst(
   ConstHandle2ConstElement This,
   const int mass_number
) {
   return detail::getByMetadatum<CPP,Handle2ConstIsotope>
      (CLASSNAME, "ElementIsotopeGetByMassNumberConst",
       This, extract::isotope, meta::mass_number, mass_number);
}

// Get, by mass_number, non-const
Handle2Isotope
ElementIsotopeGetByMassNumber(
   ConstHandle2Element This,
   const int mass_number
) {
   return detail::getByMetadatum<CPP,Handle2Isotope>
      (CLASSNAME, "ElementIsotopeGetByMassNumber",
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
      (CLASSNAME, "ElementIsotopeSetByMassNumber",
       This, extract::isotope, meta::mass_number, mass_number, isotope);
}


// -----------------------------------------------------------------------------
// Re: foobar
// -----------------------------------------------------------------------------

// Has
int
ElementFoobarHas(ConstHandle2ConstElement This)
{
   return detail::hasMetadatum<CPP>
      (CLASSNAME, "ElementFoobarHas", This, extract::foobar);
}

// Get: const
Handle2ConstFoobar
ElementFoobarGetConst(ConstHandle2ConstElement This)
{
   return detail::getMetadatum<CPP,Handle2ConstFoobar>
      (CLASSNAME, "ElementFoobarGetConst", This, extract::foobar);
}

// Get: non-const
Handle2Foobar
ElementFoobarGet(ConstHandle2Element This)
{
   return detail::getMetadatum<CPP,Handle2Foobar>
      (CLASSNAME, "ElementFoobarGet", This, extract::foobar);
}

// Set
void
ElementFoobarSet(ConstHandle2Element This, ConstHandle2ConstFoobar foobar)
{
   detail::setMetadatum<CPP,CPPFoobar>
      (CLASSNAME, "ElementFoobarSet", This, extract::foobar, foobar);
}