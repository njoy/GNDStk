
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/ScatteringAtom.hpp"
#include "ScatteringAtom.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = ScatteringAtomClass;
using CPP = multigroup::ScatteringAtom;

static const std::string CLASSNAME = "ScatteringAtom";

namespace extract {
   static auto pid = [](auto &obj) { return &obj.pid; };
   static auto numberPerMolecule = [](auto &obj) { return &obj.numberPerMolecule; };
   static auto primaryScatterer = [](auto &obj) { return &obj.primaryScatterer; };
   static auto mass = [](auto &obj) { return &obj.mass; };
   static auto e_critical = [](auto &obj) { return &obj.e_critical; };
   static auto e_max = [](auto &obj) { return &obj.e_max; };
   static auto boundAtomCrossSection = [](auto &obj) { return &obj.boundAtomCrossSection; };
   static auto selfScatteringKernel = [](auto &obj) { return &obj.selfScatteringKernel; };
   static auto T_effective = [](auto &obj) { return &obj.T_effective; };
}

using CPPMass = general::Mass;
using CPPE_critical = general::E_critical;
using CPPE_max = general::E_max;
using CPPBoundAtomCrossSection = general::BoundAtomCrossSection;
using CPPSelfScatteringKernel = general::SelfScatteringKernel;
using CPPT_effective = general::T_effective;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstScatteringAtom
ScatteringAtomDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default, non-const
Handle2ScatteringAtom
ScatteringAtomDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstScatteringAtom
ScatteringAtomCreateConst(
   const char *const pid,
   const int numberPerMolecule,
   const bool primaryScatterer,
   ConstHandle2ConstMass mass,
   ConstHandle2ConstE_critical e_critical,
   ConstHandle2ConstE_max e_max,
   ConstHandle2ConstBoundAtomCrossSection boundAtomCrossSection,
   ConstHandle2ConstSelfScatteringKernel selfScatteringKernel,
   ConstHandle2ConstT_effective T_effective
) {
   ConstHandle2ScatteringAtom handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      pid,
      numberPerMolecule,
      primaryScatterer,
      detail::tocpp<CPPMass>(mass),
      detail::tocpp<CPPE_critical>(e_critical),
      detail::tocpp<CPPE_max>(e_max),
      detail::tocpp<CPPBoundAtomCrossSection>(boundAtomCrossSection),
      detail::tocpp<CPPSelfScatteringKernel>(selfScatteringKernel),
      detail::tocpp<CPPT_effective>(T_effective)
   );
   return handle;
}

// Create, general, non-const
Handle2ScatteringAtom
ScatteringAtomCreate(
   const char *const pid,
   const int numberPerMolecule,
   const bool primaryScatterer,
   ConstHandle2ConstMass mass,
   ConstHandle2ConstE_critical e_critical,
   ConstHandle2ConstE_max e_max,
   ConstHandle2ConstBoundAtomCrossSection boundAtomCrossSection,
   ConstHandle2ConstSelfScatteringKernel selfScatteringKernel,
   ConstHandle2ConstT_effective T_effective
) {
   ConstHandle2ScatteringAtom handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      pid,
      numberPerMolecule,
      primaryScatterer,
      detail::tocpp<CPPMass>(mass),
      detail::tocpp<CPPE_critical>(e_critical),
      detail::tocpp<CPPE_max>(e_max),
      detail::tocpp<CPPBoundAtomCrossSection>(boundAtomCrossSection),
      detail::tocpp<CPPSelfScatteringKernel>(selfScatteringKernel),
      detail::tocpp<CPPT_effective>(T_effective)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ScatteringAtomAssign(ConstHandle2ScatteringAtom self, ConstHandle2ConstScatteringAtom from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ScatteringAtomDelete(ConstHandle2ConstScatteringAtom self)
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
ScatteringAtomRead(ConstHandle2ScatteringAtom self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ScatteringAtomWrite(ConstHandle2ConstScatteringAtom self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ScatteringAtomPrint(ConstHandle2ConstScatteringAtom self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ScatteringAtomPrintXML(ConstHandle2ConstScatteringAtom self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ScatteringAtomPrintJSON(ConstHandle2ConstScatteringAtom self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: pid
// -----------------------------------------------------------------------------

// Has
int
ScatteringAtomPidHas(ConstHandle2ConstScatteringAtom self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"PidHas", self, extract::pid);
}

// Get
// Returns by value
const char *
ScatteringAtomPidGet(ConstHandle2ConstScatteringAtom self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"PidGet", self, extract::pid);
}

// Set
void
ScatteringAtomPidSet(ConstHandle2ScatteringAtom self, const char *const pid)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"PidSet", self, extract::pid, pid);
}


// -----------------------------------------------------------------------------
// Metadatum: numberPerMolecule
// -----------------------------------------------------------------------------

// Has
int
ScatteringAtomNumberPerMoleculeHas(ConstHandle2ConstScatteringAtom self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"NumberPerMoleculeHas", self, extract::numberPerMolecule);
}

// Get
// Returns by value
int
ScatteringAtomNumberPerMoleculeGet(ConstHandle2ConstScatteringAtom self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"NumberPerMoleculeGet", self, extract::numberPerMolecule);
}

// Set
void
ScatteringAtomNumberPerMoleculeSet(ConstHandle2ScatteringAtom self, const int numberPerMolecule)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"NumberPerMoleculeSet", self, extract::numberPerMolecule, numberPerMolecule);
}


