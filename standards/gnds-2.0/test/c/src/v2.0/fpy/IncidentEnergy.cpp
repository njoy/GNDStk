
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/fpy/IncidentEnergy.hpp"
#include "IncidentEnergy.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = IncidentEnergyClass;
using CPP = multigroup::IncidentEnergy;

static const std::string CLASSNAME = "IncidentEnergy";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto energy = [](auto &obj) { return &obj.energy; };
   static auto yields = [](auto &obj) { return &obj.yields; };
}

using CPPEnergy = fpy::Energy;
using CPPYields = fpy::Yields;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstIncidentEnergy
IncidentEnergyDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2IncidentEnergy
IncidentEnergyDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstIncidentEnergy
IncidentEnergyCreateConst(
   const XMLName label,
   ConstHandle2ConstEnergy energy,
   ConstHandle2ConstYields yields
) {
   ConstHandle2IncidentEnergy handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      detail::tocpp<CPPEnergy>(energy),
      detail::tocpp<CPPYields>(yields)
   );
   return handle;
}

// Create, general
Handle2IncidentEnergy
IncidentEnergyCreate(
   const XMLName label,
   ConstHandle2ConstEnergy energy,
   ConstHandle2ConstYields yields
) {
   ConstHandle2IncidentEnergy handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      detail::tocpp<CPPEnergy>(energy),
      detail::tocpp<CPPYields>(yields)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
IncidentEnergyAssign(ConstHandle2IncidentEnergy This, ConstHandle2ConstIncidentEnergy from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
IncidentEnergyDelete(ConstHandle2ConstIncidentEnergy This)
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
IncidentEnergyRead(ConstHandle2IncidentEnergy This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
IncidentEnergyWrite(ConstHandle2ConstIncidentEnergy This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
IncidentEnergyPrint(ConstHandle2ConstIncidentEnergy This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
IncidentEnergyPrintXML(ConstHandle2ConstIncidentEnergy This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
IncidentEnergyPrintJSON(ConstHandle2ConstIncidentEnergy This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
IncidentEnergyLabelHas(ConstHandle2ConstIncidentEnergy This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
IncidentEnergyLabelGet(ConstHandle2ConstIncidentEnergy This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
IncidentEnergyLabelSet(ConstHandle2IncidentEnergy This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Child: energy
// -----------------------------------------------------------------------------

// Has
int
IncidentEnergyEnergyHas(ConstHandle2ConstIncidentEnergy This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EnergyHas", This, extract::energy);
}

// Get, const
Handle2ConstEnergy
IncidentEnergyEnergyGetConst(ConstHandle2ConstIncidentEnergy This)
{
   return detail::getField<CPP,Handle2ConstEnergy>
      (CLASSNAME, CLASSNAME+"EnergyGetConst", This, extract::energy);
}

// Get, non-const
Handle2Energy
IncidentEnergyEnergyGet(ConstHandle2IncidentEnergy This)
{
   return detail::getField<CPP,Handle2Energy>
      (CLASSNAME, CLASSNAME+"EnergyGet", This, extract::energy);
}

// Set
void
IncidentEnergyEnergySet(ConstHandle2IncidentEnergy This, ConstHandle2ConstEnergy energy)
{
   detail::setField<CPP,CPPEnergy>
      (CLASSNAME, CLASSNAME+"EnergySet", This, extract::energy, energy);
}


// -----------------------------------------------------------------------------
// Child: yields
// -----------------------------------------------------------------------------

// Has
int
IncidentEnergyYieldsHas(ConstHandle2ConstIncidentEnergy This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"YieldsHas", This, extract::yields);
}

// Get, const
Handle2ConstYields
IncidentEnergyYieldsGetConst(ConstHandle2ConstIncidentEnergy This)
{
   return detail::getField<CPP,Handle2ConstYields>
      (CLASSNAME, CLASSNAME+"YieldsGetConst", This, extract::yields);
}

// Get, non-const
Handle2Yields
IncidentEnergyYieldsGet(ConstHandle2IncidentEnergy This)
{
   return detail::getField<CPP,Handle2Yields>
      (CLASSNAME, CLASSNAME+"YieldsGet", This, extract::yields);
}

// Set
void
IncidentEnergyYieldsSet(ConstHandle2IncidentEnergy This, ConstHandle2ConstYields yields)
{
   detail::setField<CPP,CPPYields>
      (CLASSNAME, CLASSNAME+"YieldsSet", This, extract::yields, yields);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/fpy/IncidentEnergy/src/custom.cpp"
