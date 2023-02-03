
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/Weighted.hpp"
#include "Weighted.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = WeightedClass;
using CPP = multigroup::Weighted;

static const std::string CLASSNAME = "Weighted";

namespace extract {
   static auto XYs1d = [](auto &obj) { return &obj.XYs1d; };
   static auto evaporation = [](auto &obj) { return &obj.evaporation; };
}

using CPPXYs1d = general::XYs1d;
using CPPEvaporation = general::Evaporation;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstWeighted
WeightedDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Weighted
WeightedDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstWeighted
WeightedCreateConst(
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstEvaporation evaporation
) {
   ConstHandle2Weighted handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPXYs1d>(XYs1d),
      detail::tocpp<CPPEvaporation>(evaporation)
   );
   return handle;
}

// Create, general
Handle2Weighted
WeightedCreate(
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstEvaporation evaporation
) {
   ConstHandle2Weighted handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPXYs1d>(XYs1d),
      detail::tocpp<CPPEvaporation>(evaporation)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
WeightedAssign(ConstHandle2Weighted This, ConstHandle2ConstWeighted from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
WeightedDelete(ConstHandle2ConstWeighted This)
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
WeightedRead(ConstHandle2Weighted This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
WeightedWrite(ConstHandle2ConstWeighted This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
WeightedPrint(ConstHandle2ConstWeighted This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
WeightedPrintXML(ConstHandle2ConstWeighted This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
WeightedPrintJSON(ConstHandle2ConstWeighted This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// Has
int
WeightedXYs1dHas(ConstHandle2ConstWeighted This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"XYs1dHas", This, extract::XYs1d);
}

// Get, const
Handle2ConstXYs1d
WeightedXYs1dGetConst(ConstHandle2ConstWeighted This)
{
   return detail::getField<CPP,Handle2ConstXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGetConst", This, extract::XYs1d);
}

// Get, non-const
Handle2XYs1d
WeightedXYs1dGet(ConstHandle2Weighted This)
{
   return detail::getField<CPP,Handle2XYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGet", This, extract::XYs1d);
}

// Set
void
WeightedXYs1dSet(ConstHandle2Weighted This, ConstHandle2ConstXYs1d XYs1d)
{
   detail::setField<CPP,CPPXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dSet", This, extract::XYs1d, XYs1d);
}


// -----------------------------------------------------------------------------
// Child: evaporation
// -----------------------------------------------------------------------------

// Has
int
WeightedEvaporationHas(ConstHandle2ConstWeighted This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EvaporationHas", This, extract::evaporation);
}

// Get, const
Handle2ConstEvaporation
WeightedEvaporationGetConst(ConstHandle2ConstWeighted This)
{
   return detail::getField<CPP,Handle2ConstEvaporation>
      (CLASSNAME, CLASSNAME+"EvaporationGetConst", This, extract::evaporation);
}

// Get, non-const
Handle2Evaporation
WeightedEvaporationGet(ConstHandle2Weighted This)
{
   return detail::getField<CPP,Handle2Evaporation>
      (CLASSNAME, CLASSNAME+"EvaporationGet", This, extract::evaporation);
}

// Set
void
WeightedEvaporationSet(ConstHandle2Weighted This, ConstHandle2ConstEvaporation evaporation)
{
   detail::setField<CPP,CPPEvaporation>
      (CLASSNAME, CLASSNAME+"EvaporationSet", This, extract::evaporation, evaporation);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Weighted/src/custom.cpp"
