
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/Nuclide.hpp"
#include "Nuclide.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = NuclideClass;
using CPP = multigroup::Nuclide;

static const std::string CLASSNAME = "Nuclide";

namespace extract {
   static auto id = [](auto &obj) { return &obj.id; };
   static auto mass = [](auto &obj) { return &obj.mass; };
   static auto charge = [](auto &obj) { return &obj.charge; };
   static auto nucleus = [](auto &obj) { return &obj.nucleus; };
   static auto decayData = [](auto &obj) { return &obj.decayData; };
   static auto fissionFragmentData = [](auto &obj) { return &obj.fissionFragmentData; };
}

using CPPMass = general::Mass;
using CPPCharge = general::Charge;
using CPPNucleus = general::Nucleus;
using CPPDecayData = general::DecayData;
using CPPFissionFragmentData = top::FissionFragmentData;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstNuclide
NuclideDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Nuclide
NuclideDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstNuclide
NuclideCreateConst(
   const char *const id,
   ConstHandle2ConstMass mass,
   ConstHandle2ConstCharge charge,
   ConstHandle2ConstNucleus nucleus,
   ConstHandle2ConstDecayData decayData,
   ConstHandle2ConstFissionFragmentData fissionFragmentData
) {
   ConstHandle2Nuclide handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      id,
      detail::tocpp<CPPMass>(mass),
      detail::tocpp<CPPCharge>(charge),
      detail::tocpp<CPPNucleus>(nucleus),
      detail::tocpp<CPPDecayData>(decayData),
      detail::tocpp<CPPFissionFragmentData>(fissionFragmentData)
   );
   return handle;
}

