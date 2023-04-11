
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2.0/covariance/Slices.hpp"
#include "Slices.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = SlicesClass;
using CPP = multigroup::Slices;

static const std::string CLASSNAME = "Slices";

namespace extract {
   static auto slice = [](auto &obj) { return &obj.slice; };
}

using CPPSlice = covariance::Slice;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstSlices
SlicesDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Slices
SlicesDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstSlices
SlicesCreateConst(
   ConstHandle2Slice *const slice, const size_t sliceSize
) {
   ConstHandle2Slices handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPSlice>{}
   );
   for (size_t SliceN = 0; SliceN < sliceSize; ++SliceN)
      SlicesSliceAdd(handle, slice[SliceN]);
   return handle;
}

// Create, general
Handle2Slices
SlicesCreate(
   ConstHandle2Slice *const slice, const size_t sliceSize
) {
   ConstHandle2Slices handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPSlice>{}
   );
   for (size_t SliceN = 0; SliceN < sliceSize; ++SliceN)
      SlicesSliceAdd(handle, slice[SliceN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
SlicesAssign(ConstHandle2Slices self, ConstHandle2ConstSlices from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
SlicesDelete(ConstHandle2ConstSlices self)
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
SlicesRead(ConstHandle2Slices self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
SlicesWrite(ConstHandle2ConstSlices self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
SlicesPrint(ConstHandle2ConstSlices self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
SlicesPrintXML(ConstHandle2ConstSlices self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
SlicesPrintJSON(ConstHandle2ConstSlices self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: slice
// -----------------------------------------------------------------------------

// Has
int
SlicesSliceHas(ConstHandle2ConstSlices self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SliceHas", self, extract::slice);
}

// Clear
void
SlicesSliceClear(ConstHandle2Slices self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"SliceClear", self, extract::slice);
}

// Size
size_t
SlicesSliceSize(ConstHandle2ConstSlices self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"SliceSize", self, extract::slice);
}

// Add
void
SlicesSliceAdd(ConstHandle2Slices self, ConstHandle2ConstSlice slice)
{
   detail::addToContainer<CPP,CPPSlice>
      (CLASSNAME, CLASSNAME+"SliceAdd", self, extract::slice, slice);
}

// Get, by index \in [0,size), const
Handle2ConstSlice
SlicesSliceGetConst(ConstHandle2ConstSlices self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstSlice>
      (CLASSNAME, CLASSNAME+"SliceGetConst", self, extract::slice, index_);
}

// Get, by index \in [0,size), non-const
Handle2Slice
SlicesSliceGet(ConstHandle2Slices self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Slice>
      (CLASSNAME, CLASSNAME+"SliceGet", self, extract::slice, index_);
}

// Set, by index \in [0,size)
void
SlicesSliceSet(
   ConstHandle2Slices self,
   const size_t index_,
   ConstHandle2ConstSlice slice
) {
   detail::setByIndex<CPP,CPPSlice>
      (CLASSNAME, CLASSNAME+"SliceSet", self, extract::slice, index_, slice);
}

// Has, by domainMin
int
SlicesSliceHasByDomainMin(
   ConstHandle2ConstSlices self,
   const Float64 domainMin
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"SliceHasByDomainMin",
       self, extract::slice, meta::domainMin, domainMin);
}

// Get, by domainMin, const
Handle2ConstSlice
SlicesSliceGetByDomainMinConst(
   ConstHandle2ConstSlices self,
   const Float64 domainMin
) {
   return detail::getByMetadatum<CPP,Handle2ConstSlice>
      (CLASSNAME, CLASSNAME+"SliceGetByDomainMinConst",
       self, extract::slice, meta::domainMin, domainMin);
}

// Get, by domainMin, non-const
Handle2Slice
SlicesSliceGetByDomainMin(
   ConstHandle2Slices self,
   const Float64 domainMin
) {
   return detail::getByMetadatum<CPP,Handle2Slice>
      (CLASSNAME, CLASSNAME+"SliceGetByDomainMin",
       self, extract::slice, meta::domainMin, domainMin);
}

// Set, by domainMin
void
SlicesSliceSetByDomainMin(
   ConstHandle2Slices self,
   const Float64 domainMin,
   ConstHandle2ConstSlice slice
) {
   detail::setByMetadatum<CPP,CPPSlice>
      (CLASSNAME, CLASSNAME+"SliceSetByDomainMin",
       self, extract::slice, meta::domainMin, domainMin, slice);
}

// Has, by domainMax
int
SlicesSliceHasByDomainMax(
   ConstHandle2ConstSlices self,
   const Float64 domainMax
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"SliceHasByDomainMax",
       self, extract::slice, meta::domainMax, domainMax);
}

// Get, by domainMax, const
Handle2ConstSlice
SlicesSliceGetByDomainMaxConst(
   ConstHandle2ConstSlices self,
   const Float64 domainMax
) {
   return detail::getByMetadatum<CPP,Handle2ConstSlice>
      (CLASSNAME, CLASSNAME+"SliceGetByDomainMaxConst",
       self, extract::slice, meta::domainMax, domainMax);
}

// Get, by domainMax, non-const
Handle2Slice
SlicesSliceGetByDomainMax(
   ConstHandle2Slices self,
   const Float64 domainMax
) {
   return detail::getByMetadatum<CPP,Handle2Slice>
      (CLASSNAME, CLASSNAME+"SliceGetByDomainMax",
       self, extract::slice, meta::domainMax, domainMax);
}

// Set, by domainMax
void
SlicesSliceSetByDomainMax(
   ConstHandle2Slices self,
   const Float64 domainMax,
   ConstHandle2ConstSlice slice
) {
   detail::setByMetadatum<CPP,CPPSlice>
      (CLASSNAME, CLASSNAME+"SliceSetByDomainMax",
       self, extract::slice, meta::domainMax, domainMax, slice);
}

// Has, by domainValue
int
SlicesSliceHasByDomainValue(
   ConstHandle2ConstSlices self,
   const Float64 domainValue
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"SliceHasByDomainValue",
       self, extract::slice, meta::domainValue, domainValue);
}

// Get, by domainValue, const
Handle2ConstSlice
SlicesSliceGetByDomainValueConst(
   ConstHandle2ConstSlices self,
   const Float64 domainValue
) {
   return detail::getByMetadatum<CPP,Handle2ConstSlice>
      (CLASSNAME, CLASSNAME+"SliceGetByDomainValueConst",
       self, extract::slice, meta::domainValue, domainValue);
}

// Get, by domainValue, non-const
Handle2Slice
SlicesSliceGetByDomainValue(
   ConstHandle2Slices self,
   const Float64 domainValue
) {
   return detail::getByMetadatum<CPP,Handle2Slice>
      (CLASSNAME, CLASSNAME+"SliceGetByDomainValue",
       self, extract::slice, meta::domainValue, domainValue);
}

// Set, by domainValue
void
SlicesSliceSetByDomainValue(
   ConstHandle2Slices self,
   const Float64 domainValue,
   ConstHandle2ConstSlice slice
) {
   detail::setByMetadatum<CPP,CPPSlice>
      (CLASSNAME, CLASSNAME+"SliceSetByDomainValue",
       self, extract::slice, meta::domainValue, domainValue, slice);
}

// Has, by domainUnit
int
SlicesSliceHasByDomainUnit(
   ConstHandle2ConstSlices self,
   const XMLName domainUnit
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"SliceHasByDomainUnit",
       self, extract::slice, meta::domainUnit, domainUnit);
}

// Get, by domainUnit, const
Handle2ConstSlice
SlicesSliceGetByDomainUnitConst(
   ConstHandle2ConstSlices self,
   const XMLName domainUnit
) {
   return detail::getByMetadatum<CPP,Handle2ConstSlice>
      (CLASSNAME, CLASSNAME+"SliceGetByDomainUnitConst",
       self, extract::slice, meta::domainUnit, domainUnit);
}

// Get, by domainUnit, non-const
Handle2Slice
SlicesSliceGetByDomainUnit(
   ConstHandle2Slices self,
   const XMLName domainUnit
) {
   return detail::getByMetadatum<CPP,Handle2Slice>
      (CLASSNAME, CLASSNAME+"SliceGetByDomainUnit",
       self, extract::slice, meta::domainUnit, domainUnit);
}

// Set, by domainUnit
void
SlicesSliceSetByDomainUnit(
   ConstHandle2Slices self,
   const XMLName domainUnit,
   ConstHandle2ConstSlice slice
) {
   detail::setByMetadatum<CPP,CPPSlice>
      (CLASSNAME, CLASSNAME+"SliceSetByDomainUnit",
       self, extract::slice, meta::domainUnit, domainUnit, slice);
}

// Has, by dimension
int
SlicesSliceHasByDimension(
   ConstHandle2ConstSlices self,
   const Integer32 dimension
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"SliceHasByDimension",
       self, extract::slice, meta::dimension, dimension);
}

// Get, by dimension, const
Handle2ConstSlice
SlicesSliceGetByDimensionConst(
   ConstHandle2ConstSlices self,
   const Integer32 dimension
) {
   return detail::getByMetadatum<CPP,Handle2ConstSlice>
      (CLASSNAME, CLASSNAME+"SliceGetByDimensionConst",
       self, extract::slice, meta::dimension, dimension);
}

// Get, by dimension, non-const
Handle2Slice
SlicesSliceGetByDimension(
   ConstHandle2Slices self,
   const Integer32 dimension
) {
   return detail::getByMetadatum<CPP,Handle2Slice>
      (CLASSNAME, CLASSNAME+"SliceGetByDimension",
       self, extract::slice, meta::dimension, dimension);
}

// Set, by dimension
void
SlicesSliceSetByDimension(
   ConstHandle2Slices self,
   const Integer32 dimension,
   ConstHandle2ConstSlice slice
) {
   detail::setByMetadatum<CPP,CPPSlice>
      (CLASSNAME, CLASSNAME+"SliceSetByDimension",
       self, extract::slice, meta::dimension, dimension, slice);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/covariance/Slices/src/custom.cpp"
