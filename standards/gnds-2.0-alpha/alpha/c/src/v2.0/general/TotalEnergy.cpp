
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/TotalEnergy.hpp"
#include "TotalEnergy.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = TotalEnergyClass;
using CPP = multigroup::TotalEnergy;

static const std::string CLASSNAME = "TotalEnergy";

namespace extract {
   static auto polynomial1d = [](auto &obj) { return &obj.polynomial1d; };
}

using CPPPolynomial1d = general::Polynomial1d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstTotalEnergy
TotalEnergyDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2TotalEnergy
TotalEnergyDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstTotalEnergy
TotalEnergyCreateConst(
   ConstHandle2ConstPolynomial1d polynomial1d
) {
   ConstHandle2TotalEnergy handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPPolynomial1d>(polynomial1d)
   );
   return handle;
}

// Create, general
Handle2TotalEnergy
TotalEnergyCreate(
   ConstHandle2ConstPolynomial1d polynomial1d
) {
   ConstHandle2TotalEnergy handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPPolynomial1d>(polynomial1d)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
TotalEnergyAssign(ConstHandle2TotalEnergy This, ConstHandle2ConstTotalEnergy from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
TotalEnergyDelete(ConstHandle2ConstTotalEnergy This)
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
TotalEnergyRead(ConstHandle2TotalEnergy This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
TotalEnergyWrite(ConstHandle2ConstTotalEnergy This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
TotalEnergyPrint(ConstHandle2ConstTotalEnergy This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
TotalEnergyPrintXML(ConstHandle2ConstTotalEnergy This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
TotalEnergyPrintJSON(ConstHandle2ConstTotalEnergy This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: polynomial1d
// -----------------------------------------------------------------------------

// Has
int
TotalEnergyPolynomial1dHas(ConstHandle2ConstTotalEnergy This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Polynomial1dHas", This, extract::polynomial1d);
}

// Get, const
Handle2ConstPolynomial1d
TotalEnergyPolynomial1dGetConst(ConstHandle2ConstTotalEnergy This)
{
   return detail::getField<CPP,Handle2ConstPolynomial1d>
      (CLASSNAME, CLASSNAME+"Polynomial1dGetConst", This, extract::polynomial1d);
}

// Get, non-const
Handle2Polynomial1d
TotalEnergyPolynomial1dGet(ConstHandle2TotalEnergy This)
{
   return detail::getField<CPP,Handle2Polynomial1d>
      (CLASSNAME, CLASSNAME+"Polynomial1dGet", This, extract::polynomial1d);
}

// Set
void
TotalEnergyPolynomial1dSet(ConstHandle2TotalEnergy This, ConstHandle2ConstPolynomial1d polynomial1d)
{
   detail::setField<CPP,CPPPolynomial1d>
      (CLASSNAME, CLASSNAME+"Polynomial1dSet", This, extract::polynomial1d, polynomial1d);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/TotalEnergy/src/custom.cpp"
