
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/pops/PhotonEmissionProbabilities.hpp"
#include "PhotonEmissionProbabilities.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = PhotonEmissionProbabilitiesClass;
using CPP = multigroup::PhotonEmissionProbabilities;

static const std::string CLASSNAME = "PhotonEmissionProbabilities";

namespace extract {
   static auto shell = [](auto &obj) { return &obj.shell; };
}

using CPPShell = pops::Shell;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstPhotonEmissionProbabilities
PhotonEmissionProbabilitiesDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2PhotonEmissionProbabilities
PhotonEmissionProbabilitiesDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstPhotonEmissionProbabilities
PhotonEmissionProbabilitiesCreateConst(
   ConstHandle2Shell *const shell, const size_t shellSize
) {
   ConstHandle2PhotonEmissionProbabilities handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPShell>{}
   );
   for (size_t ShellN = 0; ShellN < shellSize; ++ShellN)
      PhotonEmissionProbabilitiesShellAdd(handle, shell[ShellN]);
   return handle;
}

// Create, general
Handle2PhotonEmissionProbabilities
PhotonEmissionProbabilitiesCreate(
   ConstHandle2Shell *const shell, const size_t shellSize
) {
   ConstHandle2PhotonEmissionProbabilities handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPShell>{}
   );
   for (size_t ShellN = 0; ShellN < shellSize; ++ShellN)
      PhotonEmissionProbabilitiesShellAdd(handle, shell[ShellN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
PhotonEmissionProbabilitiesAssign(ConstHandle2PhotonEmissionProbabilities This, ConstHandle2ConstPhotonEmissionProbabilities from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
PhotonEmissionProbabilitiesDelete(ConstHandle2ConstPhotonEmissionProbabilities This)
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
PhotonEmissionProbabilitiesRead(ConstHandle2PhotonEmissionProbabilities This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
PhotonEmissionProbabilitiesWrite(ConstHandle2ConstPhotonEmissionProbabilities This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
PhotonEmissionProbabilitiesPrint(ConstHandle2ConstPhotonEmissionProbabilities This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
PhotonEmissionProbabilitiesPrintXML(ConstHandle2ConstPhotonEmissionProbabilities This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
PhotonEmissionProbabilitiesPrintJSON(ConstHandle2ConstPhotonEmissionProbabilities This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: shell
// -----------------------------------------------------------------------------

// Has
int
PhotonEmissionProbabilitiesShellHas(ConstHandle2ConstPhotonEmissionProbabilities This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ShellHas", This, extract::shell);
}

// Clear
void
PhotonEmissionProbabilitiesShellClear(ConstHandle2PhotonEmissionProbabilities This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"ShellClear", This, extract::shell);
}

// Size
size_t
PhotonEmissionProbabilitiesShellSize(ConstHandle2ConstPhotonEmissionProbabilities This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"ShellSize", This, extract::shell);
}

// Add
void
PhotonEmissionProbabilitiesShellAdd(ConstHandle2PhotonEmissionProbabilities This, ConstHandle2ConstShell shell)
{
   detail::addToContainer<CPP,CPPShell>
      (CLASSNAME, CLASSNAME+"ShellAdd", This, extract::shell, shell);
}

// Get, by index \in [0,size), const
Handle2ConstShell
PhotonEmissionProbabilitiesShellGetConst(ConstHandle2ConstPhotonEmissionProbabilities This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstShell>
      (CLASSNAME, CLASSNAME+"ShellGetConst", This, extract::shell, index_);
}

// Get, by index \in [0,size), non-const
Handle2Shell
PhotonEmissionProbabilitiesShellGet(ConstHandle2PhotonEmissionProbabilities This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Shell>
      (CLASSNAME, CLASSNAME+"ShellGet", This, extract::shell, index_);
}

// Set, by index \in [0,size)
void
PhotonEmissionProbabilitiesShellSet(
   ConstHandle2PhotonEmissionProbabilities This,
   const size_t index_,
   ConstHandle2ConstShell shell
) {
   detail::setByIndex<CPP,CPPShell>
      (CLASSNAME, CLASSNAME+"ShellSet", This, extract::shell, index_, shell);
}

// Has, by label
int
PhotonEmissionProbabilitiesShellHasByLabel(
   ConstHandle2ConstPhotonEmissionProbabilities This,
   const XMLName label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ShellHasByLabel",
       This, extract::shell, meta::label, label);
}

// Get, by label, const
Handle2ConstShell
PhotonEmissionProbabilitiesShellGetByLabelConst(
   ConstHandle2ConstPhotonEmissionProbabilities This,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2ConstShell>
      (CLASSNAME, CLASSNAME+"ShellGetByLabelConst",
       This, extract::shell, meta::label, label);
}

// Get, by label, non-const
Handle2Shell
PhotonEmissionProbabilitiesShellGetByLabel(
   ConstHandle2PhotonEmissionProbabilities This,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2Shell>
      (CLASSNAME, CLASSNAME+"ShellGetByLabel",
       This, extract::shell, meta::label, label);
}

// Set, by label
void
PhotonEmissionProbabilitiesShellSetByLabel(
   ConstHandle2PhotonEmissionProbabilities This,
   const XMLName label,
   ConstHandle2ConstShell shell
) {
   detail::setByMetadatum<CPP,CPPShell>
      (CLASSNAME, CLASSNAME+"ShellSetByLabel",
       This, extract::shell, meta::label, label, shell);
}

// Has, by value
int
PhotonEmissionProbabilitiesShellHasByValue(
   ConstHandle2ConstPhotonEmissionProbabilities This,
   const Float64 value
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ShellHasByValue",
       This, extract::shell, meta::value, value);
}

// Get, by value, const
Handle2ConstShell
PhotonEmissionProbabilitiesShellGetByValueConst(
   ConstHandle2ConstPhotonEmissionProbabilities This,
   const Float64 value
) {
   return detail::getByMetadatum<CPP,Handle2ConstShell>
      (CLASSNAME, CLASSNAME+"ShellGetByValueConst",
       This, extract::shell, meta::value, value);
}

// Get, by value, non-const
Handle2Shell
PhotonEmissionProbabilitiesShellGetByValue(
   ConstHandle2PhotonEmissionProbabilities This,
   const Float64 value
) {
   return detail::getByMetadatum<CPP,Handle2Shell>
      (CLASSNAME, CLASSNAME+"ShellGetByValue",
       This, extract::shell, meta::value, value);
}

// Set, by value
void
PhotonEmissionProbabilitiesShellSetByValue(
   ConstHandle2PhotonEmissionProbabilities This,
   const Float64 value,
   ConstHandle2ConstShell shell
) {
   detail::setByMetadatum<CPP,CPPShell>
      (CLASSNAME, CLASSNAME+"ShellSetByValue",
       This, extract::shell, meta::value, value, shell);
}

// Has, by unit
int
PhotonEmissionProbabilitiesShellHasByUnit(
   ConstHandle2ConstPhotonEmissionProbabilities This,
   const XMLName unit
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ShellHasByUnit",
       This, extract::shell, meta::unit, unit);
}

// Get, by unit, const
Handle2ConstShell
PhotonEmissionProbabilitiesShellGetByUnitConst(
   ConstHandle2ConstPhotonEmissionProbabilities This,
   const XMLName unit
) {
   return detail::getByMetadatum<CPP,Handle2ConstShell>
      (CLASSNAME, CLASSNAME+"ShellGetByUnitConst",
       This, extract::shell, meta::unit, unit);
}

// Get, by unit, non-const
Handle2Shell
PhotonEmissionProbabilitiesShellGetByUnit(
   ConstHandle2PhotonEmissionProbabilities This,
   const XMLName unit
) {
   return detail::getByMetadatum<CPP,Handle2Shell>
      (CLASSNAME, CLASSNAME+"ShellGetByUnit",
       This, extract::shell, meta::unit, unit);
}

// Set, by unit
void
PhotonEmissionProbabilitiesShellSetByUnit(
   ConstHandle2PhotonEmissionProbabilities This,
   const XMLName unit,
   ConstHandle2ConstShell shell
) {
   detail::setByMetadatum<CPP,CPPShell>
      (CLASSNAME, CLASSNAME+"ShellSetByUnit",
       This, extract::shell, meta::unit, unit, shell);
}
