
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/top/FissionFragmentData.hpp"
#include "FissionFragmentData.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = FissionFragmentDataClass;
using CPP = multigroup::FissionFragmentData;

static const std::string CLASSNAME = "FissionFragmentData";

namespace extract {
   static auto productYields = [](auto &obj) { return &obj.productYields; };
   static auto delayedNeutrons = [](auto &obj) { return &obj.delayedNeutrons; };
   static auto fissionEnergyReleases = [](auto &obj) { return &obj.fissionEnergyReleases; };
}

using CPPProductYields = general::ProductYields;
using CPPDelayedNeutrons = general::DelayedNeutrons;
using CPPFissionEnergyReleases = general::FissionEnergyReleases;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstFissionFragmentData
FissionFragmentDataDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default, non-const
Handle2FissionFragmentData
FissionFragmentDataDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstFissionFragmentData
FissionFragmentDataCreateConst(
   ConstHandle2ConstProductYields productYields,
   ConstHandle2ConstDelayedNeutrons delayedNeutrons,
   ConstHandle2ConstFissionEnergyReleases fissionEnergyReleases
) {
   ConstHandle2FissionFragmentData handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPProductYields>(productYields),
      detail::tocpp<CPPDelayedNeutrons>(delayedNeutrons),
      detail::tocpp<CPPFissionEnergyReleases>(fissionEnergyReleases)
   );
   return handle;
}

// Create, general, non-const
Handle2FissionFragmentData
FissionFragmentDataCreate(
   ConstHandle2ConstProductYields productYields,
   ConstHandle2ConstDelayedNeutrons delayedNeutrons,
   ConstHandle2ConstFissionEnergyReleases fissionEnergyReleases
) {
   ConstHandle2FissionFragmentData handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPProductYields>(productYields),
      detail::tocpp<CPPDelayedNeutrons>(delayedNeutrons),
      detail::tocpp<CPPFissionEnergyReleases>(fissionEnergyReleases)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
FissionFragmentDataAssign(ConstHandle2FissionFragmentData self, ConstHandle2ConstFissionFragmentData from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
FissionFragmentDataDelete(ConstHandle2ConstFissionFragmentData self)
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
FissionFragmentDataRead(ConstHandle2FissionFragmentData self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
FissionFragmentDataWrite(ConstHandle2ConstFissionFragmentData self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
FissionFragmentDataPrint(ConstHandle2ConstFissionFragmentData self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
FissionFragmentDataPrintXML(ConstHandle2ConstFissionFragmentData self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
FissionFragmentDataPrintJSON(ConstHandle2ConstFissionFragmentData self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: productYields
// -----------------------------------------------------------------------------

// Has
int
FissionFragmentDataProductYieldsHas(ConstHandle2ConstFissionFragmentData self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ProductYieldsHas", self, extract::productYields);
}

// Get, const
Handle2ConstProductYields
FissionFragmentDataProductYieldsGetConst(ConstHandle2ConstFissionFragmentData self)
{
   return detail::getField<CPP,Handle2ConstProductYields>
      (CLASSNAME, CLASSNAME+"ProductYieldsGetConst", self, extract::productYields);
}

// Get, non-const
Handle2ProductYields
FissionFragmentDataProductYieldsGet(ConstHandle2FissionFragmentData self)
{
   return detail::getField<CPP,Handle2ProductYields>
      (CLASSNAME, CLASSNAME+"ProductYieldsGet", self, extract::productYields);
}

// Set
void
FissionFragmentDataProductYieldsSet(ConstHandle2FissionFragmentData self, ConstHandle2ConstProductYields productYields)
{
   detail::setField<CPP,CPPProductYields>
      (CLASSNAME, CLASSNAME+"ProductYieldsSet", self, extract::productYields, productYields);
}


// -----------------------------------------------------------------------------
// Child: delayedNeutrons
// -----------------------------------------------------------------------------

// Has
int
FissionFragmentDataDelayedNeutronsHas(ConstHandle2ConstFissionFragmentData self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DelayedNeutronsHas", self, extract::delayedNeutrons);
}

// Get, const
Handle2ConstDelayedNeutrons
FissionFragmentDataDelayedNeutronsGetConst(ConstHandle2ConstFissionFragmentData self)
{
   return detail::getField<CPP,Handle2ConstDelayedNeutrons>
      (CLASSNAME, CLASSNAME+"DelayedNeutronsGetConst", self, extract::delayedNeutrons);
}

// Get, non-const
Handle2DelayedNeutrons
FissionFragmentDataDelayedNeutronsGet(ConstHandle2FissionFragmentData self)
{
   return detail::getField<CPP,Handle2DelayedNeutrons>
      (CLASSNAME, CLASSNAME+"DelayedNeutronsGet", self, extract::delayedNeutrons);
}

// Set
void
FissionFragmentDataDelayedNeutronsSet(ConstHandle2FissionFragmentData self, ConstHandle2ConstDelayedNeutrons delayedNeutrons)
{
   detail::setField<CPP,CPPDelayedNeutrons>
      (CLASSNAME, CLASSNAME+"DelayedNeutronsSet", self, extract::delayedNeutrons, delayedNeutrons);
}


// -----------------------------------------------------------------------------
// Child: fissionEnergyReleases
// -----------------------------------------------------------------------------

// Has
int
FissionFragmentDataFissionEnergyReleasesHas(ConstHandle2ConstFissionFragmentData self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"FissionEnergyReleasesHas", self, extract::fissionEnergyReleases);
}

// Get, const
Handle2ConstFissionEnergyReleases
FissionFragmentDataFissionEnergyReleasesGetConst(ConstHandle2ConstFissionFragmentData self)
{
   return detail::getField<CPP,Handle2ConstFissionEnergyReleases>
      (CLASSNAME, CLASSNAME+"FissionEnergyReleasesGetConst", self, extract::fissionEnergyReleases);
}

// Get, non-const
Handle2FissionEnergyReleases
FissionFragmentDataFissionEnergyReleasesGet(ConstHandle2FissionFragmentData self)
{
   return detail::getField<CPP,Handle2FissionEnergyReleases>
      (CLASSNAME, CLASSNAME+"FissionEnergyReleasesGet", self, extract::fissionEnergyReleases);
}

// Set
void
FissionFragmentDataFissionEnergyReleasesSet(ConstHandle2FissionFragmentData self, ConstHandle2ConstFissionEnergyReleases fissionEnergyReleases)
{
   detail::setField<CPP,CPPFissionEnergyReleases>
      (CLASSNAME, CLASSNAME+"FissionEnergyReleasesSet", self, extract::fissionEnergyReleases, fissionEnergyReleases);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/top/FissionFragmentData/src/custom.cpp"
