
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/containers/Pdf.hpp"
#include "Pdf.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = PdfClass;
using CPP = multigroup::Pdf;

static const std::string CLASSNAME = "Pdf";

namespace extract {
   static auto XYs1d = [](auto &obj) { return &obj.XYs1d; };
   static auto regions1d = [](auto &obj) { return &obj.regions1d; };
}

using CPPXYs1d = containers::XYs1d;
using CPPRegions1d = containers::Regions1d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstPdf
PdfDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Pdf
PdfDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstPdf
PdfCreateConst(
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstRegions1d regions1d
) {
   ConstHandle2Pdf handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPXYs1d>(XYs1d),
      detail::tocpp<CPPRegions1d>(regions1d)
   );
   return handle;
}

// Create, general
Handle2Pdf
PdfCreate(
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstRegions1d regions1d
) {
   ConstHandle2Pdf handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPXYs1d>(XYs1d),
      detail::tocpp<CPPRegions1d>(regions1d)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
PdfAssign(ConstHandle2Pdf This, ConstHandle2ConstPdf from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
PdfDelete(ConstHandle2ConstPdf This)
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
PdfRead(ConstHandle2Pdf This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
PdfWrite(ConstHandle2ConstPdf This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
PdfPrint(ConstHandle2ConstPdf This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
PdfPrintXML(ConstHandle2ConstPdf This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
PdfPrintJSON(ConstHandle2ConstPdf This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// Has
int
PdfXYs1dHas(ConstHandle2ConstPdf This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"XYs1dHas", This, extract::XYs1d);
}

// Get, const
Handle2ConstXYs1d
PdfXYs1dGetConst(ConstHandle2ConstPdf This)
{
   return detail::getField<CPP,Handle2ConstXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGetConst", This, extract::XYs1d);
}

// Get, non-const
Handle2XYs1d
PdfXYs1dGet(ConstHandle2Pdf This)
{
   return detail::getField<CPP,Handle2XYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGet", This, extract::XYs1d);
}

// Set
void
PdfXYs1dSet(ConstHandle2Pdf This, ConstHandle2ConstXYs1d XYs1d)
{
   detail::setField<CPP,CPPXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dSet", This, extract::XYs1d, XYs1d);
}


// -----------------------------------------------------------------------------
// Child: regions1d
// -----------------------------------------------------------------------------

// Has
int
PdfRegions1dHas(ConstHandle2ConstPdf This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Regions1dHas", This, extract::regions1d);
}

// Get, const
Handle2ConstRegions1d
PdfRegions1dGetConst(ConstHandle2ConstPdf This)
{
   return detail::getField<CPP,Handle2ConstRegions1d>
      (CLASSNAME, CLASSNAME+"Regions1dGetConst", This, extract::regions1d);
}

// Get, non-const
Handle2Regions1d
PdfRegions1dGet(ConstHandle2Pdf This)
{
   return detail::getField<CPP,Handle2Regions1d>
      (CLASSNAME, CLASSNAME+"Regions1dGet", This, extract::regions1d);
}

// Set
void
PdfRegions1dSet(ConstHandle2Pdf This, ConstHandle2ConstRegions1d regions1d)
{
   detail::setField<CPP,CPPRegions1d>
      (CLASSNAME, CLASSNAME+"Regions1dSet", This, extract::regions1d, regions1d);
}