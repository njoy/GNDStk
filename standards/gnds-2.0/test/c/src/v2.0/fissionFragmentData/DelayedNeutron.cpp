
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/fissionFragmentData/DelayedNeutron.hpp"
#include "DelayedNeutron.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = DelayedNeutronClass;
using CPP = multigroup::DelayedNeutron;

static const std::string CLASSNAME = "DelayedNeutron";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto rate = [](auto &obj) { return &obj.rate; };
   static auto product = [](auto &obj) { return &obj.product; };
}

using CPPRate = fissionFragmentData::Rate;
using CPPProduct = common::Product;


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

// Create, default
Handle2DelayedNeutron
DelayedNeutronDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstDelayedNeutron
DelayedNeutronCreateConst(
   const XMLName label,
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

// Create, general
Handle2DelayedNeutron
DelayedNeutronCreate(
   const XMLName label,
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
DelayedNeutronAssign(ConstHandle2DelayedNeutron This, ConstHandle2ConstDelayedNeutron from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
DelayedNeutronDelete(ConstHandle2ConstDelayedNeutron This)
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
DelayedNeutronRead(ConstHandle2DelayedNeutron This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
DelayedNeutronWrite(ConstHandle2ConstDelayedNeutron This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
DelayedNeutronPrint(ConstHandle2ConstDelayedNeutron This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
DelayedNeutronPrintXML(ConstHandle2ConstDelayedNeutron This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
DelayedNeutronPrintJSON(ConstHandle2ConstDelayedNeutron This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
DelayedNeutronLabelHas(ConstHandle2ConstDelayedNeutron This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
DelayedNeutronLabelGet(ConstHandle2ConstDelayedNeutron This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
DelayedNeutronLabelSet(ConstHandle2DelayedNeutron This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Child: rate
// -----------------------------------------------------------------------------

// Has
int
DelayedNeutronRateHas(ConstHandle2ConstDelayedNeutron This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"RateHas", This, extract::rate);
}

// Get, const
Handle2ConstRate
DelayedNeutronRateGetConst(ConstHandle2ConstDelayedNeutron This)
{
   return detail::getField<CPP,Handle2ConstRate>
      (CLASSNAME, CLASSNAME+"RateGetConst", This, extract::rate);
}

// Get, non-const
Handle2Rate
DelayedNeutronRateGet(ConstHandle2DelayedNeutron This)
{
   return detail::getField<CPP,Handle2Rate>
      (CLASSNAME, CLASSNAME+"RateGet", This, extract::rate);
}

// Set
void
DelayedNeutronRateSet(ConstHandle2DelayedNeutron This, ConstHandle2ConstRate rate)
{
   detail::setField<CPP,CPPRate>
      (CLASSNAME, CLASSNAME+"RateSet", This, extract::rate, rate);
}


// -----------------------------------------------------------------------------
// Child: product
// -----------------------------------------------------------------------------

// Has
int
DelayedNeutronProductHas(ConstHandle2ConstDelayedNeutron This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ProductHas", This, extract::product);
}

// Get, const
Handle2ConstProduct
DelayedNeutronProductGetConst(ConstHandle2ConstDelayedNeutron This)
{
   return detail::getField<CPP,Handle2ConstProduct>
      (CLASSNAME, CLASSNAME+"ProductGetConst", This, extract::product);
}

// Get, non-const
Handle2Product
DelayedNeutronProductGet(ConstHandle2DelayedNeutron This)
{
   return detail::getField<CPP,Handle2Product>
      (CLASSNAME, CLASSNAME+"ProductGet", This, extract::product);
}

// Set
void
DelayedNeutronProductSet(ConstHandle2DelayedNeutron This, ConstHandle2ConstProduct product)
{
   detail::setField<CPP,CPPProduct>
      (CLASSNAME, CLASSNAME+"ProductSet", This, extract::product, product);
}
