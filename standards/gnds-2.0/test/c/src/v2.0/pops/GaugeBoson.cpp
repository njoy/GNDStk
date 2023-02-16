
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/pops/GaugeBoson.hpp"
#include "GaugeBoson.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = GaugeBosonClass;
using CPP = multigroup::GaugeBoson;

static const std::string CLASSNAME = "GaugeBoson";

namespace extract {
   static auto id = [](auto &obj) { return &obj.id; };
   static auto charge = [](auto &obj) { return &obj.charge; };
   static auto halflife = [](auto &obj) { return &obj.halflife; };
   static auto mass = [](auto &obj) { return &obj.mass; };
   static auto spin = [](auto &obj) { return &obj.spin; };
   static auto parity = [](auto &obj) { return &obj.parity; };
   static auto decayData = [](auto &obj) { return &obj.decayData; };
}

using CPPCharge = pops::Charge;
using CPPHalflife = pops::Halflife;
using CPPMass = pops::Mass;
using CPPSpin = pops::Spin;
using CPPParity = pops::Parity;
using CPPDecayData = pops::DecayData;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstGaugeBoson
GaugeBosonDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2GaugeBoson
GaugeBosonDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstGaugeBoson
GaugeBosonCreateConst(
   const XMLName id,
   ConstHandle2ConstCharge charge,
   ConstHandle2ConstHalflife halflife,
   ConstHandle2ConstMass mass,
   ConstHandle2ConstSpin spin,
   ConstHandle2ConstParity parity,
   ConstHandle2ConstDecayData decayData
) {
   ConstHandle2GaugeBoson handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      id,
      detail::tocpp<CPPCharge>(charge),
      detail::tocpp<CPPHalflife>(halflife),
      detail::tocpp<CPPMass>(mass),
      detail::tocpp<CPPSpin>(spin),
      detail::tocpp<CPPParity>(parity),
      detail::tocpp<CPPDecayData>(decayData)
   );
   return handle;
}

