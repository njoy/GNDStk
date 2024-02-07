
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/Nucleus.hpp"
#include "Nucleus.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = NucleusClass;
using CPP = multigroup::Nucleus;

static const std::string CLASSNAME = "Nucleus";

namespace extract {
   static auto id = [](auto &obj) { return &obj.id; };
   static auto index = [](auto &obj) { return &obj.index; };
   static auto mass = [](auto &obj) { return &obj.mass; };
   static auto spin = [](auto &obj) { return &obj.spin; };
   static auto parity = [](auto &obj) { return &obj.parity; };
   static auto charge = [](auto &obj) { return &obj.charge; };
   static auto halflife = [](auto &obj) { return &obj.halflife; };
   static auto energy = [](auto &obj) { return &obj.energy; };
   static auto decayData = [](auto &obj) { return &obj.decayData; };
}

using CPPMass = general::Mass;
using CPPSpin = general::Spin;
using CPPParity = general::Parity;
using CPPCharge = general::Charge;
using CPPHalflife = general::Halflife;
using CPPEnergy = general::Energy;
using CPPDecayData = general::DecayData;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstNucleus
NucleusDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default, non-const
Handle2Nucleus
NucleusDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstNucleus
NucleusCreateConst(
   const char *const id,
   const int index,
   ConstHandle2ConstMass mass,
   ConstHandle2ConstSpin spin,
   ConstHandle2ConstParity parity,
   ConstHandle2ConstCharge charge,
   ConstHandle2ConstHalflife halflife,
   ConstHandle2ConstEnergy energy,
   ConstHandle2ConstDecayData decayData
) {
   ConstHandle2Nucleus handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      id,
      index,
      detail::tocpp<CPPMass>(mass),
      detail::tocpp<CPPSpin>(spin),
      detail::tocpp<CPPParity>(parity),
      detail::tocpp<CPPCharge>(charge),
      detail::tocpp<CPPHalflife>(halflife),
      detail::tocpp<CPPEnergy>(energy),
      detail::tocpp<CPPDecayData>(decayData)
   );
   return handle;
}

// Create, general, non-const
Handle2Nucleus
NucleusCreate(
   const char *const id,
   const int index,
   ConstHandle2ConstMass mass,
   ConstHandle2ConstSpin spin,
   ConstHandle2ConstParity parity,
   ConstHandle2ConstCharge charge,
   ConstHandle2ConstHalflife halflife,
   ConstHandle2ConstEnergy energy,
   ConstHandle2ConstDecayData decayData
) {
   ConstHandle2Nucleus handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      id,
      index,
      detail::tocpp<CPPMass>(mass),
      detail::tocpp<CPPSpin>(spin),
      detail::tocpp<CPPParity>(parity),
      detail::tocpp<CPPCharge>(charge),
      detail::tocpp<CPPHalflife>(halflife),
      detail::tocpp<CPPEnergy>(energy),
      detail::tocpp<CPPDecayData>(decayData)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
NucleusAssign(ConstHandle2Nucleus self, ConstHandle2ConstNucleus from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
NucleusDelete(ConstHandle2ConstNucleus self)
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
NucleusRead(ConstHandle2Nucleus self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
NucleusWrite(ConstHandle2ConstNucleus self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
NucleusPrint(ConstHandle2ConstNucleus self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
NucleusPrintXML(ConstHandle2ConstNucleus self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
NucleusPrintJSON(ConstHandle2ConstNucleus self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: id
// -----------------------------------------------------------------------------

// Has
int
NucleusIdHas(ConstHandle2ConstNucleus self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"IdHas", self, extract::id);
}

// Get
// Returns by value
const char *
NucleusIdGet(ConstHandle2ConstNucleus self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"IdGet", self, extract::id);
}

// Set
void
NucleusIdSet(ConstHandle2Nucleus self, const char *const id)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"IdSet", self, extract::id, id);
}


// -----------------------------------------------------------------------------
// Metadatum: index
// -----------------------------------------------------------------------------

// Has
int
NucleusIndexHas(ConstHandle2ConstNucleus self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"IndexHas", self, extract::index);
}

// Get
// Returns by value
int
NucleusIndexGet(ConstHandle2ConstNucleus self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"IndexGet", self, extract::index);
}

// Set
void
NucleusIndexSet(ConstHandle2Nucleus self, const int index)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"IndexSet", self, extract::index, index);
}


