
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/Slice.hpp"
#include "Slice.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = SliceClass;
using CPP = multigroup::Slice;

static const std::string CLASSNAME = "Slice";

namespace extract {
   static auto dimension = [](auto &obj) { return &obj.dimension; };
   static auto domainValue = [](auto &obj) { return &obj.domainValue; };
   static auto domainMin = [](auto &obj) { return &obj.domainMin; };
   static auto domainMax = [](auto &obj) { return &obj.domainMax; };
   static auto domainUnit = [](auto &obj) { return &obj.domainUnit; };
}


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstSlice
SliceDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default, non-const
Handle2Slice
SliceDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstSlice
SliceCreateConst(
   const int dimension,
   const int domainValue,
   const double domainMin,
   const double domainMax,
   const char *const domainUnit
) {
   ConstHandle2Slice handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      dimension,
      domainValue,
      domainMin,
      domainMax,
      domainUnit
   );
   return handle;
}

// Create, general, non-const
Handle2Slice
SliceCreate(
   const int dimension,
   const int domainValue,
   const double domainMin,
   const double domainMax,
   const char *const domainUnit
) {
   ConstHandle2Slice handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      dimension,
      domainValue,
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
SliceAssign(ConstHandle2Slice self, ConstHandle2ConstSlice from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
SliceDelete(ConstHandle2ConstSlice self)
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
SliceRead(ConstHandle2Slice self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
SliceWrite(ConstHandle2ConstSlice self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
SlicePrint(ConstHandle2ConstSlice self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
SlicePrintXML(ConstHandle2ConstSlice self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
SlicePrintJSON(ConstHandle2ConstSlice self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: dimension
// -----------------------------------------------------------------------------

// Has
int
SliceDimensionHas(ConstHandle2ConstSlice self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DimensionHas", self, extract::dimension);
}

// Get
// Returns by value
int
SliceDimensionGet(ConstHandle2ConstSlice self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DimensionGet", self, extract::dimension);
}

// Set
void
SliceDimensionSet(ConstHandle2Slice self, const int dimension)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DimensionSet", self, extract::dimension, dimension);
}


// -----------------------------------------------------------------------------
// Metadatum: domainValue
// -----------------------------------------------------------------------------

// Has
int
SliceDomainValueHas(ConstHandle2ConstSlice self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DomainValueHas", self, extract::domainValue);
}

// Get
// Returns by value
int
SliceDomainValueGet(ConstHandle2ConstSlice self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DomainValueGet", self, extract::domainValue);
}

// Set
void
SliceDomainValueSet(ConstHandle2Slice self, const int domainValue)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DomainValueSet", self, extract::domainValue, domainValue);
}


// -----------------------------------------------------------------------------
// Metadatum: domainMin
// -----------------------------------------------------------------------------

// Has
int
SliceDomainMinHas(ConstHandle2ConstSlice self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMinHas", self, extract::domainMin);
}

// Get
// Returns by value
double
SliceDomainMinGet(ConstHandle2ConstSlice self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMinGet", self, extract::domainMin);
}

// Set
void
SliceDomainMinSet(ConstHandle2Slice self, const double domainMin)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMinSet", self, extract::domainMin, domainMin);
}


// -----------------------------------------------------------------------------
// Metadatum: domainMax
// -----------------------------------------------------------------------------

// Has
int
SliceDomainMaxHas(ConstHandle2ConstSlice self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMaxHas", self, extract::domainMax);
}

// Get
// Returns by value
double
SliceDomainMaxGet(ConstHandle2ConstSlice self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMaxGet", self, extract::domainMax);
}

// Set
void
SliceDomainMaxSet(ConstHandle2Slice self, const double domainMax)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMaxSet", self, extract::domainMax, domainMax);
}


// -----------------------------------------------------------------------------
// Metadatum: domainUnit
// -----------------------------------------------------------------------------

// Has
int
SliceDomainUnitHas(ConstHandle2ConstSlice self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DomainUnitHas", self, extract::domainUnit);
}

// Get
// Returns by value
const char *
SliceDomainUnitGet(ConstHandle2ConstSlice self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DomainUnitGet", self, extract::domainUnit);
}

// Set
void
SliceDomainUnitSet(ConstHandle2Slice self, const char *const domainUnit)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DomainUnitSet", self, extract::domainUnit, domainUnit);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Slice/src/custom.cpp"