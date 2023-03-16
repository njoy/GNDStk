
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/fissionTransport/DelayedGammaEnergy.hpp"
#include "DelayedGammaEnergy.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = DelayedGammaEnergyClass;
using CPP = multigroup::DelayedGammaEnergy;

static const std::string CLASSNAME = "DelayedGammaEnergy";

namespace extract {
   static auto polynomial1d = [](auto &obj) { return &obj.polynomial1d; };
}

using CPPPolynomial1d = containers::Polynomial1d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstDelayedGammaEnergy
DelayedGammaEnergyDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2DelayedGammaEnergy
DelayedGammaEnergyDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstDelayedGammaEnergy
DelayedGammaEnergyCreateConst(
   ConstHandle2ConstPolynomial1d polynomial1d
) {
   ConstHandle2DelayedGammaEnergy handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPPolynomial1d>(polynomial1d)
   );
   return handle;
}

// Create, general
Handle2DelayedGammaEnergy
DelayedGammaEnergyCreate(
   ConstHandle2ConstPolynomial1d polynomial1d
) {
   ConstHandle2DelayedGammaEnergy handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPPolynomial1d>(polynomial1d)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
DelayedGammaEnergyAssign(ConstHandle2DelayedGammaEnergy self, ConstHandle2ConstDelayedGammaEnergy from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
DelayedGammaEnergyDelete(ConstHandle2ConstDelayedGammaEnergy self)
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
DelayedGammaEnergyRead(ConstHandle2DelayedGammaEnergy self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
DelayedGammaEnergyWrite(ConstHandle2ConstDelayedGammaEnergy self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
DelayedGammaEnergyPrint(ConstHandle2ConstDelayedGammaEnergy self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
DelayedGammaEnergyPrintXML(ConstHandle2ConstDelayedGammaEnergy self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
DelayedGammaEnergyPrintJSON(ConstHandle2ConstDelayedGammaEnergy self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: polynomial1d
// -----------------------------------------------------------------------------

// Has
int
DelayedGammaEnergyPolynomial1dHas(ConstHandle2ConstDelayedGammaEnergy self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Polynomial1dHas", self, extract::polynomial1d);
}

// Get, const
Handle2ConstPolynomial1d
DelayedGammaEnergyPolynomial1dGetConst(ConstHandle2ConstDelayedGammaEnergy self)
{
   return detail::getField<CPP,Handle2ConstPolynomial1d>
      (CLASSNAME, CLASSNAME+"Polynomial1dGetConst", self, extract::polynomial1d);
}

// Get, non-const
Handle2Polynomial1d
DelayedGammaEnergyPolynomial1dGet(ConstHandle2DelayedGammaEnergy self)
{
   return detail::getField<CPP,Handle2Polynomial1d>
      (CLASSNAME, CLASSNAME+"Polynomial1dGet", self, extract::polynomial1d);
}

// Set
void
DelayedGammaEnergyPolynomial1dSet(ConstHandle2DelayedGammaEnergy self, ConstHandle2ConstPolynomial1d polynomial1d)
{
   detail::setField<CPP,CPPPolynomial1d>
      (CLASSNAME, CLASSNAME+"Polynomial1dSet", self, extract::polynomial1d, polynomial1d);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/fissionTransport/DelayedGammaEnergy/src/custom.cpp"
