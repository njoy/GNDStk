
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
      (CLASSNAME, "IsotopeDefaultConst");
}

// Create: default
Handle2Isotope
IsotopeDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, "IsotopeDefault");
}

// Create: general, const
Handle2ConstIsotope
IsotopeCreateConst(
   const int mass_number
) {
   return detail::createHandle<CPP,C>
      (CLASSNAME, "IsotopeCreateConst",
       mass_number);
}

// Create: general
Handle2Isotope
IsotopeCreate(
   const int mass_number
) {
   return detail::createHandle<CPP,C>
      (CLASSNAME, "IsotopeCreate",
       mass_number);
}

// Assign
void
IsotopeAssign(ConstHandle2Isotope This, ConstHandle2ConstIsotope from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, "IsotopeAssign", This, from);
}

// Delete
void
IsotopeDelete(ConstHandle2ConstIsotope This)
{
   detail::deleteHandle<CPP,C>
      (CLASSNAME, "IsotopeDelete", This);
}


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// Read
int
IsotopeRead(ConstHandle2Isotope This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, "IsotopeRead", This, filename);
}

// Write
int
IsotopeWrite(ConstHandle2ConstIsotope This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, "IsotopeWrite", This, filename);
}

// Print to standard output
int
IsotopePrint(ConstHandle2ConstIsotope This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, "IsotopePrint", This);
}

// Print to standard output, as XML
int
IsotopePrintXML(ConstHandle2ConstIsotope This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, "IsotopePrintXML", This, "XML");
}

// Print to standard output, as JSON
int
IsotopePrintJSON(ConstHandle2ConstIsotope This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, "IsotopePrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Re: mass_number
// -----------------------------------------------------------------------------

// Has
int
IsotopeMassNumberHas(ConstHandle2ConstIsotope This)
{
   return detail::hasMetadatum<CPP>
      (CLASSNAME, "IsotopeMassNumberHas", This, extract::mass_number);
}

// Get
int
IsotopeMassNumberGet(ConstHandle2ConstIsotope This)
{
   return detail::getMetadatum<CPP>
      (CLASSNAME, "IsotopeMassNumberGet", This, extract::mass_number);
}

// Set
void
IsotopeMassNumberSet(ConstHandle2Isotope This, const int mass_number)
{
   detail::setMetadatum<CPP>
      (CLASSNAME, "IsotopeMassNumberSet", This, extract::mass_number, mass_number);
}
