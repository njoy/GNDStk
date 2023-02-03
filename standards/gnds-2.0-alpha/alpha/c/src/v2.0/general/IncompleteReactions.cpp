
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/IncompleteReactions.hpp"
#include "IncompleteReactions.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = IncompleteReactionsClass;
using CPP = multigroup::IncompleteReactions;

static const std::string CLASSNAME = "IncompleteReactions";

namespace extract {
   static auto reaction = [](auto &obj) { return &obj.reaction; };
}

using CPPReaction = general::Reaction;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstIncompleteReactions
IncompleteReactionsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2IncompleteReactions
IncompleteReactionsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstIncompleteReactions
IncompleteReactionsCreateConst(
   ConstHandle2Reaction *const reaction, const size_t reactionSize
) {
   ConstHandle2IncompleteReactions handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPReaction>{}
   );
   for (size_t ReactionN = 0; ReactionN < reactionSize; ++ReactionN)
      IncompleteReactionsReactionAdd(handle, reaction[ReactionN]);
   return handle;
}

// Create, general
Handle2IncompleteReactions
IncompleteReactionsCreate(
   ConstHandle2Reaction *const reaction, const size_t reactionSize
) {
   ConstHandle2IncompleteReactions handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPReaction>{}
   );
   for (size_t ReactionN = 0; ReactionN < reactionSize; ++ReactionN)
      IncompleteReactionsReactionAdd(handle, reaction[ReactionN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
IncompleteReactionsAssign(ConstHandle2IncompleteReactions This, ConstHandle2ConstIncompleteReactions from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
IncompleteReactionsDelete(ConstHandle2ConstIncompleteReactions This)
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
IncompleteReactionsRead(ConstHandle2IncompleteReactions This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
IncompleteReactionsWrite(ConstHandle2ConstIncompleteReactions This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
IncompleteReactionsPrint(ConstHandle2ConstIncompleteReactions This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
IncompleteReactionsPrintXML(ConstHandle2ConstIncompleteReactions This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
IncompleteReactionsPrintJSON(ConstHandle2ConstIncompleteReactions This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: reaction
// -----------------------------------------------------------------------------

// Has
int
IncompleteReactionsReactionHas(ConstHandle2ConstIncompleteReactions This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ReactionHas", This, extract::reaction);
}

// Clear
void
IncompleteReactionsReactionClear(ConstHandle2IncompleteReactions This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"ReactionClear", This, extract::reaction);
}

// Size
size_t
IncompleteReactionsReactionSize(ConstHandle2ConstIncompleteReactions This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"ReactionSize", This, extract::reaction);
}

// Add
void
IncompleteReactionsReactionAdd(ConstHandle2IncompleteReactions This, ConstHandle2ConstReaction reaction)
{
   detail::addToContainer<CPP,CPPReaction>
      (CLASSNAME, CLASSNAME+"ReactionAdd", This, extract::reaction, reaction);
}

// Get, by index \in [0,size), const
Handle2ConstReaction
IncompleteReactionsReactionGetConst(ConstHandle2ConstIncompleteReactions This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstReaction>
      (CLASSNAME, CLASSNAME+"ReactionGetConst", This, extract::reaction, index_);
}

// Get, by index \in [0,size), non-const
Handle2Reaction
IncompleteReactionsReactionGet(ConstHandle2IncompleteReactions This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Reaction>
      (CLASSNAME, CLASSNAME+"ReactionGet", This, extract::reaction, index_);
}

// Set, by index \in [0,size)
void
IncompleteReactionsReactionSet(
   ConstHandle2IncompleteReactions This,
   const size_t index_,
   ConstHandle2ConstReaction reaction
) {
   detail::setByIndex<CPP,CPPReaction>
      (CLASSNAME, CLASSNAME+"ReactionSet", This, extract::reaction, index_, reaction);
}

// Has, by label
int
IncompleteReactionsReactionHasByLabel(
   ConstHandle2ConstIncompleteReactions This,
   const char *const label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ReactionHasByLabel",
       This, extract::reaction, meta::label, label);
}

// Get, by label, const
Handle2ConstReaction
IncompleteReactionsReactionGetByLabelConst(
   ConstHandle2ConstIncompleteReactions This,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2ConstReaction>
      (CLASSNAME, CLASSNAME+"ReactionGetByLabelConst",
       This, extract::reaction, meta::label, label);
}

// Get, by label, non-const
Handle2Reaction
IncompleteReactionsReactionGetByLabel(
   ConstHandle2IncompleteReactions This,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2Reaction>
      (CLASSNAME, CLASSNAME+"ReactionGetByLabel",
       This, extract::reaction, meta::label, label);
}

// Set, by label
void
IncompleteReactionsReactionSetByLabel(
   ConstHandle2IncompleteReactions This,
   const char *const label,
   ConstHandle2ConstReaction reaction
) {
   detail::setByMetadatum<CPP,CPPReaction>
      (CLASSNAME, CLASSNAME+"ReactionSetByLabel",
       This, extract::reaction, meta::label, label, reaction);
}

// Has, by ENDF_MT
int
IncompleteReactionsReactionHasByENDFMT(
   ConstHandle2ConstIncompleteReactions This,
   const int ENDF_MT
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ReactionHasByENDFMT",
       This, extract::reaction, meta::ENDF_MT, ENDF_MT);
}

// Get, by ENDF_MT, const
Handle2ConstReaction
IncompleteReactionsReactionGetByENDFMTConst(
   ConstHandle2ConstIncompleteReactions This,
   const int ENDF_MT
) {
   return detail::getByMetadatum<CPP,Handle2ConstReaction>
      (CLASSNAME, CLASSNAME+"ReactionGetByENDFMTConst",
       This, extract::reaction, meta::ENDF_MT, ENDF_MT);
}

// Get, by ENDF_MT, non-const
Handle2Reaction
IncompleteReactionsReactionGetByENDFMT(
   ConstHandle2IncompleteReactions This,
   const int ENDF_MT
) {
   return detail::getByMetadatum<CPP,Handle2Reaction>
      (CLASSNAME, CLASSNAME+"ReactionGetByENDFMT",
       This, extract::reaction, meta::ENDF_MT, ENDF_MT);
}

// Set, by ENDF_MT
void
IncompleteReactionsReactionSetByENDFMT(
   ConstHandle2IncompleteReactions This,
   const int ENDF_MT,
   ConstHandle2ConstReaction reaction
) {
   detail::setByMetadatum<CPP,CPPReaction>
      (CLASSNAME, CLASSNAME+"ReactionSetByENDFMT",
       This, extract::reaction, meta::ENDF_MT, ENDF_MT, reaction);
}

// Has, by fissionGenre
int
IncompleteReactionsReactionHasByFissionGenre(
   ConstHandle2ConstIncompleteReactions This,
   const char *const fissionGenre
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ReactionHasByFissionGenre",
       This, extract::reaction, meta::fissionGenre, fissionGenre);
}

// Get, by fissionGenre, const
Handle2ConstReaction
IncompleteReactionsReactionGetByFissionGenreConst(
   ConstHandle2ConstIncompleteReactions This,
   const char *const fissionGenre
) {
   return detail::getByMetadatum<CPP,Handle2ConstReaction>
      (CLASSNAME, CLASSNAME+"ReactionGetByFissionGenreConst",
       This, extract::reaction, meta::fissionGenre, fissionGenre);
}

// Get, by fissionGenre, non-const
Handle2Reaction
IncompleteReactionsReactionGetByFissionGenre(
   ConstHandle2IncompleteReactions This,
   const char *const fissionGenre
) {
   return detail::getByMetadatum<CPP,Handle2Reaction>
      (CLASSNAME, CLASSNAME+"ReactionGetByFissionGenre",
       This, extract::reaction, meta::fissionGenre, fissionGenre);
}

// Set, by fissionGenre
void
IncompleteReactionsReactionSetByFissionGenre(
   ConstHandle2IncompleteReactions This,
   const char *const fissionGenre,
   ConstHandle2ConstReaction reaction
) {
   detail::setByMetadatum<CPP,CPPReaction>
      (CLASSNAME, CLASSNAME+"ReactionSetByFissionGenre",
       This, extract::reaction, meta::fissionGenre, fissionGenre, reaction);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/IncompleteReactions/src/custom.cpp"
