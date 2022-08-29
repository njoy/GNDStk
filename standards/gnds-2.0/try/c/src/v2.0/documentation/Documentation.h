
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// Interface for C
// This header file is designed to work with both C and C++
// Function definitions are in this file's .cpp source

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Instructions for Users
//
// Constructs you're MORE likely to care about are preceded with:
//    // +++ comment
// Constructs you're LESS likely to care about are preceded with:
//    // --- comment
// Anything not marked as above can be ignored by most users.
//
// Documentation is the basic handle type in this file. Example:
//    // Create a default Documentation object:
//    Documentation handle = DocumentationDefault();
// Functions involving Documentation are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0_DOCUMENTATION_DOCUMENTATION
#define C_INTERFACE_TRY_V2_0_DOCUMENTATION_DOCUMENTATION

#include "GNDStk.h"
#include "v2.0/documentation/Authors.h"
#include "v2.0/documentation/Contributors.h"
#include "v2.0/documentation/Collaborations.h"
#include "v2.0/documentation/Dates.h"
#include "v2.0/documentation/Copyright.h"
#include "v2.0/documentation/Acknowledgements.h"
#include "v2.0/documentation/Keywords.h"
#include "v2.0/documentation/RelatedItems.h"
#include "v2.0/documentation/Title.h"
#include "v2.0/documentation/Abstract.h"
#include "v2.0/documentation/Body.h"
#include "v2.0/documentation/ComputerCodes.h"
#include "v2.0/documentation/ExperimentalDataSets.h"
#include "v2.0/documentation/Bibliography.h"
#include "v2.0/documentation/EndfCompatible.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct DocumentationClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Documentation
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct DocumentationClass *Documentation;

// --- Const-aware handles.
typedef const struct DocumentationClass *const ConstHandle2ConstDocumentation;
typedef       struct DocumentationClass *const ConstHandle2Documentation;
typedef const struct DocumentationClass *      Handle2ConstDocumentation;
typedef       struct DocumentationClass *      Handle2Documentation;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstDocumentation
DocumentationDefaultConst();

// +++ Create, default
extern_c Handle2Documentation
DocumentationDefault();

// --- Create, general, const
extern_c Handle2ConstDocumentation
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
);

