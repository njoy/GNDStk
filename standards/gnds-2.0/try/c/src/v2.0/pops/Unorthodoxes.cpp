
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/pops/Unorthodoxes.hpp"
#include "Unorthodoxes.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = UnorthodoxesClass;
using CPP = multigroup::Unorthodoxes;

static const std::string CLASSNAME = "Unorthodoxes";

namespace extract {
   static auto unorthodox = [](auto &obj) { return &obj.unorthodox; };
}

using CPPNuclide = pops::Nuclide;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstUnorthodoxes
UnorthodoxesDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Unorthodoxes
UnorthodoxesDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstUnorthodoxes
UnorthodoxesCreateConst(
   ConstHandle2Nuclide *const unorthodox, const size_t unorthodoxSize
) {
   ConstHandle2Unorthodoxes handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPNuclide>{}
   );
   for (size_t NuclideN = 0; NuclideN < unorthodoxSize; ++NuclideN)
      UnorthodoxesNuclideAdd(handle, unorthodox[NuclideN]);
   return handle;
}

// Create, general
Handle2Unorthodoxes
UnorthodoxesCreate(
   ConstHandle2Nuclide *const unorthodox, const size_t unorthodoxSize
) {
   ConstHandle2Unorthodoxes handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPNuclide>{}
   );
   for (size_t NuclideN = 0; NuclideN < unorthodoxSize; ++NuclideN)
      UnorthodoxesNuclideAdd(handle, unorthodox[NuclideN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
UnorthodoxesAssign(ConstHandle2Unorthodoxes This, ConstHandle2ConstUnorthodoxes from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
UnorthodoxesDelete(ConstHandle2ConstUnorthodoxes This)
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
UnorthodoxesRead(ConstHandle2Unorthodoxes This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
UnorthodoxesWrite(ConstHandle2ConstUnorthodoxes This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
UnorthodoxesPrint(ConstHandle2ConstUnorthodoxes This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
UnorthodoxesPrintXML(ConstHandle2ConstUnorthodoxes This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
UnorthodoxesPrintJSON(ConstHandle2ConstUnorthodoxes This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: unorthodox
// -----------------------------------------------------------------------------

// Has
int
UnorthodoxesNuclideHas(ConstHandle2ConstUnorthodoxes This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"NuclideHas", This, extract::unorthodox);
}

// Clear
void
UnorthodoxesNuclideClear(ConstHandle2Unorthodoxes This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"NuclideClear", This, extract::unorthodox);
}

// Size
size_t
UnorthodoxesNuclideSize(ConstHandle2ConstUnorthodoxes This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"NuclideSize", This, extract::unorthodox);
}

// Add
void
UnorthodoxesNuclideAdd(ConstHandle2Unorthodoxes This, ConstHandle2ConstNuclide unorthodox)
{
   detail::addToContainer<CPP,CPPNuclide>
      (CLASSNAME, CLASSNAME+"NuclideAdd", This, extract::unorthodox, unorthodox);
}

// Get, by index \in [0,size), const
Handle2ConstNuclide
UnorthodoxesNuclideGetConst(ConstHandle2ConstUnorthodoxes This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstNuclide>
      (CLASSNAME, CLASSNAME+"NuclideGetConst", This, extract::unorthodox, index_);
}

// Get, by index \in [0,size), non-const
Handle2Nuclide
UnorthodoxesNuclideGet(ConstHandle2Unorthodoxes This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Nuclide>
      (CLASSNAME, CLASSNAME+"NuclideGet", This, extract::unorthodox, index_);
}

// Set, by index \in [0,size)
void
UnorthodoxesNuclideSet(
   ConstHandle2Unorthodoxes This,
   const size_t index_,
   ConstHandle2ConstNuclide unorthodox
) {
   detail::setByIndex<CPP,CPPNuclide>
      (CLASSNAME, CLASSNAME+"NuclideSet", This, extract::unorthodox, index_, unorthodox);
}

// Has, by id
int
UnorthodoxesNuclideHasById(
   ConstHandle2ConstUnorthodoxes This,
   const XMLName id
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"NuclideHasById",
       This, extract::unorthodox, meta::id, id);
}

// Get, by id, const
Handle2ConstNuclide
UnorthodoxesNuclideGetByIdConst(
   ConstHandle2ConstUnorthodoxes This,
   const XMLName id
) {
   return detail::getByMetadatum<CPP,Handle2ConstNuclide>
      (CLASSNAME, CLASSNAME+"NuclideGetByIdConst",
       This, extract::unorthodox, meta::id, id);
}

// Get, by id, non-const
Handle2Nuclide
UnorthodoxesNuclideGetById(
   ConstHandle2Unorthodoxes This,
   const XMLName id
) {
   return detail::getByMetadatum<CPP,Handle2Nuclide>
      (CLASSNAME, CLASSNAME+"NuclideGetById",
       This, extract::unorthodox, meta::id, id);
}

// Set, by id
void
UnorthodoxesNuclideSetById(
   ConstHandle2Unorthodoxes This,
   const XMLName id,
   ConstHandle2ConstNuclide unorthodox
) {
   detail::setByMetadatum<CPP,CPPNuclide>
      (CLASSNAME, CLASSNAME+"NuclideSetById",
       This, extract::unorthodox, meta::id, id, unorthodox);
}