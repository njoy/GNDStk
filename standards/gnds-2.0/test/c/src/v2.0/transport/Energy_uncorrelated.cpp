
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2.0/transport/Energy_uncorrelated.hpp"
#include "Energy_uncorrelated.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = Energy_uncorrelatedClass;
using CPP = multigroup::Energy_uncorrelated;

static const std::string CLASSNAME = "Energy_uncorrelated";

namespace extract {
   static auto XYs2d = [](auto &obj) { return &obj.XYs2d; };
   static auto regions2d = [](auto &obj) { return &obj.regions2d; };
   static auto generalEvaporation = [](auto &obj) { return &obj.generalEvaporation; };
   static auto discreteGamma = [](auto &obj) { return &obj.discreteGamma; };
   static auto primaryGamma = [](auto &obj) { return &obj.primaryGamma; };
   static auto NBodyPhaseSpace = [](auto &obj) { return &obj.NBodyPhaseSpace; };
   static auto evaporation = [](auto &obj) { return &obj.evaporation; };
   static auto weightedFunctionals = [](auto &obj) { return &obj.weightedFunctionals; };
   static auto simpleMaxwellianFission = [](auto &obj) { return &obj.simpleMaxwellianFission; };
   static auto Watt = [](auto &obj) { return &obj.Watt; };
   static auto MadlandNix = [](auto &obj) { return &obj.MadlandNix; };
}

using CPPXYs2d = containers::XYs2d;
using CPPRegions2d = containers::Regions2d;
using CPPGeneralEvaporation = transport::GeneralEvaporation;
using CPPDiscreteGamma = transport::DiscreteGamma;
using CPPPrimaryGamma = transport::PrimaryGamma;
using CPPNBodyPhaseSpace = transport::NBodyPhaseSpace;
using CPPEvaporation = transport::Evaporation;
using CPPWeightedFunctionals = transport::WeightedFunctionals;
using CPPSimpleMaxwellianFission = fissionTransport::SimpleMaxwellianFission;
using CPPWatt = fissionTransport::Watt;
using CPPMadlandNix = fissionTransport::MadlandNix;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstEnergy_uncorrelated
Energy_uncorrelatedDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Energy_uncorrelated
Energy_uncorrelatedDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstEnergy_uncorrelated
Energy_uncorrelatedCreateConst(
   ConstHandle2ConstXYs2d XYs2d,
   ConstHandle2ConstRegions2d regions2d,
   ConstHandle2ConstGeneralEvaporation generalEvaporation,
   ConstHandle2ConstDiscreteGamma discreteGamma,
   ConstHandle2ConstPrimaryGamma primaryGamma,
   ConstHandle2ConstNBodyPhaseSpace NBodyPhaseSpace,
   ConstHandle2ConstEvaporation evaporation,
   ConstHandle2ConstWeightedFunctionals weightedFunctionals,
   ConstHandle2ConstSimpleMaxwellianFission simpleMaxwellianFission,
   ConstHandle2ConstWatt Watt,
   ConstHandle2ConstMadlandNix MadlandNix
) {
   ConstHandle2Energy_uncorrelated handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPXYs2d>(XYs2d),
      detail::tocpp<CPPRegions2d>(regions2d),
      detail::tocpp<CPPGeneralEvaporation>(generalEvaporation),
      detail::tocpp<CPPDiscreteGamma>(discreteGamma),
      detail::tocpp<CPPPrimaryGamma>(primaryGamma),
      detail::tocpp<CPPNBodyPhaseSpace>(NBodyPhaseSpace),
      detail::tocpp<CPPEvaporation>(evaporation),
      detail::tocpp<CPPWeightedFunctionals>(weightedFunctionals),
      detail::tocpp<CPPSimpleMaxwellianFission>(simpleMaxwellianFission),
      detail::tocpp<CPPWatt>(Watt),
      detail::tocpp<CPPMadlandNix>(MadlandNix)
   );
   return handle;
}

