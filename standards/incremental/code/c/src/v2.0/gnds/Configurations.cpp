
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "code/v2_0/gnds/Configurations.hpp"
#include "Configurations.h"

using namespace njoy::GNDStk;
using namespace code::v2_0;

using C = ConfigurationsClass;
using CPP = multigroup::Configurations;

static const std::string CLASSNAME = "Configurations";

namespace extract {
   static auto configuration = [](auto &obj) { return &obj.configuration; };
}

using CPPConfiguration = gnds::Configuration;


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
ConfigurationsAssign(ConstHandle2Configurations This, ConstHandle2ConstConfigurations from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ConfigurationsDelete(ConstHandle2ConstConfigurations This)
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
ConfigurationsRead(ConstHandle2Configurations This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ConfigurationsWrite(ConstHandle2ConstConfigurations This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
ConfigurationsPrint(ConstHandle2ConstConfigurations This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
ConfigurationsPrintXML(ConstHandle2ConstConfigurations This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
ConfigurationsPrintJSON(ConstHandle2ConstConfigurations This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: configuration
// -----------------------------------------------------------------------------

// Has
int
ConfigurationsConfigurationHas(ConstHandle2ConstConfigurations This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ConfigurationHas", This, extract::configuration);
}

// Clear
void
ConfigurationsConfigurationClear(ConstHandle2Configurations This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"ConfigurationClear", This, extract::configuration);
}

// Size
size_t
ConfigurationsConfigurationSize(ConstHandle2ConstConfigurations This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"ConfigurationSize", This, extract::configuration);
}

// Add
void
ConfigurationsConfigurationAdd(ConstHandle2Configurations This, ConstHandle2ConstConfiguration configuration)
{
   detail::addToContainer<CPP,CPPConfiguration>
      (CLASSNAME, CLASSNAME+"ConfigurationAdd", This, extract::configuration, configuration);
}

// Get, by index \in [0,size), const
Handle2ConstConfiguration
ConfigurationsConfigurationGetConst(ConstHandle2ConstConfigurations This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstConfiguration>
      (CLASSNAME, CLASSNAME+"ConfigurationGetConst", This, extract::configuration, index_);
}

// Get, by index \in [0,size), non-const
Handle2Configuration
ConfigurationsConfigurationGet(ConstHandle2Configurations This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Configuration>
      (CLASSNAME, CLASSNAME+"ConfigurationGet", This, extract::configuration, index_);
}

// Set, by index \in [0,size)
void
ConfigurationsConfigurationSet(
   ConstHandle2Configurations This,
   const size_t index_,
   ConstHandle2ConstConfiguration configuration
) {
   detail::setByIndex<CPP,CPPConfiguration>
      (CLASSNAME, CLASSNAME+"ConfigurationSet", This, extract::configuration, index_, configuration);
}

// Has, by subshell
int
ConfigurationsConfigurationHasBySubshell(
   ConstHandle2ConstConfigurations This,
   const char *const subshell
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ConfigurationHasBySubshell",
       This, extract::configuration, meta::subshell, subshell);
}

// Get, by subshell, const
Handle2ConstConfiguration
ConfigurationsConfigurationGetBySubshellConst(
   ConstHandle2ConstConfigurations This,
   const char *const subshell
) {
   return detail::getByMetadatum<CPP,Handle2ConstConfiguration>
      (CLASSNAME, CLASSNAME+"ConfigurationGetBySubshellConst",
       This, extract::configuration, meta::subshell, subshell);
}

// Get, by subshell, non-const
Handle2Configuration
ConfigurationsConfigurationGetBySubshell(
   ConstHandle2Configurations This,
   const char *const subshell
) {
   return detail::getByMetadatum<CPP,Handle2Configuration>
      (CLASSNAME, CLASSNAME+"ConfigurationGetBySubshell",
       This, extract::configuration, meta::subshell, subshell);
}

// Set, by subshell
void
ConfigurationsConfigurationSetBySubshell(
   ConstHandle2Configurations This,
   const char *const subshell,
   ConstHandle2ConstConfiguration configuration
) {
   detail::setByMetadatum<CPP,CPPConfiguration>
      (CLASSNAME, CLASSNAME+"ConfigurationSetBySubshell",
       This, extract::configuration, meta::subshell, subshell, configuration);
}

// Has, by electronNumber
int
ConfigurationsConfigurationHasByElectronNumber(
   ConstHandle2ConstConfigurations This,
   const char *const electronNumber
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ConfigurationHasByElectronNumber",
       This, extract::configuration, meta::electronNumber, electronNumber);
}

// Get, by electronNumber, const
Handle2ConstConfiguration
ConfigurationsConfigurationGetByElectronNumberConst(
   ConstHandle2ConstConfigurations This,
   const char *const electronNumber
) {
   return detail::getByMetadatum<CPP,Handle2ConstConfiguration>
      (CLASSNAME, CLASSNAME+"ConfigurationGetByElectronNumberConst",
       This, extract::configuration, meta::electronNumber, electronNumber);
}

// Get, by electronNumber, non-const
Handle2Configuration
ConfigurationsConfigurationGetByElectronNumber(
   ConstHandle2Configurations This,
   const char *const electronNumber
) {
   return detail::getByMetadatum<CPP,Handle2Configuration>
      (CLASSNAME, CLASSNAME+"ConfigurationGetByElectronNumber",
       This, extract::configuration, meta::electronNumber, electronNumber);
}

// Set, by electronNumber
void
ConfigurationsConfigurationSetByElectronNumber(
   ConstHandle2Configurations This,
   const char *const electronNumber,
   ConstHandle2ConstConfiguration configuration
) {
   detail::setByMetadatum<CPP,CPPConfiguration>
      (CLASSNAME, CLASSNAME+"ConfigurationSetByElectronNumber",
       This, extract::configuration, meta::electronNumber, electronNumber, configuration);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/gnds/Configurations/src/custom.cpp"
