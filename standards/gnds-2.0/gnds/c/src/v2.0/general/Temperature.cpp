
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "gnds/v2.0/general/Temperature.hpp"
#include "Temperature.h"

using namespace njoy::GNDStk;
using namespace gnds::v2_0;

using C = TemperatureClass;
using CPP = multigroup::Temperature;

static const std::string CLASSNAME = "Temperature";

namespace extract {
   static auto value = [](auto &obj) { return &obj.value; };
   static auto unit = [](auto &obj) { return &obj.unit; };
}


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstTemperature
TemperatureDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Temperature
TemperatureDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstTemperature
TemperatureCreateConst(
   const double value,
   const char *const unit
) {
   ConstHandle2Temperature handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      value,
      unit
   );
   return handle;
}

// Create, general
Handle2Temperature
TemperatureCreate(
   const double value,
   const char *const unit
) {
   ConstHandle2Temperature handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      value,
      unit
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
TemperatureAssign(ConstHandle2Temperature self, ConstHandle2ConstTemperature from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
TemperatureDelete(ConstHandle2ConstTemperature self)
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
TemperatureRead(ConstHandle2Temperature self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
TemperatureWrite(ConstHandle2ConstTemperature self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
TemperaturePrint(ConstHandle2ConstTemperature self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
TemperaturePrintXML(ConstHandle2ConstTemperature self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
TemperaturePrintJSON(ConstHandle2ConstTemperature self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// Has
int
TemperatureValueHas(ConstHandle2ConstTemperature self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ValueHas", self, extract::value);
}

// Get
// Returns by value
double
TemperatureValueGet(ConstHandle2ConstTemperature self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ValueGet", self, extract::value);
}

// Set
void
TemperatureValueSet(ConstHandle2Temperature self, const double value)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ValueSet", self, extract::value, value);
}


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// Has
int
TemperatureUnitHas(ConstHandle2ConstTemperature self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UnitHas", self, extract::unit);
}

// Get
// Returns by value
const char *
TemperatureUnitGet(ConstHandle2ConstTemperature self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"UnitGet", self, extract::unit);
}

// Set
void
TemperatureUnitSet(ConstHandle2Temperature self, const char *const unit)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"UnitSet", self, extract::unit, unit);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Temperature/src/custom.cpp"