// Create, general
Handle2Energy_uncorrelated
Energy_uncorrelatedCreate(
   ConstHandle2ConstXYs2d XYs2d,
   ConstHandle2ConstRegions2d regions2d,
   ConstHandle2ConstGeneralEvaporation generalEvaporation,
   ConstHandle2ConstDiscreteGamma discreteGamma,
   ConstHandle2ConstPrimaryGamma primaryGamma,
   ConstHandle2ConstNBodyPhaseSpace NBodyPhaseSpace,
   ConstHandle2ConstEvaporation evaporation,
   ConstHandle2ConstWeightedFunctionals weightedFunctionals,
   ConstHandle2ConstSimpleMaxwellianFission simpleMaxwellianFission,
   ConstHandle2ConstWatt Watt,
   ConstHandle2ConstMadlandNix MadlandNix
) {
   ConstHandle2Energy_uncorrelated handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPXYs2d>(XYs2d),
      detail::tocpp<CPPRegions2d>(regions2d),
      detail::tocpp<CPPGeneralEvaporation>(generalEvaporation),
      detail::tocpp<CPPDiscreteGamma>(discreteGamma),
      detail::tocpp<CPPPrimaryGamma>(primaryGamma),
      detail::tocpp<CPPNBodyPhaseSpace>(NBodyPhaseSpace),
      detail::tocpp<CPPEvaporation>(evaporation),
      detail::tocpp<CPPWeightedFunctionals>(weightedFunctionals),
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
Energy_uncorrelatedAssign(ConstHandle2Energy_uncorrelated self, ConstHandle2ConstEnergy_uncorrelated from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
Energy_uncorrelatedDelete(ConstHandle2ConstEnergy_uncorrelated self)
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
Energy_uncorrelatedRead(ConstHandle2Energy_uncorrelated self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
Energy_uncorrelatedWrite(ConstHandle2ConstEnergy_uncorrelated self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
Energy_uncorrelatedPrint(ConstHandle2ConstEnergy_uncorrelated self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
Energy_uncorrelatedPrintXML(ConstHandle2ConstEnergy_uncorrelated self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
Energy_uncorrelatedPrintJSON(ConstHandle2ConstEnergy_uncorrelated self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: XYs2d
// -----------------------------------------------------------------------------

// Has
int
Energy_uncorrelatedXYs2dHas(ConstHandle2ConstEnergy_uncorrelated self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"XYs2dHas", self, extract::XYs2d);
}

// Get, const
Handle2ConstXYs2d
Energy_uncorrelatedXYs2dGetConst(ConstHandle2ConstEnergy_uncorrelated self)
{
   return detail::getField<CPP,Handle2ConstXYs2d>
      (CLASSNAME, CLASSNAME+"XYs2dGetConst", self, extract::XYs2d);
}

// Get, non-const
Handle2XYs2d
Energy_uncorrelatedXYs2dGet(ConstHandle2Energy_uncorrelated self)
{
   return detail::getField<CPP,Handle2XYs2d>
      (CLASSNAME, CLASSNAME+"XYs2dGet", self, extract::XYs2d);
}

// Set
void
Energy_uncorrelatedXYs2dSet(ConstHandle2Energy_uncorrelated self, ConstHandle2ConstXYs2d XYs2d)
{
   detail::setField<CPP,CPPXYs2d>
      (CLASSNAME, CLASSNAME+"XYs2dSet", self, extract::XYs2d, XYs2d);
}


// -----------------------------------------------------------------------------
// Child: regions2d
// -----------------------------------------------------------------------------

// Has
int
Energy_uncorrelatedRegions2dHas(ConstHandle2ConstEnergy_uncorrelated self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Regions2dHas", self, extract::regions2d);
}

// Get, const
Handle2ConstRegions2d
Energy_uncorrelatedRegions2dGetConst(ConstHandle2ConstEnergy_uncorrelated self)
{
   return detail::getField<CPP,Handle2ConstRegions2d>
      (CLASSNAME, CLASSNAME+"Regions2dGetConst", self, extract::regions2d);
}

// Get, non-const
Handle2Regions2d
Energy_uncorrelatedRegions2dGet(ConstHandle2Energy_uncorrelated self)
{
   return detail::getField<CPP,Handle2Regions2d>
      (CLASSNAME, CLASSNAME+"Regions2dGet", self, extract::regions2d);
}

// Set
void
Energy_uncorrelatedRegions2dSet(ConstHandle2Energy_uncorrelated self, ConstHandle2ConstRegions2d regions2d)
{
   detail::setField<CPP,CPPRegions2d>
      (CLASSNAME, CLASSNAME+"Regions2dSet", self, extract::regions2d, regions2d);
}


// -----------------------------------------------------------------------------
// Child: generalEvaporation
// -----------------------------------------------------------------------------

// Has
int
Energy_uncorrelatedGeneralEvaporationHas(ConstHandle2ConstEnergy_uncorrelated self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"GeneralEvaporationHas", self, extract::generalEvaporation);
}

// Get, const
Handle2ConstGeneralEvaporation
Energy_uncorrelatedGeneralEvaporationGetConst(ConstHandle2ConstEnergy_uncorrelated self)
{
   return detail::getField<CPP,Handle2ConstGeneralEvaporation>
      (CLASSNAME, CLASSNAME+"GeneralEvaporationGetConst", self, extract::generalEvaporation);
}

// Get, non-const
Handle2GeneralEvaporation
Energy_uncorrelatedGeneralEvaporationGet(ConstHandle2Energy_uncorrelated self)
{
   return detail::getField<CPP,Handle2GeneralEvaporation>
      (CLASSNAME, CLASSNAME+"GeneralEvaporationGet", self, extract::generalEvaporation);
}

// Set
void
Energy_uncorrelatedGeneralEvaporationSet(ConstHandle2Energy_uncorrelated self, ConstHandle2ConstGeneralEvaporation generalEvaporation)
{
   detail::setField<CPP,CPPGeneralEvaporation>
      (CLASSNAME, CLASSNAME+"GeneralEvaporationSet", self, extract::generalEvaporation, generalEvaporation);
}


// -----------------------------------------------------------------------------
// Child: discreteGamma
// -----------------------------------------------------------------------------

// Has
int
Energy_uncorrelatedDiscreteGammaHas(ConstHandle2ConstEnergy_uncorrelated self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DiscreteGammaHas", self, extract::discreteGamma);
}

// Get, const
Handle2ConstDiscreteGamma
Energy_uncorrelatedDiscreteGammaGetConst(ConstHandle2ConstEnergy_uncorrelated self)
{
   return detail::getField<CPP,Handle2ConstDiscreteGamma>
      (CLASSNAME, CLASSNAME+"DiscreteGammaGetConst", self, extract::discreteGamma);
}

// Get, non-const
Handle2DiscreteGamma
Energy_uncorrelatedDiscreteGammaGet(ConstHandle2Energy_uncorrelated self)
{
   return detail::getField<CPP,Handle2DiscreteGamma>
      (CLASSNAME, CLASSNAME+"DiscreteGammaGet", self, extract::discreteGamma);
}

// Set
void
Energy_uncorrelatedDiscreteGammaSet(ConstHandle2Energy_uncorrelated self, ConstHandle2ConstDiscreteGamma discreteGamma)
{
   detail::setField<CPP,CPPDiscreteGamma>
      (CLASSNAME, CLASSNAME+"DiscreteGammaSet", self, extract::discreteGamma, discreteGamma);
}


// -----------------------------------------------------------------------------
// Child: primaryGamma
// -----------------------------------------------------------------------------

// Has
int
Energy_uncorrelatedPrimaryGammaHas(ConstHandle2ConstEnergy_uncorrelated self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"PrimaryGammaHas", self, extract::primaryGamma);
}

// Get, const
Handle2ConstPrimaryGamma
Energy_uncorrelatedPrimaryGammaGetConst(ConstHandle2ConstEnergy_uncorrelated self)
{
   return detail::getField<CPP,Handle2ConstPrimaryGamma>
      (CLASSNAME, CLASSNAME+"PrimaryGammaGetConst", self, extract::primaryGamma);
}

// Get, non-const
Handle2PrimaryGamma
Energy_uncorrelatedPrimaryGammaGet(ConstHandle2Energy_uncorrelated self)
{
   return detail::getField<CPP,Handle2PrimaryGamma>
      (CLASSNAME, CLASSNAME+"PrimaryGammaGet", self, extract::primaryGamma);
}

// Set
void
Energy_uncorrelatedPrimaryGammaSet(ConstHandle2Energy_uncorrelated self, ConstHandle2ConstPrimaryGamma primaryGamma)
{
   detail::setField<CPP,CPPPrimaryGamma>
      (CLASSNAME, CLASSNAME+"PrimaryGammaSet", self, extract::primaryGamma, primaryGamma);
}


// -----------------------------------------------------------------------------
// Child: NBodyPhaseSpace
// -----------------------------------------------------------------------------

// Has
int
Energy_uncorrelatedNBodyPhaseSpaceHas(ConstHandle2ConstEnergy_uncorrelated self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"NBodyPhaseSpaceHas", self, extract::NBodyPhaseSpace);
}

// Get, const
Handle2ConstNBodyPhaseSpace
Energy_uncorrelatedNBodyPhaseSpaceGetConst(ConstHandle2ConstEnergy_uncorrelated self)
{
   return detail::getField<CPP,Handle2ConstNBodyPhaseSpace>
      (CLASSNAME, CLASSNAME+"NBodyPhaseSpaceGetConst", self, extract::NBodyPhaseSpace);
}

// Get, non-const
Handle2NBodyPhaseSpace
Energy_uncorrelatedNBodyPhaseSpaceGet(ConstHandle2Energy_uncorrelated self)
{
   return detail::getField<CPP,Handle2NBodyPhaseSpace>
      (CLASSNAME, CLASSNAME+"NBodyPhaseSpaceGet", self, extract::NBodyPhaseSpace);
}

// Set
void
Energy_uncorrelatedNBodyPhaseSpaceSet(ConstHandle2Energy_uncorrelated self, ConstHandle2ConstNBodyPhaseSpace NBodyPhaseSpace)
{
   detail::setField<CPP,CPPNBodyPhaseSpace>
      (CLASSNAME, CLASSNAME+"NBodyPhaseSpaceSet", self, extract::NBodyPhaseSpace, NBodyPhaseSpace);
}


// -----------------------------------------------------------------------------
// Child: evaporation
// -----------------------------------------------------------------------------

// Has
int
Energy_uncorrelatedEvaporationHas(ConstHandle2ConstEnergy_uncorrelated self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EvaporationHas", self, extract::evaporation);
}

// Get, const
Handle2ConstEvaporation
Energy_uncorrelatedEvaporationGetConst(ConstHandle2ConstEnergy_uncorrelated self)
{
   return detail::getField<CPP,Handle2ConstEvaporation>
      (CLASSNAME, CLASSNAME+"EvaporationGetConst", self, extract::evaporation);
}

// Get, non-const
Handle2Evaporation
Energy_uncorrelatedEvaporationGet(ConstHandle2Energy_uncorrelated self)
{
   return detail::getField<CPP,Handle2Evaporation>
      (CLASSNAME, CLASSNAME+"EvaporationGet", self, extract::evaporation);
}

// Set
void
Energy_uncorrelatedEvaporationSet(ConstHandle2Energy_uncorrelated self, ConstHandle2ConstEvaporation evaporation)
{
   detail::setField<CPP,CPPEvaporation>
      (CLASSNAME, CLASSNAME+"EvaporationSet", self, extract::evaporation, evaporation);
}


// -----------------------------------------------------------------------------
// Child: weightedFunctionals
// -----------------------------------------------------------------------------

// Has
int
Energy_uncorrelatedWeightedFunctionalsHas(ConstHandle2ConstEnergy_uncorrelated self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"WeightedFunctionalsHas", self, extract::weightedFunctionals);
}

// Get, const
Handle2ConstWeightedFunctionals
Energy_uncorrelatedWeightedFunctionalsGetConst(ConstHandle2ConstEnergy_uncorrelated self)
{
   return detail::getField<CPP,Handle2ConstWeightedFunctionals>
      (CLASSNAME, CLASSNAME+"WeightedFunctionalsGetConst", self, extract::weightedFunctionals);
}

// Get, non-const
Handle2WeightedFunctionals
Energy_uncorrelatedWeightedFunctionalsGet(ConstHandle2Energy_uncorrelated self)
{
   return detail::getField<CPP,Handle2WeightedFunctionals>
      (CLASSNAME, CLASSNAME+"WeightedFunctionalsGet", self, extract::weightedFunctionals);
}

// Set
void
Energy_uncorrelatedWeightedFunctionalsSet(ConstHandle2Energy_uncorrelated self, ConstHandle2ConstWeightedFunctionals weightedFunctionals)
{
   detail::setField<CPP,CPPWeightedFunctionals>
      (CLASSNAME, CLASSNAME+"WeightedFunctionalsSet", self, extract::weightedFunctionals, weightedFunctionals);
}


// -----------------------------------------------------------------------------
// Child: simpleMaxwellianFission
// -----------------------------------------------------------------------------

// Has
int
Energy_uncorrelatedSimpleMaxwellianFissionHas(ConstHandle2ConstEnergy_uncorrelated self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SimpleMaxwellianFissionHas", self, extract::simpleMaxwellianFission);
}

// Get, const
Handle2ConstSimpleMaxwellianFission
Energy_uncorrelatedSimpleMaxwellianFissionGetConst(ConstHandle2ConstEnergy_uncorrelated self)
{
   return detail::getField<CPP,Handle2ConstSimpleMaxwellianFission>
      (CLASSNAME, CLASSNAME+"SimpleMaxwellianFissionGetConst", self, extract::simpleMaxwellianFission);
}

// Get, non-const
Handle2SimpleMaxwellianFission
Energy_uncorrelatedSimpleMaxwellianFissionGet(ConstHandle2Energy_uncorrelated self)
{
   return detail::getField<CPP,Handle2SimpleMaxwellianFission>
      (CLASSNAME, CLASSNAME+"SimpleMaxwellianFissionGet", self, extract::simpleMaxwellianFission);
}

// Set
void
Energy_uncorrelatedSimpleMaxwellianFissionSet(ConstHandle2Energy_uncorrelated self, ConstHandle2ConstSimpleMaxwellianFission simpleMaxwellianFission)
{
   detail::setField<CPP,CPPSimpleMaxwellianFission>
      (CLASSNAME, CLASSNAME+"SimpleMaxwellianFissionSet", self, extract::simpleMaxwellianFission, simpleMaxwellianFission);
}


// -----------------------------------------------------------------------------
// Child: Watt
// -----------------------------------------------------------------------------

// Has
int
Energy_uncorrelatedWattHas(ConstHandle2ConstEnergy_uncorrelated self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"WattHas", self, extract::Watt);
}

// Get, const
Handle2ConstWatt
Energy_uncorrelatedWattGetConst(ConstHandle2ConstEnergy_uncorrelated self)
{
   return detail::getField<CPP,Handle2ConstWatt>
      (CLASSNAME, CLASSNAME+"WattGetConst", self, extract::Watt);
}

// Get, non-const
Handle2Watt
Energy_uncorrelatedWattGet(ConstHandle2Energy_uncorrelated self)
{
   return detail::getField<CPP,Handle2Watt>
      (CLASSNAME, CLASSNAME+"WattGet", self, extract::Watt);
}

// Set
void
Energy_uncorrelatedWattSet(ConstHandle2Energy_uncorrelated self, ConstHandle2ConstWatt Watt)
{
   detail::setField<CPP,CPPWatt>
      (CLASSNAME, CLASSNAME+"WattSet", self, extract::Watt, Watt);
}


// -----------------------------------------------------------------------------
// Child: MadlandNix
// -----------------------------------------------------------------------------

// Has
int
Energy_uncorrelatedMadlandNixHas(ConstHandle2ConstEnergy_uncorrelated self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"MadlandNixHas", self, extract::MadlandNix);
}

// Get, const
Handle2ConstMadlandNix
Energy_uncorrelatedMadlandNixGetConst(ConstHandle2ConstEnergy_uncorrelated self)
{
   return detail::getField<CPP,Handle2ConstMadlandNix>
      (CLASSNAME, CLASSNAME+"MadlandNixGetConst", self, extract::MadlandNix);
}

// Get, non-const
Handle2MadlandNix
Energy_uncorrelatedMadlandNixGet(ConstHandle2Energy_uncorrelated self)
{
   return detail::getField<CPP,Handle2MadlandNix>
      (CLASSNAME, CLASSNAME+"MadlandNixGet", self, extract::MadlandNix);
}

// Set
void
Energy_uncorrelatedMadlandNixSet(ConstHandle2Energy_uncorrelated self, ConstHandle2ConstMadlandNix MadlandNix)
{
   detail::setField<CPP,CPPMadlandNix>
      (CLASSNAME, CLASSNAME+"MadlandNixSet", self, extract::MadlandNix, MadlandNix);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/transport/Energy_uncorrelated/src/custom.cpp"
