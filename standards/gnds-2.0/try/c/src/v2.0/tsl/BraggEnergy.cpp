
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/tsl/BraggEnergy.hpp"
#include "BraggEnergy.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = BraggEnergyClass;
using CPP = multigroup::BraggEnergy;

static const std::string CLASSNAME = "BraggEnergy";

namespace extract {
   static auto XYs1d = [](auto &obj) { return &obj.XYs1d; };
}

using CPPXYs1d = containers::XYs1d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstBraggEnergy
BraggEnergyDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2BraggEnergy
BraggEnergyDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstBraggEnergy
BraggEnergyCreateConst(
   ConstHandle2ConstXYs1d XYs1d
) {
   ConstHandle2BraggEnergy handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPXYs1d>(XYs1d)
   );
   return handle;
}

// Create, general
Handle2BraggEnergy
BraggEnergyCreate(
   ConstHandle2ConstXYs1d XYs1d
) {
   ConstHandle2BraggEnergy handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPXYs1d>(XYs1d)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
BraggEnergyAssign(ConstHandle2BraggEnergy This, ConstHandle2ConstBraggEnergy from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
BraggEnergyDelete(ConstHandle2ConstBraggEnergy This)
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
BraggEnergyRead(ConstHandle2BraggEnergy This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
BraggEnergyWrite(ConstHandle2ConstBraggEnergy This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
BraggEnergyPrint(ConstHandle2ConstBraggEnergy This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
BraggEnergyPrintXML(ConstHandle2ConstBraggEnergy This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
BraggEnergyPrintJSON(ConstHandle2ConstBraggEnergy This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// Has
int
BraggEnergyXYs1dHas(ConstHandle2ConstBraggEnergy This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"XYs1dHas", This, extract::XYs1d);
}

// Get, const
Handle2ConstXYs1d
BraggEnergyXYs1dGetConst(ConstHandle2ConstBraggEnergy This)
{
   return detail::getField<CPP,Handle2ConstXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGetConst", This, extract::XYs1d);
}

// Get, non-const
Handle2XYs1d
BraggEnergyXYs1dGet(ConstHandle2BraggEnergy This)
{
   return detail::getField<CPP,Handle2XYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGet", This, extract::XYs1d);
}

// Set
void
BraggEnergyXYs1dSet(ConstHandle2BraggEnergy This, ConstHandle2ConstXYs1d XYs1d)
{
   detail::setField<CPP,CPPXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dSet", This, extract::XYs1d, XYs1d);
}