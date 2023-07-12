
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2.0/transport/Production.hpp"
#include "Production.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = ProductionClass;
using CPP = multigroup::Production;

static const std::string CLASSNAME = "Production";

namespace extract {
   static auto ENDF_MT = [](auto &obj) { return &obj.ENDF_MT; };
   static auto label = [](auto &obj) { return &obj.label; };
   static auto crossSection = [](auto &obj) { return &obj.crossSection; };
   static auto outputChannel = [](auto &obj) { return &obj.outputChannel; };
}

using CPPCrossSection = transport::CrossSection;
using CPPOutputChannel = transport::OutputChannel;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstProduction
ProductionDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Production
ProductionDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstProduction
ProductionCreateConst(
   const Integer32 ENDF_MT,
   const XMLName label,
   ConstHandle2ConstCrossSection crossSection,
   ConstHandle2ConstOutputChannel outputChannel
) {
   ConstHandle2Production handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      ENDF_MT,
      label,
      detail::tocpp<CPPCrossSection>(crossSection),
      detail::tocpp<CPPOutputChannel>(outputChannel)
   );
   return handle;
}

// Create, general
Handle2Production
ProductionCreate(
   const Integer32 ENDF_MT,
   const XMLName label,
   ConstHandle2ConstCrossSection crossSection,
   ConstHandle2ConstOutputChannel outputChannel
) {
   ConstHandle2Production handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      ENDF_MT,
      label,
      detail::tocpp<CPPCrossSection>(crossSection),
      detail::tocpp<CPPOutputChannel>(outputChannel)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ProductionAssign(ConstHandle2Production self, ConstHandle2ConstProduction from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ProductionDelete(ConstHandle2ConstProduction self)
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
ProductionRead(ConstHandle2Production self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ProductionWrite(ConstHandle2ConstProduction self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ProductionPrint(ConstHandle2ConstProduction self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ProductionPrintXML(ConstHandle2ConstProduction self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ProductionPrintJSON(ConstHandle2ConstProduction self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: ENDF_MT
// -----------------------------------------------------------------------------

// Has
int
ProductionENDFMTHas(ConstHandle2ConstProduction self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ENDFMTHas", self, extract::ENDF_MT);
}

// Get
// Returns by value
Integer32
ProductionENDFMTGet(ConstHandle2ConstProduction self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ENDFMTGet", self, extract::ENDF_MT);
}

// Set
void
ProductionENDFMTSet(ConstHandle2Production self, const Integer32 ENDF_MT)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ENDFMTSet", self, extract::ENDF_MT, ENDF_MT);
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
ProductionLabelHas(ConstHandle2ConstProduction self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
XMLName
ProductionLabelGet(ConstHandle2ConstProduction self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
ProductionLabelSet(ConstHandle2Production self, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Child: crossSection
// -----------------------------------------------------------------------------

// Has
int
ProductionCrossSectionHas(ConstHandle2ConstProduction self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CrossSectionHas", self, extract::crossSection);
}

// Get, const
Handle2ConstCrossSection
ProductionCrossSectionGetConst(ConstHandle2ConstProduction self)
{
   return detail::getField<CPP,Handle2ConstCrossSection>
      (CLASSNAME, CLASSNAME+"CrossSectionGetConst", self, extract::crossSection);
}

// Get, non-const
Handle2CrossSection
ProductionCrossSectionGet(ConstHandle2Production self)
{
   return detail::getField<CPP,Handle2CrossSection>
      (CLASSNAME, CLASSNAME+"CrossSectionGet", self, extract::crossSection);
}

// Set
void
ProductionCrossSectionSet(ConstHandle2Production self, ConstHandle2ConstCrossSection crossSection)
{
   detail::setField<CPP,CPPCrossSection>
      (CLASSNAME, CLASSNAME+"CrossSectionSet", self, extract::crossSection, crossSection);
}


// -----------------------------------------------------------------------------
// Child: outputChannel
// -----------------------------------------------------------------------------

// Has
int
ProductionOutputChannelHas(ConstHandle2ConstProduction self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"OutputChannelHas", self, extract::outputChannel);
}

// Get, const
Handle2ConstOutputChannel
ProductionOutputChannelGetConst(ConstHandle2ConstProduction self)
{
   return detail::getField<CPP,Handle2ConstOutputChannel>
      (CLASSNAME, CLASSNAME+"OutputChannelGetConst", self, extract::outputChannel);
}

// Get, non-const
Handle2OutputChannel
ProductionOutputChannelGet(ConstHandle2Production self)
{
   return detail::getField<CPP,Handle2OutputChannel>
      (CLASSNAME, CLASSNAME+"OutputChannelGet", self, extract::outputChannel);
}

// Set
void
ProductionOutputChannelSet(ConstHandle2Production self, ConstHandle2ConstOutputChannel outputChannel)
{
   detail::setField<CPP,CPPOutputChannel>
      (CLASSNAME, CLASSNAME+"OutputChannelSet", self, extract::outputChannel, outputChannel);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/transport/Production/src/custom.cpp"
