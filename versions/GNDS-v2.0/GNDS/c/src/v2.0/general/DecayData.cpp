
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/DecayData.hpp"
#include "DecayData.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = DecayDataClass;
using CPP = multigroup::DecayData;

static const std::string CLASSNAME = "DecayData";

namespace extract {
   static auto decayModes = [](auto &obj) { return &obj.decayModes; };
   static auto averageEnergies = [](auto &obj) { return &obj.averageEnergies; };
}

using CPPDecayModes = general::DecayModes;
using CPPAverageEnergies = general::AverageEnergies;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstDecayData
DecayDataDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2DecayData
DecayDataDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstDecayData
DecayDataCreateConst(
   ConstHandle2ConstDecayModes decayModes,
   ConstHandle2ConstAverageEnergies averageEnergies
) {
   ConstHandle2DecayData handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPDecayModes>(decayModes),
      detail::tocpp<CPPAverageEnergies>(averageEnergies)
   );
   return handle;
}

// Create, general
Handle2DecayData
DecayDataCreate(
   ConstHandle2ConstDecayModes decayModes,
   ConstHandle2ConstAverageEnergies averageEnergies
) {
   ConstHandle2DecayData handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPDecayModes>(decayModes),
      detail::tocpp<CPPAverageEnergies>(averageEnergies)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
DecayDataAssign(ConstHandle2DecayData self, ConstHandle2ConstDecayData from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
DecayDataDelete(ConstHandle2ConstDecayData self)
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
DecayDataRead(ConstHandle2DecayData self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
DecayDataWrite(ConstHandle2ConstDecayData self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
DecayDataPrint(ConstHandle2ConstDecayData self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
DecayDataPrintXML(ConstHandle2ConstDecayData self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
DecayDataPrintJSON(ConstHandle2ConstDecayData self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: decayModes
// -----------------------------------------------------------------------------

// Has
int
DecayDataDecayModesHas(ConstHandle2ConstDecayData self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DecayModesHas", self, extract::decayModes);
}

// Get, const
Handle2ConstDecayModes
DecayDataDecayModesGetConst(ConstHandle2ConstDecayData self)
{
   return detail::getField<CPP,Handle2ConstDecayModes>
      (CLASSNAME, CLASSNAME+"DecayModesGetConst", self, extract::decayModes);
}

// Get
Handle2DecayModes
DecayDataDecayModesGet(ConstHandle2DecayData self)
{
   return detail::getField<CPP,Handle2DecayModes>
      (CLASSNAME, CLASSNAME+"DecayModesGet", self, extract::decayModes);
}

// Set
void
DecayDataDecayModesSet(ConstHandle2DecayData self, ConstHandle2ConstDecayModes decayModes)
{
   detail::setField<CPP,CPPDecayModes>
      (CLASSNAME, CLASSNAME+"DecayModesSet", self, extract::decayModes, decayModes);
}


// -----------------------------------------------------------------------------
// Child: averageEnergies
// -----------------------------------------------------------------------------

// Has
int
DecayDataAverageEnergiesHas(ConstHandle2ConstDecayData self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AverageEnergiesHas", self, extract::averageEnergies);
}

// Get, const
Handle2ConstAverageEnergies
DecayDataAverageEnergiesGetConst(ConstHandle2ConstDecayData self)
{
   return detail::getField<CPP,Handle2ConstAverageEnergies>
      (CLASSNAME, CLASSNAME+"AverageEnergiesGetConst", self, extract::averageEnergies);
}

// Get
Handle2AverageEnergies
DecayDataAverageEnergiesGet(ConstHandle2DecayData self)
{
   return detail::getField<CPP,Handle2AverageEnergies>
      (CLASSNAME, CLASSNAME+"AverageEnergiesGet", self, extract::averageEnergies);
}

// Set
void
DecayDataAverageEnergiesSet(ConstHandle2DecayData self, ConstHandle2ConstAverageEnergies averageEnergies)
{
   detail::setField<CPP,CPPAverageEnergies>
      (CLASSNAME, CLASSNAME+"AverageEnergiesSet", self, extract::averageEnergies, averageEnergies);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/DecayData/src/custom.cpp"
