
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/GaugeBosons.hpp"
#include "GaugeBosons.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = GaugeBosonsClass;
using CPP = multigroup::GaugeBosons;

static const std::string CLASSNAME = "GaugeBosons";

namespace extract {
   static auto gaugeBoson = [](auto &obj) { return &obj.gaugeBoson; };
}

using CPPGaugeBoson = general::GaugeBoson;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstGaugeBosons
GaugeBosonsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default, non-const
Handle2GaugeBosons
GaugeBosonsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstGaugeBosons
GaugeBosonsCreateConst(
   ConstHandle2GaugeBoson *const gaugeBoson, const size_t gaugeBosonSize
) {
   ConstHandle2GaugeBosons handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPGaugeBoson>{}
   );
   for (size_t GaugeBosonN = 0; GaugeBosonN < gaugeBosonSize; ++GaugeBosonN)
      GaugeBosonsGaugeBosonAdd(handle, gaugeBoson[GaugeBosonN]);
   return handle;
}

// Create, general, non-const
Handle2GaugeBosons
GaugeBosonsCreate(
   ConstHandle2GaugeBoson *const gaugeBoson, const size_t gaugeBosonSize
) {
   ConstHandle2GaugeBosons handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPGaugeBoson>{}
   );
   for (size_t GaugeBosonN = 0; GaugeBosonN < gaugeBosonSize; ++GaugeBosonN)
      GaugeBosonsGaugeBosonAdd(handle, gaugeBoson[GaugeBosonN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
GaugeBosonsAssign(ConstHandle2GaugeBosons self, ConstHandle2ConstGaugeBosons from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
GaugeBosonsDelete(ConstHandle2ConstGaugeBosons self)
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
GaugeBosonsRead(ConstHandle2GaugeBosons self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
GaugeBosonsWrite(ConstHandle2ConstGaugeBosons self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
GaugeBosonsPrint(ConstHandle2ConstGaugeBosons self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
GaugeBosonsPrintXML(ConstHandle2ConstGaugeBosons self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
GaugeBosonsPrintJSON(ConstHandle2ConstGaugeBosons self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: gaugeBoson
// -----------------------------------------------------------------------------

// Has
int
GaugeBosonsGaugeBosonHas(ConstHandle2ConstGaugeBosons self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"GaugeBosonHas", self, extract::gaugeBoson);
}

// Clear
void
GaugeBosonsGaugeBosonClear(ConstHandle2GaugeBosons self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"GaugeBosonClear", self, extract::gaugeBoson);
}

// Size
size_t
GaugeBosonsGaugeBosonSize(ConstHandle2ConstGaugeBosons self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"GaugeBosonSize", self, extract::gaugeBoson);
}

// Add
void
GaugeBosonsGaugeBosonAdd(ConstHandle2GaugeBosons self, ConstHandle2ConstGaugeBoson gaugeBoson)
{
   detail::addToContainer<CPP,CPPGaugeBoson>
      (CLASSNAME, CLASSNAME+"GaugeBosonAdd", self, extract::gaugeBoson, gaugeBoson);
}

// Get, by index \in [0,size), const
Handle2ConstGaugeBoson
GaugeBosonsGaugeBosonGetConst(ConstHandle2ConstGaugeBosons self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstGaugeBoson>
      (CLASSNAME, CLASSNAME+"GaugeBosonGetConst", self, extract::gaugeBoson, index_);
}

// Get, by index \in [0,size), non-const
Handle2GaugeBoson
GaugeBosonsGaugeBosonGet(ConstHandle2GaugeBosons self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2GaugeBoson>
      (CLASSNAME, CLASSNAME+"GaugeBosonGet", self, extract::gaugeBoson, index_);
}

// Set, by index \in [0,size)
void
GaugeBosonsGaugeBosonSet(
   ConstHandle2GaugeBosons self,
   const size_t index_,
   ConstHandle2ConstGaugeBoson gaugeBoson
) {
   detail::setByIndex<CPP,CPPGaugeBoson>
      (CLASSNAME, CLASSNAME+"GaugeBosonSet", self, extract::gaugeBoson, index_, gaugeBoson);
}

// ------------------------
// Re: metadatum id
// ------------------------

// Has, by id
int
GaugeBosonsGaugeBosonHasById(
   ConstHandle2ConstGaugeBosons self,
   const char *const id
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"GaugeBosonHasById",
       self, extract::gaugeBoson, meta::id, id);
}

// Get, by id, const
Handle2ConstGaugeBoson
GaugeBosonsGaugeBosonGetByIdConst(
   ConstHandle2ConstGaugeBosons self,
   const char *const id
) {
   return detail::getByMetadatum<CPP,Handle2ConstGaugeBoson>
      (CLASSNAME, CLASSNAME+"GaugeBosonGetByIdConst",
       self, extract::gaugeBoson, meta::id, id);
}

// Get, by id, non-const
Handle2GaugeBoson
GaugeBosonsGaugeBosonGetById(
   ConstHandle2GaugeBosons self,
   const char *const id
) {
   return detail::getByMetadatum<CPP,Handle2GaugeBoson>
      (CLASSNAME, CLASSNAME+"GaugeBosonGetById",
       self, extract::gaugeBoson, meta::id, id);
}

// Set, by id
void
GaugeBosonsGaugeBosonSetById(
   ConstHandle2GaugeBosons self,
   const char *const id,
   ConstHandle2ConstGaugeBoson gaugeBoson
) {
   detail::setByMetadatum<CPP,CPPGaugeBoson>
      (CLASSNAME, CLASSNAME+"GaugeBosonSetById",
       self, extract::gaugeBoson, meta::id, id, gaugeBoson);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/GaugeBosons/src/custom.cpp"
