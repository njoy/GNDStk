
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2.0/general/ColumnData.hpp"
#include "ColumnData.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = ColumnDataClass;
using CPP = multigroup::ColumnData;

static const std::string CLASSNAME = "ColumnData";

namespace extract {
   static auto ENDF_MFMT = [](auto &obj) { return &obj.ENDF_MFMT; };
   static auto href = [](auto &obj) { return &obj.href; };
   static auto slices = [](auto &obj) { return &obj.slices; };
}

using CPPSlices = general::Slices;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstColumnData
ColumnDataDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2ColumnData
ColumnDataDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstColumnData
ColumnDataCreateConst(
   const char *const ENDF_MFMT,
   const char *const href,
   ConstHandle2ConstSlices slices
) {
   ConstHandle2ColumnData handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      ENDF_MFMT,
      href,
      detail::tocpp<CPPSlices>(slices)
   );
   return handle;
}

// Create, general
Handle2ColumnData
ColumnDataCreate(
   const char *const ENDF_MFMT,
   const char *const href,
   ConstHandle2ConstSlices slices
) {
   ConstHandle2ColumnData handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      ENDF_MFMT,
      href,
      detail::tocpp<CPPSlices>(slices)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ColumnDataAssign(ConstHandle2ColumnData self, ConstHandle2ConstColumnData from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ColumnDataDelete(ConstHandle2ConstColumnData self)
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
ColumnDataRead(ConstHandle2ColumnData self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ColumnDataWrite(ConstHandle2ConstColumnData self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ColumnDataPrint(ConstHandle2ConstColumnData self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ColumnDataPrintXML(ConstHandle2ConstColumnData self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ColumnDataPrintJSON(ConstHandle2ConstColumnData self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: ENDF_MFMT
// -----------------------------------------------------------------------------

// Has
int
ColumnDataENDFMFMTHas(ConstHandle2ConstColumnData self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ENDFMFMTHas", self, extract::ENDF_MFMT);
}

// Get
// Returns by value
const char *
ColumnDataENDFMFMTGet(ConstHandle2ConstColumnData self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ENDFMFMTGet", self, extract::ENDF_MFMT);
}

// Set
void
ColumnDataENDFMFMTSet(ConstHandle2ColumnData self, const char *const ENDF_MFMT)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ENDFMFMTSet", self, extract::ENDF_MFMT, ENDF_MFMT);
}


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// Has
int
ColumnDataHrefHas(ConstHandle2ConstColumnData self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"HrefHas", self, extract::href);
}

// Get
// Returns by value
const char *
ColumnDataHrefGet(ConstHandle2ConstColumnData self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"HrefGet", self, extract::href);
}

// Set
void
ColumnDataHrefSet(ConstHandle2ColumnData self, const char *const href)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"HrefSet", self, extract::href, href);
}


// -----------------------------------------------------------------------------
// Child: slices
// -----------------------------------------------------------------------------

// Has
int
ColumnDataSlicesHas(ConstHandle2ConstColumnData self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SlicesHas", self, extract::slices);
}

// Get, const
Handle2ConstSlices
ColumnDataSlicesGetConst(ConstHandle2ConstColumnData self)
{
   return detail::getField<CPP,Handle2ConstSlices>
      (CLASSNAME, CLASSNAME+"SlicesGetConst", self, extract::slices);
}

// Get, non-const
Handle2Slices
ColumnDataSlicesGet(ConstHandle2ColumnData self)
{
   return detail::getField<CPP,Handle2Slices>
      (CLASSNAME, CLASSNAME+"SlicesGet", self, extract::slices);
}

// Set
void
ColumnDataSlicesSet(ConstHandle2ColumnData self, ConstHandle2ConstSlices slices)
{
   detail::setField<CPP,CPPSlices>
      (CLASSNAME, CLASSNAME+"SlicesSet", self, extract::slices, slices);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/ColumnData/src/custom.cpp"
