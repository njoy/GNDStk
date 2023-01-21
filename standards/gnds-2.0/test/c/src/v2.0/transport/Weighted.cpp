
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/transport/Weighted.hpp"
#include "Weighted.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = WeightedClass;
using CPP = multigroup::Weighted;

static const std::string CLASSNAME = "Weighted";

namespace extract {
   static auto XYs1d = [](auto &obj) { return &obj.XYs1d; };
   static auto XYs2d = [](auto &obj) { return &obj.XYs2d; };
   static auto evaporation = [](auto &obj) { return &obj.evaporation; };
   static auto generalEvaporation = [](auto &obj) { return &obj.generalEvaporation; };
   static auto simpleMaxwellianFission = [](auto &obj) { return &obj.simpleMaxwellianFission; };
   static auto Watt = [](auto &obj) { return &obj.Watt; };
   static auto MadlandNix = [](auto &obj) { return &obj.MadlandNix; };
}

using CPPXYs1d = containers::XYs1d;
using CPPXYs2d = containers::XYs2d;
using CPPEvaporation = transport::Evaporation;
using CPPGeneralEvaporation = transport::GeneralEvaporation;
using CPPSimpleMaxwellianFission = fissionTransport::SimpleMaxwellianFission;
using CPPWatt = fissionTransport::Watt;
using CPPMadlandNix = fissionTransport::MadlandNix;


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
   ConstHandle2ConstXYs2d XYs2d,
   ConstHandle2ConstEvaporation evaporation,
   ConstHandle2ConstGeneralEvaporation generalEvaporation,
   ConstHandle2ConstSimpleMaxwellianFission simpleMaxwellianFission,
   ConstHandle2ConstWatt Watt,
   ConstHandle2ConstMadlandNix MadlandNix
) {
   ConstHandle2Weighted handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPXYs1d>(XYs1d),
      detail::tocpp<CPPXYs2d>(XYs2d),
      detail::tocpp<CPPEvaporation>(evaporation),
      detail::tocpp<CPPGeneralEvaporation>(generalEvaporation),
      detail::tocpp<CPPSimpleMaxwellianFission>(simpleMaxwellianFission),
      detail::tocpp<CPPWatt>(Watt),
      detail::tocpp<CPPMadlandNix>(MadlandNix)
   );
   return handle;
}

// Create, general
Handle2Weighted
WeightedCreate(
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstXYs2d XYs2d,
   ConstHandle2ConstEvaporation evaporation,
   ConstHandle2ConstGeneralEvaporation generalEvaporation,
   ConstHandle2ConstSimpleMaxwellianFission simpleMaxwellianFission,
   ConstHandle2ConstWatt Watt,
   ConstHandle2ConstMadlandNix MadlandNix
) {
   ConstHandle2Weighted handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPXYs1d>(XYs1d),
      detail::tocpp<CPPXYs2d>(XYs2d),
      detail::tocpp<CPPEvaporation>(evaporation),
      detail::tocpp<CPPGeneralEvaporation>(generalEvaporation),
      detail::tocpp<CPPSimpleMaxwellianFission>(simpleMaxwellianFission),
      detail::tocpp<CPPWatt>(Watt),
      detail::tocpp<CPPMadlandNix>(MadlandNix)
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
// Child: XYs2d
// -----------------------------------------------------------------------------

// Has
int
WeightedXYs2dHas(ConstHandle2ConstWeighted This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"XYs2dHas", This, extract::XYs2d);
}

// Get, const
Handle2ConstXYs2d
WeightedXYs2dGetConst(ConstHandle2ConstWeighted This)
{
   return detail::getField<CPP,Handle2ConstXYs2d>
      (CLASSNAME, CLASSNAME+"XYs2dGetConst", This, extract::XYs2d);
}

// Get, non-const
Handle2XYs2d
WeightedXYs2dGet(ConstHandle2Weighted This)
{
   return detail::getField<CPP,Handle2XYs2d>
      (CLASSNAME, CLASSNAME+"XYs2dGet", This, extract::XYs2d);
}

// Set
void
WeightedXYs2dSet(ConstHandle2Weighted This, ConstHandle2ConstXYs2d XYs2d)
{
   detail::setField<CPP,CPPXYs2d>
      (CLASSNAME, CLASSNAME+"XYs2dSet", This, extract::XYs2d, XYs2d);
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
// Child: generalEvaporation
// -----------------------------------------------------------------------------

// Has
int
WeightedGeneralEvaporationHas(ConstHandle2ConstWeighted This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"GeneralEvaporationHas", This, extract::generalEvaporation);
}

