
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2.0/general/RowData.hpp"
#include "RowData.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = RowDataClass;
using CPP = multigroup::RowData;

static const std::string CLASSNAME = "RowData";

namespace extract {
   static auto ENDF_MFMT = [](auto &obj) { return &obj.ENDF_MFMT; };
   static auto dimension = [](auto &obj) { return &obj.dimension; };
   static auto href = [](auto &obj) { return &obj.href; };
   static auto slices = [](auto &obj) { return &obj.slices; };
}

using CPPSlices = general::Slices;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstRowData
RowDataDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2RowData
RowDataDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstRowData
RowDataCreateConst(
   const char *const ENDF_MFMT,
   const int dimension,
   const char *const href,
   ConstHandle2ConstSlices slices
) {
   ConstHandle2RowData handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      ENDF_MFMT,
      dimension,
      href,
      detail::tocpp<CPPSlices>(slices)
   );
   return handle;
}

// Create, general
Handle2RowData
RowDataCreate(
   const char *const ENDF_MFMT,
   const int dimension,
   const char *const href,
   ConstHandle2ConstSlices slices
) {
   ConstHandle2RowData handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      ENDF_MFMT,
      dimension,
      href,
      detail::tocpp<CPPSlices>(slices)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
RowDataAssign(ConstHandle2RowData self, ConstHandle2ConstRowData from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
RowDataDelete(ConstHandle2ConstRowData self)
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
RowDataRead(ConstHandle2RowData self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
RowDataWrite(ConstHandle2ConstRowData self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
RowDataPrint(ConstHandle2ConstRowData self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
RowDataPrintXML(ConstHandle2ConstRowData self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
RowDataPrintJSON(ConstHandle2ConstRowData self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: ENDF_MFMT
// -----------------------------------------------------------------------------

// Has
int
RowDataENDFMFMTHas(ConstHandle2ConstRowData self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ENDFMFMTHas", self, extract::ENDF_MFMT);
}

// Get
// Returns by value
const char *
RowDataENDFMFMTGet(ConstHandle2ConstRowData self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ENDFMFMTGet", self, extract::ENDF_MFMT);
}

// Set
void
RowDataENDFMFMTSet(ConstHandle2RowData self, const char *const ENDF_MFMT)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ENDFMFMTSet", self, extract::ENDF_MFMT, ENDF_MFMT);
}


// -----------------------------------------------------------------------------
// Metadatum: dimension
// -----------------------------------------------------------------------------

// Has
int
RowDataDimensionHas(ConstHandle2ConstRowData self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DimensionHas", self, extract::dimension);
}

// Get
// Returns by value
int
RowDataDimensionGet(ConstHandle2ConstRowData self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DimensionGet", self, extract::dimension);
}

// Set
void
RowDataDimensionSet(ConstHandle2RowData self, const int dimension)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DimensionSet", self, extract::dimension, dimension);
}


// -----------------------------------------------------------------------------
// Metadatum: href
// -----------------------------------------------------------------------------

// Has
int
RowDataHrefHas(ConstHandle2ConstRowData self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"HrefHas", self, extract::href);
}

// Get
// Returns by value
const char *
RowDataHrefGet(ConstHandle2ConstRowData self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"HrefGet", self, extract::href);
}

// Set
void
RowDataHrefSet(ConstHandle2RowData self, const char *const href)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"HrefSet", self, extract::href, href);
}


// -----------------------------------------------------------------------------
// Child: slices
// -----------------------------------------------------------------------------

// Has
int
RowDataSlicesHas(ConstHandle2ConstRowData self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SlicesHas", self, extract::slices);
}

// Get, const
Handle2ConstSlices
RowDataSlicesGetConst(ConstHandle2ConstRowData self)
{
   return detail::getField<CPP,Handle2ConstSlices>
      (CLASSNAME, CLASSNAME+"SlicesGetConst", self, extract::slices);
}

// Get, non-const
Handle2Slices
RowDataSlicesGet(ConstHandle2RowData self)
{
   return detail::getField<CPP,Handle2Slices>
      (CLASSNAME, CLASSNAME+"SlicesGet", self, extract::slices);
}

// Set
void
RowDataSlicesSet(ConstHandle2RowData self, ConstHandle2ConstSlices slices)
{
   detail::setField<CPP,CPPSlices>
      (CLASSNAME, CLASSNAME+"SlicesSet", self, extract::slices, slices);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/RowData/src/custom.cpp"
