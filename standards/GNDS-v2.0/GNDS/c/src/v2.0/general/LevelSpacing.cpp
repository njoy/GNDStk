
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/LevelSpacing.hpp"
#include "LevelSpacing.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = LevelSpacingClass;
using CPP = multigroup::LevelSpacing;

static const std::string CLASSNAME = "LevelSpacing";

namespace extract {
   static auto XYs1d = [](auto &obj) { return &obj.XYs1d; };
   static auto constant1d = [](auto &obj) { return &obj.constant1d; };
}

using CPPXYs1d = general::XYs1d;
using CPPConstant1d = general::Constant1d;


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
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstConstant1d constant1d
) {
   ConstHandle2LevelSpacing handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPXYs1d>(XYs1d),
      detail::tocpp<CPPConstant1d>(constant1d)
   );
   return handle;
}

// Create, general
Handle2LevelSpacing
LevelSpacingCreate(
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstConstant1d constant1d
) {
   ConstHandle2LevelSpacing handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPXYs1d>(XYs1d),
      detail::tocpp<CPPConstant1d>(constant1d)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
LevelSpacingAssign(ConstHandle2LevelSpacing self, ConstHandle2ConstLevelSpacing from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
LevelSpacingDelete(ConstHandle2ConstLevelSpacing self)
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
LevelSpacingRead(ConstHandle2LevelSpacing self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
LevelSpacingWrite(ConstHandle2ConstLevelSpacing self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
LevelSpacingPrint(ConstHandle2ConstLevelSpacing self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
LevelSpacingPrintXML(ConstHandle2ConstLevelSpacing self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
LevelSpacingPrintJSON(ConstHandle2ConstLevelSpacing self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// Has
int
LevelSpacingXYs1dHas(ConstHandle2ConstLevelSpacing self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"XYs1dHas", self, extract::XYs1d);
}

// Get, const
Handle2ConstXYs1d
LevelSpacingXYs1dGetConst(ConstHandle2ConstLevelSpacing self)
{
   return detail::getField<CPP,Handle2ConstXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGetConst", self, extract::XYs1d);
}

// Get, non-const
Handle2XYs1d
LevelSpacingXYs1dGet(ConstHandle2LevelSpacing self)
{
   return detail::getField<CPP,Handle2XYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGet", self, extract::XYs1d);
}

// Set
void
LevelSpacingXYs1dSet(ConstHandle2LevelSpacing self, ConstHandle2ConstXYs1d XYs1d)
{
   detail::setField<CPP,CPPXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dSet", self, extract::XYs1d, XYs1d);
}


// -----------------------------------------------------------------------------
// Child: constant1d
// -----------------------------------------------------------------------------

// Has
int
LevelSpacingConstant1dHas(ConstHandle2ConstLevelSpacing self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Constant1dHas", self, extract::constant1d);
}

// Get, const
Handle2ConstConstant1d
LevelSpacingConstant1dGetConst(ConstHandle2ConstLevelSpacing self)
{
   return detail::getField<CPP,Handle2ConstConstant1d>
      (CLASSNAME, CLASSNAME+"Constant1dGetConst", self, extract::constant1d);
}

// Get, non-const
Handle2Constant1d
LevelSpacingConstant1dGet(ConstHandle2LevelSpacing self)
{
   return detail::getField<CPP,Handle2Constant1d>
      (CLASSNAME, CLASSNAME+"Constant1dGet", self, extract::constant1d);
}

// Set
void
LevelSpacingConstant1dSet(ConstHandle2LevelSpacing self, ConstHandle2ConstConstant1d constant1d)
{
   detail::setField<CPP,CPPConstant1d>
      (CLASSNAME, CLASSNAME+"Constant1dSet", self, extract::constant1d, constant1d);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/LevelSpacing/src/custom.cpp"