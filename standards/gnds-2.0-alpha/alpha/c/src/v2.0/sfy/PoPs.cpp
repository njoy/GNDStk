
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/sfy/PoPs.hpp"
#include "PoPs.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = PoPsClass;
using CPP = multigroup::PoPs;

static const std::string CLASSNAME = "PoPs";

namespace extract {
   static auto name = [](auto &obj) { return &obj.name; };
   static auto version = [](auto &obj) { return &obj.version; };
   static auto format = [](auto &obj) { return &obj.format; };
   static auto styles = [](auto &obj) { return &obj.styles; };
   static auto chemicalElements = [](auto &obj) { return &obj.chemicalElements; };
   static auto aliases = [](auto &obj) { return &obj.aliases; };
   static auto baryons = [](auto &obj) { return &obj.baryons; };
}

using CPPStyles = common::Styles;
using CPPChemicalElements = common::ChemicalElements;
using CPPAliases = common::Aliases;
using CPPBaryons = common::Baryons;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstPoPs
PoPsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2PoPs
PoPsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstPoPs
PoPsCreateConst(
   const char *const name,
   const char *const version,
   const char *const format,
   ConstHandle2ConstStyles styles,
   ConstHandle2ConstChemicalElements chemicalElements,
   ConstHandle2ConstAliases aliases,
   ConstHandle2ConstBaryons baryons
) {
   ConstHandle2PoPs handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      name,
      version,
      format,
      detail::tocpp<CPPStyles>(styles),
      detail::tocpp<CPPChemicalElements>(chemicalElements),
      detail::tocpp<CPPAliases>(aliases),
      detail::tocpp<CPPBaryons>(baryons)
   );
   return handle;
}

// Create, general
Handle2PoPs
PoPsCreate(
   const char *const name,
   const char *const version,
   const char *const format,
   ConstHandle2ConstStyles styles,
   ConstHandle2ConstChemicalElements chemicalElements,
   ConstHandle2ConstAliases aliases,
   ConstHandle2ConstBaryons baryons
) {
   ConstHandle2PoPs handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      name,
      version,
      format,
      detail::tocpp<CPPStyles>(styles),
      detail::tocpp<CPPChemicalElements>(chemicalElements),
      detail::tocpp<CPPAliases>(aliases),
      detail::tocpp<CPPBaryons>(baryons)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
PoPsAssign(ConstHandle2PoPs This, ConstHandle2ConstPoPs from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
PoPsDelete(ConstHandle2ConstPoPs This)
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
PoPsRead(ConstHandle2PoPs This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
PoPsWrite(ConstHandle2ConstPoPs This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
PoPsPrint(ConstHandle2ConstPoPs This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
PoPsPrintXML(ConstHandle2ConstPoPs This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
PoPsPrintJSON(ConstHandle2ConstPoPs This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: name
// -----------------------------------------------------------------------------

// Has
int
PoPsNameHas(ConstHandle2ConstPoPs This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"NameHas", This, extract::name);
}

// Get
// Returns by value
const char *
PoPsNameGet(ConstHandle2ConstPoPs This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"NameGet", This, extract::name);
}

// Set
void
PoPsNameSet(ConstHandle2PoPs This, const char *const name)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"NameSet", This, extract::name, name);
}


// -----------------------------------------------------------------------------
// Metadatum: version
// -----------------------------------------------------------------------------

// Has
int
PoPsVersionHas(ConstHandle2ConstPoPs This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"VersionHas", This, extract::version);
}

// Get
// Returns by value
const char *
PoPsVersionGet(ConstHandle2ConstPoPs This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"VersionGet", This, extract::version);
}

// Set
void
PoPsVersionSet(ConstHandle2PoPs This, const char *const version)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"VersionSet", This, extract::version, version);
}


// -----------------------------------------------------------------------------
// Metadatum: format
// -----------------------------------------------------------------------------

// Has
int
PoPsFormatHas(ConstHandle2ConstPoPs This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"FormatHas", This, extract::format);
}

// Get
// Returns by value
const char *
PoPsFormatGet(ConstHandle2ConstPoPs This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"FormatGet", This, extract::format);
}

// Set
void
PoPsFormatSet(ConstHandle2PoPs This, const char *const format)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"FormatSet", This, extract::format, format);
}


// -----------------------------------------------------------------------------
// Child: styles
// -----------------------------------------------------------------------------

