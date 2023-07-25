
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "gnds/v2.0/general/ExternalFile.hpp"
#include "ExternalFile.h"

using namespace njoy::GNDStk;
using namespace gnds::v2_0;

using C = ExternalFileClass;
using CPP = multigroup::ExternalFile;

static const std::string CLASSNAME = "ExternalFile";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto path = [](auto &obj) { return &obj.path; };
   static auto checksum = [](auto &obj) { return &obj.checksum; };
   static auto algorithm = [](auto &obj) { return &obj.algorithm; };
}


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstExternalFile
ExternalFileDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2ExternalFile
ExternalFileDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstExternalFile
ExternalFileCreateConst(
   const char *const label,
   const char *const path,
   const char *const checksum,
   const char *const algorithm
) {
   ConstHandle2ExternalFile handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      path,
      checksum,
      algorithm
   );
   return handle;
}

// Create, general
Handle2ExternalFile
ExternalFileCreate(
   const char *const label,
   const char *const path,
   const char *const checksum,
   const char *const algorithm
) {
   ConstHandle2ExternalFile handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      path,
      checksum,
      algorithm
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ExternalFileAssign(ConstHandle2ExternalFile self, ConstHandle2ConstExternalFile from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ExternalFileDelete(ConstHandle2ConstExternalFile self)
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
ExternalFileRead(ConstHandle2ExternalFile self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ExternalFileWrite(ConstHandle2ConstExternalFile self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ExternalFilePrint(ConstHandle2ConstExternalFile self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ExternalFilePrintXML(ConstHandle2ConstExternalFile self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ExternalFilePrintJSON(ConstHandle2ConstExternalFile self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
ExternalFileLabelHas(ConstHandle2ConstExternalFile self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
const char *
ExternalFileLabelGet(ConstHandle2ConstExternalFile self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
ExternalFileLabelSet(ConstHandle2ExternalFile self, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: path
// -----------------------------------------------------------------------------

// Has
int
ExternalFilePathHas(ConstHandle2ConstExternalFile self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"PathHas", self, extract::path);
}

// Get
// Returns by value
const char *
ExternalFilePathGet(ConstHandle2ConstExternalFile self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"PathGet", self, extract::path);
}

// Set
void
ExternalFilePathSet(ConstHandle2ExternalFile self, const char *const path)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"PathSet", self, extract::path, path);
}


// -----------------------------------------------------------------------------
// Metadatum: checksum
// -----------------------------------------------------------------------------

// Has
int
ExternalFileChecksumHas(ConstHandle2ConstExternalFile self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ChecksumHas", self, extract::checksum);
}

// Get
// Returns by value
const char *
ExternalFileChecksumGet(ConstHandle2ConstExternalFile self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ChecksumGet", self, extract::checksum);
}

// Set
void
ExternalFileChecksumSet(ConstHandle2ExternalFile self, const char *const checksum)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ChecksumSet", self, extract::checksum, checksum);
}


// -----------------------------------------------------------------------------
// Metadatum: algorithm
// -----------------------------------------------------------------------------

// Has
int
ExternalFileAlgorithmHas(ConstHandle2ConstExternalFile self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AlgorithmHas", self, extract::algorithm);
}

// Get
// Returns by value
const char *
ExternalFileAlgorithmGet(ConstHandle2ConstExternalFile self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"AlgorithmGet", self, extract::algorithm);
}

// Set
void
ExternalFileAlgorithmSet(ConstHandle2ExternalFile self, const char *const algorithm)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"AlgorithmSet", self, extract::algorithm, algorithm);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/ExternalFile/src/custom.cpp"