// Get, const
Handle2ConstGeneralEvaporation
WeightedGeneralEvaporationGetConst(ConstHandle2ConstWeighted This)
{
   return detail::getField<CPP,Handle2ConstGeneralEvaporation>
      (CLASSNAME, CLASSNAME+"GeneralEvaporationGetConst", This, extract::generalEvaporation);
}

// Get, non-const
Handle2GeneralEvaporation
WeightedGeneralEvaporationGet(ConstHandle2Weighted This)
{
   return detail::getField<CPP,Handle2GeneralEvaporation>
      (CLASSNAME, CLASSNAME+"GeneralEvaporationGet", This, extract::generalEvaporation);
}

// Set
void
WeightedGeneralEvaporationSet(ConstHandle2Weighted This, ConstHandle2ConstGeneralEvaporation generalEvaporation)
{
   detail::setField<CPP,CPPGeneralEvaporation>
      (CLASSNAME, CLASSNAME+"GeneralEvaporationSet", This, extract::generalEvaporation, generalEvaporation);
}


// -----------------------------------------------------------------------------
// Child: simpleMaxwellianFission
// -----------------------------------------------------------------------------

// Has
int
WeightedSimpleMaxwellianFissionHas(ConstHandle2ConstWeighted This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SimpleMaxwellianFissionHas", This, extract::simpleMaxwellianFission);
}

// Get, const
Handle2ConstSimpleMaxwellianFission
WeightedSimpleMaxwellianFissionGetConst(ConstHandle2ConstWeighted This)
{
   return detail::getField<CPP,Handle2ConstSimpleMaxwellianFission>
      (CLASSNAME, CLASSNAME+"SimpleMaxwellianFissionGetConst", This, extract::simpleMaxwellianFission);
}

// Get, non-const
Handle2SimpleMaxwellianFission
WeightedSimpleMaxwellianFissionGet(ConstHandle2Weighted This)
{
   return detail::getField<CPP,Handle2SimpleMaxwellianFission>
      (CLASSNAME, CLASSNAME+"SimpleMaxwellianFissionGet", This, extract::simpleMaxwellianFission);
}

// Set
void
WeightedSimpleMaxwellianFissionSet(ConstHandle2Weighted This, ConstHandle2ConstSimpleMaxwellianFission simpleMaxwellianFission)
{
   detail::setField<CPP,CPPSimpleMaxwellianFission>
      (CLASSNAME, CLASSNAME+"SimpleMaxwellianFissionSet", This, extract::simpleMaxwellianFission, simpleMaxwellianFission);
}


// -----------------------------------------------------------------------------
// Child: Watt
// -----------------------------------------------------------------------------

// Has
int
WeightedWattHas(ConstHandle2ConstWeighted This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"WattHas", This, extract::Watt);
}

// Get, const
Handle2ConstWatt
WeightedWattGetConst(ConstHandle2ConstWeighted This)
{
   return detail::getField<CPP,Handle2ConstWatt>
      (CLASSNAME, CLASSNAME+"WattGetConst", This, extract::Watt);
}

// Get, non-const
Handle2Watt
WeightedWattGet(ConstHandle2Weighted This)
{
   return detail::getField<CPP,Handle2Watt>
      (CLASSNAME, CLASSNAME+"WattGet", This, extract::Watt);
}

// Set
void
WeightedWattSet(ConstHandle2Weighted This, ConstHandle2ConstWatt Watt)
{
   detail::setField<CPP,CPPWatt>
      (CLASSNAME, CLASSNAME+"WattSet", This, extract::Watt, Watt);
}


// -----------------------------------------------------------------------------
// Child: MadlandNix
// -----------------------------------------------------------------------------

// Has
int
WeightedMadlandNixHas(ConstHandle2ConstWeighted This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"MadlandNixHas", This, extract::MadlandNix);
}

// Get, const
Handle2ConstMadlandNix
WeightedMadlandNixGetConst(ConstHandle2ConstWeighted This)
{
   return detail::getField<CPP,Handle2ConstMadlandNix>
      (CLASSNAME, CLASSNAME+"MadlandNixGetConst", This, extract::MadlandNix);
}

// Get, non-const
Handle2MadlandNix
WeightedMadlandNixGet(ConstHandle2Weighted This)
{
   return detail::getField<CPP,Handle2MadlandNix>
      (CLASSNAME, CLASSNAME+"MadlandNixGet", This, extract::MadlandNix);
}

// Set
void
WeightedMadlandNixSet(ConstHandle2Weighted This, ConstHandle2ConstMadlandNix MadlandNix)
{
   detail::setField<CPP,CPPMadlandNix>
      (CLASSNAME, CLASSNAME+"MadlandNixSet", This, extract::MadlandNix, MadlandNix);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/transport/Weighted/src/custom.cpp"
