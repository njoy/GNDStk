
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/documentation/Author.hpp"
#include "Author.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = AuthorClass;
using CPP = multigroup::Author;

static const std::string CLASSNAME = "Author";

namespace extract {
   static auto name = [](auto &obj) { return &obj.name; };
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
Handle2ConstAuthor
AuthorDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Author
AuthorDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstAuthor
AuthorCreateConst(
   const UTF8Text name,
   const UTF8Text orcid,
   const UTF8Text email,
   ConstHandle2ConstAffiliations affiliations,
   ConstHandle2ConstNote note
) {
   ConstHandle2Author handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      name,
      orcid,
      email,
      detail::tocpp<CPPAffiliations>(affiliations),
      detail::tocpp<CPPNote>(note)
   );
   return handle;
}

// Create, general
Handle2Author
AuthorCreate(
   const UTF8Text name,
   const UTF8Text orcid,
   const UTF8Text email,
   ConstHandle2ConstAffiliations affiliations,
   ConstHandle2ConstNote note
) {
   ConstHandle2Author handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      name,
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
AuthorAssign(ConstHandle2Author This, ConstHandle2ConstAuthor from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
AuthorDelete(ConstHandle2ConstAuthor This)
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
AuthorRead(ConstHandle2Author This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
AuthorWrite(ConstHandle2ConstAuthor This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
AuthorPrint(ConstHandle2ConstAuthor This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
AuthorPrintXML(ConstHandle2ConstAuthor This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
AuthorPrintJSON(ConstHandle2ConstAuthor This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: name
// -----------------------------------------------------------------------------

// Has
int
AuthorNameHas(ConstHandle2ConstAuthor This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"NameHas", This, extract::name);
}

// Get
// Returns by value
UTF8Text
AuthorNameGet(ConstHandle2ConstAuthor This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"NameGet", This, extract::name);
}

// Set
void
AuthorNameSet(ConstHandle2Author This, const UTF8Text name)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"NameSet", This, extract::name, name);
}


// -----------------------------------------------------------------------------
// Metadatum: orcid
// -----------------------------------------------------------------------------

// Has
int
AuthorOrcidHas(ConstHandle2ConstAuthor This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"OrcidHas", This, extract::orcid);
}

// Get
// Returns by value
UTF8Text
AuthorOrcidGet(ConstHandle2ConstAuthor This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"OrcidGet", This, extract::orcid);
}

// Set
void
AuthorOrcidSet(ConstHandle2Author This, const UTF8Text orcid)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"OrcidSet", This, extract::orcid, orcid);
}


// -----------------------------------------------------------------------------
// Metadatum: email
// -----------------------------------------------------------------------------

// Has
int
AuthorEmailHas(ConstHandle2ConstAuthor This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EmailHas", This, extract::email);
}

// Get
// Returns by value
UTF8Text
AuthorEmailGet(ConstHandle2ConstAuthor This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"EmailGet", This, extract::email);
}

// Set
void
AuthorEmailSet(ConstHandle2Author This, const UTF8Text email)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"EmailSet", This, extract::email, email);
}


// -----------------------------------------------------------------------------
// Child: affiliations
// -----------------------------------------------------------------------------

// Has
int
AuthorAffiliationsHas(ConstHandle2ConstAuthor This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AffiliationsHas", This, extract::affiliations);
}

// Get, const
Handle2ConstAffiliations
AuthorAffiliationsGetConst(ConstHandle2ConstAuthor This)
{
   return detail::getField<CPP,Handle2ConstAffiliations>
      (CLASSNAME, CLASSNAME+"AffiliationsGetConst", This, extract::affiliations);
}

// Get, non-const
Handle2Affiliations
AuthorAffiliationsGet(ConstHandle2Author This)
{
   return detail::getField<CPP,Handle2Affiliations>
      (CLASSNAME, CLASSNAME+"AffiliationsGet", This, extract::affiliations);
}

// Set
void
AuthorAffiliationsSet(ConstHandle2Author This, ConstHandle2ConstAffiliations affiliations)
{
   detail::setField<CPP,CPPAffiliations>
      (CLASSNAME, CLASSNAME+"AffiliationsSet", This, extract::affiliations, affiliations);
}


// -----------------------------------------------------------------------------
// Child: note
// -----------------------------------------------------------------------------

// Has
int
AuthorNoteHas(ConstHandle2ConstAuthor This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"NoteHas", This, extract::note);
}

// Get, const
Handle2ConstNote
AuthorNoteGetConst(ConstHandle2ConstAuthor This)
{
   return detail::getField<CPP,Handle2ConstNote>
      (CLASSNAME, CLASSNAME+"NoteGetConst", This, extract::note);
}

// Get, non-const
Handle2Note
AuthorNoteGet(ConstHandle2Author This)
{
   return detail::getField<CPP,Handle2Note>
      (CLASSNAME, CLASSNAME+"NoteGet", This, extract::note);
}

// Set
void
AuthorNoteSet(ConstHandle2Author This, ConstHandle2ConstNote note)
{
   detail::setField<CPP,CPPNote>
      (CLASSNAME, CLASSNAME+"NoteSet", This, extract::note, note);
}