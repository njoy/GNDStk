
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/pops/DecayPath.hpp"
#include "DecayPath.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = DecayPathClass;
using CPP = multigroup::DecayPath;

static const std::string CLASSNAME = "DecayPath";

namespace extract {
   static auto decay = [](auto &obj) { return &obj.decay; };
}

using CPPDecay = pops::Decay;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstDecayPath
DecayPathDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2DecayPath
DecayPathDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstDecayPath
DecayPathCreateConst(
   ConstHandle2Decay *const decay, const size_t decaySize
) {
   ConstHandle2DecayPath handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPDecay>{}
   );
   for (size_t DecayN = 0; DecayN < decaySize; ++DecayN)
      DecayPathDecayAdd(handle, decay[DecayN]);
   return handle;
}

// Create, general
Handle2DecayPath
DecayPathCreate(
   ConstHandle2Decay *const decay, const size_t decaySize
) {
   ConstHandle2DecayPath handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPDecay>{}
   );
   for (size_t DecayN = 0; DecayN < decaySize; ++DecayN)
      DecayPathDecayAdd(handle, decay[DecayN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
DecayPathAssign(ConstHandle2DecayPath This, ConstHandle2ConstDecayPath from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
DecayPathDelete(ConstHandle2ConstDecayPath This)
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
DecayPathRead(ConstHandle2DecayPath This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
DecayPathWrite(ConstHandle2ConstDecayPath This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
DecayPathPrint(ConstHandle2ConstDecayPath This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
DecayPathPrintXML(ConstHandle2ConstDecayPath This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
DecayPathPrintJSON(ConstHandle2ConstDecayPath This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: decay
// -----------------------------------------------------------------------------

// Has
int
DecayPathDecayHas(ConstHandle2ConstDecayPath This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DecayHas", This, extract::decay);
}

// Clear
void
DecayPathDecayClear(ConstHandle2DecayPath This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"DecayClear", This, extract::decay);
}

// Size
size_t
DecayPathDecaySize(ConstHandle2ConstDecayPath This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"DecaySize", This, extract::decay);
}

// Add
void
DecayPathDecayAdd(ConstHandle2DecayPath This, ConstHandle2ConstDecay decay)
{
   detail::addToContainer<CPP,CPPDecay>
      (CLASSNAME, CLASSNAME+"DecayAdd", This, extract::decay, decay);
}

// Get, by index \in [0,size), const
Handle2ConstDecay
DecayPathDecayGetConst(ConstHandle2ConstDecayPath This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstDecay>
      (CLASSNAME, CLASSNAME+"DecayGetConst", This, extract::decay, index_);
}

// Get, by index \in [0,size), non-const
Handle2Decay
DecayPathDecayGet(ConstHandle2DecayPath This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Decay>
      (CLASSNAME, CLASSNAME+"DecayGet", This, extract::decay, index_);
}

// Set, by index \in [0,size)
void
DecayPathDecaySet(
   ConstHandle2DecayPath This,
   const size_t index_,
   ConstHandle2ConstDecay decay
) {
   detail::setByIndex<CPP,CPPDecay>
      (CLASSNAME, CLASSNAME+"DecaySet", This, extract::decay, index_, decay);
}

// Has, by index
int
DecayPathDecayHasByIndex(
   ConstHandle2ConstDecayPath This,
   const Integer32 index
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"DecayHasByIndex",
       This, extract::decay, meta::index, index);
}

// Get, by index, const
Handle2ConstDecay
DecayPathDecayGetByIndexConst(
   ConstHandle2ConstDecayPath This,
   const Integer32 index
) {
   return detail::getByMetadatum<CPP,Handle2ConstDecay>
      (CLASSNAME, CLASSNAME+"DecayGetByIndexConst",
       This, extract::decay, meta::index, index);
}

// Get, by index, non-const
Handle2Decay
DecayPathDecayGetByIndex(
   ConstHandle2DecayPath This,
   const Integer32 index
) {
   return detail::getByMetadatum<CPP,Handle2Decay>
      (CLASSNAME, CLASSNAME+"DecayGetByIndex",
       This, extract::decay, meta::index, index);
}

// Set, by index
void
DecayPathDecaySetByIndex(
   ConstHandle2DecayPath This,
   const Integer32 index,
   ConstHandle2ConstDecay decay
) {
   detail::setByMetadatum<CPP,CPPDecay>
      (CLASSNAME, CLASSNAME+"DecaySetByIndex",
       This, extract::decay, meta::index, index, decay);
}

// Has, by mode
int
DecayPathDecayHasByMode(
   ConstHandle2ConstDecayPath This,
   const enums::DecayType mode
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"DecayHasByMode",
       This, extract::decay, meta::mode, mode);
}

// Get, by mode, const
Handle2ConstDecay
DecayPathDecayGetByModeConst(
   ConstHandle2ConstDecayPath This,
   const enums::DecayType mode
) {
   return detail::getByMetadatum<CPP,Handle2ConstDecay>
      (CLASSNAME, CLASSNAME+"DecayGetByModeConst",
       This, extract::decay, meta::mode, mode);
}

// Get, by mode, non-const
Handle2Decay
DecayPathDecayGetByMode(
   ConstHandle2DecayPath This,
   const enums::DecayType mode
) {
   return detail::getByMetadatum<CPP,Handle2Decay>
      (CLASSNAME, CLASSNAME+"DecayGetByMode",
       This, extract::decay, meta::mode, mode);
}

// Set, by mode
void
DecayPathDecaySetByMode(
   ConstHandle2DecayPath This,
   const enums::DecayType mode,
   ConstHandle2ConstDecay decay
) {
   detail::setByMetadatum<CPP,CPPDecay>
      (CLASSNAME, CLASSNAME+"DecaySetByMode",
       This, extract::decay, meta::mode, mode, decay);
}

// Has, by complete
int
DecayPathDecayHasByComplete(
   ConstHandle2ConstDecayPath This,
   const bool complete
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"DecayHasByComplete",
       This, extract::decay, meta::complete, complete);
}

// Get, by complete, const
Handle2ConstDecay
DecayPathDecayGetByCompleteConst(
   ConstHandle2ConstDecayPath This,
   const bool complete
) {
   return detail::getByMetadatum<CPP,Handle2ConstDecay>
      (CLASSNAME, CLASSNAME+"DecayGetByCompleteConst",
       This, extract::decay, meta::complete, complete);
}

// Get, by complete, non-const
Handle2Decay
DecayPathDecayGetByComplete(
   ConstHandle2DecayPath This,
   const bool complete
) {
   return detail::getByMetadatum<CPP,Handle2Decay>
      (CLASSNAME, CLASSNAME+"DecayGetByComplete",
       This, extract::decay, meta::complete, complete);
}

// Set, by complete
void
DecayPathDecaySetByComplete(
   ConstHandle2DecayPath This,
   const bool complete,
   ConstHandle2ConstDecay decay
) {
   detail::setByMetadatum<CPP,CPPDecay>
      (CLASSNAME, CLASSNAME+"DecaySetByComplete",
       This, extract::decay, meta::complete, complete, decay);
}