// Create, general
Handle2GaugeBoson
GaugeBosonCreate(
   const XMLName id,
   ConstHandle2ConstCharge charge,
   ConstHandle2ConstHalflife halflife,
   ConstHandle2ConstMass mass,
   ConstHandle2ConstSpin spin,
   ConstHandle2ConstParity parity,
   ConstHandle2ConstDecayData decayData
) {
   ConstHandle2GaugeBoson handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      id,
      detail::tocpp<CPPCharge>(charge),
      detail::tocpp<CPPHalflife>(halflife),
      detail::tocpp<CPPMass>(mass),
      detail::tocpp<CPPSpin>(spin),
      detail::tocpp<CPPParity>(parity),
      detail::tocpp<CPPDecayData>(decayData)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
GaugeBosonAssign(ConstHandle2GaugeBoson self, ConstHandle2ConstGaugeBoson from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
GaugeBosonDelete(ConstHandle2ConstGaugeBoson self)
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
GaugeBosonRead(ConstHandle2GaugeBoson self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
GaugeBosonWrite(ConstHandle2ConstGaugeBoson self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
GaugeBosonPrint(ConstHandle2ConstGaugeBoson self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
GaugeBosonPrintXML(ConstHandle2ConstGaugeBoson self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
GaugeBosonPrintJSON(ConstHandle2ConstGaugeBoson self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: id
// -----------------------------------------------------------------------------

// Has
int
GaugeBosonIdHas(ConstHandle2ConstGaugeBoson self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"IdHas", self, extract::id);
}

// Get
// Returns by value
XMLName
GaugeBosonIdGet(ConstHandle2ConstGaugeBoson self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"IdGet", self, extract::id);
}

// Set
void
GaugeBosonIdSet(ConstHandle2GaugeBoson self, const XMLName id)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"IdSet", self, extract::id, id);
}


// -----------------------------------------------------------------------------
// Child: charge
// -----------------------------------------------------------------------------

// Has
int
GaugeBosonChargeHas(ConstHandle2ConstGaugeBoson self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ChargeHas", self, extract::charge);
}

// Get, const
Handle2ConstCharge
GaugeBosonChargeGetConst(ConstHandle2ConstGaugeBoson self)
{
   return detail::getField<CPP,Handle2ConstCharge>
      (CLASSNAME, CLASSNAME+"ChargeGetConst", self, extract::charge);
}

// Get, non-const
Handle2Charge
GaugeBosonChargeGet(ConstHandle2GaugeBoson self)
{
   return detail::getField<CPP,Handle2Charge>
      (CLASSNAME, CLASSNAME+"ChargeGet", self, extract::charge);
}

// Set
void
GaugeBosonChargeSet(ConstHandle2GaugeBoson self, ConstHandle2ConstCharge charge)
{
   detail::setField<CPP,CPPCharge>
      (CLASSNAME, CLASSNAME+"ChargeSet", self, extract::charge, charge);
}


// -----------------------------------------------------------------------------
// Child: halflife
// -----------------------------------------------------------------------------

// Has
int
GaugeBosonHalflifeHas(ConstHandle2ConstGaugeBoson self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"HalflifeHas", self, extract::halflife);
}

// Get, const
Handle2ConstHalflife
GaugeBosonHalflifeGetConst(ConstHandle2ConstGaugeBoson self)
{
   return detail::getField<CPP,Handle2ConstHalflife>
      (CLASSNAME, CLASSNAME+"HalflifeGetConst", self, extract::halflife);
}

// Get, non-const
Handle2Halflife
GaugeBosonHalflifeGet(ConstHandle2GaugeBoson self)
{
   return detail::getField<CPP,Handle2Halflife>
      (CLASSNAME, CLASSNAME+"HalflifeGet", self, extract::halflife);
}

// Set
void
GaugeBosonHalflifeSet(ConstHandle2GaugeBoson self, ConstHandle2ConstHalflife halflife)
{
   detail::setField<CPP,CPPHalflife>
      (CLASSNAME, CLASSNAME+"HalflifeSet", self, extract::halflife, halflife);
}


// -----------------------------------------------------------------------------
// Child: mass
// -----------------------------------------------------------------------------

// Has
int
GaugeBosonMassHas(ConstHandle2ConstGaugeBoson self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"MassHas", self, extract::mass);
}

// Get, const
Handle2ConstMass
GaugeBosonMassGetConst(ConstHandle2ConstGaugeBoson self)
{
   return detail::getField<CPP,Handle2ConstMass>
      (CLASSNAME, CLASSNAME+"MassGetConst", self, extract::mass);
}

// Get, non-const
Handle2Mass
GaugeBosonMassGet(ConstHandle2GaugeBoson self)
{
   return detail::getField<CPP,Handle2Mass>
      (CLASSNAME, CLASSNAME+"MassGet", self, extract::mass);
}

// Set
void
GaugeBosonMassSet(ConstHandle2GaugeBoson self, ConstHandle2ConstMass mass)
{
   detail::setField<CPP,CPPMass>
      (CLASSNAME, CLASSNAME+"MassSet", self, extract::mass, mass);
}


// -----------------------------------------------------------------------------
// Child: spin
// -----------------------------------------------------------------------------

// Has
int
GaugeBosonSpinHas(ConstHandle2ConstGaugeBoson self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SpinHas", self, extract::spin);
}

// Get, const
Handle2ConstSpin
GaugeBosonSpinGetConst(ConstHandle2ConstGaugeBoson self)
{
   return detail::getField<CPP,Handle2ConstSpin>
      (CLASSNAME, CLASSNAME+"SpinGetConst", self, extract::spin);
}

// Get, non-const
Handle2Spin
GaugeBosonSpinGet(ConstHandle2GaugeBoson self)
{
   return detail::getField<CPP,Handle2Spin>
      (CLASSNAME, CLASSNAME+"SpinGet", self, extract::spin);
}

// Set
void
GaugeBosonSpinSet(ConstHandle2GaugeBoson self, ConstHandle2ConstSpin spin)
{
   detail::setField<CPP,CPPSpin>
      (CLASSNAME, CLASSNAME+"SpinSet", self, extract::spin, spin);
}


// -----------------------------------------------------------------------------
// Child: parity
// -----------------------------------------------------------------------------

// Has
int
GaugeBosonParityHas(ConstHandle2ConstGaugeBoson self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ParityHas", self, extract::parity);
}

// Get, const
Handle2ConstParity
GaugeBosonParityGetConst(ConstHandle2ConstGaugeBoson self)
{
   return detail::getField<CPP,Handle2ConstParity>
      (CLASSNAME, CLASSNAME+"ParityGetConst", self, extract::parity);
}

// Get, non-const
Handle2Parity
GaugeBosonParityGet(ConstHandle2GaugeBoson self)
{
   return detail::getField<CPP,Handle2Parity>
      (CLASSNAME, CLASSNAME+"ParityGet", self, extract::parity);
}

// Set
void
GaugeBosonParitySet(ConstHandle2GaugeBoson self, ConstHandle2ConstParity parity)
{
   detail::setField<CPP,CPPParity>
      (CLASSNAME, CLASSNAME+"ParitySet", self, extract::parity, parity);
}


// -----------------------------------------------------------------------------
// Child: decayData
// -----------------------------------------------------------------------------

// Has
int
GaugeBosonDecayDataHas(ConstHandle2ConstGaugeBoson self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DecayDataHas", self, extract::decayData);
}

// Get, const
Handle2ConstDecayData
GaugeBosonDecayDataGetConst(ConstHandle2ConstGaugeBoson self)
{
   return detail::getField<CPP,Handle2ConstDecayData>
      (CLASSNAME, CLASSNAME+"DecayDataGetConst", self, extract::decayData);
}

// Get, non-const
Handle2DecayData
GaugeBosonDecayDataGet(ConstHandle2GaugeBoson self)
{
   return detail::getField<CPP,Handle2DecayData>
      (CLASSNAME, CLASSNAME+"DecayDataGet", self, extract::decayData);
}

// Set
void
GaugeBosonDecayDataSet(ConstHandle2GaugeBoson self, ConstHandle2ConstDecayData decayData)
{
   detail::setField<CPP,CPPDecayData>
      (CLASSNAME, CLASSNAME+"DecayDataSet", self, extract::decayData, decayData);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/pops/GaugeBoson/src/custom.cpp"
