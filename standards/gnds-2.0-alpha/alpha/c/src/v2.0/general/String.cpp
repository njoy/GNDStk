
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/String.hpp"
#include "String.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = StringClass;
using CPP = multigroup::String;

static const std::string CLASSNAME = "String";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto value = [](auto &obj) { return &obj.value; };
   static auto unit = [](auto &obj) { return &obj.unit; };
}


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstString
StringDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2String
StringDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstString
StringCreateConst(
   const char *const label,
   const char *const value,
   const char *const unit
) {
   ConstHandle2String handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      value,
      unit
   );
   return handle;
}

// Create, general
Handle2String
StringCreate(
   const char *const label,
   const char *const value,
   const char *const unit
) {
   ConstHandle2String handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      value,
      unit
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
StringAssign(ConstHandle2String self, ConstHandle2ConstString from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
StringDelete(ConstHandle2ConstString self)
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
StringRead(ConstHandle2String self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
StringWrite(ConstHandle2ConstString self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
StringPrint(ConstHandle2ConstString self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
StringPrintXML(ConstHandle2ConstString self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
StringPrintJSON(ConstHandle2ConstString self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
StringLabelHas(ConstHandle2ConstString self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
const char *
StringLabelGet(ConstHandle2ConstString self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
StringLabelSet(ConstHandle2String self, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// Has
int
StringValueHas(ConstHandle2ConstString self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ValueHas", self, extract::value);
}

// Get
// Returns by value
const char *
StringValueGet(ConstHandle2ConstString self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ValueGet", self, extract::value);
}

// Set
void
StringValueSet(ConstHandle2String self, const char *const value)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ValueSet", self, extract::value, value);
}


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// Has
int
StringUnitHas(ConstHandle2ConstString self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UnitHas", self, extract::unit);
}

// Get
// Returns by value
const char *
StringUnitGet(ConstHandle2ConstString self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"UnitGet", self, extract::unit);
}

// Set
void
StringUnitSet(ConstHandle2String self, const char *const unit)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"UnitSet", self, extract::unit, unit);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/String/src/custom.cpp"
