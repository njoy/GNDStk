
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/containers/Cdf_in_xs_pdf_cdf1d.hpp"
#include "Cdf_in_xs_pdf_cdf1d.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = Cdf_in_xs_pdf_cdf1dClass;
using CPP = multigroup::Cdf_in_xs_pdf_cdf1d;

static const std::string CLASSNAME = "Cdf_in_xs_pdf_cdf1d";

namespace extract {
   static auto values = [](auto &obj) { return &obj.values; };
}

using CPPValues = containers::Values;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstCdf_in_xs_pdf_cdf1d
Cdf_in_xs_pdf_cdf1dDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Cdf_in_xs_pdf_cdf1d
Cdf_in_xs_pdf_cdf1dDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstCdf_in_xs_pdf_cdf1d
Cdf_in_xs_pdf_cdf1dCreateConst(
   ConstHandle2ConstValues values
) {
   ConstHandle2Cdf_in_xs_pdf_cdf1d handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPValues>(values)
   );
   return handle;
}

// Create, general
Handle2Cdf_in_xs_pdf_cdf1d
Cdf_in_xs_pdf_cdf1dCreate(
   ConstHandle2ConstValues values
) {
   ConstHandle2Cdf_in_xs_pdf_cdf1d handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPValues>(values)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
Cdf_in_xs_pdf_cdf1dAssign(ConstHandle2Cdf_in_xs_pdf_cdf1d This, ConstHandle2ConstCdf_in_xs_pdf_cdf1d from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
Cdf_in_xs_pdf_cdf1dDelete(ConstHandle2ConstCdf_in_xs_pdf_cdf1d This)
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
Cdf_in_xs_pdf_cdf1dRead(ConstHandle2Cdf_in_xs_pdf_cdf1d This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
Cdf_in_xs_pdf_cdf1dWrite(ConstHandle2ConstCdf_in_xs_pdf_cdf1d This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
Cdf_in_xs_pdf_cdf1dPrint(ConstHandle2ConstCdf_in_xs_pdf_cdf1d This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
Cdf_in_xs_pdf_cdf1dPrintXML(ConstHandle2ConstCdf_in_xs_pdf_cdf1d This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
Cdf_in_xs_pdf_cdf1dPrintJSON(ConstHandle2ConstCdf_in_xs_pdf_cdf1d This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: values
// -----------------------------------------------------------------------------

// Has
int
Cdf_in_xs_pdf_cdf1dValuesHas(ConstHandle2ConstCdf_in_xs_pdf_cdf1d This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ValuesHas", This, extract::values);
}

// Get, const
Handle2ConstValues
Cdf_in_xs_pdf_cdf1dValuesGetConst(ConstHandle2ConstCdf_in_xs_pdf_cdf1d This)
{
   return detail::getField<CPP,Handle2ConstValues>
      (CLASSNAME, CLASSNAME+"ValuesGetConst", This, extract::values);
}

// Get, non-const
Handle2Values
Cdf_in_xs_pdf_cdf1dValuesGet(ConstHandle2Cdf_in_xs_pdf_cdf1d This)
{
   return detail::getField<CPP,Handle2Values>
      (CLASSNAME, CLASSNAME+"ValuesGet", This, extract::values);
}

// Set
void
Cdf_in_xs_pdf_cdf1dValuesSet(ConstHandle2Cdf_in_xs_pdf_cdf1d This, ConstHandle2ConstValues values)
{
   detail::setField<CPP,CPPValues>
      (CLASSNAME, CLASSNAME+"ValuesSet", This, extract::values, values);
}