// Has
int
PoPsStylesHas(ConstHandle2ConstPoPs This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"StylesHas", This, extract::styles);
}

// Get, const
Handle2ConstStyles
PoPsStylesGetConst(ConstHandle2ConstPoPs This)
{
   return detail::getField<CPP,Handle2ConstStyles>
      (CLASSNAME, CLASSNAME+"StylesGetConst", This, extract::styles);
}

// Get, non-const
Handle2Styles
PoPsStylesGet(ConstHandle2PoPs This)
{
   return detail::getField<CPP,Handle2Styles>
      (CLASSNAME, CLASSNAME+"StylesGet", This, extract::styles);
}

// Set
void
PoPsStylesSet(ConstHandle2PoPs This, ConstHandle2ConstStyles styles)
{
   detail::setField<CPP,CPPStyles>
      (CLASSNAME, CLASSNAME+"StylesSet", This, extract::styles, styles);
}


// -----------------------------------------------------------------------------
// Child: chemicalElements
// -----------------------------------------------------------------------------

// Has
int
PoPsChemicalElementsHas(ConstHandle2ConstPoPs This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ChemicalElementsHas", This, extract::chemicalElements);
}

// Get, const
Handle2ConstChemicalElements
PoPsChemicalElementsGetConst(ConstHandle2ConstPoPs This)
{
   return detail::getField<CPP,Handle2ConstChemicalElements>
      (CLASSNAME, CLASSNAME+"ChemicalElementsGetConst", This, extract::chemicalElements);
}

// Get, non-const
Handle2ChemicalElements
PoPsChemicalElementsGet(ConstHandle2PoPs This)
{
   return detail::getField<CPP,Handle2ChemicalElements>
      (CLASSNAME, CLASSNAME+"ChemicalElementsGet", This, extract::chemicalElements);
}

// Set
void
PoPsChemicalElementsSet(ConstHandle2PoPs This, ConstHandle2ConstChemicalElements chemicalElements)
{
   detail::setField<CPP,CPPChemicalElements>
      (CLASSNAME, CLASSNAME+"ChemicalElementsSet", This, extract::chemicalElements, chemicalElements);
}


// -----------------------------------------------------------------------------
// Child: aliases
// -----------------------------------------------------------------------------

// Has
int
PoPsAliasesHas(ConstHandle2ConstPoPs This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AliasesHas", This, extract::aliases);
}

// Get, const
Handle2ConstAliases
PoPsAliasesGetConst(ConstHandle2ConstPoPs This)
{
   return detail::getField<CPP,Handle2ConstAliases>
      (CLASSNAME, CLASSNAME+"AliasesGetConst", This, extract::aliases);
}

// Get, non-const
Handle2Aliases
PoPsAliasesGet(ConstHandle2PoPs This)
{
   return detail::getField<CPP,Handle2Aliases>
      (CLASSNAME, CLASSNAME+"AliasesGet", This, extract::aliases);
}

// Set
void
PoPsAliasesSet(ConstHandle2PoPs This, ConstHandle2ConstAliases aliases)
{
   detail::setField<CPP,CPPAliases>
      (CLASSNAME, CLASSNAME+"AliasesSet", This, extract::aliases, aliases);
}


// -----------------------------------------------------------------------------
// Child: baryons
// -----------------------------------------------------------------------------

// Has
int
PoPsBaryonsHas(ConstHandle2ConstPoPs This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"BaryonsHas", This, extract::baryons);
}

// Get, const
Handle2ConstBaryons
PoPsBaryonsGetConst(ConstHandle2ConstPoPs This)
{
   return detail::getField<CPP,Handle2ConstBaryons>
      (CLASSNAME, CLASSNAME+"BaryonsGetConst", This, extract::baryons);
}

// Get, non-const
Handle2Baryons
PoPsBaryonsGet(ConstHandle2PoPs This)
{
   return detail::getField<CPP,Handle2Baryons>
      (CLASSNAME, CLASSNAME+"BaryonsGet", This, extract::baryons);
}

// Set
void
PoPsBaryonsSet(ConstHandle2PoPs This, ConstHandle2ConstBaryons baryons)
{
   detail::setField<CPP,CPPBaryons>
      (CLASSNAME, CLASSNAME+"BaryonsSet", This, extract::baryons, baryons);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/sfy/PoPs/src/custom.cpp"
