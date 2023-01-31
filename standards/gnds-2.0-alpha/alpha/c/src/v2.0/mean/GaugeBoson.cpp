
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/mean/GaugeBoson.hpp"
#include "GaugeBoson.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = GaugeBosonClass;
using CPP = multigroup::GaugeBoson;

static const std::string CLASSNAME = "GaugeBoson";

namespace extract {
   static auto id = [](auto &obj) { return &obj.id; };
   static auto mass = [](auto &obj) { return &obj.mass; };
   static auto spin = [](auto &obj) { return &obj.spin; };
   static auto parity = [](auto &obj) { return &obj.parity; };
   static auto charge = [](auto &obj) { return &obj.charge; };
   static auto halflife = [](auto &obj) { return &obj.halflife; };
}

using CPPMass = common::Mass;
using CPPSpin = common::Spin;
using CPPParity = common::Parity;
using CPPCharge = common::Charge;
using CPPHalflife = common::Halflife;


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
   const char *const id,
   ConstHandle2ConstMass mass,
   ConstHandle2ConstSpin spin,
   ConstHandle2ConstParity parity,
   ConstHandle2ConstCharge charge,
   ConstHandle2ConstHalflife halflife
) {
   ConstHandle2GaugeBoson handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      id,
      detail::tocpp<CPPMass>(mass),
      detail::tocpp<CPPSpin>(spin),
      detail::tocpp<CPPParity>(parity),
      detail::tocpp<CPPCharge>(charge),
      detail::tocpp<CPPHalflife>(halflife)
   );
   return handle;
}

