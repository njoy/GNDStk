
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/fissionTransport/DelayedBetaEnergy.hpp"
#include "DelayedBetaEnergy.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = DelayedBetaEnergyClass;
using CPP = multigroup::DelayedBetaEnergy;

static const std::string CLASSNAME = "DelayedBetaEnergy";

namespace extract {
   static auto polynomial1d = [](auto &obj) { return &obj.polynomial1d; };
}

using CPPPolynomial1d = containers::Polynomial1d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstDelayedBetaEnergy
DelayedBetaEnergyDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2DelayedBetaEnergy
DelayedBetaEnergyDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstDelayedBetaEnergy
DelayedBetaEnergyCreateConst(
   ConstHandle2ConstPolynomial1d polynomial1d
) {
   ConstHandle2DelayedBetaEnergy handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPPolynomial1d>(polynomial1d)
   );
   return handle;
}

// Create, general
Handle2DelayedBetaEnergy
DelayedBetaEnergyCreate(
   ConstHandle2ConstPolynomial1d polynomial1d
) {
   ConstHandle2DelayedBetaEnergy handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPPolynomial1d>(polynomial1d)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
DelayedBetaEnergyAssign(ConstHandle2DelayedBetaEnergy self, ConstHandle2ConstDelayedBetaEnergy from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
DelayedBetaEnergyDelete(ConstHandle2ConstDelayedBetaEnergy self)
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
DelayedBetaEnergyRead(ConstHandle2DelayedBetaEnergy self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
DelayedBetaEnergyWrite(ConstHandle2ConstDelayedBetaEnergy self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
DelayedBetaEnergyPrint(ConstHandle2ConstDelayedBetaEnergy self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
DelayedBetaEnergyPrintXML(ConstHandle2ConstDelayedBetaEnergy self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
DelayedBetaEnergyPrintJSON(ConstHandle2ConstDelayedBetaEnergy self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: polynomial1d
// -----------------------------------------------------------------------------

// Has
int
DelayedBetaEnergyPolynomial1dHas(ConstHandle2ConstDelayedBetaEnergy self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Polynomial1dHas", self, extract::polynomial1d);
}

// Get, const
Handle2ConstPolynomial1d
DelayedBetaEnergyPolynomial1dGetConst(ConstHandle2ConstDelayedBetaEnergy self)
{
   return detail::getField<CPP,Handle2ConstPolynomial1d>
      (CLASSNAME, CLASSNAME+"Polynomial1dGetConst", self, extract::polynomial1d);
}

// Get, non-const
Handle2Polynomial1d
DelayedBetaEnergyPolynomial1dGet(ConstHandle2DelayedBetaEnergy self)
{
   return detail::getField<CPP,Handle2Polynomial1d>
      (CLASSNAME, CLASSNAME+"Polynomial1dGet", self, extract::polynomial1d);
}

// Set
void
DelayedBetaEnergyPolynomial1dSet(ConstHandle2DelayedBetaEnergy self, ConstHandle2ConstPolynomial1d polynomial1d)
{
   detail::setField<CPP,CPPPolynomial1d>
      (CLASSNAME, CLASSNAME+"Polynomial1dSet", self, extract::polynomial1d, polynomial1d);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/fissionTransport/DelayedBetaEnergy/src/custom.cpp"
