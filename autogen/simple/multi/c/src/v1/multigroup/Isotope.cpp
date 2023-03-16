
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "multi/v1/multigroup/Isotope.hpp"
#include "Isotope.h"

using namespace njoy::GNDStk;
using namespace multi::v1;

using C = IsotopeClass;
using CPP = multigroup::Isotope;

static const std::string CLASSNAME = "Isotope";

namespace extract {
   static auto mass_number = [](auto &obj) { return &obj.mass_number; };
}


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstIsotope
IsotopeDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Isotope
IsotopeDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstIsotope
IsotopeCreateConst(
   const int mass_number
) {
   ConstHandle2Isotope handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      mass_number
   );
   return handle;
}

// Create, general
Handle2Isotope
IsotopeCreate(
   const int mass_number
) {
   ConstHandle2Isotope handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      mass_number
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
IsotopeAssign(ConstHandle2Isotope self, ConstHandle2ConstIsotope from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
IsotopeDelete(ConstHandle2ConstIsotope self)
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
IsotopeRead(ConstHandle2Isotope self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
IsotopeWrite(ConstHandle2ConstIsotope self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
IsotopePrint(ConstHandle2ConstIsotope self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
IsotopePrintXML(ConstHandle2ConstIsotope self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
IsotopePrintJSON(ConstHandle2ConstIsotope self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: mass_number
// -----------------------------------------------------------------------------

// Has
int
IsotopeMassNumberHas(ConstHandle2ConstIsotope self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"MassNumberHas", self, extract::mass_number);
}

// Get
// Returns by value
int
IsotopeMassNumberGet(ConstHandle2ConstIsotope self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"MassNumberGet", self, extract::mass_number);
}

// Set
void
IsotopeMassNumberSet(ConstHandle2Isotope self, const int mass_number)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"MassNumberSet", self, extract::mass_number, mass_number);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v1/multigroup/Isotope/src/custom.cpp"
