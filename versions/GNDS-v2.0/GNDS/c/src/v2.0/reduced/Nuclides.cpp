
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/reduced/Nuclides.hpp"
#include "Nuclides.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = NuclidesClass;
using CPP = multigroup::Nuclides;

static const std::string CLASSNAME = "Nuclides";

namespace extract {
   static auto href = [](auto &obj) { return &obj.href; };
}


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstNuclides
NuclidesDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default, non-const
Handle2Nuclides
NuclidesDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstNuclides
NuclidesCreateConst(
   const char *const href
) {
   ConstHandle2Nuclides handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      href
   );
   return handle;
}

// Create, general, non-const
Handle2Nuclides
NuclidesCreate(
   const char *const href
) {
   ConstHandle2Nuclides handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      href
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
NuclidesAssign(ConstHandle2Nuclides self, ConstHandle2ConstNuclides from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
NuclidesDelete(ConstHandle2ConstNuclides self)
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
NuclidesRead(ConstHandle2Nuclides self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
NuclidesWrite(ConstHandle2ConstNuclides self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
NuclidesPrint(ConstHandle2ConstNuclides self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
NuclidesPrintXML(ConstHandle2ConstNuclides self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
NuclidesPrintJSON(ConstHandle2ConstNuclides self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Data vector
// -----------------------------------------------------------------------------

// Clear
void
NuclidesStringsClear(ConstHandle2Nuclides self)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"StringsClear", self);
}

// Get size
size_t
NuclidesStringsSize(ConstHandle2ConstNuclides self)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"StringsSize", self);
}

// Get value
// By index \in [0,size)
std::string
NuclidesStringsGet(ConstHandle2ConstNuclides self, const size_t index)
{
   return detail::vectorGet<CPP,std::string>
      (CLASSNAME, CLASSNAME+"StringsGet", self, index);
}

// Set value
// By index \in [0,size)
void
NuclidesStringsSet(ConstHandle2Nuclides self, const size_t index, const std::string value)
{
   detail::vectorSet<CPP,std::string>
      (CLASSNAME, CLASSNAME+"StringsSet", self, index, value);
}


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// Has
int
NuclidesHrefHas(ConstHandle2ConstNuclides self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"HrefHas", self, extract::href);
}

// Get
// Returns by value
const char *
NuclidesHrefGet(ConstHandle2ConstNuclides self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"HrefGet", self, extract::href);
}

// Set
void
NuclidesHrefSet(ConstHandle2Nuclides self, const char *const href)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"HrefSet", self, extract::href, href);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/reduced/Nuclides/src/custom.cpp"