// -----------------------------------------------------------------------------
// Metadatum: primaryScatterer
// -----------------------------------------------------------------------------

// Has
int
ScatteringAtomPrimaryScattererHas(ConstHandle2ConstScatteringAtom self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"PrimaryScattererHas", self, extract::primaryScatterer);
}

// Get
// Returns by value
bool
ScatteringAtomPrimaryScattererGet(ConstHandle2ConstScatteringAtom self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"PrimaryScattererGet", self, extract::primaryScatterer);
}

// Set
void
ScatteringAtomPrimaryScattererSet(ConstHandle2ScatteringAtom self, const bool primaryScatterer)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"PrimaryScattererSet", self, extract::primaryScatterer, primaryScatterer);
}


// -----------------------------------------------------------------------------
// Child: mass
// -----------------------------------------------------------------------------

// Has
int
ScatteringAtomMassHas(ConstHandle2ConstScatteringAtom self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"MassHas", self, extract::mass);
}

// Get, const
Handle2ConstMass
ScatteringAtomMassGetConst(ConstHandle2ConstScatteringAtom self)
{
   return detail::getField<CPP,Handle2ConstMass>
      (CLASSNAME, CLASSNAME+"MassGetConst", self, extract::mass);
}

// Get, non-const
Handle2Mass
ScatteringAtomMassGet(ConstHandle2ScatteringAtom self)
{
   return detail::getField<CPP,Handle2Mass>
      (CLASSNAME, CLASSNAME+"MassGet", self, extract::mass);
}

// Set
void
ScatteringAtomMassSet(ConstHandle2ScatteringAtom self, ConstHandle2ConstMass mass)
{
   detail::setField<CPP,CPPMass>
      (CLASSNAME, CLASSNAME+"MassSet", self, extract::mass, mass);
}


// -----------------------------------------------------------------------------
// Child: e_critical
// -----------------------------------------------------------------------------

// Has
int
ScatteringAtomE_criticalHas(ConstHandle2ConstScatteringAtom self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"E_criticalHas", self, extract::e_critical);
}

// Get, const
Handle2ConstE_critical
ScatteringAtomE_criticalGetConst(ConstHandle2ConstScatteringAtom self)
{
   return detail::getField<CPP,Handle2ConstE_critical>
      (CLASSNAME, CLASSNAME+"E_criticalGetConst", self, extract::e_critical);
}

// Get, non-const
Handle2E_critical
ScatteringAtomE_criticalGet(ConstHandle2ScatteringAtom self)
{
   return detail::getField<CPP,Handle2E_critical>
      (CLASSNAME, CLASSNAME+"E_criticalGet", self, extract::e_critical);
}

// Set
void
ScatteringAtomE_criticalSet(ConstHandle2ScatteringAtom self, ConstHandle2ConstE_critical e_critical)
{
   detail::setField<CPP,CPPE_critical>
      (CLASSNAME, CLASSNAME+"E_criticalSet", self, extract::e_critical, e_critical);
}


// -----------------------------------------------------------------------------
// Child: e_max
// -----------------------------------------------------------------------------

// Has
int
ScatteringAtomE_maxHas(ConstHandle2ConstScatteringAtom self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"E_maxHas", self, extract::e_max);
}

// Get, const
Handle2ConstE_max
ScatteringAtomE_maxGetConst(ConstHandle2ConstScatteringAtom self)
{
   return detail::getField<CPP,Handle2ConstE_max>
      (CLASSNAME, CLASSNAME+"E_maxGetConst", self, extract::e_max);
}

// Get, non-const
Handle2E_max
ScatteringAtomE_maxGet(ConstHandle2ScatteringAtom self)
{
   return detail::getField<CPP,Handle2E_max>
      (CLASSNAME, CLASSNAME+"E_maxGet", self, extract::e_max);
}

