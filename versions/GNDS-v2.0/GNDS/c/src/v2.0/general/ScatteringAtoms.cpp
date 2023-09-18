
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/ScatteringAtoms.hpp"
#include "ScatteringAtoms.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = ScatteringAtomsClass;
using CPP = multigroup::ScatteringAtoms;

static const std::string CLASSNAME = "ScatteringAtoms";

namespace extract {
   static auto scatteringAtom = [](auto &obj) { return &obj.scatteringAtom; };
}

using CPPScatteringAtom = general::ScatteringAtom;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstScatteringAtoms
ScatteringAtomsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2ScatteringAtoms
ScatteringAtomsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstScatteringAtoms
ScatteringAtomsCreateConst(
   ConstHandle2ScatteringAtom *const scatteringAtom, const size_t scatteringAtomSize
) {
   ConstHandle2ScatteringAtoms handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPScatteringAtom>{}
   );
   for (size_t ScatteringAtomN = 0; ScatteringAtomN < scatteringAtomSize; ++ScatteringAtomN)
      ScatteringAtomsScatteringAtomAdd(handle, scatteringAtom[ScatteringAtomN]);
   return handle;
}

// Create, general
Handle2ScatteringAtoms
ScatteringAtomsCreate(
   ConstHandle2ScatteringAtom *const scatteringAtom, const size_t scatteringAtomSize
) {
   ConstHandle2ScatteringAtoms handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPScatteringAtom>{}
   );
   for (size_t ScatteringAtomN = 0; ScatteringAtomN < scatteringAtomSize; ++ScatteringAtomN)
      ScatteringAtomsScatteringAtomAdd(handle, scatteringAtom[ScatteringAtomN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ScatteringAtomsAssign(ConstHandle2ScatteringAtoms self, ConstHandle2ConstScatteringAtoms from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ScatteringAtomsDelete(ConstHandle2ConstScatteringAtoms self)
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
ScatteringAtomsRead(ConstHandle2ScatteringAtoms self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ScatteringAtomsWrite(ConstHandle2ConstScatteringAtoms self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ScatteringAtomsPrint(ConstHandle2ConstScatteringAtoms self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ScatteringAtomsPrintXML(ConstHandle2ConstScatteringAtoms self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ScatteringAtomsPrintJSON(ConstHandle2ConstScatteringAtoms self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: scatteringAtom
// -----------------------------------------------------------------------------

// Has
int
ScatteringAtomsScatteringAtomHas(ConstHandle2ConstScatteringAtoms self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ScatteringAtomHas", self, extract::scatteringAtom);
}

// Clear
void
ScatteringAtomsScatteringAtomClear(ConstHandle2ScatteringAtoms self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"ScatteringAtomClear", self, extract::scatteringAtom);
}

// Size
size_t
ScatteringAtomsScatteringAtomSize(ConstHandle2ConstScatteringAtoms self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"ScatteringAtomSize", self, extract::scatteringAtom);
}

// Add
void
ScatteringAtomsScatteringAtomAdd(ConstHandle2ScatteringAtoms self, ConstHandle2ConstScatteringAtom scatteringAtom)
{
   detail::addToContainer<CPP,CPPScatteringAtom>
      (CLASSNAME, CLASSNAME+"ScatteringAtomAdd", self, extract::scatteringAtom, scatteringAtom);
}

// Get, by index \in [0,size), const
Handle2ConstScatteringAtom
ScatteringAtomsScatteringAtomGetConst(ConstHandle2ConstScatteringAtoms self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstScatteringAtom>
      (CLASSNAME, CLASSNAME+"ScatteringAtomGetConst", self, extract::scatteringAtom, index_);
}

// Get, by index \in [0,size)
Handle2ScatteringAtom
ScatteringAtomsScatteringAtomGet(ConstHandle2ScatteringAtoms self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ScatteringAtom>
      (CLASSNAME, CLASSNAME+"ScatteringAtomGet", self, extract::scatteringAtom, index_);
}

// Set, by index \in [0,size)
void
ScatteringAtomsScatteringAtomSet(
   ConstHandle2ScatteringAtoms self,
   const size_t index_,
   ConstHandle2ConstScatteringAtom scatteringAtom
) {
   detail::setByIndex<CPP,CPPScatteringAtom>
      (CLASSNAME, CLASSNAME+"ScatteringAtomSet", self, extract::scatteringAtom, index_, scatteringAtom);
}

// Has, by pid
int
ScatteringAtomsScatteringAtomHasByPid(
   ConstHandle2ConstScatteringAtoms self,
   const char *const pid
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ScatteringAtomHasByPid",
       self, extract::scatteringAtom, meta::pid, pid);
}

// Get, by pid, const
Handle2ConstScatteringAtom
ScatteringAtomsScatteringAtomGetByPidConst(
   ConstHandle2ConstScatteringAtoms self,
   const char *const pid
) {
   return detail::getByMetadatum<CPP,Handle2ConstScatteringAtom>
      (CLASSNAME, CLASSNAME+"ScatteringAtomGetByPidConst",
       self, extract::scatteringAtom, meta::pid, pid);
}

// Get, by pid
Handle2ScatteringAtom
ScatteringAtomsScatteringAtomGetByPid(
   ConstHandle2ScatteringAtoms self,
   const char *const pid
) {
   return detail::getByMetadatum<CPP,Handle2ScatteringAtom>
      (CLASSNAME, CLASSNAME+"ScatteringAtomGetByPid",
       self, extract::scatteringAtom, meta::pid, pid);
}

// Set, by pid
void
ScatteringAtomsScatteringAtomSetByPid(
   ConstHandle2ScatteringAtoms self,
   const char *const pid,
   ConstHandle2ConstScatteringAtom scatteringAtom
) {
   detail::setByMetadatum<CPP,CPPScatteringAtom>
      (CLASSNAME, CLASSNAME+"ScatteringAtomSetByPid",
       self, extract::scatteringAtom, meta::pid, pid, scatteringAtom);
}

// Has, by numberPerMolecule
int
ScatteringAtomsScatteringAtomHasByNumberPerMolecule(
   ConstHandle2ConstScatteringAtoms self,
   const int numberPerMolecule
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ScatteringAtomHasByNumberPerMolecule",
       self, extract::scatteringAtom, meta::numberPerMolecule, numberPerMolecule);
}

// Get, by numberPerMolecule, const
Handle2ConstScatteringAtom
ScatteringAtomsScatteringAtomGetByNumberPerMoleculeConst(
   ConstHandle2ConstScatteringAtoms self,
   const int numberPerMolecule
) {
   return detail::getByMetadatum<CPP,Handle2ConstScatteringAtom>
      (CLASSNAME, CLASSNAME+"ScatteringAtomGetByNumberPerMoleculeConst",
       self, extract::scatteringAtom, meta::numberPerMolecule, numberPerMolecule);
}

// Get, by numberPerMolecule
Handle2ScatteringAtom
ScatteringAtomsScatteringAtomGetByNumberPerMolecule(
   ConstHandle2ScatteringAtoms self,
   const int numberPerMolecule
) {
   return detail::getByMetadatum<CPP,Handle2ScatteringAtom>
      (CLASSNAME, CLASSNAME+"ScatteringAtomGetByNumberPerMolecule",
       self, extract::scatteringAtom, meta::numberPerMolecule, numberPerMolecule);
}

// Set, by numberPerMolecule
void
ScatteringAtomsScatteringAtomSetByNumberPerMolecule(
   ConstHandle2ScatteringAtoms self,
   const int numberPerMolecule,
   ConstHandle2ConstScatteringAtom scatteringAtom
) {
   detail::setByMetadatum<CPP,CPPScatteringAtom>
      (CLASSNAME, CLASSNAME+"ScatteringAtomSetByNumberPerMolecule",
       self, extract::scatteringAtom, meta::numberPerMolecule, numberPerMolecule, scatteringAtom);
}

// Has, by primaryScatterer
int
ScatteringAtomsScatteringAtomHasByPrimaryScatterer(
   ConstHandle2ConstScatteringAtoms self,
   const bool primaryScatterer
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ScatteringAtomHasByPrimaryScatterer",
       self, extract::scatteringAtom, meta::primaryScatterer, primaryScatterer);
}

// Get, by primaryScatterer, const
Handle2ConstScatteringAtom
ScatteringAtomsScatteringAtomGetByPrimaryScattererConst(
   ConstHandle2ConstScatteringAtoms self,
   const bool primaryScatterer
) {
   return detail::getByMetadatum<CPP,Handle2ConstScatteringAtom>
      (CLASSNAME, CLASSNAME+"ScatteringAtomGetByPrimaryScattererConst",
       self, extract::scatteringAtom, meta::primaryScatterer, primaryScatterer);
}

// Get, by primaryScatterer
Handle2ScatteringAtom
ScatteringAtomsScatteringAtomGetByPrimaryScatterer(
   ConstHandle2ScatteringAtoms self,
   const bool primaryScatterer
) {
   return detail::getByMetadatum<CPP,Handle2ScatteringAtom>
      (CLASSNAME, CLASSNAME+"ScatteringAtomGetByPrimaryScatterer",
       self, extract::scatteringAtom, meta::primaryScatterer, primaryScatterer);
}

// Set, by primaryScatterer
void
ScatteringAtomsScatteringAtomSetByPrimaryScatterer(
   ConstHandle2ScatteringAtoms self,
   const bool primaryScatterer,
   ConstHandle2ConstScatteringAtom scatteringAtom
) {
   detail::setByMetadatum<CPP,CPPScatteringAtom>
      (CLASSNAME, CLASSNAME+"ScatteringAtomSetByPrimaryScatterer",
       self, extract::scatteringAtom, meta::primaryScatterer, primaryScatterer, scatteringAtom);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/ScatteringAtoms/src/custom.cpp"
