
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2.0/general/Function1ds.hpp"
#include "Function1ds.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = Function1dsClass;
using CPP = multigroup::Function1ds;

static const std::string CLASSNAME = "Function1ds";

namespace extract {
   static auto Legendre = [](auto &obj) { return &obj.Legendre; };
   static auto XYs1d = [](auto &obj) { return &obj.XYs1d; };
   static auto regions1d = [](auto &obj) { return &obj.regions1d; };
}

using CPPLegendre = general::Legendre;
using CPPXYs1d = general::XYs1d;
using CPPRegions1d = general::Regions1d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstFunction1ds
Function1dsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Function1ds
Function1dsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstFunction1ds
Function1dsCreateConst(
   ConstHandle2Legendre *const Legendre, const size_t LegendreSize,
   ConstHandle2XYs1d *const XYs1d, const size_t XYs1dSize,
   ConstHandle2Regions1d *const regions1d, const size_t regions1dSize
) {
   ConstHandle2Function1ds handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPLegendre>{},
      std::vector<CPPXYs1d>{},
      std::vector<CPPRegions1d>{}
   );
   for (size_t LegendreN = 0; LegendreN < LegendreSize; ++LegendreN)
      Function1dsLegendreAdd(handle, Legendre[LegendreN]);
   for (size_t XYs1dN = 0; XYs1dN < XYs1dSize; ++XYs1dN)
      Function1dsXYs1dAdd(handle, XYs1d[XYs1dN]);
   for (size_t Regions1dN = 0; Regions1dN < regions1dSize; ++Regions1dN)
      Function1dsRegions1dAdd(handle, regions1d[Regions1dN]);
   return handle;
}

