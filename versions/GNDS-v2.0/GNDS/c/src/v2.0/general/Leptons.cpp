
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/Leptons.hpp"
#include "Leptons.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = LeptonsClass;
using CPP = multigroup::Leptons;

static const std::string CLASSNAME = "Leptons";

namespace extract {
   static auto lepton = [](auto &obj) { return &obj.lepton; };
}

using CPPLepton = general::Lepton;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstLeptons
LeptonsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Leptons
LeptonsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstLeptons
LeptonsCreateConst(
   ConstHandle2Lepton *const lepton, const size_t leptonSize
) {
   ConstHandle2Leptons handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPLepton>{}
   );
   for (size_t LeptonN = 0; LeptonN < leptonSize; ++LeptonN)
      LeptonsLeptonAdd(handle, lepton[LeptonN]);
   return handle;
}

// Create, general
Handle2Leptons
LeptonsCreate(
   ConstHandle2Lepton *const lepton, const size_t leptonSize
) {
   ConstHandle2Leptons handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPLepton>{}
   );
   for (size_t LeptonN = 0; LeptonN < leptonSize; ++LeptonN)
      LeptonsLeptonAdd(handle, lepton[LeptonN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
LeptonsAssign(ConstHandle2Leptons self, ConstHandle2ConstLeptons from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
LeptonsDelete(ConstHandle2ConstLeptons self)
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
LeptonsRead(ConstHandle2Leptons self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
LeptonsWrite(ConstHandle2ConstLeptons self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
LeptonsPrint(ConstHandle2ConstLeptons self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
LeptonsPrintXML(ConstHandle2ConstLeptons self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
LeptonsPrintJSON(ConstHandle2ConstLeptons self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: lepton
// -----------------------------------------------------------------------------

// Has
int
LeptonsLeptonHas(ConstHandle2ConstLeptons self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LeptonHas", self, extract::lepton);
}

// Clear
void
LeptonsLeptonClear(ConstHandle2Leptons self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"LeptonClear", self, extract::lepton);
}

// Size
size_t
LeptonsLeptonSize(ConstHandle2ConstLeptons self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"LeptonSize", self, extract::lepton);
}

// Add
void
LeptonsLeptonAdd(ConstHandle2Leptons self, ConstHandle2ConstLepton lepton)
{
   detail::addToContainer<CPP,CPPLepton>
      (CLASSNAME, CLASSNAME+"LeptonAdd", self, extract::lepton, lepton);
}

// Get, by index \in [0,size), const
Handle2ConstLepton
LeptonsLeptonGetConst(ConstHandle2ConstLeptons self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstLepton>
      (CLASSNAME, CLASSNAME+"LeptonGetConst", self, extract::lepton, index_);
}

// Get, by index \in [0,size)
Handle2Lepton
LeptonsLeptonGet(ConstHandle2Leptons self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Lepton>
      (CLASSNAME, CLASSNAME+"LeptonGet", self, extract::lepton, index_);
}

// Set, by index \in [0,size)
void
LeptonsLeptonSet(
   ConstHandle2Leptons self,
   const size_t index_,
   ConstHandle2ConstLepton lepton
) {
   detail::setByIndex<CPP,CPPLepton>
      (CLASSNAME, CLASSNAME+"LeptonSet", self, extract::lepton, index_, lepton);
}

// ------------------------
// Re: metadatum id
// ------------------------

// Has, by id
int
LeptonsLeptonHasById(
   ConstHandle2ConstLeptons self,
   const char *const id
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"LeptonHasById",
       self, extract::lepton, meta::id, id);
}

// Get, by id, const
Handle2ConstLepton
LeptonsLeptonGetByIdConst(
   ConstHandle2ConstLeptons self,
   const char *const id
) {
   return detail::getByMetadatum<CPP,Handle2ConstLepton>
      (CLASSNAME, CLASSNAME+"LeptonGetByIdConst",
       self, extract::lepton, meta::id, id);
}

// Get, by id
Handle2Lepton
LeptonsLeptonGetById(
   ConstHandle2Leptons self,
   const char *const id
) {
   return detail::getByMetadatum<CPP,Handle2Lepton>
      (CLASSNAME, CLASSNAME+"LeptonGetById",
       self, extract::lepton, meta::id, id);
}

// Set, by id
void
LeptonsLeptonSetById(
   ConstHandle2Leptons self,
   const char *const id,
   ConstHandle2ConstLepton lepton
) {
   detail::setByMetadatum<CPP,CPPLepton>
      (CLASSNAME, CLASSNAME+"LeptonSetById",
       self, extract::lepton, meta::id, id, lepton);
}

// ------------------------
// Re: metadatum generation
// ------------------------

// Has, by generation
int
LeptonsLeptonHasByGeneration(
   ConstHandle2ConstLeptons self,
   const char *const generation
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"LeptonHasByGeneration",
       self, extract::lepton, meta::generation, generation);
}

// Get, by generation, const
Handle2ConstLepton
LeptonsLeptonGetByGenerationConst(
   ConstHandle2ConstLeptons self,
   const char *const generation
) {
   return detail::getByMetadatum<CPP,Handle2ConstLepton>
      (CLASSNAME, CLASSNAME+"LeptonGetByGenerationConst",
       self, extract::lepton, meta::generation, generation);
}

// Get, by generation
Handle2Lepton
LeptonsLeptonGetByGeneration(
   ConstHandle2Leptons self,
   const char *const generation
) {
   return detail::getByMetadatum<CPP,Handle2Lepton>
      (CLASSNAME, CLASSNAME+"LeptonGetByGeneration",
       self, extract::lepton, meta::generation, generation);
}

// Set, by generation
void
LeptonsLeptonSetByGeneration(
   ConstHandle2Leptons self,
   const char *const generation,
   ConstHandle2ConstLepton lepton
) {
   detail::setByMetadatum<CPP,CPPLepton>
      (CLASSNAME, CLASSNAME+"LeptonSetByGeneration",
       self, extract::lepton, meta::generation, generation, lepton);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Leptons/src/custom.cpp"
