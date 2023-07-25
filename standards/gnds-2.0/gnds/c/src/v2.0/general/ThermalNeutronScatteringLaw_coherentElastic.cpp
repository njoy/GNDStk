
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "gnds/v2.0/general/ThermalNeutronScatteringLaw_coherentElastic.hpp"
#include "ThermalNeutronScatteringLaw_coherentElastic.h"

using namespace njoy::GNDStk;
using namespace gnds::v2_0;

using C = ThermalNeutronScatteringLaw_coherentElasticClass;
using CPP = multigroup::ThermalNeutronScatteringLaw_coherentElastic;

static const std::string CLASSNAME = "ThermalNeutronScatteringLaw_coherentElastic";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto pid = [](auto &obj) { return &obj.pid; };
   static auto productFrame = [](auto &obj) { return &obj.productFrame; };
   static auto S_table = [](auto &obj) { return &obj.S_table; };
}

using CPPS_table = general::S_table;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstThermalNeutronScatteringLaw_coherentElastic
ThermalNeutronScatteringLaw_coherentElasticDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2ThermalNeutronScatteringLaw_coherentElastic
ThermalNeutronScatteringLaw_coherentElasticDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstThermalNeutronScatteringLaw_coherentElastic
ThermalNeutronScatteringLaw_coherentElasticCreateConst(
   const char *const label,
   const char *const pid,
   const char *const productFrame,
   ConstHandle2ConstS_table S_table
) {
   ConstHandle2ThermalNeutronScatteringLaw_coherentElastic handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      pid,
      productFrame,
      detail::tocpp<CPPS_table>(S_table)
   );
   return handle;
}

// Create, general
Handle2ThermalNeutronScatteringLaw_coherentElastic
ThermalNeutronScatteringLaw_coherentElasticCreate(
   const char *const label,
   const char *const pid,
   const char *const productFrame,
   ConstHandle2ConstS_table S_table
) {
   ConstHandle2ThermalNeutronScatteringLaw_coherentElastic handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      pid,
      productFrame,
      detail::tocpp<CPPS_table>(S_table)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ThermalNeutronScatteringLaw_coherentElasticAssign(ConstHandle2ThermalNeutronScatteringLaw_coherentElastic self, ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ThermalNeutronScatteringLaw_coherentElasticDelete(ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic self)
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
ThermalNeutronScatteringLaw_coherentElasticRead(ConstHandle2ThermalNeutronScatteringLaw_coherentElastic self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ThermalNeutronScatteringLaw_coherentElasticWrite(ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ThermalNeutronScatteringLaw_coherentElasticPrint(ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ThermalNeutronScatteringLaw_coherentElasticPrintXML(ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ThermalNeutronScatteringLaw_coherentElasticPrintJSON(ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
ThermalNeutronScatteringLaw_coherentElasticLabelHas(ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
const char *
ThermalNeutronScatteringLaw_coherentElasticLabelGet(ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
ThermalNeutronScatteringLaw_coherentElasticLabelSet(ConstHandle2ThermalNeutronScatteringLaw_coherentElastic self, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: pid
// -----------------------------------------------------------------------------

// Has
int
ThermalNeutronScatteringLaw_coherentElasticPidHas(ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"PidHas", self, extract::pid);
}

// Get
// Returns by value
const char *
ThermalNeutronScatteringLaw_coherentElasticPidGet(ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"PidGet", self, extract::pid);
}

// Set
void
ThermalNeutronScatteringLaw_coherentElasticPidSet(ConstHandle2ThermalNeutronScatteringLaw_coherentElastic self, const char *const pid)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"PidSet", self, extract::pid, pid);
}


// -----------------------------------------------------------------------------
// Metadatum: productFrame
// -----------------------------------------------------------------------------

// Has
int
ThermalNeutronScatteringLaw_coherentElasticProductFrameHas(ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ProductFrameHas", self, extract::productFrame);
}

// Get
// Returns by value
const char *
ThermalNeutronScatteringLaw_coherentElasticProductFrameGet(ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ProductFrameGet", self, extract::productFrame);
}

// Set
void
ThermalNeutronScatteringLaw_coherentElasticProductFrameSet(ConstHandle2ThermalNeutronScatteringLaw_coherentElastic self, const char *const productFrame)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ProductFrameSet", self, extract::productFrame, productFrame);
}


// -----------------------------------------------------------------------------
// Child: S_table
// -----------------------------------------------------------------------------

// Has
int
ThermalNeutronScatteringLaw_coherentElasticS_tableHas(ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"S_tableHas", self, extract::S_table);
}

// Get, const
Handle2ConstS_table
ThermalNeutronScatteringLaw_coherentElasticS_tableGetConst(ConstHandle2ConstThermalNeutronScatteringLaw_coherentElastic self)
{
   return detail::getField<CPP,Handle2ConstS_table>
      (CLASSNAME, CLASSNAME+"S_tableGetConst", self, extract::S_table);
}

// Get, non-const
Handle2S_table
ThermalNeutronScatteringLaw_coherentElasticS_tableGet(ConstHandle2ThermalNeutronScatteringLaw_coherentElastic self)
{
   return detail::getField<CPP,Handle2S_table>
      (CLASSNAME, CLASSNAME+"S_tableGet", self, extract::S_table);
}

// Set
void
ThermalNeutronScatteringLaw_coherentElasticS_tableSet(ConstHandle2ThermalNeutronScatteringLaw_coherentElastic self, ConstHandle2ConstS_table S_table)
{
   detail::setField<CPP,CPPS_table>
      (CLASSNAME, CLASSNAME+"S_tableSet", self, extract::S_table, S_table);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/ThermalNeutronScatteringLaw_coherentElastic/src/custom.cpp"