// Create, general
Handle2Function1ds
Function1dsCreate(
   ConstHandle2Legendre *const Legendre, const size_t LegendreSize,
   ConstHandle2XYs1d *const XYs1d, const size_t XYs1dSize,
   ConstHandle2Regions1d *const regions1d, const size_t regions1dSize
) {
   ConstHandle2Function1ds handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPLegendre>{},
      std::vector<CPPXYs1d>{},
      std::vector<CPPRegions1d>{}
   );
   for (size_t LegendreN = 0; LegendreN < LegendreSize; ++LegendreN)
      Function1dsLegendreAdd(handle, Legendre[LegendreN]);
   for (size_t XYs1dN = 0; XYs1dN < XYs1dSize; ++XYs1dN)
      Function1dsXYs1dAdd(handle, XYs1d[XYs1dN]);
   for (size_t Regions1dN = 0; Regions1dN < regions1dSize; ++Regions1dN)
      Function1dsRegions1dAdd(handle, regions1d[Regions1dN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
Function1dsAssign(ConstHandle2Function1ds self, ConstHandle2ConstFunction1ds from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
Function1dsDelete(ConstHandle2ConstFunction1ds self)
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
Function1dsRead(ConstHandle2Function1ds self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
Function1dsWrite(ConstHandle2ConstFunction1ds self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
Function1dsPrint(ConstHandle2ConstFunction1ds self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
Function1dsPrintXML(ConstHandle2ConstFunction1ds self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
Function1dsPrintJSON(ConstHandle2ConstFunction1ds self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: Legendre
// -----------------------------------------------------------------------------

// Has
int
Function1dsLegendreHas(ConstHandle2ConstFunction1ds self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LegendreHas", self, extract::Legendre);
}

// Clear
void
Function1dsLegendreClear(ConstHandle2Function1ds self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"LegendreClear", self, extract::Legendre);
}

// Size
size_t
Function1dsLegendreSize(ConstHandle2ConstFunction1ds self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"LegendreSize", self, extract::Legendre);
}

// Add
void
Function1dsLegendreAdd(ConstHandle2Function1ds self, ConstHandle2ConstLegendre Legendre)
{
   detail::addToContainer<CPP,CPPLegendre>
      (CLASSNAME, CLASSNAME+"LegendreAdd", self, extract::Legendre, Legendre);
}

// Get, by index \in [0,size), const
Handle2ConstLegendre
Function1dsLegendreGetConst(ConstHandle2ConstFunction1ds self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstLegendre>
      (CLASSNAME, CLASSNAME+"LegendreGetConst", self, extract::Legendre, index_);
}

// Get, by index \in [0,size), non-const
Handle2Legendre
Function1dsLegendreGet(ConstHandle2Function1ds self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Legendre>
      (CLASSNAME, CLASSNAME+"LegendreGet", self, extract::Legendre, index_);
}

// Set, by index \in [0,size)
void
Function1dsLegendreSet(
   ConstHandle2Function1ds self,
   const size_t index_,
   ConstHandle2ConstLegendre Legendre
) {
   detail::setByIndex<CPP,CPPLegendre>
      (CLASSNAME, CLASSNAME+"LegendreSet", self, extract::Legendre, index_, Legendre);
}

// Has, by outerDomainValue
int
Function1dsLegendreHasByOuterDomainValue(
   ConstHandle2ConstFunction1ds self,
   const double outerDomainValue
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"LegendreHasByOuterDomainValue",
       self, extract::Legendre, meta::outerDomainValue, outerDomainValue);
}

// Get, by outerDomainValue, const
Handle2ConstLegendre
Function1dsLegendreGetByOuterDomainValueConst(
   ConstHandle2ConstFunction1ds self,
   const double outerDomainValue
) {
   return detail::getByMetadatum<CPP,Handle2ConstLegendre>
      (CLASSNAME, CLASSNAME+"LegendreGetByOuterDomainValueConst",
       self, extract::Legendre, meta::outerDomainValue, outerDomainValue);
}

// Get, by outerDomainValue, non-const
Handle2Legendre
Function1dsLegendreGetByOuterDomainValue(
   ConstHandle2Function1ds self,
   const double outerDomainValue
) {
   return detail::getByMetadatum<CPP,Handle2Legendre>
      (CLASSNAME, CLASSNAME+"LegendreGetByOuterDomainValue",
       self, extract::Legendre, meta::outerDomainValue, outerDomainValue);
}

// Set, by outerDomainValue
void
Function1dsLegendreSetByOuterDomainValue(
   ConstHandle2Function1ds self,
   const double outerDomainValue,
   ConstHandle2ConstLegendre Legendre
) {
   detail::setByMetadatum<CPP,CPPLegendre>
      (CLASSNAME, CLASSNAME+"LegendreSetByOuterDomainValue",
       self, extract::Legendre, meta::outerDomainValue, outerDomainValue, Legendre);
}


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// Has
int
Function1dsXYs1dHas(ConstHandle2ConstFunction1ds self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"XYs1dHas", self, extract::XYs1d);
}

// Clear
void
Function1dsXYs1dClear(ConstHandle2Function1ds self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"XYs1dClear", self, extract::XYs1d);
}

// Size
size_t
Function1dsXYs1dSize(ConstHandle2ConstFunction1ds self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"XYs1dSize", self, extract::XYs1d);
}

// Add
void
Function1dsXYs1dAdd(ConstHandle2Function1ds self, ConstHandle2ConstXYs1d XYs1d)
{
   detail::addToContainer<CPP,CPPXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dAdd", self, extract::XYs1d, XYs1d);
}

// Get, by index \in [0,size), const
Handle2ConstXYs1d
Function1dsXYs1dGetConst(ConstHandle2ConstFunction1ds self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGetConst", self, extract::XYs1d, index_);
}

// Get, by index \in [0,size), non-const
Handle2XYs1d
Function1dsXYs1dGet(ConstHandle2Function1ds self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2XYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGet", self, extract::XYs1d, index_);
}

// Set, by index \in [0,size)
void
Function1dsXYs1dSet(
   ConstHandle2Function1ds self,
   const size_t index_,
   ConstHandle2ConstXYs1d XYs1d
) {
   detail::setByIndex<CPP,CPPXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dSet", self, extract::XYs1d, index_, XYs1d);
}

// Has, by label
int
Function1dsXYs1dHasByLabel(
   ConstHandle2ConstFunction1ds self,
   const char *const label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"XYs1dHasByLabel",
       self, extract::XYs1d, meta::label, label);
}

// Get, by label, const
Handle2ConstXYs1d
Function1dsXYs1dGetByLabelConst(
   ConstHandle2ConstFunction1ds self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2ConstXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGetByLabelConst",
       self, extract::XYs1d, meta::label, label);
}

// Get, by label, non-const
Handle2XYs1d
Function1dsXYs1dGetByLabel(
   ConstHandle2Function1ds self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2XYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGetByLabel",
       self, extract::XYs1d, meta::label, label);
}

// Set, by label
void
Function1dsXYs1dSetByLabel(
   ConstHandle2Function1ds self,
   const char *const label,
   ConstHandle2ConstXYs1d XYs1d
) {
   detail::setByMetadatum<CPP,CPPXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dSetByLabel",
       self, extract::XYs1d, meta::label, label, XYs1d);
}

