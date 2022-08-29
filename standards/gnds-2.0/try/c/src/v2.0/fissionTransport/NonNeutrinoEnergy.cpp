
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/fissionTransport/NonNeutrinoEnergy.hpp"
#include "NonNeutrinoEnergy.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = NonNeutrinoEnergyClass;
using CPP = multigroup::NonNeutrinoEnergy;

static const std::string CLASSNAME = "NonNeutrinoEnergy";

namespace extract {
   static auto polynomial1d = [](auto &obj) { return &obj.polynomial1d; };
}

using CPPPolynomial1d = unknownNamespace::Polynomial1d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstNonNeutrinoEnergy
NonNeutrinoEnergyDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2NonNeutrinoEnergy
NonNeutrinoEnergyDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstNonNeutrinoEnergy
NonNeutrinoEnergyCreateConst(
   ConstHandle2ConstPolynomial1d polynomial1d
) {
   ConstHandle2NonNeutrinoEnergy handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPPolynomial1d>(polynomial1d)
   );
   return handle;
}

// Create, general
Handle2NonNeutrinoEnergy
NonNeutrinoEnergyCreate(
   ConstHandle2ConstPolynomial1d polynomial1d
) {
   ConstHandle2NonNeutrinoEnergy handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPPolynomial1d>(polynomial1d)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
NonNeutrinoEnergyAssign(ConstHandle2NonNeutrinoEnergy This, ConstHandle2ConstNonNeutrinoEnergy from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
NonNeutrinoEnergyDelete(ConstHandle2ConstNonNeutrinoEnergy This)
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
NonNeutrinoEnergyRead(ConstHandle2NonNeutrinoEnergy This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
NonNeutrinoEnergyWrite(ConstHandle2ConstNonNeutrinoEnergy This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
NonNeutrinoEnergyPrint(ConstHandle2ConstNonNeutrinoEnergy This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
NonNeutrinoEnergyPrintXML(ConstHandle2ConstNonNeutrinoEnergy This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
NonNeutrinoEnergyPrintJSON(ConstHandle2ConstNonNeutrinoEnergy This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: polynomial1d
// -----------------------------------------------------------------------------

// Has
int
NonNeutrinoEnergyPolynomial1dHas(ConstHandle2ConstNonNeutrinoEnergy This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Polynomial1dHas", This, extract::polynomial1d);
}

// Get, const
Handle2ConstPolynomial1d
NonNeutrinoEnergyPolynomial1dGetConst(ConstHandle2ConstNonNeutrinoEnergy This)
{
   return detail::getField<CPP,Handle2ConstPolynomial1d>
      (CLASSNAME, CLASSNAME+"Polynomial1dGetConst", This, extract::polynomial1d);
}

// Get, non-const
Handle2Polynomial1d
NonNeutrinoEnergyPolynomial1dGet(ConstHandle2NonNeutrinoEnergy This)
{
   return detail::getField<CPP,Handle2Polynomial1d>
      (CLASSNAME, CLASSNAME+"Polynomial1dGet", This, extract::polynomial1d);
}

// Set
void
NonNeutrinoEnergyPolynomial1dSet(ConstHandle2NonNeutrinoEnergy This, ConstHandle2ConstPolynomial1d polynomial1d)
{
   detail::setField<CPP,CPPPolynomial1d>
      (CLASSNAME, CLASSNAME+"Polynomial1dSet", This, extract::polynomial1d, polynomial1d);
}
