
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/containers/Integer.hpp"
#include "Integer.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = IntegerClass;
using CPP = multigroup::Integer;

static const std::string CLASSNAME = "Integer";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto unit = [](auto &obj) { return &obj.unit; };
   static auto value = [](auto &obj) { return &obj.value; };
}


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstInteger
IntegerDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Integer
IntegerDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstInteger
IntegerCreateConst(
   const XMLName label,
   const XMLName unit,
   const Integer32 value
) {
   ConstHandle2Integer handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      unit,
      value
   );
   return handle;
}

// Create, general
Handle2Integer
IntegerCreate(
   const XMLName label,
   const XMLName unit,
   const Integer32 value
) {
   ConstHandle2Integer handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      unit,
      value
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
IntegerAssign(ConstHandle2Integer This, ConstHandle2ConstInteger from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
IntegerDelete(ConstHandle2ConstInteger This)
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
IntegerRead(ConstHandle2Integer This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
IntegerWrite(ConstHandle2ConstInteger This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
IntegerPrint(ConstHandle2ConstInteger This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
IntegerPrintXML(ConstHandle2ConstInteger This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
IntegerPrintJSON(ConstHandle2ConstInteger This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
IntegerLabelHas(ConstHandle2ConstInteger This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
IntegerLabelGet(ConstHandle2ConstInteger This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
IntegerLabelSet(ConstHandle2Integer This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// Has
int
IntegerUnitHas(ConstHandle2ConstInteger This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UnitHas", This, extract::unit);
}

// Get
// Returns by value
XMLName
IntegerUnitGet(ConstHandle2ConstInteger This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"UnitGet", This, extract::unit);
}

// Set
void
IntegerUnitSet(ConstHandle2Integer This, const XMLName unit)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"UnitSet", This, extract::unit, unit);
}


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// Has
int
IntegerValueHas(ConstHandle2ConstInteger This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ValueHas", This, extract::value);
}

// Get
// Returns by value
Integer32
IntegerValueGet(ConstHandle2ConstInteger This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ValueGet", This, extract::value);
}

// Set
void
IntegerValueSet(ConstHandle2Integer This, const Integer32 value)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ValueSet", This, extract::value, value);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/containers/Integer/src/custom.cpp"