// -----------------------------------------------------------------------------
// Child: mass
// -----------------------------------------------------------------------------

// Has
int
NucleusMassHas(ConstHandle2ConstNucleus self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"MassHas", self, extract::mass);
}

// Get, const
Handle2ConstMass
NucleusMassGetConst(ConstHandle2ConstNucleus self)
{
   return detail::getField<CPP,Handle2ConstMass>
      (CLASSNAME, CLASSNAME+"MassGetConst", self, extract::mass);
}

// Get, non-const
Handle2Mass
NucleusMassGet(ConstHandle2Nucleus self)
{
   return detail::getField<CPP,Handle2Mass>
      (CLASSNAME, CLASSNAME+"MassGet", self, extract::mass);
}

// Set
void
NucleusMassSet(ConstHandle2Nucleus self, ConstHandle2ConstMass mass)
{
   detail::setField<CPP,CPPMass>
      (CLASSNAME, CLASSNAME+"MassSet", self, extract::mass, mass);
}


// -----------------------------------------------------------------------------
// Child: spin
// -----------------------------------------------------------------------------

// Has
int
NucleusSpinHas(ConstHandle2ConstNucleus self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SpinHas", self, extract::spin);
}

// Get, const
Handle2ConstSpin
NucleusSpinGetConst(ConstHandle2ConstNucleus self)
{
   return detail::getField<CPP,Handle2ConstSpin>
      (CLASSNAME, CLASSNAME+"SpinGetConst", self, extract::spin);
}

// Get, non-const
Handle2Spin
NucleusSpinGet(ConstHandle2Nucleus self)
{
   return detail::getField<CPP,Handle2Spin>
      (CLASSNAME, CLASSNAME+"SpinGet", self, extract::spin);
}

// Set
void
NucleusSpinSet(ConstHandle2Nucleus self, ConstHandle2ConstSpin spin)
{
   detail::setField<CPP,CPPSpin>
      (CLASSNAME, CLASSNAME+"SpinSet", self, extract::spin, spin);
}


// -----------------------------------------------------------------------------
// Child: parity
// -----------------------------------------------------------------------------

// Has
int
NucleusParityHas(ConstHandle2ConstNucleus self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ParityHas", self, extract::parity);
}

// Get, const
Handle2ConstParity
NucleusParityGetConst(ConstHandle2ConstNucleus self)
{
   return detail::getField<CPP,Handle2ConstParity>
      (CLASSNAME, CLASSNAME+"ParityGetConst", self, extract::parity);
}

// Get, non-const
Handle2Parity
NucleusParityGet(ConstHandle2Nucleus self)
{
   return detail::getField<CPP,Handle2Parity>
      (CLASSNAME, CLASSNAME+"ParityGet", self, extract::parity);
}

// Set
void
NucleusParitySet(ConstHandle2Nucleus self, ConstHandle2ConstParity parity)
{
   detail::setField<CPP,CPPParity>
      (CLASSNAME, CLASSNAME+"ParitySet", self, extract::parity, parity);
}


// -----------------------------------------------------------------------------
// Child: charge
// -----------------------------------------------------------------------------

// Has
int
NucleusChargeHas(ConstHandle2ConstNucleus self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ChargeHas", self, extract::charge);
}

// Get, const
Handle2ConstCharge
NucleusChargeGetConst(ConstHandle2ConstNucleus self)
{
   return detail::getField<CPP,Handle2ConstCharge>
      (CLASSNAME, CLASSNAME+"ChargeGetConst", self, extract::charge);
}

