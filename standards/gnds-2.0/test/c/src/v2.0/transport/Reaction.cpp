
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2.0/transport/Reaction.hpp"
#include "Reaction.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = ReactionClass;
using CPP = multigroup::Reaction;

static const std::string CLASSNAME = "Reaction";

namespace extract {
   static auto ENDF_MT = [](auto &obj) { return &obj.ENDF_MT; };
   static auto fissionGenre = [](auto &obj) { return &obj.fissionGenre; };
   static auto label = [](auto &obj) { return &obj.label; };
   static auto doubleDifferentialCrossSection = [](auto &obj) { return &obj.doubleDifferentialCrossSection; };
   static auto crossSection = [](auto &obj) { return &obj.crossSection; };
   static auto outputChannel = [](auto &obj) { return &obj.outputChannel; };
}

using CPPDoubleDifferentialCrossSection = transport::DoubleDifferentialCrossSection;
using CPPCrossSection = transport::CrossSection;
using CPPOutputChannel = transport::OutputChannel;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstReaction
ReactionDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Reaction
ReactionDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstReaction
ReactionCreateConst(
   const Integer32 ENDF_MT,
   const XMLName fissionGenre,
   const XMLName label,
   ConstHandle2ConstDoubleDifferentialCrossSection doubleDifferentialCrossSection,
   ConstHandle2ConstCrossSection crossSection,
   ConstHandle2ConstOutputChannel outputChannel
) {
   ConstHandle2Reaction handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      ENDF_MT,
      fissionGenre,
      label,
      detail::tocpp<CPPDoubleDifferentialCrossSection>(doubleDifferentialCrossSection),
      detail::tocpp<CPPCrossSection>(crossSection),
      detail::tocpp<CPPOutputChannel>(outputChannel)
   );
   return handle;
}