// Set
void
ScatteringAtomE_maxSet(ConstHandle2ScatteringAtom self, ConstHandle2ConstE_max e_max)
{
   detail::setField<CPP,CPPE_max>
      (CLASSNAME, CLASSNAME+"E_maxSet", self, extract::e_max, e_max);
}


// -----------------------------------------------------------------------------
// Child: boundAtomCrossSection
// -----------------------------------------------------------------------------

// Has
int
ScatteringAtomBoundAtomCrossSectionHas(ConstHandle2ConstScatteringAtom self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"BoundAtomCrossSectionHas", self, extract::boundAtomCrossSection);
}

// Get, const
Handle2ConstBoundAtomCrossSection
ScatteringAtomBoundAtomCrossSectionGetConst(ConstHandle2ConstScatteringAtom self)
{
   return detail::getField<CPP,Handle2ConstBoundAtomCrossSection>
      (CLASSNAME, CLASSNAME+"BoundAtomCrossSectionGetConst", self, extract::boundAtomCrossSection);
}

// Get, non-const
Handle2BoundAtomCrossSection
ScatteringAtomBoundAtomCrossSectionGet(ConstHandle2ScatteringAtom self)
{
   return detail::getField<CPP,Handle2BoundAtomCrossSection>
      (CLASSNAME, CLASSNAME+"BoundAtomCrossSectionGet", self, extract::boundAtomCrossSection);
}

// Set
void
ScatteringAtomBoundAtomCrossSectionSet(ConstHandle2ScatteringAtom self, ConstHandle2ConstBoundAtomCrossSection boundAtomCrossSection)
{
   detail::setField<CPP,CPPBoundAtomCrossSection>
      (CLASSNAME, CLASSNAME+"BoundAtomCrossSectionSet", self, extract::boundAtomCrossSection, boundAtomCrossSection);
}


// -----------------------------------------------------------------------------
// Child: selfScatteringKernel
// -----------------------------------------------------------------------------

// Has
int
ScatteringAtomSelfScatteringKernelHas(ConstHandle2ConstScatteringAtom self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SelfScatteringKernelHas", self, extract::selfScatteringKernel);
}

// Get, const
Handle2ConstSelfScatteringKernel
ScatteringAtomSelfScatteringKernelGetConst(ConstHandle2ConstScatteringAtom self)
{
   return detail::getField<CPP,Handle2ConstSelfScatteringKernel>
      (CLASSNAME, CLASSNAME+"SelfScatteringKernelGetConst", self, extract::selfScatteringKernel);
}

// Get, non-const
Handle2SelfScatteringKernel
ScatteringAtomSelfScatteringKernelGet(ConstHandle2ScatteringAtom self)
{
   return detail::getField<CPP,Handle2SelfScatteringKernel>
      (CLASSNAME, CLASSNAME+"SelfScatteringKernelGet", self, extract::selfScatteringKernel);
}

// Set
void
ScatteringAtomSelfScatteringKernelSet(ConstHandle2ScatteringAtom self, ConstHandle2ConstSelfScatteringKernel selfScatteringKernel)
{
   detail::setField<CPP,CPPSelfScatteringKernel>
      (CLASSNAME, CLASSNAME+"SelfScatteringKernelSet", self, extract::selfScatteringKernel, selfScatteringKernel);
}


// -----------------------------------------------------------------------------
// Child: T_effective
// -----------------------------------------------------------------------------

// Has
int
ScatteringAtomT_effectiveHas(ConstHandle2ConstScatteringAtom self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"T_effectiveHas", self, extract::T_effective);
}

// Get, const
Handle2ConstT_effective
ScatteringAtomT_effectiveGetConst(ConstHandle2ConstScatteringAtom self)
{
   return detail::getField<CPP,Handle2ConstT_effective>
      (CLASSNAME, CLASSNAME+"T_effectiveGetConst", self, extract::T_effective);
}

// Get, non-const
Handle2T_effective
ScatteringAtomT_effectiveGet(ConstHandle2ScatteringAtom self)
{
   return detail::getField<CPP,Handle2T_effective>
      (CLASSNAME, CLASSNAME+"T_effectiveGet", self, extract::T_effective);
}

// Set
void
ScatteringAtomT_effectiveSet(ConstHandle2ScatteringAtom self, ConstHandle2ConstT_effective T_effective)
{
   detail::setField<CPP,CPPT_effective>
      (CLASSNAME, CLASSNAME+"T_effectiveSet", self, extract::T_effective, T_effective);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/ScatteringAtom/src/custom.cpp"