// Create, general
Handle2GaugeBoson
GaugeBosonCreate(
   const char *const id,
   ConstHandle2ConstMass mass,
   ConstHandle2ConstSpin spin,
   ConstHandle2ConstParity parity,
   ConstHandle2ConstCharge charge,
   ConstHandle2ConstHalflife halflife
) {
   ConstHandle2GaugeBoson handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      id,
      detail::tocpp<CPPMass>(mass),
      detail::tocpp<CPPSpin>(spin),
      detail::tocpp<CPPParity>(parity),
      detail::tocpp<CPPCharge>(charge),
      detail::tocpp<CPPHalflife>(halflife)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
GaugeBosonAssign(ConstHandle2GaugeBoson This, ConstHandle2ConstGaugeBoson from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
GaugeBosonDelete(ConstHandle2ConstGaugeBoson This)
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
GaugeBosonRead(ConstHandle2GaugeBoson This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
GaugeBosonWrite(ConstHandle2ConstGaugeBoson This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
GaugeBosonPrint(ConstHandle2ConstGaugeBoson This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
GaugeBosonPrintXML(ConstHandle2ConstGaugeBoson This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
GaugeBosonPrintJSON(ConstHandle2ConstGaugeBoson This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: id
// -----------------------------------------------------------------------------

// Has
int
GaugeBosonIdHas(ConstHandle2ConstGaugeBoson This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"IdHas", This, extract::id);
}

// Get
// Returns by value
const char *
GaugeBosonIdGet(ConstHandle2ConstGaugeBoson This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"IdGet", This, extract::id);
}

// Set
void
GaugeBosonIdSet(ConstHandle2GaugeBoson This, const char *const id)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"IdSet", This, extract::id, id);
}


// -----------------------------------------------------------------------------
// Child: mass
// -----------------------------------------------------------------------------

// Has
int
GaugeBosonMassHas(ConstHandle2ConstGaugeBoson This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"MassHas", This, extract::mass);
}

// Get, const
Handle2ConstMass
GaugeBosonMassGetConst(ConstHandle2ConstGaugeBoson This)
{
   return detail::getField<CPP,Handle2ConstMass>
      (CLASSNAME, CLASSNAME+"MassGetConst", This, extract::mass);
}

// Get, non-const
Handle2Mass
GaugeBosonMassGet(ConstHandle2GaugeBoson This)
{
   return detail::getField<CPP,Handle2Mass>
      (CLASSNAME, CLASSNAME+"MassGet", This, extract::mass);
}

// Set
void
GaugeBosonMassSet(ConstHandle2GaugeBoson This, ConstHandle2ConstMass mass)
{
   detail::setField<CPP,CPPMass>
      (CLASSNAME, CLASSNAME+"MassSet", This, extract::mass, mass);
}


// -----------------------------------------------------------------------------
// Child: spin
// -----------------------------------------------------------------------------

// Has
int
GaugeBosonSpinHas(ConstHandle2ConstGaugeBoson This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SpinHas", This, extract::spin);
}

// Get, const
Handle2ConstSpin
GaugeBosonSpinGetConst(ConstHandle2ConstGaugeBoson This)
{
   return detail::getField<CPP,Handle2ConstSpin>
      (CLASSNAME, CLASSNAME+"SpinGetConst", This, extract::spin);
}

// Get, non-const
Handle2Spin
GaugeBosonSpinGet(ConstHandle2GaugeBoson This)
{
   return detail::getField<CPP,Handle2Spin>
      (CLASSNAME, CLASSNAME+"SpinGet", This, extract::spin);
}

// Set
void
GaugeBosonSpinSet(ConstHandle2GaugeBoson This, ConstHandle2ConstSpin spin)
{
   detail::setField<CPP,CPPSpin>
      (CLASSNAME, CLASSNAME+"SpinSet", This, extract::spin, spin);
}


// -----------------------------------------------------------------------------
// Child: parity
// -----------------------------------------------------------------------------

// Has
int
GaugeBosonParityHas(ConstHandle2ConstGaugeBoson This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ParityHas", This, extract::parity);
}

// Get, const
Handle2ConstParity
GaugeBosonParityGetConst(ConstHandle2ConstGaugeBoson This)
{
   return detail::getField<CPP,Handle2ConstParity>
      (CLASSNAME, CLASSNAME+"ParityGetConst", This, extract::parity);
}

// Get, non-const
Handle2Parity
GaugeBosonParityGet(ConstHandle2GaugeBoson This)
{
   return detail::getField<CPP,Handle2Parity>
      (CLASSNAME, CLASSNAME+"ParityGet", This, extract::parity);
}

// Set
void
GaugeBosonParitySet(ConstHandle2GaugeBoson This, ConstHandle2ConstParity parity)
{
   detail::setField<CPP,CPPParity>
      (CLASSNAME, CLASSNAME+"ParitySet", This, extract::parity, parity);
}


// -----------------------------------------------------------------------------
// Child: charge
// -----------------------------------------------------------------------------

// Has
int
GaugeBosonChargeHas(ConstHandle2ConstGaugeBoson This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ChargeHas", This, extract::charge);
}

// Get, const
Handle2ConstCharge
GaugeBosonChargeGetConst(ConstHandle2ConstGaugeBoson This)
{
   return detail::getField<CPP,Handle2ConstCharge>
      (CLASSNAME, CLASSNAME+"ChargeGetConst", This, extract::charge);
}

// Get, non-const
Handle2Charge
GaugeBosonChargeGet(ConstHandle2GaugeBoson This)
{
   return detail::getField<CPP,Handle2Charge>
      (CLASSNAME, CLASSNAME+"ChargeGet", This, extract::charge);
}

// Set
void
GaugeBosonChargeSet(ConstHandle2GaugeBoson This, ConstHandle2ConstCharge charge)
{
   detail::setField<CPP,CPPCharge>
      (CLASSNAME, CLASSNAME+"ChargeSet", This, extract::charge, charge);
}


// -----------------------------------------------------------------------------
// Child: halflife
// -----------------------------------------------------------------------------

// Has
int
GaugeBosonHalflifeHas(ConstHandle2ConstGaugeBoson This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"HalflifeHas", This, extract::halflife);
}

// Get, const
Handle2ConstHalflife
GaugeBosonHalflifeGetConst(ConstHandle2ConstGaugeBoson This)
{
   return detail::getField<CPP,Handle2ConstHalflife>
      (CLASSNAME, CLASSNAME+"HalflifeGetConst", This, extract::halflife);
}

// Get, non-const
Handle2Halflife
GaugeBosonHalflifeGet(ConstHandle2GaugeBoson This)
{
   return detail::getField<CPP,Handle2Halflife>
      (CLASSNAME, CLASSNAME+"HalflifeGet", This, extract::halflife);
}

// Set
void
GaugeBosonHalflifeSet(ConstHandle2GaugeBoson This, ConstHandle2ConstHalflife halflife)
{
   detail::setField<CPP,CPPHalflife>
      (CLASSNAME, CLASSNAME+"HalflifeSet", This, extract::halflife, halflife);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/mean/GaugeBoson/src/custom.cpp"
