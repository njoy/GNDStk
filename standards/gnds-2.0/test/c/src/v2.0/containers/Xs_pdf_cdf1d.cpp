
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/containers/Xs_pdf_cdf1d.hpp"
#include "Xs_pdf_cdf1d.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = Xs_pdf_cdf1dClass;
using CPP = multigroup::Xs_pdf_cdf1d;

static const std::string CLASSNAME = "Xs_pdf_cdf1d";

namespace extract {
   static auto outerDomainValue = [](auto &obj) { return &obj.outerDomainValue; };
   static auto xs = [](auto &obj) { return &obj.xs; };
   static auto pdf = [](auto &obj) { return &obj.pdf; };
   static auto cdf = [](auto &obj) { return &obj.cdf; };
}

using CPPXs_in_xs_pdf_cdf1d = containers::Xs_in_xs_pdf_cdf1d;
using CPPPdf = containers::Pdf;
using CPPCdf_in_xs_pdf_cdf1d = containers::Cdf_in_xs_pdf_cdf1d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstXs_pdf_cdf1d
Xs_pdf_cdf1dDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Xs_pdf_cdf1d
Xs_pdf_cdf1dDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstXs_pdf_cdf1d
Xs_pdf_cdf1dCreateConst(
   const Float64 outerDomainValue,
   ConstHandle2ConstXs_in_xs_pdf_cdf1d xs,
   ConstHandle2ConstPdf pdf,
   ConstHandle2ConstCdf_in_xs_pdf_cdf1d cdf
) {
   ConstHandle2Xs_pdf_cdf1d handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      outerDomainValue,
      detail::tocpp<CPPXs_in_xs_pdf_cdf1d>(xs),
      detail::tocpp<CPPPdf>(pdf),
      detail::tocpp<CPPCdf_in_xs_pdf_cdf1d>(cdf)
   );
   return handle;
}

