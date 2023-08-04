
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/Halflife.hpp"
#include "Halflife.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = HalflifeClass;
using CPP = multigroup::Halflife;

static const std::string CLASSNAME = "Halflife";

namespace extract {
   static auto string = [](auto &obj) { return &obj.string; };
   static auto Double = [](auto &obj) { return &obj.Double; };
}

using CPPString = general::String;
using CPPDouble = general::Double;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstHalflife
HalflifeDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Halflife
HalflifeDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstHalflife
HalflifeCreateConst(
   ConstHandle2ConstString string,
   ConstHandle2ConstDouble Double
) {
   ConstHandle2Halflife handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPString>(string),
      detail::tocpp<CPPDouble>(Double)
   );
   return handle;
}

// Create, general
Handle2Halflife
HalflifeCreate(
   ConstHandle2ConstString string,
   ConstHandle2ConstDouble Double
) {
   ConstHandle2Halflife handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPString>(string),
      detail::tocpp<CPPDouble>(Double)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
HalflifeAssign(ConstHandle2Halflife self, ConstHandle2ConstHalflife from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
HalflifeDelete(ConstHandle2ConstHalflife self)
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
HalflifeRead(ConstHandle2Halflife self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
HalflifeWrite(ConstHandle2ConstHalflife self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
HalflifePrint(ConstHandle2ConstHalflife self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
HalflifePrintXML(ConstHandle2ConstHalflife self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
HalflifePrintJSON(ConstHandle2ConstHalflife self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: string
// -----------------------------------------------------------------------------

// Has
int
HalflifeStringHas(ConstHandle2ConstHalflife self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"StringHas", self, extract::string);
}

// Get, const
Handle2ConstString
HalflifeStringGetConst(ConstHandle2ConstHalflife self)
{
   return detail::getField<CPP,Handle2ConstString>
      (CLASSNAME, CLASSNAME+"StringGetConst", self, extract::string);
}

// Get, non-const
Handle2String
HalflifeStringGet(ConstHandle2Halflife self)
{
   return detail::getField<CPP,Handle2String>
      (CLASSNAME, CLASSNAME+"StringGet", self, extract::string);
}

// Set
void
HalflifeStringSet(ConstHandle2Halflife self, ConstHandle2ConstString string)
{
   detail::setField<CPP,CPPString>
      (CLASSNAME, CLASSNAME+"StringSet", self, extract::string, string);
}


// -----------------------------------------------------------------------------
// Child: Double
// -----------------------------------------------------------------------------

// Has
int
HalflifeDoubleHas(ConstHandle2ConstHalflife self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DoubleHas", self, extract::Double);
}

// Get, const
Handle2ConstDouble
HalflifeDoubleGetConst(ConstHandle2ConstHalflife self)
{
   return detail::getField<CPP,Handle2ConstDouble>
      (CLASSNAME, CLASSNAME+"DoubleGetConst", self, extract::Double);
}

// Get, non-const
Handle2Double
HalflifeDoubleGet(ConstHandle2Halflife self)
{
   return detail::getField<CPP,Handle2Double>
      (CLASSNAME, CLASSNAME+"DoubleGet", self, extract::Double);
}

// Set
void
HalflifeDoubleSet(ConstHandle2Halflife self, ConstHandle2ConstDouble Double)
{
   detail::setField<CPP,CPPDouble>
      (CLASSNAME, CLASSNAME+"DoubleSet", self, extract::Double, Double);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Halflife/src/custom.cpp"