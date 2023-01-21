
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/documentation/Documentation.hpp"
#include "Documentation.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = DocumentationClass;
using CPP = multigroup::Documentation;

static const std::string CLASSNAME = "Documentation";

namespace extract {
   static auto doi = [](auto &obj) { return &obj.doi; };
   static auto publicationDate = [](auto &obj) { return &obj.publicationDate; };
   static auto version = [](auto &obj) { return &obj.version; };
   static auto authors = [](auto &obj) { return &obj.authors; };
   static auto contributors = [](auto &obj) { return &obj.contributors; };
   static auto collaborations = [](auto &obj) { return &obj.collaborations; };
   static auto dates = [](auto &obj) { return &obj.dates; };
   static auto copyright = [](auto &obj) { return &obj.copyright; };
   static auto acknowledgements = [](auto &obj) { return &obj.acknowledgements; };
   static auto keywords = [](auto &obj) { return &obj.keywords; };
   static auto relatedItems = [](auto &obj) { return &obj.relatedItems; };
   static auto title = [](auto &obj) { return &obj.title; };
   static auto abstract = [](auto &obj) { return &obj.abstract; };
   static auto body = [](auto &obj) { return &obj.body; };
   static auto computerCodes = [](auto &obj) { return &obj.computerCodes; };
   static auto experimentalDataSets = [](auto &obj) { return &obj.experimentalDataSets; };
   static auto bibliography = [](auto &obj) { return &obj.bibliography; };
   static auto endfCompatible = [](auto &obj) { return &obj.endfCompatible; };
}

using CPPAuthors = documentation::Authors;
using CPPContributors = documentation::Contributors;
using CPPCollaborations = documentation::Collaborations;
using CPPDates = documentation::Dates;
using CPPCopyright = documentation::Copyright;
using CPPAcknowledgements = documentation::Acknowledgements;
using CPPKeywords = documentation::Keywords;
using CPPRelatedItems = documentation::RelatedItems;
using CPPTitle = documentation::Title;
using CPPAbstract = documentation::Abstract;
using CPPBody = documentation::Body;
using CPPComputerCodes = documentation::ComputerCodes;
using CPPExperimentalDataSets = documentation::ExperimentalDataSets;
using CPPBibliography = documentation::Bibliography;
using CPPEndfCompatible = documentation::EndfCompatible;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstDocumentation
DocumentationDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Documentation
DocumentationDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstDocumentation
DocumentationCreateConst(
   const UTF8Text doi,
   const char *const publicationDate,
   const UTF8Text version,
   ConstHandle2ConstAuthors authors,
   ConstHandle2ConstContributors contributors,
   ConstHandle2ConstCollaborations collaborations,
   ConstHandle2ConstDates dates,
   ConstHandle2ConstCopyright copyright,
   ConstHandle2ConstAcknowledgements acknowledgements,
   ConstHandle2ConstKeywords keywords,
   ConstHandle2ConstRelatedItems relatedItems,
   ConstHandle2ConstTitle title,
   ConstHandle2ConstAbstract abstract,
   ConstHandle2ConstBody body,
   ConstHandle2ConstComputerCodes computerCodes,
   ConstHandle2ConstExperimentalDataSets experimentalDataSets,
   ConstHandle2ConstBibliography bibliography,
   ConstHandle2ConstEndfCompatible endfCompatible
) {
   ConstHandle2Documentation handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      doi,
      publicationDate,
      version,
      detail::tocpp<CPPAuthors>(authors),
      detail::tocpp<CPPContributors>(contributors),
      detail::tocpp<CPPCollaborations>(collaborations),
      detail::tocpp<CPPDates>(dates),
      detail::tocpp<CPPCopyright>(copyright),
      detail::tocpp<CPPAcknowledgements>(acknowledgements),
      detail::tocpp<CPPKeywords>(keywords),
      detail::tocpp<CPPRelatedItems>(relatedItems),
      detail::tocpp<CPPTitle>(title),
      detail::tocpp<CPPAbstract>(abstract),
      detail::tocpp<CPPBody>(body),
      detail::tocpp<CPPComputerCodes>(computerCodes),
      detail::tocpp<CPPExperimentalDataSets>(experimentalDataSets),
      detail::tocpp<CPPBibliography>(bibliography),
      detail::tocpp<CPPEndfCompatible>(endfCompatible)
   );
   return handle;
}

