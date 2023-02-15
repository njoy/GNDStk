
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/reduced/Distribution.hpp"
#include "Distribution.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = DistributionClass;
using CPP = multigroup::Distribution;

static const std::string CLASSNAME = "Distribution";

namespace extract {
   static auto thermalNeutronScatteringLaw = [](auto &obj) { return &obj.thermalNeutronScatteringLaw; };
   static auto uncorrelated = [](auto &obj) { return &obj.uncorrelated; };
   static auto unspecified = [](auto &obj) { return &obj.unspecified; };
   static auto XYs2d = [](auto &obj) { return &obj.XYs2d; };
   static auto branching3d = [](auto &obj) { return &obj.branching3d; };
}

using CPPThermalNeutronScatteringLaw = general::ThermalNeutronScatteringLaw;
using CPPUncorrelated = general::Uncorrelated;
using CPPUnspecified = general::Unspecified;
using CPPXYs2d = general::XYs2d;
using CPPBranching3d = general::Branching3d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstDistribution
DistributionDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Distribution
DistributionDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstDistribution
DistributionCreateConst(
   ConstHandle2ConstThermalNeutronScatteringLaw thermalNeutronScatteringLaw,
   ConstHandle2ConstUncorrelated uncorrelated,
   ConstHandle2ConstUnspecified unspecified,
   ConstHandle2ConstXYs2d XYs2d,
   ConstHandle2ConstBranching3d branching3d
) {
   ConstHandle2Distribution handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPThermalNeutronScatteringLaw>(thermalNeutronScatteringLaw),
      detail::tocpp<CPPUncorrelated>(uncorrelated),
      detail::tocpp<CPPUnspecified>(unspecified),
      detail::tocpp<CPPXYs2d>(XYs2d),
      detail::tocpp<CPPBranching3d>(branching3d)
   );
   return handle;
}

