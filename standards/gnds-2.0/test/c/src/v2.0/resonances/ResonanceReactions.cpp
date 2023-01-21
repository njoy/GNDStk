
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/resonances/ResonanceReactions.hpp"
#include "ResonanceReactions.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = ResonanceReactionsClass;
using CPP = multigroup::ResonanceReactions;

static const std::string CLASSNAME = "ResonanceReactions";

namespace extract {
   static auto resonanceReaction = [](auto &obj) { return &obj.resonanceReaction; };
}

using CPPResonanceReaction = resonances::ResonanceReaction;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstResonanceReactions
ResonanceReactionsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2ResonanceReactions
ResonanceReactionsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstResonanceReactions
ResonanceReactionsCreateConst(
   ConstHandle2ResonanceReaction *const resonanceReaction, const size_t resonanceReactionSize
) {
   ConstHandle2ResonanceReactions handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPResonanceReaction>{}
   );
   for (size_t ResonanceReactionN = 0; ResonanceReactionN < resonanceReactionSize; ++ResonanceReactionN)
      ResonanceReactionsResonanceReactionAdd(handle, resonanceReaction[ResonanceReactionN]);
   return handle;
}

// Create, general
Handle2ResonanceReactions
ResonanceReactionsCreate(
   ConstHandle2ResonanceReaction *const resonanceReaction, const size_t resonanceReactionSize
) {
   ConstHandle2ResonanceReactions handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPResonanceReaction>{}
   );
   for (size_t ResonanceReactionN = 0; ResonanceReactionN < resonanceReactionSize; ++ResonanceReactionN)
      ResonanceReactionsResonanceReactionAdd(handle, resonanceReaction[ResonanceReactionN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ResonanceReactionsAssign(ConstHandle2ResonanceReactions This, ConstHandle2ConstResonanceReactions from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ResonanceReactionsDelete(ConstHandle2ConstResonanceReactions This)
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
ResonanceReactionsRead(ConstHandle2ResonanceReactions This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ResonanceReactionsWrite(ConstHandle2ConstResonanceReactions This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
ResonanceReactionsPrint(ConstHandle2ConstResonanceReactions This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
ResonanceReactionsPrintXML(ConstHandle2ConstResonanceReactions This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
ResonanceReactionsPrintJSON(ConstHandle2ConstResonanceReactions This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: resonanceReaction
// -----------------------------------------------------------------------------

// Has
int
ResonanceReactionsResonanceReactionHas(ConstHandle2ConstResonanceReactions This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ResonanceReactionHas", This, extract::resonanceReaction);
}

// Clear
void
ResonanceReactionsResonanceReactionClear(ConstHandle2ResonanceReactions This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"ResonanceReactionClear", This, extract::resonanceReaction);
}

// Size
size_t
ResonanceReactionsResonanceReactionSize(ConstHandle2ConstResonanceReactions This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"ResonanceReactionSize", This, extract::resonanceReaction);
}

// Add
void
ResonanceReactionsResonanceReactionAdd(ConstHandle2ResonanceReactions This, ConstHandle2ConstResonanceReaction resonanceReaction)
{
   detail::addToContainer<CPP,CPPResonanceReaction>
      (CLASSNAME, CLASSNAME+"ResonanceReactionAdd", This, extract::resonanceReaction, resonanceReaction);
}

// Get, by index \in [0,size), const
Handle2ConstResonanceReaction
ResonanceReactionsResonanceReactionGetConst(ConstHandle2ConstResonanceReactions This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstResonanceReaction>
      (CLASSNAME, CLASSNAME+"ResonanceReactionGetConst", This, extract::resonanceReaction, index_);
}

// Get, by index \in [0,size), non-const
Handle2ResonanceReaction
ResonanceReactionsResonanceReactionGet(ConstHandle2ResonanceReactions This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ResonanceReaction>
      (CLASSNAME, CLASSNAME+"ResonanceReactionGet", This, extract::resonanceReaction, index_);
}

// Set, by index \in [0,size)
void
ResonanceReactionsResonanceReactionSet(
   ConstHandle2ResonanceReactions This,
   const size_t index_,
   ConstHandle2ConstResonanceReaction resonanceReaction
) {
   detail::setByIndex<CPP,CPPResonanceReaction>
      (CLASSNAME, CLASSNAME+"ResonanceReactionSet", This, extract::resonanceReaction, index_, resonanceReaction);
}

// Has, by label
int
ResonanceReactionsResonanceReactionHasByLabel(
   ConstHandle2ConstResonanceReactions This,
   const XMLName label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ResonanceReactionHasByLabel",
       This, extract::resonanceReaction, meta::label, label);
}

// Get, by label, const
Handle2ConstResonanceReaction
ResonanceReactionsResonanceReactionGetByLabelConst(
   ConstHandle2ConstResonanceReactions This,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2ConstResonanceReaction>
      (CLASSNAME, CLASSNAME+"ResonanceReactionGetByLabelConst",
       This, extract::resonanceReaction, meta::label, label);
}

// Get, by label, non-const
Handle2ResonanceReaction
ResonanceReactionsResonanceReactionGetByLabel(
   ConstHandle2ResonanceReactions This,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2ResonanceReaction>
      (CLASSNAME, CLASSNAME+"ResonanceReactionGetByLabel",
       This, extract::resonanceReaction, meta::label, label);
}

// Set, by label
void
ResonanceReactionsResonanceReactionSetByLabel(
   ConstHandle2ResonanceReactions This,
   const XMLName label,
   ConstHandle2ConstResonanceReaction resonanceReaction
) {
   detail::setByMetadatum<CPP,CPPResonanceReaction>
      (CLASSNAME, CLASSNAME+"ResonanceReactionSetByLabel",
       This, extract::resonanceReaction, meta::label, label, resonanceReaction);
}

// Has, by ejectile
int
ResonanceReactionsResonanceReactionHasByEjectile(
   ConstHandle2ConstResonanceReactions This,
   const XMLName ejectile
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ResonanceReactionHasByEjectile",
       This, extract::resonanceReaction, meta::ejectile, ejectile);
}

// Get, by ejectile, const
Handle2ConstResonanceReaction
ResonanceReactionsResonanceReactionGetByEjectileConst(
   ConstHandle2ConstResonanceReactions This,
   const XMLName ejectile
) {
   return detail::getByMetadatum<CPP,Handle2ConstResonanceReaction>
      (CLASSNAME, CLASSNAME+"ResonanceReactionGetByEjectileConst",
       This, extract::resonanceReaction, meta::ejectile, ejectile);
}

// Get, by ejectile, non-const
Handle2ResonanceReaction
ResonanceReactionsResonanceReactionGetByEjectile(
   ConstHandle2ResonanceReactions This,
   const XMLName ejectile
) {
   return detail::getByMetadatum<CPP,Handle2ResonanceReaction>
      (CLASSNAME, CLASSNAME+"ResonanceReactionGetByEjectile",
       This, extract::resonanceReaction, meta::ejectile, ejectile);
}

// Set, by ejectile
void
ResonanceReactionsResonanceReactionSetByEjectile(
   ConstHandle2ResonanceReactions This,
   const XMLName ejectile,
   ConstHandle2ConstResonanceReaction resonanceReaction
) {
   detail::setByMetadatum<CPP,CPPResonanceReaction>
      (CLASSNAME, CLASSNAME+"ResonanceReactionSetByEjectile",
       This, extract::resonanceReaction, meta::ejectile, ejectile, resonanceReaction);
}

// Has, by boundaryConditionValue
int
ResonanceReactionsResonanceReactionHasByBoundaryConditionValue(
   ConstHandle2ConstResonanceReactions This,
   const Float64 boundaryConditionValue
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ResonanceReactionHasByBoundaryConditionValue",
       This, extract::resonanceReaction, meta::boundaryConditionValue, boundaryConditionValue);
}

// Get, by boundaryConditionValue, const
Handle2ConstResonanceReaction
ResonanceReactionsResonanceReactionGetByBoundaryConditionValueConst(
   ConstHandle2ConstResonanceReactions This,
   const Float64 boundaryConditionValue
) {
   return detail::getByMetadatum<CPP,Handle2ConstResonanceReaction>
      (CLASSNAME, CLASSNAME+"ResonanceReactionGetByBoundaryConditionValueConst",
       This, extract::resonanceReaction, meta::boundaryConditionValue, boundaryConditionValue);
}

// Get, by boundaryConditionValue, non-const
Handle2ResonanceReaction
ResonanceReactionsResonanceReactionGetByBoundaryConditionValue(
   ConstHandle2ResonanceReactions This,
   const Float64 boundaryConditionValue
) {
   return detail::getByMetadatum<CPP,Handle2ResonanceReaction>
      (CLASSNAME, CLASSNAME+"ResonanceReactionGetByBoundaryConditionValue",
       This, extract::resonanceReaction, meta::boundaryConditionValue, boundaryConditionValue);
}

// Set, by boundaryConditionValue
void
ResonanceReactionsResonanceReactionSetByBoundaryConditionValue(
   ConstHandle2ResonanceReactions This,
   const Float64 boundaryConditionValue,
   ConstHandle2ConstResonanceReaction resonanceReaction
) {
   detail::setByMetadatum<CPP,CPPResonanceReaction>
      (CLASSNAME, CLASSNAME+"ResonanceReactionSetByBoundaryConditionValue",
       This, extract::resonanceReaction, meta::boundaryConditionValue, boundaryConditionValue, resonanceReaction);
}

// Has, by eliminated
int
ResonanceReactionsResonanceReactionHasByEliminated(
   ConstHandle2ConstResonanceReactions This,
   const bool eliminated
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ResonanceReactionHasByEliminated",
       This, extract::resonanceReaction, meta::eliminated, eliminated);
}

// Get, by eliminated, const
Handle2ConstResonanceReaction
ResonanceReactionsResonanceReactionGetByEliminatedConst(
   ConstHandle2ConstResonanceReactions This,
   const bool eliminated
) {
   return detail::getByMetadatum<CPP,Handle2ConstResonanceReaction>
      (CLASSNAME, CLASSNAME+"ResonanceReactionGetByEliminatedConst",
       This, extract::resonanceReaction, meta::eliminated, eliminated);
}

// Get, by eliminated, non-const
Handle2ResonanceReaction
ResonanceReactionsResonanceReactionGetByEliminated(
   ConstHandle2ResonanceReactions This,
   const bool eliminated
) {
   return detail::getByMetadatum<CPP,Handle2ResonanceReaction>
      (CLASSNAME, CLASSNAME+"ResonanceReactionGetByEliminated",
       This, extract::resonanceReaction, meta::eliminated, eliminated);
}

// Set, by eliminated
void
ResonanceReactionsResonanceReactionSetByEliminated(
   ConstHandle2ResonanceReactions This,
   const bool eliminated,
   ConstHandle2ConstResonanceReaction resonanceReaction
) {
   detail::setByMetadatum<CPP,CPPResonanceReaction>
      (CLASSNAME, CLASSNAME+"ResonanceReactionSetByEliminated",
       This, extract::resonanceReaction, meta::eliminated, eliminated, resonanceReaction);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/resonances/ResonanceReactions/src/custom.cpp"