// Create, general
Handle2Documentation
DocumentationCreate(
   const UTF8Text doi,
   const char *const publicationDate,
   const UTF8Text version,
   ConstHandle2ConstAuthors authors,
   ConstHandle2ConstContributors contributors,
   ConstHandle2ConstCollaborations collaborations,
   ConstHandle2ConstDates dates,
   ConstHandle2ConstCopyright copyright,
   ConstHandle2ConstAcknowledgements acknowledgements,
   ConstHandle2ConstKeywords keywords,
   ConstHandle2ConstRelatedItems relatedItems,
   ConstHandle2ConstTitle title,
   ConstHandle2ConstAbstract abstract,
   ConstHandle2ConstBody body,
   ConstHandle2ConstComputerCodes computerCodes,
   ConstHandle2ConstExperimentalDataSets experimentalDataSets,
   ConstHandle2ConstBibliography bibliography,
   ConstHandle2ConstEndfCompatible endfCompatible
) {
   ConstHandle2Documentation handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      doi,
      publicationDate,
      version,
      detail::tocpp<CPPAuthors>(authors),
      detail::tocpp<CPPContributors>(contributors),
      detail::tocpp<CPPCollaborations>(collaborations),
      detail::tocpp<CPPDates>(dates),
      detail::tocpp<CPPCopyright>(copyright),
      detail::tocpp<CPPAcknowledgements>(acknowledgements),
      detail::tocpp<CPPKeywords>(keywords),
      detail::tocpp<CPPRelatedItems>(relatedItems),
      detail::tocpp<CPPTitle>(title),
      detail::tocpp<CPPAbstract>(abstract),
      detail::tocpp<CPPBody>(body),
      detail::tocpp<CPPComputerCodes>(computerCodes),
      detail::tocpp<CPPExperimentalDataSets>(experimentalDataSets),
      detail::tocpp<CPPBibliography>(bibliography),
      detail::tocpp<CPPEndfCompatible>(endfCompatible)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
DocumentationAssign(ConstHandle2Documentation This, ConstHandle2ConstDocumentation from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
DocumentationDelete(ConstHandle2ConstDocumentation This)
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
DocumentationRead(ConstHandle2Documentation This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
DocumentationWrite(ConstHandle2ConstDocumentation This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
DocumentationPrint(ConstHandle2ConstDocumentation This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
DocumentationPrintXML(ConstHandle2ConstDocumentation This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
DocumentationPrintJSON(ConstHandle2ConstDocumentation This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: doi
// -----------------------------------------------------------------------------

// Has
int
DocumentationDoiHas(ConstHandle2ConstDocumentation This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DoiHas", This, extract::doi);
}

// Get
// Returns by value
UTF8Text
DocumentationDoiGet(ConstHandle2ConstDocumentation This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DoiGet", This, extract::doi);
}

// Set
void
DocumentationDoiSet(ConstHandle2Documentation This, const UTF8Text doi)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DoiSet", This, extract::doi, doi);
}


// -----------------------------------------------------------------------------
// Metadatum: publicationDate
// -----------------------------------------------------------------------------

// Has
int
DocumentationPublicationDateHas(ConstHandle2ConstDocumentation This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"PublicationDateHas", This, extract::publicationDate);
}

// Get
// Returns by value
const char *
DocumentationPublicationDateGet(ConstHandle2ConstDocumentation This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"PublicationDateGet", This, extract::publicationDate);
}

// Set
void
DocumentationPublicationDateSet(ConstHandle2Documentation This, const char *const publicationDate)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"PublicationDateSet", This, extract::publicationDate, publicationDate);
}


// -----------------------------------------------------------------------------
// Metadatum: version
// -----------------------------------------------------------------------------

// Has
int
DocumentationVersionHas(ConstHandle2ConstDocumentation This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"VersionHas", This, extract::version);
}

// Get
// Returns by value
UTF8Text
DocumentationVersionGet(ConstHandle2ConstDocumentation This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"VersionGet", This, extract::version);
}

// Set
void
DocumentationVersionSet(ConstHandle2Documentation This, const UTF8Text version)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"VersionSet", This, extract::version, version);
}


