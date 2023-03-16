
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/CovarianceSections.hpp"
#include "CovarianceSections.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = CovarianceSectionsClass;
using CPP = multigroup::CovarianceSections;

static const std::string CLASSNAME = "CovarianceSections";

namespace extract {
   static auto covarianceSection = [](auto &obj) { return &obj.covarianceSection; };
}

using CPPCovarianceSection = general::CovarianceSection;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstCovarianceSections
CovarianceSectionsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2CovarianceSections
CovarianceSectionsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstCovarianceSections
CovarianceSectionsCreateConst(
   ConstHandle2CovarianceSection *const covarianceSection, const size_t covarianceSectionSize
) {
   ConstHandle2CovarianceSections handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPCovarianceSection>{}
   );
   for (size_t CovarianceSectionN = 0; CovarianceSectionN < covarianceSectionSize; ++CovarianceSectionN)
      CovarianceSectionsCovarianceSectionAdd(handle, covarianceSection[CovarianceSectionN]);
   return handle;
}

// Create, general
Handle2CovarianceSections
CovarianceSectionsCreate(
   ConstHandle2CovarianceSection *const covarianceSection, const size_t covarianceSectionSize
) {
   ConstHandle2CovarianceSections handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPCovarianceSection>{}
   );
   for (size_t CovarianceSectionN = 0; CovarianceSectionN < covarianceSectionSize; ++CovarianceSectionN)
      CovarianceSectionsCovarianceSectionAdd(handle, covarianceSection[CovarianceSectionN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
CovarianceSectionsAssign(ConstHandle2CovarianceSections self, ConstHandle2ConstCovarianceSections from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
CovarianceSectionsDelete(ConstHandle2ConstCovarianceSections self)
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
CovarianceSectionsRead(ConstHandle2CovarianceSections self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
CovarianceSectionsWrite(ConstHandle2ConstCovarianceSections self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
CovarianceSectionsPrint(ConstHandle2ConstCovarianceSections self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
CovarianceSectionsPrintXML(ConstHandle2ConstCovarianceSections self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
CovarianceSectionsPrintJSON(ConstHandle2ConstCovarianceSections self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: covarianceSection
// -----------------------------------------------------------------------------

// Has
int
CovarianceSectionsCovarianceSectionHas(ConstHandle2ConstCovarianceSections self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CovarianceSectionHas", self, extract::covarianceSection);
}

// Clear
void
CovarianceSectionsCovarianceSectionClear(ConstHandle2CovarianceSections self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"CovarianceSectionClear", self, extract::covarianceSection);
}

// Size
size_t
CovarianceSectionsCovarianceSectionSize(ConstHandle2ConstCovarianceSections self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"CovarianceSectionSize", self, extract::covarianceSection);
}

// Add
void
CovarianceSectionsCovarianceSectionAdd(ConstHandle2CovarianceSections self, ConstHandle2ConstCovarianceSection covarianceSection)
{
   detail::addToContainer<CPP,CPPCovarianceSection>
      (CLASSNAME, CLASSNAME+"CovarianceSectionAdd", self, extract::covarianceSection, covarianceSection);
}

// Get, by index \in [0,size), const
Handle2ConstCovarianceSection
CovarianceSectionsCovarianceSectionGetConst(ConstHandle2ConstCovarianceSections self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstCovarianceSection>
      (CLASSNAME, CLASSNAME+"CovarianceSectionGetConst", self, extract::covarianceSection, index_);
}

// Get, by index \in [0,size), non-const
Handle2CovarianceSection
CovarianceSectionsCovarianceSectionGet(ConstHandle2CovarianceSections self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2CovarianceSection>
      (CLASSNAME, CLASSNAME+"CovarianceSectionGet", self, extract::covarianceSection, index_);
}

// Set, by index \in [0,size)
void
CovarianceSectionsCovarianceSectionSet(
   ConstHandle2CovarianceSections self,
   const size_t index_,
   ConstHandle2ConstCovarianceSection covarianceSection
) {
   detail::setByIndex<CPP,CPPCovarianceSection>
      (CLASSNAME, CLASSNAME+"CovarianceSectionSet", self, extract::covarianceSection, index_, covarianceSection);
}

// Has, by label
int
CovarianceSectionsCovarianceSectionHasByLabel(
   ConstHandle2ConstCovarianceSections self,
   const char *const label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"CovarianceSectionHasByLabel",
       self, extract::covarianceSection, meta::label, label);
}

// Get, by label, const
Handle2ConstCovarianceSection
CovarianceSectionsCovarianceSectionGetByLabelConst(
   ConstHandle2ConstCovarianceSections self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2ConstCovarianceSection>
      (CLASSNAME, CLASSNAME+"CovarianceSectionGetByLabelConst",
       self, extract::covarianceSection, meta::label, label);
}

// Get, by label, non-const
Handle2CovarianceSection
CovarianceSectionsCovarianceSectionGetByLabel(
   ConstHandle2CovarianceSections self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2CovarianceSection>
      (CLASSNAME, CLASSNAME+"CovarianceSectionGetByLabel",
       self, extract::covarianceSection, meta::label, label);
}

// Set, by label
void
CovarianceSectionsCovarianceSectionSetByLabel(
   ConstHandle2CovarianceSections self,
   const char *const label,
   ConstHandle2ConstCovarianceSection covarianceSection
) {
   detail::setByMetadatum<CPP,CPPCovarianceSection>
      (CLASSNAME, CLASSNAME+"CovarianceSectionSetByLabel",
       self, extract::covarianceSection, meta::label, label, covarianceSection);
}

// Has, by crossTerm
int
CovarianceSectionsCovarianceSectionHasByCrossTerm(
   ConstHandle2ConstCovarianceSections self,
   const bool crossTerm
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"CovarianceSectionHasByCrossTerm",
       self, extract::covarianceSection, meta::crossTerm, crossTerm);
}

// Get, by crossTerm, const
Handle2ConstCovarianceSection
CovarianceSectionsCovarianceSectionGetByCrossTermConst(
   ConstHandle2ConstCovarianceSections self,
   const bool crossTerm
) {
   return detail::getByMetadatum<CPP,Handle2ConstCovarianceSection>
      (CLASSNAME, CLASSNAME+"CovarianceSectionGetByCrossTermConst",
       self, extract::covarianceSection, meta::crossTerm, crossTerm);
}

// Get, by crossTerm, non-const
Handle2CovarianceSection
CovarianceSectionsCovarianceSectionGetByCrossTerm(
   ConstHandle2CovarianceSections self,
   const bool crossTerm
) {
   return detail::getByMetadatum<CPP,Handle2CovarianceSection>
      (CLASSNAME, CLASSNAME+"CovarianceSectionGetByCrossTerm",
       self, extract::covarianceSection, meta::crossTerm, crossTerm);
}

// Set, by crossTerm
void
CovarianceSectionsCovarianceSectionSetByCrossTerm(
   ConstHandle2CovarianceSections self,
   const bool crossTerm,
   ConstHandle2ConstCovarianceSection covarianceSection
) {
   detail::setByMetadatum<CPP,CPPCovarianceSection>
      (CLASSNAME, CLASSNAME+"CovarianceSectionSetByCrossTerm",
       self, extract::covarianceSection, meta::crossTerm, crossTerm, covarianceSection);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/CovarianceSections/src/custom.cpp"
