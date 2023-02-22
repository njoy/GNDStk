
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/Axes.hpp"
#include "Axes.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = AxesClass;
using CPP = multigroup::Axes;

static const std::string CLASSNAME = "Axes";

namespace extract {
   static auto axis = [](auto &obj) { return &obj.axis; };
   static auto grid = [](auto &obj) { return &obj.grid; };
}

using CPPAxis = general::Axis;
using CPPGrid = general::Grid;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstAxes
AxesDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Axes
AxesDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstAxes
AxesCreateConst(
   ConstHandle2Axis *const axis, const size_t axisSize,
   ConstHandle2Grid *const grid, const size_t gridSize
) {
   ConstHandle2Axes handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPAxis>{},
      std::vector<CPPGrid>{}
   );
   for (size_t AxisN = 0; AxisN < axisSize; ++AxisN)
      AxesAxisAdd(handle, axis[AxisN]);
   for (size_t GridN = 0; GridN < gridSize; ++GridN)
      AxesGridAdd(handle, grid[GridN]);
   return handle;
}

// Create, general
Handle2Axes
AxesCreate(
   ConstHandle2Axis *const axis, const size_t axisSize,
   ConstHandle2Grid *const grid, const size_t gridSize
) {
   ConstHandle2Axes handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPAxis>{},
      std::vector<CPPGrid>{}
   );
   for (size_t AxisN = 0; AxisN < axisSize; ++AxisN)
      AxesAxisAdd(handle, axis[AxisN]);
   for (size_t GridN = 0; GridN < gridSize; ++GridN)
      AxesGridAdd(handle, grid[GridN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
AxesAssign(ConstHandle2Axes self, ConstHandle2ConstAxes from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
AxesDelete(ConstHandle2ConstAxes self)
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
AxesRead(ConstHandle2Axes self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
AxesWrite(ConstHandle2ConstAxes self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
AxesPrint(ConstHandle2ConstAxes self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
AxesPrintXML(ConstHandle2ConstAxes self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
AxesPrintJSON(ConstHandle2ConstAxes self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: axis
// -----------------------------------------------------------------------------

// Has
int
AxesAxisHas(ConstHandle2ConstAxes self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AxisHas", self, extract::axis);
}

// Clear
void
AxesAxisClear(ConstHandle2Axes self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"AxisClear", self, extract::axis);
}

// Size
size_t
AxesAxisSize(ConstHandle2ConstAxes self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"AxisSize", self, extract::axis);
}

// Add
void
AxesAxisAdd(ConstHandle2Axes self, ConstHandle2ConstAxis axis)
{
   detail::addToContainer<CPP,CPPAxis>
      (CLASSNAME, CLASSNAME+"AxisAdd", self, extract::axis, axis);
}

// Get, by index \in [0,size), const
Handle2ConstAxis
AxesAxisGetConst(ConstHandle2ConstAxes self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstAxis>
      (CLASSNAME, CLASSNAME+"AxisGetConst", self, extract::axis, index_);
}

// Get, by index \in [0,size), non-const
Handle2Axis
AxesAxisGet(ConstHandle2Axes self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Axis>
      (CLASSNAME, CLASSNAME+"AxisGet", self, extract::axis, index_);
}

// Set, by index \in [0,size)
void
AxesAxisSet(
   ConstHandle2Axes self,
   const size_t index_,
   ConstHandle2ConstAxis axis
) {
   detail::setByIndex<CPP,CPPAxis>
      (CLASSNAME, CLASSNAME+"AxisSet", self, extract::axis, index_, axis);
}

// Has, by index
int
AxesAxisHasByIndex(
   ConstHandle2ConstAxes self,
   const int index
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"AxisHasByIndex",
       self, extract::axis, meta::index, index);
}

// Get, by index, const
Handle2ConstAxis
AxesAxisGetByIndexConst(
   ConstHandle2ConstAxes self,
   const int index
) {
   return detail::getByMetadatum<CPP,Handle2ConstAxis>
      (CLASSNAME, CLASSNAME+"AxisGetByIndexConst",
       self, extract::axis, meta::index, index);
}

// Get, by index, non-const
Handle2Axis
AxesAxisGetByIndex(
   ConstHandle2Axes self,
   const int index
) {
   return detail::getByMetadatum<CPP,Handle2Axis>
      (CLASSNAME, CLASSNAME+"AxisGetByIndex",
       self, extract::axis, meta::index, index);
}

// Set, by index
void
AxesAxisSetByIndex(
   ConstHandle2Axes self,
   const int index,
   ConstHandle2ConstAxis axis
) {
   detail::setByMetadatum<CPP,CPPAxis>
      (CLASSNAME, CLASSNAME+"AxisSetByIndex",
       self, extract::axis, meta::index, index, axis);
}

// Has, by label
int
AxesAxisHasByLabel(
   ConstHandle2ConstAxes self,
   const char *const label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"AxisHasByLabel",
       self, extract::axis, meta::label, label);
}

// Get, by label, const
Handle2ConstAxis
AxesAxisGetByLabelConst(
   ConstHandle2ConstAxes self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2ConstAxis>
      (CLASSNAME, CLASSNAME+"AxisGetByLabelConst",
       self, extract::axis, meta::label, label);
}

// Get, by label, non-const
Handle2Axis
AxesAxisGetByLabel(
   ConstHandle2Axes self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2Axis>
      (CLASSNAME, CLASSNAME+"AxisGetByLabel",
       self, extract::axis, meta::label, label);
}

// Set, by label
void
AxesAxisSetByLabel(
   ConstHandle2Axes self,
   const char *const label,
   ConstHandle2ConstAxis axis
) {
   detail::setByMetadatum<CPP,CPPAxis>
      (CLASSNAME, CLASSNAME+"AxisSetByLabel",
       self, extract::axis, meta::label, label, axis);
}

// Has, by unit
int
AxesAxisHasByUnit(
   ConstHandle2ConstAxes self,
   const char *const unit
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"AxisHasByUnit",
       self, extract::axis, meta::unit, unit);
}

// Get, by unit, const
Handle2ConstAxis
AxesAxisGetByUnitConst(
   ConstHandle2ConstAxes self,
   const char *const unit
) {
   return detail::getByMetadatum<CPP,Handle2ConstAxis>
      (CLASSNAME, CLASSNAME+"AxisGetByUnitConst",
       self, extract::axis, meta::unit, unit);
}

// Get, by unit, non-const
Handle2Axis
AxesAxisGetByUnit(
   ConstHandle2Axes self,
   const char *const unit
) {
   return detail::getByMetadatum<CPP,Handle2Axis>
      (CLASSNAME, CLASSNAME+"AxisGetByUnit",
       self, extract::axis, meta::unit, unit);
}

// Set, by unit
void
AxesAxisSetByUnit(
   ConstHandle2Axes self,
   const char *const unit,
   ConstHandle2ConstAxis axis
) {
   detail::setByMetadatum<CPP,CPPAxis>
      (CLASSNAME, CLASSNAME+"AxisSetByUnit",
       self, extract::axis, meta::unit, unit, axis);
}


// -----------------------------------------------------------------------------
// Child: grid
// -----------------------------------------------------------------------------

// Has
int
AxesGridHas(ConstHandle2ConstAxes self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"GridHas", self, extract::grid);
}

// Clear
void
AxesGridClear(ConstHandle2Axes self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"GridClear", self, extract::grid);
}

// Size
size_t
AxesGridSize(ConstHandle2ConstAxes self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"GridSize", self, extract::grid);
}