// -----------------------------------------------------------------------------
// Child: authors
// -----------------------------------------------------------------------------

// Has
int
DocumentationAuthorsHas(ConstHandle2ConstDocumentation This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AuthorsHas", This, extract::authors);
}

// Get, const
Handle2ConstAuthors
DocumentationAuthorsGetConst(ConstHandle2ConstDocumentation This)
{
   return detail::getField<CPP,Handle2ConstAuthors>
      (CLASSNAME, CLASSNAME+"AuthorsGetConst", This, extract::authors);
}

// Get, non-const
Handle2Authors
DocumentationAuthorsGet(ConstHandle2Documentation This)
{
   return detail::getField<CPP,Handle2Authors>
      (CLASSNAME, CLASSNAME+"AuthorsGet", This, extract::authors);
}

// Set
void
DocumentationAuthorsSet(ConstHandle2Documentation This, ConstHandle2ConstAuthors authors)
{
   detail::setField<CPP,CPPAuthors>
      (CLASSNAME, CLASSNAME+"AuthorsSet", This, extract::authors, authors);
}


// -----------------------------------------------------------------------------
// Child: contributors
// -----------------------------------------------------------------------------

// Has
int
DocumentationContributorsHas(ConstHandle2ConstDocumentation This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ContributorsHas", This, extract::contributors);
}

// Get, const
Handle2ConstContributors
DocumentationContributorsGetConst(ConstHandle2ConstDocumentation This)
{
   return detail::getField<CPP,Handle2ConstContributors>
      (CLASSNAME, CLASSNAME+"ContributorsGetConst", This, extract::contributors);
}

// Get, non-const
Handle2Contributors
DocumentationContributorsGet(ConstHandle2Documentation This)
{
   return detail::getField<CPP,Handle2Contributors>
      (CLASSNAME, CLASSNAME+"ContributorsGet", This, extract::contributors);
}

// Set
void
DocumentationContributorsSet(ConstHandle2Documentation This, ConstHandle2ConstContributors contributors)
{
   detail::setField<CPP,CPPContributors>
      (CLASSNAME, CLASSNAME+"ContributorsSet", This, extract::contributors, contributors);
}


// -----------------------------------------------------------------------------
// Child: collaborations
// -----------------------------------------------------------------------------

// Has
int
DocumentationCollaborationsHas(ConstHandle2ConstDocumentation This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CollaborationsHas", This, extract::collaborations);
}

// Get, const
Handle2ConstCollaborations
DocumentationCollaborationsGetConst(ConstHandle2ConstDocumentation This)
{
   return detail::getField<CPP,Handle2ConstCollaborations>
      (CLASSNAME, CLASSNAME+"CollaborationsGetConst", This, extract::collaborations);
}

// Get, non-const
Handle2Collaborations
DocumentationCollaborationsGet(ConstHandle2Documentation This)
{
   return detail::getField<CPP,Handle2Collaborations>
      (CLASSNAME, CLASSNAME+"CollaborationsGet", This, extract::collaborations);
}

// Set
void
DocumentationCollaborationsSet(ConstHandle2Documentation This, ConstHandle2ConstCollaborations collaborations)
{
   detail::setField<CPP,CPPCollaborations>
      (CLASSNAME, CLASSNAME+"CollaborationsSet", This, extract::collaborations, collaborations);
}


// -----------------------------------------------------------------------------
// Child: dates
// -----------------------------------------------------------------------------

// Has
int
DocumentationDatesHas(ConstHandle2ConstDocumentation This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DatesHas", This, extract::dates);
}

// Get, const
Handle2ConstDates
DocumentationDatesGetConst(ConstHandle2ConstDocumentation This)
{
   return detail::getField<CPP,Handle2ConstDates>
      (CLASSNAME, CLASSNAME+"DatesGetConst", This, extract::dates);
}

// Get, non-const
Handle2Dates
DocumentationDatesGet(ConstHandle2Documentation This)
{
   return detail::getField<CPP,Handle2Dates>
      (CLASSNAME, CLASSNAME+"DatesGet", This, extract::dates);
}

// Set
void
DocumentationDatesSet(ConstHandle2Documentation This, ConstHandle2ConstDates dates)
{
   detail::setField<CPP,CPPDates>
      (CLASSNAME, CLASSNAME+"DatesSet", This, extract::dates, dates);
}