// Has, by index
int
Function1dsXYs1dHasByIndex(
   ConstHandle2ConstFunction1ds self,
   const int index
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"XYs1dHasByIndex",
       self, extract::XYs1d, meta::index, index);
}

// Get, by index, const
Handle2ConstXYs1d
Function1dsXYs1dGetByIndexConst(
   ConstHandle2ConstFunction1ds self,
   const int index
) {
   return detail::getByMetadatum<CPP,Handle2ConstXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGetByIndexConst",
       self, extract::XYs1d, meta::index, index);
}

// Get, by index, non-const
Handle2XYs1d
Function1dsXYs1dGetByIndex(
   ConstHandle2Function1ds self,
   const int index
) {
   return detail::getByMetadatum<CPP,Handle2XYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGetByIndex",
       self, extract::XYs1d, meta::index, index);
}

// Set, by index
void
Function1dsXYs1dSetByIndex(
   ConstHandle2Function1ds self,
   const int index,
   ConstHandle2ConstXYs1d XYs1d
) {
   detail::setByMetadatum<CPP,CPPXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dSetByIndex",
       self, extract::XYs1d, meta::index, index, XYs1d);
}

// Has, by interpolation
int
Function1dsXYs1dHasByInterpolation(
   ConstHandle2ConstFunction1ds self,
   const char *const interpolation
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"XYs1dHasByInterpolation",
       self, extract::XYs1d, meta::interpolation, interpolation);
}

// Get, by interpolation, const
Handle2ConstXYs1d
Function1dsXYs1dGetByInterpolationConst(
   ConstHandle2ConstFunction1ds self,
   const char *const interpolation
) {
   return detail::getByMetadatum<CPP,Handle2ConstXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGetByInterpolationConst",
       self, extract::XYs1d, meta::interpolation, interpolation);
}

// Get, by interpolation, non-const
Handle2XYs1d
Function1dsXYs1dGetByInterpolation(
   ConstHandle2Function1ds self,
   const char *const interpolation
) {
   return detail::getByMetadatum<CPP,Handle2XYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGetByInterpolation",
       self, extract::XYs1d, meta::interpolation, interpolation);
}

// Set, by interpolation
void
Function1dsXYs1dSetByInterpolation(
   ConstHandle2Function1ds self,
   const char *const interpolation,
   ConstHandle2ConstXYs1d XYs1d
) {
   detail::setByMetadatum<CPP,CPPXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dSetByInterpolation",
       self, extract::XYs1d, meta::interpolation, interpolation, XYs1d);
}

// Has, by outerDomainValue
int
Function1dsXYs1dHasByOuterDomainValue(
   ConstHandle2ConstFunction1ds self,
   const double outerDomainValue
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"XYs1dHasByOuterDomainValue",
       self, extract::XYs1d, meta::outerDomainValue, outerDomainValue);
}

// Get, by outerDomainValue, const
Handle2ConstXYs1d
Function1dsXYs1dGetByOuterDomainValueConst(
   ConstHandle2ConstFunction1ds self,
   const double outerDomainValue
) {
   return detail::getByMetadatum<CPP,Handle2ConstXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGetByOuterDomainValueConst",
       self, extract::XYs1d, meta::outerDomainValue, outerDomainValue);
}

// Get, by outerDomainValue, non-const
Handle2XYs1d
Function1dsXYs1dGetByOuterDomainValue(
   ConstHandle2Function1ds self,
   const double outerDomainValue
) {
   return detail::getByMetadatum<CPP,Handle2XYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGetByOuterDomainValue",
       self, extract::XYs1d, meta::outerDomainValue, outerDomainValue);
}

// Set, by outerDomainValue
void
Function1dsXYs1dSetByOuterDomainValue(
   ConstHandle2Function1ds self,
   const double outerDomainValue,
   ConstHandle2ConstXYs1d XYs1d
) {
   detail::setByMetadatum<CPP,CPPXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dSetByOuterDomainValue",
       self, extract::XYs1d, meta::outerDomainValue, outerDomainValue, XYs1d);
}


// -----------------------------------------------------------------------------
// Child: regions1d
// -----------------------------------------------------------------------------

// Has
int
Function1dsRegions1dHas(ConstHandle2ConstFunction1ds self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Regions1dHas", self, extract::regions1d);
}

