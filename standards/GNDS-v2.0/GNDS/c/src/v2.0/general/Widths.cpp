
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/Widths.hpp"
#include "Widths.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = WidthsClass;
using CPP = multigroup::Widths;

static const std::string CLASSNAME = "Widths";

namespace extract {
   static auto width = [](auto &obj) { return &obj.width; };
}

using CPPWidth = general::Width;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstWidths
WidthsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Widths
WidthsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstWidths
WidthsCreateConst(
   ConstHandle2Width *const width, const size_t widthSize
) {
   ConstHandle2Widths handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPWidth>{}
   );
   for (size_t WidthN = 0; WidthN < widthSize; ++WidthN)
      WidthsWidthAdd(handle, width[WidthN]);
   return handle;
}

// Create, general
Handle2Widths
WidthsCreate(
   ConstHandle2Width *const width, const size_t widthSize
) {
   ConstHandle2Widths handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPWidth>{}
   );
   for (size_t WidthN = 0; WidthN < widthSize; ++WidthN)
      WidthsWidthAdd(handle, width[WidthN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
WidthsAssign(ConstHandle2Widths self, ConstHandle2ConstWidths from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
WidthsDelete(ConstHandle2ConstWidths self)
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
WidthsRead(ConstHandle2Widths self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
WidthsWrite(ConstHandle2ConstWidths self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
WidthsPrint(ConstHandle2ConstWidths self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
WidthsPrintXML(ConstHandle2ConstWidths self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
WidthsPrintJSON(ConstHandle2ConstWidths self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: width
// -----------------------------------------------------------------------------

// Has
int
WidthsWidthHas(ConstHandle2ConstWidths self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"WidthHas", self, extract::width);
}

// Clear
void
WidthsWidthClear(ConstHandle2Widths self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"WidthClear", self, extract::width);
}

// Size
size_t
WidthsWidthSize(ConstHandle2ConstWidths self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"WidthSize", self, extract::width);
}

// Add
void
WidthsWidthAdd(ConstHandle2Widths self, ConstHandle2ConstWidth width)
{
   detail::addToContainer<CPP,CPPWidth>
      (CLASSNAME, CLASSNAME+"WidthAdd", self, extract::width, width);
}

// Get, by index \in [0,size), const
Handle2ConstWidth
WidthsWidthGetConst(ConstHandle2ConstWidths self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstWidth>
      (CLASSNAME, CLASSNAME+"WidthGetConst", self, extract::width, index_);
}

// Get, by index \in [0,size), non-const
Handle2Width
WidthsWidthGet(ConstHandle2Widths self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Width>
      (CLASSNAME, CLASSNAME+"WidthGet", self, extract::width, index_);
}

// Set, by index \in [0,size)
void
WidthsWidthSet(
   ConstHandle2Widths self,
   const size_t index_,
   ConstHandle2ConstWidth width
) {
   detail::setByIndex<CPP,CPPWidth>
      (CLASSNAME, CLASSNAME+"WidthSet", self, extract::width, index_, width);
}

// Has, by label
int
WidthsWidthHasByLabel(
   ConstHandle2ConstWidths self,
   const char *const label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"WidthHasByLabel",
       self, extract::width, meta::label, label);
}

// Get, by label, const
Handle2ConstWidth
WidthsWidthGetByLabelConst(
   ConstHandle2ConstWidths self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2ConstWidth>
      (CLASSNAME, CLASSNAME+"WidthGetByLabelConst",
       self, extract::width, meta::label, label);
}

// Get, by label, non-const
Handle2Width
WidthsWidthGetByLabel(
   ConstHandle2Widths self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2Width>
      (CLASSNAME, CLASSNAME+"WidthGetByLabel",
       self, extract::width, meta::label, label);
}

// Set, by label
void
WidthsWidthSetByLabel(
   ConstHandle2Widths self,
   const char *const label,
   ConstHandle2ConstWidth width
) {
   detail::setByMetadatum<CPP,CPPWidth>
      (CLASSNAME, CLASSNAME+"WidthSetByLabel",
       self, extract::width, meta::label, label, width);
}

// Has, by resonanceReaction
int
WidthsWidthHasByResonanceReaction(
   ConstHandle2ConstWidths self,
   const char *const resonanceReaction
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"WidthHasByResonanceReaction",
       self, extract::width, meta::resonanceReaction, resonanceReaction);
}

// Get, by resonanceReaction, const
Handle2ConstWidth
WidthsWidthGetByResonanceReactionConst(
   ConstHandle2ConstWidths self,
   const char *const resonanceReaction
) {
   return detail::getByMetadatum<CPP,Handle2ConstWidth>
      (CLASSNAME, CLASSNAME+"WidthGetByResonanceReactionConst",
       self, extract::width, meta::resonanceReaction, resonanceReaction);
}

// Get, by resonanceReaction, non-const
Handle2Width
WidthsWidthGetByResonanceReaction(
   ConstHandle2Widths self,
   const char *const resonanceReaction
) {
   return detail::getByMetadatum<CPP,Handle2Width>
      (CLASSNAME, CLASSNAME+"WidthGetByResonanceReaction",
       self, extract::width, meta::resonanceReaction, resonanceReaction);
}

// Set, by resonanceReaction
void
WidthsWidthSetByResonanceReaction(
   ConstHandle2Widths self,
   const char *const resonanceReaction,
   ConstHandle2ConstWidth width
) {
   detail::setByMetadatum<CPP,CPPWidth>
      (CLASSNAME, CLASSNAME+"WidthSetByResonanceReaction",
       self, extract::width, meta::resonanceReaction, resonanceReaction, width);
}

// Has, by degreesOfFreedom
int
WidthsWidthHasByDegreesOfFreedom(
   ConstHandle2ConstWidths self,
   const int degreesOfFreedom
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"WidthHasByDegreesOfFreedom",
       self, extract::width, meta::degreesOfFreedom, degreesOfFreedom);
}

// Get, by degreesOfFreedom, const
Handle2ConstWidth
WidthsWidthGetByDegreesOfFreedomConst(
   ConstHandle2ConstWidths self,
   const int degreesOfFreedom
) {
   return detail::getByMetadatum<CPP,Handle2ConstWidth>
      (CLASSNAME, CLASSNAME+"WidthGetByDegreesOfFreedomConst",
       self, extract::width, meta::degreesOfFreedom, degreesOfFreedom);
}

// Get, by degreesOfFreedom, non-const
Handle2Width
WidthsWidthGetByDegreesOfFreedom(
   ConstHandle2Widths self,
   const int degreesOfFreedom
) {
   return detail::getByMetadatum<CPP,Handle2Width>
      (CLASSNAME, CLASSNAME+"WidthGetByDegreesOfFreedom",
       self, extract::width, meta::degreesOfFreedom, degreesOfFreedom);
}

// Set, by degreesOfFreedom
void
WidthsWidthSetByDegreesOfFreedom(
   ConstHandle2Widths self,
   const int degreesOfFreedom,
   ConstHandle2ConstWidth width
) {
   detail::setByMetadatum<CPP,CPPWidth>
      (CLASSNAME, CLASSNAME+"WidthSetByDegreesOfFreedom",
       self, extract::width, meta::degreesOfFreedom, degreesOfFreedom, width);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Widths/src/custom.cpp"