
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/documentation/Contributor.hpp"
#include "Contributor.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = ContributorClass;
using CPP = multigroup::Contributor;

static const std::string CLASSNAME = "Contributor";

namespace extract {
   static auto name = [](auto &obj) { return &obj.name; };
   static auto contributorType = [](auto &obj) { return &obj.contributorType; };
   static auto orcid = [](auto &obj) { return &obj.orcid; };
   static auto email = [](auto &obj) { return &obj.email; };
   static auto affiliations = [](auto &obj) { return &obj.affiliations; };
   static auto note = [](auto &obj) { return &obj.note; };
}

using CPPAffiliations = documentation::Affiliations;
using CPPNote = documentation::Note;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstContributor
ContributorDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Contributor
ContributorDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstContributor
ContributorCreateConst(
   const UTF8Text name,
   const enums::ContributorType contributorType,
   const UTF8Text orcid,
   const UTF8Text email,
   ConstHandle2ConstAffiliations affiliations,
   ConstHandle2ConstNote note
) {
   ConstHandle2Contributor handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      name,
      contributorType,
      orcid,
      email,
      detail::tocpp<CPPAffiliations>(affiliations),
      detail::tocpp<CPPNote>(note)
   );
   return handle;
}

// Create, general
Handle2Contributor
ContributorCreate(
   const UTF8Text name,
   const enums::ContributorType contributorType,
   const UTF8Text orcid,
   const UTF8Text email,
   ConstHandle2ConstAffiliations affiliations,
   ConstHandle2ConstNote note
) {
   ConstHandle2Contributor handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      name,
      contributorType,
      orcid,
      email,
      detail::tocpp<CPPAffiliations>(affiliations),
      detail::tocpp<CPPNote>(note)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ContributorAssign(ConstHandle2Contributor This, ConstHandle2ConstContributor from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ContributorDelete(ConstHandle2ConstContributor This)
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
ContributorRead(ConstHandle2Contributor This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ContributorWrite(ConstHandle2ConstContributor This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
ContributorPrint(ConstHandle2ConstContributor This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
ContributorPrintXML(ConstHandle2ConstContributor This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
ContributorPrintJSON(ConstHandle2ConstContributor This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: name
// -----------------------------------------------------------------------------

// Has
int
ContributorNameHas(ConstHandle2ConstContributor This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"NameHas", This, extract::name);
}

// Get
// Returns by value
UTF8Text
ContributorNameGet(ConstHandle2ConstContributor This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"NameGet", This, extract::name);
}

// Set
void
ContributorNameSet(ConstHandle2Contributor This, const UTF8Text name)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"NameSet", This, extract::name, name);
}


// -----------------------------------------------------------------------------
// Metadatum: contributorType
// -----------------------------------------------------------------------------

// Has
int
ContributorContributorTypeHas(ConstHandle2ConstContributor This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ContributorTypeHas", This, extract::contributorType);
}

// Get
// Returns by value
enums::ContributorType
ContributorContributorTypeGet(ConstHandle2ConstContributor This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ContributorTypeGet", This, extract::contributorType);
}

// Set
void
ContributorContributorTypeSet(ConstHandle2Contributor This, const enums::ContributorType contributorType)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ContributorTypeSet", This, extract::contributorType, contributorType);
}


// -----------------------------------------------------------------------------
// Metadatum: orcid
// -----------------------------------------------------------------------------

// Has
int
ContributorOrcidHas(ConstHandle2ConstContributor This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"OrcidHas", This, extract::orcid);
}

// Get
// Returns by value
UTF8Text
ContributorOrcidGet(ConstHandle2ConstContributor This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"OrcidGet", This, extract::orcid);
}

// Set
void
ContributorOrcidSet(ConstHandle2Contributor This, const UTF8Text orcid)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"OrcidSet", This, extract::orcid, orcid);
}


// -----------------------------------------------------------------------------
// Metadatum: email
// -----------------------------------------------------------------------------

// Has
int
ContributorEmailHas(ConstHandle2ConstContributor This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EmailHas", This, extract::email);
}

// Get
// Returns by value
UTF8Text
ContributorEmailGet(ConstHandle2ConstContributor This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"EmailGet", This, extract::email);
}

// Set
void
ContributorEmailSet(ConstHandle2Contributor This, const UTF8Text email)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"EmailSet", This, extract::email, email);
}


// -----------------------------------------------------------------------------
// Child: affiliations
// -----------------------------------------------------------------------------

// Has
int
ContributorAffiliationsHas(ConstHandle2ConstContributor This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AffiliationsHas", This, extract::affiliations);
}

// Get, const
Handle2ConstAffiliations
ContributorAffiliationsGetConst(ConstHandle2ConstContributor This)
{
   return detail::getField<CPP,Handle2ConstAffiliations>
      (CLASSNAME, CLASSNAME+"AffiliationsGetConst", This, extract::affiliations);
}

// Get, non-const
Handle2Affiliations
ContributorAffiliationsGet(ConstHandle2Contributor This)
{
   return detail::getField<CPP,Handle2Affiliations>
      (CLASSNAME, CLASSNAME+"AffiliationsGet", This, extract::affiliations);
}

// Set
void
ContributorAffiliationsSet(ConstHandle2Contributor This, ConstHandle2ConstAffiliations affiliations)
{
   detail::setField<CPP,CPPAffiliations>
      (CLASSNAME, CLASSNAME+"AffiliationsSet", This, extract::affiliations, affiliations);
}


// -----------------------------------------------------------------------------
// Child: note
// -----------------------------------------------------------------------------

// Has
int
ContributorNoteHas(ConstHandle2ConstContributor This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"NoteHas", This, extract::note);
}

// Get, const
Handle2ConstNote
ContributorNoteGetConst(ConstHandle2ConstContributor This)
{
   return detail::getField<CPP,Handle2ConstNote>
      (CLASSNAME, CLASSNAME+"NoteGetConst", This, extract::note);
}

// Get, non-const
Handle2Note
ContributorNoteGet(ConstHandle2Contributor This)
{
   return detail::getField<CPP,Handle2Note>
      (CLASSNAME, CLASSNAME+"NoteGet", This, extract::note);
}

// Set
void
ContributorNoteSet(ConstHandle2Contributor This, ConstHandle2ConstNote note)
{
   detail::setField<CPP,CPPNote>
      (CLASSNAME, CLASSNAME+"NoteSet", This, extract::note, note);
}
