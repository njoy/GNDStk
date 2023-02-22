
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/FissionComponent.hpp"
#include "FissionComponent.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = FissionComponentClass;
using CPP = multigroup::FissionComponent;

static const std::string CLASSNAME = "FissionComponent";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto ENDF_MT = [](auto &obj) { return &obj.ENDF_MT; };
   static auto fissionGenre = [](auto &obj) { return &obj.fissionGenre; };
   static auto crossSection = [](auto &obj) { return &obj.crossSection; };
   static auto outputChannel = [](auto &obj) { return &obj.outputChannel; };
}

using CPPCrossSection = general::CrossSection;
using CPPOutputChannel = general::OutputChannel;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstFissionComponent
FissionComponentDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2FissionComponent
FissionComponentDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstFissionComponent
FissionComponentCreateConst(
   const char *const label,
   const int ENDF_MT,
   const char *const fissionGenre,
   ConstHandle2ConstCrossSection crossSection,
   ConstHandle2ConstOutputChannel outputChannel
) {
   ConstHandle2FissionComponent handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      ENDF_MT,
      fissionGenre,
      detail::tocpp<CPPCrossSection>(crossSection),
      detail::tocpp<CPPOutputChannel>(outputChannel)
   );
   return handle;
}

// Create, general
Handle2FissionComponent
FissionComponentCreate(
   const char *const label,
   const int ENDF_MT,
   const char *const fissionGenre,
   ConstHandle2ConstCrossSection crossSection,
   ConstHandle2ConstOutputChannel outputChannel
) {
   ConstHandle2FissionComponent handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      ENDF_MT,
      fissionGenre,
      detail::tocpp<CPPCrossSection>(crossSection),
      detail::tocpp<CPPOutputChannel>(outputChannel)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
FissionComponentAssign(ConstHandle2FissionComponent self, ConstHandle2ConstFissionComponent from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
FissionComponentDelete(ConstHandle2ConstFissionComponent self)
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
FissionComponentRead(ConstHandle2FissionComponent self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
FissionComponentWrite(ConstHandle2ConstFissionComponent self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
FissionComponentPrint(ConstHandle2ConstFissionComponent self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
FissionComponentPrintXML(ConstHandle2ConstFissionComponent self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
FissionComponentPrintJSON(ConstHandle2ConstFissionComponent self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
FissionComponentLabelHas(ConstHandle2ConstFissionComponent self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
const char *
FissionComponentLabelGet(ConstHandle2ConstFissionComponent self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
FissionComponentLabelSet(ConstHandle2FissionComponent self, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: ENDF_MT
// -----------------------------------------------------------------------------

// Has
int
FissionComponentENDFMTHas(ConstHandle2ConstFissionComponent self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ENDFMTHas", self, extract::ENDF_MT);
}

// Get
// Returns by value
int
FissionComponentENDFMTGet(ConstHandle2ConstFissionComponent self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ENDFMTGet", self, extract::ENDF_MT);
}

// Set
void
FissionComponentENDFMTSet(ConstHandle2FissionComponent self, const int ENDF_MT)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ENDFMTSet", self, extract::ENDF_MT, ENDF_MT);
}


// -----------------------------------------------------------------------------
// Metadatum: fissionGenre
// -----------------------------------------------------------------------------

// Has
int
FissionComponentFissionGenreHas(ConstHandle2ConstFissionComponent self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"FissionGenreHas", self, extract::fissionGenre);
}

// Get
// Returns by value
const char *
FissionComponentFissionGenreGet(ConstHandle2ConstFissionComponent self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"FissionGenreGet", self, extract::fissionGenre);
}

// Set
void
FissionComponentFissionGenreSet(ConstHandle2FissionComponent self, const char *const fissionGenre)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"FissionGenreSet", self, extract::fissionGenre, fissionGenre);
}


// -----------------------------------------------------------------------------
// Child: crossSection
// -----------------------------------------------------------------------------

// Has
int
FissionComponentCrossSectionHas(ConstHandle2ConstFissionComponent self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CrossSectionHas", self, extract::crossSection);
}

// Get, const
Handle2ConstCrossSection
FissionComponentCrossSectionGetConst(ConstHandle2ConstFissionComponent self)
{
   return detail::getField<CPP,Handle2ConstCrossSection>
      (CLASSNAME, CLASSNAME+"CrossSectionGetConst", self, extract::crossSection);
}

// Get, non-const
Handle2CrossSection
FissionComponentCrossSectionGet(ConstHandle2FissionComponent self)
{
   return detail::getField<CPP,Handle2CrossSection>
      (CLASSNAME, CLASSNAME+"CrossSectionGet", self, extract::crossSection);
}

// Set
void
FissionComponentCrossSectionSet(ConstHandle2FissionComponent self, ConstHandle2ConstCrossSection crossSection)
{
   detail::setField<CPP,CPPCrossSection>
      (CLASSNAME, CLASSNAME+"CrossSectionSet", self, extract::crossSection, crossSection);
}


// -----------------------------------------------------------------------------
// Child: outputChannel
// -----------------------------------------------------------------------------

// Has
int
FissionComponentOutputChannelHas(ConstHandle2ConstFissionComponent self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"OutputChannelHas", self, extract::outputChannel);
}

// Get, const
Handle2ConstOutputChannel
FissionComponentOutputChannelGetConst(ConstHandle2ConstFissionComponent self)
{
   return detail::getField<CPP,Handle2ConstOutputChannel>
      (CLASSNAME, CLASSNAME+"OutputChannelGetConst", self, extract::outputChannel);
}

// Get, non-const
Handle2OutputChannel
FissionComponentOutputChannelGet(ConstHandle2FissionComponent self)
{
   return detail::getField<CPP,Handle2OutputChannel>
      (CLASSNAME, CLASSNAME+"OutputChannelGet", self, extract::outputChannel);
}

// Set
void
FissionComponentOutputChannelSet(ConstHandle2FissionComponent self, ConstHandle2ConstOutputChannel outputChannel)
{
   detail::setField<CPP,CPPOutputChannel>
      (CLASSNAME, CLASSNAME+"OutputChannelSet", self, extract::outputChannel, outputChannel);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/FissionComponent/src/custom.cpp"