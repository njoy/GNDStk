
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/cpTransport/NuclearTerm.hpp"
#include "NuclearTerm.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = NuclearTermClass;
using CPP = multigroup::NuclearTerm;

static const std::string CLASSNAME = "NuclearTerm";

namespace extract {
   static auto XYs2d = [](auto &obj) { return &obj.XYs2d; };
   static auto regions2d = [](auto &obj) { return &obj.regions2d; };
}

using CPPXYs2d = containers::XYs2d;
using CPPRegions2d = containers::Regions2d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstNuclearTerm
NuclearTermDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2NuclearTerm
NuclearTermDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstNuclearTerm
NuclearTermCreateConst(
   ConstHandle2ConstXYs2d XYs2d,
   ConstHandle2ConstRegions2d regions2d
) {
   ConstHandle2NuclearTerm handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPXYs2d>(XYs2d),
      detail::tocpp<CPPRegions2d>(regions2d)
   );
   return handle;
}

// Create, general
Handle2NuclearTerm
NuclearTermCreate(
   ConstHandle2ConstXYs2d XYs2d,
   ConstHandle2ConstRegions2d regions2d
) {
   ConstHandle2NuclearTerm handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPXYs2d>(XYs2d),
      detail::tocpp<CPPRegions2d>(regions2d)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
NuclearTermAssign(ConstHandle2NuclearTerm This, ConstHandle2ConstNuclearTerm from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
NuclearTermDelete(ConstHandle2ConstNuclearTerm This)
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
NuclearTermRead(ConstHandle2NuclearTerm This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
NuclearTermWrite(ConstHandle2ConstNuclearTerm This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
NuclearTermPrint(ConstHandle2ConstNuclearTerm This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
NuclearTermPrintXML(ConstHandle2ConstNuclearTerm This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
NuclearTermPrintJSON(ConstHandle2ConstNuclearTerm This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: XYs2d
// -----------------------------------------------------------------------------

// Has
int
NuclearTermXYs2dHas(ConstHandle2ConstNuclearTerm This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"XYs2dHas", This, extract::XYs2d);
}

// Get, const
Handle2ConstXYs2d
NuclearTermXYs2dGetConst(ConstHandle2ConstNuclearTerm This)
{
   return detail::getField<CPP,Handle2ConstXYs2d>
      (CLASSNAME, CLASSNAME+"XYs2dGetConst", This, extract::XYs2d);
}

// Get, non-const
Handle2XYs2d
NuclearTermXYs2dGet(ConstHandle2NuclearTerm This)
{
   return detail::getField<CPP,Handle2XYs2d>
      (CLASSNAME, CLASSNAME+"XYs2dGet", This, extract::XYs2d);
}

// Set
void
NuclearTermXYs2dSet(ConstHandle2NuclearTerm This, ConstHandle2ConstXYs2d XYs2d)
{
   detail::setField<CPP,CPPXYs2d>
      (CLASSNAME, CLASSNAME+"XYs2dSet", This, extract::XYs2d, XYs2d);
}


// -----------------------------------------------------------------------------
// Child: regions2d
// -----------------------------------------------------------------------------

// Has
int
NuclearTermRegions2dHas(ConstHandle2ConstNuclearTerm This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Regions2dHas", This, extract::regions2d);
}

// Get, const
Handle2ConstRegions2d
NuclearTermRegions2dGetConst(ConstHandle2ConstNuclearTerm This)
{
   return detail::getField<CPP,Handle2ConstRegions2d>
      (CLASSNAME, CLASSNAME+"Regions2dGetConst", This, extract::regions2d);
}

// Get, non-const
Handle2Regions2d
NuclearTermRegions2dGet(ConstHandle2NuclearTerm This)
{
   return detail::getField<CPP,Handle2Regions2d>
      (CLASSNAME, CLASSNAME+"Regions2dGet", This, extract::regions2d);
}

// Set
void
NuclearTermRegions2dSet(ConstHandle2NuclearTerm This, ConstHandle2ConstRegions2d regions2d)
{
   detail::setField<CPP,CPPRegions2d>
      (CLASSNAME, CLASSNAME+"Regions2dSet", This, extract::regions2d, regions2d);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/cpTransport/NuclearTerm/src/custom.cpp"
