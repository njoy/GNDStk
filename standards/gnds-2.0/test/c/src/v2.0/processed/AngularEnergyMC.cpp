
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/processed/AngularEnergyMC.hpp"
#include "AngularEnergyMC.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = AngularEnergyMCClass;
using CPP = multigroup::AngularEnergyMC;

static const std::string CLASSNAME = "AngularEnergyMC";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto productFrame = [](auto &obj) { return &obj.productFrame; };
   static auto angular_uncorrelated = [](auto &obj) { return &obj.angular_uncorrelated; };
   static auto angularEnergy = [](auto &obj) { return &obj.angularEnergy; };
}

using CPPAngular_uncorrelated = transport::Angular_uncorrelated;
using CPPAngularEnergy = transport::AngularEnergy;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstAngularEnergyMC
AngularEnergyMCDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2AngularEnergyMC
AngularEnergyMCDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstAngularEnergyMC
AngularEnergyMCCreateConst(
   const XMLName label,
   const XMLName productFrame,
   ConstHandle2ConstAngular_uncorrelated angular_uncorrelated,
   ConstHandle2ConstAngularEnergy angularEnergy
) {
   ConstHandle2AngularEnergyMC handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      productFrame,
      detail::tocpp<CPPAngular_uncorrelated>(angular_uncorrelated),
      detail::tocpp<CPPAngularEnergy>(angularEnergy)
   );
   return handle;
}

// Create, general
Handle2AngularEnergyMC
AngularEnergyMCCreate(
   const XMLName label,
   const XMLName productFrame,
   ConstHandle2ConstAngular_uncorrelated angular_uncorrelated,
   ConstHandle2ConstAngularEnergy angularEnergy
) {
   ConstHandle2AngularEnergyMC handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      productFrame,
      detail::tocpp<CPPAngular_uncorrelated>(angular_uncorrelated),
      detail::tocpp<CPPAngularEnergy>(angularEnergy)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
AngularEnergyMCAssign(ConstHandle2AngularEnergyMC This, ConstHandle2ConstAngularEnergyMC from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
AngularEnergyMCDelete(ConstHandle2ConstAngularEnergyMC This)
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
AngularEnergyMCRead(ConstHandle2AngularEnergyMC This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
AngularEnergyMCWrite(ConstHandle2ConstAngularEnergyMC This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
AngularEnergyMCPrint(ConstHandle2ConstAngularEnergyMC This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
AngularEnergyMCPrintXML(ConstHandle2ConstAngularEnergyMC This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
AngularEnergyMCPrintJSON(ConstHandle2ConstAngularEnergyMC This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
AngularEnergyMCLabelHas(ConstHandle2ConstAngularEnergyMC This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
AngularEnergyMCLabelGet(ConstHandle2ConstAngularEnergyMC This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
AngularEnergyMCLabelSet(ConstHandle2AngularEnergyMC This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: productFrame
// -----------------------------------------------------------------------------

// Has
int
AngularEnergyMCProductFrameHas(ConstHandle2ConstAngularEnergyMC This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ProductFrameHas", This, extract::productFrame);
}

// Get
// Returns by value
XMLName
AngularEnergyMCProductFrameGet(ConstHandle2ConstAngularEnergyMC This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ProductFrameGet", This, extract::productFrame);
}

// Set
void
AngularEnergyMCProductFrameSet(ConstHandle2AngularEnergyMC This, const XMLName productFrame)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ProductFrameSet", This, extract::productFrame, productFrame);
}


// -----------------------------------------------------------------------------
// Child: angular_uncorrelated
// -----------------------------------------------------------------------------

// Has
int
AngularEnergyMCAngular_uncorrelatedHas(ConstHandle2ConstAngularEnergyMC This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Angular_uncorrelatedHas", This, extract::angular_uncorrelated);
}

// Get, const
Handle2ConstAngular_uncorrelated
AngularEnergyMCAngular_uncorrelatedGetConst(ConstHandle2ConstAngularEnergyMC This)
{
   return detail::getField<CPP,Handle2ConstAngular_uncorrelated>
      (CLASSNAME, CLASSNAME+"Angular_uncorrelatedGetConst", This, extract::angular_uncorrelated);
}

// Get, non-const
Handle2Angular_uncorrelated
AngularEnergyMCAngular_uncorrelatedGet(ConstHandle2AngularEnergyMC This)
{
   return detail::getField<CPP,Handle2Angular_uncorrelated>
      (CLASSNAME, CLASSNAME+"Angular_uncorrelatedGet", This, extract::angular_uncorrelated);
}

// Set
void
AngularEnergyMCAngular_uncorrelatedSet(ConstHandle2AngularEnergyMC This, ConstHandle2ConstAngular_uncorrelated angular_uncorrelated)
{
   detail::setField<CPP,CPPAngular_uncorrelated>
      (CLASSNAME, CLASSNAME+"Angular_uncorrelatedSet", This, extract::angular_uncorrelated, angular_uncorrelated);
}


// -----------------------------------------------------------------------------
// Child: angularEnergy
// -----------------------------------------------------------------------------

// Has
int
AngularEnergyMCAngularEnergyHas(ConstHandle2ConstAngularEnergyMC This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AngularEnergyHas", This, extract::angularEnergy);
}

// Get, const
Handle2ConstAngularEnergy
AngularEnergyMCAngularEnergyGetConst(ConstHandle2ConstAngularEnergyMC This)
{
   return detail::getField<CPP,Handle2ConstAngularEnergy>
      (CLASSNAME, CLASSNAME+"AngularEnergyGetConst", This, extract::angularEnergy);
}

// Get, non-const
Handle2AngularEnergy
AngularEnergyMCAngularEnergyGet(ConstHandle2AngularEnergyMC This)
{
   return detail::getField<CPP,Handle2AngularEnergy>
      (CLASSNAME, CLASSNAME+"AngularEnergyGet", This, extract::angularEnergy);
}

// Set
void
AngularEnergyMCAngularEnergySet(ConstHandle2AngularEnergyMC This, ConstHandle2ConstAngularEnergy angularEnergy)
{
   detail::setField<CPP,CPPAngularEnergy>
      (CLASSNAME, CLASSNAME+"AngularEnergySet", This, extract::angularEnergy, angularEnergy);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/processed/AngularEnergyMC/src/custom.cpp"