// Create, general
Handle2Distribution
DistributionCreate(
   ConstHandle2ConstThermalNeutronScatteringLaw thermalNeutronScatteringLaw,
   ConstHandle2ConstUncorrelated uncorrelated,
   ConstHandle2ConstUnspecified unspecified,
   ConstHandle2ConstXYs2d XYs2d,
   ConstHandle2ConstBranching3d branching3d
) {
   ConstHandle2Distribution handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPThermalNeutronScatteringLaw>(thermalNeutronScatteringLaw),
      detail::tocpp<CPPUncorrelated>(uncorrelated),
      detail::tocpp<CPPUnspecified>(unspecified),
      detail::tocpp<CPPXYs2d>(XYs2d),
      detail::tocpp<CPPBranching3d>(branching3d)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
DistributionAssign(ConstHandle2Distribution self, ConstHandle2ConstDistribution from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
DistributionDelete(ConstHandle2ConstDistribution self)
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
DistributionRead(ConstHandle2Distribution self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
DistributionWrite(ConstHandle2ConstDistribution self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
DistributionPrint(ConstHandle2ConstDistribution self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
DistributionPrintXML(ConstHandle2ConstDistribution self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
DistributionPrintJSON(ConstHandle2ConstDistribution self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: thermalNeutronScatteringLaw
// -----------------------------------------------------------------------------

// Has
int
DistributionThermalNeutronScatteringLawHas(ConstHandle2ConstDistribution self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLawHas", self, extract::thermalNeutronScatteringLaw);
}

// Get, const
Handle2ConstThermalNeutronScatteringLaw
DistributionThermalNeutronScatteringLawGetConst(ConstHandle2ConstDistribution self)
{
   return detail::getField<CPP,Handle2ConstThermalNeutronScatteringLaw>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLawGetConst", self, extract::thermalNeutronScatteringLaw);
}

// Get, non-const
Handle2ThermalNeutronScatteringLaw
DistributionThermalNeutronScatteringLawGet(ConstHandle2Distribution self)
{
   return detail::getField<CPP,Handle2ThermalNeutronScatteringLaw>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLawGet", self, extract::thermalNeutronScatteringLaw);
}

// Set
void
DistributionThermalNeutronScatteringLawSet(ConstHandle2Distribution self, ConstHandle2ConstThermalNeutronScatteringLaw thermalNeutronScatteringLaw)
{
   detail::setField<CPP,CPPThermalNeutronScatteringLaw>
      (CLASSNAME, CLASSNAME+"ThermalNeutronScatteringLawSet", self, extract::thermalNeutronScatteringLaw, thermalNeutronScatteringLaw);
}


// -----------------------------------------------------------------------------
// Child: uncorrelated
// -----------------------------------------------------------------------------

// Has
int
DistributionUncorrelatedHas(ConstHandle2ConstDistribution self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UncorrelatedHas", self, extract::uncorrelated);
}

// Get, const
Handle2ConstUncorrelated
DistributionUncorrelatedGetConst(ConstHandle2ConstDistribution self)
{
   return detail::getField<CPP,Handle2ConstUncorrelated>
      (CLASSNAME, CLASSNAME+"UncorrelatedGetConst", self, extract::uncorrelated);
}

// Get, non-const
Handle2Uncorrelated
DistributionUncorrelatedGet(ConstHandle2Distribution self)
{
   return detail::getField<CPP,Handle2Uncorrelated>
      (CLASSNAME, CLASSNAME+"UncorrelatedGet", self, extract::uncorrelated);
}

// Set
void
DistributionUncorrelatedSet(ConstHandle2Distribution self, ConstHandle2ConstUncorrelated uncorrelated)
{
   detail::setField<CPP,CPPUncorrelated>
      (CLASSNAME, CLASSNAME+"UncorrelatedSet", self, extract::uncorrelated, uncorrelated);
}


// -----------------------------------------------------------------------------
// Child: unspecified
// -----------------------------------------------------------------------------

// Has
int
DistributionUnspecifiedHas(ConstHandle2ConstDistribution self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UnspecifiedHas", self, extract::unspecified);
}

// Get, const
Handle2ConstUnspecified
DistributionUnspecifiedGetConst(ConstHandle2ConstDistribution self)
{
   return detail::getField<CPP,Handle2ConstUnspecified>
      (CLASSNAME, CLASSNAME+"UnspecifiedGetConst", self, extract::unspecified);
}

// Get, non-const
Handle2Unspecified
DistributionUnspecifiedGet(ConstHandle2Distribution self)
{
   return detail::getField<CPP,Handle2Unspecified>
      (CLASSNAME, CLASSNAME+"UnspecifiedGet", self, extract::unspecified);
}

// Set
void
DistributionUnspecifiedSet(ConstHandle2Distribution self, ConstHandle2ConstUnspecified unspecified)
{
   detail::setField<CPP,CPPUnspecified>
      (CLASSNAME, CLASSNAME+"UnspecifiedSet", self, extract::unspecified, unspecified);
}


// -----------------------------------------------------------------------------
// Child: XYs2d
// -----------------------------------------------------------------------------

// Has
int
DistributionXYs2dHas(ConstHandle2ConstDistribution self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"XYs2dHas", self, extract::XYs2d);
}

// Get, const
Handle2ConstXYs2d
DistributionXYs2dGetConst(ConstHandle2ConstDistribution self)
{
   return detail::getField<CPP,Handle2ConstXYs2d>
      (CLASSNAME, CLASSNAME+"XYs2dGetConst", self, extract::XYs2d);
}

// Get, non-const
Handle2XYs2d
DistributionXYs2dGet(ConstHandle2Distribution self)
{
   return detail::getField<CPP,Handle2XYs2d>
      (CLASSNAME, CLASSNAME+"XYs2dGet", self, extract::XYs2d);
}

// Set
void
DistributionXYs2dSet(ConstHandle2Distribution self, ConstHandle2ConstXYs2d XYs2d)
{
   detail::setField<CPP,CPPXYs2d>
      (CLASSNAME, CLASSNAME+"XYs2dSet", self, extract::XYs2d, XYs2d);
}


// -----------------------------------------------------------------------------
// Child: branching3d
// -----------------------------------------------------------------------------

// Has
int
DistributionBranching3dHas(ConstHandle2ConstDistribution self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Branching3dHas", self, extract::branching3d);
}

// Get, const
Handle2ConstBranching3d
DistributionBranching3dGetConst(ConstHandle2ConstDistribution self)
{
   return detail::getField<CPP,Handle2ConstBranching3d>
      (CLASSNAME, CLASSNAME+"Branching3dGetConst", self, extract::branching3d);
}

// Get, non-const
Handle2Branching3d
DistributionBranching3dGet(ConstHandle2Distribution self)
{
   return detail::getField<CPP,Handle2Branching3d>
      (CLASSNAME, CLASSNAME+"Branching3dGet", self, extract::branching3d);
}

// Set
void
DistributionBranching3dSet(ConstHandle2Distribution self, ConstHandle2ConstBranching3d branching3d)
{
   detail::setField<CPP,CPPBranching3d>
      (CLASSNAME, CLASSNAME+"Branching3dSet", self, extract::branching3d, branching3d);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/reduced/Distribution/src/custom.cpp"
