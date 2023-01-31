
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/mean/Productions.hpp"
#include "Productions.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = ProductionsClass;
using CPP = multigroup::Productions;

static const std::string CLASSNAME = "Productions";

namespace extract {
   static auto production = [](auto &obj) { return &obj.production; };
}

using CPPProduction = mean::Production;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstProductions
ProductionsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Productions
ProductionsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstProductions
ProductionsCreateConst(
   ConstHandle2Production *const production, const size_t productionSize
) {
   ConstHandle2Productions handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPProduction>{}
   );
   for (size_t ProductionN = 0; ProductionN < productionSize; ++ProductionN)
      ProductionsProductionAdd(handle, production[ProductionN]);
   return handle;
}

// Create, general
Handle2Productions
ProductionsCreate(
   ConstHandle2Production *const production, const size_t productionSize
) {
   ConstHandle2Productions handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPProduction>{}
   );
   for (size_t ProductionN = 0; ProductionN < productionSize; ++ProductionN)
      ProductionsProductionAdd(handle, production[ProductionN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ProductionsAssign(ConstHandle2Productions This, ConstHandle2ConstProductions from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ProductionsDelete(ConstHandle2ConstProductions This)
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
ProductionsRead(ConstHandle2Productions This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ProductionsWrite(ConstHandle2ConstProductions This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
ProductionsPrint(ConstHandle2ConstProductions This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
ProductionsPrintXML(ConstHandle2ConstProductions This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
ProductionsPrintJSON(ConstHandle2ConstProductions This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: production
// -----------------------------------------------------------------------------

// Has
int
ProductionsProductionHas(ConstHandle2ConstProductions This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ProductionHas", This, extract::production);
}

// Clear
void
ProductionsProductionClear(ConstHandle2Productions This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"ProductionClear", This, extract::production);
}

// Size
size_t
ProductionsProductionSize(ConstHandle2ConstProductions This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"ProductionSize", This, extract::production);
}

// Add
void
ProductionsProductionAdd(ConstHandle2Productions This, ConstHandle2ConstProduction production)
{
   detail::addToContainer<CPP,CPPProduction>
      (CLASSNAME, CLASSNAME+"ProductionAdd", This, extract::production, production);
}

// Get, by index \in [0,size), const
Handle2ConstProduction
ProductionsProductionGetConst(ConstHandle2ConstProductions This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstProduction>
      (CLASSNAME, CLASSNAME+"ProductionGetConst", This, extract::production, index_);
}

// Get, by index \in [0,size), non-const
Handle2Production
ProductionsProductionGet(ConstHandle2Productions This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Production>
      (CLASSNAME, CLASSNAME+"ProductionGet", This, extract::production, index_);
}

// Set, by index \in [0,size)
void
ProductionsProductionSet(
   ConstHandle2Productions This,
   const size_t index_,
   ConstHandle2ConstProduction production
) {
   detail::setByIndex<CPP,CPPProduction>
      (CLASSNAME, CLASSNAME+"ProductionSet", This, extract::production, index_, production);
}

// Has, by label
int
ProductionsProductionHasByLabel(
   ConstHandle2ConstProductions This,
   const char *const label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ProductionHasByLabel",
       This, extract::production, meta::label, label);
}

// Get, by label, const
Handle2ConstProduction
ProductionsProductionGetByLabelConst(
   ConstHandle2ConstProductions This,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2ConstProduction>
      (CLASSNAME, CLASSNAME+"ProductionGetByLabelConst",
       This, extract::production, meta::label, label);
}

// Get, by label, non-const
Handle2Production
ProductionsProductionGetByLabel(
   ConstHandle2Productions This,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2Production>
      (CLASSNAME, CLASSNAME+"ProductionGetByLabel",
       This, extract::production, meta::label, label);
}

// Set, by label
void
ProductionsProductionSetByLabel(
   ConstHandle2Productions This,
   const char *const label,
   ConstHandle2ConstProduction production
) {
   detail::setByMetadatum<CPP,CPPProduction>
      (CLASSNAME, CLASSNAME+"ProductionSetByLabel",
       This, extract::production, meta::label, label, production);
}

// Has, by ENDF_MT
int
ProductionsProductionHasByENDFMT(
   ConstHandle2ConstProductions This,
   const int ENDF_MT
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ProductionHasByENDFMT",
       This, extract::production, meta::ENDF_MT, ENDF_MT);
}

// Get, by ENDF_MT, const
Handle2ConstProduction
ProductionsProductionGetByENDFMTConst(
   ConstHandle2ConstProductions This,
   const int ENDF_MT
) {
   return detail::getByMetadatum<CPP,Handle2ConstProduction>
      (CLASSNAME, CLASSNAME+"ProductionGetByENDFMTConst",
       This, extract::production, meta::ENDF_MT, ENDF_MT);
}

// Get, by ENDF_MT, non-const
Handle2Production
ProductionsProductionGetByENDFMT(
   ConstHandle2Productions This,
   const int ENDF_MT
) {
   return detail::getByMetadatum<CPP,Handle2Production>
      (CLASSNAME, CLASSNAME+"ProductionGetByENDFMT",
       This, extract::production, meta::ENDF_MT, ENDF_MT);
}

// Set, by ENDF_MT
void
ProductionsProductionSetByENDFMT(
   ConstHandle2Productions This,
   const int ENDF_MT,
   ConstHandle2ConstProduction production
) {
   detail::setByMetadatum<CPP,CPPProduction>
      (CLASSNAME, CLASSNAME+"ProductionSetByENDFMT",
       This, extract::production, meta::ENDF_MT, ENDF_MT, production);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/mean/Productions/src/custom.cpp"
