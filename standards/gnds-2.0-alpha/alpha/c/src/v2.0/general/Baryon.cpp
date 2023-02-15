
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/Baryon.hpp"
#include "Baryon.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = BaryonClass;
using CPP = multigroup::Baryon;

static const std::string CLASSNAME = "Baryon";

namespace extract {
   static auto id = [](auto &obj) { return &obj.id; };
   static auto mass = [](auto &obj) { return &obj.mass; };
   static auto spin = [](auto &obj) { return &obj.spin; };
   static auto parity = [](auto &obj) { return &obj.parity; };
   static auto charge = [](auto &obj) { return &obj.charge; };
   static auto halflife = [](auto &obj) { return &obj.halflife; };
   static auto decayData = [](auto &obj) { return &obj.decayData; };
}

using CPPMass = general::Mass;
using CPPSpin = general::Spin;
using CPPParity = general::Parity;
using CPPCharge = general::Charge;
using CPPHalflife = general::Halflife;
using CPPDecayData = general::DecayData;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstBaryon
BaryonDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Baryon
BaryonDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstBaryon
BaryonCreateConst(
   const char *const id,
   ConstHandle2ConstMass mass,
   ConstHandle2ConstSpin spin,
   ConstHandle2ConstParity parity,
   ConstHandle2ConstCharge charge,
   ConstHandle2ConstHalflife halflife,
   ConstHandle2ConstDecayData decayData
) {
   ConstHandle2Baryon handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      id,
      detail::tocpp<CPPMass>(mass),
      detail::tocpp<CPPSpin>(spin),
      detail::tocpp<CPPParity>(parity),
      detail::tocpp<CPPCharge>(charge),
      detail::tocpp<CPPHalflife>(halflife),
      detail::tocpp<CPPDecayData>(decayData)
   );
   return handle;
}