// Create, general
Handle2Reaction
ReactionCreate(
   const Integer32 ENDF_MT,
   const XMLName fissionGenre,
   const XMLName label,
   ConstHandle2ConstDoubleDifferentialCrossSection doubleDifferentialCrossSection,
   ConstHandle2ConstCrossSection crossSection,
   ConstHandle2ConstOutputChannel outputChannel
) {
   ConstHandle2Reaction handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      ENDF_MT,
      fissionGenre,
      label,
      detail::tocpp<CPPDoubleDifferentialCrossSection>(doubleDifferentialCrossSection),
      detail::tocpp<CPPCrossSection>(crossSection),
      detail::tocpp<CPPOutputChannel>(outputChannel)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ReactionAssign(ConstHandle2Reaction self, ConstHandle2ConstReaction from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ReactionDelete(ConstHandle2ConstReaction self)
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
ReactionRead(ConstHandle2Reaction self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ReactionWrite(ConstHandle2ConstReaction self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ReactionPrint(ConstHandle2ConstReaction self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ReactionPrintXML(ConstHandle2ConstReaction self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ReactionPrintJSON(ConstHandle2ConstReaction self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: ENDF_MT
// -----------------------------------------------------------------------------

// Has
int
ReactionENDFMTHas(ConstHandle2ConstReaction self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ENDFMTHas", self, extract::ENDF_MT);
}

// Get
// Returns by value
Integer32
ReactionENDFMTGet(ConstHandle2ConstReaction self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ENDFMTGet", self, extract::ENDF_MT);
}

// Set
void
ReactionENDFMTSet(ConstHandle2Reaction self, const Integer32 ENDF_MT)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ENDFMTSet", self, extract::ENDF_MT, ENDF_MT);
}


// -----------------------------------------------------------------------------
// Metadatum: fissionGenre
// -----------------------------------------------------------------------------

// Has
int
ReactionFissionGenreHas(ConstHandle2ConstReaction self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"FissionGenreHas", self, extract::fissionGenre);
}

// Get
// Returns by value
XMLName
ReactionFissionGenreGet(ConstHandle2ConstReaction self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"FissionGenreGet", self, extract::fissionGenre);
}

// Set
void
ReactionFissionGenreSet(ConstHandle2Reaction self, const XMLName fissionGenre)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"FissionGenreSet", self, extract::fissionGenre, fissionGenre);
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
ReactionLabelHas(ConstHandle2ConstReaction self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
XMLName
ReactionLabelGet(ConstHandle2ConstReaction self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
ReactionLabelSet(ConstHandle2Reaction self, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Child: doubleDifferentialCrossSection
// -----------------------------------------------------------------------------

// Has
int
ReactionDoubleDifferentialCrossSectionHas(ConstHandle2ConstReaction self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DoubleDifferentialCrossSectionHas", self, extract::doubleDifferentialCrossSection);
}

// Get, const
Handle2ConstDoubleDifferentialCrossSection
ReactionDoubleDifferentialCrossSectionGetConst(ConstHandle2ConstReaction self)
{
   return detail::getField<CPP,Handle2ConstDoubleDifferentialCrossSection>
      (CLASSNAME, CLASSNAME+"DoubleDifferentialCrossSectionGetConst", self, extract::doubleDifferentialCrossSection);
}

// Get, non-const
Handle2DoubleDifferentialCrossSection
ReactionDoubleDifferentialCrossSectionGet(ConstHandle2Reaction self)
{
   return detail::getField<CPP,Handle2DoubleDifferentialCrossSection>
      (CLASSNAME, CLASSNAME+"DoubleDifferentialCrossSectionGet", self, extract::doubleDifferentialCrossSection);
}

// Set
void
ReactionDoubleDifferentialCrossSectionSet(ConstHandle2Reaction self, ConstHandle2ConstDoubleDifferentialCrossSection doubleDifferentialCrossSection)
{
   detail::setField<CPP,CPPDoubleDifferentialCrossSection>
      (CLASSNAME, CLASSNAME+"DoubleDifferentialCrossSectionSet", self, extract::doubleDifferentialCrossSection, doubleDifferentialCrossSection);
}


// -----------------------------------------------------------------------------
// Child: crossSection
// -----------------------------------------------------------------------------

// Has
int
ReactionCrossSectionHas(ConstHandle2ConstReaction self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CrossSectionHas", self, extract::crossSection);
}

// Get, const
Handle2ConstCrossSection
ReactionCrossSectionGetConst(ConstHandle2ConstReaction self)
{
   return detail::getField<CPP,Handle2ConstCrossSection>
      (CLASSNAME, CLASSNAME+"CrossSectionGetConst", self, extract::crossSection);
}

// Get, non-const
Handle2CrossSection
ReactionCrossSectionGet(ConstHandle2Reaction self)
{
   return detail::getField<CPP,Handle2CrossSection>
      (CLASSNAME, CLASSNAME+"CrossSectionGet", self, extract::crossSection);
}

// Set
void
ReactionCrossSectionSet(ConstHandle2Reaction self, ConstHandle2ConstCrossSection crossSection)
{
   detail::setField<CPP,CPPCrossSection>
      (CLASSNAME, CLASSNAME+"CrossSectionSet", self, extract::crossSection, crossSection);
}


// -----------------------------------------------------------------------------
// Child: outputChannel
// -----------------------------------------------------------------------------

// Has
int
ReactionOutputChannelHas(ConstHandle2ConstReaction self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"OutputChannelHas", self, extract::outputChannel);
}

// Get, const
Handle2ConstOutputChannel
ReactionOutputChannelGetConst(ConstHandle2ConstReaction self)
{
   return detail::getField<CPP,Handle2ConstOutputChannel>
      (CLASSNAME, CLASSNAME+"OutputChannelGetConst", self, extract::outputChannel);
}

// Get, non-const
Handle2OutputChannel
ReactionOutputChannelGet(ConstHandle2Reaction self)
{
   return detail::getField<CPP,Handle2OutputChannel>
      (CLASSNAME, CLASSNAME+"OutputChannelGet", self, extract::outputChannel);
}

// Set
void
ReactionOutputChannelSet(ConstHandle2Reaction self, ConstHandle2ConstOutputChannel outputChannel)
{
   detail::setField<CPP,CPPOutputChannel>
      (CLASSNAME, CLASSNAME+"OutputChannelSet", self, extract::outputChannel, outputChannel);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/transport/Reaction/src/custom.cpp"
