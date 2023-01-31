
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/sfy/AverageEnergies.hpp"
#include "AverageEnergies.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = AverageEnergiesClass;
using CPP = multigroup::AverageEnergies;

static const std::string CLASSNAME = "AverageEnergies";

namespace extract {
   static auto averageEnergy = [](auto &obj) { return &obj.averageEnergy; };
}

using CPPAverageEnergy = sfy::AverageEnergy;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstAverageEnergies
AverageEnergiesDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2AverageEnergies
AverageEnergiesDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstAverageEnergies
AverageEnergiesCreateConst(
   ConstHandle2AverageEnergy *const averageEnergy, const size_t averageEnergySize
) {
   ConstHandle2AverageEnergies handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPAverageEnergy>{}
   );
   for (size_t AverageEnergyN = 0; AverageEnergyN < averageEnergySize; ++AverageEnergyN)
      AverageEnergiesAverageEnergyAdd(handle, averageEnergy[AverageEnergyN]);
   return handle;
}

// Create, general
Handle2AverageEnergies
AverageEnergiesCreate(
   ConstHandle2AverageEnergy *const averageEnergy, const size_t averageEnergySize
) {
   ConstHandle2AverageEnergies handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPAverageEnergy>{}
   );
   for (size_t AverageEnergyN = 0; AverageEnergyN < averageEnergySize; ++AverageEnergyN)
      AverageEnergiesAverageEnergyAdd(handle, averageEnergy[AverageEnergyN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
AverageEnergiesAssign(ConstHandle2AverageEnergies This, ConstHandle2ConstAverageEnergies from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
AverageEnergiesDelete(ConstHandle2ConstAverageEnergies This)
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
AverageEnergiesRead(ConstHandle2AverageEnergies This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
AverageEnergiesWrite(ConstHandle2ConstAverageEnergies This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
AverageEnergiesPrint(ConstHandle2ConstAverageEnergies This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
AverageEnergiesPrintXML(ConstHandle2ConstAverageEnergies This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
AverageEnergiesPrintJSON(ConstHandle2ConstAverageEnergies This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: averageEnergy
// -----------------------------------------------------------------------------

// Has
int
AverageEnergiesAverageEnergyHas(ConstHandle2ConstAverageEnergies This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AverageEnergyHas", This, extract::averageEnergy);
}

// Clear
void
AverageEnergiesAverageEnergyClear(ConstHandle2AverageEnergies This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"AverageEnergyClear", This, extract::averageEnergy);
}

// Size
size_t
AverageEnergiesAverageEnergySize(ConstHandle2ConstAverageEnergies This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"AverageEnergySize", This, extract::averageEnergy);
}

// Add
void
AverageEnergiesAverageEnergyAdd(ConstHandle2AverageEnergies This, ConstHandle2ConstAverageEnergy averageEnergy)
{
   detail::addToContainer<CPP,CPPAverageEnergy>
      (CLASSNAME, CLASSNAME+"AverageEnergyAdd", This, extract::averageEnergy, averageEnergy);
}

// Get, by index \in [0,size), const
Handle2ConstAverageEnergy
AverageEnergiesAverageEnergyGetConst(ConstHandle2ConstAverageEnergies This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstAverageEnergy>
      (CLASSNAME, CLASSNAME+"AverageEnergyGetConst", This, extract::averageEnergy, index_);
}

// Get, by index \in [0,size), non-const
Handle2AverageEnergy
AverageEnergiesAverageEnergyGet(ConstHandle2AverageEnergies This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2AverageEnergy>
      (CLASSNAME, CLASSNAME+"AverageEnergyGet", This, extract::averageEnergy, index_);
}

// Set, by index \in [0,size)
void
AverageEnergiesAverageEnergySet(
   ConstHandle2AverageEnergies This,
   const size_t index_,
   ConstHandle2ConstAverageEnergy averageEnergy
) {
   detail::setByIndex<CPP,CPPAverageEnergy>
      (CLASSNAME, CLASSNAME+"AverageEnergySet", This, extract::averageEnergy, index_, averageEnergy);
}

// Has, by label
int
AverageEnergiesAverageEnergyHasByLabel(
   ConstHandle2ConstAverageEnergies This,
   const char *const label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"AverageEnergyHasByLabel",
       This, extract::averageEnergy, meta::label, label);
}

// Get, by label, const
Handle2ConstAverageEnergy
AverageEnergiesAverageEnergyGetByLabelConst(
   ConstHandle2ConstAverageEnergies This,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2ConstAverageEnergy>
      (CLASSNAME, CLASSNAME+"AverageEnergyGetByLabelConst",
       This, extract::averageEnergy, meta::label, label);
}

// Get, by label, non-const
Handle2AverageEnergy
AverageEnergiesAverageEnergyGetByLabel(
   ConstHandle2AverageEnergies This,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2AverageEnergy>
      (CLASSNAME, CLASSNAME+"AverageEnergyGetByLabel",
       This, extract::averageEnergy, meta::label, label);
}

// Set, by label
void
AverageEnergiesAverageEnergySetByLabel(
   ConstHandle2AverageEnergies This,
   const char *const label,
   ConstHandle2ConstAverageEnergy averageEnergy
) {
   detail::setByMetadatum<CPP,CPPAverageEnergy>
      (CLASSNAME, CLASSNAME+"AverageEnergySetByLabel",
       This, extract::averageEnergy, meta::label, label, averageEnergy);
}

// Has, by value
int
AverageEnergiesAverageEnergyHasByValue(
   ConstHandle2ConstAverageEnergies This,
   const double value
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"AverageEnergyHasByValue",
       This, extract::averageEnergy, meta::value, value);
}

// Get, by value, const
Handle2ConstAverageEnergy
AverageEnergiesAverageEnergyGetByValueConst(
   ConstHandle2ConstAverageEnergies This,
   const double value
) {
   return detail::getByMetadatum<CPP,Handle2ConstAverageEnergy>
      (CLASSNAME, CLASSNAME+"AverageEnergyGetByValueConst",
       This, extract::averageEnergy, meta::value, value);
}

// Get, by value, non-const
Handle2AverageEnergy
AverageEnergiesAverageEnergyGetByValue(
   ConstHandle2AverageEnergies This,
   const double value
) {
   return detail::getByMetadatum<CPP,Handle2AverageEnergy>
      (CLASSNAME, CLASSNAME+"AverageEnergyGetByValue",
       This, extract::averageEnergy, meta::value, value);
}

// Set, by value
void
AverageEnergiesAverageEnergySetByValue(
   ConstHandle2AverageEnergies This,
   const double value,
   ConstHandle2ConstAverageEnergy averageEnergy
) {
   detail::setByMetadatum<CPP,CPPAverageEnergy>
      (CLASSNAME, CLASSNAME+"AverageEnergySetByValue",
       This, extract::averageEnergy, meta::value, value, averageEnergy);
}

// Has, by unit
int
AverageEnergiesAverageEnergyHasByUnit(
   ConstHandle2ConstAverageEnergies This,
   const char *const unit
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"AverageEnergyHasByUnit",
       This, extract::averageEnergy, meta::unit, unit);
}

// Get, by unit, const
Handle2ConstAverageEnergy
AverageEnergiesAverageEnergyGetByUnitConst(
   ConstHandle2ConstAverageEnergies This,
   const char *const unit
) {
   return detail::getByMetadatum<CPP,Handle2ConstAverageEnergy>
      (CLASSNAME, CLASSNAME+"AverageEnergyGetByUnitConst",
       This, extract::averageEnergy, meta::unit, unit);
}

// Get, by unit, non-const
Handle2AverageEnergy
AverageEnergiesAverageEnergyGetByUnit(
   ConstHandle2AverageEnergies This,
   const char *const unit
) {
   return detail::getByMetadatum<CPP,Handle2AverageEnergy>
      (CLASSNAME, CLASSNAME+"AverageEnergyGetByUnit",
       This, extract::averageEnergy, meta::unit, unit);
}

// Set, by unit
void
AverageEnergiesAverageEnergySetByUnit(
   ConstHandle2AverageEnergies This,
   const char *const unit,
   ConstHandle2ConstAverageEnergy averageEnergy
) {
   detail::setByMetadatum<CPP,CPPAverageEnergy>
      (CLASSNAME, CLASSNAME+"AverageEnergySetByUnit",
       This, extract::averageEnergy, meta::unit, unit, averageEnergy);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/sfy/AverageEnergies/src/custom.cpp"