// -----------------------------------------------------------------------------
// Child: copyright
// -----------------------------------------------------------------------------

// Has
int
DocumentationCopyrightHas(ConstHandle2ConstDocumentation This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CopyrightHas", This, extract::copyright);
}

// Get, const
Handle2ConstCopyright
DocumentationCopyrightGetConst(ConstHandle2ConstDocumentation This)
{
   return detail::getField<CPP,Handle2ConstCopyright>
      (CLASSNAME, CLASSNAME+"CopyrightGetConst", This, extract::copyright);
}

// Get, non-const
Handle2Copyright
DocumentationCopyrightGet(ConstHandle2Documentation This)
{
   return detail::getField<CPP,Handle2Copyright>
      (CLASSNAME, CLASSNAME+"CopyrightGet", This, extract::copyright);
}

// Set
void
DocumentationCopyrightSet(ConstHandle2Documentation This, ConstHandle2ConstCopyright copyright)
{
   detail::setField<CPP,CPPCopyright>
      (CLASSNAME, CLASSNAME+"CopyrightSet", This, extract::copyright, copyright);
}


// -----------------------------------------------------------------------------
// Child: acknowledgements
// -----------------------------------------------------------------------------

// Has
int
DocumentationAcknowledgementsHas(ConstHandle2ConstDocumentation This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AcknowledgementsHas", This, extract::acknowledgements);
}

// Get, const
Handle2ConstAcknowledgements
DocumentationAcknowledgementsGetConst(ConstHandle2ConstDocumentation This)
{
   return detail::getField<CPP,Handle2ConstAcknowledgements>
      (CLASSNAME, CLASSNAME+"AcknowledgementsGetConst", This, extract::acknowledgements);
}

// Get, non-const
Handle2Acknowledgements
DocumentationAcknowledgementsGet(ConstHandle2Documentation This)
{
   return detail::getField<CPP,Handle2Acknowledgements>
      (CLASSNAME, CLASSNAME+"AcknowledgementsGet", This, extract::acknowledgements);
}

// Set
void
DocumentationAcknowledgementsSet(ConstHandle2Documentation This, ConstHandle2ConstAcknowledgements acknowledgements)
{
   detail::setField<CPP,CPPAcknowledgements>
      (CLASSNAME, CLASSNAME+"AcknowledgementsSet", This, extract::acknowledgements, acknowledgements);
}


// -----------------------------------------------------------------------------
// Child: keywords
// -----------------------------------------------------------------------------

// Has
int
DocumentationKeywordsHas(ConstHandle2ConstDocumentation This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"KeywordsHas", This, extract::keywords);
}

// Get, const
Handle2ConstKeywords
DocumentationKeywordsGetConst(ConstHandle2ConstDocumentation This)
{
   return detail::getField<CPP,Handle2ConstKeywords>
      (CLASSNAME, CLASSNAME+"KeywordsGetConst", This, extract::keywords);
}

// Get, non-const
Handle2Keywords
DocumentationKeywordsGet(ConstHandle2Documentation This)
{
   return detail::getField<CPP,Handle2Keywords>
      (CLASSNAME, CLASSNAME+"KeywordsGet", This, extract::keywords);
}

// Set
void
DocumentationKeywordsSet(ConstHandle2Documentation This, ConstHandle2ConstKeywords keywords)
{
   detail::setField<CPP,CPPKeywords>
      (CLASSNAME, CLASSNAME+"KeywordsSet", This, extract::keywords, keywords);
}


// -----------------------------------------------------------------------------
// Child: relatedItems
// -----------------------------------------------------------------------------

// Has
int
DocumentationRelatedItemsHas(ConstHandle2ConstDocumentation This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"RelatedItemsHas", This, extract::relatedItems);
}

// Get, const
Handle2ConstRelatedItems
DocumentationRelatedItemsGetConst(ConstHandle2ConstDocumentation This)
{
   return detail::getField<CPP,Handle2ConstRelatedItems>
      (CLASSNAME, CLASSNAME+"RelatedItemsGetConst", This, extract::relatedItems);
}

// Get, non-const
Handle2RelatedItems
DocumentationRelatedItemsGet(ConstHandle2Documentation This)
{
   return detail::getField<CPP,Handle2RelatedItems>
      (CLASSNAME, CLASSNAME+"RelatedItemsGet", This, extract::relatedItems);
}

