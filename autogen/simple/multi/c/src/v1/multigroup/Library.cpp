
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "multi/v1/multigroup/Library.hpp"
#include "Library.h"

using namespace njoy::GNDStk;
using namespace multi::v1;

using C = LibraryClass;
using CPP = multigroup::Library;

static const std::string CLASSNAME = "Library";

namespace extract {
   static auto name = [](auto &obj) { return &obj.name; };
   static auto element = [](auto &obj) { return &obj.element; };
}

using CPPElement = multigroup::Element;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstLibrary
LibraryDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Library
LibraryDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstLibrary
LibraryCreateConst(
   const char *const name,
   ConstHandle2ConstElement *const element, const size_t elementSize
) {
   ConstHandle2Library handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      name,
      std::vector<CPPElement>{}
   );
   for (size_t ElementN = 0; ElementN < elementSize; ++ElementN)
      LibraryElementAdd(handle, element[ElementN]);
   return handle;
}

// Create, general
Handle2Library
LibraryCreate(
   const char *const name,
   ConstHandle2ConstElement *const element, const size_t elementSize
) {
   ConstHandle2Library handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      name,
      std::vector<CPPElement>{}
   );
   for (size_t ElementN = 0; ElementN < elementSize; ++ElementN)
      LibraryElementAdd(handle, element[ElementN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
LibraryAssign(ConstHandle2Library This, ConstHandle2ConstLibrary from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
LibraryDelete(ConstHandle2ConstLibrary This)
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
LibraryRead(ConstHandle2Library This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
LibraryWrite(ConstHandle2ConstLibrary This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
LibraryPrint(ConstHandle2ConstLibrary This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
LibraryPrintXML(ConstHandle2ConstLibrary This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
LibraryPrintJSON(ConstHandle2ConstLibrary This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: name
// -----------------------------------------------------------------------------

// Get
// Returns by value
const char *
LibraryNameGet(ConstHandle2ConstLibrary This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"NameGet", This, extract::name);
}

// Set
void
LibraryNameSet(ConstHandle2Library This, const char *const name)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"NameSet", This, extract::name, name);
}


// -----------------------------------------------------------------------------
// Child: element
// -----------------------------------------------------------------------------

// Clear
void
LibraryElementClear(ConstHandle2Library This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"ElementClear", This, extract::element);
}

// Size
size_t
LibraryElementSize(ConstHandle2ConstLibrary This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"ElementSize", This, extract::element);
}

// Add
void
LibraryElementAdd(ConstHandle2Library This, ConstHandle2ConstElement element)
{
   detail::addToContainer<CPP,CPPElement>
      (CLASSNAME, CLASSNAME+"ElementAdd", This, extract::element, element);
}

// Get, by index \in [0,size), const
Handle2ConstElement
LibraryElementGetConst(ConstHandle2ConstLibrary This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstElement>
      (CLASSNAME, CLASSNAME+"ElementGetConst", This, extract::element, index_);
}

// Get, by index \in [0,size), non-const
Handle2Element
LibraryElementGet(ConstHandle2Library This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Element>
      (CLASSNAME, CLASSNAME+"ElementGet", This, extract::element, index_);
}

// Set, by index \in [0,size)
void
LibraryElementSet(
   ConstHandle2Library This,
   const size_t index_,
   ConstHandle2ConstElement element
) {
   detail::setByIndex<CPP,CPPElement>
      (CLASSNAME, CLASSNAME+"ElementSet", This, extract::element, index_, element);
}

// Has, by symbol
int
LibraryElementHasBySymbol(
   ConstHandle2ConstLibrary This,
   const char *const symbol
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ElementHasBySymbol",
       This, extract::element, meta::symbol, symbol);
}

// Get, by symbol, const
Handle2ConstElement
LibraryElementGetBySymbolConst(
   ConstHandle2ConstLibrary This,
   const char *const symbol
) {
   return detail::getByMetadatum<CPP,Handle2ConstElement>
      (CLASSNAME, CLASSNAME+"ElementGetBySymbolConst",
       This, extract::element, meta::symbol, symbol);
}

// Get, by symbol, non-const
Handle2Element
LibraryElementGetBySymbol(
   ConstHandle2Library This,
   const char *const symbol
) {
   return detail::getByMetadatum<CPP,Handle2Element>
      (CLASSNAME, CLASSNAME+"ElementGetBySymbol",
       This, extract::element, meta::symbol, symbol);
}

// Set, by symbol
void
LibraryElementSetBySymbol(
   ConstHandle2Library This,
   const char *const symbol,
   ConstHandle2ConstElement element
) {
   detail::setByMetadatum<CPP,CPPElement>
      (CLASSNAME, CLASSNAME+"ElementSetBySymbol",
       This, extract::element, meta::symbol, symbol, element);
}

// Has, by atomic_number
int
LibraryElementHasByAtomicNumber(
   ConstHandle2ConstLibrary This,
   const int atomic_number
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ElementHasByAtomicNumber",
       This, extract::element, meta::atomic_number, atomic_number);
}

// Get, by atomic_number, const
Handle2ConstElement
LibraryElementGetByAtomicNumberConst(
   ConstHandle2ConstLibrary This,
   const int atomic_number
) {
   return detail::getByMetadatum<CPP,Handle2ConstElement>
      (CLASSNAME, CLASSNAME+"ElementGetByAtomicNumberConst",
       This, extract::element, meta::atomic_number, atomic_number);
}

// Get, by atomic_number, non-const
Handle2Element
LibraryElementGetByAtomicNumber(
   ConstHandle2Library This,
   const int atomic_number
) {
   return detail::getByMetadatum<CPP,Handle2Element>
      (CLASSNAME, CLASSNAME+"ElementGetByAtomicNumber",
       This, extract::element, meta::atomic_number, atomic_number);
}

// Set, by atomic_number
void
LibraryElementSetByAtomicNumber(
   ConstHandle2Library This,
   const int atomic_number,
   ConstHandle2ConstElement element
) {
   detail::setByMetadatum<CPP,CPPElement>
      (CLASSNAME, CLASSNAME+"ElementSetByAtomicNumber",
       This, extract::element, meta::atomic_number, atomic_number, element);
}
