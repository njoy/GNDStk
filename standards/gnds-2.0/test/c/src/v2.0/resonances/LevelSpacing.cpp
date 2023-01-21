
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/resonances/LevelSpacing.hpp"
#include "LevelSpacing.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = LevelSpacingClass;
using CPP = multigroup::LevelSpacing;

static const std::string CLASSNAME = "LevelSpacing";

namespace extract {
   static auto constant1d = [](auto &obj) { return &obj.constant1d; };
   static auto XYs1d = [](auto &obj) { return &obj.XYs1d; };
   static auto regions1d = [](auto &obj) { return &obj.regions1d; };
}

using CPPConstant1d = containers::Constant1d;
using CPPXYs1d = containers::XYs1d;
using CPPRegions1d = containers::Regions1d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstLevelSpacing
LevelSpacingDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2LevelSpacing
LevelSpacingDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstLevelSpacing
LevelSpacingCreateConst(
   ConstHandle2ConstConstant1d constant1d,
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstRegions1d regions1d
) {
   ConstHandle2LevelSpacing handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPConstant1d>(constant1d),
      detail::tocpp<CPPXYs1d>(XYs1d),
      detail::tocpp<CPPRegions1d>(regions1d)
   );
   return handle;
}

// Create, general
Handle2LevelSpacing
LevelSpacingCreate(
   ConstHandle2ConstConstant1d constant1d,
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstRegions1d regions1d
) {
   ConstHandle2LevelSpacing handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPConstant1d>(constant1d),
      detail::tocpp<CPPXYs1d>(XYs1d),
      detail::tocpp<CPPRegions1d>(regions1d)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
LevelSpacingAssign(ConstHandle2LevelSpacing This, ConstHandle2ConstLevelSpacing from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
LevelSpacingDelete(ConstHandle2ConstLevelSpacing This)
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
LevelSpacingRead(ConstHandle2LevelSpacing This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
LevelSpacingWrite(ConstHandle2ConstLevelSpacing This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
LevelSpacingPrint(ConstHandle2ConstLevelSpacing This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
LevelSpacingPrintXML(ConstHandle2ConstLevelSpacing This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
LevelSpacingPrintJSON(ConstHandle2ConstLevelSpacing This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: constant1d
// -----------------------------------------------------------------------------

// Has
int
LevelSpacingConstant1dHas(ConstHandle2ConstLevelSpacing This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Constant1dHas", This, extract::constant1d);
}

// Get, const
Handle2ConstConstant1d
LevelSpacingConstant1dGetConst(ConstHandle2ConstLevelSpacing This)
{
   return detail::getField<CPP,Handle2ConstConstant1d>
      (CLASSNAME, CLASSNAME+"Constant1dGetConst", This, extract::constant1d);
}

// Get, non-const
Handle2Constant1d
LevelSpacingConstant1dGet(ConstHandle2LevelSpacing This)
{
   return detail::getField<CPP,Handle2Constant1d>
      (CLASSNAME, CLASSNAME+"Constant1dGet", This, extract::constant1d);
}

// Set
void
LevelSpacingConstant1dSet(ConstHandle2LevelSpacing This, ConstHandle2ConstConstant1d constant1d)
{
   detail::setField<CPP,CPPConstant1d>
      (CLASSNAME, CLASSNAME+"Constant1dSet", This, extract::constant1d, constant1d);
}


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// Has
int
LevelSpacingXYs1dHas(ConstHandle2ConstLevelSpacing This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"XYs1dHas", This, extract::XYs1d);
}

// Get, const
Handle2ConstXYs1d
LevelSpacingXYs1dGetConst(ConstHandle2ConstLevelSpacing This)
{
   return detail::getField<CPP,Handle2ConstXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGetConst", This, extract::XYs1d);
}

// Get, non-const
Handle2XYs1d
LevelSpacingXYs1dGet(ConstHandle2LevelSpacing This)
{
   return detail::getField<CPP,Handle2XYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGet", This, extract::XYs1d);
}

// Set
void
LevelSpacingXYs1dSet(ConstHandle2LevelSpacing This, ConstHandle2ConstXYs1d XYs1d)
{
   detail::setField<CPP,CPPXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dSet", This, extract::XYs1d, XYs1d);
}


// -----------------------------------------------------------------------------
// Child: regions1d
// -----------------------------------------------------------------------------

// Has
int
LevelSpacingRegions1dHas(ConstHandle2ConstLevelSpacing This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Regions1dHas", This, extract::regions1d);
}

// Get, const
Handle2ConstRegions1d
LevelSpacingRegions1dGetConst(ConstHandle2ConstLevelSpacing This)
{
   return detail::getField<CPP,Handle2ConstRegions1d>
      (CLASSNAME, CLASSNAME+"Regions1dGetConst", This, extract::regions1d);
}

// Get, non-const
Handle2Regions1d
LevelSpacingRegions1dGet(ConstHandle2LevelSpacing This)
{
   return detail::getField<CPP,Handle2Regions1d>
      (CLASSNAME, CLASSNAME+"Regions1dGet", This, extract::regions1d);
}

// Set
void
LevelSpacingRegions1dSet(ConstHandle2LevelSpacing This, ConstHandle2ConstRegions1d regions1d)
{
   detail::setField<CPP,CPPRegions1d>
      (CLASSNAME, CLASSNAME+"Regions1dSet", This, extract::regions1d, regions1d);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/resonances/LevelSpacing/src/custom.cpp"
