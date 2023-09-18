
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/J.hpp"
#include "J.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = JClass;
using CPP = multigroup::J;

static const std::string CLASSNAME = "J";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto value = [](auto &obj) { return &obj.value; };
   static auto levelSpacing = [](auto &obj) { return &obj.levelSpacing; };
   static auto widths = [](auto &obj) { return &obj.widths; };
}

using CPPLevelSpacing = general::LevelSpacing;
using CPPWidths = general::Widths;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstJ
JDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2J
JDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstJ
JCreateConst(
   const char *const label,
   const int value,
   ConstHandle2ConstLevelSpacing levelSpacing,
   ConstHandle2ConstWidths widths
) {
   ConstHandle2J handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      value,
      detail::tocpp<CPPLevelSpacing>(levelSpacing),
      detail::tocpp<CPPWidths>(widths)
   );
   return handle;
}

// Create, general
Handle2J
JCreate(
   const char *const label,
   const int value,
   ConstHandle2ConstLevelSpacing levelSpacing,
   ConstHandle2ConstWidths widths
) {
   ConstHandle2J handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      value,
      detail::tocpp<CPPLevelSpacing>(levelSpacing),
      detail::tocpp<CPPWidths>(widths)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
JAssign(ConstHandle2J self, ConstHandle2ConstJ from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
JDelete(ConstHandle2ConstJ self)
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
JRead(ConstHandle2J self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
JWrite(ConstHandle2ConstJ self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
JPrint(ConstHandle2ConstJ self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
JPrintXML(ConstHandle2ConstJ self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
JPrintJSON(ConstHandle2ConstJ self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
JLabelHas(ConstHandle2ConstJ self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
const char *
JLabelGet(ConstHandle2ConstJ self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
JLabelSet(ConstHandle2J self, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// Has
int
JValueHas(ConstHandle2ConstJ self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ValueHas", self, extract::value);
}

// Get
// Returns by value
int
JValueGet(ConstHandle2ConstJ self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ValueGet", self, extract::value);
}

// Set
void
JValueSet(ConstHandle2J self, const int value)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ValueSet", self, extract::value, value);
}


// -----------------------------------------------------------------------------
// Child: levelSpacing
// -----------------------------------------------------------------------------

// Has
int
JLevelSpacingHas(ConstHandle2ConstJ self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LevelSpacingHas", self, extract::levelSpacing);
}

// Get, const
Handle2ConstLevelSpacing
JLevelSpacingGetConst(ConstHandle2ConstJ self)
{
   return detail::getField<CPP,Handle2ConstLevelSpacing>
      (CLASSNAME, CLASSNAME+"LevelSpacingGetConst", self, extract::levelSpacing);
}

// Get
Handle2LevelSpacing
JLevelSpacingGet(ConstHandle2J self)
{
   return detail::getField<CPP,Handle2LevelSpacing>
      (CLASSNAME, CLASSNAME+"LevelSpacingGet", self, extract::levelSpacing);
}

// Set
void
JLevelSpacingSet(ConstHandle2J self, ConstHandle2ConstLevelSpacing levelSpacing)
{
   detail::setField<CPP,CPPLevelSpacing>
      (CLASSNAME, CLASSNAME+"LevelSpacingSet", self, extract::levelSpacing, levelSpacing);
}


// -----------------------------------------------------------------------------
// Child: widths
// -----------------------------------------------------------------------------

// Has
int
JWidthsHas(ConstHandle2ConstJ self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"WidthsHas", self, extract::widths);
}

// Get, const
Handle2ConstWidths
JWidthsGetConst(ConstHandle2ConstJ self)
{
   return detail::getField<CPP,Handle2ConstWidths>
      (CLASSNAME, CLASSNAME+"WidthsGetConst", self, extract::widths);
}

// Get
Handle2Widths
JWidthsGet(ConstHandle2J self)
{
   return detail::getField<CPP,Handle2Widths>
      (CLASSNAME, CLASSNAME+"WidthsGet", self, extract::widths);
}

// Set
void
JWidthsSet(ConstHandle2J self, ConstHandle2ConstWidths widths)
{
   detail::setField<CPP,CPPWidths>
      (CLASSNAME, CLASSNAME+"WidthsSet", self, extract::widths, widths);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/J/src/custom.cpp"
