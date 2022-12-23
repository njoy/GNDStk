
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
//    // +++ remark
// Constructs you're LESS likely to care about are preceded with:
//    // --- remark
// Anything not marked as above can be ignored by most users.
//
// Contributor is the basic handle type in this file. Example:
//    // Create a default Contributor object:
//    Contributor handle = ContributorDefault();
// Functions involving Contributor are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_DOCUMENTATION_CONTRIBUTOR
#define C_INTERFACE_TEST_V2_0_DOCUMENTATION_CONTRIBUTOR

#include "GNDStk.h"
#include "v2.0/documentation/Affiliations.h"
#include "v2.0/documentation/Note.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ContributorClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Contributor
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ContributorClass *Contributor;

// --- Const-aware handles.
typedef const struct ContributorClass *const ConstHandle2ConstContributor;
typedef       struct ContributorClass *const ConstHandle2Contributor;
typedef const struct ContributorClass *      Handle2ConstContributor;
typedef       struct ContributorClass *      Handle2Contributor;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstContributor
ContributorDefaultConst();

// +++ Create, default
extern_c Handle2Contributor
ContributorDefault();

// --- Create, general, const
extern_c Handle2ConstContributor
ContributorCreateConst(
   const UTF8Text name,
   const enums::ContributorType contributorType,
   const UTF8Text orcid,
   const UTF8Text email,
   ConstHandle2ConstAffiliations affiliations,
   ConstHandle2ConstNote note
);

// +++ Create, general
extern_c Handle2Contributor
ContributorCreate(
   const UTF8Text name,
   const enums::ContributorType contributorType,
   const UTF8Text orcid,
   const UTF8Text email,
   ConstHandle2ConstAffiliations affiliations,
   ConstHandle2ConstNote note
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ContributorAssign(ConstHandle2Contributor This, ConstHandle2ConstContributor from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ContributorDelete(ConstHandle2ConstContributor This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ContributorRead(ConstHandle2Contributor This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ContributorWrite(ConstHandle2ConstContributor This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ContributorPrint(ConstHandle2ConstContributor This);

// +++ Print to standard output, as XML
extern_c int
ContributorPrintXML(ConstHandle2ConstContributor This);

// +++ Print to standard output, as JSON
extern_c int
ContributorPrintJSON(ConstHandle2ConstContributor This);


// -----------------------------------------------------------------------------
// Metadatum: name
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ContributorNameHas(ConstHandle2ConstContributor This);

// +++ Get
// +++ Returns by value
extern_c UTF8Text
ContributorNameGet(ConstHandle2ConstContributor This);

// +++ Set
extern_c void
ContributorNameSet(ConstHandle2Contributor This, const UTF8Text name);


// -----------------------------------------------------------------------------
// Metadatum: contributorType
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ContributorContributorTypeHas(ConstHandle2ConstContributor This);

// +++ Get
// +++ Returns by value
extern_c enums::ContributorType
ContributorContributorTypeGet(ConstHandle2ConstContributor This);

// +++ Set
extern_c void
ContributorContributorTypeSet(ConstHandle2Contributor This, const enums::ContributorType contributorType);


// -----------------------------------------------------------------------------
// Metadatum: orcid
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ContributorOrcidHas(ConstHandle2ConstContributor This);

// +++ Get
// +++ Returns by value
extern_c UTF8Text
ContributorOrcidGet(ConstHandle2ConstContributor This);

// +++ Set
extern_c void
ContributorOrcidSet(ConstHandle2Contributor This, const UTF8Text orcid);


// -----------------------------------------------------------------------------
// Metadatum: email
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ContributorEmailHas(ConstHandle2ConstContributor This);

// +++ Get
// +++ Returns by value
extern_c UTF8Text
ContributorEmailGet(ConstHandle2ConstContributor This);

// +++ Set
extern_c void
ContributorEmailSet(ConstHandle2Contributor This, const UTF8Text email);


// -----------------------------------------------------------------------------
// Child: affiliations
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ContributorAffiliationsHas(ConstHandle2ConstContributor This);

// --- Get, const
extern_c Handle2ConstAffiliations
ContributorAffiliationsGetConst(ConstHandle2ConstContributor This);

// +++ Get, non-const
extern_c Handle2Affiliations
ContributorAffiliationsGet(ConstHandle2Contributor This);

// +++ Set
extern_c void
ContributorAffiliationsSet(ConstHandle2Contributor This, ConstHandle2ConstAffiliations affiliations);


// -----------------------------------------------------------------------------
// Child: note
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ContributorNoteHas(ConstHandle2ConstContributor This);

// --- Get, const
extern_c Handle2ConstNote
ContributorNoteGetConst(ConstHandle2ConstContributor This);

// +++ Get, non-const
extern_c Handle2Note
ContributorNoteGet(ConstHandle2Contributor This);

// +++ Set
extern_c void
ContributorNoteSet(ConstHandle2Contributor This, ConstHandle2ConstNote note);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
