
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/Configuration.hpp"
#include "Configuration.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = ConfigurationClass;
using CPP = multigroup::Configuration;

static const std::string CLASSNAME = "Configuration";

namespace extract {
   static auto subshell = [](auto &obj) { return &obj.subshell; };
   static auto electronNumber = [](auto &obj) { return &obj.electronNumber; };
   static auto bindingEnergy = [](auto &obj) { return &obj.bindingEnergy; };
   static auto decayData = [](auto &obj) { return &obj.decayData; };
}

using CPPBindingEnergy = general::BindingEnergy;
using CPPDecayData = general::DecayData;


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

// Create, default, non-const
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
   const double electronNumber,
   ConstHandle2ConstBindingEnergy bindingEnergy,
   ConstHandle2DecayData *const decayData, const size_t decayDataSize
) {
   ConstHandle2Configuration handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      subshell,
      electronNumber,
      detail::tocpp<CPPBindingEnergy>(bindingEnergy),
      std::vector<CPPDecayData>{}
   );
   for (size_t DecayDataN = 0; DecayDataN < decayDataSize; ++DecayDataN)
      ConfigurationDecayDataAdd(handle, decayData[DecayDataN]);
   return handle;
}

// Create, general, non-const
Handle2Configuration
ConfigurationCreate(
   const char *const subshell,
   const double electronNumber,
   ConstHandle2ConstBindingEnergy bindingEnergy,
   ConstHandle2DecayData *const decayData, const size_t decayDataSize
) {
   ConstHandle2Configuration handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      subshell,
      electronNumber,
      detail::tocpp<CPPBindingEnergy>(bindingEnergy),
      std::vector<CPPDecayData>{}
   );
   for (size_t DecayDataN = 0; DecayDataN < decayDataSize; ++DecayDataN)
      ConfigurationDecayDataAdd(handle, decayData[DecayDataN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ConfigurationAssign(ConstHandle2Configuration self, ConstHandle2ConstConfiguration from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ConfigurationDelete(ConstHandle2ConstConfiguration self)
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
ConfigurationRead(ConstHandle2Configuration self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ConfigurationWrite(ConstHandle2ConstConfiguration self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ConfigurationPrint(ConstHandle2ConstConfiguration self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ConfigurationPrintXML(ConstHandle2ConstConfiguration self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ConfigurationPrintJSON(ConstHandle2ConstConfiguration self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: subshell
// -----------------------------------------------------------------------------

// Has
int
ConfigurationSubshellHas(ConstHandle2ConstConfiguration self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SubshellHas", self, extract::subshell);
}

// Get
// Returns by value
const char *
ConfigurationSubshellGet(ConstHandle2ConstConfiguration self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"SubshellGet", self, extract::subshell);
}

// Set
void
ConfigurationSubshellSet(ConstHandle2Configuration self, const char *const subshell)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"SubshellSet", self, extract::subshell, subshell);
}


// -----------------------------------------------------------------------------
// Metadatum: electronNumber
// -----------------------------------------------------------------------------

// Has
int
ConfigurationElectronNumberHas(ConstHandle2ConstConfiguration self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ElectronNumberHas", self, extract::electronNumber);
}

// Get
// Returns by value
double
ConfigurationElectronNumberGet(ConstHandle2ConstConfiguration self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ElectronNumberGet", self, extract::electronNumber);
}

// Set
void
ConfigurationElectronNumberSet(ConstHandle2Configuration self, const double electronNumber)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ElectronNumberSet", self, extract::electronNumber, electronNumber);
}


// -----------------------------------------------------------------------------
// Child: bindingEnergy
// -----------------------------------------------------------------------------

// Has
int
ConfigurationBindingEnergyHas(ConstHandle2ConstConfiguration self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"BindingEnergyHas", self, extract::bindingEnergy);
}

// Get, const
Handle2ConstBindingEnergy
ConfigurationBindingEnergyGetConst(ConstHandle2ConstConfiguration self)
{
   return detail::getField<CPP,Handle2ConstBindingEnergy>
      (CLASSNAME, CLASSNAME+"BindingEnergyGetConst", self, extract::bindingEnergy);
}

// Get, non-const
Handle2BindingEnergy
ConfigurationBindingEnergyGet(ConstHandle2Configuration self)
{
   return detail::getField<CPP,Handle2BindingEnergy>
      (CLASSNAME, CLASSNAME+"BindingEnergyGet", self, extract::bindingEnergy);
}

// Set
void
ConfigurationBindingEnergySet(ConstHandle2Configuration self, ConstHandle2ConstBindingEnergy bindingEnergy)
{
   detail::setField<CPP,CPPBindingEnergy>
      (CLASSNAME, CLASSNAME+"BindingEnergySet", self, extract::bindingEnergy, bindingEnergy);
}


// -----------------------------------------------------------------------------
// Child: decayData
// -----------------------------------------------------------------------------

// Has
int
ConfigurationDecayDataHas(ConstHandle2ConstConfiguration self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DecayDataHas", self, extract::decayData);
}

// Clear
void
ConfigurationDecayDataClear(ConstHandle2Configuration self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"DecayDataClear", self, extract::decayData);
}

// Size
size_t
ConfigurationDecayDataSize(ConstHandle2ConstConfiguration self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"DecayDataSize", self, extract::decayData);
}

// Add
void
ConfigurationDecayDataAdd(ConstHandle2Configuration self, ConstHandle2ConstDecayData decayData)
{
   detail::addToContainer<CPP,CPPDecayData>
      (CLASSNAME, CLASSNAME+"DecayDataAdd", self, extract::decayData, decayData);
}

// Get, by index \in [0,size), const
Handle2ConstDecayData
ConfigurationDecayDataGetConst(ConstHandle2ConstConfiguration self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstDecayData>
      (CLASSNAME, CLASSNAME+"DecayDataGetConst", self, extract::decayData, index_);
}

// Get, by index \in [0,size), non-const
Handle2DecayData
ConfigurationDecayDataGet(ConstHandle2Configuration self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2DecayData>
      (CLASSNAME, CLASSNAME+"DecayDataGet", self, extract::decayData, index_);
}

// Set, by index \in [0,size)
void
ConfigurationDecayDataSet(
   ConstHandle2Configuration self,
   const size_t index_,
   ConstHandle2ConstDecayData decayData
) {
   detail::setByIndex<CPP,CPPDecayData>
      (CLASSNAME, CLASSNAME+"DecayDataSet", self, extract::decayData, index_, decayData);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Configuration/src/custom.cpp"
