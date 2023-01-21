
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/styles/ProjectileEnergyDomain.hpp"
#include "ProjectileEnergyDomain.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = ProjectileEnergyDomainClass;
using CPP = multigroup::ProjectileEnergyDomain;

static const std::string CLASSNAME = "ProjectileEnergyDomain";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto max = [](auto &obj) { return &obj.max; };
   static auto min = [](auto &obj) { return &obj.min; };
   static auto unit = [](auto &obj) { return &obj.unit; };
}


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstProjectileEnergyDomain
ProjectileEnergyDomainDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2ProjectileEnergyDomain
ProjectileEnergyDomainDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstProjectileEnergyDomain
ProjectileEnergyDomainCreateConst(
   const XMLName label,
   const Float64 max,
   const Float64 min,
   const XMLName unit
) {
   ConstHandle2ProjectileEnergyDomain handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      max,
      min,
      unit
   );
   return handle;
}

// Create, general
Handle2ProjectileEnergyDomain
ProjectileEnergyDomainCreate(
   const XMLName label,
   const Float64 max,
   const Float64 min,
   const XMLName unit
) {
   ConstHandle2ProjectileEnergyDomain handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      max,
      min,
      unit
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ProjectileEnergyDomainAssign(ConstHandle2ProjectileEnergyDomain This, ConstHandle2ConstProjectileEnergyDomain from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ProjectileEnergyDomainDelete(ConstHandle2ConstProjectileEnergyDomain This)
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
ProjectileEnergyDomainRead(ConstHandle2ProjectileEnergyDomain This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ProjectileEnergyDomainWrite(ConstHandle2ConstProjectileEnergyDomain This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
ProjectileEnergyDomainPrint(ConstHandle2ConstProjectileEnergyDomain This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
ProjectileEnergyDomainPrintXML(ConstHandle2ConstProjectileEnergyDomain This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
ProjectileEnergyDomainPrintJSON(ConstHandle2ConstProjectileEnergyDomain This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
ProjectileEnergyDomainLabelHas(ConstHandle2ConstProjectileEnergyDomain This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
ProjectileEnergyDomainLabelGet(ConstHandle2ConstProjectileEnergyDomain This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
ProjectileEnergyDomainLabelSet(ConstHandle2ProjectileEnergyDomain This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: max
// -----------------------------------------------------------------------------

// Has
int
ProjectileEnergyDomainMaxHas(ConstHandle2ConstProjectileEnergyDomain This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"MaxHas", This, extract::max);
}

// Get
// Returns by value
Float64
ProjectileEnergyDomainMaxGet(ConstHandle2ConstProjectileEnergyDomain This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"MaxGet", This, extract::max);
}

// Set
void
ProjectileEnergyDomainMaxSet(ConstHandle2ProjectileEnergyDomain This, const Float64 max)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"MaxSet", This, extract::max, max);
}


// -----------------------------------------------------------------------------
// Metadatum: min
// -----------------------------------------------------------------------------

// Has
int
ProjectileEnergyDomainMinHas(ConstHandle2ConstProjectileEnergyDomain This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"MinHas", This, extract::min);
}

// Get
// Returns by value
Float64
ProjectileEnergyDomainMinGet(ConstHandle2ConstProjectileEnergyDomain This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"MinGet", This, extract::min);
}

// Set
void
ProjectileEnergyDomainMinSet(ConstHandle2ProjectileEnergyDomain This, const Float64 min)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"MinSet", This, extract::min, min);
}


// -----------------------------------------------------------------------------
// Metadatum: unit
// -----------------------------------------------------------------------------

// Has
int
ProjectileEnergyDomainUnitHas(ConstHandle2ConstProjectileEnergyDomain This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UnitHas", This, extract::unit);
}

// Get
// Returns by value
XMLName
ProjectileEnergyDomainUnitGet(ConstHandle2ConstProjectileEnergyDomain This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"UnitGet", This, extract::unit);
}

// Set
void
ProjectileEnergyDomainUnitSet(ConstHandle2ProjectileEnergyDomain This, const XMLName unit)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"UnitSet", This, extract::unit, unit);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/styles/ProjectileEnergyDomain/src/custom.cpp"
