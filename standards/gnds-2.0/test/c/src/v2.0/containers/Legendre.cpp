
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/containers/Legendre.hpp"
#include "Legendre.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = LegendreClass;
using CPP = multigroup::Legendre;

static const std::string CLASSNAME = "Legendre";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto outerDomainValue = [](auto &obj) { return &obj.outerDomainValue; };
   static auto lowerIndex = [](auto &obj) { return &obj.lowerIndex; };
   static auto domainMin = [](auto &obj) { return &obj.domainMin; };
   static auto domainMax = [](auto &obj) { return &obj.domainMax; };
   static auto values = [](auto &obj) { return &obj.values; };
}

using CPPValues = containers::Values;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstLegendre
LegendreDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Legendre
LegendreDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstLegendre
LegendreCreateConst(
   const XMLName label,
   const Float64 outerDomainValue,
   const Integer32 lowerIndex,
   const Float64 domainMin,
   const Float64 domainMax,
   ConstHandle2ConstValues values
) {
   ConstHandle2Legendre handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      outerDomainValue,
      lowerIndex,
      domainMin,
      domainMax,
      detail::tocpp<CPPValues>(values)
   );
   return handle;
}

// Create, general
Handle2Legendre
LegendreCreate(
   const XMLName label,
   const Float64 outerDomainValue,
   const Integer32 lowerIndex,
   const Float64 domainMin,
   const Float64 domainMax,
   ConstHandle2ConstValues values
) {
   ConstHandle2Legendre handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      outerDomainValue,
      lowerIndex,
      domainMin,
      domainMax,
      detail::tocpp<CPPValues>(values)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
LegendreAssign(ConstHandle2Legendre This, ConstHandle2ConstLegendre from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
LegendreDelete(ConstHandle2ConstLegendre This)
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
LegendreRead(ConstHandle2Legendre This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
LegendreWrite(ConstHandle2ConstLegendre This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
LegendrePrint(ConstHandle2ConstLegendre This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
LegendrePrintXML(ConstHandle2ConstLegendre This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
LegendrePrintJSON(ConstHandle2ConstLegendre This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
LegendreLabelHas(ConstHandle2ConstLegendre This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
LegendreLabelGet(ConstHandle2ConstLegendre This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
LegendreLabelSet(ConstHandle2Legendre This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: outerDomainValue
// -----------------------------------------------------------------------------

// Has
int
LegendreOuterDomainValueHas(ConstHandle2ConstLegendre This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"OuterDomainValueHas", This, extract::outerDomainValue);
}

// Get
// Returns by value
Float64
LegendreOuterDomainValueGet(ConstHandle2ConstLegendre This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"OuterDomainValueGet", This, extract::outerDomainValue);
}

// Set
void
LegendreOuterDomainValueSet(ConstHandle2Legendre This, const Float64 outerDomainValue)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"OuterDomainValueSet", This, extract::outerDomainValue, outerDomainValue);
}


// -----------------------------------------------------------------------------
// Metadatum: lowerIndex
// -----------------------------------------------------------------------------

// Has
int
LegendreLowerIndexHas(ConstHandle2ConstLegendre This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LowerIndexHas", This, extract::lowerIndex);
}

// Get
// Returns by value
Integer32
LegendreLowerIndexGet(ConstHandle2ConstLegendre This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LowerIndexGet", This, extract::lowerIndex);
}

// Set
void
LegendreLowerIndexSet(ConstHandle2Legendre This, const Integer32 lowerIndex)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LowerIndexSet", This, extract::lowerIndex, lowerIndex);
}


// -----------------------------------------------------------------------------
// Metadatum: domainMin
// -----------------------------------------------------------------------------

// Has
int
LegendreDomainMinHas(ConstHandle2ConstLegendre This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMinHas", This, extract::domainMin);
}

// Get
// Returns by value
Float64
LegendreDomainMinGet(ConstHandle2ConstLegendre This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMinGet", This, extract::domainMin);
}

// Set
void
LegendreDomainMinSet(ConstHandle2Legendre This, const Float64 domainMin)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMinSet", This, extract::domainMin, domainMin);
}


// -----------------------------------------------------------------------------
// Metadatum: domainMax
// -----------------------------------------------------------------------------

// Has
int
LegendreDomainMaxHas(ConstHandle2ConstLegendre This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMaxHas", This, extract::domainMax);
}

// Get
// Returns by value
Float64
LegendreDomainMaxGet(ConstHandle2ConstLegendre This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMaxGet", This, extract::domainMax);
}

// Set
void
LegendreDomainMaxSet(ConstHandle2Legendre This, const Float64 domainMax)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMaxSet", This, extract::domainMax, domainMax);
}


// -----------------------------------------------------------------------------
// Child: values
// -----------------------------------------------------------------------------

// Has
int
LegendreValuesHas(ConstHandle2ConstLegendre This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ValuesHas", This, extract::values);
}

// Get, const
Handle2ConstValues
LegendreValuesGetConst(ConstHandle2ConstLegendre This)
{
   return detail::getField<CPP,Handle2ConstValues>
      (CLASSNAME, CLASSNAME+"ValuesGetConst", This, extract::values);
}

// Get, non-const
Handle2Values
LegendreValuesGet(ConstHandle2Legendre This)
{
   return detail::getField<CPP,Handle2Values>
      (CLASSNAME, CLASSNAME+"ValuesGet", This, extract::values);
}

// Set
void
LegendreValuesSet(ConstHandle2Legendre This, ConstHandle2ConstValues values)
{
   detail::setField<CPP,CPPValues>
      (CLASSNAME, CLASSNAME+"ValuesSet", This, extract::values, values);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/containers/Legendre/src/custom.cpp"