// Create, general
Handle2Xs_pdf_cdf1d
Xs_pdf_cdf1dCreate(
   const Float64 outerDomainValue,
   ConstHandle2ConstXs_in_xs_pdf_cdf1d xs,
   ConstHandle2ConstPdf pdf,
   ConstHandle2ConstCdf_in_xs_pdf_cdf1d cdf
) {
   ConstHandle2Xs_pdf_cdf1d handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      outerDomainValue,
      detail::tocpp<CPPXs_in_xs_pdf_cdf1d>(xs),
      detail::tocpp<CPPPdf>(pdf),
      detail::tocpp<CPPCdf_in_xs_pdf_cdf1d>(cdf)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
Xs_pdf_cdf1dAssign(ConstHandle2Xs_pdf_cdf1d This, ConstHandle2ConstXs_pdf_cdf1d from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
Xs_pdf_cdf1dDelete(ConstHandle2ConstXs_pdf_cdf1d This)
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
Xs_pdf_cdf1dRead(ConstHandle2Xs_pdf_cdf1d This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
Xs_pdf_cdf1dWrite(ConstHandle2ConstXs_pdf_cdf1d This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
Xs_pdf_cdf1dPrint(ConstHandle2ConstXs_pdf_cdf1d This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
Xs_pdf_cdf1dPrintXML(ConstHandle2ConstXs_pdf_cdf1d This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
Xs_pdf_cdf1dPrintJSON(ConstHandle2ConstXs_pdf_cdf1d This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: outerDomainValue
// -----------------------------------------------------------------------------

// Has
int
Xs_pdf_cdf1dOuterDomainValueHas(ConstHandle2ConstXs_pdf_cdf1d This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"OuterDomainValueHas", This, extract::outerDomainValue);
}

// Get
// Returns by value
Float64
Xs_pdf_cdf1dOuterDomainValueGet(ConstHandle2ConstXs_pdf_cdf1d This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"OuterDomainValueGet", This, extract::outerDomainValue);
}

// Set
void
Xs_pdf_cdf1dOuterDomainValueSet(ConstHandle2Xs_pdf_cdf1d This, const Float64 outerDomainValue)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"OuterDomainValueSet", This, extract::outerDomainValue, outerDomainValue);
}


// -----------------------------------------------------------------------------
// Child: xs
// -----------------------------------------------------------------------------

// Has
int
Xs_pdf_cdf1dXs_in_xs_pdf_cdf1dHas(ConstHandle2ConstXs_pdf_cdf1d This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Xs_in_xs_pdf_cdf1dHas", This, extract::xs);
}

// Get, const
Handle2ConstXs_in_xs_pdf_cdf1d
Xs_pdf_cdf1dXs_in_xs_pdf_cdf1dGetConst(ConstHandle2ConstXs_pdf_cdf1d This)
{
   return detail::getField<CPP,Handle2ConstXs_in_xs_pdf_cdf1d>
      (CLASSNAME, CLASSNAME+"Xs_in_xs_pdf_cdf1dGetConst", This, extract::xs);
}

// Get, non-const
Handle2Xs_in_xs_pdf_cdf1d
Xs_pdf_cdf1dXs_in_xs_pdf_cdf1dGet(ConstHandle2Xs_pdf_cdf1d This)
{
   return detail::getField<CPP,Handle2Xs_in_xs_pdf_cdf1d>
      (CLASSNAME, CLASSNAME+"Xs_in_xs_pdf_cdf1dGet", This, extract::xs);
}

// Set
void
Xs_pdf_cdf1dXs_in_xs_pdf_cdf1dSet(ConstHandle2Xs_pdf_cdf1d This, ConstHandle2ConstXs_in_xs_pdf_cdf1d xs)
{
   detail::setField<CPP,CPPXs_in_xs_pdf_cdf1d>
      (CLASSNAME, CLASSNAME+"Xs_in_xs_pdf_cdf1dSet", This, extract::xs, xs);
}


// -----------------------------------------------------------------------------
// Child: pdf
// -----------------------------------------------------------------------------

// Has
int
Xs_pdf_cdf1dPdfHas(ConstHandle2ConstXs_pdf_cdf1d This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"PdfHas", This, extract::pdf);
}

// Get, const
Handle2ConstPdf
Xs_pdf_cdf1dPdfGetConst(ConstHandle2ConstXs_pdf_cdf1d This)
{
   return detail::getField<CPP,Handle2ConstPdf>
      (CLASSNAME, CLASSNAME+"PdfGetConst", This, extract::pdf);
}

// Get, non-const
Handle2Pdf
Xs_pdf_cdf1dPdfGet(ConstHandle2Xs_pdf_cdf1d This)
{
   return detail::getField<CPP,Handle2Pdf>
      (CLASSNAME, CLASSNAME+"PdfGet", This, extract::pdf);
}

// Set
void
Xs_pdf_cdf1dPdfSet(ConstHandle2Xs_pdf_cdf1d This, ConstHandle2ConstPdf pdf)
{
   detail::setField<CPP,CPPPdf>
      (CLASSNAME, CLASSNAME+"PdfSet", This, extract::pdf, pdf);
}


// -----------------------------------------------------------------------------
// Child: cdf
// -----------------------------------------------------------------------------

// Has
int
Xs_pdf_cdf1dCdf_in_xs_pdf_cdf1dHas(ConstHandle2ConstXs_pdf_cdf1d This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Cdf_in_xs_pdf_cdf1dHas", This, extract::cdf);
}

// Get, const
Handle2ConstCdf_in_xs_pdf_cdf1d
Xs_pdf_cdf1dCdf_in_xs_pdf_cdf1dGetConst(ConstHandle2ConstXs_pdf_cdf1d This)
{
   return detail::getField<CPP,Handle2ConstCdf_in_xs_pdf_cdf1d>
      (CLASSNAME, CLASSNAME+"Cdf_in_xs_pdf_cdf1dGetConst", This, extract::cdf);
}

// Get, non-const
Handle2Cdf_in_xs_pdf_cdf1d
Xs_pdf_cdf1dCdf_in_xs_pdf_cdf1dGet(ConstHandle2Xs_pdf_cdf1d This)
{
   return detail::getField<CPP,Handle2Cdf_in_xs_pdf_cdf1d>
      (CLASSNAME, CLASSNAME+"Cdf_in_xs_pdf_cdf1dGet", This, extract::cdf);
}

// Set
void
Xs_pdf_cdf1dCdf_in_xs_pdf_cdf1dSet(ConstHandle2Xs_pdf_cdf1d This, ConstHandle2ConstCdf_in_xs_pdf_cdf1d cdf)
{
   detail::setField<CPP,CPPCdf_in_xs_pdf_cdf1d>
      (CLASSNAME, CLASSNAME+"Cdf_in_xs_pdf_cdf1dSet", This, extract::cdf, cdf);
}
