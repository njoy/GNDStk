
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/resonances/EnergyIntervals.hpp"
#include "EnergyIntervals.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = EnergyIntervalsClass;
using CPP = multigroup::EnergyIntervals;

static const std::string CLASSNAME = "EnergyIntervals";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto energyInterval = [](auto &obj) { return &obj.energyInterval; };
}

using CPPEnergyInterval = resonances::EnergyInterval;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstEnergyIntervals
EnergyIntervalsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2EnergyIntervals
EnergyIntervalsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstEnergyIntervals
EnergyIntervalsCreateConst(
   const XMLName label,
   ConstHandle2EnergyInterval *const energyInterval, const size_t energyIntervalSize
) {
   ConstHandle2EnergyIntervals handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      std::vector<CPPEnergyInterval>{}
   );
   for (size_t EnergyIntervalN = 0; EnergyIntervalN < energyIntervalSize; ++EnergyIntervalN)
      EnergyIntervalsEnergyIntervalAdd(handle, energyInterval[EnergyIntervalN]);
   return handle;
}

// Create, general
Handle2EnergyIntervals
EnergyIntervalsCreate(
   const XMLName label,
   ConstHandle2EnergyInterval *const energyInterval, const size_t energyIntervalSize
) {
   ConstHandle2EnergyIntervals handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      std::vector<CPPEnergyInterval>{}
   );
   for (size_t EnergyIntervalN = 0; EnergyIntervalN < energyIntervalSize; ++EnergyIntervalN)
      EnergyIntervalsEnergyIntervalAdd(handle, energyInterval[EnergyIntervalN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
EnergyIntervalsAssign(ConstHandle2EnergyIntervals This, ConstHandle2ConstEnergyIntervals from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
EnergyIntervalsDelete(ConstHandle2ConstEnergyIntervals This)
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
EnergyIntervalsRead(ConstHandle2EnergyIntervals This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
EnergyIntervalsWrite(ConstHandle2ConstEnergyIntervals This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
EnergyIntervalsPrint(ConstHandle2ConstEnergyIntervals This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
EnergyIntervalsPrintXML(ConstHandle2ConstEnergyIntervals This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
EnergyIntervalsPrintJSON(ConstHandle2ConstEnergyIntervals This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
EnergyIntervalsLabelHas(ConstHandle2ConstEnergyIntervals This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
EnergyIntervalsLabelGet(ConstHandle2ConstEnergyIntervals This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
EnergyIntervalsLabelSet(ConstHandle2EnergyIntervals This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Child: energyInterval
// -----------------------------------------------------------------------------

// Has
int
EnergyIntervalsEnergyIntervalHas(ConstHandle2ConstEnergyIntervals This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EnergyIntervalHas", This, extract::energyInterval);
}

// Clear
void
EnergyIntervalsEnergyIntervalClear(ConstHandle2EnergyIntervals This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"EnergyIntervalClear", This, extract::energyInterval);
}

// Size
size_t
EnergyIntervalsEnergyIntervalSize(ConstHandle2ConstEnergyIntervals This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"EnergyIntervalSize", This, extract::energyInterval);
}

// Add
void
EnergyIntervalsEnergyIntervalAdd(ConstHandle2EnergyIntervals This, ConstHandle2ConstEnergyInterval energyInterval)
{
   detail::addToContainer<CPP,CPPEnergyInterval>
      (CLASSNAME, CLASSNAME+"EnergyIntervalAdd", This, extract::energyInterval, energyInterval);
}

// Get, by index \in [0,size), const
Handle2ConstEnergyInterval
EnergyIntervalsEnergyIntervalGetConst(ConstHandle2ConstEnergyIntervals This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstEnergyInterval>
      (CLASSNAME, CLASSNAME+"EnergyIntervalGetConst", This, extract::energyInterval, index_);
}

// Get, by index \in [0,size), non-const
Handle2EnergyInterval
EnergyIntervalsEnergyIntervalGet(ConstHandle2EnergyIntervals This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2EnergyInterval>
      (CLASSNAME, CLASSNAME+"EnergyIntervalGet", This, extract::energyInterval, index_);
}

// Set, by index \in [0,size)
void
EnergyIntervalsEnergyIntervalSet(
   ConstHandle2EnergyIntervals This,
   const size_t index_,
   ConstHandle2ConstEnergyInterval energyInterval
) {
   detail::setByIndex<CPP,CPPEnergyInterval>
      (CLASSNAME, CLASSNAME+"EnergyIntervalSet", This, extract::energyInterval, index_, energyInterval);
}

// Has, by index
int
EnergyIntervalsEnergyIntervalHasByIndex(
   ConstHandle2ConstEnergyIntervals This,
   const Integer32 index
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"EnergyIntervalHasByIndex",
       This, extract::energyInterval, meta::index, index);
}

// Get, by index, const
Handle2ConstEnergyInterval
EnergyIntervalsEnergyIntervalGetByIndexConst(
   ConstHandle2ConstEnergyIntervals This,
   const Integer32 index
) {
   return detail::getByMetadatum<CPP,Handle2ConstEnergyInterval>
      (CLASSNAME, CLASSNAME+"EnergyIntervalGetByIndexConst",
       This, extract::energyInterval, meta::index, index);
}

// Get, by index, non-const
Handle2EnergyInterval
EnergyIntervalsEnergyIntervalGetByIndex(
   ConstHandle2EnergyIntervals This,
   const Integer32 index
) {
   return detail::getByMetadatum<CPP,Handle2EnergyInterval>
      (CLASSNAME, CLASSNAME+"EnergyIntervalGetByIndex",
       This, extract::energyInterval, meta::index, index);
}

// Set, by index
void
EnergyIntervalsEnergyIntervalSetByIndex(
   ConstHandle2EnergyIntervals This,
   const Integer32 index,
   ConstHandle2ConstEnergyInterval energyInterval
) {
   detail::setByMetadatum<CPP,CPPEnergyInterval>
      (CLASSNAME, CLASSNAME+"EnergyIntervalSetByIndex",
       This, extract::energyInterval, meta::index, index, energyInterval);
}

// Has, by domainMin
int
EnergyIntervalsEnergyIntervalHasByDomainMin(
   ConstHandle2ConstEnergyIntervals This,
   const Float64 domainMin
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"EnergyIntervalHasByDomainMin",
       This, extract::energyInterval, meta::domainMin, domainMin);
}

// Get, by domainMin, const
Handle2ConstEnergyInterval
EnergyIntervalsEnergyIntervalGetByDomainMinConst(
   ConstHandle2ConstEnergyIntervals This,
   const Float64 domainMin
) {
   return detail::getByMetadatum<CPP,Handle2ConstEnergyInterval>
      (CLASSNAME, CLASSNAME+"EnergyIntervalGetByDomainMinConst",
       This, extract::energyInterval, meta::domainMin, domainMin);
}

// Get, by domainMin, non-const
Handle2EnergyInterval
EnergyIntervalsEnergyIntervalGetByDomainMin(
   ConstHandle2EnergyIntervals This,
   const Float64 domainMin
) {
   return detail::getByMetadatum<CPP,Handle2EnergyInterval>
      (CLASSNAME, CLASSNAME+"EnergyIntervalGetByDomainMin",
       This, extract::energyInterval, meta::domainMin, domainMin);
}

// Set, by domainMin
void
EnergyIntervalsEnergyIntervalSetByDomainMin(
   ConstHandle2EnergyIntervals This,
   const Float64 domainMin,
   ConstHandle2ConstEnergyInterval energyInterval
) {
   detail::setByMetadatum<CPP,CPPEnergyInterval>
      (CLASSNAME, CLASSNAME+"EnergyIntervalSetByDomainMin",
       This, extract::energyInterval, meta::domainMin, domainMin, energyInterval);
}

// Has, by domainMax
int
EnergyIntervalsEnergyIntervalHasByDomainMax(
   ConstHandle2ConstEnergyIntervals This,
   const Float64 domainMax
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"EnergyIntervalHasByDomainMax",
       This, extract::energyInterval, meta::domainMax, domainMax);
}

// Get, by domainMax, const
Handle2ConstEnergyInterval
EnergyIntervalsEnergyIntervalGetByDomainMaxConst(
   ConstHandle2ConstEnergyIntervals This,
   const Float64 domainMax
) {
   return detail::getByMetadatum<CPP,Handle2ConstEnergyInterval>
      (CLASSNAME, CLASSNAME+"EnergyIntervalGetByDomainMaxConst",
       This, extract::energyInterval, meta::domainMax, domainMax);
}

// Get, by domainMax, non-const
Handle2EnergyInterval
EnergyIntervalsEnergyIntervalGetByDomainMax(
   ConstHandle2EnergyIntervals This,
   const Float64 domainMax
) {
   return detail::getByMetadatum<CPP,Handle2EnergyInterval>
      (CLASSNAME, CLASSNAME+"EnergyIntervalGetByDomainMax",
       This, extract::energyInterval, meta::domainMax, domainMax);
}

// Set, by domainMax
void
EnergyIntervalsEnergyIntervalSetByDomainMax(
   ConstHandle2EnergyIntervals This,
   const Float64 domainMax,
   ConstHandle2ConstEnergyInterval energyInterval
) {
   detail::setByMetadatum<CPP,CPPEnergyInterval>
      (CLASSNAME, CLASSNAME+"EnergyIntervalSetByDomainMax",
       This, extract::energyInterval, meta::domainMax, domainMax, energyInterval);
}

// Has, by domainUnit
int
EnergyIntervalsEnergyIntervalHasByDomainUnit(
   ConstHandle2ConstEnergyIntervals This,
   const XMLName domainUnit
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"EnergyIntervalHasByDomainUnit",
       This, extract::energyInterval, meta::domainUnit, domainUnit);
}

// Get, by domainUnit, const
Handle2ConstEnergyInterval
EnergyIntervalsEnergyIntervalGetByDomainUnitConst(
   ConstHandle2ConstEnergyIntervals This,
   const XMLName domainUnit
) {
   return detail::getByMetadatum<CPP,Handle2ConstEnergyInterval>
      (CLASSNAME, CLASSNAME+"EnergyIntervalGetByDomainUnitConst",
       This, extract::energyInterval, meta::domainUnit, domainUnit);
}

// Get, by domainUnit, non-const
Handle2EnergyInterval
EnergyIntervalsEnergyIntervalGetByDomainUnit(
   ConstHandle2EnergyIntervals This,
   const XMLName domainUnit
) {
   return detail::getByMetadatum<CPP,Handle2EnergyInterval>
      (CLASSNAME, CLASSNAME+"EnergyIntervalGetByDomainUnit",
       This, extract::energyInterval, meta::domainUnit, domainUnit);
}

// Set, by domainUnit
void
EnergyIntervalsEnergyIntervalSetByDomainUnit(
   ConstHandle2EnergyIntervals This,
   const XMLName domainUnit,
   ConstHandle2ConstEnergyInterval energyInterval
) {
   detail::setByMetadatum<CPP,CPPEnergyInterval>
      (CLASSNAME, CLASSNAME+"EnergyIntervalSetByDomainUnit",
       This, extract::energyInterval, meta::domainUnit, domainUnit, energyInterval);
}
