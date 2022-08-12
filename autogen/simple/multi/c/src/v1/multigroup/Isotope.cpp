
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

// Create: default, const
Handle2ConstIsotope
IsotopeDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create: default
Handle2Isotope
IsotopeDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create: general, const
Handle2ConstIsotope
IsotopeCreateConst(
   const int mass_number
) {
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"CreateConst",
       mass_number);
}

// Create: general
Handle2Isotope
IsotopeCreate(
   const int mass_number
) {
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Create",
       mass_number);
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
IsotopeAssign(ConstHandle2Isotope This, ConstHandle2ConstIsotope from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
IsotopeDelete(ConstHandle2ConstIsotope This)
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
IsotopeRead(ConstHandle2Isotope This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
IsotopeWrite(ConstHandle2ConstIsotope This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
IsotopePrint(ConstHandle2ConstIsotope This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
IsotopePrintXML(ConstHandle2ConstIsotope This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
IsotopePrintJSON(ConstHandle2ConstIsotope This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Re: mass_number
// -----------------------------------------------------------------------------

// Has
int
IsotopeMassNumberHas(ConstHandle2ConstIsotope This)
{
   return detail::hasMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"MassNumberHas", This, extract::mass_number);
}

// Get
int
IsotopeMassNumberGet(ConstHandle2ConstIsotope This)
{
   return detail::getMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"MassNumberGet", This, extract::mass_number);
}

// Set
void
IsotopeMassNumberSet(ConstHandle2Isotope This, const int mass_number)
{
   detail::setMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"MassNumberSet", This, extract::mass_number, mass_number);
}
