
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/ENDFconversionFlags.hpp"
#include "ENDFconversionFlags.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = ENDFconversionFlagsClass;
using CPP = multigroup::ENDFconversionFlags;

static const std::string CLASSNAME = "ENDFconversionFlags";

namespace extract {
   static auto flags = [](auto &obj) { return &obj.flags; };
   static auto href = [](auto &obj) { return &obj.href; };
   static auto conversion = [](auto &obj) { return &obj.conversion; };
}

using CPPConversion = general::Conversion;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstENDFconversionFlags
ENDFconversionFlagsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2ENDFconversionFlags
ENDFconversionFlagsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstENDFconversionFlags
ENDFconversionFlagsCreateConst(
   const char *const flags,
   const char *const href,
   ConstHandle2Conversion *const conversion, const size_t conversionSize
) {
   ConstHandle2ENDFconversionFlags handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      flags,
      href,
      std::vector<CPPConversion>{}
   );
   for (size_t ConversionN = 0; ConversionN < conversionSize; ++ConversionN)
      ENDFconversionFlagsConversionAdd(handle, conversion[ConversionN]);
   return handle;
}

// Create, general
Handle2ENDFconversionFlags
ENDFconversionFlagsCreate(
   const char *const flags,
   const char *const href,
   ConstHandle2Conversion *const conversion, const size_t conversionSize
) {
   ConstHandle2ENDFconversionFlags handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      flags,
      href,
      std::vector<CPPConversion>{}
   );
   for (size_t ConversionN = 0; ConversionN < conversionSize; ++ConversionN)
      ENDFconversionFlagsConversionAdd(handle, conversion[ConversionN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ENDFconversionFlagsAssign(ConstHandle2ENDFconversionFlags self, ConstHandle2ConstENDFconversionFlags from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ENDFconversionFlagsDelete(ConstHandle2ConstENDFconversionFlags self)
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
ENDFconversionFlagsRead(ConstHandle2ENDFconversionFlags self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ENDFconversionFlagsWrite(ConstHandle2ConstENDFconversionFlags self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ENDFconversionFlagsPrint(ConstHandle2ConstENDFconversionFlags self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ENDFconversionFlagsPrintXML(ConstHandle2ConstENDFconversionFlags self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ENDFconversionFlagsPrintJSON(ConstHandle2ConstENDFconversionFlags self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: flags
// -----------------------------------------------------------------------------

// Has
int
ENDFconversionFlagsFlagsHas(ConstHandle2ConstENDFconversionFlags self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"FlagsHas", self, extract::flags);
}

// Get
// Returns by value
const char *
ENDFconversionFlagsFlagsGet(ConstHandle2ConstENDFconversionFlags self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"FlagsGet", self, extract::flags);
}

// Set
void
ENDFconversionFlagsFlagsSet(ConstHandle2ENDFconversionFlags self, const char *const flags)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"FlagsSet", self, extract::flags, flags);
}


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// Has
int
ENDFconversionFlagsHrefHas(ConstHandle2ConstENDFconversionFlags self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"HrefHas", self, extract::href);
}

// Get
// Returns by value
const char *
ENDFconversionFlagsHrefGet(ConstHandle2ConstENDFconversionFlags self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"HrefGet", self, extract::href);
}

// Set
void
ENDFconversionFlagsHrefSet(ConstHandle2ENDFconversionFlags self, const char *const href)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"HrefSet", self, extract::href, href);
}


// -----------------------------------------------------------------------------
// Child: conversion
// -----------------------------------------------------------------------------

// Has
int
ENDFconversionFlagsConversionHas(ConstHandle2ConstENDFconversionFlags self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ConversionHas", self, extract::conversion);
}

// Clear
void
ENDFconversionFlagsConversionClear(ConstHandle2ENDFconversionFlags self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"ConversionClear", self, extract::conversion);
}

// Size
size_t
ENDFconversionFlagsConversionSize(ConstHandle2ConstENDFconversionFlags self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"ConversionSize", self, extract::conversion);
}

