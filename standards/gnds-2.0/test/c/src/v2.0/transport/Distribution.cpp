
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2.0/transport/Distribution.hpp"
#include "Distribution.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = DistributionClass;
using CPP = multigroup::Distribution;

static const std::string CLASSNAME = "Distribution";

namespace extract {
}

using CPPAngularTwoBody = transport::AngularTwoBody;
using CPPUncorrelated = transport::Uncorrelated;
using CPPAngularEnergy = transport::AngularEnergy;
using CPPEnergyAngular = transport::EnergyAngular;
using CPPKalbachMann = transport::KalbachMann;
using CPPReference = transport::Reference;
using CPPBranching3d = transport::Branching3d;
using CPPCoulombPlusNuclearElastic = cpTransport::CoulombPlusNuclearElastic;
using CPPThermalNeutronScatteringLaw = tsl::ThermalNeutronScatteringLaw;
using CPPCoherentPhotonScattering = atomic::CoherentPhotonScattering;
using CPPIncoherentPhotonScattering = atomic::IncoherentPhotonScattering;
using CPPUnspecified = transport::Unspecified;
using CPPMultiGroup3d = transport::MultiGroup3d;
using CPPAngularEnergyMC = processed::AngularEnergyMC;
using CPPEnergyAngularMC = processed::EnergyAngularMC;
using CPPXYs2d = containers::XYs2d;


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
) {
   ConstHandle2Distribution handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst"
   );
   return handle;
}

// Create, general
Handle2Distribution
DistributionCreate(
) {
   ConstHandle2Distribution handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create"
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
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/transport/Distribution/src/custom.cpp"
