
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/Mass.hpp"
#include "Mass.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = MassClass;
using CPP = multigroup::Mass;

static const std::string CLASSNAME = "Mass";

namespace extract {
   static auto value = [](auto &obj) { return &obj.value; };
   static auto unit = [](auto &obj) { return &obj.unit; };
   static auto Double = [](auto &obj) { return &obj.Double; };
}

using CPPDouble = general::Double;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstMass
MassDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Mass
MassDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstMass
MassCreateConst(
   const double value,
   const char *const unit,
   ConstHandle2ConstDouble Double
) {
   ConstHandle2Mass handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      value,
      unit,
      detail::tocpp<CPPDouble>(Double)
   );
   return handle;
}

// Create, general
Handle2Mass
MassCreate(
   const double value,
   const char *const unit,
   ConstHandle2ConstDouble Double
) {
   ConstHandle2Mass handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      value,
      unit,
      detail::tocpp<CPPDouble>(Double)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
MassAssign(ConstHandle2Mass self, ConstHandle2ConstMass from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
MassDelete(ConstHandle2ConstMass self)
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
MassRead(ConstHandle2Mass self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
MassWrite(ConstHandle2ConstMass self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
MassPrint(ConstHandle2ConstMass self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
MassPrintXML(ConstHandle2ConstMass self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
MassPrintJSON(ConstHandle2ConstMass self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// Has
int
MassValueHas(ConstHandle2ConstMass self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ValueHas", self, extract::value);
}

// Get
// Returns by value
double
MassValueGet(ConstHandle2ConstMass self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ValueGet", self, extract::value);
}

// Set
void
MassValueSet(ConstHandle2Mass self, const double value)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ValueSet", self, extract::value, value);
}


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// Has
int
MassUnitHas(ConstHandle2ConstMass self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UnitHas", self, extract::unit);
}

// Get
// Returns by value
const char *
MassUnitGet(ConstHandle2ConstMass self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"UnitGet", self, extract::unit);
}

// Set
void
MassUnitSet(ConstHandle2Mass self, const char *const unit)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"UnitSet", self, extract::unit, unit);
}


// -----------------------------------------------------------------------------
// Child: Double
// -----------------------------------------------------------------------------

// Has
int
MassDoubleHas(ConstHandle2ConstMass self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DoubleHas", self, extract::Double);
}

// Get, const
Handle2ConstDouble
MassDoubleGetConst(ConstHandle2ConstMass self)
{
   return detail::getField<CPP,Handle2ConstDouble>
      (CLASSNAME, CLASSNAME+"DoubleGetConst", self, extract::Double);
}

// Get
Handle2Double
MassDoubleGet(ConstHandle2Mass self)
{
   return detail::getField<CPP,Handle2Double>
      (CLASSNAME, CLASSNAME+"DoubleGet", self, extract::Double);
}

// Set
void
MassDoubleSet(ConstHandle2Mass self, ConstHandle2ConstDouble Double)
{
   detail::setField<CPP,CPPDouble>
      (CLASSNAME, CLASSNAME+"DoubleSet", self, extract::Double, Double);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Mass/src/custom.cpp"
