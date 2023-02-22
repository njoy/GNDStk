
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/ElapsedTime.hpp"
#include "ElapsedTime.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = ElapsedTimeClass;
using CPP = multigroup::ElapsedTime;

static const std::string CLASSNAME = "ElapsedTime";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto time = [](auto &obj) { return &obj.time; };
   static auto yields = [](auto &obj) { return &obj.yields; };
   static auto incidentEnergies = [](auto &obj) { return &obj.incidentEnergies; };
}

using CPPTime = general::Time;
using CPPYields = general::Yields;
using CPPIncidentEnergies = general::IncidentEnergies;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstElapsedTime
ElapsedTimeDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2ElapsedTime
ElapsedTimeDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstElapsedTime
ElapsedTimeCreateConst(
   const char *const label,
   ConstHandle2ConstTime time,
   ConstHandle2ConstYields yields,
   ConstHandle2ConstIncidentEnergies incidentEnergies
) {
   ConstHandle2ElapsedTime handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      detail::tocpp<CPPTime>(time),
      detail::tocpp<CPPYields>(yields),
      detail::tocpp<CPPIncidentEnergies>(incidentEnergies)
   );
   return handle;
}

// Create, general
Handle2ElapsedTime
ElapsedTimeCreate(
   const char *const label,
   ConstHandle2ConstTime time,
   ConstHandle2ConstYields yields,
   ConstHandle2ConstIncidentEnergies incidentEnergies
) {
   ConstHandle2ElapsedTime handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      detail::tocpp<CPPTime>(time),
      detail::tocpp<CPPYields>(yields),
      detail::tocpp<CPPIncidentEnergies>(incidentEnergies)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ElapsedTimeAssign(ConstHandle2ElapsedTime self, ConstHandle2ConstElapsedTime from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ElapsedTimeDelete(ConstHandle2ConstElapsedTime self)
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
ElapsedTimeRead(ConstHandle2ElapsedTime self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ElapsedTimeWrite(ConstHandle2ConstElapsedTime self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ElapsedTimePrint(ConstHandle2ConstElapsedTime self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ElapsedTimePrintXML(ConstHandle2ConstElapsedTime self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ElapsedTimePrintJSON(ConstHandle2ConstElapsedTime self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
ElapsedTimeLabelHas(ConstHandle2ConstElapsedTime self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
const char *
ElapsedTimeLabelGet(ConstHandle2ConstElapsedTime self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
ElapsedTimeLabelSet(ConstHandle2ElapsedTime self, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Child: time
// -----------------------------------------------------------------------------

// Has
int
ElapsedTimeTimeHas(ConstHandle2ConstElapsedTime self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"TimeHas", self, extract::time);
}

// Get, const
Handle2ConstTime
ElapsedTimeTimeGetConst(ConstHandle2ConstElapsedTime self)
{
   return detail::getField<CPP,Handle2ConstTime>
      (CLASSNAME, CLASSNAME+"TimeGetConst", self, extract::time);
}

// Get, non-const
Handle2Time
ElapsedTimeTimeGet(ConstHandle2ElapsedTime self)
{
   return detail::getField<CPP,Handle2Time>
      (CLASSNAME, CLASSNAME+"TimeGet", self, extract::time);
}

// Set
void
ElapsedTimeTimeSet(ConstHandle2ElapsedTime self, ConstHandle2ConstTime time)
{
   detail::setField<CPP,CPPTime>
      (CLASSNAME, CLASSNAME+"TimeSet", self, extract::time, time);
}


// -----------------------------------------------------------------------------
// Child: yields
// -----------------------------------------------------------------------------

// Has
int
ElapsedTimeYieldsHas(ConstHandle2ConstElapsedTime self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"YieldsHas", self, extract::yields);
}

// Get, const
Handle2ConstYields
ElapsedTimeYieldsGetConst(ConstHandle2ConstElapsedTime self)
{
   return detail::getField<CPP,Handle2ConstYields>
      (CLASSNAME, CLASSNAME+"YieldsGetConst", self, extract::yields);
}

// Get, non-const
Handle2Yields
ElapsedTimeYieldsGet(ConstHandle2ElapsedTime self)
{
   return detail::getField<CPP,Handle2Yields>
      (CLASSNAME, CLASSNAME+"YieldsGet", self, extract::yields);
}

// Set
void
ElapsedTimeYieldsSet(ConstHandle2ElapsedTime self, ConstHandle2ConstYields yields)
{
   detail::setField<CPP,CPPYields>
      (CLASSNAME, CLASSNAME+"YieldsSet", self, extract::yields, yields);
}


// -----------------------------------------------------------------------------
// Child: incidentEnergies
// -----------------------------------------------------------------------------

// Has
int
ElapsedTimeIncidentEnergiesHas(ConstHandle2ConstElapsedTime self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"IncidentEnergiesHas", self, extract::incidentEnergies);
}

// Get, const
Handle2ConstIncidentEnergies
ElapsedTimeIncidentEnergiesGetConst(ConstHandle2ConstElapsedTime self)
{
   return detail::getField<CPP,Handle2ConstIncidentEnergies>
      (CLASSNAME, CLASSNAME+"IncidentEnergiesGetConst", self, extract::incidentEnergies);
}

// Get, non-const
Handle2IncidentEnergies
ElapsedTimeIncidentEnergiesGet(ConstHandle2ElapsedTime self)
{
   return detail::getField<CPP,Handle2IncidentEnergies>
      (CLASSNAME, CLASSNAME+"IncidentEnergiesGet", self, extract::incidentEnergies);
}

// Set
void
ElapsedTimeIncidentEnergiesSet(ConstHandle2ElapsedTime self, ConstHandle2ConstIncidentEnergies incidentEnergies)
{
   detail::setField<CPP,CPPIncidentEnergies>
      (CLASSNAME, CLASSNAME+"IncidentEnergiesSet", self, extract::incidentEnergies, incidentEnergies);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/ElapsedTime/src/custom.cpp"