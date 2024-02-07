
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/DelayedNeutron.hpp"
#include "DelayedNeutron.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = DelayedNeutronClass;
using CPP = multigroup::DelayedNeutron;

static const std::string CLASSNAME = "DelayedNeutron";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto rate = [](auto &obj) { return &obj.rate; };
   static auto product = [](auto &obj) { return &obj.product; };
}

using CPPRate = general::Rate;
using CPPProduct = reduced::Product;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstDelayedNeutron
DelayedNeutronDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default, non-const
Handle2DelayedNeutron
DelayedNeutronDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstDelayedNeutron
DelayedNeutronCreateConst(
   const char *const label,
   ConstHandle2ConstRate rate,
   ConstHandle2ConstProduct product
) {
   ConstHandle2DelayedNeutron handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      detail::tocpp<CPPRate>(rate),
      detail::tocpp<CPPProduct>(product)
   );
   return handle;
}

// Create, general, non-const
Handle2DelayedNeutron
DelayedNeutronCreate(
   const char *const label,
   ConstHandle2ConstRate rate,
   ConstHandle2ConstProduct product
) {
   ConstHandle2DelayedNeutron handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      detail::tocpp<CPPRate>(rate),
      detail::tocpp<CPPProduct>(product)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
DelayedNeutronAssign(ConstHandle2DelayedNeutron self, ConstHandle2ConstDelayedNeutron from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
DelayedNeutronDelete(ConstHandle2ConstDelayedNeutron self)
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
DelayedNeutronRead(ConstHandle2DelayedNeutron self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
DelayedNeutronWrite(ConstHandle2ConstDelayedNeutron self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
DelayedNeutronPrint(ConstHandle2ConstDelayedNeutron self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
DelayedNeutronPrintXML(ConstHandle2ConstDelayedNeutron self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
DelayedNeutronPrintJSON(ConstHandle2ConstDelayedNeutron self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
DelayedNeutronLabelHas(ConstHandle2ConstDelayedNeutron self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
const char *
DelayedNeutronLabelGet(ConstHandle2ConstDelayedNeutron self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
DelayedNeutronLabelSet(ConstHandle2DelayedNeutron self, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Child: rate
// -----------------------------------------------------------------------------

// Has
int
DelayedNeutronRateHas(ConstHandle2ConstDelayedNeutron self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"RateHas", self, extract::rate);
}

// Get, const
Handle2ConstRate
DelayedNeutronRateGetConst(ConstHandle2ConstDelayedNeutron self)
{
   return detail::getField<CPP,Handle2ConstRate>
      (CLASSNAME, CLASSNAME+"RateGetConst", self, extract::rate);
}

// Get, non-const
Handle2Rate
DelayedNeutronRateGet(ConstHandle2DelayedNeutron self)
{
   return detail::getField<CPP,Handle2Rate>
      (CLASSNAME, CLASSNAME+"RateGet", self, extract::rate);
}

// Set
void
DelayedNeutronRateSet(ConstHandle2DelayedNeutron self, ConstHandle2ConstRate rate)
{
   detail::setField<CPP,CPPRate>
      (CLASSNAME, CLASSNAME+"RateSet", self, extract::rate, rate);
}


// -----------------------------------------------------------------------------
// Child: product
// -----------------------------------------------------------------------------

// Has
int
DelayedNeutronProductHas(ConstHandle2ConstDelayedNeutron self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ProductHas", self, extract::product);
}

// Get, const
Handle2ConstProduct
DelayedNeutronProductGetConst(ConstHandle2ConstDelayedNeutron self)
{
   return detail::getField<CPP,Handle2ConstProduct>
      (CLASSNAME, CLASSNAME+"ProductGetConst", self, extract::product);
}

// Get, non-const
Handle2Product
DelayedNeutronProductGet(ConstHandle2DelayedNeutron self)
{
   return detail::getField<CPP,Handle2Product>
      (CLASSNAME, CLASSNAME+"ProductGet", self, extract::product);
}

// Set
void
DelayedNeutronProductSet(ConstHandle2DelayedNeutron self, ConstHandle2ConstProduct product)
{
   detail::setField<CPP,CPPProduct>
      (CLASSNAME, CLASSNAME+"ProductSet", self, extract::product, product);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/DelayedNeutron/src/custom.cpp"