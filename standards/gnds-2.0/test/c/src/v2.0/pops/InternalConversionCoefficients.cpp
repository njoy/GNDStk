
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2.0/pops/InternalConversionCoefficients.hpp"
#include "InternalConversionCoefficients.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = InternalConversionCoefficientsClass;
using CPP = multigroup::InternalConversionCoefficients;

static const std::string CLASSNAME = "InternalConversionCoefficients";

namespace extract {
   static auto shell = [](auto &obj) { return &obj.shell; };
}

using CPPShell = pops::Shell;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstInternalConversionCoefficients
InternalConversionCoefficientsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2InternalConversionCoefficients
InternalConversionCoefficientsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstInternalConversionCoefficients
InternalConversionCoefficientsCreateConst(
   ConstHandle2Shell *const shell, const size_t shellSize
) {
   ConstHandle2InternalConversionCoefficients handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPShell>{}
   );
   for (size_t ShellN = 0; ShellN < shellSize; ++ShellN)
      InternalConversionCoefficientsShellAdd(handle, shell[ShellN]);
   return handle;
}

// Create, general
Handle2InternalConversionCoefficients
InternalConversionCoefficientsCreate(
   ConstHandle2Shell *const shell, const size_t shellSize
) {
   ConstHandle2InternalConversionCoefficients handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPShell>{}
   );
   for (size_t ShellN = 0; ShellN < shellSize; ++ShellN)
      InternalConversionCoefficientsShellAdd(handle, shell[ShellN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
InternalConversionCoefficientsAssign(ConstHandle2InternalConversionCoefficients self, ConstHandle2ConstInternalConversionCoefficients from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
InternalConversionCoefficientsDelete(ConstHandle2ConstInternalConversionCoefficients self)
{
   detail::deleteHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Delete", self);
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
InternalConversionCoefficientsRead(ConstHandle2InternalConversionCoefficients self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
InternalConversionCoefficientsWrite(ConstHandle2ConstInternalConversionCoefficients self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
InternalConversionCoefficientsPrint(ConstHandle2ConstInternalConversionCoefficients self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
InternalConversionCoefficientsPrintXML(ConstHandle2ConstInternalConversionCoefficients self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
InternalConversionCoefficientsPrintJSON(ConstHandle2ConstInternalConversionCoefficients self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: shell
// -----------------------------------------------------------------------------

// Has
int
InternalConversionCoefficientsShellHas(ConstHandle2ConstInternalConversionCoefficients self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ShellHas", self, extract::shell);
}

// Clear
void
InternalConversionCoefficientsShellClear(ConstHandle2InternalConversionCoefficients self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"ShellClear", self, extract::shell);
}

// Size
size_t
InternalConversionCoefficientsShellSize(ConstHandle2ConstInternalConversionCoefficients self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"ShellSize", self, extract::shell);
}

// Add
void
InternalConversionCoefficientsShellAdd(ConstHandle2InternalConversionCoefficients self, ConstHandle2ConstShell shell)
{
   detail::addToContainer<CPP,CPPShell>
      (CLASSNAME, CLASSNAME+"ShellAdd", self, extract::shell, shell);
}

// Get, by index \in [0,size), const
Handle2ConstShell
InternalConversionCoefficientsShellGetConst(ConstHandle2ConstInternalConversionCoefficients self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstShell>
      (CLASSNAME, CLASSNAME+"ShellGetConst", self, extract::shell, index_);
}

// Get, by index \in [0,size), non-const
Handle2Shell
InternalConversionCoefficientsShellGet(ConstHandle2InternalConversionCoefficients self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Shell>
      (CLASSNAME, CLASSNAME+"ShellGet", self, extract::shell, index_);
}

// Set, by index \in [0,size)
void
InternalConversionCoefficientsShellSet(
   ConstHandle2InternalConversionCoefficients self,
   const size_t index_,
   ConstHandle2ConstShell shell
) {
   detail::setByIndex<CPP,CPPShell>
      (CLASSNAME, CLASSNAME+"ShellSet", self, extract::shell, index_, shell);
}

// Has, by label
int
InternalConversionCoefficientsShellHasByLabel(
   ConstHandle2ConstInternalConversionCoefficients self,
   const XMLName label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ShellHasByLabel",
       self, extract::shell, meta::label, label);
}

// Get, by label, const
Handle2ConstShell
InternalConversionCoefficientsShellGetByLabelConst(
   ConstHandle2ConstInternalConversionCoefficients self,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2ConstShell>
      (CLASSNAME, CLASSNAME+"ShellGetByLabelConst",
       self, extract::shell, meta::label, label);
}

// Get, by label, non-const
Handle2Shell
InternalConversionCoefficientsShellGetByLabel(
   ConstHandle2InternalConversionCoefficients self,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2Shell>
      (CLASSNAME, CLASSNAME+"ShellGetByLabel",
       self, extract::shell, meta::label, label);
}

// Set, by label
void
InternalConversionCoefficientsShellSetByLabel(
   ConstHandle2InternalConversionCoefficients self,
   const XMLName label,
   ConstHandle2ConstShell shell
) {
   detail::setByMetadatum<CPP,CPPShell>
      (CLASSNAME, CLASSNAME+"ShellSetByLabel",
       self, extract::shell, meta::label, label, shell);
}

// Has, by value
int
InternalConversionCoefficientsShellHasByValue(
   ConstHandle2ConstInternalConversionCoefficients self,
   const Float64 value
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ShellHasByValue",
       self, extract::shell, meta::value, value);
}

// Get, by value, const
Handle2ConstShell
InternalConversionCoefficientsShellGetByValueConst(
   ConstHandle2ConstInternalConversionCoefficients self,
   const Float64 value
) {
   return detail::getByMetadatum<CPP,Handle2ConstShell>
      (CLASSNAME, CLASSNAME+"ShellGetByValueConst",
       self, extract::shell, meta::value, value);
}

// Get, by value, non-const
Handle2Shell
InternalConversionCoefficientsShellGetByValue(
   ConstHandle2InternalConversionCoefficients self,
   const Float64 value
) {
   return detail::getByMetadatum<CPP,Handle2Shell>
      (CLASSNAME, CLASSNAME+"ShellGetByValue",
       self, extract::shell, meta::value, value);
}

// Set, by value
void
InternalConversionCoefficientsShellSetByValue(
   ConstHandle2InternalConversionCoefficients self,
   const Float64 value,
   ConstHandle2ConstShell shell
) {
   detail::setByMetadatum<CPP,CPPShell>
      (CLASSNAME, CLASSNAME+"ShellSetByValue",
       self, extract::shell, meta::value, value, shell);
}

// Has, by unit
int
InternalConversionCoefficientsShellHasByUnit(
   ConstHandle2ConstInternalConversionCoefficients self,
   const XMLName unit
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ShellHasByUnit",
       self, extract::shell, meta::unit, unit);
}

// Get, by unit, const
Handle2ConstShell
InternalConversionCoefficientsShellGetByUnitConst(
   ConstHandle2ConstInternalConversionCoefficients self,
   const XMLName unit
) {
   return detail::getByMetadatum<CPP,Handle2ConstShell>
      (CLASSNAME, CLASSNAME+"ShellGetByUnitConst",
       self, extract::shell, meta::unit, unit);
}

// Get, by unit, non-const
Handle2Shell
InternalConversionCoefficientsShellGetByUnit(
   ConstHandle2InternalConversionCoefficients self,
   const XMLName unit
) {
   return detail::getByMetadatum<CPP,Handle2Shell>
      (CLASSNAME, CLASSNAME+"ShellGetByUnit",
       self, extract::shell, meta::unit, unit);
}

// Set, by unit
void
InternalConversionCoefficientsShellSetByUnit(
   ConstHandle2InternalConversionCoefficients self,
   const XMLName unit,
   ConstHandle2ConstShell shell
) {
   detail::setByMetadatum<CPP,CPPShell>
      (CLASSNAME, CLASSNAME+"ShellSetByUnit",
       self, extract::shell, meta::unit, unit, shell);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/pops/InternalConversionCoefficients/src/custom.cpp"
