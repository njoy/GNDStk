
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/pops/Configuration.hpp"
#include "Configuration.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = ConfigurationClass;
using CPP = multigroup::Configuration;

static const std::string CLASSNAME = "Configuration";

namespace extract {
   static auto subshell = [](auto &obj) { return &obj.subshell; };
   static auto electronNumber = [](auto &obj) { return &obj.electronNumber; };
   static auto bindingEnergy = [](auto &obj) { return &obj.bindingEnergy; };
   static auto decayData = [](auto &obj) { return &obj.decayData; };
}

using CPPBindingEnergy = pops::BindingEnergy;
using CPPDecayData = pops::DecayData;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstConfiguration
ConfigurationDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Configuration
ConfigurationDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstConfiguration
ConfigurationCreateConst(
   const char *const subshell,
   const Float64 electronNumber,
   ConstHandle2ConstBindingEnergy bindingEnergy,
   ConstHandle2ConstDecayData decayData
) {
   ConstHandle2Configuration handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      subshell,
      electronNumber,
      detail::tocpp<CPPBindingEnergy>(bindingEnergy),
      detail::tocpp<CPPDecayData>(decayData)
   );
   return handle;
}

// Create, general
Handle2Configuration
ConfigurationCreate(
   const char *const subshell,
   const Float64 electronNumber,
   ConstHandle2ConstBindingEnergy bindingEnergy,
   ConstHandle2ConstDecayData decayData
) {
   ConstHandle2Configuration handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      subshell,
      electronNumber,
      detail::tocpp<CPPBindingEnergy>(bindingEnergy),
      detail::tocpp<CPPDecayData>(decayData)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ConfigurationAssign(ConstHandle2Configuration This, ConstHandle2ConstConfiguration from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ConfigurationDelete(ConstHandle2ConstConfiguration This)
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
ConfigurationRead(ConstHandle2Configuration This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ConfigurationWrite(ConstHandle2ConstConfiguration This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
ConfigurationPrint(ConstHandle2ConstConfiguration This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
ConfigurationPrintXML(ConstHandle2ConstConfiguration This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
ConfigurationPrintJSON(ConstHandle2ConstConfiguration This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: subshell
// -----------------------------------------------------------------------------

// Has
int
ConfigurationSubshellHas(ConstHandle2ConstConfiguration This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SubshellHas", This, extract::subshell);
}

// Get
// Returns by value
const char *
ConfigurationSubshellGet(ConstHandle2ConstConfiguration This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"SubshellGet", This, extract::subshell);
}

// Set
void
ConfigurationSubshellSet(ConstHandle2Configuration This, const char *const subshell)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"SubshellSet", This, extract::subshell, subshell);
}


// -----------------------------------------------------------------------------
// Metadatum: electronNumber
// -----------------------------------------------------------------------------

// Has
int
ConfigurationElectronNumberHas(ConstHandle2ConstConfiguration This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ElectronNumberHas", This, extract::electronNumber);
}

// Get
// Returns by value
Float64
ConfigurationElectronNumberGet(ConstHandle2ConstConfiguration This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ElectronNumberGet", This, extract::electronNumber);
}

// Set
void
ConfigurationElectronNumberSet(ConstHandle2Configuration This, const Float64 electronNumber)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ElectronNumberSet", This, extract::electronNumber, electronNumber);
}


// -----------------------------------------------------------------------------
// Child: bindingEnergy
// -----------------------------------------------------------------------------

// Has
int
ConfigurationBindingEnergyHas(ConstHandle2ConstConfiguration This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"BindingEnergyHas", This, extract::bindingEnergy);
}

// Get, const
Handle2ConstBindingEnergy
ConfigurationBindingEnergyGetConst(ConstHandle2ConstConfiguration This)
{
   return detail::getField<CPP,Handle2ConstBindingEnergy>
      (CLASSNAME, CLASSNAME+"BindingEnergyGetConst", This, extract::bindingEnergy);
}

// Get, non-const
Handle2BindingEnergy
ConfigurationBindingEnergyGet(ConstHandle2Configuration This)
{
   return detail::getField<CPP,Handle2BindingEnergy>
      (CLASSNAME, CLASSNAME+"BindingEnergyGet", This, extract::bindingEnergy);
}

// Set
void
ConfigurationBindingEnergySet(ConstHandle2Configuration This, ConstHandle2ConstBindingEnergy bindingEnergy)
{
   detail::setField<CPP,CPPBindingEnergy>
      (CLASSNAME, CLASSNAME+"BindingEnergySet", This, extract::bindingEnergy, bindingEnergy);
}


// -----------------------------------------------------------------------------
// Child: decayData
// -----------------------------------------------------------------------------

// Has
int
ConfigurationDecayDataHas(ConstHandle2ConstConfiguration This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DecayDataHas", This, extract::decayData);
}

// Get, const
Handle2ConstDecayData
ConfigurationDecayDataGetConst(ConstHandle2ConstConfiguration This)
{
   return detail::getField<CPP,Handle2ConstDecayData>
      (CLASSNAME, CLASSNAME+"DecayDataGetConst", This, extract::decayData);
}

// Get, non-const
Handle2DecayData
ConfigurationDecayDataGet(ConstHandle2Configuration This)
{
   return detail::getField<CPP,Handle2DecayData>
      (CLASSNAME, CLASSNAME+"DecayDataGet", This, extract::decayData);
}

// Set
void
ConfigurationDecayDataSet(ConstHandle2Configuration This, ConstHandle2ConstDecayData decayData)
{
   detail::setField<CPP,CPPDecayData>
      (CLASSNAME, CLASSNAME+"DecayDataSet", This, extract::decayData, decayData);
}