// Create, general
Handle2Nuclide
NuclideCreate(
   const char *const id,
   ConstHandle2ConstMass mass,
   ConstHandle2ConstCharge charge,
   ConstHandle2ConstNucleus nucleus,
   ConstHandle2ConstDecayData decayData,
   ConstHandle2ConstFissionFragmentData fissionFragmentData
) {
   ConstHandle2Nuclide handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      id,
      detail::tocpp<CPPMass>(mass),
      detail::tocpp<CPPCharge>(charge),
      detail::tocpp<CPPNucleus>(nucleus),
      detail::tocpp<CPPDecayData>(decayData),
      detail::tocpp<CPPFissionFragmentData>(fissionFragmentData)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
NuclideAssign(ConstHandle2Nuclide self, ConstHandle2ConstNuclide from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
NuclideDelete(ConstHandle2ConstNuclide self)
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
NuclideRead(ConstHandle2Nuclide self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
NuclideWrite(ConstHandle2ConstNuclide self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
NuclidePrint(ConstHandle2ConstNuclide self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
NuclidePrintXML(ConstHandle2ConstNuclide self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
NuclidePrintJSON(ConstHandle2ConstNuclide self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: id
// -----------------------------------------------------------------------------

// Has
int
NuclideIdHas(ConstHandle2ConstNuclide self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"IdHas", self, extract::id);
}

// Get
// Returns by value
const char *
NuclideIdGet(ConstHandle2ConstNuclide self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"IdGet", self, extract::id);
}

// Set
void
NuclideIdSet(ConstHandle2Nuclide self, const char *const id)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"IdSet", self, extract::id, id);
}


// -----------------------------------------------------------------------------
// Child: mass
// -----------------------------------------------------------------------------

// Has
int
NuclideMassHas(ConstHandle2ConstNuclide self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"MassHas", self, extract::mass);
}

// Get, const
Handle2ConstMass
NuclideMassGetConst(ConstHandle2ConstNuclide self)
{
   return detail::getField<CPP,Handle2ConstMass>
      (CLASSNAME, CLASSNAME+"MassGetConst", self, extract::mass);
}

// Get, non-const
Handle2Mass
NuclideMassGet(ConstHandle2Nuclide self)
{
   return detail::getField<CPP,Handle2Mass>
      (CLASSNAME, CLASSNAME+"MassGet", self, extract::mass);
}

// Set
void
NuclideMassSet(ConstHandle2Nuclide self, ConstHandle2ConstMass mass)
{
   detail::setField<CPP,CPPMass>
      (CLASSNAME, CLASSNAME+"MassSet", self, extract::mass, mass);
}


// -----------------------------------------------------------------------------
// Child: charge
// -----------------------------------------------------------------------------

// Has
int
NuclideChargeHas(ConstHandle2ConstNuclide self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ChargeHas", self, extract::charge);
}

// Get, const
Handle2ConstCharge
NuclideChargeGetConst(ConstHandle2ConstNuclide self)
{
   return detail::getField<CPP,Handle2ConstCharge>
      (CLASSNAME, CLASSNAME+"ChargeGetConst", self, extract::charge);
}

// Get, non-const
Handle2Charge
NuclideChargeGet(ConstHandle2Nuclide self)
{
   return detail::getField<CPP,Handle2Charge>
      (CLASSNAME, CLASSNAME+"ChargeGet", self, extract::charge);
}

// Set
void
NuclideChargeSet(ConstHandle2Nuclide self, ConstHandle2ConstCharge charge)
{
   detail::setField<CPP,CPPCharge>
      (CLASSNAME, CLASSNAME+"ChargeSet", self, extract::charge, charge);
}


// -----------------------------------------------------------------------------
// Child: nucleus
// -----------------------------------------------------------------------------

// Has
int
NuclideNucleusHas(ConstHandle2ConstNuclide self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"NucleusHas", self, extract::nucleus);
}

// Get, const
Handle2ConstNucleus
NuclideNucleusGetConst(ConstHandle2ConstNuclide self)
{
   return detail::getField<CPP,Handle2ConstNucleus>
      (CLASSNAME, CLASSNAME+"NucleusGetConst", self, extract::nucleus);
}

// Get, non-const
Handle2Nucleus
NuclideNucleusGet(ConstHandle2Nuclide self)
{
   return detail::getField<CPP,Handle2Nucleus>
      (CLASSNAME, CLASSNAME+"NucleusGet", self, extract::nucleus);
}

// Set
void
NuclideNucleusSet(ConstHandle2Nuclide self, ConstHandle2ConstNucleus nucleus)
{
   detail::setField<CPP,CPPNucleus>
      (CLASSNAME, CLASSNAME+"NucleusSet", self, extract::nucleus, nucleus);
}


// -----------------------------------------------------------------------------
// Child: decayData
// -----------------------------------------------------------------------------

// Has
int
NuclideDecayDataHas(ConstHandle2ConstNuclide self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DecayDataHas", self, extract::decayData);
}

// Get, const
Handle2ConstDecayData
NuclideDecayDataGetConst(ConstHandle2ConstNuclide self)
{
   return detail::getField<CPP,Handle2ConstDecayData>
      (CLASSNAME, CLASSNAME+"DecayDataGetConst", self, extract::decayData);
}

// Get, non-const
Handle2DecayData
NuclideDecayDataGet(ConstHandle2Nuclide self)
{
   return detail::getField<CPP,Handle2DecayData>
      (CLASSNAME, CLASSNAME+"DecayDataGet", self, extract::decayData);
}

// Set
void
NuclideDecayDataSet(ConstHandle2Nuclide self, ConstHandle2ConstDecayData decayData)
{
   detail::setField<CPP,CPPDecayData>
      (CLASSNAME, CLASSNAME+"DecayDataSet", self, extract::decayData, decayData);
}


// -----------------------------------------------------------------------------
// Child: fissionFragmentData
// -----------------------------------------------------------------------------

// Has
int
NuclideFissionFragmentDataHas(ConstHandle2ConstNuclide self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"FissionFragmentDataHas", self, extract::fissionFragmentData);
}

// Get, const
Handle2ConstFissionFragmentData
NuclideFissionFragmentDataGetConst(ConstHandle2ConstNuclide self)
{
   return detail::getField<CPP,Handle2ConstFissionFragmentData>
      (CLASSNAME, CLASSNAME+"FissionFragmentDataGetConst", self, extract::fissionFragmentData);
}

// Get, non-const
Handle2FissionFragmentData
NuclideFissionFragmentDataGet(ConstHandle2Nuclide self)
{
   return detail::getField<CPP,Handle2FissionFragmentData>
      (CLASSNAME, CLASSNAME+"FissionFragmentDataGet", self, extract::fissionFragmentData);
}

// Set
void
NuclideFissionFragmentDataSet(ConstHandle2Nuclide self, ConstHandle2ConstFissionFragmentData fissionFragmentData)
{
   detail::setField<CPP,CPPFissionFragmentData>
      (CLASSNAME, CLASSNAME+"FissionFragmentDataSet", self, extract::fissionFragmentData, fissionFragmentData);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Nuclide/src/custom.cpp"
