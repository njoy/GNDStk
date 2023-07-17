
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2.0/general/T_M.hpp"
#include "T_M.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = T_MClass;
using CPP = multigroup::T_M;

static const std::string CLASSNAME = "T_M";

namespace extract {
   static auto XYs1d = [](auto &obj) { return &obj.XYs1d; };
}

using CPPXYs1d = general::XYs1d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstT_M
T_MDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2T_M
T_MDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstT_M
T_MCreateConst(
   ConstHandle2ConstXYs1d XYs1d
) {
   ConstHandle2T_M handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPXYs1d>(XYs1d)
   );
   return handle;
}

// Create, general
Handle2T_M
T_MCreate(
   ConstHandle2ConstXYs1d XYs1d
) {
   ConstHandle2T_M handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPXYs1d>(XYs1d)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
T_MAssign(ConstHandle2T_M self, ConstHandle2ConstT_M from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
T_MDelete(ConstHandle2ConstT_M self)
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
T_MRead(ConstHandle2T_M self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
T_MWrite(ConstHandle2ConstT_M self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
T_MPrint(ConstHandle2ConstT_M self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
T_MPrintXML(ConstHandle2ConstT_M self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
T_MPrintJSON(ConstHandle2ConstT_M self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// Has
int
T_MXYs1dHas(ConstHandle2ConstT_M self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"XYs1dHas", self, extract::XYs1d);
}

// Get, const
Handle2ConstXYs1d
T_MXYs1dGetConst(ConstHandle2ConstT_M self)
{
   return detail::getField<CPP,Handle2ConstXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGetConst", self, extract::XYs1d);
}

// Get, non-const
Handle2XYs1d
T_MXYs1dGet(ConstHandle2T_M self)
{
   return detail::getField<CPP,Handle2XYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGet", self, extract::XYs1d);
}

// Set
void
T_MXYs1dSet(ConstHandle2T_M self, ConstHandle2ConstXYs1d XYs1d)
{
   detail::setField<CPP,CPPXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dSet", self, extract::XYs1d, XYs1d);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/T_M/src/custom.cpp"
