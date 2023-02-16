
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/resonances/Resolved.hpp"
#include "Resolved.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = ResolvedClass;
using CPP = multigroup::Resolved;

static const std::string CLASSNAME = "Resolved";

namespace extract {
   static auto domainMin = [](auto &obj) { return &obj.domainMin; };
   static auto domainMax = [](auto &obj) { return &obj.domainMax; };
   static auto domainUnit = [](auto &obj) { return &obj.domainUnit; };
}

using CPPRMatrix = resonances::RMatrix;
using CPPBreitWigner = resonances::BreitWigner;
using CPPEnergyIntervals = resonances::EnergyIntervals;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstResolved
ResolvedDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Resolved
ResolvedDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstResolved
ResolvedCreateConst(
   const Float64 domainMin,
   const Float64 domainMax,
   const XMLName domainUnit,
) {
   ConstHandle2Resolved handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      domainMin,
      domainMax,
      domainUnit
   );
   return handle;
}

// Create, general
Handle2Resolved
ResolvedCreate(
   const Float64 domainMin,
   const Float64 domainMax,
   const XMLName domainUnit,
) {
   ConstHandle2Resolved handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      domainMin,
      domainMax,
      domainUnit
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ResolvedAssign(ConstHandle2Resolved self, ConstHandle2ConstResolved from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ResolvedDelete(ConstHandle2ConstResolved self)
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
ResolvedRead(ConstHandle2Resolved self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ResolvedWrite(ConstHandle2ConstResolved self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ResolvedPrint(ConstHandle2ConstResolved self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ResolvedPrintXML(ConstHandle2ConstResolved self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ResolvedPrintJSON(ConstHandle2ConstResolved self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: domainMin
// -----------------------------------------------------------------------------

// Has
int
ResolvedDomainMinHas(ConstHandle2ConstResolved self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMinHas", self, extract::domainMin);
}

// Get
// Returns by value
Float64
ResolvedDomainMinGet(ConstHandle2ConstResolved self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMinGet", self, extract::domainMin);
}

// Set
void
ResolvedDomainMinSet(ConstHandle2Resolved self, const Float64 domainMin)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMinSet", self, extract::domainMin, domainMin);
}


// -----------------------------------------------------------------------------
// Metadatum: domainMax
// -----------------------------------------------------------------------------

// Has
int
ResolvedDomainMaxHas(ConstHandle2ConstResolved self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMaxHas", self, extract::domainMax);
}

// Get
// Returns by value
Float64
ResolvedDomainMaxGet(ConstHandle2ConstResolved self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMaxGet", self, extract::domainMax);
}

// Set
void
ResolvedDomainMaxSet(ConstHandle2Resolved self, const Float64 domainMax)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMaxSet", self, extract::domainMax, domainMax);
}


// -----------------------------------------------------------------------------
// Metadatum: domainUnit
// -----------------------------------------------------------------------------

// Has
int
ResolvedDomainUnitHas(ConstHandle2ConstResolved self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DomainUnitHas", self, extract::domainUnit);
}

// Get
// Returns by value
XMLName
ResolvedDomainUnitGet(ConstHandle2ConstResolved self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DomainUnitGet", self, extract::domainUnit);
}

// Set
void
ResolvedDomainUnitSet(ConstHandle2Resolved self, const XMLName domainUnit)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DomainUnitSet", self, extract::domainUnit, domainUnit);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/resonances/Resolved/src/custom.cpp"