// Add
void
ENDFconversionFlagsConversionAdd(ConstHandle2ENDFconversionFlags self, ConstHandle2ConstConversion conversion)
{
   detail::addToContainer<CPP,CPPConversion>
      (CLASSNAME, CLASSNAME+"ConversionAdd", self, extract::conversion, conversion);
}

// Get, by index \in [0,size), const
Handle2ConstConversion
ENDFconversionFlagsConversionGetConst(ConstHandle2ConstENDFconversionFlags self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstConversion>
      (CLASSNAME, CLASSNAME+"ConversionGetConst", self, extract::conversion, index_);
}

// Get, by index \in [0,size)
Handle2Conversion
ENDFconversionFlagsConversionGet(ConstHandle2ENDFconversionFlags self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Conversion>
      (CLASSNAME, CLASSNAME+"ConversionGet", self, extract::conversion, index_);
}

// Set, by index \in [0,size)
void
ENDFconversionFlagsConversionSet(
   ConstHandle2ENDFconversionFlags self,
   const size_t index_,
   ConstHandle2ConstConversion conversion
) {
   detail::setByIndex<CPP,CPPConversion>
      (CLASSNAME, CLASSNAME+"ConversionSet", self, extract::conversion, index_, conversion);
}

// ------------------------
// Re: metadatum flags
// ------------------------

// Has, by flags
int
ENDFconversionFlagsConversionHasByFlags(
   ConstHandle2ConstENDFconversionFlags self,
   const char *const flags
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ConversionHasByFlags",
       self, extract::conversion, meta::flags, flags);
}

// Get, by flags, const
Handle2ConstConversion
ENDFconversionFlagsConversionGetByFlagsConst(
   ConstHandle2ConstENDFconversionFlags self,
   const char *const flags
) {
   return detail::getByMetadatum<CPP,Handle2ConstConversion>
      (CLASSNAME, CLASSNAME+"ConversionGetByFlagsConst",
       self, extract::conversion, meta::flags, flags);
}

// Get, by flags
Handle2Conversion
ENDFconversionFlagsConversionGetByFlags(
   ConstHandle2ENDFconversionFlags self,
   const char *const flags
) {
   return detail::getByMetadatum<CPP,Handle2Conversion>
      (CLASSNAME, CLASSNAME+"ConversionGetByFlags",
       self, extract::conversion, meta::flags, flags);
}

// Set, by flags
void
ENDFconversionFlagsConversionSetByFlags(
   ConstHandle2ENDFconversionFlags self,
   const char *const flags,
   ConstHandle2ConstConversion conversion
) {
   detail::setByMetadatum<CPP,CPPConversion>
      (CLASSNAME, CLASSNAME+"ConversionSetByFlags",
       self, extract::conversion, meta::flags, flags, conversion);
}

// ------------------------
// Re: metadatum href
// ------------------------

// Has, by href
int
ENDFconversionFlagsConversionHasByHref(
   ConstHandle2ConstENDFconversionFlags self,
   const char *const href
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ConversionHasByHref",
       self, extract::conversion, meta::href, href);
}

// Get, by href, const
Handle2ConstConversion
ENDFconversionFlagsConversionGetByHrefConst(
   ConstHandle2ConstENDFconversionFlags self,
   const char *const href
) {
   return detail::getByMetadatum<CPP,Handle2ConstConversion>
      (CLASSNAME, CLASSNAME+"ConversionGetByHrefConst",
       self, extract::conversion, meta::href, href);
}

// Get, by href
Handle2Conversion
ENDFconversionFlagsConversionGetByHref(
   ConstHandle2ENDFconversionFlags self,
   const char *const href
) {
   return detail::getByMetadatum<CPP,Handle2Conversion>
      (CLASSNAME, CLASSNAME+"ConversionGetByHref",
       self, extract::conversion, meta::href, href);
}

// Set, by href
void
ENDFconversionFlagsConversionSetByHref(
   ConstHandle2ENDFconversionFlags self,
   const char *const href,
   ConstHandle2ConstConversion conversion
) {
   detail::setByMetadatum<CPP,CPPConversion>
      (CLASSNAME, CLASSNAME+"ConversionSetByHref",
       self, extract::conversion, meta::href, href, conversion);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/ENDFconversionFlags/src/custom.cpp"
