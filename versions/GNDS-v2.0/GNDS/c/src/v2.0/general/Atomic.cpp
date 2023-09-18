
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/Atomic.hpp"
#include "Atomic.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = AtomicClass;
using CPP = multigroup::Atomic;

static const std::string CLASSNAME = "Atomic";

namespace extract {
   static auto configurations = [](auto &obj) { return &obj.configurations; };
}

using CPPConfigurations = general::Configurations;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstAtomic
AtomicDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Atomic
AtomicDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstAtomic
AtomicCreateConst(
   ConstHandle2ConstConfigurations configurations
) {
   ConstHandle2Atomic handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPConfigurations>(configurations)
   );
   return handle;
}

// Create, general
Handle2Atomic
AtomicCreate(
   ConstHandle2ConstConfigurations configurations
) {
   ConstHandle2Atomic handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPConfigurations>(configurations)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
AtomicAssign(ConstHandle2Atomic self, ConstHandle2ConstAtomic from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
AtomicDelete(ConstHandle2ConstAtomic self)
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
AtomicRead(ConstHandle2Atomic self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
AtomicWrite(ConstHandle2ConstAtomic self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
AtomicPrint(ConstHandle2ConstAtomic self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
AtomicPrintXML(ConstHandle2ConstAtomic self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
AtomicPrintJSON(ConstHandle2ConstAtomic self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: configurations
// -----------------------------------------------------------------------------

// Has
int
AtomicConfigurationsHas(ConstHandle2ConstAtomic self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ConfigurationsHas", self, extract::configurations);
}

// Get, const
Handle2ConstConfigurations
AtomicConfigurationsGetConst(ConstHandle2ConstAtomic self)
{
   return detail::getField<CPP,Handle2ConstConfigurations>
      (CLASSNAME, CLASSNAME+"ConfigurationsGetConst", self, extract::configurations);
}

// Get
Handle2Configurations
AtomicConfigurationsGet(ConstHandle2Atomic self)
{
   return detail::getField<CPP,Handle2Configurations>
      (CLASSNAME, CLASSNAME+"ConfigurationsGet", self, extract::configurations);
}

// Set
void
AtomicConfigurationsSet(ConstHandle2Atomic self, ConstHandle2ConstConfigurations configurations)
{
   detail::setField<CPP,CPPConfigurations>
      (CLASSNAME, CLASSNAME+"ConfigurationsSet", self, extract::configurations, configurations);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Atomic/src/custom.cpp"