// Add
void
AxesGridAdd(ConstHandle2Axes self, ConstHandle2ConstGrid grid)
{
   detail::addToContainer<CPP,CPPGrid>
      (CLASSNAME, CLASSNAME+"GridAdd", self, extract::grid, grid);
}

// Get, by index \in [0,size), const
Handle2ConstGrid
AxesGridGetConst(ConstHandle2ConstAxes self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstGrid>
      (CLASSNAME, CLASSNAME+"GridGetConst", self, extract::grid, index_);
}

// Get, by index \in [0,size), non-const
Handle2Grid
AxesGridGet(ConstHandle2Axes self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Grid>
      (CLASSNAME, CLASSNAME+"GridGet", self, extract::grid, index_);
}

// Set, by index \in [0,size)
void
AxesGridSet(
   ConstHandle2Axes self,
   const size_t index_,
   ConstHandle2ConstGrid grid
) {
   detail::setByIndex<CPP,CPPGrid>
      (CLASSNAME, CLASSNAME+"GridSet", self, extract::grid, index_, grid);
}

// Has, by index
int
AxesGridHasByIndex(
   ConstHandle2ConstAxes self,
   const int index
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"GridHasByIndex",
       self, extract::grid, meta::index, index);
}

// Get, by index, const
Handle2ConstGrid
AxesGridGetByIndexConst(
   ConstHandle2ConstAxes self,
   const int index
) {
   return detail::getByMetadatum<CPP,Handle2ConstGrid>
      (CLASSNAME, CLASSNAME+"GridGetByIndexConst",
       self, extract::grid, meta::index, index);
}

// Get, by index, non-const
Handle2Grid
AxesGridGetByIndex(
   ConstHandle2Axes self,
   const int index
) {
   return detail::getByMetadatum<CPP,Handle2Grid>
      (CLASSNAME, CLASSNAME+"GridGetByIndex",
       self, extract::grid, meta::index, index);
}

// Set, by index
void
AxesGridSetByIndex(
   ConstHandle2Axes self,
   const int index,
   ConstHandle2ConstGrid grid
) {
   detail::setByMetadatum<CPP,CPPGrid>
      (CLASSNAME, CLASSNAME+"GridSetByIndex",
       self, extract::grid, meta::index, index, grid);
}