// Set
void
DocumentationRelatedItemsSet(ConstHandle2Documentation This, ConstHandle2ConstRelatedItems relatedItems)
{
   detail::setField<CPP,CPPRelatedItems>
      (CLASSNAME, CLASSNAME+"RelatedItemsSet", This, extract::relatedItems, relatedItems);
}


// -----------------------------------------------------------------------------
// Child: title
// -----------------------------------------------------------------------------

// Has
int
DocumentationTitleHas(ConstHandle2ConstDocumentation This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"TitleHas", This, extract::title);
}

// Get, const
Handle2ConstTitle
DocumentationTitleGetConst(ConstHandle2ConstDocumentation This)
{
   return detail::getField<CPP,Handle2ConstTitle>
      (CLASSNAME, CLASSNAME+"TitleGetConst", This, extract::title);
}

// Get, non-const
Handle2Title
DocumentationTitleGet(ConstHandle2Documentation This)
{
   return detail::getField<CPP,Handle2Title>
      (CLASSNAME, CLASSNAME+"TitleGet", This, extract::title);
}

// Set
void
DocumentationTitleSet(ConstHandle2Documentation This, ConstHandle2ConstTitle title)
{
   detail::setField<CPP,CPPTitle>
      (CLASSNAME, CLASSNAME+"TitleSet", This, extract::title, title);
}


// -----------------------------------------------------------------------------
// Child: abstract
// -----------------------------------------------------------------------------

// Has
int
DocumentationAbstractHas(ConstHandle2ConstDocumentation This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AbstractHas", This, extract::abstract);
}

// Get, const
Handle2ConstAbstract
DocumentationAbstractGetConst(ConstHandle2ConstDocumentation This)
{
   return detail::getField<CPP,Handle2ConstAbstract>
      (CLASSNAME, CLASSNAME+"AbstractGetConst", This, extract::abstract);
}

// Get, non-const
Handle2Abstract
DocumentationAbstractGet(ConstHandle2Documentation This)
{
   return detail::getField<CPP,Handle2Abstract>
      (CLASSNAME, CLASSNAME+"AbstractGet", This, extract::abstract);
}

// Set
void
DocumentationAbstractSet(ConstHandle2Documentation This, ConstHandle2ConstAbstract abstract)
{
   detail::setField<CPP,CPPAbstract>
      (CLASSNAME, CLASSNAME+"AbstractSet", This, extract::abstract, abstract);
}


// -----------------------------------------------------------------------------
// Child: body
// -----------------------------------------------------------------------------

// Has
int
DocumentationBodyHas(ConstHandle2ConstDocumentation This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"BodyHas", This, extract::body);
}

// Get, const
Handle2ConstBody
DocumentationBodyGetConst(ConstHandle2ConstDocumentation This)
{
   return detail::getField<CPP,Handle2ConstBody>
      (CLASSNAME, CLASSNAME+"BodyGetConst", This, extract::body);
}

// Get, non-const
Handle2Body
DocumentationBodyGet(ConstHandle2Documentation This)
{
   return detail::getField<CPP,Handle2Body>
      (CLASSNAME, CLASSNAME+"BodyGet", This, extract::body);
}

// Set
void
DocumentationBodySet(ConstHandle2Documentation This, ConstHandle2ConstBody body)
{
   detail::setField<CPP,CPPBody>
      (CLASSNAME, CLASSNAME+"BodySet", This, extract::body, body);
}


// -----------------------------------------------------------------------------
// Child: computerCodes
// -----------------------------------------------------------------------------

// Has
int
DocumentationComputerCodesHas(ConstHandle2ConstDocumentation This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ComputerCodesHas", This, extract::computerCodes);
}

// Get, const
Handle2ConstComputerCodes
DocumentationComputerCodesGetConst(ConstHandle2ConstDocumentation This)
{
   return detail::getField<CPP,Handle2ConstComputerCodes>
      (CLASSNAME, CLASSNAME+"ComputerCodesGetConst", This, extract::computerCodes);
}

// Get, non-const
Handle2ComputerCodes
DocumentationComputerCodesGet(ConstHandle2Documentation This)
{
   return detail::getField<CPP,Handle2ComputerCodes>
      (CLASSNAME, CLASSNAME+"ComputerCodesGet", This, extract::computerCodes);
}

