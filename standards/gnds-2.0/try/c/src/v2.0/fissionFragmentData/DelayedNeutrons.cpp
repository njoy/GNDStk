
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/fissionFragmentData/DelayedNeutrons.hpp"
#include "DelayedNeutrons.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = DelayedNeutronsClass;
using CPP = multigroup::DelayedNeutrons;

static const std::string CLASSNAME = "DelayedNeutrons";

namespace extract {
   static auto delayedNeutron = [](auto &obj) { return &obj.delayedNeutron; };
}

using CPPDelayedNeutron = fissionFragmentData::DelayedNeutron;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstDelayedNeutrons
DelayedNeutronsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2DelayedNeutrons
DelayedNeutronsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstDelayedNeutrons
DelayedNeutronsCreateConst(
   ConstHandle2DelayedNeutron *const delayedNeutron, const size_t delayedNeutronSize
) {
   ConstHandle2DelayedNeutrons handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPDelayedNeutron>{}
   );
   for (size_t DelayedNeutronN = 0; DelayedNeutronN < delayedNeutronSize; ++DelayedNeutronN)
      DelayedNeutronsDelayedNeutronAdd(handle, delayedNeutron[DelayedNeutronN]);
   return handle;
}

// Create, general
Handle2DelayedNeutrons
DelayedNeutronsCreate(
   ConstHandle2DelayedNeutron *const delayedNeutron, const size_t delayedNeutronSize
) {
   ConstHandle2DelayedNeutrons handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPDelayedNeutron>{}
   );
   for (size_t DelayedNeutronN = 0; DelayedNeutronN < delayedNeutronSize; ++DelayedNeutronN)
      DelayedNeutronsDelayedNeutronAdd(handle, delayedNeutron[DelayedNeutronN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
DelayedNeutronsAssign(ConstHandle2DelayedNeutrons This, ConstHandle2ConstDelayedNeutrons from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
DelayedNeutronsDelete(ConstHandle2ConstDelayedNeutrons This)
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
DelayedNeutronsRead(ConstHandle2DelayedNeutrons This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
DelayedNeutronsWrite(ConstHandle2ConstDelayedNeutrons This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
DelayedNeutronsPrint(ConstHandle2ConstDelayedNeutrons This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
DelayedNeutronsPrintXML(ConstHandle2ConstDelayedNeutrons This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
DelayedNeutronsPrintJSON(ConstHandle2ConstDelayedNeutrons This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: delayedNeutron
// -----------------------------------------------------------------------------

// Has
int
DelayedNeutronsDelayedNeutronHas(ConstHandle2ConstDelayedNeutrons This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DelayedNeutronHas", This, extract::delayedNeutron);
}

// Clear
void
DelayedNeutronsDelayedNeutronClear(ConstHandle2DelayedNeutrons This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"DelayedNeutronClear", This, extract::delayedNeutron);
}

// Size
size_t
DelayedNeutronsDelayedNeutronSize(ConstHandle2ConstDelayedNeutrons This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"DelayedNeutronSize", This, extract::delayedNeutron);
}

// Add
void
DelayedNeutronsDelayedNeutronAdd(ConstHandle2DelayedNeutrons This, ConstHandle2ConstDelayedNeutron delayedNeutron)
{
   detail::addToContainer<CPP,CPPDelayedNeutron>
      (CLASSNAME, CLASSNAME+"DelayedNeutronAdd", This, extract::delayedNeutron, delayedNeutron);
}

// Get, by index \in [0,size), const
Handle2ConstDelayedNeutron
DelayedNeutronsDelayedNeutronGetConst(ConstHandle2ConstDelayedNeutrons This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstDelayedNeutron>
      (CLASSNAME, CLASSNAME+"DelayedNeutronGetConst", This, extract::delayedNeutron, index_);
}

// Get, by index \in [0,size), non-const
Handle2DelayedNeutron
DelayedNeutronsDelayedNeutronGet(ConstHandle2DelayedNeutrons This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2DelayedNeutron>
      (CLASSNAME, CLASSNAME+"DelayedNeutronGet", This, extract::delayedNeutron, index_);
}

// Set, by index \in [0,size)
void
DelayedNeutronsDelayedNeutronSet(
   ConstHandle2DelayedNeutrons This,
   const size_t index_,
   ConstHandle2ConstDelayedNeutron delayedNeutron
) {
   detail::setByIndex<CPP,CPPDelayedNeutron>
      (CLASSNAME, CLASSNAME+"DelayedNeutronSet", This, extract::delayedNeutron, index_, delayedNeutron);
}

// Has, by label
int
DelayedNeutronsDelayedNeutronHasByLabel(
   ConstHandle2ConstDelayedNeutrons This,
   const XMLName label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"DelayedNeutronHasByLabel",
       This, extract::delayedNeutron, meta::label, label);
}

// Get, by label, const
Handle2ConstDelayedNeutron
DelayedNeutronsDelayedNeutronGetByLabelConst(
   ConstHandle2ConstDelayedNeutrons This,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2ConstDelayedNeutron>
      (CLASSNAME, CLASSNAME+"DelayedNeutronGetByLabelConst",
       This, extract::delayedNeutron, meta::label, label);
}

// Get, by label, non-const
Handle2DelayedNeutron
DelayedNeutronsDelayedNeutronGetByLabel(
   ConstHandle2DelayedNeutrons This,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2DelayedNeutron>
      (CLASSNAME, CLASSNAME+"DelayedNeutronGetByLabel",
       This, extract::delayedNeutron, meta::label, label);
}

// Set, by label
void
DelayedNeutronsDelayedNeutronSetByLabel(
   ConstHandle2DelayedNeutrons This,
   const XMLName label,
   ConstHandle2ConstDelayedNeutron delayedNeutron
) {
   detail::setByMetadatum<CPP,CPPDelayedNeutron>
      (CLASSNAME, CLASSNAME+"DelayedNeutronSetByLabel",
       This, extract::delayedNeutron, meta::label, label, delayedNeutron);
}