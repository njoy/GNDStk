
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/IncidentEnergies.hpp"
#include "IncidentEnergies.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = IncidentEnergiesClass;
using CPP = multigroup::IncidentEnergies;

static const std::string CLASSNAME = "IncidentEnergies";

namespace extract {
   static auto incidentEnergy = [](auto &obj) { return &obj.incidentEnergy; };
}

using CPPIncidentEnergy = general::IncidentEnergy;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstIncidentEnergies
IncidentEnergiesDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2IncidentEnergies
IncidentEnergiesDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstIncidentEnergies
IncidentEnergiesCreateConst(
   ConstHandle2IncidentEnergy *const incidentEnergy, const size_t incidentEnergySize
) {
   ConstHandle2IncidentEnergies handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPIncidentEnergy>{}
   );
   for (size_t IncidentEnergyN = 0; IncidentEnergyN < incidentEnergySize; ++IncidentEnergyN)
      IncidentEnergiesIncidentEnergyAdd(handle, incidentEnergy[IncidentEnergyN]);
   return handle;
}

// Create, general
Handle2IncidentEnergies
IncidentEnergiesCreate(
   ConstHandle2IncidentEnergy *const incidentEnergy, const size_t incidentEnergySize
) {
   ConstHandle2IncidentEnergies handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPIncidentEnergy>{}
   );
   for (size_t IncidentEnergyN = 0; IncidentEnergyN < incidentEnergySize; ++IncidentEnergyN)
      IncidentEnergiesIncidentEnergyAdd(handle, incidentEnergy[IncidentEnergyN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
IncidentEnergiesAssign(ConstHandle2IncidentEnergies self, ConstHandle2ConstIncidentEnergies from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
IncidentEnergiesDelete(ConstHandle2ConstIncidentEnergies self)
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
IncidentEnergiesRead(ConstHandle2IncidentEnergies self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
IncidentEnergiesWrite(ConstHandle2ConstIncidentEnergies self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
IncidentEnergiesPrint(ConstHandle2ConstIncidentEnergies self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
IncidentEnergiesPrintXML(ConstHandle2ConstIncidentEnergies self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
IncidentEnergiesPrintJSON(ConstHandle2ConstIncidentEnergies self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: incidentEnergy
// -----------------------------------------------------------------------------

// Has
int
IncidentEnergiesIncidentEnergyHas(ConstHandle2ConstIncidentEnergies self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"IncidentEnergyHas", self, extract::incidentEnergy);
}

// Clear
void
IncidentEnergiesIncidentEnergyClear(ConstHandle2IncidentEnergies self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"IncidentEnergyClear", self, extract::incidentEnergy);
}

// Size
size_t
IncidentEnergiesIncidentEnergySize(ConstHandle2ConstIncidentEnergies self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"IncidentEnergySize", self, extract::incidentEnergy);
}

// Add
void
IncidentEnergiesIncidentEnergyAdd(ConstHandle2IncidentEnergies self, ConstHandle2ConstIncidentEnergy incidentEnergy)
{
   detail::addToContainer<CPP,CPPIncidentEnergy>
      (CLASSNAME, CLASSNAME+"IncidentEnergyAdd", self, extract::incidentEnergy, incidentEnergy);
}

// Get, by index \in [0,size), const
Handle2ConstIncidentEnergy
IncidentEnergiesIncidentEnergyGetConst(ConstHandle2ConstIncidentEnergies self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstIncidentEnergy>
      (CLASSNAME, CLASSNAME+"IncidentEnergyGetConst", self, extract::incidentEnergy, index_);
}

// Get, by index \in [0,size)
Handle2IncidentEnergy
IncidentEnergiesIncidentEnergyGet(ConstHandle2IncidentEnergies self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2IncidentEnergy>
      (CLASSNAME, CLASSNAME+"IncidentEnergyGet", self, extract::incidentEnergy, index_);
}

// Set, by index \in [0,size)
void
IncidentEnergiesIncidentEnergySet(
   ConstHandle2IncidentEnergies self,
   const size_t index_,
   ConstHandle2ConstIncidentEnergy incidentEnergy
) {
   detail::setByIndex<CPP,CPPIncidentEnergy>
      (CLASSNAME, CLASSNAME+"IncidentEnergySet", self, extract::incidentEnergy, index_, incidentEnergy);
}

// Has, by label
int
IncidentEnergiesIncidentEnergyHasByLabel(
   ConstHandle2ConstIncidentEnergies self,
   const char *const label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"IncidentEnergyHasByLabel",
       self, extract::incidentEnergy, meta::label, label);
}

// Get, by label, const
Handle2ConstIncidentEnergy
IncidentEnergiesIncidentEnergyGetByLabelConst(
   ConstHandle2ConstIncidentEnergies self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2ConstIncidentEnergy>
      (CLASSNAME, CLASSNAME+"IncidentEnergyGetByLabelConst",
       self, extract::incidentEnergy, meta::label, label);
}

// Get, by label
Handle2IncidentEnergy
IncidentEnergiesIncidentEnergyGetByLabel(
   ConstHandle2IncidentEnergies self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2IncidentEnergy>
      (CLASSNAME, CLASSNAME+"IncidentEnergyGetByLabel",
       self, extract::incidentEnergy, meta::label, label);
}

// Set, by label
void
IncidentEnergiesIncidentEnergySetByLabel(
   ConstHandle2IncidentEnergies self,
   const char *const label,
   ConstHandle2ConstIncidentEnergy incidentEnergy
) {
   detail::setByMetadatum<CPP,CPPIncidentEnergy>
      (CLASSNAME, CLASSNAME+"IncidentEnergySetByLabel",
       self, extract::incidentEnergy, meta::label, label, incidentEnergy);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/IncidentEnergies/src/custom.cpp"
