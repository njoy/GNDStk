
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2.0/pops/Configurations.hpp"
#include "Configurations.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = ConfigurationsClass;
using CPP = multigroup::Configurations;

static const std::string CLASSNAME = "Configurations";

namespace extract {
   static auto configuration = [](auto &obj) { return &obj.configuration; };
}

using CPPConfiguration = pops::Configuration;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstConfigurations
ConfigurationsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Configurations
ConfigurationsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstConfigurations
ConfigurationsCreateConst(
   ConstHandle2Configuration *const configuration, const size_t configurationSize
) {
   ConstHandle2Configurations handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPConfiguration>{}
   );
   for (size_t ConfigurationN = 0; ConfigurationN < configurationSize; ++ConfigurationN)
      ConfigurationsConfigurationAdd(handle, configuration[ConfigurationN]);
   return handle;
}

// Create, general
Handle2Configurations
ConfigurationsCreate(
   ConstHandle2Configuration *const configuration, const size_t configurationSize
) {
   ConstHandle2Configurations handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPConfiguration>{}
   );
   for (size_t ConfigurationN = 0; ConfigurationN < configurationSize; ++ConfigurationN)
      ConfigurationsConfigurationAdd(handle, configuration[ConfigurationN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ConfigurationsAssign(ConstHandle2Configurations self, ConstHandle2ConstConfigurations from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ConfigurationsDelete(ConstHandle2ConstConfigurations self)
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
ConfigurationsRead(ConstHandle2Configurations self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ConfigurationsWrite(ConstHandle2ConstConfigurations self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ConfigurationsPrint(ConstHandle2ConstConfigurations self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ConfigurationsPrintXML(ConstHandle2ConstConfigurations self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ConfigurationsPrintJSON(ConstHandle2ConstConfigurations self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: configuration
// -----------------------------------------------------------------------------

// Has
int
ConfigurationsConfigurationHas(ConstHandle2ConstConfigurations self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ConfigurationHas", self, extract::configuration);
}

// Clear
void
ConfigurationsConfigurationClear(ConstHandle2Configurations self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"ConfigurationClear", self, extract::configuration);
}

// Size
size_t
ConfigurationsConfigurationSize(ConstHandle2ConstConfigurations self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"ConfigurationSize", self, extract::configuration);
}

// Add
void
ConfigurationsConfigurationAdd(ConstHandle2Configurations self, ConstHandle2ConstConfiguration configuration)
{
   detail::addToContainer<CPP,CPPConfiguration>
      (CLASSNAME, CLASSNAME+"ConfigurationAdd", self, extract::configuration, configuration);
}

// Get, by index \in [0,size), const
Handle2ConstConfiguration
ConfigurationsConfigurationGetConst(ConstHandle2ConstConfigurations self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstConfiguration>
      (CLASSNAME, CLASSNAME+"ConfigurationGetConst", self, extract::configuration, index_);
}

// Get, by index \in [0,size), non-const
Handle2Configuration
ConfigurationsConfigurationGet(ConstHandle2Configurations self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Configuration>
      (CLASSNAME, CLASSNAME+"ConfigurationGet", self, extract::configuration, index_);
}

// Set, by index \in [0,size)
void
ConfigurationsConfigurationSet(
   ConstHandle2Configurations self,
   const size_t index_,
   ConstHandle2ConstConfiguration configuration
) {
   detail::setByIndex<CPP,CPPConfiguration>
      (CLASSNAME, CLASSNAME+"ConfigurationSet", self, extract::configuration, index_, configuration);
}

// Has, by subshell
int
ConfigurationsConfigurationHasBySubshell(
   ConstHandle2ConstConfigurations self,
   const char *const subshell
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ConfigurationHasBySubshell",
       self, extract::configuration, meta::subshell, subshell);
}

// Get, by subshell, const
Handle2ConstConfiguration
ConfigurationsConfigurationGetBySubshellConst(
   ConstHandle2ConstConfigurations self,
   const char *const subshell
) {
   return detail::getByMetadatum<CPP,Handle2ConstConfiguration>
      (CLASSNAME, CLASSNAME+"ConfigurationGetBySubshellConst",
       self, extract::configuration, meta::subshell, subshell);
}

// Get, by subshell, non-const
Handle2Configuration
ConfigurationsConfigurationGetBySubshell(
   ConstHandle2Configurations self,
   const char *const subshell
) {
   return detail::getByMetadatum<CPP,Handle2Configuration>
      (CLASSNAME, CLASSNAME+"ConfigurationGetBySubshell",
       self, extract::configuration, meta::subshell, subshell);
}

// Set, by subshell
void
ConfigurationsConfigurationSetBySubshell(
   ConstHandle2Configurations self,
   const char *const subshell,
   ConstHandle2ConstConfiguration configuration
) {
   detail::setByMetadatum<CPP,CPPConfiguration>
      (CLASSNAME, CLASSNAME+"ConfigurationSetBySubshell",
       self, extract::configuration, meta::subshell, subshell, configuration);
}

// Has, by electronNumber
int
ConfigurationsConfigurationHasByElectronNumber(
   ConstHandle2ConstConfigurations self,
   const Float64 electronNumber
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ConfigurationHasByElectronNumber",
       self, extract::configuration, meta::electronNumber, electronNumber);
}

// Get, by electronNumber, const
Handle2ConstConfiguration
ConfigurationsConfigurationGetByElectronNumberConst(
   ConstHandle2ConstConfigurations self,
   const Float64 electronNumber
) {
   return detail::getByMetadatum<CPP,Handle2ConstConfiguration>
      (CLASSNAME, CLASSNAME+"ConfigurationGetByElectronNumberConst",
       self, extract::configuration, meta::electronNumber, electronNumber);
}

// Get, by electronNumber, non-const
Handle2Configuration
ConfigurationsConfigurationGetByElectronNumber(
   ConstHandle2Configurations self,
   const Float64 electronNumber
) {
   return detail::getByMetadatum<CPP,Handle2Configuration>
      (CLASSNAME, CLASSNAME+"ConfigurationGetByElectronNumber",
       self, extract::configuration, meta::electronNumber, electronNumber);
}

// Set, by electronNumber
void
ConfigurationsConfigurationSetByElectronNumber(
   ConstHandle2Configurations self,
   const Float64 electronNumber,
   ConstHandle2ConstConfiguration configuration
) {
   detail::setByMetadatum<CPP,CPPConfiguration>
      (CLASSNAME, CLASSNAME+"ConfigurationSetByElectronNumber",
       self, extract::configuration, meta::electronNumber, electronNumber, configuration);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/pops/Configurations/src/custom.cpp"