// Get, non-const
Handle2Charge
NucleusChargeGet(ConstHandle2Nucleus self)
{
   return detail::getField<CPP,Handle2Charge>
      (CLASSNAME, CLASSNAME+"ChargeGet", self, extract::charge);
}

// Set
void
NucleusChargeSet(ConstHandle2Nucleus self, ConstHandle2ConstCharge charge)
{
   detail::setField<CPP,CPPCharge>
      (CLASSNAME, CLASSNAME+"ChargeSet", self, extract::charge, charge);
}


// -----------------------------------------------------------------------------
// Child: halflife
// -----------------------------------------------------------------------------

// Has
int
NucleusHalflifeHas(ConstHandle2ConstNucleus self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"HalflifeHas", self, extract::halflife);
}

// Get, const
Handle2ConstHalflife
NucleusHalflifeGetConst(ConstHandle2ConstNucleus self)
{
   return detail::getField<CPP,Handle2ConstHalflife>
      (CLASSNAME, CLASSNAME+"HalflifeGetConst", self, extract::halflife);
}

// Get, non-const
Handle2Halflife
NucleusHalflifeGet(ConstHandle2Nucleus self)
{
   return detail::getField<CPP,Handle2Halflife>
      (CLASSNAME, CLASSNAME+"HalflifeGet", self, extract::halflife);
}

// Set
void
NucleusHalflifeSet(ConstHandle2Nucleus self, ConstHandle2ConstHalflife halflife)
{
   detail::setField<CPP,CPPHalflife>
      (CLASSNAME, CLASSNAME+"HalflifeSet", self, extract::halflife, halflife);
}


// -----------------------------------------------------------------------------
// Child: energy
// -----------------------------------------------------------------------------

// Has
int
NucleusEnergyHas(ConstHandle2ConstNucleus self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EnergyHas", self, extract::energy);
}

// Get, const
Handle2ConstEnergy
NucleusEnergyGetConst(ConstHandle2ConstNucleus self)
{
   return detail::getField<CPP,Handle2ConstEnergy>
      (CLASSNAME, CLASSNAME+"EnergyGetConst", self, extract::energy);
}

// Get, non-const
Handle2Energy
NucleusEnergyGet(ConstHandle2Nucleus self)
{
   return detail::getField<CPP,Handle2Energy>
      (CLASSNAME, CLASSNAME+"EnergyGet", self, extract::energy);
}

// Set
void
NucleusEnergySet(ConstHandle2Nucleus self, ConstHandle2ConstEnergy energy)
{
   detail::setField<CPP,CPPEnergy>
      (CLASSNAME, CLASSNAME+"EnergySet", self, extract::energy, energy);
}


// -----------------------------------------------------------------------------
// Child: decayData
// -----------------------------------------------------------------------------

// Has
int
NucleusDecayDataHas(ConstHandle2ConstNucleus self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DecayDataHas", self, extract::decayData);
}

// Get, const
Handle2ConstDecayData
NucleusDecayDataGetConst(ConstHandle2ConstNucleus self)
{
   return detail::getField<CPP,Handle2ConstDecayData>
      (CLASSNAME, CLASSNAME+"DecayDataGetConst", self, extract::decayData);
}

// Get, non-const
Handle2DecayData
NucleusDecayDataGet(ConstHandle2Nucleus self)
{
   return detail::getField<CPP,Handle2DecayData>
      (CLASSNAME, CLASSNAME+"DecayDataGet", self, extract::decayData);
}

// Set
void
NucleusDecayDataSet(ConstHandle2Nucleus self, ConstHandle2ConstDecayData decayData)
{
   detail::setField<CPP,CPPDecayData>
      (CLASSNAME, CLASSNAME+"DecayDataSet", self, extract::decayData, decayData);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Nucleus/src/custom.cpp"
