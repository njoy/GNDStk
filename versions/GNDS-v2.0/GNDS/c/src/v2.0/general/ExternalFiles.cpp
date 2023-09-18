
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/ExternalFiles.hpp"
#include "ExternalFiles.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = ExternalFilesClass;
using CPP = multigroup::ExternalFiles;

static const std::string CLASSNAME = "ExternalFiles";

namespace extract {
   static auto externalFile = [](auto &obj) { return &obj.externalFile; };
}

using CPPExternalFile = general::ExternalFile;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstExternalFiles
ExternalFilesDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2ExternalFiles
ExternalFilesDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstExternalFiles
ExternalFilesCreateConst(
   ConstHandle2ExternalFile *const externalFile, const size_t externalFileSize
) {
   ConstHandle2ExternalFiles handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPExternalFile>{}
   );
   for (size_t ExternalFileN = 0; ExternalFileN < externalFileSize; ++ExternalFileN)
      ExternalFilesExternalFileAdd(handle, externalFile[ExternalFileN]);
   return handle;
}

// Create, general
Handle2ExternalFiles
ExternalFilesCreate(
   ConstHandle2ExternalFile *const externalFile, const size_t externalFileSize
) {
   ConstHandle2ExternalFiles handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPExternalFile>{}
   );
   for (size_t ExternalFileN = 0; ExternalFileN < externalFileSize; ++ExternalFileN)
      ExternalFilesExternalFileAdd(handle, externalFile[ExternalFileN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ExternalFilesAssign(ConstHandle2ExternalFiles self, ConstHandle2ConstExternalFiles from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ExternalFilesDelete(ConstHandle2ConstExternalFiles self)
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
ExternalFilesRead(ConstHandle2ExternalFiles self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ExternalFilesWrite(ConstHandle2ConstExternalFiles self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ExternalFilesPrint(ConstHandle2ConstExternalFiles self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ExternalFilesPrintXML(ConstHandle2ConstExternalFiles self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ExternalFilesPrintJSON(ConstHandle2ConstExternalFiles self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: externalFile
// -----------------------------------------------------------------------------

// Has
int
ExternalFilesExternalFileHas(ConstHandle2ConstExternalFiles self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ExternalFileHas", self, extract::externalFile);
}

// Clear
void
ExternalFilesExternalFileClear(ConstHandle2ExternalFiles self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"ExternalFileClear", self, extract::externalFile);
}

// Size
size_t
ExternalFilesExternalFileSize(ConstHandle2ConstExternalFiles self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"ExternalFileSize", self, extract::externalFile);
}

// Add
void
ExternalFilesExternalFileAdd(ConstHandle2ExternalFiles self, ConstHandle2ConstExternalFile externalFile)
{
   detail::addToContainer<CPP,CPPExternalFile>
      (CLASSNAME, CLASSNAME+"ExternalFileAdd", self, extract::externalFile, externalFile);
}

// Get, by index \in [0,size), const
Handle2ConstExternalFile
ExternalFilesExternalFileGetConst(ConstHandle2ConstExternalFiles self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstExternalFile>
      (CLASSNAME, CLASSNAME+"ExternalFileGetConst", self, extract::externalFile, index_);
}

// Get, by index \in [0,size)
Handle2ExternalFile
ExternalFilesExternalFileGet(ConstHandle2ExternalFiles self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ExternalFile>
      (CLASSNAME, CLASSNAME+"ExternalFileGet", self, extract::externalFile, index_);
}

// Set, by index \in [0,size)
void
ExternalFilesExternalFileSet(
   ConstHandle2ExternalFiles self,
   const size_t index_,
   ConstHandle2ConstExternalFile externalFile
) {
   detail::setByIndex<CPP,CPPExternalFile>
      (CLASSNAME, CLASSNAME+"ExternalFileSet", self, extract::externalFile, index_, externalFile);
}

// Has, by label
int
ExternalFilesExternalFileHasByLabel(
   ConstHandle2ConstExternalFiles self,
   const char *const label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ExternalFileHasByLabel",
       self, extract::externalFile, meta::label, label);
}

// Get, by label, const
Handle2ConstExternalFile
ExternalFilesExternalFileGetByLabelConst(
   ConstHandle2ConstExternalFiles self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2ConstExternalFile>
      (CLASSNAME, CLASSNAME+"ExternalFileGetByLabelConst",
       self, extract::externalFile, meta::label, label);
}

// Get, by label
Handle2ExternalFile
ExternalFilesExternalFileGetByLabel(
   ConstHandle2ExternalFiles self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2ExternalFile>
      (CLASSNAME, CLASSNAME+"ExternalFileGetByLabel",
       self, extract::externalFile, meta::label, label);
}

// Set, by label
void
ExternalFilesExternalFileSetByLabel(
   ConstHandle2ExternalFiles self,
   const char *const label,
   ConstHandle2ConstExternalFile externalFile
) {
   detail::setByMetadatum<CPP,CPPExternalFile>
      (CLASSNAME, CLASSNAME+"ExternalFileSetByLabel",
       self, extract::externalFile, meta::label, label, externalFile);
}

// Has, by path
int
ExternalFilesExternalFileHasByPath(
   ConstHandle2ConstExternalFiles self,
   const char *const path
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ExternalFileHasByPath",
       self, extract::externalFile, meta::path, path);
}

// Get, by path, const
Handle2ConstExternalFile
ExternalFilesExternalFileGetByPathConst(
   ConstHandle2ConstExternalFiles self,
   const char *const path
) {
   return detail::getByMetadatum<CPP,Handle2ConstExternalFile>
      (CLASSNAME, CLASSNAME+"ExternalFileGetByPathConst",
       self, extract::externalFile, meta::path, path);
}

// Get, by path
Handle2ExternalFile
ExternalFilesExternalFileGetByPath(
   ConstHandle2ExternalFiles self,
   const char *const path
) {
   return detail::getByMetadatum<CPP,Handle2ExternalFile>
      (CLASSNAME, CLASSNAME+"ExternalFileGetByPath",
       self, extract::externalFile, meta::path, path);
}

// Set, by path
void
ExternalFilesExternalFileSetByPath(
   ConstHandle2ExternalFiles self,
   const char *const path,
   ConstHandle2ConstExternalFile externalFile
) {
   detail::setByMetadatum<CPP,CPPExternalFile>
      (CLASSNAME, CLASSNAME+"ExternalFileSetByPath",
       self, extract::externalFile, meta::path, path, externalFile);
}

// Has, by checksum
int
ExternalFilesExternalFileHasByChecksum(
   ConstHandle2ConstExternalFiles self,
   const char *const checksum
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ExternalFileHasByChecksum",
       self, extract::externalFile, meta::checksum, checksum);
}

// Get, by checksum, const
Handle2ConstExternalFile
ExternalFilesExternalFileGetByChecksumConst(
   ConstHandle2ConstExternalFiles self,
   const char *const checksum
) {
   return detail::getByMetadatum<CPP,Handle2ConstExternalFile>
      (CLASSNAME, CLASSNAME+"ExternalFileGetByChecksumConst",
       self, extract::externalFile, meta::checksum, checksum);
}

// Get, by checksum
Handle2ExternalFile
ExternalFilesExternalFileGetByChecksum(
   ConstHandle2ExternalFiles self,
   const char *const checksum
) {
   return detail::getByMetadatum<CPP,Handle2ExternalFile>
      (CLASSNAME, CLASSNAME+"ExternalFileGetByChecksum",
       self, extract::externalFile, meta::checksum, checksum);
}

// Set, by checksum
void
ExternalFilesExternalFileSetByChecksum(
   ConstHandle2ExternalFiles self,
   const char *const checksum,
   ConstHandle2ConstExternalFile externalFile
) {
   detail::setByMetadatum<CPP,CPPExternalFile>
      (CLASSNAME, CLASSNAME+"ExternalFileSetByChecksum",
       self, extract::externalFile, meta::checksum, checksum, externalFile);
}

// Has, by algorithm
int
ExternalFilesExternalFileHasByAlgorithm(
   ConstHandle2ConstExternalFiles self,
   const char *const algorithm
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"ExternalFileHasByAlgorithm",
       self, extract::externalFile, meta::algorithm, algorithm);
}

// Get, by algorithm, const
Handle2ConstExternalFile
ExternalFilesExternalFileGetByAlgorithmConst(
   ConstHandle2ConstExternalFiles self,
   const char *const algorithm
) {
   return detail::getByMetadatum<CPP,Handle2ConstExternalFile>
      (CLASSNAME, CLASSNAME+"ExternalFileGetByAlgorithmConst",
       self, extract::externalFile, meta::algorithm, algorithm);
}

// Get, by algorithm
Handle2ExternalFile
ExternalFilesExternalFileGetByAlgorithm(
   ConstHandle2ExternalFiles self,
   const char *const algorithm
) {
   return detail::getByMetadatum<CPP,Handle2ExternalFile>
      (CLASSNAME, CLASSNAME+"ExternalFileGetByAlgorithm",
       self, extract::externalFile, meta::algorithm, algorithm);
}

// Set, by algorithm
void
ExternalFilesExternalFileSetByAlgorithm(
   ConstHandle2ExternalFiles self,
   const char *const algorithm,
   ConstHandle2ConstExternalFile externalFile
) {
   detail::setByMetadatum<CPP,CPPExternalFile>
      (CLASSNAME, CLASSNAME+"ExternalFileSetByAlgorithm",
       self, extract::externalFile, meta::algorithm, algorithm, externalFile);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/ExternalFiles/src/custom.cpp"