// Create, general
Handle2Baryon
BaryonCreate(
   const char *const id,
   ConstHandle2ConstMass mass,
   ConstHandle2ConstSpin spin,
   ConstHandle2ConstParity parity,
   ConstHandle2ConstCharge charge,
   ConstHandle2ConstHalflife halflife,
   ConstHandle2ConstDecayData decayData
) {
   ConstHandle2Baryon handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      id,
      detail::tocpp<CPPMass>(mass),
      detail::tocpp<CPPSpin>(spin),
      detail::tocpp<CPPParity>(parity),
      detail::tocpp<CPPCharge>(charge),
      detail::tocpp<CPPHalflife>(halflife),
      detail::tocpp<CPPDecayData>(decayData)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
BaryonAssign(ConstHandle2Baryon self, ConstHandle2ConstBaryon from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
BaryonDelete(ConstHandle2ConstBaryon self)
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
BaryonRead(ConstHandle2Baryon self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
BaryonWrite(ConstHandle2ConstBaryon self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
BaryonPrint(ConstHandle2ConstBaryon self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
BaryonPrintXML(ConstHandle2ConstBaryon self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
BaryonPrintJSON(ConstHandle2ConstBaryon self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: id
// -----------------------------------------------------------------------------

// Has
int
BaryonIdHas(ConstHandle2ConstBaryon self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"IdHas", self, extract::id);
}

// Get
// Returns by value
const char *
BaryonIdGet(ConstHandle2ConstBaryon self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"IdGet", self, extract::id);
}

// Set
void
BaryonIdSet(ConstHandle2Baryon self, const char *const id)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"IdSet", self, extract::id, id);
}


// -----------------------------------------------------------------------------
// Child: mass
// -----------------------------------------------------------------------------

// Has
int
BaryonMassHas(ConstHandle2ConstBaryon self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"MassHas", self, extract::mass);
}

// Get, const
Handle2ConstMass
BaryonMassGetConst(ConstHandle2ConstBaryon self)
{
   return detail::getField<CPP,Handle2ConstMass>
      (CLASSNAME, CLASSNAME+"MassGetConst", self, extract::mass);
}

// Get, non-const
Handle2Mass
BaryonMassGet(ConstHandle2Baryon self)
{
   return detail::getField<CPP,Handle2Mass>
      (CLASSNAME, CLASSNAME+"MassGet", self, extract::mass);
}

// Set
void
BaryonMassSet(ConstHandle2Baryon self, ConstHandle2ConstMass mass)
{
   detail::setField<CPP,CPPMass>
      (CLASSNAME, CLASSNAME+"MassSet", self, extract::mass, mass);
}


// -----------------------------------------------------------------------------
// Child: spin
// -----------------------------------------------------------------------------

// Has
int
BaryonSpinHas(ConstHandle2ConstBaryon self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SpinHas", self, extract::spin);
}

// Get, const
Handle2ConstSpin
BaryonSpinGetConst(ConstHandle2ConstBaryon self)
{
   return detail::getField<CPP,Handle2ConstSpin>
      (CLASSNAME, CLASSNAME+"SpinGetConst", self, extract::spin);
}

// Get, non-const
Handle2Spin
BaryonSpinGet(ConstHandle2Baryon self)
{
   return detail::getField<CPP,Handle2Spin>
      (CLASSNAME, CLASSNAME+"SpinGet", self, extract::spin);
}

// Set
void
BaryonSpinSet(ConstHandle2Baryon self, ConstHandle2ConstSpin spin)
{
   detail::setField<CPP,CPPSpin>
      (CLASSNAME, CLASSNAME+"SpinSet", self, extract::spin, spin);
}


// -----------------------------------------------------------------------------
// Child: parity
// -----------------------------------------------------------------------------

// Has
int
BaryonParityHas(ConstHandle2ConstBaryon self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ParityHas", self, extract::parity);
}

// Get, const
Handle2ConstParity
BaryonParityGetConst(ConstHandle2ConstBaryon self)
{
   return detail::getField<CPP,Handle2ConstParity>
      (CLASSNAME, CLASSNAME+"ParityGetConst", self, extract::parity);
}

// Get, non-const
Handle2Parity
BaryonParityGet(ConstHandle2Baryon self)
{
   return detail::getField<CPP,Handle2Parity>
      (CLASSNAME, CLASSNAME+"ParityGet", self, extract::parity);
}

// Set
void
BaryonParitySet(ConstHandle2Baryon self, ConstHandle2ConstParity parity)
{
   detail::setField<CPP,CPPParity>
      (CLASSNAME, CLASSNAME+"ParitySet", self, extract::parity, parity);
}


// -----------------------------------------------------------------------------
// Child: charge
// -----------------------------------------------------------------------------

// Has
int
BaryonChargeHas(ConstHandle2ConstBaryon self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ChargeHas", self, extract::charge);
}

// Get, const
Handle2ConstCharge
BaryonChargeGetConst(ConstHandle2ConstBaryon self)
{
   return detail::getField<CPP,Handle2ConstCharge>
      (CLASSNAME, CLASSNAME+"ChargeGetConst", self, extract::charge);
}

// Get, non-const
Handle2Charge
BaryonChargeGet(ConstHandle2Baryon self)
{
   return detail::getField<CPP,Handle2Charge>
      (CLASSNAME, CLASSNAME+"ChargeGet", self, extract::charge);
}

// Set
void
BaryonChargeSet(ConstHandle2Baryon self, ConstHandle2ConstCharge charge)
{
   detail::setField<CPP,CPPCharge>
      (CLASSNAME, CLASSNAME+"ChargeSet", self, extract::charge, charge);
}


// -----------------------------------------------------------------------------
// Child: halflife
// -----------------------------------------------------------------------------

// Has
int
BaryonHalflifeHas(ConstHandle2ConstBaryon self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"HalflifeHas", self, extract::halflife);
}

// Get, const
Handle2ConstHalflife
BaryonHalflifeGetConst(ConstHandle2ConstBaryon self)
{
   return detail::getField<CPP,Handle2ConstHalflife>
      (CLASSNAME, CLASSNAME+"HalflifeGetConst", self, extract::halflife);
}

// Get, non-const
Handle2Halflife
BaryonHalflifeGet(ConstHandle2Baryon self)
{
   return detail::getField<CPP,Handle2Halflife>
      (CLASSNAME, CLASSNAME+"HalflifeGet", self, extract::halflife);
}

// Set
void
BaryonHalflifeSet(ConstHandle2Baryon self, ConstHandle2ConstHalflife halflife)
{
   detail::setField<CPP,CPPHalflife>
      (CLASSNAME, CLASSNAME+"HalflifeSet", self, extract::halflife, halflife);
}


// -----------------------------------------------------------------------------
// Child: decayData
// -----------------------------------------------------------------------------

// Has
int
BaryonDecayDataHas(ConstHandle2ConstBaryon self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DecayDataHas", self, extract::decayData);
}

// Get, const
Handle2ConstDecayData
BaryonDecayDataGetConst(ConstHandle2ConstBaryon self)
{
   return detail::getField<CPP,Handle2ConstDecayData>
      (CLASSNAME, CLASSNAME+"DecayDataGetConst", self, extract::decayData);
}

// Get, non-const
Handle2DecayData
BaryonDecayDataGet(ConstHandle2Baryon self)
{
   return detail::getField<CPP,Handle2DecayData>
      (CLASSNAME, CLASSNAME+"DecayDataGet", self, extract::decayData);
}

// Set
void
BaryonDecayDataSet(ConstHandle2Baryon self, ConstHandle2ConstDecayData decayData)
{
   detail::setField<CPP,CPPDecayData>
      (CLASSNAME, CLASSNAME+"DecayDataSet", self, extract::decayData, decayData);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Baryon/src/custom.cpp"