// Set
void
DocumentationComputerCodesSet(ConstHandle2Documentation This, ConstHandle2ConstComputerCodes computerCodes)
{
   detail::setField<CPP,CPPComputerCodes>
      (CLASSNAME, CLASSNAME+"ComputerCodesSet", This, extract::computerCodes, computerCodes);
}


// -----------------------------------------------------------------------------
// Child: experimentalDataSets
// -----------------------------------------------------------------------------

// Has
int
DocumentationExperimentalDataSetsHas(ConstHandle2ConstDocumentation This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ExperimentalDataSetsHas", This, extract::experimentalDataSets);
}

// Get, const
Handle2ConstExperimentalDataSets
DocumentationExperimentalDataSetsGetConst(ConstHandle2ConstDocumentation This)
{
   return detail::getField<CPP,Handle2ConstExperimentalDataSets>
      (CLASSNAME, CLASSNAME+"ExperimentalDataSetsGetConst", This, extract::experimentalDataSets);
}

// Get, non-const
Handle2ExperimentalDataSets
DocumentationExperimentalDataSetsGet(ConstHandle2Documentation This)
{
   return detail::getField<CPP,Handle2ExperimentalDataSets>
      (CLASSNAME, CLASSNAME+"ExperimentalDataSetsGet", This, extract::experimentalDataSets);
}

// Set
void
DocumentationExperimentalDataSetsSet(ConstHandle2Documentation This, ConstHandle2ConstExperimentalDataSets experimentalDataSets)
{
   detail::setField<CPP,CPPExperimentalDataSets>
      (CLASSNAME, CLASSNAME+"ExperimentalDataSetsSet", This, extract::experimentalDataSets, experimentalDataSets);
}


// -----------------------------------------------------------------------------
// Child: bibliography
// -----------------------------------------------------------------------------

// Has
int
DocumentationBibliographyHas(ConstHandle2ConstDocumentation This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"BibliographyHas", This, extract::bibliography);
}

// Get, const
Handle2ConstBibliography
DocumentationBibliographyGetConst(ConstHandle2ConstDocumentation This)
{
   return detail::getField<CPP,Handle2ConstBibliography>
      (CLASSNAME, CLASSNAME+"BibliographyGetConst", This, extract::bibliography);
}

// Get, non-const
Handle2Bibliography
DocumentationBibliographyGet(ConstHandle2Documentation This)
{
   return detail::getField<CPP,Handle2Bibliography>
      (CLASSNAME, CLASSNAME+"BibliographyGet", This, extract::bibliography);
}

// Set
void
DocumentationBibliographySet(ConstHandle2Documentation This, ConstHandle2ConstBibliography bibliography)
{
   detail::setField<CPP,CPPBibliography>
      (CLASSNAME, CLASSNAME+"BibliographySet", This, extract::bibliography, bibliography);
}


// -----------------------------------------------------------------------------
// Child: endfCompatible
// -----------------------------------------------------------------------------

// Has
int
DocumentationEndfCompatibleHas(ConstHandle2ConstDocumentation This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EndfCompatibleHas", This, extract::endfCompatible);
}

// Get, const
Handle2ConstEndfCompatible
DocumentationEndfCompatibleGetConst(ConstHandle2ConstDocumentation This)
{
   return detail::getField<CPP,Handle2ConstEndfCompatible>
      (CLASSNAME, CLASSNAME+"EndfCompatibleGetConst", This, extract::endfCompatible);
}

// Get, non-const
Handle2EndfCompatible
DocumentationEndfCompatibleGet(ConstHandle2Documentation This)
{
   return detail::getField<CPP,Handle2EndfCompatible>
      (CLASSNAME, CLASSNAME+"EndfCompatibleGet", This, extract::endfCompatible);
}

// Set
void
DocumentationEndfCompatibleSet(ConstHandle2Documentation This, ConstHandle2ConstEndfCompatible endfCompatible)
{
   detail::setField<CPP,CPPEndfCompatible>
      (CLASSNAME, CLASSNAME+"EndfCompatibleSet", This, extract::endfCompatible, endfCompatible);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/documentation/Documentation/src/custom.cpp"
