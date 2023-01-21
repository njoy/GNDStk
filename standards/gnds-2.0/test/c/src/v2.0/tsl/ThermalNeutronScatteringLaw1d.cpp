
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/tsl/ThermalNeutronScatteringLaw1d.hpp"
#include "ThermalNeutronScatteringLaw1d.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = ThermalNeutronScatteringLaw1dClass;
using CPP = multigroup::ThermalNeutronScatteringLaw1d;

static const std::string CLASSNAME = "ThermalNeutronScatteringLaw1d";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto href = [](auto &obj) { return &obj.href; };
}


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstThermalNeutronScatteringLaw1d
ThermalNeutronScatteringLaw1dDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2ThermalNeutronScatteringLaw1d
ThermalNeutronScatteringLaw1dDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstThermalNeutronScatteringLaw1d
ThermalNeutronScatteringLaw1dCreateConst(
   const XMLName label,
   const XMLName href
) {
   ConstHandle2ThermalNeutronScatteringLaw1d handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      href
   );
   return handle;
}

// Create, general
Handle2ThermalNeutronScatteringLaw1d
ThermalNeutronScatteringLaw1dCreate(
   const XMLName label,
   const XMLName href
) {
   ConstHandle2ThermalNeutronScatteringLaw1d handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      href
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ThermalNeutronScatteringLaw1dAssign(ConstHandle2ThermalNeutronScatteringLaw1d This, ConstHandle2ConstThermalNeutronScatteringLaw1d from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ThermalNeutronScatteringLaw1dDelete(ConstHandle2ConstThermalNeutronScatteringLaw1d This)
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
ThermalNeutronScatteringLaw1dRead(ConstHandle2ThermalNeutronScatteringLaw1d This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ThermalNeutronScatteringLaw1dWrite(ConstHandle2ConstThermalNeutronScatteringLaw1d This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
ThermalNeutronScatteringLaw1dPrint(ConstHandle2ConstThermalNeutronScatteringLaw1d This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
ThermalNeutronScatteringLaw1dPrintXML(ConstHandle2ConstThermalNeutronScatteringLaw1d This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
ThermalNeutronScatteringLaw1dPrintJSON(ConstHandle2ConstThermalNeutronScatteringLaw1d This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
ThermalNeutronScatteringLaw1dLabelHas(ConstHandle2ConstThermalNeutronScatteringLaw1d This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
ThermalNeutronScatteringLaw1dLabelGet(ConstHandle2ConstThermalNeutronScatteringLaw1d This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
ThermalNeutronScatteringLaw1dLabelSet(ConstHandle2ThermalNeutronScatteringLaw1d This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// Has
int
ThermalNeutronScatteringLaw1dHrefHas(ConstHandle2ConstThermalNeutronScatteringLaw1d This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"HrefHas", This, extract::href);
}

// Get
// Returns by value
XMLName
ThermalNeutronScatteringLaw1dHrefGet(ConstHandle2ConstThermalNeutronScatteringLaw1d This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"HrefGet", This, extract::href);
}

// Set
void
ThermalNeutronScatteringLaw1dHrefSet(ConstHandle2ThermalNeutronScatteringLaw1d This, const XMLName href)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"HrefSet", This, extract::href, href);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/tsl/ThermalNeutronScatteringLaw1d/src/custom.cpp"
