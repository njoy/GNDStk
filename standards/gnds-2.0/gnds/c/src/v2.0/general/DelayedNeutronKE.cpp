
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "gnds/v2.0/general/DelayedNeutronKE.hpp"
#include "DelayedNeutronKE.h"

using namespace njoy::GNDStk;
using namespace gnds::v2_0;

using C = DelayedNeutronKEClass;
using CPP = multigroup::DelayedNeutronKE;

static const std::string CLASSNAME = "DelayedNeutronKE";

namespace extract {
   static auto polynomial1d = [](auto &obj) { return &obj.polynomial1d; };
   static auto XYs1d = [](auto &obj) { return &obj.XYs1d; };
}

using CPPPolynomial1d = general::Polynomial1d;
using CPPXYs1d = general::XYs1d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstDelayedNeutronKE
DelayedNeutronKEDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2DelayedNeutronKE
DelayedNeutronKEDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstDelayedNeutronKE
DelayedNeutronKECreateConst(
   ConstHandle2ConstPolynomial1d polynomial1d,
   ConstHandle2ConstXYs1d XYs1d
) {
   ConstHandle2DelayedNeutronKE handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPPolynomial1d>(polynomial1d),
      detail::tocpp<CPPXYs1d>(XYs1d)
   );
   return handle;
}

// Create, general
Handle2DelayedNeutronKE
DelayedNeutronKECreate(
   ConstHandle2ConstPolynomial1d polynomial1d,
   ConstHandle2ConstXYs1d XYs1d
) {
   ConstHandle2DelayedNeutronKE handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPPolynomial1d>(polynomial1d),
      detail::tocpp<CPPXYs1d>(XYs1d)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
DelayedNeutronKEAssign(ConstHandle2DelayedNeutronKE self, ConstHandle2ConstDelayedNeutronKE from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
DelayedNeutronKEDelete(ConstHandle2ConstDelayedNeutronKE self)
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
DelayedNeutronKERead(ConstHandle2DelayedNeutronKE self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
DelayedNeutronKEWrite(ConstHandle2ConstDelayedNeutronKE self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
DelayedNeutronKEPrint(ConstHandle2ConstDelayedNeutronKE self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
DelayedNeutronKEPrintXML(ConstHandle2ConstDelayedNeutronKE self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
DelayedNeutronKEPrintJSON(ConstHandle2ConstDelayedNeutronKE self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: polynomial1d
// -----------------------------------------------------------------------------

// Has
int
DelayedNeutronKEPolynomial1dHas(ConstHandle2ConstDelayedNeutronKE self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Polynomial1dHas", self, extract::polynomial1d);
}

// Get, const
Handle2ConstPolynomial1d
DelayedNeutronKEPolynomial1dGetConst(ConstHandle2ConstDelayedNeutronKE self)
{
   return detail::getField<CPP,Handle2ConstPolynomial1d>
      (CLASSNAME, CLASSNAME+"Polynomial1dGetConst", self, extract::polynomial1d);
}

// Get, non-const
Handle2Polynomial1d
DelayedNeutronKEPolynomial1dGet(ConstHandle2DelayedNeutronKE self)
{
   return detail::getField<CPP,Handle2Polynomial1d>
      (CLASSNAME, CLASSNAME+"Polynomial1dGet", self, extract::polynomial1d);
}

// Set
void
DelayedNeutronKEPolynomial1dSet(ConstHandle2DelayedNeutronKE self, ConstHandle2ConstPolynomial1d polynomial1d)
{
   detail::setField<CPP,CPPPolynomial1d>
      (CLASSNAME, CLASSNAME+"Polynomial1dSet", self, extract::polynomial1d, polynomial1d);
}


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// Has
int
DelayedNeutronKEXYs1dHas(ConstHandle2ConstDelayedNeutronKE self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"XYs1dHas", self, extract::XYs1d);
}

// Get, const
Handle2ConstXYs1d
DelayedNeutronKEXYs1dGetConst(ConstHandle2ConstDelayedNeutronKE self)
{
   return detail::getField<CPP,Handle2ConstXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGetConst", self, extract::XYs1d);
}

// Get, non-const
Handle2XYs1d
DelayedNeutronKEXYs1dGet(ConstHandle2DelayedNeutronKE self)
{
   return detail::getField<CPP,Handle2XYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGet", self, extract::XYs1d);
}

// Set
void
DelayedNeutronKEXYs1dSet(ConstHandle2DelayedNeutronKE self, ConstHandle2ConstXYs1d XYs1d)
{
   detail::setField<CPP,CPPXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dSet", self, extract::XYs1d, XYs1d);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/DelayedNeutronKE/src/custom.cpp"
