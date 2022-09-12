
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/documentation/Contributors.hpp"
#include "Contributors.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = ContributorsClass;
using CPP = multigroup::Contributors;

static const std::string CLASSNAME = "Contributors";

namespace extract {
   static auto contributor = [](auto &obj) { return &obj.contributor; };
}

using CPPAuthor = documentation::Author;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstContributors
ContributorsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Contributors
ContributorsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstContributors
ContributorsCreateConst(
   ConstHandle2Author *const contributor, const size_t contributorSize
) {
   ConstHandle2Contributors handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPAuthor>{}
   );
   for (size_t AuthorN = 0; AuthorN < contributorSize; ++AuthorN)
      ContributorsAuthorAdd(handle, contributor[AuthorN]);
   return handle;
}

// Create, general
Handle2Contributors
ContributorsCreate(
   ConstHandle2Author *const contributor, const size_t contributorSize
) {
   ConstHandle2Contributors handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPAuthor>{}
   );
   for (size_t AuthorN = 0; AuthorN < contributorSize; ++AuthorN)
      ContributorsAuthorAdd(handle, contributor[AuthorN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ContributorsAssign(ConstHandle2Contributors This, ConstHandle2ConstContributors from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ContributorsDelete(ConstHandle2ConstContributors This)
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
ContributorsRead(ConstHandle2Contributors This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ContributorsWrite(ConstHandle2ConstContributors This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
ContributorsPrint(ConstHandle2ConstContributors This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
ContributorsPrintXML(ConstHandle2ConstContributors This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
ContributorsPrintJSON(ConstHandle2ConstContributors This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: contributor
// -----------------------------------------------------------------------------

// Has
int
ContributorsAuthorHas(ConstHandle2ConstContributors This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AuthorHas", This, extract::contributor);
}

// Clear
void
ContributorsAuthorClear(ConstHandle2Contributors This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"AuthorClear", This, extract::contributor);
}

// Size
size_t
ContributorsAuthorSize(ConstHandle2ConstContributors This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"AuthorSize", This, extract::contributor);
}

// Add
void
ContributorsAuthorAdd(ConstHandle2Contributors This, ConstHandle2ConstAuthor contributor)
{
   detail::addToContainer<CPP,CPPAuthor>
      (CLASSNAME, CLASSNAME+"AuthorAdd", This, extract::contributor, contributor);
}

// Get, by index \in [0,size), const
Handle2ConstAuthor
ContributorsAuthorGetConst(ConstHandle2ConstContributors This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstAuthor>
      (CLASSNAME, CLASSNAME+"AuthorGetConst", This, extract::contributor, index_);
}

// Get, by index \in [0,size), non-const
Handle2Author
ContributorsAuthorGet(ConstHandle2Contributors This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Author>
      (CLASSNAME, CLASSNAME+"AuthorGet", This, extract::contributor, index_);
}

// Set, by index \in [0,size)
void
ContributorsAuthorSet(
   ConstHandle2Contributors This,
   const size_t index_,
   ConstHandle2ConstAuthor contributor
) {
   detail::setByIndex<CPP,CPPAuthor>
      (CLASSNAME, CLASSNAME+"AuthorSet", This, extract::contributor, index_, contributor);
}

// Has, by name
int
ContributorsAuthorHasByName(
   ConstHandle2ConstContributors This,
   const UTF8Text name
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"AuthorHasByName",
       This, extract::contributor, meta::name, name);
}

// Get, by name, const
Handle2ConstAuthor
ContributorsAuthorGetByNameConst(
   ConstHandle2ConstContributors This,
   const UTF8Text name
) {
   return detail::getByMetadatum<CPP,Handle2ConstAuthor>
      (CLASSNAME, CLASSNAME+"AuthorGetByNameConst",
       This, extract::contributor, meta::name, name);
}

// Get, by name, non-const
Handle2Author
ContributorsAuthorGetByName(
   ConstHandle2Contributors This,
   const UTF8Text name
) {
   return detail::getByMetadatum<CPP,Handle2Author>
      (CLASSNAME, CLASSNAME+"AuthorGetByName",
       This, extract::contributor, meta::name, name);
}

// Set, by name
void
ContributorsAuthorSetByName(
   ConstHandle2Contributors This,
   const UTF8Text name,
   ConstHandle2ConstAuthor contributor
) {
   detail::setByMetadatum<CPP,CPPAuthor>
      (CLASSNAME, CLASSNAME+"AuthorSetByName",
       This, extract::contributor, meta::name, name, contributor);
}

// Has, by orcid
int
ContributorsAuthorHasByOrcid(
   ConstHandle2ConstContributors This,
   const UTF8Text orcid
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"AuthorHasByOrcid",
       This, extract::contributor, meta::orcid, orcid);
}

// Get, by orcid, const
Handle2ConstAuthor
ContributorsAuthorGetByOrcidConst(
   ConstHandle2ConstContributors This,
   const UTF8Text orcid
) {
   return detail::getByMetadatum<CPP,Handle2ConstAuthor>
      (CLASSNAME, CLASSNAME+"AuthorGetByOrcidConst",
       This, extract::contributor, meta::orcid, orcid);
}

// Get, by orcid, non-const
Handle2Author
ContributorsAuthorGetByOrcid(
   ConstHandle2Contributors This,
   const UTF8Text orcid
) {
   return detail::getByMetadatum<CPP,Handle2Author>
      (CLASSNAME, CLASSNAME+"AuthorGetByOrcid",
       This, extract::contributor, meta::orcid, orcid);
}

// Set, by orcid
void
ContributorsAuthorSetByOrcid(
   ConstHandle2Contributors This,
   const UTF8Text orcid,
   ConstHandle2ConstAuthor contributor
) {
   detail::setByMetadatum<CPP,CPPAuthor>
      (CLASSNAME, CLASSNAME+"AuthorSetByOrcid",
       This, extract::contributor, meta::orcid, orcid, contributor);
}

// Has, by email
int
ContributorsAuthorHasByEmail(
   ConstHandle2ConstContributors This,
   const UTF8Text email
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"AuthorHasByEmail",
       This, extract::contributor, meta::email, email);
}

// Get, by email, const
Handle2ConstAuthor
ContributorsAuthorGetByEmailConst(
   ConstHandle2ConstContributors This,
   const UTF8Text email
) {
   return detail::getByMetadatum<CPP,Handle2ConstAuthor>
      (CLASSNAME, CLASSNAME+"AuthorGetByEmailConst",
       This, extract::contributor, meta::email, email);
}

// Get, by email, non-const
Handle2Author
ContributorsAuthorGetByEmail(
   ConstHandle2Contributors This,
   const UTF8Text email
) {
   return detail::getByMetadatum<CPP,Handle2Author>
      (CLASSNAME, CLASSNAME+"AuthorGetByEmail",
       This, extract::contributor, meta::email, email);
}

// Set, by email
void
ContributorsAuthorSetByEmail(
   ConstHandle2Contributors This,
   const UTF8Text email,
   ConstHandle2ConstAuthor contributor
) {
   detail::setByMetadatum<CPP,CPPAuthor>
      (CLASSNAME, CLASSNAME+"AuthorSetByEmail",
       This, extract::contributor, meta::email, email, contributor);
}