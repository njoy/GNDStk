
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/pops/Nuclides.hpp"
#include "Nuclides.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = NuclidesClass;
using CPP = multigroup::Nuclides;

static const std::string CLASSNAME = "Nuclides";

namespace extract {
   static auto nuclide = [](auto &obj) { return &obj.nuclide; };
}

using CPPNuclide = pops::Nuclide;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstNuclides
NuclidesDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Nuclides
NuclidesDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstNuclides
NuclidesCreateConst(
   ConstHandle2Nuclide *const nuclide, const size_t nuclideSize
) {
   ConstHandle2Nuclides handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPNuclide>{}
   );
   for (size_t NuclideN = 0; NuclideN < nuclideSize; ++NuclideN)
      NuclidesNuclideAdd(handle, nuclide[NuclideN]);
   return handle;
}

// Create, general
Handle2Nuclides
NuclidesCreate(
   ConstHandle2Nuclide *const nuclide, const size_t nuclideSize
) {
   ConstHandle2Nuclides handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPNuclide>{}
   );
   for (size_t NuclideN = 0; NuclideN < nuclideSize; ++NuclideN)
      NuclidesNuclideAdd(handle, nuclide[NuclideN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
NuclidesAssign(ConstHandle2Nuclides This, ConstHandle2ConstNuclides from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
NuclidesDelete(ConstHandle2ConstNuclides This)
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
NuclidesRead(ConstHandle2Nuclides This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
NuclidesWrite(ConstHandle2ConstNuclides This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
NuclidesPrint(ConstHandle2ConstNuclides This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
NuclidesPrintXML(ConstHandle2ConstNuclides This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
NuclidesPrintJSON(ConstHandle2ConstNuclides This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: nuclide
// -----------------------------------------------------------------------------

// Has
int
NuclidesNuclideHas(ConstHandle2ConstNuclides This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"NuclideHas", This, extract::nuclide);
}

// Clear
void
NuclidesNuclideClear(ConstHandle2Nuclides This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"NuclideClear", This, extract::nuclide);
}

// Size
size_t
NuclidesNuclideSize(ConstHandle2ConstNuclides This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"NuclideSize", This, extract::nuclide);
}

// Add
void
NuclidesNuclideAdd(ConstHandle2Nuclides This, ConstHandle2ConstNuclide nuclide)
{
   detail::addToContainer<CPP,CPPNuclide>
      (CLASSNAME, CLASSNAME+"NuclideAdd", This, extract::nuclide, nuclide);
}

// Get, by index \in [0,size), const
Handle2ConstNuclide
NuclidesNuclideGetConst(ConstHandle2ConstNuclides This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstNuclide>
      (CLASSNAME, CLASSNAME+"NuclideGetConst", This, extract::nuclide, index_);
}

// Get, by index \in [0,size), non-const
Handle2Nuclide
NuclidesNuclideGet(ConstHandle2Nuclides This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Nuclide>
      (CLASSNAME, CLASSNAME+"NuclideGet", This, extract::nuclide, index_);
}

// Set, by index \in [0,size)
void
NuclidesNuclideSet(
   ConstHandle2Nuclides This,
   const size_t index_,
   ConstHandle2ConstNuclide nuclide
) {
   detail::setByIndex<CPP,CPPNuclide>
      (CLASSNAME, CLASSNAME+"NuclideSet", This, extract::nuclide, index_, nuclide);
}

// Has, by id
int
NuclidesNuclideHasById(
   ConstHandle2ConstNuclides This,
   const XMLName id
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"NuclideHasById",
       This, extract::nuclide, meta::id, id);
}

// Get, by id, const
Handle2ConstNuclide
NuclidesNuclideGetByIdConst(
   ConstHandle2ConstNuclides This,
   const XMLName id
) {
   return detail::getByMetadatum<CPP,Handle2ConstNuclide>
      (CLASSNAME, CLASSNAME+"NuclideGetByIdConst",
       This, extract::nuclide, meta::id, id);
}

// Get, by id, non-const
Handle2Nuclide
NuclidesNuclideGetById(
   ConstHandle2Nuclides This,
   const XMLName id
) {
   return detail::getByMetadatum<CPP,Handle2Nuclide>
      (CLASSNAME, CLASSNAME+"NuclideGetById",
       This, extract::nuclide, meta::id, id);
}

// Set, by id
void
NuclidesNuclideSetById(
   ConstHandle2Nuclides This,
   const XMLName id,
   ConstHandle2ConstNuclide nuclide
) {
   detail::setByMetadatum<CPP,CPPNuclide>
      (CLASSNAME, CLASSNAME+"NuclideSetById",
       This, extract::nuclide, meta::id, id, nuclide);
}
