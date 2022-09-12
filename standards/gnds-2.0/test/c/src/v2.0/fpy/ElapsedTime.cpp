
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/fpy/ElapsedTime.hpp"
#include "ElapsedTime.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = ElapsedTimeClass;
using CPP = multigroup::ElapsedTime;

static const std::string CLASSNAME = "ElapsedTime";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto time = [](auto &obj) { return &obj.time; };
}

using CPPTime = fpy::Time;
using CPPYields = fpy::Yields;
using CPPIncidentEnergies = fpy::IncidentEnergies;


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
   const XMLName label,
   ConstHandle2ConstTime time,
) {
   ConstHandle2ElapsedTime handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      detail::tocpp<CPPTime>(time)
   );
   return handle;
}

// Create, general
Handle2ElapsedTime
ElapsedTimeCreate(
   const XMLName label,
   ConstHandle2ConstTime time,
) {
   ConstHandle2ElapsedTime handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      detail::tocpp<CPPTime>(time)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ElapsedTimeAssign(ConstHandle2ElapsedTime This, ConstHandle2ConstElapsedTime from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ElapsedTimeDelete(ConstHandle2ConstElapsedTime This)
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
ElapsedTimeRead(ConstHandle2ElapsedTime This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ElapsedTimeWrite(ConstHandle2ConstElapsedTime This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
ElapsedTimePrint(ConstHandle2ConstElapsedTime This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
ElapsedTimePrintXML(ConstHandle2ConstElapsedTime This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
ElapsedTimePrintJSON(ConstHandle2ConstElapsedTime This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
ElapsedTimeLabelHas(ConstHandle2ConstElapsedTime This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
ElapsedTimeLabelGet(ConstHandle2ConstElapsedTime This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
ElapsedTimeLabelSet(ConstHandle2ElapsedTime This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Child: time
// -----------------------------------------------------------------------------

// Has
int
ElapsedTimeTimeHas(ConstHandle2ConstElapsedTime This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"TimeHas", This, extract::time);
}

// Get, const
Handle2ConstTime
ElapsedTimeTimeGetConst(ConstHandle2ConstElapsedTime This)
{
   return detail::getField<CPP,Handle2ConstTime>
      (CLASSNAME, CLASSNAME+"TimeGetConst", This, extract::time);
}

// Get, non-const
Handle2Time
ElapsedTimeTimeGet(ConstHandle2ElapsedTime This)
{
   return detail::getField<CPP,Handle2Time>
      (CLASSNAME, CLASSNAME+"TimeGet", This, extract::time);
}

// Set
void
ElapsedTimeTimeSet(ConstHandle2ElapsedTime This, ConstHandle2ConstTime time)
{
   detail::setField<CPP,CPPTime>
      (CLASSNAME, CLASSNAME+"TimeSet", This, extract::time, time);
}