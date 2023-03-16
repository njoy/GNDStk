
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/Time.hpp"
#include "Time.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = TimeClass;
using CPP = multigroup::Time;

static const std::string CLASSNAME = "Time";

namespace extract {
   static auto Double = [](auto &obj) { return &obj.Double; };
   static auto string = [](auto &obj) { return &obj.string; };
}

using CPPDouble = general::Double;
using CPPString = general::String;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstTime
TimeDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Time
TimeDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstTime
TimeCreateConst(
   ConstHandle2ConstDouble Double,
   ConstHandle2ConstString string
) {
   ConstHandle2Time handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPDouble>(Double),
      detail::tocpp<CPPString>(string)
   );
   return handle;
}

// Create, general
Handle2Time
TimeCreate(
   ConstHandle2ConstDouble Double,
   ConstHandle2ConstString string
) {
   ConstHandle2Time handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPDouble>(Double),
      detail::tocpp<CPPString>(string)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
TimeAssign(ConstHandle2Time self, ConstHandle2ConstTime from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
TimeDelete(ConstHandle2ConstTime self)
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
TimeRead(ConstHandle2Time self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
TimeWrite(ConstHandle2ConstTime self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
TimePrint(ConstHandle2ConstTime self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
TimePrintXML(ConstHandle2ConstTime self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
TimePrintJSON(ConstHandle2ConstTime self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: Double
// -----------------------------------------------------------------------------

// Has
int
TimeDoubleHas(ConstHandle2ConstTime self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DoubleHas", self, extract::Double);
}

// Get, const
Handle2ConstDouble
TimeDoubleGetConst(ConstHandle2ConstTime self)
{
   return detail::getField<CPP,Handle2ConstDouble>
      (CLASSNAME, CLASSNAME+"DoubleGetConst", self, extract::Double);
}

// Get, non-const
Handle2Double
TimeDoubleGet(ConstHandle2Time self)
{
   return detail::getField<CPP,Handle2Double>
      (CLASSNAME, CLASSNAME+"DoubleGet", self, extract::Double);
}

// Set
void
TimeDoubleSet(ConstHandle2Time self, ConstHandle2ConstDouble Double)
{
   detail::setField<CPP,CPPDouble>
      (CLASSNAME, CLASSNAME+"DoubleSet", self, extract::Double, Double);
}


// -----------------------------------------------------------------------------
// Child: string
// -----------------------------------------------------------------------------

// Has
int
TimeStringHas(ConstHandle2ConstTime self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"StringHas", self, extract::string);
}

// Get, const
Handle2ConstString
TimeStringGetConst(ConstHandle2ConstTime self)
{
   return detail::getField<CPP,Handle2ConstString>
      (CLASSNAME, CLASSNAME+"StringGetConst", self, extract::string);
}

// Get, non-const
Handle2String
TimeStringGet(ConstHandle2Time self)
{
   return detail::getField<CPP,Handle2String>
      (CLASSNAME, CLASSNAME+"StringGet", self, extract::string);
}

// Set
void
TimeStringSet(ConstHandle2Time self, ConstHandle2ConstString string)
{
   detail::setField<CPP,CPPString>
      (CLASSNAME, CLASSNAME+"StringSet", self, extract::string, string);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Time/src/custom.cpp"