// Has, by label
int
AxesGridHasByLabel(
   ConstHandle2ConstAxes self,
   const char *const label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"GridHasByLabel",
       self, extract::grid, meta::label, label);
}

// Get, by label, const
Handle2ConstGrid
AxesGridGetByLabelConst(
   ConstHandle2ConstAxes self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2ConstGrid>
      (CLASSNAME, CLASSNAME+"GridGetByLabelConst",
       self, extract::grid, meta::label, label);
}

// Get, by label, non-const
Handle2Grid
AxesGridGetByLabel(
   ConstHandle2Axes self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2Grid>
      (CLASSNAME, CLASSNAME+"GridGetByLabel",
       self, extract::grid, meta::label, label);
}

// Set, by label
void
AxesGridSetByLabel(
   ConstHandle2Axes self,
   const char *const label,
   ConstHandle2ConstGrid grid
) {
   detail::setByMetadatum<CPP,CPPGrid>
      (CLASSNAME, CLASSNAME+"GridSetByLabel",
       self, extract::grid, meta::label, label, grid);
}

// Has, by unit
int
AxesGridHasByUnit(
   ConstHandle2ConstAxes self,
   const char *const unit
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"GridHasByUnit",
       self, extract::grid, meta::unit, unit);
}

// Get, by unit, const
Handle2ConstGrid
AxesGridGetByUnitConst(
   ConstHandle2ConstAxes self,
   const char *const unit
) {
   return detail::getByMetadatum<CPP,Handle2ConstGrid>
      (CLASSNAME, CLASSNAME+"GridGetByUnitConst",
       self, extract::grid, meta::unit, unit);
}

// Get, by unit, non-const
Handle2Grid
AxesGridGetByUnit(
   ConstHandle2Axes self,
   const char *const unit
) {
   return detail::getByMetadatum<CPP,Handle2Grid>
      (CLASSNAME, CLASSNAME+"GridGetByUnit",
       self, extract::grid, meta::unit, unit);
}

// Set, by unit
void
AxesGridSetByUnit(
   ConstHandle2Axes self,
   const char *const unit,
   ConstHandle2ConstGrid grid
) {
   detail::setByMetadatum<CPP,CPPGrid>
      (CLASSNAME, CLASSNAME+"GridSetByUnit",
       self, extract::grid, meta::unit, unit, grid);
}

// Has, by style
int
AxesGridHasByStyle(
   ConstHandle2ConstAxes self,
   const char *const style
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"GridHasByStyle",
       self, extract::grid, meta::style, style);
}

// Get, by style, const
Handle2ConstGrid
AxesGridGetByStyleConst(
   ConstHandle2ConstAxes self,
   const char *const style
) {
   return detail::getByMetadatum<CPP,Handle2ConstGrid>
      (CLASSNAME, CLASSNAME+"GridGetByStyleConst",
       self, extract::grid, meta::style, style);
}

// Get, by style, non-const
Handle2Grid
AxesGridGetByStyle(
   ConstHandle2Axes self,
   const char *const style
) {
   return detail::getByMetadatum<CPP,Handle2Grid>
      (CLASSNAME, CLASSNAME+"GridGetByStyle",
       self, extract::grid, meta::style, style);
}

// Set, by style
void
AxesGridSetByStyle(
   ConstHandle2Axes self,
   const char *const style,
   ConstHandle2ConstGrid grid
) {
   detail::setByMetadatum<CPP,CPPGrid>
      (CLASSNAME, CLASSNAME+"GridSetByStyle",
       self, extract::grid, meta::style, style, grid);
}

// Has, by interpolation
int
AxesGridHasByInterpolation(
   ConstHandle2ConstAxes self,
   const char *const interpolation
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"GridHasByInterpolation",
       self, extract::grid, meta::interpolation, interpolation);
}

// Get, by interpolation, const
Handle2ConstGrid
AxesGridGetByInterpolationConst(
   ConstHandle2ConstAxes self,
   const char *const interpolation
) {
   return detail::getByMetadatum<CPP,Handle2ConstGrid>
      (CLASSNAME, CLASSNAME+"GridGetByInterpolationConst",
       self, extract::grid, meta::interpolation, interpolation);
}

// Get, by interpolation, non-const
Handle2Grid
AxesGridGetByInterpolation(
   ConstHandle2Axes self,
   const char *const interpolation
) {
   return detail::getByMetadatum<CPP,Handle2Grid>
      (CLASSNAME, CLASSNAME+"GridGetByInterpolation",
       self, extract::grid, meta::interpolation, interpolation);
}

// Set, by interpolation
void
AxesGridSetByInterpolation(
   ConstHandle2Axes self,
   const char *const interpolation,
   ConstHandle2ConstGrid grid
) {
   detail::setByMetadatum<CPP,CPPGrid>
      (CLASSNAME, CLASSNAME+"GridSetByInterpolation",
       self, extract::grid, meta::interpolation, interpolation, grid);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Axes/src/custom.cpp"