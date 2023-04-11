
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2.0/documentation/ComputerCodes.hpp"
#include "ComputerCodes.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = ComputerCodesClass;
using CPP = multigroup::ComputerCodes;

static const std::string CLASSNAME = "ComputerCodes";

namespace extract {
   static auto computerCode = [](auto &obj) { return &obj.computerCode; };
}

using CPPComputerCode = documentation::ComputerCode;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstComputerCodes
ComputerCodesDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2ComputerCodes
ComputerCodesDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstComputerCodes
ComputerCodesCreateConst(
   ConstHandle2ComputerCode *const computerCode, const size_t computerCodeSize
) {
   ConstHandle2ComputerCodes handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPComputerCode>{}
   );
   for (size_t ComputerCodeN = 0; ComputerCodeN < computerCodeSize; ++ComputerCodeN)
      ComputerCodesComputerCodeAdd(handle, computerCode[ComputerCodeN]);
   return handle;
}

// Create, general
Handle2ComputerCodes
ComputerCodesCreate(
   ConstHandle2ComputerCode *const computerCode, const size_t computerCodeSize
) {
   ConstHandle2ComputerCodes handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPComputerCode>{}
   );
   for (size_t ComputerCodeN = 0; ComputerCodeN < computerCodeSize; ++ComputerCodeN)
      ComputerCodesComputerCodeAdd(handle, computerCode[ComputerCodeN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ComputerCodesAssign(ConstHandle2ComputerCodes self, ConstHandle2ConstComputerCodes from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ComputerCodesDelete(ConstHandle2ConstComputerCodes self)
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
ComputerCodesRead(ConstHandle2ComputerCodes self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ComputerCodesWrite(ConstHandle2ConstComputerCodes self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ComputerCodesPrint(ConstHandle2ConstComputerCodes self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ComputerCodesPrintXML(ConstHandle2ConstComputerCodes self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ComputerCodesPrintJSON(ConstHandle2ConstComputerCodes self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: computerCode
// -----------------------------------------------------------------------------

// Has
int
ComputerCodesComputerCodeHas(ConstHandle2ConstComputerCodes self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ComputerCodeHas", self, extract::computerCode);
}

// Clear
void
ComputerCodesComputerCodeClear(ConstHandle2ComputerCodes self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"ComputerCodeClear", self, extract::computerCode);
}

// Size
size_t
ComputerCodesComputerCodeSize(ConstHandle2ConstComputerCodes self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"ComputerCodeSize", self, extract::computerCode);
}

// Add
void
ComputerCodesComputerCodeAdd(ConstHandle2ComputerCodes self, ConstHandle2ConstComputerCode computerCode)
{
   detail::addToContainer<CPP,CPPComputerCode>
      (CLASSNAME, CLASSNAME+"ComputerCodeAdd", self, extract::computerCode, computerCode);
}

// Get, by index \in [0,size), const
Handle2ConstComputerCode
ComputerCodesComputerCodeGetConst(ConstHandle2ConstComputerCodes self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstComputerCode>
      (CLASSNAME, CLASSNAME+"ComputerCodeGetConst", self, extract::computerCode, index_);
}

// Get, by index \in [0,size), non-const
Handle2ComputerCode
ComputerCodesComputerCodeGet(ConstHandle2ComputerCodes self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ComputerCode>
      (CLASSNAME, CLASSNAME+"ComputerCodeGet", self, extract::computerCode, index_);
}

// Set, by index \in [0,size)
void
ComputerCodesComputerCodeSet(
   ConstHandle2ComputerCodes self,
   const size_t index_,
   ConstHandle2ConstComputerCode computerCode
) {
   detail::setByIndex<CPP,CPPComputerCode>
      (CLASSNAME, CLASSNAME+"ComputerCodeSet", self, extract::computerCode, index_, computerCode);
}

// Has, by label
int
ComputerCodesComputerCodeHasByLabel(
   ConstHandle2ConstComputerCodes self,
   const XMLName label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ComputerCodeHasByLabel",
       self, extract::computerCode, meta::label, label);
}

// Get, by label, const
Handle2ConstComputerCode
ComputerCodesComputerCodeGetByLabelConst(
   ConstHandle2ConstComputerCodes self,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2ConstComputerCode>
      (CLASSNAME, CLASSNAME+"ComputerCodeGetByLabelConst",
       self, extract::computerCode, meta::label, label);
}

// Get, by label, non-const
Handle2ComputerCode
ComputerCodesComputerCodeGetByLabel(
   ConstHandle2ComputerCodes self,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2ComputerCode>
      (CLASSNAME, CLASSNAME+"ComputerCodeGetByLabel",
       self, extract::computerCode, meta::label, label);
}

// Set, by label
void
ComputerCodesComputerCodeSetByLabel(
   ConstHandle2ComputerCodes self,
   const XMLName label,
   ConstHandle2ConstComputerCode computerCode
) {
   detail::setByMetadatum<CPP,CPPComputerCode>
      (CLASSNAME, CLASSNAME+"ComputerCodeSetByLabel",
       self, extract::computerCode, meta::label, label, computerCode);
}

// Has, by name
int
ComputerCodesComputerCodeHasByName(
   ConstHandle2ConstComputerCodes self,
   const UTF8Text name
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ComputerCodeHasByName",
       self, extract::computerCode, meta::name, name);
}

// Get, by name, const
Handle2ConstComputerCode
ComputerCodesComputerCodeGetByNameConst(
   ConstHandle2ConstComputerCodes self,
   const UTF8Text name
) {
   return detail::getByMetadatum<CPP,Handle2ConstComputerCode>
      (CLASSNAME, CLASSNAME+"ComputerCodeGetByNameConst",
       self, extract::computerCode, meta::name, name);
}

// Get, by name, non-const
Handle2ComputerCode
ComputerCodesComputerCodeGetByName(
   ConstHandle2ComputerCodes self,
   const UTF8Text name
) {
   return detail::getByMetadatum<CPP,Handle2ComputerCode>
      (CLASSNAME, CLASSNAME+"ComputerCodeGetByName",
       self, extract::computerCode, meta::name, name);
}

// Set, by name
void
ComputerCodesComputerCodeSetByName(
   ConstHandle2ComputerCodes self,
   const UTF8Text name,
   ConstHandle2ConstComputerCode computerCode
) {
   detail::setByMetadatum<CPP,CPPComputerCode>
      (CLASSNAME, CLASSNAME+"ComputerCodeSetByName",
       self, extract::computerCode, meta::name, name, computerCode);
}

// Has, by version
int
ComputerCodesComputerCodeHasByVersion(
   ConstHandle2ConstComputerCodes self,
   const XMLName version
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ComputerCodeHasByVersion",
       self, extract::computerCode, meta::version, version);
}

// Get, by version, const
Handle2ConstComputerCode
ComputerCodesComputerCodeGetByVersionConst(
   ConstHandle2ConstComputerCodes self,
   const XMLName version
) {
   return detail::getByMetadatum<CPP,Handle2ConstComputerCode>
      (CLASSNAME, CLASSNAME+"ComputerCodeGetByVersionConst",
       self, extract::computerCode, meta::version, version);
}

// Get, by version, non-const
Handle2ComputerCode
ComputerCodesComputerCodeGetByVersion(
   ConstHandle2ComputerCodes self,
   const XMLName version
) {
   return detail::getByMetadatum<CPP,Handle2ComputerCode>
      (CLASSNAME, CLASSNAME+"ComputerCodeGetByVersion",
       self, extract::computerCode, meta::version, version);
}

// Set, by version
void
ComputerCodesComputerCodeSetByVersion(
   ConstHandle2ComputerCodes self,
   const XMLName version,
   ConstHandle2ConstComputerCode computerCode
) {
   detail::setByMetadatum<CPP,CPPComputerCode>
      (CLASSNAME, CLASSNAME+"ComputerCodeSetByVersion",
       self, extract::computerCode, meta::version, version, computerCode);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/documentation/ComputerCodes/src/custom.cpp"
