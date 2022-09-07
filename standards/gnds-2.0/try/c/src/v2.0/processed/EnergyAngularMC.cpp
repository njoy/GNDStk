
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/processed/EnergyAngularMC.hpp"
#include "EnergyAngularMC.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = EnergyAngularMCClass;
using CPP = multigroup::EnergyAngularMC;

static const std::string CLASSNAME = "EnergyAngularMC";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto productFrame = [](auto &obj) { return &obj.productFrame; };
   static auto energy = [](auto &obj) { return &obj.energy; };
   static auto energyAngular = [](auto &obj) { return &obj.energyAngular; };
}

using CPPEnergy = common::Energy;
using CPPEnergyAngular = transport::EnergyAngular;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstEnergyAngularMC
EnergyAngularMCDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2EnergyAngularMC
EnergyAngularMCDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstEnergyAngularMC
EnergyAngularMCCreateConst(
   const XMLName label,
   const XMLName productFrame,
   ConstHandle2ConstEnergy energy,
   ConstHandle2ConstEnergyAngular energyAngular
) {
   ConstHandle2EnergyAngularMC handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      productFrame,
      detail::tocpp<CPPEnergy>(energy),
      detail::tocpp<CPPEnergyAngular>(energyAngular)
   );
   return handle;
}

// Create, general
Handle2EnergyAngularMC
EnergyAngularMCCreate(
   const XMLName label,
   const XMLName productFrame,
   ConstHandle2ConstEnergy energy,
   ConstHandle2ConstEnergyAngular energyAngular
) {
   ConstHandle2EnergyAngularMC handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      productFrame,
      detail::tocpp<CPPEnergy>(energy),
      detail::tocpp<CPPEnergyAngular>(energyAngular)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
EnergyAngularMCAssign(ConstHandle2EnergyAngularMC This, ConstHandle2ConstEnergyAngularMC from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
EnergyAngularMCDelete(ConstHandle2ConstEnergyAngularMC This)
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
EnergyAngularMCRead(ConstHandle2EnergyAngularMC This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
EnergyAngularMCWrite(ConstHandle2ConstEnergyAngularMC This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
EnergyAngularMCPrint(ConstHandle2ConstEnergyAngularMC This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
EnergyAngularMCPrintXML(ConstHandle2ConstEnergyAngularMC This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
EnergyAngularMCPrintJSON(ConstHandle2ConstEnergyAngularMC This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
EnergyAngularMCLabelHas(ConstHandle2ConstEnergyAngularMC This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
EnergyAngularMCLabelGet(ConstHandle2ConstEnergyAngularMC This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
EnergyAngularMCLabelSet(ConstHandle2EnergyAngularMC This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: productFrame
// -----------------------------------------------------------------------------

// Has
int
EnergyAngularMCProductFrameHas(ConstHandle2ConstEnergyAngularMC This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ProductFrameHas", This, extract::productFrame);
}

// Get
// Returns by value
XMLName
EnergyAngularMCProductFrameGet(ConstHandle2ConstEnergyAngularMC This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ProductFrameGet", This, extract::productFrame);
}

// Set
void
EnergyAngularMCProductFrameSet(ConstHandle2EnergyAngularMC This, const XMLName productFrame)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ProductFrameSet", This, extract::productFrame, productFrame);
}


// -----------------------------------------------------------------------------
// Child: energy
// -----------------------------------------------------------------------------

// Has
int
EnergyAngularMCEnergyHas(ConstHandle2ConstEnergyAngularMC This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EnergyHas", This, extract::energy);
}

// Get, const
Handle2ConstEnergy
EnergyAngularMCEnergyGetConst(ConstHandle2ConstEnergyAngularMC This)
{
   return detail::getField<CPP,Handle2ConstEnergy>
      (CLASSNAME, CLASSNAME+"EnergyGetConst", This, extract::energy);
}

// Get, non-const
Handle2Energy
EnergyAngularMCEnergyGet(ConstHandle2EnergyAngularMC This)
{
   return detail::getField<CPP,Handle2Energy>
      (CLASSNAME, CLASSNAME+"EnergyGet", This, extract::energy);
}

// Set
void
EnergyAngularMCEnergySet(ConstHandle2EnergyAngularMC This, ConstHandle2ConstEnergy energy)
{
   detail::setField<CPP,CPPEnergy>
      (CLASSNAME, CLASSNAME+"EnergySet", This, extract::energy, energy);
}


// -----------------------------------------------------------------------------
// Child: energyAngular
// -----------------------------------------------------------------------------

// Has
int
EnergyAngularMCEnergyAngularHas(ConstHandle2ConstEnergyAngularMC This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EnergyAngularHas", This, extract::energyAngular);
}

// Get, const
Handle2ConstEnergyAngular
EnergyAngularMCEnergyAngularGetConst(ConstHandle2ConstEnergyAngularMC This)
{
   return detail::getField<CPP,Handle2ConstEnergyAngular>
      (CLASSNAME, CLASSNAME+"EnergyAngularGetConst", This, extract::energyAngular);
}

// Get, non-const
Handle2EnergyAngular
EnergyAngularMCEnergyAngularGet(ConstHandle2EnergyAngularMC This)
{
   return detail::getField<CPP,Handle2EnergyAngular>
      (CLASSNAME, CLASSNAME+"EnergyAngularGet", This, extract::energyAngular);
}

// Set
void
EnergyAngularMCEnergyAngularSet(ConstHandle2EnergyAngularMC This, ConstHandle2ConstEnergyAngular energyAngular)
{
   detail::setField<CPP,CPPEnergyAngular>
      (CLASSNAME, CLASSNAME+"EnergyAngularSet", This, extract::energyAngular, energyAngular);
}
