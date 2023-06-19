
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2.0/general/Axis.hpp"
#include "Axis.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = AxisClass;
using CPP = multigroup::Axis;

static const std::string CLASSNAME = "Axis";

namespace extract {
   static auto index = [](auto &obj) { return &obj.index; };
   static auto label = [](auto &obj) { return &obj.label; };
   static auto unit = [](auto &obj) { return &obj.unit; };
}


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstAxis
AxisDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Axis
AxisDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstAxis
AxisCreateConst(
   const int index,
   const char *const label,
   const char *const unit
) {
   ConstHandle2Axis handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      index,
      label,
      unit
   );
   return handle;
}

// Create, general
Handle2Axis
AxisCreate(
   const int index,
   const char *const label,
   const char *const unit
) {
   ConstHandle2Axis handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      index,
      label,
      unit
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
AxisAssign(ConstHandle2Axis self, ConstHandle2ConstAxis from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
AxisDelete(ConstHandle2ConstAxis self)
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
AxisRead(ConstHandle2Axis self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
AxisWrite(ConstHandle2ConstAxis self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
AxisPrint(ConstHandle2ConstAxis self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
AxisPrintXML(ConstHandle2ConstAxis self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
AxisPrintJSON(ConstHandle2ConstAxis self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: index
// -----------------------------------------------------------------------------

// Has
int
AxisIndexHas(ConstHandle2ConstAxis self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"IndexHas", self, extract::index);
}

// Get
// Returns by value
int
AxisIndexGet(ConstHandle2ConstAxis self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"IndexGet", self, extract::index);
}

// Set
void
AxisIndexSet(ConstHandle2Axis self, const int index)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"IndexSet", self, extract::index, index);
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
AxisLabelHas(ConstHandle2ConstAxis self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
const char *
AxisLabelGet(ConstHandle2ConstAxis self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
AxisLabelSet(ConstHandle2Axis self, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// Has
int
AxisUnitHas(ConstHandle2ConstAxis self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UnitHas", self, extract::unit);
}

// Get
// Returns by value
const char *
AxisUnitGet(ConstHandle2ConstAxis self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"UnitGet", self, extract::unit);
}

// Set
void
AxisUnitSet(ConstHandle2Axis self, const char *const unit)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"UnitSet", self, extract::unit, unit);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Axis/src/custom.cpp"
