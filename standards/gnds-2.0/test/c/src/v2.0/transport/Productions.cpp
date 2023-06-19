
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2.0/transport/Productions.hpp"
#include "Productions.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = ProductionsClass;
using CPP = multigroup::Productions;

static const std::string CLASSNAME = "Productions";

namespace extract {
   static auto production = [](auto &obj) { return &obj.production; };
}

using CPPProduction = transport::Production;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstProductions
ProductionsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Productions
ProductionsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstProductions
ProductionsCreateConst(
   ConstHandle2ConstProduction production
) {
   ConstHandle2Productions handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPProduction>(production)
   );
   return handle;
}

// Create, general
Handle2Productions
ProductionsCreate(
   ConstHandle2ConstProduction production
) {
   ConstHandle2Productions handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPProduction>(production)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ProductionsAssign(ConstHandle2Productions self, ConstHandle2ConstProductions from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ProductionsDelete(ConstHandle2ConstProductions self)
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
ProductionsRead(ConstHandle2Productions self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ProductionsWrite(ConstHandle2ConstProductions self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ProductionsPrint(ConstHandle2ConstProductions self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ProductionsPrintXML(ConstHandle2ConstProductions self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ProductionsPrintJSON(ConstHandle2ConstProductions self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: production
// -----------------------------------------------------------------------------

// Has
int
ProductionsProductionHas(ConstHandle2ConstProductions self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ProductionHas", self, extract::production);
}

// Get, const
Handle2ConstProduction
ProductionsProductionGetConst(ConstHandle2ConstProductions self)
{
   return detail::getField<CPP,Handle2ConstProduction>
      (CLASSNAME, CLASSNAME+"ProductionGetConst", self, extract::production);
}

// Get, non-const
Handle2Production
ProductionsProductionGet(ConstHandle2Productions self)
{
   return detail::getField<CPP,Handle2Production>
      (CLASSNAME, CLASSNAME+"ProductionGet", self, extract::production);
}

// Set
void
ProductionsProductionSet(ConstHandle2Productions self, ConstHandle2ConstProduction production)
{
   detail::setField<CPP,CPPProduction>
      (CLASSNAME, CLASSNAME+"ProductionSet", self, extract::production, production);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/transport/Productions/src/custom.cpp"
