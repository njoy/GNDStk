
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/resonances/J.hpp"
#include "J.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = JClass;
using CPP = multigroup::J;

static const std::string CLASSNAME = "J";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto value = [](auto &obj) { return &obj.value; };
   static auto levelSpacing = [](auto &obj) { return &obj.levelSpacing; };
   static auto widths = [](auto &obj) { return &obj.widths; };
}

using CPPLevelSpacing = resonances::LevelSpacing;
using CPPWidths = resonances::Widths;


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
   const XMLName label,
   const Fraction32 value,
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
   const XMLName label,
   const Fraction32 value,
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
JAssign(ConstHandle2J This, ConstHandle2ConstJ from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
JDelete(ConstHandle2ConstJ This)
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
JRead(ConstHandle2J This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
JWrite(ConstHandle2ConstJ This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
JPrint(ConstHandle2ConstJ This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
JPrintXML(ConstHandle2ConstJ This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
JPrintJSON(ConstHandle2ConstJ This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
JLabelHas(ConstHandle2ConstJ This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
JLabelGet(ConstHandle2ConstJ This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
JLabelSet(ConstHandle2J This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// Has
int
JValueHas(ConstHandle2ConstJ This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ValueHas", This, extract::value);
}

// Get
// Returns by value
Fraction32
JValueGet(ConstHandle2ConstJ This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ValueGet", This, extract::value);
}

// Set
void
JValueSet(ConstHandle2J This, const Fraction32 value)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ValueSet", This, extract::value, value);
}


// -----------------------------------------------------------------------------
// Child: levelSpacing
// -----------------------------------------------------------------------------

// Has
int
JLevelSpacingHas(ConstHandle2ConstJ This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LevelSpacingHas", This, extract::levelSpacing);
}

// Get, const
Handle2ConstLevelSpacing
JLevelSpacingGetConst(ConstHandle2ConstJ This)
{
   return detail::getField<CPP,Handle2ConstLevelSpacing>
      (CLASSNAME, CLASSNAME+"LevelSpacingGetConst", This, extract::levelSpacing);
}

// Get, non-const
Handle2LevelSpacing
JLevelSpacingGet(ConstHandle2J This)
{
   return detail::getField<CPP,Handle2LevelSpacing>
      (CLASSNAME, CLASSNAME+"LevelSpacingGet", This, extract::levelSpacing);
}

// Set
void
JLevelSpacingSet(ConstHandle2J This, ConstHandle2ConstLevelSpacing levelSpacing)
{
   detail::setField<CPP,CPPLevelSpacing>
      (CLASSNAME, CLASSNAME+"LevelSpacingSet", This, extract::levelSpacing, levelSpacing);
}


// -----------------------------------------------------------------------------
// Child: widths
// -----------------------------------------------------------------------------

// Has
int
JWidthsHas(ConstHandle2ConstJ This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"WidthsHas", This, extract::widths);
}

// Get, const
Handle2ConstWidths
JWidthsGetConst(ConstHandle2ConstJ This)
{
   return detail::getField<CPP,Handle2ConstWidths>
      (CLASSNAME, CLASSNAME+"WidthsGetConst", This, extract::widths);
}

// Get, non-const
Handle2Widths
JWidthsGet(ConstHandle2J This)
{
   return detail::getField<CPP,Handle2Widths>
      (CLASSNAME, CLASSNAME+"WidthsGet", This, extract::widths);
}

// Set
void
JWidthsSet(ConstHandle2J This, ConstHandle2ConstWidths widths)
{
   detail::setField<CPP,CPPWidths>
      (CLASSNAME, CLASSNAME+"WidthsSet", This, extract::widths, widths);
}