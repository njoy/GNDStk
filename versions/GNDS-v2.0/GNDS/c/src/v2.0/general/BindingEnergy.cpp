
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/BindingEnergy.hpp"
#include "BindingEnergy.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = BindingEnergyClass;
using CPP = multigroup::BindingEnergy;

static const std::string CLASSNAME = "BindingEnergy";

namespace extract {
   static auto Double = [](auto &obj) { return &obj.Double; };
}

using CPPDouble = general::Double;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstBindingEnergy
BindingEnergyDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default, non-const
Handle2BindingEnergy
BindingEnergyDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstBindingEnergy
BindingEnergyCreateConst(
   ConstHandle2ConstDouble Double
) {
   ConstHandle2BindingEnergy handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPDouble>(Double)
   );
   return handle;
}

// Create, general, non-const
Handle2BindingEnergy
BindingEnergyCreate(
   ConstHandle2ConstDouble Double
) {
   ConstHandle2BindingEnergy handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPDouble>(Double)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
BindingEnergyAssign(ConstHandle2BindingEnergy self, ConstHandle2ConstBindingEnergy from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
BindingEnergyDelete(ConstHandle2ConstBindingEnergy self)
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
BindingEnergyRead(ConstHandle2BindingEnergy self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
BindingEnergyWrite(ConstHandle2ConstBindingEnergy self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
BindingEnergyPrint(ConstHandle2ConstBindingEnergy self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
BindingEnergyPrintXML(ConstHandle2ConstBindingEnergy self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
BindingEnergyPrintJSON(ConstHandle2ConstBindingEnergy self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: Double
// -----------------------------------------------------------------------------

// Has
int
BindingEnergyDoubleHas(ConstHandle2ConstBindingEnergy self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DoubleHas", self, extract::Double);
}

// Get, const
Handle2ConstDouble
BindingEnergyDoubleGetConst(ConstHandle2ConstBindingEnergy self)
{
   return detail::getField<CPP,Handle2ConstDouble>
      (CLASSNAME, CLASSNAME+"DoubleGetConst", self, extract::Double);
}

// Get, non-const
Handle2Double
BindingEnergyDoubleGet(ConstHandle2BindingEnergy self)
{
   return detail::getField<CPP,Handle2Double>
      (CLASSNAME, CLASSNAME+"DoubleGet", self, extract::Double);
}

// Set
void
BindingEnergyDoubleSet(ConstHandle2BindingEnergy self, ConstHandle2ConstDouble Double)
{
   detail::setField<CPP,CPPDouble>
      (CLASSNAME, CLASSNAME+"DoubleSet", self, extract::Double, Double);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/BindingEnergy/src/custom.cpp"