// +++ Create, general
extern_c Handle2Documentation
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
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
DocumentationAssign(ConstHandle2Documentation This, ConstHandle2ConstDocumentation from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
DocumentationDelete(ConstHandle2ConstDocumentation This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
DocumentationRead(ConstHandle2Documentation This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
DocumentationWrite(ConstHandle2ConstDocumentation This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
DocumentationPrint(ConstHandle2ConstDocumentation This);

// +++ Print to standard output, as XML
extern_c int
DocumentationPrintXML(ConstHandle2ConstDocumentation This);

// +++ Print to standard output, as JSON
extern_c int
DocumentationPrintJSON(ConstHandle2ConstDocumentation This);


// -----------------------------------------------------------------------------
// Metadatum: doi
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DocumentationDoiHas(ConstHandle2ConstDocumentation This);

// +++ Get
// +++ Returns by value
extern_c UTF8Text
DocumentationDoiGet(ConstHandle2ConstDocumentation This);

// +++ Set
extern_c void
DocumentationDoiSet(ConstHandle2Documentation This, const UTF8Text doi);


// -----------------------------------------------------------------------------
// Metadatum: publicationDate
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DocumentationPublicationDateHas(ConstHandle2ConstDocumentation This);

// +++ Get
// +++ Returns by value
extern_c const char *
DocumentationPublicationDateGet(ConstHandle2ConstDocumentation This);

// +++ Set
extern_c void
DocumentationPublicationDateSet(ConstHandle2Documentation This, const char *const publicationDate);


// -----------------------------------------------------------------------------
// Metadatum: version
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DocumentationVersionHas(ConstHandle2ConstDocumentation This);

// +++ Get
// +++ Returns by value
extern_c UTF8Text
DocumentationVersionGet(ConstHandle2ConstDocumentation This);

// +++ Set
extern_c void
DocumentationVersionSet(ConstHandle2Documentation This, const UTF8Text version);


// -----------------------------------------------------------------------------
// Child: authors
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DocumentationAuthorsHas(ConstHandle2ConstDocumentation This);

// --- Get, const
extern_c Handle2ConstAuthors
DocumentationAuthorsGetConst(ConstHandle2ConstDocumentation This);

// +++ Get, non-const
extern_c Handle2Authors
DocumentationAuthorsGet(ConstHandle2Documentation This);

// +++ Set
extern_c void
DocumentationAuthorsSet(ConstHandle2Documentation This, ConstHandle2ConstAuthors authors);


// -----------------------------------------------------------------------------
// Child: contributors
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DocumentationContributorsHas(ConstHandle2ConstDocumentation This);

// --- Get, const
extern_c Handle2ConstContributors
DocumentationContributorsGetConst(ConstHandle2ConstDocumentation This);

// +++ Get, non-const
extern_c Handle2Contributors
DocumentationContributorsGet(ConstHandle2Documentation This);

// +++ Set
extern_c void
DocumentationContributorsSet(ConstHandle2Documentation This, ConstHandle2ConstContributors contributors);


// -----------------------------------------------------------------------------
// Child: collaborations
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DocumentationCollaborationsHas(ConstHandle2ConstDocumentation This);

// --- Get, const
extern_c Handle2ConstCollaborations
DocumentationCollaborationsGetConst(ConstHandle2ConstDocumentation This);

// +++ Get, non-const
extern_c Handle2Collaborations
DocumentationCollaborationsGet(ConstHandle2Documentation This);

// +++ Set
extern_c void
DocumentationCollaborationsSet(ConstHandle2Documentation This, ConstHandle2ConstCollaborations collaborations);


// -----------------------------------------------------------------------------
// Child: dates
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DocumentationDatesHas(ConstHandle2ConstDocumentation This);

// --- Get, const
extern_c Handle2ConstDates
DocumentationDatesGetConst(ConstHandle2ConstDocumentation This);

// +++ Get, non-const
extern_c Handle2Dates
DocumentationDatesGet(ConstHandle2Documentation This);

// +++ Set
extern_c void
DocumentationDatesSet(ConstHandle2Documentation This, ConstHandle2ConstDates dates);


// -----------------------------------------------------------------------------
// Child: copyright
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DocumentationCopyrightHas(ConstHandle2ConstDocumentation This);

// --- Get, const
extern_c Handle2ConstCopyright
DocumentationCopyrightGetConst(ConstHandle2ConstDocumentation This);

// +++ Get, non-const
extern_c Handle2Copyright
DocumentationCopyrightGet(ConstHandle2Documentation This);

// +++ Set
extern_c void
DocumentationCopyrightSet(ConstHandle2Documentation This, ConstHandle2ConstCopyright copyright);


// -----------------------------------------------------------------------------
// Child: acknowledgements
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DocumentationAcknowledgementsHas(ConstHandle2ConstDocumentation This);

// --- Get, const
extern_c Handle2ConstAcknowledgements
DocumentationAcknowledgementsGetConst(ConstHandle2ConstDocumentation This);

// +++ Get, non-const
extern_c Handle2Acknowledgements
DocumentationAcknowledgementsGet(ConstHandle2Documentation This);

// +++ Set
extern_c void
DocumentationAcknowledgementsSet(ConstHandle2Documentation This, ConstHandle2ConstAcknowledgements acknowledgements);


// -----------------------------------------------------------------------------
// Child: keywords
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DocumentationKeywordsHas(ConstHandle2ConstDocumentation This);

// --- Get, const
extern_c Handle2ConstKeywords
DocumentationKeywordsGetConst(ConstHandle2ConstDocumentation This);

// +++ Get, non-const
extern_c Handle2Keywords
DocumentationKeywordsGet(ConstHandle2Documentation This);

// +++ Set
extern_c void
DocumentationKeywordsSet(ConstHandle2Documentation This, ConstHandle2ConstKeywords keywords);


// -----------------------------------------------------------------------------
// Child: relatedItems
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DocumentationRelatedItemsHas(ConstHandle2ConstDocumentation This);

// --- Get, const
extern_c Handle2ConstRelatedItems
DocumentationRelatedItemsGetConst(ConstHandle2ConstDocumentation This);

// +++ Get, non-const
extern_c Handle2RelatedItems
DocumentationRelatedItemsGet(ConstHandle2Documentation This);

// +++ Set
extern_c void
DocumentationRelatedItemsSet(ConstHandle2Documentation This, ConstHandle2ConstRelatedItems relatedItems);


// -----------------------------------------------------------------------------
// Child: title
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DocumentationTitleHas(ConstHandle2ConstDocumentation This);

// --- Get, const
extern_c Handle2ConstTitle
DocumentationTitleGetConst(ConstHandle2ConstDocumentation This);

// +++ Get, non-const
extern_c Handle2Title
DocumentationTitleGet(ConstHandle2Documentation This);

// +++ Set
extern_c void
DocumentationTitleSet(ConstHandle2Documentation This, ConstHandle2ConstTitle title);


// -----------------------------------------------------------------------------
// Child: abstract
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DocumentationAbstractHas(ConstHandle2ConstDocumentation This);

// --- Get, const
extern_c Handle2ConstAbstract
DocumentationAbstractGetConst(ConstHandle2ConstDocumentation This);

// +++ Get, non-const
extern_c Handle2Abstract
DocumentationAbstractGet(ConstHandle2Documentation This);

// +++ Set
extern_c void
DocumentationAbstractSet(ConstHandle2Documentation This, ConstHandle2ConstAbstract abstract);


// -----------------------------------------------------------------------------
// Child: body
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DocumentationBodyHas(ConstHandle2ConstDocumentation This);

// --- Get, const
extern_c Handle2ConstBody
DocumentationBodyGetConst(ConstHandle2ConstDocumentation This);

// +++ Get, non-const
extern_c Handle2Body
DocumentationBodyGet(ConstHandle2Documentation This);

// +++ Set
extern_c void
DocumentationBodySet(ConstHandle2Documentation This, ConstHandle2ConstBody body);


// -----------------------------------------------------------------------------
// Child: computerCodes
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DocumentationComputerCodesHas(ConstHandle2ConstDocumentation This);

// --- Get, const
extern_c Handle2ConstComputerCodes
DocumentationComputerCodesGetConst(ConstHandle2ConstDocumentation This);

// +++ Get, non-const
extern_c Handle2ComputerCodes
DocumentationComputerCodesGet(ConstHandle2Documentation This);

// +++ Set
extern_c void
DocumentationComputerCodesSet(ConstHandle2Documentation This, ConstHandle2ConstComputerCodes computerCodes);


// -----------------------------------------------------------------------------
// Child: experimentalDataSets
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DocumentationExperimentalDataSetsHas(ConstHandle2ConstDocumentation This);

// --- Get, const
extern_c Handle2ConstExperimentalDataSets
DocumentationExperimentalDataSetsGetConst(ConstHandle2ConstDocumentation This);

// +++ Get, non-const
extern_c Handle2ExperimentalDataSets
DocumentationExperimentalDataSetsGet(ConstHandle2Documentation This);

// +++ Set
extern_c void
DocumentationExperimentalDataSetsSet(ConstHandle2Documentation This, ConstHandle2ConstExperimentalDataSets experimentalDataSets);


// -----------------------------------------------------------------------------
// Child: bibliography
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DocumentationBibliographyHas(ConstHandle2ConstDocumentation This);

// --- Get, const
extern_c Handle2ConstBibliography
DocumentationBibliographyGetConst(ConstHandle2ConstDocumentation This);

// +++ Get, non-const
extern_c Handle2Bibliography
DocumentationBibliographyGet(ConstHandle2Documentation This);

// +++ Set
extern_c void
DocumentationBibliographySet(ConstHandle2Documentation This, ConstHandle2ConstBibliography bibliography);


// -----------------------------------------------------------------------------
// Child: endfCompatible
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DocumentationEndfCompatibleHas(ConstHandle2ConstDocumentation This);

// --- Get, const
extern_c Handle2ConstEndfCompatible
DocumentationEndfCompatibleGetConst(ConstHandle2ConstDocumentation This);

// +++ Get, non-const
extern_c Handle2EndfCompatible
DocumentationEndfCompatibleGet(ConstHandle2Documentation This);

// +++ Set
extern_c void
DocumentationEndfCompatibleSet(ConstHandle2Documentation This, ConstHandle2ConstEndfCompatible endfCompatible);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
