
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2.0/resonances/L.hpp"
#include "L.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = LClass;
using CPP = multigroup::L;

static const std::string CLASSNAME = "L";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto value = [](auto &obj) { return &obj.value; };
   static auto Js = [](auto &obj) { return &obj.Js; };
}

using CPPJs = resonances::Js;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstL
LDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2L
LDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstL
LCreateConst(
   const XMLName label,
   const Integer32 value,
   ConstHandle2ConstJs Js
) {
   ConstHandle2L handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      value,
      detail::tocpp<CPPJs>(Js)
   );
   return handle;
}

// Create, general
Handle2L
LCreate(
   const XMLName label,
   const Integer32 value,
   ConstHandle2ConstJs Js
) {
   ConstHandle2L handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      value,
      detail::tocpp<CPPJs>(Js)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
LAssign(ConstHandle2L self, ConstHandle2ConstL from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
LDelete(ConstHandle2ConstL self)
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
LRead(ConstHandle2L self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
LWrite(ConstHandle2ConstL self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
LPrint(ConstHandle2ConstL self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
LPrintXML(ConstHandle2ConstL self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
LPrintJSON(ConstHandle2ConstL self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
LLabelHas(ConstHandle2ConstL self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
XMLName
LLabelGet(ConstHandle2ConstL self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
LLabelSet(ConstHandle2L self, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// Has
int
LValueHas(ConstHandle2ConstL self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ValueHas", self, extract::value);
}

// Get
// Returns by value
Integer32
LValueGet(ConstHandle2ConstL self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ValueGet", self, extract::value);
}

// Set
void
LValueSet(ConstHandle2L self, const Integer32 value)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ValueSet", self, extract::value, value);
}


// -----------------------------------------------------------------------------
// Child: Js
// -----------------------------------------------------------------------------

// Has
int
LJsHas(ConstHandle2ConstL self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"JsHas", self, extract::Js);
}

// Get, const
Handle2ConstJs
LJsGetConst(ConstHandle2ConstL self)
{
   return detail::getField<CPP,Handle2ConstJs>
      (CLASSNAME, CLASSNAME+"JsGetConst", self, extract::Js);
}

// Get, non-const
Handle2Js
LJsGet(ConstHandle2L self)
{
   return detail::getField<CPP,Handle2Js>
      (CLASSNAME, CLASSNAME+"JsGet", self, extract::Js);
}

// Set
void
LJsSet(ConstHandle2L self, ConstHandle2ConstJs Js)
{
   detail::setField<CPP,CPPJs>
      (CLASSNAME, CLASSNAME+"JsSet", self, extract::Js, Js);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/resonances/L/src/custom.cpp"