// Clear
void
Function1dsRegions1dClear(ConstHandle2Function1ds self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"Regions1dClear", self, extract::regions1d);
}

// Size
size_t
Function1dsRegions1dSize(ConstHandle2ConstFunction1ds self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"Regions1dSize", self, extract::regions1d);
}

// Add
void
Function1dsRegions1dAdd(ConstHandle2Function1ds self, ConstHandle2ConstRegions1d regions1d)
{
   detail::addToContainer<CPP,CPPRegions1d>
      (CLASSNAME, CLASSNAME+"Regions1dAdd", self, extract::regions1d, regions1d);
}

// Get, by index \in [0,size), const
Handle2ConstRegions1d
Function1dsRegions1dGetConst(ConstHandle2ConstFunction1ds self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstRegions1d>
      (CLASSNAME, CLASSNAME+"Regions1dGetConst", self, extract::regions1d, index_);
}

// Get, by index \in [0,size), non-const
Handle2Regions1d
Function1dsRegions1dGet(ConstHandle2Function1ds self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Regions1d>
      (CLASSNAME, CLASSNAME+"Regions1dGet", self, extract::regions1d, index_);
}

// Set, by index \in [0,size)
void
Function1dsRegions1dSet(
   ConstHandle2Function1ds self,
   const size_t index_,
   ConstHandle2ConstRegions1d regions1d
) {
   detail::setByIndex<CPP,CPPRegions1d>
      (CLASSNAME, CLASSNAME+"Regions1dSet", self, extract::regions1d, index_, regions1d);
}

// Has, by label
int
Function1dsRegions1dHasByLabel(
   ConstHandle2ConstFunction1ds self,
   const char *const label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"Regions1dHasByLabel",
       self, extract::regions1d, meta::label, label);
}

// Get, by label, const
Handle2ConstRegions1d
Function1dsRegions1dGetByLabelConst(
   ConstHandle2ConstFunction1ds self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2ConstRegions1d>
      (CLASSNAME, CLASSNAME+"Regions1dGetByLabelConst",
       self, extract::regions1d, meta::label, label);
}

// Get, by label, non-const
Handle2Regions1d
Function1dsRegions1dGetByLabel(
   ConstHandle2Function1ds self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2Regions1d>
      (CLASSNAME, CLASSNAME+"Regions1dGetByLabel",
       self, extract::regions1d, meta::label, label);
}

// Set, by label
void
Function1dsRegions1dSetByLabel(
   ConstHandle2Function1ds self,
   const char *const label,
   ConstHandle2ConstRegions1d regions1d
) {
   detail::setByMetadatum<CPP,CPPRegions1d>
      (CLASSNAME, CLASSNAME+"Regions1dSetByLabel",
       self, extract::regions1d, meta::label, label, regions1d);
}

// Has, by outerDomainValue
int
Function1dsRegions1dHasByOuterDomainValue(
   ConstHandle2ConstFunction1ds self,
   const double outerDomainValue
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"Regions1dHasByOuterDomainValue",
       self, extract::regions1d, meta::outerDomainValue, outerDomainValue);
}

// Get, by outerDomainValue, const
Handle2ConstRegions1d
Function1dsRegions1dGetByOuterDomainValueConst(
   ConstHandle2ConstFunction1ds self,
   const double outerDomainValue
) {
   return detail::getByMetadatum<CPP,Handle2ConstRegions1d>
      (CLASSNAME, CLASSNAME+"Regions1dGetByOuterDomainValueConst",
       self, extract::regions1d, meta::outerDomainValue, outerDomainValue);
}

// Get, by outerDomainValue, non-const
Handle2Regions1d
Function1dsRegions1dGetByOuterDomainValue(
   ConstHandle2Function1ds self,
   const double outerDomainValue
) {
   return detail::getByMetadatum<CPP,Handle2Regions1d>
      (CLASSNAME, CLASSNAME+"Regions1dGetByOuterDomainValue",
       self, extract::regions1d, meta::outerDomainValue, outerDomainValue);
}

// Set, by outerDomainValue
void
Function1dsRegions1dSetByOuterDomainValue(
   ConstHandle2Function1ds self,
   const double outerDomainValue,
   ConstHandle2ConstRegions1d regions1d
) {
   detail::setByMetadatum<CPP,CPPRegions1d>
      (CLASSNAME, CLASSNAME+"Regions1dSetByOuterDomainValue",
       self, extract::regions1d, meta::outerDomainValue, outerDomainValue, regions1d);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Function1ds/src/custom.cpp"
