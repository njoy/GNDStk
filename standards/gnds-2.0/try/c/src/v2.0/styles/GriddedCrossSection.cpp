
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/styles/GriddedCrossSection.hpp"
#include "GriddedCrossSection.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = GriddedCrossSectionClass;
using CPP = multigroup::GriddedCrossSection;

static const std::string CLASSNAME = "GriddedCrossSection";

namespace extract {
   static auto date = [](auto &obj) { return &obj.date; };
   static auto derivedFrom = [](auto &obj) { return &obj.derivedFrom; };
   static auto label = [](auto &obj) { return &obj.label; };
   static auto grid = [](auto &obj) { return &obj.grid; };
   static auto documentation = [](auto &obj) { return &obj.documentation; };
}

using CPPGrid = unknownNamespace::Grid;
using CPPDocumentation = documentation::Documentation;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstGriddedCrossSection
GriddedCrossSectionDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2GriddedCrossSection
GriddedCrossSectionDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstGriddedCrossSection
GriddedCrossSectionCreateConst(
   const char *const date,
   const XMLName derivedFrom,
   const XMLName label,
   ConstHandle2ConstGrid grid,
   ConstHandle2ConstDocumentation documentation
) {
   ConstHandle2GriddedCrossSection handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      date,
      derivedFrom,
      label,
      detail::tocpp<CPPGrid>(grid),
      detail::tocpp<CPPDocumentation>(documentation)
   );
   return handle;
}

// Create, general
Handle2GriddedCrossSection
GriddedCrossSectionCreate(
   const char *const date,
   const XMLName derivedFrom,
   const XMLName label,
   ConstHandle2ConstGrid grid,
   ConstHandle2ConstDocumentation documentation
) {
   ConstHandle2GriddedCrossSection handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      date,
      derivedFrom,
      label,
      detail::tocpp<CPPGrid>(grid),
      detail::tocpp<CPPDocumentation>(documentation)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
GriddedCrossSectionAssign(ConstHandle2GriddedCrossSection This, ConstHandle2ConstGriddedCrossSection from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
GriddedCrossSectionDelete(ConstHandle2ConstGriddedCrossSection This)
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
GriddedCrossSectionRead(ConstHandle2GriddedCrossSection This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
GriddedCrossSectionWrite(ConstHandle2ConstGriddedCrossSection This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
GriddedCrossSectionPrint(ConstHandle2ConstGriddedCrossSection This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
GriddedCrossSectionPrintXML(ConstHandle2ConstGriddedCrossSection This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
GriddedCrossSectionPrintJSON(ConstHandle2ConstGriddedCrossSection This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: date
// -----------------------------------------------------------------------------

// Has
int
GriddedCrossSectionDateHas(ConstHandle2ConstGriddedCrossSection This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DateHas", This, extract::date);
}

// Get
// Returns by value
const char *
GriddedCrossSectionDateGet(ConstHandle2ConstGriddedCrossSection This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DateGet", This, extract::date);
}

// Set
void
GriddedCrossSectionDateSet(ConstHandle2GriddedCrossSection This, const char *const date)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DateSet", This, extract::date, date);
}


// -----------------------------------------------------------------------------
// Metadatum: derivedFrom
// -----------------------------------------------------------------------------

// Has
int
GriddedCrossSectionDerivedFromHas(ConstHandle2ConstGriddedCrossSection This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DerivedFromHas", This, extract::derivedFrom);
}

// Get
// Returns by value
XMLName
GriddedCrossSectionDerivedFromGet(ConstHandle2ConstGriddedCrossSection This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DerivedFromGet", This, extract::derivedFrom);
}

// Set
void
GriddedCrossSectionDerivedFromSet(ConstHandle2GriddedCrossSection This, const XMLName derivedFrom)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DerivedFromSet", This, extract::derivedFrom, derivedFrom);
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
GriddedCrossSectionLabelHas(ConstHandle2ConstGriddedCrossSection This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
GriddedCrossSectionLabelGet(ConstHandle2ConstGriddedCrossSection This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
GriddedCrossSectionLabelSet(ConstHandle2GriddedCrossSection This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Child: grid
// -----------------------------------------------------------------------------

// Has
int
GriddedCrossSectionGridHas(ConstHandle2ConstGriddedCrossSection This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"GridHas", This, extract::grid);
}

// Get, const
Handle2ConstGrid
GriddedCrossSectionGridGetConst(ConstHandle2ConstGriddedCrossSection This)
{
   return detail::getField<CPP,Handle2ConstGrid>
      (CLASSNAME, CLASSNAME+"GridGetConst", This, extract::grid);
}

// Get, non-const
Handle2Grid
GriddedCrossSectionGridGet(ConstHandle2GriddedCrossSection This)
{
   return detail::getField<CPP,Handle2Grid>
      (CLASSNAME, CLASSNAME+"GridGet", This, extract::grid);
}

// Set
void
GriddedCrossSectionGridSet(ConstHandle2GriddedCrossSection This, ConstHandle2ConstGrid grid)
{
   detail::setField<CPP,CPPGrid>
      (CLASSNAME, CLASSNAME+"GridSet", This, extract::grid, grid);
}


// -----------------------------------------------------------------------------
// Child: documentation
// -----------------------------------------------------------------------------

// Has
int
GriddedCrossSectionDocumentationHas(ConstHandle2ConstGriddedCrossSection This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DocumentationHas", This, extract::documentation);
}

// Get, const
Handle2ConstDocumentation
GriddedCrossSectionDocumentationGetConst(ConstHandle2ConstGriddedCrossSection This)
{
   return detail::getField<CPP,Handle2ConstDocumentation>
      (CLASSNAME, CLASSNAME+"DocumentationGetConst", This, extract::documentation);
}

// Get, non-const
Handle2Documentation
GriddedCrossSectionDocumentationGet(ConstHandle2GriddedCrossSection This)
{
   return detail::getField<CPP,Handle2Documentation>
      (CLASSNAME, CLASSNAME+"DocumentationGet", This, extract::documentation);
}

// Set
void
GriddedCrossSectionDocumentationSet(ConstHandle2GriddedCrossSection This, ConstHandle2ConstDocumentation documentation)
{
   detail::setField<CPP,CPPDocumentation>
      (CLASSNAME, CLASSNAME+"DocumentationSet", This, extract::documentation, documentation);
}
