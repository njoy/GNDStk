
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/FissionComponents.hpp"
#include "FissionComponents.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = FissionComponentsClass;
using CPP = multigroup::FissionComponents;

static const std::string CLASSNAME = "FissionComponents";

namespace extract {
   static auto fissionComponent = [](auto &obj) { return &obj.fissionComponent; };
}

using CPPFissionComponent = general::FissionComponent;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstFissionComponents
FissionComponentsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2FissionComponents
FissionComponentsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstFissionComponents
FissionComponentsCreateConst(
   ConstHandle2FissionComponent *const fissionComponent, const size_t fissionComponentSize
) {
   ConstHandle2FissionComponents handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPFissionComponent>{}
   );
   for (size_t FissionComponentN = 0; FissionComponentN < fissionComponentSize; ++FissionComponentN)
      FissionComponentsFissionComponentAdd(handle, fissionComponent[FissionComponentN]);
   return handle;
}

// Create, general
Handle2FissionComponents
FissionComponentsCreate(
   ConstHandle2FissionComponent *const fissionComponent, const size_t fissionComponentSize
) {
   ConstHandle2FissionComponents handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPFissionComponent>{}
   );
   for (size_t FissionComponentN = 0; FissionComponentN < fissionComponentSize; ++FissionComponentN)
      FissionComponentsFissionComponentAdd(handle, fissionComponent[FissionComponentN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
FissionComponentsAssign(ConstHandle2FissionComponents self, ConstHandle2ConstFissionComponents from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
FissionComponentsDelete(ConstHandle2ConstFissionComponents self)
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
FissionComponentsRead(ConstHandle2FissionComponents self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
FissionComponentsWrite(ConstHandle2ConstFissionComponents self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
FissionComponentsPrint(ConstHandle2ConstFissionComponents self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
FissionComponentsPrintXML(ConstHandle2ConstFissionComponents self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
FissionComponentsPrintJSON(ConstHandle2ConstFissionComponents self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: fissionComponent
// -----------------------------------------------------------------------------

// Has
int
FissionComponentsFissionComponentHas(ConstHandle2ConstFissionComponents self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"FissionComponentHas", self, extract::fissionComponent);
}

// Clear
void
FissionComponentsFissionComponentClear(ConstHandle2FissionComponents self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"FissionComponentClear", self, extract::fissionComponent);
}

// Size
size_t
FissionComponentsFissionComponentSize(ConstHandle2ConstFissionComponents self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"FissionComponentSize", self, extract::fissionComponent);
}

// Add
void
FissionComponentsFissionComponentAdd(ConstHandle2FissionComponents self, ConstHandle2ConstFissionComponent fissionComponent)
{
   detail::addToContainer<CPP,CPPFissionComponent>
      (CLASSNAME, CLASSNAME+"FissionComponentAdd", self, extract::fissionComponent, fissionComponent);
}

// Get, by index \in [0,size), const
Handle2ConstFissionComponent
FissionComponentsFissionComponentGetConst(ConstHandle2ConstFissionComponents self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstFissionComponent>
      (CLASSNAME, CLASSNAME+"FissionComponentGetConst", self, extract::fissionComponent, index_);
}

// Get, by index \in [0,size)
Handle2FissionComponent
FissionComponentsFissionComponentGet(ConstHandle2FissionComponents self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2FissionComponent>
      (CLASSNAME, CLASSNAME+"FissionComponentGet", self, extract::fissionComponent, index_);
}

// Set, by index \in [0,size)
void
FissionComponentsFissionComponentSet(
   ConstHandle2FissionComponents self,
   const size_t index_,
   ConstHandle2ConstFissionComponent fissionComponent
) {
   detail::setByIndex<CPP,CPPFissionComponent>
      (CLASSNAME, CLASSNAME+"FissionComponentSet", self, extract::fissionComponent, index_, fissionComponent);
}

// Has, by label
int
FissionComponentsFissionComponentHasByLabel(
   ConstHandle2ConstFissionComponents self,
   const char *const label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"FissionComponentHasByLabel",
       self, extract::fissionComponent, meta::label, label);
}

// Get, by label, const
Handle2ConstFissionComponent
FissionComponentsFissionComponentGetByLabelConst(
   ConstHandle2ConstFissionComponents self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2ConstFissionComponent>
      (CLASSNAME, CLASSNAME+"FissionComponentGetByLabelConst",
       self, extract::fissionComponent, meta::label, label);
}

// Get, by label
Handle2FissionComponent
FissionComponentsFissionComponentGetByLabel(
   ConstHandle2FissionComponents self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2FissionComponent>
      (CLASSNAME, CLASSNAME+"FissionComponentGetByLabel",
       self, extract::fissionComponent, meta::label, label);
}

// Set, by label
void
FissionComponentsFissionComponentSetByLabel(
   ConstHandle2FissionComponents self,
   const char *const label,
   ConstHandle2ConstFissionComponent fissionComponent
) {
   detail::setByMetadatum<CPP,CPPFissionComponent>
      (CLASSNAME, CLASSNAME+"FissionComponentSetByLabel",
       self, extract::fissionComponent, meta::label, label, fissionComponent);
}

// Has, by ENDF_MT
int
FissionComponentsFissionComponentHasByENDFMT(
   ConstHandle2ConstFissionComponents self,
   const int ENDF_MT
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"FissionComponentHasByENDFMT",
       self, extract::fissionComponent, meta::ENDF_MT, ENDF_MT);
}

// Get, by ENDF_MT, const
Handle2ConstFissionComponent
FissionComponentsFissionComponentGetByENDFMTConst(
   ConstHandle2ConstFissionComponents self,
   const int ENDF_MT
) {
   return detail::getByMetadatum<CPP,Handle2ConstFissionComponent>
      (CLASSNAME, CLASSNAME+"FissionComponentGetByENDFMTConst",
       self, extract::fissionComponent, meta::ENDF_MT, ENDF_MT);
}

// Get, by ENDF_MT
Handle2FissionComponent
FissionComponentsFissionComponentGetByENDFMT(
   ConstHandle2FissionComponents self,
   const int ENDF_MT
) {
   return detail::getByMetadatum<CPP,Handle2FissionComponent>
      (CLASSNAME, CLASSNAME+"FissionComponentGetByENDFMT",
       self, extract::fissionComponent, meta::ENDF_MT, ENDF_MT);
}

// Set, by ENDF_MT
void
FissionComponentsFissionComponentSetByENDFMT(
   ConstHandle2FissionComponents self,
   const int ENDF_MT,
   ConstHandle2ConstFissionComponent fissionComponent
) {
   detail::setByMetadatum<CPP,CPPFissionComponent>
      (CLASSNAME, CLASSNAME+"FissionComponentSetByENDFMT",
       self, extract::fissionComponent, meta::ENDF_MT, ENDF_MT, fissionComponent);
}

// Has, by fissionGenre
int
FissionComponentsFissionComponentHasByFissionGenre(
   ConstHandle2ConstFissionComponents self,
   const char *const fissionGenre
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"FissionComponentHasByFissionGenre",
       self, extract::fissionComponent, meta::fissionGenre, fissionGenre);
}

// Get, by fissionGenre, const
Handle2ConstFissionComponent
FissionComponentsFissionComponentGetByFissionGenreConst(
   ConstHandle2ConstFissionComponents self,
   const char *const fissionGenre
) {
   return detail::getByMetadatum<CPP,Handle2ConstFissionComponent>
      (CLASSNAME, CLASSNAME+"FissionComponentGetByFissionGenreConst",
       self, extract::fissionComponent, meta::fissionGenre, fissionGenre);
}

// Get, by fissionGenre
Handle2FissionComponent
FissionComponentsFissionComponentGetByFissionGenre(
   ConstHandle2FissionComponents self,
   const char *const fissionGenre
) {
   return detail::getByMetadatum<CPP,Handle2FissionComponent>
      (CLASSNAME, CLASSNAME+"FissionComponentGetByFissionGenre",
       self, extract::fissionComponent, meta::fissionGenre, fissionGenre);
}

// Set, by fissionGenre
void
FissionComponentsFissionComponentSetByFissionGenre(
   ConstHandle2FissionComponents self,
   const char *const fissionGenre,
   ConstHandle2ConstFissionComponent fissionComponent
) {
   detail::setByMetadatum<CPP,CPPFissionComponent>
      (CLASSNAME, CLASSNAME+"FissionComponentSetByFissionGenre",
       self, extract::fissionComponent, meta::fissionGenre, fissionGenre, fissionComponent);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/FissionComponents/src/custom.cpp"
