
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/pops/LogNormal.hpp"
#include "LogNormal.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = LogNormalClass;
using CPP = multigroup::LogNormal;

static const std::string CLASSNAME = "LogNormal";

namespace extract {
   static auto Double = [](auto &obj) { return &obj.Double; };
}

using CPPDouble = extra::Double;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstLogNormal
LogNormalDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2LogNormal
LogNormalDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstLogNormal
LogNormalCreateConst(
   ConstHandle2ConstDouble Double
) {
   ConstHandle2LogNormal handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPDouble>(Double)
   );
   return handle;
}

// Create, general
Handle2LogNormal
LogNormalCreate(
   ConstHandle2ConstDouble Double
) {
   ConstHandle2LogNormal handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPDouble>(Double)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
LogNormalAssign(ConstHandle2LogNormal self, ConstHandle2ConstLogNormal from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
LogNormalDelete(ConstHandle2ConstLogNormal self)
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
LogNormalRead(ConstHandle2LogNormal self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
LogNormalWrite(ConstHandle2ConstLogNormal self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
LogNormalPrint(ConstHandle2ConstLogNormal self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
LogNormalPrintXML(ConstHandle2ConstLogNormal self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
LogNormalPrintJSON(ConstHandle2ConstLogNormal self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: Double
// -----------------------------------------------------------------------------

// Has
int
LogNormalDoubleHas(ConstHandle2ConstLogNormal self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DoubleHas", self, extract::Double);
}

// Get, const
Handle2ConstDouble
LogNormalDoubleGetConst(ConstHandle2ConstLogNormal self)
{
   return detail::getField<CPP,Handle2ConstDouble>
      (CLASSNAME, CLASSNAME+"DoubleGetConst", self, extract::Double);
}

// Get, non-const
Handle2Double
LogNormalDoubleGet(ConstHandle2LogNormal self)
{
   return detail::getField<CPP,Handle2Double>
      (CLASSNAME, CLASSNAME+"DoubleGet", self, extract::Double);
}

// Set
void
LogNormalDoubleSet(ConstHandle2LogNormal self, ConstHandle2ConstDouble Double)
{
   detail::setField<CPP,CPPDouble>
      (CLASSNAME, CLASSNAME+"DoubleSet", self, extract::Double, Double);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/pops/LogNormal/src/custom.cpp"
