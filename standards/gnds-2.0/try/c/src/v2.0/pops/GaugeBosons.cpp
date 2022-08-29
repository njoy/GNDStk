
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/pops/GaugeBosons.hpp"
#include "GaugeBosons.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = GaugeBosonsClass;
using CPP = multigroup::GaugeBosons;

static const std::string CLASSNAME = "GaugeBosons";

namespace extract {
   static auto gaugeBoson = [](auto &obj) { return &obj.gaugeBoson; };
}

using CPPGaugeBoson = pops::GaugeBoson;


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

// Create, default
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

// Create, general
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
GaugeBosonsAssign(ConstHandle2GaugeBosons This, ConstHandle2ConstGaugeBosons from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
GaugeBosonsDelete(ConstHandle2ConstGaugeBosons This)
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
GaugeBosonsRead(ConstHandle2GaugeBosons This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
GaugeBosonsWrite(ConstHandle2ConstGaugeBosons This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
GaugeBosonsPrint(ConstHandle2ConstGaugeBosons This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
GaugeBosonsPrintXML(ConstHandle2ConstGaugeBosons This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
GaugeBosonsPrintJSON(ConstHandle2ConstGaugeBosons This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: gaugeBoson
// -----------------------------------------------------------------------------

// Has
int
GaugeBosonsGaugeBosonHas(ConstHandle2ConstGaugeBosons This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"GaugeBosonHas", This, extract::gaugeBoson);
}

// Clear
void
GaugeBosonsGaugeBosonClear(ConstHandle2GaugeBosons This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"GaugeBosonClear", This, extract::gaugeBoson);
}

// Size
size_t
GaugeBosonsGaugeBosonSize(ConstHandle2ConstGaugeBosons This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"GaugeBosonSize", This, extract::gaugeBoson);
}

// Add
void
GaugeBosonsGaugeBosonAdd(ConstHandle2GaugeBosons This, ConstHandle2ConstGaugeBoson gaugeBoson)
{
   detail::addToContainer<CPP,CPPGaugeBoson>
      (CLASSNAME, CLASSNAME+"GaugeBosonAdd", This, extract::gaugeBoson, gaugeBoson);
}

// Get, by index \in [0,size), const
Handle2ConstGaugeBoson
GaugeBosonsGaugeBosonGetConst(ConstHandle2ConstGaugeBosons This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstGaugeBoson>
      (CLASSNAME, CLASSNAME+"GaugeBosonGetConst", This, extract::gaugeBoson, index_);
}

// Get, by index \in [0,size), non-const
Handle2GaugeBoson
GaugeBosonsGaugeBosonGet(ConstHandle2GaugeBosons This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2GaugeBoson>
      (CLASSNAME, CLASSNAME+"GaugeBosonGet", This, extract::gaugeBoson, index_);
}

// Set, by index \in [0,size)
void
GaugeBosonsGaugeBosonSet(
   ConstHandle2GaugeBosons This,
   const size_t index_,
   ConstHandle2ConstGaugeBoson gaugeBoson
) {
   detail::setByIndex<CPP,CPPGaugeBoson>
      (CLASSNAME, CLASSNAME+"GaugeBosonSet", This, extract::gaugeBoson, index_, gaugeBoson);
}

// Has, by id
int
GaugeBosonsGaugeBosonHasById(
   ConstHandle2ConstGaugeBosons This,
   const XMLName id
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"GaugeBosonHasById",
       This, extract::gaugeBoson, meta::id, id);
}

// Get, by id, const
Handle2ConstGaugeBoson
GaugeBosonsGaugeBosonGetByIdConst(
   ConstHandle2ConstGaugeBosons This,
   const XMLName id
) {
   return detail::getByMetadatum<CPP,Handle2ConstGaugeBoson>
      (CLASSNAME, CLASSNAME+"GaugeBosonGetByIdConst",
       This, extract::gaugeBoson, meta::id, id);
}

// Get, by id, non-const
Handle2GaugeBoson
GaugeBosonsGaugeBosonGetById(
   ConstHandle2GaugeBosons This,
   const XMLName id
) {
   return detail::getByMetadatum<CPP,Handle2GaugeBoson>
      (CLASSNAME, CLASSNAME+"GaugeBosonGetById",
       This, extract::gaugeBoson, meta::id, id);
}

// Set, by id
void
GaugeBosonsGaugeBosonSetById(
   ConstHandle2GaugeBosons This,
   const XMLName id,
   ConstHandle2ConstGaugeBoson gaugeBoson
) {
   detail::setByMetadatum<CPP,CPPGaugeBoson>
      (CLASSNAME, CLASSNAME+"GaugeBosonSetById",
       This, extract::gaugeBoson, meta::id, id, gaugeBoson);
}
